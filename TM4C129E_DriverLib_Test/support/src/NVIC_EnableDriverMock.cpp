/**
 *
 * @file NVIC_EnableDriverMock.cpp
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

#include <tm4c129e_test/NVIC_EnableDriverMock.h>

namespace
{
NVIC_EnableDriverMock* g_pstNVICEnableDriverMock = nullptr;
}

void TM4C129E_DriverLib_Test__vSetNVICEnableDriverMock(NVIC_EnableDriverMock* pstMockArg)
{
    g_pstNVICEnableDriverMock = pstMockArg;
}

void TM4C129E_DriverLib_Test__vClearNVICEnableDriverMock(void)
{
    g_pstNVICEnableDriverMock = nullptr;
}

extern "C" NVIC_nERROR NVIC__enReadValue(NVIC_nMODULE enModuleArg, NVIC_nVECTOR enVectorArg, uintptr_t uptrRegisterOffsetArg, UBase_t* puxValueArg)
{
    if(nullptr == g_pstNVICEnableDriverMock)
    {
        return NVIC_enERROR_UNDEF;
    }

    return g_pstNVICEnableDriverMock->ReadValue(enModuleArg, enVectorArg, uptrRegisterOffsetArg, puxValueArg);
}

extern "C" NVIC_nERROR NVIC__enSetWriteValue(NVIC_nMODULE enModuleArg, NVIC_nVECTOR enVectorArg, uintptr_t uptrRegisterOffsetArg, UBase_t uxValueArg)
{
    if(nullptr == g_pstNVICEnableDriverMock)
    {
        return NVIC_enERROR_UNDEF;
    }

    return g_pstNVICEnableDriverMock->SetWriteValue(enModuleArg, enVectorArg, uptrRegisterOffsetArg, uxValueArg);
}

extern "C" NVIC_nERROR NVIC__enSetVectorPriority(NVIC_nMODULE enModuleArg, NVIC_nVECTOR enVectorArg, NVIC_nPRIORITY enPriorityArg)
{
    if(nullptr == g_pstNVICEnableDriverMock)
    {
        return NVIC_enERROR_UNDEF;
    }

    return g_pstNVICEnableDriverMock->SetVectorPriority(enModuleArg, enVectorArg, enPriorityArg);
}