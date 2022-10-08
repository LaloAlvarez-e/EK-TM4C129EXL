/**
 *
 * @file UART_RegisterPeripheral_Module4.h
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
 * @verbatim 22 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 22 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_UART_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_UART_REGISTERPERIPHERAL_MODULE4_H_
#define XDRIVER_MCU_UART_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_UART_REGISTERPERIPHERAL_MODULE4_H_

#include <xDriver_MCU/UART/Peripheral/Register/xHeader/UART_RegisterAddress.h>
#include <xDriver_MCU/UART/Peripheral/Register/RegisterDefines/UART_RegisterDefines.h>
#include <xDriver_MCU/UART/Peripheral/Struct/xHeader/UART_StructPeripheral.h>

/******************************************************************************************
************************************ UART4 *********************************************
******************************************************************************************/

#define UART4    ((UART_t*) (UART4_BASE))

/******************************************************************************************
************************************ 1 DR *********************************************
******************************************************************************************/
#define UART4_DR    ((UARTDR_t*) (UART4_BASE + UART_DR_OFFSET ))
#define UART4_DR_R    (*((volatile UBase_t*) (UART4_BASE + UART_DR_OFFSET)))

/******************************************************************************************
************************************ 2 RSR *********************************************
************************************ 2 ECR *********************************************
******************************************************************************************/
#define UART4_RSR    ((UARTRSR_t*) (UART4_BASE + UART_RSR_OFFSET ))
#define UART4_RSR_R    (*((volatile const UBase_t*) (UART4_BASE + UART_RSR_OFFSET)))
#define UART4_ECR    ((UARTECR_t*) (UART4_BASE + UART_ECR_OFFSET ))
#define UART4_ECR_R    (*((volatile UBase_t*) (UART4_BASE + UART_ECR_OFFSET)))

/******************************************************************************************
************************************ 3 FR *********************************************
******************************************************************************************/
#define UART4_FR    ((UARTFR_t*) (UART4_BASE + UART_FR_OFFSET ))
#define UART4_FR_R    (*((volatile const UBase_t*) (UART4_BASE + UART_FR_OFFSET)))

/******************************************************************************************
************************************ 4 ILPR *********************************************
******************************************************************************************/
#define UART4_ILPR    ((UARTILPR_t*) (UART4_BASE + UART_ILPR_OFFSET ))
#define UART4_ILPR_R    (*((volatile UBase_t*) (UART4_BASE + UART_ILPR_OFFSET)))

/******************************************************************************************
************************************ 5 IBRD *********************************************
******************************************************************************************/
#define UART4_IBRD    ((UARTIBRD_t*) (UART4_BASE + UART_IBRD_OFFSET ))
#define UART4_IBRD_R    (*((volatile UBase_t*) (UART4_BASE + UART_IBRD_OFFSET)))

/******************************************************************************************
************************************ 6 FBRD *********************************************
******************************************************************************************/
#define UART4_FBRD    ((UARTFBRD_t*) (UART4_BASE + UART_FBRD_OFFSET ))
#define UART4_FBRD_R    (*((volatile UBase_t*) (UART4_BASE + UART_FBRD_OFFSET)))

/******************************************************************************************
************************************ 7 LCRH *********************************************
******************************************************************************************/
#define UART4_LCRH    ((UARTLCRH_t*) (UART4_BASE + UART_LCRH_OFFSET ))
#define UART4_LCRH_R    (*((volatile UBase_t*) (UART4_BASE + UART_LCRH_OFFSET)))

/******************************************************************************************
************************************ 8 DMACTL *********************************************
******************************************************************************************/
#define UART4_DMACTL    ((UARTDMACTL_t*) (UART4_BASE + UART_DMACTL_OFFSET ))
#define UART4_DMACTL_R    (*((volatile UBase_t*) (UART4_BASE + UART_DMACTL_OFFSET)))

/******************************************************************************************
************************************ 9 IFLS *********************************************
******************************************************************************************/
#define UART4_IFLS    ((UARTIFLS_t*) (UART4_BASE + UART_IFLS_OFFSET ))
#define UART4_IFLS_R    (*((volatile UBase_t*) (UART4_BASE + UART_IFLS_OFFSET)))

