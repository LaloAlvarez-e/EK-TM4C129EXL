/**
 *
 * @file SYSCTL_GatingClock_Test.cpp
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
 * @verbatim 31 mar. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 31 mar. 2026   GitHub Copilot   1.0         initial Version@endverbatim
 */

extern "C"
{
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_GatingClock.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_RSCLKCFG.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/xHeader/SYSCTL_RegisterAddress.h>
}

#include <tm4c129e_test/SYSCTL_PrimitivesMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Invoke;
using ::testing::Return;
using ::testing::StrictMock;

/**
 * @brief Validate MEMTIMU update-field programming in the memory-timing updater.
 * @summary Confirms that `SYSCTL__enUpdateMemoryTiming` writes the documented
 *          `RSCLKCFG.MEMTIMU` field with the update command through the primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_GatingClock.c
 * - SYSCTL RSCLKCFG register definitions@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RSCLKCFG-001@endverbatim
 */
TEST(SYSCTL_GatingClockTest, UpdateMemoryTimingUsesExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) RSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) RSCLK_CFG_MEMTIMU_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) RSCLK_CFG_R_MEMTIMU_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) RSCLK_CFG_MEMTIMU_UPDATE, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enUpdateMemoryTiming(SYSCTL_enMODULE_0));
}

/**
 * @brief Validate NEW_PLLFREQ update-field programming in the PLL-value updater.
 * @summary Confirms that `SYSCTL__enUpdatePLLValues` writes the documented
 *          `RSCLKCFG.NEWFREQ` update field through the primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_GatingClock.c
 * - SYSCTL RSCLKCFG register definitions@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RSCLKCFG-002@endverbatim
 */
TEST(SYSCTL_GatingClockTest, UpdatePLLValuesUsesExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) RSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) RSCLK_CFG_NEW_PLLFREQ_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) RSCLK_CFG_R_NEW_PLLFREQ_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) RSCLK_CFG_NEW_PLLFREQ_UPDATE, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enUpdatePLLValues(SYSCTL_enMODULE_0));
}

/**
 * @brief Validate ACG-field programming in the sleep-mode gating selector.
 * @summary Confirms that `SYSCTL__enAllowChangeToSleepMode` writes the documented
 *          `RSCLKCFG.ACG` field using the caller-provided boolean state.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_GatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RSCLKCFG-003@endverbatim
 */
TEST(SYSCTL_GatingClockTest, AllowChangeToSleepModeUsesExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) RSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) RSCLK_CFG_ACG_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) RSCLK_CFG_R_ACG_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) SYSCTL_enTRUE, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enAllowChangeToSleepMode(SYSCTL_enMODULE_0, SYSCTL_enTRUE));
}

/**
 * @brief Validate null-pointer rejection in the sleep-mode gating selector getter.
 * @summary Confirms that `SYSCTL__enIsAllowedChangeToSleepMode` rejects a null
 *          output pointer before attempting primitive register access.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_GatingClock.c
 * - Public API parameter validation path@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RSCLKCFG-004@endverbatim
 */
TEST(SYSCTL_GatingClockTest, IsAllowedChangeToSleepModeRejectsNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enIsAllowedChangeToSleepMode(SYSCTL_enMODULE_0, (SYSCTL_nBOOLEAN*) 0UL));
}

/**
 * @brief Validate ACG-field reads in the sleep-mode gating selector getter.
 * @summary Confirms that `SYSCTL__enIsAllowedChangeToSleepMode` reads the
 *          documented `RSCLKCFG.ACG` field and returns the boolean value unchanged.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_GatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RSCLKCFG-005@endverbatim
 */
TEST(SYSCTL_GatingClockTest, IsAllowedChangeToSleepModeUsesExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nBOOLEAN enStateReg;

    enStateReg = SYSCTL_enFALSE;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) RSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) RSCLK_CFG_ACG_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) RSCLK_CFG_R_ACG_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) SYSCTL_enTRUE;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enIsAllowedChangeToSleepMode(SYSCTL_enMODULE_0, &enStateReg));
    EXPECT_EQ(SYSCTL_enTRUE, enStateReg);
}

/**
 * @brief Validate read-error propagation in the sleep-mode gating selector getter.
 * @summary Confirms that `SYSCTL__enIsAllowedChangeToSleepMode` returns the
 *          primitive read error unchanged and preserves caller state when the
 *          read path fails.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_GatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RSCLKCFG-006@endverbatim
 */
TEST(SYSCTL_GatingClockTest, IsAllowedChangeToSleepModePropagatesReadError)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nBOOLEAN enStateReg;

    enStateReg = SYSCTL_enTRUE;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enIsAllowedChangeToSleepMode(SYSCTL_enMODULE_0, &enStateReg));
    EXPECT_EQ(SYSCTL_enTRUE, enStateReg);
}

