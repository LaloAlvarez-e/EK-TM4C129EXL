/**
 *
 * @file CAN_RegisterPeripheral_Bitbanding_Module0.h
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
 * @verbatim May 28, 2021 @endverbatim
 *
 * @author
 * @verbatim indevicemex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * May 28, 2021        indevicemex    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_CAN_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_BITBANDING_XHEADER_CAN_REGISTERPERIPHERAL_BITBANDING_MODULE0_H_
#define XDRIVER_MCU_CAN_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_BITBANDING_XHEADER_CAN_REGISTERPERIPHERAL_BITBANDING_MODULE0_H_

#include <xDriver_MCU/CAN/Peripheral/Register/xHeader/CAN_RegisterAddress.h>
#include <xDriver_MCU/CAN/Peripheral/Register/RegisterDefines/CAN_RegisterDefines.h>
#include <xDriver_MCU/CAN/Peripheral/Struct/xHeader/CAN_StructPeripheral_Bitbanding.h>

/******************************************************************************************
************************************ CAN1 *********************************************
******************************************************************************************/
#define CAN1_BITBANDING    ((CAN_BITBANDING_t*) (CAN_BITBANDING_BASE + (CAN1_OFFSET * 32U)))

/******************************************************************************************
*********************************** * 1 CTL *********************************************
******************************************************************************************/
#define CAN1_BITBANDING_CTL    ((BITBANDING_CANCTL_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_CTL_OFFSET) * 32U)))

#define CAN1_BITBANDING_CTL_INIT    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_CTL_OFFSET) * 32U) + (CAN_CTL_R_INIT_BIT * 4U))))
#define CAN1_BITBANDING_CTL_IE    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_CTL_OFFSET) * 32U) + (CAN_CTL_R_IE_BIT * 4U))))
#define CAN1_BITBANDING_CTL_SIE    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_CTL_OFFSET) * 32U) + (CAN_CTL_R_SIE_BIT * 4U))))
#define CAN1_BITBANDING_CTL_EIE    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_CTL_OFFSET) * 32U) + (CAN_CTL_R_EIE_BIT * 4U))))
#define CAN1_BITBANDING_CTL_DAR    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_CTL_OFFSET) * 32U) + (CAN_CTL_R_DAR_BIT * 4U))))
#define CAN1_BITBANDING_CTL_CCE    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_CTL_OFFSET) * 32U) + (CAN_CTL_R_CCE_BIT * 4U))))
#define CAN1_BITBANDING_CTL_TEST    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_CTL_OFFSET) * 32U) + (CAN_CTL_R_TEST_BIT * 4U))))

/******************************************************************************************
*********************************** * 2 STS *********************************************
******************************************************************************************/
#define CAN1_BITBANDING_STS    ((BITBANDING_CANSTS_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_STS_OFFSET) * 32U)))

#define CAN1_BITBANDING_STS_LEC_0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_STS_OFFSET) * 32U) + ((CAN_STS_R_LEC_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_STS_LEC_1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_STS_OFFSET) * 32U) + ((CAN_STS_R_LEC_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_STS_LEC_2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_STS_OFFSET) * 32U) + ((CAN_STS_R_LEC_BIT + 2UL) * 4U))))
#define CAN1_BITBANDING_STS_TXOK    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_STS_OFFSET) * 32U) + (CAN_STS_R_TXOK_BIT * 4U))))
#define CAN1_BITBANDING_STS_RXOK    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_STS_OFFSET) * 32U) + (CAN_STS_R_RXOK_BIT * 4U))))
#define CAN1_BITBANDING_STS_EPASS    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_STS_OFFSET) * 32U) + (CAN_STS_R_EPASS_BIT * 4U))))
#define CAN1_BITBANDING_STS_EWARN    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_STS_OFFSET) * 32U) + (CAN_STS_R_EWARN_BIT * 4U))))
#define CAN1_BITBANDING_STS_BOFF    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_STS_OFFSET) * 32U) + (CAN_STS_R_BOFF_BIT * 4U))))

/******************************************************************************************
*********************************** * 3 ERR *********************************************
******************************************************************************************/
#define CAN1_BITBANDING_ERR    ((BITBANDING_CANERR_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_ERR_OFFSET) * 32U)))

#define CAN1_BITBANDING_ERR_RP    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_ERR_OFFSET) * 32U) + (CAN_ERR_R_RP_BIT * 4U))))

/******************************************************************************************
*********************************** * 4 BIT *********************************************
******************************************************************************************/
#define CAN1_BITBANDING_BIT    ((BITBANDING_CANBIT_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_BIT_OFFSET) * 32U)))

#define CAN1_BITBANDING_BIT_BRP_0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_BIT_OFFSET) * 32U) + ((CAN_BIT_R_BRP_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_BIT_BRP_1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_BIT_OFFSET) * 32U) + ((CAN_BIT_R_BRP_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_BIT_BRP_2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_BIT_OFFSET) * 32U) + ((CAN_BIT_R_BRP_BIT + 2UL) * 4U))))
#define CAN1_BITBANDING_BIT_BRP_3    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_BIT_OFFSET) * 32U) + ((CAN_BIT_R_BRP_BIT + 3UL) * 4U))))
#define CAN1_BITBANDING_BIT_BRP_4    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_BIT_OFFSET) * 32U) + ((CAN_BIT_R_BRP_BIT + 4UL) * 4U))))
#define CAN1_BITBANDING_BIT_BRP_5    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_BIT_OFFSET) * 32U) + ((CAN_BIT_R_BRP_BIT + 5UL) * 4U))))
#define CAN1_BITBANDING_BIT_SJW_0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_BIT_OFFSET) * 32U) + ((CAN_BIT_R_SJW_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_BIT_SJW_1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_BIT_OFFSET) * 32U) + ((CAN_BIT_R_SJW_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_BIT_TSEG1_0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_BIT_OFFSET) * 32U) + ((CAN_BIT_R_TSEG1_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_BIT_TSEG1_1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_BIT_OFFSET) * 32U) + ((CAN_BIT_R_TSEG1_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_BIT_TSEG1_2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_BIT_OFFSET) * 32U) + ((CAN_BIT_R_TSEG1_BIT + 2UL) * 4U))))
#define CAN1_BITBANDING_BIT_TSEG1_3    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_BIT_OFFSET) * 32U) + ((CAN_BIT_R_TSEG1_BIT + 3UL) * 4U))))
#define CAN1_BITBANDING_BIT_TSEG2_0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_BIT_OFFSET) * 32U) + ((CAN_BIT_R_TSEG2_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_BIT_TSEG2_1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_BIT_OFFSET) * 32U) + ((CAN_BIT_R_TSEG2_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_BIT_TSEG2_2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_BIT_OFFSET) * 32U) + ((CAN_BIT_R_TSEG2_BIT + 2UL) * 4U))))

/******************************************************************************************
*********************************** * 5 INT *********************************************
******************************************************************************************/
#define CAN1_BITBANDING_INT    ((BITBANDING_CANINT_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U)))

#define CAN1_BITBANDING_BIT_INTID_0    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_BIT_INTID_1    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_BIT_INTID_2    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 2UL) * 4U))))
#define CAN1_BITBANDING_BIT_INTID_3    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 3UL) * 4U))))
#define CAN1_BITBANDING_BIT_INTID_4    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 4UL) * 4U))))
#define CAN1_BITBANDING_BIT_INTID_5    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 5UL) * 4U))))
#define CAN1_BITBANDING_BIT_INTID_6    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 6UL) * 4U))))
#define CAN1_BITBANDING_BIT_INTID_7    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 7UL) * 4U))))
#define CAN1_BITBANDING_BIT_INTID_8    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 8UL) * 4U))))
#define CAN1_BITBANDING_BIT_INTID_9    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 9UL) * 4U))))
#define CAN1_BITBANDING_BIT_INTID_10    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 10UL) * 4U))))
#define CAN1_BITBANDING_BIT_INTID_11    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 11UL) * 4U))))
#define CAN1_BITBANDING_BIT_INTID_12    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 12UL) * 4U))))
#define CAN1_BITBANDING_BIT_INTID_13    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 13UL) * 4U))))
#define CAN1_BITBANDING_BIT_INTID_14    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 14UL) * 4U))))
#define CAN1_BITBANDING_BIT_INTID_15    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 15UL) * 4U))))
#define CAN1_BITBANDING_BIT_INTID_16    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 16UL) * 4U))))
#define CAN1_BITBANDING_BIT_INTID_17    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 17UL) * 4U))))
#define CAN1_BITBANDING_BIT_INTID_18    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 18UL) * 4U))))
#define CAN1_BITBANDING_BIT_INTID_19    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 19UL) * 4U))))
#define CAN1_BITBANDING_BIT_INTID_20    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 20UL) * 4U))))
#define CAN1_BITBANDING_BIT_INTID_21    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 21UL) * 4U))))
#define CAN1_BITBANDING_BIT_INTID_22    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 22UL) * 4U))))
#define CAN1_BITBANDING_BIT_INTID_23    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 23UL) * 4U))))
#define CAN1_BITBANDING_BIT_INTID_24    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 24UL) * 4U))))
#define CAN1_BITBANDING_BIT_INTID_25    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 25UL) * 4U))))
#define CAN1_BITBANDING_BIT_INTID_26    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 26UL) * 4U))))
#define CAN1_BITBANDING_BIT_INTID_27    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 27UL) * 4U))))
#define CAN1_BITBANDING_BIT_INTID_28    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 28UL) * 4U))))
#define CAN1_BITBANDING_BIT_INTID_29    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 29UL) * 4U))))
#define CAN1_BITBANDING_BIT_INTID_30    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 30UL) * 4U))))
#define CAN1_BITBANDING_BIT_INTID_31    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_INT_OFFSET) * 32U) + ((CAN_INT_R_INTID_BIT + 31UL) * 4U))))

