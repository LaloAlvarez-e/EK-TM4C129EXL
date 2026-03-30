/**
 *
 * @file NVIC_MCURegisterAccessMock.cpp
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

#include <tm4c129e_test/NVIC_MCURegisterAccessMock.h>

namespace
{
NVIC_MCURegisterAccessMock* g_pstNVICMCURegisterAccessMock = nullptr;
}

void TM4C129E_DriverLib_Test__vSetNVICMCURegisterAccessMock(NVIC_MCURegisterAccessMock* pstMockArg)
{
    g_pstNVICMCURegisterAccessMock = pstMockArg;
}

void TM4C129E_DriverLib_Test__vClearNVICMCURegisterAccessMock(void)
{
    g_pstNVICMCURegisterAccessMock = nullptr;
}

extern "C" MCU_nERROR MCU__enCheckParams(UBase_t uxModuleArg, UBase_t uxModuleMaxArg)
{
    if(nullptr == g_pstNVICMCURegisterAccessMock)
    {
        return MCU_enERROR_UNDEF;
    }

    return g_pstNVICMCURegisterAccessMock->CheckParams(uxModuleArg, uxModuleMaxArg);
}

extern "C" MCU_nERROR MCU__enReadRegister(MCU_Register_t* pstRegisterDataArg)
{
    if(nullptr == g_pstNVICMCURegisterAccessMock)
    {
        return MCU_enERROR_UNDEF;
    }

    return g_pstNVICMCURegisterAccessMock->ReadRegister(pstRegisterDataArg);
}

extern "C" MCU_nERROR MCU__enWriteRegister(const MCU_Register_t* const pstRegisterDataArg)
{
    if(nullptr == g_pstNVICMCURegisterAccessMock)
    {
        return MCU_enERROR_UNDEF;
    }

    return g_pstNVICMCURegisterAccessMock->WriteRegister(pstRegisterDataArg);
}