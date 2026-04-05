/*
 * SYSCTL_SystemClock.c
 *
 *  Created on: 15 jun. 2021
 *      Author: InDeviceMex
 */
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_SystemClock.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_MemoryTiming.h>
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_GatingClock.h>
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_AlternateClock.h>
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_MainOsc.h>
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_OutputClock.h>
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_PLLCLock.h>
#include <xDriver_MCU/SYSCTL/Driver/Intrinsics/SYSCTL_Intrinsics.h>
#include <xDriver_MCU/SYSCTL/Peripheral/SYSCTL_Peripheral.h>

#define SYSCTL_TIMEOUT ((UBase_t) 1000000UL)

#define SYSCTL_PLL_M_INT_INDEX (0UL)
#define SYSCTL_PLL_M_FRAC_INDEX (1UL)
#define SYSCTL_N_INDEX (2UL)
#define SYSCTL_Q_INDEX (3UL)
#define SYSCTL_DIV_INDEXMAX (4UL)

#define SYSCTL_enMOSCFrequency (SYSCTL_enXTAL_25MHZ)
#define SYSCTL_uxPIOSCFrequency (16000000UL)
#define SYSCTL_uxLFIOSCFrequency (33000UL)

static SYSCTL_nERROR SYSCTL_enGetMOSCFrequencyGeneric(SYSCTL_nXTAL enXtalArg, UBase_t* puxXtalFrequencyArg);
static SYSCTL_nERROR SYSCTL_enGetMOSCAvailableFrequency(SYSCTL_nMODULE enModuleArg, UBase_t* puxFrequencyArg);
static SYSCTL_nERROR SYSCTL_enGetDivValueByVCOAndXTAL(SYSCTL_nVCO enVcoRangeArg, SYSCTL_nXTAL enXtalArg, UBase_t uxRequestArg, UBase_t* puxResponseArg);