/******************************************************************************************
*********************************** * 6 TST *********************************************
******************************************************************************************/
#define CAN1_BITBANDING_TST    ((BITBANDING_CANTST_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TST_OFFSET) * 32U)))

#define CAN1_BITBANDING_TST_BASIC    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TST_OFFSET) * 32U) + (CAN_TST_R_BASIC_BIT * 4U))))
#define CAN1_BITBANDING_TST_SILENT    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TST_OFFSET) * 32U) + (CAN_TST_R_SILENT_BIT * 4U))))
#define CAN1_BITBANDING_TST_LBACK    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TST_OFFSET) * 32U) + (CAN_TST_R_LBACK_BIT * 4U))))
#define CAN1_BITBANDING_TST_TX_0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TST_OFFSET) * 32U) + ((CAN_TST_R_TX_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_TST_TX_1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TST_OFFSET) * 32U) + ((CAN_TST_R_TX_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_TST_RX    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TST_OFFSET) * 32U) + (CAN_TST_R_RX_BIT * 4U))))

/******************************************************************************************
*********************************** * 7 BRPE *********************************************
******************************************************************************************/
#define CAN1_BITBANDING_BRPE    ((BITBANDING_CANBRPE_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_BRPE_OFFSET) * 32U)))

#define CAN1_BITBANDING_BRPE_BRPE_0    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_BRPE_OFFSET) * 32U) + ((CAN_BRPE_R_BRPE_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_BRPE_BRPE_1    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_BRPE_OFFSET) * 32U) + ((CAN_BRPE_R_BRPE_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_BRPE_BRPE_2    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_BRPE_OFFSET) * 32U) + ((CAN_BRPE_R_BRPE_BIT + 2UL) * 4U))))
#define CAN1_BITBANDING_BRPE_BRPE_3    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_BRPE_OFFSET) * 32U) + ((CAN_BRPE_R_BRPE_BIT + 3UL) * 4U))))

/******************************************************************************************
*********************************** * 8-9 IFnCRQ *********************************************
******************************************************************************************/
#define CAN1_BITBANDING_IF1CRQ    ((BITBANDING_CANIFnCRQ_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1CRQ_OFFSET) * 32U)))
#define CAN1_BITBANDING_IF2CRQ    ((BITBANDING_CANIFnCRQ_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2CRQ_OFFSET) * 32U)))

#define CAN1_BITBANDING_IF1CRQ_MNUM_0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1CRQ_OFFSET) * 32U) + ((CAN_IFnCRQ_R_MNUM_BIT + 0UL)* 4U))))
#define CAN1_BITBANDING_IF1CRQ_MNUM_1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1CRQ_OFFSET) * 32U) + ((CAN_IFnCRQ_R_MNUM_BIT + 1UL)* 4U))))
#define CAN1_BITBANDING_IF1CRQ_MNUM_2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1CRQ_OFFSET) * 32U) + ((CAN_IFnCRQ_R_MNUM_BIT + 2UL)* 4U))))
#define CAN1_BITBANDING_IF1CRQ_MNUM_3    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1CRQ_OFFSET) * 32U) + ((CAN_IFnCRQ_R_MNUM_BIT + 3UL)* 4U))))
#define CAN1_BITBANDING_IF1CRQ_MNUM_4    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1CRQ_OFFSET) * 32U) + ((CAN_IFnCRQ_R_MNUM_BIT + 4UL)* 4U))))
#define CAN1_BITBANDING_IF1CRQ_MNUM_5    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1CRQ_OFFSET) * 32U) + ((CAN_IFnCRQ_R_MNUM_BIT + 5UL)* 4U))))
#define CAN1_BITBANDING_IF1CRQ_BUSY    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1CRQ_OFFSET) * 32U) + (CAN_IFnCRQ_R_BUSY_BIT * 4U))))

#define CAN1_BITBANDING_IF2CRQ_MNUM_0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2CRQ_OFFSET) * 32U) + ((CAN_IFnCRQ_R_MNUM_BIT + 0UL)* 4U))))
#define CAN1_BITBANDING_IF2CRQ_MNUM_1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2CRQ_OFFSET) * 32U) + ((CAN_IFnCRQ_R_MNUM_BIT + 1UL)* 4U))))
#define CAN1_BITBANDING_IF2CRQ_MNUM_2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2CRQ_OFFSET) * 32U) + ((CAN_IFnCRQ_R_MNUM_BIT + 2UL)* 4U))))
#define CAN1_BITBANDING_IF2CRQ_MNUM_3    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2CRQ_OFFSET) * 32U) + ((CAN_IFnCRQ_R_MNUM_BIT + 3UL)* 4U))))
#define CAN1_BITBANDING_IF2CRQ_MNUM_4    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2CRQ_OFFSET) * 32U) + ((CAN_IFnCRQ_R_MNUM_BIT + 4UL)* 4U))))
#define CAN1_BITBANDING_IF2CRQ_MNUM_5    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2CRQ_OFFSET) * 32U) + ((CAN_IFnCRQ_R_MNUM_BIT + 5UL)* 4U))))
#define CAN1_BITBANDING_IF2CRQ_BUSY    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2CRQ_OFFSET) * 32U) + (CAN_IFnCRQ_R_BUSY_BIT * 4U))))

/******************************************************************************************
*********************************** * 10-11 IFnCMSK *********************************************
******************************************************************************************/
#define CAN1_BITBANDING_IF1CMSK    ((BITBANDING_CANIFnCMSK_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1CMSK_OFFSET) * 32U)))
#define CAN1_BITBANDING_IF2CMSK    ((BITBANDING_CANIFnCMSK_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2CMSK_OFFSET) * 32U)))

#define CAN1_BITBANDING_IF1CMSK_DATAB    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1CMSK_OFFSET) * 32U) + (CAN_IFnCMSK_R_DATAB_BIT * 4U))))
#define CAN1_BITBANDING_IF1CMSK_DATAA    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1CMSK_OFFSET) * 32U) + (CAN_IFnCMSK_R_DATAA_BIT * 4U))))
#define CAN1_BITBANDING_IF1CMSK_NEWDAT    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1CMSK_OFFSET) * 32U) + (CAN_IFnCMSK_R_NEWDAT_TXRQST_BIT * 4U))))
#define CAN1_BITBANDING_IF1CMSK_TXRQST    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1CMSK_OFFSET) * 32U) + (CAN_IFnCMSK_R_NEWDAT_TXRQST_BIT * 4U))))
#define CAN1_BITBANDING_IF1CMSK_CLRINTPND    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1CMSK_OFFSET) * 32U) + (CAN_IFnCMSK_R_CLRINTPND_BIT * 4U))))
#define CAN1_BITBANDING_IF1CMSK_CONTROL    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1CMSK_OFFSET) * 32U) + (CAN_IFnCMSK_R_CONTROL_BIT * 4U))))
#define CAN1_BITBANDING_IF1CMSK_ARB    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1CMSK_OFFSET) * 32U) + (CAN_IFnCMSK_R_ARB_BIT * 4U))))
#define CAN1_BITBANDING_IF1CMSK_MASK    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1CMSK_OFFSET) * 32U) + (CAN_IFnCMSK_R_MASK_BIT * 4U))))
#define CAN1_BITBANDING_IF1CMSK_WRNRD    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1CMSK_OFFSET) * 32U) + (CAN_IFnCMSK_R_WRNRD_BIT * 4U))))

#define CAN1_BITBANDING_IF2CMSK_DATAB    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2CMSK_OFFSET) * 32U) + (CAN_IFnCMSK_R_DATAB_BIT * 4U))))
#define CAN1_BITBANDING_IF2CMSK_DATAA    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2CMSK_OFFSET) * 32U) + (CAN_IFnCMSK_R_DATAA_BIT * 4U))))
#define CAN1_BITBANDING_IF2CMSK_NEWDAT    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2CMSK_OFFSET) * 32U) + (CAN_IFnCMSK_R_NEWDAT_TXRQST_BIT * 4U))))
#define CAN1_BITBANDING_IF2CMSK_TXRQST    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2CMSK_OFFSET) * 32U) + (CAN_IFnCMSK_R_NEWDAT_TXRQST_BIT * 4U))))
#define CAN1_BITBANDING_IF2CMSK_CLRINTPND    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2CMSK_OFFSET) * 32U) + (CAN_IFnCMSK_R_CLRINTPND_BIT * 4U))))
#define CAN1_BITBANDING_IF2CMSK_CONTROL    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2CMSK_OFFSET) * 32U) + (CAN_IFnCMSK_R_CONTROL_BIT * 4U))))
#define CAN1_BITBANDING_IF2CMSK_ARB    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2CMSK_OFFSET) * 32U) + (CAN_IFnCMSK_R_ARB_BIT * 4U))))
#define CAN1_BITBANDING_IF2CMSK_MASK    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1CMSK_OFFSET) * 32U) + (CAN_IFnCMSK_R_MASK_BIT * 4U))))
#define CAN1_BITBANDING_IF2CMSK_WRNRD    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1CMSK_OFFSET) * 32U) + (CAN_IFnCMSK_R_WRNRD_BIT * 4U))))

/******************************************************************************************
*********************************** * 12-13 IFnMSK1 *********************************************
******************************************************************************************/
#define CAN1_BITBANDING_IF1MSK1    ((BITBANDING_CANIFnMSK1_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK1_OFFSET) * 32U)))
#define CAN1_BITBANDING_IF2MSK1    ((BITBANDING_CANIFnMSK1_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK1_OFFSET) * 32U)))


