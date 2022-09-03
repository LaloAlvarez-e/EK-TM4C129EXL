/**
 *
 * @file UART_BreakError.c
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
#include <xDriver_MCU/UART/Driver/Errors/xHeader/UART_BreakError.h>

#include <xDriver_MCU/UART/Driver/Intrinsics/Primitives/UART_Primitives.h>
#include <xDriver_MCU/UART/Peripheral/UART_Peripheral.h>

UART_nERROR UART__enGetBreakErrorState(UART_nMODULE enModule)
{
    UART_nERROR enErrorReg = UART_enERROR_INACTIVE;
    enErrorReg = (UART_nERROR) UART__u32ReadRegister(enModule, UART_RSR_OFFSET,
                                         UART_RSR_BE_MASK, UART_RSR_R_BE_BIT);
    return (enErrorReg);
}
