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

#ifndef C31A2BF7_58C8_48C0_8592_727B5850C1F8
#define C31A2BF7_58C8_48C0_8592_727B5850C1F8

#ifndef XAPPLICATION_MCU_UART_XHEADER_UART_SYSEXC_H_
#define XAPPLICATION_MCU_UART_XHEADER_UART_SYSEXC_H_

#include <xApplication_MCU/UART/Intrinsics/xHeader/UART_Defines.h>
#include <xApplication_MCU/SYSEXC/xHeader/SYSEXC_Report.h>

void UART__vSysExcReportCallback(const SYSEXC_REPORT_t* pstReportArg, void* pvContextArg);

#endif /* XAPPLICATION_MCU_UART_XHEADER_UART_SYSEXC_H_ */


#endif /* C31A2BF7_58C8_48C0_8592_727B5850C1F8 */
