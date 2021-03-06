/**
 *
 * @file SYSCTL_InterruptRoutine_Source.h
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

#ifndef XDRIVER_MCU_SYSCTL_DRIVER_INTERRUPT_INTERRUPTROUTINE_XHEADER_SYSCTL_INTERRUPTROUTINE_SOURCE_H_
#define XDRIVER_MCU_SYSCTL_DRIVER_INTERRUPT_INTERRUPTROUTINE_XHEADER_SYSCTL_INTERRUPTROUTINE_SOURCE_H_

#include <xDriver_MCU/SYSCTL/Peripheral/xHeader/SYSCTL_Enum.h>

void (*SYSCTL__pvfGetIRQSourceHandler(SYSCTL_nINTERRUPT enInterruptSourceArg))(void);
void (**SYSCTL__pvfGetIRQSourceHandlerPointer(SYSCTL_nINTERRUPT enInterruptSourceArg))(void);

#endif /* XDRIVER_MCU_SYSCTL_DRIVER_INTERRUPT_INTERRUPTROUTINE_XHEADER_SYSCTL_INTERRUPTROUTINE_SOURCE_H_ */
