/**
 *
 * @file SYSCTL_Ready_Test.cpp
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
 * @verbatim 4 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 4 abr. 2026    GitHub Copilot   1.0         initial Version@endverbatim
 */

extern "C"
{
#include <xDriver_MCU/SYSCTL/App/xHeader/SYSCTL_Ready.h>
}

#include <tm4c129e_test/SYSCTL_ReadyDriverMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::InSequence;
using ::testing::Invoke;
using ::testing::Return;
using ::testing::StrictMock;

/**
 * @brief Validate ready-query error propagation in the run-mode ready setter.
 * @summary Confirms that `SYSCTL__enSetReadyOnRunMode` returns the underlying
 *          peripheral-ready query error and exits before any run-mode enable or
 *          reset operations occur.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_ReadyDriverMock bridge
 * - Original source under test: SYSCTL_Ready.c@endverbatim
 */
TEST(SYSCTL_ReadyTest, SetReadyOnRunModePropagatesReadyQueryError)
{
    StrictMock<SYSCTL_ReadyDriverMock> stMock;
    SYSCTL_ReadyDriverMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, IsPeripheralReady(SYSCTL_enMODULE_0, SYSCTL_enGPIOA, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_RANGE));

    EXPECT_EQ(SYSCTL_enERROR_RANGE,
              SYSCTL__enSetReadyOnRunMode(SYSCTL_enMODULE_0, SYSCTL_enGPIOA));
}

/**
 * @brief Validate ordered run-mode ready setup when the peripheral is not ready.
 * @summary Confirms that `SYSCTL__enSetReadyOnRunMode` queries readiness,
 *          enables run mode for a not-ready peripheral, and then asserts the
 *          peripheral reset in that order.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_ReadyDriverMock bridge
 * - Original source under test: SYSCTL_Ready.c@endverbatim
 */
TEST(SYSCTL_ReadyTest, SetReadyOnRunModeEnablesRunModeThenResets)
{
    StrictMock<SYSCTL_ReadyDriverMock> stMock;
    SYSCTL_ReadyDriverMockScope stMockScope(&stMock);
    InSequence stSequence;

    EXPECT_CALL(stMock, IsPeripheralReady(SYSCTL_enMODULE_0, SYSCTL_enUART3, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE, SYSCTL_nPERIPHERAL, SYSCTL_nBOOLEAN* penReadyArg) -> SYSCTL_nERROR
        {
            if(nullptr != penReadyArg)
            {
                *penReadyArg = SYSCTL_enFALSE;
            }
            return SYSCTL_enERROR_OK;
        }));
    EXPECT_CALL(stMock, EnableRunMode(SYSCTL_enMODULE_0, SYSCTL_enUART3))
        .WillOnce(Return(SYSCTL_enERROR_OK));
    EXPECT_CALL(stMock, SetPeripheralReset(SYSCTL_enMODULE_0, SYSCTL_enUART3))
        .WillOnce(Return(SYSCTL_enERROR_OK));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetReadyOnRunMode(SYSCTL_enMODULE_0, SYSCTL_enUART3));
}

/**
 * @brief Validate ordered run-mode clear sequencing when the peripheral is ready.
 * @summary Confirms that `SYSCTL__enClearReadyOnRunMode` queries readiness,
 *          asserts peripheral reset for a ready peripheral, and then disables
 *          run mode in that order.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_ReadyDriverMock bridge
 * - Original source under test: SYSCTL_Ready.c@endverbatim
 */
TEST(SYSCTL_ReadyTest, ClearReadyOnRunModeResetsThenDisablesRunMode)
{
    StrictMock<SYSCTL_ReadyDriverMock> stMock;
    SYSCTL_ReadyDriverMockScope stMockScope(&stMock);
    InSequence stSequence;

    EXPECT_CALL(stMock, IsPeripheralReady(SYSCTL_enMODULE_0, SYSCTL_enSSI2, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE, SYSCTL_nPERIPHERAL, SYSCTL_nBOOLEAN* penReadyArg) -> SYSCTL_nERROR
        {
            if(nullptr != penReadyArg)
            {
                *penReadyArg = SYSCTL_enTRUE;
            }
            return SYSCTL_enERROR_OK;
        }));
    EXPECT_CALL(stMock, SetPeripheralReset(SYSCTL_enMODULE_0, SYSCTL_enSSI2))
        .WillOnce(Return(SYSCTL_enERROR_OK));
    EXPECT_CALL(stMock, DisableRunMode(SYSCTL_enMODULE_0, SYSCTL_enSSI2))
        .WillOnce(Return(SYSCTL_enERROR_OK));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enClearReadyOnRunMode(SYSCTL_enMODULE_0, SYSCTL_enSSI2));
}

/**
 * @brief Validate reset-write error propagation in the SYSCTL reset helper.
 * @summary Confirms that `SYSCTL__enReset` returns the peripheral-reset error
 *          when the peripheral is already ready instead of dropping the reset
 *          write status.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_ReadyDriverMock bridge
 * - Original source under test: SYSCTL_Ready.c@endverbatim
 */
TEST(SYSCTL_ReadyTest, ResetPropagatesPeripheralResetError)
{
    StrictMock<SYSCTL_ReadyDriverMock> stMock;
    SYSCTL_ReadyDriverMockScope stMockScope(&stMock);
    InSequence stSequence;

    EXPECT_CALL(stMock, IsPeripheralReady(SYSCTL_enMODULE_0, SYSCTL_enTIMER5, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE, SYSCTL_nPERIPHERAL, SYSCTL_nBOOLEAN* penReadyArg) -> SYSCTL_nERROR
        {
            if(nullptr != penReadyArg)
            {
                *penReadyArg = SYSCTL_enTRUE;
            }
            return SYSCTL_enERROR_OK;
        }));
    EXPECT_CALL(stMock, SetPeripheralReset(SYSCTL_enMODULE_0, SYSCTL_enTIMER5))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE,
              SYSCTL__enReset(SYSCTL_enMODULE_0, SYSCTL_enTIMER5));
}

/**
 * @brief Validate delegation through the SYSCTL ready-state wrapper.
 * @summary Confirms that `SYSCTL__enIsReady` forwards the caller module,
 *          peripheral selector, and output pointer to the underlying
 *          peripheral-ready query and returns the resulting status unchanged.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_ReadyDriverMock bridge
 * - Original source under test: SYSCTL_Ready.c@endverbatim
 */
TEST(SYSCTL_ReadyTest, IsReadyDelegatesToPeripheralReady)
{
    StrictMock<SYSCTL_ReadyDriverMock> stMock;
    SYSCTL_ReadyDriverMockScope stMockScope(&stMock);
    SYSCTL_nBOOLEAN enReadyReg;

    enReadyReg = SYSCTL_enFALSE;

    EXPECT_CALL(stMock, IsPeripheralReady(SYSCTL_enMODULE_0, SYSCTL_enEEPROM, &enReadyReg))
        .WillOnce(Invoke([](SYSCTL_nMODULE, SYSCTL_nPERIPHERAL, SYSCTL_nBOOLEAN* penReadyArg) -> SYSCTL_nERROR
        {
            if(nullptr != penReadyArg)
            {
                *penReadyArg = SYSCTL_enTRUE;
            }
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enIsReady(SYSCTL_enMODULE_0, SYSCTL_enEEPROM, &enReadyReg));
    EXPECT_EQ(SYSCTL_enTRUE, enReadyReg);
}