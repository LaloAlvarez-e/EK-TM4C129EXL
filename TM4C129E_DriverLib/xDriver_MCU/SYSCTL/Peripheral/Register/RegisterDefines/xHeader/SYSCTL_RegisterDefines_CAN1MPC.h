/*
 * SYSCTL_RegisterDefines_CAN1MPC.h
 *
 *  Created on: 13 jun. 2021
 *      Author: InDeviceMex
 */

#ifndef XDRIVER_MCU_SYSCTL_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_SYSCTL_REGISTERDEFINES_CAN1MPC_H_
#define XDRIVER_MCU_SYSCTL_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_SYSCTL_REGISTERDEFINES_CAN1MPC_H_

#include <xDriver_MCU/Common/xHeader/MCU_Variables.h>

/******************************************************************************************
************************************ 39 CAN1MPC *********************************************
******************************************************************************************/
/*--------*/
#define SYSCTL_CAN1MPC_R_PWRCTL_MASK    ((uint32_t) 0x00000003UL)
#define SYSCTL_CAN1MPC_R_PWRCTL_BIT    (0UL)
#define SYSCTL_CAN1MPC_R_PWRCTL_OFF    ((uint32_t) 0x00000000UL)
#define SYSCTL_CAN1MPC_R_PWRCTL_ON    ((uint32_t) 0x00000003UL)

#define SYSCTL_CAN1MPC_PWRCTL_MASK    ((uint32_t) 0x00000003UL)
#define SYSCTL_CAN1MPC_PWRCTL_OFF    ((uint32_t) 0x00000000UL)
#define SYSCTL_CAN1MPC_PWRCTL_ON    ((uint32_t) 0x00000003UL)
/*--------*/

#endif /* XDRIVER_MCU_SYSCTL_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_SYSCTL_REGISTERDEFINES_CAN1MPC_H_ */
