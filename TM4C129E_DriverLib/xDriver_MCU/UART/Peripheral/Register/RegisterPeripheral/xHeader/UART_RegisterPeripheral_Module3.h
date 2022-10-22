/**
 *
 * @file UART_RegisterPeripheral_Module3.h
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

#ifndef XDRIVER_MCU_UART_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_UART_REGISTERPERIPHERAL_MODULE3_H_
#define XDRIVER_MCU_UART_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_UART_REGISTERPERIPHERAL_MODULE3_H_

#include <xDriver_MCU/UART/Peripheral/Register/xHeader/UART_RegisterAddress.h>
#include <xDriver_MCU/UART/Peripheral/Register/RegisterDefines/UART_RegisterDefines.h>
#include <xDriver_MCU/UART/Peripheral/Struct/xHeader/UART_StructPeripheral.h>

/******************************************************************************************
************************************ UART3 *********************************************
******************************************************************************************/

#define UART3    ((UART_t*) (UART3_BASE))

/******************************************************************************************
************************************ 1 DR *********************************************
******************************************************************************************/
#define UART3_DR    ((UART_DR_t*) (UART3_BASE + UART_DR_OFFSET ))
#define UART3_DR_R    (*((volatile UBase_t*) (UART3_BASE + UART_DR_OFFSET)))

/******************************************************************************************
************************************ 2 RSR *********************************************
************************************ 2 ECR *********************************************
******************************************************************************************/
#define UART3_RSR    ((UART_RSR_t*) (UART3_BASE + UART_RSR_OFFSET ))
#define UART3_RSR_R    (*((volatile const UBase_t*) (UART3_BASE + UART_RSR_OFFSET)))
#define UART3_ECR    ((UART_ECR_t*) (UART3_BASE + UART_ECR_OFFSET ))
#define UART3_ECR_R    (*((volatile UBase_t*) (UART3_BASE + UART_ECR_OFFSET)))

/******************************************************************************************
************************************ 3 FR *********************************************
******************************************************************************************/
#define UART3_FR    ((UART_FR_t*) (UART3_BASE + UART_FR_OFFSET ))
#define UART3_FR_R    (*((volatile const UBase_t*) (UART3_BASE + UART_FR_OFFSET)))

/******************************************************************************************
************************************ 4 ILPR *********************************************
******************************************************************************************/
#define UART3_ILPR    ((UART_ILPR_t*) (UART3_BASE + UART_ILPR_OFFSET ))
#define UART3_ILPR_R    (*((volatile UBase_t*) (UART3_BASE + UART_ILPR_OFFSET)))

/******************************************************************************************
************************************ 5 IBRD *********************************************
******************************************************************************************/
#define UART3_IBRD    ((UART_IBRD_t*) (UART3_BASE + UART_IBRD_OFFSET ))
#define UART3_IBRD_R    (*((volatile UBase_t*) (UART3_BASE + UART_IBRD_OFFSET)))

/******************************************************************************************
************************************ 6 FBRD *********************************************
******************************************************************************************/
#define UART3_FBRD    ((UART_FBRD_t*) (UART3_BASE + UART_FBRD_OFFSET ))
#define UART3_FBRD_R    (*((volatile UBase_t*) (UART3_BASE + UART_FBRD_OFFSET)))

/******************************************************************************************
************************************ 7 LCRH *********************************************
******************************************************************************************/
#define UART3_LCRH    ((UART_LCRH_t*) (UART3_BASE + UART_LCRH_OFFSET ))
#define UART3_LCRH_R    (*((volatile UBase_t*) (UART3_BASE + UART_LCRH_OFFSET)))

/******************************************************************************************
************************************ 8 DMACTL *********************************************
******************************************************************************************/
#define UART3_DMACTL    ((UART_DMACTL_t*) (UART3_BASE + UART_DMACTL_OFFSET ))
#define UART3_DMACTL_R    (*((volatile UBase_t*) (UART3_BASE + UART_DMACTL_OFFSET)))

/******************************************************************************************
************************************ 9 IFLS *********************************************
******************************************************************************************/
#define UART3_IFLS    ((UART_IFLS_t*) (UART3_BASE + UART_IFLS_OFFSET ))
#define UART3_IFLS_R    (*((volatile UBase_t*) (UART3_BASE + UART_IFLS_OFFSET)))

