/**
 *
 * @file ADC_Comparator_ResetTrigger.c
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
#include <xDriver_MCU/ADC/Driver/Comparator/Reset/xHeader/ADC_Comparator_ResetTrigger.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/ADC/Driver/Intrinsics/ADC_Intrinsics.h>
#include <xDriver_MCU/ADC/Peripheral/ADC_Peripheral.h>

ADC_nERROR ADC_Comparator__enResetTriggerConditionsByMask(ADC_nMODULE enModuleArg, ADC_nCOMPMASK enComparatorMaskArg)
{
    ADC_nERROR enErrorReg;
    enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enComparatorMaskArg, (UBase_t) ADC_enCOMPMASK_MAX);
    if(ADC_enERROR_OK == enErrorReg)
    {
        ADC_Register_t stRegister;
        stRegister.uxShift = ADC_DC_RIC_R_DCINT0_BIT;
        stRegister.uxMask = MCU_MASK_BASE;
        stRegister.uptrAddress = ADC_DC_RIC_OFFSET;
        stRegister.uxValue = (UBase_t) enComparatorMaskArg;
        stRegister.uxValue <<= ADC_DC_RIC_R_DCTRIG0_BIT;
        enErrorReg = ADC__enWriteRegister(enModuleArg, &stRegister);
        if(ADC_enERROR_OK == enErrorReg)
        {
            do
            {
                enErrorReg = ADC__enReadRegister(enModuleArg, &stRegister);
            }while((ADC_enERROR_OK == enErrorReg) && (0UL != stRegister.uxValue));
        }
    }
    return (enErrorReg);
}

ADC_nERROR ADC_Comparator__enResetTriggerConditionsByNumber(ADC_nMODULE enModuleArg, ADC_nCOMPARATOR enComparatorArg)
{
    ADC_nERROR enErrorReg;
    enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enComparatorArg, (UBase_t) ADC_enCOMPARATOR_MAX);
    if(ADC_enERROR_OK == enErrorReg)
    {
        ADC_Register_t stRegister;
        stRegister.uxShift = (UBase_t) enComparatorArg;
        stRegister.uxShift += ADC_DC_RIC_R_DCTRIG0_BIT;
        stRegister.uxMask = ADC_DC_RIC_DCTRIG0_MASK;
        stRegister.uptrAddress = ADC_DC_RIC_OFFSET;
        stRegister.uxValue = ADC_DC_RIC_DCTRIG0_RESET;
        enErrorReg = ADC__enWriteRegister(enModuleArg, &stRegister);
        if(ADC_enERROR_OK == enErrorReg)
        {
            do
            {
                enErrorReg = ADC__enReadRegister(enModuleArg, &stRegister);
            }while((ADC_enERROR_OK == enErrorReg) && (0UL != stRegister.uxValue));
        }
    }
    return (enErrorReg);
}
