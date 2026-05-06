/**
 *
 * @file UART_InterruptRoutine_Source.h
 * @copyright
 * @verbatim InDeviceMex 2020 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 23 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 23 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_UART_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_XHEADER_UART_INTERRUPTROUTINE_SOURCE_H_
#define XDRIVER_MCU_UART_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_XHEADER_UART_INTERRUPTROUTINE_SOURCE_H_

#include <xDriver_MCU/UART/Peripheral/xHeader/UART_Enum.h>

UART_pvfIRQSourceHandler_t UART__pvfGetIRQSourceHandler(UART_nMODULE enModuleArg, UART_nINT enInterruptSourceArg);
UART_pvfIRQSourceHandler_t* UART__pvfGetIRQSourceHandlerPointer(UART_nMODULE enModuleArg, UART_nINT enInterruptSourceArg);

#endif /* XDRIVER_MCU_UART_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_XHEADER_UART_INTERRUPTROUTINE_SOURCE_H_ */
