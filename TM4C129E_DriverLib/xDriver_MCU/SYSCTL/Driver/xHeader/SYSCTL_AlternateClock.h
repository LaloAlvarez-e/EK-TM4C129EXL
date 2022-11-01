/*
 * SYSCTL_AlternateClock.h
 *
 *  Created on: 13 jun. 2021
 *      Author: InDeviceMex
 */

#ifndef XDRIVER_MCU_SYSCTL_DRIVER_XHEADER_SYSCTL_ALTERNATECLOCK_H_
#define XDRIVER_MCU_SYSCTL_DRIVER_XHEADER_SYSCTL_ALTERNATECLOCK_H_

#include <xDriver_MCU/SYSCTL/Peripheral/xHeader/SYSCTL_Enum.h>

SYSCTL_nERROR SYSCTL__enSetAlternateClockSource(SYSCTL_nMODULE enModuleArg, SYSCTL_nALTCLK_SRC enSourceArg);
SYSCTL_nERROR SYSCTL__enGetAlternateClockSource(SYSCTL_nMODULE enModuleArg, SYSCTL_nALTCLK_SRC* penSourceArg);


#endif /* XDRIVER_MCU_SYSCTL_DRIVER_XHEADER_SYSCTL_ALTERNATECLOCK_H_ */
