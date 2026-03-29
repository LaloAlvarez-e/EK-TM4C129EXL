/**
 *
 * @file SCB_InterruptRoutine_NMI.c
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
 * @verbatim 18 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 18 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/Core/SCB/Interrupt/InterruptRoutine/xHeader/SCB_InterruptRoutine_NMI.h>

#include <xApplication_MCU/Core/SCB/Interrupt/InterruptRoutine/xHeader/SCB_InterruptRoutine_Source.h>
#include <xApplication_MCU/Core/SCB/Intrinsics/xHeader/SCB_Dependencies.h>
#include <xApplication_MCU/Core/SCB/xHeader/SCB_Report.h>

static void NMI__vCreateReport(SCB_REPORT_t* pstReportArg, SCB_nNMI_BIT enSourceArg, UBase_t uxStatusMaskArg);

static void NMI__vCreateReport(SCB_REPORT_t* pstReportArg, SCB_nNMI_BIT enSourceArg, UBase_t uxStatusMaskArg)
{
    pstReportArg->enModule = SCB_enMODULE_0;
    pstReportArg->enFault = SCB_enFAULT_NMI;
    pstReportArg->uxSource = (UBase_t) enSourceArg;
    pstReportArg->uxStatusMask = uxStatusMaskArg;
    pstReportArg->uxFaultAddress = 0UL;
    pstReportArg->uxContext[0UL] = 0UL;
    pstReportArg->uxContext[1UL] = 0UL;
    pstReportArg->uxContext[2UL] = 0UL;
    pstReportArg->uxContext[3UL] = 0UL;
    pstReportArg->uxContext[4UL] = 0UL;
    pstReportArg->uxContext[5UL] = 0UL;
    pstReportArg->uxContext[6UL] = 0UL;
    pstReportArg->uxContext[7UL] = 0UL;
}

void NMI__vIRQVectorHandler(void)
{
    NMI__vIRQVectorHandlerReport(SCB_BASE, (void*) 0UL);
    NMI__vIRQVectorHandlerCustom(SCB_BASE, (void*) 0UL);
}

void NMI__vIRQVectorHandlerReport(uintptr_t uptrModuleArg, void* pvArgument)
{
    volatile UBase_t uxRegNMI;
    SCB_REPORT_t stReport;

    (void) uptrModuleArg;
    (void) pvArgument;

    uxRegNMI = SYSCTL_NMIC_R;

    stReport.enModule = SCB_enMODULE_0;
    stReport.enFault = SCB_enFAULT_NMI;
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

    if(0UL == ((UBase_t) SCB_enNMI_ALL & uxRegNMI))
    {
        NMI__vCreateReport(&stReport, SCB_enNMI_BIT_SW, uxRegNMI);
        SCB__vInvokeReportHandler(stReport.enFault, &stReport);
    }
    else
    {
        if(0UL != ((UBase_t) SCB_enNMI_MOSC_FAILURE & uxRegNMI))
        {
            NMI__vCreateReport(&stReport, SCB_enNMI_BIT_MOSC_FAILURE, uxRegNMI);
            SCB__vInvokeReportHandler(stReport.enFault, &stReport);
        }
        if(0UL != ((UBase_t) SCB_enNMI_TAMPER & uxRegNMI))
        {
            NMI__vCreateReport(&stReport, SCB_enNMI_BIT_TAMPER, uxRegNMI);
            SCB__vInvokeReportHandler(stReport.enFault, &stReport);
        }
        if(0UL != ((UBase_t) SCB_enNMI_WDT1 & uxRegNMI))
        {
            NMI__vCreateReport(&stReport, SCB_enNMI_BIT_WDT1, uxRegNMI);
            SCB__vInvokeReportHandler(stReport.enFault, &stReport);
        }
        if(0UL != ((UBase_t) SCB_enNMI_WDT0 & uxRegNMI))
        {
            NMI__vCreateReport(&stReport, SCB_enNMI_BIT_WDT0, uxRegNMI);
            SCB__vInvokeReportHandler(stReport.enFault, &stReport);
        }
        if(0UL != ((UBase_t) SCB_enNMI_POWER & uxRegNMI))
        {
            NMI__vCreateReport(&stReport, SCB_enNMI_BIT_POWER, uxRegNMI);
            SCB__vInvokeReportHandler(stReport.enFault, &stReport);
        }
        if(0UL != ((UBase_t) SCB_enNMI_EXTERNAL & uxRegNMI))
        {
            NMI__vCreateReport(&stReport, SCB_enNMI_BIT_EXTERNAL, uxRegNMI);
            SCB__vInvokeReportHandler(stReport.enFault, &stReport);
        }
    }
}

void NMI__vIRQVectorHandlerCustom(uintptr_t uptrModuleArg, void* pvArgument)
{
    volatile UBase_t uxRegNMI;
    SCB_pvfIRQSourceHandler_t pvfCallback;

    (void) uptrModuleArg;
    (void) pvArgument;

    uxRegNMI = SYSCTL_NMIC_R;

    if(0UL == ((UBase_t) SCB_enNMI_ALL & uxRegNMI))
    {
        pvfCallback = SCB_NMI__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enNMI_BIT_SW);
        pvfCallback(SCB_BASE, (void*) SCB_enNMI_BIT_SW);
    }
    else
    {
        if(0UL != ((UBase_t) SCB_enNMI_MOSC_FAILURE & uxRegNMI))
        {
            do
            {
                SYSCTL_NMIC_R &= ~ (UBase_t) SCB_enNMI_MOSC_FAILURE;
            }while(0UL != ((UBase_t) SCB_enNMI_MOSC_FAILURE & SYSCTL_NMIC_R));

            pvfCallback = SCB_NMI__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enNMI_BIT_MOSC_FAILURE);
            pvfCallback(SCB_BASE, (void*) SCB_enNMI_BIT_MOSC_FAILURE);
        }
        if(0UL != ((UBase_t) SCB_enNMI_TAMPER & uxRegNMI))
        {
            do
            {
                SYSCTL_NMIC_R &= ~(UBase_t) SCB_enNMI_TAMPER;
            }while(0UL != ((UBase_t) SCB_enNMI_TAMPER & SYSCTL_NMIC_R));

            /**
             * TODO: Check if TAMPER requires to be cleared in HIB module
             */
            pvfCallback = SCB_NMI__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enNMI_BIT_TAMPER);
            pvfCallback(SCB_BASE, (void*) SCB_enNMI_BIT_TAMPER);
        }
        if(0UL != ((UBase_t) SCB_enNMI_WDT1 & uxRegNMI))
        {
            UBase_t uxRegWrite1;

            do
            {
                SYSCTL_NMIC_R &= ~(UBase_t) SCB_enNMI_WDT1;
            }while(0UL != ((UBase_t) SCB_enNMI_WDT1 & SYSCTL_NMIC_R));

            WDT1_ICR_R = 0UL;
            do
            {
                uxRegWrite1 = WDT1_CTL_R;
                uxRegWrite1 &= WDT_CTL_R_WRC_MASK;
            }while(WDT_CTL_R_WRC_PROGRESS == uxRegWrite1);

            pvfCallback = SCB_NMI__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enNMI_BIT_WDT1);
            pvfCallback(SCB_BASE, (void*) SCB_enNMI_BIT_WDT1);
        }
        if(0UL != ((UBase_t) SCB_enNMI_WDT0 & uxRegNMI))
        {
            do
            {
                SYSCTL_NMIC_R &= ~(UBase_t) SCB_enNMI_WDT0;
            }while(0UL != ((UBase_t) SCB_enNMI_WDT0 & SYSCTL_NMIC_R));

            WDT0_ICR_R = 0UL;
            pvfCallback = SCB_NMI__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enNMI_BIT_WDT0);
            pvfCallback(SCB_BASE, (void*) SCB_enNMI_BIT_WDT0);
        }
        if(0UL != ((UBase_t) SCB_enNMI_POWER & uxRegNMI))
        {
            do
            {
                SYSCTL_NMIC_R &= ~(UBase_t) SCB_enNMI_POWER;
            }while(0UL != ((UBase_t) SCB_enNMI_POWER & SYSCTL_NMIC_R));

            pvfCallback = SCB_NMI__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enNMI_BIT_POWER);
            pvfCallback(SCB_BASE, (void*) SCB_enNMI_BIT_POWER);
        }
        if(0UL != ((UBase_t) SCB_enNMI_EXTERNAL & uxRegNMI))
        {
            do
            {
                SYSCTL_NMIC_R &= ~(UBase_t) SCB_enNMI_EXTERNAL;
            }while(0UL != ((UBase_t) SCB_enNMI_EXTERNAL & SYSCTL_NMIC_R));

            pvfCallback = SCB_NMI__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enNMI_BIT_EXTERNAL);
            pvfCallback(SCB_BASE, (void*) SCB_enNMI_BIT_EXTERNAL);
        }
    }
}
