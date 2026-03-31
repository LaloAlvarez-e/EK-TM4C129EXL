/**
 *
 * @file SYSCTL_DeepSleepGatingClock_Test.cpp
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
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_DeepSleepGatingClock.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_DSCLKCFG.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/xHeader/SYSCTL_RegisterAddress.h>
}

#include <tm4c129e_test/SYSCTL_PrimitivesMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Invoke;
using ::testing::Return;
using ::testing::StrictMock;

/**
 * @brief Validate the disabled-state encoding in the deep-sleep PIOSC setter.
 * @summary Confirms that `SYSCTL__enSetPIOSCStateOnDeepSleep` maps the public
 *          disabled state to the documented `DSCLKCFG.PIOSCPD` field encoding.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_DeepSleepGatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-DSCLKCFG-001@endverbatim
 */
TEST(SYSCTL_DeepSleepGatingClockTest, SetPIOSCStateOnDeepSleepUsesDisabledFieldEncoding)
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
            EXPECT_EQ((uintptr_t) DSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) DSCLK_CFG_PIOSC_PD_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) DSCLK_CFG_R_PIOSC_PD_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) DSCLK_CFG_PIOSC_PD_DIS, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetPIOSCStateOnDeepSleep(SYSCTL_enMODULE_0, SYSCTL_enSTATE_DIS));
}

/**
 * @brief Validate the enabled-state encoding in the deep-sleep PIOSC setter.
 * @summary Confirms that `SYSCTL__enSetPIOSCStateOnDeepSleep` maps the public
 *          enabled state to the documented `DSCLKCFG.PIOSCPD` field encoding.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_DeepSleepGatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-DSCLKCFG-002@endverbatim
 */
TEST(SYSCTL_DeepSleepGatingClockTest, SetPIOSCStateOnDeepSleepUsesEnabledFieldEncoding)
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
            EXPECT_EQ((uintptr_t) DSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) DSCLK_CFG_PIOSC_PD_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) DSCLK_CFG_R_PIOSC_PD_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) DSCLK_CFG_PIOSC_PD_ENA, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetPIOSCStateOnDeepSleep(SYSCTL_enMODULE_0, SYSCTL_enSTATE_ENA));
}

/**
 * @brief Validate null-pointer rejection in the deep-sleep PIOSC getter.
 * @summary Confirms that `SYSCTL__enGetPIOSCStateOnDeepSleep` rejects a null
 *          output pointer before attempting primitive register access.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_DeepSleepGatingClock.c
 * - Public API parameter validation path@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-DSCLKCFG-003@endverbatim
 */
TEST(SYSCTL_DeepSleepGatingClockTest, GetPIOSCStateOnDeepSleepRejectsNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetPIOSCStateOnDeepSleep(SYSCTL_enMODULE_0, (SYSCTL_nSTATE*) 0UL));
}

/**
 * @brief Validate enabled-field decoding in the deep-sleep PIOSC getter.
 * @summary Confirms that `SYSCTL__enGetPIOSCStateOnDeepSleep` decodes the
 *          documented enabled `DSCLKCFG.PIOSCPD` value into the public enabled state.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_DeepSleepGatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-DSCLKCFG-004@endverbatim
 */
TEST(SYSCTL_DeepSleepGatingClockTest, GetPIOSCStateOnDeepSleepMapsEnabledFieldEncoding)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nSTATE enStateReg;

    enStateReg = SYSCTL_enSTATE_UNDEF;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) DSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) DSCLK_CFG_PIOSC_PD_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) DSCLK_CFG_R_PIOSC_PD_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) DSCLK_CFG_PIOSC_PD_ENA;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetPIOSCStateOnDeepSleep(SYSCTL_enMODULE_0, &enStateReg));
    EXPECT_EQ(SYSCTL_enSTATE_ENA, enStateReg);
}

