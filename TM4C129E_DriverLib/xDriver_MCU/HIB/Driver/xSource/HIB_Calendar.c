/**
 *
 * @file HIB_Calendar.c
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
#include <xDriver_MCU/HIB/Driver/xHeader/HIB_Calendar.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/HIB/Driver/Intrinsics/HIB_Intrinsics.h>
#include <xDriver_MCU/HIB/Peripheral/HIB_Peripheral.h>

static HIB_nERROR HIB__enReadCalendarField(HIB_nMODULE enModuleArg, uintptr_t uptrAddressArg,
                                           UBase_t uxMaskArg, UBase_t uxShiftArg,
                                           UBase_t* puxValueArg);
static HIB_nERROR HIB__enReadCalendarRegister(HIB_nMODULE enModuleArg, uintptr_t uptrAddressArg,
                                              UBase_t* puxValueArg);
static HIB_nERROR HIB__enWriteCalendarField(HIB_nMODULE enModuleArg, uintptr_t uptrAddressArg,
                                            UBase_t uxMaskArg, UBase_t uxShiftArg,
                                            UBase_t uxValueArg);
static HIB_nERROR HIB__enWriteCalendarRegister(HIB_nMODULE enModuleArg, uintptr_t uptrAddressArg,
                                               UBase_t uxValueArg);
static HIB_nERROR HIB__enCalendarUnlock(HIB_nMODULE enModuleArg, HIB_nBOOLEAN* penLockStateArg);
static HIB_nERROR HIB__enCalendarRelock(HIB_nMODULE enModuleArg, HIB_nBOOLEAN enLockStateArg,
                                        HIB_nERROR enErrorArg);
static void HIB__vDecodeCalendarCurrent(UBase_t uxCalendar0Arg, UBase_t uxCalendar1Arg,
                                        HIB_CALENDAR_t* pstCalendarArg);
static void HIB__vDecodeCalendarLoad(UBase_t uxCalendar0Arg, UBase_t uxCalendar1Arg,
                                     HIB_CALENDAR_t* pstCalendarArg);
static void HIB__vDecodeCalendarMatch(UBase_t uxCalendar0Arg, UBase_t uxCalendar1Arg,
                                      HIB_CALENDAR_t* pstCalendarArg);
static void HIB__vEncodeCalendarLoad(const HIB_CALENDAR_t* pstCalendarArg,
                                     UBase_t* puxCalendar0Arg, UBase_t* puxCalendar1Arg);
static void HIB__vEncodeCalendarMatch(const HIB_CALENDAR_t* pstCalendarArg,
                                      UBase_t* puxCalendar0Arg, UBase_t* puxCalendar1Arg);

static HIB_nERROR HIB__enReadCalendarField(HIB_nMODULE enModuleArg, uintptr_t uptrAddressArg,
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

static HIB_nERROR HIB__enReadCalendarRegister(HIB_nMODULE enModuleArg, uintptr_t uptrAddressArg,
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

static HIB_nERROR HIB__enWriteCalendarField(HIB_nMODULE enModuleArg, uintptr_t uptrAddressArg,
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

static HIB_nERROR HIB__enWriteCalendarRegister(HIB_nMODULE enModuleArg, uintptr_t uptrAddressArg,
                                               UBase_t uxValueArg)
{
    HIB_Register_t stRegister;

    stRegister.uxShift = 0UL;
    stRegister.uxMask = MCU_MASK_BASE;
    stRegister.uptrAddress = uptrAddressArg;
    stRegister.uxValue = uxValueArg;

    return HIB__enWriteRegister(enModuleArg, &stRegister);
}

static HIB_nERROR HIB__enCalendarUnlock(HIB_nMODULE enModuleArg, HIB_nBOOLEAN* penLockStateArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = HIB__enIsLocked(enModuleArg, penLockStateArg);
    if((HIB_enERROR_OK == enErrorReg) && (HIB_enTRUE == *penLockStateArg))
    {
        enErrorReg = HIB__enUnlock(enModuleArg);
    }
    return (enErrorReg);
}

static HIB_nERROR HIB__enCalendarRelock(HIB_nMODULE enModuleArg, HIB_nBOOLEAN enLockStateArg,
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

static void HIB__vDecodeCalendarCurrent(UBase_t uxCalendar0Arg, UBase_t uxCalendar1Arg,
                                        HIB_CALENDAR_t* pstCalendarArg)
{
    UBase_t uxValid0Reg;
    UBase_t uxValid1Reg;

    pstCalendarArg->uxSecond = (uxCalendar0Arg >> HIB_CAL0_R_SEC_BIT) & HIB_CAL0_SEC_MASK;
    pstCalendarArg->uxMinute = (uxCalendar0Arg >> HIB_CAL0_R_MIN_BIT) & HIB_CAL0_MIN_MASK;
    pstCalendarArg->uxHour = (uxCalendar0Arg >> HIB_CAL0_R_HR_BIT) & HIB_CAL0_HR_MASK;
    pstCalendarArg->enAMPM = (HIB_nAMPM) ((uxCalendar0Arg >> HIB_CAL0_R_AMPM_BIT) & HIB_CAL0_AMPM_MASK);

    pstCalendarArg->uxDayOfMonth = (uxCalendar1Arg >> HIB_CAL1_R_DOM_BIT) & HIB_CAL1_DOM_MASK;
    pstCalendarArg->uxMonth = (uxCalendar1Arg >> HIB_CAL1_R_MON_BIT) & HIB_CAL1_MON_MASK;
    pstCalendarArg->uxYear = (uxCalendar1Arg >> HIB_CAL1_R_YEAR_BIT) & HIB_CAL1_YEAR_MASK;
    pstCalendarArg->uxDayOfWeek = (uxCalendar1Arg >> HIB_CAL1_R_DOW_BIT) & HIB_CAL1_DOW_MASK;

    uxValid0Reg = (uxCalendar0Arg >> HIB_CAL0_R_VALID_BIT) & HIB_CAL0_VALID_MASK;
    uxValid1Reg = (uxCalendar1Arg >> HIB_CAL1_R_VALID_BIT) & HIB_CAL1_VALID_MASK;
    pstCalendarArg->enValid = ((0UL != uxValid0Reg) && (0UL != uxValid1Reg)) ? HIB_enSTATUS_ACTIVE : HIB_enSTATUS_INACTIVE;
}

static void HIB__vDecodeCalendarLoad(UBase_t uxCalendar0Arg, UBase_t uxCalendar1Arg,
                                     HIB_CALENDAR_t* pstCalendarArg)
{
    pstCalendarArg->uxSecond = (uxCalendar0Arg >> HIB_CALLD0_R_SEC_BIT) & HIB_CALLD0_SEC_MASK;
    pstCalendarArg->uxMinute = (uxCalendar0Arg >> HIB_CALLD0_R_MIN_BIT) & HIB_CALLD0_MIN_MASK;
    pstCalendarArg->uxHour = (uxCalendar0Arg >> HIB_CALLD0_R_HR_BIT) & HIB_CALLD0_HR_MASK;
    pstCalendarArg->enAMPM = (HIB_nAMPM) ((uxCalendar0Arg >> HIB_CALLD0_R_AMPM_BIT) & HIB_CALLD0_AMPM_MASK);

    pstCalendarArg->uxDayOfMonth = (uxCalendar1Arg >> HIB_CALLD1_R_DOM_BIT) & HIB_CALLD1_DOM_MASK;
    pstCalendarArg->uxMonth = (uxCalendar1Arg >> HIB_CALLD1_R_MON_BIT) & HIB_CALLD1_MON_MASK;
    pstCalendarArg->uxYear = (uxCalendar1Arg >> HIB_CALLD1_R_YEAR_BIT) & HIB_CALLD1_YEAR_MASK;
    pstCalendarArg->uxDayOfWeek = (uxCalendar1Arg >> HIB_CALLD1_R_DOW_BIT) & HIB_CALLD1_DOW_MASK;
    pstCalendarArg->enValid = HIB_enSTATUS_ACTIVE;
}

static void HIB__vDecodeCalendarMatch(UBase_t uxCalendar0Arg, UBase_t uxCalendar1Arg,
                                      HIB_CALENDAR_t* pstCalendarArg)
{
    pstCalendarArg->uxSecond = (uxCalendar0Arg >> HIB_CALM0_R_SEC_BIT) & HIB_CALM0_SEC_MASK;
    pstCalendarArg->uxMinute = (uxCalendar0Arg >> HIB_CALM0_R_MIN_BIT) & HIB_CALM0_MIN_MASK;
    pstCalendarArg->uxHour = (uxCalendar0Arg >> HIB_CALM0_R_HR_BIT) & HIB_CALM0_HR_MASK;
    pstCalendarArg->enAMPM = (HIB_nAMPM) ((uxCalendar0Arg >> HIB_CALM0_R_AMPM_BIT) & HIB_CALM0_AMPM_MASK);

    pstCalendarArg->uxDayOfMonth = (uxCalendar1Arg >> HIB_CALM1_R_DOM_BIT) & HIB_CALM1_DOM_MASK;
    pstCalendarArg->uxMonth = 0UL;
    pstCalendarArg->uxYear = 0UL;
    pstCalendarArg->uxDayOfWeek = 0UL;
    pstCalendarArg->enValid = HIB_enSTATUS_ACTIVE;
}

static void HIB__vEncodeCalendarLoad(const HIB_CALENDAR_t* pstCalendarArg,
                                     UBase_t* puxCalendar0Arg, UBase_t* puxCalendar1Arg)
{
    UBase_t uxCalendar0Reg;
    UBase_t uxCalendar1Reg;

    uxCalendar0Reg = 0UL;
    uxCalendar1Reg = 0UL;

    uxCalendar0Reg |= (pstCalendarArg->uxSecond & HIB_CALLD0_SEC_MASK) << HIB_CALLD0_R_SEC_BIT;
    uxCalendar0Reg |= (pstCalendarArg->uxMinute & HIB_CALLD0_MIN_MASK) << HIB_CALLD0_R_MIN_BIT;
    uxCalendar0Reg |= (pstCalendarArg->uxHour & HIB_CALLD0_HR_MASK) << HIB_CALLD0_R_HR_BIT;
    uxCalendar0Reg |= ((UBase_t) pstCalendarArg->enAMPM & HIB_CALLD0_AMPM_MASK) << HIB_CALLD0_R_AMPM_BIT;

    uxCalendar1Reg |= (pstCalendarArg->uxDayOfMonth & HIB_CALLD1_DOM_MASK) << HIB_CALLD1_R_DOM_BIT;
    uxCalendar1Reg |= (pstCalendarArg->uxMonth & HIB_CALLD1_MON_MASK) << HIB_CALLD1_R_MON_BIT;
    uxCalendar1Reg |= (pstCalendarArg->uxYear & HIB_CALLD1_YEAR_MASK) << HIB_CALLD1_R_YEAR_BIT;
    uxCalendar1Reg |= (pstCalendarArg->uxDayOfWeek & HIB_CALLD1_DOW_MASK) << HIB_CALLD1_R_DOW_BIT;

    *puxCalendar0Arg = uxCalendar0Reg;
    *puxCalendar1Arg = uxCalendar1Reg;
}

static void HIB__vEncodeCalendarMatch(const HIB_CALENDAR_t* pstCalendarArg,
                                      UBase_t* puxCalendar0Arg, UBase_t* puxCalendar1Arg)
{
    UBase_t uxCalendar0Reg;
    UBase_t uxCalendar1Reg;

    uxCalendar0Reg = 0UL;
    uxCalendar1Reg = 0UL;

    uxCalendar0Reg |= (pstCalendarArg->uxSecond & HIB_CALM0_SEC_MASK) << HIB_CALM0_R_SEC_BIT;
    uxCalendar0Reg |= (pstCalendarArg->uxMinute & HIB_CALM0_MIN_MASK) << HIB_CALM0_R_MIN_BIT;
    uxCalendar0Reg |= (pstCalendarArg->uxHour & HIB_CALM0_HR_MASK) << HIB_CALM0_R_HR_BIT;
    uxCalendar0Reg |= ((UBase_t) pstCalendarArg->enAMPM & HIB_CALM0_AMPM_MASK) << HIB_CALM0_R_AMPM_BIT;

    uxCalendar1Reg |= (pstCalendarArg->uxDayOfMonth & HIB_CALM1_DOM_MASK) << HIB_CALM1_R_DOM_BIT;

    *puxCalendar0Arg = uxCalendar0Reg;
    *puxCalendar1Arg = uxCalendar1Reg;
}

HIB_nERROR HIB__enSetCalendarMode(HIB_nMODULE enModuleArg, HIB_nCALENDAR_MODE enModeArg)
{
    HIB_nBOOLEAN enLockStateReg;
    HIB_nERROR enErrorReg;
    UBase_t uxValueReg;

    enLockStateReg = HIB_enFALSE;
    enErrorReg = (HIB_enCALENDAR_MODE < enModeArg) ? HIB_enERROR_VALUE : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        uxValueReg = (HIB_enCALENDAR_MODE == enModeArg) ? HIB_CALCTL_CALEN_CALENDAR : HIB_CALCTL_CALEN_COUNTER;
        enErrorReg = HIB__enCalendarUnlock(enModuleArg, &enLockStateReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enWriteCalendarField(enModuleArg, HIB_CALCTL_OFFSET, HIB_CALCTL_CALEN_MASK,
                                               HIB_CALCTL_R_CALEN_BIT, uxValueReg);
    }
    return HIB__enCalendarRelock(enModuleArg, enLockStateReg, enErrorReg);
}

HIB_nERROR HIB__enGetCalendarMode(HIB_nMODULE enModuleArg, HIB_nCALENDAR_MODE* penModeArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxValueReg;

    enErrorReg = (0UL == (uintptr_t) penModeArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadCalendarField(enModuleArg, HIB_CALCTL_OFFSET, HIB_CALCTL_CALEN_MASK,
                                              HIB_CALCTL_R_CALEN_BIT, &uxValueReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        *penModeArg = (HIB_nCALENDAR_MODE) uxValueReg;
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enSetHourMode(HIB_nMODULE enModuleArg, HIB_nHOUR_MODE enModeArg)
{
    HIB_nBOOLEAN enLockStateReg;
    HIB_nERROR enErrorReg;
    UBase_t uxValueReg;

    enLockStateReg = HIB_enFALSE;
    enErrorReg = (HIB_enHOUR_24 < enModeArg) ? HIB_enERROR_VALUE : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        uxValueReg = (HIB_enHOUR_24 == enModeArg) ? HIB_CALCTL_CAL24_24H : HIB_CALCTL_CAL24_12H;
        enErrorReg = HIB__enCalendarUnlock(enModuleArg, &enLockStateReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enWriteCalendarField(enModuleArg, HIB_CALCTL_OFFSET, HIB_CALCTL_CAL24_MASK,
                                               HIB_CALCTL_R_CAL24_BIT, uxValueReg);
    }
    return HIB__enCalendarRelock(enModuleArg, enLockStateReg, enErrorReg);
}

HIB_nERROR HIB__enGetHourMode(HIB_nMODULE enModuleArg, HIB_nHOUR_MODE* penModeArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxValueReg;

    enErrorReg = (0UL == (uintptr_t) penModeArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadCalendarField(enModuleArg, HIB_CALCTL_OFFSET, HIB_CALCTL_CAL24_MASK,
                                              HIB_CALCTL_R_CAL24_BIT, &uxValueReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        *penModeArg = (HIB_nHOUR_MODE) uxValueReg;
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enGetCalendarValue(HIB_nMODULE enModuleArg, HIB_CALENDAR_t* pstCalendarArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxCalendar0Reg;
    UBase_t uxCalendar1Reg;

    enErrorReg = (0UL == (uintptr_t) pstCalendarArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    uxCalendar0Reg = 0UL;
    uxCalendar1Reg = 0UL;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadCalendarRegister(enModuleArg, HIB_CAL0_OFFSET, &uxCalendar0Reg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadCalendarRegister(enModuleArg, HIB_CAL1_OFFSET, &uxCalendar1Reg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        HIB__vDecodeCalendarCurrent(uxCalendar0Reg, uxCalendar1Reg, pstCalendarArg);
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enSetCalendarLoad(HIB_nMODULE enModuleArg, const HIB_CALENDAR_t* pstCalendarArg)
{
    HIB_nBOOLEAN enLockStateReg;
    HIB_nERROR enErrorReg;
    UBase_t uxCalendar0Reg;
    UBase_t uxCalendar1Reg;

    enLockStateReg = HIB_enFALSE;
    uxCalendar0Reg = 0UL;
    uxCalendar1Reg = 0UL;
    enErrorReg = (0UL == (uintptr_t) pstCalendarArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        HIB__vEncodeCalendarLoad(pstCalendarArg, &uxCalendar0Reg, &uxCalendar1Reg);
        enErrorReg = HIB__enCalendarUnlock(enModuleArg, &enLockStateReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enWriteCalendarRegister(enModuleArg, HIB_CALLD0_OFFSET, uxCalendar0Reg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enWriteCalendarRegister(enModuleArg, HIB_CALLD1_OFFSET, uxCalendar1Reg);
    }
    return HIB__enCalendarRelock(enModuleArg, enLockStateReg, enErrorReg);
}

HIB_nERROR HIB__enGetCalendarLoad(HIB_nMODULE enModuleArg, HIB_CALENDAR_t* pstCalendarArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxCalendar0Reg;
    UBase_t uxCalendar1Reg;

    enErrorReg = (0UL == (uintptr_t) pstCalendarArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    uxCalendar0Reg = 0UL;
    uxCalendar1Reg = 0UL;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadCalendarRegister(enModuleArg, HIB_CALLD0_OFFSET, &uxCalendar0Reg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadCalendarRegister(enModuleArg, HIB_CALLD1_OFFSET, &uxCalendar1Reg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        HIB__vDecodeCalendarLoad(uxCalendar0Reg, uxCalendar1Reg, pstCalendarArg);
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enSetCalendarMatch(HIB_nMODULE enModuleArg, const HIB_CALENDAR_t* pstCalendarArg)
{
    HIB_nBOOLEAN enLockStateReg;
    HIB_nERROR enErrorReg;
    UBase_t uxCalendar0Reg;
    UBase_t uxCalendar1Reg;

    enLockStateReg = HIB_enFALSE;
    uxCalendar0Reg = 0UL;
    uxCalendar1Reg = 0UL;
    enErrorReg = (0UL == (uintptr_t) pstCalendarArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        HIB__vEncodeCalendarMatch(pstCalendarArg, &uxCalendar0Reg, &uxCalendar1Reg);
        enErrorReg = HIB__enCalendarUnlock(enModuleArg, &enLockStateReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enWriteCalendarRegister(enModuleArg, HIB_CALM0_OFFSET, uxCalendar0Reg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enWriteCalendarRegister(enModuleArg, HIB_CALM1_OFFSET, uxCalendar1Reg);
    }
    return HIB__enCalendarRelock(enModuleArg, enLockStateReg, enErrorReg);
}

HIB_nERROR HIB__enGetCalendarMatch(HIB_nMODULE enModuleArg, HIB_CALENDAR_t* pstCalendarArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxCalendar0Reg;
    UBase_t uxCalendar1Reg;

    enErrorReg = (0UL == (uintptr_t) pstCalendarArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    uxCalendar0Reg = 0UL;
    uxCalendar1Reg = 0UL;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadCalendarRegister(enModuleArg, HIB_CALM0_OFFSET, &uxCalendar0Reg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadCalendarRegister(enModuleArg, HIB_CALM1_OFFSET, &uxCalendar1Reg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        HIB__vDecodeCalendarMatch(uxCalendar0Reg, uxCalendar1Reg, pstCalendarArg);
    }
    return (enErrorReg);
}