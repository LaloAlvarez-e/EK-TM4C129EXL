 /**
 *
 * @file SCB_InterruptRoutine_BusFault.c
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
#include <xApplication_MCU/Core/SCB/Interrupt/InterruptRoutine/xHeader/SCB_InterruptRoutine_BusFault.h>

#include <xApplication_MCU/Core/SCB/Interrupt/InterruptRoutine/xHeader/SCB_InterruptRoutine_Source.h>
#include <xApplication_MCU/Core/SCB/Intrinsics/xHeader/SCB_Dependencies.h>
#include <xApplication_MCU/Core/SCB/xHeader/SCB_Report.h>

static void BusFault__vCreateReport(SCB_REPORT_t* pstReportArg, SCB_nBUS_BIT enSourceArg,
                                    UBase_t uxStatusMaskArg, UBase_t uxFaultAddressArg,
                                    const UBase_t* puxContextArg);

UBase_t SCB_BusFault_puxContext[8UL];

static void BusFault__vCreateReport(SCB_REPORT_t* pstReportArg, SCB_nBUS_BIT enSourceArg,
                                    UBase_t uxStatusMaskArg, UBase_t uxFaultAddressArg,
                                    const UBase_t* puxContextArg)
{
    UBase_t uxIndexReg;

    pstReportArg->enModule = SCB_enMODULE_0;
    pstReportArg->enFault = SCB_enFAULT_BUS;
    pstReportArg->uxSource = (UBase_t) enSourceArg;
    pstReportArg->uxStatusMask = uxStatusMaskArg;
    pstReportArg->uxFaultAddress = uxFaultAddressArg;

    for(uxIndexReg = 0UL; uxIndexReg < 8UL; uxIndexReg++)
    {
        pstReportArg->uxContext[uxIndexReg] = puxContextArg[uxIndexReg];
    }
}

void BusFault__vIRQVectorHandlerReport(uintptr_t uptrModuleArg, void* pvArgument)
{
    SCB_t* pstSCBReg;
    UBase_t uxBusFault;
    UBase_t uxBusAddressValid;
    UBase_t uxBusAddressFault;
    const UBase_t* puxContext;
    SCB_REPORT_t stReport;

    pstSCBReg = (SCB_t*) uptrModuleArg;
    puxContext = (const UBase_t*) pvArgument;

    uxBusAddressValid = 0UL;
    uxBusFault = pstSCBReg->CFSR;
    uxBusFault >>= 8UL;
    uxBusFault &= (UBase_t) SCB_enBUS_ALL;
    uxBusAddressFault = puxContext[6UL];

    stReport.enModule = SCB_enMODULE_0;
    stReport.enFault = SCB_enFAULT_BUS;
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

    if(0UL == ((UBase_t) SCB_enBUS_ALL & uxBusFault))
    {
        BusFault__vCreateReport(&stReport, SCB_enBUS_BIT_SW, uxBusFault, uxBusAddressFault, puxContext);
        SCB__vInvokeReportHandler(stReport.enFault, &stReport);
    }
    else
    {
        if((UBase_t) SCB_enBUS_LSPERR & uxBusFault)
        {
            BusFault__vCreateReport(&stReport, SCB_enBUS_BIT_LSPERR, uxBusFault, uxBusAddressFault, puxContext);
            SCB__vInvokeReportHandler(stReport.enFault, &stReport);
        }
        if((UBase_t) SCB_enBUS_STKERR & uxBusFault)
        {
            BusFault__vCreateReport(&stReport, SCB_enBUS_BIT_STKERR, uxBusFault, uxBusAddressFault, puxContext);
            SCB__vInvokeReportHandler(stReport.enFault, &stReport);
        }
        if((UBase_t) SCB_enBUS_UNSTKERR & uxBusFault)
        {
            BusFault__vCreateReport(&stReport, SCB_enBUS_BIT_UNSTKERR, uxBusFault, uxBusAddressFault, puxContext);
            SCB__vInvokeReportHandler(stReport.enFault, &stReport);
        }
        if((UBase_t) SCB_enBUS_IMPRECISERR & uxBusFault)
        {
            BusFault__vCreateReport(&stReport, SCB_enBUS_BIT_IMPRECISERR, uxBusFault, uxBusAddressFault, puxContext);
            SCB__vInvokeReportHandler(stReport.enFault, &stReport);
        }
        if((UBase_t) SCB_enBUS_BFARVALID & uxBusFault)
        {
            uxBusAddressValid = 1UL;
            uxBusAddressFault = pstSCBReg->BFAR;
            BusFault__vCreateReport(&stReport, SCB_enBUS_BIT_BFARVALID, uxBusFault, uxBusAddressFault, puxContext);
            SCB__vInvokeReportHandler(stReport.enFault, &stReport);
        }
        if((UBase_t) SCB_enBUS_PRECISERR & uxBusFault)
        {
            if(1UL == uxBusAddressValid)
            {
                uxBusAddressFault = pstSCBReg->BFAR;
            }
            else
            {
                uxBusAddressFault = puxContext[6UL];
            }
            BusFault__vCreateReport(&stReport, SCB_enBUS_BIT_PRECISERR, uxBusFault, uxBusAddressFault, puxContext);
            SCB__vInvokeReportHandler(stReport.enFault, &stReport);
        }
        if((UBase_t) SCB_enBUS_IBUSERR & uxBusFault)
        {
            uxBusAddressFault = puxContext[6UL];
            BusFault__vCreateReport(&stReport, SCB_enBUS_BIT_IBUSERR, uxBusFault, uxBusAddressFault, puxContext);
            SCB__vInvokeReportHandler(stReport.enFault, &stReport);
        }
    }
}

void BusFault__vIRQVectorHandlerCustom(uintptr_t uptrModuleArg, void* pvArgument)
{
    SCB_t* pstSCBReg;
    UBase_t uxBusFault;
    SCB_pvfIRQSourceHandler_t pvfCallback;

    (void) pvArgument;

    pstSCBReg = (SCB_t*) uptrModuleArg;

    uxBusFault = pstSCBReg->CFSR;
    uxBusFault >>= 8UL;
    uxBusFault &= (UBase_t) SCB_enBUS_ALL;
    if(0UL == ((UBase_t) SCB_enBUS_ALL & uxBusFault))
    {
        pvfCallback = SCB_BusFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enBUS_BIT_SW);
        pvfCallback(SCB_BASE, (void*) SCB_enBUS_BIT_SW);
    }
    else
    {
        if((UBase_t) SCB_enBUS_LSPERR & uxBusFault)
        {
            pstSCBReg->CFSR = SCB_CFSR_R_LSPERR_CLEAR;
            pvfCallback = SCB_BusFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enBUS_BIT_LSPERR);
            pvfCallback(SCB_BASE, (void*) SCB_enBUS_BIT_LSPERR);
        }
        if((UBase_t) SCB_enBUS_STKERR & uxBusFault)
        {
            pstSCBReg->CFSR = SCB_CFSR_R_STKERR_CLEAR;
            pvfCallback = SCB_BusFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enBUS_BIT_STKERR);
            pvfCallback(SCB_BASE, (void*) SCB_enBUS_BIT_STKERR);
        }
        if((UBase_t) SCB_enBUS_UNSTKERR & uxBusFault)
        {
            pstSCBReg->CFSR = SCB_CFSR_R_UNSTKERR_CLEAR;
            pvfCallback = SCB_BusFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enBUS_BIT_UNSTKERR);
            pvfCallback(SCB_BASE, (void*) SCB_enBUS_BIT_UNSTKERR);
        }
        if((UBase_t) SCB_enBUS_IMPRECISERR & uxBusFault)
        {
            pstSCBReg->CFSR = SCB_CFSR_R_IMPRECISERR_CLEAR;
            pvfCallback = SCB_BusFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enBUS_BIT_IMPRECISERR);
            pvfCallback(SCB_BASE, (void*) SCB_enBUS_BIT_IMPRECISERR);
        }
        if((UBase_t) SCB_enBUS_BFARVALID & uxBusFault)
        {
            pstSCBReg->CFSR = SCB_CFSR_R_BFARVALID_CLEAR;
            pvfCallback = SCB_BusFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enBUS_BIT_BFARVALID);
            pvfCallback(SCB_BASE, (void*) SCB_enBUS_BIT_BFARVALID);
        }
        if((UBase_t) SCB_enBUS_PRECISERR & uxBusFault)
        {
            pstSCBReg->CFSR = SCB_CFSR_R_PRECISERR_CLEAR;
            pvfCallback = SCB_BusFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enBUS_BIT_PRECISERR);
            pvfCallback(SCB_BASE, (void*) SCB_enBUS_BIT_PRECISERR);
        }
        if((UBase_t) SCB_enBUS_IBUSERR & uxBusFault)
        {
            pstSCBReg->CFSR = SCB_CFSR_R_IBUSERR_CLEAR;
            pvfCallback = SCB_BusFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enBUS_BIT_IBUSERR);
            pvfCallback(SCB_BASE, (void*) SCB_enBUS_BIT_IBUSERR);
        }
    }

}


