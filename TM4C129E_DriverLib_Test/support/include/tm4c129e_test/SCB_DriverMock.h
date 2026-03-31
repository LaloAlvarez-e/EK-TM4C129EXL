/**
 *
 * @file SCB_DriverMock.h
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

#ifndef B71C7D34_7C88_4994_B3F2_2378C6386F14
#define B71C7D34_7C88_4994_B3F2_2378C6386F14

#ifndef AFA6A95F_CA31_465C_A03C_2A55FC8A8AF3
#define AFA6A95F_CA31_465C_A03C_2A55FC8A8AF3

#ifndef TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SCB_DRIVERMOCK_H_
#define TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SCB_DRIVERMOCK_H_

extern "C"
{
#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/Core/SCB/Driver/Intrinsics/Primitives/xHeader/SCB_ReadRegister.h>
#include <xDriver_MCU/Core/SCB/Driver/Intrinsics/Primitives/xHeader/SCB_WriteRegister.h>
}

#include <gmock/gmock.h>

class SCB_DriverMock
{
public:
    MOCK_METHOD(MCU_nERROR, CheckParams, (UBase_t uxValueArg, UBase_t uxMaxArg));
    MOCK_METHOD(SCB_nERROR, ReadRegister, (SCB_nMODULE enModuleArg, SCB_Register_t* pstRegisterDataArg));
    MOCK_METHOD(SCB_nERROR, WriteRegister, (SCB_nMODULE enModuleArg, SCB_Register_t* pstRegisterDataArg));
    MOCK_METHOD(void, DataSyncBarrier, ());
    MOCK_METHOD(MCU_nSTATE, DisableGlobalInterrupt, ());
    MOCK_METHOD(void, SetGlobalInterrupt, (MCU_nSTATE enStateArg));
    MOCK_METHOD(void, WaitForInterrupt, ());
};

void TM4C129E_DriverLib_Test__vSetSCBDriverMock(SCB_DriverMock* pstMockArg);
void TM4C129E_DriverLib_Test__vClearSCBDriverMock(void);

class SCB_DriverMockScope
{
public:
    explicit SCB_DriverMockScope(SCB_DriverMock* pstMockArg)
    {
        TM4C129E_DriverLib_Test__vSetSCBDriverMock(pstMockArg);
    }

    ~SCB_DriverMockScope()
    {
        TM4C129E_DriverLib_Test__vClearSCBDriverMock();
    }
};

#endif /* TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SCB_DRIVERMOCK_H_ */


#endif /* AFA6A95F_CA31_465C_A03C_2A55FC8A8AF3 */


#endif /* B71C7D34_7C88_4994_B3F2_2378C6386F14 */
