/**
 *
 * @file SYSEXC_Report_Test.cpp
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
#include <xApplication_MCU/SYSEXC/xHeader/SYSEXC_Report.h>
}

#include <gtest/gtest.h>

namespace
{
struct SYSEXC_ReportHandlerRecord
{
    void* pvContext;
    const SYSEXC_REPORT_t* pstReport;
    UBase_t uxCallCount;
};

SYSEXC_ReportHandlerRecord g_stReportHandlerRecord = {nullptr, nullptr, 0UL};

MCU_nERROR TM4C129E_DriverLib_Test__enReportHandler(void* pvContextArg, const SYSEXC_REPORT_t* pstReportArg)
{
    g_stReportHandlerRecord.pvContext = pvContextArg;
    g_stReportHandlerRecord.pstReport = pstReportArg;
    g_stReportHandlerRecord.uxCallCount++;
    return MCU_enERROR_OK;
}

class SYSEXC_ReportTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        g_stReportHandlerRecord.pvContext = nullptr;
        g_stReportHandlerRecord.pstReport = nullptr;
        g_stReportHandlerRecord.uxCallCount = 0UL;
        EXPECT_EQ(SYSEXC_enERROR_OK, SYSEXC__enUnregisterReportHandler());
    }

    void TearDown() override
    {
        EXPECT_EQ(SYSEXC_enERROR_OK, SYSEXC__enUnregisterReportHandler());
    }
};
}

/**
 * @brief Validate null-handler rejection in report registration.
 * @summary Confirms that `SYSEXC__enRegisterReportHandler` rejects a null report
 *          callback and leaves the dispatch path inactive.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSEXC_Report.c
 * - Static callback state reset through `SYSEXC__enUnregisterReportHandler`@endverbatim
 */
TEST_F(SYSEXC_ReportTest, RegisterReportHandlerRejectsNullCallback)
{
    SYSEXC_REPORT_t stReport;

    stReport.enModule = SYSEXC_enMODULE_0;
    stReport.enSource = SYSEXC_enINT_DIV0;
    stReport.enStatusMask = SYSEXC_enINTMASK_DIV0;
    stReport.uxFaultAddress = 0x12345678UL;
    stReport.uxICSR = 0UL;
    stReport.uxActiveVector = 0UL;
    stReport.uxStackedVector = 0UL;
    stReport.uxContext[0UL] = 0UL;
    stReport.uxContext[1UL] = 0UL;
    stReport.uxContext[2UL] = 0UL;
    stReport.uxContext[3UL] = 0UL;
    stReport.uxContext[4UL] = 0UL;
    stReport.uxContext[5UL] = 0UL;
    stReport.uxContext[6UL] = 0UL;
    stReport.uxContext[7UL] = 0UL;

    EXPECT_EQ(SYSEXC_enERROR_POINTER,
              SYSEXC__enRegisterReportHandler((void*) 0x1234UL, (SYSEXC_pvfReportHandler_t) 0UL));

    SYSEXC__vInvokeReportHandler(&stReport);

    EXPECT_EQ((UBase_t) 0UL, g_stReportHandlerRecord.uxCallCount);
    EXPECT_EQ(nullptr, g_stReportHandlerRecord.pvContext);
    EXPECT_EQ(nullptr, g_stReportHandlerRecord.pstReport);
}

/**
 * @brief Validate that registration preserves context and dispatches the report.
 * @summary Confirms that `SYSEXC__enRegisterReportHandler` stores both the user
 *          context pointer and callback, and that `SYSEXC__vInvokeReportHandler`
 *          forwards the exact report pointer to that callback.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSEXC_Report.c
 * - Test callback recorder in this translation unit@endverbatim
 */
TEST_F(SYSEXC_ReportTest, RegisterReportHandlerDispatchesReportWithContext)
{
    SYSEXC_REPORT_t stReport;
    UBase_t uxContextMarker;

    uxContextMarker = 0xCAFEBABEU;
    stReport.enModule = SYSEXC_enMODULE_0;
    stReport.enSource = SYSEXC_enINT_INEXACT;
    stReport.enStatusMask = SYSEXC_enINTMASK_INEXACT;
    stReport.uxFaultAddress = 0x20000000UL;
    stReport.uxICSR = 0x1UL;
    stReport.uxActiveVector = 3UL;
    stReport.uxStackedVector = 11UL;
    stReport.uxContext[0UL] = 1UL;
    stReport.uxContext[1UL] = 2UL;
    stReport.uxContext[2UL] = 3UL;
    stReport.uxContext[3UL] = 4UL;
    stReport.uxContext[4UL] = 5UL;
    stReport.uxContext[5UL] = 6UL;
    stReport.uxContext[6UL] = 7UL;
    stReport.uxContext[7UL] = 8UL;

    EXPECT_EQ(SYSEXC_enERROR_OK,
              SYSEXC__enRegisterReportHandler(&uxContextMarker, &TM4C129E_DriverLib_Test__enReportHandler));

    SYSEXC__vInvokeReportHandler(&stReport);

    EXPECT_EQ((UBase_t) 1UL, g_stReportHandlerRecord.uxCallCount);
    EXPECT_EQ((void*) &uxContextMarker, g_stReportHandlerRecord.pvContext);
    EXPECT_EQ(&stReport, g_stReportHandlerRecord.pstReport);
}

/**
 * @brief Validate that unregister and null-report paths do not dispatch callbacks.
 * @summary Confirms that `SYSEXC__enUnregisterReportHandler` clears the callback
 *          state and that `SYSEXC__vInvokeReportHandler` ignores null report
 *          pointers even when a handler has been registered.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSEXC_Report.c
 * - Test callback recorder in this translation unit@endverbatim
 */
TEST_F(SYSEXC_ReportTest, UnregisterAndNullReportPreventDispatch)
{
    UBase_t uxContextMarker;

    uxContextMarker = 0xDEADBEEFUL;

    EXPECT_EQ(SYSEXC_enERROR_OK,
              SYSEXC__enRegisterReportHandler(&uxContextMarker, &TM4C129E_DriverLib_Test__enReportHandler));

    SYSEXC__vInvokeReportHandler((const SYSEXC_REPORT_t*) 0UL);
    EXPECT_EQ((UBase_t) 0UL, g_stReportHandlerRecord.uxCallCount);

    EXPECT_EQ(SYSEXC_enERROR_OK, SYSEXC__enUnregisterReportHandler());

    SYSEXC__vInvokeReportHandler((const SYSEXC_REPORT_t*) &g_stReportHandlerRecord);

    EXPECT_EQ((UBase_t) 0UL, g_stReportHandlerRecord.uxCallCount);
    EXPECT_EQ(nullptr, g_stReportHandlerRecord.pvContext);
    EXPECT_EQ(nullptr, g_stReportHandlerRecord.pstReport);
}