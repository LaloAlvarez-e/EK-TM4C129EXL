/**
 *
 * @file SYSCTL_SystemClock_Test.cpp
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
 * @verbatim 02 apr. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 02 apr. 2026   GitHub Copilot   1.0         initial Version@endverbatim
 */

extern "C"
{
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_SystemClock.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_ALTCLKCFG.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_MEMTIM0.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_MOSCCTL.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_PLLFREQ.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_PLLSTAT.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_RIS.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_RSCLKCFG.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_DIVSCLK.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/xHeader/SYSCTL_RegisterAddress.h>
}

#include <tm4c129e_test/SYSCTL_MCURegisterAccessMock.h>
#include <tm4c129e_test/SYSCTL_PrimitivesMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::_;
using ::testing::InSequence;
using ::testing::Invoke;
using ::testing::Return;
using ::testing::StrictMock;
using ::testing::Truly;

namespace
{

auto MakeWriteRegisterAction(uintptr_t uptrAddressArg,
                             UBase_t uxMaskArg,
                             UBase_t uxShiftArg,
                             UBase_t uxValueArg,
                             SYSCTL_nERROR enErrorArg = SYSCTL_enERROR_OK)
{
    return [=](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
    {
        EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
        EXPECT_NE(nullptr, pstRegisterDataArg);
        if(nullptr == pstRegisterDataArg)
        {
            return SYSCTL_enERROR_POINTER;
        }

        EXPECT_EQ(uptrAddressArg, pstRegisterDataArg->uptrAddress);
        EXPECT_EQ(uxMaskArg, pstRegisterDataArg->uxMask);
        EXPECT_EQ(uxShiftArg, pstRegisterDataArg->uxShift);
        EXPECT_EQ(uxValueArg, pstRegisterDataArg->uxValue);
        return enErrorArg;
    };
}

auto MakeReadRegisterAction(uintptr_t uptrAddressArg,
                            UBase_t uxMaskArg,
                            UBase_t uxShiftArg,
                            UBase_t uxValueArg,
                            SYSCTL_nERROR enErrorArg = SYSCTL_enERROR_OK)
{
    return [=](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
    {
        EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
        EXPECT_NE(nullptr, pstRegisterDataArg);
        if(nullptr == pstRegisterDataArg)
        {
            return SYSCTL_enERROR_POINTER;
        }

        EXPECT_EQ(uptrAddressArg, pstRegisterDataArg->uptrAddress);
        EXPECT_EQ(uxMaskArg, pstRegisterDataArg->uxMask);
        EXPECT_EQ(uxShiftArg, pstRegisterDataArg->uxShift);
        if(SYSCTL_enERROR_OK == enErrorArg)
        {
            pstRegisterDataArg->uxValue = uxValueArg;
        }
        return enErrorArg;
    };
}

void ExpectCheckParamsOk(SYSCTL_MCURegisterAccessMock& stMockArg, int s32TimesArg)
{
    EXPECT_CALL(stMockArg, CheckParams(_, _))
        .Times(s32TimesArg)
        .WillRepeatedly(Return(MCU_enERROR_OK));
}

void ExpectMemoryTimingWrites(SYSCTL_PrimitivesMock& stMockArg,
                              SYSCTL_nMEM_HIGHTIME enMemoryHighTimeArg,
                              SYSCTL_nMEM_WAITSTATE enMemoryWaitStateArg,
                              SYSCTL_nMEM_CLOCKEDGE enMemoryClockEdgeArg)
{
    EXPECT_CALL(stMockArg, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(MEMORY_TIM0_OFFSET,
                                                 MEMORY_TIM0_FLASH_BCHT_MASK,
                                                 MEMORY_TIM0_R_FLASH_BCHT_BIT,
                                                 (UBase_t) enMemoryHighTimeArg)));
    EXPECT_CALL(stMockArg, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(MEMORY_TIM0_OFFSET,
                                                 MEMORY_TIM0_EEPROM_BCHT_MASK,
                                                 MEMORY_TIM0_R_EEPROM_BCHT_BIT,
                                                 (UBase_t) enMemoryHighTimeArg)));
    EXPECT_CALL(stMockArg, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(MEMORY_TIM0_OFFSET,
                                                 MEMORY_TIM0_FLASH_WS_MASK,
                                                 MEMORY_TIM0_R_FLASH_WS_BIT,
                                                 (UBase_t) enMemoryWaitStateArg)));
    EXPECT_CALL(stMockArg, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(MEMORY_TIM0_OFFSET,
                                                 MEMORY_TIM0_EEPROM_WS_MASK,
                                                 MEMORY_TIM0_R_EEPROM_WS_BIT,
                                                 (UBase_t) enMemoryWaitStateArg)));
    EXPECT_CALL(stMockArg, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(MEMORY_TIM0_OFFSET,
                                                 MEMORY_TIM0_FLASH_BCE_MASK,
                                                 MEMORY_TIM0_R_FLASH_BCE_BIT,
                                                 (UBase_t) enMemoryClockEdgeArg)));
    EXPECT_CALL(stMockArg, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(MEMORY_TIM0_OFFSET,
                                                 MEMORY_TIM0_EEPROM_BCE_MASK,
                                                 MEMORY_TIM0_R_EEPROM_BCE_BIT,
                                                 (UBase_t) enMemoryClockEdgeArg)));
}

void ExpectPll480MHzVCOReads(SYSCTL_PrimitivesMock& stMockArg)
{
    EXPECT_CALL(stMockArg, ReadRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeReadRegisterAction(RSCLK_CFG_OFFSET,
                                                RSCLK_CFG_PLL_SRC_MASK,
                                                RSCLK_CFG_R_PLL_SRC_BIT,
                                                (UBase_t) SYSCTL_enOSCCLK_SRC_PIOSC)));
    EXPECT_CALL(stMockArg, ReadRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeReadRegisterAction(PLL_FREQ1_OFFSET,
                                                PLL_FREQ1_PLL_N_VALUE_MASK,
                                                PLL_FREQ1_R_PLL_N_VALUE_BIT,
                                                0UL)));
    EXPECT_CALL(stMockArg, ReadRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeReadRegisterAction(PLL_FREQ1_OFFSET,
                                                PLL_FREQ1_PLL_Q_VALUE_MASK,
                                                PLL_FREQ1_R_PLL_Q_VALUE_BIT,
                                                0UL)));
    EXPECT_CALL(stMockArg, ReadRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeReadRegisterAction(PLL_FREQ0_OFFSET,
                                                PLL_FREQ0_PLL_M_INT_MASK,
                                                PLL_FREQ0_R_PLL_M_INT_BIT,
                                                30UL)));
    EXPECT_CALL(stMockArg, ReadRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeReadRegisterAction(PLL_FREQ0_OFFSET,
                                                PLL_FREQ0_PLL_M_FRAC_MASK,
                                                PLL_FREQ0_R_PLL_M_FRAC_BIT,
                                                0UL)));
}

void ExpectSafePIOSCStage(SYSCTL_PrimitivesMock& stMockArg)
{
    ExpectMemoryTimingWrites(stMockArg,
                             SYSCTL_enMEM_HIGHTIME_3_5,
                             SYSCTL_enMEM_WAITSTATE_5,
                             SYSCTL_enMEM_CLOCKEDGE_RISING);
    EXPECT_CALL(stMockArg, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_MEMTIMU_MASK,
                                                 RSCLK_CFG_R_MEMTIMU_BIT,
                                                 RSCLK_CFG_MEMTIMU_UPDATE)));
    EXPECT_CALL(stMockArg, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_OSC_SRC_MASK,
                                                 RSCLK_CFG_R_OSC_SRC_BIT,
                                                 (UBase_t) SYSCTL_enOSCCLK_SRC_PIOSC)));
    EXPECT_CALL(stMockArg, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_OSC_SYSDIV_MASK,
                                                 RSCLK_CFG_R_OSC_SYSDIV_BIT,
                                                 0UL)));
    EXPECT_CALL(stMockArg, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_USEPLL_MASK,
                                                 RSCLK_CFG_R_USEPLL_BIT,
                                                 (UBase_t) SYSCTL_enSYSCLK_SRC_OSCCLK)));
    ExpectMemoryTimingWrites(stMockArg,
                             SYSCTL_enMEM_HIGHTIME_0_5,
                             SYSCTL_enMEM_WAITSTATE_0,
                             SYSCTL_enMEM_CLOCKEDGE_FAILING);
    EXPECT_CALL(stMockArg, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_MEMTIMU_MASK,
                                                 RSCLK_CFG_R_MEMTIMU_BIT,
                                                 RSCLK_CFG_MEMTIMU_UPDATE)));
}

