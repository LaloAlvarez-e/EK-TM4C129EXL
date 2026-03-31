/**
 *
 * @file SYSEXC_MCURegisterAccessMock.h
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

#ifndef B769130F_6CC3_4357_983B_88E4FCB7824C
#define B769130F_6CC3_4357_983B_88E4FCB7824C

#ifndef DBB03954_808A_4DE4_A5E8_BA9E1B436CAB
#define DBB03954_808A_4DE4_A5E8_BA9E1B436CAB

#ifndef TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSEXC_MCUREGISTERACCESSMOCK_H_
#define TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSEXC_MCUREGISTERACCESSMOCK_H_

extern "C"
{
#include <xDriver_MCU/Common/xHeader/MCU_CheckParams.h>
#include <xDriver_MCU/Common/xHeader/MCU_ReadReg.h>
#include <xDriver_MCU/Common/xHeader/MCU_WriteReg.h>
}

#include <gmock/gmock.h>

class SYSEXC_MCURegisterAccessMock
{
public:
    MOCK_METHOD(MCU_nERROR, CheckParams, (UBase_t uxModuleArg, UBase_t uxModuleMaxArg));
    MOCK_METHOD(MCU_nERROR, ReadRegister, (MCU_Register_t* pstRegisterDataArg));
    MOCK_METHOD(MCU_nERROR, WriteRegister, (const MCU_Register_t* pstRegisterDataArg));
};

void TM4C129E_DriverLib_Test__vSetSYSEXCMCURegisterAccessMock(SYSEXC_MCURegisterAccessMock* pstMockArg);
void TM4C129E_DriverLib_Test__vClearSYSEXCMCURegisterAccessMock(void);

class SYSEXC_MCURegisterAccessMockScope
{
public:
    explicit SYSEXC_MCURegisterAccessMockScope(SYSEXC_MCURegisterAccessMock* pstMockArg)
    {
        TM4C129E_DriverLib_Test__vSetSYSEXCMCURegisterAccessMock(pstMockArg);
    }

    ~SYSEXC_MCURegisterAccessMockScope()
    {
        TM4C129E_DriverLib_Test__vClearSYSEXCMCURegisterAccessMock();
    }
};

#endif /* TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSEXC_MCUREGISTERACCESSMOCK_H_ */


#endif /* DBB03954_808A_4DE4_A5E8_BA9E1B436CAB */


#endif /* B769130F_6CC3_4357_983B_88E4FCB7824C */
