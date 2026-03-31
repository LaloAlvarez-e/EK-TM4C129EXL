/**
 *
 * @file SYSCTL_PeripheralGenericMock.cpp
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

#include <tm4c129e_test/SYSCTL_PeripheralGenericMock.h>

namespace
{
SYSCTL_PeripheralGenericMock* g_pstSYSCTLPeripheralGenericMock = nullptr;
}

void TM4C129E_DriverLib_Test__vSetSYSCTLPeripheralGenericMock(SYSCTL_PeripheralGenericMock* pstMockArg)
{
    g_pstSYSCTLPeripheralGenericMock = pstMockArg;
}

void TM4C129E_DriverLib_Test__vClearSYSCTLPeripheralGenericMock(void)
{
    g_pstSYSCTLPeripheralGenericMock = nullptr;
}

extern "C" SYSCTL_nERROR SYSCTL__enReadPeripheral(SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg,
                                                   SYSCTL_Register_t* pstRegisterDataArg)
{
    if(nullptr == g_pstSYSCTLPeripheralGenericMock)
    {
        return SYSCTL_enERROR_UNDEF;
    }

    return g_pstSYSCTLPeripheralGenericMock->ReadPeripheral(enModuleArg, enPeripheralArg, pstRegisterDataArg);
}

extern "C" SYSCTL_nERROR SYSCTL__enWritePeripheral(SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg,
                                                    SYSCTL_Register_t* pstRegisterDataArg)
{
    if(nullptr == g_pstSYSCTLPeripheralGenericMock)
    {
        return SYSCTL_enERROR_UNDEF;
    }

    return g_pstSYSCTLPeripheralGenericMock->WritePeripheral(enModuleArg, enPeripheralArg, pstRegisterDataArg);
}