bool IsPLLDivisorReadRequest(SYSCTL_Register_t* pstRegisterDataArg)
{
    bool boValidReg;

    boValidReg = false;
    if(nullptr != pstRegisterDataArg)
    {
        boValidReg = (RSCLK_CFG_OFFSET == pstRegisterDataArg->uptrAddress) &&
                     (RSCLK_CFG_PLL_SYSDIV_MASK == pstRegisterDataArg->uxMask) &&
                     (RSCLK_CFG_R_PLL_SYSDIV_BIT == pstRegisterDataArg->uxShift);
    }
    return (boValidReg);
}

bool IsPLLStateWriteRequest(SYSCTL_Register_t* pstRegisterDataArg)
{
    bool boValidReg;

    boValidReg = false;
    if(nullptr != pstRegisterDataArg)
    {
        boValidReg = (PLL_FREQ0_OFFSET == pstRegisterDataArg->uptrAddress) &&
                     (PLL_FREQ0_PLL_PWR_MASK == pstRegisterDataArg->uxMask) &&
                     (PLL_FREQ0_R_PLL_PWR_BIT == pstRegisterDataArg->uxShift);
    }
    return (boValidReg);
}

}

/**
 * @brief Validate null-pointer rejection in the SystemClock frequency getters.
 * @summary Confirms that `SYSCTL__enGetVCOClockFrequency` and
 *          `SYSCTL__enGetPLLClockFrequency` reject null output pointers before
 *          attempting any dependency reads.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_SystemClock.c
 * - Public API parameter validation path@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-SYSCLK-001@endverbatim
 */
TEST(SYSCTL_SystemClockTest, GetVCOAndPLLClockFrequencyRejectNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetVCOClockFrequency(SYSCTL_enMODULE_0, (UBase_t*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetPLLClockFrequency(SYSCTL_enMODULE_0, (UBase_t*) 0UL));
}

/**
 * @brief Validate that the PIOSC PLL reference path no longer depends on MOSC state.
 * @summary Confirms that `SYSCTL__enGetVCOClockFrequency` uses the documented
 *          PIOSC reference directly when `RSCLKCFG.PLLSRC` selects PIOSC and
 *          derives the expected VCO frequency from the programmed MINT, MFRAC,
 *          N, and Q fields without reading `MOSCCTL.NOXTAL`.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original sources under test: SYSCTL_SystemClock.c, SYSCTL_GatingClock.c,
 *   and SYSCTL_PLLCLock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-SYSCLK-002@endverbatim
 */
TEST(SYSCTL_SystemClockTest, GetVCOClockFrequencyUsesPIOSCReferenceWithoutMOSCDependency)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    InSequence stSequence;
    UBase_t uxFrequencyReg;

    uxFrequencyReg = 0UL;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(RSCLK_CFG_OFFSET,
                                                RSCLK_CFG_PLL_SRC_MASK,
                                                RSCLK_CFG_R_PLL_SRC_BIT,
                                                (UBase_t) SYSCTL_enOSCCLK_SRC_PIOSC)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(PLL_FREQ1_OFFSET,
                                                PLL_FREQ1_PLL_N_VALUE_MASK,
                                                PLL_FREQ1_R_PLL_N_VALUE_BIT,
                                                0UL)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(PLL_FREQ1_OFFSET,
                                                PLL_FREQ1_PLL_Q_VALUE_MASK,
                                                PLL_FREQ1_R_PLL_Q_VALUE_BIT,
                                                0UL)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(PLL_FREQ0_OFFSET,
                                                PLL_FREQ0_PLL_M_INT_MASK,
                                                PLL_FREQ0_R_PLL_M_INT_BIT,
                                                30UL)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(PLL_FREQ0_OFFSET,
                                                PLL_FREQ0_PLL_M_FRAC_MASK,
                                                PLL_FREQ0_R_PLL_M_FRAC_BIT,
                                                0UL)));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enGetVCOClockFrequency(SYSCTL_enMODULE_0, &uxFrequencyReg));
    EXPECT_EQ((UBase_t) 480000000UL, uxFrequencyReg);
}

/**
 * @brief Validate that the MOSC PLL reference path only uses MOSC when it is available.
 * @summary Confirms that `SYSCTL__enGetVCOClockFrequency` checks the documented
 *          MOSC availability bits before using the fixed MOSC reference and then
 *          derives the expected VCO frequency from the programmed PLL divider fields.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original sources under test: SYSCTL_SystemClock.c, SYSCTL_GatingClock.c,
 *   SYSCTL_MainOsc.c, and SYSCTL_PLLCLock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-SYSCLK-004@endverbatim
 */
TEST(SYSCTL_SystemClockTest, GetVCOClockFrequencyUsesMOSCReferenceOnlyWhenMOSCAvailable)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    InSequence stSequence;
    UBase_t uxFrequencyReg;

    uxFrequencyReg = 0UL;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(RSCLK_CFG_OFFSET,
                                                RSCLK_CFG_PLL_SRC_MASK,
                                                RSCLK_CFG_R_PLL_SRC_BIT,
                                                (UBase_t) SYSCTL_enOSCCLK_SRC_MOSC)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(MOSC_CTL_OFFSET,
                                                MOSC_CTL_NOXTAL_MASK,
                                                MOSC_CTL_R_NOXTAL_BIT,
                                                (UBase_t) MOSC_CTL_NOXTAL_CONNECTED)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(MOSC_CTL_OFFSET,
                                                MOSC_CTL_PWRDN_MASK,
                                                MOSC_CTL_R_PWRDN_BIT,
                                                (UBase_t) MOSC_CTL_PWRDN_POWERUP)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(PLL_FREQ1_OFFSET,
                                                PLL_FREQ1_PLL_N_VALUE_MASK,
                                                PLL_FREQ1_R_PLL_N_VALUE_BIT,
                                                4UL)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(PLL_FREQ1_OFFSET,
                                                PLL_FREQ1_PLL_Q_VALUE_MASK,
                                                PLL_FREQ1_R_PLL_Q_VALUE_BIT,
                                                0UL)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(PLL_FREQ0_OFFSET,
                                                PLL_FREQ0_PLL_M_INT_MASK,
                                                PLL_FREQ0_R_PLL_M_INT_BIT,
                                                96UL)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(PLL_FREQ0_OFFSET,
                                                PLL_FREQ0_PLL_M_FRAC_MASK,
                                                PLL_FREQ0_R_PLL_M_FRAC_BIT,
                                                0UL)));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enGetVCOClockFrequency(SYSCTL_enMODULE_0, &uxFrequencyReg));
    EXPECT_EQ((UBase_t) 480000000UL, uxFrequencyReg);
}

/**
 * @brief Validate that MOSC-selected oscillator frequency returns zero when MOSC is unavailable.
 * @summary Confirms that `SYSCTL__enGetOscillatorFrequency` does not report the
 *          nominal MOSC frequency when the crystal is disconnected or powered down.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original sources under test: SYSCTL_SystemClock.c, SYSCTL_GatingClock.c,
 *   and SYSCTL_MainOsc.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-SYSCLK-005@endverbatim
 */
TEST(SYSCTL_SystemClockTest, GetOscillatorFrequencyReturnsZeroWhenMOSCIsUnavailable)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    InSequence stSequence;
    UBase_t uxFrequencyReg;

    uxFrequencyReg = 1UL;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(RSCLK_CFG_OFFSET,
                                                RSCLK_CFG_OSC_SRC_MASK,
                                                RSCLK_CFG_R_OSC_SRC_BIT,
                                                (UBase_t) SYSCTL_enOSCCLK_SRC_MOSC)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(RSCLK_CFG_OFFSET,
                                                RSCLK_CFG_OSC_SYSDIV_MASK,
                                                RSCLK_CFG_R_OSC_SYSDIV_BIT,
                                                0UL)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(MOSC_CTL_OFFSET,
                                                MOSC_CTL_NOXTAL_MASK,
                                                MOSC_CTL_R_NOXTAL_BIT,
                                                (UBase_t) MOSC_CTL_NOXTAL_CONNECTED)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(MOSC_CTL_OFFSET,
                                                MOSC_CTL_PWRDN_MASK,
                                                MOSC_CTL_R_PWRDN_BIT,
                                                (UBase_t) MOSC_CTL_PWRDN_POWERDOWN)));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enGetOscillatorFrequency(SYSCTL_enMODULE_0, &uxFrequencyReg));
    EXPECT_EQ((UBase_t) 0UL, uxFrequencyReg);
}

