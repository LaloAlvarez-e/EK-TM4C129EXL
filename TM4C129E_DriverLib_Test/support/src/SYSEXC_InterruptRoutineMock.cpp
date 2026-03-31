/**
 *
 * @file SYSEXC_InterruptRoutineMock.cpp
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

#include <tm4c129e_test/SYSEXC_InterruptRoutineMock.h>

namespace
{
SYSEXC_InterruptRoutineMock* g_pstSYSEXCInterruptRoutineMock = nullptr;
}

extern "C" UBase_t TM4C129E_DriverLib_Test__u32HostSCBICSRValue = 0UL;

void TM4C129E_DriverLib_Test__vSetSYSEXCInterruptRoutineMock(SYSEXC_InterruptRoutineMock* pstMockArg)
{
    g_pstSYSEXCInterruptRoutineMock = pstMockArg;
}

void TM4C129E_DriverLib_Test__vClearSYSEXCInterruptRoutineMock(void)
{
    g_pstSYSEXCInterruptRoutineMock = nullptr;
}

extern "C" void SYSEXC__vInvokeReportHandler(const SYSEXC_REPORT_t* pstReportArg)
{
    if(nullptr != g_pstSYSEXCInterruptRoutineMock)
    {
        g_pstSYSEXCInterruptRoutineMock->InvokeReportHandler(pstReportArg);
    }
}

extern "C" SYSEXC_pvfIRQSourceHandler_t SYSEXC__pvfGetIRQSourceHandler(SYSEXC_nMODULE enModuleArg, SYSEXC_nINT enIntSourceArg)
{
    if(nullptr == g_pstSYSEXCInterruptRoutineMock)
    {
        return (SYSEXC_pvfIRQSourceHandler_t) 0UL;
    }

    return g_pstSYSEXCInterruptRoutineMock->GetIRQSourceHandler(enModuleArg, enIntSourceArg);
}