/**
 *
 * @file SYSEXC_InterruptRoutine_Vector.c
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
 * @verbatim 11 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 11 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/SYSEXC/Interrupt/InterruptRoutine/xHeader/SYSEXC_InterruptRoutine_Vector.h>
#include <xApplication_MCU/SYSEXC/Intrinsics/xHeader/SYSEXC_Dependencies.h>
#include <xApplication_MCU/SYSEXC/xHeader/SYSEXC_Report.h>
#include <xDriver_MCU/Core/SCB/Peripheral/Register/xHeader/SCB_RegisterPeripheral.h>
#include <xDriver_MCU/Core/SCB/Peripheral/Register/RegisterDefines/xHeader/SCB_RegisterDefines_INTCTLR.h>

static void SYSEXC__vCreateReport(SYSEXC_REPORT_t* pstReportArg, SYSEXC_nINT enSourceArg,
                                  UBase_t uxStatusMaskArg, UBase_t uxFaultAddressArg,
                                  const UBase_t* puxContextArg);
UBase_t SYSEXC_puxContext[8UL];

static void SYSEXC__vCreateReport(SYSEXC_REPORT_t* pstReportArg, SYSEXC_nINT enSourceArg,
                                  UBase_t uxStatusMaskArg, UBase_t uxFaultAddressArg,
                                  const UBase_t* puxContextArg)
{
    UBase_t uxIndexReg;

    pstReportArg->enModule = SYSEXC_enMODULE_0;
    pstReportArg->enSource = enSourceArg;
    pstReportArg->enStatusMask = (SYSEXC_nINTMASK) uxStatusMaskArg;
    pstReportArg->uxFaultAddress = uxFaultAddressArg;
    pstReportArg->uxICSR = SCB_ICSR_R;
    pstReportArg->uxActiveVector = (pstReportArg->uxICSR & SCB_ICSR_R_VECTACTIVE_MASK) >> SCB_ICSR_R_VECTACTIVE_BIT;
    pstReportArg->uxStackedVector = puxContextArg[7UL] & 0x1FFUL;

    for(uxIndexReg = 0UL; uxIndexReg < 8UL; uxIndexReg++)
    {
        pstReportArg->uxContext[uxIndexReg] = puxContextArg[uxIndexReg];
    }
}

void SYSEXC__vIRQVectorHandlerReport(uintptr_t uptrModuleArg, void* pvArgument)
{
    SYSEXC_t* pstSystemExceptionReg;
    UBase_t uxSystemException;
    UBase_t uxSysExcAddressFault;
    SYSEXC_REPORT_t stReport;

    UBase_t* puxContext;
    UBase_t* puxContextOffset;

    pstSystemExceptionReg = (SYSEXC_t*) uptrModuleArg;
    puxContext = (UBase_t*) pvArgument;

    uxSystemException = pstSystemExceptionReg->MIS;
    puxContextOffset = puxContext;
    puxContextOffset += 6UL;
    uxSysExcAddressFault = *puxContextOffset;

    stReport.enModule = 0;
    stReport.enSource = 0;
    stReport.enStatusMask = 0;
    stReport.uxFaultAddress = 0;
    stReport.uxICSR = 0;
    stReport.uxActiveVector = 0;
    stReport.uxStackedVector = 0;
    stReport.uxContext[0UL] = 0;
    stReport.uxContext[1UL] = 0;
    stReport.uxContext[2UL] = 0;
    stReport.uxContext[3UL] = 0;
    stReport.uxContext[4UL] = 0;
    stReport.uxContext[5UL] = 0;
    stReport.uxContext[6UL] = 0;
    stReport.uxContext[7UL] = 0;

    if(0UL == ((UBase_t) SYSEXC_enINTMASK_ALL & uxSystemException))
    {
        SYSEXC__vCreateReport(&stReport, SYSEXC_enINT_SW, uxSystemException, uxSysExcAddressFault, puxContext);
        SYSEXC__vInvokeReportHandler(&stReport);
    }
    else
    {
        if(0UL != ((UBase_t) SYSEXC_enINTMASK_DENORMAL & uxSystemException))
        {
            SYSEXC__vCreateReport(&stReport, SYSEXC_enINT_DENORMAL, uxSystemException, uxSysExcAddressFault, puxContext);
            SYSEXC__vInvokeReportHandler(&stReport);
        }
        if(0UL != ((UBase_t) SYSEXC_enINTMASK_DIV0 & uxSystemException))
        {
            SYSEXC__vCreateReport(&stReport, SYSEXC_enINT_DIV0, uxSystemException, uxSysExcAddressFault, puxContext);
            SYSEXC__vInvokeReportHandler(&stReport);
        }
        if(0UL != ((UBase_t) SYSEXC_enINTMASK_INVALID & uxSystemException))
        {
            SYSEXC__vCreateReport(&stReport, SYSEXC_enINT_INVALID, uxSystemException, uxSysExcAddressFault, puxContext);
            SYSEXC__vInvokeReportHandler(&stReport);
        }
        if(0UL != ((UBase_t) SYSEXC_enINTMASK_UNDERFLOW & uxSystemException))
        {
            SYSEXC__vCreateReport(&stReport, SYSEXC_enINT_UNDERFLOW, uxSystemException, uxSysExcAddressFault, puxContext);
            SYSEXC__vInvokeReportHandler(&stReport);
        }
        if(0UL != ((UBase_t) SYSEXC_enINTMASK_OVERFLOW & uxSystemException))
        {
            SYSEXC__vCreateReport(&stReport, SYSEXC_enINT_OVERFLOW, uxSystemException, uxSysExcAddressFault, puxContext);
            SYSEXC__vInvokeReportHandler(&stReport);
        }
        if(0UL != ((UBase_t) SYSEXC_enINTMASK_INEXACT & uxSystemException))
        {
            SYSEXC__vCreateReport(&stReport, SYSEXC_enINT_INEXACT, uxSystemException, uxSysExcAddressFault, puxContext);
            SYSEXC__vInvokeReportHandler(&stReport);
        }
    }

}

void SYSEXC__vIRQVectorHandlerCustom(uintptr_t uptrModuleArg, void* pvArgument)
{
    SYSEXC_t* pstSystemExceptionReg;
    UBase_t uxSystemException;
    SYSEXC_pvfIRQSourceHandler_t pvfCallback;

    (void) pvArgument;

    pstSystemExceptionReg = (SYSEXC_t*) uptrModuleArg;
    uxSystemException = pstSystemExceptionReg->MIS;

    if(0UL == ((UBase_t) SYSEXC_enINTMASK_ALL & uxSystemException))
    {
        pvfCallback = SYSEXC__pvfGetIRQSourceHandler(SYSEXC_enMODULE_0, SYSEXC_enINT_SW);
        pvfCallback(SYSEXC_BASE, (void*) SYSEXC_enINT_SW);
    }
    else
    {
        if(0UL != ((UBase_t) SYSEXC_enINTMASK_DENORMAL & uxSystemException))
        {
            pstSystemExceptionReg->IC = (UBase_t) SYSEXC_enINTMASK_DENORMAL;
            pvfCallback = SYSEXC__pvfGetIRQSourceHandler(SYSEXC_enMODULE_0, SYSEXC_enINT_DENORMAL);
            pvfCallback(SYSEXC_BASE, (void*) SYSEXC_enINT_DENORMAL);
        }
        if(0UL != ((UBase_t) SYSEXC_enINTMASK_DIV0 & uxSystemException))
        {
            pstSystemExceptionReg->IC = (UBase_t) SYSEXC_enINTMASK_DIV0;
            pvfCallback = SYSEXC__pvfGetIRQSourceHandler(SYSEXC_enMODULE_0, SYSEXC_enINT_DIV0);
            pvfCallback(SYSEXC_BASE, (void*) SYSEXC_enINT_DIV0);
        }
        if(0UL != ((UBase_t) SYSEXC_enINTMASK_INVALID & uxSystemException))
        {
            pstSystemExceptionReg->IC = (UBase_t) SYSEXC_enINTMASK_INVALID;
            pvfCallback = SYSEXC__pvfGetIRQSourceHandler(SYSEXC_enMODULE_0, SYSEXC_enINT_INVALID);
            pvfCallback(SYSEXC_BASE, (void*) SYSEXC_enINT_INVALID);
        }
        if(0UL != ((UBase_t) SYSEXC_enINTMASK_UNDERFLOW & uxSystemException))
        {
            pstSystemExceptionReg->IC = (UBase_t) SYSEXC_enINTMASK_UNDERFLOW;
            pvfCallback = SYSEXC__pvfGetIRQSourceHandler(SYSEXC_enMODULE_0, SYSEXC_enINT_UNDERFLOW);
            pvfCallback(SYSEXC_BASE, (void*) SYSEXC_enINT_UNDERFLOW);
        }
        if(0UL != ((UBase_t) SYSEXC_enINTMASK_OVERFLOW & uxSystemException))
        {
            pstSystemExceptionReg->IC = (UBase_t) SYSEXC_enINTMASK_OVERFLOW;
            pvfCallback = SYSEXC__pvfGetIRQSourceHandler(SYSEXC_enMODULE_0, SYSEXC_enINT_OVERFLOW);
            pvfCallback(SYSEXC_BASE, (void*) SYSEXC_enINT_OVERFLOW);
        }
        if(0UL != ((UBase_t) SYSEXC_enINTMASK_INEXACT & uxSystemException))
        {
            pstSystemExceptionReg->IC = (UBase_t) SYSEXC_enINTMASK_INEXACT;
            pvfCallback = SYSEXC__pvfGetIRQSourceHandler(SYSEXC_enMODULE_0, SYSEXC_enINT_INEXACT);
            pvfCallback(SYSEXC_BASE, (void*) SYSEXC_enINT_INEXACT);
        }
    }

}