/**
 * @brief Validate that MOSC-selected output clock returns zero when MOSC is unavailable.
 * @summary Confirms that `SYSCTL__enGetOutputClockFrequency` does not report the
 *          nominal MOSC frequency when the output clock source selects MOSC but
 *          the crystal is disconnected or powered down.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original sources under test: SYSCTL_SystemClock.c, SYSCTL_OutputClock.c,
 *   and SYSCTL_MainOsc.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-SYSCLK-006@endverbatim
 */
TEST(SYSCTL_SystemClockTest, GetOutputClockFrequencyReturnsZeroWhenMOSCIsUnavailable)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    InSequence stSequence;
    UBase_t uxFrequencyReg;

    uxFrequencyReg = 1UL;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(DIVSCLK_CFG_OFFSET,
                                                DIVSCLK_CFG_SRC_MASK,
                                                DIVSCLK_CFG_R_SRC_BIT,
                                                (UBase_t) SYSCTL_enOUTCLK_SRC_MOSC)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(DIVSCLK_CFG_OFFSET,
                                                DIVSCLK_CFG_DIV_MASK,
                                                DIVSCLK_CFG_R_DIV_BIT,
                                                0UL)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(MOSC_CTL_OFFSET,
                                                MOSC_CTL_NOXTAL_MASK,
                                                MOSC_CTL_R_NOXTAL_BIT,
                                                (UBase_t) MOSC_CTL_NOXTAL_NOCONNECTED)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(MOSC_CTL_OFFSET,
                                                MOSC_CTL_PWRDN_MASK,
                                                MOSC_CTL_R_PWRDN_BIT,
                                                (UBase_t) MOSC_CTL_PWRDN_POWERUP)));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enGetOutputClockFrequency(SYSCTL_enMODULE_0, &uxFrequencyReg));
    EXPECT_EQ((UBase_t) 0UL, uxFrequencyReg);
}

/**
 * @brief Validate PLL output-frequency derivation after the PIOSC-based VCO calculation.
 * @summary Confirms that `SYSCTL__enGetPLLClockFrequency` first derives the VCO
 *          frequency from the PIOSC PLL reference path and then applies the
 *          documented `RSCLKCFG.PLLSYSDIV + 1` divisor to produce the PLL clock.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original sources under test: SYSCTL_SystemClock.c, SYSCTL_GatingClock.c,
 *   and SYSCTL_PLLCLock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-SYSCLK-003@endverbatim
 */
TEST(SYSCTL_SystemClockTest, GetPLLClockFrequencyUsesDerivedVCOAndPllDivisor)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    InSequence stSequence;
    UBase_t uxFrequencyReg;

    uxFrequencyReg = 0UL;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(RSCLK_CFG_OFFSET,
                                                RSCLK_CFG_PLL_SRC_MASK,
                                                RSCLK_CFG_R_PLL_SRC_BIT,
                                                (UBase_t) SYSCTL_enOSCCLK_SRC_PIOSC)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(PLL_FREQ1_OFFSET,
                                                PLL_FREQ1_PLL_N_VALUE_MASK,
                                                PLL_FREQ1_R_PLL_N_VALUE_BIT,
                                                0UL)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(PLL_FREQ1_OFFSET,
                                                PLL_FREQ1_PLL_Q_VALUE_MASK,
                                                PLL_FREQ1_R_PLL_Q_VALUE_BIT,
                                                0UL)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(PLL_FREQ0_OFFSET,
                                                PLL_FREQ0_PLL_M_INT_MASK,
                                                PLL_FREQ0_R_PLL_M_INT_BIT,
                                                30UL)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(PLL_FREQ0_OFFSET,
                                                PLL_FREQ0_PLL_M_FRAC_MASK,
                                                PLL_FREQ0_R_PLL_M_FRAC_BIT,
                                                0UL)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(RSCLK_CFG_OFFSET,
                                                RSCLK_CFG_PLL_SYSDIV_MASK,
                                                RSCLK_CFG_R_PLL_SYSDIV_BIT,
                                                3UL)));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enGetPLLClockFrequency(SYSCTL_enMODULE_0, &uxFrequencyReg));
    EXPECT_EQ((UBase_t) 120000000UL, uxFrequencyReg);
}

/**
 * @brief Validate the fixed nominal frequency helpers.
 * @summary Confirms that the direct PIOSC, MOSC, and LFIOSC helper APIs reject
 *          null output pointers and return the documented nominal frequencies
 *          used by the board-support clock model.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_SystemClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-SYSCLK-012@endverbatim
 */
