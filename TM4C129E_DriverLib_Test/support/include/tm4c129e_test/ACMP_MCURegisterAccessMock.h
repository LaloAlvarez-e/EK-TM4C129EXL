/**
 *
 * @file ACMP_MCURegisterAccessMock.h
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

#ifndef DD128BD9_92EF_43BA_80B9_4C1FCECD7962
#define DD128BD9_92EF_43BA_80B9_4C1FCECD7962

#ifndef TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_ACMP_MCUREGISTERACCESSMOCK_H_
#define TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_ACMP_MCUREGISTERACCESSMOCK_H_

extern "C"
{
#include <xDriver_MCU/Common/xHeader/MCU_CheckParams.h>
#include <xDriver_MCU/Common/xHeader/MCU_ReadReg.h>
#include <xDriver_MCU/Common/xHeader/MCU_WriteReg.h>
}

#include <gmock/gmock.h>

class ACMP_MCURegisterAccessMock
{
public:
    MOCK_METHOD(MCU_nERROR, CheckParams, (UBase_t uxModuleArg, UBase_t uxModuleMaxArg));
    MOCK_METHOD(MCU_nERROR, ReadRegister, (MCU_Register_t* pstRegisterDataArg));
    MOCK_METHOD(MCU_nERROR, WriteRegister, (const MCU_Register_t* pstRegisterDataArg));
};

void TM4C129E_DriverLib_Test__vSetACMPMCURegisterAccessMock(ACMP_MCURegisterAccessMock* pstMockArg);
void TM4C129E_DriverLib_Test__vClearACMPMCURegisterAccessMock(void);

class ACMP_MCURegisterAccessMockScope
{
public:
    explicit ACMP_MCURegisterAccessMockScope(ACMP_MCURegisterAccessMock* pstMockArg)
    {
        TM4C129E_DriverLib_Test__vSetACMPMCURegisterAccessMock(pstMockArg);
    }

    ~ACMP_MCURegisterAccessMockScope()
    {
        TM4C129E_DriverLib_Test__vClearACMPMCURegisterAccessMock();
    }
};

#endif /* TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_ACMP_MCUREGISTERACCESSMOCK_H_ */


#endif /* DD128BD9_92EF_43BA_80B9_4C1FCECD7962 */
