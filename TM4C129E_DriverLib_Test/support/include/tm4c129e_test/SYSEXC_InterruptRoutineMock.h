/**
 *
 * @file SYSEXC_InterruptRoutineMock.h
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

#ifndef AADCB942_6831_4C81_BE38_55F045B9CE04
#define AADCB942_6831_4C81_BE38_55F045B9CE04

#ifndef A860A56B5_E55E_4691_98B1_6AFEB7D98BC6
#define A860A56B5_E55E_4691_98B1_6AFEB7D98BC6

#ifndef TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSEXC_INTERRUPTRUTINEMOCK_H_
#define TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSEXC_INTERRUPTRUTINEMOCK_H_

extern "C"
{
#include <xApplication_MCU/SYSEXC/xHeader/SYSEXC_Report.h>
#include <xDriver_MCU/SYSEXC/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/SYSEXC_InterruptRoutine_Source.h>
}

#include <gmock/gmock.h>

using SYSEXC_TestIRQSourceHandler_t = SYSEXC_pvfIRQSourceHandler_t;

class SYSEXC_InterruptRoutineMock
{
public:
    MOCK_METHOD(void, InvokeReportHandler, (const SYSEXC_REPORT_t* pstReportArg));
    MOCK_METHOD(SYSEXC_TestIRQSourceHandler_t, GetIRQSourceHandler, (SYSEXC_nMODULE enModuleArg, SYSEXC_nINT enIntSourceArg));
};

void TM4C129E_DriverLib_Test__vSetSYSEXCInterruptRoutineMock(SYSEXC_InterruptRoutineMock* pstMockArg);
void TM4C129E_DriverLib_Test__vClearSYSEXCInterruptRoutineMock(void);

class SYSEXC_InterruptRoutineMockScope
{
public:
    explicit SYSEXC_InterruptRoutineMockScope(SYSEXC_InterruptRoutineMock* pstMockArg)
    {
        TM4C129E_DriverLib_Test__vSetSYSEXCInterruptRoutineMock(pstMockArg);
    }

    ~SYSEXC_InterruptRoutineMockScope()
    {
        TM4C129E_DriverLib_Test__vClearSYSEXCInterruptRoutineMock();
    }
};

#endif /* TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSEXC_INTERRUPTRUTINEMOCK_H_ */


#endif /* A860A56B5_E55E_4691_98B1_6AFEB7D98BC6 */


#endif /* AADCB942_6831_4C81_BE38_55F045B9CE04 */