#define CAN1_BITBANDING_IF1MSK1_MSK_EX_ID0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 0UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK1_MSK_EX_ID1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 1UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK1_MSK_EX_ID2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 2UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK1_MSK_EX_ID3    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 3UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK1_MSK_EX_ID4    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 4UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK1_MSK_EX_ID5    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 5UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK1_MSK_EX_ID6    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 6UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK1_MSK_EX_ID7    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 7UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK1_MSK_EX_ID8    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 8UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK1_MSK_EX_ID9    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 9UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK1_MSK_EX_ID10    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 10UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK1_MSK_EX_ID11    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 11UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK1_MSK_EX_ID12    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 12UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK1_MSK_EX_ID13    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 13UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK1_MSK_EX_ID14    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 14UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK1_MSK_EX_ID15    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 15UL)* 4U))))


#define CAN1_BITBANDING_IF2MSK1_MSK_EX_ID0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 0UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK1_MSK_EX_ID1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 1UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK1_MSK_EX_ID2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 2UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK1_MSK_EX_ID3    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 3UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK1_MSK_EX_ID4    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 4UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK1_MSK_EX_ID5    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 5UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK1_MSK_EX_ID6    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 6UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK1_MSK_EX_ID7    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 7UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK1_MSK_EX_ID8    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 8UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK1_MSK_EX_ID9    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 9UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK1_MSK_EX_ID10    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 10UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK1_MSK_EX_ID11    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 11UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK1_MSK_EX_ID12    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 12UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK1_MSK_EX_ID13    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 13UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK1_MSK_EX_ID14    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 14UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK1_MSK_EX_ID15    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK1_OFFSET) * 32U) + ((CAN_IFnMSK1_R_MSK_BIT + 15UL)* 4U))))

/******************************************************************************************
*********************************** * 14-15 IFnMSK2 *********************************************
******************************************************************************************/
#define CAN1_BITBANDING_IF1MSK2    ((BITBANDING_CANIFnMSK2_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK2_OFFSET) * 32U)))
#define CAN1_BITBANDING_IF2MSK2    ((BITBANDING_CANIFnMSK2_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK2_OFFSET) * 32U)))

#define CAN1_BITBANDING_IF1MSK2_MSK_EX_ID16    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 0UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK2_MSK_EX_ID17    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 1UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK2_MSK_EX_ID18    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 2UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK2_MSK_EX_ID19    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 3UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK2_MSK_EX_ID20    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 4UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK2_MSK_EX_ID21    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 5UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK2_MSK_EX_ID22    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 6UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK2_MSK_EX_ID23    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 7UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK2_MSK_EX_ID24    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 8UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK2_MSK_EX_ID25    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 9UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK2_MSK_EX_ID26    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 10UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK2_MSK_EX_ID27    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 11UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK2_MSK_EX_ID28    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 12UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK2_MSK_ID0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 2UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK2_MSK_ID1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 3UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK2_MSK_ID2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 4UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK2_MSK_ID3    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 5UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK2_MSK_ID4    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 6UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK2_MSK_ID5    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 7UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK2_MSK_ID6    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 8UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK2_MSK_ID7    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 9UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK2_MSK_ID8    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 10UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK2_MSK_ID9    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 11UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK2_MSK_ID10    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 12UL)* 4U))))
#define CAN1_BITBANDING_IF1MSK2_MDIR    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK2_OFFSET) * 32U) + (CAN_IFnMSK2_R_MDIR_BIT * 4U))))
#define CAN1_BITBANDING_IF1MSK2_MXTD    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MSK2_OFFSET) * 32U) + (CAN_IFnMSK2_R_MXTD_BIT * 4U))))

#define CAN1_BITBANDING_IF2MSK2_MSK_EX_ID16    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 0UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK2_MSK_EX_ID17    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 1UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK2_MSK_EX_ID18    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 2UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK2_MSK_EX_ID19    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 3UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK2_MSK_EX_ID20    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 4UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK2_MSK_EX_ID21    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 5UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK2_MSK_EX_ID22    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 6UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK2_MSK_EX_ID23    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 7UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK2_MSK_EX_ID24    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 8UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK2_MSK_EX_ID25    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 9UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK2_MSK_EX_ID26    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 10UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK2_MSK_EX_ID27    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 11UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK2_MSK_EX_ID28    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 12UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK2_MSK_ID0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 2UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK2_MSK_ID1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 3UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK2_MSK_ID2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 4UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK2_MSK_ID3    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 5UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK2_MSK_ID4    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 6UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK2_MSK_ID5    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 7UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK2_MSK_ID6    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 8UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK2_MSK_ID7    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 9UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK2_MSK_ID8    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 10UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK2_MSK_ID9    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 11UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK2_MSK_ID10    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK2_OFFSET) * 32U) + ((CAN_IFnMSK2_R_MSK_BIT + 12UL)* 4U))))
#define CAN1_BITBANDING_IF2MSK2_MDIR    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK2_OFFSET) * 32U) + (CAN_IFnMSK2_R_MDIR_BIT * 4U))))
#define CAN1_BITBANDING_IF2MSK2_MXTD    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MSK2_OFFSET) * 32U) + (CAN_IFnMSK2_R_MXTD_BIT * 4U))))

/******************************************************************************************
*********************************** * 16-17 IFnARB1 *********************************************
******************************************************************************************/
#define CAN1_BITBANDING_IF1ARB1    ((BITBANDING_CANIFnARB1_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB1_OFFSET) * 32U)))
#define CAN1_BITBANDING_IF2ARB1    ((BITBANDING_CANIFnARB1_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB1_OFFSET) * 32U)))


#define CAN1_BITBANDING_IF1ARB1_ID_EX_ID0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 0UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB1_ID_EX_ID1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 1UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB1_ID_EX_ID2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 2UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB1_ID_EX_ID3    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 3UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB1_ID_EX_ID4    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 4UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB1_ID_EX_ID5    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 5UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB1_ID_EX_ID6    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 6UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB1_ID_EX_ID7    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 7UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB1_ID_EX_ID8    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 8UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB1_ID_EX_ID9    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 9UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB1_ID_EX_ID10    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 10UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB1_ID_EX_ID11    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 11UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB1_ID_EX_ID12    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 12UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB1_ID_EX_ID13    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 13UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB1_ID_EX_ID14    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 14UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB1_ID_EX_ID15    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 15UL)* 4U))))


#define CAN1_BITBANDING_IF2ARB1_ID_EX_ID0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 0UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB1_ID_EX_ID1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 1UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB1_ID_EX_ID2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 2UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB1_ID_EX_ID3    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 3UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB1_ID_EX_ID4    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 4UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB1_ID_EX_ID5    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 5UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB1_ID_EX_ID6    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 6UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB1_ID_EX_ID7    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 7UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB1_ID_EX_ID8    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 8UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB1_ID_EX_ID9    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 9UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB1_ID_EX_ID10    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 10UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB1_ID_EX_ID11    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 11UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB1_ID_EX_ID12    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 12UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB1_ID_EX_ID13    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 13UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB1_ID_EX_ID14    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 14UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB1_ID_EX_ID15    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB1_OFFSET) * 32U) + ((CAN_IFnARB1_R_ID_BIT + 15UL)* 4U))))

/******************************************************************************************
*********************************** * 18-19 IFnARB2 *********************************************
******************************************************************************************/
#define CAN1_BITBANDING_IF1ARB2    ((BITBANDING_CANIFnARB2_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB2_OFFSET) * 32U)))
#define CAN1_BITBANDING_IF2ARB2    ((BITBANDING_CANIFnARB2_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB2_OFFSET) * 32U)))

#define CAN1_BITBANDING_IF1ARB2_ID_EX_ID16    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 0UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB2_ID_EX_ID17    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 1UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB2_ID_EX_ID18    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 2UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB2_ID_EX_ID19    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 3UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB2_ID_EX_ID20    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 4UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB2_ID_EX_ID21    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 5UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB2_ID_EX_ID22    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 6UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB2_ID_EX_ID23    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 7UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB2_ID_EX_ID24    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 8UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB2_ID_EX_ID25    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 9UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB2_ID_EX_ID26    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 10UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB2_ID_EX_ID27    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 11UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB2_ID_EX_ID28    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 12UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB2_ID_ID0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 2UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB2_ID_ID1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 3UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB2_ID_ID2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 4UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB2_ID_ID3    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 5UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB2_ID_ID4    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 6UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB2_ID_ID5    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 7UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB2_ID_ID6    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 8UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB2_ID_ID7    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 9UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB2_ID_ID8    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 10UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB2_ID_ID9    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 11UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB2_ID_ID10    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 12UL)* 4U))))
#define CAN1_BITBANDING_IF1ARB2_DIR    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB2_OFFSET) * 32U) + (CAN_IFnARB2_R_DIR_BIT * 4U))))
#define CAN1_BITBANDING_IF1ARB2_XTD    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB2_OFFSET) * 32U) + (CAN_IFnARB2_R_XTD_BIT * 4U))))
#define CAN1_BITBANDING_IF1ARB2_MSGVAL    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB2_OFFSET) * 32U) + (CAN_IFnARB2_R_MSGVAL_BIT * 4U))))