/******************************************************************************************
************************************ 10 IM *********************************************
******************************************************************************************/
#define UART3_IM    ((UART_IM_t*) (UART3_BASE + UART_IM_OFFSET ))
#define UART3_IM_R    (*((volatile UBase_t*) (UART3_BASE + UART_IM_OFFSET)))

/******************************************************************************************
************************************ 11 RIS *********************************************
******************************************************************************************/
#define UART3_RIS    ((UART_RIS_t*) (UART3_BASE + UART_RIS_OFFSET ))
#define UART3_RIS_R    (*((volatile const UBase_t*) (UART3_BASE + UART_RIS_OFFSET)))

/******************************************************************************************
************************************ 12 MIS *********************************************
******************************************************************************************/
#define UART3_MIS    ((UART_MIS_t*) (UART3_BASE + UART_MIS_OFFSET ))
#define UART3_MIS_R    (*((volatile const UBase_t*) (UART3_BASE + UART_MIS_OFFSET)))

/******************************************************************************************
************************************ 13 ICR *********************************************
******************************************************************************************/
#define UART3_ICR    ((UART_ICR_t*) (UART3_BASE + UART_ICR_OFFSET ))
#define UART3_ICR_R    (*((volatile UBase_t*) (UART3_BASE + UART_ICR_OFFSET)))

/******************************************************************************************
************************************ 14 DMACTL *********************************************
******************************************************************************************/
#define UART3_DMACTL    ((UART_DMACTL_t*) (UART3_BASE + UART_DMACTL_OFFSET ))
#define UART3_DMACTL_R    (*((volatile UBase_t*) (UART3_BASE + UART_DMACTL_OFFSET)))

/******************************************************************************************
************************************ 15 BIT9ADDR *********************************************
******************************************************************************************/
#define UART3_BIT9ADDR    ((UART_BIT9ADDR_t*) (UART3_BASE + UART_BIT9ADDR_OFFSET ))
#define UART3_BIT9ADDR_R    (*((volatile UBase_t*) (UART3_BASE + UART_BIT9ADDR_OFFSET)))

/******************************************************************************************
************************************ 16 BIT9AMASK *********************************************
******************************************************************************************/
#define UART3_BIT9AMASK    ((UART_BIT9AMASK_t*) (UART3_BASE + UART_BIT9AMASK_OFFSET ))
#define UART3_BIT9AMASK_R    (*((volatile UBase_t*) (UART3_BASE + UART_BIT9AMASK_OFFSET)))

/******************************************************************************************
************************************ 17 PP *********************************************
******************************************************************************************/
#define UART3_PP    ((UART_PP_t*) (UART3_BASE + UART_PP_OFFSET ))
#define UART3_PP_R    (*((volatile const UBase_t*) (UART3_BASE + UART_PP_OFFSET)))

/******************************************************************************************
************************************ 18 CC *********************************************
******************************************************************************************/
#define UART3_CC    ((UART_CC_t*) (UART3_BASE + UART_CC_OFFSET ))
#define UART3_CC_R    (*((volatile UBase_t*) (UART3_BASE + UART_CC_OFFSET)))


/******************************************************************************************
 ************************************ 19 PeriphID4 *********************************************
 ******************************************************************************************/
/* UART3 PID4*/
#define UART3_PeriphID4    ((UART_PeriphID4_t*) (UART3_BASE + UART_PeriphID4_OFFSET))
#define UART3_PeriphID4_R    (*((volatile const UBase_t*) (UART3_BASE + UART_PeriphID4_OFFSET)))

/******************************************************************************************
 ************************************ 20 PeriphID5 *********************************************
 ******************************************************************************************/
/* UART3 PID5*/
#define UART3_PeriphID5    ((UART_PeriphID5_t*) (UART3_BASE + UART_PeriphID5_OFFSET))
#define UART3_PeriphID5_R    (*((volatile const UBase_t*) (UART3_BASE + UART_PeriphID5_OFFSET)))

/******************************************************************************************
 ************************************ 21 PeriphID6 *********************************************
 ******************************************************************************************/
