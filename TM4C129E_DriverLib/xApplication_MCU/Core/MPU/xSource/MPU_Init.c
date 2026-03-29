/**
 *
 * @file MPU_Init.c
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
 * @verbatim 29 mar. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 29 mar. 2026   GitHub Copilot    1.0     initial Version@endverbatim
 */
#include <stdint.h>

#include <xApplication_MCU/Core/MPU/xHeader/MPU_Init.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/Core/MPU/Peripheral/MPU_Peripheral.h>

static const UBase_t MPU_uxRegionValue[8UL] =
{
    MPU_RBAR_R_REGION_REG0,
    MPU_RBAR_R_REGION_REG1,
    MPU_RBAR_R_REGION_REG2,
    MPU_RBAR_R_REGION_REG3,
    MPU_RBAR_R_REGION_REG4,
    MPU_RBAR_R_REGION_REG5,
    MPU_RBAR_R_REGION_REG6,
    MPU_RBAR_R_REGION_REG7,
};

extern uint8_t __intvec_start__;
extern uint8_t __flash_exec_end__;
extern uint8_t __data_load_end__;
extern uint8_t __vtable_start__;
extern uint8_t __stack_end__;
extern uint8_t __ramcode_start__;
extern uint8_t __ramcode_end__;

static void MPU__vDisableRegion(UBase_t uxRegionArg);
static void MPU__vConfigureRegion(UBase_t uxRegionArg, UBase_t uxStartArg, UBase_t uxEndArg, UBase_t uxAccessPermissionArg, UBase_t uxExecuteNeverArg);
static void MPU__vGetRegionEnvelope(UBase_t uxStartArg, UBase_t uxEndArg, UBase_t* puxBaseArg, UBase_t* puxSizeArg);
static UBase_t MPU__uxGetRegionSize(UBase_t uxSpanArg);
static UBase_t MPU__uxGetRegionSizeEncoding(UBase_t uxSizeArg);
static UBase_t MPU__uxGetSubRegionDisableMask(UBase_t uxBaseArg, UBase_t uxSizeArg, UBase_t uxStartArg, UBase_t uxEndArg);

void MPU__vInit(void)
{
    UBase_t uxFlashStart;
    UBase_t uxFlashExecEnd;
    UBase_t uxFlashEnd;
    UBase_t uxSramStart;
    UBase_t uxSramEnd;
    UBase_t uxSramCodeStart;
    UBase_t uxSramCodeEnd;
    UBase_t uxRegion;
    uxFlashStart = (UBase_t) (uintptr_t) &__intvec_start__;
    uxFlashExecEnd = (UBase_t) (uintptr_t) &__flash_exec_end__;
    uxFlashEnd = (UBase_t) (uintptr_t) &__data_load_end__;
    uxSramStart = (UBase_t) (uintptr_t) &__vtable_start__;
    uxSramEnd = (UBase_t) (uintptr_t) &__stack_end__;
    uxSramCodeStart = (UBase_t) (uintptr_t) &__ramcode_start__;
    uxSramCodeEnd = (UBase_t) (uintptr_t) &__ramcode_end__;

    if(uxFlashEnd < uxFlashExecEnd)
    {
        uxFlashEnd = uxFlashExecEnd;
    }

    MCU__vBlocking();

    MCU__vWriteRegister(MPU_BASE, MPU_CTRL_OFFSET, 0UL, MPU_CTRL_ENABLE_MASK,
                        MPU_CTRL_R_ENABLE_BIT);

    for(uxRegion = 0UL; uxRegion < 8UL; uxRegion++)
    {
        MPU__vDisableRegion(uxRegion);
    }

    MPU__vConfigureRegion(0UL, uxFlashStart, uxFlashEnd, MPU_RASR_R_AP_RORO, MPU_RASR_R_XN_ENA);
    MPU__vConfigureRegion(1UL, uxFlashStart, uxFlashExecEnd, MPU_RASR_R_AP_RORO, MPU_RASR_R_XN_DIS);
    MPU__vConfigureRegion(2UL, uxSramStart, uxSramEnd, MPU_RASR_R_AP_RWRW, MPU_RASR_R_XN_ENA);
    MPU__vConfigureRegion(3UL, uxSramCodeStart, uxSramCodeEnd, MPU_RASR_R_AP_RWRW, MPU_RASR_R_XN_DIS);

    MCU__vWriteRegister(MPU_BASE, MPU_CTRL_OFFSET, MPU_CTRL_R_ENABLE_ENA | MPU_CTRL_R_PRIVDEFENA_ENA,
                        MPU_CTRL_ENABLE_MASK | MPU_CTRL_R_PRIVDEFENA_MASK, 0UL);

    MCU__vBlocking();
}

static void MPU__vDisableRegion(UBase_t uxRegionArg)
{
    MCU__vWriteRegister(MPU_BASE, MPU_RNR_OFFSET, uxRegionArg, MPU_RNR_REGION_MASK,
                        MPU_RNR_R_REGION_BIT);
    MCU__vWriteRegister(MPU_BASE, MPU_RASR_OFFSET, 0UL, MPU_RASR_R_ENABLE_MASK, 0UL);
}