#define CAN1_BITBANDING_IF2ARB2_ID_EX_ID16    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 0UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB2_ID_EX_ID17    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 1UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB2_ID_EX_ID18    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 2UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB2_ID_EX_ID19    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 3UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB2_ID_EX_ID20    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 4UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB2_ID_EX_ID21    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 5UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB2_ID_EX_ID22    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 6UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB2_ID_EX_ID23    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 7UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB2_ID_EX_ID24    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 8UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB2_ID_EX_ID25    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 9UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB2_ID_EX_ID26    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 10UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB2_ID_EX_ID27    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 11UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB2_ID_EX_ID28    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 12UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB2_ID_ID0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 2UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB2_ID_ID1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 3UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB2_ID_ID2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 4UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB2_ID_ID3    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 5UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB2_ID_ID4    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 6UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB2_ID_ID5    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 7UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB2_ID_ID6    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 8UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB2_ID_ID7    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 9UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB2_ID_ID8    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 10UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB2_ID_ID9    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 11UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB2_ID_ID10    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB2_OFFSET) * 32U) + ((CAN_IFnARB2_R_ID_BIT + 12UL)* 4U))))
#define CAN1_BITBANDING_IF2ARB2_DIR    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB2_OFFSET) * 32U) + (CAN_IFnARB2_R_DIR_BIT * 4U))))
#define CAN1_BITBANDING_IF2ARB2_XTD    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2ARB2_OFFSET) * 32U) + (CAN_IFnARB2_R_XTD_BIT * 4U))))
#define CAN1_BITBANDING_IF1ARB2_MSGVAL    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1ARB2_OFFSET) * 32U) + (CAN_IFnARB2_R_MSGVAL_BIT * 4U))))

/******************************************************************************************
*********************************** * 20-21 IFnMCTL *********************************************
******************************************************************************************/
#define CAN1_BITBANDING_IF1MCTL    ((BITBANDING_CANIFnMCTL_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MCTL_OFFSET) * 32U)))
#define CAN1_BITBANDING_IF2MCTL    ((BITBANDING_CANIFnMCTL_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MCTL_OFFSET) * 32U)))

#define CAN1_BITBANDING_IF1MCTL_DLC_0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MCTL_OFFSET) * 32U) + ((CAN_IFnMCTL_R_DLC_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_IF1MCTL_DLC_1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MCTL_OFFSET) * 32U) + ((CAN_IFnMCTL_R_DLC_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_IF1MCTL_DLC_2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MCTL_OFFSET) * 32U) + ((CAN_IFnMCTL_R_DLC_BIT + 2UL) * 4U))))
#define CAN1_BITBANDING_IF1MCTL_DLC_3    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MCTL_OFFSET) * 32U) + ((CAN_IFnMCTL_R_DLC_BIT + 3UL) * 4U))))
#define CAN1_BITBANDING_IF1MCTL_EOB    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MCTL_OFFSET) * 32U) + (CAN_IFnMCTL_R_EOB_BIT * 4U))))
#define CAN1_BITBANDING_IF1MCTL_TXRQST    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MCTL_OFFSET) * 32U) + (CAN_IFnMCTL_R_TXRQST_BIT * 4U))))
#define CAN1_BITBANDING_IF1MCTL_RMTEN    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MCTL_OFFSET) * 32U) + (CAN_IFnMCTL_R_RMTEN_BIT * 4U))))
#define CAN1_BITBANDING_IF1MCTL_RXIE    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MCTL_OFFSET) * 32U) + (CAN_IFnMCTL_R_RXIE_BIT * 4U))))
#define CAN1_BITBANDING_IF1MCTL_TXIE    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MCTL_OFFSET) * 32U) + (CAN_IFnMCTL_R_TXIE_BIT * 4U))))
#define CAN1_BITBANDING_IF1MCTL_UMASK    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MCTL_OFFSET) * 32U) + (CAN_IFnMCTL_R_UMASK_BIT * 4U))))
#define CAN1_BITBANDING_IF1MCTL_INTPND    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MCTL_OFFSET) * 32U) + (CAN_IFnMCTL_R_INTPND_BIT * 4U))))
#define CAN1_BITBANDING_IF1MCTL_MSGLST    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MCTL_OFFSET) * 32U) + (CAN_IFnMCTL_R_MSGLST_BIT * 4U))))
#define CAN1_BITBANDING_IF1MCTL_NEWDAT    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1MCTL_OFFSET) * 32U) + (CAN_IFnMCTL_R_NEWDAT_BIT * 4U))))

#define CAN1_BITBANDING_IF2MCTL_DLC_0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MCTL_OFFSET) * 32U) + ((CAN_IFnMCTL_R_DLC_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_IF2MCTL_DLC_1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MCTL_OFFSET) * 32U) + ((CAN_IFnMCTL_R_DLC_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_IF2MCTL_DLC_2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MCTL_OFFSET) * 32U) + ((CAN_IFnMCTL_R_DLC_BIT + 2UL) * 4U))))
#define CAN1_BITBANDING_IF2MCTL_DLC_3    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MCTL_OFFSET) * 32U) + ((CAN_IFnMCTL_R_DLC_BIT + 3UL) * 4U))))
#define CAN1_BITBANDING_IF2MCTL_EOB    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MCTL_OFFSET) * 32U) + (CAN_IFnMCTL_R_EOB_BIT * 4U))))
#define CAN1_BITBANDING_IF2MCTL_TXRQST    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MCTL_OFFSET) * 32U) + (CAN_IFnMCTL_R_TXRQST_BIT * 4U))))
#define CAN1_BITBANDING_IF2MCTL_RMTEN    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MCTL_OFFSET) * 32U) + (CAN_IFnMCTL_R_RMTEN_BIT * 4U))))
#define CAN1_BITBANDING_IF2MCTL_RXIE    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MCTL_OFFSET) * 32U) + (CAN_IFnMCTL_R_RXIE_BIT * 4U))))
#define CAN1_BITBANDING_IF2MCTL_TXIE    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MCTL_OFFSET) * 32U) + (CAN_IFnMCTL_R_TXIE_BIT * 4U))))
#define CAN1_BITBANDING_IF2MCTL_UMASK    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MCTL_OFFSET) * 32U) + (CAN_IFnMCTL_R_UMASK_BIT * 4U))))
#define CAN1_BITBANDING_IF2MCTL_INTPND    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MCTL_OFFSET) * 32U) + (CAN_IFnMCTL_R_INTPND_BIT * 4U))))
#define CAN1_BITBANDING_IF2MCTL_MSGLST    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MCTL_OFFSET) * 32U) + (CAN_IFnMCTL_R_MSGLST_BIT * 4U))))
#define CAN1_BITBANDING_IF2MCTL_NEWDAT    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2MCTL_OFFSET) * 32U) + (CAN_IFnMCTL_R_NEWDAT_BIT * 4U))))

/******************************************************************************************
*********************************** * 22-23 IFnDA1 *********************************************
******************************************************************************************/
#define CAN1_BITBANDING_IF1DA1    ((BITBANDING_CANIFnDA1_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA1_OFFSET) * 32U)))
#define CAN1_BITBANDING_IF2DA1    ((BITBANDING_CANIFnDA1_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA1_OFFSET) * 32U)))

#define CAN1_BITBANDING_IF1DA1_DATA0_0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA0_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_IF1DA1_DATA0_1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA0_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_IF1DA1_DATA0_2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA0_BIT + 2UL) * 4U))))
#define CAN1_BITBANDING_IF1DA1_DATA0_3    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA0_BIT + 3UL) * 4U))))
#define CAN1_BITBANDING_IF1DA1_DATA0_4    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA0_BIT + 4UL) * 4U))))
#define CAN1_BITBANDING_IF1DA1_DATA0_5    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA0_BIT + 5UL) * 4U))))
#define CAN1_BITBANDING_IF1DA1_DATA0_6    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA0_BIT + 6UL) * 4U))))
#define CAN1_BITBANDING_IF1DA1_DATA0_7    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA0_BIT + 7UL) * 4U))))
#define CAN1_BITBANDING_IF1DA1_DATA1_0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA1_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_IF1DA1_DATA1_1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA1_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_IF1DA1_DATA1_2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA1_BIT + 2UL) * 4U))))
#define CAN1_BITBANDING_IF1DA1_DATA1_3    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA1_BIT + 3UL) * 4U))))
#define CAN1_BITBANDING_IF1DA1_DATA1_4    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA1_BIT + 4UL) * 4U))))
#define CAN1_BITBANDING_IF1DA1_DATA1_5    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA1_BIT + 5UL) * 4U))))
#define CAN1_BITBANDING_IF1DA1_DATA1_6    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA1_BIT + 6UL) * 4U))))
#define CAN1_BITBANDING_IF1DA1_DATA1_7    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA1_BIT + 7UL) * 4U))))


#define CAN1_BITBANDING_IF2DA1_DATA0_0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA0_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_IF2DA1_DATA0_1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA0_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_IF2DA1_DATA0_2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA0_BIT + 2UL) * 4U))))
#define CAN1_BITBANDING_IF2DA1_DATA0_3    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA0_BIT + 3UL) * 4U))))
#define CAN1_BITBANDING_IF2DA1_DATA0_4    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA0_BIT + 4UL) * 4U))))
#define CAN1_BITBANDING_IF2DA1_DATA0_5    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA0_BIT + 5UL) * 4U))))
#define CAN1_BITBANDING_IF2DA1_DATA0_6    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA0_BIT + 6UL) * 4U))))
#define CAN1_BITBANDING_IF2DA1_DATA0_7    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA0_BIT + 7UL) * 4U))))
#define CAN1_BITBANDING_IF2DA1_DATA1_0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA1_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_IF2DA1_DATA1_1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA1_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_IF2DA1_DATA1_2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA1_BIT + 2UL) * 4U))))
#define CAN1_BITBANDING_IF2DA1_DATA1_3    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA1_BIT + 3UL) * 4U))))
#define CAN1_BITBANDING_IF2DA1_DATA1_4    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA1_BIT + 4UL) * 4U))))
#define CAN1_BITBANDING_IF2DA1_DATA1_5    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA1_BIT + 5UL) * 4U))))
#define CAN1_BITBANDING_IF2DA1_DATA1_6    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA1_BIT + 6UL) * 4U))))
#define CAN1_BITBANDING_IF2DA1_DATA1_7    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA1_OFFSET) * 32U) + ((CAN_IFnDA1_R_DATA1_BIT + 7UL) * 4U))))

