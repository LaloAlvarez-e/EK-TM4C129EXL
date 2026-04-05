/**
 *
 * @file SYSCTL_ReadyDriverMock.h
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

#ifndef CF227C33_6D1A_4B9A_8E4E_88F29D70E11D
#define CF227C33_6D1A_4B9A_8E4E_88F29D70E11D

#ifndef A61797ED_90F1_45F0_A2D5_B2D991A17E67
#define A61797ED_90F1_45F0_A2D5_B2D991A17E67

#ifndef TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSCTL_READYDRIVERMOCK_H_
#define TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSCTL_READYDRIVERMOCK_H_

extern "C"
{
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_PeripheralReady.h>
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_PeripheralReset.h>
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_PeripheralRunMode.h>
}

#include <gmock/gmock.h>

class SYSCTL_ReadyDriverMock
{
public:
    MOCK_METHOD(SYSCTL_nERROR, IsPeripheralReady,
                (SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg, SYSCTL_nBOOLEAN* penReadyArg));
    MOCK_METHOD(SYSCTL_nERROR, EnableRunMode, (SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg));
    MOCK_METHOD(SYSCTL_nERROR, DisableRunMode, (SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg));
    MOCK_METHOD(SYSCTL_nERROR, SetPeripheralReset, (SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg));
};

void TM4C129E_DriverLib_Test__vSetSYSCTLReadyDriverMock(SYSCTL_ReadyDriverMock* pstMockArg);
void TM4C129E_DriverLib_Test__vClearSYSCTLReadyDriverMock(void);

class SYSCTL_ReadyDriverMockScope
{
public:
    explicit SYSCTL_ReadyDriverMockScope(SYSCTL_ReadyDriverMock* pstMockArg)
    {
        TM4C129E_DriverLib_Test__vSetSYSCTLReadyDriverMock(pstMockArg);
    }

    ~SYSCTL_ReadyDriverMockScope()
    {
        TM4C129E_DriverLib_Test__vClearSYSCTLReadyDriverMock();
    }
};

#endif /* TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSCTL_READYDRIVERMOCK_H_ */

#endif /* A61797ED_90F1_45F0_A2D5_B2D991A17E67 */


#endif /* CF227C33_6D1A_4B9A_8E4E_88F29D70E11D */
