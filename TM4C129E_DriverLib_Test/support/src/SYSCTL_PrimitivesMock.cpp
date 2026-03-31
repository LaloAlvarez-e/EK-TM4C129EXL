/**
 *
 * @file SYSCTL_PrimitivesMock.cpp
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

#include <tm4c129e_test/SYSCTL_PrimitivesMock.h>

namespace
{
SYSCTL_PrimitivesMock* g_pstSYSCTLPrimitivesMock = nullptr;
}

void TM4C129E_DriverLib_Test__vSetSYSCTLPrimitivesMock(SYSCTL_PrimitivesMock* pstMockArg)
{
    g_pstSYSCTLPrimitivesMock = pstMockArg;
}

void TM4C129E_DriverLib_Test__vClearSYSCTLPrimitivesMock(void)
{
    g_pstSYSCTLPrimitivesMock = nullptr;
}

extern "C" SYSCTL_nERROR SYSCTL__enReadRegister(SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg)
{
    if(nullptr == g_pstSYSCTLPrimitivesMock)
    {
        return SYSCTL_enERROR_UNDEF;
    }

    return g_pstSYSCTLPrimitivesMock->ReadRegister(enModuleArg, pstRegisterDataArg);
}

extern "C" SYSCTL_nERROR SYSCTL__enWriteRegister(SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg)
{
    if(nullptr == g_pstSYSCTLPrimitivesMock)
    {
        return SYSCTL_enERROR_UNDEF;
    }

    return g_pstSYSCTLPrimitivesMock->WriteRegister(enModuleArg, pstRegisterDataArg);
}