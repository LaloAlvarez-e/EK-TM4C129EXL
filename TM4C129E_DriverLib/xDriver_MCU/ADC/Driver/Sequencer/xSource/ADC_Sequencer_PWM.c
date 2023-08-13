/**
 *
 * @file ADC_Sequencer_PWM.c
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
#include <xDriver_MCU/ADC/Driver/Sequencer/xHeader/ADC_Sequencer_PWM.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/ADC/Driver/Intrinsics/ADC_Intrinsics.h>
#include <xDriver_MCU/ADC/Peripheral/ADC_Peripheral.h>

ADC_nERROR ADC_Sequencer__enSetPWMTriggerByMask(ADC_nMODULE enModuleArg, ADC_nSEQMASK enSequencerMaskArg,
                                              ADC_nSEQ_PWM enPWMTriggerArg)
{
    ADC_nERROR enErrorReg;
    enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enSequencerMaskArg, (UBase_t) ADC_enSEQMASK_MAX);
    if(ADC_enERROR_OK == enErrorReg)
    {
        UBase_t uxSequencerReg = 0U;
        UBase_t uxSequencerMaskReg = (UBase_t) enSequencerMaskArg;
        while((0U != uxSequencerMaskReg) && (ADC_enERROR_OK == enErrorReg))
        {
            if(0UL != ((UBase_t) ADC_enSEQMASK_0 & uxSequencerMaskReg))
            {
                enErrorReg = ADC_Sequencer__enSetPWMTriggerByNumber(enModuleArg, (ADC_nSEQUENCER) uxSequencerReg, enPWMTriggerArg);
            }
            uxSequencerReg++;
            uxSequencerMaskReg >>= 1U;
        }
    }
    return (enErrorReg);
}

ADC_nERROR ADC_Sequencer__enSetPWMTriggerByNumber(ADC_nMODULE enModuleArg, ADC_nSEQUENCER enSequencerArg,
                                                ADC_nSEQ_PWM enPWMTriggerArg)
{
    ADC_nERROR enErrorReg;
    enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enSequencerArg, (UBase_t) ADC_enSEQ_MAX);
    if(ADC_enERROR_OK == enErrorReg)
    {
        ADC_Register_t stRegister;
        stRegister.uxShift = (UBase_t) enSequencerArg;
        stRegister.uxShift *= (ADC_TSSEL_R_PS1_BIT - ADC_TSSEL_R_PS0_BIT);
        stRegister.uxShift += ADC_TSSEL_R_PS0_BIT;
        stRegister.uxMask = ADC_TSSEL_PS0_MASK;
        stRegister.uptrAddress = ADC_TSSEL_OFFSET;
        stRegister.uxValue = (UBase_t) enPWMTriggerArg;
        enErrorReg = ADC__enWriteRegister(enModuleArg, &stRegister);
    }
    return (enErrorReg);
}

ADC_nERROR ADC_Sequencer__enGetPWMTriggerByNumber(ADC_nMODULE enModuleArg, ADC_nSEQUENCER enSequencerArg,
                                                       ADC_nSEQ_PWM* penPWMTriggerArg)
{
    ADC_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penPWMTriggerArg) ? ADC_enERROR_POINTER : ADC_enERROR_OK;

    if(ADC_enERROR_OK == enErrorReg)
    {
        enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enSequencerArg, (UBase_t) ADC_enSEQ_MAX);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        ADC_Register_t stRegister;
        stRegister.uxShift = (UBase_t) enSequencerArg;
        stRegister.uxShift *= (ADC_TSSEL_R_PS1_BIT - ADC_TSSEL_R_PS0_BIT);
        stRegister.uxShift += ADC_TSSEL_R_PS0_BIT;
        stRegister.uxMask = ADC_TSSEL_PS0_MASK;
        stRegister.uptrAddress = ADC_TSSEL_OFFSET;
        enErrorReg = ADC__enReadRegister(enModuleArg, &stRegister);
        if(ADC_enERROR_OK == enErrorReg)
        {
            *penPWMTriggerArg = (ADC_nSEQ_PWM) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}
