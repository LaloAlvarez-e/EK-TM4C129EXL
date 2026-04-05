/**
 *
 * @file SYSCTL_InterruptRoutine_Vector_Test.cpp
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
#include <xApplication_MCU/SYSCTL/Interrupt/InterruptRoutine/xHeader/SYSCTL_InterruptRoutine_Vector.h>
#include <xApplication_MCU/SYSCTL/Intrinsics/xHeader/SYSCTL_Dependencies.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_MISC.h>
}

#include <tm4c129e_test/SYSCTL_InterruptRoutineMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::InSequence;
using ::testing::Return;
using ::testing::StrictMock;

namespace
{
struct SYSCTL_CallbackRecord
{
    uintptr_t uptrModule;
    void* pvArgument;
    UBase_t uxMISCValue;
};

SYSCTL_CallbackRecord g_astCallbackRecord[(UBase_t) SYSCTL_enINT_MAX];
UBase_t g_uxCallbackCount = 0UL;

void TM4C129E_DriverLib_Test__vSYSCTLIRQSourceHandlerRecorder(uintptr_t uptrModuleArg, void* pvArgument)
{
    g_astCallbackRecord[g_uxCallbackCount].uptrModule = uptrModuleArg;
    g_astCallbackRecord[g_uxCallbackCount].pvArgument = pvArgument;
    g_astCallbackRecord[g_uxCallbackCount].uxMISCValue = TM4C129E_DriverLib_Test__u32HostSYSCTLMISCValue;
    g_uxCallbackCount++;
}

class SYSCTL_InterruptRoutineVectorTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        UBase_t uxIndex;

        TM4C129E_DriverLib_Test__u32HostSYSCTLMISCValue = 0UL;
        g_uxCallbackCount = 0UL;

        for(uxIndex = 0UL; uxIndex < (UBase_t) SYSCTL_enINT_MAX; uxIndex++)
        {
            g_astCallbackRecord[uxIndex].uptrModule = 0UL;
            g_astCallbackRecord[uxIndex].pvArgument = nullptr;
            g_astCallbackRecord[uxIndex].uxMISCValue = 0UL;
        }
    }
};
}

/**
 * @brief Validate software callback dispatch when no SYSCTL source is active.
 * @summary Confirms that `SYSCTL__vIRQVectorHandler` requests the software
 *          callback when no architected `MISC` source bit is asserted and
 *          forwards the SYSCTL base plus software-source enum argument.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_InterruptRoutineMock bridge
 * - SYSCTL host MISC register overlay
 * - Original source under test: SYSCTL_InterruptRoutine_Vector.c@endverbatim
 */
TEST_F(SYSCTL_InterruptRoutineVectorTest, IRQVectorHandlerDispatchesSoftwareCallbackWhenNoBitsAreSet)
{
    StrictMock<SYSCTL_InterruptRoutineMock> stMock;
    SYSCTL_InterruptRoutineMockScope stMockScope(&stMock);
    const SYSCTL_TestIRQSourceHandler_t pfHandler = &TM4C129E_DriverLib_Test__vSYSCTLIRQSourceHandlerRecorder;

    EXPECT_CALL(stMock, GetIRQSourceHandler(SYSCTL_enMODULE_0, SYSCTL_enINT_SW))
        .WillOnce(Return(pfHandler));

    SYSCTL__vIRQVectorHandler();

    EXPECT_EQ((UBase_t) 1UL, g_uxCallbackCount);
    EXPECT_EQ((uintptr_t) SYSCTL0_BASE, g_astCallbackRecord[0UL].uptrModule);
    EXPECT_EQ((void*) SYSCTL_enINT_SW, g_astCallbackRecord[0UL].pvArgument);
    EXPECT_EQ((UBase_t) 0UL, g_astCallbackRecord[0UL].uxMISCValue);
    EXPECT_EQ((UBase_t) 0UL, TM4C129E_DriverLib_Test__u32HostSYSCTLMISCValue);
}

