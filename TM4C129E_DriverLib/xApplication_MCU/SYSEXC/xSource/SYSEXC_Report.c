/**
 *
 * @file SYSEXC_Report.c
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

#include <xApplication_MCU/SYSEXC/xHeader/SYSEXC_Report.h>

#include <xDriver_MCU/Common/MCU_Common.h>

static SYSEXC_pvfReportHandler_t SYSEXC_pvfReportHandler = (SYSEXC_pvfReportHandler_t) 0UL;
static void* SYSEXC_pvReportHandlerContext = (void*) 0UL;

SYSEXC_nERROR SYSEXC__enRegisterReportHandler(void* pvContextArg, SYSEXC_pvfReportHandler_t pvfReportHandlerArg)
{
    SYSEXC_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) pvfReportHandlerArg) ? SYSEXC_enERROR_POINTER : SYSEXC_enERROR_OK;
    if(SYSEXC_enERROR_OK == enErrorReg)
    {
        SYSEXC_pvfReportHandler = pvfReportHandlerArg;
        SYSEXC_pvReportHandlerContext = pvContextArg;
    }

    return (enErrorReg);
}

SYSEXC_nERROR SYSEXC__enUnregisterReportHandler(void)
{
    SYSEXC_pvfReportHandler = (SYSEXC_pvfReportHandler_t) 0UL;
    SYSEXC_pvReportHandlerContext = (void*) 0UL;
    return (SYSEXC_enERROR_OK);
}

void SYSEXC__vInvokeReportHandler(const SYSEXC_REPORT_t* pstReportArg)
{
    if((0UL != (uintptr_t) pstReportArg) && (0UL != (uintptr_t) SYSEXC_pvfReportHandler))
    {
        SYSEXC_pvfReportHandler(SYSEXC_pvReportHandlerContext, pstReportArg);
    }
}
