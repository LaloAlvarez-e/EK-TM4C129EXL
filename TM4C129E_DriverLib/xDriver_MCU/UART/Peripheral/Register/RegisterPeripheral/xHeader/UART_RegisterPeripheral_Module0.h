/**
 *
 * @file UART_RegisterPeripheral_Module0.h
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

#ifndef XDRIVER_MCU_UART_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_UART_REGISTERPERIPHERAL_MODULE0_H_
#define XDRIVER_MCU_UART_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_UART_REGISTERPERIPHERAL_MODULE0_H_

#include <xDriver_MCU/UART/Peripheral/Register/xHeader/UART_RegisterAddress.h>
#include <xDriver_MCU/UART/Peripheral/Register/RegisterDefines/UART_RegisterDefines.h>
#include <xDriver_MCU/UART/Peripheral/Struct/xHeader/UART_StructPeripheral.h>

/******************************************************************************************
************************************ UART0 *********************************************
******************************************************************************************/

#define UART0    ((UART_t*) (UART0_BASE))

/******************************************************************************************
************************************ 1 DR *********************************************
******************************************************************************************/
#define UART0_DR    ((UART_DR_t*) (UART0_BASE + UART_DR_OFFSET ))
#define UART0_DR_R    (*((volatile UBase_t*) (UART0_BASE + UART_DR_OFFSET)))

/******************************************************************************************
************************************ 2 RSR *********************************************
************************************ 2 ECR *********************************************
******************************************************************************************/
#define UART0_RSR    ((UART_RSR_t*) (UART0_BASE + UART_RSR_OFFSET ))
#define UART0_RSR_R    (*((volatile const UBase_t*) (UART0_BASE + UART_RSR_OFFSET)))
#define UART0_ECR    ((UART_ECR_t*) (UART0_BASE + UART_ECR_OFFSET ))
#define UART0_ECR_R    (*((volatile UBase_t*) (UART0_BASE + UART_ECR_OFFSET)))

/******************************************************************************************
************************************ 3 FR *********************************************
******************************************************************************************/
#define UART0_FR    ((UART_FR_t*) (UART0_BASE + UART_FR_OFFSET ))
#define UART0_FR_R    (*((volatile const UBase_t*) (UART0_BASE + UART_FR_OFFSET)))

/******************************************************************************************
************************************ 4 ILPR *********************************************
******************************************************************************************/
#define UART0_ILPR    ((UART_ILPR_t*) (UART0_BASE + UART_ILPR_OFFSET ))
#define UART0_ILPR_R    (*((volatile UBase_t*) (UART0_BASE + UART_ILPR_OFFSET)))

/******************************************************************************************
************************************ 5 IBRD *********************************************
******************************************************************************************/
#define UART0_IBRD    ((UART_IBRD_t*) (UART0_BASE + UART_IBRD_OFFSET ))
#define UART0_IBRD_R    (*((volatile UBase_t*) (UART0_BASE + UART_IBRD_OFFSET)))

/******************************************************************************************
************************************ 6 FBRD *********************************************
******************************************************************************************/
#define UART0_FBRD    ((UART_FBRD_t*) (UART0_BASE + UART_FBRD_OFFSET ))
#define UART0_FBRD_R    (*((volatile UBase_t*) (UART0_BASE + UART_FBRD_OFFSET)))

/******************************************************************************************
************************************ 7 LCRH *********************************************
******************************************************************************************/
#define UART0_LCRH    ((UART_LCRH_t*) (UART0_BASE + UART_LCRH_OFFSET ))
#define UART0_LCRH_R    (*((volatile UBase_t*) (UART0_BASE + UART_LCRH_OFFSET)))

/******************************************************************************************
************************************ 8 DMACTL *********************************************
******************************************************************************************/
#define UART0_DMACTL    ((UART_DMACTL_t*) (UART0_BASE + UART_DMACTL_OFFSET ))
#define UART0_DMACTL_R    (*((volatile UBase_t*) (UART0_BASE + UART_DMACTL_OFFSET)))

