/**
 *
 * @file SYSCTL_InterruptRegisterMock.cpp
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

#include <tm4c129e_test/SYSCTL_InterruptRegisterMock.h>

namespace
{
SYSCTL_InterruptRegisterMock* g_pstSYSCTLInterruptRegisterMock = nullptr;
}

void TM4C129E_DriverLib_Test__vSetSYSCTLInterruptRegisterMock(SYSCTL_InterruptRegisterMock* pstMockArg)
{
    g_pstSYSCTLInterruptRegisterMock = pstMockArg;
}

void TM4C129E_DriverLib_Test__vClearSYSCTLInterruptRegisterMock(void)
{
    g_pstSYSCTLInterruptRegisterMock = nullptr;
}

extern "C" SCB_nERROR SCB__enRegisterIRQVectorHandler(SCB_nMODULE enModuleArg,
                                                       SCB_nVECISR enVectorArg,
                                                       SCB_pvfIRQVectorHandler_t pfIrqVectorHandlerArg,
                                                       SCB_pvfIRQVectorHandler_t* pfIrqVectorHandlerExternArg)
{
    if(nullptr == g_pstSYSCTLInterruptRegisterMock)
    {
        return SCB_enERROR_UNDEF;
    }

    return g_pstSYSCTLInterruptRegisterMock->RegisterIRQVectorHandler(enModuleArg,
                                                                      enVectorArg,
                                                                      pfIrqVectorHandlerArg,
                                                                      pfIrqVectorHandlerExternArg);
}