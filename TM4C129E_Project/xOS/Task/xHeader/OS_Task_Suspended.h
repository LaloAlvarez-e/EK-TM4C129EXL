/**
 *
 * @file OS_Task_Suspended.h
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
 * @verbatim 15 jul. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 15 jul. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef XOS_TASK_XHEADER_OS_TASK_SUSPENDED_H_
#define XOS_TASK_XHEADER_OS_TASK_SUSPENDED_H_

#include <xOS/Task/xHeader/OS_Task_Defines.h>

void OS_Task__vInitialiseSuspendedTaskLists(void);
void OS_Task__vTaskSuspendAll(void);
uint32_t OS_Task__u32TaskResumeAll(void);

uint32_t OS_Task__u32GetPendedTicks(void);
void OS_Task__vSetPendedTicks(uint32_t u32ValueArg);
void OS_Task__vIncreasePendedTicks(void);

uint32_t OS_Task__u32GetYieldPending(void);
void OS_Task__vSetYieldPending(uint32_t s32ValueArg);

#endif /* XOS_TASK_XHEADER_OS_TASK_SUSPENDED_H_ */