/**
 *
 * @file SYSTICK_Calibration.c
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
#include <xApplication_MCU/Core/SYSTICK/xHeader/SYSTICK_Calibration.h>

#include <xDriver_MCU/Core/SYSTICK/Driver/xHeader/SYSTICK_Calibration.h>
#include <xDriver_MCU/Core/SYSTICK/Peripheral/Register/xHeader/SYSTICK_RegisterAddress.h>

#define SYSTICK_CALIBRATION_PS_10MS (10000000000ULL)
#define SYSTICK_CALIBRATION_US_10MS (10000ULL)
#define SYSTICK_CALIBRATION_REFERENCE_COUNT_10MS ((uint64_t) SYSTICK_PIOSC4 / 100ULL)

SYSTICK_nERROR SYSTICK__enGetTickTimingPs(SYSTICK_nMODULE enModuleArg, UBase_t uxTickArg, UBase_t uxSystemFrequencyMHzArg,
                               uint64_t* pu64TickPicoSecondsArg, uint64_t* pu64PeriodPicoSecondsArg)
{
    SYSTICK_CALIBRATION_INFO_t stCalibrationInfo;
    SYSTICK_nERROR enErrorReg;

    enErrorReg = SYSTICK_enERROR_OK;
    if(((uint64_t*) 0UL == pu64TickPicoSecondsArg) || ((uint64_t*) 0UL == pu64PeriodPicoSecondsArg))
    {
        enErrorReg = SYSTICK_enERROR_POINTER;
    }

    if(SYSTICK_enERROR_OK == enErrorReg)
    {
         if((2UL > uxTickArg) || (SYSTICK_MAXVALUE < uxTickArg))
         {
             enErrorReg = SYSTICK_enERROR_VALUE;
         }
    }

    if(SYSTICK_enERROR_OK == enErrorReg)
    {
         if(0UL == uxSystemFrequencyMHzArg)
         {
             enErrorReg = SYSTICK_enERROR_VALUE;
         }
    }

    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        *pu64TickPicoSecondsArg = SYSTICK_CALIBRATION_PS_10MS / (uint64_t) SYSTICK_CALIBRATION_US_10MS;
        *pu64TickPicoSecondsArg += ((uint64_t) uxSystemFrequencyMHzArg / 2ULL);
        *pu64TickPicoSecondsArg /= (uint64_t) uxSystemFrequencyMHzArg;

        *pu64PeriodPicoSecondsArg = (SYSTICK_CALIBRATION_PS_10MS / (uint64_t) SYSTICK_CALIBRATION_US_10MS) * (uint64_t) uxTickArg;
        *pu64PeriodPicoSecondsArg += ((uint64_t) uxSystemFrequencyMHzArg / 2ULL);
        *pu64PeriodPicoSecondsArg /= (uint64_t) uxSystemFrequencyMHzArg;

        stCalibrationInfo.uxCalibrationCount10Ms = 0UL;
        stCalibrationInfo.uxCalibrationCount1Ms = 0UL;
        stCalibrationInfo.u64CalibrationTickPs = 0ULL;
        stCalibrationInfo.enSkew = SYSTICK_enSKEW_UNDEF;
        stCalibrationInfo.enReference = SYSTICK_enREFERENCE_UNDEF;
        
        SYSTICK_nERROR enCalibrationErrorReg = SYSTICK__enGetTrustedCalibrationInfo(enModuleArg, &stCalibrationInfo);
        
        if(SYSTICK_enERROR_OK == enCalibrationErrorReg)
        {
            const uint64_t u64CalibrationCountReg = (uint64_t) stCalibrationInfo.uxCalibrationCount10Ms;

            *pu64TickPicoSecondsArg *= SYSTICK_CALIBRATION_REFERENCE_COUNT_10MS;
            *pu64TickPicoSecondsArg += (u64CalibrationCountReg / 2ULL);
            *pu64TickPicoSecondsArg /= u64CalibrationCountReg;

            *pu64PeriodPicoSecondsArg *= SYSTICK_CALIBRATION_REFERENCE_COUNT_10MS;
            *pu64PeriodPicoSecondsArg += (u64CalibrationCountReg / 2ULL);
            *pu64PeriodPicoSecondsArg /= u64CalibrationCountReg;
        }
    }


    return (enErrorReg);
}

static SYSTICK_nERROR SYSTICK__enGetCalibrationCount10Ms(SYSTICK_nMODULE enModuleArg, uint64_t* pu64CountArg);

static SYSTICK_nERROR SYSTICK__enGetCalibrationCount10Ms(SYSTICK_nMODULE enModuleArg, uint64_t* pu64CountArg)
{
    SYSTICK_nERROR enErrorReg;
    UBase_t uxCalibrationCountReg;

    uxCalibrationCountReg = 0UL;
    enErrorReg = (0UL == (uintptr_t) pu64CountArg) ? SYSTICK_enERROR_POINTER : SYSTICK_enERROR_OK;
    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSTICK__enGetCalibrationValue(enModuleArg, &uxCalibrationCountReg);
    }

    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        if(0UL == uxCalibrationCountReg)
        {
            enErrorReg = SYSTICK_enERROR_VALUE;
        }
    }

    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        *pu64CountArg = (uint64_t) uxCalibrationCountReg;
    }
    return (enErrorReg);
}

SYSTICK_nERROR SYSTICK__enGetCalibrationInfo(SYSTICK_nMODULE enModuleArg, SYSTICK_CALIBRATION_INFO_t* pstInfoArg)
{
    SYSTICK_nERROR enErrorReg;
    uint64_t u64CalibrationCountReg;
    uint64_t u64CalibrationCount1MsReg;

    u64CalibrationCountReg = 0ULL;
    u64CalibrationCount1MsReg = 0ULL;
    enErrorReg = (0UL == (uintptr_t) pstInfoArg) ? SYSTICK_enERROR_POINTER : SYSTICK_enERROR_OK;
    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSTICK__enGetCalibrationCount10Ms(enModuleArg, &u64CalibrationCountReg);
    }
    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSTICK__enGetCalibrationSkew(enModuleArg, &pstInfoArg->enSkew);
    }
    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSTICK__enGetCalibrationReference(enModuleArg, &pstInfoArg->enReference);
    }
    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        u64CalibrationCount1MsReg = u64CalibrationCountReg + 5ULL;
        u64CalibrationCount1MsReg /= 10ULL;
        if((0ULL == u64CalibrationCount1MsReg) || (SYSTICK_VALUEMAX < u64CalibrationCount1MsReg))
        {
            enErrorReg = SYSTICK_enERROR_RANGE;
        }
    }
    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        pstInfoArg->uxCalibrationCount10Ms = (UBase_t) u64CalibrationCountReg;
        pstInfoArg->uxCalibrationCount1Ms = (UBase_t) u64CalibrationCount1MsReg;
        pstInfoArg->u64CalibrationTickPs = SYSTICK_CALIBRATION_PS_10MS;
        pstInfoArg->u64CalibrationTickPs += (u64CalibrationCountReg / 2ULL);
        pstInfoArg->u64CalibrationTickPs /= (uint64_t) pstInfoArg->uxCalibrationCount10Ms;
    }
    return (enErrorReg);
}

SYSTICK_nERROR SYSTICK__enGetTrustedCalibrationInfo(SYSTICK_nMODULE enModuleArg, SYSTICK_CALIBRATION_INFO_t* pstInfoArg)
{
    SYSTICK_nERROR enErrorReg;
    
    enErrorReg = (0UL == (uintptr_t) pstInfoArg) ? SYSTICK_enERROR_POINTER : SYSTICK_enERROR_OK;
    /* Only trust CALIB when it is exact and reference-backed; the count deviation from the nominal basis becomes the correction factor. */
    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSTICK__enGetCalibrationInfo(enModuleArg, pstInfoArg);
    }

    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        if((SYSTICK_enSKEW_EXACT         != pstInfoArg->enSkew) || 
           (SYSTICK_enREFERENCE_EXTERNAL != pstInfoArg->enReference))
        {
            enErrorReg = SYSTICK_enERROR_VALUE;
        }
    }
    return (enErrorReg);
}