static SYSCTL_nERROR SYSCTL_enGetDivValueByVCOAndXTAL(SYSCTL_nVCO enVcoRangeArg, SYSCTL_nXTAL enXtalArg, UBase_t uxRequestArg, UBase_t* puxResponseArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL_enERROR_OK;
    if (((UBase_t) SYSCTL_enXTAL_MAX <= (UBase_t) enXtalArg)    ||
        ((UBase_t) SYSCTL_enVCO_MAX <= (UBase_t) enVcoRangeArg) ||
        (SYSCTL_DIV_INDEXMAX <= uxRequestArg))
    {
        enErrorReg = SYSCTL_enERROR_VALUE;
    }

    if((SYSCTL_enERROR_OK == enErrorReg) && (0UL == (uintptr_t) puxResponseArg))
    {
        enErrorReg = SYSCTL_enERROR_POINTER;
    }

    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        static const uint16_t uxXTALtoVCOReg[(UBase_t) SYSCTL_enVCO_MAX][(UBase_t) SYSCTL_enXTAL_MAX][SYSCTL_DIV_INDEXMAX] =
        {
            {/* VCO 320 MHz */
                { 64U , 0U  , (1U - 1U), (1U - 1U) },     /* Inv */
                { 64U , 0U  , (1U - 1U), (1U - 1U) },     /* Inv */
                { 64U , 0U  , (1U - 1U), (1U - 1U) },     /* Inv */
                { 64U , 0U  , (1U - 1U), (1U - 1U) },     /* Inv */
                { 64U , 0U  , (1U - 1U), (1U - 1U) },     /* Inv */
                { 64U , 0U  , (1U - 1U), (1U - 1U) },     /* Inv */
                { 64U , 0U  , (1U - 1U), (1U - 1U) },     /* Inv */
                { 64U , 0U  , (1U - 1U), (1U - 1U) },     /* Inv */
                { 64U , 0U  , (1U - 1U), (1U - 1U) },     /* Inv */
                { 64U , 0U  , (1U - 1U), (1U - 1U) },     /* 5 MHz */
                { 62U , 512U, (1U - 1U), (1U - 1U) },     /* 5.12 MHz */
                { 160U, 0U  , (3U - 1U), (1U - 1U) },     /* 6 MHz */
                { 52U , 85U , (1U - 1U), (1U - 1U) },     /* 6.144 MHz */
                { 43U , 412U, (1U - 1U), (1U - 1U) },     /* 7.3728 MHz */
                { 40U , 0U  , (1U - 1U), (1U - 1U) },     /* 8 MHz */
                { 39U , 64U , (1U - 1U), (1U - 1U) },     /* 8.192 MHz */
                { 32U , 0U  , (1U - 1U), (1U - 1U) },     /* 10 MHz */
                { 80U , 0U  , (3U - 1U), (1U - 1U) },     /* 12 MHz */
                { 26U , 43U , (1U - 1U), (1U - 1U) },     /* 12.288 MHz */
                { 23U , 613U, (1U - 1U), (1U - 1U) },     /* 13.56 MHz */
                { 22U , 358U, (1U - 1U), (1U - 1U) },     /* 14.318180 MHz */
                { 20U , 0U  , (1U - 1U), (1U - 1U) },     /* 16 MHz */
                { 19U , 544U, (1U - 1U), (1U - 1U) },     /* 16.384 MHz */
                { 160U, 0U  , (9U - 1U), (1U - 1U) },     /* 18 MHz */
                { 16U , 0U  , (1U - 1U), (1U - 1U) },     /* 20 MHz */
                { 40U , 0U  , (3U - 1U), (1U - 1U) },     /* 24 MHz */
                { 64U , 0U  , (5U - 1U), (1U - 1U) },     /* 25 MHz */
            },
            {/* VCO 480 MHz */
                { 96U , 0U  , (1U - 1U), (1U - 1U) },     /* Inv */
                { 96U , 0U  , (1U - 1U), (1U - 1U) },     /* Inv */
                { 96U , 0U  , (1U - 1U), (1U - 1U) },     /* Inv */
                { 96U , 0U  , (1U - 1U), (1U - 1U) },     /* Inv */
                { 96U , 0U  , (1U - 1U), (1U - 1U) },     /* Inv */
                { 96U , 0U  , (1U - 1U), (1U - 1U) },     /* Inv */
                { 96U , 0U  , (1U - 1U), (1U - 1U) },     /* Inv */
                { 96U , 0U  , (1U - 1U), (1U - 1U) },     /* Inv */
                { 96U , 0U  , (1U - 1U), (1U - 1U) },     /* Inv */
                { 96U , 0U  , (1U - 1U), (1U - 1U) },     /* 5 MHz */
                { 93U , 768U, (1U - 1U), (1U - 1U) },     /* 5.12 MHz */
                { 80U , 0U  , (1U - 1U), (1U - 1U) },     /* 6 MHz */
                { 78U , 128U, (1U - 1U), (1U - 1U) },     /* 6.144 MHz */
                { 65U , 107U, (1U - 1U), (1U - 1U) },     /* 7.3728 MHz */
                { 60U , 0U  , (1U - 1U), (1U - 1U) },     /* 8 MHz */
                { 58U , 608U, (1U - 1U), (1U - 1U) },     /* 8.192 MHz */
                { 48U , 0U  , (1U - 1U), (1U - 1U) },     /* 10 MHz */
                { 40U , 0U  , (1U - 1U), (1U - 1U) },     /* 12 MHz */
                { 39U , 64U , (1U - 1U), (1U - 1U) },     /* 12.288 MHz */
                { 35U , 408U, (1U - 1U), (1U - 1U) },     /* 13.56 MHz */
                { 33U , 536U, (1U - 1U), (1U - 1U) },     /* 14.318180 MHz */
                { 30U , 0U  , (1U - 1U), (1U - 1U) },     /* 16 MHz */
                { 29U , 304U, (1U - 1U), (1U - 1U) },     /* 16.384 MHz */
                { 80U , 0U  , (3U - 1U), (1U - 1U) },     /* 18 MHz */
                { 24U , 0U  , (1U - 1U), (1U - 1U) },     /* 20 MHz */
                { 20U , 0U  , (1U - 1U), (1U - 1U) },     /* 24 MHz */
                { 96U , 0U  , (5U - 1U), (1U - 1U) },     /* 25 MHz */
            },
        };
        *puxResponseArg = (UBase_t) uxXTALtoVCOReg[(UBase_t) enVcoRangeArg][(UBase_t) enXtalArg][uxRequestArg];
    }
    return (enErrorReg);
}

