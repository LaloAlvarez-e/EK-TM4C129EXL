/**
 *
 * @file OS_Task_Event.c
 * @copyright
 * @verbatim InDeviceMex 2021 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 29 jul. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 29 jul. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xOS/Task/xHeader/OS_Task_Event.h>

#include <xOS/Task/Intrinsics/OS_Task_Intrinsics.h>
#include <xOS/Task/xHeader/OS_Task_Delayed.h>
#include <xOS/Task/xHeader/OS_Task_Ready.h>

void OS_Task__vPlaceOnEventList(OS_List_t* const pstEventList,
                                const OS_UBase_t uxTicksToWait)
{
    if(0UL != (OS_Pointer_t) pstEventList)
    {
        /* THIS FUNCTION MUST BE CALLED WITH EITHER INTERRUPTS DISABLED OR THE
        SCHEDULER SUSPENDED AND THE QUEUE BEING ACCESSED LOCKED. */
        OS_Task_TCB_t *pstCurrentTCB;
        OS_UBase_t uxListSize;

        pstCurrentTCB = OS_Task__pstGetCurrentTCB();
        OS_List__vInsert(pstEventList, &(pstCurrentTCB->stEventListItem));

        uxListSize = OS_List__uxRemove(&(pstCurrentTCB->stGenericListItem));
        if(0UL == uxListSize)
        {
            OS_Task__vAdaptResetReadyPriority(pstCurrentTCB->uxPriorityTask);
        }

        if(OS_ADAPT_MAX_DELAY == uxTicksToWait)
        {
            OS_List_t* pstSuspendedTaskList;
            pstSuspendedTaskList = OS_Task__pstGetSuspendedTaskList();
            OS_List__vInsertEnd(pstSuspendedTaskList,
                                &(pstCurrentTCB->stGenericListItem));
        }
        else
        {
            OS_UBase_t uxTimeToWake;
            OS_UBase_t uxTickCount;

            uxTickCount = OS_Task__uxGetTickCount_NotSafe();
            uxTimeToWake = uxTickCount + uxTicksToWait;
            OS_Task__vAddCurrentTaskToDelayedList(uxTimeToWake);
        }
    }
}

void OS_Task__vPlaceOnEventListRestricted(OS_List_t* const pstEventList,
                                          const OS_UBase_t uxTicksToWait,
                                          const OS_Boolean_t boWaitIndefinitely)
{
    if(0UL != (OS_Pointer_t) pstEventList)
    {

        /* This function should not be called by application code hence the
        'Restricted' in its name.  It is not part of the public API.  It is
        designed for use by kernel code, and has special calling requirements -
        it should be called with the scheduler suspended. */
        OS_Task_TCB_t *pstCurrentTCB;
        OS_UBase_t uxListSize;

        pstCurrentTCB = OS_Task__pstGetCurrentTCB();
        OS_List__vInsertEnd(pstEventList,
                            &(pstCurrentTCB->stEventListItem));

        uxListSize = OS_List__uxRemove(&(pstCurrentTCB->stGenericListItem));
        if(0UL == uxListSize)
        {
            OS_Task__vAdaptResetReadyPriority(pstCurrentTCB->uxPriorityTask);
        }

        if(TRUE == boWaitIndefinitely)
        {
            OS_List_t* pstSuspendedTaskList;
            pstSuspendedTaskList = OS_Task__pstGetSuspendedTaskList();
            OS_List__vInsertEnd(pstSuspendedTaskList, &(pstCurrentTCB->stGenericListItem));
        }
        else
        {
            OS_UBase_t uxTimeToWake;
            OS_UBase_t uxTickCount;

            uxTickCount = OS_Task__uxGetTickCount_NotSafe();
            uxTimeToWake = uxTickCount + uxTicksToWait;
            OS_Task__vAddCurrentTaskToDelayedList(uxTimeToWake);
        }
    }
}

void OS_Task__vPlaceOnUnorderedEventList(OS_List_t* pstEventList,
                                         const OS_UBase_t uxItemValue,
                                         const OS_UBase_t uxTicksToWait)
{

    if(0UL != (OS_Pointer_t) pstEventList)
    {
        /* THIS FUNCTION MUST BE CALLED WITH THE SCHEDULER SUSPENDED.  It is used by
        the event groups implementation. */
        OS_UBase_t uxSchedulerSuspended;
        uxSchedulerSuspended = OS_Task__uxGetSchedulerSuspended();
        if(0UL != uxSchedulerSuspended)
        {
            OS_Task_TCB_t *pstCurrentTCB;
            OS_UBase_t uxListSize;

            pstCurrentTCB = OS_Task__pstGetCurrentTCB();
            OS_List__vSetItemValue(&(pstCurrentTCB->stEventListItem),
                                   uxItemValue | OS_TASK_EVENT_LIST_ITEM_VALUE_IN_USE );

            OS_List__vInsertEnd(pstEventList, &(pstCurrentTCB->stEventListItem));
            uxListSize = OS_List__uxRemove(&(pstCurrentTCB->stGenericListItem));
            if(0UL == uxListSize)
            {
                OS_Task__vAdaptResetReadyPriority(pstCurrentTCB->uxPriorityTask);
            }

            if(OS_ADAPT_MAX_DELAY == uxTicksToWait)
            {
                OS_List_t* pstSuspendedTaskList;
                pstSuspendedTaskList = OS_Task__pstGetSuspendedTaskList();
                OS_List__vInsertEnd(pstSuspendedTaskList, &(pstCurrentTCB->stGenericListItem));
            }
            else
            {
                OS_UBase_t uxTimeToWake;
                OS_UBase_t uxTickCount;

                uxTickCount = OS_Task__uxGetTickCount_NotSafe();
                uxTimeToWake = uxTickCount + uxTicksToWait;
                OS_Task__vAddCurrentTaskToDelayedList(uxTimeToWake);
            }
        }
    }
}