/**
 * @brief Validate MISC clearing and callback dispatch for active SYSCTL sources.
 * @summary Confirms that `SYSCTL__vIRQVectorHandler` clears each asserted SYSCTL
 *          source through `MISC` and dispatches the matching callback in source
 *          order for BOR, MOSC failure, PLL lock, and MOSC power-up.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_InterruptRoutineMock bridge
 * - SYSCTL host MISC register overlay
 * - Original source under test: SYSCTL_InterruptRoutine_Vector.c@endverbatim
 */
TEST_F(SYSCTL_InterruptRoutineVectorTest, IRQVectorHandlerClearsAndDispatchesEachAssertedSource)
{
    StrictMock<SYSCTL_InterruptRoutineMock> stMock;
    SYSCTL_InterruptRoutineMockScope stMockScope(&stMock);
    const SYSCTL_TestIRQSourceHandler_t pfHandler = &TM4C129E_DriverLib_Test__vSYSCTLIRQSourceHandlerRecorder;
    const UBase_t uxActiveMask = (UBase_t) (SYSCTL_enINTMASK_BOR | SYSCTL_enINTMASK_MOSC_FAILURE |
            SYSCTL_enINTMASK_PLL_LOCK | SYSCTL_enINTMASK_MOSC_POWERUP);

    TM4C129E_DriverLib_Test__u32HostSYSCTLMISCValue = uxActiveMask;

    {
        InSequence stSequence;

        EXPECT_CALL(stMock, GetIRQSourceHandler(SYSCTL_enMODULE_0, SYSCTL_enINT_BOR))
            .WillOnce(Return(pfHandler));
        EXPECT_CALL(stMock, GetIRQSourceHandler(SYSCTL_enMODULE_0, SYSCTL_enINT_MOSC_FAILURE))
            .WillOnce(Return(pfHandler));
        EXPECT_CALL(stMock, GetIRQSourceHandler(SYSCTL_enMODULE_0, SYSCTL_enINT_PLL_LOCK))
            .WillOnce(Return(pfHandler));
        EXPECT_CALL(stMock, GetIRQSourceHandler(SYSCTL_enMODULE_0, SYSCTL_enINT_MOSC_POWERUP))
            .WillOnce(Return(pfHandler));
    }

    SYSCTL__vIRQVectorHandler();

    EXPECT_EQ((UBase_t) 4UL, g_uxCallbackCount);

    EXPECT_EQ((uintptr_t) SYSCTL0_BASE, g_astCallbackRecord[0UL].uptrModule);
    EXPECT_EQ((void*) SYSCTL_enINT_BOR, g_astCallbackRecord[0UL].pvArgument);
    EXPECT_EQ((UBase_t) SYSCTL_MISC_R_BOR_MASK, g_astCallbackRecord[0UL].uxMISCValue);

    EXPECT_EQ((uintptr_t) SYSCTL0_BASE, g_astCallbackRecord[1UL].uptrModule);
    EXPECT_EQ((void*) SYSCTL_enINT_MOSC_FAILURE, g_astCallbackRecord[1UL].pvArgument);
    EXPECT_EQ((UBase_t) SYSCTL_MISC_R_MOSC_FAILURE_MASK, g_astCallbackRecord[1UL].uxMISCValue);

    EXPECT_EQ((uintptr_t) SYSCTL0_BASE, g_astCallbackRecord[2UL].uptrModule);
    EXPECT_EQ((void*) SYSCTL_enINT_PLL_LOCK, g_astCallbackRecord[2UL].pvArgument);
    EXPECT_EQ((UBase_t) SYSCTL_MISC_R_PLL_LOCK_MASK, g_astCallbackRecord[2UL].uxMISCValue);

    EXPECT_EQ((uintptr_t) SYSCTL0_BASE, g_astCallbackRecord[3UL].uptrModule);
    EXPECT_EQ((void*) SYSCTL_enINT_MOSC_POWERUP, g_astCallbackRecord[3UL].pvArgument);
    EXPECT_EQ((UBase_t) SYSCTL_MISC_R_MOSC_POWERUP_MASK, g_astCallbackRecord[3UL].uxMISCValue);

    EXPECT_EQ((UBase_t) SYSCTL_MISC_R_MOSC_POWERUP_MASK, TM4C129E_DriverLib_Test__u32HostSYSCTLMISCValue);
}