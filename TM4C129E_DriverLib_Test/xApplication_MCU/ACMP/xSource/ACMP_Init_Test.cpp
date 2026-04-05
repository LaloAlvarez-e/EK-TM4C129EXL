/**
 *
 * @file ACMP_Init_Test.cpp
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
#include <xApplication_MCU/ACMP/xHeader/ACMP_Init.h>
}

#include <tm4c129e_test/ACMP_InitDriverMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::InSequence;
using ::testing::Return;
using ::testing::StrictMock;

namespace
{
void TM4C129E_DriverLib_Test__vDummyACMPIRQVectorHandler(void)
{
}
}

/**
 * @brief Validate early exit on ACMP ready-state failure.
 * @summary Confirms that `ACMP__enInit` propagates the first ready-state
 *          setup error without attempting comparator IRQ-handler lookup or
 *          registration work.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - ACMP_InitDriverMock bridge
 * - Original source under test: ACMP_Init.c@endverbatim
 */
TEST(ACMP_InitTest, InitPropagatesReadyError)
{
    StrictMock<ACMP_InitDriverMock> stMock;
    ACMP_InitDriverMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, SetReadyOnRunMode(ACMP_enMODULE_0))
        .WillOnce(Return(ACMP_enERROR_RANGE));

    EXPECT_EQ(ACMP_enERROR_RANGE, ACMP__enInit(ACMP_enMODULE_0));
}

/**
 * @brief Validate the ordered ACMP init registration sequence.
 * @summary Confirms that `ACMP__enInit` enables ACMP ready state, obtains the
 *          installed IRQ handler for comparators 0 through 2 in order, and
 *          registers each comparator vector until the full sequence completes
 *          successfully.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - ACMP_InitDriverMock bridge
 * - Original source under test: ACMP_Init.c@endverbatim
 */
TEST(ACMP_InitTest, InitRegistersAllComparatorsInOrder)
{
    StrictMock<ACMP_InitDriverMock> stMock;
    ACMP_InitDriverMockScope stMockScope(&stMock);
    InSequence stSequence;
    const ACMP_TestIRQVectorHandler_t pfHandler = &TM4C129E_DriverLib_Test__vDummyACMPIRQVectorHandler;

    EXPECT_CALL(stMock, SetReadyOnRunMode(ACMP_enMODULE_0))
        .WillOnce(Return(ACMP_enERROR_OK));

    const auto vExpectRegistration = [&](ACMP_nCOMP enComparatorArg)
    {
        EXPECT_CALL(stMock, GetIRQVectorHandler(ACMP_enMODULE_0, enComparatorArg))
            .WillOnce(Return(pfHandler));
        EXPECT_CALL(stMock, RegisterIRQVectorHandler(ACMP_enMODULE_0, enComparatorArg, pfHandler))
            .WillOnce(Return(ACMP_enERROR_OK));
    };

    vExpectRegistration(ACMP_enCOMP_0);
    vExpectRegistration(ACMP_enCOMP_1);
    vExpectRegistration(ACMP_enCOMP_2);

    EXPECT_EQ(ACMP_enERROR_OK, ACMP__enInit(ACMP_enMODULE_0));
}

/**
 * @brief Validate early exit on ACMP comparator registration failure.
 * @summary Confirms that `ACMP__enInit` stops on the first comparator IRQ
 *          registration failure and propagates that ACMP error without
 *          attempting later comparator registrations.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - ACMP_InitDriverMock bridge
 * - Original source under test: ACMP_Init.c@endverbatim
 */
TEST(ACMP_InitTest, InitStopsWhenComparatorRegistrationFails)
{
    StrictMock<ACMP_InitDriverMock> stMock;
    ACMP_InitDriverMockScope stMockScope(&stMock);
    InSequence stSequence;
    const ACMP_TestIRQVectorHandler_t pfHandler = &TM4C129E_DriverLib_Test__vDummyACMPIRQVectorHandler;

    EXPECT_CALL(stMock, SetReadyOnRunMode(ACMP_enMODULE_0))
        .WillOnce(Return(ACMP_enERROR_OK));
    EXPECT_CALL(stMock, GetIRQVectorHandler(ACMP_enMODULE_0, ACMP_enCOMP_0))
        .WillOnce(Return(pfHandler));
    EXPECT_CALL(stMock, RegisterIRQVectorHandler(ACMP_enMODULE_0, ACMP_enCOMP_0, pfHandler))
        .WillOnce(Return(ACMP_enERROR_OK));
    EXPECT_CALL(stMock, GetIRQVectorHandler(ACMP_enMODULE_0, ACMP_enCOMP_1))
        .WillOnce(Return(pfHandler));
    EXPECT_CALL(stMock, RegisterIRQVectorHandler(ACMP_enMODULE_0, ACMP_enCOMP_1, pfHandler))
        .WillOnce(Return(ACMP_enERROR_RANGE));

    EXPECT_EQ(ACMP_enERROR_RANGE, ACMP__enInit(ACMP_enMODULE_0));
}