/**
 *
 * @file UART_SCB.c
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

#include <xApplication_MCU/UART/xHeader/UART_SCB.h>

#include <xApplication_MCU/UART/Printf/UART_Printf.h>
#include <xApplication_MCU/UART/Intrinsics/xHeader/UART_Dependencies.h>

static UART_nERROR UART__enSCBPrintReport(void* pvContextArg, const SCB_REPORT_t* pstReportArg,
                                          const char* const* ppcMessagesArg, UBase_t uxMessageCountArg,
                                          const char* pcDefaultMessageArg);

static const char* UART_pcSCBUsageFaultMessages[SCB_enUSAGE_BIT_MAX] =
{
    "SCB USAGE FAULT on Undefined Instruction",
    "SCB USAGE FAULT on Invalid State",
    "SCB USAGE FAULT on Invalid PC Load",
    "SCB USAGE FAULT on Coprocessor Access",
    "SCB USAGE FAULT on Unaligned Access",
    "SCB USAGE FAULT on Divide by Zero",
    "SCB USAGE FAULT triggered by Software",
};

static const char* UART_pcSCBBusFaultMessages[SCB_enBUS_BIT_MAX] =
{
    "SCB BUS FAULT on Instruction Bus Access",
    "SCB BUS FAULT on Precise Data Access",
    "SCB BUS FAULT on Imprecise Data Access",
    "SCB BUS FAULT on Exception Unstack",
    "SCB BUS FAULT on Exception Stack",
    "SCB BUS FAULT on FPU Lazy State Preservation",
    "SCB BUS FAULT with Valid Fault Address",
    "SCB BUS FAULT triggered by Software",
};

static const char* UART_pcSCBMemoryFaultMessages[SCB_enMEMORY_BIT_MAX] =
{
    "SCB MEMORY FAULT on Instruction Access Violation",
    "SCB MEMORY FAULT on Data Access Violation",
    "SCB MEMORY FAULT on Exception Unstack",
    "SCB MEMORY FAULT on Exception Stack",
    "SCB MEMORY FAULT on FPU Lazy State Preservation",
    "SCB MEMORY FAULT with Valid Fault Address",
    "SCB MEMORY FAULT triggered by Software",
};

static const char* UART_pcSCBHardFaultMessages[SCB_enHARD_BIT_MAX] =
{
    "SCB HARD FAULT on Vector Table Read",
    "SCB HARD FAULT triggered by Software",
};

static const char* UART_pcSCBNMIMessages[SCB_enNMI_BIT_MAX] =
{
    "SCB NMI from External Source",
    "SCB NMI from Power Source",
    "SCB NMI from Watchdog 0",
    "SCB NMI from Watchdog 1",
    "SCB NMI from Tamper Source",
    "SCB NMI from MOSC Failure",
    "SCB NMI triggered by Software",
};

static UART_nERROR UART__enSCBPrintReport(void* pvContextArg, const SCB_REPORT_t* pstReportArg,
                                          const char* const* ppcMessagesArg, UBase_t uxMessageCountArg,
                                          const char* pcDefaultMessageArg)
{
    UART_nMODULE enModuleReg;
    UART_nERROR enErrorReg;
    const char* pcMessageReg;

    enErrorReg = (0UL == (uintptr_t) pstReportArg) ? UART_enERROR_POINTER : UART_enERROR_OK;
    pcMessageReg = pcDefaultMessageArg;

    if((UART_enERROR_OK == enErrorReg) && ((UBase_t) pstReportArg->uxSource < uxMessageCountArg))
    {
        pcMessageReg = ppcMessagesArg[pstReportArg->uxSource];
    }

    if(UART_enERROR_OK == enErrorReg)
    {
        enModuleReg = (UART_nMODULE) (uintptr_t) pvContextArg;
        UART__uxPrintf(enModuleReg, "%s\n\r"
                        "Context address: %X\n\r"
                        "Core Register dump:\n\r"
                        "R0: %X, R1: %X\n\r"
                        "R2: %X, R3: %X\n\r"
                        "R12: %X xPSR: %X\n\r"
                        "LR: %X, PC: %X\n\r",
                        pcMessageReg,
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

UART_nERROR UART__enSCBUsageFaultReportCallback(void* pvContextArg, const SCB_REPORT_t* pstReportArg)
{
    return (UART__enSCBPrintReport(pvContextArg, pstReportArg, UART_pcSCBUsageFaultMessages,
                                   SCB_enUSAGE_BIT_MAX, "SCB USAGE FAULT exception Detected"));
}

UART_nERROR UART__enSCBBusFaultReportCallback(void* pvContextArg, const SCB_REPORT_t* pstReportArg)
{
    return (UART__enSCBPrintReport(pvContextArg, pstReportArg, UART_pcSCBBusFaultMessages,
                                   SCB_enBUS_BIT_MAX, "SCB BUS FAULT exception Detected"));
}

UART_nERROR UART__enSCBMemoryFaultReportCallback(void* pvContextArg, const SCB_REPORT_t* pstReportArg)
{
    return (UART__enSCBPrintReport(pvContextArg, pstReportArg, UART_pcSCBMemoryFaultMessages,
                                   SCB_enMEMORY_BIT_MAX, "SCB MEMORY FAULT exception Detected"));
}

UART_nERROR UART__enSCBHardFaultReportCallback(void* pvContextArg, const SCB_REPORT_t* pstReportArg)
{
    return (UART__enSCBPrintReport(pvContextArg, pstReportArg, UART_pcSCBHardFaultMessages,
                                   SCB_enHARD_BIT_MAX, "SCB HARD FAULT exception Detected"));
}

UART_nERROR UART__enSCBNMIReportCallback(void* pvContextArg, const SCB_REPORT_t* pstReportArg)
{
    return (UART__enSCBPrintReport(pvContextArg, pstReportArg, UART_pcSCBNMIMessages,
                                   SCB_enNMI_BIT_MAX, "SCB NMI exception Detected"));
}
