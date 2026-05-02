/**
 *
 * @file HIB_Tamper.h
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

#ifndef XDRIVER_MCU_HIB_DRIVER_XHEADER_HIB_TAMPER_H_
#define XDRIVER_MCU_HIB_DRIVER_XHEADER_HIB_TAMPER_H_

#include <xDriver_MCU/HIB/Peripheral/xHeader/HIB_Enum.h>

HIB_nERROR HIB__enIsTamperPresent(HIB_nMODULE enModuleArg, HIB_nBOOLEAN* penPresentArg);

HIB_nERROR HIB__enSetTamperState(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg);
HIB_nERROR HIB__enGetTamperState(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg);

HIB_nERROR HIB__enSetTamperWakeState(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg);
HIB_nERROR HIB__enGetTamperWakeState(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg);

HIB_nERROR HIB__enSetTamperMemoryClear(HIB_nMODULE enModuleArg, HIB_nTAMPER_MEMCLR enStateArg);
HIB_nERROR HIB__enGetTamperMemoryClear(HIB_nMODULE enModuleArg, HIB_nTAMPER_MEMCLR* penStateArg);

HIB_nERROR HIB__enClearTamperEvent(HIB_nMODULE enModuleArg);

HIB_nERROR HIB__enSetTamperPinState(HIB_nMODULE enModuleArg, HIB_nTAMPER enTamperArg, HIB_nSTATE enStateArg);
HIB_nERROR HIB__enGetTamperPinState(HIB_nMODULE enModuleArg, HIB_nTAMPER enTamperArg, HIB_nSTATE* penStateArg);

HIB_nERROR HIB__enSetTamperPinLevel(HIB_nMODULE enModuleArg, HIB_nTAMPER enTamperArg, HIB_nTAMPER_LEVEL enLevelArg);
HIB_nERROR HIB__enGetTamperPinLevel(HIB_nMODULE enModuleArg, HIB_nTAMPER enTamperArg, HIB_nTAMPER_LEVEL* penLevelArg);

HIB_nERROR HIB__enSetTamperPinPullupState(HIB_nMODULE enModuleArg, HIB_nTAMPER enTamperArg, HIB_nSTATE enStateArg);
HIB_nERROR HIB__enGetTamperPinPullupState(HIB_nMODULE enModuleArg, HIB_nTAMPER enTamperArg, HIB_nSTATE* penStateArg);

HIB_nERROR HIB__enSetTamperPinGlitchState(HIB_nMODULE enModuleArg, HIB_nTAMPER enTamperArg, HIB_nTAMPER_GLITCH enStateArg);
HIB_nERROR HIB__enGetTamperPinGlitchState(HIB_nMODULE enModuleArg, HIB_nTAMPER enTamperArg, HIB_nTAMPER_GLITCH* penStateArg);

HIB_nERROR HIB__enGetTamperStatus(HIB_nMODULE enModuleArg, HIB_nTAMPER_STATUS* penStatusArg);
HIB_nERROR HIB__enGetTamperXOscState(HIB_nMODULE enModuleArg, HIB_nSTATUS* penStatusArg);
HIB_nERROR HIB__enGetTamperXOscFailure(HIB_nMODULE enModuleArg, HIB_nSTATUS* penStatusArg);

HIB_nERROR HIB__enGetTamperLog(HIB_nMODULE enModuleArg, HIB_nTAMPER enTamperArg, HIB_TAMPER_LOG_t* pstLogArg);

#endif /* XDRIVER_MCU_HIB_DRIVER_XHEADER_HIB_TAMPER_H_ */
