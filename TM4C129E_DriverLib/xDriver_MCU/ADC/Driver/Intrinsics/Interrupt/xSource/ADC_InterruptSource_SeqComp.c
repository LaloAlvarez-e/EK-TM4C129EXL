/**
 *
 * @file ADC_InterruptSource_SeqComp.c
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
#include <xDriver_MCU/ADC/Driver/Intrinsics/Interrupt/xHeader/ADC_InterruptSource_SeqComp.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/ADC/Peripheral/ADC_Peripheral.h>
#include <xDriver_MCU/ADC/Driver/Intrinsics/Primitives/ADC_Primitives.h>

ADC_nERROR ADC_Comparator__enSetInterruptSourceStateByMask(ADC_nMODULE enModuleArg, ADC_nCOMPMASK enComparatorMaskArg,
                                                           ADC_nSTATE enStateArg)
{
    ADC_Register_t stRegister;
    UBase_t uxComparatorMaskReg;
    UBase_t uxOffsetReg;
    UBase_t uxComparatorReg;
    ADC_nERROR enErrorReg;

    enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enComparatorMaskArg, (UBase_t) ADC_enCOMPMASK_MAX);
    if(ADC_enERROR_OK == enErrorReg)
    {
        stRegister.uxShift = ADC_DC_CTL_R_CIE_BIT;
        stRegister.uxMask = ADC_DC_CTL_CIE_MASK;
        stRegister.uxValue = (UBase_t) enStateArg;

        uxComparatorReg = 0U;
        uxComparatorMaskReg = (UBase_t) enComparatorMaskArg;
        while((0UL != uxComparatorMaskReg) && (ADC_enERROR_OK == enErrorReg))
        {
            if(0UL != (((UBase_t) ADC_enCOMPMASK_0) & uxComparatorMaskReg))
            {
                uxOffsetReg = uxComparatorReg;
                uxOffsetReg <<= 2U;
                uxOffsetReg += ADC_DC_CTL_OFFSET;
                stRegister.uptrAddress = (uintptr_t) uxOffsetReg;
                enErrorReg = ADC__enWriteRegister(enModuleArg, &stRegister);
            }
            uxComparatorMaskReg >>= 1U;
            uxComparatorReg++;
        }
    }

    return (enErrorReg);
}

ADC_nERROR ADC_Comparator__enSetInterruptSourceStateByNumber(ADC_nMODULE enModuleArg, ADC_nCOMPARATOR enComparatorArg,
                                                             ADC_nSTATE enStateArg)
{
    ADC_Register_t stRegister;
    UBase_t uxOffsetReg;
    ADC_nERROR enErrorReg;

    enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enComparatorArg, (UBase_t) ADC_enCOMPARATOR_MAX);
    if(ADC_enERROR_OK == enErrorReg)
    {
        uxOffsetReg = (UBase_t) enComparatorArg;
        uxOffsetReg <<= 2U;
        uxOffsetReg += ADC_DC_CTL_OFFSET;

        stRegister.uxShift = ADC_DC_CTL_R_CIE_BIT;
        stRegister.uxMask = ADC_DC_CTL_CIE_MASK;
        stRegister.uptrAddress = (uintptr_t) uxOffsetReg;
        stRegister.uxValue = (UBase_t) enStateArg;
        enErrorReg = ADC__enWriteRegister(enModuleArg, &stRegister);
    }

    return (enErrorReg);
}


ADC_nERROR ADC_Comparator__enGetInterruptSourceStateByMask(ADC_nMODULE enModuleArg, ADC_nCOMPMASK enComparatorMaskArg,
                                                           ADC_nCOMPMASK* penComparatorGetArg)
{
    ADC_Register_t stRegister;
    UBase_t uxComparatorMaskReg;
    UBase_t uxOffsetReg;
    UBase_t uxComparatorReg;
    UBase_t uxComparatorGetReg;
    UBase_t uxValueReg;
    ADC_nERROR enErrorReg;

    uxComparatorGetReg = 0U;
    enErrorReg = ADC_enERROR_OK;
    if(0UL == (uintptr_t) penComparatorGetArg)
    {
        enErrorReg = ADC_enERROR_POINTER;
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enComparatorMaskArg, (UBase_t) ADC_enCOMPMASK_MAX);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        stRegister.uxShift = ADC_DC_CTL_R_CIE_BIT;
        stRegister.uxMask = ADC_DC_CTL_CIE_MASK;

        uxValueReg = (UBase_t) ADC_enCOMPMASK_0;
        uxComparatorReg = 0U;
        uxComparatorMaskReg = (UBase_t) enComparatorMaskArg;
        while((0UL != uxComparatorMaskReg) && (ADC_enERROR_OK == enErrorReg))
        {
            if(0UL != (((UBase_t) ADC_enCOMPMASK_0) & uxComparatorMaskReg))
            {
                uxOffsetReg = uxComparatorReg;
                uxOffsetReg <<= 2U;
                uxOffsetReg += ADC_DC_CTL_OFFSET;
                stRegister.uptrAddress = (uintptr_t) uxOffsetReg;
                enErrorReg = ADC__enReadRegister(enModuleArg, &stRegister);
                if(ADC_enERROR_OK == enErrorReg)
                {
                    if(0UL != stRegister.uxValue)
                    {
                        uxComparatorGetReg |= uxValueReg;
                    }
                }
            }
            uxValueReg <<= 1U;
            uxComparatorMaskReg >>= 1U;
            uxComparatorReg++;
        }
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        *penComparatorGetArg = (ADC_nCOMPMASK) uxComparatorGetReg;
    }
    return (enErrorReg);
}

ADC_nERROR ADC_Comparator__enGetInterruptSourceStateByNumber(ADC_nMODULE enModuleArg, ADC_nCOMPARATOR enComparatorArg,
                                                             ADC_nSTATE* penStateArg)
{
    ADC_Register_t stRegister;
    UBase_t uxOffsetReg;
    ADC_nERROR enErrorReg;

    enErrorReg = ADC_enERROR_OK;
    if(0UL == (uintptr_t) penStateArg)
    {
        enErrorReg = ADC_enERROR_POINTER;
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enComparatorArg, (UBase_t) ADC_enCOMPARATOR_MAX);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        uxOffsetReg = (UBase_t) enComparatorArg;
        uxOffsetReg <<= 2U;
        uxOffsetReg += ADC_DC_CTL_OFFSET;

        stRegister.uxShift = ADC_DC_CTL_R_CIE_BIT;
        stRegister.uxMask = ADC_DC_CTL_CIE_MASK;
        stRegister.uptrAddress = (uintptr_t) uxOffsetReg;
        enErrorReg = ADC__enReadRegister(enModuleArg, &stRegister);

    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        *penStateArg = (ADC_nSTATE) stRegister.uxValue;
    }
    return (enErrorReg);
}

ADC_nERROR ADC_Comparator__enEnableInterruptSourceByMask(ADC_nMODULE enModuleArg, ADC_nCOMPMASK enComparatorMaskArg)
{
    ADC_nERROR enReturnReg;

    enReturnReg = ADC_Comparator__enSetInterruptSourceStateByMask(enModuleArg, enComparatorMaskArg, ADC_enSTATE_ENA);

    return (enReturnReg);
}

ADC_nERROR ADC_Comparator__enEnableInterruptSourceByNumber(ADC_nMODULE enModuleArg, ADC_nCOMPARATOR enComparatorArg)
{
    ADC_nERROR enReturnReg;

    enReturnReg = ADC_Comparator__enSetInterruptSourceStateByNumber(enModuleArg, enComparatorArg, ADC_enSTATE_ENA);

    return (enReturnReg);
}

ADC_nERROR ADC_Comparator__enDisableInterruptSourceByMask(ADC_nMODULE enModuleArg, ADC_nCOMPMASK enComparatorMaskArg)
{
    ADC_nERROR enReturnReg;

    enReturnReg = ADC_Comparator__enSetInterruptSourceStateByMask(enModuleArg, enComparatorMaskArg, ADC_enSTATE_DIS);

    return (enReturnReg);
}

ADC_nERROR ADC_Comparator__enDisableInterruptSourceByNumber(ADC_nMODULE enModuleArg, ADC_nCOMPARATOR enComparatorArg)
{
    ADC_nERROR enReturnReg;

    enReturnReg = ADC_Comparator__enSetInterruptSourceStateByNumber(enModuleArg, enComparatorArg, ADC_enSTATE_DIS);

    return (enReturnReg);
}

ADC_nERROR ADC_Comparator__enClearInterruptSourceByMask(ADC_nMODULE enModuleArg, ADC_nCOMPMASK enComparatorMaskArg)
{
    ADC_Register_t stRegister;
    ADC_nERROR enErrorReg;

    enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enComparatorMaskArg, ((UBase_t) ADC_enCOMPMASK_ALL) + 1U);
    if(ADC_enERROR_OK == enErrorReg)
    {
        stRegister.uxShift = 0UL;
        stRegister.uxMask = MCU_MASK_BASE;
        stRegister.uptrAddress = ADC_DCISC_OFFSET;
        stRegister.uxValue = (UBase_t) enComparatorMaskArg;
        enErrorReg = ADC__enWriteRegister(enModuleArg, &stRegister);
    }

    return (enErrorReg);
}

ADC_nERROR ADC_Comparator__enClearInterruptSourceByNumber(ADC_nMODULE enModuleArg, ADC_nCOMPARATOR enComparatorArg)
{
    ADC_Register_t stRegister;
    ADC_nERROR enErrorReg;

    enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enComparatorArg, (UBase_t) ADC_enCOMPARATOR_MAX);
    if(ADC_enERROR_OK == enErrorReg)
    {
        stRegister.uxShift = (UBase_t) enComparatorArg;
        stRegister.uxMask = ADC_DCISC_DCINT_MASK;
        stRegister.uptrAddress = ADC_DCISC_OFFSET;
        stRegister.uxValue = ADC_DCISC_DCINT_CLEAR;
        enErrorReg = ADC__enWriteRegister(enModuleArg, &stRegister);
    }

    return (enErrorReg);
}

ADC_nERROR ADC_Comparator__enStatusInterruptSourceByMask(ADC_nMODULE enModuleArg, ADC_nCOMPMASK enComparatorMaskArg,
                                                         ADC_nCOMPMASK* penComparatorGetArg)
{
    ADC_Register_t stRegister;
    ADC_nERROR enErrorReg;

    enErrorReg = ADC_enERROR_OK;
    if(0UL == (uintptr_t) penComparatorGetArg)
    {
        enErrorReg = ADC_enERROR_POINTER;
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enComparatorMaskArg, (UBase_t) ADC_enCOMPMASK_MAX);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        stRegister.uxShift = 0UL;
        stRegister.uxMask = (UBase_t) enComparatorMaskArg;
        stRegister.uptrAddress = ADC_DCISC_OFFSET;
        enErrorReg = ADC__enReadRegister(enModuleArg, &stRegister);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        *penComparatorGetArg = (ADC_nCOMPMASK) stRegister.uxValue;
    }

    return (enErrorReg);
}

ADC_nERROR ADC_Comparator__enStatusInterruptSourceByNumber(ADC_nMODULE enModuleArg, ADC_nCOMPARATOR enComparatorArg,
                                                           ADC_nSTATE* penStateArg)
{
    ADC_Register_t stRegister;
    ADC_nERROR enErrorReg;

    enErrorReg = ADC_enERROR_OK;
    if(0UL == (uintptr_t) penStateArg)
    {
        enErrorReg = ADC_enERROR_POINTER;
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enComparatorArg, (UBase_t) ADC_enCOMPARATOR_MAX);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        stRegister.uxShift = (UBase_t) enComparatorArg;
        stRegister.uxMask = ADC_DCISC_DCINT_MASK;
        stRegister.uptrAddress = ADC_DCISC_OFFSET;
        enErrorReg = ADC__enReadRegister(enModuleArg, &stRegister);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        *penStateArg = (ADC_nSTATE) stRegister.uxValue;
    }

    return (enErrorReg);
}
