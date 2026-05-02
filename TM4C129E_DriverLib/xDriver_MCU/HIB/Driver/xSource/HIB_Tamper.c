/**
 *
 * @file HIB_Tamper.c
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
#include <xDriver_MCU/HIB/Driver/xHeader/HIB_Tamper.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/HIB/Driver/Intrinsics/HIB_Intrinsics.h>
#include <xDriver_MCU/HIB/Peripheral/HIB_Peripheral.h>

static HIB_nERROR HIB__enReadTamperField(HIB_nMODULE enModuleArg, uintptr_t uptrAddressArg,
                                         UBase_t uxMaskArg, UBase_t uxShiftArg,
                                         UBase_t* puxValueArg);
static HIB_nERROR HIB__enWriteTamperField(HIB_nMODULE enModuleArg, uintptr_t uptrAddressArg,
                                          UBase_t uxMaskArg, UBase_t uxShiftArg,
                                          UBase_t uxValueArg);
static HIB_nERROR HIB__enReadTamperRegister(HIB_nMODULE enModuleArg, uintptr_t uptrAddressArg,
                                            UBase_t* puxValueArg);
static HIB_nERROR HIB__enTamperUnlock(HIB_nMODULE enModuleArg, HIB_nBOOLEAN* penLockStateArg);
static HIB_nERROR HIB__enTamperRelock(HIB_nMODULE enModuleArg, HIB_nBOOLEAN enLockStateArg,
                                      HIB_nERROR enErrorArg);
static HIB_nERROR HIB__enGetTamperShift(HIB_nTAMPER enTamperArg, UBase_t uxOffsetArg,
                                        UBase_t* puxShiftArg);

static HIB_nERROR HIB__enReadTamperField(HIB_nMODULE enModuleArg, uintptr_t uptrAddressArg,
                                         UBase_t uxMaskArg, UBase_t uxShiftArg,
                                         UBase_t* puxValueArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) puxValueArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        HIB_Register_t stRegister;

        stRegister.uxShift = uxShiftArg;
        stRegister.uxMask = uxMaskArg;
        stRegister.uptrAddress = uptrAddressArg;
        stRegister.uxValue = 0UL;

        enErrorReg = HIB__enReadRegister(enModuleArg, &stRegister);
        if(HIB_enERROR_OK == enErrorReg)
        {
            *puxValueArg = stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

static HIB_nERROR HIB__enWriteTamperField(HIB_nMODULE enModuleArg, uintptr_t uptrAddressArg,
                                          UBase_t uxMaskArg, UBase_t uxShiftArg,
                                          UBase_t uxValueArg)
{
    HIB_Register_t stRegister;

    stRegister.uxShift = uxShiftArg;
    stRegister.uxMask = uxMaskArg;
    stRegister.uptrAddress = uptrAddressArg;
    stRegister.uxValue = uxValueArg;

    return HIB__enWriteRegister(enModuleArg, &stRegister);
}

static HIB_nERROR HIB__enReadTamperRegister(HIB_nMODULE enModuleArg, uintptr_t uptrAddressArg,
                                            UBase_t* puxValueArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) puxValueArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        HIB_Register_t stRegister;

        stRegister.uxShift = 0UL;
        stRegister.uxMask = MCU_MASK_BASE;
        stRegister.uptrAddress = uptrAddressArg;
        stRegister.uxValue = 0UL;

        enErrorReg = HIB__enReadRegister(enModuleArg, &stRegister);
        if(HIB_enERROR_OK == enErrorReg)
        {
            *puxValueArg = stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

static HIB_nERROR HIB__enTamperUnlock(HIB_nMODULE enModuleArg, HIB_nBOOLEAN* penLockStateArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = HIB__enIsLocked(enModuleArg, penLockStateArg);
    if((HIB_enERROR_OK == enErrorReg) && (HIB_enTRUE == *penLockStateArg))
    {
        enErrorReg = HIB__enUnlock(enModuleArg);
    }
    return (enErrorReg);
}

static HIB_nERROR HIB__enTamperRelock(HIB_nMODULE enModuleArg, HIB_nBOOLEAN enLockStateArg,
                                      HIB_nERROR enErrorArg)
{
    if(HIB_enTRUE == enLockStateArg)
    {
        HIB_nERROR enLockErrorReg;

        enLockErrorReg = HIB__enLock(enModuleArg);
        if(HIB_enERROR_OK == enErrorArg)
        {
            enErrorArg = enLockErrorReg;
        }
    }
    return enErrorArg;
}

static HIB_nERROR HIB__enGetTamperShift(HIB_nTAMPER enTamperArg, UBase_t uxOffsetArg,
                                        UBase_t* puxShiftArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) puxShiftArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = (HIB_enTAMPER_MAX <= enTamperArg) ? HIB_enERROR_RANGE : HIB_enERROR_OK;
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        *puxShiftArg = (((UBase_t) enTamperArg) << 3UL) + uxOffsetArg;
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enIsTamperPresent(HIB_nMODULE enModuleArg, HIB_nBOOLEAN* penPresentArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxValueReg;

    enErrorReg = (0UL == (uintptr_t) penPresentArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    uxValueReg = 0UL;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadTamperField(enModuleArg, HIB_PP_OFFSET, HIB_PP_TAMPER_MASK,
                                            HIB_PP_R_TAMPER_BIT, &uxValueReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        *penPresentArg = (0UL != uxValueReg) ? HIB_enTRUE : HIB_enFALSE;
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enSetTamperState(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg)
{
    HIB_nBOOLEAN enLockStateReg;
    HIB_nERROR enErrorReg;
    UBase_t uxValueReg;

    enLockStateReg = HIB_enFALSE;
    uxValueReg = (HIB_enSTATE_ENA == enStateArg) ? HIB_TPCTL_TPEN_ENA : HIB_TPCTL_TPEN_DIS;
    enErrorReg = HIB__enTamperUnlock(enModuleArg, &enLockStateReg);
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enWriteTamperField(enModuleArg, HIB_TPCTL_OFFSET, HIB_TPCTL_TPEN_MASK,
                                             HIB_TPCTL_R_TPEN_BIT, uxValueReg);
    }
    return HIB__enTamperRelock(enModuleArg, enLockStateReg, enErrorReg);
}

HIB_nERROR HIB__enGetTamperState(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxValueReg;

    enErrorReg = (0UL == (uintptr_t) penStateArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    uxValueReg = 0UL;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadTamperField(enModuleArg, HIB_TPCTL_OFFSET, HIB_TPCTL_TPEN_MASK,
                                            HIB_TPCTL_R_TPEN_BIT, &uxValueReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        *penStateArg = (0UL != uxValueReg) ? HIB_enSTATE_ENA : HIB_enSTATE_DIS;
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enSetTamperWakeState(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg)
{
    HIB_nBOOLEAN enLockStateReg;
    HIB_nERROR enErrorReg;
    UBase_t uxValueReg;

    enLockStateReg = HIB_enFALSE;
    uxValueReg = (HIB_enSTATE_ENA == enStateArg) ? HIB_TPCTL_WAKE_ENA : HIB_TPCTL_WAKE_DIS;
    enErrorReg = HIB__enTamperUnlock(enModuleArg, &enLockStateReg);
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enWriteTamperField(enModuleArg, HIB_TPCTL_OFFSET, HIB_TPCTL_WAKE_MASK,
                                             HIB_TPCTL_R_WAKE_BIT, uxValueReg);
    }
    return HIB__enTamperRelock(enModuleArg, enLockStateReg, enErrorReg);
}

HIB_nERROR HIB__enGetTamperWakeState(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxValueReg;

    enErrorReg = (0UL == (uintptr_t) penStateArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    uxValueReg = 0UL;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadTamperField(enModuleArg, HIB_TPCTL_OFFSET, HIB_TPCTL_WAKE_MASK,
                                            HIB_TPCTL_R_WAKE_BIT, &uxValueReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        *penStateArg = (0UL != uxValueReg) ? HIB_enSTATE_ENA : HIB_enSTATE_DIS;
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enSetTamperMemoryClear(HIB_nMODULE enModuleArg, HIB_nTAMPER_MEMCLR enStateArg)
{
    HIB_nBOOLEAN enLockStateReg;
    HIB_nERROR enErrorReg;

    enLockStateReg = HIB_enFALSE;
    enErrorReg = (HIB_enTAMPER_MEMCLR_ALL < enStateArg) ? HIB_enERROR_VALUE : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enTamperUnlock(enModuleArg, &enLockStateReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enWriteTamperField(enModuleArg, HIB_TPCTL_OFFSET, HIB_TPCTL_MEMCLR_MASK,
                                             HIB_TPCTL_R_MEMCLR_BIT, (UBase_t) enStateArg);
    }
    return HIB__enTamperRelock(enModuleArg, enLockStateReg, enErrorReg);
}

HIB_nERROR HIB__enGetTamperMemoryClear(HIB_nMODULE enModuleArg, HIB_nTAMPER_MEMCLR* penStateArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxValueReg;

    enErrorReg = (0UL == (uintptr_t) penStateArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    uxValueReg = 0UL;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadTamperField(enModuleArg, HIB_TPCTL_OFFSET, HIB_TPCTL_MEMCLR_MASK,
                                            HIB_TPCTL_R_MEMCLR_BIT, &uxValueReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        *penStateArg = (HIB_nTAMPER_MEMCLR) uxValueReg;
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enClearTamperEvent(HIB_nMODULE enModuleArg)
{
    HIB_nBOOLEAN enLockStateReg;
    HIB_nERROR enErrorReg;

    enLockStateReg = HIB_enFALSE;
    enErrorReg = HIB__enTamperUnlock(enModuleArg, &enLockStateReg);
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enWriteTamperField(enModuleArg, HIB_TPCTL_OFFSET, HIB_TPCTL_TPCLR_MASK,
                                             HIB_TPCTL_R_TPCLR_BIT, HIB_TPCTL_TPCLR_CLEAR);
    }
    return HIB__enTamperRelock(enModuleArg, enLockStateReg, enErrorReg);
}

HIB_nERROR HIB__enSetTamperPinState(HIB_nMODULE enModuleArg, HIB_nTAMPER enTamperArg,
                                    HIB_nSTATE enStateArg)
{
    HIB_nBOOLEAN enLockStateReg;
    HIB_nERROR enErrorReg;
    UBase_t uxShiftReg;
    UBase_t uxValueReg;

    enLockStateReg = HIB_enFALSE;
    uxShiftReg = 0UL;
    uxValueReg = (HIB_enSTATE_ENA == enStateArg) ? 1UL : 0UL;
    enErrorReg = HIB__enGetTamperShift(enTamperArg, 0UL, &uxShiftReg);
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enTamperUnlock(enModuleArg, &enLockStateReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enWriteTamperField(enModuleArg, HIB_TPIO_OFFSET, HIB_TPIO_EN0_MASK,
                                             uxShiftReg, uxValueReg);
    }
    return HIB__enTamperRelock(enModuleArg, enLockStateReg, enErrorReg);
}

HIB_nERROR HIB__enGetTamperPinState(HIB_nMODULE enModuleArg, HIB_nTAMPER enTamperArg,
                                    HIB_nSTATE* penStateArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxShiftReg;
    UBase_t uxValueReg;

    enErrorReg = (0UL == (uintptr_t) penStateArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    uxShiftReg = 0UL;
    uxValueReg = 0UL;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enGetTamperShift(enTamperArg, 0UL, &uxShiftReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadTamperField(enModuleArg, HIB_TPIO_OFFSET, HIB_TPIO_EN0_MASK,
                                            uxShiftReg, &uxValueReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        *penStateArg = (0UL != uxValueReg) ? HIB_enSTATE_ENA : HIB_enSTATE_DIS;
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enSetTamperPinLevel(HIB_nMODULE enModuleArg, HIB_nTAMPER enTamperArg,
                                    HIB_nTAMPER_LEVEL enLevelArg)
{
    HIB_nBOOLEAN enLockStateReg;
    HIB_nERROR enErrorReg;
    UBase_t uxShiftReg;

    enLockStateReg = HIB_enFALSE;
    uxShiftReg = 0UL;
    enErrorReg = (HIB_enTAMPER_LEVEL_HIGH < enLevelArg) ? HIB_enERROR_VALUE : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enGetTamperShift(enTamperArg, 1UL, &uxShiftReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enTamperUnlock(enModuleArg, &enLockStateReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enWriteTamperField(enModuleArg, HIB_TPIO_OFFSET, HIB_TPIO_LEV0_MASK,
                                             uxShiftReg, (UBase_t) enLevelArg);
    }
    return HIB__enTamperRelock(enModuleArg, enLockStateReg, enErrorReg);
}

HIB_nERROR HIB__enGetTamperPinLevel(HIB_nMODULE enModuleArg, HIB_nTAMPER enTamperArg,
                                    HIB_nTAMPER_LEVEL* penLevelArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxShiftReg;
    UBase_t uxValueReg;

    enErrorReg = (0UL == (uintptr_t) penLevelArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    uxShiftReg = 0UL;
    uxValueReg = 0UL;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enGetTamperShift(enTamperArg, 1UL, &uxShiftReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadTamperField(enModuleArg, HIB_TPIO_OFFSET, HIB_TPIO_LEV0_MASK,
                                            uxShiftReg, &uxValueReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        *penLevelArg = (HIB_nTAMPER_LEVEL) uxValueReg;
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enSetTamperPinPullupState(HIB_nMODULE enModuleArg, HIB_nTAMPER enTamperArg,
                                          HIB_nSTATE enStateArg)
{
    HIB_nBOOLEAN enLockStateReg;
    HIB_nERROR enErrorReg;
    UBase_t uxShiftReg;
    UBase_t uxValueReg;

    enLockStateReg = HIB_enFALSE;
    uxShiftReg = 0UL;
    uxValueReg = (HIB_enSTATE_ENA == enStateArg) ? 1UL : 0UL;
    enErrorReg = HIB__enGetTamperShift(enTamperArg, 2UL, &uxShiftReg);
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enTamperUnlock(enModuleArg, &enLockStateReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enWriteTamperField(enModuleArg, HIB_TPIO_OFFSET, HIB_TPIO_PUEN0_MASK,
                                             uxShiftReg, uxValueReg);
    }
    return HIB__enTamperRelock(enModuleArg, enLockStateReg, enErrorReg);
}

HIB_nERROR HIB__enGetTamperPinPullupState(HIB_nMODULE enModuleArg, HIB_nTAMPER enTamperArg,
                                          HIB_nSTATE* penStateArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxShiftReg;
    UBase_t uxValueReg;

    enErrorReg = (0UL == (uintptr_t) penStateArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    uxShiftReg = 0UL;
    uxValueReg = 0UL;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enGetTamperShift(enTamperArg, 2UL, &uxShiftReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadTamperField(enModuleArg, HIB_TPIO_OFFSET, HIB_TPIO_PUEN0_MASK,
                                            uxShiftReg, &uxValueReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        *penStateArg = (0UL != uxValueReg) ? HIB_enSTATE_ENA : HIB_enSTATE_DIS;
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enSetTamperPinGlitchState(HIB_nMODULE enModuleArg, HIB_nTAMPER enTamperArg,
                                          HIB_nTAMPER_GLITCH enStateArg)
{
    HIB_nBOOLEAN enLockStateReg;
    HIB_nERROR enErrorReg;
    UBase_t uxShiftReg;

    enLockStateReg = HIB_enFALSE;
    uxShiftReg = 0UL;
    enErrorReg = (HIB_enTAMPER_GLITCH_LONG < enStateArg) ? HIB_enERROR_VALUE : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enGetTamperShift(enTamperArg, 3UL, &uxShiftReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enTamperUnlock(enModuleArg, &enLockStateReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enWriteTamperField(enModuleArg, HIB_TPIO_OFFSET, HIB_TPIO_GFLTR0_MASK,
                                             uxShiftReg, (UBase_t) enStateArg);
    }
    return HIB__enTamperRelock(enModuleArg, enLockStateReg, enErrorReg);
}

HIB_nERROR HIB__enGetTamperPinGlitchState(HIB_nMODULE enModuleArg, HIB_nTAMPER enTamperArg,
                                          HIB_nTAMPER_GLITCH* penStateArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxShiftReg;
    UBase_t uxValueReg;

    enErrorReg = (0UL == (uintptr_t) penStateArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    uxShiftReg = 0UL;
    uxValueReg = 0UL;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enGetTamperShift(enTamperArg, 3UL, &uxShiftReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadTamperField(enModuleArg, HIB_TPIO_OFFSET, HIB_TPIO_GFLTR0_MASK,
                                            uxShiftReg, &uxValueReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        *penStateArg = (HIB_nTAMPER_GLITCH) uxValueReg;
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enGetTamperStatus(HIB_nMODULE enModuleArg, HIB_nTAMPER_STATUS* penStatusArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxValueReg;

    enErrorReg = (0UL == (uintptr_t) penStatusArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    uxValueReg = 0UL;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadTamperField(enModuleArg, HIB_TPSTAT_OFFSET, HIB_TPSTAT_STATE_MASK,
                                            HIB_TPSTAT_R_STATE_BIT, &uxValueReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        *penStatusArg = (HIB_nTAMPER_STATUS) uxValueReg;
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enGetTamperXOscState(HIB_nMODULE enModuleArg, HIB_nSTATUS* penStatusArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxValueReg;

    enErrorReg = (0UL == (uintptr_t) penStatusArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    uxValueReg = 0UL;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadTamperField(enModuleArg, HIB_TPSTAT_OFFSET, HIB_TPSTAT_XOSCST_MASK,
                                            HIB_TPSTAT_R_XOSCST_BIT, &uxValueReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        *penStatusArg = (HIB_TPSTAT_XOSCST_ACTIVE == uxValueReg) ? HIB_enSTATUS_ACTIVE : HIB_enSTATUS_INACTIVE;
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enGetTamperXOscFailure(HIB_nMODULE enModuleArg, HIB_nSTATUS* penStatusArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxValueReg;

    enErrorReg = (0UL == (uintptr_t) penStatusArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    uxValueReg = 0UL;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadTamperField(enModuleArg, HIB_TPSTAT_OFFSET, HIB_TPSTAT_XOSCFAIL_MASK,
                                            HIB_TPSTAT_R_XOSCFAIL_BIT, &uxValueReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        *penStatusArg = (HIB_TPSTAT_XOSCFAIL_FAIL == uxValueReg) ? HIB_enSTATUS_ACTIVE : HIB_enSTATUS_INACTIVE;
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enGetTamperLog(HIB_nMODULE enModuleArg, HIB_nTAMPER enTamperArg,
                               HIB_TAMPER_LOG_t* pstLogArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxTimeReg;
    UBase_t uxTriggerReg;
    uintptr_t uptrTimeOffsetReg;
    uintptr_t uptrTriggerOffsetReg;

    enErrorReg = (0UL == (uintptr_t) pstLogArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    uxTimeReg = 0UL;
    uxTriggerReg = 0UL;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = (HIB_enTAMPER_MAX <= enTamperArg) ? HIB_enERROR_RANGE : HIB_enERROR_OK;
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        uptrTimeOffsetReg = HIB_TPLOG0_OFFSET + (((uintptr_t) enTamperArg) << 3UL);
        uptrTriggerOffsetReg = HIB_TPLOG1_OFFSET + (((uintptr_t) enTamperArg) << 3UL);

        enErrorReg = HIB__enReadTamperRegister(enModuleArg, uptrTimeOffsetReg, &uxTimeReg);
        if(HIB_enERROR_OK == enErrorReg)
        {
            enErrorReg = HIB__enReadTamperRegister(enModuleArg, uptrTriggerOffsetReg, &uxTriggerReg);
        }
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        pstLogArg->uxSecond = (uxTimeReg >> HIB_TPLOGTIME_R_SEC_BIT) & HIB_TPLOGTIME_SEC_MASK;
        pstLogArg->uxMinute = (uxTimeReg >> HIB_TPLOGTIME_R_MIN_BIT) & HIB_TPLOGTIME_MIN_MASK;
        pstLogArg->uxHour = (uxTimeReg >> HIB_TPLOGTIME_R_HR_BIT) & HIB_TPLOGTIME_HR_MASK;
        pstLogArg->uxDayOfMonth = (uxTimeReg >> HIB_TPLOGTIME_R_DOM_BIT) & HIB_TPLOGTIME_DOM_MASK;
        pstLogArg->uxMonth = (uxTimeReg >> HIB_TPLOGTIME_R_MON_BIT) & HIB_TPLOGTIME_MON_MASK;
        pstLogArg->uxYear = (uxTimeReg >> HIB_TPLOGTIME_R_YEAR_BIT) & HIB_TPLOGTIME_YEAR_MASK;

        pstLogArg->uxTriggerMask = 0UL;
        pstLogArg->uxTriggerMask |= ((uxTriggerReg >> HIB_TPLOGTRIG_R_TRIG0_BIT) & HIB_TPLOGTRIG_TRIG0_MASK) << 0UL;
        pstLogArg->uxTriggerMask |= ((uxTriggerReg >> HIB_TPLOGTRIG_R_TRIG1_BIT) & HIB_TPLOGTRIG_TRIG1_MASK) << 1UL;
        pstLogArg->uxTriggerMask |= ((uxTriggerReg >> HIB_TPLOGTRIG_R_TRIG2_BIT) & HIB_TPLOGTRIG_TRIG2_MASK) << 2UL;
        pstLogArg->uxTriggerMask |= ((uxTriggerReg >> HIB_TPLOGTRIG_R_TRIG3_BIT) & HIB_TPLOGTRIG_TRIG3_MASK) << 3UL;
        pstLogArg->enXOscFailure = (((uxTriggerReg >> HIB_TPLOGTRIG_R_XOSC_BIT) & HIB_TPLOGTRIG_XOSC_MASK) == HIB_TPLOGTRIG_XOSC_FAIL) ? HIB_enSTATUS_ACTIVE : HIB_enSTATUS_INACTIVE;
    }
    return (enErrorReg);
}