/**
 *
 * @file TIMER_RegisterPeripheral_Control_32_Module3.h
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
 * @verbatim 8 jul. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 8 jul. 2020     vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_REGISTER_TIMER_REGISTERPERIPHERAL_TIMER_REGISTERPERIPHERAL_CONTROL_32_TIMER_REGISTERPERIPHERAL_CONTROL_32_MODULE3_H_
#define XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_REGISTER_TIMER_REGISTERPERIPHERAL_TIMER_REGISTERPERIPHERAL_CONTROL_32_TIMER_REGISTERPERIPHERAL_CONTROL_32_MODULE3_H_

#include <xDriver_MCU/TIMER/Peripheral/Register/RegisterAddress/TIMER_RegisterAddress.h>
#include <xDriver_MCU/TIMER/Peripheral/Struct/StructPeripheral/xHeader/TIMER_StructPeripheral_Control_32.h>

#define GPTM3_CTL    (((GPTM_CTL_t*) (GPTM3_BASE)))

/******************************************************************************************
************************************ 1 CFG *********************************************
******************************************************************************************/
#define GPTM3_CTL_CFG    ((GPTMCFG_t*) (GPTM3_BASE + GPTM_CTL_CFG_OFFSET))
#define GPTM3_CTL_CFG_R    (*((volatile uint32_t*) (GPTM3_BASE + GPTM_CTL_CFG_OFFSET)))

/******************************************************************************************
************************************ 5 SYNC *********************************************
******************************************************************************************/

#define GPTM3_CTL_SYNC    ((GPTMSYNC_t*) (GPTM3_BASE + GPTM_CTL_SYNC_OFFSET))
#define GPTM3_CTL_SYNC_R    (*((volatile uint32_t*) (GPTM3_BASE + GPTM_CTL_SYNC_OFFSET)))

/******************************************************************************************
************************************ 27 PP *********************************************
******************************************************************************************/

#define GPTM3_CTL_PP    ((GPTMPP_t*) (GPTM3_BASE + GPTM_CTL_PP_OFFSET))
#define GPTM3_CTL_PP_R    (*((volatile uint32_t*) (GPTM3_BASE + GPTM_CTL_PP_OFFSET)))

/******************************************************************************************
************************************ 28 CC *********************************************
******************************************************************************************/

#define GPTM3_CTL_CC    ((GPTMCC_t*) (GPTM3_BASE + GPTM_CTL_CC_OFFSET))
#define GPTM3_CTL_CC_R    (*((volatile uint32_t*) (GPTM3_BASE + GPTM_CTL_CC_OFFSET)))

#endif /* XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_REGISTER_TIMER_REGISTERPERIPHERAL_TIMER_REGISTERPERIPHERAL_CONTROL_32_TIMER_REGISTERPERIPHERAL_CONTROL_32_MODULE3_H_ */