SYSTICK_nERROR SYSTICK__enGetTickCountUs(SYSTICK_nMODULE enModuleArg, UBase_t uxTimeUsArg, UBase_t uxSystemFrequencyMHzArg,
                                         UBase_t* puxTickArg)
{
    SYSTICK_CALIBRATION_INFO_t stCalibrationInfo;
    SYSTICK_nERROR enErrorReg;
    uint64_t u64TickCountReg;

    stCalibrationInfo.uxCalibrationCount10Ms = 0UL;
    stCalibrationInfo.uxCalibrationCount1Ms = 0UL;
    stCalibrationInfo.u64CalibrationTickPs = 0ULL;
    stCalibrationInfo.enSkew = SYSTICK_enSKEW_UNDEF;
    stCalibrationInfo.enReference = SYSTICK_enREFERENCE_UNDEF;
    u64TickCountReg = (uint64_t) uxSystemFrequencyMHzArg * (uint64_t) uxTimeUsArg;


    enErrorReg = (0UL == (uintptr_t) puxTickArg) ? SYSTICK_enERROR_POINTER : SYSTICK_enERROR_OK;

    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        if(0UL == uxTimeUsArg)
        {
            enErrorReg = SYSTICK_enERROR_VALUE;
        }
    }

    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        if(0UL == uxSystemFrequencyMHzArg)
        {
            enErrorReg = SYSTICK_enERROR_VALUE;
        }
    }

    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        *puxTickArg = (UBase_t) u64TickCountReg;
        
        SYSTICK_nERROR enCalibrationErrorReg = SYSTICK__enGetTrustedCalibrationInfo(enModuleArg, &stCalibrationInfo);
        if(SYSTICK_enERROR_OK == enCalibrationErrorReg)
        {
            u64TickCountReg *= (uint64_t) stCalibrationInfo.uxCalibrationCount10Ms;
            u64TickCountReg += (SYSTICK_CALIBRATION_REFERENCE_COUNT_10MS / 2ULL);
            u64TickCountReg /= SYSTICK_CALIBRATION_REFERENCE_COUNT_10MS;
            *puxTickArg = (UBase_t) u64TickCountReg;
        }
    }

    return (enErrorReg);
}

