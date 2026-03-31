/**
 *
 * @file SCB_DriverMock.cpp
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

#include <tm4c129e_test/SCB_DriverMock.h>

namespace
{
SCB_DriverMock* g_pstSCBDriverMock = nullptr;
}

void TM4C129E_DriverLib_Test__vSetSCBDriverMock(SCB_DriverMock* pstMockArg)
{
    g_pstSCBDriverMock = pstMockArg;
}

void TM4C129E_DriverLib_Test__vClearSCBDriverMock(void)
{
    g_pstSCBDriverMock = nullptr;
}

extern "C" MCU_nERROR MCU__enCheckParams(UBase_t uxValueArg, UBase_t uxMaxArg)
{
    if(nullptr == g_pstSCBDriverMock)
    {
        return MCU_enERROR_UNDEF;
    }

    return g_pstSCBDriverMock->CheckParams(uxValueArg, uxMaxArg);
}

extern "C" SCB_nERROR SCB__enReadRegister(SCB_nMODULE enModuleArg, SCB_Register_t* pstRegisterDataArg)
{
    if(nullptr == g_pstSCBDriverMock)
    {
        return SCB_enERROR_UNDEF;
    }

    return g_pstSCBDriverMock->ReadRegister(enModuleArg, pstRegisterDataArg);
}

extern "C" SCB_nERROR SCB__enWriteRegister(SCB_nMODULE enModuleArg, SCB_Register_t* pstRegisterDataArg)
{
    if(nullptr == g_pstSCBDriverMock)
    {
        return SCB_enERROR_UNDEF;
    }

    return g_pstSCBDriverMock->WriteRegister(enModuleArg, pstRegisterDataArg);
}

extern "C" void TM4C129E_DriverLib_Test__vHostDataSyncBarrier(void)
{
    if(nullptr != g_pstSCBDriverMock)
    {
        g_pstSCBDriverMock->DataSyncBarrier();
    }
}

extern "C" MCU_nSTATE MCU__enDisableGlobalInterrupt(void)
{
    if(nullptr == g_pstSCBDriverMock)
    {
        return MCU_enSTATE_UNDEF;
    }

    return g_pstSCBDriverMock->DisableGlobalInterrupt();
}

extern "C" void MCU__vSetGlobalInterrupt(MCU_nSTATE enStateArg)
{
    if(nullptr != g_pstSCBDriverMock)
    {
        g_pstSCBDriverMock->SetGlobalInterrupt(enStateArg);
    }
}

extern "C" void TM4C129E_DriverLib_Test__vHostWaitForInterrupt(void)
{
    if(nullptr != g_pstSCBDriverMock)
    {
        g_pstSCBDriverMock->WaitForInterrupt();
    }
}

extern "C" void MCU__vNoOperation(void)
{
}