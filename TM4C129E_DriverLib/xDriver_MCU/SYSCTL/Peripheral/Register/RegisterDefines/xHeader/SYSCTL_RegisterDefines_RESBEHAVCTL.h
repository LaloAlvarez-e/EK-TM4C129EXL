/*
 * SYSCTL_RegisterDefines_RESBEHAVCTL.h
 *
 *  Created on: 13 jun. 2021
 *      Author: InDeviceMex
 */

#ifndef XDRIVER_MCU_SYSCTL_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_SYSCTL_REGISTERDEFINES_RESBEHAVCTL_H_
#define XDRIVER_MCU_SYSCTL_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_SYSCTL_REGISTERDEFINES_RESBEHAVCTL_H_

#include <xDriver_MCU/SYSCTL/Peripheral/xHeader/SYSCTL_Enum.h>

/******************************************************************************************
************************************ 30 RESBEHAVCTL *********************************************
******************************************************************************************/
/*--------*/
#define RESET_BEHAVCTL_R_EXTERNAL_MASK    ((UBase_t) 0x00000003UL)
#define RESET_BEHAVCTL_R_EXTERNAL_BIT    (0UL)
#define RESET_BEHAVCTL_R_EXTERNAL_DEFAULT    ((UBase_t) 0x00000000UL)
#define RESET_BEHAVCTL_R_EXTERNAL_SYSRESET    ((UBase_t) 0x00000002UL)
#define RESET_BEHAVCTL_R_EXTERNAL_POR    ((UBase_t) 0x00000003UL)

#define RESET_BEHAVCTL_EXTERNAL_MASK    ((UBase_t) 0x00000003UL)
#define RESET_BEHAVCTL_EXTERNAL_DEFAULT    ((UBase_t) 0x00000000UL)
#define RESET_BEHAVCTL_EXTERNAL_SYSRESET    ((UBase_t) 0x00000002UL)
#define RESET_BEHAVCTL_EXTERNAL_POR    ((UBase_t) 0x00000003UL)
/*--------*/

/*--------*/
#define RESET_BEHAVCTL_R_BOR_MASK    ((UBase_t) 0x0000000CUL)
#define RESET_BEHAVCTL_R_BOR_BIT    (2UL)
#define RESET_BEHAVCTL_R_BOR_DEFAULT    ((UBase_t) 0x00000000UL)
#define RESET_BEHAVCTL_R_BOR_SYSRESET    ((UBase_t) 0x00000008UL)
#define RESET_BEHAVCTL_R_BOR_POR    ((UBase_t) 0x0000000CUL)

#define RESET_BEHAVCTL_BOR_MASK    ((UBase_t) 0x00000003UL)
#define RESET_BEHAVCTL_BOR_DEFAULT    ((UBase_t) 0x00000000UL)
#define RESET_BEHAVCTL_BOR_SYSRESET    ((UBase_t) 0x00000002UL)
#define RESET_BEHAVCTL_BOR_POR    ((UBase_t) 0x00000003UL)
/*--------*/

/*--------*/
#define RESET_BEHAVCTL_R_WDG0_MASK    ((UBase_t) 0x00000030UL)
#define RESET_BEHAVCTL_R_WDG0_BIT    (4UL)
#define RESET_BEHAVCTL_R_WDG0_DEFAULT    ((UBase_t) 0x00000000UL)
#define RESET_BEHAVCTL_R_WDG0_SYSRESET    ((UBase_t) 0x00000020UL)
#define RESET_BEHAVCTL_R_WDG0_POR    ((UBase_t) 0x00000030UL)

#define RESET_BEHAVCTL_WDG0_MASK    ((UBase_t) 0x00000003UL)
#define RESET_BEHAVCTL_WDG0_DEFAULT    ((UBase_t) 0x00000000UL)
#define RESET_BEHAVCTL_WDG0_SYSRESET    ((UBase_t) 0x00000002UL)
#define RESET_BEHAVCTL_WDG0_POR    ((UBase_t) 0x00000003UL)
/*--------*/

/*--------*/
#define RESET_BEHAVCTL_R_WDG1_MASK    ((UBase_t) 0x000000C0UL)
#define RESET_BEHAVCTL_R_WDG1_BIT    (6UL)
#define RESET_BEHAVCTL_R_WDG1_DEFAULT    ((UBase_t) 0x00000000UL)
#define RESET_BEHAVCTL_R_WDG1_SYSRESET    ((UBase_t) 0x00000080UL)
#define RESET_BEHAVCTL_R_WDG1_POR    ((UBase_t) 0x000000C0UL)

#define RESET_BEHAVCTL_WDG1_MASK    ((UBase_t) 0x00000003UL)
#define RESET_BEHAVCTL_WDG1_DEFAULT    ((UBase_t) 0x00000000UL)
#define RESET_BEHAVCTL_WDG1_SYSRESET    ((UBase_t) 0x00000002UL)
#define RESET_BEHAVCTL_WDG1_POR    ((UBase_t) 0x00000003UL)
/*--------*/

#endif /* XDRIVER_MCU_SYSCTL_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_SYSCTL_REGISTERDEFINES_RESBEHAVCTL_H_ */