/**
 * @brief Validate disabled-field decoding in the deep-sleep PIOSC getter.
 * @summary Confirms that `SYSCTL__enGetPIOSCStateOnDeepSleep` decodes the
 *          documented disabled `DSCLKCFG.PIOSCPD` value into the public disabled state.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_DeepSleepGatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-DSCLKCFG-005@endverbatim
 */
TEST(SYSCTL_DeepSleepGatingClockTest, GetPIOSCStateOnDeepSleepMapsDisabledFieldEncoding)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nSTATE enStateReg;

    enStateReg = SYSCTL_enSTATE_UNDEF;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) DSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) DSCLK_CFG_PIOSC_PD_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) DSCLK_CFG_R_PIOSC_PD_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) DSCLK_CFG_PIOSC_PD_DIS;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetPIOSCStateOnDeepSleep(SYSCTL_enMODULE_0, &enStateReg));
    EXPECT_EQ(SYSCTL_enSTATE_DIS, enStateReg);
}

/**
 * @brief Validate read-error propagation in the deep-sleep PIOSC getter.
 * @summary Confirms that `SYSCTL__enGetPIOSCStateOnDeepSleep` returns the primitive
 *          read error unchanged and preserves caller state when the read path fails.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_DeepSleepGatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-DSCLKCFG-006@endverbatim
 */
TEST(SYSCTL_DeepSleepGatingClockTest, GetPIOSCStateOnDeepSleepPropagatesReadError)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nSTATE enStateReg;

    enStateReg = SYSCTL_enSTATE_ENA;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enGetPIOSCStateOnDeepSleep(SYSCTL_enMODULE_0, &enStateReg));
    EXPECT_EQ(SYSCTL_enSTATE_ENA, enStateReg);
}

/**
 * @brief Validate MOSCDPD-field programming in the MOSC-failure deep-sleep setter.
 * @summary Confirms that `SYSCTL__enAllowDisableMOSCOnFailure` writes the documented
 *          `DSCLKCFG.MOSCDPD` field using the caller-provided boolean state.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_DeepSleepGatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-DSCLKCFG-007@endverbatim
 */
TEST(SYSCTL_DeepSleepGatingClockTest, AllowDisableMOSCOnFailureUsesExpectedField)
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
            EXPECT_EQ((uintptr_t) DSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) DSCLK_CFG_MOSC_DPD_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) DSCLK_CFG_R_MOSC_DPD_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) SYSCTL_enTRUE, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enAllowDisableMOSCOnFailure(SYSCTL_enMODULE_0, SYSCTL_enTRUE));
}

/**
 * @brief Validate null-pointer rejection in the MOSC-failure deep-sleep getter.
 * @summary Confirms that `SYSCTL__enIsAllowedDisableMOSCOnFailure` rejects a null
 *          output pointer before attempting primitive register access.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_DeepSleepGatingClock.c
 * - Public API parameter validation path@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-DSCLKCFG-008@endverbatim
 */
TEST(SYSCTL_DeepSleepGatingClockTest, IsAllowedDisableMOSCOnFailureRejectsNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enIsAllowedDisableMOSCOnFailure(SYSCTL_enMODULE_0, (SYSCTL_nBOOLEAN*) 0UL));
}

/**
 * @brief Validate MOSCDPD-field reads in the MOSC-failure deep-sleep getter.
 * @summary Confirms that `SYSCTL__enIsAllowedDisableMOSCOnFailure` reads the
 *          documented `DSCLKCFG.MOSCDPD` field and returns the boolean value unchanged.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_DeepSleepGatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-DSCLKCFG-009@endverbatim
 */
TEST(SYSCTL_DeepSleepGatingClockTest, IsAllowedDisableMOSCOnFailureUsesExpectedField)
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
            EXPECT_EQ((uintptr_t) DSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) DSCLK_CFG_MOSC_DPD_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) DSCLK_CFG_R_MOSC_DPD_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) SYSCTL_enTRUE;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enIsAllowedDisableMOSCOnFailure(SYSCTL_enMODULE_0, &enStateReg));
    EXPECT_EQ(SYSCTL_enTRUE, enStateReg);
}

