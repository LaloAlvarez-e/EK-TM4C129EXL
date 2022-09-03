/**
 *
 * @file SCB_PendSV.h
 * @copyright
 * @verbatim InDeviceMex 2020 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 19 jun. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 19 jun. 2020     vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_DRIVER_HEADER_SCB_SCB_DRIVER_SCB_PENDSV_H_
#define XDRIVER_MCU_DRIVER_HEADER_SCB_SCB_DRIVER_SCB_PENDSV_H_

#include <xDriver_MCU/Core/SCB/Peripheral/xHeader/SCB_Enum.h>

void SCB_PendSV__vSetPending(void);
void SCB_PendSV__vClearPending(void);
SCB_nPENDSTATE SCB_PendSV__enGetPending(void);

void SCB_PendSV__vSetPriority(SCB_nPRIORITY enPendSVPriority);
SCB_nPRIORITY SCB_PendSV__enGetPriority(void);

#endif /* XDRIVER_MCU_DRIVER_HEADER_SCB_SCB_DRIVER_SCB_PENDSV_H_ */