static void MPU__vConfigureRegion(UBase_t uxRegionArg, UBase_t uxStartArg, UBase_t uxEndArg, UBase_t uxAccessPermissionArg, UBase_t uxExecuteNeverArg)
{
    UBase_t uxBaseReg;
    UBase_t uxSizeReg;
    UBase_t uxSubRegionMaskReg;
    UBase_t uxSizeEncodingReg;

    if((uxEndArg <= uxStartArg) || (7UL < uxRegionArg))
    {
        return;
    }

    MPU__vGetRegionEnvelope(uxStartArg, uxEndArg, &uxBaseReg, &uxSizeReg);
    uxSubRegionMaskReg = MPU__uxGetSubRegionDisableMask(uxBaseReg, uxSizeReg, uxStartArg, uxEndArg);
    uxSizeEncodingReg = MPU__uxGetRegionSizeEncoding(uxSizeReg);

    MCU__vWriteRegister(MPU_BASE, MPU_RNR_OFFSET, uxRegionArg, MPU_RNR_REGION_MASK,
                        MPU_RNR_R_REGION_BIT);
    MCU__vWriteRegister(MPU_BASE, MPU_RBAR_OFFSET,
                        uxBaseReg | MPU_RBAR_R_VALID_ENA | MPU_uxRegionValue[uxRegionArg],
                        MPU_RBAR_R_ADDR_MASK | MPU_RBAR_R_VALID_MASK | MPU_RBAR_R_REGION_MASK, 0UL);
    MCU__vWriteRegister(MPU_BASE, MPU_RASR_OFFSET,
                        uxExecuteNeverArg | uxAccessPermissionArg | MPU_RASR_R_S_DIS |
                        MPU_RASR_R_C_DIS | MPU_RASR_R_B_DIS | MPU_RASR_R_TEX_WB_WRA |
                        MPU_RASR_R_ENABLE_ENA | uxSizeEncodingReg | uxSubRegionMaskReg,
                        MPU_RASR_R_XN_MASK | MPU_RASR_R_AP_MASK | MPU_RASR_R_S_MASK |
                        MPU_RASR_R_C_MASK | MPU_RASR_R_B_MASK | MPU_RASR_R_TEX_MASK |
                        MPU_RASR_R_ENABLE_MASK | MPU_RASR_R_SIZE_MASK | MPU_RASR_R_SRD_MASK,
                        0UL);
}

static void MPU__vGetRegionEnvelope(UBase_t uxStartArg, UBase_t uxEndArg, UBase_t* puxBaseArg, UBase_t* puxSizeArg)
{
    UBase_t uxBaseReg;
    UBase_t uxSizeReg;

    uxSizeReg = MPU__uxGetRegionSize(uxEndArg - uxStartArg);
    uxBaseReg = uxStartArg & ~(uxSizeReg - 1UL);

    while((uxBaseReg + uxSizeReg) < uxEndArg)
    {
        uxSizeReg <<= 1UL;
        uxBaseReg = uxStartArg & ~(uxSizeReg - 1UL);
    }

    *puxBaseArg = uxBaseReg;
    *puxSizeArg = uxSizeReg;
}

static UBase_t MPU__uxGetRegionSize(UBase_t uxSpanArg)
{
    UBase_t uxSizeReg;

    uxSizeReg = 32UL;
    while(uxSizeReg < uxSpanArg)
    {
        uxSizeReg <<= 1UL;
    }
    return (uxSizeReg);
}

static UBase_t MPU__uxGetRegionSizeEncoding(UBase_t uxSizeArg)
{
    UBase_t uxBitReg;

    uxBitReg = 0UL;
    while(1UL < uxSizeArg)
    {
        uxSizeArg >>= 1UL;
        uxBitReg++;
    }
    return (((uxBitReg - 1UL) << MPU_RASR_R_SIZE_BIT));
}

static UBase_t MPU__uxGetSubRegionDisableMask(UBase_t uxBaseArg, UBase_t uxSizeArg, UBase_t uxStartArg, UBase_t uxEndArg)
{
    UBase_t uxSubRegionMaskReg;
    UBase_t uxSubRegionStartReg;
    UBase_t uxSubRegionEndReg;
    UBase_t uxSubRegionSizeReg;
    UBase_t uxSubRegion;

    uxSubRegionMaskReg = 0UL;
    if(256UL <= uxSizeArg)
    {
        uxSubRegionSizeReg = uxSizeArg >> 3UL;
        for(uxSubRegion = 0UL; uxSubRegion < 8UL; uxSubRegion++)
        {
            uxSubRegionStartReg = uxBaseArg + (uxSubRegion * uxSubRegionSizeReg);
            uxSubRegionEndReg = uxSubRegionStartReg + uxSubRegionSizeReg;
            if((uxSubRegionEndReg <= uxStartArg) || (uxSubRegionStartReg >= uxEndArg))
            {
                uxSubRegionMaskReg |= (1UL << (uxSubRegion + 8UL));
            }
        }
    }
    return (uxSubRegionMaskReg);
}