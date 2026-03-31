/**
 *
 * @file SYSCTL_PeripheralGenericMock.h
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
 * @verbatim 30 mar. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 30 mar. 2026   GitHub Copilot   1.0         initial Version@endverbatim
 */

#ifndef B45AF058_4A27_439E_9BA6_862F9F1F85AA
#define B45AF058_4A27_439E_9BA6_862F9F1F85AA

#ifndef TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSCTL_PERIPHERALGENERICMOCK_H_
#define TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSCTL_PERIPHERALGENERICMOCK_H_

extern "C"
{
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_PeripheralGeneric.h>
}

#include <gmock/gmock.h>

class SYSCTL_PeripheralGenericMock
{
public:
    MOCK_METHOD(SYSCTL_nERROR, ReadPeripheral,
                (SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg, SYSCTL_Register_t* pstRegisterDataArg));
    MOCK_METHOD(SYSCTL_nERROR, WritePeripheral,
                (SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg, SYSCTL_Register_t* pstRegisterDataArg));
};

void TM4C129E_DriverLib_Test__vSetSYSCTLPeripheralGenericMock(SYSCTL_PeripheralGenericMock* pstMockArg);
void TM4C129E_DriverLib_Test__vClearSYSCTLPeripheralGenericMock(void);

class SYSCTL_PeripheralGenericMockScope
{
public:
    explicit SYSCTL_PeripheralGenericMockScope(SYSCTL_PeripheralGenericMock* pstMockArg)
    {
        TM4C129E_DriverLib_Test__vSetSYSCTLPeripheralGenericMock(pstMockArg);
    }

    ~SYSCTL_PeripheralGenericMockScope()
    {
        TM4C129E_DriverLib_Test__vClearSYSCTLPeripheralGenericMock();
    }
};

#endif /* TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSCTL_PERIPHERALGENERICMOCK_H_ */


#endif /* B45AF058_4A27_439E_9BA6_862F9F1F85AA */
