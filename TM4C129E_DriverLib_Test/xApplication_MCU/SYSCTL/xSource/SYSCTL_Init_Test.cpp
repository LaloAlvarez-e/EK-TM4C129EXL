/**
 *
 * @file SYSCTL_Init_Test.cpp
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
 * @verbatim 3 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 3 abr. 2026    GitHub Copilot   1.0         initial Version@endverbatim
 */

extern "C"
{
#include <xApplication_MCU/SYSCTL/xHeader/SYSCTL_Init.h>
}

#include <tm4c129e_test/SYSCTL_InitDriverMock.h>

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
 * @brief Validate module validation failure in the SYSCTL init helper.
 * @summary Confirms that `SYSCTL__enInit` propagates `MCU__enCheckParams`
 *          errors and exits before any IRQ-handler registration or interrupt-
 *          source programming calls occur.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_InitDriverMock bridge
 * - Original source under test: SYSCTL_Init.c@endverbatim
 */
TEST(SYSCTL_InitTest, InitPropagatesModuleValidationError)
{
    StrictMock<SYSCTL_InitDriverMock> stMock;
    SYSCTL_InitDriverMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, CheckParams((UBase_t) SYSCTL_enMODULE_UNDEF, (UBase_t) SYSCTL_enMODULE_MAX))
        .WillOnce(Return(MCU_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE,
              SYSCTL__enInit(SYSCTL_enMODULE_UNDEF,
                             SYSCTL_enINTMASK_MOSC_FAILURE,
                             SYSCTL_enPRI3));
}

/**
 * @brief Validate the full ordered init sequence when a source mask is enabled.
 * @summary Confirms that `SYSCTL__enInit` validates the module, obtains and
 *          registers the IRQ vector handler, disables and clears all SYSCTL
 *          interrupt sources, enables the requested mask, and finally enables
 *          the interrupt vector with the caller-provided priority.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_InitDriverMock bridge
 * - Original source under test: SYSCTL_Init.c@endverbatim
 */
TEST(SYSCTL_InitTest, InitPerformsExpectedOrderedSetupWithVectorEnable)
{
    StrictMock<SYSCTL_InitDriverMock> stMock;
    SYSCTL_InitDriverMockScope stMockScope(&stMock);
    InSequence stSequence;
    const SYSCTL_TestIRQVectorHandler_t pfHandler = &TM4C129E_DriverLib_Test__vDummyIRQVectorHandler;

    EXPECT_CALL(stMock, CheckParams((UBase_t) SYSCTL_enMODULE_0, (UBase_t) SYSCTL_enMODULE_MAX))
        .WillOnce(Return(MCU_enERROR_OK));
    EXPECT_CALL(stMock, GetIRQVectorHandler())
        .WillOnce(Return(pfHandler));
    EXPECT_CALL(stMock, RegisterIRQVectorHandler(pfHandler))
        .WillOnce(Return(SYSCTL_enERROR_OK));
    EXPECT_CALL(stMock, DisableInterruptSourceByMask(SYSCTL_enMODULE_0, SYSCTL_enINTMASK_ALL))
        .WillOnce(Return(SYSCTL_enERROR_OK));
    EXPECT_CALL(stMock, ClearInterruptSourceByMask(SYSCTL_enMODULE_0, SYSCTL_enINTMASK_ALL))
        .WillOnce(Return(SYSCTL_enERROR_OK));
    EXPECT_CALL(stMock, EnableInterruptSourceByMask(SYSCTL_enMODULE_0, SYSCTL_enINTMASK_MOSC_FAILURE))
        .WillOnce(Return(SYSCTL_enERROR_OK));
    EXPECT_CALL(stMock, EnableInterruptVector(SYSCTL_enPRI3))
        .WillOnce(Return(SYSCTL_enERROR_OK));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enInit(SYSCTL_enMODULE_0,
                             SYSCTL_enINTMASK_MOSC_FAILURE,
                             SYSCTL_enPRI3));
}

/**
 * @brief Validate early exit after an IRQ-registration failure.
 * @summary Confirms that `SYSCTL__enInit` propagates IRQ-registration failures
 *          before any interrupt-source disable, clear, enable, or vector-state
 *          operations occur.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_InitDriverMock bridge
 * - Original source under test: SYSCTL_Init.c@endverbatim
 */
