/**
 *
 * @file SYSCTL_InterruptRoutineMock.h
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
 * @verbatim 4 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 4 abr. 2026    GitHub Copilot   1.0         initial Version@endverbatim
 */

#ifndef CE6A89C2_E6EF_4125_9D1F_A51F4FF95B2F
#define CE6A89C2_E6EF_4125_9D1F_A51F4FF95B2F

#ifndef TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSCTL_INTERRUPTRUTINEMOCK_H_
#define TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSCTL_INTERRUPTRUTINEMOCK_H_

extern "C"
{
#include <xDriver_MCU/SYSCTL/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/SYSCTL_InterruptRoutine_Source.h>
}

#include <gmock/gmock.h>

using SYSCTL_TestIRQSourceHandler_t = SYSCTL_pvfIRQSourceHandler_t;

class SYSCTL_InterruptRoutineMock
{
public:
    MOCK_METHOD(SYSCTL_TestIRQSourceHandler_t, GetIRQSourceHandler, (SYSCTL_nMODULE enModuleArg, SYSCTL_nINT enIntSourceArg));
};

void TM4C129E_DriverLib_Test__vSetSYSCTLInterruptRoutineMock(SYSCTL_InterruptRoutineMock* pstMockArg);
void TM4C129E_DriverLib_Test__vClearSYSCTLInterruptRoutineMock(void);

class SYSCTL_InterruptRoutineMockScope
{
public:
    explicit SYSCTL_InterruptRoutineMockScope(SYSCTL_InterruptRoutineMock* pstMockArg)
    {
        TM4C129E_DriverLib_Test__vSetSYSCTLInterruptRoutineMock(pstMockArg);
    }

    ~SYSCTL_InterruptRoutineMockScope()
    {
        TM4C129E_DriverLib_Test__vClearSYSCTLInterruptRoutineMock();
    }
};

#endif /* TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSCTL_INTERRUPTRUTINEMOCK_H_ */


#endif /* CE6A89C2_E6EF_4125_9D1F_A51F4FF95B2F */
