/**
 *
 * @file SYSEXC_MCURegisterAccessMock.cpp
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

#include <tm4c129e_test/SYSEXC_MCURegisterAccessMock.h>

namespace
{
SYSEXC_MCURegisterAccessMock* g_pstSYSEXCMCURegisterAccessMock = nullptr;
}

void TM4C129E_DriverLib_Test__vSetSYSEXCMCURegisterAccessMock(SYSEXC_MCURegisterAccessMock* pstMockArg)
{
    g_pstSYSEXCMCURegisterAccessMock = pstMockArg;
}

void TM4C129E_DriverLib_Test__vClearSYSEXCMCURegisterAccessMock(void)
{
    g_pstSYSEXCMCURegisterAccessMock = nullptr;
}

extern "C" MCU_nERROR MCU__enCheckParams(UBase_t uxModuleArg, UBase_t uxModuleMaxArg)
{
    if(nullptr == g_pstSYSEXCMCURegisterAccessMock)
    {
        return MCU_enERROR_UNDEF;
    }

    return g_pstSYSEXCMCURegisterAccessMock->CheckParams(uxModuleArg, uxModuleMaxArg);
}

extern "C" MCU_nERROR MCU__enReadRegister(MCU_Register_t* pstRegisterDataArg)
{
    if(nullptr == g_pstSYSEXCMCURegisterAccessMock)
    {
        return MCU_enERROR_UNDEF;
    }

    return g_pstSYSEXCMCURegisterAccessMock->ReadRegister(pstRegisterDataArg);
}

extern "C" MCU_nERROR MCU__enWriteRegister(const MCU_Register_t* const pstRegisterDataArg)
{
    if(nullptr == g_pstSYSEXCMCURegisterAccessMock)
    {
        return MCU_enERROR_UNDEF;
    }

    return g_pstSYSEXCMCURegisterAccessMock->WriteRegister(pstRegisterDataArg);
}