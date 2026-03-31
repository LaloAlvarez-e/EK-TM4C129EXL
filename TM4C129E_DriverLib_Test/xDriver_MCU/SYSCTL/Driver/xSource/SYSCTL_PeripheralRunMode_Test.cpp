/**
 *
 * @file SYSCTL_PeripheralRunMode_Test.cpp
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
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_PeripheralRunMode.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/xHeader/SYSCTL_RegisterAddress.h>
}

#include <tm4c129e_test/SYSCTL_PeripheralGenericMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::InSequence;
using ::testing::Invoke;
using ::testing::Return;
using ::testing::StrictMock;

/**
 * @brief Validate RCGC write composition and PR ready polling in the run-mode setter.
 * @summary Confirms that `SYSCTL__enSetRunModeState` writes the requested run-mode
 *          state through `SYSCTL_RCGC_OFFSET` and then polls the ready helper
 *          until the peripheral reports ready.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PeripheralGenericMock bridge
 * - Original sources under test: SYSCTL_PeripheralRunMode.c, SYSCTL_PeripheralReady.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RCGC-001@endverbatim
 */
TEST(SYSCTL_PeripheralRunModeTest, SetRunModeStateUsesExpectedPeripheralWriteAndReadyPoll)
{
    StrictMock<SYSCTL_PeripheralGenericMock> stMock;
    SYSCTL_PeripheralGenericMockScope stMockScope(&stMock);

    InSequence stSequence;

    EXPECT_CALL(stMock, WritePeripheral(SYSCTL_enMODULE_0, SYSCTL_enGPIOA, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg,
                            SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_EQ(SYSCTL_enGPIOA, enPeripheralArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SYSCTL_RCGC_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) SYSCTL_enSTATE_ENA, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_CALL(stMock, ReadPeripheral(SYSCTL_enMODULE_0, SYSCTL_enGPIOA, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg,
                            SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_EQ(SYSCTL_enGPIOA, enPeripheralArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SYSCTL_PR_OFFSET, pstRegisterDataArg->uptrAddress);
            pstRegisterDataArg->uxValue = (UBase_t) SYSCTL_enFALSE;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_CALL(stMock, ReadPeripheral(SYSCTL_enMODULE_0, SYSCTL_enGPIOA, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg,
                            SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_EQ(SYSCTL_enGPIOA, enPeripheralArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SYSCTL_PR_OFFSET, pstRegisterDataArg->uptrAddress);
            pstRegisterDataArg->uxValue = (UBase_t) SYSCTL_enTRUE;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetRunModeState(SYSCTL_enMODULE_0, SYSCTL_enGPIOA, SYSCTL_enSTATE_ENA));
}

/**
 * @brief Validate enabled-state delegation in the run-mode enable wrapper.
 * @summary Confirms that `SYSCTL__enEnableRunMode` delegates through the shared
 *          setter path using the enabled state and completes the ready poll.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PeripheralGenericMock bridge
 * - Original sources under test: SYSCTL_PeripheralRunMode.c, SYSCTL_PeripheralReady.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RCGC-002@endverbatim
 */
TEST(SYSCTL_PeripheralRunModeTest, EnableRunModeUsesEnabledState)
{
    StrictMock<SYSCTL_PeripheralGenericMock> stMock;
    SYSCTL_PeripheralGenericMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WritePeripheral(SYSCTL_enMODULE_0, SYSCTL_enUART0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE, SYSCTL_nPERIPHERAL, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SYSCTL_RCGC_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) SYSCTL_enSTATE_ENA, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));
    EXPECT_CALL(stMock, ReadPeripheral(SYSCTL_enMODULE_0, SYSCTL_enUART0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE, SYSCTL_nPERIPHERAL, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SYSCTL_PR_OFFSET, pstRegisterDataArg->uptrAddress);
            pstRegisterDataArg->uxValue = (UBase_t) SYSCTL_enTRUE;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enEnableRunMode(SYSCTL_enMODULE_0, SYSCTL_enUART0));
}

/**
 * @brief Validate disabled-state delegation in the run-mode disable wrapper.
 * @summary Confirms that `SYSCTL__enDisableRunMode` delegates through the shared
 *          setter path using the disabled state and completes the ready poll.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PeripheralGenericMock bridge
 * - Original sources under test: SYSCTL_PeripheralRunMode.c, SYSCTL_PeripheralReady.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RCGC-003@endverbatim
 */
TEST(SYSCTL_PeripheralRunModeTest, DisableRunModeUsesDisabledState)
{
    StrictMock<SYSCTL_PeripheralGenericMock> stMock;
    SYSCTL_PeripheralGenericMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WritePeripheral(SYSCTL_enMODULE_0, SYSCTL_enUART1, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE, SYSCTL_nPERIPHERAL, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SYSCTL_RCGC_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) SYSCTL_enSTATE_DIS, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));
    EXPECT_CALL(stMock, ReadPeripheral(SYSCTL_enMODULE_0, SYSCTL_enUART1, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE, SYSCTL_nPERIPHERAL, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SYSCTL_PR_OFFSET, pstRegisterDataArg->uptrAddress);
            pstRegisterDataArg->uxValue = (UBase_t) SYSCTL_enTRUE;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enDisableRunMode(SYSCTL_enMODULE_0, SYSCTL_enUART1));
}

/**
 * @brief Validate ready-read error propagation in the run-mode setter.
 * @summary Confirms that `SYSCTL__enSetRunModeState` returns the ready-read
 *          failure unchanged after the RCGC write succeeds.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PeripheralGenericMock bridge
 * - Original sources under test: SYSCTL_PeripheralRunMode.c, SYSCTL_PeripheralReady.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RCGC-004@endverbatim
 */
TEST(SYSCTL_PeripheralRunModeTest, SetRunModeStatePropagatesReadyReadError)
{
    StrictMock<SYSCTL_PeripheralGenericMock> stMock;
    SYSCTL_PeripheralGenericMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WritePeripheral(SYSCTL_enMODULE_0, SYSCTL_enGPIOA, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_OK));
    EXPECT_CALL(stMock, ReadPeripheral(SYSCTL_enMODULE_0, SYSCTL_enGPIOA, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE,
              SYSCTL__enSetRunModeState(SYSCTL_enMODULE_0, SYSCTL_enGPIOA, SYSCTL_enSTATE_ENA));
}

/**
 * @brief Validate null-pointer rejection in the run-mode getter.
 * @summary Confirms that `SYSCTL__enGetRunModeState` rejects a null output
 *          pointer before attempting the peripheral-generic read seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_PeripheralRunMode.c
 * - Public API parameter validation path@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RCGC-005@endverbatim
 */
TEST(SYSCTL_PeripheralRunModeTest, GetRunModeStateRejectsNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetRunModeState(SYSCTL_enMODULE_0, SYSCTL_enGPIOA, (SYSCTL_nSTATE*) 0UL));
}

