/**
 *
 * @file TIMER_InterruptRegisterMock.cpp
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

#include <tm4c129e_test/TIMER_InterruptRegisterMock.h>

namespace
{
TIMER_InterruptRegisterMock* g_pstTIMERInterruptRegisterMock = nullptr;
}

void TM4C129E_DriverLib_Test__vSetTIMERInterruptRegisterMock(TIMER_InterruptRegisterMock* pstMockArg)
{
    g_pstTIMERInterruptRegisterMock = pstMockArg;
}

void TM4C129E_DriverLib_Test__vClearTIMERInterruptRegisterMock(void)
{
    g_pstTIMERInterruptRegisterMock = nullptr;
}

extern "C" void TIMER__vGetSubParams(TIMER_nMODULE enModuleArg, UBase_t* puxSubModuleArg, UBase_t* puxModuleNumberArg)
{
    if(nullptr == g_pstTIMERInterruptRegisterMock)
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

    g_pstTIMERInterruptRegisterMock->GetSubParams(enModuleArg, puxSubModuleArg, puxModuleNumberArg);
}

extern "C" SCB_nERROR SCB__enRegisterIRQVectorHandler(SCB_nMODULE enModuleArg,
                                                       SCB_nVECISR enVectorArg,
                                                       SCB_pvfIRQVectorHandler_t pfIrqVectorHandlerArg,
                                                       SCB_pvfIRQVectorHandler_t* pfIrqVectorHandlerExternArg)
{
    if(nullptr == g_pstTIMERInterruptRegisterMock)
    {
        return SCB_enERROR_UNDEF;
    }

    return g_pstTIMERInterruptRegisterMock->RegisterIRQVectorHandler(enModuleArg,
                                                                     enVectorArg,
                                                                     pfIrqVectorHandlerArg,
                                                                     pfIrqVectorHandlerExternArg);
}

extern "C" void (**TIMER__pvfGetIRQVectorHandlerPointer(TIMER_nSUBMODULE enTIMERSubmoduleArg,
                                                         TIMER_nMODULE_NUM enTIMERModuleNumberArg))(void)
{
    if(nullptr == g_pstTIMERInterruptRegisterMock)
    {
        return (TIMER_TestIRQVectorHandlerPointer_t) 0UL;
    }

    return g_pstTIMERInterruptRegisterMock->GetIRQVectorHandlerPointer(enTIMERSubmoduleArg,
                                                                       enTIMERModuleNumberArg);
}