/**
 * @brief Validate read-error propagation in the MOSC-failure deep-sleep getter.
 * @summary Confirms that `SYSCTL__enIsAllowedDisableMOSCOnFailure` returns the
 *          primitive read error unchanged and preserves caller state when the
 *          read path fails.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_DeepSleepGatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-DSCLKCFG-010@endverbatim
 */
TEST(SYSCTL_DeepSleepGatingClockTest, IsAllowedDisableMOSCOnFailurePropagatesReadError)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nBOOLEAN enStateReg;

    enStateReg = SYSCTL_enTRUE;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE,
              SYSCTL__enIsAllowedDisableMOSCOnFailure(SYSCTL_enMODULE_0, &enStateReg));
    EXPECT_EQ(SYSCTL_enTRUE, enStateReg);
}

/**
 * @brief Validate DSOSCSRC-field programming in the deep-sleep oscillator-source setter.
 * @summary Confirms that `SYSCTL__enSetDeepSleepOscillatorClockSource` writes the
 *          documented `DSCLKCFG.DSOSCSRC` field using the public oscillator-source enum.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_DeepSleepGatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-DSCLKCFG-011@endverbatim
 */
TEST(SYSCTL_DeepSleepGatingClockTest, SetDeepSleepOscillatorClockSourceUsesExpectedField)
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
            EXPECT_EQ((uintptr_t) DSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) DSCLK_CFG_DEEPSLEEP_OSC_SRC_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) DSCLK_CFG_R_DEEPSLEEP_OSC_SRC_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) SYSCTL_enOSCCLK_SRC_MOSC, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetDeepSleepOscillatorClockSource(SYSCTL_enMODULE_0, SYSCTL_enOSCCLK_SRC_MOSC));
}

/**
 * @brief Validate null-pointer rejection in the deep-sleep oscillator-source getter.
 * @summary Confirms that `SYSCTL__enGetDeepSleepOscillatorClockSource` rejects a null
 *          output pointer before attempting primitive register access.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_DeepSleepGatingClock.c
 * - Public API parameter validation path@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-DSCLKCFG-012@endverbatim
 */
TEST(SYSCTL_DeepSleepGatingClockTest, GetDeepSleepOscillatorClockSourceRejectsNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetDeepSleepOscillatorClockSource(SYSCTL_enMODULE_0, (SYSCTL_nOSCCLK_SRC*) 0UL));
}

/**
 * @brief Validate DSOSCSRC-field reads in the deep-sleep oscillator-source getter.
 * @summary Confirms that `SYSCTL__enGetDeepSleepOscillatorClockSource` reads the
 *          documented `DSCLKCFG.DSOSCSRC` field and returns the public oscillator-source enum.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_DeepSleepGatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-DSCLKCFG-013@endverbatim
 */
TEST(SYSCTL_DeepSleepGatingClockTest, GetDeepSleepOscillatorClockSourceUsesExpectedField)
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
            EXPECT_EQ((uintptr_t) DSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) DSCLK_CFG_DEEPSLEEP_OSC_SRC_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) DSCLK_CFG_R_DEEPSLEEP_OSC_SRC_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) SYSCTL_enOSCCLK_SRC_RTCOSC;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enGetDeepSleepOscillatorClockSource(SYSCTL_enMODULE_0, &enSourceReg));
    EXPECT_EQ(SYSCTL_enOSCCLK_SRC_RTCOSC, enSourceReg);
}

/**
 * @brief Validate read-error propagation in the deep-sleep oscillator-source getter.
 * @summary Confirms that `SYSCTL__enGetDeepSleepOscillatorClockSource` returns the
 *          primitive read error unchanged and preserves caller state when the
 *          read path fails.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_DeepSleepGatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-DSCLKCFG-014@endverbatim
 */
