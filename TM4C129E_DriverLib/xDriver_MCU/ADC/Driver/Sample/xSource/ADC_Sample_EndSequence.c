/**
 *
 * @file ADC_Sample_EndSequence.c
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
#include <xDriver_MCU/ADC/Driver/Sample/xHeader/ADC_Sample_EndSequence.h>

#include <xDriver_MCU/ADC/Driver/Sample/xHeader/ADC_Sample_Generic.h>
#include <xDriver_MCU/ADC/Peripheral/ADC_Peripheral.h>

void ADC_Sample__vSetEndSequence(ADC_nMODULE enModule, ADC_nSEQUENCER enSequencer,
                                ADC_nMUX enMux, ADC_nSEQ_INPUT_ENDED enSampleEndSequence)
{
    ADC_Sample__vSetGeneric((uint32_t) enModule, (uint32_t) enSequencer, ADC_SS_CTL_OFFSET,
                           (uint32_t) enMux, (uint32_t) enSampleEndSequence,
                           ADC_SSCTL_END0_MASK, ADC_SSCTL_R_END0_BIT);
}

ADC_nSEQ_INPUT_ENDED ADC_Sample__enGetEndSequence(ADC_nMODULE enModule,
                                                 ADC_nSEQUENCER enSequencer, ADC_nMUX enMux)
{
    ADC_nSEQ_INPUT_ENDED enSeqInputEnded = ADC_enSEQ_INPUT_ENDED_DIS;
    enSeqInputEnded = (ADC_nSEQ_INPUT_ENDED) ADC_Sample__u32GetGeneric((uint32_t) enModule,
                                                                      (uint32_t) enSequencer,
                                                                      ADC_SS_CTL_OFFSET,
                                                                      (uint32_t) enMux,
                                                                      ADC_SSCTL_END0_MASK,
                                                                      ADC_SSCTL_R_END0_BIT);
    return (enSeqInputEnded);
}
