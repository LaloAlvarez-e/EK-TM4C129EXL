/**
 *
 * @file ADC_InterruptSource_SeqSample.c
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
 * @verbatim 22 nov. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 22 nov. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/ADC/Driver/Intrinsics/Interrupt/xHeader/ADC_InterruptSource_SeqSample.h>

#include <xDriver_MCU/Common/xHeader/MCU_CheckParams.h>
#include <xDriver_MCU/ADC/Peripheral/ADC_Peripheral.h>
#include <xDriver_MCU/ADC/Driver/Intrinsics/Primitives/ADC_Primitives.h>

static const UBase_t ADC_uxSampleMax[(UBase_t) ADC_enSEQ_MAX] =
{
    (UBase_t) ADC_enSAMPLE_MAX, (UBase_t) ADC_enSAMPLE_4, (UBase_t) ADC_enSAMPLE_4, (UBase_t) ADC_enSAMPLE_1
};

ADC_nERROR ADC_Sample__enSetInterruptSourceStateByMask(ADC_nMODULE enModuleArg, ADC_nSEQMASK enSequencerMaskArg,
                                                       ADC_nSAMPLE enSampleArg, ADC_nSTATE enStateArg)
{
    ADC_nERROR enErrorMemoryReg;
    enErrorMemoryReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enSequencerMaskArg, (UBase_t) ADC_enSEQMASK_MAX);
    if(ADC_enERROR_OK == enErrorMemoryReg)
    {
        ADC_nERROR enErrorReg = ADC_enERROR_OK;
        UBase_t uxSequencerNumReg = 0U;
        UBase_t uxSequencerMaskReg = (UBase_t) enSequencerMaskArg;
        while(0UL != uxSequencerMaskReg)
        {
            if(0UL != (((UBase_t) ADC_enSEQMASK_0) & uxSequencerMaskReg))
            {
                UBase_t uxSampleMaxReg = ADC_uxSampleMax[uxSequencerNumReg];
                enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enSampleArg, uxSampleMaxReg);
                if(ADC_enERROR_OK == enErrorReg)
                {
                    UBase_t uxSampleReg = (UBase_t) enSampleArg;
                    uxSampleReg <<= 2UL; /* each mux have 4 bits*/
                    uxSampleReg += ADC_SS_CTL_R_IE0_BIT;

                    UBase_t uxSequencerOffsetReg = uxSequencerNumReg;
                    uxSequencerOffsetReg *= ADC_SS_REGISTER_NUM; /*Add offset for input sequencer*/
                    uxSequencerOffsetReg <<= 2UL;
                    uxSequencerOffsetReg += ADC_SS_REGISTER_BASE_OFFSET;
                    uxSequencerOffsetReg += ADC_SS_CTL_OFFSET;

                    ADC_Register_t stRegister;
                    stRegister.uxShift = (UBase_t) uxSampleReg;
                    stRegister.uxMask = ADC_SS_CTL_IE0_MASK;
                    stRegister.uxValue = (UBase_t) enStateArg;
                    stRegister.uptrAddress = (uintptr_t) uxSequencerOffsetReg;
                    enErrorReg = ADC__enWriteRegister(enModuleArg, &stRegister);
                }
            }
            if(ADC_enERROR_OK != enErrorReg)
            {
                enErrorMemoryReg = enErrorReg;
            }
            uxSequencerMaskReg >>= 1U;
            uxSequencerNumReg++;
        }
    }
    return (enErrorMemoryReg);
}

