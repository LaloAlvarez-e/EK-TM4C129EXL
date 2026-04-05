/**
 *
 * @file TIMER_InitDriverMock.h
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

#ifndef BA265E3E_3C95_43F8_8D11_406EC63E7C00
#define BA265E3E_3C95_43F8_8D11_406EC63E7C00

#ifndef TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_TIMER_INITDRIVERMOCK_H_
#define TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_TIMER_INITDRIVERMOCK_H_

extern "C"
{
#include <xApplication_MCU/TIMER/Intrinsics/xHeader/TIMER_Defines.h>
}

#include <gmock/gmock.h>

using TIMER_TestIRQVectorHandler_t = void (*)(void);

class TIMER_InitDriverMock
{
public:
    MOCK_METHOD(TIMER_TestIRQVectorHandler_t, GetIRQVectorHandler, (TIMER_nSUBMODULE enSubModuleArg, TIMER_nMODULE_NUM enModuleNumberArg));
    MOCK_METHOD(TIMER_nERROR, RegisterIRQVectorHandler, (TIMER_TestIRQVectorHandler_t pfIrqVectorHandlerArg, TIMER_nMODULE enModuleArg));
};

void TM4C129E_DriverLib_Test__vSetTIMERInitDriverMock(TIMER_InitDriverMock* pstMockArg);
void TM4C129E_DriverLib_Test__vClearTIMERInitDriverMock(void);

class TIMER_InitDriverMockScope
{
public:
    explicit TIMER_InitDriverMockScope(TIMER_InitDriverMock* pstMockArg)
    {
        TM4C129E_DriverLib_Test__vSetTIMERInitDriverMock(pstMockArg);
    }

    ~TIMER_InitDriverMockScope()
    {
        TM4C129E_DriverLib_Test__vClearTIMERInitDriverMock();
    }
};

#endif /* TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_TIMER_INITDRIVERMOCK_H_ */


#endif /* BA265E3E_3C95_43F8_8D11_406EC63E7C00 */
