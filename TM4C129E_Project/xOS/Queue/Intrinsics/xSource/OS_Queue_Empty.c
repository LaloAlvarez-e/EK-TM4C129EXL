/**
 *
 * @file OS_Queue_Empty.c
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
 * @verbatim 4 oct. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 4 oct. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xOS/Queue/Intrinsics/xHeader/OS_Queue_Empty.h>
#include <xOS/Task/OS_Task.h>

OS_Boolean_t OS_Queue__boIsQueueEmpty(const OS_Queue_t* pstQueue)
{
    OS_Boolean_t boReturn;
    boReturn = TRUE;
    if(0UL != (OS_Pointer_t) pstQueue)
    {
        OS_Task__vEnterCritical();
        {
            boReturn = (0UL == pstQueue->uxMessagesWaiting) ? TRUE : FALSE;
        }
        OS_Task__vExitCritical();
    }
    return (boReturn);
}

OS_Boolean_t OS_Queue__boIsQueueEmptyFromISR(const OS_Queue_Handle_t* const pstQueue)
{
    const OS_Queue_t* pstQueueReg = ( const OS_Queue_t*) pstQueue;
    OS_Boolean_t boReturn;
    boReturn = TRUE;
    if(0UL != (OS_Pointer_t) pstQueue)
    {
        boReturn = (0UL == pstQueueReg->uxMessagesWaiting) ? TRUE : FALSE;
    }
    return (boReturn);
}
