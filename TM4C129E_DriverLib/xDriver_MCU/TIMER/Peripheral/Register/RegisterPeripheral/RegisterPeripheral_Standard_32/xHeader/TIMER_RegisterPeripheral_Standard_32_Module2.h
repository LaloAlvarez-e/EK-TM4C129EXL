/**
 *
 * @file TIMER_RegisterPeripheral_Standard_32_Module2.h
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
 * @verbatim 9 jul. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 9 jul. 2020     vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_REGISTER_TIMER_REGISTERPERIPHERAL_TIMER_REGISTERPERIPHERAL_STANDARD_32_TIMER_REGISTERPERIPHERAL_STANDARD_32_MODULE2_H_
#define XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_REGISTER_TIMER_REGISTERPERIPHERAL_TIMER_REGISTERPERIPHERAL_STANDARD_32_TIMER_REGISTERPERIPHERAL_STANDARD_32_MODULE2_H_

#include <xDriver_MCU/TIMER/Peripheral/Register/RegisterAddress/TIMER_RegisterAddress.h>
#include <xDriver_MCU/TIMER/Peripheral/Struct/StructPeripheral/xHeader/TIMER_StructPeripheral_Standard.h>

#define GPTM2    (((GPTM_t*) (GPTM2_BASE)))

/******************************************************************************************
************************************ 1 CFG *********************************************
******************************************************************************************/
#define GPTM2_CFG    ((GPTMCFG_t*) (GPTM2_BASE + GPTM_CFG_OFFSET))
#define GPTM2_CFG_R    (*((volatile uint32_t*) (GPTM2_BASE + GPTM_CFG_OFFSET)))

/******************************************************************************************
************************************ 2 TAMR *********************************************
******************************************************************************************/
#define GPTM2_TAMR    ((GPTMTAMR_t*) (GPTM2_BASE + GPTM_TAMR_OFFSET))
#define GPTM2_TAMR_R    (*((volatile uint32_t*) (GPTM2_BASE + GPTM_TAMR_OFFSET)))

/******************************************************************************************
************************************ 3 TBMR *********************************************
******************************************************************************************/
#define GPTM2_TBMR    ((GPTMTBMR_t*) (GPTM2_BASE + GPTM_TBMR_OFFSET))
#define GPTM2_TBMR_R    (*((volatile uint32_t*) (GPTM2_BASE + GPTM_TBMR_OFFSET)))


/******************************************************************************************
************************************ 4 CTL *********************************************
******************************************************************************************/
#define GPTM2_GPTMCTL    ((GPTMCTL_t*) (GPTM2_BASE + GPTM_CTL_OFFSET))
#define GPTM2_GPTMCTL_R    (*((volatile uint32_t*) (GPTM2_BASE + GPTM_CTL_OFFSET)))

/******************************************************************************************
************************************ 5 SYNC *********************************************
******************************************************************************************/
#define GPTM2_SYNC    ((GPTMSYNC_t*) (GPTM2_BASE + GPTM_SYNC_OFFSET))
#define GPTM2_SYNC_R    (*((volatile uint32_t*) (GPTM2_BASE + GPTM_SYNC_OFFSET)))

/******************************************************************************************
************************************ 6 IMR *********************************************
******************************************************************************************/
#define GPTM2_IMR    ((GPTMIMR_t*) (GPTM2_BASE + GPTM_IMR_OFFSET))
#define GPTM2_IMR_R    (*((volatile uint32_t*) (GPTM2_BASE + GPTM_IMR_OFFSET)))

/******************************************************************************************
************************************ 7 RIS *********************************************
******************************************************************************************/
#define GPTM2_RIS    ((GPTMRIS_t*) (GPTM2_BASE + GPTM_RIS_OFFSET))
#define GPTM2_RIS_R    (*((volatile const uint32_t*) (GPTM2_BASE + GPTM_RIS_OFFSET)))

