/**
 *
 * @file ADC_Comparator_GenericRange.c
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
#include <xDriver_MCU/ADC/Driver/Comparator/Range/xHeader/ADC_Comparator_GenericRange.h>

#include <xDriver_MCU/ADC/Driver/Comparator/xHeader/ADC_CompGeneric.h>
#include <xDriver_MCU/ADC/Peripheral/ADC_Peripheral.h>

void ADC_Comparator__vSetGenericRange(uint32_t u32Module, uint32_t  u32Comparator,
                               uint32_t u32Range, uint32_t u32RangeMask, uint32_t u32RangeBit)
{
    ADC_Comparator__vSetGeneric(u32Module , u32Comparator, ADC_DC_CMP_OFFSET, u32Range,
                         u32RangeMask, u32RangeBit);
}

uint32_t ADC_Comparator__u32GetGenericRange(uint32_t u32Module, uint32_t  u32Comparator,
                                     uint32_t u32RangeMask, uint32_t u32RangeBit)
{
    uint32_t u32RengeReg = 0UL;
    u32RengeReg = ADC_Comparator__u32GetGeneric(u32Module, u32Comparator, ADC_DC_CMP_OFFSET,
                                         u32RangeMask, u32RangeBit);
    return (u32RengeReg);
}
