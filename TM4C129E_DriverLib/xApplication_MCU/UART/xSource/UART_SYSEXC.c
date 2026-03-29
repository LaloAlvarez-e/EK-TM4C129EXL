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

static const char* UART__pcGetSysExcMessage(SYSEXC_nINT enSourceArg);

static const char* UART__pcGetSysExcMessage(SYSEXC_nINT enSourceArg)
{
    const char* pcMessageReg;

    pcMessageReg = "SYSEXC FAULT exception Detected";
    switch(enSourceArg)
    {
        case SYSEXC_enINT_SW:
            pcMessageReg = "SYSEXC FAULT Exception triggered by Software";
            break;
        case SYSEXC_enINT_DENORMAL:
            pcMessageReg = "SYSEXC FAULT on De-normal Operation";
            break;
        case SYSEXC_enINT_DIV0:
            pcMessageReg = "SYSEXC FAULT on a Div by 0";
            break;
        case SYSEXC_enINT_INVALID:
            pcMessageReg = "SYSEXC FAULT on execution of an invalid operation";
            break;
        case SYSEXC_enINT_UNDERFLOW:
            pcMessageReg = "SYSEXC FAULT, underflow exception";
            break;
        case SYSEXC_enINT_OVERFLOW:
            pcMessageReg = "SYSEXC FAULT, overflow exception";
            break;
        case SYSEXC_enINT_INEXACT:
            pcMessageReg = "SYSEXC FAULT, Inexact operation exception";
            break;
        default:
            break;
    }

    return (pcMessageReg);
}

void UART__vSysExcReportCallback(const SYSEXC_REPORT_t* pstReportArg, void* pvContextArg)
{
    UART_nMODULE enModuleReg;

    if(0UL != (uintptr_t) pstReportArg)
    {
        enModuleReg = (UART_nMODULE) (uintptr_t) pvContextArg;
        UART__uxPrintf(enModuleReg, "%s\n\r"
                        "Context address: %X\n\r"
                        "Core Register dump:\n\r"
                        "R0: %X, R1: %X\n\r"
                        "R2: %X, R3: %X\n\r"
                        "R12: %X xPSR: %X\n\r"
                        "LR: %X, PC: %X\n\r",
                        UART__pcGetSysExcMessage(pstReportArg->enSource),
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
}
