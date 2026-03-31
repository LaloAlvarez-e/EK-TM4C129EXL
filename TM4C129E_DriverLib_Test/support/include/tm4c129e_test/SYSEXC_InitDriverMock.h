/**
 *
 * @file SYSEXC_InitDriverMock.h
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

#ifndef TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSEXC_INITDRIVERMOCK_H_
#define TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSEXC_INITDRIVERMOCK_H_

extern "C"
{
#include <xApplication_MCU/SYSEXC/Intrinsics/xHeader/SYSEXC_Dependencies.h>
}

#include <gmock/gmock.h>

class SYSEXC_InitDriverMock
{
public:
    MOCK_METHOD(MCU_nERROR, CheckParams, (UBase_t uxValueArg, UBase_t uxMaxArg));
    MOCK_METHOD(SYSEXC_pvfIRQVectorHandler_t, GetIRQVectorHandler, (SYSEXC_nMODULE enModuleArg));
    MOCK_METHOD(SYSEXC_nERROR, RegisterIRQVectorHandler, (SYSEXC_nMODULE enModuleArg, SYSEXC_pvfIRQVectorHandler_t pfIrqVectorHandlerArg));
    MOCK_METHOD(SYSEXC_nERROR, DisableInterruptSourceByMask, (SYSEXC_nMODULE enModuleArg, SYSEXC_nINTMASK enInterruptMaskArg));
    MOCK_METHOD(SYSEXC_nERROR, ClearInterruptSourceByMask, (SYSEXC_nMODULE enModuleArg, SYSEXC_nINTMASK enInterruptMaskArg));
    MOCK_METHOD(SYSEXC_nERROR, EnableInterruptSourceByMask, (SYSEXC_nMODULE enModuleArg, SYSEXC_nINTMASK enInterruptMaskArg));
    MOCK_METHOD(SYSEXC_nERROR, EnableInterruptVectorWithPriority, (SYSEXC_nMODULE enModuleArg, SYSEXC_nPRIORITY enPriorityArg));
};

void TM4C129E_DriverLib_Test__vSetSYSEXCInitDriverMock(SYSEXC_InitDriverMock* pstMockArg);
void TM4C129E_DriverLib_Test__vClearSYSEXCInitDriverMock(void);

class SYSEXC_InitDriverMockScope
{
public:
    explicit SYSEXC_InitDriverMockScope(SYSEXC_InitDriverMock* pstMockArg)
    {
        TM4C129E_DriverLib_Test__vSetSYSEXCInitDriverMock(pstMockArg);
    }

    ~SYSEXC_InitDriverMockScope()
    {
        TM4C129E_DriverLib_Test__vClearSYSEXCInitDriverMock();
    }
};

#endif /* TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSEXC_INITDRIVERMOCK_H_ */