TEST(SYSCTL_SystemClockTest, GetStaticClockHelpersReturnExpectedNominalValuesAndRejectNullPointers)
{
    UBase_t uxFrequencyReg;

    uxFrequencyReg = 0UL;
    EXPECT_EQ(SYSCTL_enERROR_POINTER, SYSCTL__enGetPIOSCFrequency((UBase_t*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetPIOSCFrequency(&uxFrequencyReg));
    EXPECT_EQ((UBase_t) 16000000UL, uxFrequencyReg);

    uxFrequencyReg = 0UL;
    EXPECT_EQ(SYSCTL_enERROR_POINTER, SYSCTL__enGetMOSCFrequency((UBase_t*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetMOSCFrequency(&uxFrequencyReg));
    EXPECT_EQ((UBase_t) 25000000UL, uxFrequencyReg);

    uxFrequencyReg = 0UL;
    EXPECT_EQ(SYSCTL_enERROR_POINTER, SYSCTL__enGetLFIOSCFrequency((UBase_t*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetLFIOSCFrequency(&uxFrequencyReg));
    EXPECT_EQ((UBase_t) 33000UL, uxFrequencyReg);
}

/**
 * @brief Validate null-pointer rejection in alternate-clock frequency queries.
 * @summary Confirms that `SYSCTL__enGetAlternateClockFrequency` rejects a null
 *          output pointer before touching the alternate-clock source register path.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_SystemClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-SYSCLK-013@endverbatim
 */
TEST(SYSCTL_SystemClockTest, GetAlternateClockFrequencyRejectsNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetAlternateClockFrequency(SYSCTL_enMODULE_0, (UBase_t*) 0UL));
}

/**
 * @brief Validate alternate-clock source frequency selection.
 * @summary Confirms that `SYSCTL__enGetAlternateClockFrequency` returns the
 *          correct PIOSC, RTCOSC, and LFIOSC frequencies for the programmed
 *          alternate source and rejects unsupported source values.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original sources under test: SYSCTL_SystemClock.c and SYSCTL_AlternateClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-SYSCLK-014@endverbatim
 */
TEST(SYSCTL_SystemClockTest, GetAlternateClockFrequencyUsesAllDocumentedSourcesAndRejectsInvalidSource)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        UBase_t uxFrequencyReg;

        uxFrequencyReg = 0UL;
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeReadRegisterAction(ALTCLK_CFG_OFFSET,
                                                    ALTCLK_CFG_ALTCLK_MASK,
                                                    ALTCLK_CFG_R_ALTCLK_BIT,
                                                    (UBase_t) SYSCTL_enALTCLK_SRC_PIOSC)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enGetAlternateClockFrequency(SYSCTL_enMODULE_0, &uxFrequencyReg));
        EXPECT_EQ((UBase_t) 16000000UL, uxFrequencyReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        UBase_t uxFrequencyReg;

        uxFrequencyReg = 0UL;
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeReadRegisterAction(ALTCLK_CFG_OFFSET,
                                                    ALTCLK_CFG_ALTCLK_MASK,
                                                    ALTCLK_CFG_R_ALTCLK_BIT,
                                                    (UBase_t) SYSCTL_enALTCLK_SRC_RTCOSC)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enGetAlternateClockFrequency(SYSCTL_enMODULE_0, &uxFrequencyReg));
        EXPECT_EQ((UBase_t) 32768UL, uxFrequencyReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        UBase_t uxFrequencyReg;

        uxFrequencyReg = 0UL;
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeReadRegisterAction(ALTCLK_CFG_OFFSET,
                                                    ALTCLK_CFG_ALTCLK_MASK,
                                                    ALTCLK_CFG_R_ALTCLK_BIT,
                                                    (UBase_t) SYSCTL_enALTCLK_SRC_LFIOSC)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enGetAlternateClockFrequency(SYSCTL_enMODULE_0, &uxFrequencyReg));
        EXPECT_EQ((UBase_t) 33000UL, uxFrequencyReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        UBase_t uxFrequencyReg;

        uxFrequencyReg = 123UL;
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeReadRegisterAction(ALTCLK_CFG_OFFSET,
                                                    ALTCLK_CFG_ALTCLK_MASK,
                                                    ALTCLK_CFG_R_ALTCLK_BIT,
                                                    (UBase_t) SYSCTL_enALTCLK_SRC_UNDEF)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE,
                  SYSCTL__enGetAlternateClockFrequency(SYSCTL_enMODULE_0, &uxFrequencyReg));
        EXPECT_EQ((UBase_t) 123UL, uxFrequencyReg);
    }
}

/**
 * @brief Validate null-pointer rejection in oscillator frequency queries.
 * @summary Confirms that `SYSCTL__enGetOscillatorFrequency` rejects a null output
 *          pointer before touching the oscillator source and divisor registers.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_SystemClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-SYSCLK-015@endverbatim
 */
TEST(SYSCTL_SystemClockTest, GetOscillatorFrequencyRejectsNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetOscillatorFrequency(SYSCTL_enMODULE_0, (UBase_t*) 0UL));
}

/**
 * @brief Validate non-MOSC oscillator frequency selection and divisor handling.
 * @summary Confirms that `SYSCTL__enGetOscillatorFrequency` applies the
 *          programmed oscillator divider to the selected PIOSC, RTCOSC, and
 *          LFIOSC sources and rejects unsupported oscillator source values.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_SystemClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-SYSCLK-016@endverbatim
 */
TEST(SYSCTL_SystemClockTest, GetOscillatorFrequencyUsesNonMOSCSourcesAndRejectsInvalidSource)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        InSequence stSequence;
        UBase_t uxFrequencyReg;

        uxFrequencyReg = 0UL;
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeReadRegisterAction(RSCLK_CFG_OFFSET,
                                                    RSCLK_CFG_OSC_SRC_MASK,
                                                    RSCLK_CFG_R_OSC_SRC_BIT,
                                                    (UBase_t) SYSCTL_enOSCCLK_SRC_PIOSC)));
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeReadRegisterAction(RSCLK_CFG_OFFSET,
                                                    RSCLK_CFG_OSC_SYSDIV_MASK,
                                                    RSCLK_CFG_R_OSC_SYSDIV_BIT,
                                                    1UL)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enGetOscillatorFrequency(SYSCTL_enMODULE_0, &uxFrequencyReg));
        EXPECT_EQ((UBase_t) 8000000UL, uxFrequencyReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        InSequence stSequence;
        UBase_t uxFrequencyReg;

        uxFrequencyReg = 0UL;
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeReadRegisterAction(RSCLK_CFG_OFFSET,
                                                    RSCLK_CFG_OSC_SRC_MASK,
                                                    RSCLK_CFG_R_OSC_SRC_BIT,
                                                    (UBase_t) SYSCTL_enOSCCLK_SRC_RTCOSC)));
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeReadRegisterAction(RSCLK_CFG_OFFSET,
                                                    RSCLK_CFG_OSC_SYSDIV_MASK,
                                                    RSCLK_CFG_R_OSC_SYSDIV_BIT,
                                                    0UL)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enGetOscillatorFrequency(SYSCTL_enMODULE_0, &uxFrequencyReg));
        EXPECT_EQ((UBase_t) 32768UL, uxFrequencyReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        InSequence stSequence;
        UBase_t uxFrequencyReg;

        uxFrequencyReg = 0UL;
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeReadRegisterAction(RSCLK_CFG_OFFSET,
                                                    RSCLK_CFG_OSC_SRC_MASK,
                                                    RSCLK_CFG_R_OSC_SRC_BIT,
                                                    (UBase_t) SYSCTL_enOSCCLK_SRC_LFIOSC)));
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeReadRegisterAction(RSCLK_CFG_OFFSET,
                                                    RSCLK_CFG_OSC_SYSDIV_MASK,
                                                    RSCLK_CFG_R_OSC_SYSDIV_BIT,
                                                    2UL)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enGetOscillatorFrequency(SYSCTL_enMODULE_0, &uxFrequencyReg));
        EXPECT_EQ((UBase_t) 11000UL, uxFrequencyReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        InSequence stSequence;
        UBase_t uxFrequencyReg;

        uxFrequencyReg = 123UL;
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeReadRegisterAction(RSCLK_CFG_OFFSET,
                                                    RSCLK_CFG_OSC_SRC_MASK,
                                                    RSCLK_CFG_R_OSC_SRC_BIT,
                                                    (UBase_t) SYSCTL_enOSCCLK_SRC_UNDEF)));
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeReadRegisterAction(RSCLK_CFG_OFFSET,
                                                    RSCLK_CFG_OSC_SYSDIV_MASK,
                                                    RSCLK_CFG_R_OSC_SYSDIV_BIT,
                                                    0UL)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE,
                  SYSCTL__enGetOscillatorFrequency(SYSCTL_enMODULE_0, &uxFrequencyReg));
        EXPECT_EQ((UBase_t) 123UL, uxFrequencyReg);
    }
}

/**
 * @brief Validate system-clock source delegation.
 * @summary Confirms that `SYSCTL__enGetSystemClockFrequency` rejects a null output
 *          pointer and delegates to the oscillator or PLL frequency helper based
 *          on the programmed system clock source selection.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original sources under test: SYSCTL_SystemClock.c and SYSCTL_PLLCLock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-SYSCLK-017@endverbatim
 */
TEST(SYSCTL_SystemClockTest, GetSystemClockFrequencyRejectsNullPointerAndDelegatesBySource)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetSystemClockFrequency(SYSCTL_enMODULE_0, (UBase_t*) 0UL));

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        InSequence stSequence;
        UBase_t uxFrequencyReg;

        uxFrequencyReg = 0UL;
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeReadRegisterAction(RSCLK_CFG_OFFSET,
                                                    RSCLK_CFG_USEPLL_MASK,
                                                    RSCLK_CFG_R_USEPLL_BIT,
                                                    (UBase_t) SYSCTL_enSYSCLK_SRC_OSCCLK)));
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeReadRegisterAction(RSCLK_CFG_OFFSET,
                                                    RSCLK_CFG_OSC_SRC_MASK,
                                                    RSCLK_CFG_R_OSC_SRC_BIT,
                                                    (UBase_t) SYSCTL_enOSCCLK_SRC_RTCOSC)));
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeReadRegisterAction(RSCLK_CFG_OFFSET,
                                                    RSCLK_CFG_OSC_SYSDIV_MASK,
                                                    RSCLK_CFG_R_OSC_SYSDIV_BIT,
                                                    0UL)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enGetSystemClockFrequency(SYSCTL_enMODULE_0, &uxFrequencyReg));
        EXPECT_EQ((UBase_t) 32768UL, uxFrequencyReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        InSequence stSequence;
        UBase_t uxFrequencyReg;

        uxFrequencyReg = 0UL;
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeReadRegisterAction(RSCLK_CFG_OFFSET,
                                                    RSCLK_CFG_USEPLL_MASK,
                                                    RSCLK_CFG_R_USEPLL_BIT,
                                                    (UBase_t) SYSCTL_enSYSCLK_SRC_PLLCLK)));
        ExpectPll480MHzVCOReads(stMock);
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeReadRegisterAction(RSCLK_CFG_OFFSET,
                                                    RSCLK_CFG_PLL_SYSDIV_MASK,
                                                    RSCLK_CFG_R_PLL_SYSDIV_BIT,
                                                    3UL)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enGetSystemClockFrequency(SYSCTL_enMODULE_0, &uxFrequencyReg));
        EXPECT_EQ((UBase_t) 120000000UL, uxFrequencyReg);
    }
}

/**
 * @brief Validate output-clock source delegation and divisor handling.
 * @summary Confirms that `SYSCTL__enGetOutputClockFrequency` rejects a null output
 *          pointer, applies the programmed divider to the selected PIOSC or SYSCLK
 *          source, and rejects unsupported output source values.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original sources under test: SYSCTL_SystemClock.c, SYSCTL_OutputClock.c,
 *   and SYSCTL_PLLCLock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-SYSCLK-018@endverbatim
 */
