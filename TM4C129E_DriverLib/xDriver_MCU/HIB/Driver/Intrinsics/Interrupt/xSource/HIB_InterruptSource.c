/**
 *
 * @file HIB_InterruptSource.c
 * @copyright
 * @verbatim InDeviceMex 2026 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 6 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 6 abr. 2026    vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/HIB/Driver/Intrinsics/Interrupt/xHeader/HIB_InterruptSource.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/HIB/Driver/Intrinsics/Primitives/HIB_Primitives.h>
#include <xDriver_MCU/HIB/Peripheral/HIB_Peripheral.h>

static HIB_nERROR HIB__enGetInterruptSourceShift(HIB_nMODULE enModuleArg, HIB_nINT enInterruptArg, UBase_t* puxShiftArg);

static HIB_nERROR HIB__enGetInterruptSourceShift(HIB_nMODULE enModuleArg, HIB_nINT enInterruptArg, UBase_t* puxShiftArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) puxShiftArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = (HIB_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) HIB_enMODULE_MAX);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = (HIB_nERROR) MCU__enCheckParams((UBase_t) enInterruptArg, (UBase_t) HIB_enINT_MAX);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        static const UBase_t HIB_uxInterruptBit[(UBase_t) HIB_enINT_MAX] =
        {
         HIB_RIS_R_RTCALT0_BIT   , HIB_RIS_R_RTCALT0_BIT , HIB_RIS_R_LOWBAT_BIT, HIB_RIS_R_EXTW_BIT,
         HIB_RIS_R_WC_BIT, HIB_RIS_R_PADIOWK_BIT, HIB_RIS_R_RSTWK_BIT, HIB_RIS_R_VDDFAIL_BIT
        };

        if((UBase_t) enInterruptArg < (UBase_t) HIB_enINT_MAX)
        {
            *puxShiftArg = HIB_uxInterruptBit[(UBase_t) enInterruptArg];
        }
        else
        {
            enErrorReg = HIB_enERROR_VALUE;
        }
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enSetInterruptSourceStateByMask(HIB_nMODULE enModuleArg, HIB_nINTMASK enInterruptMaskArg, HIB_nSTATE enStateArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = (HIB_nERROR) MCU__enCheckParams((UBase_t) enInterruptMaskArg, (UBase_t) HIB_enINTMASK_MAX);
    if(HIB_enERROR_OK == enErrorReg)
    {
        HIB_Register_t stRegister;
        UBase_t uxValueReg;

        uxValueReg = (HIB_enSTATE_DIS == enStateArg) ? 0UL : (UBase_t) enInterruptMaskArg;

        stRegister.uxShift = 0UL;
        stRegister.uxMask = (UBase_t) enInterruptMaskArg;
        stRegister.uptrAddress = HIB_IM_OFFSET;
        stRegister.uxValue = uxValueReg;
        enErrorReg = HIB__enWriteRegister(enModuleArg, &stRegister);
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enSetInterruptSourceStateByNumber(HIB_nMODULE enModuleArg, HIB_nINT enInterruptArg, HIB_nSTATE enStateArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxShiftReg;

    uxShiftReg = 0UL;
    enErrorReg = HIB__enGetInterruptSourceShift(enModuleArg, enInterruptArg, &uxShiftReg);
    if(HIB_enERROR_OK == enErrorReg)
    {
        HIB_Register_t stRegister;

        stRegister.uxShift = uxShiftReg;
        stRegister.uxMask = HIB_IM_RTCALT0_MASK;
        stRegister.uptrAddress = HIB_IM_OFFSET;
        stRegister.uxValue = (UBase_t) enStateArg;
        enErrorReg = HIB__enWriteRegister(enModuleArg, &stRegister);
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enGetInterruptSourceStateByMask(HIB_nMODULE enModuleArg, HIB_nINTMASK enInterruptMaskArg, HIB_nINTMASK* penInterruptGetArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) penInterruptGetArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = (HIB_nERROR) MCU__enCheckParams((UBase_t) enInterruptMaskArg, (UBase_t) HIB_enINTMASK_MAX);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        HIB_Register_t stRegister;

        stRegister.uxShift = 0UL;
        stRegister.uxMask = (UBase_t) enInterruptMaskArg;
        stRegister.uptrAddress = HIB_IM_OFFSET;
        stRegister.uxValue = 0UL;
        enErrorReg = HIB__enReadRegister(enModuleArg, &stRegister);
        if(HIB_enERROR_OK == enErrorReg)
        {
            *penInterruptGetArg = (HIB_nINTMASK) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enGetInterruptSourceStateByNumber(HIB_nMODULE enModuleArg, HIB_nINT enInterruptArg, HIB_nSTATE* penStateArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxShiftReg;

    uxShiftReg = 0UL;
    enErrorReg = (0UL == (uintptr_t) penStateArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enGetInterruptSourceShift(enModuleArg, enInterruptArg, &uxShiftReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        HIB_Register_t stRegister;

        stRegister.uxShift = uxShiftReg;
        stRegister.uxMask = HIB_IM_RTCALT0_MASK;
        stRegister.uptrAddress = HIB_IM_OFFSET;
        stRegister.uxValue = 0UL;
        enErrorReg = HIB__enReadRegister(enModuleArg, &stRegister);
        if(HIB_enERROR_OK == enErrorReg)
        {
            *penStateArg = (HIB_nSTATE) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enEnableInterruptSourceByMask(HIB_nMODULE enModuleArg, HIB_nINTMASK enInterruptMaskArg)
{
    HIB_nERROR enErrorReg;
    enErrorReg = HIB__enSetInterruptSourceStateByMask(enModuleArg, enInterruptMaskArg, HIB_enSTATE_ENA);
    return (enErrorReg);
}

HIB_nERROR HIB__enEnableInterruptSourceByNumber(HIB_nMODULE enModuleArg, HIB_nINT enInterruptArg)
{
    HIB_nERROR enErrorReg;
    enErrorReg = HIB__enSetInterruptSourceStateByNumber(enModuleArg, enInterruptArg, HIB_enSTATE_ENA);
    return (enErrorReg);
}

HIB_nERROR HIB__enClearInterruptSourceByMask(HIB_nMODULE enModuleArg, HIB_nINTMASK enInterruptMaskArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = (HIB_nERROR) MCU__enCheckParams((UBase_t) enInterruptMaskArg, (UBase_t) HIB_enINTMASK_MAX);
    if(HIB_enERROR_OK == enErrorReg)
    {
        HIB_Register_t stRegister;

        stRegister.uxShift = 0UL;
        stRegister.uxMask = MCU_MASK_BASE;
        stRegister.uptrAddress = HIB_IC_OFFSET;
        stRegister.uxValue = (UBase_t) enInterruptMaskArg;
        enErrorReg = HIB__enWriteRegister(enModuleArg, &stRegister);
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enClearInterruptSourceByNumber(HIB_nMODULE enModuleArg, HIB_nINT enInterruptArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxShiftReg;

    uxShiftReg = 0UL;
    enErrorReg = HIB__enGetInterruptSourceShift(enModuleArg, enInterruptArg, &uxShiftReg);
    if(HIB_enERROR_OK == enErrorReg)
    {
        HIB_Register_t stRegister;
        UBase_t uxValueReg;

        uxValueReg = 1UL;
        uxValueReg <<= uxShiftReg;

        stRegister.uxShift = 0UL;
        stRegister.uxMask = MCU_MASK_BASE;
        stRegister.uptrAddress = HIB_IC_OFFSET;
        stRegister.uxValue = uxValueReg;
        enErrorReg = HIB__enWriteRegister(enModuleArg, &stRegister);
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enStatusInterruptSourceByMask(HIB_nMODULE enModuleArg, HIB_nINTMASK enInterruptMaskArg, HIB_nINTMASK* penInterruptStatusArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) penInterruptStatusArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = (HIB_nERROR) MCU__enCheckParams((UBase_t) enInterruptMaskArg, (UBase_t) HIB_enINTMASK_MAX);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        HIB_Register_t stRegister;

        stRegister.uxShift = 0UL;
        stRegister.uxMask = (UBase_t) enInterruptMaskArg;
        stRegister.uptrAddress = HIB_RIS_OFFSET;
        stRegister.uxValue = 0UL;
        enErrorReg = HIB__enReadRegister(enModuleArg, &stRegister);
        if(HIB_enERROR_OK == enErrorReg)
        {
            *penInterruptStatusArg = (HIB_nINTMASK) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enStatusInterruptSourceByNumber(HIB_nMODULE enModuleArg, HIB_nINT enInterruptArg, HIB_nSTATUS* penStatusArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxShiftReg;

    uxShiftReg = 0UL;
    enErrorReg = (0UL == (uintptr_t) penStatusArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enGetInterruptSourceShift(enModuleArg, enInterruptArg, &uxShiftReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        HIB_Register_t stRegister;

        stRegister.uxShift = uxShiftReg;
        stRegister.uxMask = HIB_RIS_RTCALT0_MASK;
        stRegister.uptrAddress = HIB_RIS_OFFSET;
        stRegister.uxValue = 0UL;
        enErrorReg = HIB__enReadRegister(enModuleArg, &stRegister);
        if(HIB_enERROR_OK == enErrorReg)
        {
            *penStatusArg = (HIB_nSTATUS) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enStatusMaskedInterruptSourceByMask(HIB_nMODULE enModuleArg, HIB_nINTMASK enInterruptMaskArg, HIB_nINTMASK* penInterruptStatusArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) penInterruptStatusArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = (HIB_nERROR) MCU__enCheckParams((UBase_t) enInterruptMaskArg, (UBase_t) HIB_enINTMASK_MAX);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        HIB_Register_t stRegister;

        stRegister.uxShift = 0UL;
        stRegister.uxMask = (UBase_t) enInterruptMaskArg;
        stRegister.uptrAddress = HIB_MIS_OFFSET;
        stRegister.uxValue = 0UL;
        enErrorReg = HIB__enReadRegister(enModuleArg, &stRegister);
        if(HIB_enERROR_OK == enErrorReg)
        {
            *penInterruptStatusArg = (HIB_nINTMASK) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enStatusMaskedInterruptSourceByNumber(HIB_nMODULE enModuleArg, HIB_nINT enInterruptArg, HIB_nSTATUS* penStatusArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxShiftReg;

    uxShiftReg = 0UL;
    enErrorReg = (0UL == (uintptr_t) penStatusArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enGetInterruptSourceShift(enModuleArg, enInterruptArg, &uxShiftReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        HIB_Register_t stRegister;

        stRegister.uxShift = uxShiftReg;
        stRegister.uxMask = HIB_MIS_RTCALT0_MASK;
        stRegister.uptrAddress = HIB_MIS_OFFSET;
        stRegister.uxValue = 0UL;
        enErrorReg = HIB__enReadRegister(enModuleArg, &stRegister);
        if(HIB_enERROR_OK == enErrorReg)
        {
            *penStatusArg = (HIB_nSTATUS) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}
