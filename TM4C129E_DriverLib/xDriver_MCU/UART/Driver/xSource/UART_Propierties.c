/**
 *
 * @file UART_Propierties.c
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
 * @verbatim 7 feb. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 7 feb. 2021     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/UART/Driver/xHeader/UART_Propierties.h>

#include <xDriver_MCU/UART/Driver/Intrinsics/Primitives/UART_Primitives.h>
#include <xDriver_MCU/UART/Peripheral/UART_Peripheral.h>

UART_nERROR UART__enIsBit9Supported(UART_nMODULE enModule)
{
    UART_nERROR enSupported = UART_enERROR_OK;
    enSupported = (UART_nERROR) UART__uxReadRegister(enModule, UART_PP_OFFSET,
                                           UART_PP_NB_MASK, UART_PP_R_NB_BIT);
    return (enSupported);
}

UART_nERROR UART__enIsSmartCardSupported(UART_nMODULE enModule)
{
    UART_nERROR enSupported = UART_enERROR_OK;
    enSupported = (UART_nERROR) UART__uxReadRegister(enModule, UART_PP_OFFSET,
                                               UART_PP_SC_MASK, UART_PP_R_SC_BIT);
    return (enSupported);
}
