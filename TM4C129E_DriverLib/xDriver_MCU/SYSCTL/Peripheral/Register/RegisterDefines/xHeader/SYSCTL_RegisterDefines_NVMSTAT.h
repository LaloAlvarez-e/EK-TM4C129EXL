/*
 * SYSCTL_RegisterDefines_NVMSTAT.h
 *
 *  Created on: 13 jun. 2021
 *      Author: InDeviceMex
 */

#ifndef XDRIVER_MCU_SYSCTL_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_SYSCTL_REGISTERDEFINES_NVMSTAT_H_
#define XDRIVER_MCU_SYSCTL_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_SYSCTL_REGISTERDEFINES_NVMSTAT_H_

#include <xDriver_MCU/Common/xHeader/MCU_Variables.h>

/**********************************************************************************
************************************24 NVMSTAT *********************************************
******************************************************************************************/
/*----------*/
#define SYSCTL_NVMSTAT_R_FWB_MASK    ((uint32_t) 0x00000001UL)
#define SYSCTL_NVMSTAT_R_FWB_BIT    (0UL)
#define SYSCTL_NVMSTAT_R_FWB_NOPRESENT    ((uint32_t) 0x00000000UL)
#define SYSCTL_NVMSTAT_R_FWB_PRESENT    ((uint32_t) 0x00000001UL)

#define SYSCTL_NVMSTAT_FWB_MASK    ((uint32_t) 0x00000001UL)
#define SYSCTL_NVMSTAT_FWB_NOPRESENT    ((uint32_t) 0x00000000UL)
#define SYSCTL_NVMSTAT_FWB_PRESENT    ((uint32_t) 0x00000001UL)
/*----------*/


#endif /* XDRIVER_MCU_SYSCTL_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_SYSCTL_REGISTERDEFINES_NVMSTAT_H_ */
