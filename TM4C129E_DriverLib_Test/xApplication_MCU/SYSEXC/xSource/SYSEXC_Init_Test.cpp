/**
 *
 * @file SYSEXC_Init_Test.cpp
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
 * @verbatim 30 mar. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 30 mar. 2026   GitHub Copilot   1.0         initial Version@endverbatim
 */

extern "C"
{
#include <xApplication_MCU/SYSEXC/xHeader/SYSEXC_Init.h>
}

#include <tm4c129e_test/SYSEXC_InitDriverMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::InSequence;
using ::testing::Return;
using ::testing::StrictMock;

namespace
{
void TM4C129E_DriverLib_Test__vDummyIRQVectorHandler(void)
{
}
}

/**
 * @brief Validate module validation failure in the SYSEXC init helper.
 * @summary Confirms that `SYSEXC__enInit` propagates `MCU__enCheckParams`
 *          errors and exits before any vector-registration or interrupt-source
 *          programming calls occur.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSEXC_InitDriverMock bridge
 * - Original source under test: SYSEXC_Init.c@endverbatim
 */
TEST(SYSEXC_InitTest, InitPropagatesModuleValidationError)
{
    StrictMock<SYSEXC_InitDriverMock> stMock;
    SYSEXC_InitDriverMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, CheckParams((UBase_t) SYSEXC_enMODULE_UNDEF, (UBase_t) SYSEXC_enMODULE_MAX))
        .WillOnce(Return(MCU_enERROR_VALUE));

    EXPECT_EQ(SYSEXC_enERROR_VALUE,
              SYSEXC__enInit(SYSEXC_enMODULE_UNDEF, SYSEXC_enINTMASK_DIV0, SYSEXC_enPRI3));
}

/**
 * @brief Validate the full ordered init sequence for SYSEXC.
 * @summary Confirms that `SYSEXC__enInit` validates the module, obtains and
 *          registers the IRQ vector handler, disables and clears all sources,
 *          enables the requested source mask, and finally enables the vector
 *          with the caller-provided priority.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSEXC_InitDriverMock bridge
 * - Original source under test: SYSEXC_Init.c@endverbatim
 */
TEST(SYSEXC_InitTest, InitPerformsExpectedOrderedSetup)
{
    StrictMock<SYSEXC_InitDriverMock> stMock;
    SYSEXC_InitDriverMockScope stMockScope(&stMock);
    InSequence stSequence;
    const SYSEXC_pvfIRQVectorHandler_t pfHandler = &TM4C129E_DriverLib_Test__vDummyIRQVectorHandler;

    EXPECT_CALL(stMock, CheckParams((UBase_t) SYSEXC_enMODULE_0, (UBase_t) SYSEXC_enMODULE_MAX))
        .WillOnce(Return(MCU_enERROR_OK));
    EXPECT_CALL(stMock, GetIRQVectorHandler(SYSEXC_enMODULE_0))
        .WillOnce(Return(pfHandler));
    EXPECT_CALL(stMock, RegisterIRQVectorHandler(SYSEXC_enMODULE_0, pfHandler))
        .WillOnce(Return(SYSEXC_enERROR_OK));
    EXPECT_CALL(stMock, DisableInterruptSourceByMask(SYSEXC_enMODULE_0, SYSEXC_enINTMASK_ALL))
        .WillOnce(Return(SYSEXC_enERROR_OK));
    EXPECT_CALL(stMock, ClearInterruptSourceByMask(SYSEXC_enMODULE_0, SYSEXC_enINTMASK_ALL))
        .WillOnce(Return(SYSEXC_enERROR_OK));
    EXPECT_CALL(stMock, EnableInterruptSourceByMask(SYSEXC_enMODULE_0, SYSEXC_enINTMASK_DIV0))
        .WillOnce(Return(SYSEXC_enERROR_OK));
    EXPECT_CALL(stMock, EnableInterruptVectorWithPriority(SYSEXC_enMODULE_0, SYSEXC_enPRI3))
        .WillOnce(Return(SYSEXC_enERROR_OK));

    EXPECT_EQ(SYSEXC_enERROR_OK,
              SYSEXC__enInit(SYSEXC_enMODULE_0, SYSEXC_enINTMASK_DIV0, SYSEXC_enPRI3));
}

/**
 * @brief Validate early exit after an interrupt-source programming failure.
 * @summary Confirms that `SYSEXC__enInit` stops after the first failing setup
 *          step and propagates that error without attempting later source-enable
 *          or vector-enable calls.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSEXC_InitDriverMock bridge
 * - Original source under test: SYSEXC_Init.c@endverbatim
 */
TEST(SYSEXC_InitTest, InitStopsWhenClearAllSourcesFails)
{
    StrictMock<SYSEXC_InitDriverMock> stMock;
    SYSEXC_InitDriverMockScope stMockScope(&stMock);
    InSequence stSequence;
    const SYSEXC_pvfIRQVectorHandler_t pfHandler = &TM4C129E_DriverLib_Test__vDummyIRQVectorHandler;

    EXPECT_CALL(stMock, CheckParams((UBase_t) SYSEXC_enMODULE_0, (UBase_t) SYSEXC_enMODULE_MAX))
        .WillOnce(Return(MCU_enERROR_OK));
    EXPECT_CALL(stMock, GetIRQVectorHandler(SYSEXC_enMODULE_0))
        .WillOnce(Return(pfHandler));
    EXPECT_CALL(stMock, RegisterIRQVectorHandler(SYSEXC_enMODULE_0, pfHandler))
        .WillOnce(Return(SYSEXC_enERROR_OK));
    EXPECT_CALL(stMock, DisableInterruptSourceByMask(SYSEXC_enMODULE_0, SYSEXC_enINTMASK_ALL))
        .WillOnce(Return(SYSEXC_enERROR_OK));
    EXPECT_CALL(stMock, ClearInterruptSourceByMask(SYSEXC_enMODULE_0, SYSEXC_enINTMASK_ALL))
        .WillOnce(Return(SYSEXC_enERROR_RANGE));

    EXPECT_EQ(SYSEXC_enERROR_RANGE,
              SYSEXC__enInit(SYSEXC_enMODULE_0, SYSEXC_enINTMASK_DIV0, SYSEXC_enPRI3));
}