TEST(SYSCTL_DeepSleepGatingClockTest, GetDeepSleepOscillatorClockSourcePropagatesReadError)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nOSCCLK_SRC enSourceReg;

    enSourceReg = SYSCTL_enOSCCLK_SRC_MOSC;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE,
              SYSCTL__enGetDeepSleepOscillatorClockSource(SYSCTL_enMODULE_0, &enSourceReg));
    EXPECT_EQ(SYSCTL_enOSCCLK_SRC_MOSC, enSourceReg);
}

/**
 * @brief Validate DSSYSDIV-field programming in the deep-sleep oscillator-divisor setter.
 * @summary Confirms that `SYSCTL__enSetDeepSleepOscillatorClockDivisor` writes the
 *          documented `DSCLKCFG.DSSYSDIV` field using the caller-provided divisor.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_DeepSleepGatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-DSCLKCFG-015@endverbatim
 */
TEST(SYSCTL_DeepSleepGatingClockTest, SetDeepSleepOscillatorClockDivisorUsesExpectedField)
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
            EXPECT_EQ((uintptr_t) DSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) DSCLK_CFG_DEEPSLEEP_OSC_SYSDIV_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) DSCLK_CFG_R_DEEPSLEEP_OSC_SYSDIV_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) 0x12UL, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetDeepSleepOscillatorClockDivisor(SYSCTL_enMODULE_0, (UBase_t) 0x12UL));
}

/**
 * @brief Validate null-pointer rejection in the deep-sleep oscillator-divisor getter.
 * @summary Confirms that `SYSCTL__enGetDeepSleepOscillatorClockDivisor` rejects a null
 *          output pointer before attempting primitive register access.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_DeepSleepGatingClock.c
 * - Public API parameter validation path@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-DSCLKCFG-016@endverbatim
 */
TEST(SYSCTL_DeepSleepGatingClockTest, GetDeepSleepOscillatorClockDivisorRejectsNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetDeepSleepOscillatorClockDivisor(SYSCTL_enMODULE_0, (UBase_t*) 0UL));
}

/**
 * @brief Validate DSSYSDIV-field reads in the deep-sleep oscillator-divisor getter.
 * @summary Confirms that `SYSCTL__enGetDeepSleepOscillatorClockDivisor` reads the
 *          documented `DSCLKCFG.DSSYSDIV` field and returns the divisor unchanged.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_DeepSleepGatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-DSCLKCFG-017@endverbatim
 */
TEST(SYSCTL_DeepSleepGatingClockTest, GetDeepSleepOscillatorClockDivisorUsesExpectedField)
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
            EXPECT_EQ((uintptr_t) DSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) DSCLK_CFG_DEEPSLEEP_OSC_SYSDIV_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) DSCLK_CFG_R_DEEPSLEEP_OSC_SYSDIV_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) 0x21UL;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enGetDeepSleepOscillatorClockDivisor(SYSCTL_enMODULE_0, &uxDivisorReg));
    EXPECT_EQ((UBase_t) 0x21UL, uxDivisorReg);
}

/**
 * @brief Validate read-error propagation in the deep-sleep oscillator-divisor getter.
 * @summary Confirms that `SYSCTL__enGetDeepSleepOscillatorClockDivisor` returns the
 *          primitive read error unchanged and preserves caller state when the
 *          read path fails.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_DeepSleepGatingClock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-DSCLKCFG-018@endverbatim
 */
TEST(SYSCTL_DeepSleepGatingClockTest, GetDeepSleepOscillatorClockDivisorPropagatesReadError)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    UBase_t uxDivisorReg;

    uxDivisorReg = (UBase_t) 0x44UL;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE,
              SYSCTL__enGetDeepSleepOscillatorClockDivisor(SYSCTL_enMODULE_0, &uxDivisorReg));
    EXPECT_EQ((UBase_t) 0x44UL, uxDivisorReg);
}