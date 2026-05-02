/**
 *
 * @file UART_Ready.h
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
 * @verbatim 13 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 13 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef XAPPLICATION_MCU_UART_INTRINSICS_XHEADER_UART_READY_H_
#define XAPPLICATION_MCU_UART_INTRINSICS_XHEADER_UART_READY_H_

#include <xApplication_MCU/UART/Intrinsics/xHeader/UART_Defines.h>

UART_nERROR UART__enSetReadyOnRunMode(UART_nMODULE enModuleArg);
UART_nERROR UART__enClearReadyOnRunMode(UART_nMODULE enModuleArg);
UART_nERROR UART__enReset(UART_nMODULE enModuleArg);
UART_nERROR UART__enIsReady(UART_nMODULE enModuleArg, UART_nBOOLEAN* penReadyArg);

#endif /* XAPPLICATION_MCU_UART_INTRINSICS_XHEADER_UART_READY_H_ */
