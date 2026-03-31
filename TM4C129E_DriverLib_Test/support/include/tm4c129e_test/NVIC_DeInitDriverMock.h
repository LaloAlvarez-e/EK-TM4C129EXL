/**
 *
 * @file NVIC_DeInitDriverMock.h
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

#ifndef BA9A0378_9892_4155_BC47_E8EEA6AA59D8
#define BA9A0378_9892_4155_BC47_E8EEA6AA59D8

#ifndef C1EF89D8_4A53_46E3_BFE5_96B5B8A854A8
#define C1EF89D8_4A53_46E3_BFE5_96B5B8A854A8

#ifndef TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_NVIC_DEINITDRIVERMOCK_H_
#define TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_NVIC_DEINITDRIVERMOCK_H_

extern "C"
{
#include <xDriver_MCU/Core/NVIC/Driver/xHeader/NVIC_Enable.h>
}

#include <gmock/gmock.h>

class NVIC_DeInitDriverMock
{
public:
    MOCK_METHOD(NVIC_nERROR, DisableVector, (NVIC_nMODULE enModuleArg, NVIC_nVECTOR enVectorArg));
};

void TM4C129E_DriverLib_Test__vSetNVICDeInitDriverMock(NVIC_DeInitDriverMock* pstMockArg);
void TM4C129E_DriverLib_Test__vClearNVICDeInitDriverMock(void);

class NVIC_DeInitDriverMockScope
{
public:
    explicit NVIC_DeInitDriverMockScope(NVIC_DeInitDriverMock* pstMockArg)
    {
        TM4C129E_DriverLib_Test__vSetNVICDeInitDriverMock(pstMockArg);
    }

    ~NVIC_DeInitDriverMockScope()
    {
        TM4C129E_DriverLib_Test__vClearNVICDeInitDriverMock();
    }
};

#endif /* TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_NVIC_DEINITDRIVERMOCK_H_ */

#endif /* C1EF89D8_4A53_46E3_BFE5_96B5B8A854A8 */


#endif /* BA9A0378_9892_4155_BC47_E8EEA6AA59D8 */
