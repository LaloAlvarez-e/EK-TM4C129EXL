/**
 *
 * @file SCB_InterruptRoutine_MemoryFault.c
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
#include <xApplication_MCU/Core/SCB/Interrupt/InterruptRoutine/xHeader/SCB_InterruptRoutine_MemoryFault.h>

#include <xApplication_MCU/Core/SCB/Interrupt/InterruptRoutine/xHeader/SCB_InterruptRoutine_Source.h>
#include <xApplication_MCU/Core/SCB/Intrinsics/xHeader/SCB_Dependencies.h>
#include <xApplication_MCU/Core/SCB/xHeader/SCB_Report.h>

static void MemoryFault__vCreateReport(SCB_REPORT_t* pstReportArg, SCB_nMEMORY_BIT enSourceArg,
                                       UBase_t uxStatusMaskArg, UBase_t uxFaultAddressArg,
                                       const UBase_t* puxContextArg);

UBase_t SCB_MemoryFault_puxContext[8UL];

static void MemoryFault__vCreateReport(SCB_REPORT_t* pstReportArg, SCB_nMEMORY_BIT enSourceArg,
                                       UBase_t uxStatusMaskArg, UBase_t uxFaultAddressArg,
                                       const UBase_t* puxContextArg)
{
    UBase_t uxIndexReg;

    pstReportArg->enModule = SCB_enMODULE_0;
    pstReportArg->enFault = SCB_enFAULT_MEMORY;
    pstReportArg->uxSource = (UBase_t) enSourceArg;
    pstReportArg->uxStatusMask = uxStatusMaskArg;
    pstReportArg->uxFaultAddress = uxFaultAddressArg;

    for(uxIndexReg = 0UL; uxIndexReg < 8UL; uxIndexReg++)
    {
        pstReportArg->uxContext[uxIndexReg] = puxContextArg[uxIndexReg];
    }
}

void MemoryFault__vIRQVectorHandlerReport(uintptr_t uptrModuleArg, void* pvArgument)
{
    SCB_t* pstSCBReg;
    UBase_t uxMemoryFault;
    UBase_t uxMemoryAddressValid;
    UBase_t uxMemoryAddressFault;
    const UBase_t* puxContext;
    SCB_REPORT_t stReport;

    pstSCBReg = (SCB_t*) uptrModuleArg;
    puxContext = (const UBase_t*) pvArgument;

    uxMemoryAddressValid = 0UL;
    uxMemoryFault = pstSCBReg->CFSR;
    uxMemoryFault >>= 0UL;
    uxMemoryFault &= (UBase_t) SCB_enMEMORY_ALL;
    uxMemoryAddressFault = puxContext[6UL];

    stReport.enModule = SCB_enMODULE_0;
    stReport.enFault = SCB_enFAULT_MEMORY;
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

    if(0UL == ((UBase_t) SCB_enMEMORY_ALL & uxMemoryFault))
    {
        MemoryFault__vCreateReport(&stReport, SCB_enMEMORY_BIT_SW, uxMemoryFault, uxMemoryAddressFault, puxContext);
        SCB__vInvokeReportHandler(stReport.enFault, &stReport);
    }
    else
    {
        if((UBase_t) SCB_enMEMORY_MLSPERR & uxMemoryFault)
        {
            MemoryFault__vCreateReport(&stReport, SCB_enMEMORY_BIT_MLSPERR, uxMemoryFault, uxMemoryAddressFault, puxContext);
            SCB__vInvokeReportHandler(stReport.enFault, &stReport);
        }
        if((UBase_t) SCB_enMEMORY_MSTKERR & uxMemoryFault)
        {
            MemoryFault__vCreateReport(&stReport, SCB_enMEMORY_BIT_MSTKERR, uxMemoryFault, uxMemoryAddressFault, puxContext);
            SCB__vInvokeReportHandler(stReport.enFault, &stReport);
        }
        if((UBase_t) SCB_enMEMORY_MUNSTKERR & uxMemoryFault)
        {
            MemoryFault__vCreateReport(&stReport, SCB_enMEMORY_BIT_MUNSTKERR, uxMemoryFault, uxMemoryAddressFault, puxContext);
            SCB__vInvokeReportHandler(stReport.enFault, &stReport);
        }
        if((UBase_t) SCB_enMEMORY_MMARVALID & uxMemoryFault)
        {
            uxMemoryAddressValid = 1UL;
            uxMemoryAddressFault = pstSCBReg->MMFAR;
            MemoryFault__vCreateReport(&stReport, SCB_enMEMORY_BIT_MMARVALID, uxMemoryFault, uxMemoryAddressFault, puxContext);
            SCB__vInvokeReportHandler(stReport.enFault, &stReport);
        }
        if((UBase_t) SCB_enMEMORY_DACCVIOL & uxMemoryFault)
        {
            if(1UL == uxMemoryAddressValid)
            {
                uxMemoryAddressFault = pstSCBReg->MMFAR;
            }
            else
            {
                uxMemoryAddressFault = puxContext[6UL];
            }
            MemoryFault__vCreateReport(&stReport, SCB_enMEMORY_BIT_DACCVIOL, uxMemoryFault, uxMemoryAddressFault, puxContext);
            SCB__vInvokeReportHandler(stReport.enFault, &stReport);
        }
        if((UBase_t) SCB_enMEMORY_IACCVIOL & uxMemoryFault)
        {
            uxMemoryAddressFault = puxContext[6UL];
            MemoryFault__vCreateReport(&stReport, SCB_enMEMORY_BIT_IACCVIOL, uxMemoryFault, uxMemoryAddressFault, puxContext);
            SCB__vInvokeReportHandler(stReport.enFault, &stReport);
        }
    }
}

void MemoryFault__vIRQVectorHandlerCustom(uintptr_t uptrModuleArg, void* pvArgument)
{
    SCB_t* pstSCBReg;
    UBase_t uxMemoryFault;
    SCB_pvfIRQSourceHandler_t pvfCallback;

    (void) pvArgument;

    pstSCBReg = (SCB_t*) uptrModuleArg;

    uxMemoryFault = pstSCBReg->CFSR;
    uxMemoryFault >>= 0UL;
    uxMemoryFault &= (UBase_t) SCB_enMEMORY_ALL;
    if(0UL == ((UBase_t) SCB_enMEMORY_ALL & uxMemoryFault))
    {
        pvfCallback = SCB_MemoryFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enMEMORY_BIT_SW);
        pvfCallback(SCB_BASE, (void*) SCB_enMEMORY_BIT_SW);
    }
    else
    {
        if((UBase_t) SCB_enMEMORY_MLSPERR & uxMemoryFault)
        {
            pstSCBReg->CFSR = SCB_CFSR_R_MLSPERR_CLEAR;
            pvfCallback = SCB_MemoryFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enMEMORY_BIT_MLSPERR);
            pvfCallback(SCB_BASE, (void*) SCB_enMEMORY_BIT_MLSPERR);
        }
        if((UBase_t) SCB_enMEMORY_MSTKERR & uxMemoryFault)
        {
            pstSCBReg->CFSR = SCB_CFSR_R_MSTKERR_CLEAR;
            pvfCallback = SCB_MemoryFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enMEMORY_BIT_MSTKERR);
            pvfCallback(SCB_BASE, (void*) SCB_enMEMORY_BIT_MSTKERR);
        }
        if((UBase_t) SCB_enMEMORY_MUNSTKERR & uxMemoryFault)
        {
            pstSCBReg->CFSR = SCB_CFSR_R_MUNSTKERR_CLEAR;
            pvfCallback = SCB_MemoryFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enMEMORY_BIT_MUNSTKERR);
            pvfCallback(SCB_BASE, (void*) SCB_enMEMORY_BIT_MUNSTKERR);
        }
        if((UBase_t) SCB_enMEMORY_MMARVALID & uxMemoryFault)
        {
            pstSCBReg->CFSR = SCB_CFSR_R_MMARVALID_CLEAR;
            pvfCallback = SCB_MemoryFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enMEMORY_BIT_MMARVALID);
            pvfCallback(SCB_BASE, (void*) SCB_enMEMORY_BIT_MMARVALID);
        }
        if((UBase_t) SCB_enMEMORY_DACCVIOL & uxMemoryFault)
        {
            pstSCBReg->CFSR = SCB_CFSR_R_DACCVIOL_CLEAR;
            pvfCallback = SCB_MemoryFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enMEMORY_BIT_DACCVIOL);
            pvfCallback(SCB_BASE, (void*) SCB_enMEMORY_BIT_DACCVIOL);
        }
        if((UBase_t) SCB_enMEMORY_IACCVIOL & uxMemoryFault)
        {
            pstSCBReg->CFSR = SCB_CFSR_R_IACCVIOL_CLEAR;
            pvfCallback = SCB_MemoryFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enMEMORY_BIT_IACCVIOL);
            pvfCallback(SCB_BASE, (void*) SCB_enMEMORY_BIT_IACCVIOL);
        }
    }

}


