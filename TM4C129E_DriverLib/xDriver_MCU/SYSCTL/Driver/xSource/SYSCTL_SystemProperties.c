/**
 *
 * @file SYSCTL_SystemProperties.c
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
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_SystemProperties.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/SYSCTL/Driver/Intrinsics/Primitives/SYSCTL_Primitives.h>
#include <xDriver_MCU/SYSCTL/Peripheral/SYSCTL_Peripheral.h>

static SYSCTL_nERROR SYSCTL__enGetSystemPropertyState(SYSCTL_nMODULE enModuleArg, UBase_t uxMaskArg,
                                                      UBase_t uxShiftArg, SYSCTL_nBOOLEAN* penStateArg);

static SYSCTL_nERROR SYSCTL__enGetSystemPropertyState(SYSCTL_nMODULE enModuleArg, UBase_t uxMaskArg,
                                                      UBase_t uxShiftArg, SYSCTL_nBOOLEAN* penStateArg)
{
    SYSCTL_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) penStateArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        SYSCTL_Register_t stRegister;
        stRegister.uxShift = uxShiftArg;
        stRegister.uxMask = uxMaskArg;
        stRegister.uptrAddress = SYSCTL_PROP_OFFSET;
        enErrorReg = SYSCTL__enReadRegister(enModuleArg, &stRegister);
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            *penStateArg = (SYSCTL_nBOOLEAN) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enIsFPUPresent(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStateArg)
{
    return SYSCTL__enGetSystemPropertyState(enModuleArg, SYSCTL_PROP_FPU_MASK, SYSCTL_PROP_R_FPU_BIT, penStateArg);
}

SYSCTL_nERROR SYSCTL__enIsLDOSequenceSupported(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStateArg)
{
    return SYSCTL__enGetSystemPropertyState(enModuleArg, SYSCTL_PROP_LDO_SEQ_MASK, SYSCTL_PROP_R_LDO_SEQ_BIT,
                                            penStateArg);
}

SYSCTL_nERROR SYSCTL__enIsFlashLowPowerModeSupported(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStateArg)
{
    return SYSCTL__enGetSystemPropertyState(enModuleArg, SYSCTL_PROP_FLASH_LPM_MASK, SYSCTL_PROP_R_FLASH_LPM_BIT,
                                            penStateArg);
}

SYSCTL_nERROR SYSCTL__enIsSRAMLowPowerModeSupported(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStateArg)
{
    return SYSCTL__enGetSystemPropertyState(enModuleArg, SYSCTL_PROP_SRAM_LPM_MASK, SYSCTL_PROP_R_SRAM_LPM_BIT,
                                            penStateArg);
}

SYSCTL_nERROR SYSCTL__enIsSRAMStandbyModeSupported(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStateArg)
{
    return SYSCTL__enGetSystemPropertyState(enModuleArg, SYSCTL_PROP_SRAM_SM_MASK, SYSCTL_PROP_R_SRAM_SM_BIT,
                                            penStateArg);
}

SYSCTL_nERROR SYSCTL__enIsPIOSCPowerDownModeSupported(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStateArg)
{
    return SYSCTL__enGetSystemPropertyState(enModuleArg, SYSCTL_PROP_PIOSC_PDE_MASK, SYSCTL_PROP_R_PIOSC_PDE_BIT,
                                            penStateArg);
}

SYSCTL_nERROR SYSCTL__enIsTempSensorPowerDownModeSupported(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStateArg)
{
    return SYSCTL__enGetSystemPropertyState(enModuleArg, SYSCTL_PROP_TS_PDE_MASK, SYSCTL_PROP_R_TS_PDE_BIT,
                                            penStateArg);
}

SYSCTL_nERROR SYSCTL__enIsLDOSleepModeSupported(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStateArg)
{
    return SYSCTL__enGetSystemPropertyState(enModuleArg, SYSCTL_PROP_LDO_SME_MASK, SYSCTL_PROP_R_LDO_SME_BIT,
                                            penStateArg);
}
