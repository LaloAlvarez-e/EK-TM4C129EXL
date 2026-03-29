/**
 *
 * @file SCB_Report.c
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

#include <xApplication_MCU/Core/SCB/xHeader/SCB_Report.h>

#include <xDriver_MCU/Common/MCU_Common.h>

typedef struct
{
    SCB_pvfReportHandler_t pvfReportHandler;
    void* pvReportHandlerContext;
} SCB_REPORT_HANDLER_t;

static SCB_REPORT_HANDLER_t SCB_astReportHandler[SCB_enFAULT_MAX] =
{
    {(SCB_pvfReportHandler_t) 0UL, (void*) 0UL},
    {(SCB_pvfReportHandler_t) 0UL, (void*) 0UL},
    {(SCB_pvfReportHandler_t) 0UL, (void*) 0UL},
    {(SCB_pvfReportHandler_t) 0UL, (void*) 0UL},
    {(SCB_pvfReportHandler_t) 0UL, (void*) 0UL},
};

SCB_nERROR SCB__enRegisterReportHandler(SCB_nFAULT enFaultArg, void* pvContextArg, SCB_pvfReportHandler_t pvfReportHandlerArg)
{
    SCB_nERROR enErrorReg;

    enErrorReg = (SCB_nERROR) MCU__enCheckParams((UBase_t) enFaultArg, (UBase_t) SCB_enFAULT_MAX);
    if(SCB_enERROR_OK == enErrorReg)
    {
        enErrorReg = (0UL == (uintptr_t) pvfReportHandlerArg) ? SCB_enERROR_POINTER : SCB_enERROR_OK;
    }
    if(SCB_enERROR_OK == enErrorReg)
    {
        SCB_astReportHandler[(UBase_t) enFaultArg].pvfReportHandler = pvfReportHandlerArg;
        SCB_astReportHandler[(UBase_t) enFaultArg].pvReportHandlerContext = pvContextArg;
    }

    return (enErrorReg);
}

SCB_nERROR SCB__enUnregisterReportHandler(SCB_nFAULT enFaultArg)
{
    SCB_nERROR enErrorReg;

    enErrorReg = (SCB_nERROR) MCU__enCheckParams((UBase_t) enFaultArg, (UBase_t) SCB_enFAULT_MAX);
    if(SCB_enERROR_OK == enErrorReg)
    {
        SCB_astReportHandler[(UBase_t) enFaultArg].pvfReportHandler = (SCB_pvfReportHandler_t) 0UL;
        SCB_astReportHandler[(UBase_t) enFaultArg].pvReportHandlerContext = (void*) 0UL;
    }
    return (enErrorReg);
}

void SCB__vInvokeReportHandler(SCB_nFAULT enFaultArg, const SCB_REPORT_t* pstReportArg)
{
    SCB_nERROR enErrorReg;

    enErrorReg = (SCB_nERROR) MCU__enCheckParams((UBase_t) enFaultArg, (UBase_t) SCB_enFAULT_MAX);
    if((SCB_enERROR_OK == enErrorReg) && (0UL != (uintptr_t) pstReportArg)
            && (0UL != (uintptr_t) SCB_astReportHandler[(UBase_t) enFaultArg].pvfReportHandler))
    {
        SCB_astReportHandler[(UBase_t) enFaultArg].pvfReportHandler(
                SCB_astReportHandler[(UBase_t) enFaultArg].pvReportHandlerContext, pstReportArg);
    }
}