ADC_nERROR ADC_Sample__enSetInterruptSourceStateByNumber(ADC_nMODULE enModuleArg, ADC_nSEQUENCER enSequencerArg,
                                                         ADC_nSAMPLE enSampleArg, ADC_nSTATE enStateArg)
{
    ADC_nERROR enErrorReg;
    enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enSequencerArg, (UBase_t) ADC_enSEQ_MAX);
    if(ADC_enERROR_OK == enErrorReg)
    {
        UBase_t uxSampleMaxReg = ADC_uxSampleMax[(UBase_t) enSequencerArg];
        enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enSampleArg, uxSampleMaxReg);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        UBase_t uxSampleReg = (UBase_t) enSampleArg;
        uxSampleReg <<= 2UL; /* each mux have 4 bits*/
        uxSampleReg += ADC_SS_CTL_R_IE0_BIT;

        UBase_t uxSequencerOffsetReg = (UBase_t) enSequencerArg;
        uxSequencerOffsetReg *= ADC_SS_REGISTER_NUM; /*Add offset for input sequencer*/
        uxSequencerOffsetReg <<= 2UL;
        uxSequencerOffsetReg += ADC_SS_REGISTER_BASE_OFFSET;
        uxSequencerOffsetReg += ADC_SS_CTL_OFFSET;

        ADC_Register_t stRegister;
        stRegister.uxShift = (UBase_t) uxSampleReg;
        stRegister.uxMask = ADC_SS_CTL_IE0_MASK;
        stRegister.uxValue = (UBase_t) enStateArg;
        stRegister.uptrAddress = (uintptr_t) uxSequencerOffsetReg;
        enErrorReg = ADC__enWriteRegister(enModuleArg, &stRegister);
    }
    return (enErrorReg);
}

ADC_nERROR ADC_Sample__enGetInterruptSourceStateByMask(ADC_nMODULE enModuleArg, ADC_nSEQMASK enSequencerMaskArg,
                                                       ADC_nSAMPLE enSampleArg, ADC_nSEQMASK* penSequencerGetArg)
{
    ADC_nERROR enErrorMemoryReg;
    enErrorMemoryReg = (0UL == (uintptr_t) penSequencerGetArg) ? ADC_enERROR_POINTER : ADC_enERROR_OK;
    if(ADC_enERROR_OK == enErrorMemoryReg)
    {
        enErrorMemoryReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enSequencerMaskArg, (UBase_t) ADC_enSEQMASK_MAX);
    }
    if(ADC_enERROR_OK == enErrorMemoryReg)
    {
        UBase_t uxSequencerGetReg = 0U;
        UBase_t uxValueReg = (UBase_t) ADC_enSEQMASK_0;
        UBase_t uxSequencerNumReg = 0U;
        UBase_t uxSequencerMaskReg = (UBase_t) enSequencerMaskArg;
        ADC_nERROR enErrorReg = ADC_enERROR_OK;
        while(0UL != uxSequencerMaskReg)
        {
            if(0UL != (((UBase_t) ADC_enSEQMASK_0) & uxSequencerMaskReg))
            {
                UBase_t uxSampleMaxReg = ADC_uxSampleMax[uxSequencerNumReg];
                enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enSampleArg, uxSampleMaxReg);
                if(ADC_enERROR_OK == enErrorReg)
                {
                    UBase_t uxSampleReg = (UBase_t) enSampleArg;
                    uxSampleReg <<= 2UL; /* each mux have 4 bits*/
                    uxSampleReg += ADC_SS_CTL_R_IE0_BIT;

                    UBase_t uxSequencerOffsetReg = uxSequencerNumReg;
                    uxSequencerOffsetReg *= ADC_SS_REGISTER_NUM; /*Add offset for input sequencer*/
                    uxSequencerOffsetReg <<= 2UL;
                    uxSequencerOffsetReg += ADC_SS_REGISTER_BASE_OFFSET;
                    uxSequencerOffsetReg += ADC_SS_CTL_OFFSET;

                    ADC_Register_t stRegister;
                    stRegister.uxShift = (UBase_t) uxSampleReg;
                    stRegister.uxMask = ADC_SS_CTL_IE0_MASK;
                    stRegister.uptrAddress = (uintptr_t) uxSequencerOffsetReg;
                    enErrorReg = ADC__enReadRegister(enModuleArg, &stRegister);
                    if((ADC_enERROR_OK == enErrorReg) && (0UL != stRegister.uxValue))
                    {
                        uxSequencerGetReg |= uxValueReg;
                    }
                }
            }
            if(ADC_enERROR_OK != enErrorReg)
            {
                enErrorMemoryReg = enErrorReg;
            }

            uxValueReg <<= 1U;
            uxSequencerMaskReg >>= 1U;
            uxSequencerNumReg++;
        }

        if(ADC_enERROR_OK == enErrorMemoryReg)
        {
            *penSequencerGetArg = (ADC_nSEQMASK ) uxSequencerGetReg;
        }
    }
    return (enErrorMemoryReg);
}

