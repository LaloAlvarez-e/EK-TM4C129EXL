/**
 *
 * @file NVIC_DeInitDriverMock.cpp
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
 * @verbatim 29 mar. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 29 mar. 2026   GitHub Copilot   1.0         initial Version@endverbatim
 */

#include <tm4c129e_test/NVIC_DeInitDriverMock.h>

namespace
{
NVIC_DeInitDriverMock* g_pstNVICDeInitDriverMock = nullptr;
}

void TM4C129E_DriverLib_Test__vSetNVICDeInitDriverMock(NVIC_DeInitDriverMock* pstMockArg)
{
    g_pstNVICDeInitDriverMock = pstMockArg;
}

void TM4C129E_DriverLib_Test__vClearNVICDeInitDriverMock(void)
{
    g_pstNVICDeInitDriverMock = nullptr;
}

extern "C" NVIC_nERROR NVIC__enDisableVector(NVIC_nMODULE enModuleArg, NVIC_nVECTOR enVectorArg)
{
    if(nullptr == g_pstNVICDeInitDriverMock)
    {
        return NVIC_enERROR_UNDEF;
    }

    return g_pstNVICDeInitDriverMock->DisableVector(enModuleArg, enVectorArg);
}