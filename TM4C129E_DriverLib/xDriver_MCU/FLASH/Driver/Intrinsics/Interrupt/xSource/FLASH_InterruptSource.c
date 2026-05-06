/**
 *
 * @file FLASH_InterruptSource.c
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
 * @verbatim 10 ago. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 10 ago. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/FLASH/Driver/Intrinsics/Interrupt/xHeader/FLASH_InterruptSource.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/FLASH/Peripheral/FLASH_Peripheral.h>
#include <xDriver_MCU/FLASH/Driver/Intrinsics/Primitives/FLASH_Primitives.h>


FLASH_nERROR FLASH__enGetInterruptSourceShift(FLASH_nMODULE enModuleArg, FLASH_nINT enInterruptArg, UBase_t* puxShiftArg)
{
    FLASH_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) puxShiftArg) ? FLASH_enERROR_POINTER : FLASH_enERROR_OK;
    if(FLASH_enERROR_OK == enErrorReg)
    {
        enErrorReg = (FLASH_nERROR) MCU__enCheckParams_RAM((UBase_t) enModuleArg, (UBase_t) FLASH_enMODULE_MAX);
    }
    if(FLASH_enERROR_OK == enErrorReg)
    {
        enErrorReg = (FLASH_nERROR) MCU__enCheckParams_RAM((UBase_t) enInterruptArg, (UBase_t) FLASH_enINT_SW);
    }
    if(FLASH_enERROR_OK == enErrorReg)
    {
        static const UBase_t FLASH_uxInterruptBit[(UBase_t) FLASH_enINT_SW] =
        {
         FLASH_RIS_R_ARIS_BIT   , FLASH_RIS_R_PRIS_BIT , FLASH_RIS_R_ERIS_BIT   , FLASH_RIS_R_VOLTRIS_BIT,
         FLASH_RIS_R_INVDRIS_BIT, FLASH_RIS_R_ERRIS_BIT, FLASH_RIS_R_PROGRIS_BIT
        };
        *puxShiftArg = FLASH_uxInterruptBit[(UBase_t) enInterruptArg];
    }
    return (enErrorReg);
}

FLASH_nERROR FLASH__enSetInterruptSourceStateByMask(FLASH_nMODULE enModuleArg, FLASH_nINTMASK enInterruptMaskArg, FLASH_nSTATE enStateArg)
{
    FLASH_nERROR enErrorReg;
    enErrorReg = (FLASH_nERROR) MCU__enCheckParams_RAM((UBase_t) enInterruptMaskArg, (UBase_t) FLASH_enINTMASK_MAX);
    if(FLASH_enERROR_OK == enErrorReg)
    {
        UBase_t uxValueReg = (FLASH_enSTATE_DIS == enStateArg) ? 0U : (UBase_t) enInterruptMaskArg;

        FLASH_Register_t stRegister;
        stRegister.uxShift = 0U;
        stRegister.uxMask = enInterruptMaskArg;
        stRegister.uptrAddress = FLASH_IM_OFFSET;
        stRegister.uxValue = uxValueReg;
        enErrorReg = FLASH__enWriteRegister(enModuleArg, &stRegister);
    }

    return (enErrorReg);
}

FLASH_nERROR FLASH__enSetInterruptSourceStateByNumber(FLASH_nMODULE enModuleArg, FLASH_nINT enInterruptArg, FLASH_nSTATE enStateArg)
{
    FLASH_nERROR enErrorReg;
    enErrorReg = (FLASH_nERROR) MCU__enCheckParams_RAM((UBase_t) enInterruptArg, (UBase_t) FLASH_enINT_SW);

    UBase_t uxShiftReg;
    uxShiftReg = 0UL;
    if(FLASH_enERROR_OK == enErrorReg)
    {
        enErrorReg = FLASH__enGetInterruptSourceShift(enModuleArg, enInterruptArg, &uxShiftReg);
    }
    if(FLASH_enERROR_OK == enErrorReg)
    {
        FLASH_Register_t stRegister;
        stRegister.uxShift = uxShiftReg;
        stRegister.uxMask = FLASH_IM_AMASK_MASK;
        stRegister.uptrAddress = FLASH_IM_OFFSET;
        stRegister.uxValue = (UBase_t) enStateArg;
        enErrorReg = FLASH__enWriteRegister(enModuleArg, &stRegister);
    }
    return (enErrorReg);
}

FLASH_nERROR FLASH__enGetInterruptSourceStateByMask(FLASH_nMODULE enModuleArg, FLASH_nINTMASK enInterruptMaskArg, FLASH_nINTMASK* penInterruptGetArg)
{
    FLASH_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penInterruptGetArg) ? FLASH_enERROR_POINTER : FLASH_enERROR_OK;
    if(FLASH_enERROR_OK == enErrorReg)
    {
        enErrorReg = (FLASH_nERROR) MCU__enCheckParams_RAM((UBase_t) enInterruptMaskArg, (UBase_t) FLASH_enINTMASK_MAX);
    }
    if(FLASH_enERROR_OK == enErrorReg)
    {
        FLASH_Register_t stRegister;
        stRegister.uxShift = 0U;
        stRegister.uxMask = enInterruptMaskArg;
        stRegister.uptrAddress = FLASH_IM_OFFSET;
        enErrorReg = FLASH__enReadRegister(enModuleArg, &stRegister);
        if(FLASH_enERROR_OK == enErrorReg)
        {
            *penInterruptGetArg = (FLASH_nINTMASK) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

FLASH_nERROR FLASH__enGetInterruptSourceStateByNumber(FLASH_nMODULE enModuleArg, FLASH_nINT enInterruptArg, FLASH_nSTATE* penStateArg)
{
    FLASH_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penStateArg) ? FLASH_enERROR_POINTER : FLASH_enERROR_OK;
    if(FLASH_enERROR_OK == enErrorReg)
    {
        enErrorReg = (FLASH_nERROR) MCU__enCheckParams_RAM((UBase_t) enInterruptArg, (UBase_t) FLASH_enINT_SW);
    }

    UBase_t uxShiftReg;
    uxShiftReg = 0U;
    if(FLASH_enERROR_OK == enErrorReg)
    {
        enErrorReg = FLASH__enGetInterruptSourceShift(enModuleArg, enInterruptArg, &uxShiftReg);
    }
    if(FLASH_enERROR_OK == enErrorReg)
    {
        FLASH_Register_t stRegister;
        stRegister.uxShift = uxShiftReg;
        stRegister.uxMask = FLASH_IM_AMASK_MASK;
        stRegister.uptrAddress = FLASH_IM_OFFSET;
        enErrorReg = FLASH__enReadRegister(enModuleArg, &stRegister);
        if(FLASH_enERROR_OK == enErrorReg)
        {
            *penStateArg = (FLASH_nSTATE) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

FLASH_nERROR FLASH__enEnableInterruptSourceByMask(FLASH_nMODULE enModuleArg, FLASH_nINTMASK enInterruptMaskArg)
{
    FLASH_nERROR enErrorReg;
    enErrorReg = FLASH__enSetInterruptSourceStateByMask(enModuleArg, enInterruptMaskArg, FLASH_enSTATE_ENA);
    return (enErrorReg);
}

FLASH_nERROR FLASH__enEnableInterruptSourceByNumber(FLASH_nMODULE enModuleArg, FLASH_nINT enInterruptArg)
{
    FLASH_nERROR enErrorReg;
    enErrorReg = FLASH__enSetInterruptSourceStateByNumber(enModuleArg, enInterruptArg, FLASH_enSTATE_ENA);
    return (enErrorReg);
}

FLASH_nERROR FLASH__enDisableInterruptSourceByMask(FLASH_nMODULE enModuleArg, FLASH_nINTMASK enInterruptMaskArg)
{
    FLASH_nERROR enErrorReg;
    enErrorReg = FLASH__enSetInterruptSourceStateByMask(enModuleArg, enInterruptMaskArg, FLASH_enSTATE_DIS);
    return (enErrorReg);
}

FLASH_nERROR FLASH__enDisableInterruptSourceByNumber(FLASH_nMODULE enModuleArg, FLASH_nINT enInterruptArg)
{
    FLASH_nERROR enErrorReg;
    enErrorReg = FLASH__enSetInterruptSourceStateByNumber(enModuleArg, enInterruptArg, FLASH_enSTATE_DIS);
    return (enErrorReg);
}

FLASH_nERROR FLASH__enClearInterruptSourceByMask(FLASH_nMODULE enModuleArg, FLASH_nINTMASK enInterruptMaskArg)
{
    FLASH_nERROR enErrorReg;
    enErrorReg = (FLASH_nERROR) MCU__enCheckParams_RAM((UBase_t) enInterruptMaskArg, (UBase_t) FLASH_enINTMASK_MAX);
    if(FLASH_enERROR_OK == enErrorReg)
    {
        FLASH_Register_t stRegister;
        stRegister.uxShift = 0U;
        stRegister.uxMask = MCU_MASK_BASE;
        stRegister.uptrAddress = FLASH_MISC_OFFSET;
        stRegister.uxValue = enInterruptMaskArg;
        enErrorReg = FLASH__enWriteRegister(enModuleArg, &stRegister);
    }

    return (enErrorReg);
}

FLASH_nERROR FLASH__enClearInterruptSourceByNumber(FLASH_nMODULE enModuleArg, FLASH_nINT enInterruptArg)
{
    FLASH_nERROR enErrorReg;
    enErrorReg = (FLASH_nERROR) MCU__enCheckParams_RAM((UBase_t) enInterruptArg, (UBase_t) FLASH_enINT_SW);

    UBase_t uxShiftReg;
    uxShiftReg = 0UL;
    if(FLASH_enERROR_OK == enErrorReg)
    {
        enErrorReg = FLASH__enGetInterruptSourceShift(enModuleArg, enInterruptArg, &uxShiftReg);
    }
    if(FLASH_enERROR_OK == enErrorReg)
    {
        UBase_t uxValueReg = 1UL;
        uxValueReg <<= uxShiftReg;

        FLASH_Register_t stRegister;
        stRegister.uxShift = 0U;
        stRegister.uxMask = MCU_MASK_BASE;
        stRegister.uptrAddress = FLASH_MISC_OFFSET;
        stRegister.uxValue = (UBase_t) uxValueReg;
        enErrorReg = FLASH__enWriteRegister(enModuleArg, &stRegister);
    }
    return (enErrorReg);
}

FLASH_nERROR FLASH__enStatusInterruptSourceByMask(FLASH_nMODULE enModuleArg, FLASH_nINTMASK enInterruptMaskArg, FLASH_nINTMASK* penInterruptStatusArg)
{
    FLASH_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penInterruptStatusArg) ? FLASH_enERROR_POINTER : FLASH_enERROR_OK;

    if(FLASH_enERROR_OK == enErrorReg)
    {
        enErrorReg = (FLASH_nERROR) MCU__enCheckParams_RAM((UBase_t) enInterruptMaskArg, (UBase_t) FLASH_enINTMASK_MAX);
    }
    if(FLASH_enERROR_OK == enErrorReg)
    {
        FLASH_Register_t stRegister;
        stRegister.uxShift = 0U;
        stRegister.uxMask = enInterruptMaskArg;
        stRegister.uptrAddress = FLASH_RIS_OFFSET;
        enErrorReg = FLASH__enReadRegister(enModuleArg, &stRegister);
        if(FLASH_enERROR_OK == enErrorReg)
        {
            *penInterruptStatusArg = (FLASH_nINTMASK) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

FLASH_nERROR FLASH__enStatusInterruptSourceByNumber(FLASH_nMODULE enModuleArg, FLASH_nINT enInterruptArg, FLASH_nSTATUS* penStatusArg)
{
    FLASH_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penStatusArg) ? FLASH_enERROR_POINTER : FLASH_enERROR_OK;
    if(FLASH_enERROR_OK == enErrorReg)
    {
        enErrorReg = (FLASH_nERROR) MCU__enCheckParams_RAM((UBase_t) enInterruptArg, (UBase_t) FLASH_enINT_SW);
    }

    UBase_t uxShiftReg;
    uxShiftReg = 0UL;
    if(FLASH_enERROR_OK == enErrorReg)
    {
        enErrorReg = FLASH__enGetInterruptSourceShift(enModuleArg, enInterruptArg, &uxShiftReg);
    }
    if(FLASH_enERROR_OK == enErrorReg)
    {
        FLASH_Register_t stRegister;
        stRegister.uxShift = uxShiftReg;
        stRegister.uxMask = FLASH_RIS_ARIS_MASK;
        stRegister.uptrAddress = FLASH_RIS_OFFSET;
        enErrorReg = FLASH__enReadRegister(enModuleArg, &stRegister);
        if(FLASH_enERROR_OK == enErrorReg)
        {
            *penStatusArg = (FLASH_nSTATUS) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

FLASH_nERROR FLASH__enStatusMaskedInterruptSourceByMask(FLASH_nMODULE enModuleArg, FLASH_nINTMASK enInterruptMaskArg, FLASH_nINTMASK* penInterruptStatusArg)
{
    FLASH_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penInterruptStatusArg) ? FLASH_enERROR_POINTER : FLASH_enERROR_OK;

    if(FLASH_enERROR_OK == enErrorReg)
    {
        enErrorReg = (FLASH_nERROR) MCU__enCheckParams_RAM((UBase_t) enInterruptMaskArg, (UBase_t) FLASH_enINTMASK_MAX);
    }
    if(FLASH_enERROR_OK == enErrorReg)
    {
        FLASH_Register_t stRegister;
        stRegister.uxShift = 0U;
        stRegister.uxMask = enInterruptMaskArg;
        stRegister.uptrAddress = FLASH_MISC_OFFSET;
        enErrorReg = FLASH__enReadRegister(enModuleArg, &stRegister);
        if(FLASH_enERROR_OK == enErrorReg)
        {
            *penInterruptStatusArg = (FLASH_nINTMASK) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

FLASH_nERROR FLASH__enStatusMaskedInterruptSourceByNumber(FLASH_nMODULE enModuleArg, FLASH_nINT enInterruptArg, FLASH_nSTATUS* penStatusArg)
{
    FLASH_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penStatusArg) ? FLASH_enERROR_POINTER : FLASH_enERROR_OK;
    if(FLASH_enERROR_OK == enErrorReg)
    {
        enErrorReg = (FLASH_nERROR) MCU__enCheckParams_RAM((UBase_t) enInterruptArg, (UBase_t) FLASH_enINT_SW);
    }

    UBase_t uxShiftReg;
    uxShiftReg = 0UL;
    if(FLASH_enERROR_OK == enErrorReg)
    {
        enErrorReg = FLASH__enGetInterruptSourceShift(enModuleArg, enInterruptArg, &uxShiftReg);
    }
    if(FLASH_enERROR_OK == enErrorReg)
    {
        FLASH_Register_t stRegister;
        stRegister.uxShift = uxShiftReg;
        stRegister.uxMask = FLASH_MISC_AMISC_MASK;
        stRegister.uptrAddress = FLASH_MISC_OFFSET;
        enErrorReg = FLASH__enReadRegister(enModuleArg, &stRegister);
        if(FLASH_enERROR_OK == enErrorReg)
        {
            *penStatusArg = (FLASH_nSTATUS) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}