TEST(SYSCTL_InitTest, InitStopsWhenIRQRegistrationFails)
{
    StrictMock<SYSCTL_InitDriverMock> stMock;
    SYSCTL_InitDriverMockScope stMockScope(&stMock);
    InSequence stSequence;
    const SYSCTL_TestIRQVectorHandler_t pfHandler = &TM4C129E_DriverLib_Test__vDummyIRQVectorHandler;

    EXPECT_CALL(stMock, CheckParams((UBase_t) SYSCTL_enMODULE_0, (UBase_t) SYSCTL_enMODULE_MAX))
        .WillOnce(Return(MCU_enERROR_OK));
    EXPECT_CALL(stMock, GetIRQVectorHandler())
        .WillOnce(Return(pfHandler));
    EXPECT_CALL(stMock, RegisterIRQVectorHandler(pfHandler))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE,
              SYSCTL__enInit(SYSCTL_enMODULE_0,
                             SYSCTL_enINTMASK_MOSC_FAILURE,
                             SYSCTL_enPRI3));
}

/**
 * @brief Validate the init sequence when no interrupt source mask is requested.
 * @summary Confirms that `SYSCTL__enInit` still performs the ordered handler and
 *          source setup when the requested mask is `SYSCTL_enINTMASK_NONE`, then
 *          disables the vector instead of enabling it.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_InitDriverMock bridge
 * - Original source under test: SYSCTL_Init.c@endverbatim
 */
TEST(SYSCTL_InitTest, InitDisablesVectorWhenInterruptMaskIsNone)
{
    StrictMock<SYSCTL_InitDriverMock> stMock;
    SYSCTL_InitDriverMockScope stMockScope(&stMock);
    InSequence stSequence;
    const SYSCTL_TestIRQVectorHandler_t pfHandler = &TM4C129E_DriverLib_Test__vDummyIRQVectorHandler;

    EXPECT_CALL(stMock, CheckParams((UBase_t) SYSCTL_enMODULE_0, (UBase_t) SYSCTL_enMODULE_MAX))
        .WillOnce(Return(MCU_enERROR_OK));
    EXPECT_CALL(stMock, GetIRQVectorHandler())
        .WillOnce(Return(pfHandler));
    EXPECT_CALL(stMock, RegisterIRQVectorHandler(pfHandler))
        .WillOnce(Return(SYSCTL_enERROR_OK));
    EXPECT_CALL(stMock, DisableInterruptSourceByMask(SYSCTL_enMODULE_0, SYSCTL_enINTMASK_ALL))
        .WillOnce(Return(SYSCTL_enERROR_OK));
    EXPECT_CALL(stMock, ClearInterruptSourceByMask(SYSCTL_enMODULE_0, SYSCTL_enINTMASK_ALL))
        .WillOnce(Return(SYSCTL_enERROR_OK));
    EXPECT_CALL(stMock, EnableInterruptSourceByMask(SYSCTL_enMODULE_0, SYSCTL_enINTMASK_NONE))
        .WillOnce(Return(SYSCTL_enERROR_OK));
    EXPECT_CALL(stMock, DisableInterruptVector())
        .WillOnce(Return(SYSCTL_enERROR_OK));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enInit(SYSCTL_enMODULE_0,
                             SYSCTL_enINTMASK_NONE,
                             SYSCTL_enPRI2));
}

/**
 * @brief Validate vector-enable failure propagation in the SYSCTL init helper.
 * @summary Confirms that `SYSCTL__enInit` propagates interrupt-vector enable
 *          failures after the requested source mask has been configured.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_InitDriverMock bridge
 * - Original source under test: SYSCTL_Init.c@endverbatim
 */
TEST(SYSCTL_InitTest, InitPropagatesVectorEnableFailure)
{
    StrictMock<SYSCTL_InitDriverMock> stMock;
    SYSCTL_InitDriverMockScope stMockScope(&stMock);
    InSequence stSequence;
    const SYSCTL_TestIRQVectorHandler_t pfHandler = &TM4C129E_DriverLib_Test__vDummyIRQVectorHandler;

    EXPECT_CALL(stMock, CheckParams((UBase_t) SYSCTL_enMODULE_0, (UBase_t) SYSCTL_enMODULE_MAX))
        .WillOnce(Return(MCU_enERROR_OK));
    EXPECT_CALL(stMock, GetIRQVectorHandler())
        .WillOnce(Return(pfHandler));
    EXPECT_CALL(stMock, RegisterIRQVectorHandler(pfHandler))
        .WillOnce(Return(SYSCTL_enERROR_OK));
    EXPECT_CALL(stMock, DisableInterruptSourceByMask(SYSCTL_enMODULE_0, SYSCTL_enINTMASK_ALL))
        .WillOnce(Return(SYSCTL_enERROR_OK));
    EXPECT_CALL(stMock, ClearInterruptSourceByMask(SYSCTL_enMODULE_0, SYSCTL_enINTMASK_ALL))
        .WillOnce(Return(SYSCTL_enERROR_OK));
    EXPECT_CALL(stMock, EnableInterruptSourceByMask(SYSCTL_enMODULE_0, SYSCTL_enINTMASK_PLL_LOCK))
        .WillOnce(Return(SYSCTL_enERROR_OK));
    EXPECT_CALL(stMock, EnableInterruptVector(SYSCTL_enPRI1))
        .WillOnce(Return(SYSCTL_enERROR_RANGE));

    EXPECT_EQ(SYSCTL_enERROR_RANGE,
              SYSCTL__enInit(SYSCTL_enMODULE_0,
                             SYSCTL_enINTMASK_PLL_LOCK,
                             SYSCTL_enPRI1));
}

