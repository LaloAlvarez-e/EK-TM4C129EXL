/**
 *
 * @file HIB_Control.c
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
#include <xDriver_MCU/HIB/Driver/xHeader/HIB_Control.h>

#include <xDriver_MCU/HIB/Driver/Intrinsics/HIB_Intrinsics.h>
#include <xDriver_MCU/HIB/Peripheral/HIB_Peripheral.h>

static HIB_nERROR HIB__enReadControlField(HIB_nMODULE enModuleArg, uintptr_t uptrAddressArg,
                                          UBase_t uxMaskArg, UBase_t uxShiftArg,
                                          UBase_t* puxValueArg);
static HIB_nERROR HIB__enWriteControlField(HIB_nMODULE enModuleArg, uintptr_t uptrAddressArg,
                                           UBase_t uxMaskArg, UBase_t uxShiftArg,
                                           UBase_t uxValueArg);
static HIB_nERROR HIB__enIOUnlock(HIB_nMODULE enModuleArg, HIB_nBOOLEAN* penLockStateArg);
static HIB_nERROR HIB__enIORelock(HIB_nMODULE enModuleArg, HIB_nBOOLEAN enLockStateArg,
                                  HIB_nERROR enErrorArg);

static HIB_nERROR HIB__enReadControlField(HIB_nMODULE enModuleArg, uintptr_t uptrAddressArg,
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

static HIB_nERROR HIB__enWriteControlField(HIB_nMODULE enModuleArg, uintptr_t uptrAddressArg,
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

static HIB_nERROR HIB__enIOUnlock(HIB_nMODULE enModuleArg, HIB_nBOOLEAN* penLockStateArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = HIB__enIsLocked(enModuleArg, penLockStateArg);
    if((HIB_enERROR_OK == enErrorReg) && (HIB_enTRUE == *penLockStateArg))
    {
        enErrorReg = HIB__enUnlock(enModuleArg);
    }
    return (enErrorReg);
}

static HIB_nERROR HIB__enIORelock(HIB_nMODULE enModuleArg, HIB_nBOOLEAN enLockStateArg,
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

HIB_nERROR HIB__enSetWakeRTCState(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg)
{
    UBase_t uxValueReg;

    uxValueReg = (HIB_enSTATE_ENA == enStateArg) ? HIB_CTL_RTCWEN_ENA : HIB_CTL_RTCWEN_DIS;
    return HIB__enWriteControlField(enModuleArg, HIB_CTL_OFFSET, HIB_CTL_RTCWEN_MASK,
                                    HIB_CTL_R_RTCWEN_BIT, uxValueReg);
}

HIB_nERROR HIB__enGetWakeRTCState(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxValueReg;

    enErrorReg = (0UL == (uintptr_t) penStateArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    uxValueReg = 0UL;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadControlField(enModuleArg, HIB_CTL_OFFSET, HIB_CTL_RTCWEN_MASK,
                                             HIB_CTL_R_RTCWEN_BIT, &uxValueReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        *penStateArg = (0UL != uxValueReg) ? HIB_enSTATE_ENA : HIB_enSTATE_DIS;
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enSetWakePinState(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg)
{
    UBase_t uxValueReg;

    uxValueReg = (HIB_enSTATE_ENA == enStateArg) ? HIB_CTL_PINWEN_ENA : HIB_CTL_PINWEN_DIS;
    return HIB__enWriteControlField(enModuleArg, HIB_CTL_OFFSET, HIB_CTL_PINWEN_MASK,
                                    HIB_CTL_R_PINWEN_BIT, uxValueReg);
}

HIB_nERROR HIB__enGetWakePinState(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxValueReg;

    enErrorReg = (0UL == (uintptr_t) penStateArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    uxValueReg = 0UL;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadControlField(enModuleArg, HIB_CTL_OFFSET, HIB_CTL_PINWEN_MASK,
                                             HIB_CTL_R_PINWEN_BIT, &uxValueReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        *penStateArg = (0UL != uxValueReg) ? HIB_enSTATE_ENA : HIB_enSTATE_DIS;
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enSetWakeBatteryState(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg)
{
    UBase_t uxValueReg;

    uxValueReg = (HIB_enSTATE_ENA == enStateArg) ? HIB_CTL_BATWKEN_ENA : HIB_CTL_BATWKEN_DIS;
    return HIB__enWriteControlField(enModuleArg, HIB_CTL_OFFSET, HIB_CTL_BATWKEN_MASK,
                                    HIB_CTL_R_BATWKEN_BIT, uxValueReg);
}

HIB_nERROR HIB__enGetWakeBatteryState(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxValueReg;

    enErrorReg = (0UL == (uintptr_t) penStateArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    uxValueReg = 0UL;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadControlField(enModuleArg, HIB_CTL_OFFSET, HIB_CTL_BATWKEN_MASK,
                                             HIB_CTL_R_BATWKEN_BIT, &uxValueReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        *penStateArg = (0UL != uxValueReg) ? HIB_enSTATE_ENA : HIB_enSTATE_DIS;
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enSetWakeUnlockState(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg)
{
    HIB_nBOOLEAN enLockStateReg;
    HIB_nERROR enErrorReg;
    UBase_t uxValueReg;

    enLockStateReg = HIB_enFALSE;
    uxValueReg = (HIB_enSTATE_ENA == enStateArg) ? HIB_IO_WUUNLK_ENA : HIB_IO_WUUNLK_DIS;
    enErrorReg = HIB__enIOUnlock(enModuleArg, &enLockStateReg);
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enWriteControlField(enModuleArg, HIB_IO_OFFSET, HIB_IO_WUUNLK_MASK,
                                              HIB_IO_R_WUUNLK_BIT, uxValueReg);
    }
    return HIB__enIORelock(enModuleArg, enLockStateReg, enErrorReg);
}

HIB_nERROR HIB__enGetWakeUnlockState(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxValueReg;

    enErrorReg = (0UL == (uintptr_t) penStateArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    uxValueReg = 0UL;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadControlField(enModuleArg, HIB_IO_OFFSET, HIB_IO_WUUNLK_MASK,
                                             HIB_IO_R_WUUNLK_BIT, &uxValueReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        *penStateArg = (0UL != uxValueReg) ? HIB_enSTATE_ENA : HIB_enSTATE_DIS;
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enSetWakeResetState(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg)
{
    HIB_nBOOLEAN enLockStateReg;
    HIB_nERROR enErrorReg;
    UBase_t uxValueReg;

    enLockStateReg = HIB_enFALSE;
    uxValueReg = (HIB_enSTATE_ENA == enStateArg) ? HIB_IO_WURSTEN_ENA : HIB_IO_WURSTEN_DIS;
    enErrorReg = HIB__enIOUnlock(enModuleArg, &enLockStateReg);
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enWriteControlField(enModuleArg, HIB_IO_OFFSET, HIB_IO_WURSTEN_MASK,
                                              HIB_IO_R_WURSTEN_BIT, uxValueReg);
    }
    return HIB__enIORelock(enModuleArg, enLockStateReg, enErrorReg);
}

HIB_nERROR HIB__enGetWakeResetState(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxValueReg;

    enErrorReg = (0UL == (uintptr_t) penStateArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    uxValueReg = 0UL;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadControlField(enModuleArg, HIB_IO_OFFSET, HIB_IO_WURSTEN_MASK,
                                             HIB_IO_R_WURSTEN_BIT, &uxValueReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        *penStateArg = (0UL != uxValueReg) ? HIB_enSTATE_ENA : HIB_enSTATE_DIS;
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enGetWakePinPresence(HIB_nMODULE enModuleArg, HIB_nWAKE_PIN* penStateArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxValueReg;

    enErrorReg = (0UL == (uintptr_t) penStateArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    uxValueReg = 0UL;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadControlField(enModuleArg, HIB_PP_OFFSET, HIB_PP_WAKENC_MASK,
                                             HIB_PP_R_WAKENC_BIT, &uxValueReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        *penStateArg = (HIB_PP_WAKENC_PRESENT == uxValueReg) ? HIB_enWAKE_PIN_PRESENT : HIB_enWAKE_PIN_ABSENT;
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enSetClock32State(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg)
{
    UBase_t uxValueReg;

    uxValueReg = (HIB_enSTATE_ENA == enStateArg) ? HIB_CTL_CLK32EN_ENA : HIB_CTL_CLK32EN_DIS;
    return HIB__enWriteControlField(enModuleArg, HIB_CTL_OFFSET, HIB_CTL_CLK32EN_MASK,
                                    HIB_CTL_R_CLK32EN_BIT, uxValueReg);
}

HIB_nERROR HIB__enGetClock32State(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxValueReg;

    enErrorReg = (0UL == (uintptr_t) penStateArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    uxValueReg = 0UL;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadControlField(enModuleArg, HIB_CTL_OFFSET, HIB_CTL_CLK32EN_MASK,
                                             HIB_CTL_R_CLK32EN_BIT, &uxValueReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        *penStateArg = (0UL != uxValueReg) ? HIB_enSTATE_ENA : HIB_enSTATE_DIS;
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enSetSystemClockState(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg)
{
    UBase_t uxValueReg;

    uxValueReg = (HIB_enSTATE_ENA == enStateArg) ? HIB_CC_SYSCLKEN_ENA : HIB_CC_SYSCLKEN_DIS;
    return HIB__enWriteControlField(enModuleArg, HIB_CC_OFFSET, HIB_CC_SYSCLKEN_MASK,
                                    HIB_CC_R_SYSCLKEN_BIT, uxValueReg);
}

HIB_nERROR HIB__enGetSystemClockState(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxValueReg;

    enErrorReg = (0UL == (uintptr_t) penStateArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    uxValueReg = 0UL;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadControlField(enModuleArg, HIB_CC_OFFSET, HIB_CC_SYSCLKEN_MASK,
                                             HIB_CC_R_SYSCLKEN_BIT, &uxValueReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        *penStateArg = (0UL != uxValueReg) ? HIB_enSTATE_ENA : HIB_enSTATE_DIS;
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enSetOscillator(HIB_nMODULE enModuleArg, HIB_nOSC enStateArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = (HIB_enOSC_LFIOSC < enStateArg) ? HIB_enERROR_VALUE : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enWriteControlField(enModuleArg, HIB_CTL_OFFSET, HIB_CTL_OSCSEL_MASK,
                                              HIB_CTL_R_OSCSEL_BIT, (UBase_t) enStateArg);
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enGetOscillator(HIB_nMODULE enModuleArg, HIB_nOSC* penStateArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxValueReg;

    enErrorReg = (0UL == (uintptr_t) penStateArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    uxValueReg = 0UL;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadControlField(enModuleArg, HIB_CTL_OFFSET, HIB_CTL_OSCSEL_MASK,
                                             HIB_CTL_R_OSCSEL_BIT, &uxValueReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        *penStateArg = (HIB_nOSC) uxValueReg;
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enSetOscillatorDrive(HIB_nMODULE enModuleArg, HIB_nOSC_DRIVE enStateArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = (HIB_enOSC_DRIVE_HIGH < enStateArg) ? HIB_enERROR_VALUE : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enWriteControlField(enModuleArg, HIB_CTL_OFFSET, HIB_CTL_OSCDRV_MASK,
                                              HIB_CTL_R_OSCDRV_BIT, (UBase_t) enStateArg);
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enGetOscillatorDrive(HIB_nMODULE enModuleArg, HIB_nOSC_DRIVE* penStateArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxValueReg;

    enErrorReg = (0UL == (uintptr_t) penStateArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    uxValueReg = 0UL;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadControlField(enModuleArg, HIB_CTL_OFFSET, HIB_CTL_OSCDRV_MASK,
                                             HIB_CTL_R_OSCDRV_BIT, &uxValueReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        *penStateArg = (HIB_nOSC_DRIVE) uxValueReg;
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enSetOscillatorBypassState(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg)
{
    UBase_t uxValueReg;

    uxValueReg = (HIB_enSTATE_ENA == enStateArg) ? HIB_CTL_OSCBYP_BYPASS : HIB_CTL_OSCBYP_CRYSTAL;
    return HIB__enWriteControlField(enModuleArg, HIB_CTL_OFFSET, HIB_CTL_OSCBYP_MASK,
                                    HIB_CTL_R_OSCBYP_BIT, uxValueReg);
}

HIB_nERROR HIB__enGetOscillatorBypassState(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxValueReg;

    enErrorReg = (0UL == (uintptr_t) penStateArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    uxValueReg = 0UL;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadControlField(enModuleArg, HIB_CTL_OFFSET, HIB_CTL_OSCBYP_MASK,
                                             HIB_CTL_R_OSCBYP_BIT, &uxValueReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        *penStateArg = (HIB_CTL_OSCBYP_BYPASS == uxValueReg) ? HIB_enSTATE_ENA : HIB_enSTATE_DIS;
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enSetBatteryThreshold(HIB_nMODULE enModuleArg, HIB_nVBAT enStateArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = (HIB_enVBAT_2_5V < enStateArg) ? HIB_enERROR_VALUE : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enWriteControlField(enModuleArg, HIB_CTL_OFFSET, HIB_CTL_VBATSEL_MASK,
                                              HIB_CTL_R_VBATSEL_BIT, (UBase_t) enStateArg);
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enGetBatteryThreshold(HIB_nMODULE enModuleArg, HIB_nVBAT* penStateArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxValueReg;

    enErrorReg = (0UL == (uintptr_t) penStateArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    uxValueReg = 0UL;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadControlField(enModuleArg, HIB_CTL_OFFSET, HIB_CTL_VBATSEL_MASK,
                                             HIB_CTL_R_VBATSEL_BIT, &uxValueReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        *penStateArg = (HIB_nVBAT) uxValueReg;
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enStartBatteryCheck(HIB_nMODULE enModuleArg)
{
    return HIB__enWriteControlField(enModuleArg, HIB_CTL_OFFSET, HIB_CTL_BATCHK_MASK,
                                    HIB_CTL_R_BATCHK_BIT, HIB_CTL_BATCHK_START);
}

HIB_nERROR HIB__enSetAbortState(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg)
{
    UBase_t uxValueReg;

    uxValueReg = (HIB_enSTATE_ENA == enStateArg) ? HIB_CTL_VABORT_ENA : HIB_CTL_VABORT_DIS;
    return HIB__enWriteControlField(enModuleArg, HIB_CTL_OFFSET, HIB_CTL_VABORT_MASK,
                                    HIB_CTL_R_VABORT_BIT, uxValueReg);
}

HIB_nERROR HIB__enGetAbortState(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxValueReg;

    enErrorReg = (0UL == (uintptr_t) penStateArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    uxValueReg = 0UL;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadControlField(enModuleArg, HIB_CTL_OFFSET, HIB_CTL_VABORT_MASK,
                                             HIB_CTL_R_VABORT_BIT, &uxValueReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        *penStateArg = (0UL != uxValueReg) ? HIB_enSTATE_ENA : HIB_enSTATE_DIS;
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enSetVDD3ONState(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg)
{
    UBase_t uxValueReg;

    uxValueReg = (HIB_enSTATE_ENA == enStateArg) ? HIB_CTL_VDD3ON_ENA : HIB_CTL_VDD3ON_DIS;
    return HIB__enWriteControlField(enModuleArg, HIB_CTL_OFFSET, HIB_CTL_VDD3ON_MASK,
                                    HIB_CTL_R_VDD3ON_BIT, uxValueReg);
}

HIB_nERROR HIB__enGetVDD3ONState(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxValueReg;

    enErrorReg = (0UL == (uintptr_t) penStateArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    uxValueReg = 0UL;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadControlField(enModuleArg, HIB_CTL_OFFSET, HIB_CTL_VDD3ON_MASK,
                                             HIB_CTL_R_VDD3ON_BIT, &uxValueReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        *penStateArg = (0UL != uxValueReg) ? HIB_enSTATE_ENA : HIB_enSTATE_DIS;
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enSetRetentionState(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg)
{
    UBase_t uxValueReg;

    uxValueReg = (HIB_enSTATE_ENA == enStateArg) ? HIB_CTL_RETCLR_RETAIN : HIB_CTL_RETCLR_RELEASE;
    return HIB__enWriteControlField(enModuleArg, HIB_CTL_OFFSET, HIB_CTL_RETCLR_MASK,
                                    HIB_CTL_R_RETCLR_BIT, uxValueReg);
}

HIB_nERROR HIB__enGetRetentionState(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxValueReg;

    enErrorReg = (0UL == (uintptr_t) penStateArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    uxValueReg = 0UL;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadControlField(enModuleArg, HIB_CTL_OFFSET, HIB_CTL_RETCLR_MASK,
                                             HIB_CTL_R_RETCLR_BIT, &uxValueReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        *penStateArg = (HIB_CTL_RETCLR_RETAIN == uxValueReg) ? HIB_enSTATE_ENA : HIB_enSTATE_DIS;
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enRequestHibernate(HIB_nMODULE enModuleArg)
{
    return HIB__enWriteControlField(enModuleArg, HIB_CTL_OFFSET, HIB_CTL_HIBREQ_MASK,
                                    HIB_CTL_R_HIBREQ_BIT, HIB_CTL_HIBREQ_REQ);
}
