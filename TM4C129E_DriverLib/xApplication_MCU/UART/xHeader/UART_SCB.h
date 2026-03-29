/**
 *
 * @file UART_SCB.h
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

#ifndef F4A9C1F2_1DD6_4BBA_B361_18617EDDAE9E
#define F4A9C1F2_1DD6_4BBA_B361_18617EDDAE9E

#ifndef XAPPLICATION_MCU_UART_XHEADER_UART_SCB_H_
#define XAPPLICATION_MCU_UART_XHEADER_UART_SCB_H_

#include <xApplication_MCU/UART/Intrinsics/xHeader/UART_Defines.h>
#include <xApplication_MCU/Core/SCB/xHeader/SCB_Report.h>

UART_nERROR UART__enSCBUsageFaultReportCallback(void* pvContextArg, const SCB_REPORT_t* pstReportArg);
UART_nERROR UART__enSCBBusFaultReportCallback(void* pvContextArg, const SCB_REPORT_t* pstReportArg);
UART_nERROR UART__enSCBMemoryFaultReportCallback(void* pvContextArg, const SCB_REPORT_t* pstReportArg);
UART_nERROR UART__enSCBHardFaultReportCallback(void* pvContextArg, const SCB_REPORT_t* pstReportArg);
UART_nERROR UART__enSCBNMIReportCallback(void* pvContextArg, const SCB_REPORT_t* pstReportArg);

#endif /* XAPPLICATION_MCU_UART_XHEADER_UART_SCB_H_ */


#endif /* F4A9C1F2_1DD6_4BBA_B361_18617EDDAE9E */
