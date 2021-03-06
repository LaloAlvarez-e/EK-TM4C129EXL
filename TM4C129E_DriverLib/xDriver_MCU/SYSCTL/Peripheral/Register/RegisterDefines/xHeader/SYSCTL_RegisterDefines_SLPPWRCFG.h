/*
 * SYSCTL_RegisterDefines_SLPPWRCFG.h
 *
 *  Created on: 13 jun. 2021
 *      Author: InDeviceMex
 */

#ifndef XDRIVER_MCU_SYSCTL_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_SYSCTL_REGISTERDEFINES_SLPPWRCFG_H_
#define XDRIVER_MCU_SYSCTL_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_SYSCTL_REGISTERDEFINES_SLPPWRCFG_H_

#include <xDriver_MCU/Common/xHeader/MCU_Variables.h>

/******************************************************************************************
************************************22 SLPPWRCFG *********************************************
******************************************************************************************/
/*--------*/
#define SYSCTL_SLPPWRCFG_R_SRAMPM_MASK    ((uint32_t) 0x00000003UL)
#define SYSCTL_SLPPWRCFG_R_SRAMPM_BIT    (0UL)
#define SYSCTL_SLPPWRCFG_R_SRAMPM_ACTIVE    ((uint32_t) 0x00000000UL)
#define SYSCTL_SLPPWRCFG_R_SRAMPM_STANDBY    ((uint32_t) 0x00000001UL)
#define SYSCTL_SLPPWRCFG_R_SRAMPM_LOWPOWER    ((uint32_t) 0x00000003UL)

#define SYSCTL_SLPPWRCFG_SRAMPM_MASK    ((uint32_t) 0x00000003UL)
#define SYSCTL_SLPPWRCFG_SRAMPM_ACTIVE    ((uint32_t) 0x00000000UL)
#define SYSCTL_SLPPWRCFG_SRAMPM_STANDBY    ((uint32_t) 0x00000001UL)
#define SYSCTL_SLPPWRCFG_SRAMPM_LOWPOWER    ((uint32_t) 0x00000003UL)
/*--------*/

/*--------*/
#define SYSCTL_SLPPWRCFG_R_FLASHPM_MASK    ((uint32_t) 0x00000030UL)
#define SYSCTL_SLPPWRCFG_R_FLASHPM_BIT    (2UL)
#define SYSCTL_SLPPWRCFG_R_FLASHPM_ACTIVE    ((uint32_t) 0x00000000UL)
#define SYSCTL_SLPPWRCFG_R_FLASHPM_LOWPOWER    ((uint32_t) 0x00000020UL)

#define SYSCTL_SLPPWRCFG_FLASHPM_MASK    ((uint32_t) 0x00000003UL)
#define SYSCTL_SLPPWRCFG_FLASHPM_ACTIVE    ((uint32_t) 0x00000000UL)
#define SYSCTL_SLPPWRCFG_FLASHPM_LOWPOWER    ((uint32_t) 0x00000002UL)
/*--------*/

#endif /* XDRIVER_MCU_SYSCTL_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_SYSCTL_REGISTERDEFINES_SLPPWRCFG_H_ */
