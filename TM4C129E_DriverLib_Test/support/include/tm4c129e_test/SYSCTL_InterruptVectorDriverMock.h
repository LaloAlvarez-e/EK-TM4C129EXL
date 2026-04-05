/**
 *
 * @file SYSCTL_InterruptVectorDriverMock.h
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

#ifndef F5983042_F47F_401D_B61A_D9D6B5BEBF79
#define F5983042_F47F_401D_B61A_D9D6B5BEBF79

#ifndef TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSCTL_INTERRUPTVECTORDRIVERMOCK_H_
#define TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSCTL_INTERRUPTVECTORDRIVERMOCK_H_

extern "C"
{
#include <xDriver_MCU/Core/NVIC/NVIC.h>
}

#include <gmock/gmock.h>

class SYSCTL_InterruptVectorDriverMock
{
public:
    MOCK_METHOD(NVIC_nERROR, EnableVector, (NVIC_nMODULE enModuleArg, NVIC_nVECTOR enVectorArg, NVIC_nPRIORITY enPriorityArg));
    MOCK_METHOD(NVIC_nERROR, DisableVector, (NVIC_nMODULE enModuleArg, NVIC_nVECTOR enVectorArg));
};

void TM4C129E_DriverLib_Test__vSetSYSCTLInterruptVectorDriverMock(SYSCTL_InterruptVectorDriverMock* pstMockArg);
void TM4C129E_DriverLib_Test__vClearSYSCTLInterruptVectorDriverMock(void);

class SYSCTL_InterruptVectorDriverMockScope
{
public:
    explicit SYSCTL_InterruptVectorDriverMockScope(SYSCTL_InterruptVectorDriverMock* pstMockArg)
    {
        TM4C129E_DriverLib_Test__vSetSYSCTLInterruptVectorDriverMock(pstMockArg);
    }

    ~SYSCTL_InterruptVectorDriverMockScope()
    {
        TM4C129E_DriverLib_Test__vClearSYSCTLInterruptVectorDriverMock();
    }
};

#endif /* TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSCTL_INTERRUPTVECTORDRIVERMOCK_H_ */


#endif /* F5983042_F47F_401D_B61A_D9D6B5BEBF79 */
