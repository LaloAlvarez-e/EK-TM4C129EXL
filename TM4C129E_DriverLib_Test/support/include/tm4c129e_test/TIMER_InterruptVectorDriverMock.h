/**
 *
 * @file TIMER_InterruptVectorDriverMock.h
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

#ifndef DC31C071_A9F4_4DBE_B9A8_2EB345287D44
#define DC31C071_A9F4_4DBE_B9A8_2EB345287D44

#ifndef TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_TIMER_INTERRUPTVECTORDRIVERMOCK_H_
#define TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_TIMER_INTERRUPTVECTORDRIVERMOCK_H_

extern "C"
{
#include <xDriver_MCU/Core/NVIC/NVIC.h>
#include <xDriver_MCU/TIMER/Driver/Intrinsics/Primitives/xHeader/TIMER_SubParams.h>
}

#include <gmock/gmock.h>

class TIMER_InterruptVectorDriverMock
{
public:
    MOCK_METHOD(void, GetSubParams, (TIMER_nMODULE enModuleArg, UBase_t* puxSubModuleArg, UBase_t* puxModuleNumberArg));
    MOCK_METHOD(NVIC_nERROR, EnableVector, (NVIC_nMODULE enModuleArg, NVIC_nVECTOR enVectorArg, NVIC_nPRIORITY enPriorityArg));
    MOCK_METHOD(NVIC_nERROR, DisableVector, (NVIC_nMODULE enModuleArg, NVIC_nVECTOR enVectorArg));
};

void TM4C129E_DriverLib_Test__vSetTIMERInterruptVectorDriverMock(TIMER_InterruptVectorDriverMock* pstMockArg);
void TM4C129E_DriverLib_Test__vClearTIMERInterruptVectorDriverMock(void);

class TIMER_InterruptVectorDriverMockScope
{
public:
    explicit TIMER_InterruptVectorDriverMockScope(TIMER_InterruptVectorDriverMock* pstMockArg)
    {
        TM4C129E_DriverLib_Test__vSetTIMERInterruptVectorDriverMock(pstMockArg);
    }

    ~TIMER_InterruptVectorDriverMockScope()
    {
        TM4C129E_DriverLib_Test__vClearTIMERInterruptVectorDriverMock();
    }
};

#endif /* TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_TIMER_INTERRUPTVECTORDRIVERMOCK_H_ */


#endif /* DC31C071_A9F4_4DBE_B9A8_2EB345287D44 */
