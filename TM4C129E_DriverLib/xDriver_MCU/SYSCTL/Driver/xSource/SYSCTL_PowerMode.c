/**
 *
 * @file SYSCTL_PowerMode.c
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
 * @verbatim 5 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 5 abr. 2026    GitHub Copilot   1.0         initial Version@endverbatim
 */

#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_PowerMode.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/SYSCTL/Driver/Intrinsics/Primitives/SYSCTL_Primitives.h>
#include <xDriver_MCU/SYSCTL/Peripheral/SYSCTL_Peripheral.h>

static SYSCTL_nERROR SYSCTL__enSetPowerModeField(SYSCTL_nMODULE enModuleArg, UBase_t uxAddressArg,
                                                 UBase_t uxMaskArg, UBase_t uxShiftArg, UBase_t uxValueArg);
static SYSCTL_nERROR SYSCTL__enGetPowerModeField(SYSCTL_nMODULE enModuleArg, UBase_t uxAddressArg,
                                                 UBase_t uxMaskArg, UBase_t uxShiftArg, UBase_t* puxValueArg);
static SYSCTL_nERROR SYSCTL__enGetPowerModeState(SYSCTL_nMODULE enModuleArg, UBase_t uxAddressArg,
                                                 UBase_t uxMaskArg, UBase_t uxShiftArg,
                                                 SYSCTL_nBOOLEAN* penStatusArg);

static SYSCTL_nERROR SYSCTL__enSetPowerModeField(SYSCTL_nMODULE enModuleArg, UBase_t uxAddressArg,
                                                 UBase_t uxMaskArg, UBase_t uxShiftArg, UBase_t uxValueArg)
{
    SYSCTL_Register_t stRegister;
    stRegister.uxShift = uxShiftArg;
    stRegister.uxMask = uxMaskArg;
    stRegister.uptrAddress = uxAddressArg;
    stRegister.uxValue = uxValueArg;

    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL__enWriteRegister(enModuleArg, &stRegister);
    return (enErrorReg);
}

static SYSCTL_nERROR SYSCTL__enGetPowerModeField(SYSCTL_nMODULE enModuleArg, UBase_t uxAddressArg,
                                                 UBase_t uxMaskArg, UBase_t uxShiftArg, UBase_t* puxValueArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) puxValueArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        SYSCTL_Register_t stRegister;
        stRegister.uxShift = uxShiftArg;
        stRegister.uxMask = uxMaskArg;
        stRegister.uptrAddress = uxAddressArg;
        enErrorReg = SYSCTL__enReadRegister(enModuleArg, &stRegister);
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            *puxValueArg = stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

static SYSCTL_nERROR SYSCTL__enGetPowerModeState(SYSCTL_nMODULE enModuleArg, UBase_t uxAddressArg,
                                                 UBase_t uxMaskArg, UBase_t uxShiftArg,
                                                 SYSCTL_nBOOLEAN* penStatusArg)
{
    UBase_t uxValueReg;
    SYSCTL_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) penStatusArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetPowerModeField(enModuleArg, uxAddressArg, uxMaskArg, uxShiftArg, &uxValueReg);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        *penStatusArg = (SYSCTL_nBOOLEAN) uxValueReg;
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enSetSRAMPowerModeOnSleepMode(SYSCTL_nMODULE enModuleArg,
                                                    SYSCTL_nSRAM_POWER_MODE enPowerModeArg)
{
    return SYSCTL__enSetPowerModeField(enModuleArg, SLPPWR_CFG_OFFSET, SLPPWR_CFG_SRAM_PM_MASK,
                                       SLPPWR_CFG_R_SRAM_PM_BIT, (UBase_t) enPowerModeArg);
}

