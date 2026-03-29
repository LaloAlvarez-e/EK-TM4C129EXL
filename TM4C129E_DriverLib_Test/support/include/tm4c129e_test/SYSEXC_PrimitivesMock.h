/**
 *
 * @file SYSEXC_PrimitivesMock.h
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

#ifndef TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSEXC_PRIMITIVESMOCK_H_
#define TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSEXC_PRIMITIVESMOCK_H_

extern "C"
{
#include <xDriver_MCU/Common/xHeader/MCU_Enum.h>
#include <xDriver_MCU/SYSEXC/Driver/Intrinsics/Primitives/xHeader/SYSEXC_ReadRegister.h>
#include <xDriver_MCU/SYSEXC/Driver/Intrinsics/Primitives/xHeader/SYSEXC_WriteRegister.h>
}

#include <gmock/gmock.h>

class SYSEXC_PrimitivesMock
{
public:
    MOCK_METHOD(MCU_nERROR, CheckParams, (UBase_t uxModuleArg, UBase_t uxModuleMaxArg));
    MOCK_METHOD(UBase_t, CheckParamsRaw, (UBase_t uxModuleArg, UBase_t uxModuleMaxArg));
    MOCK_METHOD(SYSEXC_nERROR, ReadRegister, (SYSEXC_nMODULE enModuleArg, SYSEXC_Register_t* pstRegisterDataArg));
    MOCK_METHOD(SYSEXC_nERROR, WriteRegister, (SYSEXC_nMODULE enModuleArg, SYSEXC_Register_t* pstRegisterDataArg));
};

void TM4C129E_DriverLib_Test__vSetSYSEXCPrimitivesMock(SYSEXC_PrimitivesMock* pstMockArg);
void TM4C129E_DriverLib_Test__vClearSYSEXCPrimitivesMock(void);

class SYSEXC_PrimitivesMockScope
{
public:
    explicit SYSEXC_PrimitivesMockScope(SYSEXC_PrimitivesMock* pstMockArg)
    {
        TM4C129E_DriverLib_Test__vSetSYSEXCPrimitivesMock(pstMockArg);
    }

    ~SYSEXC_PrimitivesMockScope()
    {
        TM4C129E_DriverLib_Test__vClearSYSEXCPrimitivesMock();
    }
};

#endif /* TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSEXC_PRIMITIVESMOCK_H_ */