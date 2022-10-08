/**
 *
 * @file UART_ClearToSend.c
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
#include <xDriver_MCU/UART/Driver/Flags/xHeader/UART_ClearToSend.h>

#include <xDriver_MCU/UART/Driver/Intrinsics/Primitives/UART_Primitives.h>
#include <xDriver_MCU/UART/Peripheral/UART_Peripheral.h>

UART_nCTS UART__enGetClearToSendStatus(UART_nMODULE enModule)
{
    UART_nCTS enCTSReg = UART_enCTS_NOASSERT;
    enCTSReg = (UART_nCTS) UART__uxReadRegister(enModule, UART_FR_OFFSET,
                                     UART_FR_CTS_MASK, UART_FR_R_CTS_BIT);
    return (enCTSReg);
}
