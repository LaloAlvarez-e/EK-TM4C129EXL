/**
 *
 * @file NVIC_RegisterPrimitivesMock.h
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

#ifndef TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_NVIC_REGISTERPRIMITIVESMOCK_H_
#define TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_NVIC_REGISTERPRIMITIVESMOCK_H_

extern "C"
{
#include <xDriver_MCU/Common/xHeader/MCU_Enum.h>
#include <xDriver_MCU/Core/NVIC/Driver/Intrinsics/Primitives/xHeader/NVIC_ReadRegister.h>
#include <xDriver_MCU/Core/NVIC/Driver/Intrinsics/Primitives/xHeader/NVIC_WriteRegister.h>
}

#include <gmock/gmock.h>

class NVIC_RegisterPrimitivesMock
{
public:
    MOCK_METHOD(MCU_nERROR, CheckParams, (UBase_t uxModuleArg, UBase_t uxModuleMaxArg));
    MOCK_METHOD(NVIC_nERROR, ReadRegister, (NVIC_nMODULE enModuleArg, NVIC_Register_t* pstRegisterDataArg));
    MOCK_METHOD(NVIC_nERROR, WriteRegister, (NVIC_nMODULE enModuleArg, NVIC_Register_t* pstRegisterDataArg));
};

void TM4C129E_DriverLib_Test__vSetNVICRegisterPrimitivesMock(NVIC_RegisterPrimitivesMock* pstMockArg);
void TM4C129E_DriverLib_Test__vClearNVICRegisterPrimitivesMock(void);

class NVIC_RegisterPrimitivesMockScope
{
public:
    explicit NVIC_RegisterPrimitivesMockScope(NVIC_RegisterPrimitivesMock* pstMockArg)
    {
        TM4C129E_DriverLib_Test__vSetNVICRegisterPrimitivesMock(pstMockArg);
    }

    ~NVIC_RegisterPrimitivesMockScope()
    {
        TM4C129E_DriverLib_Test__vClearNVICRegisterPrimitivesMock();
    }
};

#endif /* TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_NVIC_REGISTERPRIMITIVESMOCK_H_ */
