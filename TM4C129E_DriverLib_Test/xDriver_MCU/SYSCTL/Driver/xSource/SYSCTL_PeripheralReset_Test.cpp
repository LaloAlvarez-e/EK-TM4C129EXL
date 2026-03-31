/**
 *
 * @file SYSCTL_PeripheralReset_Test.cpp
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
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_PeripheralReset.h>
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
 * @brief Validate SR write ordering and PR ready polling during peripheral reset.
 * @summary Confirms that `SYSCTL__enSetPeripheralReset` asserts the selected
 *          software-reset bit through `SYSCTL_SR_OFFSET`, releases that same bit,
 *          and then polls the ready helper until the peripheral reports ready.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PeripheralGenericMock bridge
 * - Original sources under test: SYSCTL_PeripheralReset.c, SYSCTL_PeripheralReady.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-SR-001@endverbatim
 */
TEST(SYSCTL_PeripheralResetTest, SetPeripheralResetUsesAssertThenReleaseWriteOrderingAndReadyPoll)
{
    StrictMock<SYSCTL_PeripheralGenericMock> stMock;
    SYSCTL_PeripheralGenericMockScope stMockScope(&stMock);

    InSequence stSequence;

    EXPECT_CALL(stMock, WritePeripheral(SYSCTL_enMODULE_0, SYSCTL_enUSB, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg,
                            SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_EQ(SYSCTL_enUSB, enPeripheralArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SYSCTL_SR_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) 1UL, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_CALL(stMock, WritePeripheral(SYSCTL_enMODULE_0, SYSCTL_enUSB, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg,
                            SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_EQ(SYSCTL_enUSB, enPeripheralArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SYSCTL_SR_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) 0UL, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_CALL(stMock, ReadPeripheral(SYSCTL_enMODULE_0, SYSCTL_enUSB, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg,
                            SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_EQ(SYSCTL_enUSB, enPeripheralArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SYSCTL_PR_OFFSET, pstRegisterDataArg->uptrAddress);
            pstRegisterDataArg->uxValue = (UBase_t) SYSCTL_enFALSE;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_CALL(stMock, ReadPeripheral(SYSCTL_enMODULE_0, SYSCTL_enUSB, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg,
                            SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_EQ(SYSCTL_enUSB, enPeripheralArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SYSCTL_PR_OFFSET, pstRegisterDataArg->uptrAddress);
            pstRegisterDataArg->uxValue = (UBase_t) SYSCTL_enTRUE;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enSetPeripheralReset(SYSCTL_enMODULE_0, SYSCTL_enUSB));
}

/**
 * @brief Validate early exit when the reset-assert write fails.
 * @summary Confirms that `SYSCTL__enSetPeripheralReset` returns the first reset
 *          write error immediately and skips both the deassert write and ready poll.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PeripheralGenericMock bridge
 * - Original sources under test: SYSCTL_PeripheralReset.c, SYSCTL_PeripheralReady.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-SR-002@endverbatim
 */
TEST(SYSCTL_PeripheralResetTest, SetPeripheralResetStopsWhenAssertWriteFails)
{
    StrictMock<SYSCTL_PeripheralGenericMock> stMock;
    SYSCTL_PeripheralGenericMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WritePeripheral(SYSCTL_enMODULE_0, SYSCTL_enCAN0, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enSetPeripheralReset(SYSCTL_enMODULE_0, SYSCTL_enCAN0));
}

/**
 * @brief Validate early exit when the reset-release write fails.
 * @summary Confirms that `SYSCTL__enSetPeripheralReset` performs the assert write,
 *          returns the release-write error unchanged, and does not enter the ready poll.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PeripheralGenericMock bridge
 * - Original sources under test: SYSCTL_PeripheralReset.c, SYSCTL_PeripheralReady.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-SR-003@endverbatim
 */
TEST(SYSCTL_PeripheralResetTest, SetPeripheralResetStopsWhenReleaseWriteFails)
{
    StrictMock<SYSCTL_PeripheralGenericMock> stMock;
    SYSCTL_PeripheralGenericMockScope stMockScope(&stMock);

    InSequence stSequence;

    EXPECT_CALL(stMock, WritePeripheral(SYSCTL_enMODULE_0, SYSCTL_enGPIOA, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_OK));
    EXPECT_CALL(stMock, WritePeripheral(SYSCTL_enMODULE_0, SYSCTL_enGPIOA, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enSetPeripheralReset(SYSCTL_enMODULE_0, SYSCTL_enGPIOA));
}

/**
 * @brief Validate error propagation from the ready-poll path after reset writes succeed.
 * @summary Confirms that `SYSCTL__enSetPeripheralReset` returns the ready-read
 *          failure unchanged after the assert and release writes complete.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PeripheralGenericMock bridge
 * - Original sources under test: SYSCTL_PeripheralReset.c, SYSCTL_PeripheralReady.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-SR-004@endverbatim
 */
TEST(SYSCTL_PeripheralResetTest, SetPeripheralResetPropagatesReadyReadError)
{
    StrictMock<SYSCTL_PeripheralGenericMock> stMock;
    SYSCTL_PeripheralGenericMockScope stMockScope(&stMock);

    InSequence stSequence;

    EXPECT_CALL(stMock, WritePeripheral(SYSCTL_enMODULE_0, SYSCTL_enUART0, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_OK));
    EXPECT_CALL(stMock, WritePeripheral(SYSCTL_enMODULE_0, SYSCTL_enUART0, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_OK));
    EXPECT_CALL(stMock, ReadPeripheral(SYSCTL_enMODULE_0, SYSCTL_enUART0, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enSetPeripheralReset(SYSCTL_enMODULE_0, SYSCTL_enUART0));
}

/**
 * @brief Validate null-pointer rejection in the reset-state getter.
 * @summary Confirms that `SYSCTL__enIsPeripheralOnReset` rejects a null output
 *          pointer before attempting the peripheral-generic read seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_PeripheralReset.c
 * - Public API parameter validation path@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-SR-005@endverbatim
 */
TEST(SYSCTL_PeripheralResetTest, IsPeripheralOnResetRejectsNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enIsPeripheralOnReset(SYSCTL_enMODULE_0, SYSCTL_enUSB, (SYSCTL_nBOOLEAN*) 0UL));
}

/**
 * @brief Validate SR-family read composition in the reset-state getter.
 * @summary Confirms that `SYSCTL__enIsPeripheralOnReset` reads from
 *          `SYSCTL_SR_OFFSET`, forwards the selected peripheral unchanged, and
 *          returns the boolean state from the peripheral-generic seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PeripheralGenericMock bridge
 * - Original source under test: SYSCTL_PeripheralReset.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-SR-006@endverbatim
 */
TEST(SYSCTL_PeripheralResetTest, IsPeripheralOnResetUsesExpectedPeripheralRead)
{
    StrictMock<SYSCTL_PeripheralGenericMock> stMock;
    SYSCTL_PeripheralGenericMockScope stMockScope(&stMock);
    SYSCTL_nBOOLEAN enStateReg;

    enStateReg = SYSCTL_enFALSE;

    EXPECT_CALL(stMock, ReadPeripheral(SYSCTL_enMODULE_0, SYSCTL_enUSB, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg,
                            SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_EQ(SYSCTL_enUSB, enPeripheralArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SYSCTL_SR_OFFSET, pstRegisterDataArg->uptrAddress);
            pstRegisterDataArg->uxValue = (UBase_t) SYSCTL_enTRUE;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enIsPeripheralOnReset(SYSCTL_enMODULE_0, SYSCTL_enUSB, &enStateReg));
    EXPECT_EQ(SYSCTL_enTRUE, enStateReg);
}

/**
 * @brief Validate read-error propagation in the reset-state getter.
 * @summary Confirms that `SYSCTL__enIsPeripheralOnReset` returns the
 *          peripheral-generic read error unchanged and preserves the caller
 *          output value when the read path fails.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PeripheralGenericMock bridge
 * - Original source under test: SYSCTL_PeripheralReset.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-SR-007@endverbatim
 */
TEST(SYSCTL_PeripheralResetTest, IsPeripheralOnResetPropagatesReadError)
{
    StrictMock<SYSCTL_PeripheralGenericMock> stMock;
    SYSCTL_PeripheralGenericMockScope stMockScope(&stMock);
    SYSCTL_nBOOLEAN enStateReg;

    enStateReg = SYSCTL_enTRUE;

    EXPECT_CALL(stMock, ReadPeripheral(SYSCTL_enMODULE_0, SYSCTL_enGPIOA, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enIsPeripheralOnReset(SYSCTL_enMODULE_0, SYSCTL_enGPIOA, &enStateReg));
    EXPECT_EQ(SYSCTL_enTRUE, enStateReg);
}