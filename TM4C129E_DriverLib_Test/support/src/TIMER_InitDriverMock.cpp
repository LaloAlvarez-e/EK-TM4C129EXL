/**
 *
 * @file TIMER_InitDriverMock.cpp
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

#include <tm4c129e_test/TIMER_InitDriverMock.h>

namespace
{
TIMER_InitDriverMock* g_pstTIMERInitDriverMock = nullptr;
}

void TM4C129E_DriverLib_Test__vSetTIMERInitDriverMock(TIMER_InitDriverMock* pstMockArg)
{
    g_pstTIMERInitDriverMock = pstMockArg;
}

void TM4C129E_DriverLib_Test__vClearTIMERInitDriverMock(void)
{
    g_pstTIMERInitDriverMock = nullptr;
}

extern "C" TIMER_TestIRQVectorHandler_t TIMER__pvfGetIRQVectorHandler(TIMER_nSUBMODULE enTIMERSubmoduleArg,
                                                                       TIMER_nMODULE_NUM enTIMERModuleNumberArg)
{
    if(nullptr == g_pstTIMERInitDriverMock)
    {
        return (TIMER_TestIRQVectorHandler_t) 0UL;
    }

    return g_pstTIMERInitDriverMock->GetIRQVectorHandler(enTIMERSubmoduleArg, enTIMERModuleNumberArg);
}

extern "C" TIMER_nERROR TIMER__enRegisterIRQVectorHandler(TIMER_TestIRQVectorHandler_t pfIrqVectorHandlerArg,
                                                           TIMER_nMODULE enModuleArg)
{
    if(nullptr == g_pstTIMERInitDriverMock)
    {
        return TIMER_enERROR_UNDEF;
    }

    return g_pstTIMERInitDriverMock->RegisterIRQVectorHandler(pfIrqVectorHandlerArg, enModuleArg);
}