/******************************************************************************************
*********************************** * 24-25 IFnDA2 *********************************************
******************************************************************************************/
#define CAN1_BITBANDING_IF1DA2    ((BITBANDING_CANIFnDA2_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA2_OFFSET) * 32U)))
#define CAN1_BITBANDING_IF2DA2    ((BITBANDING_CANIFnDA2_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA2_OFFSET) * 32U)))

#define CAN1_BITBANDING_IF1DA2_DATA2_0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA2_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_IF1DA2_DATA2_1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA2_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_IF1DA2_DATA2_2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA2_BIT + 2UL) * 4U))))
#define CAN1_BITBANDING_IF1DA2_DATA2_3    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA2_BIT + 3UL) * 4U))))
#define CAN1_BITBANDING_IF1DA2_DATA2_4    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA2_BIT + 4UL) * 4U))))
#define CAN1_BITBANDING_IF1DA2_DATA2_5    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA2_BIT + 5UL) * 4U))))
#define CAN1_BITBANDING_IF1DA2_DATA2_6    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA2_BIT + 6UL) * 4U))))
#define CAN1_BITBANDING_IF1DA2_DATA2_7    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA2_BIT + 7UL) * 4U))))
#define CAN1_BITBANDING_IF1DA2_DATA3_0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA3_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_IF1DA2_DATA3_1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA3_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_IF1DA2_DATA3_2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA3_BIT + 2UL) * 4U))))
#define CAN1_BITBANDING_IF1DA2_DATA3_3    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA3_BIT + 3UL) * 4U))))
#define CAN1_BITBANDING_IF1DA2_DATA3_4    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA3_BIT + 4UL) * 4U))))
#define CAN1_BITBANDING_IF1DA2_DATA3_5    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA3_BIT + 5UL) * 4U))))
#define CAN1_BITBANDING_IF1DA2_DATA3_6    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA3_BIT + 6UL) * 4U))))
#define CAN1_BITBANDING_IF1DA2_DATA3_7    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA3_BIT + 7UL) * 4U))))


#define CAN1_BITBANDING_IF2DA2_DATA2_0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA2_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_IF2DA2_DATA2_1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA2_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_IF2DA2_DATA2_2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA2_BIT + 2UL) * 4U))))
#define CAN1_BITBANDING_IF2DA2_DATA2_3    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA2_BIT + 3UL) * 4U))))
#define CAN1_BITBANDING_IF2DA2_DATA2_4    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA2_BIT + 4UL) * 4U))))
#define CAN1_BITBANDING_IF2DA2_DATA2_5    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA2_BIT + 5UL) * 4U))))
#define CAN1_BITBANDING_IF2DA2_DATA2_6    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA2_BIT + 6UL) * 4U))))
#define CAN1_BITBANDING_IF2DA2_DATA2_7    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA2_BIT + 7UL) * 4U))))
#define CAN1_BITBANDING_IF2DA2_DATA3_0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA3_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_IF2DA2_DATA3_1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA3_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_IF2DA2_DATA3_2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA3_BIT + 2UL) * 4U))))
#define CAN1_BITBANDING_IF2DA2_DATA3_3    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA3_BIT + 3UL) * 4U))))
#define CAN1_BITBANDING_IF2DA2_DATA3_4    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA3_BIT + 4UL) * 4U))))
#define CAN1_BITBANDING_IF2DA2_DATA3_5    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA3_BIT + 5UL) * 4U))))
#define CAN1_BITBANDING_IF2DA2_DATA3_6    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA3_BIT + 6UL) * 4U))))
#define CAN1_BITBANDING_IF2DA2_DATA3_7    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DA2_OFFSET) * 32U) + ((CAN_IFnDA2_R_DATA3_BIT + 7UL) * 4U))))

/******************************************************************************************
*********************************** * 26-27 IFnDB1 *********************************************
******************************************************************************************/
#define CAN1_BITBANDING_IF1DB1    ((BITBANDING_CANIFnDB1_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB1_OFFSET) * 32U)))
#define CAN1_BITBANDING_IF2DB1    ((BITBANDING_CANIFnDB1_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB1_OFFSET) * 32U)))

#define CAN1_BITBANDING_IF1DB1_DATA4_0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA4_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_IF1DB1_DATA4_1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA4_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_IF1DB1_DATA4_2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA4_BIT + 2UL) * 4U))))
#define CAN1_BITBANDING_IF1DB1_DATA4_3    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA4_BIT + 3UL) * 4U))))
#define CAN1_BITBANDING_IF1DB1_DATA4_4    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA4_BIT + 4UL) * 4U))))
#define CAN1_BITBANDING_IF1DB1_DATA4_5    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA4_BIT + 5UL) * 4U))))
#define CAN1_BITBANDING_IF1DB1_DATA4_6    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA4_BIT + 6UL) * 4U))))
#define CAN1_BITBANDING_IF1DB1_DATA4_7    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA4_BIT + 7UL) * 4U))))
#define CAN1_BITBANDING_IF1DB1_DATA5_0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA5_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_IF1DB1_DATA5_1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA5_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_IF1DB1_DATA5_2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA5_BIT + 2UL) * 4U))))
#define CAN1_BITBANDING_IF1DB1_DATA5_3    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA5_BIT + 3UL) * 4U))))
#define CAN1_BITBANDING_IF1DB1_DATA5_4    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA5_BIT + 4UL) * 4U))))
#define CAN1_BITBANDING_IF1DB1_DATA5_5    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA5_BIT + 5UL) * 4U))))
#define CAN1_BITBANDING_IF1DB1_DATA5_6    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA5_BIT + 6UL) * 4U))))
#define CAN1_BITBANDING_IF1DB1_DATA5_7    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA5_BIT + 7UL) * 4U))))


#define CAN1_BITBANDING_IF2DB1_DATA4_0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA4_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_IF2DB1_DATA4_1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA4_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_IF2DB1_DATA4_2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA4_BIT + 2UL) * 4U))))
#define CAN1_BITBANDING_IF2DB1_DATA4_3    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA4_BIT + 3UL) * 4U))))
#define CAN1_BITBANDING_IF2DB1_DATA4_4    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA4_BIT + 4UL) * 4U))))
#define CAN1_BITBANDING_IF2DB1_DATA4_5    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA4_BIT + 5UL) * 4U))))
#define CAN1_BITBANDING_IF2DB1_DATA4_6    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA4_BIT + 6UL) * 4U))))
#define CAN1_BITBANDING_IF2DB1_DATA4_7    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA4_BIT + 7UL) * 4U))))
#define CAN1_BITBANDING_IF2DB1_DATA5_0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA5_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_IF2DB1_DATA5_1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA5_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_IF2DB1_DATA5_2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA5_BIT + 2UL) * 4U))))
#define CAN1_BITBANDING_IF2DB1_DATA5_3    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA5_BIT + 3UL) * 4U))))
#define CAN1_BITBANDING_IF2DB1_DATA5_4    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA5_BIT + 4UL) * 4U))))
#define CAN1_BITBANDING_IF2DB1_DATA5_5    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA5_BIT + 5UL) * 4U))))
#define CAN1_BITBANDING_IF2DB1_DATA5_6    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA5_BIT + 6UL) * 4U))))
#define CAN1_BITBANDING_IF2DB1_DATA5_7    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB1_OFFSET) * 32U) + ((CAN_IFnDB1_R_DATA5_BIT + 7UL) * 4U))))

/******************************************************************************************
*********************************** * 28-29 IFnDB2 *********************************************
******************************************************************************************/
#define CAN1_BITBANDING_IF1DB2    ((BITBANDING_CANIFnDB2_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB2_OFFSET) * 32U)))
#define CAN1_BITBANDING_IF2DB2    ((BITBANDING_CANIFnDB2_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB2_OFFSET) * 32U)))

#define CAN1_BITBANDING_IF1DB2_DATA6_0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA6_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_IF1DB2_DATA6_1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA6_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_IF1DB2_DATA6_2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA6_BIT + 2UL) * 4U))))
#define CAN1_BITBANDING_IF1DB2_DATA6_3    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA6_BIT + 3UL) * 4U))))
#define CAN1_BITBANDING_IF1DB2_DATA6_4    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA6_BIT + 4UL) * 4U))))
#define CAN1_BITBANDING_IF1DB2_DATA6_5    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA6_BIT + 5UL) * 4U))))
#define CAN1_BITBANDING_IF1DB2_DATA6_6    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA6_BIT + 6UL) * 4U))))
#define CAN1_BITBANDING_IF1DB2_DATA6_7    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA6_BIT + 7UL) * 4U))))
#define CAN1_BITBANDING_IF1DB2_DATA7_0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA7_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_IF1DB2_DATA7_1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA7_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_IF1DB2_DATA7_2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA7_BIT + 2UL) * 4U))))
#define CAN1_BITBANDING_IF1DB2_DATA7_3    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA7_BIT + 3UL) * 4U))))
#define CAN1_BITBANDING_IF1DB2_DATA7_4    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA7_BIT + 4UL) * 4U))))
#define CAN1_BITBANDING_IF1DB2_DATA7_5    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA7_BIT + 5UL) * 4U))))
#define CAN1_BITBANDING_IF1DB2_DATA7_6    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA7_BIT + 6UL) * 4U))))
#define CAN1_BITBANDING_IF1DB2_DATA7_7    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF1DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA7_BIT + 7UL) * 4U))))


