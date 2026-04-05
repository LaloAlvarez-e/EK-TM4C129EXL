/**
 *
 * @file SYSCTL_DeInitClockGatesMock.cpp
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

#include <tm4c129e_test/SYSCTL_DeInitClockGatesMock.h>

namespace
{
SYSCTL_DeInitClockGatesMock* g_pstSYSCTLDeInitClockGatesMock = nullptr;
}

void TM4C129E_DriverLib_Test__vSetSYSCTLDeInitClockGatesMock(SYSCTL_DeInitClockGatesMock* pstMockArg)
{
    g_pstSYSCTLDeInitClockGatesMock = pstMockArg;
}

void TM4C129E_DriverLib_Test__vClearSYSCTLDeInitClockGatesMock(void)
{
    g_pstSYSCTLDeInitClockGatesMock = nullptr;
}

extern "C" SYSCTL_nERROR SYSCTL__enClearReadyOnRunMode(SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg)
{
    if(nullptr == g_pstSYSCTLDeInitClockGatesMock)
    {
        return SYSCTL_enERROR_UNDEF;
    }

    return g_pstSYSCTLDeInitClockGatesMock->ClearReadyOnRunMode(enModuleArg, enPeripheralArg);
}