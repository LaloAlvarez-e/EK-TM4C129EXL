/**
 *
 * @file TIMER_Init_Test.cpp
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
#include <xApplication_MCU/TIMER/xHeader/TIMER_Init.h>
}

#include <tm4c129e_test/TIMER_InitDriverMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::InSequence;
using ::testing::Return;
using ::testing::StrictMock;

namespace
{
void TM4C129E_DriverLib_Test__vDummyTIMERIRQVectorHandler(void)
{
}
}

/**
 * @brief Validate the ordered TIMER init registration sequence.
 * @summary Confirms that `TIMER__enInit` obtains the installed IRQ vector
 *          handler for each TIMER A/B application slot from module 0 through 7
 *          and registers each slot in order until the full sequence completes
 *          successfully.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - TIMER_InitDriverMock bridge
 * - Original source under test: TIMER_Init.c@endverbatim
 */
TEST(TIMER_InitTest, InitRegistersAllTimerVectorsInOrder)
{
    StrictMock<TIMER_InitDriverMock> stMock;
    TIMER_InitDriverMockScope stMockScope(&stMock);
    InSequence stSequence;
    const TIMER_TestIRQVectorHandler_t pfHandler = &TM4C129E_DriverLib_Test__vDummyTIMERIRQVectorHandler;

    const auto vExpectRegistration = [&](TIMER_nSUBMODULE enSubModuleArg,
                                         TIMER_nMODULE_NUM enModuleNumberArg,
                                         TIMER_nMODULE enModuleArg)
    {
        EXPECT_CALL(stMock, GetIRQVectorHandler(enSubModuleArg, enModuleNumberArg))
            .WillOnce(Return(pfHandler));
        EXPECT_CALL(stMock, RegisterIRQVectorHandler(pfHandler, enModuleArg))
            .WillOnce(Return(TIMER_enERROR_OK));
    };

    vExpectRegistration(TIMER_enSUBMODULE_A, TIMER_enMODULE_NUM_0, TIMER_enT0A);
    vExpectRegistration(TIMER_enSUBMODULE_B, TIMER_enMODULE_NUM_0, TIMER_enT0B);
    vExpectRegistration(TIMER_enSUBMODULE_A, TIMER_enMODULE_NUM_1, TIMER_enT1A);
    vExpectRegistration(TIMER_enSUBMODULE_B, TIMER_enMODULE_NUM_1, TIMER_enT1B);
    vExpectRegistration(TIMER_enSUBMODULE_A, TIMER_enMODULE_NUM_2, TIMER_enT2A);
    vExpectRegistration(TIMER_enSUBMODULE_B, TIMER_enMODULE_NUM_2, TIMER_enT2B);
    vExpectRegistration(TIMER_enSUBMODULE_A, TIMER_enMODULE_NUM_3, TIMER_enT3A);
    vExpectRegistration(TIMER_enSUBMODULE_B, TIMER_enMODULE_NUM_3, TIMER_enT3B);
    vExpectRegistration(TIMER_enSUBMODULE_A, TIMER_enMODULE_NUM_4, TIMER_enT4A);
    vExpectRegistration(TIMER_enSUBMODULE_B, TIMER_enMODULE_NUM_4, TIMER_enT4B);
    vExpectRegistration(TIMER_enSUBMODULE_A, TIMER_enMODULE_NUM_5, TIMER_enT5A);
    vExpectRegistration(TIMER_enSUBMODULE_B, TIMER_enMODULE_NUM_5, TIMER_enT5B);
    vExpectRegistration(TIMER_enSUBMODULE_A, TIMER_enMODULE_NUM_6, TIMER_enT6A);
    vExpectRegistration(TIMER_enSUBMODULE_B, TIMER_enMODULE_NUM_6, TIMER_enT6B);
    vExpectRegistration(TIMER_enSUBMODULE_A, TIMER_enMODULE_NUM_7, TIMER_enT7A);
    vExpectRegistration(TIMER_enSUBMODULE_B, TIMER_enMODULE_NUM_7, TIMER_enT7B);

    EXPECT_EQ(TIMER_enERROR_OK, TIMER__enInit());
}

/**
 * @brief Validate early exit on TIMER init registration failure.
 * @summary Confirms that `TIMER__enInit` stops on the first IRQ registration
 *          failure and propagates that TIMER error without attempting later
 *          module registrations.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - TIMER_InitDriverMock bridge
 * - Original source under test: TIMER_Init.c@endverbatim
 */
TEST(TIMER_InitTest, InitStopsWhenRegistrationFails)
{
    StrictMock<TIMER_InitDriverMock> stMock;
    TIMER_InitDriverMockScope stMockScope(&stMock);
    InSequence stSequence;
    const TIMER_TestIRQVectorHandler_t pfHandler = &TM4C129E_DriverLib_Test__vDummyTIMERIRQVectorHandler;

    EXPECT_CALL(stMock, GetIRQVectorHandler(TIMER_enSUBMODULE_A, TIMER_enMODULE_NUM_0))
        .WillOnce(Return(pfHandler));
    EXPECT_CALL(stMock, RegisterIRQVectorHandler(pfHandler, TIMER_enT0A))
        .WillOnce(Return(TIMER_enERROR_OK));
    EXPECT_CALL(stMock, GetIRQVectorHandler(TIMER_enSUBMODULE_B, TIMER_enMODULE_NUM_0))
        .WillOnce(Return(pfHandler));
    EXPECT_CALL(stMock, RegisterIRQVectorHandler(pfHandler, TIMER_enT0B))
        .WillOnce(Return(TIMER_enERROR_OK));
    EXPECT_CALL(stMock, GetIRQVectorHandler(TIMER_enSUBMODULE_A, TIMER_enMODULE_NUM_1))
        .WillOnce(Return(pfHandler));
    EXPECT_CALL(stMock, RegisterIRQVectorHandler(pfHandler, TIMER_enT1A))
        .WillOnce(Return(TIMER_enERROR_RANGE));

    EXPECT_EQ(TIMER_enERROR_RANGE, TIMER__enInit());
}