/**
 * @brief Validate USEPLL-field programming in the system-clock source setter.
 * @summary Confirms that `SYSCTL__enSetSystemClockSource` writes the documented
 *          `RSCLKCFG.USEPLL` field using the public system-clock source enum.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_GatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RSCLKCFG-007@endverbatim
 */
TEST(SYSCTL_GatingClockTest, SetSystemClockSourceUsesExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) RSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) RSCLK_CFG_USEPLL_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) RSCLK_CFG_R_USEPLL_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) SYSCTL_enSYSCLK_SRC_PLLCLK, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetSystemClockSource(SYSCTL_enMODULE_0, SYSCTL_enSYSCLK_SRC_PLLCLK));
}

/**
 * @brief Validate null-pointer rejection in the system-clock source getter.
 * @summary Confirms that `SYSCTL__enGetSystemClockSource` rejects a null output
 *          pointer before attempting primitive register access.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_GatingClock.c
 * - Public API parameter validation path@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RSCLKCFG-008@endverbatim
 */
TEST(SYSCTL_GatingClockTest, GetSystemClockSourceRejectsNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetSystemClockSource(SYSCTL_enMODULE_0, (SYSCTL_nSYSCLK_SRC*) 0UL));
}

/**
 * @brief Validate USEPLL-field reads in the system-clock source getter.
 * @summary Confirms that `SYSCTL__enGetSystemClockSource` reads the documented
 *          `RSCLKCFG.USEPLL` field and returns the public system-clock source enum.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_GatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RSCLKCFG-009@endverbatim
 */
TEST(SYSCTL_GatingClockTest, GetSystemClockSourceUsesExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nSYSCLK_SRC enSourceReg;

    enSourceReg = SYSCTL_enSYSCLK_SRC_UNDEF;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) RSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) RSCLK_CFG_USEPLL_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) RSCLK_CFG_R_USEPLL_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) SYSCTL_enSYSCLK_SRC_OSCCLK;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetSystemClockSource(SYSCTL_enMODULE_0, &enSourceReg));
    EXPECT_EQ(SYSCTL_enSYSCLK_SRC_OSCCLK, enSourceReg);
}

/**
 * @brief Validate read-error propagation in the system-clock source getter.
 * @summary Confirms that `SYSCTL__enGetSystemClockSource` returns the primitive
 *          read error unchanged and preserves caller state when the read path fails.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_GatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RSCLKCFG-010@endverbatim
 */
TEST(SYSCTL_GatingClockTest, GetSystemClockSourcePropagatesReadError)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nSYSCLK_SRC enSourceReg;

    enSourceReg = SYSCTL_enSYSCLK_SRC_PLLCLK;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enGetSystemClockSource(SYSCTL_enMODULE_0, &enSourceReg));
    EXPECT_EQ(SYSCTL_enSYSCLK_SRC_PLLCLK, enSourceReg);
}

/**
 * @brief Validate PLLSRC-field programming in the PLL-clock source setter.
 * @summary Confirms that `SYSCTL__enSetPLLClockSource` writes the documented
 *          `RSCLKCFG.PLLSRC` field using the public oscillator-source enum.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_GatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RSCLKCFG-011@endverbatim
 */
TEST(SYSCTL_GatingClockTest, SetPLLClockSourceUsesExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) RSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) RSCLK_CFG_PLL_SRC_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) RSCLK_CFG_R_PLL_SRC_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) SYSCTL_enOSCCLK_SRC_MOSC, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetPLLClockSource(SYSCTL_enMODULE_0, SYSCTL_enOSCCLK_SRC_MOSC));
}

/**
 * @brief Validate null-pointer rejection in the PLL-clock source getter.
 * @summary Confirms that `SYSCTL__enGetPLLClockSource` rejects a null output
 *          pointer before attempting primitive register access.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_GatingClock.c
 * - Public API parameter validation path@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RSCLKCFG-012@endverbatim
 */
TEST(SYSCTL_GatingClockTest, GetPLLClockSourceRejectsNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetPLLClockSource(SYSCTL_enMODULE_0, (SYSCTL_nOSCCLK_SRC*) 0UL));
}

/**
 * @brief Validate PLLSRC-field reads in the PLL-clock source getter.
 * @summary Confirms that `SYSCTL__enGetPLLClockSource` reads the documented
 *          `RSCLKCFG.PLLSRC` field and returns the public oscillator-source enum.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_GatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RSCLKCFG-013@endverbatim
 */
TEST(SYSCTL_GatingClockTest, GetPLLClockSourceUsesExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nOSCCLK_SRC enSourceReg;

    enSourceReg = SYSCTL_enOSCCLK_SRC_UNDEF;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) RSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) RSCLK_CFG_PLL_SRC_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) RSCLK_CFG_R_PLL_SRC_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) SYSCTL_enOSCCLK_SRC_PIOSC;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetPLLClockSource(SYSCTL_enMODULE_0, &enSourceReg));
    EXPECT_EQ(SYSCTL_enOSCCLK_SRC_PIOSC, enSourceReg);
}

