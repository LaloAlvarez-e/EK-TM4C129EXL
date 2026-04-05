/**
 *
 * @file SYSCTL_InitDriverMock.h
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
 * @verbatim 3 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 3 abr. 2026    GitHub Copilot   1.0         initial Version@endverbatim
 */

#ifndef C834FC04_C0FB_4D1D_9060_58A53183454B
#define C834FC04_C0FB_4D1D_9060_58A53183454B

#ifndef TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSCTL_INITDRIVERMOCK_H_
#define TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSCTL_INITDRIVERMOCK_H_

extern "C"
{
#include <xApplication_MCU/SYSCTL/Intrinsics/xHeader/SYSCTL_Dependencies.h>
#include <xApplication_MCU/SYSCTL/Interrupt/SYSCTL_Interrupt.h>
}

#include <gmock/gmock.h>

using SYSCTL_TestIRQVectorHandler_t = SYSCTL_pvfIRQVectorHandler_t;

class SYSCTL_InitDriverMock
{
public:
    MOCK_METHOD(MCU_nERROR, CheckParams, (UBase_t uxValueArg, UBase_t uxMaxArg));
    MOCK_METHOD(SYSCTL_TestIRQVectorHandler_t, GetIRQVectorHandler, ());
    MOCK_METHOD(SYSCTL_nERROR, RegisterIRQVectorHandler, (SYSCTL_TestIRQVectorHandler_t pfIrqVectorHandlerArg));
    MOCK_METHOD(SYSCTL_nERROR, DisableInterruptSourceByMask, (SYSCTL_nMODULE enModuleArg, SYSCTL_nINTMASK enInterruptMaskArg));
    MOCK_METHOD(SYSCTL_nERROR, ClearInterruptSourceByMask, (SYSCTL_nMODULE enModuleArg, SYSCTL_nINTMASK enInterruptMaskArg));
    MOCK_METHOD(SYSCTL_nERROR, EnableInterruptSourceByMask, (SYSCTL_nMODULE enModuleArg, SYSCTL_nINTMASK enInterruptMaskArg));
    MOCK_METHOD(SYSCTL_nERROR, EnableInterruptVector, (SYSCTL_nPRIORITY enPriorityArg));
    MOCK_METHOD(SYSCTL_nERROR, DisableInterruptVector, ());
};

void TM4C129E_DriverLib_Test__vSetSYSCTLInitDriverMock(SYSCTL_InitDriverMock* pstMockArg);
void TM4C129E_DriverLib_Test__vClearSYSCTLInitDriverMock(void);

class SYSCTL_InitDriverMockScope
{
public:
    explicit SYSCTL_InitDriverMockScope(SYSCTL_InitDriverMock* pstMockArg)
    {
        TM4C129E_DriverLib_Test__vSetSYSCTLInitDriverMock(pstMockArg);
    }

    ~SYSCTL_InitDriverMockScope()
    {
        TM4C129E_DriverLib_Test__vClearSYSCTLInitDriverMock();
    }
};

#endif /* TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSCTL_INITDRIVERMOCK_H_ */


#endif /* C834FC04_C0FB_4D1D_9060_58A53183454B */
