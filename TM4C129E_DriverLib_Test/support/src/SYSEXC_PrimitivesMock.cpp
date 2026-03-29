/**
 *
 * @file SYSEXC_PrimitivesMock.cpp
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
 * @verbatim 28 mar. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 28 mar. 2026   GitHub Copilot   1.0         initial Version@endverbatim
 */

#include <tm4c129e_test/SYSEXC_PrimitivesMock.h>

namespace
{
SYSEXC_PrimitivesMock* g_pstSYSEXCPrimitivesMock = nullptr;
}

void TM4C129E_DriverLib_Test__vSetSYSEXCPrimitivesMock(SYSEXC_PrimitivesMock* pstMockArg)
{
    g_pstSYSEXCPrimitivesMock = pstMockArg;
}

void TM4C129E_DriverLib_Test__vClearSYSEXCPrimitivesMock(void)
{
    g_pstSYSEXCPrimitivesMock = nullptr;
}

extern "C" MCU_nERROR MCU__enCheckParams(UBase_t uxModuleArg, UBase_t uxModuleMaxArg)
{
    if(nullptr == g_pstSYSEXCPrimitivesMock)
    {
        return MCU_enERROR_UNDEF;
    }

    return g_pstSYSEXCPrimitivesMock->CheckParams(uxModuleArg, uxModuleMaxArg);
}

extern "C" UBase_t MCU__uxCheckParams(UBase_t uxModuleArg, UBase_t uxModuleMaxArg)
{
    if(nullptr == g_pstSYSEXCPrimitivesMock)
    {
        return UNDEF_VALUE;
    }

    return g_pstSYSEXCPrimitivesMock->CheckParamsRaw(uxModuleArg, uxModuleMaxArg);
}

extern "C" SYSEXC_nERROR SYSEXC__enReadRegister(SYSEXC_nMODULE enModuleArg, SYSEXC_Register_t* pstRegisterDataArg)
{
    if(nullptr == g_pstSYSEXCPrimitivesMock)
    {
        return SYSEXC_enERROR_UNDEF;
    }

    return g_pstSYSEXCPrimitivesMock->ReadRegister(enModuleArg, pstRegisterDataArg);
}

extern "C" SYSEXC_nERROR SYSEXC__enWriteRegister(SYSEXC_nMODULE enModuleArg, SYSEXC_Register_t* pstRegisterDataArg)
{
    if(nullptr == g_pstSYSEXCPrimitivesMock)
    {
        return SYSEXC_enERROR_UNDEF;
    }

    return g_pstSYSEXCPrimitivesMock->WriteRegister(enModuleArg, pstRegisterDataArg);
}