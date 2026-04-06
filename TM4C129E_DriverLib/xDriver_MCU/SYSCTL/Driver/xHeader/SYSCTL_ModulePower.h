/**
 *
 * @file SYSCTL_ModulePower.h
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

#ifndef XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_DRIVER_SYSCTL_MODULEPOWER_H_
#define XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_DRIVER_SYSCTL_MODULEPOWER_H_

#include <xDriver_MCU/SYSCTL/Peripheral/xHeader/SYSCTL_Enum.h>

SYSCTL_nERROR SYSCTL__enSetModuleMemoryPowerControlState(SYSCTL_nMODULE enModuleArg,
                                                         SYSCTL_nPERIPHERAL enPeripheralArg,
                                                         SYSCTL_nMODULE_MEMORY_POWER enPowerControlArg);
SYSCTL_nERROR SYSCTL__enGetModuleMemoryPowerControlState(SYSCTL_nMODULE enModuleArg,
                                                         SYSCTL_nPERIPHERAL enPeripheralArg,
                                                         SYSCTL_nMODULE_MEMORY_POWER* penPowerControlArg);

SYSCTL_nERROR SYSCTL__enPowerOnModuleMemory(SYSCTL_nMODULE enModuleArg,
                                            SYSCTL_nPERIPHERAL enPeripheralArg);
SYSCTL_nERROR SYSCTL__enPowerOffModuleMemory(SYSCTL_nMODULE enModuleArg,
                                             SYSCTL_nPERIPHERAL enPeripheralArg);
SYSCTL_nERROR SYSCTL__enRetainModuleMemory(SYSCTL_nMODULE enModuleArg,
                                           SYSCTL_nPERIPHERAL enPeripheralArg);

SYSCTL_nERROR SYSCTL__enGetModulePowerState(SYSCTL_nMODULE enModuleArg,
                                            SYSCTL_nPERIPHERAL enPeripheralArg,
                                            SYSCTL_nMODULE_POWER_STATUS* penPowerStateArg);
SYSCTL_nERROR SYSCTL__enGetModuleMemoryState(SYSCTL_nMODULE enModuleArg,
                                             SYSCTL_nPERIPHERAL enPeripheralArg,
                                             SYSCTL_nMODULE_MEMORY_POWER* penMemoryStateArg);

#endif /* XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_DRIVER_SYSCTL_MODULEPOWER_H_ */
