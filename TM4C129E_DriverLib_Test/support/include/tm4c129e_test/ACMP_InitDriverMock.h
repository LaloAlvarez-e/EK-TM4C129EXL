/**
 *
 * @file ACMP_InitDriverMock.h
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

#ifndef B1AB0BC7_7622_4ABF_A00A_18C14D88EDD6
#define B1AB0BC7_7622_4ABF_A00A_18C14D88EDD6

#ifndef A8493925C_6FED_4309_A80E_A9E856D801EE
#define A8493925C_6FED_4309_A80E_A9E856D801EE

#ifndef TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_ACMP_INITDRIVERMOCK_H_
#define TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_ACMP_INITDRIVERMOCK_H_

extern "C"
{
#include <xApplication_MCU/ACMP/Intrinsics/xHeader/ACMP_Defines.h>
}

#include <gmock/gmock.h>

using ACMP_TestIRQVectorHandler_t = ACMP_pvfIRQVectorHandler_t;

class ACMP_InitDriverMock
{
public:
    MOCK_METHOD(ACMP_nERROR, SetReadyOnRunMode, (ACMP_nMODULE enModuleArg));
    MOCK_METHOD(ACMP_TestIRQVectorHandler_t, GetIRQVectorHandler, (ACMP_nMODULE enModuleArg, ACMP_nCOMP enComparatorArg));
    MOCK_METHOD(ACMP_nERROR, RegisterIRQVectorHandler, (ACMP_nMODULE enModuleArg, ACMP_nCOMP enComparatorArg, ACMP_TestIRQVectorHandler_t pfIrqVectorHandlerArg));
};

void TM4C129E_DriverLib_Test__vSetACMPInitDriverMock(ACMP_InitDriverMock* pstMockArg);
void TM4C129E_DriverLib_Test__vClearACMPInitDriverMock(void);

class ACMP_InitDriverMockScope
{
public:
    explicit ACMP_InitDriverMockScope(ACMP_InitDriverMock* pstMockArg)
    {
        TM4C129E_DriverLib_Test__vSetACMPInitDriverMock(pstMockArg);
    }

    ~ACMP_InitDriverMockScope()
    {
        TM4C129E_DriverLib_Test__vClearACMPInitDriverMock();
    }
};

#endif /* TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_ACMP_INITDRIVERMOCK_H_ */


#endif /* A8493925C_6FED_4309_A80E_A9E856D801EE */


#endif /* B1AB0BC7_7622_4ABF_A00A_18C14D88EDD6 */
