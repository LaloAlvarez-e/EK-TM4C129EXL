/**
 *
 * @file NVIC_MCURegisterAccessMock.h
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

#ifndef FEB54E37_7BE9_4356_B930_8D1A24AC0642
#define FEB54E37_7BE9_4356_B930_8D1A24AC0642

#ifndef TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_NVIC_MCUREGISTERACCESSMOCK_H_
#define TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_NVIC_MCUREGISTERACCESSMOCK_H_

extern "C"
{
#include <xDriver_MCU/Common/xHeader/MCU_CheckParams.h>
#include <xDriver_MCU/Common/xHeader/MCU_ReadReg.h>
#include <xDriver_MCU/Common/xHeader/MCU_WriteReg.h>
}

#include <gmock/gmock.h>

class NVIC_MCURegisterAccessMock
{
public:
    MOCK_METHOD(MCU_nERROR, CheckParams, (UBase_t uxModuleArg, UBase_t uxModuleMaxArg));
    MOCK_METHOD(MCU_nERROR, ReadRegister, (MCU_Register_t* pstRegisterDataArg));
    MOCK_METHOD(MCU_nERROR, WriteRegister, (const MCU_Register_t* pstRegisterDataArg));
};

void TM4C129E_DriverLib_Test__vSetNVICMCURegisterAccessMock(NVIC_MCURegisterAccessMock* pstMockArg);
void TM4C129E_DriverLib_Test__vClearNVICMCURegisterAccessMock(void);

class NVIC_MCURegisterAccessMockScope
{
public:
    explicit NVIC_MCURegisterAccessMockScope(NVIC_MCURegisterAccessMock* pstMockArg)
    {
        TM4C129E_DriverLib_Test__vSetNVICMCURegisterAccessMock(pstMockArg);
    }

    ~NVIC_MCURegisterAccessMockScope()
    {
        TM4C129E_DriverLib_Test__vClearNVICMCURegisterAccessMock();
    }
};

#endif /* TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_NVIC_MCUREGISTERACCESSMOCK_H_ */


#endif /* FEB54E37_7BE9_4356_B930_8D1A24AC0642 */
