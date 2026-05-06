/**
 *
 * @file SCB_InterruptRoutine_HardFault.c
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
#include <xApplication_MCU/Core/SCB/Interrupt/InterruptRoutine/xHeader/SCB_InterruptRoutine_HardFault.h>
#include <xApplication_MCU/Core/SCB/Interrupt/InterruptRoutine/xHeader/SCB_InterruptRoutine_MemoryFault.h>
#include <xApplication_MCU/Core/SCB/Interrupt/InterruptRoutine/xHeader/SCB_InterruptRoutine_UsageFault.h>

#include <xApplication_MCU/Core/SCB/Interrupt/InterruptRoutine/xHeader/SCB_InterruptRoutine_Source.h>
#include <xApplication_MCU/Core/SCB/Intrinsics/xHeader/SCB_Dependencies.h>
#include <xApplication_MCU/Core/SCB/xHeader/SCB_Report.h>

static void HardFault__vCreateReport(SCB_REPORT_t* pstReportArg, SCB_nHARD_BIT enSourceArg,
                                     UBase_t uxStatusMaskArg, UBase_t uxFaultAddressArg,
                                     const UBase_t* puxContextArg);

UBase_t SCB_HardFault_puxContext[8UL];

static void HardFault__vCreateReport(SCB_REPORT_t* pstReportArg, SCB_nHARD_BIT enSourceArg,
                                     UBase_t uxStatusMaskArg, UBase_t uxFaultAddressArg,
                                     const UBase_t* puxContextArg)
{
    UBase_t uxIndexReg;

    pstReportArg->enModule = SCB_enMODULE_0;
    pstReportArg->enFault = SCB_enFAULT_HARD;
    pstReportArg->uxSource = (UBase_t) enSourceArg;
    pstReportArg->uxStatusMask = uxStatusMaskArg;
    pstReportArg->uxFaultAddress = uxFaultAddressArg;

    for(uxIndexReg = 0UL; uxIndexReg < 8UL; uxIndexReg++)
    {
        pstReportArg->uxContext[uxIndexReg] = puxContextArg[uxIndexReg];
    }
}

void HardFault__vIRQVectorHandlerReport(uintptr_t uptrModuleArg, void* pvArgument)
{
    SCB_t* pstSCBReg;
    UBase_t uxHardFault;
    UBase_t uxFaultType;
    UBase_t uxHardMemoryFault;
    const UBase_t* puxContext;
    SCB_REPORT_t stReport;

    pstSCBReg = (SCB_t*) uptrModuleArg;
    puxContext = (const UBase_t*) pvArgument;

    uxFaultType = pstSCBReg->HFSR;
    uxHardMemoryFault = puxContext[6UL];

    stReport.enModule = SCB_enMODULE_0;
    stReport.enFault = SCB_enFAULT_HARD;
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

    if(0UL != uxFaultType)
    {
        if(SCB_HFSR_R_FORCED_MASK & uxFaultType)
        {
            uxHardFault = pstSCBReg->CFSR;
            if(((UBase_t)SCB_enMEMORY_ALL << 0UL) & uxHardFault)
            {
                MemoryFault__vIRQVectorHandlerReport(SCB_BASE, (void*) pvArgument);
            }
            else if(((UBase_t)SCB_enBUS_ALL << 8UL) & uxHardFault)
            {
                BusFault__vIRQVectorHandlerReport(SCB_BASE, (void*) pvArgument);
            }
            else if(((UBase_t)SCB_enUSAGE_ALL << 16UL) & uxHardFault)
            {
                UsageFault__vIRQVectorHandlerReport(SCB_BASE, (void*) pvArgument);
            }
        }
        if(SCB_HFSR_R_VECTTBL_MASK & uxFaultType)
        {
            HardFault__vCreateReport(&stReport, SCB_enHARD_BIT_VECT, uxFaultType, uxHardMemoryFault, puxContext);
            SCB__vInvokeReportHandler(stReport.enFault, &stReport);
        }
    }
    else
    {
        HardFault__vCreateReport(&stReport, SCB_enHARD_BIT_SW, uxFaultType, uxHardMemoryFault, puxContext);
        SCB__vInvokeReportHandler(stReport.enFault, &stReport);
    }
}

void HardFault__vIRQVectorHandlerCustom(uintptr_t uptrModuleArg, void* pvArgument)
{
    SCB_t* pstSCBReg;
    UBase_t uxHardFault;
    SCB_pvfIRQSourceHandler_t pvfCallback;
    UBase_t uxFaultType;

    pstSCBReg = (SCB_t*) uptrModuleArg;

    uxFaultType = pstSCBReg->HFSR;

    if(0UL != uxFaultType)
    {
        if(SCB_HFSR_R_FORCED_MASK & uxFaultType)
        {
            pstSCBReg->HFSR = SCB_HFSR_R_FORCED_MASK;
            uxHardFault = pstSCBReg->CFSR;
            if(((UBase_t)SCB_enMEMORY_ALL << 0UL) & uxHardFault)
            {
                MemoryFault__vIRQVectorHandlerCustom(SCB_BASE, (void*) pvArgument);
            }
            else if(((UBase_t)SCB_enBUS_ALL << 8UL) & uxHardFault)
            {
                BusFault__vIRQVectorHandlerCustom(SCB_BASE, (void*) pvArgument);
            }
            else if(((UBase_t)SCB_enUSAGE_ALL << 16UL) & uxHardFault)
            {
                UsageFault__vIRQVectorHandlerCustom(SCB_BASE, (void*) pvArgument);
            }
        }
        if(SCB_HFSR_R_VECTTBL_MASK & uxFaultType)
        {
            pstSCBReg->HFSR = SCB_HFSR_R_VECTTBL_MASK;
            pvfCallback = SCB_HardFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enHARD_BIT_VECT);
            pvfCallback(SCB_BASE, (void*) SCB_enHARD_BIT_VECT);
        }
    }
    else
    {
        pvfCallback = SCB_HardFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enHARD_BIT_SW);
        pvfCallback(SCB_BASE, (void*) SCB_enHARD_BIT_SW);
    }
}
