/**
 *
 * @file SYSEXC_InterruptRoutine_Vector_Test.cpp
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
#include <xApplication_MCU/SYSEXC/Interrupt/InterruptRoutine/xHeader/SYSEXC_InterruptRoutine_Vector.h>
#include <xDriver_MCU/Core/SCB/Peripheral/Register/xHeader/SCB_RegisterPeripheral.h>
#include <xDriver_MCU/Core/SCB/Peripheral/Register/RegisterDefines/xHeader/SCB_RegisterDefines_INTCTLR.h>
#include <xDriver_MCU/SYSEXC/Peripheral/Register/xHeader/SYSEXC_RegisterAddress.h>
}

#include <tm4c129e_test/SYSEXC_InterruptRoutineMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Invoke;
using ::testing::Return;
using ::testing::StrictMock;

namespace
{
struct SYSEXC_CallbackRecord
{
    uintptr_t uptrModule;
    void* pvArgument;
    UBase_t uxCallCount;
};

struct SYSEXC_HostModuleRegisters
{
    UBase_t RIS;
    UBase_t IM;
    UBase_t MIS;
    UBase_t IC;
};

SYSEXC_CallbackRecord g_stCallbackRecord = {0UL, nullptr, 0UL};
SYSEXC_CallbackRecord g_stDiv0CallbackRecord = {0UL, nullptr, 0UL};
SYSEXC_CallbackRecord g_stOverflowCallbackRecord = {0UL, nullptr, 0UL};

void TM4C129E_DriverLib_Test__vIRQSourceHandlerRecorder(uintptr_t uptrModuleArg, void* pvArgument)
{
    g_stCallbackRecord.uptrModule = uptrModuleArg;
    g_stCallbackRecord.pvArgument = pvArgument;
    g_stCallbackRecord.uxCallCount++;
}

void TM4C129E_DriverLib_Test__vIRQSourceHandlerDiv0(uintptr_t uptrModuleArg, void* pvArgument)
{
    g_stDiv0CallbackRecord.uptrModule = uptrModuleArg;
    g_stDiv0CallbackRecord.pvArgument = pvArgument;
    g_stDiv0CallbackRecord.uxCallCount++;
}

void TM4C129E_DriverLib_Test__vIRQSourceHandlerOverflow(uintptr_t uptrModuleArg, void* pvArgument)
{
    g_stOverflowCallbackRecord.uptrModule = uptrModuleArg;
    g_stOverflowCallbackRecord.pvArgument = pvArgument;
    g_stOverflowCallbackRecord.uxCallCount++;
}

class SYSEXC_InterruptRoutineVectorTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        TM4C129E_DriverLib_Test__u32HostSCBICSRValue = 0UL;
        g_stCallbackRecord.uptrModule = 0UL;
        g_stCallbackRecord.pvArgument = nullptr;
        g_stCallbackRecord.uxCallCount = 0UL;
        g_stDiv0CallbackRecord.uptrModule = 0UL;
        g_stDiv0CallbackRecord.pvArgument = nullptr;
        g_stDiv0CallbackRecord.uxCallCount = 0UL;
        g_stOverflowCallbackRecord.uptrModule = 0UL;
        g_stOverflowCallbackRecord.pvArgument = nullptr;
        g_stOverflowCallbackRecord.uxCallCount = 0UL;
    }
};
}

/**
 * @brief Validate report creation for the software SYSEXC path.
 * @summary Confirms that `SYSEXC__vIRQVectorHandlerReport` generates a software
 *          report when no architected status bits are set, copies the stacked
 *          context, extracts the stacked PC fault address, and derives the
 *          active and stacked vector values from ICSR and the saved xPSR.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSEXC_InterruptRoutineMock bridge
 * - SCB host ICSR overlay
 * - Original source under test: SYSEXC_InterruptRoutine_Vector.c@endverbatim
 */
