/**
 *
 * @file SYSCTL_InterruptVectorDriverMock.cpp
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

#include <tm4c129e_test/SYSCTL_InterruptVectorDriverMock.h>

namespace
{
SYSCTL_InterruptVectorDriverMock* g_pstSYSCTLInterruptVectorDriverMock = nullptr;
}

void TM4C129E_DriverLib_Test__vSetSYSCTLInterruptVectorDriverMock(SYSCTL_InterruptVectorDriverMock* pstMockArg)
{
    g_pstSYSCTLInterruptVectorDriverMock = pstMockArg;
}

void TM4C129E_DriverLib_Test__vClearSYSCTLInterruptVectorDriverMock(void)
{
    g_pstSYSCTLInterruptVectorDriverMock = nullptr;
}

extern "C" NVIC_nERROR NVIC__enEnableVector(NVIC_nMODULE enModuleArg, NVIC_nVECTOR enVectorArg, NVIC_nPRIORITY enPriorityArg)
{
    if(nullptr == g_pstSYSCTLInterruptVectorDriverMock)
    {
        return NVIC_enERROR_UNDEF;
    }

    return g_pstSYSCTLInterruptVectorDriverMock->EnableVector(enModuleArg, enVectorArg, enPriorityArg);
}

extern "C" NVIC_nERROR NVIC__enDisableVector(NVIC_nMODULE enModuleArg, NVIC_nVECTOR enVectorArg)
{
    if(nullptr == g_pstSYSCTLInterruptVectorDriverMock)
    {
        return NVIC_enERROR_UNDEF;
    }

    return g_pstSYSCTLInterruptVectorDriverMock->DisableVector(enModuleArg, enVectorArg);
}