/**
 *
 * @file SYSCTL_BootConfig.h
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

#ifndef D47BCE91_D40D_426F_9D97_6233D044EEE6
#define D47BCE91_D40D_426F_9D97_6233D044EEE6
#ifndef XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_DRIVER_SYSCTL_BOOTCONFIG_H_
#define XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_DRIVER_SYSCTL_BOOTCONFIG_H_

#include <xDriver_MCU/SYSCTL/Peripheral/xHeader/SYSCTL_Enum.h>

SYSCTL_nERROR SYSCTL__enGetBootConfigDebug0(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStateArg);
SYSCTL_nERROR SYSCTL__enGetBootConfigDebug1(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStateArg);
SYSCTL_nERROR SYSCTL__enGetBootConfigKey(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStateArg);
SYSCTL_nERROR SYSCTL__enGetBootConfigGPIOEnable(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStateArg);
SYSCTL_nERROR SYSCTL__enGetBootConfigGPIOPolarity(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStateArg);
SYSCTL_nERROR SYSCTL__enGetBootConfigGPIOPin(SYSCTL_nMODULE enModuleArg, UBase_t* puxPinArg);
SYSCTL_nERROR SYSCTL__enGetBootConfigGPIOPort(SYSCTL_nMODULE enModuleArg, UBase_t* puxPortArg);
SYSCTL_nERROR SYSCTL__enGetBootConfigNotWritten(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStateArg);

#endif /* XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_DRIVER_SYSCTL_BOOTCONFIG_H_ */


#endif /* D47BCE91_D40D_426F_9D97_6233D044EEE6 */
