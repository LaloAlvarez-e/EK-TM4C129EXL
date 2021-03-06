/**
 *
 * @file ADC_Comparator_Generic.c
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
 * @verbatim 5 dic. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 5 dic. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/ADC/Driver/Comparator/Control/xHeader/ADC_Comparator_Generic.h>

#include <xDriver_MCU/ADC/Driver/Comparator/xHeader/ADC_CompGeneric.h>
#include <xDriver_MCU/ADC/Peripheral/ADC_Peripheral.h>

void ADC_Comparator__vSetGenericControl(uint32_t u32Module, uint32_t  u32Comparator,
                                 uint32_t u32Feature, uint32_t u32FeatureMask,
                                 uint32_t u32FeatureBit)
{
    ADC_Comparator__vSetGeneric(u32Module , u32Comparator, ADC_DC_CTL_OFFSET, u32Feature,
                         u32FeatureMask, u32FeatureBit);
}

uint32_t ADC_Comparator__u32GetGenericControl(uint32_t u32Module, uint32_t  u32Comparator,
                                       uint32_t u32FeatureMask, uint32_t u32FeatureBit)
{
    uint32_t u32Reg = 0UL;
    u32Reg = ADC_Comparator__u32GetGeneric(u32Module, u32Comparator, ADC_DC_CTL_OFFSET,
                                    u32FeatureMask, u32FeatureBit);
    return (u32Reg);
}
