/**
 *
 * @file SYSEXC_InitDriverMock.cpp
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

#include <tm4c129e_test/SYSEXC_InitDriverMock.h>

namespace
{
SYSEXC_InitDriverMock* g_pstSYSEXCInitDriverMock = nullptr;
}

void TM4C129E_DriverLib_Test__vSetSYSEXCInitDriverMock(SYSEXC_InitDriverMock* pstMockArg)
{
    g_pstSYSEXCInitDriverMock = pstMockArg;
}

void TM4C129E_DriverLib_Test__vClearSYSEXCInitDriverMock(void)
{
    g_pstSYSEXCInitDriverMock = nullptr;
}

extern "C" MCU_nERROR MCU__enCheckParams(UBase_t uxValueArg, UBase_t uxMaxArg)
{
    if(nullptr == g_pstSYSEXCInitDriverMock)
    {
        return MCU_enERROR_UNDEF;
    }

    return g_pstSYSEXCInitDriverMock->CheckParams(uxValueArg, uxMaxArg);
}

extern "C" SYSEXC_pvfIRQVectorHandler_t SYSEXC__pvfGetIRQVectorHandler(SYSEXC_nMODULE enModuleArg)
{
    if(nullptr == g_pstSYSEXCInitDriverMock)
    {
        return (SYSEXC_pvfIRQVectorHandler_t) 0UL;
    }

    return g_pstSYSEXCInitDriverMock->GetIRQVectorHandler(enModuleArg);
}

extern "C" SYSEXC_nERROR SYSEXC__enRegisterIRQVectorHandler(SYSEXC_nMODULE enModuleArg, SYSEXC_pvfIRQVectorHandler_t pfIrqVectorHandlerArg)
{
    if(nullptr == g_pstSYSEXCInitDriverMock)
    {
        return SYSEXC_enERROR_UNDEF;
    }

    return g_pstSYSEXCInitDriverMock->RegisterIRQVectorHandler(enModuleArg, pfIrqVectorHandlerArg);
}

extern "C" SYSEXC_nERROR SYSEXC__enDisableInterruptSourceByMask(SYSEXC_nMODULE enModuleArg, SYSEXC_nINTMASK enInterruptMaskArg)
{
    if(nullptr == g_pstSYSEXCInitDriverMock)
    {
        return SYSEXC_enERROR_UNDEF;
    }

    return g_pstSYSEXCInitDriverMock->DisableInterruptSourceByMask(enModuleArg, enInterruptMaskArg);
}

extern "C" SYSEXC_nERROR SYSEXC__enClearInterruptSourceByMask(SYSEXC_nMODULE enModuleArg, SYSEXC_nINTMASK enInterruptMaskArg)
{
    if(nullptr == g_pstSYSEXCInitDriverMock)
    {
        return SYSEXC_enERROR_UNDEF;
    }

    return g_pstSYSEXCInitDriverMock->ClearInterruptSourceByMask(enModuleArg, enInterruptMaskArg);
}

extern "C" SYSEXC_nERROR SYSEXC__enEnableInterruptSourceByMask(SYSEXC_nMODULE enModuleArg, SYSEXC_nINTMASK enInterruptMaskArg)
{
    if(nullptr == g_pstSYSEXCInitDriverMock)
    {
        return SYSEXC_enERROR_UNDEF;
    }

    return g_pstSYSEXCInitDriverMock->EnableInterruptSourceByMask(enModuleArg, enInterruptMaskArg);
}

extern "C" SYSEXC_nERROR SYSEXC__enEnableInterruptVectorWithPriority(SYSEXC_nMODULE enModuleArg, SYSEXC_nPRIORITY enPriorityArg)
{
    if(nullptr == g_pstSYSEXCInitDriverMock)
    {
        return SYSEXC_enERROR_UNDEF;
    }

    return g_pstSYSEXCInitDriverMock->EnableInterruptVectorWithPriority(enModuleArg, enPriorityArg);
}