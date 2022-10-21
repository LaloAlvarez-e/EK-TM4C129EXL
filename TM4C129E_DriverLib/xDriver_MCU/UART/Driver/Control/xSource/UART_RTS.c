/**
 *
 * @file UART_RTS.c
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
 * @verbatim 8 feb. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 8 feb. 2021     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/UART/Driver/Control/xHeader/UART_RTS.h>

#include <xDriver_MCU/UART/Driver/Intrinsics/Primitives/UART_Primitives.h>
#include <xDriver_MCU/UART/Peripheral/UART_Peripheral.h>

void UART__vSetRTSMode(UART_nMODULE enModule, UART_nLINE_MODE enRTSModeArg)
{
    UART__vWriteRegister(enModule, UART_CTL_OFFSET, (UBase_t) enRTSModeArg,
                         UART_CTL_RTSEN_MASK, UART_CTL_R_RTSEN_BIT);
}

UART_nLINE_MODE UART__enGetRTSMode(UART_nMODULE enModule)
{
    UART_nLINE_MODE enRTSModeReg = UART_enLINE_MODE_SOFT;
    enRTSModeReg = (UART_nLINE_MODE) UART__uxReadRegister(enModule, UART_CTL_OFFSET,
                                         UART_CTL_RTSEN_MASK, UART_CTL_R_RTSEN_BIT);
    return (enRTSModeReg);
}

void UART__vSetRTSLevel(UART_nMODULE enModule, UART_nLEVEL enRTSLevelArg)
{
    UART__vWriteRegister(enModule, UART_CTL_OFFSET, (UBase_t) enRTSLevelArg,
                         UART_CTL_RTS_MASK, UART_CTL_R_RTS_BIT);
}

UART_nLEVEL UART__enGetRTSLevel(UART_nMODULE enModule)
{
    UART_nLEVEL enRTSLevelReg = UART_enLEVEL_LOW;
    enRTSLevelReg = (UART_nLEVEL) UART__uxReadRegister(enModule, UART_CTL_OFFSET,
                                                UART_CTL_RTS_MASK, UART_CTL_R_RTS_BIT);
    return (enRTSLevelReg);
}


