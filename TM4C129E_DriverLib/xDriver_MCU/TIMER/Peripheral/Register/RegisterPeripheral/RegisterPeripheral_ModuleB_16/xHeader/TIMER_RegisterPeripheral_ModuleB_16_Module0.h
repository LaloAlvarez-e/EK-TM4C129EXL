/**
 *
 * @file TIMER_RegisterPeripheral_ModuleB_16_Module0.h
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

#ifndef XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_REGISTER_TIMER_REGISTERPERIPHERAL_TIMER_REGISTERPERIPHERAL_MODULEB_16_TIMER_REGISTERPERIPHERAL_MODULEB_16_MODULE0_H_
#define XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_REGISTER_TIMER_REGISTERPERIPHERAL_TIMER_REGISTERPERIPHERAL_MODULEB_16_TIMER_REGISTERPERIPHERAL_MODULEB_16_MODULE0_H_

#include <xDriver_MCU/TIMER/Peripheral/Register/RegisterAddress/TIMER_RegisterAddress.h>
#include <xDriver_MCU/TIMER/Peripheral/Struct/StructPeripheral/xHeader/TIMER_StructPeripheral_ModuleB_16.h>

#define GPTM0_TB    (((GPTM_TB_TypeDef*) (GPTM0_BASE)))

/******************************************************************************************
************************************ 3 TBMR *********************************************
******************************************************************************************/
#define GPTM0_TB_TnMR    ((TB_GPTMMR_TypeDef*) (GPTM0_BASE + GPTM_TB_TnMR_OFFSET))
#define GPTM0_TB_TnMR_R    (*((volatile uint32_t*) (GPTM0_BASE + GPTM_TB_TnMR_OFFSET)))

/******************************************************************************************
************************************ 4 CTL *********************************************
******************************************************************************************/
#define GPTM0_TB_TnCTL    ((TB_GPTMCTL_TypeDef*) (GPTM0_BASE + GPTM_TB_TnCTL_OFFSET))
#define GPTM0_TB_TnCTL_R    (*((volatile uint32_t*) (GPTM0_BASE + GPTM_TB_TnCTL_OFFSET)))

/******************************************************************************************
************************************ 6 IMR *********************************************
******************************************************************************************/
#define GPTM0_TB_TnIMR    ((TB_GPTMIMR_TypeDef*) (GPTM0_BASE + GPTM_TB_TnIMR_OFFSET))
#define GPTM0_TB_TnIMR_R    (*((volatile uint32_t*) (GPTM0_BASE + GPTM_TB_TnIMR_OFFSET)))

/******************************************************************************************
************************************ 7 RIS *********************************************
******************************************************************************************/
#define GPTM0_TB_TnRIS    ((TB_GPTMRIS_TypeDef*) (GPTM0_BASE + GPTM_TB_TnRIS_OFFSET))
#define GPTM0_TB_TnRIS_R    (*((volatile const uint32_t*) (GPTM0_BASE + GPTM_TB_TnRIS_OFFSET)))

/******************************************************************************************
************************************ 8 MIS *********************************************
******************************************************************************************/
#define GPTM0_TB_TnMIS    ((TB_GPTMMIS_TypeDef*) (GPTM0_BASE + GPTM_TB_TnMIS_OFFSET))
#define GPTM0_TB_TnMIS_R    (*((volatile const uint32_t*) (GPTM0_BASE + GPTM_TB_TnMIS_OFFSET)))

/******************************************************************************************
************************************ 9 ICR *********************************************
******************************************************************************************/
#define GPTM0_TB_TnICR    ((TB_GPTMICR_TypeDef*) (GPTM0_BASE + GPTM_TB_TnICR_OFFSET))
#define GPTM0_TB_TnICR_R    (*((volatile uint32_t*) (GPTM0_BASE + GPTM_TB_TnICR_OFFSET)))

