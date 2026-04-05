/**
 *
 * @file SYSCTL_ReadyDriverMock.cpp
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

#include <tm4c129e_test/SYSCTL_ReadyDriverMock.h>

namespace
{
SYSCTL_ReadyDriverMock* g_pstSYSCTLReadyDriverMock = nullptr;
}

void TM4C129E_DriverLib_Test__vSetSYSCTLReadyDriverMock(SYSCTL_ReadyDriverMock* pstMockArg)
{
    g_pstSYSCTLReadyDriverMock = pstMockArg;
}

void TM4C129E_DriverLib_Test__vClearSYSCTLReadyDriverMock(void)
{
    g_pstSYSCTLReadyDriverMock = nullptr;
}

extern "C" SYSCTL_nERROR SYSCTL__enIsPeripheralReady(SYSCTL_nMODULE enModuleArg,
                                                      SYSCTL_nPERIPHERAL enPeripheralArg,
                                                      SYSCTL_nBOOLEAN* penReadyArg)
{
    if(nullptr == g_pstSYSCTLReadyDriverMock)
    {
        return SYSCTL_enERROR_UNDEF;
    }

    return g_pstSYSCTLReadyDriverMock->IsPeripheralReady(enModuleArg, enPeripheralArg, penReadyArg);
}

extern "C" SYSCTL_nERROR SYSCTL__enEnableRunMode(SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg)
{
    if(nullptr == g_pstSYSCTLReadyDriverMock)
    {
        return SYSCTL_enERROR_UNDEF;
    }

    return g_pstSYSCTLReadyDriverMock->EnableRunMode(enModuleArg, enPeripheralArg);
}

extern "C" SYSCTL_nERROR SYSCTL__enDisableRunMode(SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg)
{
    if(nullptr == g_pstSYSCTLReadyDriverMock)
    {
        return SYSCTL_enERROR_UNDEF;
    }

    return g_pstSYSCTLReadyDriverMock->DisableRunMode(enModuleArg, enPeripheralArg);
}

extern "C" SYSCTL_nERROR SYSCTL__enSetPeripheralReset(SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg)
{
    if(nullptr == g_pstSYSCTLReadyDriverMock)
    {
        return SYSCTL_enERROR_UNDEF;
    }

    return g_pstSYSCTLReadyDriverMock->SetPeripheralReset(enModuleArg, enPeripheralArg);
}