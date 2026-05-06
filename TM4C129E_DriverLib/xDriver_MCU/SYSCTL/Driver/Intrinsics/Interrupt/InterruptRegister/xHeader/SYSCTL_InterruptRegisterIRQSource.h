/**
 *
 * @file SYSCTL_InterruptRegisterIRQSource.h
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
 * @verbatim 17 feb. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 17 feb. 2021     vyldram    1.0         initial Version@endverbatim
 */
#ifndef XDRIVER_MCU_SYSCTL_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTREGISTER_XHEADER_SYSCTL_INTERRUPTREGISTERIRQSOURCE_H_
#define XDRIVER_MCU_SYSCTL_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTREGISTER_XHEADER_SYSCTL_INTERRUPTREGISTERIRQSOURCE_H_

#include <xDriver_MCU/SYSCTL/Peripheral/xHeader/SYSCTL_Enum.h>

SYSCTL_nERROR SYSCTL__enRegisterIRQSourceHandler(SYSCTL_nMODULE enModuleArg, SYSCTL_nINT enInterruptSourceArg, SYSCTL_pvfIRQSourceHandler_t pfIrqSourceHandler);

#endif /* XDRIVER_MCU_SYSCTL_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTREGISTER_XHEADER_SYSCTL_INTERRUPTREGISTERIRQSOURCE_H_ */
