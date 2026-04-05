/*
 * SYSCTL_RegisterDefines_LDOSPCTL.h
 *
 *  Created on: 13 jun. 2021
 *      Author: InDeviceMex
 */

#ifndef XDRIVER_MCU_SYSCTL_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_SYSCTL_REGISTERDEFINES_LDOSPCTL_H_
#define XDRIVER_MCU_SYSCTL_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_SYSCTL_REGISTERDEFINES_LDOSPCTL_H_

#include <xDriver_MCU/SYSCTL/Peripheral/xHeader/SYSCTL_Enum.h>

/******************************************************************************************
************************************25 LDOSPCTL *********************************************
******************************************************************************************/
/*--------*/
#define LDO_SPCTL_R_VLDO_MASK    ((UBase_t) 0x000000FFUL)
#define LDO_SPCTL_R_VLDO_BIT    (0UL)

#define LDO_SPCTL_VLDO_MASK    ((UBase_t) 0x000000FFUL)
/*--------*/

/*--------*/
#define LDO_SPCTL_R_VADJEN_MASK    ((UBase_t) 0x80000000UL)
#define LDO_SPCTL_R_VADJEN_BIT    (31UL)

#define LDO_SPCTL_VADJEN_MASK    ((UBase_t) 0x00000001UL)
/*--------*/

#endif /* XDRIVER_MCU_SYSCTL_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_SYSCTL_REGISTERDEFINES_LDOSPCTL_H_ */
