/**
 *
 * @file UART_SYSEXC.c
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

#include <xApplication_MCU/UART/xHeader/UART_SYSEXC.h>

#include <xApplication_MCU/UART/Printf/UART_Printf.h>
#include <xApplication_MCU/UART/Intrinsics/xHeader/UART_Dependencies.h>
#include <xDriver_MCU/Common/xHeader/MCU_FloatingPoint.h>

static UART_nERROR UART__enGetSysExcMessage(SYSEXC_nINT enSourceArg, const char** ppcMessageArg);

volatile UBase_t UART_uxLastSysExcStatusMask = 0UL;
volatile UBase_t UART_uxLastSysExcFPSCR = 0UL;
volatile UBase_t UART_uxLastSysExcSource = 0UL;

const char* SysExtMessages[SYSEXC_enINT_MAX] =
{
    "SYSEXC FAULT on De-normal Operation",
    "SYSEXC FAULT on a Div by 0",
    "SYSEXC FAULT on execution of an invalid operation",
    "SYSEXC FAULT, underflow exception",
    "SYSEXC FAULT, overflow exception",
    "SYSEXC FAULT, Inexact operation exception",
    "SYSEXC FAULT Exception triggered by Software",
};

static UART_nERROR UART__enGetSysExcMessage(SYSEXC_nINT enSourceArg, const char** ppcMessageArg)
{
    UART_nERROR enErrorReg;

    enErrorReg = ((const char**) 0UL == ppcMessageArg) ? UART_enERROR_POINTER : UART_enERROR_OK;

    if(UART_enERROR_OK == enErrorReg)
    {
        enErrorReg = (UART_nERROR) MCU__enCheckParams((UBase_t) enSourceArg, (UBase_t) SYSEXC_enINT_MAX);
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        *ppcMessageArg = (SYSEXC_enINT_MAX > (UBase_t) enSourceArg) ?
                            (const char*) SysExtMessages[enSourceArg] :
                            (const char*) "SYSEXC FAULT exception Detected";
    }

    return (enErrorReg);
}

UART_nERROR UART__enSysExcReportCallback(void* pvContextArg, const SYSEXC_REPORT_t* pstReportArg)
{
    UART_nMODULE enModuleReg;
    UART_nERROR enErrorReg;
    const char* pcMessageReg = (const char*) 0UL;
    UBase_t uxFpscrReg;

    uxFpscrReg = 0UL;

    enErrorReg = (0UL == (uintptr_t) pstReportArg) ? UART_enERROR_POINTER : UART_enERROR_OK;
    
    if(UART_enERROR_OK == enErrorReg)
    {
        enModuleReg = (UART_nMODULE) (uintptr_t) pvContextArg;
        enErrorReg = UART__enGetSysExcMessage(pstReportArg->enSource, &pcMessageReg);
        uxFpscrReg = MCU__uxGetFPUStatusControl();
        UART_uxLastSysExcStatusMask = (UBase_t) pstReportArg->enStatusMask;
        UART_uxLastSysExcFPSCR = uxFpscrReg;
        UART_uxLastSysExcSource = (UBase_t) pstReportArg->enSource;
    }

    if(UART_enERROR_OK == enErrorReg)
    {

        UART__uxPrintf(enModuleReg, "%s\n\r"
                        "Source index: %X\n\r"
                        "Status mask: %X\n\r"
                        "FPSCR: %X\n\r"
                        "Context address: %X\n\r"
                        "Core Register dump:\n\r"
                        "R0: %X, R1: %X\n\r"
                        "R2: %X, R3: %X\n\r"
                        "R12: %X xPSR: %X\n\r"
                        "LR: %X, PC: %X\n\r",
                        pcMessageReg,
                        (UBase_t) pstReportArg->enSource,
                        (UBase_t) pstReportArg->enStatusMask,
                        uxFpscrReg,
                        pstReportArg->uxFaultAddress,
                        pstReportArg->uxContext[0UL],
                        pstReportArg->uxContext[1UL],
                        pstReportArg->uxContext[2UL],
                        pstReportArg->uxContext[3UL],
                        pstReportArg->uxContext[4UL],
                        pstReportArg->uxContext[7UL],
                        pstReportArg->uxContext[5UL],
                        pstReportArg->uxContext[6UL]);
    }

    return (enErrorReg);
}
