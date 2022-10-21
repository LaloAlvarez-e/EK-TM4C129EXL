/**
 *
 * @file UART_Parity.h
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

#ifndef XDRIVER_MCU_UART_DRIVER_LINECONTROL_XHEADER_UART_PARITY_H_
#define XDRIVER_MCU_UART_DRIVER_LINECONTROL_XHEADER_UART_PARITY_H_

#include <xDriver_MCU/UART/Peripheral/xHeader/UART_Enum.h>

void UART__vSetParityConfigStruct(UART_nMODULE enModule,
                                  const UART_PARITY_t stParityConfig);
void UART__vSetParityConfigStructPointer(UART_nMODULE enModule,
                                         const UART_PARITY_t* pstParityConfig);

void UART__vSetParityConfig(UART_nMODULE enModule,
                            UART_nSTATE enParityStateArg,
                            UART_nPARITY_TYPE enParityTypeArg,
                            UART_nSTATE enParityStickArg);
void UART__vSetParityEnable(UART_nMODULE enModule, UART_nSTATE enParityState);
UART_nSTATE UART__enGetParityEnable(UART_nMODULE enModule);
void UART__vSetParityType(UART_nMODULE enModule, UART_nPARITY_TYPE enParityTypeArg);
UART_nPARITY_TYPE UART__enGetParityType(UART_nMODULE enModule);
void UART__vSetParityStick(UART_nMODULE enModule, UART_nSTATE enParityStickArg);
UART_nSTATE UART__enGetParityStick(UART_nMODULE enModule);

#endif /* XDRIVER_MCU_UART_DRIVER_LINECONTROL_XHEADER_UART_PARITY_H_ */