/**
 * @brief Validate read-error propagation in the PLL-clock source getter.
 * @summary Confirms that `SYSCTL__enGetPLLClockSource` returns the primitive read
 *          error unchanged and preserves caller state when the read path fails.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_GatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RSCLKCFG-014@endverbatim
 */
TEST(SYSCTL_GatingClockTest, GetPLLClockSourcePropagatesReadError)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nOSCCLK_SRC enSourceReg;

    enSourceReg = SYSCTL_enOSCCLK_SRC_MOSC;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enGetPLLClockSource(SYSCTL_enMODULE_0, &enSourceReg));
    EXPECT_EQ(SYSCTL_enOSCCLK_SRC_MOSC, enSourceReg);
}

/**
 * @brief Validate OSCSRC-field programming in the oscillator-clock source setter.
 * @summary Confirms that `SYSCTL__enSetOscillatorClockSource` writes the documented
 *          `RSCLKCFG.OSCSRC` field using the public oscillator-source enum.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_GatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RSCLKCFG-015@endverbatim
 */
TEST(SYSCTL_GatingClockTest, SetOscillatorClockSourceUsesExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) RSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) RSCLK_CFG_OSC_SRC_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) RSCLK_CFG_R_OSC_SRC_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) SYSCTL_enOSCCLK_SRC_RTCOSC, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetOscillatorClockSource(SYSCTL_enMODULE_0, SYSCTL_enOSCCLK_SRC_RTCOSC));
}

/**
 * @brief Validate null-pointer rejection in the oscillator-clock source getter.
 * @summary Confirms that `SYSCTL__enGetOscillatorClockSource` rejects a null
 *          output pointer before attempting primitive register access.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_GatingClock.c
 * - Public API parameter validation path@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RSCLKCFG-016@endverbatim
 */
TEST(SYSCTL_GatingClockTest, GetOscillatorClockSourceRejectsNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetOscillatorClockSource(SYSCTL_enMODULE_0, (SYSCTL_nOSCCLK_SRC*) 0UL));
}

/**
 * @brief Validate OSCSRC-field reads in the oscillator-clock source getter.
 * @summary Confirms that `SYSCTL__enGetOscillatorClockSource` reads the documented
 *          `RSCLKCFG.OSCSRC` field and returns the public oscillator-source enum.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_GatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RSCLKCFG-017@endverbatim
 */
TEST(SYSCTL_GatingClockTest, GetOscillatorClockSourceUsesExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nOSCCLK_SRC enSourceReg;

    enSourceReg = SYSCTL_enOSCCLK_SRC_UNDEF;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) RSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) RSCLK_CFG_OSC_SRC_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) RSCLK_CFG_R_OSC_SRC_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) SYSCTL_enOSCCLK_SRC_LFIOSC;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetOscillatorClockSource(SYSCTL_enMODULE_0, &enSourceReg));
    EXPECT_EQ(SYSCTL_enOSCCLK_SRC_LFIOSC, enSourceReg);
}

/**
 * @brief Validate read-error propagation in the oscillator-clock source getter.
 * @summary Confirms that `SYSCTL__enGetOscillatorClockSource` returns the primitive
 *          read error unchanged and preserves caller state when the read path fails.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_GatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RSCLKCFG-018@endverbatim
 */
TEST(SYSCTL_GatingClockTest, GetOscillatorClockSourcePropagatesReadError)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nOSCCLK_SRC enSourceReg;

    enSourceReg = SYSCTL_enOSCCLK_SRC_RTCOSC;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enGetOscillatorClockSource(SYSCTL_enMODULE_0, &enSourceReg));
    EXPECT_EQ(SYSCTL_enOSCCLK_SRC_RTCOSC, enSourceReg);
}

/**
 * @brief Validate OSYSDIV-field programming in the oscillator-clock divisor setter.
 * @summary Confirms that `SYSCTL__enSetOscillatorClockDivisor` writes the documented
 *          `RSCLKCFG.OSYSDIV` field using the caller-provided divisor value.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_GatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RSCLKCFG-019@endverbatim
 */
TEST(SYSCTL_GatingClockTest, SetOscillatorClockDivisorUsesExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) RSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) RSCLK_CFG_OSC_SYSDIV_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) RSCLK_CFG_R_OSC_SYSDIV_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) 0x55UL, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enSetOscillatorClockDivisor(SYSCTL_enMODULE_0, (UBase_t) 0x55UL));
}

