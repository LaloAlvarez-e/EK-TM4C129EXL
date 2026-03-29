/**
 *
 * @file SCB_InterruptRoutine_UsageFault.c
 * @copyright
 * @verbatim InDeviceMex 2021 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 15 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 15 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/Core/SCB/Interrupt/InterruptRoutine/xHeader/SCB_InterruptRoutine_UsageFault.h>

#include <xApplication_MCU/Core/SCB/Interrupt/InterruptRoutine/xHeader/SCB_InterruptRoutine_Source.h>
#include <xApplication_MCU/Core/SCB/Intrinsics/xHeader/SCB_Dependencies.h>
#include <xApplication_MCU/Core/SCB/xHeader/SCB_Report.h>

static void UsageFault__vCreateReport(SCB_REPORT_t* pstReportArg, SCB_nUSAGE_BIT enSourceArg,
                                      UBase_t uxStatusMaskArg, UBase_t uxFaultAddressArg,
                                      const UBase_t* puxContextArg);

UBase_t SCB_UsageFault_puxContext[8UL];

static void UsageFault__vCreateReport(SCB_REPORT_t* pstReportArg, SCB_nUSAGE_BIT enSourceArg,
                                      UBase_t uxStatusMaskArg, UBase_t uxFaultAddressArg,
                                      const UBase_t* puxContextArg)
{
    UBase_t uxIndexReg;

    pstReportArg->enModule = SCB_enMODULE_0;
    pstReportArg->enFault = SCB_enFAULT_USAGE;
    pstReportArg->uxSource = (UBase_t) enSourceArg;
    pstReportArg->uxStatusMask = uxStatusMaskArg;
    pstReportArg->uxFaultAddress = uxFaultAddressArg;

    for(uxIndexReg = 0UL; uxIndexReg < 8UL; uxIndexReg++)
    {
        pstReportArg->uxContext[uxIndexReg] = puxContextArg[uxIndexReg];
    }
}

void UsageFault__vIRQVectorHandlerReport(uintptr_t uptrModuleArg, void* pvArgument)
{
    SCB_t* pstSCBReg;
    UBase_t uxUsageFault;
    UBase_t uxUsageAddressFault;
    const UBase_t* puxContext;
    SCB_REPORT_t stReport;

    pstSCBReg = (SCB_t*) uptrModuleArg;
    puxContext = (const UBase_t*) pvArgument;

    uxUsageFault = pstSCBReg->CFSR;
    uxUsageFault >>= 16UL;
    uxUsageFault &= (UBase_t) SCB_enUSAGE_ALL;
    uxUsageAddressFault = puxContext[6UL];

    stReport.enModule = SCB_enMODULE_0;
    stReport.enFault = SCB_enFAULT_USAGE;
    stReport.uxSource = 0UL;
    stReport.uxStatusMask = 0UL;
    stReport.uxFaultAddress = 0UL;
    stReport.uxContext[0UL] = 0UL;
    stReport.uxContext[1UL] = 0UL;
    stReport.uxContext[2UL] = 0UL;
    stReport.uxContext[3UL] = 0UL;
    stReport.uxContext[4UL] = 0UL;
    stReport.uxContext[5UL] = 0UL;
    stReport.uxContext[6UL] = 0UL;
    stReport.uxContext[7UL] = 0UL;

    if(0UL == ((UBase_t) SCB_enUSAGE_ALL & uxUsageFault))
    {
        UsageFault__vCreateReport(&stReport, SCB_enUSAGE_BIT_SW, uxUsageFault, uxUsageAddressFault, puxContext);
        SCB__vInvokeReportHandler(stReport.enFault, &stReport);
    }
    else
    {
        if((UBase_t) SCB_enUSAGE_UNDEFINSTR & uxUsageFault)
        {
            UsageFault__vCreateReport(&stReport, SCB_enUSAGE_BIT_UNDEFINSTR, uxUsageFault, uxUsageAddressFault, puxContext);
            SCB__vInvokeReportHandler(stReport.enFault, &stReport);
        }
        if((UBase_t) SCB_enUSAGE_INVSTATE & uxUsageFault)
        {
            UsageFault__vCreateReport(&stReport, SCB_enUSAGE_BIT_INVSTATE, uxUsageFault, uxUsageAddressFault, puxContext);
            SCB__vInvokeReportHandler(stReport.enFault, &stReport);
        }
        if((UBase_t) SCB_enUSAGE_INVPC & uxUsageFault)
        {
            UsageFault__vCreateReport(&stReport, SCB_enUSAGE_BIT_INVPC, uxUsageFault, uxUsageAddressFault, puxContext);
            SCB__vInvokeReportHandler(stReport.enFault, &stReport);
        }
        if((UBase_t) SCB_enUSAGE_NOCP & uxUsageFault)
        {
            UsageFault__vCreateReport(&stReport, SCB_enUSAGE_BIT_NOCP, uxUsageFault, uxUsageAddressFault, puxContext);
            SCB__vInvokeReportHandler(stReport.enFault, &stReport);
        }
        if((UBase_t) SCB_enUSAGE_UNALIGNED & uxUsageFault)
        {
            UsageFault__vCreateReport(&stReport, SCB_enUSAGE_BIT_UNALIGNED, uxUsageFault, uxUsageAddressFault, puxContext);
            SCB__vInvokeReportHandler(stReport.enFault, &stReport);
        }
        if((UBase_t) SCB_enUSAGE_DIVBYZERO & uxUsageFault)
        {
            UsageFault__vCreateReport(&stReport, SCB_enUSAGE_BIT_DIVBYZERO, uxUsageFault, uxUsageAddressFault, puxContext);
            SCB__vInvokeReportHandler(stReport.enFault, &stReport);
        }
    }
}

void UsageFault__vIRQVectorHandlerCustom(uintptr_t uptrModuleArg, void* pvArgument)
{
    SCB_t* pstSCBReg;
    UBase_t uxUsageFault;
    SCB_pvfIRQSourceHandler_t pvfCallback;

    (void) pvArgument;

    pstSCBReg = (SCB_t*) uptrModuleArg;

    uxUsageFault = pstSCBReg->CFSR;
    uxUsageFault >>= 16UL;
    uxUsageFault &= (UBase_t) SCB_enUSAGE_ALL;
    if(0UL == ((UBase_t) SCB_enUSAGE_ALL & uxUsageFault))
    {
        pvfCallback = SCB_UsageFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enUSAGE_BIT_SW);
        pvfCallback(SCB_BASE, (void*) SCB_enUSAGE_BIT_SW);
    }
    else
    {
        if((UBase_t) SCB_enUSAGE_UNDEFINSTR & uxUsageFault)
        {
            pstSCBReg->CFSR = SCB_CFSR_R_UNDEFINSTR_CLEAR;
            pvfCallback = SCB_UsageFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enUSAGE_BIT_UNDEFINSTR);
            pvfCallback(SCB_BASE, (void*) SCB_enUSAGE_BIT_UNDEFINSTR);
        }
        if((UBase_t) SCB_enUSAGE_INVSTATE & uxUsageFault)
        {
            pstSCBReg->CFSR = SCB_CFSR_R_INVSTATE_CLEAR;
            pvfCallback = SCB_UsageFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enUSAGE_BIT_INVSTATE);
            pvfCallback(SCB_BASE, (void*) SCB_enUSAGE_BIT_INVSTATE);
        }
        if((UBase_t) SCB_enUSAGE_INVPC & uxUsageFault)
        {
            pstSCBReg->CFSR = SCB_CFSR_R_INVPC_CLEAR;
            pvfCallback = SCB_UsageFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enUSAGE_BIT_INVPC);
            pvfCallback(SCB_BASE, (void*) SCB_enUSAGE_BIT_INVPC);
        }
        if((UBase_t) SCB_enUSAGE_NOCP & uxUsageFault)
        {
            pstSCBReg->CFSR = SCB_CFSR_R_NOCP_CLEAR;
            pvfCallback = SCB_UsageFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enUSAGE_BIT_NOCP);
            pvfCallback(SCB_BASE, (void*) SCB_enUSAGE_BIT_NOCP);
        }
        if((UBase_t) SCB_enUSAGE_UNALIGNED & uxUsageFault)
        {
            pstSCBReg->CFSR = SCB_CFSR_R_UNALIGNED_CLEAR;
            pvfCallback = SCB_UsageFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enUSAGE_BIT_UNALIGNED);
            pvfCallback(SCB_BASE, (void*) SCB_enUSAGE_BIT_UNALIGNED);
        }
        if((UBase_t) SCB_enUSAGE_DIVBYZERO & uxUsageFault)
        {
            pstSCBReg->CFSR = SCB_CFSR_R_DIVBYZERO_CLEAR;
            pvfCallback = SCB_UsageFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enUSAGE_BIT_DIVBYZERO);
            pvfCallback(SCB_BASE, (void*) SCB_enUSAGE_BIT_DIVBYZERO);
        }
    }
}
