/**
 *
 * @file NVIC_Enable_Test.cpp
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
#include <xDriver_MCU/Core/NVIC/Driver/xHeader/NVIC_Enable.h>
#include <xDriver_MCU/Core/NVIC/Peripheral/Register/xHeader/NVIC_RegisterAddress.h>
}

#include <tm4c129e_test/NVIC_EnableDriverMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::DoAll;
using ::testing::InSequence;
using ::testing::Return;
using ::testing::SetArgPointee;
using ::testing::StrictMock;

/**
 * @brief Validate that vector-state reads use the ISER register family.
 * @summary Confirms that `NVIC__enGetVectorState` delegates to `NVIC__enReadValue`
 *          with `NVIC_ISER_OFFSET` and forwards the returned enable state.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - NVIC_EnableDriverMock bridge
 * - Original source under test: NVIC_Enable.c@endverbatim
 */
TEST(NVIC_EnableTest, GetVectorStateUsesISERReadPath)
{
    StrictMock<NVIC_EnableDriverMock> stMock;
    NVIC_EnableDriverMockScope stMockScope(&stMock);
    NVIC_nSTATE enStateReg;

    enStateReg = NVIC_enSTATE_UNDEF;

    EXPECT_CALL(stMock, ReadValue(NVIC_enMODULE_0, NVIC_enVECTOR_GPIOA, (uintptr_t) NVIC_ISER_OFFSET, testing::_))
        .WillOnce(DoAll(SetArgPointee<3>((UBase_t) NVIC_enSTATE_ENA), Return(NVIC_enERROR_OK)));

    EXPECT_EQ(NVIC_enERROR_OK,
              NVIC__enGetVectorState(NVIC_enMODULE_0, NVIC_enVECTOR_GPIOA, &enStateReg));
    EXPECT_EQ(NVIC_enSTATE_ENA, enStateReg);
}

/**
 * @brief Validate that disabling a vector writes through the ICER path.
 * @summary Confirms that `NVIC__enSetVectorState` selects `NVIC_ICER_OFFSET`
 *          and writes the enabled bit marker when the requested state is disable.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - NVIC_EnableDriverMock bridge
 * - Original source under test: NVIC_Enable.c@endverbatim
 */
TEST(NVIC_EnableTest, SetVectorStateUsesICERForDisable)
{
    StrictMock<NVIC_EnableDriverMock> stMock;
    NVIC_EnableDriverMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock,
                SetWriteValue(NVIC_enMODULE_0,
                              NVIC_enVECTOR_UART0,
                              (uintptr_t) NVIC_ICER_OFFSET,
                              (UBase_t) NVIC_enSTATE_ENA))
        .WillOnce(Return(NVIC_enERROR_OK));

    EXPECT_EQ(NVIC_enERROR_OK,
              NVIC__enSetVectorState(NVIC_enMODULE_0, NVIC_enVECTOR_UART0, NVIC_enSTATE_DIS));
}

/**
 * @brief Validate that enabling a vector writes through the ISER path.
 * @summary Confirms that `NVIC__enSetVectorState` selects `NVIC_ISER_OFFSET`
 *          and writes the enabled bit marker when the requested state is enable.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - NVIC_EnableDriverMock bridge
 * - Original source under test: NVIC_Enable.c@endverbatim
 */
TEST(NVIC_EnableTest, SetVectorStateUsesISERForEnable)
{
    StrictMock<NVIC_EnableDriverMock> stMock;
    NVIC_EnableDriverMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock,
                SetWriteValue(NVIC_enMODULE_0,
                              NVIC_enVECTOR_UART1,
                              (uintptr_t) NVIC_ISER_OFFSET,
                              (UBase_t) NVIC_enSTATE_ENA))
        .WillOnce(Return(NVIC_enERROR_OK));

    EXPECT_EQ(NVIC_enERROR_OK,
              NVIC__enSetVectorState(NVIC_enMODULE_0, NVIC_enVECTOR_UART1, NVIC_enSTATE_ENA));
}

/**
 * @brief Validate that priority programming precedes vector enablement.
 * @summary Confirms that `NVIC__enEnableVector` first programs priority and then
 *          enables the vector through the ISER write path when priority succeeds.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - NVIC_EnableDriverMock bridge
 * - Original source under test: NVIC_Enable.c@endverbatim
 */
