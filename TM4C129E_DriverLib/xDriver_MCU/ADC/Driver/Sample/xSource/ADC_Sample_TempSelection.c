/**
 *
 * @file ADC_Sample_TempSelection.c
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
 * @verbatim 24 nov. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 24 nov. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/ADC/Driver/Sample/xHeader/ADC_Sample_TempSelection.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/ADC/Driver/Sample/xHeader/ADC_Sample_Generic.h>
#include <xDriver_MCU/ADC/Peripheral/ADC_Peripheral.h>

ADC_nERROR ADC_Sample__enSetTempSelectionByMask(ADC_nMODULE enModuleArg, ADC_nSEQMASK enSequencerMaskArg,
                                                ADC_nSAMPLE enSampleArg, ADC_nSTATE enStateArg)
{
    uint32_t u32SequencerReg;
    uint32_t u32SequencerMaskReg;
    ADC_nERROR enErrorReg;
    ADC_nERROR enErrorMemoryReg;

    enErrorMemoryReg = (ADC_nERROR) MCU__enCheckParams((uint32_t) enSequencerMaskArg, ((uint32_t) ADC_enSEQMASK_ALL + 1UL));
    if(ADC_enERROR_OK == enErrorMemoryReg)
    {
        u32SequencerReg = 0U;
        u32SequencerMaskReg = (uint32_t) enSequencerMaskArg;
        enErrorReg = ADC_enERROR_OK;
        while(0U != u32SequencerMaskReg)
        {
            if(0UL != (ADC_enSEQMASK_0 & u32SequencerMaskReg))
            {
                enErrorReg = ADC_Sample__enSetTempSelectionByNumber(enModuleArg, (ADC_nSEQUENCER) u32SequencerReg, enSampleArg, enStateArg);
            }

            if(ADC_enERROR_OK != enErrorReg)
            {
                enErrorMemoryReg = enErrorReg;
            }
            u32SequencerReg++;
            u32SequencerMaskReg >>= 1U;
        }
    }

    return (enErrorMemoryReg);
}

ADC_nERROR ADC_Sample__enSetTempSelectionByNumber(ADC_nMODULE enModuleArg, ADC_nSEQUENCER enSequencerArg,
                                                  ADC_nSAMPLE enSampleArg, ADC_nSTATE enStateArg)
{
    ADC_Register_t stRegister;
    ADC_nERROR enErrorReg;

    stRegister.u32Shift = ADC_SS_CTL_R_TS0_BIT;
    stRegister.u32Mask = ADC_SS_CTL_TS0_MASK;
    stRegister.uptrAddress = ADC_SS_CTL_OFFSET;
    stRegister.u32Value = (uint32_t) enStateArg;
    enErrorReg = ADC_Sample__enSetGeneric(enModuleArg, enSequencerArg, enSampleArg, &stRegister);
    return (enErrorReg);
}

ADC_nERROR ADC_Sample__enGetTempSelectionByNumber(ADC_nMODULE enModuleArg, ADC_nSEQUENCER enSequencerArg,
                                                  ADC_nSAMPLE enSampleArg, ADC_nSTATE* penStateArg)
{
    ADC_Register_t stRegister;
    ADC_nERROR enErrorReg;

    if(0UL != (uintptr_t) penStateArg)
    {
        stRegister.u32Shift = ADC_SS_CTL_R_TS0_BIT;
        stRegister.u32Mask = ADC_SS_CTL_TS0_MASK;
        stRegister.uptrAddress = ADC_SS_CTL_OFFSET;
        enErrorReg = ADC_Sample__enGetGeneric(enModuleArg, enSequencerArg, enSampleArg, &stRegister);
        if(ADC_enERROR_OK == enErrorReg)
        {
            *penStateArg = (ADC_nSTATE) stRegister.u32Value;
        }
    }
    else
    {
        enErrorReg = ADC_enERROR_POINTER;
    }
    return (enErrorReg);
}