/******************************************************************************************
************************************ 9 IFLS *********************************************
******************************************************************************************/
#define UART0_IFLS    ((UART_IFLS_t*) (UART0_BASE + UART_IFLS_OFFSET ))
#define UART0_IFLS_R    (*((volatile UBase_t*) (UART0_BASE + UART_IFLS_OFFSET)))

/******************************************************************************************
************************************ 10 IM *********************************************
******************************************************************************************/
#define UART0_IM    ((UART_IM_t*) (UART0_BASE + UART_IM_OFFSET ))
#define UART0_IM_R    (*((volatile UBase_t*) (UART0_BASE + UART_IM_OFFSET)))

/******************************************************************************************
************************************ 11 RIS *********************************************
******************************************************************************************/
#define UART0_RIS    ((UART_RIS_t*) (UART0_BASE + UART_RIS_OFFSET ))
#define UART0_RIS_R    (*((volatile const UBase_t*) (UART0_BASE + UART_RIS_OFFSET)))

/******************************************************************************************
************************************ 12 MIS *********************************************
******************************************************************************************/
#define UART0_MIS    ((UART_MIS_t*) (UART0_BASE + UART_MIS_OFFSET ))
#define UART0_MIS_R    (*((volatile const UBase_t*) (UART0_BASE + UART_MIS_OFFSET)))

/******************************************************************************************
************************************ 13 ICR *********************************************
******************************************************************************************/
#define UART0_ICR    ((UART_ICR_t*) (UART0_BASE + UART_ICR_OFFSET ))
#define UART0_ICR_R    (*((volatile UBase_t*) (UART0_BASE + UART_ICR_OFFSET)))

/******************************************************************************************
************************************ 14 DMACTL *********************************************
******************************************************************************************/
#define UART0_DMACTL    ((UART_DMACTL_t*) (UART0_BASE + UART_DMACTL_OFFSET ))
#define UART0_DMACTL_R    (*((volatile UBase_t*) (UART0_BASE + UART_DMACTL_OFFSET)))

/******************************************************************************************
************************************ 15 BIT9ADDR *********************************************
******************************************************************************************/
#define UART0_BIT9ADDR    ((UART_BIT9ADDR_t*) (UART0_BASE + UART_BIT9ADDR_OFFSET ))
#define UART0_BIT9ADDR_R    (*((volatile UBase_t*) (UART0_BASE + UART_BIT9ADDR_OFFSET)))

/******************************************************************************************
************************************ 16 BIT9AMASK *********************************************
******************************************************************************************/
#define UART0_BIT9AMASK    ((UART_BIT9AMASK_t*) (UART0_BASE + UART_BIT9AMASK_OFFSET ))
#define UART0_BIT9AMASK_R    (*((volatile UBase_t*) (UART0_BASE + UART_BIT9AMASK_OFFSET)))

/******************************************************************************************
************************************ 17 PP *********************************************
******************************************************************************************/
#define UART0_PP    ((UART_PP_t*) (UART0_BASE + UART_PP_OFFSET ))
#define UART0_PP_R    (*((volatile const UBase_t*) (UART0_BASE + UART_PP_OFFSET)))

/******************************************************************************************
************************************ 18 CC *********************************************
******************************************************************************************/
#define UART0_CC    ((UART_CC_t*) (UART0_BASE + UART_CC_OFFSET ))
#define UART0_CC_R    (*((volatile UBase_t*) (UART0_BASE + UART_CC_OFFSET)))


/******************************************************************************************
 ************************************ 19 PeriphID4 *********************************************
 ******************************************************************************************/
/* UART0 PID4*/
#define UART0_PeriphID4    ((UART_PeriphID4_t*) (UART0_BASE + UART_PeriphID4_OFFSET))
#define UART0_PeriphID4_R    (*((volatile const UBase_t*) (UART0_BASE + UART_PeriphID4_OFFSET)))

/******************************************************************************************
 ************************************ 20 PeriphID5 *********************************************
 ******************************************************************************************/
/* UART0 PID5*/
#define UART0_PeriphID5    ((UART_PeriphID5_t*) (UART0_BASE + UART_PeriphID5_OFFSET))
#define UART0_PeriphID5_R    (*((volatile const UBase_t*) (UART0_BASE + UART_PeriphID5_OFFSET)))

