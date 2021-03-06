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

#include <xDriver_MCU/ADC/Driver/Sample/xHeader/ADC_Sample_Generic.h>
#include <xDriver_MCU/ADC/Peripheral/ADC_Peripheral.h>

void ADC_Sample__vSetTempSelection(ADC_nMODULE enModule, ADC_nSEQUENCER enSequencer,
                                  ADC_nMUX enMux, ADC_nSEQ_INPUT_TEMP enSampleTempSelection)
{
    ADC_Sample__vSetGeneric((uint32_t) enModule, (uint32_t) enSequencer,
                           ADC_SS_CTL_OFFSET, (uint32_t) enMux,
                           (uint32_t) enSampleTempSelection,
                           ADC_SSCTL_TS0_MASK, ADC_SSCTL_R_TS0_BIT);
}

ADC_nSEQ_INPUT_TEMP ADC_Sample__enGetTempSelection(ADC_nMODULE enModule,
                                                  ADC_nSEQUENCER enSequencer, ADC_nMUX enMux)
{
    ADC_nSEQ_INPUT_TEMP enSeqInputTemp = ADC_enSEQ_INPUT_TEMP_DIS;
    enSeqInputTemp = (ADC_nSEQ_INPUT_TEMP) ADC_Sample__u32GetGeneric((uint32_t) enModule,
                                                    (uint32_t) enSequencer, ADC_SS_CTL_OFFSET,
                                                    (uint32_t) enMux, ADC_SSCTL_TS0_MASK,
                                                    ADC_SSCTL_R_TS0_BIT);
    return (enSeqInputTemp);
}
