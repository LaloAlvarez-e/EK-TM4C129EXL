/**
 *
 * @file SYSCTL_SystemProperties.h
 * @copyright
 * @verbatim InDeviceMex 2026 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 5 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 5 abr. 2026    GitHub Copilot   1.0         initial Version@endverbatim
 */
#ifndef XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_DRIVER_SYSCTL_SYSTEMPROPERTIES_H_
#define XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_DRIVER_SYSCTL_SYSTEMPROPERTIES_H_

#include <xDriver_MCU/SYSCTL/Peripheral/xHeader/SYSCTL_Enum.h>

SYSCTL_nERROR SYSCTL__enIsFPUPresent(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStateArg);
SYSCTL_nERROR SYSCTL__enIsLDOSequenceSupported(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStateArg);
SYSCTL_nERROR SYSCTL__enIsFlashLowPowerModeSupported(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStateArg);
SYSCTL_nERROR SYSCTL__enIsSRAMLowPowerModeSupported(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStateArg);
SYSCTL_nERROR SYSCTL__enIsSRAMStandbyModeSupported(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStateArg);
SYSCTL_nERROR SYSCTL__enIsPIOSCPowerDownModeSupported(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStateArg);
SYSCTL_nERROR SYSCTL__enIsTempSensorPowerDownModeSupported(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStateArg);
SYSCTL_nERROR SYSCTL__enIsLDOSleepModeSupported(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStateArg);

#endif /* XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_DRIVER_SYSCTL_SYSTEMPROPERTIES_H_ */
