/**
 *
 * @file TIMER_InterruptVector_Test.cpp
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
#include <xApplication_MCU/TIMER/Interrupt/xHeader/TIMER_InterruptVector.h>
}

#include <tm4c129e_test/TIMER_InterruptVectorDriverMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::_;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::SetArgPointee;
using ::testing::StrictMock;

/**
 * @brief Validate wide-timer routing in the TIMER vector-enable wrapper.
 * @summary Confirms that `TIMER__enEnableInterruptVector` resolves the public
 *          wide-timer module selector into the corresponding A-side NVIC vector
 *          before delegating to the NVIC enable wrapper and returning its
 *          status.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - TIMER_InterruptVectorDriverMock bridge
 * - Original source under test: TIMER_InterruptVector.c@endverbatim
 */
TEST(TIMER_InterruptVectorTest, EnableInterruptVectorMapsWideTimerToTimerAVector)
{
    StrictMock<TIMER_InterruptVectorDriverMock> stMock;
    TIMER_InterruptVectorDriverMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, GetSubParams(TIMER_enT0W, _, _))
        .WillOnce(DoAll(SetArgPointee<1>((UBase_t) TIMER_enSUBMODULE_W),
                        SetArgPointee<2>((UBase_t) TIMER_enMODULE_NUM_0)));
    EXPECT_CALL(stMock,
                EnableVector(NVIC_enMODULE_0,
                             NVIC_enVECTOR_TIMER0A,
                             (NVIC_nPRIORITY) TIMER_enPRI4))
        .WillOnce(Return(NVIC_enERROR_OK));

    EXPECT_EQ(TIMER_enERROR_OK,
              TIMER__enEnableInterruptVector(TIMER_enT0W, TIMER_enPRI4));
}

/**
 * @brief Validate NVIC error propagation in the TIMER vector-enable wrapper.
 * @summary Confirms that `TIMER__enEnableInterruptVector` propagates the
 *          underlying NVIC enable-vector failure for the selected TIMER vector.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - TIMER_InterruptVectorDriverMock bridge
 * - Original source under test: TIMER_InterruptVector.c@endverbatim
 */
TEST(TIMER_InterruptVectorTest, EnableInterruptVectorPropagatesNVICError)
{
    StrictMock<TIMER_InterruptVectorDriverMock> stMock;
    TIMER_InterruptVectorDriverMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, GetSubParams(TIMER_enT2B, _, _))
        .WillOnce(DoAll(SetArgPointee<1>((UBase_t) TIMER_enSUBMODULE_B),
                        SetArgPointee<2>((UBase_t) TIMER_enMODULE_NUM_2)));
    EXPECT_CALL(stMock,
                EnableVector(NVIC_enMODULE_0,
                             NVIC_enVECTOR_TIMER2B,
                             (NVIC_nPRIORITY) TIMER_enPRI1))
        .WillOnce(Return(NVIC_enERROR_RANGE));

    EXPECT_EQ(TIMER_enERROR_RANGE,
              TIMER__enEnableInterruptVector(TIMER_enT2B, TIMER_enPRI1));
}

/**
 * @brief Validate mapped-vector disable delegation in the TIMER wrapper.
 * @summary Confirms that `TIMER__enDisableInterruptVector` resolves the caller
 *          module into the expected NVIC TIMER vector before delegating the
 *          disable request and returning its status.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - TIMER_InterruptVectorDriverMock bridge
 * - Original source under test: TIMER_InterruptVector.c@endverbatim
 */
TEST(TIMER_InterruptVectorTest, DisableInterruptVectorUsesMappedTimerVector)
{
    StrictMock<TIMER_InterruptVectorDriverMock> stMock;
    TIMER_InterruptVectorDriverMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, GetSubParams(TIMER_enT5B, _, _))
        .WillOnce(DoAll(SetArgPointee<1>((UBase_t) TIMER_enSUBMODULE_B),
                        SetArgPointee<2>((UBase_t) TIMER_enMODULE_NUM_5)));
    EXPECT_CALL(stMock, DisableVector(NVIC_enMODULE_0, NVIC_enVECTOR_TIMER5B))
        .WillOnce(Return(NVIC_enERROR_OK));

    EXPECT_EQ(TIMER_enERROR_OK,
              TIMER__enDisableInterruptVector(TIMER_enT5B));
}

/**
 * @brief Validate NVIC error propagation in the TIMER vector-disable wrapper.
 * @summary Confirms that `TIMER__enDisableInterruptVector` propagates the
 *          underlying NVIC disable-vector failure for the selected TIMER vector.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - TIMER_InterruptVectorDriverMock bridge
 * - Original source under test: TIMER_InterruptVector.c@endverbatim
 */
TEST(TIMER_InterruptVectorTest, DisableInterruptVectorPropagatesNVICError)
{
    StrictMock<TIMER_InterruptVectorDriverMock> stMock;
    TIMER_InterruptVectorDriverMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, GetSubParams(TIMER_enT7A, _, _))
        .WillOnce(DoAll(SetArgPointee<1>((UBase_t) TIMER_enSUBMODULE_A),
                        SetArgPointee<2>((UBase_t) TIMER_enMODULE_NUM_7)));
    EXPECT_CALL(stMock, DisableVector(NVIC_enMODULE_0, NVIC_enVECTOR_TIMER7A))
        .WillOnce(Return(NVIC_enERROR_VALUE));

    EXPECT_EQ(TIMER_enERROR_VALUE,
              TIMER__enDisableInterruptVector(TIMER_enT7A));
}