/**
 * @brief Validate vector-disable failure propagation in the SYSCTL init helper.
 * @summary Confirms that `SYSCTL__enInit` propagates interrupt-vector disable
 *          failures on the `SYSCTL_enINTMASK_NONE` branch after source setup.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_InitDriverMock bridge
 * - Original source under test: SYSCTL_Init.c@endverbatim
 */
TEST(SYSCTL_InitTest, InitPropagatesVectorDisableFailure)
{
    StrictMock<SYSCTL_InitDriverMock> stMock;
    SYSCTL_InitDriverMockScope stMockScope(&stMock);
    InSequence stSequence;
    const SYSCTL_TestIRQVectorHandler_t pfHandler = &TM4C129E_DriverLib_Test__vDummyIRQVectorHandler;

    EXPECT_CALL(stMock, CheckParams((UBase_t) SYSCTL_enMODULE_0, (UBase_t) SYSCTL_enMODULE_MAX))
        .WillOnce(Return(MCU_enERROR_OK));
    EXPECT_CALL(stMock, GetIRQVectorHandler())
        .WillOnce(Return(pfHandler));
    EXPECT_CALL(stMock, RegisterIRQVectorHandler(pfHandler))
        .WillOnce(Return(SYSCTL_enERROR_OK));
    EXPECT_CALL(stMock, DisableInterruptSourceByMask(SYSCTL_enMODULE_0, SYSCTL_enINTMASK_ALL))
        .WillOnce(Return(SYSCTL_enERROR_OK));
    EXPECT_CALL(stMock, ClearInterruptSourceByMask(SYSCTL_enMODULE_0, SYSCTL_enINTMASK_ALL))
        .WillOnce(Return(SYSCTL_enERROR_OK));
    EXPECT_CALL(stMock, EnableInterruptSourceByMask(SYSCTL_enMODULE_0, SYSCTL_enINTMASK_NONE))
        .WillOnce(Return(SYSCTL_enERROR_OK));
    EXPECT_CALL(stMock, DisableInterruptVector())
        .WillOnce(Return(SYSCTL_enERROR_RANGE));

    EXPECT_EQ(SYSCTL_enERROR_RANGE,
              SYSCTL__enInit(SYSCTL_enMODULE_0,
                             SYSCTL_enINTMASK_NONE,
                             SYSCTL_enPRI2));
}

/**
 * @brief Validate early exit after a clear-all-sources failure.
 * @summary Confirms that `SYSCTL__enInit` stops after the first failing setup
 *          step and propagates that error without attempting later requested-
 *          source programming or vector enable/disable calls.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_InitDriverMock bridge
 * - Original source under test: SYSCTL_Init.c@endverbatim
 */
TEST(SYSCTL_InitTest, InitStopsWhenClearAllSourcesFails)
{
    StrictMock<SYSCTL_InitDriverMock> stMock;
    SYSCTL_InitDriverMockScope stMockScope(&stMock);
    InSequence stSequence;
    const SYSCTL_TestIRQVectorHandler_t pfHandler = &TM4C129E_DriverLib_Test__vDummyIRQVectorHandler;

    EXPECT_CALL(stMock, CheckParams((UBase_t) SYSCTL_enMODULE_0, (UBase_t) SYSCTL_enMODULE_MAX))
        .WillOnce(Return(MCU_enERROR_OK));
    EXPECT_CALL(stMock, GetIRQVectorHandler())
        .WillOnce(Return(pfHandler));
    EXPECT_CALL(stMock, RegisterIRQVectorHandler(pfHandler))
        .WillOnce(Return(SYSCTL_enERROR_OK));
    EXPECT_CALL(stMock, DisableInterruptSourceByMask(SYSCTL_enMODULE_0, SYSCTL_enINTMASK_ALL))
        .WillOnce(Return(SYSCTL_enERROR_OK));
    EXPECT_CALL(stMock, ClearInterruptSourceByMask(SYSCTL_enMODULE_0, SYSCTL_enINTMASK_ALL))
        .WillOnce(Return(SYSCTL_enERROR_RANGE));

    EXPECT_EQ(SYSCTL_enERROR_RANGE,
              SYSCTL__enInit(SYSCTL_enMODULE_0,
                             SYSCTL_enINTMASK_MOSC_POWERUP,
                             SYSCTL_enPRI3));
}