/**
 *
 * @file SYSCTL_MCURegisterAccessMock.h
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

#ifndef TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSCTL_MCUREGISTERACCESSMOCK_H_
#define TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSCTL_MCUREGISTERACCESSMOCK_H_

extern "C"
{
#include <xDriver_MCU/Common/xHeader/MCU_CheckParams.h>
#include <xDriver_MCU/Common/xHeader/MCU_ReadReg.h>
#include <xDriver_MCU/Common/xHeader/MCU_WriteReg.h>
}

#include <gmock/gmock.h>

class SYSCTL_MCURegisterAccessMock
{
public:
    MOCK_METHOD(MCU_nERROR, CheckParams, (UBase_t uxModuleArg, UBase_t uxModuleMaxArg));
    MOCK_METHOD(MCU_nERROR, ReadRegister, (MCU_Register_t* pstRegisterDataArg));
    MOCK_METHOD(MCU_nERROR, WriteRegister, (const MCU_Register_t* pstRegisterDataArg));
};

void TM4C129E_DriverLib_Test__vSetSYSCTLMCURegisterAccessMock(SYSCTL_MCURegisterAccessMock* pstMockArg);
void TM4C129E_DriverLib_Test__vClearSYSCTLMCURegisterAccessMock(void);

class SYSCTL_MCURegisterAccessMockScope
{
public:
    explicit SYSCTL_MCURegisterAccessMockScope(SYSCTL_MCURegisterAccessMock* pstMockArg)
    {
        TM4C129E_DriverLib_Test__vSetSYSCTLMCURegisterAccessMock(pstMockArg);
    }

    ~SYSCTL_MCURegisterAccessMockScope()
    {
        TM4C129E_DriverLib_Test__vClearSYSCTLMCURegisterAccessMock();
    }
};

#endif /* TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSCTL_MCUREGISTERACCESSMOCK_H_ */

