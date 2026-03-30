/**
 *
 * @file NVIC_RegisterPrimitivesMock.cpp
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

#include <tm4c129e_test/NVIC_RegisterPrimitivesMock.h>

namespace
{
NVIC_RegisterPrimitivesMock* g_pstNVICRegisterPrimitivesMock = nullptr;
}

void TM4C129E_DriverLib_Test__vSetNVICRegisterPrimitivesMock(NVIC_RegisterPrimitivesMock* pstMockArg)
{
    g_pstNVICRegisterPrimitivesMock = pstMockArg;
}

void TM4C129E_DriverLib_Test__vClearNVICRegisterPrimitivesMock(void)
{
    g_pstNVICRegisterPrimitivesMock = nullptr;
}

extern "C" MCU_nERROR MCU__enCheckParams(UBase_t uxModuleArg, UBase_t uxModuleMaxArg)
{
    if(nullptr == g_pstNVICRegisterPrimitivesMock)
    {
        return MCU_enERROR_UNDEF;
    }

    return g_pstNVICRegisterPrimitivesMock->CheckParams(uxModuleArg, uxModuleMaxArg);
}

extern "C" NVIC_nERROR NVIC__enReadRegister(NVIC_nMODULE enModuleArg, NVIC_Register_t* pstRegisterDataArg)
{
    if(nullptr == g_pstNVICRegisterPrimitivesMock)
    {
        return NVIC_enERROR_UNDEF;
    }

    return g_pstNVICRegisterPrimitivesMock->ReadRegister(enModuleArg, pstRegisterDataArg);
}

extern "C" NVIC_nERROR NVIC__enWriteRegister(NVIC_nMODULE enModuleArg, NVIC_Register_t* pstRegisterDataArg)
{
    if(nullptr == g_pstNVICRegisterPrimitivesMock)
    {
        return NVIC_enERROR_UNDEF;
    }

    return g_pstNVICRegisterPrimitivesMock->WriteRegister(enModuleArg, pstRegisterDataArg);
}