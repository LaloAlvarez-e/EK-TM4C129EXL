/**
 *
 * @file SYSCTL_PeripheralDeepSleepMode_Test.cpp
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
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_PeripheralDeepSleepMode.h>
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
 * @brief Validate DCGC write composition and PR ready polling in the deep-sleep setter.
 * @summary Confirms that `SYSCTL__enSetDeepSleepModeState` writes the requested
 *          deep-sleep mode state through `SYSCTL_DCGC_OFFSET` and then polls the
 *          ready helper until the peripheral reports ready.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PeripheralGenericMock bridge
 * - Original sources under test: SYSCTL_PeripheralDeepSleepMode.c, SYSCTL_PeripheralReady.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-DCGC-001@endverbatim
 */
TEST(SYSCTL_PeripheralDeepSleepModeTest, SetDeepSleepModeStateUsesExpectedPeripheralWriteAndReadyPoll)
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
            EXPECT_EQ((uintptr_t) SYSCTL_DCGC_OFFSET, pstRegisterDataArg->uptrAddress);
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
              SYSCTL__enSetDeepSleepModeState(SYSCTL_enMODULE_0, SYSCTL_enGPIOA, SYSCTL_enSTATE_ENA));
}

/**
 * @brief Validate enabled-state delegation in the deep-sleep enable wrapper.
 * @summary Confirms that `SYSCTL__enEnableDeepSleepMode` delegates through the
 *          shared setter path using the enabled state and completes the ready poll.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PeripheralGenericMock bridge
 * - Original sources under test: SYSCTL_PeripheralDeepSleepMode.c, SYSCTL_PeripheralReady.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-DCGC-002@endverbatim
 */
TEST(SYSCTL_PeripheralDeepSleepModeTest, EnableDeepSleepModeUsesEnabledState)
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
            EXPECT_EQ((uintptr_t) SYSCTL_DCGC_OFFSET, pstRegisterDataArg->uptrAddress);
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

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enEnableDeepSleepMode(SYSCTL_enMODULE_0, SYSCTL_enUART0));
}

/**
 * @brief Validate disabled-state delegation in the deep-sleep disable wrapper.
 * @summary Confirms that `SYSCTL__enDisableDeepSleepMode` delegates through the
 *          shared setter path using the disabled state and completes the ready poll.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PeripheralGenericMock bridge
 * - Original sources under test: SYSCTL_PeripheralDeepSleepMode.c, SYSCTL_PeripheralReady.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-DCGC-003@endverbatim
 */
TEST(SYSCTL_PeripheralDeepSleepModeTest, DisableDeepSleepModeUsesDisabledState)
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
            EXPECT_EQ((uintptr_t) SYSCTL_DCGC_OFFSET, pstRegisterDataArg->uptrAddress);
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

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enDisableDeepSleepMode(SYSCTL_enMODULE_0, SYSCTL_enUART1));
}

/**
 * @brief Validate ready-read error propagation in the deep-sleep setter.
 * @summary Confirms that `SYSCTL__enSetDeepSleepModeState` returns the ready-read
 *          failure unchanged after the DCGC write succeeds.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PeripheralGenericMock bridge
 * - Original sources under test: SYSCTL_PeripheralDeepSleepMode.c, SYSCTL_PeripheralReady.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-DCGC-004@endverbatim
 */
TEST(SYSCTL_PeripheralDeepSleepModeTest, SetDeepSleepModeStatePropagatesReadyReadError)
{
    StrictMock<SYSCTL_PeripheralGenericMock> stMock;
    SYSCTL_PeripheralGenericMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WritePeripheral(SYSCTL_enMODULE_0, SYSCTL_enGPIOA, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_OK));
    EXPECT_CALL(stMock, ReadPeripheral(SYSCTL_enMODULE_0, SYSCTL_enGPIOA, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE,
              SYSCTL__enSetDeepSleepModeState(SYSCTL_enMODULE_0, SYSCTL_enGPIOA, SYSCTL_enSTATE_ENA));
}

/**
 * @brief Validate null-pointer rejection in the deep-sleep getter.
 * @summary Confirms that `SYSCTL__enGetDeepSleepModeState` rejects a null output
 *          pointer before attempting the peripheral-generic read seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_PeripheralDeepSleepMode.c
 * - Public API parameter validation path@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-DCGC-005@endverbatim
 */
TEST(SYSCTL_PeripheralDeepSleepModeTest, GetDeepSleepModeStateRejectsNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetDeepSleepModeState(SYSCTL_enMODULE_0, SYSCTL_enGPIOA, (SYSCTL_nSTATE*) 0UL));
}

/**
 * @brief Validate DCGC-family read composition in the deep-sleep getter.
 * @summary Confirms that `SYSCTL__enGetDeepSleepModeState` reads from
 *          `SYSCTL_DCGC_OFFSET`, forwards the selected peripheral unchanged, and
 *          returns the state value from the peripheral-generic seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PeripheralGenericMock bridge
 * - Original source under test: SYSCTL_PeripheralDeepSleepMode.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-DCGC-006@endverbatim
 */
TEST(SYSCTL_PeripheralDeepSleepModeTest, GetDeepSleepModeStateUsesExpectedPeripheralRead)
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
            EXPECT_EQ((uintptr_t) SYSCTL_DCGC_OFFSET, pstRegisterDataArg->uptrAddress);
            pstRegisterDataArg->uxValue = (UBase_t) SYSCTL_enSTATE_DIS;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enGetDeepSleepModeState(SYSCTL_enMODULE_0, SYSCTL_enGPIOA, &enStateReg));
    EXPECT_EQ(SYSCTL_enSTATE_DIS, enStateReg);
}

/**
 * @brief Validate read-error propagation in the deep-sleep getter.
 * @summary Confirms that `SYSCTL__enGetDeepSleepModeState` returns the
 *          peripheral-generic read error unchanged and preserves the caller
 *          output value when the read path fails.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PeripheralGenericMock bridge
 * - Original source under test: SYSCTL_PeripheralDeepSleepMode.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-DCGC-007@endverbatim
 */
TEST(SYSCTL_PeripheralDeepSleepModeTest, GetDeepSleepModeStatePropagatesReadError)
{
    StrictMock<SYSCTL_PeripheralGenericMock> stMock;
    SYSCTL_PeripheralGenericMockScope stMockScope(&stMock);
    SYSCTL_nSTATE enStateReg;

    enStateReg = SYSCTL_enSTATE_ENA;

    EXPECT_CALL(stMock, ReadPeripheral(SYSCTL_enMODULE_0, SYSCTL_enUART1, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE,
              SYSCTL__enGetDeepSleepModeState(SYSCTL_enMODULE_0, SYSCTL_enUART1, &enStateReg));
    EXPECT_EQ(SYSCTL_enSTATE_ENA, enStateReg);
}