static SYSCTL_nERROR SYSCTL_enGetMOSCFrequencyGeneric(SYSCTL_nXTAL enXtalArg, UBase_t* puxXtalFrequencyArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = ((UBase_t) SYSCTL_enXTAL_MAX <= (UBase_t) enXtalArg) ? SYSCTL_enERROR_VALUE : SYSCTL_enERROR_OK;

    if((SYSCTL_enERROR_OK == enErrorReg) && (0UL == (uintptr_t) puxXtalFrequencyArg))
    {
        enErrorReg = SYSCTL_enERROR_POINTER;
    }

    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        static const UBase_t uxFreqXtalReg [(UBase_t) SYSCTL_enXTAL_MAX]=
        {
          1000000UL , 1843200UL , 2000000UL , 2457600UL , 3579545UL , 3686400UL ,
          4000000UL , 4096000UL , 4915200UL , 5000000UL , 5120000UL , 6000000UL ,
          6144000UL , 7372800UL , 8000000UL , 8192000UL , 10000000UL, 12000000UL,
          12288000UL, 13560000UL, 14318180UL, 16000000UL, 16384000UL, 18000000UL,
          20000000UL, 24000000UL, 25000000UL
        };
        *puxXtalFrequencyArg = uxFreqXtalReg[(UBase_t) enXtalArg];
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enGetPIOSCFrequency(UBase_t* puxFrequencyArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) puxFrequencyArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        *puxFrequencyArg = SYSCTL_uxPIOSCFrequency;
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enGetMOSCFrequency(UBase_t* puxFrequencyArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL_enGetMOSCFrequencyGeneric(SYSCTL_enMOSCFrequency, puxFrequencyArg);
    return (enErrorReg);
}

static SYSCTL_nERROR SYSCTL_enGetMOSCAvailableFrequency(SYSCTL_nMODULE enModuleArg, UBase_t* puxFrequencyArg)
{
    SYSCTL_nERROR enErrorReg;
    SYSCTL_nSTATE enMOSCStateReg;
    SYSCTL_nSTATE enMOSCPowerStateReg;
    enErrorReg = (0UL == (uintptr_t) puxFrequencyArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;

    enMOSCStateReg = SYSCTL_enSTATE_DIS;
    enMOSCPowerStateReg = SYSCTL_enSTATE_DIS;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetMOSCState(enModuleArg, &enMOSCStateReg);
    }

    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetMOSCPowerState(enModuleArg, &enMOSCPowerStateReg);
    }

    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        if((SYSCTL_enSTATE_ENA == enMOSCStateReg) && (SYSCTL_enSTATE_ENA == enMOSCPowerStateReg))
        {
            enErrorReg = SYSCTL__enGetMOSCFrequency(puxFrequencyArg);
        }
        else
        {
            *puxFrequencyArg = 0UL;
        }
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enGetLFIOSCFrequency(UBase_t* puxFrequencyArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) puxFrequencyArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        *puxFrequencyArg = SYSCTL_uxLFIOSCFrequency;
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enGetVCOClockFrequency(SYSCTL_nMODULE enModuleArg, UBase_t *puxVCOFrequency)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) puxVCOFrequency) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;

    SYSCTL_nOSCCLK_SRC enPLLClockSourceReg;
    enPLLClockSourceReg = SYSCTL_enOSCCLK_SRC_PIOSC;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
         enErrorReg = SYSCTL__enGetPLLClockSource(enModuleArg, &enPLLClockSourceReg);
    }

    UBase_t uxFrequencyClockReg = 0UL;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        if(SYSCTL_enOSCCLK_SRC_PIOSC == enPLLClockSourceReg)
        {
            enErrorReg = SYSCTL__enGetPIOSCFrequency(&uxFrequencyClockReg);
        }
        else if(SYSCTL_enOSCCLK_SRC_MOSC == enPLLClockSourceReg)
        {
            enErrorReg = SYSCTL_enGetMOSCAvailableFrequency(enModuleArg, &uxFrequencyClockReg);
        }
        else
        {
            enErrorReg = SYSCTL_enERROR_VALUE;
        }
    }

    UBase_t uxPLLNValueReg = 0UL;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetPLLClockValue_N(enModuleArg, &uxPLLNValueReg);
    }

    UBase_t uxPLLQValueReg = 0UL;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetPLLClockValue_Q(enModuleArg, &uxPLLQValueReg);
    }

    UBase_t uxPLLMIntegerValueReg = 0UL;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetPLLClockIntegerValue_M(enModuleArg, &uxPLLMIntegerValueReg);
    }

    UBase_t uxPLLMFractionalValueReg = 0UL;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetPLLClockFractionalValue_M(enModuleArg, &uxPLLMFractionalValueReg);
    }

    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        uxPLLNValueReg += 1UL;
        uxPLLQValueReg += 1UL;

        uint64_t u64FrequencyInReg = uxPLLMIntegerValueReg;
        u64FrequencyInReg *= 1024UL;
        u64FrequencyInReg += uxPLLMFractionalValueReg;
        u64FrequencyInReg *= uxFrequencyClockReg;
        u64FrequencyInReg /= 1024UL;
        u64FrequencyInReg /= uxPLLNValueReg;
        u64FrequencyInReg /= uxPLLQValueReg;

        *puxVCOFrequency =  (UBase_t) u64FrequencyInReg;
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enGetAlternateClockFrequency(SYSCTL_nMODULE enModuleArg, UBase_t* puxFrequencyArg)
{

    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) puxFrequencyArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;

    SYSCTL_nALTCLK_SRC enClockSourceReg;
    enClockSourceReg = SYSCTL_enALTCLK_SRC_PIOSC;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetAlternateClockSource(enModuleArg, &enClockSourceReg);
    }

    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        UBase_t uxFrequencyReg = 0UL;
        switch(enClockSourceReg)
        {
        case SYSCTL_enALTCLK_SRC_PIOSC:
            enErrorReg = SYSCTL__enGetPIOSCFrequency(&uxFrequencyReg);
            break;
        case SYSCTL_enALTCLK_SRC_RTCOSC:
            uxFrequencyReg = 32768UL;
            break;
        case SYSCTL_enALTCLK_SRC_LFIOSC:
            enErrorReg = SYSCTL__enGetLFIOSCFrequency(&uxFrequencyReg);
            break;
        default:
            uxFrequencyReg = 0UL;
            enErrorReg = SYSCTL_enERROR_VALUE;
            break;
        }
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            *puxFrequencyArg = (UBase_t) uxFrequencyReg;
        }
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enGetOscillatorFrequency(SYSCTL_nMODULE enModuleArg, UBase_t* puxFrequencyArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) puxFrequencyArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;

    SYSCTL_nOSCCLK_SRC enClockSourceReg;
    enClockSourceReg = SYSCTL_enOSCCLK_SRC_PIOSC;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetOscillatorClockSource(enModuleArg, &enClockSourceReg);
    }

    UBase_t uxDivisorReg = 0UL;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetOscillatorClockDivisor(enModuleArg, &uxDivisorReg);
    }

    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        UBase_t uxFrequencyReg = 0UL;
        switch(enClockSourceReg)
        {
        case SYSCTL_enOSCCLK_SRC_PIOSC:
            enErrorReg = SYSCTL__enGetPIOSCFrequency(&uxFrequencyReg);
            break;
        case SYSCTL_enOSCCLK_SRC_RTCOSC:
            uxFrequencyReg = 32768UL;
            break;
        case SYSCTL_enOSCCLK_SRC_MOSC:
            enErrorReg = SYSCTL_enGetMOSCAvailableFrequency(enModuleArg, &uxFrequencyReg);
            break;
        case SYSCTL_enOSCCLK_SRC_LFIOSC:
            enErrorReg = SYSCTL__enGetLFIOSCFrequency(&uxFrequencyReg);
            break;
        default:
            uxFrequencyReg = 0UL;
            enErrorReg = SYSCTL_enERROR_VALUE;
            break;
        }
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            uxDivisorReg += 1UL;
            uxFrequencyReg /= uxDivisorReg;
            *puxFrequencyArg = (UBase_t) uxFrequencyReg;
        }
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enGetOutputClockFrequency(SYSCTL_nMODULE enModuleArg, UBase_t* puxFrequencyArg)
{

    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) puxFrequencyArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;

    SYSCTL_nOUTCLK_SRC enClockSourceReg;
    enClockSourceReg = SYSCTL_enOUTCLK_SRC_SYSCLK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetOutputClockSource(enModuleArg, &enClockSourceReg);
    }

    UBase_t uxDivisorReg = 0UL;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetOutputClockDivisor(enModuleArg, &uxDivisorReg);
    }

    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        UBase_t uxFrequencyReg = 0UL;
        switch(enClockSourceReg)
        {
        case SYSCTL_enOUTCLK_SRC_PIOSC:
            enErrorReg = SYSCTL__enGetPIOSCFrequency(&uxFrequencyReg);
            break;
        case SYSCTL_enOUTCLK_SRC_MOSC:
            enErrorReg = SYSCTL_enGetMOSCAvailableFrequency(enModuleArg, &uxFrequencyReg);
            break;
        case SYSCTL_enOUTCLK_SRC_SYSCLK:
            enErrorReg = SYSCTL__enGetSystemClockFrequency(enModuleArg, &uxFrequencyReg);
            break;
        default:
            uxFrequencyReg = 0UL;
            enErrorReg = SYSCTL_enERROR_VALUE;
            break;
        }
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            uxDivisorReg += 1UL;
            uxFrequencyReg /= uxDivisorReg;
            *puxFrequencyArg = (UBase_t) uxFrequencyReg;
        }
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enGetPLLClockFrequency(SYSCTL_nMODULE enModuleArg, UBase_t* puxFrequencyArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) puxFrequencyArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;

    UBase_t uxVCOFreqReg;
    uxVCOFreqReg = 0UL;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetVCOClockFrequency(enModuleArg, &uxVCOFreqReg);
    }

    UBase_t uxDivisorReg = 0UL;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetPLLClockDivisor(enModuleArg, &uxDivisorReg);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        uxDivisorReg += 1UL;
        uxVCOFreqReg /= uxDivisorReg;
        *puxFrequencyArg = (UBase_t) uxVCOFreqReg;
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enGetSystemClockFrequency(SYSCTL_nMODULE enModuleArg, UBase_t* puxFrequencyArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) puxFrequencyArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;

    SYSCTL_nSYSCLK_SRC enClockSourceReg;
    enClockSourceReg = SYSCTL_enSYSCLK_SRC_OSCCLK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetSystemClockSource(enModuleArg, &enClockSourceReg);
    }

    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        UBase_t uxFrequencyReg = 0UL;
        enErrorReg = (SYSCTL_enSYSCLK_SRC_OSCCLK == enClockSourceReg) ?
                SYSCTL__enGetOscillatorFrequency(enModuleArg, &uxFrequencyReg):
                SYSCTL__enGetPLLClockFrequency(enModuleArg, &uxFrequencyReg);
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            *puxFrequencyArg = uxFrequencyReg;
        }
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enSetSystemClock(SYSCTL_nMODULE enModuleArg, UBase_t uxSystemClockArg, const SYSCTL_CONFIG_t* pstClockConfig, UBase_t uxTimeoutArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL_enERROR_OK;
    if((0UL == uxSystemClockArg) || (120000000UL < uxSystemClockArg))
    {
        enErrorReg = SYSCTL_enERROR_VALUE;
    }

    if((SYSCTL_enERROR_OK == enErrorReg) && (0UL == (uintptr_t) pstClockConfig))
    {
        enErrorReg = SYSCTL_enERROR_POINTER;
    }

    SYSCTL_nSYSCLK_SRC enSystemClkReg = SYSCTL_enSYSCLK_SRC_OSCCLK;
    SYSCTL_nOSCCLK_SRC enOscSoruceReg = SYSCTL_enOSCCLK_SRC_PIOSC;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enOscSoruceReg = pstClockConfig->enOscillatorSource;
        enSystemClkReg = pstClockConfig->enSystemClockSource;
    }

    SYSCTL_nXTAL enCrystalReg = SYSCTL_enXTAL_1MHZ;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        if(SYSCTL_enOSCCLK_SRC_MOSC == enOscSoruceReg)
        {
            enCrystalReg = pstClockConfig->enExternalCrystal;
        }
        if(SYSCTL_enOSCCLK_SRC_PIOSC == enOscSoruceReg)
        {
            enCrystalReg = SYSCTL_enXTAL_16MHZ;
        }
    }


    if((SYSCTL_enERROR_OK          == enErrorReg     ) &&
       (SYSCTL_enSYSCLK_SRC_PLLCLK ==  enSystemClkReg) &&
       ((SYSCTL_enOSCCLK_SRC_MOSC != enOscSoruceReg)    && (SYSCTL_enOSCCLK_SRC_PIOSC != enOscSoruceReg)))
    {
        enErrorReg = SYSCTL_enERROR_VALUE;
    }

    if((SYSCTL_enERROR_OK        == enErrorReg    )    &&
       (SYSCTL_enOSCCLK_SRC_MOSC == enOscSoruceReg)    &&
       (((UBase_t) SYSCTL_enXTAL_5MHZ  > enCrystalReg) || ((UBase_t) SYSCTL_enXTAL_25MHZ < enCrystalReg) ))
    {
        enErrorReg = SYSCTL_enERROR_VALUE;
    }

    if((SYSCTL_enERROR_OK == enErrorReg) && (SYSCTL_enOSCCLK_SRC_MOSC == enOscSoruceReg))
    {
        enErrorReg = ((UBase_t) SYSCTL_enXTAL_10MHZ <= enCrystalReg) ?
                SYSCTL__enSetMOSCFrequencyRange(enModuleArg, SYSCTL_enMOSC_RANGE_HIGH):
                SYSCTL__enSetMOSCFrequencyRange(enModuleArg, SYSCTL_enMOSC_RANGE_LOW);
    }

    if((SYSCTL_enERROR_OK == enErrorReg) && (SYSCTL_enOSCCLK_SRC_MOSC == enOscSoruceReg))
    {
        enErrorReg = SYSCTL__enSetMOSCState(enModuleArg, SYSCTL_enSTATE_ENA);
    }
    if((SYSCTL_enERROR_OK == enErrorReg) && (SYSCTL_enOSCCLK_SRC_MOSC == enOscSoruceReg))
    {
        enErrorReg = SYSCTL__enSetMOSCPowerState(enModuleArg, SYSCTL_enSTATE_ENA);
    }

    if((SYSCTL_enERROR_OK == enErrorReg) && (SYSCTL_enOSCCLK_SRC_MOSC == enOscSoruceReg))
    {
        if(uxTimeoutArg == 0UL)
        {
            SYSCTL_nSTATUS enStatusReg = SYSCTL_enSTATUS_INACTIVE;
            do
            {
                enErrorReg = SYSCTL__enStatusInterruptSourceByNumber(enModuleArg, SYSCTL_enINT_MOSC_POWERUP, &enStatusReg);
            }while((SYSCTL_enSTATUS_INACTIVE == enStatusReg) && (SYSCTL_enERROR_OK == enErrorReg));
        }
        else
        {
            SYSCTL_nSTATUS enStatusReg = SYSCTL_enSTATUS_INACTIVE;
            UBase_t uxTimeout = uxTimeoutArg;
            do
            {
                enErrorReg = SYSCTL__enStatusInterruptSourceByNumber(enModuleArg, SYSCTL_enINT_MOSC_POWERUP, &enStatusReg);
                uxTimeout -= 1UL;
            }while((SYSCTL_enSTATUS_INACTIVE == enStatusReg) && (SYSCTL_enERROR_OK == enErrorReg) && (0UL != uxTimeout));

            if((SYSCTL_enSTATUS_INACTIVE == enStatusReg) && (SYSCTL_enERROR_OK == enErrorReg) && (0UL == uxTimeout))
            {
                enErrorReg = SYSCTL_enERROR_TIMEOUT;
            }
        }
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enSetMemoryTiming(enModuleArg, 120000000UL); /*ste at max due to configure a new clock is necessary to change to PIOSC*/
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enUpdateMemoryTiming(enModuleArg);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enSetOscillatorClockSource(enModuleArg, SYSCTL_enOSCCLK_SRC_PIOSC);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enSetOscillatorClockDivisor(enModuleArg, 0UL);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enSetSystemClockSource(enModuleArg, SYSCTL_enSYSCLK_SRC_OSCCLK);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enSetMemoryTiming(enModuleArg, 16000000UL);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enUpdateMemoryTiming(enModuleArg);
    }
    if((SYSCTL_enERROR_OK == enErrorReg) && (SYSCTL_enSYSCLK_SRC_OSCCLK ==  enSystemClkReg))
    {
        enErrorReg = SYSCTL__enSetOscillatorClockSource(enModuleArg, enOscSoruceReg);
        UBase_t uxSystemFrequencyReg = 0UL;
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            enErrorReg = SYSCTL__enGetOscillatorFrequency(enModuleArg, &uxSystemFrequencyReg);
        }
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            UBase_t uxDivisorReg = uxSystemFrequencyReg;
            uxDivisorReg /= uxSystemClockArg;
            if(0UL != uxDivisorReg)
            {
                uxSystemFrequencyReg = uxSystemFrequencyReg / uxDivisorReg;
                uxDivisorReg -= 1UL;
            }
            enErrorReg = SYSCTL__enSetOscillatorClockDivisor(enModuleArg, uxDivisorReg);
        }
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            enErrorReg = SYSCTL__enSetMemoryTiming(enModuleArg, uxSystemFrequencyReg);
        }
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            enErrorReg = SYSCTL__enSetPLLClockState(enModuleArg, SYSCTL_enSTATE_DIS);
        }
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            enErrorReg = SYSCTL__enUpdateMemoryTiming(enModuleArg);
        }
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            enErrorReg = SYSCTL__enSetSystemClockSource(enModuleArg, SYSCTL_enSYSCLK_SRC_OSCCLK);
        }
    }

    if((SYSCTL_enERROR_OK == enErrorReg) && (SYSCTL_enSYSCLK_SRC_PLLCLK ==  enSystemClkReg))
    {
        SYSCTL_nVCO enVcoRangeReg = pstClockConfig->enVCORange;
        UBase_t uxPLLMIntegerReg = 0UL;
        enErrorReg = SYSCTL_enGetDivValueByVCOAndXTAL(enVcoRangeReg, enCrystalReg, SYSCTL_PLL_M_INT_INDEX, &uxPLLMIntegerReg);

        UBase_t uxPLLMFractionalReg = 0UL;
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            enErrorReg = SYSCTL_enGetDivValueByVCOAndXTAL(enVcoRangeReg, enCrystalReg, SYSCTL_PLL_M_FRAC_INDEX, &uxPLLMFractionalReg);
        }
        UBase_t uxPLLNValueReg = 0UL;
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            enErrorReg = SYSCTL_enGetDivValueByVCOAndXTAL(enVcoRangeReg, enCrystalReg, SYSCTL_N_INDEX, &uxPLLNValueReg);
        }
        UBase_t uxPLLQValueReg = 0UL;
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            enErrorReg = SYSCTL_enGetDivValueByVCOAndXTAL(enVcoRangeReg, enCrystalReg, SYSCTL_Q_INDEX, &uxPLLQValueReg);
        }
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            enErrorReg = SYSCTL__enSetPLLClockIntegerValue_M(enModuleArg, uxPLLMIntegerReg);
        }
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            enErrorReg = SYSCTL__enSetPLLClockFractionalValue_M(enModuleArg, uxPLLMFractionalReg);
        }
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            enErrorReg = SYSCTL__enSetPLLClockValue_N(enModuleArg, uxPLLNValueReg);
        }
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            enErrorReg = SYSCTL__enSetPLLClockValue_Q(enModuleArg, uxPLLQValueReg);
        }
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            enErrorReg = SYSCTL__enSetPLLClockSource(enModuleArg, enOscSoruceReg);
        }
        UBase_t uxSystemFrequencyReg = 0UL;
        UBase_t uxPLLDivisorReg = 0UL;
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            enErrorReg = SYSCTL__enGetVCOClockFrequency(enModuleArg, &uxSystemFrequencyReg);
            if(SYSCTL_enERROR_OK == enErrorReg)
            {
                uxPLLDivisorReg = uxSystemFrequencyReg;
                uxPLLDivisorReg /= uxSystemClockArg;
                if(0UL != uxPLLDivisorReg)
                {
                    uxSystemFrequencyReg /= uxPLLDivisorReg;
                    uxPLLDivisorReg -= 1UL;
                }
                enErrorReg = SYSCTL__enSetMemoryTiming(enModuleArg, uxSystemFrequencyReg);
            }
        }
        SYSCTL_nSTATE enPllState = SYSCTL_enSTATE_DIS;
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            enErrorReg = SYSCTL__enGetPLLClockState(enModuleArg, &enPllState);
        }
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            enErrorReg = (SYSCTL_enSTATE_DIS == enPllState) ?
                    SYSCTL__enSetPLLClockState(enModuleArg, SYSCTL_enSTATE_ENA) :
                    SYSCTL__enUpdatePLLValues(enModuleArg);
        }

        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            if(uxTimeoutArg == 0UL)
            {
                SYSCTL_nBOOLEAN enPllLocked = SYSCTL_enFALSE;
                do
                {
                    enErrorReg = SYSCTL__enIsPLLClockLocked(enModuleArg, &enPllLocked);
                }while((SYSCTL_enFALSE == enPllLocked) && (SYSCTL_enERROR_OK == enErrorReg));
            }
            else
            {
                SYSCTL_nBOOLEAN enPllLocked = SYSCTL_enFALSE;
                UBase_t uxTimeout = uxTimeoutArg;
                do
                {
                    enErrorReg = SYSCTL__enIsPLLClockLocked(enModuleArg, &enPllLocked);
                    uxTimeout -= 1UL;
                }while((SYSCTL_enFALSE == enPllLocked) && (SYSCTL_enERROR_OK == enErrorReg) && (0UL != uxTimeout));

                if((SYSCTL_enFALSE == enPllLocked) && (SYSCTL_enERROR_OK == enErrorReg) && (0UL == uxTimeout))
                {
                    enErrorReg = SYSCTL_enERROR_TIMEOUT;
                }
            }
        }

        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            enErrorReg = SYSCTL__enSetPLLClockDivisor(enModuleArg, uxPLLDivisorReg);
        }
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            enErrorReg = SYSCTL__enUpdateMemoryTiming(enModuleArg);
        }
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            enErrorReg = SYSCTL__enSetSystemClockSource(enModuleArg, SYSCTL_enSYSCLK_SRC_PLLCLK);
        }
    }

    return (enErrorReg);
}
