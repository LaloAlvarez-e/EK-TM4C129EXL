/**
 *
 * @file TIMER_InterruptRegisterMock.h
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

#ifndef BFEBAC53_853F_4ADC_B69F_A05658733022
#define BFEBAC53_853F_4ADC_B69F_A05658733022

#ifndef TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_TIMER_INTERRUPTREGISTERMOCK_H_
#define TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_TIMER_INTERRUPTREGISTERMOCK_H_

extern "C"
{
#include <xApplication_MCU/Core/SCB/xHeader/SCB_RegisterIRQVector.h>
#include <xDriver_MCU/TIMER/Driver/Intrinsics/Primitives/xHeader/TIMER_SubParams.h>
}

#include <gmock/gmock.h>

using TIMER_TestIRQVectorHandler_t = void (*)(void);
using TIMER_TestIRQVectorHandlerPointer_t = TIMER_TestIRQVectorHandler_t*;

class TIMER_InterruptRegisterMock
{
public:
    MOCK_METHOD(void, GetSubParams, (TIMER_nMODULE enModuleArg, UBase_t* puxSubModuleArg, UBase_t* puxModuleNumberArg));
    MOCK_METHOD(SCB_nERROR,
                RegisterIRQVectorHandler,
                (SCB_nMODULE enModuleArg,
                 SCB_nVECISR enVectorArg,
                 SCB_pvfIRQVectorHandler_t pfIrqVectorHandlerArg,
                 SCB_pvfIRQVectorHandler_t* pfIrqVectorHandlerExternArg));
    MOCK_METHOD(TIMER_TestIRQVectorHandlerPointer_t,
                GetIRQVectorHandlerPointer,
                (TIMER_nSUBMODULE enSubModuleArg, TIMER_nMODULE_NUM enModuleNumberArg));
};

void TM4C129E_DriverLib_Test__vSetTIMERInterruptRegisterMock(TIMER_InterruptRegisterMock* pstMockArg);
void TM4C129E_DriverLib_Test__vClearTIMERInterruptRegisterMock(void);

class TIMER_InterruptRegisterMockScope
{
public:
    explicit TIMER_InterruptRegisterMockScope(TIMER_InterruptRegisterMock* pstMockArg)
    {
        TM4C129E_DriverLib_Test__vSetTIMERInterruptRegisterMock(pstMockArg);
    }

    ~TIMER_InterruptRegisterMockScope()
    {
        TM4C129E_DriverLib_Test__vClearTIMERInterruptRegisterMock();
    }
};

#endif /* TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_TIMER_INTERRUPTREGISTERMOCK_H_ */


#endif /* BFEBAC53_853F_4ADC_B69F_A05658733022 */