TEST(SYSCTL_SystemClockTest, GetOutputClockFrequencyRejectsNullPointerAndDelegatesBySelectedSource)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetOutputClockFrequency(SYSCTL_enMODULE_0, (UBase_t*) 0UL));

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        InSequence stSequence;
        UBase_t uxFrequencyReg;

        uxFrequencyReg = 0UL;
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeReadRegisterAction(DIVSCLK_CFG_OFFSET,
                                                    DIVSCLK_CFG_SRC_MASK,
                                                    DIVSCLK_CFG_R_SRC_BIT,
                                                    (UBase_t) SYSCTL_enOUTCLK_SRC_PIOSC)));
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeReadRegisterAction(DIVSCLK_CFG_OFFSET,
                                                    DIVSCLK_CFG_DIV_MASK,
                                                    DIVSCLK_CFG_R_DIV_BIT,
                                                    1UL)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enGetOutputClockFrequency(SYSCTL_enMODULE_0, &uxFrequencyReg));
        EXPECT_EQ((UBase_t) 8000000UL, uxFrequencyReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        InSequence stSequence;
        UBase_t uxFrequencyReg;

        uxFrequencyReg = 0UL;
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeReadRegisterAction(DIVSCLK_CFG_OFFSET,
                                                    DIVSCLK_CFG_SRC_MASK,
                                                    DIVSCLK_CFG_R_SRC_BIT,
                                                    (UBase_t) SYSCTL_enOUTCLK_SRC_SYSCLK)));
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeReadRegisterAction(DIVSCLK_CFG_OFFSET,
                                                    DIVSCLK_CFG_DIV_MASK,
                                                    DIVSCLK_CFG_R_DIV_BIT,
                                                    1UL)));
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeReadRegisterAction(RSCLK_CFG_OFFSET,
                                                    RSCLK_CFG_USEPLL_MASK,
                                                    RSCLK_CFG_R_USEPLL_BIT,
                                                    (UBase_t) SYSCTL_enSYSCLK_SRC_PLLCLK)));
        ExpectPll480MHzVCOReads(stMock);
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeReadRegisterAction(RSCLK_CFG_OFFSET,
                                                    RSCLK_CFG_PLL_SYSDIV_MASK,
                                                    RSCLK_CFG_R_PLL_SYSDIV_BIT,
                                                    3UL)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enGetOutputClockFrequency(SYSCTL_enMODULE_0, &uxFrequencyReg));
        EXPECT_EQ((UBase_t) 60000000UL, uxFrequencyReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        InSequence stSequence;
        UBase_t uxFrequencyReg;

        uxFrequencyReg = 123UL;
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeReadRegisterAction(DIVSCLK_CFG_OFFSET,
                                                    DIVSCLK_CFG_SRC_MASK,
                                                    DIVSCLK_CFG_R_SRC_BIT,
                                                    (UBase_t) SYSCTL_enOUTCLK_SRC_UNDEF)));
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeReadRegisterAction(DIVSCLK_CFG_OFFSET,
                                                    DIVSCLK_CFG_DIV_MASK,
                                                    DIVSCLK_CFG_R_DIV_BIT,
                                                    0UL)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE,
                  SYSCTL__enGetOutputClockFrequency(SYSCTL_enMODULE_0, &uxFrequencyReg));
        EXPECT_EQ((UBase_t) 123UL, uxFrequencyReg);
    }
}

/**
 * @brief Validate input rejection in the composite system-clock setter.
 * @summary Confirms that `SYSCTL__enSetSystemClock` rejects zero or out-of-range
 *          requested clock values and rejects a null configuration pointer before
 *          touching any dependency register path.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_SystemClock.c
 * - Public API parameter validation path@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-SYSCLK-007@endverbatim
 */
TEST(SYSCTL_SystemClockTest, SetSystemClockRejectsInvalidValueAndNullConfig)
{
    SYSCTL_CONFIG_t stClockConfig;

    stClockConfig.enExternalCrystal = SYSCTL_enXTAL_25MHZ;
    stClockConfig.enOscillatorSource = SYSCTL_enOSCCLK_SRC_PIOSC;
    stClockConfig.enSystemClockSource = SYSCTL_enSYSCLK_SRC_OSCCLK;
    stClockConfig.enVCORange = SYSCTL_enVCO_480MHZ;

    EXPECT_EQ(SYSCTL_enERROR_VALUE,
              SYSCTL__enSetSystemClock(SYSCTL_enMODULE_0,
                                       0UL,
                                       &stClockConfig,
                                       1UL));
    EXPECT_EQ(SYSCTL_enERROR_VALUE,
              SYSCTL__enSetSystemClock(SYSCTL_enMODULE_0,
                                       120000001UL,
                                       &stClockConfig,
                                       1UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enSetSystemClock(SYSCTL_enMODULE_0,
                                       16000000UL,
                                       (const SYSCTL_CONFIG_t*) 0UL,
                                       1UL));
}

/**
 * @brief Validate unsupported PLL-source and MOSC-crystal configurations.
 * @summary Confirms that `SYSCTL__enSetSystemClock` rejects PLL requests that
 *          use unsupported oscillator sources and rejects MOSC selections whose
 *          configured crystal frequency is outside the accepted range.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_SystemClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-SYSCLK-019@endverbatim
 */
TEST(SYSCTL_SystemClockTest, SetSystemClockRejectsUnsupportedPLLSourceAndInvalidMOSCCrystal)
{
    SYSCTL_CONFIG_t stClockConfig;

    stClockConfig.enExternalCrystal = SYSCTL_enXTAL_25MHZ;
    stClockConfig.enOscillatorSource = SYSCTL_enOSCCLK_SRC_LFIOSC;
    stClockConfig.enSystemClockSource = SYSCTL_enSYSCLK_SRC_PLLCLK;
    stClockConfig.enVCORange = SYSCTL_enVCO_480MHZ;

    EXPECT_EQ(SYSCTL_enERROR_VALUE,
              SYSCTL__enSetSystemClock(SYSCTL_enMODULE_0,
                                       16000000UL,
                                       &stClockConfig,
                                       1UL));

    stClockConfig.enExternalCrystal = SYSCTL_enXTAL_4_9152MHZ;
    stClockConfig.enOscillatorSource = SYSCTL_enOSCCLK_SRC_MOSC;
    stClockConfig.enSystemClockSource = SYSCTL_enSYSCLK_SRC_OSCCLK;
    stClockConfig.enVCORange = SYSCTL_enVCO_480MHZ;

    EXPECT_EQ(SYSCTL_enERROR_VALUE,
              SYSCTL__enSetSystemClock(SYSCTL_enMODULE_0,
                                       16000000UL,
                                       &stClockConfig,
                                       1UL));
}

/**
 * @brief Validate the successful OSCCLK path using the internal PIOSC source.
 * @summary Confirms that `SYSCTL__enSetSystemClock` performs the safe PIOSC
 *          staging sequence, computes the final oscillator divisor for a PIOSC-
 *          driven OSCCLK request, disables the PLL output path, and commits the
 *          final OSCCLK system-source selection.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original sources under test: SYSCTL_SystemClock.c and SYSCTL_MemoryTiming.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-SYSCLK-020@endverbatim
 */
TEST(SYSCTL_SystemClockTest, SetSystemClockUsesOSCCLKPIOSCPathAndDisablesPLL)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    InSequence stSequence;
    SYSCTL_CONFIG_t stClockConfig;

    stClockConfig.enExternalCrystal = SYSCTL_enXTAL_25MHZ;
    stClockConfig.enOscillatorSource = SYSCTL_enOSCCLK_SRC_PIOSC;
    stClockConfig.enSystemClockSource = SYSCTL_enSYSCLK_SRC_OSCCLK;
    stClockConfig.enVCORange = SYSCTL_enVCO_480MHZ;

    ExpectSafePIOSCStage(stMock);
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_OSC_SRC_MASK,
                                                 RSCLK_CFG_R_OSC_SRC_BIT,
                                                 (UBase_t) SYSCTL_enOSCCLK_SRC_PIOSC)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeReadRegisterAction(RSCLK_CFG_OFFSET,
                                                RSCLK_CFG_OSC_SRC_MASK,
                                                RSCLK_CFG_R_OSC_SRC_BIT,
                                                (UBase_t) SYSCTL_enOSCCLK_SRC_PIOSC)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeReadRegisterAction(RSCLK_CFG_OFFSET,
                                                RSCLK_CFG_OSC_SYSDIV_MASK,
                                                RSCLK_CFG_R_OSC_SYSDIV_BIT,
                                                0UL)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_OSC_SYSDIV_MASK,
                                                 RSCLK_CFG_R_OSC_SYSDIV_BIT,
                                                 0UL)));
    ExpectMemoryTimingWrites(stMock,
                             SYSCTL_enMEM_HIGHTIME_0_5,
                             SYSCTL_enMEM_WAITSTATE_0,
                             SYSCTL_enMEM_CLOCKEDGE_FAILING);
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(PLL_FREQ0_OFFSET,
                                                 PLL_FREQ0_PLL_PWR_MASK,
                                                 PLL_FREQ0_R_PLL_PWR_BIT,
                                                 (UBase_t) SYSCTL_enSTATE_DIS)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_MEMTIMU_MASK,
                                                 RSCLK_CFG_R_MEMTIMU_BIT,
                                                 RSCLK_CFG_MEMTIMU_UPDATE)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_USEPLL_MASK,
                                                 RSCLK_CFG_R_USEPLL_BIT,
                                                 (UBase_t) SYSCTL_enSYSCLK_SRC_OSCCLK)));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetSystemClock(SYSCTL_enMODULE_0,
                                       16000000UL,
                                       &stClockConfig,
                                       1UL));
}

