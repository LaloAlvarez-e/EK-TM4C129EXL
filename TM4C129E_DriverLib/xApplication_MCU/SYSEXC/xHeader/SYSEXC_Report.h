/**
 *
 * @file SYSEXC_Report.h
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
 * @verbatim 24 mar. 2026 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 24 mar. 2026     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef XAPPLICATION_MCU_SYSEXC_XHEADER_SYSEXC_REPORT_H_
#define XAPPLICATION_MCU_SYSEXC_XHEADER_SYSEXC_REPORT_H_

#include <xApplication_MCU/SYSEXC/Intrinsics/xHeader/SYSEXC_Defines.h>

typedef struct
{
    SYSEXC_nMODULE enModule;
    SYSEXC_nINT enSource;
    SYSEXC_nINTMASK enStatusMask;
    UBase_t uxFaultAddress;
    UBase_t uxICSR;
    UBase_t uxActiveVector;
    UBase_t uxStackedVector;
    UBase_t uxContext[8UL];
} SYSEXC_REPORT_t;

typedef MCU_nERROR (*SYSEXC_pvfReportHandler_t)(void* pvContextArg, const SYSEXC_REPORT_t* pstReportArg);


SYSEXC_nERROR SYSEXC__enRegisterReportHandler(void* pvContextArg, SYSEXC_pvfReportHandler_t pvfReportHandlerArg);
SYSEXC_nERROR SYSEXC__enUnregisterReportHandler(void);
void SYSEXC__vInvokeReportHandler(const SYSEXC_REPORT_t* pstReportArg);

#endif /* XAPPLICATION_MCU_SYSEXC_XHEADER_SYSEXC_REPORT_H_ */
