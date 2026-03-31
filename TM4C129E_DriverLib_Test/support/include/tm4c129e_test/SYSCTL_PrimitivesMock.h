/**
 *
 * @file SYSCTL_PrimitivesMock.h
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

#ifndef D0B0A1B4_2AEB_44FE_B428_2D236DED4814
#define D0B0A1B4_2AEB_44FE_B428_2D236DED4814

#ifndef TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSCTL_PRIMITIVESMOCK_H_
#define TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSCTL_PRIMITIVESMOCK_H_

extern "C"
{
#include <xDriver_MCU/SYSCTL/Driver/Intrinsics/Primitives/xHeader/SYSCTL_ReadRegister.h>
#include <xDriver_MCU/SYSCTL/Driver/Intrinsics/Primitives/xHeader/SYSCTL_WriteRegister.h>
}

#include <gmock/gmock.h>

class SYSCTL_PrimitivesMock
{
public:
    MOCK_METHOD(SYSCTL_nERROR, ReadRegister, (SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg));
    MOCK_METHOD(SYSCTL_nERROR, WriteRegister, (SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg));
};

void TM4C129E_DriverLib_Test__vSetSYSCTLPrimitivesMock(SYSCTL_PrimitivesMock* pstMockArg);
void TM4C129E_DriverLib_Test__vClearSYSCTLPrimitivesMock(void);

class SYSCTL_PrimitivesMockScope
{
public:
    explicit SYSCTL_PrimitivesMockScope(SYSCTL_PrimitivesMock* pstMockArg)
    {
        TM4C129E_DriverLib_Test__vSetSYSCTLPrimitivesMock(pstMockArg);
    }

    ~SYSCTL_PrimitivesMockScope()
    {
        TM4C129E_DriverLib_Test__vClearSYSCTLPrimitivesMock();
    }
};

#endif /* TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSCTL_PRIMITIVESMOCK_H_ */


#endif /* D0B0A1B4_2AEB_44FE_B428_2D236DED4814 */