OS_Boolean_t OS_Task__boRemoveFromEventList(const OS_List_t* const pstEventList)
{
    /* THIS FUNCTION MUST BE CALLED FROM A CRITICAL SECTION.  It can also be
    called from a critical section within an ISR. */
    OS_Task_TCB_t *pstUnblockedTCB;
    OS_Boolean_t boReturn;

    boReturn = FALSE;
    pstUnblockedTCB = (OS_Task_TCB_t*) OS_List__pvGetOwnerOfHeadEntry(pstEventList);
    if(0UL != (OS_Pointer_t) pstUnblockedTCB)
    {
        OS_Task_TCB_t *pstCurrentTCB;
        OS_UBase_t uxSchedulerSuspended;

        (void) OS_List__uxRemove(&(pstUnblockedTCB->stEventListItem));

        uxSchedulerSuspended = OS_Task__uxGetSchedulerSuspended();
        if(0UL == uxSchedulerSuspended)
        {
            (void) OS_List__uxRemove(&(pstUnblockedTCB->stGenericListItem));
            OS_Task__vAddTaskToReadyList(pstUnblockedTCB);
        }
        else
        {
            OS_List_t* pstPendingReadyList;
            pstPendingReadyList = OS_Task__pstGetPendingReadyList();
            OS_List__vInsertEnd(pstPendingReadyList,
                                &(pstUnblockedTCB->stEventListItem));
        }

        pstCurrentTCB = OS_Task__pstGetCurrentTCB();
        if( pstUnblockedTCB->uxPriorityTask > pstCurrentTCB->uxPriorityTask )
        {
            boReturn = TRUE;
            OS_Task__vSetYieldPending(TRUE);
        }
        else
        {
            boReturn = FALSE;
        }
        OS_Task__vResetNextTaskUnblockTime();
    }
    return (boReturn);
}

OS_Boolean_t OS_Task__boRemoveFromUnorderedEventList(OS_ListItem_t* pstEventListItem,
                                                     const OS_UBase_t xItemValue)
{
    OS_UBase_t uxSchedulerSuspended;
    OS_Boolean_t boReturn;

    /* THIS FUNCTION MUST BE CALLED WITH THE SCHEDULER SUSPENDED.  It is used by
    the event flags implementation. */
    boReturn = FALSE;
    uxSchedulerSuspended = OS_Task__uxGetSchedulerSuspended();
    if(0UL != uxSchedulerSuspended)
    {
        OS_Task_TCB_t *pstUnblockedTCB;
        OS_List__vSetItemValue(pstEventListItem,
                   xItemValue | OS_TASK_EVENT_LIST_ITEM_VALUE_IN_USE );

        pstUnblockedTCB = (OS_Task_TCB_t *) OS_List__pvGetItemOwner(pstEventListItem );
        if(0UL != (OS_Pointer_t) pstUnblockedTCB)
        {
            OS_Task_TCB_t *pstCurrentTCB;

            (void) OS_List__uxRemove(pstEventListItem);
            (void) OS_List__uxRemove(&(pstUnblockedTCB->stGenericListItem));
            OS_Task__vAddTaskToReadyList(pstUnblockedTCB);

            pstCurrentTCB = OS_Task__pstGetCurrentTCB();
            if( pstUnblockedTCB->uxPriorityTask > pstCurrentTCB->uxPriorityTask )
            {
                boReturn = TRUE;
                OS_Task__vSetYieldPending(TRUE);
            }
            else
            {
                boReturn = FALSE;
            }
        }
    }
    return (boReturn);
}

OS_UBase_t OS_Task__uxResetEventItemValue(void)
{
    OS_Task_TCB_t *pstCurrentTCB;
    OS_UBase_t uxResetValue;
    OS_UBase_t uxReturn;

    pstCurrentTCB = OS_Task__pstGetCurrentTCB();
    uxReturn = OS_List__uxGetItemValue(&(pstCurrentTCB->stEventListItem));
    uxResetValue = OS_TASK_MAX_PRIORITIES;
    uxResetValue -= pstCurrentTCB->uxPriorityTask;

    OS_List__vSetItemValue(&(pstCurrentTCB->stEventListItem), uxResetValue);
    return (uxReturn);
}
