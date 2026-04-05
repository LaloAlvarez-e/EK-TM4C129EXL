/**
 *
 * @file SYSCTL_InitDriverMock.cpp
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

#include <tm4c129e_test/SYSCTL_InitDriverMock.h>

namespace
{
SYSCTL_InitDriverMock* g_pstSYSCTLInitDriverMock = nullptr;
}

void TM4C129E_DriverLib_Test__vSetSYSCTLInitDriverMock(SYSCTL_InitDriverMock* pstMockArg)
{
    g_pstSYSCTLInitDriverMock = pstMockArg;
}

void TM4C129E_DriverLib_Test__vClearSYSCTLInitDriverMock(void)
{
    g_pstSYSCTLInitDriverMock = nullptr;
}

extern "C" MCU_nERROR MCU__enCheckParams(UBase_t uxValueArg, UBase_t uxMaxArg)
{
    if(nullptr == g_pstSYSCTLInitDriverMock)
    {
        return MCU_enERROR_UNDEF;
    }

    return g_pstSYSCTLInitDriverMock->CheckParams(uxValueArg, uxMaxArg);
}

extern "C" SYSCTL_TestIRQVectorHandler_t SYSCTL__pvfGetIRQVectorHandler(void)
{
    if(nullptr == g_pstSYSCTLInitDriverMock)
    {
        return (SYSCTL_TestIRQVectorHandler_t) 0UL;
    }

    return g_pstSYSCTLInitDriverMock->GetIRQVectorHandler();
}

extern "C" SYSCTL_nERROR SYSCTL__enRegisterIRQVectorHandler(SYSCTL_TestIRQVectorHandler_t pfIrqVectorHandlerArg)
{
    if(nullptr == g_pstSYSCTLInitDriverMock)
    {
        return SYSCTL_enERROR_UNDEF;
    }

    return g_pstSYSCTLInitDriverMock->RegisterIRQVectorHandler(pfIrqVectorHandlerArg);
}

extern "C" SYSCTL_nERROR SYSCTL__enDisableInterruptSourceByMask(SYSCTL_nMODULE enModuleArg, SYSCTL_nINTMASK enInterruptMaskArg)
{
    if(nullptr == g_pstSYSCTLInitDriverMock)
    {
        return SYSCTL_enERROR_UNDEF;
    }

    return g_pstSYSCTLInitDriverMock->DisableInterruptSourceByMask(enModuleArg, enInterruptMaskArg);
}

extern "C" SYSCTL_nERROR SYSCTL__enClearInterruptSourceByMask(SYSCTL_nMODULE enModuleArg, SYSCTL_nINTMASK enInterruptMaskArg)
{
    if(nullptr == g_pstSYSCTLInitDriverMock)
    {
        return SYSCTL_enERROR_UNDEF;
    }

    return g_pstSYSCTLInitDriverMock->ClearInterruptSourceByMask(enModuleArg, enInterruptMaskArg);
}

extern "C" SYSCTL_nERROR SYSCTL__enEnableInterruptSourceByMask(SYSCTL_nMODULE enModuleArg, SYSCTL_nINTMASK enInterruptMaskArg)
{
    if(nullptr == g_pstSYSCTLInitDriverMock)
    {
        return SYSCTL_enERROR_UNDEF;
    }

    return g_pstSYSCTLInitDriverMock->EnableInterruptSourceByMask(enModuleArg, enInterruptMaskArg);
}

extern "C" SYSCTL_nERROR SYSCTL__enEnableInterruptVector(SYSCTL_nPRIORITY enPriorityArg)
{
    if(nullptr == g_pstSYSCTLInitDriverMock)
    {
        return SYSCTL_enERROR_UNDEF;
    }

    return g_pstSYSCTLInitDriverMock->EnableInterruptVector(enPriorityArg);
}

extern "C" SYSCTL_nERROR SYSCTL__enDisableInterruptVector(void)
{
    if(nullptr == g_pstSYSCTLInitDriverMock)
    {
        return SYSCTL_enERROR_UNDEF;
    }

    return g_pstSYSCTLInitDriverMock->DisableInterruptVector();
}