/**
 * @brief Validate the successful MOSC-backed OSCCLK path.
 * @summary Confirms that `SYSCTL__enSetSystemClock` enables and waits for the
 *          main oscillator, performs the safe PIOSC staging sequence, then commits
 *          the final MOSC-based OSCCLK path with the documented 25 MHz board clock
 *          and the corresponding memory-timing update.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - SYSCTL_MCURegisterAccessMock bridge
 * - Original sources under test: SYSCTL_SystemClock.c, SYSCTL_MainOsc.c,
 *   SYSCTL_MemoryTiming.c, and SYSCTL_InterruptSource.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-SYSCLK-021@endverbatim
 */
TEST(SYSCTL_SystemClockTest, SetSystemClockUsesOSCCLKMOSCPathAfterSuccessfulPowerUp)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    StrictMock<SYSCTL_MCURegisterAccessMock> stMCUMock;
    SYSCTL_MCURegisterAccessMockScope stMCUMockScope(&stMCUMock);
    SYSCTL_CONFIG_t stClockConfig;

    stClockConfig.enExternalCrystal = SYSCTL_enXTAL_25MHZ;
    stClockConfig.enOscillatorSource = SYSCTL_enOSCCLK_SRC_MOSC;
    stClockConfig.enSystemClockSource = SYSCTL_enSYSCLK_SRC_OSCCLK;
    stClockConfig.enVCORange = SYSCTL_enVCO_480MHZ;

    ExpectCheckParamsOk(stMCUMock, 3);

    InSequence stSequence;

    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(MOSC_CTL_OFFSET,
                                                 MOSC_CTL_OSCRNG_MASK,
                                                 MOSC_CTL_R_OSCRNG_BIT,
                                                 (UBase_t) SYSCTL_enMOSC_RANGE_HIGH)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(MOSC_CTL_OFFSET,
                                                 MOSC_CTL_NOXTAL_MASK,
                                                 MOSC_CTL_R_NOXTAL_BIT,
                                                 (UBase_t) MOSC_CTL_NOXTAL_CONNECTED)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(MOSC_CTL_OFFSET,
                                                 MOSC_CTL_PWRDN_MASK,
                                                 MOSC_CTL_R_PWRDN_BIT,
                                                 (UBase_t) MOSC_CTL_PWRDN_POWERUP)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeReadRegisterAction(SYSCTL_RIS_OFFSET,
                                                SYSCTL_RIS_BOR_MASK,
                                                SYSCTL_RIS_R_MOSC_POWERUP_BIT,
                                                (UBase_t) SYSCTL_enSTATUS_ACTIVE)));
    ExpectSafePIOSCStage(stMock);
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_OSC_SRC_MASK,
                                                 RSCLK_CFG_R_OSC_SRC_BIT,
                                                 (UBase_t) SYSCTL_enOSCCLK_SRC_MOSC)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeReadRegisterAction(RSCLK_CFG_OFFSET,
                                                RSCLK_CFG_OSC_SRC_MASK,
                                                RSCLK_CFG_R_OSC_SRC_BIT,
                                                (UBase_t) SYSCTL_enOSCCLK_SRC_MOSC)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeReadRegisterAction(RSCLK_CFG_OFFSET,
                                                RSCLK_CFG_OSC_SYSDIV_MASK,
                                                RSCLK_CFG_R_OSC_SYSDIV_BIT,
                                                0UL)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeReadRegisterAction(MOSC_CTL_OFFSET,
                                                MOSC_CTL_NOXTAL_MASK,
                                                MOSC_CTL_R_NOXTAL_BIT,
                                                (UBase_t) MOSC_CTL_NOXTAL_CONNECTED)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeReadRegisterAction(MOSC_CTL_OFFSET,
                                                MOSC_CTL_PWRDN_MASK,
                                                MOSC_CTL_R_PWRDN_BIT,
                                                (UBase_t) MOSC_CTL_PWRDN_POWERUP)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_OSC_SYSDIV_MASK,
                                                 RSCLK_CFG_R_OSC_SYSDIV_BIT,
                                                 0UL)));
    ExpectMemoryTimingWrites(stMock,
                             SYSCTL_enMEM_HIGHTIME_1_5,
                             SYSCTL_enMEM_WAITSTATE_1,
                             SYSCTL_enMEM_CLOCKEDGE_RISING);
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(PLL_FREQ0_OFFSET,
                                                 PLL_FREQ0_PLL_PWR_MASK,
                                                 PLL_FREQ0_R_PLL_PWR_BIT,
                                                 (UBase_t) SYSCTL_enSTATE_DIS)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_MEMTIMU_MASK,
                                                 RSCLK_CFG_R_MEMTIMU_BIT,
                                                 RSCLK_CFG_MEMTIMU_UPDATE)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_USEPLL_MASK,
                                                 RSCLK_CFG_R_USEPLL_BIT,
                                                 (UBase_t) SYSCTL_enSYSCLK_SRC_OSCCLK)));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetSystemClock(SYSCTL_enMODULE_0,
                                       25000000UL,
                                       &stClockConfig,
                                       0UL));
}

/**
 * @brief Validate that PLL system-clock re-entry ignores the previously programmed divisor state.
 * @summary Confirms that `SYSCTL__enSetSystemClock` performs the safe PIOSC staging
 *          sequence, programs the PLL values for a 480 MHz VCO, and on re-entry
 *          computes the new `RSCLKCFG.PLLSYSDIV` from the configured VCO frequency
 *          without reading the currently programmed PLL divisor state.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original sources under test: SYSCTL_SystemClock.c, SYSCTL_GatingClock.c,
 *   SYSCTL_PLLCLock.c, SYSCTL_MemoryTiming.c, and SYSCTL_MainOsc.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-SYSCLK-008@endverbatim
 */