ADC_nERROR ADC_Sample__enGetInterruptSourceStateByNumber(ADC_nMODULE enModuleArg, ADC_nSEQUENCER enSequencerArg,
                                                         ADC_nSAMPLE enSampleArg, ADC_nSTATE* penStateArg)
{
    ADC_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penStateArg) ? ADC_enERROR_POINTER : ADC_enERROR_OK;
    if(ADC_enERROR_OK == enErrorReg)
    {
        enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enSequencerArg, (UBase_t) ADC_enSEQ_MAX);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        UBase_t uxSampleMaxReg = ADC_uxSampleMax[(UBase_t) enSequencerArg];
        enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enSampleArg, uxSampleMaxReg);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        UBase_t uxSampleReg = (UBase_t) enSampleArg;
        uxSampleReg <<= 2UL; /* each mux have 4 bits*/
        uxSampleReg += ADC_SS_CTL_R_IE0_BIT;

        UBase_t uxSequencerOffsetReg = (UBase_t) enSequencerArg;
        uxSequencerOffsetReg *= ADC_SS_REGISTER_NUM; /*Add offset for input sequencer*/
        uxSequencerOffsetReg <<= 2UL;
        uxSequencerOffsetReg += ADC_SS_REGISTER_BASE_OFFSET;
        uxSequencerOffsetReg += ADC_SS_CTL_OFFSET;

        ADC_Register_t stRegister;
        stRegister.uxShift = (UBase_t) uxSampleReg;
        stRegister.uxMask = ADC_SS_CTL_IE0_MASK;
        stRegister.uptrAddress = (uintptr_t) uxSequencerOffsetReg;
        enErrorReg = ADC__enWriteRegister(enModuleArg, &stRegister);
        if(ADC_enERROR_OK == enErrorReg)
        {
            *penStateArg = (ADC_nSTATE) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

ADC_nERROR ADC_Sample__enEnableInterruptSourceByMask(ADC_nMODULE enModuleArg, ADC_nSEQMASK enSequencerMaskArg,
                                                     ADC_nSAMPLE enSampleArg)
{
    ADC_nERROR enErrorReg;
    enErrorReg = ADC_Sample__enSetInterruptSourceStateByMask(enModuleArg, enSequencerMaskArg, enSampleArg, ADC_enSTATE_ENA);
    return (enErrorReg);
}

ADC_nERROR ADC_Sample__enEnableInterruptSourceByNumber(ADC_nMODULE enModuleArg, ADC_nSEQUENCER enSequencerArg,
                                                       ADC_nSAMPLE enSampleArg)
{
    ADC_nERROR enErrorReg;
    enErrorReg = ADC_Sample__enSetInterruptSourceStateByNumber(enModuleArg, enSequencerArg, enSampleArg, ADC_enSTATE_ENA);
    return (enErrorReg);
}

ADC_nERROR ADC_Sample__enDisableInterruptSourceByMask(ADC_nMODULE enModuleArg, ADC_nSEQMASK enSequencerMaskArg,
                                                      ADC_nSAMPLE enSampleArg)
{
    ADC_nERROR enErrorReg;
    enErrorReg = ADC_Sample__enSetInterruptSourceStateByMask(enModuleArg, enSequencerMaskArg, enSampleArg, ADC_enSTATE_DIS);
    return (enErrorReg);
}

ADC_nERROR ADC_Sample__enDisableInterruptSourceByNumber(ADC_nMODULE enModuleArg, ADC_nSEQUENCER enSequencerArg,
                                                        ADC_nSAMPLE enSampleArg)
{
    ADC_nERROR enErrorReg;
    enErrorReg = ADC_Sample__enSetInterruptSourceStateByNumber(enModuleArg, enSequencerArg, enSampleArg, ADC_enSTATE_DIS);
    return (enErrorReg);
}

