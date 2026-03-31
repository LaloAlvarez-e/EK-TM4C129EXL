/**
 *
 * @file NVIC_DeInitInterrupts_Test.cpp
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
 * Date           Author           Version     Description
 * 29 mar. 2026   GitHub Copilot   1.0         initial Version@endverbatim
 */

extern "C"
{
#include <xDriver_MCU/Core/NVIC/Driver/xHeader/NVIC_DeInitInterrupts.h>
}

#include <tm4c129e_test/NVIC_DeInitDriverMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Invoke;
using ::testing::StrictMock;

/**
 * @brief Validate that the disable-all helper iterates every implemented IRQ vector.
 * @summary Confirms that `NVIC__enDisableAllInterrupts` calls
 *          `NVIC__enDisableVector` for every vector from `0` through
 *          `NVIC_enVECTOR_MAX - 1` and returns success when all calls succeed.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - NVIC_DeInitDriverMock bridge
 * - Original source under test: NVIC_DeInitInterrupts.c@endverbatim
 */
TEST(NVIC_DeInitInterruptsTest, DisableAllInterruptsIteratesAcrossAllVectors)
{
    StrictMock<NVIC_DeInitDriverMock> stMock;
    NVIC_DeInitDriverMockScope stMockScope(&stMock);
    UBase_t uxExpectedVector;

    uxExpectedVector = 0UL;

    EXPECT_CALL(stMock, DisableVector(NVIC_enMODULE_0, testing::_))
        .Times((int) NVIC_enVECTOR_MAX)
        .WillRepeatedly(Invoke([&uxExpectedVector](NVIC_nMODULE enModuleArg, NVIC_nVECTOR enVectorArg) -> NVIC_nERROR
        {
            EXPECT_EQ(NVIC_enMODULE_0, enModuleArg);
            EXPECT_EQ((UBase_t) uxExpectedVector, (UBase_t) enVectorArg);
            uxExpectedVector++;
            return NVIC_enERROR_OK;
        }));

    EXPECT_EQ(NVIC_enERROR_OK, NVIC__enDisableAllInterrupts(NVIC_enMODULE_0));
    EXPECT_EQ((UBase_t) NVIC_enVECTOR_MAX, uxExpectedVector);
}

/**
 * @brief Validate early exit on the first disable-vector failure.
 * @summary Confirms that `NVIC__enDisableAllInterrupts` stops iterating and
 *          returns the underlying error as soon as `NVIC__enDisableVector` fails.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - NVIC_DeInitDriverMock bridge
 * - Original source under test: NVIC_DeInitInterrupts.c@endverbatim
 */
TEST(NVIC_DeInitInterruptsTest, DisableAllInterruptsStopsOnDisableError)
{
    StrictMock<NVIC_DeInitDriverMock> stMock;
    NVIC_DeInitDriverMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, DisableVector(NVIC_enMODULE_0, (NVIC_nVECTOR) 0UL))
        .WillOnce(Invoke([](NVIC_nMODULE, NVIC_nVECTOR) -> NVIC_nERROR
        {
            return NVIC_enERROR_OK;
        }));
    EXPECT_CALL(stMock, DisableVector(NVIC_enMODULE_0, (NVIC_nVECTOR) 1UL))
        .WillOnce(Invoke([](NVIC_nMODULE, NVIC_nVECTOR) -> NVIC_nERROR
        {
            return NVIC_enERROR_OK;
        }));
    EXPECT_CALL(stMock, DisableVector(NVIC_enMODULE_0, (NVIC_nVECTOR) 2UL))
        .WillOnce(Invoke([](NVIC_nMODULE, NVIC_nVECTOR) -> NVIC_nERROR
        {
            return NVIC_enERROR_RANGE;
        }));

    EXPECT_EQ(NVIC_enERROR_RANGE, NVIC__enDisableAllInterrupts(NVIC_enMODULE_0));
}