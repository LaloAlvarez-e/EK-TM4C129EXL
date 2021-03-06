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

#include <xOS/Task/Intrinsics/xHeader/OS_Task_Defines.h>

void OS_Task__vSuspendAll(void);
OS_Boolean_t OS_Task__boResumeAll(void);
void OS_Task__vSuspend(OS_Task_Handle_t pvTaskToSuspend);
void OS_Task__vResume(OS_Task_Handle_t pvTaskToResume);
OS_Boolean_t OS_Task__boResumeFromISR(OS_Task_Handle_t pvTaskToResume);

OS_Task_eSleepModeStatus OS_Task__enConfirmSleepModeStatus(void);

#endif /* XOS_TASK_XHEADER_OS_TASK_SUSPENDED_H_ */
