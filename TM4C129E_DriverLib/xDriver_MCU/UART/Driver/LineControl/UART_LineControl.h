/**
 *
 * @file UART_LineControl.h
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
 * @verbatim 24 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 24 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_UART_DRIVER_LINECONTROL_UART_LINECONTROL_H_
#define XDRIVER_MCU_UART_DRIVER_LINECONTROL_UART_LINECONTROL_H_

#include <xDriver_MCU/UART/Driver/LineControl/xHeader/UART_BaudRate.h>
#include <xDriver_MCU/UART/Driver/LineControl/xHeader/UART_Break.h>
#include <xDriver_MCU/UART/Driver/LineControl/xHeader/UART_Fifo.h>
#include <xDriver_MCU/UART/Driver/LineControl/xHeader/UART_Length.h>
#include <xDriver_MCU/UART/Driver/LineControl/xHeader/UART_Parity.h>
#include <xDriver_MCU/UART/Driver/LineControl/xHeader/UART_Stop.h>

void UART__vSetLineControl(UART_nMODULE enModule, UART_nLENGTH enLengthDataArg,
                           UART_nFIFO enFifoEnable, UART_nSTOP enStopBitsArg,
                           UART_nPARITY enParityState, UART_nPARITY_TYPE enParityTypeArg,
                           UART_nPARITY_STICK enParityStickArg);
void UART__vSetLineControlStructPointer(UART_nMODULE enModule,
                                        const UART_LINE_CONTROL_t* pstLineControl);
void UART__vSetLineControlStruct(UART_nMODULE enModule,
                                 const UART_LINE_CONTROL_t stLineControl);

#endif /* XDRIVER_MCU_UART_DRIVER_LINECONTROL_UART_LINECONTROL_H_ */
