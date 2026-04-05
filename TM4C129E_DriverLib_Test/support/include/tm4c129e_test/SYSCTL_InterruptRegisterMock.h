/**
 *
 * @file SYSCTL_InterruptRegisterMock.h
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

#ifndef C49D9112_DF58_458A_B971_CEA3F78374CB
#define C49D9112_DF58_458A_B971_CEA3F78374CB

#ifndef D5758490_4F53_4EA1_A27F_A3A814556A2E
#define D5758490_4F53_4EA1_A27F_A3A814556A2E

#ifndef TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSCTL_INTERRUPTREGISTERMOCK_H_
#define TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSCTL_INTERRUPTREGISTERMOCK_H_

extern "C"
{
#include <xApplication_MCU/Core/SCB/xHeader/SCB_RegisterIRQVector.h>
}

#include <gmock/gmock.h>

class SYSCTL_InterruptRegisterMock
{
public:
    MOCK_METHOD(SCB_nERROR,
                RegisterIRQVectorHandler,
                (SCB_nMODULE enModuleArg,
                 SCB_nVECISR enVectorArg,
                 SCB_pvfIRQVectorHandler_t pfIrqVectorHandlerArg,
                 SCB_pvfIRQVectorHandler_t* pfIrqVectorHandlerExternArg));
};

void TM4C129E_DriverLib_Test__vSetSYSCTLInterruptRegisterMock(SYSCTL_InterruptRegisterMock* pstMockArg);
void TM4C129E_DriverLib_Test__vClearSYSCTLInterruptRegisterMock(void);

class SYSCTL_InterruptRegisterMockScope
{
public:
    explicit SYSCTL_InterruptRegisterMockScope(SYSCTL_InterruptRegisterMock* pstMockArg)
    {
        TM4C129E_DriverLib_Test__vSetSYSCTLInterruptRegisterMock(pstMockArg);
    }

    ~SYSCTL_InterruptRegisterMockScope()
    {
        TM4C129E_DriverLib_Test__vClearSYSCTLInterruptRegisterMock();
    }
};

#endif /* TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSCTL_INTERRUPTREGISTERMOCK_H_ */


#endif /* D5758490_4F53_4EA1_A27F_A3A814556A2E */


#endif /* C49D9112_DF58_458A_B971_CEA3F78374CB */
