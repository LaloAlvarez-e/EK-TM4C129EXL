/**
 *
 * @file SYSCTL_DeviceID.h
 * @copyright
 * @verbatim InDeviceMex 2026 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 4 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 4 abr. 2026    GitHub Copilot   1.0         initial Version@endverbatim
 */

#ifndef B7B498AC_C838_4571_AFDA_2172E3D4749C
#define B7B498AC_C838_4571_AFDA_2172E3D4749C

#ifndef XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_DRIVER_SYSCTL_DEVICEID_H_
#define XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_DRIVER_SYSCTL_DEVICEID_H_

#include <xDriver_MCU/SYSCTL/Peripheral/xHeader/SYSCTL_Enum.h>

SYSCTL_nERROR SYSCTL__enGetDID0Version(SYSCTL_nMODULE enModuleArg, UBase_t* puxVersionArg);
SYSCTL_nERROR SYSCTL__enGetDID0Class(SYSCTL_nMODULE enModuleArg, UBase_t* puxClassArg);
SYSCTL_nERROR SYSCTL__enGetDID0MajorRevision(SYSCTL_nMODULE enModuleArg, UBase_t* puxMajorRevisionArg);
SYSCTL_nERROR SYSCTL__enGetDID0MinorRevision(SYSCTL_nMODULE enModuleArg, UBase_t* puxMinorRevisionArg);

SYSCTL_nERROR SYSCTL__enGetDID1Version(SYSCTL_nMODULE enModuleArg, UBase_t* puxVersionArg);
SYSCTL_nERROR SYSCTL__enGetDID1Family(SYSCTL_nMODULE enModuleArg, UBase_t* puxFamilyArg);
SYSCTL_nERROR SYSCTL__enGetDID1PartNo(SYSCTL_nMODULE enModuleArg, UBase_t* puxPartNoArg);
SYSCTL_nERROR SYSCTL__enGetDID1PinCount(SYSCTL_nMODULE enModuleArg, UBase_t* puxPinCountArg);
SYSCTL_nERROR SYSCTL__enGetDID1TempRange(SYSCTL_nMODULE enModuleArg, UBase_t* puxTempRangeArg);
SYSCTL_nERROR SYSCTL__enGetDID1Package(SYSCTL_nMODULE enModuleArg, UBase_t* puxPackageArg);
SYSCTL_nERROR SYSCTL__enGetDID1RoHS(SYSCTL_nMODULE enModuleArg, UBase_t* puxRoHSArg);
SYSCTL_nERROR SYSCTL__enGetDID1Qualification(SYSCTL_nMODULE enModuleArg, UBase_t* puxQualificationArg);

#endif /* XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_DRIVER_SYSCTL_DEVICEID_H_ */


#endif /* B7B498AC_C838_4571_AFDA_2172E3D4749C */
