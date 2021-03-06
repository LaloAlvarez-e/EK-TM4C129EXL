/**
 *
 * @file OS_CoRoutine_Delayed.h
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
 * @verbatim 28 nov. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 28 nov. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef XOS_COROUTINE_INTRINSICS_XHEADER_OS_COROUTINE_DELAYED_H_
#define XOS_COROUTINE_INTRINSICS_XHEADER_OS_COROUTINE_DELAYED_H_

#include <xOS/CoRoutine/Intrinsics/xHeader/OS_CoRoutine_Defines.h>

OS_List_t* OS_CoRoutine__pstGetOverflowDelayedList(void);
OS_List_t* OS_CoRoutine__pstGetDelayedList(void);

void OS_CoRoutine__vSetOverflowDelayedList(OS_List_t* NewListArg);
void OS_CoRoutine__vSetDelayedList(OS_List_t* NewListArg);

void OS_CoRoutine__vInitialiseDelayedLists(void);

#endif /* XOS_COROUTINE_INTRINSICS_XHEADER_OS_COROUTINE_DELAYED_H_ */
