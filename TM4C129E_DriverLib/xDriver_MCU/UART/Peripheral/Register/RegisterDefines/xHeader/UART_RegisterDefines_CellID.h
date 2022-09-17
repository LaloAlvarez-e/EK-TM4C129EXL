/**
 *
 * @file UART_RegisterDefines_CellID.h
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
#ifndef XDRIVER_MCU_UART_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_UART_REGISTERDEFINES_CELLID_H_
#define XDRIVER_MCU_UART_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_UART_REGISTERDEFINES_CELLID_H_

#include <xDriver_MCU/UART/Peripheral/xHeader/UART_Enum.h>

/**************************************************************************************
************************************* 27 PCellID0 *************************************
****************************************************************************************/

/*--------*/
#define UART_PCellID0_R_CID0_MASK    ((uint32_t) 0x000000FFUL)
#define UART_PCellID0_R_CID0_BIT    ((uint32_t) 0UL)
#define UART_PCellID0_R_CID0_RESET    ((uint32_t) 0x0000000DUL)

#define UART_PCellID0_CID0_MASK    ((uint32_t) 0x000000FFUL)
#define UART_PCellID0_CID0_RESET    ((uint32_t) 0x0000000DUL)
/*--------*/

/**************************************************************************************
************************************* 28 PCellID1 *************************************
****************************************************************************************/

/*--------*/
#define UART_PCellID1_R_CID1_MASK    ((uint32_t) 0x000000FFUL)
#define UART_PCellID1_R_CID1_BIT    ((uint32_t) 0UL)
#define UART_PCellID1_R_CID1_RESET    ((uint32_t) 0x000000F0UL)

#define UART_PCellID1_CID1_MASK    ((uint32_t) 0x000000FFUL)
#define UART_PCellID1_CID1_RESET    ((uint32_t) 0x000000F0UL)
/*--------*/

/**************************************************************************************
************************************* 29 PCellID2 *************************************
****************************************************************************************/

/*--------*/
#define UART_PCellID2_R_CID2_MASK    ((uint32_t) 0x000000FFUL)
#define UART_PCellID2_R_CID2_BIT    ((uint32_t) 0UL)
#define UART_PCellID2_R_CID2_RESET    ((uint32_t) 0x00000005UL)

#define UART_PCellID2_CID2_MASK    ((uint32_t) 0x000000FFUL)
#define UART_PCellID2_CID2_RESET    ((uint32_t) 0x00000005UL)
/*--------*/

/**************************************************************************************
************************************* 30 PCellID3 *************************************
****************************************************************************************/

/*--------*/
#define UART_PCellID3_R_CID3_MASK    ((uint32_t) 0x000000FFUL)
#define UART_PCellID3_R_CID3_BIT    ((uint32_t) 0UL)
#define UART_PCellID3_R_CID3_RESET    ((uint32_t) 0x000000B1UL)

#define UART_PCellID3_CID3_MASK    ((uint32_t) 0x000000FFUL)
#define UART_PCellID3_CID3_RESET    ((uint32_t) 0x000000B1UL)
/*--------*/

#endif /* XDRIVER_MCU_UART_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_UART_REGISTERDEFINES_CELLID_H_ */
