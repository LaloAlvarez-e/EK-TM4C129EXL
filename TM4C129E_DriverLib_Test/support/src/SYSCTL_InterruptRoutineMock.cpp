/**
 *
 * @file SYSCTL_InterruptRoutineMock.cpp
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

#include <tm4c129e_test/SYSCTL_InterruptRoutineMock.h>

namespace
{
SYSCTL_InterruptRoutineMock* g_pstSYSCTLInterruptRoutineMock = nullptr;
}

extern "C" UBase_t TM4C129E_DriverLib_Test__u32HostSYSCTLMISCValue = 0UL;

void TM4C129E_DriverLib_Test__vSetSYSCTLInterruptRoutineMock(SYSCTL_InterruptRoutineMock* pstMockArg)
{
    g_pstSYSCTLInterruptRoutineMock = pstMockArg;
}

void TM4C129E_DriverLib_Test__vClearSYSCTLInterruptRoutineMock(void)
{
    g_pstSYSCTLInterruptRoutineMock = nullptr;
}

extern "C" SYSCTL_pvfIRQSourceHandler_t SYSCTL__pvfGetIRQSourceHandler(SYSCTL_nMODULE enModuleArg, SYSCTL_nINT enIntSourceArg)
{
    if(nullptr == g_pstSYSCTLInterruptRoutineMock)
    {
        return (SYSCTL_pvfIRQSourceHandler_t) 0UL;
    }

    return g_pstSYSCTLInterruptRoutineMock->GetIRQSourceHandler(enModuleArg, enIntSourceArg);
}