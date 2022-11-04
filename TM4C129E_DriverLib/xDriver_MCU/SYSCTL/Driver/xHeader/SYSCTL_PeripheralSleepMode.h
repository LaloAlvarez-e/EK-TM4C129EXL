/**
 *
 * @file SYSCTL_PeripheralSleepMode.h
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
 * @verbatim 24 jun. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 24 jun. 2020     vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_DRIVER_SYSCTL_PERIPHERALSLEEPMODE_H_
#define XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_DRIVER_SYSCTL_PERIPHERALSLEEPMODE_H_

#include <xDriver_MCU/SYSCTL/Peripheral/xHeader/SYSCTL_Enum.h>

SYSCTL_nERROR SYSCTL__enSetSleepModeState(SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg, SYSCTL_nSTATE enStateArg);
SYSCTL_nERROR SYSCTL__enEnableSleepMode(SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg);
SYSCTL_nERROR SYSCTL__enDisableSleepMode(SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg);

SYSCTL_nERROR SYSCTL__enGetSleepModeState(SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg, SYSCTL_nSTATE* penStateArg);

#endif /* XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_DRIVER_SYSCTL_PERIPHERALSLEEPMODE_H_ */