#define CAN1_BITBANDING_IF2DB2_DATA6_0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA6_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_IF2DB2_DATA6_1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA6_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_IF2DB2_DATA6_2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA6_BIT + 2UL) * 4U))))
#define CAN1_BITBANDING_IF2DB2_DATA6_3    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA6_BIT + 3UL) * 4U))))
#define CAN1_BITBANDING_IF2DB2_DATA6_4    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA6_BIT + 4UL) * 4U))))
#define CAN1_BITBANDING_IF2DB2_DATA6_5    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA6_BIT + 5UL) * 4U))))
#define CAN1_BITBANDING_IF2DB2_DATA6_6    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA6_BIT + 6UL) * 4U))))
#define CAN1_BITBANDING_IF2DB2_DATA6_7    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA6_BIT + 7UL) * 4U))))
#define CAN1_BITBANDING_IF2DB2_DATA7_0    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA7_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_IF2DB2_DATA7_1    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA7_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_IF2DB2_DATA7_2    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA7_BIT + 2UL) * 4U))))
#define CAN1_BITBANDING_IF2DB2_DATA7_3    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA7_BIT + 3UL) * 4U))))
#define CAN1_BITBANDING_IF2DB2_DATA7_4    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA7_BIT + 4UL) * 4U))))
#define CAN1_BITBANDING_IF2DB2_DATA7_5    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA7_BIT + 5UL) * 4U))))
#define CAN1_BITBANDING_IF2DB2_DATA7_6    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA7_BIT + 6UL) * 4U))))
#define CAN1_BITBANDING_IF2DB2_DATA7_7    (*((volatile uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_IF2DB2_OFFSET) * 32U) + ((CAN_IFnDB2_R_DATA7_BIT + 7UL) * 4U))))

/******************************************************************************************
*********************************** * 30 - 31 TXRQn *********************************************
******************************************************************************************/
#define CAN1_BITBANDING_TXRQ1    ((BITBANDING_CANTXRQn_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ1_OFFSET) * 32U)))
#define CAN1_BITBANDING_TXRQ2    ((BITBANDING_CANTXRQn_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ2_OFFSET) * 32U)))

#define CAN1_BITBANDING_TXRQ1_TXRQST1    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ1_OFFSET) * 32U) + ((CAN_TXRQ1_R_TXRQST_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_TXRQ1_TXRQST2    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ1_OFFSET) * 32U) + ((CAN_TXRQ1_R_TXRQST_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_TXRQ1_TXRQST3    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ1_OFFSET) * 32U) + ((CAN_TXRQ1_R_TXRQST_BIT + 2UL) * 4U))))
#define CAN1_BITBANDING_TXRQ1_TXRQST4    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ1_OFFSET) * 32U) + ((CAN_TXRQ1_R_TXRQST_BIT + 3UL) * 4U))))
#define CAN1_BITBANDING_TXRQ1_TXRQST5    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ1_OFFSET) * 32U) + ((CAN_TXRQ1_R_TXRQST_BIT + 4UL) * 4U))))
#define CAN1_BITBANDING_TXRQ1_TXRQST6    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ1_OFFSET) * 32U) + ((CAN_TXRQ1_R_TXRQST_BIT + 5UL) * 4U))))
#define CAN1_BITBANDING_TXRQ1_TXRQST7    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ1_OFFSET) * 32U) + ((CAN_TXRQ1_R_TXRQST_BIT + 6UL) * 4U))))
#define CAN1_BITBANDING_TXRQ1_TXRQST8    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ1_OFFSET) * 32U) + ((CAN_TXRQ1_R_TXRQST_BIT + 7UL) * 4U))))
#define CAN1_BITBANDING_TXRQ1_TXRQST9    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ1_OFFSET) * 32U) + ((CAN_TXRQ1_R_TXRQST_BIT + 8UL) * 4U))))
#define CAN1_BITBANDING_TXRQ1_TXRQST10    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ1_OFFSET) * 32U) + ((CAN_TXRQ1_R_TXRQST_BIT + 9UL) * 4U))))
#define CAN1_BITBANDING_TXRQ1_TXRQST11    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ1_OFFSET) * 32U) + ((CAN_TXRQ1_R_TXRQST_BIT + 10UL) * 4U))))
#define CAN1_BITBANDING_TXRQ1_TXRQST12    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ1_OFFSET) * 32U) + ((CAN_TXRQ1_R_TXRQST_BIT + 11UL) * 4U))))
#define CAN1_BITBANDING_TXRQ1_TXRQST13    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ1_OFFSET) * 32U) + ((CAN_TXRQ1_R_TXRQST_BIT + 12UL) * 4U))))
#define CAN1_BITBANDING_TXRQ1_TXRQST14    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ1_OFFSET) * 32U) + ((CAN_TXRQ1_R_TXRQST_BIT + 13UL) * 4U))))
#define CAN1_BITBANDING_TXRQ1_TXRQST15    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ1_OFFSET) * 32U) + ((CAN_TXRQ1_R_TXRQST_BIT + 14UL) * 4U))))
#define CAN1_BITBANDING_TXRQ1_TXRQST16    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ1_OFFSET) * 32U) + ((CAN_TXRQ1_R_TXRQST_BIT + 15UL) * 4U))))


#define CAN1_BITBANDING_TXRQ2_TXRQST17    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ2_OFFSET) * 32U) + ((CAN_TXRQ2_R_TXRQST_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_TXRQ2_TXRQST18    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ2_OFFSET) * 32U) + ((CAN_TXRQ2_R_TXRQST_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_TXRQ2_TXRQST19    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ2_OFFSET) * 32U) + ((CAN_TXRQ2_R_TXRQST_BIT + 2UL) * 4U))))
#define CAN1_BITBANDING_TXRQ2_TXRQST20    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ2_OFFSET) * 32U) + ((CAN_TXRQ2_R_TXRQST_BIT + 3UL) * 4U))))
#define CAN1_BITBANDING_TXRQ2_TXRQST21    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ2_OFFSET) * 32U) + ((CAN_TXRQ2_R_TXRQST_BIT + 4UL) * 4U))))
#define CAN1_BITBANDING_TXRQ2_TXRQST22    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ2_OFFSET) * 32U) + ((CAN_TXRQ2_R_TXRQST_BIT + 5UL) * 4U))))
#define CAN1_BITBANDING_TXRQ2_TXRQST23    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ2_OFFSET) * 32U) + ((CAN_TXRQ2_R_TXRQST_BIT + 6UL) * 4U))))
#define CAN1_BITBANDING_TXRQ2_TXRQST24    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ2_OFFSET) * 32U) + ((CAN_TXRQ2_R_TXRQST_BIT + 7UL) * 4U))))
#define CAN1_BITBANDING_TXRQ2_TXRQST25    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ2_OFFSET) * 32U) + ((CAN_TXRQ2_R_TXRQST_BIT + 8UL) * 4U))))
#define CAN1_BITBANDING_TXRQ2_TXRQST26    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ2_OFFSET) * 32U) + ((CAN_TXRQ2_R_TXRQST_BIT + 9UL) * 4U))))
#define CAN1_BITBANDING_TXRQ2_TXRQST27    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ2_OFFSET) * 32U) + ((CAN_TXRQ2_R_TXRQST_BIT + 10UL) * 4U))))
#define CAN1_BITBANDING_TXRQ2_TXRQST28    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ2_OFFSET) * 32U) + ((CAN_TXRQ2_R_TXRQST_BIT + 11UL) * 4U))))
#define CAN1_BITBANDING_TXRQ2_TXRQST29    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ2_OFFSET) * 32U) + ((CAN_TXRQ2_R_TXRQST_BIT + 12UL) * 4U))))
#define CAN1_BITBANDING_TXRQ2_TXRQST30    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ2_OFFSET) * 32U) + ((CAN_TXRQ2_R_TXRQST_BIT + 13UL) * 4U))))
#define CAN1_BITBANDING_TXRQ2_TXRQST31    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ2_OFFSET) * 32U) + ((CAN_TXRQ2_R_TXRQST_BIT + 14UL) * 4U))))
#define CAN1_BITBANDING_TXRQ2_TXRQST32    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_TXRQ2_OFFSET) * 32U) + ((CAN_TXRQ2_R_TXRQST_BIT + 15UL) * 4U))))

/******************************************************************************************
*********************************** * 32 - 33 NWDAn *********************************************
******************************************************************************************/
#define CAN1_BITBANDING_NWDA1    ((BITBANDING_CANNWDAn_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA1_OFFSET) * 32U)))
#define CAN1_BITBANDING_NWDA2    ((BITBANDING_CANNWDAn_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA2_OFFSET) * 32U)))

