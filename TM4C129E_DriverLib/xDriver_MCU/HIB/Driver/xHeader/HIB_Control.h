/**
 *
 * @file HIB_Control.h
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
 * @verbatim 6 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 6 abr. 2026    vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_HIB_DRIVER_XHEADER_HIB_CONTROL_H_
#define XDRIVER_MCU_HIB_DRIVER_XHEADER_HIB_CONTROL_H_

#include <xDriver_MCU/HIB/Peripheral/xHeader/HIB_Enum.h>

HIB_nERROR HIB__enSetWakeRTCState(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg);
HIB_nERROR HIB__enGetWakeRTCState(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg);

HIB_nERROR HIB__enSetWakePinState(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg);
HIB_nERROR HIB__enGetWakePinState(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg);

HIB_nERROR HIB__enSetWakeBatteryState(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg);
HIB_nERROR HIB__enGetWakeBatteryState(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg);

HIB_nERROR HIB__enSetWakeUnlockState(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg);
HIB_nERROR HIB__enGetWakeUnlockState(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg);

HIB_nERROR HIB__enSetWakeResetState(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg);
HIB_nERROR HIB__enGetWakeResetState(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg);

HIB_nERROR HIB__enGetWakePinPresence(HIB_nMODULE enModuleArg, HIB_nWAKE_PIN* penStateArg);

HIB_nERROR HIB__enSetClock32State(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg);
HIB_nERROR HIB__enGetClock32State(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg);

HIB_nERROR HIB__enSetSystemClockState(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg);
HIB_nERROR HIB__enGetSystemClockState(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg);

HIB_nERROR HIB__enSetOscillator(HIB_nMODULE enModuleArg, HIB_nOSC enStateArg);
HIB_nERROR HIB__enGetOscillator(HIB_nMODULE enModuleArg, HIB_nOSC* penStateArg);

HIB_nERROR HIB__enSetOscillatorDrive(HIB_nMODULE enModuleArg, HIB_nOSC_DRIVE enStateArg);
HIB_nERROR HIB__enGetOscillatorDrive(HIB_nMODULE enModuleArg, HIB_nOSC_DRIVE* penStateArg);

HIB_nERROR HIB__enSetOscillatorBypassState(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg);
HIB_nERROR HIB__enGetOscillatorBypassState(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg);

HIB_nERROR HIB__enSetBatteryThreshold(HIB_nMODULE enModuleArg, HIB_nVBAT enStateArg);
HIB_nERROR HIB__enGetBatteryThreshold(HIB_nMODULE enModuleArg, HIB_nVBAT* penStateArg);

HIB_nERROR HIB__enStartBatteryCheck(HIB_nMODULE enModuleArg);

HIB_nERROR HIB__enSetAbortState(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg);
HIB_nERROR HIB__enGetAbortState(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg);

HIB_nERROR HIB__enSetVDD3ONState(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg);
HIB_nERROR HIB__enGetVDD3ONState(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg);

HIB_nERROR HIB__enSetRetentionState(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg);
HIB_nERROR HIB__enGetRetentionState(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg);

HIB_nERROR HIB__enRequestHibernate(HIB_nMODULE enModuleArg);

#endif /* XDRIVER_MCU_HIB_DRIVER_XHEADER_HIB_CONTROL_H_ */
