/**
 *
 * @file TIMER_RegisterPeripheral_ModuleW_32_Module6.h
 * @copyright
 * @verbatim InDeviceMex 2021 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 10 jul. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 10 jul. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_TIMER_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_REGISTERPERIPHERAL_MODULEW_32_XHEADER_TIMER_REGISTERPERIPHERAL_MODULEW_32_MODULE6_H_
#define XDRIVER_MCU_TIMER_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_REGISTERPERIPHERAL_MODULEW_32_XHEADER_TIMER_REGISTERPERIPHERAL_MODULEW_32_MODULE6_H_

#include <xDriver_MCU/TIMER/Peripheral/Register/RegisterAddress/TIMER_RegisterAddress.h>
#include <xDriver_MCU/TIMER/Peripheral/Struct/StructPeripheral/xHeader/TIMER_StructPeripheral_ModuleW_32.h>

#define GPTM6_TW    (((GPTM_TW_TypeDef*) (GPTM6_BASE)))

/******************************************************************************************
************************************ 2 TAMR *********************************************
******************************************************************************************/
#define GPTM6_TW_TnMR    ((TW_GPTMMR_TypeDef*) (GPTM6_BASE + GPTM_TW_TnMR_OFFSET))
#define GPTM6_TW_TnMR_R    (*((volatile uint32_t*) (GPTM6_BASE + GPTM_TW_TnMR_OFFSET)))

/******************************************************************************************
************************************ 4 CTL *********************************************
******************************************************************************************/
#define GPTM6_TW_TnCTL    ((TW_GPTMCTL_TypeDef*) (GPTM6_BASE + GPTM_TW_TnCTL_OFFSET))
#define GPTM6_TW_TnCTL_R    (*((volatile uint32_t*) (GPTM6_BASE + GPTM_TW_TnCTL_OFFSET)))

/******************************************************************************************
************************************ 6 IMR *********************************************
******************************************************************************************/
#define GPTM6_TW_TnIMR    ((TW_GPTMIMR_TypeDef*) (GPTM6_BASE + GPTM_TW_TnIMR_OFFSET))
#define GPTM6_TW_TnIMR_R    (*((volatile uint32_t*) (GPTM6_BASE + GPTM_TW_TnIMR_OFFSET)))

/******************************************************************************************
************************************ 7 RIS *********************************************
******************************************************************************************/
#define GPTM6_TW_TnRIS    ((TW_GPTMRIS_TypeDef*) (GPTM6_BASE + GPTM_TW_TnRIS_OFFSET))
#define GPTM6_TW_TnRIS_R    (*((volatile const uint32_t*) (GPTM6_BASE + GPTM_TW_TnRIS_OFFSET)))

/******************************************************************************************
************************************ 8 MIS *********************************************
******************************************************************************************/
#define GPTM6_TW_TnMIS    ((TW_GPTMMIS_TypeDef*) (GPTM6_BASE + GPTM_TW_TnMIS_OFFSET))
#define GPTM6_TW_TnMIS_R    (*((volatile const uint32_t*) (GPTM6_BASE + GPTM_TW_TnMIS_OFFSET)))

/******************************************************************************************
************************************ 9 ICR *********************************************
******************************************************************************************/
#define GPTM6_TW_TnICR    ((TW_GPTMICR_TypeDef*) (GPTM6_BASE + GPTM_TW_TnICR_OFFSET))
#define GPTM6_TW_TnICR_R    (*((volatile uint32_t*) (GPTM6_BASE + GPTM_TW_TnICR_OFFSET)))

/******************************************************************************************
************************************ 10 TAILR *********************************************
******************************************************************************************/
#define GPTM6_TW_TnILR    ((TW_GPTMILR_TypeDef*) (GPTM6_BASE + GPTM_TW_TnILR_OFFSET))
#define GPTM6_TW_TnILR_R    (*((volatile uint32_t*) (GPTM6_BASE + GPTM_TW_TnILR_OFFSET)))

/******************************************************************************************
************************************ 12 TAMATCHR *********************************************
******************************************************************************************/
#define GPTM6_TW_TnMATCHR    ((TW_GPTMMATCHR_TypeDef*) (GPTM6_BASE + GPTM_TW_TnMATCHR_OFFSET))
#define GPTM6_TW_TnMATCHR_R    (*((volatile uint32_t*) (GPTM6_BASE + GPTM_TW_TnMATCHR_OFFSET)))

/******************************************************************************************
************************************ 18 TAR *********************************************
******************************************************************************************/
#define GPTM6_TW_TnR    ((TW_GPTMR_TypeDef*) (GPTM6_BASE + GPTM_TW_TnR_OFFSET))
#define GPTM6_TW_TnR_R    (*((volatile uint32_t*) (GPTM6_BASE + GPTM_TW_TnR_OFFSET)))

/******************************************************************************************
************************************ 20 TAV *********************************************
******************************************************************************************/
#define GPTM6_TW_TnV    ((TW_GPTMV_TypeDef*) (GPTM6_BASE + GPTM_TW_TnV_OFFSET))
#define GPTM6_TW_TnV_R    (*((volatile uint32_t*) (GPTM6_BASE + GPTM_TW_TnV_OFFSET)))

/******************************************************************************************
************************************ 22 RTCPD *********************************************
******************************************************************************************/
#define GPTM6_TW_RTCPD    ((TW_GPTMRTCPD_TypeDef*) (GPTM6_BASE + GPTM_TW_RTCPD_OFFSET))
#define GPTM6_TW_RTCPD_R    (*((volatile uint32_t*) (GPTM6_BASE + GPTM_TW_RTCPD_OFFSET)))

/******************************************************************************************
************************************ 25 DMAEV *********************************************
******************************************************************************************/
#define GPTM6_TW_TnDMAEV    ((TW_GPTMDMAEV_TypeDef*) (GPTM6_BASE + GPTM_TW_TnDMAEV_OFFSET))
#define GPTM6_TW_TnDMAEV_R    (*((volatile uint32_t*) (GPTM6_BASE + GPTM_TW_TnDMAEV_OFFSET)))

/******************************************************************************************
************************************ 26 ADCEV *********************************************
******************************************************************************************/
#define GPTM6_TW_TnADCEV    ((TW_GPTMADCEV_TypeDef*) (GPTM6_BASE + GPTM_TW_TnADCEV_OFFSET))
#define GPTM6_TW_TnADCEV_R    (*((volatile uint32_t*) (GPTM6_BASE + GPTM_TW_TnADCEV_OFFSET)))

#endif /* XDRIVER_MCU_TIMER_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_REGISTERPERIPHERAL_MODULEW_32_XHEADER_TIMER_REGISTERPERIPHERAL_MODULEW_32_MODULE6_H_ */
