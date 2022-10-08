/**
 *
 * @file ADC_Comparator_TriggerMode.c
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
#include <xDriver_MCU/ADC/Driver/Comparator/Control/xHeader/ADC_Comparator_TriggerMode.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/ADC/Driver/Comparator/xHeader/ADC_CompGeneric.h>
#include <xDriver_MCU/ADC/Peripheral/ADC_Peripheral.h>

ADC_nERROR ADC_Comparator__enSetTriggerModeByMask(ADC_nMODULE enModuleArg, ADC_nCOMPMASK enComparatorMaskArg,
                                                         ADC_nCOMP_MODE enTriggerModeArg)
{
    UBase_t uxComparatorReg;
    UBase_t uxComparatorMaskReg;
    ADC_nERROR enErrorReg;
    ADC_nERROR enErrorMemoryReg;

    enErrorMemoryReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enComparatorMaskArg, (UBase_t) ADC_enCOMPMASK_MAX);
    if(ADC_enERROR_OK == enErrorMemoryReg)
    {
        uxComparatorReg = 0U;
        uxComparatorMaskReg = (UBase_t) enComparatorMaskArg;
        enErrorReg = ADC_enERROR_OK;
        while(0U != uxComparatorMaskReg)
        {
            if(0UL != ((UBase_t) ADC_enCOMPMASK_0 & uxComparatorMaskReg))
            {
                enErrorReg = ADC_Comparator__enSetTriggerModeByNumber(enModuleArg, (ADC_nCOMPARATOR) uxComparatorReg, enTriggerModeArg);
            }

            if(ADC_enERROR_OK != enErrorReg)
            {
                enErrorMemoryReg = enErrorReg;
                break;
            }
            uxComparatorReg++;
            uxComparatorMaskReg >>= 1U;
        }
    }

    return (enErrorMemoryReg);
}

ADC_nERROR ADC_Comparator__enSetTriggerModeByNumber(ADC_nMODULE enModuleArg, ADC_nCOMPARATOR enComparatorArg,
                                                    ADC_nCOMP_MODE enTriggerModeArg)
{
    ADC_Register_t stRegister;
    ADC_nERROR enErrorReg;

    stRegister.uxShift = ADC_DC_CTL_R_CTM_BIT;
    stRegister.uxMask = ADC_DC_CTL_CTM_MASK;
    stRegister.uptrAddress = ADC_DC_CTL_OFFSET;
    stRegister.uxValue = (UBase_t) enTriggerModeArg;
    enErrorReg = ADC_Comparator__enSetGeneric(enModuleArg, enComparatorArg, &stRegister);

    return (enErrorReg);
}

ADC_nERROR ADC_Comparator__enGetTriggerModeByNumber(ADC_nMODULE enModuleArg, ADC_nCOMPARATOR enComparatorArg,
                                                           ADC_nCOMP_MODE* penTriggerModeArg)
{
    ADC_Register_t stRegister;
    ADC_nERROR enErrorReg;

    enErrorReg = ADC_enERROR_OK;
    if(0UL == (uintptr_t) penTriggerModeArg)
    {
        enErrorReg = ADC_enERROR_POINTER;
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        stRegister.uxShift = ADC_DC_CTL_R_CTM_BIT;
        stRegister.uxMask = ADC_DC_CTL_CTM_MASK;
        stRegister.uptrAddress = ADC_DC_CTL_OFFSET;
        enErrorReg = ADC_Comparator__enGetGeneric(enModuleArg, enComparatorArg, &stRegister);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        *penTriggerModeArg = (ADC_nCOMP_MODE) stRegister.uxValue;
    }

    return (enErrorReg);
}