TEST(NVIC_EnableTest, EnableVectorProgramsPriorityBeforeEnablingState)
{
    StrictMock<NVIC_EnableDriverMock> stMock;
    NVIC_EnableDriverMockScope stMockScope(&stMock);
    InSequence stSequence;

    EXPECT_CALL(stMock, SetVectorPriority(NVIC_enMODULE_0, NVIC_enVECTOR_SSI0, NVIC_enPRI3))
        .WillOnce(Return(NVIC_enERROR_OK));
    EXPECT_CALL(stMock,
                SetWriteValue(NVIC_enMODULE_0,
                              NVIC_enVECTOR_SSI0,
                              (uintptr_t) NVIC_ISER_OFFSET,
                              (UBase_t) NVIC_enSTATE_ENA))
        .WillOnce(Return(NVIC_enERROR_OK));

    EXPECT_EQ(NVIC_enERROR_OK,
              NVIC__enEnableVector(NVIC_enMODULE_0, NVIC_enVECTOR_SSI0, NVIC_enPRI3));
}

/**
 * @brief Validate that enable flow stops when priority programming fails.
 * @summary Confirms that `NVIC__enEnableVector` propagates the priority error and
 *          does not attempt the state-enable write when the priority helper fails.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - NVIC_EnableDriverMock bridge
 * - Original source under test: NVIC_Enable.c@endverbatim
 */
TEST(NVIC_EnableTest, EnableVectorStopsWhenPriorityProgrammingFails)
{
    StrictMock<NVIC_EnableDriverMock> stMock;
    NVIC_EnableDriverMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, SetVectorPriority(NVIC_enMODULE_0, NVIC_enVECTOR_I2C0, NVIC_enPRI5))
        .WillOnce(Return(NVIC_enERROR_VALUE));

    EXPECT_EQ(NVIC_enERROR_VALUE,
              NVIC__enEnableVector(NVIC_enMODULE_0, NVIC_enVECTOR_I2C0, NVIC_enPRI5));
}

/**
 * @brief Validate that disable-vector wrapper delegates to the ICER state path.
 * @summary Confirms that `NVIC__enDisableVector` reaches the same disable write
 *          path as `NVIC__enSetVectorState(..., NVIC_enSTATE_DIS)`.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - NVIC_EnableDriverMock bridge
 * - Original source under test: NVIC_Enable.c@endverbatim
 */
TEST(NVIC_EnableTest, DisableVectorUsesDisableStatePath)
{
    StrictMock<NVIC_EnableDriverMock> stMock;
    NVIC_EnableDriverMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock,
                SetWriteValue(NVIC_enMODULE_0,
                              NVIC_enVECTOR_TIMER0A,
                              (uintptr_t) NVIC_ICER_OFFSET,
                              (UBase_t) NVIC_enSTATE_ENA))
        .WillOnce(Return(NVIC_enERROR_OK));

    EXPECT_EQ(NVIC_enERROR_OK,
              NVIC__enDisableVector(NVIC_enMODULE_0, NVIC_enVECTOR_TIMER0A));
}

/**
 * @brief Validate that undefined state now routes through the disable path.
 * @summary Confirms that `NVIC__enSetVectorState` only uses the ISER enable path
 *          for `NVIC_enSTATE_ENA`, while `NVIC_enSTATE_UNDEF` follows the same
 *          ICER path as disable instead of being treated as enable.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - NVIC_EnableDriverMock bridge
 * - Original source under test: NVIC_Enable.c@endverbatim
 */
TEST(NVIC_EnableTest, SetVectorStateUsesDisablePathForUndefinedState)
{
    StrictMock<NVIC_EnableDriverMock> stMock;
    NVIC_EnableDriverMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock,
                SetWriteValue(NVIC_enMODULE_0,
                              NVIC_enVECTOR_TIMER1A,
                              (uintptr_t) NVIC_ICER_OFFSET,
                              (UBase_t) NVIC_enSTATE_ENA))
        .WillOnce(Return(NVIC_enERROR_OK));

    EXPECT_EQ(NVIC_enERROR_OK,
              NVIC__enSetVectorState(NVIC_enMODULE_0, NVIC_enVECTOR_TIMER1A, NVIC_enSTATE_UNDEF));
}