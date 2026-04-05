/**
 *
 * @file ACMP_InitDriverMock.cpp
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

#include <tm4c129e_test/ACMP_InitDriverMock.h>

namespace
{
ACMP_InitDriverMock* g_pstACMPInitDriverMock = nullptr;
}

void TM4C129E_DriverLib_Test__vSetACMPInitDriverMock(ACMP_InitDriverMock* pstMockArg)
{
    g_pstACMPInitDriverMock = pstMockArg;
}

void TM4C129E_DriverLib_Test__vClearACMPInitDriverMock(void)
{
    g_pstACMPInitDriverMock = nullptr;
}

extern "C" ACMP_nERROR ACMP__enSetReadyOnRunMode(ACMP_nMODULE enModuleArg)
{
    if(nullptr == g_pstACMPInitDriverMock)
    {
        return ACMP_enERROR_UNDEF;
    }

    return g_pstACMPInitDriverMock->SetReadyOnRunMode(enModuleArg);
}

extern "C" ACMP_TestIRQVectorHandler_t ACMP__pvfGetIRQVectorHandler(ACMP_nMODULE enModuleArg,
                                                                      ACMP_nCOMP enComparatorArg)
{
    if(nullptr == g_pstACMPInitDriverMock)
    {
        return (ACMP_TestIRQVectorHandler_t) 0UL;
    }

    return g_pstACMPInitDriverMock->GetIRQVectorHandler(enModuleArg, enComparatorArg);
}

extern "C" ACMP_nERROR ACMP__enRegisterIRQVectorHandler(ACMP_nMODULE enModuleArg,
                                                          ACMP_nCOMP enComparatorArg,
                                                          ACMP_TestIRQVectorHandler_t pfIrqVectorHandlerArg)
{
    if(nullptr == g_pstACMPInitDriverMock)
    {
        return ACMP_enERROR_UNDEF;
    }

    return g_pstACMPInitDriverMock->RegisterIRQVectorHandler(enModuleArg, enComparatorArg, pfIrqVectorHandlerArg);
}