/**
 *
 * @file SYSCTL_DeInitClockGatesMock.h
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

#ifndef DE9529F5_19B2_4D34_9951_14C090E4DA15
#define DE9529F5_19B2_4D34_9951_14C090E4DA15

#ifndef DD4D1E64_0344_43A3_A6A3_85A7E85E2E81
#define DD4D1E64_0344_43A3_A6A3_85A7E85E2E81

#ifndef TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSCTL_DEINITCLOCKGATESMOCK_H_
#define TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSCTL_DEINITCLOCKGATESMOCK_H_

extern "C"
{
#include <xDriver_MCU/SYSCTL/App/xHeader/SYSCTL_Ready.h>
}

#include <gmock/gmock.h>

class SYSCTL_DeInitClockGatesMock
{
public:
    MOCK_METHOD(SYSCTL_nERROR, ClearReadyOnRunMode, (SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg));
};

void TM4C129E_DriverLib_Test__vSetSYSCTLDeInitClockGatesMock(SYSCTL_DeInitClockGatesMock* pstMockArg);
void TM4C129E_DriverLib_Test__vClearSYSCTLDeInitClockGatesMock(void);

class SYSCTL_DeInitClockGatesMockScope
{
public:
    explicit SYSCTL_DeInitClockGatesMockScope(SYSCTL_DeInitClockGatesMock* pstMockArg)
    {
        TM4C129E_DriverLib_Test__vSetSYSCTLDeInitClockGatesMock(pstMockArg);
    }

    ~SYSCTL_DeInitClockGatesMockScope()
    {
        TM4C129E_DriverLib_Test__vClearSYSCTLDeInitClockGatesMock();
    }
};

#endif /* TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSCTL_DEINITCLOCKGATESMOCK_H_ */

#endif /* DD4D1E64_0344_43A3_A6A3_85A7E85E2E81 */


#endif /* DE9529F5_19B2_4D34_9951_14C090E4DA15 */
