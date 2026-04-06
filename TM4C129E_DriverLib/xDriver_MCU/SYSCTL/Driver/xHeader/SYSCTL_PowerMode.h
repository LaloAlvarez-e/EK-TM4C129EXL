/**
 *
 * @file SYSCTL_PowerMode.h
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

#ifndef XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_DRIVER_SYSCTL_POWERMODE_H_
#define XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_DRIVER_SYSCTL_POWERMODE_H_

#include <xDriver_MCU/SYSCTL/Peripheral/xHeader/SYSCTL_Enum.h>

SYSCTL_nERROR SYSCTL__enSetSRAMPowerModeOnSleepMode(SYSCTL_nMODULE enModuleArg,
                                                    SYSCTL_nSRAM_POWER_MODE enPowerModeArg);
SYSCTL_nERROR SYSCTL__enGetSRAMPowerModeOnSleepMode(SYSCTL_nMODULE enModuleArg,
                                                    SYSCTL_nSRAM_POWER_MODE* penPowerModeArg);

SYSCTL_nERROR SYSCTL__enSetFlashPowerModeOnSleepMode(SYSCTL_nMODULE enModuleArg,
                                                     SYSCTL_nFLASH_POWER_MODE enPowerModeArg);
SYSCTL_nERROR SYSCTL__enGetFlashPowerModeOnSleepMode(SYSCTL_nMODULE enModuleArg,
                                                     SYSCTL_nFLASH_POWER_MODE* penPowerModeArg);

SYSCTL_nERROR SYSCTL__enSetPowerModeOnSleepMode(SYSCTL_nMODULE enModuleArg,
                                                SYSCTL_nSRAM_POWER_MODE enSRAMPowerModeArg,
                                                SYSCTL_nFLASH_POWER_MODE enFlashPowerModeArg);
SYSCTL_nERROR SYSCTL__enGetPowerModeOnSleepMode(SYSCTL_nMODULE enModuleArg,
                                                SYSCTL_nSRAM_POWER_MODE* penSRAMPowerModeArg,
                                                SYSCTL_nFLASH_POWER_MODE* penFlashPowerModeArg);

SYSCTL_nERROR SYSCTL__enSetSRAMPowerModeOnDeepSleepMode(SYSCTL_nMODULE enModuleArg,
                                                        SYSCTL_nSRAM_POWER_MODE enPowerModeArg);
SYSCTL_nERROR SYSCTL__enGetSRAMPowerModeOnDeepSleepMode(SYSCTL_nMODULE enModuleArg,
                                                        SYSCTL_nSRAM_POWER_MODE* penPowerModeArg);

SYSCTL_nERROR SYSCTL__enSetFlashPowerModeOnDeepSleepMode(SYSCTL_nMODULE enModuleArg,
                                                         SYSCTL_nFLASH_POWER_MODE enPowerModeArg);
SYSCTL_nERROR SYSCTL__enGetFlashPowerModeOnDeepSleepMode(SYSCTL_nMODULE enModuleArg,
                                                         SYSCTL_nFLASH_POWER_MODE* penPowerModeArg);

SYSCTL_nERROR SYSCTL__enSetPowerModeOnDeepSleepMode(SYSCTL_nMODULE enModuleArg,
                                                    SYSCTL_nSRAM_POWER_MODE enSRAMPowerModeArg,
                                                    SYSCTL_nFLASH_POWER_MODE enFlashPowerModeArg);
SYSCTL_nERROR SYSCTL__enGetPowerModeOnDeepSleepMode(SYSCTL_nMODULE enModuleArg,
                                                    SYSCTL_nSRAM_POWER_MODE* penSRAMPowerModeArg,
                                                    SYSCTL_nFLASH_POWER_MODE* penFlashPowerModeArg);

SYSCTL_nERROR SYSCTL__enUseTempSensorPowerDownOnDeepSleepMode(SYSCTL_nMODULE enModuleArg,
                                                              SYSCTL_nSTATE enStateArg);
SYSCTL_nERROR SYSCTL__enIsTempSensorPowerDownOnDeepSleepModeUsed(SYSCTL_nMODULE enModuleArg,
                                                                 SYSCTL_nBOOLEAN* penStateArg);

SYSCTL_nERROR SYSCTL__enUseLDOSleepModeOnDeepSleepMode(SYSCTL_nMODULE enModuleArg,
                                                       SYSCTL_nSTATE enStateArg);
SYSCTL_nERROR SYSCTL__enIsLDOSleepModeOnDeepSleepModeUsed(SYSCTL_nMODULE enModuleArg,
                                                          SYSCTL_nBOOLEAN* penStateArg);

SYSCTL_nERROR SYSCTL__enIsSRAMPowerDownRequestError(SYSCTL_nMODULE enModuleArg,
                                                    SYSCTL_nBOOLEAN* penStatusArg);
SYSCTL_nERROR SYSCTL__enIsFlashPowerDownRequestError(SYSCTL_nMODULE enModuleArg,
                                                     SYSCTL_nBOOLEAN* penStatusArg);
SYSCTL_nERROR SYSCTL__enIsPIOSCPowerDownRequestError(SYSCTL_nMODULE enModuleArg,
                                                     SYSCTL_nBOOLEAN* penStatusArg);
SYSCTL_nERROR SYSCTL__enIsDeepSleepLDOMinimumVoltageError(SYSCTL_nMODULE enModuleArg,
                                                          SYSCTL_nBOOLEAN* penStatusArg);
SYSCTL_nERROR SYSCTL__enIsSleepLDOMinimumVoltageError(SYSCTL_nMODULE enModuleArg,
                                                      SYSCTL_nBOOLEAN* penStatusArg);
SYSCTL_nERROR SYSCTL__enIsLDOMaximumVoltageError(SYSCTL_nMODULE enModuleArg,
                                                 SYSCTL_nBOOLEAN* penStatusArg);
SYSCTL_nERROR SYSCTL__enIsPIOSCPowerDownRequestWarning(SYSCTL_nMODULE enModuleArg,
                                                       SYSCTL_nBOOLEAN* penStatusArg);
SYSCTL_nERROR SYSCTL__enIsPowerModeRequestActive(SYSCTL_nMODULE enModuleArg,
                                                 SYSCTL_nBOOLEAN* penStatusArg);
SYSCTL_nERROR SYSCTL__enIsLowPowerModeActive(SYSCTL_nMODULE enModuleArg,
                                             SYSCTL_nBOOLEAN* penStatusArg);
SYSCTL_nERROR SYSCTL__enIsFlashLowPowerModeActive(SYSCTL_nMODULE enModuleArg,
                                                  SYSCTL_nBOOLEAN* penStatusArg);
SYSCTL_nERROR SYSCTL__enIsLDOUpdateActive(SYSCTL_nMODULE enModuleArg,
                                          SYSCTL_nBOOLEAN* penStatusArg);

#endif /* XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_DRIVER_SYSCTL_POWERMODE_H_ */
