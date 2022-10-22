/**
 *
 * @file UART_RegisterDefines_9BITADDR.h
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
#ifndef XDRIVER_MCU_UART_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_UART_REGISTERDEFINES_9BITADDR_H_
#define XDRIVER_MCU_UART_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_UART_REGISTERDEFINES_9BITADDR_H_

#include <xDriver_MCU/UART/Peripheral/xHeader/UART_Enum.h>

/******************************************************************************************
************************************ 15 9BITADDR *********************************************
******************************************************************************************/
/*--------*/
#define UART_BIT9ADDR_R_ADDR_MASK    ((UBase_t) 0x000000FFUL)
#define UART_BIT9ADDR_R_ADDR_BIT    ((UBase_t) 0UL)

#define UART_BIT9ADDR_ADDR_MASK    ((UBase_t) 0x000000FFUL)
/*--------*/

/*--------*/
#define UART_BIT9ADDR_R_BIT9EN_MASK    ((UBase_t) 0x00008000UL)
#define UART_BIT9ADDR_R_BIT9EN_BIT    ((UBase_t) 15UL)
#define UART_BIT9ADDR_R_BIT9EN_DIS    ((UBase_t) 0x00000000UL)
#define UART_BIT9ADDR_R_BIT9EN_ENA    ((UBase_t) 0x00008000UL)

#define UART_BIT9ADDR_BIT9EN_MASK    ((UBase_t) 0x00000001UL)
#define UART_BIT9ADDR_BIT9EN_DIS    ((UBase_t) 0x00000000UL)
#define UART_BIT9ADDR_BIT9EN_ENA    ((UBase_t) 0x00000001UL)
/*--------*/

#endif /* XDRIVER_MCU_UART_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_UART_REGISTERDEFINES_9BITADDR_H_ */