TEST_F(SYSEXC_InterruptRoutineVectorTest, ReportHandlerBuildsSoftwareReportFromContext)
{
    StrictMock<SYSEXC_InterruptRoutineMock> stMock;
    SYSEXC_InterruptRoutineMockScope stMockScope(&stMock);
    SYSEXC_HostModuleRegisters stModule;
    UBase_t uxContext[8UL];

    stModule.IM = 0UL;
    stModule.IC = 0UL;
    stModule.MIS = 0UL;
    TM4C129E_DriverLib_Test__u32HostSCBICSRValue = SCB_ICSR_R_VECTACTIVE_PENDSV;
    uxContext[0UL] = 0x10UL;
    uxContext[1UL] = 0x11UL;
    uxContext[2UL] = 0x12UL;
    uxContext[3UL] = 0x13UL;
    uxContext[4UL] = 0x14UL;
    uxContext[5UL] = 0x15UL;
    uxContext[6UL] = 0x20001234UL;
    uxContext[7UL] = 0x0000005AUL;

    EXPECT_CALL(stMock, InvokeReportHandler(testing::_))
        .WillOnce(Invoke([&uxContext](const SYSEXC_REPORT_t* pstReportArg)
        {
            ASSERT_NE(nullptr, pstReportArg);
            EXPECT_EQ(SYSEXC_enMODULE_0, pstReportArg->enModule);
            EXPECT_EQ(SYSEXC_enINT_SW, pstReportArg->enSource);
            EXPECT_EQ(SYSEXC_enINTMASK_NONE, pstReportArg->enStatusMask);
            EXPECT_EQ((UBase_t) 0x20001234UL, pstReportArg->uxFaultAddress);
            EXPECT_EQ((UBase_t) SCB_ICSR_R_VECTACTIVE_PENDSV, pstReportArg->uxICSR);
            EXPECT_EQ((UBase_t) SCB_ICSR_R_VECTACTIVE_PENDSV, pstReportArg->uxActiveVector);
            EXPECT_EQ((UBase_t) 0x5AUL, pstReportArg->uxStackedVector);
            EXPECT_EQ((UBase_t) uxContext[0UL], pstReportArg->uxContext[0UL]);
            EXPECT_EQ((UBase_t) uxContext[7UL], pstReportArg->uxContext[7UL]);
        }));

    SYSEXC__vIRQVectorHandlerReport((uintptr_t) &stModule, (void*) uxContext);
}

/**
 * @brief Validate report creation for multiple active SYSEXC status bits.
 * @summary Confirms that `SYSEXC__vIRQVectorHandlerReport` emits one report per
 *          asserted architected status bit and preserves the full original MIS
 *          status mask in each generated report.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSEXC_InterruptRoutineMock bridge
 * - SCB host ICSR overlay
 * - Original source under test: SYSEXC_InterruptRoutine_Vector.c@endverbatim
 */
TEST_F(SYSEXC_InterruptRoutineVectorTest, ReportHandlerEmitsOneReportPerAssertedSource)
{
    StrictMock<SYSEXC_InterruptRoutineMock> stMock;
    SYSEXC_InterruptRoutineMockScope stMockScope(&stMock);
    SYSEXC_HostModuleRegisters stModule;
    UBase_t uxContext[8UL];
    UBase_t uxReportIndex = 0UL;

    stModule.IM = 0UL;
    stModule.IC = 0UL;
    stModule.MIS = (UBase_t) (SYSEXC_enINTMASK_DENORMAL | SYSEXC_enINTMASK_INEXACT);
    TM4C129E_DriverLib_Test__u32HostSCBICSRValue = SCB_ICSR_R_VECTACTIVE_SYSEXC;
    uxContext[0UL] = 1UL;
    uxContext[1UL] = 2UL;
    uxContext[2UL] = 3UL;
    uxContext[3UL] = 4UL;
    uxContext[4UL] = 5UL;
    uxContext[5UL] = 6UL;
    uxContext[6UL] = 0x20005678UL;
    uxContext[7UL] = 0x00000123UL;

    EXPECT_CALL(stMock, InvokeReportHandler(testing::_))
        .Times(2)
        .WillRepeatedly(Invoke([&uxReportIndex](const SYSEXC_REPORT_t* pstReportArg)
        {
            ASSERT_NE(nullptr, pstReportArg);
            EXPECT_EQ((SYSEXC_nINTMASK) (SYSEXC_enINTMASK_DENORMAL | SYSEXC_enINTMASK_INEXACT), pstReportArg->enStatusMask);
            if(0UL == uxReportIndex)
            {
                EXPECT_EQ(SYSEXC_enINT_DENORMAL, pstReportArg->enSource);
            }
            else
            {
                EXPECT_EQ(SYSEXC_enINT_INEXACT, pstReportArg->enSource);
            }
            uxReportIndex++;
        }));

    SYSEXC__vIRQVectorHandlerReport((uintptr_t) &stModule, (void*) uxContext);
    EXPECT_EQ((UBase_t) 2UL, uxReportIndex);
}

