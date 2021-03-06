/**
 *
 * @file SYSCTL_InterruptSource.h
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
 * @verbatim 16 jun. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 16 jun. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_SYSCTL_DRIVER_INTERRUPT_XHEADER_SYSCTL_INTERRUPTSOURCE_H_
#define XDRIVER_MCU_SYSCTL_DRIVER_INTERRUPT_XHEADER_SYSCTL_INTERRUPTSOURCE_H_

#include <xDriver_MCU/SYSCTL/Peripheral/xHeader/SYSCTL_Enum.h>

void SYSCTL__vEnInterruptSource(SYSCTL_nINT_SOURCE enSourceInt);
void SYSCTL__vDisInterruptSource(SYSCTL_nINT_SOURCE enSourceInt);
void SYSCTL__vClearInterruptSource(SYSCTL_nINT_SOURCE enSourceInt);
SYSCTL_nINT_SOURCE SYSCTL__enStatusInterruptSource(SYSCTL_nINT_SOURCE enSourceInt);

#endif /* XDRIVER_MCU_SYSCTL_DRIVER_INTERRUPT_XHEADER_SYSCTL_INTERRUPTSOURCE_H_ */