/* UART3 PID6*/
#define UART3_PeriphID6    ((UART_PeriphID6_t*) (UART3_BASE + UART_PeriphID6_OFFSET))
#define UART3_PeriphID6_R    (*((volatile const UBase_t*) (UART3_BASE + UART_PeriphID6_OFFSET)))

/******************************************************************************************
 ************************************ 22 PeriphID7 *********************************************
 ******************************************************************************************/
/* UART3 PID7*/
#define UART3_PeriphID7    ((UART_PeriphID7_t*) (UART3_BASE + UART_PeriphID7_OFFSET))
#define UART3_PeriphID7_R    (*((volatile const UBase_t*) (UART3_BASE + UART_PeriphID7_OFFSET)))

/******************************************************************************************
 ************************************ 23 PeriphID0 *********************************************
 ******************************************************************************************/
/* UART3 PID0*/
#define UART3_PeriphID0    ((UART_PeriphID0_t*) (UART3_BASE + UART_PeriphID0_OFFSET))
#define UART3_PeriphID0_R    (*((volatile const UBase_t*) (UART3_BASE + UART_PeriphID0_OFFSET)))

/******************************************************************************************
 ************************************ 24 PeriphID1 *********************************************
 ******************************************************************************************/
/* UART3 PID1*/
#define UART3_PeriphID1    ((UART_PeriphID1_t*) (UART3_BASE + UART_PeriphID1_OFFSET))
#define UART3_PeriphID1_R    (*((volatile const UBase_t*) (UART3_BASE + UART_PeriphID1_OFFSET)))

/******************************************************************************************
 ************************************ 25 PeriphID2 *********************************************
 ******************************************************************************************/
/* UART3 PID2*/
#define UART3_PeriphID2    ((UART_PeriphID2_t*) (UART3_BASE + UART_PeriphID2_OFFSET))
#define UART3_PeriphID2_R    (*((volatile const UBase_t*) (UART3_BASE + UART_PeriphID2_OFFSET)))

/******************************************************************************************
 ************************************ 26 PeriphID3 *********************************************
 ******************************************************************************************/
/* UART3 PID3*/
#define UART3_PeriphID3    ((UART_PeriphID3_t*) (UART3_BASE + UART_PeriphID3_OFFSET))
#define UART3_PeriphID3_R    (*((volatile const UBase_t*) (UART3_BASE + UART_PeriphID3_OFFSET)))

/******************************************************************************************
 ************************************ 27 CellID0 *********************************************
 ******************************************************************************************/
/* UART3 CID0*/
#define UART3_PCellID0    ((UART_PCellID0_t*) (UART3_BASE + UART_PCellID0_OFFSET))
#define UART3_PCellID0_R    (*((volatile const UBase_t*) (UART3_BASE + UART_PCellID0_OFFSET)))

/******************************************************************************************
 ************************************ 28 CellID1 *********************************************
 ******************************************************************************************/
/* UART3 CID1*/
#define UART3_PCellID1    ((UART_PCellID1_t*) (UART3_BASE + UART_PCellID1_OFFSET))
#define UART3_PCellID1_R    (*((volatile const UBase_t*) (UART3_BASE + UART_PCellID1_OFFSET)))

/******************************************************************************************
 ************************************ 29 CellID2 *********************************************
 ******************************************************************************************/
/* UART3 CID2*/
#define UART3_PCellID2    ((UART_PCellID2_t*) (UART3_BASE + UART_PCellID2_OFFSET))
#define UART3_PCellID2_R    (*((volatile const UBase_t*) (UART3_BASE + UART_PCellID2_OFFSET)))

/******************************************************************************************
 ************************************ 30 CellID3 *********************************************
 ******************************************************************************************/
/* UART3 CID3*/
#define UART3_PCellID3    ((UART_PCellID3_t*) (UART3_BASE + UART_PCellID3_OFFSET))
#define UART3_PCellID3_R    (*((volatile const UBase_t*) (UART3_BASE + UART_PCellID3_OFFSET)))

#endif /* XDRIVER_MCU_UART_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_UART_REGISTERPERIPHERAL_MODULE3_H_ */
