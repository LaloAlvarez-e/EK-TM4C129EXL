/*
 * SYSCTL_RegisterDefines_RSCLKCFG.h
 *
 *  Created on: 13 jun. 2021
 *      Author: InDeviceMex
 */

#ifndef XDRIVER_MCU_SYSCTL_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_SYSCTL_REGISTERDEFINES_RSCLKCFG_H_
#define XDRIVER_MCU_SYSCTL_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_SYSCTL_REGISTERDEFINES_RSCLKCFG_H_

#include <xDriver_MCU/Common/xHeader/MCU_Variables.h>

/******************************************************************************************
************************************ 11 RSCLKCFG *********************************************
******************************************************************************************/
/*--------*/
#define SYSCTL_RSCLKCFG_R_PSYSDIV_MASK    ((uint32_t) 0x000003FFUL)
#define SYSCTL_RSCLKCFG_R_PSYSDIV_BIT    (0UL)

#define SYSCTL_RSCLKCFG_PSYSDIV_MASK    ((uint32_t) 0x000003FFUL)
/*--------*/

/*--------*/
#define SYSCTL_RSCLKCFG_R_OSYSDIV_MASK    ((uint32_t) 0x000FFC00UL)
#define SYSCTL_RSCLKCFG_R_OSYSDIV_BIT    (10UL)

#define SYSCTL_RSCLKCFG_OSYSDIV_MASK    ((uint32_t) 0x000003FFUL)
/*--------*/

/*--------*/
#define SYSCTL_RSCLKCFG_R_OSCSRC_MASK    ((uint32_t) 0x00F00000UL)
#define SYSCTL_RSCLKCFG_R_OSCSRC_BIT    (20UL)
#define SYSCTL_RSCLKCFG_R_OSCSRC_PIOSC    ((uint32_t) 0x00000000UL)
#define SYSCTL_RSCLKCFG_R_OSCSRC_LFIOSC    ((uint32_t) 0x00200000UL)
#define SYSCTL_RSCLKCFG_R_OSCSRC_MOSC    ((uint32_t) 0x00300000UL)
#define SYSCTL_RSCLKCFG_R_OSCSRC_RTCOSC    ((uint32_t) 0x00400000UL)

#define SYSCTL_RSCLKCFG_OSCSRC_MASK    ((uint32_t) 0x0000000FUL)
#define SYSCTL_RSCLKCFG_OSCSRC_PIOSC    ((uint32_t) 0x00000000UL)
#define SYSCTL_RSCLKCFG_OSCSRC_LFIOSC    ((uint32_t) 0x00000002UL)
#define SYSCTL_RSCLKCFG_OSCSRC_MOSC    ((uint32_t) 0x00000003UL)
#define SYSCTL_RSCLKCFG_OSCSRC_RTCOSC    ((uint32_t) 0x00000004UL)
/*--------*/

/*--------*/
#define SYSCTL_RSCLKCFG_R_PLLSRC_MASK    ((uint32_t) 0x0F000000UL)
#define SYSCTL_RSCLKCFG_R_PLLSRC_BIT    (24UL)
#define SYSCTL_RSCLKCFG_R_PLLSRC_PIOSC    ((uint32_t) 0x00000000UL)
#define SYSCTL_RSCLKCFG_R_PLLSRC_MOSC    ((uint32_t) 0x03000000UL)

#define SYSCTL_RSCLKCFG_PLLSRC_MASK    ((uint32_t) 0x0000000FUL)
#define SYSCTL_RSCLKCFG_PLLSRC_PIOSC    ((uint32_t) 0x00000000UL)
#define SYSCTL_RSCLKCFG_PLLSRC_MOSC    ((uint32_t) 0x00000003UL)
/*--------*/

/*--------*/
#define SYSCTL_RSCLKCFG_R_USEPLL_MASK    ((uint32_t) 0x10000000UL)
#define SYSCTL_RSCLKCFG_R_USEPLL_BIT    (28UL)
#define SYSCTL_RSCLKCFG_R_USEPLL_OSC    ((uint32_t) 0x00000000UL)
#define SYSCTL_RSCLKCFG_R_USEPLL_PLL    ((uint32_t) 0x10000000UL)

#define SYSCTL_RSCLKCFG_USEPLL_MASK    ((uint32_t) 0x00000001UL)
#define SYSCTL_RSCLKCFG_USEPLL_OSC    ((uint32_t) 0x00000000UL)
#define SYSCTL_RSCLKCFG_USEPLL_PLL    ((uint32_t) 0x00000001UL)
/*--------*/

/*--------*/
#define SYSCTL_RSCLKCFG_R_ACG_MASK    ((uint32_t) 0x20000000UL)
#define SYSCTL_RSCLKCFG_R_ACG_BIT    (29UL)
#define SYSCTL_RSCLKCFG_R_ACG_RCGCn    ((uint32_t) 0x00000000UL)
#define SYSCTL_RSCLKCFG_R_ACG_SCGCn    ((uint32_t) 0x20000000UL)

#define SYSCTL_RSCLKCFG_ACG_MASK    ((uint32_t) 0x00000001UL)
#define SYSCTL_RSCLKCFG_ACG_RCGCn    ((uint32_t) 0x00000000UL)
#define SYSCTL_RSCLKCFG_ACG_SCGCn    ((uint32_t) 0x00000001UL)
/*--------*/

/*--------*/
#define SYSCTL_RSCLKCFG_R_NEWFREQ_MASK    ((uint32_t) 0x40000000UL)
#define SYSCTL_RSCLKCFG_R_NEWFREQ_BIT    (30UL)
#define SYSCTL_RSCLKCFG_R_NEWFREQ_NOEFFECT    ((uint32_t) 0x00000000UL)
#define SYSCTL_RSCLKCFG_R_NEWFREQ_UPDATE    ((uint32_t) 0x40000000UL)

#define SYSCTL_RSCLKCFG_NEWFREQ_MASK    ((uint32_t) 0x00000001UL)
#define SYSCTL_RSCLKCFG_NEWFREQ_NOEFFECT    ((uint32_t) 0x00000000UL)
#define SYSCTL_RSCLKCFG_NEWFREQ_UPDATE    ((uint32_t) 0x00000001UL)
/*--------*/

/*--------*/
#define SYSCTL_RSCLKCFG_R_MEMTIMU_MASK    ((uint32_t) 0x80000000UL)
#define SYSCTL_RSCLKCFG_R_MEMTIMU_BIT    (31UL)
#define SYSCTL_RSCLKCFG_R_MEMTIMU_NOEFFECT    ((uint32_t) 0x00000000UL)
#define SYSCTL_RSCLKCFG_R_MEMTIMU_UPDATE    ((uint32_t) 0x80000000UL)

#define SYSCTL_RSCLKCFG_MEMTIMU_MASK    ((uint32_t) 0x00000001UL)
#define SYSCTL_RSCLKCFG_MEMTIMU_NOEFFECT    ((uint32_t) 0x00000000UL)
#define SYSCTL_RSCLKCFG_MEMTIMU_UPDATE    ((uint32_t) 0x00000001UL)
/*--------*/

#endif /* XDRIVER_MCU_SYSCTL_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_SYSCTL_REGISTERDEFINES_RSCLKCFG_H_ */