#define CAN1_BITBANDING_NWDA1_NEWDAT1    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA1_OFFSET) * 32U) + ((CAN_NWDA1_R_NEWDAT_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_NWDA1_NEWDAT2    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA1_OFFSET) * 32U) + ((CAN_NWDA1_R_NEWDAT_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_NWDA1_NEWDAT3    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA1_OFFSET) * 32U) + ((CAN_NWDA1_R_NEWDAT_BIT + 2UL) * 4U))))
#define CAN1_BITBANDING_NWDA1_NEWDAT4    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA1_OFFSET) * 32U) + ((CAN_NWDA1_R_NEWDAT_BIT + 3UL) * 4U))))
#define CAN1_BITBANDING_NWDA1_NEWDAT5    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA1_OFFSET) * 32U) + ((CAN_NWDA1_R_NEWDAT_BIT + 4UL) * 4U))))
#define CAN1_BITBANDING_NWDA1_NEWDAT6    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA1_OFFSET) * 32U) + ((CAN_NWDA1_R_NEWDAT_BIT + 5UL) * 4U))))
#define CAN1_BITBANDING_NWDA1_NEWDAT7    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA1_OFFSET) * 32U) + ((CAN_NWDA1_R_NEWDAT_BIT + 6UL) * 4U))))
#define CAN1_BITBANDING_NWDA1_NEWDAT8    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA1_OFFSET) * 32U) + ((CAN_NWDA1_R_NEWDAT_BIT + 7UL) * 4U))))
#define CAN1_BITBANDING_NWDA1_NEWDAT9    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA1_OFFSET) * 32U) + ((CAN_NWDA1_R_NEWDAT_BIT + 8UL) * 4U))))
#define CAN1_BITBANDING_NWDA1_NEWDAT10    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA1_OFFSET) * 32U) + ((CAN_NWDA1_R_NEWDAT_BIT + 9UL) * 4U))))
#define CAN1_BITBANDING_NWDA1_NEWDAT11    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA1_OFFSET) * 32U) + ((CAN_NWDA1_R_NEWDAT_BIT + 10UL) * 4U))))
#define CAN1_BITBANDING_NWDA1_NEWDAT12    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA1_OFFSET) * 32U) + ((CAN_NWDA1_R_NEWDAT_BIT + 11UL) * 4U))))
#define CAN1_BITBANDING_NWDA1_NEWDAT13    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA1_OFFSET) * 32U) + ((CAN_NWDA1_R_NEWDAT_BIT + 12UL) * 4U))))
#define CAN1_BITBANDING_NWDA1_NEWDAT14    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA1_OFFSET) * 32U) + ((CAN_NWDA1_R_NEWDAT_BIT + 13UL) * 4U))))
#define CAN1_BITBANDING_NWDA1_NEWDAT15    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA1_OFFSET) * 32U) + ((CAN_NWDA1_R_NEWDAT_BIT + 14UL) * 4U))))
#define CAN1_BITBANDING_NWDA1_NEWDAT16    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA1_OFFSET) * 32U) + ((CAN_NWDA1_R_NEWDAT_BIT + 15UL) * 4U))))


#define CAN1_BITBANDING_NWDA2_NEWDAT17    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA2_OFFSET) * 32U) + ((CAN_NWDA2_R_NEWDAT_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_NWDA2_NEWDAT18    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA2_OFFSET) * 32U) + ((CAN_NWDA2_R_NEWDAT_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_NWDA2_NEWDAT19    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA2_OFFSET) * 32U) + ((CAN_NWDA2_R_NEWDAT_BIT + 2UL) * 4U))))
#define CAN1_BITBANDING_NWDA2_NEWDAT20    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA2_OFFSET) * 32U) + ((CAN_NWDA2_R_NEWDAT_BIT + 3UL) * 4U))))
#define CAN1_BITBANDING_NWDA2_NEWDAT21    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA2_OFFSET) * 32U) + ((CAN_NWDA2_R_NEWDAT_BIT + 4UL) * 4U))))
#define CAN1_BITBANDING_NWDA2_NEWDAT22    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA2_OFFSET) * 32U) + ((CAN_NWDA2_R_NEWDAT_BIT + 5UL) * 4U))))
#define CAN1_BITBANDING_NWDA2_NEWDAT23    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA2_OFFSET) * 32U) + ((CAN_NWDA2_R_NEWDAT_BIT + 6UL) * 4U))))
#define CAN1_BITBANDING_NWDA2_NEWDAT24    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA2_OFFSET) * 32U) + ((CAN_NWDA2_R_NEWDAT_BIT + 7UL) * 4U))))
#define CAN1_BITBANDING_NWDA2_NEWDAT25    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA2_OFFSET) * 32U) + ((CAN_NWDA2_R_NEWDAT_BIT + 8UL) * 4U))))
#define CAN1_BITBANDING_NWDA2_NEWDAT26    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA2_OFFSET) * 32U) + ((CAN_NWDA2_R_NEWDAT_BIT + 9UL) * 4U))))
#define CAN1_BITBANDING_NWDA2_NEWDAT27    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA2_OFFSET) * 32U) + ((CAN_NWDA2_R_NEWDAT_BIT + 10UL) * 4U))))
#define CAN1_BITBANDING_NWDA2_NEWDAT28    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA2_OFFSET) * 32U) + ((CAN_NWDA2_R_NEWDAT_BIT + 11UL) * 4U))))
#define CAN1_BITBANDING_NWDA2_NEWDAT29    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA2_OFFSET) * 32U) + ((CAN_NWDA2_R_NEWDAT_BIT + 12UL) * 4U))))
#define CAN1_BITBANDING_NWDA2_NEWDAT30    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA2_OFFSET) * 32U) + ((CAN_NWDA2_R_NEWDAT_BIT + 13UL) * 4U))))
#define CAN1_BITBANDING_NWDA2_NEWDAT31    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA2_OFFSET) * 32U) + ((CAN_NWDA2_R_NEWDAT_BIT + 14UL) * 4U))))
#define CAN1_BITBANDING_NWDA2_NEWDAT32    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_NWDA2_OFFSET) * 32U) + ((CAN_NWDA2_R_NEWDAT_BIT + 15UL) * 4U))))

/******************************************************************************************
*********************************** * 34 - 35 MSGnINT *********************************************
******************************************************************************************/
#define CAN1_BITBANDING_MSG1INT    ((BITBANDING_CANMSGnINT_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1INT_OFFSET) * 32U)))
#define CAN1_BITBANDING_MSG2INT    ((BITBANDING_CANMSGnINT_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2INT_OFFSET) * 32U)))

#define CAN1_BITBANDING_MSG1INT_INTPND1    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1INT_OFFSET) * 32U) + ((CAN_MSG1INT_R_INTPND_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_MSG1INT_INTPND2    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1INT_OFFSET) * 32U) + ((CAN_MSG1INT_R_INTPND_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_MSG1INT_INTPND3    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1INT_OFFSET) * 32U) + ((CAN_MSG1INT_R_INTPND_BIT + 2UL) * 4U))))
#define CAN1_BITBANDING_MSG1INT_INTPND4    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1INT_OFFSET) * 32U) + ((CAN_MSG1INT_R_INTPND_BIT + 3UL) * 4U))))
#define CAN1_BITBANDING_MSG1INT_INTPND5    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1INT_OFFSET) * 32U) + ((CAN_MSG1INT_R_INTPND_BIT + 4UL) * 4U))))
#define CAN1_BITBANDING_MSG1INT_INTPND6    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1INT_OFFSET) * 32U) + ((CAN_MSG1INT_R_INTPND_BIT + 5UL) * 4U))))
#define CAN1_BITBANDING_MSG1INT_INTPND7    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1INT_OFFSET) * 32U) + ((CAN_MSG1INT_R_INTPND_BIT + 6UL) * 4U))))
#define CAN1_BITBANDING_MSG1INT_INTPND8    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1INT_OFFSET) * 32U) + ((CAN_MSG1INT_R_INTPND_BIT + 7UL) * 4U))))
#define CAN1_BITBANDING_MSG1INT_INTPND9    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1INT_OFFSET) * 32U) + ((CAN_MSG1INT_R_INTPND_BIT + 8UL) * 4U))))
#define CAN1_BITBANDING_MSG1INT_INTPND10    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1INT_OFFSET) * 32U) + ((CAN_MSG1INT_R_INTPND_BIT + 9UL) * 4U))))
#define CAN1_BITBANDING_MSG1INT_INTPND11    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1INT_OFFSET) * 32U) + ((CAN_MSG1INT_R_INTPND_BIT + 10UL) * 4U))))
#define CAN1_BITBANDING_MSG1INT_INTPND12    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1INT_OFFSET) * 32U) + ((CAN_MSG1INT_R_INTPND_BIT + 11UL) * 4U))))
#define CAN1_BITBANDING_MSG1INT_INTPND13    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1INT_OFFSET) * 32U) + ((CAN_MSG1INT_R_INTPND_BIT + 12UL) * 4U))))
#define CAN1_BITBANDING_MSG1INT_INTPND14    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1INT_OFFSET) * 32U) + ((CAN_MSG1INT_R_INTPND_BIT + 13UL) * 4U))))
#define CAN1_BITBANDING_MSG1INT_INTPND15    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1INT_OFFSET) * 32U) + ((CAN_MSG1INT_R_INTPND_BIT + 14UL) * 4U))))
#define CAN1_BITBANDING_MSG1INT_INTPND16    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1INT_OFFSET) * 32U) + ((CAN_MSG1INT_R_INTPND_BIT + 15UL) * 4U))))