/**
 * @brief Validate null-pointer rejection in the oscillator-clock divisor getter.
 * @summary Confirms that `SYSCTL__enGetOscillatorClockDivisor` rejects a null
 *          output pointer before attempting primitive register access.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_GatingClock.c
 * - Public API parameter validation path@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RSCLKCFG-020@endverbatim
 */
TEST(SYSCTL_GatingClockTest, GetOscillatorClockDivisorRejectsNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetOscillatorClockDivisor(SYSCTL_enMODULE_0, (UBase_t*) 0UL));
}

/**
 * @brief Validate OSYSDIV-field reads in the oscillator-clock divisor getter.
 * @summary Confirms that `SYSCTL__enGetOscillatorClockDivisor` reads the documented
 *          `RSCLKCFG.OSYSDIV` field and returns the divisor value unchanged.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_GatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RSCLKCFG-021@endverbatim
 */
TEST(SYSCTL_GatingClockTest, GetOscillatorClockDivisorUsesExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    UBase_t uxDivisorReg;

    uxDivisorReg = 0UL;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) RSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) RSCLK_CFG_OSC_SYSDIV_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) RSCLK_CFG_R_OSC_SYSDIV_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) 0xAAUL;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetOscillatorClockDivisor(SYSCTL_enMODULE_0, &uxDivisorReg));
    EXPECT_EQ((UBase_t) 0xAAUL, uxDivisorReg);
}

/**
 * @brief Validate read-error propagation in the oscillator-clock divisor getter.
 * @summary Confirms that `SYSCTL__enGetOscillatorClockDivisor` returns the primitive
 *          read error unchanged and preserves caller state when the read path fails.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_GatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RSCLKCFG-022@endverbatim
 */
TEST(SYSCTL_GatingClockTest, GetOscillatorClockDivisorPropagatesReadError)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    UBase_t uxDivisorReg;

    uxDivisorReg = (UBase_t) 0x11UL;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enGetOscillatorClockDivisor(SYSCTL_enMODULE_0, &uxDivisorReg));
    EXPECT_EQ((UBase_t) 0x11UL, uxDivisorReg);
}

/**
 * @brief Validate PSYSDIV-field programming in the PLL-clock divisor setter.
 * @summary Confirms that `SYSCTL__enSetPLLClockDivisor` writes the documented
 *          `RSCLKCFG.PSYSDIV` field using the caller-provided divisor value.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_GatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RSCLKCFG-023@endverbatim
 */
TEST(SYSCTL_GatingClockTest, SetPLLClockDivisorUsesExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) RSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) RSCLK_CFG_PLL_SYSDIV_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) RSCLK_CFG_R_PLL_SYSDIV_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) 0x33UL, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enSetPLLClockDivisor(SYSCTL_enMODULE_0, (UBase_t) 0x33UL));
}

/**
 * @brief Validate null-pointer rejection in the PLL-clock divisor getter.
 * @summary Confirms that `SYSCTL__enGetPLLClockDivisor` rejects a null output
 *          pointer before attempting primitive register access.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_GatingClock.c
 * - Public API parameter validation path@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RSCLKCFG-024@endverbatim
 */
TEST(SYSCTL_GatingClockTest, GetPLLClockDivisorRejectsNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetPLLClockDivisor(SYSCTL_enMODULE_0, (UBase_t*) 0UL));
}

/**
 * @brief Validate PSYSDIV-field reads in the PLL-clock divisor getter.
 * @summary Confirms that `SYSCTL__enGetPLLClockDivisor` reads the documented
 *          `RSCLKCFG.PSYSDIV` field and returns the divisor value unchanged.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_GatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RSCLKCFG-025@endverbatim
 */
TEST(SYSCTL_GatingClockTest, GetPLLClockDivisorUsesExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    UBase_t uxDivisorReg;

    uxDivisorReg = 0UL;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) RSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) RSCLK_CFG_PLL_SYSDIV_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) RSCLK_CFG_R_PLL_SYSDIV_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) 0x66UL;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetPLLClockDivisor(SYSCTL_enMODULE_0, &uxDivisorReg));
    EXPECT_EQ((UBase_t) 0x66UL, uxDivisorReg);
}

/**
 * @brief Validate read-error propagation in the PLL-clock divisor getter.
 * @summary Confirms that `SYSCTL__enGetPLLClockDivisor` returns the primitive
 *          read error unchanged and preserves caller state when the read path fails.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_GatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RSCLKCFG-026@endverbatim
 */
TEST(SYSCTL_GatingClockTest, GetPLLClockDivisorPropagatesReadError)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    UBase_t uxDivisorReg;

    uxDivisorReg = (UBase_t) 0x22UL;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enGetPLLClockDivisor(SYSCTL_enMODULE_0, &uxDivisorReg));
    EXPECT_EQ((UBase_t) 0x22UL, uxDivisorReg);
}