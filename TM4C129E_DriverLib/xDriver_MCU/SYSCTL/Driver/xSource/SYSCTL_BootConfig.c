/**
 *
 * @file SYSCTL_BootConfig.c
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
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_BootConfig.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/SYSCTL/Driver/Intrinsics/Primitives/SYSCTL_Primitives.h>
#include <xDriver_MCU/SYSCTL/Peripheral/SYSCTL_Peripheral.h>

static SYSCTL_nERROR SYSCTL__enGetBootConfigValue(SYSCTL_nMODULE enModuleArg, UBase_t uxMaskArg,
                                                  UBase_t uxShiftArg, UBase_t* puxValueArg);
static SYSCTL_nERROR SYSCTL__enGetBootConfigState(SYSCTL_nMODULE enModuleArg, UBase_t uxMaskArg,
                                                  UBase_t uxShiftArg, SYSCTL_nBOOLEAN* penStateArg);

static SYSCTL_nERROR SYSCTL__enGetBootConfigValue(SYSCTL_nMODULE enModuleArg, UBase_t uxMaskArg,
                                                  UBase_t uxShiftArg, UBase_t* puxValueArg)
{
    SYSCTL_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) puxValueArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        SYSCTL_Register_t stRegister;
        stRegister.uxShift = uxShiftArg;
        stRegister.uxMask = uxMaskArg;
        stRegister.uptrAddress = BOOT_CFG_OFFSET;
        enErrorReg = SYSCTL__enReadRegister(enModuleArg, &stRegister);
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            *puxValueArg = stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

static SYSCTL_nERROR SYSCTL__enGetBootConfigState(SYSCTL_nMODULE enModuleArg, UBase_t uxMaskArg,
                                                  UBase_t uxShiftArg, SYSCTL_nBOOLEAN* penStateArg)
{
    SYSCTL_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) penStateArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        UBase_t uxValueReg;
        enErrorReg = SYSCTL__enGetBootConfigValue(enModuleArg, uxMaskArg, uxShiftArg, &uxValueReg);
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            *penStateArg = (SYSCTL_nBOOLEAN) uxValueReg;
        }
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enGetBootConfigDebug0(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStateArg)
{
    return SYSCTL__enGetBootConfigState(enModuleArg, BOOT_CFG_DBG0_MASK, BOOT_CFG_R_DBG0_BIT, penStateArg);
}

SYSCTL_nERROR SYSCTL__enGetBootConfigDebug1(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStateArg)
{
    return SYSCTL__enGetBootConfigState(enModuleArg, BOOT_CFG_DBG1_MASK, BOOT_CFG_R_DBG1_BIT, penStateArg);
}

SYSCTL_nERROR SYSCTL__enGetBootConfigKey(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStateArg)
{
    return SYSCTL__enGetBootConfigState(enModuleArg, BOOT_CFG_KEY_MASK, BOOT_CFG_R_KEY_BIT, penStateArg);
}

SYSCTL_nERROR SYSCTL__enGetBootConfigGPIOEnable(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStateArg)
{
    return SYSCTL__enGetBootConfigState(enModuleArg, BOOT_CFG_EN_MASK, BOOT_CFG_R_EN_BIT, penStateArg);
}

SYSCTL_nERROR SYSCTL__enGetBootConfigGPIOPolarity(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStateArg)
{
    return SYSCTL__enGetBootConfigState(enModuleArg, BOOT_CFG_POL_MASK, BOOT_CFG_R_POL_BIT, penStateArg);
}

SYSCTL_nERROR SYSCTL__enGetBootConfigGPIOPin(SYSCTL_nMODULE enModuleArg, UBase_t* puxPinArg)
{
    return SYSCTL__enGetBootConfigValue(enModuleArg, BOOT_CFG_PIN_MASK, BOOT_CFG_R_PIN_BIT, puxPinArg);
}

SYSCTL_nERROR SYSCTL__enGetBootConfigGPIOPort(SYSCTL_nMODULE enModuleArg, UBase_t* puxPortArg)
{
    return SYSCTL__enGetBootConfigValue(enModuleArg, BOOT_CFG_PORT_MASK, BOOT_CFG_R_PORT_BIT, puxPortArg);
}

SYSCTL_nERROR SYSCTL__enGetBootConfigNotWritten(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStateArg)
{
    return SYSCTL__enGetBootConfigState(enModuleArg, BOOT_CFG_NW_MASK, BOOT_CFG_R_NW_BIT, penStateArg);
}