SYSTICK_nERROR SYSTICK__enGetCalibrationReloadUs(SYSTICK_nMODULE enModuleArg, UBase_t uxTimeUsArg, UBase_t* puxReloadArg)
{
    SYSTICK_nERROR enErrorReg;
    uint64_t u64CalibrationCountReg;
    uint64_t u64TickCountReg;

    u64CalibrationCountReg = 0ULL;
    u64TickCountReg = 0ULL;
    enErrorReg = (0UL == (uintptr_t) puxReloadArg) ? SYSTICK_enERROR_POINTER : SYSTICK_enERROR_OK;

    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        if(0UL == uxTimeUsArg)
        {
            enErrorReg = SYSTICK_enERROR_VALUE;
        }
    }

    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSTICK__enGetCalibrationCount10Ms(enModuleArg, &u64CalibrationCountReg);
    }

    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        u64TickCountReg = u64CalibrationCountReg * (uint64_t) uxTimeUsArg;
        u64TickCountReg += (SYSTICK_CALIBRATION_US_10MS / 2ULL);
        u64TickCountReg /= SYSTICK_CALIBRATION_US_10MS;
        if((0ULL == u64TickCountReg) || (SYSTICK_VALUEMAX < u64TickCountReg))
        {
            enErrorReg = SYSTICK_enERROR_RANGE;
        }
    }

    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        *puxReloadArg = (UBase_t) (u64TickCountReg - 1ULL);
    }

    return (enErrorReg);
}

SYSTICK_nERROR SYSTICK__enGetCalibrationTimeUs(SYSTICK_nMODULE enModuleArg, UBase_t uxReloadArg, UBase_t* puxTimeUsArg)
{
    SYSTICK_nERROR enErrorReg;
    uint64_t u64CalibrationCountReg;
    uint64_t u64TimeUsReg;

    u64CalibrationCountReg = 0ULL;
    u64TimeUsReg = 0ULL;
    enErrorReg = (0UL == (uintptr_t) puxTimeUsArg) ? SYSTICK_enERROR_POINTER : SYSTICK_enERROR_OK;

    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        if(SYSTICK_VALUEMAX < ((uint64_t) uxReloadArg + 1ULL))
        {
            enErrorReg = SYSTICK_enERROR_RANGE;
        }
    }

    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSTICK__enGetCalibrationCount10Ms(enModuleArg, &u64CalibrationCountReg);
    }
    
    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        u64TimeUsReg = ((uint64_t) uxReloadArg + 1ULL) * SYSTICK_CALIBRATION_US_10MS;
        u64TimeUsReg += (u64CalibrationCountReg / 2ULL);
        u64TimeUsReg /= u64CalibrationCountReg;
        *puxTimeUsArg = (UBase_t) u64TimeUsReg;
    }
    return (enErrorReg);
}