TEST(SYSCTL_SystemClockTest, SetSystemClockPLLReentryIgnoresPreviousDivisorState)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    InSequence stSequence;
    SYSCTL_CONFIG_t stClockConfig;

    stClockConfig.enExternalCrystal = SYSCTL_enXTAL_25MHZ;
    stClockConfig.enOscillatorSource = SYSCTL_enOSCCLK_SRC_PIOSC;
    stClockConfig.enSystemClockSource = SYSCTL_enSYSCLK_SRC_PLLCLK;
    stClockConfig.enVCORange = SYSCTL_enVCO_480MHZ;

    ExpectMemoryTimingWrites(stMock,
                             SYSCTL_enMEM_HIGHTIME_3_5,
                             SYSCTL_enMEM_WAITSTATE_5,
                             SYSCTL_enMEM_CLOCKEDGE_RISING);
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_MEMTIMU_MASK,
                                                 RSCLK_CFG_R_MEMTIMU_BIT,
                                                 RSCLK_CFG_MEMTIMU_UPDATE)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_OSC_SRC_MASK,
                                                 RSCLK_CFG_R_OSC_SRC_BIT,
                                                 (UBase_t) SYSCTL_enOSCCLK_SRC_PIOSC)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_OSC_SYSDIV_MASK,
                                                 RSCLK_CFG_R_OSC_SYSDIV_BIT,
                                                 0UL)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_USEPLL_MASK,
                                                 RSCLK_CFG_R_USEPLL_BIT,
                                                 (UBase_t) SYSCTL_enSYSCLK_SRC_OSCCLK)));
    ExpectMemoryTimingWrites(stMock,
                             SYSCTL_enMEM_HIGHTIME_0_5,
                             SYSCTL_enMEM_WAITSTATE_0,
                             SYSCTL_enMEM_CLOCKEDGE_FAILING);
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_MEMTIMU_MASK,
                                                 RSCLK_CFG_R_MEMTIMU_BIT,
                                                 RSCLK_CFG_MEMTIMU_UPDATE)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(PLL_FREQ0_OFFSET,
                                                 PLL_FREQ0_PLL_M_INT_MASK,
                                                 PLL_FREQ0_R_PLL_M_INT_BIT,
                                                 30UL)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(PLL_FREQ0_OFFSET,
                                                 PLL_FREQ0_PLL_M_FRAC_MASK,
                                                 PLL_FREQ0_R_PLL_M_FRAC_BIT,
                                                 0UL)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(PLL_FREQ1_OFFSET,
                                                 PLL_FREQ1_PLL_N_VALUE_MASK,
                                                 PLL_FREQ1_R_PLL_N_VALUE_BIT,
                                                 0UL)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(PLL_FREQ1_OFFSET,
                                                 PLL_FREQ1_PLL_Q_VALUE_MASK,
                                                 PLL_FREQ1_R_PLL_Q_VALUE_BIT,
                                                 0UL)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_PLL_SRC_MASK,
                                                 RSCLK_CFG_R_PLL_SRC_BIT,
                                                 (UBase_t) SYSCTL_enOSCCLK_SRC_PIOSC)));
    ExpectPll480MHzVCOReads(stMock);
    ExpectMemoryTimingWrites(stMock,
                             SYSCTL_enMEM_HIGHTIME_3_5,
                             SYSCTL_enMEM_WAITSTATE_5,
                             SYSCTL_enMEM_CLOCKEDGE_RISING);
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeReadRegisterAction(PLL_FREQ0_OFFSET,
                                                PLL_FREQ0_PLL_PWR_MASK,
                                                PLL_FREQ0_R_PLL_PWR_BIT,
                                                (UBase_t) SYSCTL_enSTATE_DIS)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(PLL_FREQ0_OFFSET,
                                                 PLL_FREQ0_PLL_PWR_MASK,
                                                 PLL_FREQ0_R_PLL_PWR_BIT,
                                                 (UBase_t) SYSCTL_enSTATE_ENA)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeReadRegisterAction(PLL_STAT_OFFSET,
                                                PLL_STAT_LOCK_MASK,
                                                PLL_STAT_R_LOCK_BIT,
                                                (UBase_t) SYSCTL_enTRUE)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_PLL_SYSDIV_MASK,
                                                 RSCLK_CFG_R_PLL_SYSDIV_BIT,
                                                 3UL)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_MEMTIMU_MASK,
                                                 RSCLK_CFG_R_MEMTIMU_BIT,
                                                 RSCLK_CFG_MEMTIMU_UPDATE)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0,
                                     Truly(IsPLLDivisorReadRequest)))
        .Times(0);
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_USEPLL_MASK,
                                                 RSCLK_CFG_R_USEPLL_BIT,
                                                 (UBase_t) SYSCTL_enSYSCLK_SRC_PLLCLK)));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetSystemClock(SYSCTL_enMODULE_0,
                                       120000000UL,
                                       &stClockConfig,
                                       1UL));
}

/**
 * @brief Validate that the already-enabled PLL path refreshes values without re-enabling PLL power.
 * @summary Confirms that `SYSCTL__enSetSystemClock` still performs the safe PIOSC staging
 *          sequence and PLL parameter programming, then uses the documented
 *          `RSCLKCFG.NEW_PLLFREQ` update path when the PLL is already enabled
 *          instead of writing the PLL power-enable field again.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original sources under test: SYSCTL_SystemClock.c, SYSCTL_GatingClock.c,
 *   SYSCTL_PLLCLock.c, and SYSCTL_MemoryTiming.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-SYSCLK-010@endverbatim
 */
TEST(SYSCTL_SystemClockTest, SetSystemClockPLLRefreshesValuesWhenAlreadyEnabled)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    InSequence stSequence;
    SYSCTL_CONFIG_t stClockConfig;

    stClockConfig.enExternalCrystal = SYSCTL_enXTAL_25MHZ;
    stClockConfig.enOscillatorSource = SYSCTL_enOSCCLK_SRC_PIOSC;
    stClockConfig.enSystemClockSource = SYSCTL_enSYSCLK_SRC_PLLCLK;
    stClockConfig.enVCORange = SYSCTL_enVCO_480MHZ;

    ExpectMemoryTimingWrites(stMock,
                             SYSCTL_enMEM_HIGHTIME_3_5,
                             SYSCTL_enMEM_WAITSTATE_5,
                             SYSCTL_enMEM_CLOCKEDGE_RISING);
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_MEMTIMU_MASK,
                                                 RSCLK_CFG_R_MEMTIMU_BIT,
                                                 RSCLK_CFG_MEMTIMU_UPDATE)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_OSC_SRC_MASK,
                                                 RSCLK_CFG_R_OSC_SRC_BIT,
                                                 (UBase_t) SYSCTL_enOSCCLK_SRC_PIOSC)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_OSC_SYSDIV_MASK,
                                                 RSCLK_CFG_R_OSC_SYSDIV_BIT,
                                                 0UL)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_USEPLL_MASK,
                                                 RSCLK_CFG_R_USEPLL_BIT,
                                                 (UBase_t) SYSCTL_enSYSCLK_SRC_OSCCLK)));
    ExpectMemoryTimingWrites(stMock,
                             SYSCTL_enMEM_HIGHTIME_0_5,
                             SYSCTL_enMEM_WAITSTATE_0,
                             SYSCTL_enMEM_CLOCKEDGE_FAILING);
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_MEMTIMU_MASK,
                                                 RSCLK_CFG_R_MEMTIMU_BIT,
                                                 RSCLK_CFG_MEMTIMU_UPDATE)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(PLL_FREQ0_OFFSET,
                                                 PLL_FREQ0_PLL_M_INT_MASK,
                                                 PLL_FREQ0_R_PLL_M_INT_BIT,
                                                 30UL)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(PLL_FREQ0_OFFSET,
                                                 PLL_FREQ0_PLL_M_FRAC_MASK,
                                                 PLL_FREQ0_R_PLL_M_FRAC_BIT,
                                                 0UL)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(PLL_FREQ1_OFFSET,
                                                 PLL_FREQ1_PLL_N_VALUE_MASK,
                                                 PLL_FREQ1_R_PLL_N_VALUE_BIT,
                                                 0UL)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(PLL_FREQ1_OFFSET,
                                                 PLL_FREQ1_PLL_Q_VALUE_MASK,
                                                 PLL_FREQ1_R_PLL_Q_VALUE_BIT,
                                                 0UL)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_PLL_SRC_MASK,
                                                 RSCLK_CFG_R_PLL_SRC_BIT,
                                                 (UBase_t) SYSCTL_enOSCCLK_SRC_PIOSC)));
    ExpectPll480MHzVCOReads(stMock);
    ExpectMemoryTimingWrites(stMock,
                             SYSCTL_enMEM_HIGHTIME_3_5,
                             SYSCTL_enMEM_WAITSTATE_5,
                             SYSCTL_enMEM_CLOCKEDGE_RISING);
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeReadRegisterAction(PLL_FREQ0_OFFSET,
                                                PLL_FREQ0_PLL_PWR_MASK,
                                                PLL_FREQ0_R_PLL_PWR_BIT,
                                                (UBase_t) SYSCTL_enSTATE_ENA)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_NEW_PLLFREQ_MASK,
                                                 RSCLK_CFG_R_NEW_PLLFREQ_BIT,
                                                 RSCLK_CFG_NEW_PLLFREQ_UPDATE)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeReadRegisterAction(PLL_STAT_OFFSET,
                                                PLL_STAT_LOCK_MASK,
                                                PLL_STAT_R_LOCK_BIT,
                                                (UBase_t) SYSCTL_enTRUE)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_PLL_SYSDIV_MASK,
                                                 RSCLK_CFG_R_PLL_SYSDIV_BIT,
                                                 3UL)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_MEMTIMU_MASK,
                                                 RSCLK_CFG_R_MEMTIMU_BIT,
                                                 RSCLK_CFG_MEMTIMU_UPDATE)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0,
                                     Truly(IsPLLDivisorReadRequest)))
        .Times(0);
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0,
                                      Truly(IsPLLStateWriteRequest)))
        .Times(0);
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_USEPLL_MASK,
                                                 RSCLK_CFG_R_USEPLL_BIT,
                                                 (UBase_t) SYSCTL_enSYSCLK_SRC_PLLCLK)));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetSystemClock(SYSCTL_enMODULE_0,
                                       120000000UL,
                                       &stClockConfig,
                                       1UL));
}

