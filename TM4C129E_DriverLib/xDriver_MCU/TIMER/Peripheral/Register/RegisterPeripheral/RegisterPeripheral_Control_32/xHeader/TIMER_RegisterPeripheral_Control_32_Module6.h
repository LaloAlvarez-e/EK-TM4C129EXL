/**
 *
 * @file TIMER_RegisterPeripheral_Control_32_Module6.h
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

#ifndef XDRIVER_MCU_TIMER_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_REGISTERPERIPHERAL_CONTROL_32_XHEADER_TIMER_REGISTERPERIPHERAL_CONTROL_32_MODULE6_H_
#define XDRIVER_MCU_TIMER_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_REGISTERPERIPHERAL_CONTROL_32_XHEADER_TIMER_REGISTERPERIPHERAL_CONTROL_32_MODULE6_H_

#include <xDriver_MCU/TIMER/Peripheral/Register/RegisterAddress/TIMER_RegisterAddress.h>
#include <xDriver_MCU/TIMER/Peripheral/Struct/StructPeripheral/xHeader/TIMER_StructPeripheral_Control_32.h>

#define GPTM6_CTL    (((GPTM_CTL_t*) (GPTM6_BASE)))

/******************************************************************************************
************************************ 1 CFG *********************************************
******************************************************************************************/
#define GPTM6_CTL_CFG    ((GPTMCFG_t*) (GPTM6_BASE + GPTM_CTL_CFG_OFFSET))
#define GPTM6_CTL_CFG_R    (*((volatile uint32_t*) (GPTM6_BASE + GPTM_CTL_CFG_OFFSET)))

/******************************************************************************************
************************************ 5 SYNC *********************************************
******************************************************************************************/

#define GPTM6_CTL_SYNC    ((GPTMSYNC_t*) (GPTM6_BASE + GPTM_CTL_SYNC_OFFSET))
#define GPTM6_CTL_SYNC_R    (*((volatile uint32_t*) (GPTM6_BASE + GPTM_CTL_SYNC_OFFSET)))

/******************************************************************************************
************************************ 27 PP *********************************************
******************************************************************************************/

#define GPTM6_CTL_PP    ((GPTMPP_t*) (GPTM6_BASE + GPTM_CTL_PP_OFFSET))
#define GPTM6_CTL_PP_R    (*((volatile uint32_t*) (GPTM6_BASE + GPTM_CTL_PP_OFFSET)))

/******************************************************************************************
************************************ 28 CC *********************************************
******************************************************************************************/

#define GPTM6_CTL_CC    ((GPTMCC_t*) (GPTM6_BASE + GPTM_CTL_CC_OFFSET))
#define GPTM6_CTL_CC_R    (*((volatile uint32_t*) (GPTM6_BASE + GPTM_CTL_CC_OFFSET)))

#endif /* XDRIVER_MCU_TIMER_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_REGISTERPERIPHERAL_CONTROL_32_XHEADER_TIMER_REGISTERPERIPHERAL_CONTROL_32_MODULE6_H_ */