/******************************************************************************************
 ************************************ 21 PeriphID6 *********************************************
 ******************************************************************************************/
/* UART0 PID6*/
#define UART0_PeriphID6    ((UART_PeriphID6_t*) (UART0_BASE + UART_PeriphID6_OFFSET))
#define UART0_PeriphID6_R    (*((volatile const UBase_t*) (UART0_BASE + UART_PeriphID6_OFFSET)))

/******************************************************************************************
 ************************************ 22 PeriphID7 *********************************************
 ******************************************************************************************/
/* UART0 PID7*/
#define UART0_PeriphID7    ((UART_PeriphID7_t*) (UART0_BASE + UART_PeriphID7_OFFSET))
#define UART0_PeriphID7_R    (*((volatile const UBase_t*) (UART0_BASE + UART_PeriphID7_OFFSET)))

/******************************************************************************************
 ************************************ 23 PeriphID0 *********************************************
 ******************************************************************************************/
/* UART0 PID0*/
#define UART0_PeriphID0    ((UART_PeriphID0_t*) (UART0_BASE + UART_PeriphID0_OFFSET))
#define UART0_PeriphID0_R    (*((volatile const UBase_t*) (UART0_BASE + UART_PeriphID0_OFFSET)))

/******************************************************************************************
 ************************************ 24 PeriphID1 *********************************************
 ******************************************************************************************/
/* UART0 PID1*/
#define UART0_PeriphID1    ((UART_PeriphID1_t*) (UART0_BASE + UART_PeriphID1_OFFSET))
#define UART0_PeriphID1_R    (*((volatile const UBase_t*) (UART0_BASE + UART_PeriphID1_OFFSET)))

/******************************************************************************************
 ************************************ 25 PeriphID2 *********************************************
 ******************************************************************************************/
/* UART0 PID2*/
#define UART0_PeriphID2    ((UART_PeriphID2_t*) (UART0_BASE + UART_PeriphID2_OFFSET))
#define UART0_PeriphID2_R    (*((volatile const UBase_t*) (UART0_BASE + UART_PeriphID2_OFFSET)))

/******************************************************************************************
 ************************************ 26 PeriphID3 *********************************************
 ******************************************************************************************/
/* UART0 PID3*/
#define UART0_PeriphID3    ((UART_PeriphID3_t*) (UART0_BASE + UART_PeriphID3_OFFSET))
#define UART0_PeriphID3_R    (*((volatile const UBase_t*) (UART0_BASE + UART_PeriphID3_OFFSET)))

/******************************************************************************************
 ************************************ 27 CellID0 *********************************************
 ******************************************************************************************/
/* UART0 CID0*/
#define UART0_PCellID0    ((UART_PCellID0_t*) (UART0_BASE + UART_PCellID0_OFFSET))
#define UART0_PCellID0_R    (*((volatile const UBase_t*) (UART0_BASE + UART_PCellID0_OFFSET)))

/******************************************************************************************
 ************************************ 28 CellID1 *********************************************
 ******************************************************************************************/
/* UART0 CID1*/
#define UART0_PCellID1    ((UART_PCellID1_t*) (UART0_BASE + UART_PCellID1_OFFSET))
#define UART0_PCellID1_R    (*((volatile const UBase_t*) (UART0_BASE + UART_PCellID1_OFFSET)))

/******************************************************************************************
 ************************************ 29 CellID2 *********************************************
 ******************************************************************************************/
/* UART0 CID2*/
#define UART0_PCellID2    ((UART_PCellID2_t*) (UART0_BASE + UART_PCellID2_OFFSET))
#define UART0_PCellID2_R    (*((volatile const UBase_t*) (UART0_BASE + UART_PCellID2_OFFSET)))

/******************************************************************************************
 ************************************ 30 CellID3 *********************************************
 ******************************************************************************************/
/* UART0 CID3*/
#define UART0_PCellID3    ((UART_PCellID3_t*) (UART0_BASE + UART_PCellID3_OFFSET))
#define UART0_PCellID3_R    (*((volatile const UBase_t*) (UART0_BASE + UART_PCellID3_OFFSET)))

#endif /* XDRIVER_MCU_UART_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_UART_REGISTERPERIPHERAL_MODULE0_H_ */