/******************************************************************************************
************************************ 8 MIS *********************************************
******************************************************************************************/
#define GPTM2_MIS    ((GPTMMIS_t*) (GPTM2_BASE + GPTM_MIS_OFFSET))
#define GPTM2_MIS_R    (*((volatile const uint32_t*) (GPTM2_BASE + GPTM_MIS_OFFSET)))

/******************************************************************************************
************************************ 9 ICR *********************************************
******************************************************************************************/
#define GPTM2_ICR    ((GPTMICR_t*) (GPTM2_BASE + GPTM_ICR_OFFSET))
#define GPTM2_ICR_R    (*((volatile uint32_t*) (GPTM2_BASE + GPTM_ICR_OFFSET)))

/******************************************************************************************
************************************ 10 TAILR *********************************************
******************************************************************************************/
#define GPTM2_TAILR    ((GPTMTAILR_t*) (GPTM2_BASE + GPTM_TAILR_OFFSET))
#define GPTM2_TAILR_R    (*((volatile uint32_t*) (GPTM2_BASE + GPTM_TAILR_OFFSET)))

/******************************************************************************************
************************************ 11 TBILR *********************************************
******************************************************************************************/
#define GPTM2_TBILR    ((GPTMTBILR_t*) (GPTM2_BASE + GPTM_TBILR_OFFSET))
#define GPTM2_TBILR_R    (*((volatile uint32_t*) (GPTM2_BASE + GPTM_TBILR_OFFSET)))

/******************************************************************************************
************************************ 12 TAMATCHR *********************************************
******************************************************************************************/
#define GPTM2_TAMATCHR    ((GPTMTAMATCHR_t*) (GPTM2_BASE + GPTM_TAMATCHR_OFFSET))
#define GPTM2_TAMATCHR_R    (*((volatile uint32_t*) (GPTM2_BASE + GPTM_TAMATCHR_OFFSET)))

/******************************************************************************************
************************************ 13 TBMATCHR *********************************************
******************************************************************************************/
#define GPTM2_TBMATCHR    ((GPTMTBMATCHR_t*) (GPTM2_BASE + GPTM_TBMATCHR_OFFSET))
#define GPTM2_TBMATCHR_R    (*((volatile uint32_t*) (GPTM2_BASE + GPTM_TBMATCHR_OFFSET)))

/******************************************************************************************
************************************ 14 TAPR *********************************************
******************************************************************************************/
#define GPTM2_TAPR    ((GPTMTAPR_t*) (GPTM2_BASE + GPTM_TAPR_OFFSET))
#define GPTM2_TAPR_R    (*((volatile uint32_t*) (GPTM2_BASE + GPTM_TAPR_OFFSET)))

/******************************************************************************************
************************************ 15 TBPR *********************************************
******************************************************************************************/
#define GPTM2_TBPR    ((GPTMTBPR_t*) (GPTM2_BASE + GPTM_TBPR_OFFSET))
#define GPTM2_TBPR_R    (*((volatile uint32_t*) (GPTM2_BASE + GPTM_TBPR_OFFSET)))

/******************************************************************************************
************************************ 16 TAPMR *********************************************
******************************************************************************************/
#define GPTM2_TAPMR    ((GPTMTAPMR_t*) (GPTM2_BASE + GPTM_TAPMR_OFFSET))
#define GPTM2_TAPMR_R    (*((volatile uint32_t*) (GPTM2_BASE + GPTM_TAPMR_OFFSET)))

/******************************************************************************************
************************************ 17 TBPMR *********************************************
******************************************************************************************/
#define GPTM2_TBPMR    ((GPTMTBPMR_t*) (GPTM2_BASE + GPTM_TBPMR_OFFSET))
#define GPTM2_TBPMR_R    (*((volatile uint32_t*) (GPTM2_BASE + GPTM_TBPMR_OFFSET)))

/******************************************************************************************
************************************ 18 TAR *********************************************
******************************************************************************************/
#define GPTM2_TAR    ((GPTMTAR_t*) (GPTM2_BASE + GPTM_TAR_OFFSET))
#define GPTM2_TAR_R    (*((volatile uint32_t*) (GPTM2_BASE + GPTM_TAR_OFFSET)))