/******************************************************************************************
************************************ 10 IM *********************************************
******************************************************************************************/
#define UART4_IM    ((UARTIM_t*) (UART4_BASE + UART_IM_OFFSET ))
#define UART4_IM_R    (*((volatile UBase_t*) (UART4_BASE + UART_IM_OFFSET)))

/******************************************************************************************
************************************ 11 RIS *********************************************
******************************************************************************************/
#define UART4_RIS    ((UARTRIS_t*) (UART4_BASE + UART_RIS_OFFSET ))
#define UART4_RIS_R    (*((volatile const UBase_t*) (UART4_BASE + UART_RIS_OFFSET)))

/******************************************************************************************
************************************ 12 MIS *********************************************
******************************************************************************************/
#define UART4_MIS    ((UARTMIS_t*) (UART4_BASE + UART_MIS_OFFSET ))
#define UART4_MIS_R    (*((volatile const UBase_t*) (UART4_BASE + UART_MIS_OFFSET)))

/******************************************************************************************
************************************ 13 ICR *********************************************
******************************************************************************************/
#define UART4_ICR    ((UARTICR_t*) (UART4_BASE + UART_ICR_OFFSET ))
#define UART4_ICR_R    (*((volatile UBase_t*) (UART4_BASE + UART_ICR_OFFSET)))

/******************************************************************************************
************************************ 14 DMACTL *********************************************
******************************************************************************************/
#define UART4_DMACTL    ((UARTDMACTL_t*) (UART4_BASE + UART_DMACTL_OFFSET ))
#define UART4_DMACTL_R    (*((volatile UBase_t*) (UART4_BASE + UART_DMACTL_OFFSET)))

/******************************************************************************************
************************************ 15 9BITADDR *********************************************
******************************************************************************************/
#define UART4_9BITADDR    ((UART9BITADDR8_t*) (UART4_BASE + UART_9BITADDR_OFFSET ))
#define UART4_9BITADDR_R    (*((volatile UBase_t*) (UART4_BASE + UART_9BITADDR_OFFSET)))

/******************************************************************************************
************************************ 16 9BITAMASK *********************************************
******************************************************************************************/
#define UART4_9BITAMASK    ((UART9BITAMASK8_t*) (UART4_BASE + UART_9BITAMASK_OFFSET ))
#define UART4_9BITAMASK_R    (*((volatile UBase_t*) (UART4_BASE + UART_9BITAMASK_OFFSET)))

/******************************************************************************************
************************************ 17 PP *********************************************
******************************************************************************************/
#define UART4_PP    ((UARTPP_t*) (UART4_BASE + UART_PP_OFFSET ))
#define UART4_PP_R    (*((volatile const UBase_t*) (UART4_BASE + UART_PP_OFFSET)))

/******************************************************************************************
************************************ 18 CC *********************************************
******************************************************************************************/
#define UART4_CC    ((UARTCC_t*) (UART4_BASE + UART_CC_OFFSET ))
#define UART4_CC_R    (*((volatile UBase_t*) (UART4_BASE + UART_CC_OFFSET)))


/******************************************************************************************
 ************************************ 19 PeriphID4 *********************************************
 ******************************************************************************************/
/* UART4 PID4*/
#define UART4_PeriphID4    ((UARTPeriphID4_t*) (UART4_BASE + UART_PeriphID4_OFFSET))
#define UART4_PeriphID4_R    (*((volatile const UBase_t*) (UART4_BASE + UART_PeriphID4_OFFSET)))

/******************************************************************************************
 ************************************ 20 PeriphID5 *********************************************
 ******************************************************************************************/
/* UART4 PID5*/
#define UART4_PeriphID5    ((UARTPeriphID5_t*) (UART4_BASE + UART_PeriphID5_OFFSET))
#define UART4_PeriphID5_R    (*((volatile const UBase_t*) (UART4_BASE + UART_PeriphID5_OFFSET)))

/******************************************************************************************
 ************************************ 21 PeriphID6 *********************************************
 ******************************************************************************************/
