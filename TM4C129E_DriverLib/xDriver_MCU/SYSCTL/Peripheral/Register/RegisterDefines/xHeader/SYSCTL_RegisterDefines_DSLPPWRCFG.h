/*
 * SYSCTL_RegisterDefines_DSLPPWRCFG.h
 *
 *  Created on: 13 jun. 2021
 *      Author: InDeviceMex
 */

#ifndef XDRIVER_MCU_SYSCTL_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_SYSCTL_REGISTERDEFINES_DSLPPWRCFG_H_
#define XDRIVER_MCU_SYSCTL_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_SYSCTL_REGISTERDEFINES_DSLPPWRCFG_H_

#include <xDriver_MCU/SYSCTL/Peripheral/xHeader/SYSCTL_Enum.h>

/******************************************************************************************
************************************23 DSLPPWRCFG *********************************************
******************************************************************************************/
/*--------*/
#define DSLPPWR_CFG_R_SRAM_PM_MASK    ((UBase_t) 0x00000003UL)
#define DSLPPWR_CFG_R_SRAM_PM_BIT    (0UL)
#define DSLPPWR_CFG_R_SRAM_PM_ACTIVE    ((UBase_t) 0x00000000UL)
#define DSLPPWR_CFG_R_SRAM_PM_STANDBY    ((UBase_t) 0x00000001UL)
#define DSLPPWR_CFG_R_SRAM_PM_LOWPOWER    ((UBase_t) 0x00000003UL)

#define DSLPPWR_CFG_SRAM_PM_MASK    ((UBase_t) 0x00000003UL)
#define DSLPPWR_CFG_SRAM_PM_ACTIVE    ((UBase_t) 0x00000000UL)
#define DSLPPWR_CFG_SRAM_PM_STANDBY    ((UBase_t) 0x00000001UL)
#define DSLPPWR_CFG_SRAM_PM_LOWPOWER    ((UBase_t) 0x00000003UL)
/*--------*/

/*--------*/
#define DSLPPWR_CFG_R_FLASH_PM_MASK    ((UBase_t) 0x00000030UL)
#define DSLPPWR_CFG_R_FLASH_PM_BIT    (4UL)
#define DSLPPWR_CFG_R_FLASH_PM_ACTIVE    ((UBase_t) 0x00000000UL)
#define DSLPPWR_CFG_R_FLASH_PM_LOWPOWER    ((UBase_t) 0x00000020UL)

#define DSLPPWR_CFG_FLASH_PM_MASK    ((UBase_t) 0x00000003UL)
#define DSLPPWR_CFG_FLASH_PM_ACTIVE    ((UBase_t) 0x00000000UL)
#define DSLPPWR_CFG_FLASH_PM_LOWPOWER    ((UBase_t) 0x00000002UL)
/*--------*/

/*--------*/
#define DSLPPWR_CFG_R_TS_PD_MASK    ((UBase_t) 0x00000100UL)
#define DSLPPWR_CFG_R_TS_PD_BIT    (8UL)
#define DSLPPWR_CFG_R_TS_PD_DIS    ((UBase_t) 0x00000000UL)
#define DSLPPWR_CFG_R_TS_PD_ENA    ((UBase_t) 0x00000100UL)

#define DSLPPWR_CFG_TS_PD_MASK    ((UBase_t) 0x00000001UL)
#define DSLPPWR_CFG_TS_PD_DIS    ((UBase_t) 0x00000000UL)
#define DSLPPWR_CFG_TS_PD_ENA    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define DSLPPWR_CFG_R_LDO_SM_MASK    ((UBase_t) 0x00000200UL)
#define DSLPPWR_CFG_R_LDO_SM_BIT    (9UL)
#define DSLPPWR_CFG_R_LDO_SM_DIS    ((UBase_t) 0x00000000UL)
#define DSLPPWR_CFG_R_LDO_SM_ENA    ((UBase_t) 0x00000200UL)

#define DSLPPWR_CFG_LDO_SM_MASK    ((UBase_t) 0x00000001UL)
#define DSLPPWR_CFG_LDO_SM_DIS    ((UBase_t) 0x00000000UL)
#define DSLPPWR_CFG_LDO_SM_ENA    ((UBase_t) 0x00000001UL)
/*--------*/


#endif /* XDRIVER_MCU_SYSCTL_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_SYSCTL_REGISTERDEFINES_DSLPPWRCFG_H_ */