/******************************************************************************************
************************************ 19 TBR *********************************************
******************************************************************************************/
#define GPTM2_TBR    ((GPTMTBR_t*) (GPTM2_BASE + GPTM_TBR_OFFSET))
#define GPTM2_TBR_R    (*((volatile uint32_t*) (GPTM2_BASE + GPTM_TBR_OFFSET)))

/******************************************************************************************
************************************ 20 TAV *********************************************
******************************************************************************************/
#define GPTM2_TAV    ((GPTMTAV_t*) (GPTM2_BASE + GPTM_TAV_OFFSET))
#define GPTM2_TAV_R    (*((volatile uint32_t*) (GPTM2_BASE + GPTM_TAV_OFFSET)))

/******************************************************************************************
************************************ 21 TBV *********************************************
******************************************************************************************/
#define GPTM2_TBV    ((GPTMTBV_t*) (GPTM2_BASE + GPTM_TBV_OFFSET))
#define GPTM2_TBV_R    (*((volatile uint32_t*) (GPTM2_BASE + GPTM_TBV_OFFSET)))

/******************************************************************************************
************************************ 22 RTCPD *********************************************
******************************************************************************************/
#define GPTM2_RTCPD    ((GPTMRTCPD_t*) (GPTM2_BASE + GPTM_RTCPD_OFFSET))
#define GPTM2_RTCPD_R    (*((volatile uint32_t*) (GPTM2_BASE + GPTM_RTCPD_OFFSET)))

/******************************************************************************************
************************************ 23 TAPS *********************************************
******************************************************************************************/
#define GPTM2_TAPS    ((GPTMTAPS_t*) (GPTM2_BASE + GPTM_TAPS_OFFSET))
#define GPTM2_TAPS_R    (*((volatile uint32_t*) (GPTM2_BASE + GPTM_TAPS_OFFSET)))

/******************************************************************************************
************************************ 24 TBPS *********************************************
******************************************************************************************/
#define GPTM2_TBPS    ((GPTMTBPS_t*) (GPTM2_BASE + GPTM_TBPS_OFFSET))
#define GPTM2_TBPS_R    (*((volatile uint32_t*) (GPTM2_BASE + GPTM_TBPS_OFFSET)))

/******************************************************************************************
************************************ 25 DMAEV *********************************************
******************************************************************************************/
#define GPTM2_DMAEV    ((GPTMDMAEV_t*) (GPTM2_BASE + GPTM_DMAEV_OFFSET))
#define GPTM2_DMAEV_R    (*((volatile uint32_t*) (GPTM2_BASE + GPTM_DMAEV_OFFSET)))

/******************************************************************************************
************************************ 26 ADCEV *********************************************
******************************************************************************************/
#define GPTM2_ADCEV    ((GPTMADCEV_t*) (GPTM2_BASE + GPTM_ADCEV_OFFSET))
#define GPTM2_ADCEV_R    (*((volatile uint32_t*) (GPTM2_BASE + GPTM_ADCEV_OFFSET)))

/******************************************************************************************
************************************ 27 PP *********************************************
******************************************************************************************/
#define GPTM2_PP    ((GPTMPP_t*) (GPTM2_BASE + GPTM_PP_OFFSET))
#define GPTM2_PP_R    (*((volatile uint32_t*) (GPTM2_BASE + GPTM_PP_OFFSET)))

/******************************************************************************************
************************************ 28 CC *********************************************
******************************************************************************************/
#define GPTM2_CC    ((GPTMCC_t*) (GPTM2_BASE + GPTM_CC_OFFSET))
#define GPTM2_CC_R    (*((volatile uint32_t*) (GPTM2_BASE + GPTM_CC_OFFSET)))

#endif /* XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_REGISTER_TIMER_REGISTERPERIPHERAL_TIMER_REGISTERPERIPHERAL_STANDARD_32_TIMER_REGISTERPERIPHERAL_STANDARD_32_MODULE2_H_ */
