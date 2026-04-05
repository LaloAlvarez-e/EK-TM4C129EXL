/**
 *
 * @file SYSCTL_InterruptSource.c
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
 * @verbatim 17 feb. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 17 feb. 2021     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/SYSCTL/Driver/Intrinsics/Interrupt/xHeader/SYSCTL_InterruptSource.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/SYSCTL/Driver/Intrinsics/Primitives/SYSCTL_Primitives.h>
#include <xDriver_MCU/SYSCTL/Peripheral/SYSCTL_Peripheral.h>

static SYSCTL_nERROR SYSCTL__enGetInterruptSourceShift(SYSCTL_nMODULE enModuleArg, SYSCTL_nINT enInterruptArg, UBase_t* puxShiftArg);


static SYSCTL_nERROR SYSCTL__enGetInterruptSourceShift(SYSCTL_nMODULE enModuleArg, SYSCTL_nINT enInterruptArg, UBase_t* puxShiftArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) puxShiftArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SYSCTL_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) SYSCTL_enMODULE_MAX);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SYSCTL_nERROR) MCU__enCheckParams((UBase_t) enInterruptArg, (UBase_t) SYSCTL_enINT_SW);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        static const UBase_t SYSCTL_uxInterruptBit[(UBase_t) SYSCTL_enINT_SW] =
        {
         SYSCTL_RIS_R_BOR_BIT     , SYSCTL_RIS_R_MOSC_FAILURE_BIT    ,
         SYSCTL_RIS_R_PLL_LOCK_BIT, SYSCTL_RIS_R_MOSC_POWERUP_BIT    ,
        };
        *puxShiftArg = SYSCTL_uxInterruptBit[(UBase_t) enInterruptArg];
    }
    return (enErrorReg);
}


SYSCTL_nERROR SYSCTL__enSetInterruptSourceStateByMask(SYSCTL_nMODULE enModuleArg, SYSCTL_nINTMASK enInterruptMaskArg, SYSCTL_nSTATE enStateArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (SYSCTL_nERROR) MCU__enCheckParams((UBase_t) enInterruptMaskArg, (UBase_t) SYSCTL_enINTMASK_MAX);
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        UBase_t uxValueReg = (SYSCTL_enSTATE_DIS == enStateArg) ? 0U : (UBase_t) enInterruptMaskArg ;

        SYSCTL_Register_t stRegister;
        stRegister.uxShift = 0U;
        stRegister.uxMask = enInterruptMaskArg;
        stRegister.uptrAddress = SYSCTL_IMC_OFFSET;
        stRegister.uxValue = uxValueReg;
        enErrorReg = SYSCTL__enWriteRegister(enModuleArg, &stRegister);
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enSetInterruptSourceStateByNumber(SYSCTL_nMODULE enModuleArg, SYSCTL_nINT enInterruptArg, SYSCTL_nSTATE enStateArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (SYSCTL_nERROR) MCU__enCheckParams((UBase_t) enInterruptArg, (UBase_t) SYSCTL_enINT_SW);
    UBase_t uxShiftReg;
    uxShiftReg = 0UL;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetInterruptSourceShift(enModuleArg, enInterruptArg, &uxShiftReg);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        SYSCTL_Register_t stRegister;
        stRegister.uxShift = uxShiftReg;
        stRegister.uxMask = SYSCTL_IMC_BOR_MASK;
        stRegister.uptrAddress = SYSCTL_IMC_OFFSET;
        stRegister.uxValue = (UBase_t) enStateArg;
        enErrorReg = SYSCTL__enWriteRegister(enModuleArg, &stRegister);
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enGetInterruptSourceStateByMask(SYSCTL_nMODULE enModuleArg, SYSCTL_nINTMASK enInterruptMaskArg, SYSCTL_nINTMASK* penInterruptGetArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penInterruptGetArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SYSCTL_nERROR) MCU__enCheckParams((UBase_t) enInterruptMaskArg, (UBase_t) SYSCTL_enINTMASK_MAX);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        SYSCTL_Register_t stRegister;
        stRegister.uxShift = 0U;
        stRegister.uxMask = enInterruptMaskArg;
        stRegister.uptrAddress = SYSCTL_IMC_OFFSET;
        enErrorReg = SYSCTL__enReadRegister(enModuleArg, &stRegister);
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            *penInterruptGetArg = (SYSCTL_nINTMASK) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enGetInterruptSourceStateByNumber(SYSCTL_nMODULE enModuleArg, SYSCTL_nINT enInterruptArg, SYSCTL_nSTATE* penStateArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penStateArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SYSCTL_nERROR) MCU__enCheckParams((UBase_t) enInterruptArg, (UBase_t) SYSCTL_enINT_SW);
    }

    UBase_t uxShiftReg;
    uxShiftReg = 0U;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetInterruptSourceShift(enModuleArg, enInterruptArg, &uxShiftReg);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        SYSCTL_Register_t stRegister;
        stRegister.uxShift = uxShiftReg;
        stRegister.uxMask = SYSCTL_IMC_BOR_MASK;
        stRegister.uptrAddress = SYSCTL_IMC_OFFSET;
        enErrorReg = SYSCTL__enReadRegister(enModuleArg, &stRegister);
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            *penStateArg = (SYSCTL_nSTATE) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enEnableInterruptSourceByMask(SYSCTL_nMODULE enModuleArg, SYSCTL_nINTMASK enInterruptMaskArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL__enSetInterruptSourceStateByMask(enModuleArg, enInterruptMaskArg, SYSCTL_enSTATE_ENA);
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enEnableInterruptSourceByNumber(SYSCTL_nMODULE enModuleArg, SYSCTL_nINT enInterruptArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL__enSetInterruptSourceStateByNumber(enModuleArg, enInterruptArg, SYSCTL_enSTATE_ENA);
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enDisableInterruptSourceByMask(SYSCTL_nMODULE enModuleArg, SYSCTL_nINTMASK enInterruptMaskArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL__enSetInterruptSourceStateByMask(enModuleArg, enInterruptMaskArg, SYSCTL_enSTATE_DIS);
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enDisableInterruptSourceByNumber(SYSCTL_nMODULE enModuleArg, SYSCTL_nINT enInterruptArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL__enSetInterruptSourceStateByNumber(enModuleArg, enInterruptArg, SYSCTL_enSTATE_DIS);
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enClearInterruptSourceByMask(SYSCTL_nMODULE enModuleArg, SYSCTL_nINTMASK enInterruptMaskArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (SYSCTL_nERROR) MCU__enCheckParams((UBase_t) enInterruptMaskArg, (UBase_t) SYSCTL_enINTMASK_MAX);
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        SYSCTL_Register_t stRegister;
        stRegister.uxShift = 0U;
        stRegister.uxMask = MCU_MASK_BASE;
        stRegister.uptrAddress = SYSCTL_MISC_OFFSET;
        stRegister.uxValue = enInterruptMaskArg;
        enErrorReg = SYSCTL__enWriteRegister(enModuleArg, &stRegister);
    }

    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enClearInterruptSourceByNumber(SYSCTL_nMODULE enModuleArg, SYSCTL_nINT enInterruptArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (SYSCTL_nERROR) MCU__enCheckParams((UBase_t) enInterruptArg, (UBase_t) SYSCTL_enINT_SW);

    UBase_t uxShiftReg;
    uxShiftReg = 0UL;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetInterruptSourceShift(enModuleArg, enInterruptArg, &uxShiftReg);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        UBase_t uxValueReg = 1UL;
        uxValueReg <<= uxShiftReg;

        SYSCTL_Register_t stRegister;
        stRegister.uxShift = 0U;
        stRegister.uxMask = MCU_MASK_BASE;
        stRegister.uptrAddress = SYSCTL_MISC_OFFSET;
        stRegister.uxValue = (UBase_t) uxValueReg;
        enErrorReg = SYSCTL__enWriteRegister(enModuleArg, &stRegister);
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enStatusInterruptSourceByMask(SYSCTL_nMODULE enModuleArg, SYSCTL_nINTMASK enInterruptMaskArg, SYSCTL_nINTMASK* penInterruptStatusArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penInterruptStatusArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;

    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SYSCTL_nERROR) MCU__enCheckParams((UBase_t) enInterruptMaskArg, (UBase_t) SYSCTL_enINTMASK_MAX);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        SYSCTL_Register_t stRegister;
        stRegister.uxShift = 0U;
        stRegister.uxMask = enInterruptMaskArg;
        stRegister.uptrAddress = SYSCTL_RIS_OFFSET;
        enErrorReg = SYSCTL__enReadRegister(enModuleArg, &stRegister);
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            *penInterruptStatusArg = (SYSCTL_nINTMASK) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enStatusInterruptSourceByNumber(SYSCTL_nMODULE enModuleArg, SYSCTL_nINT enInterruptArg, SYSCTL_nSTATUS* penStatusArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penStatusArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SYSCTL_nERROR) MCU__enCheckParams((UBase_t) enInterruptArg, (UBase_t) SYSCTL_enINT_SW);
    }

    UBase_t uxShiftReg;
    uxShiftReg = 0UL;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetInterruptSourceShift(enModuleArg, enInterruptArg, &uxShiftReg);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        SYSCTL_Register_t stRegister;
        stRegister.uxShift = uxShiftReg;
        stRegister.uxMask = SYSCTL_RIS_BOR_MASK;
        stRegister.uptrAddress = SYSCTL_RIS_OFFSET;
        enErrorReg = SYSCTL__enReadRegister(enModuleArg, &stRegister);
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            *penStatusArg = (SYSCTL_nSTATUS) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enStatusMaskedInterruptSourceByMask(SYSCTL_nMODULE enModuleArg, SYSCTL_nINTMASK enInterruptMaskArg, SYSCTL_nINTMASK* penInterruptStatusArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penInterruptStatusArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;

    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SYSCTL_nERROR) MCU__enCheckParams((UBase_t) enInterruptMaskArg, (UBase_t) SYSCTL_enINTMASK_MAX);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        SYSCTL_Register_t stRegister;
        stRegister.uxShift = 0U;
        stRegister.uxMask = enInterruptMaskArg;
        stRegister.uptrAddress = SYSCTL_MISC_OFFSET;
        enErrorReg = SYSCTL__enReadRegister(enModuleArg, &stRegister);
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            *penInterruptStatusArg = (SYSCTL_nINTMASK) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enStatusMaskedInterruptSourceByNumber(SYSCTL_nMODULE enModuleArg, SYSCTL_nINT enInterruptArg, SYSCTL_nSTATUS* penStatusArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penStatusArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SYSCTL_nERROR) MCU__enCheckParams((UBase_t) enInterruptArg, (UBase_t) SYSCTL_enINT_SW);
    }

    UBase_t uxShiftReg;
    uxShiftReg = 0UL;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetInterruptSourceShift(enModuleArg, enInterruptArg, &uxShiftReg);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        SYSCTL_Register_t stRegister;
        stRegister.uxShift = uxShiftReg;
        stRegister.uxMask = SYSCTL_MISC_BOR_MASK;
        stRegister.uptrAddress = SYSCTL_MISC_OFFSET;
        enErrorReg = SYSCTL__enReadRegister(enModuleArg, &stRegister);
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            *penStatusArg = (SYSCTL_nSTATUS) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}
