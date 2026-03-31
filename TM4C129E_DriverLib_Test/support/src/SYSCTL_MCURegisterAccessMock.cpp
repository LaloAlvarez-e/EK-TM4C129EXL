/**
 *
 * @file SYSCTL_MCURegisterAccessMock.cpp
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

#include <tm4c129e_test/SYSCTL_MCURegisterAccessMock.h>

namespace
{
SYSCTL_MCURegisterAccessMock* g_pstSYSCTLMCURegisterAccessMock = nullptr;
}

void TM4C129E_DriverLib_Test__vSetSYSCTLMCURegisterAccessMock(SYSCTL_MCURegisterAccessMock* pstMockArg)
{
    g_pstSYSCTLMCURegisterAccessMock = pstMockArg;
}

void TM4C129E_DriverLib_Test__vClearSYSCTLMCURegisterAccessMock(void)
{
    g_pstSYSCTLMCURegisterAccessMock = nullptr;
}

extern "C" MCU_nERROR MCU__enCheckParams(UBase_t uxModuleArg, UBase_t uxModuleMaxArg)
{
    if(nullptr == g_pstSYSCTLMCURegisterAccessMock)
    {
        return MCU_enERROR_UNDEF;
    }

    return g_pstSYSCTLMCURegisterAccessMock->CheckParams(uxModuleArg, uxModuleMaxArg);
}

extern "C" MCU_nERROR MCU__enReadRegister(MCU_Register_t* pstRegisterDataArg)
{
    if(nullptr == g_pstSYSCTLMCURegisterAccessMock)
    {
        return MCU_enERROR_UNDEF;
    }

    return g_pstSYSCTLMCURegisterAccessMock->ReadRegister(pstRegisterDataArg);
}

extern "C" MCU_nERROR MCU__enWriteRegister(const MCU_Register_t* const pstRegisterDataArg)
{
    if(nullptr == g_pstSYSCTLMCURegisterAccessMock)
    {
        return MCU_enERROR_UNDEF;
    }

    return g_pstSYSCTLMCURegisterAccessMock->WriteRegister(pstRegisterDataArg);
}