/**
 * @brief Validate timeout handling while waiting for PLL lock after configuration.
 * @summary Confirms that `SYSCTL__enSetSystemClock` completes the safe staging
 *          and PLL parameter programming path for a PIOSC-based PLL request,
 *          enables the PLL when needed, and then returns `SYSCTL_enERROR_TIMEOUT`
 *          when `PLLSTAT.LOCK` never asserts within the caller-provided limit.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original sources under test: SYSCTL_SystemClock.c, SYSCTL_GatingClock.c,
 *   SYSCTL_PLLCLock.c, and SYSCTL_MemoryTiming.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-SYSCLK-011@endverbatim
 */
TEST(SYSCTL_SystemClockTest, SetSystemClockTimesOutWhileWaitingForPLLLock)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    InSequence stSequence;
    SYSCTL_CONFIG_t stClockConfig;

    stClockConfig.enExternalCrystal = SYSCTL_enXTAL_25MHZ;
    stClockConfig.enOscillatorSource = SYSCTL_enOSCCLK_SRC_PIOSC;
    stClockConfig.enSystemClockSource = SYSCTL_enSYSCLK_SRC_PLLCLK;
    stClockConfig.enVCORange = SYSCTL_enVCO_480MHZ;

    ExpectMemoryTimingWrites(stMock,
                             SYSCTL_enMEM_HIGHTIME_3_5,
                             SYSCTL_enMEM_WAITSTATE_5,
                             SYSCTL_enMEM_CLOCKEDGE_RISING);
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_MEMTIMU_MASK,
                                                 RSCLK_CFG_R_MEMTIMU_BIT,
                                                 RSCLK_CFG_MEMTIMU_UPDATE)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_OSC_SRC_MASK,
                                                 RSCLK_CFG_R_OSC_SRC_BIT,
                                                 (UBase_t) SYSCTL_enOSCCLK_SRC_PIOSC)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_OSC_SYSDIV_MASK,
                                                 RSCLK_CFG_R_OSC_SYSDIV_BIT,
                                                 0UL)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_USEPLL_MASK,
                                                 RSCLK_CFG_R_USEPLL_BIT,
                                                 (UBase_t) SYSCTL_enSYSCLK_SRC_OSCCLK)));
    ExpectMemoryTimingWrites(stMock,
                             SYSCTL_enMEM_HIGHTIME_0_5,
                             SYSCTL_enMEM_WAITSTATE_0,
                             SYSCTL_enMEM_CLOCKEDGE_FAILING);
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_MEMTIMU_MASK,
                                                 RSCLK_CFG_R_MEMTIMU_BIT,
                                                 RSCLK_CFG_MEMTIMU_UPDATE)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(PLL_FREQ0_OFFSET,
                                                 PLL_FREQ0_PLL_M_INT_MASK,
                                                 PLL_FREQ0_R_PLL_M_INT_BIT,
                                                 30UL)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(PLL_FREQ0_OFFSET,
                                                 PLL_FREQ0_PLL_M_FRAC_MASK,
                                                 PLL_FREQ0_R_PLL_M_FRAC_BIT,
                                                 0UL)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(PLL_FREQ1_OFFSET,
                                                 PLL_FREQ1_PLL_N_VALUE_MASK,
                                                 PLL_FREQ1_R_PLL_N_VALUE_BIT,
                                                 0UL)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(PLL_FREQ1_OFFSET,
                                                 PLL_FREQ1_PLL_Q_VALUE_MASK,
                                                 PLL_FREQ1_R_PLL_Q_VALUE_BIT,
                                                 0UL)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(RSCLK_CFG_OFFSET,
                                                 RSCLK_CFG_PLL_SRC_MASK,
                                                 RSCLK_CFG_R_PLL_SRC_BIT,
                                                 (UBase_t) SYSCTL_enOSCCLK_SRC_PIOSC)));
    ExpectPll480MHzVCOReads(stMock);
    ExpectMemoryTimingWrites(stMock,
                             SYSCTL_enMEM_HIGHTIME_3_5,
                             SYSCTL_enMEM_WAITSTATE_5,
                             SYSCTL_enMEM_CLOCKEDGE_RISING);
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeReadRegisterAction(PLL_FREQ0_OFFSET,
                                                PLL_FREQ0_PLL_PWR_MASK,
                                                PLL_FREQ0_R_PLL_PWR_BIT,
                                                (UBase_t) SYSCTL_enSTATE_DIS)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(PLL_FREQ0_OFFSET,
                                                 PLL_FREQ0_PLL_PWR_MASK,
                                                 PLL_FREQ0_R_PLL_PWR_BIT,
                                                 (UBase_t) SYSCTL_enSTATE_ENA)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeReadRegisterAction(PLL_STAT_OFFSET,
                                                PLL_STAT_LOCK_MASK,
                                                PLL_STAT_R_LOCK_BIT,
                                                (UBase_t) SYSCTL_enFALSE)));

    EXPECT_EQ(SYSCTL_enERROR_TIMEOUT,
              SYSCTL__enSetSystemClock(SYSCTL_enMODULE_0,
                                       120000000UL,
                                       &stClockConfig,
                                       1UL));
}

/**
 * @brief Validate timeout handling while waiting for MOSC power-up status.
 * @summary Confirms that `SYSCTL__enSetSystemClock` programs the MOSC range,
 *          state, and power state for a MOSC-based request and then returns
 *          `SYSCTL_enERROR_TIMEOUT` when the `RIS.MOSCPUPRIS` status remains
 *          inactive until the caller-provided timeout expires.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - SYSCTL_MCURegisterAccessMock bridge
 * - Original sources under test: SYSCTL_SystemClock.c, SYSCTL_MainOsc.c,
 *   and SYSCTL_InterruptSource.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-SYSCLK-009@endverbatim
 */
TEST(SYSCTL_SystemClockTest, SetSystemClockTimesOutWhileWaitingForMOSCPowerUpStatus)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    StrictMock<SYSCTL_MCURegisterAccessMock> stMCUMock;
    SYSCTL_MCURegisterAccessMockScope stMCUMockScope(&stMCUMock);
    SYSCTL_CONFIG_t stClockConfig;

    stClockConfig.enExternalCrystal = SYSCTL_enXTAL_25MHZ;
    stClockConfig.enOscillatorSource = SYSCTL_enOSCCLK_SRC_MOSC;
    stClockConfig.enSystemClockSource = SYSCTL_enSYSCLK_SRC_OSCCLK;
    stClockConfig.enVCORange = SYSCTL_enVCO_480MHZ;

    ExpectCheckParamsOk(stMCUMock, 3);

    InSequence stSequence;

    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(MOSC_CTL_OFFSET,
                                                 MOSC_CTL_OSCRNG_MASK,
                                                 MOSC_CTL_R_OSCRNG_BIT,
                                                 (UBase_t) SYSCTL_enMOSC_RANGE_HIGH)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(MOSC_CTL_OFFSET,
                                                 MOSC_CTL_NOXTAL_MASK,
                                                 MOSC_CTL_R_NOXTAL_BIT,
                                                 (UBase_t) MOSC_CTL_NOXTAL_CONNECTED)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(MOSC_CTL_OFFSET,
                                                 MOSC_CTL_PWRDN_MASK,
                                                 MOSC_CTL_R_PWRDN_BIT,
                                                 (UBase_t) MOSC_CTL_PWRDN_POWERUP)));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeReadRegisterAction(SYSCTL_RIS_OFFSET,
                                                SYSCTL_RIS_BOR_MASK,
                                                SYSCTL_RIS_R_MOSC_POWERUP_BIT,
                                                (UBase_t) SYSCTL_enSTATUS_INACTIVE)));

    EXPECT_EQ(SYSCTL_enERROR_TIMEOUT,
              SYSCTL__enSetSystemClock(SYSCTL_enMODULE_0,
                                       25000000UL,
                                       &stClockConfig,
                                       1UL));
}