/**
 * @brief Validate RCGC-family read composition in the run-mode getter.
 * @summary Confirms that `SYSCTL__enGetRunModeState` reads from
 *          `SYSCTL_RCGC_OFFSET`, forwards the selected peripheral unchanged, and
 *          returns the state value from the peripheral-generic seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PeripheralGenericMock bridge
 * - Original source under test: SYSCTL_PeripheralRunMode.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RCGC-006@endverbatim
 */
TEST(SYSCTL_PeripheralRunModeTest, GetRunModeStateUsesExpectedPeripheralRead)
{
    StrictMock<SYSCTL_PeripheralGenericMock> stMock;
    SYSCTL_PeripheralGenericMockScope stMockScope(&stMock);
    SYSCTL_nSTATE enStateReg;

    enStateReg = SYSCTL_enSTATE_UNDEF;

    EXPECT_CALL(stMock, ReadPeripheral(SYSCTL_enMODULE_0, SYSCTL_enGPIOA, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg,
                            SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_EQ(SYSCTL_enGPIOA, enPeripheralArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SYSCTL_RCGC_OFFSET, pstRegisterDataArg->uptrAddress);
            pstRegisterDataArg->uxValue = (UBase_t) SYSCTL_enSTATE_DIS;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetRunModeState(SYSCTL_enMODULE_0, SYSCTL_enGPIOA, &enStateReg));
    EXPECT_EQ(SYSCTL_enSTATE_DIS, enStateReg);
}

/**
 * @brief Validate read-error propagation in the run-mode getter.
 * @summary Confirms that `SYSCTL__enGetRunModeState` returns the
 *          peripheral-generic read error unchanged and preserves the caller
 *          output value when the read path fails.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PeripheralGenericMock bridge
 * - Original source under test: SYSCTL_PeripheralRunMode.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-RCGC-007@endverbatim
 */
TEST(SYSCTL_PeripheralRunModeTest, GetRunModeStatePropagatesReadError)
{
    StrictMock<SYSCTL_PeripheralGenericMock> stMock;
    SYSCTL_PeripheralGenericMockScope stMockScope(&stMock);
    SYSCTL_nSTATE enStateReg;

    enStateReg = SYSCTL_enSTATE_ENA;

    EXPECT_CALL(stMock, ReadPeripheral(SYSCTL_enMODULE_0, SYSCTL_enUART1, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enGetRunModeState(SYSCTL_enMODULE_0, SYSCTL_enUART1, &enStateReg));
    EXPECT_EQ(SYSCTL_enSTATE_ENA, enStateReg);
}