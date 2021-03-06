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

#include <xDriver_MCU/ADC/Driver/Sequencer/xHeader/ADC_Sequencer_Generic.h>
#include <xDriver_MCU/ADC/Peripheral/ADC_Peripheral.h>

void ADC_Sequencer__vSetPWMTrigger(ADC_nMODULE enModule, ADC_nSEQUENCER enSequence,
                                  ADC_nSEQ_PWM enSeqPWMTrigger)
{
    ADC_Sequencer__vSetGenericBit((uint32_t) enModule, ADC_TSSEL_OFFSET, (uint32_t) enSequence,
                                 (uint32_t) enSeqPWMTrigger, ADC_TSSEL_PS0_MASK,
                                 (ADC_TSSEL_R_PS1_BIT - ADC_TSSEL_R_PS0_BIT),
                                 ADC_TSSEL_R_PS0_BIT);
}

ADC_nSEQ_PWM ADC_Sequencer__enGetPWMTrigger(ADC_nMODULE enModule, ADC_nSEQUENCER enSequence)
{
    ADC_nSEQ_PWM enSeqPwmReg = ADC_enSEQ_PWM_MODULE0;
    enSeqPwmReg = (ADC_nSEQ_PWM) (ADC_Sequencer__u32GetGenericBit((uint32_t) enModule,
                                                 ADC_TSSEL_OFFSET, (uint32_t) enSequence,
                                                 ADC_TSSEL_PS0_MASK,
                                                 (ADC_TSSEL_R_PS1_BIT - ADC_TSSEL_R_PS0_BIT),
                                                 ADC_TSSEL_R_PS0_BIT));
    return (enSeqPwmReg);
}
