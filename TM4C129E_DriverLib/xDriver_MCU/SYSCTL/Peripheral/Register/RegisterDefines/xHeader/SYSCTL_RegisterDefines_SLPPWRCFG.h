/*
 * SYSCTL_RegisterDefines_SLPPWRCFG.h
 *
 *  Created on: 13 jun. 2021
 *      Author: InDeviceMex
 */

#ifndef XDRIVER_MCU_SYSCTL_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_SYSCTL_REGISTERDEFINES_SLPPWRCFG_H_
#define XDRIVER_MCU_SYSCTL_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_SYSCTL_REGISTERDEFINES_SLPPWRCFG_H_

#include <xDriver_MCU/SYSCTL/Peripheral/xHeader/SYSCTL_Enum.h>

/******************************************************************************************
************************************22 SLPPWRCFG *********************************************
******************************************************************************************/
/*--------*/
#define SLPPWR_CFG_R_SRAM_PM_MASK    ((UBase_t) 0x00000003UL)
#define SLPPWR_CFG_R_SRAM_PM_BIT    (0UL)
#define SLPPWR_CFG_R_SRAM_PM_ACTIVE    ((UBase_t) 0x00000000UL)
#define SLPPWR_CFG_R_SRAM_PM_STANDBY    ((UBase_t) 0x00000001UL)
#define SLPPWR_CFG_R_SRAM_PM_LOWPOWER    ((UBase_t) 0x00000003UL)

#define SLPPWR_CFG_SRAM_PM_MASK    ((UBase_t) 0x00000003UL)
#define SLPPWR_CFG_SRAM_PM_ACTIVE    ((UBase_t) 0x00000000UL)
#define SLPPWR_CFG_SRAM_PM_STANDBY    ((UBase_t) 0x00000001UL)
#define SLPPWR_CFG_SRAM_PM_LOWPOWER    ((UBase_t) 0x00000003UL)
/*--------*/

/*--------*/
#define SLPPWR_CFG_R_FLASH_PM_MASK    ((UBase_t) 0x00000030UL)
#define SLPPWR_CFG_R_FLASH_PM_BIT    (4UL)
#define SLPPWR_CFG_R_FLASH_PM_ACTIVE    ((UBase_t) 0x00000000UL)
#define SLPPWR_CFG_R_FLASH_PM_LOWPOWER    ((UBase_t) 0x00000020UL)

#define SLPPWR_CFG_FLASH_PM_MASK    ((UBase_t) 0x00000003UL)
#define SLPPWR_CFG_FLASH_PM_ACTIVE    ((UBase_t) 0x00000000UL)
#define SLPPWR_CFG_FLASH_PM_LOWPOWER    ((UBase_t) 0x00000002UL)
/*--------*/

#endif /* XDRIVER_MCU_SYSCTL_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_SYSCTL_REGISTERDEFINES_SLPPWRCFG_H_ */
