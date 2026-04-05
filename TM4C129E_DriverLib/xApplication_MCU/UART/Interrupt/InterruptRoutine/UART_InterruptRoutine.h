/**
 *
 * @file UART_InterruptRoutine.h
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

#ifndef XAPPLICATION_MCU_UART_INTERRUPT_INTERRUPTROUTINE_UART_INTERRUPTROUTINE_H_
#define XAPPLICATION_MCU_UART_INTERRUPT_INTERRUPTROUTINE_UART_INTERRUPTROUTINE_H_

#include <xApplication_MCU/UART/Intrinsics/xHeader/UART_Defines.h>
#include <xApplication_MCU/UART/Interrupt/InterruptRoutine/xHeader/UART_InterruptRoutine_Vector_Module0.h>
#include <xApplication_MCU/UART/Interrupt/InterruptRoutine/xHeader/UART_InterruptRoutine_Vector_Module1.h>
#include <xApplication_MCU/UART/Interrupt/InterruptRoutine/xHeader/UART_InterruptRoutine_Vector_Module2.h>
#include <xApplication_MCU/UART/Interrupt/InterruptRoutine/xHeader/UART_InterruptRoutine_Vector_Module3.h>
#include <xApplication_MCU/UART/Interrupt/InterruptRoutine/xHeader/UART_InterruptRoutine_Vector_Module4.h>
#include <xApplication_MCU/UART/Interrupt/InterruptRoutine/xHeader/UART_InterruptRoutine_Vector_Module5.h>
#include <xApplication_MCU/UART/Interrupt/InterruptRoutine/xHeader/UART_InterruptRoutine_Vector_Module6.h>
#include <xApplication_MCU/UART/Interrupt/InterruptRoutine/xHeader/UART_InterruptRoutine_Vector_Module7.h>

UART_pvfIRQVectorHandler_t UART__pvfGetIRQVectorHandler(UART_nMODULE enUARTModule);
UART_pvfIRQVectorHandler_t* UART__pvfGetIRQVectorHandlerPointer(UART_nMODULE enUARTModule);

#endif /* XAPPLICATION_MCU_UART_INTERRUPT_INTERRUPTROUTINE_UART_INTERRUPTROUTINE_H_ */
