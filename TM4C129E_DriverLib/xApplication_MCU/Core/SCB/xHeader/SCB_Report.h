/**
 *
 * @file SCB_Report.h
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
 * Date           Author     Version     Description
 * 29 mar. 2026   GitHub Copilot    1.0     initial Version@endverbatim
 */

#ifndef E3446190_C88F_4B2C_81E2_4A827228323E
#define E3446190_C88F_4B2C_81E2_4A827228323E

#ifndef XAPPLICATION_MCU_CORE_SCB_XHEADER_SCB_REPORT_H_
#define XAPPLICATION_MCU_CORE_SCB_XHEADER_SCB_REPORT_H_

#include <xApplication_MCU/Core/SCB/Intrinsics/xHeader/SCB_Defines.h>

typedef struct
{
    SCB_nMODULE enModule;
    SCB_nFAULT enFault;
    UBase_t uxSource;
    UBase_t uxStatusMask;
    UBase_t uxFaultAddress;
    UBase_t uxContext[8UL];
} SCB_REPORT_t;

typedef MCU_nERROR (*SCB_pvfReportHandler_t)(void* pvContextArg, const SCB_REPORT_t* pstReportArg);

SCB_nERROR SCB__enRegisterReportHandler(SCB_nFAULT enFaultArg, void* pvContextArg, SCB_pvfReportHandler_t pvfReportHandlerArg);
SCB_nERROR SCB__enUnregisterReportHandler(SCB_nFAULT enFaultArg);
void SCB__vInvokeReportHandler(SCB_nFAULT enFaultArg, const SCB_REPORT_t* pstReportArg);

#endif /* XAPPLICATION_MCU_CORE_SCB_XHEADER_SCB_REPORT_H_ */


#endif /* E3446190_C88F_4B2C_81E2_4A827228323E */