/* UART4 PID6*/
#define UART4_PeriphID6    ((UARTPeriphID6_t*) (UART4_BASE + UART_PeriphID6_OFFSET))
#define UART4_PeriphID6_R    (*((volatile const UBase_t*) (UART4_BASE + UART_PeriphID6_OFFSET)))

/******************************************************************************************
 ************************************ 22 PeriphID7 *********************************************
 ******************************************************************************************/
/* UART4 PID7*/
#define UART4_PeriphID7    ((UARTPeriphID7_t*) (UART4_BASE + UART_PeriphID7_OFFSET))
#define UART4_PeriphID7_R    (*((volatile const UBase_t*) (UART4_BASE + UART_PeriphID7_OFFSET)))

/******************************************************************************************
 ************************************ 23 PeriphID0 *********************************************
 ******************************************************************************************/
/* UART4 PID0*/
#define UART4_PeriphID0    ((UARTPeriphID0_t*) (UART4_BASE + UART_PeriphID0_OFFSET))
#define UART4_PeriphID0_R    (*((volatile const UBase_t*) (UART4_BASE + UART_PeriphID0_OFFSET)))

/******************************************************************************************
 ************************************ 24 PeriphID1 *********************************************
 ******************************************************************************************/
/* UART4 PID1*/
#define UART4_PeriphID1    ((UARTPeriphID1_t*) (UART4_BASE + UART_PeriphID1_OFFSET))
#define UART4_PeriphID1_R    (*((volatile const UBase_t*) (UART4_BASE + UART_PeriphID1_OFFSET)))

/******************************************************************************************
 ************************************ 25 PeriphID2 *********************************************
 ******************************************************************************************/
/* UART4 PID2*/
#define UART4_PeriphID2    ((UARTPeriphID2_t*) (UART4_BASE + UART_PeriphID2_OFFSET))
#define UART4_PeriphID2_R    (*((volatile const UBase_t*) (UART4_BASE + UART_PeriphID2_OFFSET)))

/******************************************************************************************
 ************************************ 26 PeriphID3 *********************************************
 ******************************************************************************************/
/* UART4 PID3*/
#define UART4_PeriphID3    ((UARTPeriphID3_t*) (UART4_BASE + UART_PeriphID3_OFFSET))
#define UART4_PeriphID3_R    (*((volatile const UBase_t*) (UART4_BASE + UART_PeriphID3_OFFSET)))

/******************************************************************************************
 ************************************ 27 CellID0 *********************************************
 ******************************************************************************************/
/* UART4 CID0*/
#define UART4_PCellID0    ((UARTCellID0_t*) (UART4_BASE + UART_PCellID0_OFFSET))
#define UART4_PCellID0_R    (*((volatile const UBase_t*) (UART4_BASE + UART_PCellID0_OFFSET)))

/******************************************************************************************
 ************************************ 28 CellID1 *********************************************
 ******************************************************************************************/
/* UART4 CID1*/
#define UART4_PCellID1    ((UARTCellID1_t*) (UART4_BASE + UART_PCellID1_OFFSET))
#define UART4_PCellID1_R    (*((volatile const UBase_t*) (UART4_BASE + UART_PCellID1_OFFSET)))

/******************************************************************************************
 ************************************ 29 CellID2 *********************************************
 ******************************************************************************************/
/* UART4 CID2*/
#define UART4_PCellID2    ((UARTCellID2_t*) (UART4_BASE + UART_PCellID2_OFFSET))
#define UART4_PCellID2_R    (*((volatile const UBase_t*) (UART4_BASE + UART_PCellID2_OFFSET)))

/******************************************************************************************
 ************************************ 30 CellID3 *********************************************
 ******************************************************************************************/
/* UART4 CID3*/
#define UART4_PCellID3    ((UARTCellID3_t*) (UART4_BASE + UART_PCellID3_OFFSET))
#define UART4_PCellID3_R    (*((volatile const UBase_t*) (UART4_BASE + UART_PCellID3_OFFSET)))

#endif /* XDRIVER_MCU_UART_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_UART_REGISTERPERIPHERAL_MODULE4_H_ */