#define CAN1_BITBANDING_MSG2INT_INTPND17    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2INT_OFFSET) * 32U) + ((CAN_MSG2INT_R_INTPND_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_MSG2INT_INTPND18    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2INT_OFFSET) * 32U) + ((CAN_MSG2INT_R_INTPND_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_MSG2INT_INTPND19    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2INT_OFFSET) * 32U) + ((CAN_MSG2INT_R_INTPND_BIT + 2UL) * 4U))))
#define CAN1_BITBANDING_MSG2INT_INTPND20    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2INT_OFFSET) * 32U) + ((CAN_MSG2INT_R_INTPND_BIT + 3UL) * 4U))))
#define CAN1_BITBANDING_MSG2INT_INTPND21    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2INT_OFFSET) * 32U) + ((CAN_MSG2INT_R_INTPND_BIT + 4UL) * 4U))))
#define CAN1_BITBANDING_MSG2INT_INTPND22    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2INT_OFFSET) * 32U) + ((CAN_MSG2INT_R_INTPND_BIT + 5UL) * 4U))))
#define CAN1_BITBANDING_MSG2INT_INTPND23    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2INT_OFFSET) * 32U) + ((CAN_MSG2INT_R_INTPND_BIT + 6UL) * 4U))))
#define CAN1_BITBANDING_MSG2INT_INTPND24    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2INT_OFFSET) * 32U) + ((CAN_MSG2INT_R_INTPND_BIT + 7UL) * 4U))))
#define CAN1_BITBANDING_MSG2INT_INTPND25    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2INT_OFFSET) * 32U) + ((CAN_MSG2INT_R_INTPND_BIT + 8UL) * 4U))))
#define CAN1_BITBANDING_MSG2INT_INTPND26    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2INT_OFFSET) * 32U) + ((CAN_MSG2INT_R_INTPND_BIT + 9UL) * 4U))))
#define CAN1_BITBANDING_MSG2INT_INTPND27    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2INT_OFFSET) * 32U) + ((CAN_MSG2INT_R_INTPND_BIT + 10UL) * 4U))))
#define CAN1_BITBANDING_MSG2INT_INTPND28    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2INT_OFFSET) * 32U) + ((CAN_MSG2INT_R_INTPND_BIT + 11UL) * 4U))))
#define CAN1_BITBANDING_MSG2INT_INTPND29    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2INT_OFFSET) * 32U) + ((CAN_MSG2INT_R_INTPND_BIT + 12UL) * 4U))))
#define CAN1_BITBANDING_MSG2INT_INTPND30    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2INT_OFFSET) * 32U) + ((CAN_MSG2INT_R_INTPND_BIT + 13UL) * 4U))))
#define CAN1_BITBANDING_MSG2INT_INTPND31    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2INT_OFFSET) * 32U) + ((CAN_MSG2INT_R_INTPND_BIT + 14UL) * 4U))))
#define CAN1_BITBANDING_MSG2INT_INTPND32    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2INT_OFFSET) * 32U) + ((CAN_MSG2INT_R_INTPND_BIT + 15UL) * 4U))))

/******************************************************************************************
*********************************** * 36 - 37 MSGnVAL *********************************************
******************************************************************************************/
#define CAN1_BITBANDING_MSG1VAL    ((BITBANDING_CANMSGnVAL_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1VAL_OFFSET) * 32U)))
#define CAN1_BITBANDING_MSG2VAL    ((BITBANDING_CANMSGnVAL_t*) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2VAL_OFFSET) * 32U)))

#define CAN1_BITBANDING_MSG1VAL_MSGVAL1    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1VAL_OFFSET) * 32U) + ((CAN_MSG1VAL_R_MSGVAL_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_MSG1VAL_MSGVAL2    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1VAL_OFFSET) * 32U) + ((CAN_MSG1VAL_R_MSGVAL_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_MSG1VAL_MSGVAL3    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1VAL_OFFSET) * 32U) + ((CAN_MSG1VAL_R_MSGVAL_BIT + 2UL) * 4U))))
#define CAN1_BITBANDING_MSG1VAL_MSGVAL4    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1VAL_OFFSET) * 32U) + ((CAN_MSG1VAL_R_MSGVAL_BIT + 3UL) * 4U))))
#define CAN1_BITBANDING_MSG1VAL_MSGVAL5    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1VAL_OFFSET) * 32U) + ((CAN_MSG1VAL_R_MSGVAL_BIT + 4UL) * 4U))))
#define CAN1_BITBANDING_MSG1VAL_MSGVAL6    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1VAL_OFFSET) * 32U) + ((CAN_MSG1VAL_R_MSGVAL_BIT + 5UL) * 4U))))
#define CAN1_BITBANDING_MSG1VAL_MSGVAL7    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1VAL_OFFSET) * 32U) + ((CAN_MSG1VAL_R_MSGVAL_BIT + 6UL) * 4U))))
#define CAN1_BITBANDING_MSG1VAL_MSGVAL8    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1VAL_OFFSET) * 32U) + ((CAN_MSG1VAL_R_MSGVAL_BIT + 7UL) * 4U))))
#define CAN1_BITBANDING_MSG1VAL_MSGVAL9    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1VAL_OFFSET) * 32U) + ((CAN_MSG1VAL_R_MSGVAL_BIT + 8UL) * 4U))))
#define CAN1_BITBANDING_MSG1VAL_MSGVAL10    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1VAL_OFFSET) * 32U) + ((CAN_MSG1VAL_R_MSGVAL_BIT + 9UL) * 4U))))
#define CAN1_BITBANDING_MSG1VAL_MSGVAL11    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1VAL_OFFSET) * 32U) + ((CAN_MSG1VAL_R_MSGVAL_BIT + 10UL) * 4U))))
#define CAN1_BITBANDING_MSG1VAL_MSGVAL12    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1VAL_OFFSET) * 32U) + ((CAN_MSG1VAL_R_MSGVAL_BIT + 11UL) * 4U))))
#define CAN1_BITBANDING_MSG1VAL_MSGVAL13    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1VAL_OFFSET) * 32U) + ((CAN_MSG1VAL_R_MSGVAL_BIT + 12UL) * 4U))))
#define CAN1_BITBANDING_MSG1VAL_MSGVAL14    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1VAL_OFFSET) * 32U) + ((CAN_MSG1VAL_R_MSGVAL_BIT + 13UL) * 4U))))
#define CAN1_BITBANDING_MSG1VAL_MSGVAL15    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1VAL_OFFSET) * 32U) + ((CAN_MSG1VAL_R_MSGVAL_BIT + 14UL) * 4U))))
#define CAN1_BITBANDING_MSG1VAL_MSGVAL16    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG1VAL_OFFSET) * 32U) + ((CAN_MSG1VAL_R_MSGVAL_BIT + 15UL) * 4U))))


#define CAN1_BITBANDING_MSG2VAL_MSGVAL17    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2VAL_OFFSET) * 32U) + ((CAN_MSG2VAL_R_MSGVAL_BIT + 0UL) * 4U))))
#define CAN1_BITBANDING_MSG2VAL_MSGVAL18    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2VAL_OFFSET) * 32U) + ((CAN_MSG2VAL_R_MSGVAL_BIT + 1UL) * 4U))))
#define CAN1_BITBANDING_MSG2VAL_MSGVAL19    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2VAL_OFFSET) * 32U) + ((CAN_MSG2VAL_R_MSGVAL_BIT + 2UL) * 4U))))
#define CAN1_BITBANDING_MSG2VAL_MSGVAL20    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2VAL_OFFSET) * 32U) + ((CAN_MSG2VAL_R_MSGVAL_BIT + 3UL) * 4U))))
#define CAN1_BITBANDING_MSG2VAL_MSGVAL21    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2VAL_OFFSET) * 32U) + ((CAN_MSG2VAL_R_MSGVAL_BIT + 4UL) * 4U))))
#define CAN1_BITBANDING_MSG2VAL_MSGVAL22    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2VAL_OFFSET) * 32U) + ((CAN_MSG2VAL_R_MSGVAL_BIT + 5UL) * 4U))))
#define CAN1_BITBANDING_MSG2VAL_MSGVAL23    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2VAL_OFFSET) * 32U) + ((CAN_MSG2VAL_R_MSGVAL_BIT + 6UL) * 4U))))
#define CAN1_BITBANDING_MSG2VAL_MSGVAL24    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2VAL_OFFSET) * 32U) + ((CAN_MSG2VAL_R_MSGVAL_BIT + 7UL) * 4U))))
#define CAN1_BITBANDING_MSG2VAL_MSGVAL25    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2VAL_OFFSET) * 32U) + ((CAN_MSG2VAL_R_MSGVAL_BIT + 8UL) * 4U))))
#define CAN1_BITBANDING_MSG2VAL_MSGVAL26    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2VAL_OFFSET) * 32U) + ((CAN_MSG2VAL_R_MSGVAL_BIT + 9UL) * 4U))))
#define CAN1_BITBANDING_MSG2VAL_MSGVAL27    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2VAL_OFFSET) * 32U) + ((CAN_MSG2VAL_R_MSGVAL_BIT + 10UL) * 4U))))
#define CAN1_BITBANDING_MSG2VAL_MSGVAL28    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2VAL_OFFSET) * 32U) + ((CAN_MSG2VAL_R_MSGVAL_BIT + 11UL) * 4U))))
#define CAN1_BITBANDING_MSG2VAL_MSGVAL29    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2VAL_OFFSET) * 32U) + ((CAN_MSG2VAL_R_MSGVAL_BIT + 12UL) * 4U))))
#define CAN1_BITBANDING_MSG2VAL_MSGVAL30    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2VAL_OFFSET) * 32U) + ((CAN_MSG2VAL_R_MSGVAL_BIT + 13UL) * 4U))))
#define CAN1_BITBANDING_MSG2VAL_MSGVAL31    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2VAL_OFFSET) * 32U) + ((CAN_MSG2VAL_R_MSGVAL_BIT + 14UL) * 4U))))
#define CAN1_BITBANDING_MSG2VAL_MSGVAL32    (*((volatile const uint32_t *) (CAN_BITBANDING_BASE + ((CAN1_OFFSET + CAN_MSG2VAL_OFFSET) * 32U) + ((CAN_MSG2VAL_R_MSGVAL_BIT + 15UL) * 4U))))

#endif /* XDRIVER_MCU_CAN_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_BITBANDING_XHEADER_CAN_REGISTERPERIPHERAL_BITBANDING_MODULE0_H_ */