/******************************************************************************************
************************************ 11 TBILR *********************************************
******************************************************************************************/
#define GPTM0_TB_TnILR    ((TB_GPTMILR_TypeDef*) (GPTM0_BASE + GPTM_TB_TnILR_OFFSET))
#define GPTM0_TB_TnILR_R    (*((volatile uint32_t*) (GPTM0_BASE + GPTM_TB_TnILR_OFFSET)))

/******************************************************************************************
************************************ 13 TBMATCHR *********************************************
******************************************************************************************/
#define GPTM0_TB_TnMATCHR    ((TB_GPTMMATCHR_TypeDef*) (GPTM0_BASE + GPTM_TB_TnMATCHR_OFFSET))
#define GPTM0_TB_TnMATCHR_R    (*((volatile uint32_t*) (GPTM0_BASE + GPTM_TB_TnMATCHR_OFFSET)))

/******************************************************************************************
************************************ 15 TBPR *********************************************
******************************************************************************************/
#define GPTM0_TB_TnPR    ((TB_GPTMPR_TypeDef*) (GPTM0_BASE + GPTM_TB_TnPR_OFFSET))
#define GPTM0_TB_TnPR_R    (*((volatile uint32_t*) (GPTM0_BASE + GPTM_TB_TnPR_OFFSET)))

/******************************************************************************************
************************************ 17 TBPMR *********************************************
******************************************************************************************/
#define GPTM0_TB_TnPMR    ((TB_GPTMPMR_TypeDef*) (GPTM0_BASE + GPTM_TB_TnPMR_OFFSET))
#define GPTM0_TB_TnPMR_R    (*((volatile uint32_t*) (GPTM0_BASE + GPTM_TB_TnPMR_OFFSET)))

/******************************************************************************************
************************************ 19 TBR *********************************************
******************************************************************************************/
#define GPTM0_TB_TnR    ((TB_GPTMR_TypeDef*) (GPTM0_BASE + GPTM_TB_TnR_OFFSET))
#define GPTM0_TB_TnR_R    (*((volatile uint32_t*) (GPTM0_BASE + GPTM_TB_TnR_OFFSET)))

/******************************************************************************************
************************************ 21 TBV *********************************************
******************************************************************************************/
#define GPTM0_TB_TnV    ((TB_GPTMV_TypeDef*) (GPTM0_BASE + GPTM_TB_TnV_OFFSET))
#define GPTM0_TB_TnV_R    (*((volatile uint32_t*) (GPTM0_BASE + GPTM_TB_TnV_OFFSET)))

/******************************************************************************************
************************************ 24 TBPS *********************************************
******************************************************************************************/
#define GPTM0_TB_TnPS    ((TB_GPTMPS_TypeDef*) (GPTM0_BASE + GPTM_TB_TnPS_OFFSET))
#define GPTM0_TB_TnPS_R    (*((volatile uint32_t*) (GPTM0_BASE + GPTM_TB_TnPS_OFFSET)))

/******************************************************************************************
************************************ 25 DMAEV *********************************************
******************************************************************************************/
#define GPTM0_TB_TnDMAEV    ((TB_GPTMDMAEV_TypeDef*) (GPTM0_BASE + GPTM_TB_TnDMAEV_OFFSET))
#define GPTM0_TB_TnDMAEV_R    (*((volatile uint32_t*) (GPTM0_BASE + GPTM_TB_TnDMAEV_OFFSET)))

/******************************************************************************************
************************************ 26 ADCEV *********************************************
******************************************************************************************/
#define GPTM0_TB_TnADCEV    ((TB_GPTMADCEV_TypeDef*) (GPTM0_BASE + GPTM_TB_TnADCEV_OFFSET))
#define GPTM0_TB_TnADCEV_R    (*((volatile uint32_t*) (GPTM0_BASE + GPTM_TB_TnADCEV_OFFSET)))

#endif /* XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_REGISTER_TIMER_REGISTERPERIPHERAL_TIMER_REGISTERPERIPHERAL_MODULEB_16_TIMER_REGISTERPERIPHERAL_MODULEB_16_MODULE0_H_ */
