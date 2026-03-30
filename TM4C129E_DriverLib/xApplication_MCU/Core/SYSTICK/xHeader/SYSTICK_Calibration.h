/**
 *
 * @file SYSTICK_Calibration.h
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
 * @verbatim 29 mar. 2026 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 29 mar. 2026     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef XAPPLICATION_MCU_CORE_SYSTICK_XHEADER_SYSTICK_CALIBRATION_H_
#define XAPPLICATION_MCU_CORE_SYSTICK_XHEADER_SYSTICK_CALIBRATION_H_

#include <xApplication_MCU/Core/SYSTICK/Intrinsics/xHeader/SYSTICK_Defines.h>

typedef struct
{
    UBase_t uxCalibrationCount10Ms;
    UBase_t uxCalibrationCount1Ms;
    uint64_t u64CalibrationTickPs;
    SYSTICK_nSKEW enSkew;
    SYSTICK_nREFERENCE enReference;
} SYSTICK_CALIBRATION_INFO_t;

SYSTICK_nERROR SYSTICK__enGetTickTimingPs(SYSTICK_nMODULE enModuleArg, UBase_t uxTickArg, UBase_t uxSystemFrequencyMHzArg,
                               uint64_t* pu64TickPicoSecondsArg, uint64_t* pu64PeriodPicoSecondsArg);
SYSTICK_nERROR SYSTICK__enGetCalibrationInfo(SYSTICK_nMODULE enModuleArg, SYSTICK_CALIBRATION_INFO_t* pstInfoArg);
SYSTICK_nERROR SYSTICK__enGetTrustedCalibrationInfo(SYSTICK_nMODULE enModuleArg, SYSTICK_CALIBRATION_INFO_t* pstInfoArg);
SYSTICK_nERROR SYSTICK__enGetTickCountUs(SYSTICK_nMODULE enModuleArg, UBase_t uxTimeUsArg, UBase_t uxSystemFrequencyMHzArg,
                                         UBase_t* puxTickArg);
SYSTICK_nERROR SYSTICK__enGetCalibrationReloadUs(SYSTICK_nMODULE enModuleArg, UBase_t uxTimeUsArg, UBase_t* puxReloadArg);
SYSTICK_nERROR SYSTICK__enGetCalibrationTimeUs(SYSTICK_nMODULE enModuleArg, UBase_t uxReloadArg, UBase_t* puxTimeUsArg);

#endif /* XAPPLICATION_MCU_CORE_SYSTICK_XHEADER_SYSTICK_CALIBRATION_H_ */
