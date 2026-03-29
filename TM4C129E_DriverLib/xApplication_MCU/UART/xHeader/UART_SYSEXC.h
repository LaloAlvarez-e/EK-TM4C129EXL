/**
 *
 * @file UART_SYSEXC.h
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
#ifndef XAPPLICATION_MCU_UART_XHEADER_UART_SYSEXC_H_
#define XAPPLICATION_MCU_UART_XHEADER_UART_SYSEXC_H_

#include <xApplication_MCU/UART/Intrinsics/xHeader/UART_Defines.h>
#include <xApplication_MCU/SYSEXC/xHeader/SYSEXC_Report.h>

UART_nERROR UART__enSysExcReportCallback(void* pvContextArg, const SYSEXC_REPORT_t* pstReportArg);

#endif /* XAPPLICATION_MCU_UART_XHEADER_UART_SYSEXC_H_ */
