/**
 *
 * @file TIMER_InterruptVectorDriverMock.cpp
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

#include <tm4c129e_test/TIMER_InterruptVectorDriverMock.h>

namespace
{
TIMER_InterruptVectorDriverMock* g_pstTIMERInterruptVectorDriverMock = nullptr;
}

void TM4C129E_DriverLib_Test__vSetTIMERInterruptVectorDriverMock(TIMER_InterruptVectorDriverMock* pstMockArg)
{
    g_pstTIMERInterruptVectorDriverMock = pstMockArg;
}

void TM4C129E_DriverLib_Test__vClearTIMERInterruptVectorDriverMock(void)
{
    g_pstTIMERInterruptVectorDriverMock = nullptr;
}

extern "C" void TIMER__vGetSubParams(TIMER_nMODULE enModuleArg, UBase_t* puxSubModuleArg, UBase_t* puxModuleNumberArg)
{
    if(nullptr == g_pstTIMERInterruptVectorDriverMock)
    {
        if(nullptr != puxSubModuleArg)
        {
            *puxSubModuleArg = 0UL;
        }
        if(nullptr != puxModuleNumberArg)
        {
            *puxModuleNumberArg = 0UL;
        }
        return;
    }

    g_pstTIMERInterruptVectorDriverMock->GetSubParams(enModuleArg, puxSubModuleArg, puxModuleNumberArg);
}

extern "C" NVIC_nERROR NVIC__enEnableVector(NVIC_nMODULE enModuleArg, NVIC_nVECTOR enVectorArg, NVIC_nPRIORITY enPriorityArg)
{
    if(nullptr == g_pstTIMERInterruptVectorDriverMock)
    {
        return NVIC_enERROR_UNDEF;
    }

    return g_pstTIMERInterruptVectorDriverMock->EnableVector(enModuleArg, enVectorArg, enPriorityArg);
}

extern "C" NVIC_nERROR NVIC__enDisableVector(NVIC_nMODULE enModuleArg, NVIC_nVECTOR enVectorArg)
{
    if(nullptr == g_pstTIMERInterruptVectorDriverMock)
    {
        return NVIC_enERROR_UNDEF;
    }

    return g_pstTIMERInterruptVectorDriverMock->DisableVector(enModuleArg, enVectorArg);
}