/**
 * @brief Validate custom callback dispatch for the software SYSEXC path.
 * @summary Confirms that `SYSEXC__vIRQVectorHandlerCustom` requests the software
 *          source callback when no architected status bits are set and forwards
 *          the SYSEXC base plus software-source enum argument to that callback.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSEXC_InterruptRoutineMock bridge
 * - Original source under test: SYSEXC_InterruptRoutine_Vector.c@endverbatim
 */
TEST_F(SYSEXC_InterruptRoutineVectorTest, CustomHandlerDispatchesSoftwareCallbackWhenNoBitsAreSet)
{
    StrictMock<SYSEXC_InterruptRoutineMock> stMock;
    SYSEXC_InterruptRoutineMockScope stMockScope(&stMock);
    SYSEXC_HostModuleRegisters stModule;
    const SYSEXC_TestIRQSourceHandler_t pfHandler = &TM4C129E_DriverLib_Test__vIRQSourceHandlerRecorder;

    stModule.IM = 0UL;
    stModule.IC = 0UL;
    stModule.MIS = 0UL;

    EXPECT_CALL(stMock, GetIRQSourceHandler(SYSEXC_enMODULE_0, SYSEXC_enINT_SW))
        .WillOnce(Return(pfHandler));

    SYSEXC__vIRQVectorHandlerCustom((uintptr_t) &stModule, nullptr);

    EXPECT_EQ((uintptr_t) SYSEXC_BASE, g_stCallbackRecord.uptrModule);
    EXPECT_EQ((void*) SYSEXC_enINT_SW, g_stCallbackRecord.pvArgument);
    EXPECT_EQ((UBase_t) 1UL, g_stCallbackRecord.uxCallCount);
    EXPECT_EQ((UBase_t) 0UL, stModule.IC);
}

/**
 * @brief Validate custom callback dispatch and IC clearing for active sources.
 * @summary Confirms that `SYSEXC__vIRQVectorHandlerCustom` clears each asserted
 *          interrupt source in the IC register and dispatches the matching source
 *          callbacks in source-order for the active MIS bits.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSEXC_InterruptRoutineMock bridge
 * - Original source under test: SYSEXC_InterruptRoutine_Vector.c@endverbatim
 */
TEST_F(SYSEXC_InterruptRoutineVectorTest, CustomHandlerClearsAndDispatchesEachAssertedSource)
{
    StrictMock<SYSEXC_InterruptRoutineMock> stMock;
    SYSEXC_InterruptRoutineMockScope stMockScope(&stMock);
    SYSEXC_HostModuleRegisters stModule;
    const SYSEXC_TestIRQSourceHandler_t pfDiv0Handler = &TM4C129E_DriverLib_Test__vIRQSourceHandlerDiv0;
    const SYSEXC_TestIRQSourceHandler_t pfOverflowHandler = &TM4C129E_DriverLib_Test__vIRQSourceHandlerOverflow;

    stModule.IM = 0UL;
    stModule.IC = 0UL;
    stModule.MIS = (UBase_t) (SYSEXC_enINTMASK_DIV0 | SYSEXC_enINTMASK_OVERFLOW);

    EXPECT_CALL(stMock, GetIRQSourceHandler(SYSEXC_enMODULE_0, SYSEXC_enINT_DIV0))
        .WillOnce(Return(pfDiv0Handler));
    EXPECT_CALL(stMock, GetIRQSourceHandler(SYSEXC_enMODULE_0, SYSEXC_enINT_OVERFLOW))
        .WillOnce(Return(pfOverflowHandler));

    SYSEXC__vIRQVectorHandlerCustom((uintptr_t) &stModule, nullptr);

    EXPECT_EQ((uintptr_t) SYSEXC_BASE, g_stDiv0CallbackRecord.uptrModule);
    EXPECT_EQ((void*) SYSEXC_enINT_DIV0, g_stDiv0CallbackRecord.pvArgument);
    EXPECT_EQ((UBase_t) 1UL, g_stDiv0CallbackRecord.uxCallCount);
    EXPECT_EQ((uintptr_t) SYSEXC_BASE, g_stOverflowCallbackRecord.uptrModule);
    EXPECT_EQ((void*) SYSEXC_enINT_OVERFLOW, g_stOverflowCallbackRecord.pvArgument);
    EXPECT_EQ((UBase_t) 1UL, g_stOverflowCallbackRecord.uxCallCount);
    EXPECT_EQ((UBase_t) SYSEXC_enINTMASK_OVERFLOW, stModule.IC);
}