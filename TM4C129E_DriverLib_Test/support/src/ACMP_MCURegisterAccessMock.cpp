/**
 *
 * @file ACMP_MCURegisterAccessMock.cpp
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
 * @verbatim 5 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 5 abr. 2026    GitHub Copilot   1.0         initial Version@endverbatim
 */

#include <tm4c129e_test/ACMP_MCURegisterAccessMock.h>

namespace
{
ACMP_MCURegisterAccessMock* g_pstACMPMCURegisterAccessMock = nullptr;
}

void TM4C129E_DriverLib_Test__vSetACMPMCURegisterAccessMock(ACMP_MCURegisterAccessMock* pstMockArg)
{
    g_pstACMPMCURegisterAccessMock = pstMockArg;
}

void TM4C129E_DriverLib_Test__vClearACMPMCURegisterAccessMock(void)
{
    g_pstACMPMCURegisterAccessMock = nullptr;
}

extern "C" MCU_nERROR MCU__enCheckParams(UBase_t uxModuleArg, UBase_t uxModuleMaxArg)
{
    if(nullptr == g_pstACMPMCURegisterAccessMock)
    {
        return MCU_enERROR_UNDEF;
    }

    return g_pstACMPMCURegisterAccessMock->CheckParams(uxModuleArg, uxModuleMaxArg);
}

extern "C" MCU_nERROR MCU__enReadRegister(MCU_Register_t* pstRegisterDataArg)
{
    if(nullptr == g_pstACMPMCURegisterAccessMock)
    {
        return MCU_enERROR_UNDEF;
    }

    return g_pstACMPMCURegisterAccessMock->ReadRegister(pstRegisterDataArg);
}

extern "C" MCU_nERROR MCU__enWriteRegister(const MCU_Register_t* const pstRegisterDataArg)
{
    if(nullptr == g_pstACMPMCURegisterAccessMock)
    {
        return MCU_enERROR_UNDEF;
    }

    return g_pstACMPMCURegisterAccessMock->WriteRegister(pstRegisterDataArg);
}