SYSCTL_nERROR SYSCTL__enGetSRAMPowerModeOnSleepMode(SYSCTL_nMODULE enModuleArg,
                                                    SYSCTL_nSRAM_POWER_MODE* penPowerModeArg)
{
    UBase_t uxValueReg;
    SYSCTL_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) penPowerModeArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetPowerModeField(enModuleArg, SLPPWR_CFG_OFFSET, SLPPWR_CFG_SRAM_PM_MASK,
                                                 SLPPWR_CFG_R_SRAM_PM_BIT, &uxValueReg);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        *penPowerModeArg = (SYSCTL_nSRAM_POWER_MODE) uxValueReg;
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enSetFlashPowerModeOnSleepMode(SYSCTL_nMODULE enModuleArg,
                                                     SYSCTL_nFLASH_POWER_MODE enPowerModeArg)
{
    return SYSCTL__enSetPowerModeField(enModuleArg, SLPPWR_CFG_OFFSET, SLPPWR_CFG_FLASH_PM_MASK,
                                       SLPPWR_CFG_R_FLASH_PM_BIT, (UBase_t) enPowerModeArg);
}

SYSCTL_nERROR SYSCTL__enGetFlashPowerModeOnSleepMode(SYSCTL_nMODULE enModuleArg,
                                                     SYSCTL_nFLASH_POWER_MODE* penPowerModeArg)
{
    UBase_t uxValueReg;
    SYSCTL_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) penPowerModeArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetPowerModeField(enModuleArg, SLPPWR_CFG_OFFSET, SLPPWR_CFG_FLASH_PM_MASK,
                                                 SLPPWR_CFG_R_FLASH_PM_BIT, &uxValueReg);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        *penPowerModeArg = (SYSCTL_nFLASH_POWER_MODE) uxValueReg;
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enSetPowerModeOnSleepMode(SYSCTL_nMODULE enModuleArg,
                                                SYSCTL_nSRAM_POWER_MODE enSRAMPowerModeArg,
                                                SYSCTL_nFLASH_POWER_MODE enFlashPowerModeArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL__enSetSRAMPowerModeOnSleepMode(enModuleArg, enSRAMPowerModeArg);
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enSetFlashPowerModeOnSleepMode(enModuleArg, enFlashPowerModeArg);
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enGetPowerModeOnSleepMode(SYSCTL_nMODULE enModuleArg,
                                                SYSCTL_nSRAM_POWER_MODE* penSRAMPowerModeArg,
                                                SYSCTL_nFLASH_POWER_MODE* penFlashPowerModeArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL__enGetSRAMPowerModeOnSleepMode(enModuleArg, penSRAMPowerModeArg);
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetFlashPowerModeOnSleepMode(enModuleArg, penFlashPowerModeArg);
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enSetSRAMPowerModeOnDeepSleepMode(SYSCTL_nMODULE enModuleArg,
                                                        SYSCTL_nSRAM_POWER_MODE enPowerModeArg)
{
    return SYSCTL__enSetPowerModeField(enModuleArg, DSLPPWR_CFG_OFFSET, DSLPPWR_CFG_SRAM_PM_MASK,
                                       DSLPPWR_CFG_R_SRAM_PM_BIT, (UBase_t) enPowerModeArg);
}

SYSCTL_nERROR SYSCTL__enGetSRAMPowerModeOnDeepSleepMode(SYSCTL_nMODULE enModuleArg,
                                                        SYSCTL_nSRAM_POWER_MODE* penPowerModeArg)
{
    UBase_t uxValueReg;
    SYSCTL_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) penPowerModeArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetPowerModeField(enModuleArg, DSLPPWR_CFG_OFFSET, DSLPPWR_CFG_SRAM_PM_MASK,
                                                 DSLPPWR_CFG_R_SRAM_PM_BIT, &uxValueReg);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        *penPowerModeArg = (SYSCTL_nSRAM_POWER_MODE) uxValueReg;
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enSetFlashPowerModeOnDeepSleepMode(SYSCTL_nMODULE enModuleArg,
                                                         SYSCTL_nFLASH_POWER_MODE enPowerModeArg)
{
    return SYSCTL__enSetPowerModeField(enModuleArg, DSLPPWR_CFG_OFFSET, DSLPPWR_CFG_FLASH_PM_MASK,
                                       DSLPPWR_CFG_R_FLASH_PM_BIT, (UBase_t) enPowerModeArg);
}

SYSCTL_nERROR SYSCTL__enGetFlashPowerModeOnDeepSleepMode(SYSCTL_nMODULE enModuleArg,
                                                         SYSCTL_nFLASH_POWER_MODE* penPowerModeArg)
{
    UBase_t uxValueReg;
    SYSCTL_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) penPowerModeArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetPowerModeField(enModuleArg, DSLPPWR_CFG_OFFSET, DSLPPWR_CFG_FLASH_PM_MASK,
                                                 DSLPPWR_CFG_R_FLASH_PM_BIT, &uxValueReg);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        *penPowerModeArg = (SYSCTL_nFLASH_POWER_MODE) uxValueReg;
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enSetPowerModeOnDeepSleepMode(SYSCTL_nMODULE enModuleArg,
                                                    SYSCTL_nSRAM_POWER_MODE enSRAMPowerModeArg,
                                                    SYSCTL_nFLASH_POWER_MODE enFlashPowerModeArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL__enSetSRAMPowerModeOnDeepSleepMode(enModuleArg, enSRAMPowerModeArg);
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enSetFlashPowerModeOnDeepSleepMode(enModuleArg, enFlashPowerModeArg);
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enGetPowerModeOnDeepSleepMode(SYSCTL_nMODULE enModuleArg,
                                                    SYSCTL_nSRAM_POWER_MODE* penSRAMPowerModeArg,
                                                    SYSCTL_nFLASH_POWER_MODE* penFlashPowerModeArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL__enGetSRAMPowerModeOnDeepSleepMode(enModuleArg, penSRAMPowerModeArg);
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetFlashPowerModeOnDeepSleepMode(enModuleArg, penFlashPowerModeArg);
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enUseTempSensorPowerDownOnDeepSleepMode(SYSCTL_nMODULE enModuleArg,
                                                              SYSCTL_nSTATE enStateArg)
{
    return SYSCTL__enSetPowerModeField(enModuleArg, DSLPPWR_CFG_OFFSET, DSLPPWR_CFG_TS_PD_MASK,
                                       DSLPPWR_CFG_R_TS_PD_BIT, (UBase_t) enStateArg);
}

SYSCTL_nERROR SYSCTL__enIsTempSensorPowerDownOnDeepSleepModeUsed(SYSCTL_nMODULE enModuleArg,
                                                                 SYSCTL_nBOOLEAN* penStateArg)
{
    return SYSCTL__enGetPowerModeState(enModuleArg, DSLPPWR_CFG_OFFSET, DSLPPWR_CFG_TS_PD_MASK,
                                       DSLPPWR_CFG_R_TS_PD_BIT, penStateArg);
}

SYSCTL_nERROR SYSCTL__enUseLDOSleepModeOnDeepSleepMode(SYSCTL_nMODULE enModuleArg,
                                                       SYSCTL_nSTATE enStateArg)
{
    return SYSCTL__enSetPowerModeField(enModuleArg, DSLPPWR_CFG_OFFSET, DSLPPWR_CFG_LDO_SM_MASK,
                                       DSLPPWR_CFG_R_LDO_SM_BIT, (UBase_t) enStateArg);
}

SYSCTL_nERROR SYSCTL__enIsLDOSleepModeOnDeepSleepModeUsed(SYSCTL_nMODULE enModuleArg,
                                                          SYSCTL_nBOOLEAN* penStateArg)
{
    return SYSCTL__enGetPowerModeState(enModuleArg, DSLPPWR_CFG_OFFSET, DSLPPWR_CFG_LDO_SM_MASK,
                                       DSLPPWR_CFG_R_LDO_SM_BIT, penStateArg);
}

SYSCTL_nERROR SYSCTL__enIsSRAMPowerDownRequestError(SYSCTL_nMODULE enModuleArg,
                                                    SYSCTL_nBOOLEAN* penStatusArg)
{
    return SYSCTL__enGetPowerModeState(enModuleArg, SDP_MST_OFFSET, SDP_MST_SRAM_PD_ERR_MASK,
                                       SDP_MST_R_SRAM_PD_ERR_BIT, penStatusArg);
}

SYSCTL_nERROR SYSCTL__enIsFlashPowerDownRequestError(SYSCTL_nMODULE enModuleArg,
                                                     SYSCTL_nBOOLEAN* penStatusArg)
{
    return SYSCTL__enGetPowerModeState(enModuleArg, SDP_MST_OFFSET, SDP_MST_FLASH_PD_ERR_MASK,
                                       SDP_MST_R_FLASH_PD_ERR_BIT, penStatusArg);
}

SYSCTL_nERROR SYSCTL__enIsPIOSCPowerDownRequestError(SYSCTL_nMODULE enModuleArg,
                                                     SYSCTL_nBOOLEAN* penStatusArg)
{
    return SYSCTL__enGetPowerModeState(enModuleArg, SDP_MST_OFFSET, SDP_MST_PIOSC_PD_ERR_MASK,
                                       SDP_MST_R_PIOSC_PD_ERR_BIT, penStatusArg);
}

SYSCTL_nERROR SYSCTL__enIsDeepSleepLDOMinimumVoltageError(SYSCTL_nMODULE enModuleArg,
                                                          SYSCTL_nBOOLEAN* penStatusArg)
{
    return SYSCTL__enGetPowerModeState(enModuleArg, SDP_MST_OFFSET, SDP_MST_VLDO_DMIN_ERR_MASK,
                                       SDP_MST_R_VLDO_DMIN_ERR_BIT, penStatusArg);
}

SYSCTL_nERROR SYSCTL__enIsSleepLDOMinimumVoltageError(SYSCTL_nMODULE enModuleArg,
                                                      SYSCTL_nBOOLEAN* penStatusArg)
{
    return SYSCTL__enGetPowerModeState(enModuleArg, SDP_MST_OFFSET, SDP_MST_VLDO_SMIN_ERR_MASK,
                                       SDP_MST_R_VLDO_SMIN_ERR_BIT, penStatusArg);
}

SYSCTL_nERROR SYSCTL__enIsLDOMaximumVoltageError(SYSCTL_nMODULE enModuleArg,
                                                 SYSCTL_nBOOLEAN* penStatusArg)
{
    return SYSCTL__enGetPowerModeState(enModuleArg, SDP_MST_OFFSET, SDP_MST_VLDO_MAX_ERR_MASK,
                                       SDP_MST_R_VLDO_MAX_ERR_BIT, penStatusArg);
}

SYSCTL_nERROR SYSCTL__enIsPIOSCPowerDownRequestWarning(SYSCTL_nMODULE enModuleArg,
                                                       SYSCTL_nBOOLEAN* penStatusArg)
{
    return SYSCTL__enGetPowerModeState(enModuleArg, SDP_MST_OFFSET, SDP_MST_PIOSC_PD_WARNING_MASK,
                                       SDP_MST_R_PIOSC_PD_WARNING_BIT, penStatusArg);
}

SYSCTL_nERROR SYSCTL__enIsPowerModeRequestActive(SYSCTL_nMODULE enModuleArg,
                                                 SYSCTL_nBOOLEAN* penStatusArg)
{
    return SYSCTL__enGetPowerModeState(enModuleArg, SDP_MST_OFFSET, SDP_MST_LOW_ACTIVE_MASK,
                                       SDP_MST_R_LOW_ACTIVE_BIT, penStatusArg);
}

SYSCTL_nERROR SYSCTL__enIsLowPowerModeActive(SYSCTL_nMODULE enModuleArg,
                                             SYSCTL_nBOOLEAN* penStatusArg)
{
    return SYSCTL__enGetPowerModeState(enModuleArg, SDP_MST_OFFSET, SDP_MST_LOW_PWR_MASK,
                                       SDP_MST_R_LOW_PWR_BIT, penStatusArg);
}

SYSCTL_nERROR SYSCTL__enIsFlashLowPowerModeActive(SYSCTL_nMODULE enModuleArg,
                                                  SYSCTL_nBOOLEAN* penStatusArg)
{
    return SYSCTL__enGetPowerModeState(enModuleArg, SDP_MST_OFFSET, SDP_MST_FLASH_LP_MASK,
                                       SDP_MST_R_FLASH_LP_BIT, penStatusArg);
}

SYSCTL_nERROR SYSCTL__enIsLDOUpdateActive(SYSCTL_nMODULE enModuleArg,
                                          SYSCTL_nBOOLEAN* penStatusArg)
{
    return SYSCTL__enGetPowerModeState(enModuleArg, SDP_MST_OFFSET, SDP_MST_LDO_UA_MASK,
                                       SDP_MST_R_LDO_UA_BIT, penStatusArg);
}
