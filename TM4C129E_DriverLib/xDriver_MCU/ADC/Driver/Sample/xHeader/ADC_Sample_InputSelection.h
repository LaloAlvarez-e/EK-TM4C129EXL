/**
 *
 * @file ADC_Sample_InputSelection.h
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
 * @verbatim 23 nov. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 23 nov. 2020     vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_ADC_DRIVER_Sample_XHEADER_ADC_Sample_INPUTSELECTION_H_
#define XDRIVER_MCU_ADC_DRIVER_Sample_XHEADER_ADC_Sample_INPUTSELECTION_H_

#include <xDriver_MCU/ADC/Peripheral/xHeader/ADC_Enum.h>

void ADC_Sample__vSetInputSelection(ADC_nMODULE enModule,
                                   ADC_nSEQUENCER enSequencer,
                                   ADC_nMUX enMux,
                                   ADC_nSEQ_INPUT enSampleInputSelection);
ADC_nSEQ_INPUT ADC_Sample__enGetInputSelection(ADC_nMODULE enModule,
                                              ADC_nSEQUENCER enSequencer,
                                              ADC_nMUX enMux);

#endif /* XDRIVER_MCU_ADC_DRIVER_Sample_XHEADER_ADC_Sample_INPUTSELECTION_H_ */
