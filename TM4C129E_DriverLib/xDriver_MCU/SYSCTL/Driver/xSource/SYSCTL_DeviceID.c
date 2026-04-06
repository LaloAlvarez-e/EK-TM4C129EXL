/**
 *
 * @file SYSCTL_DeviceID.c
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
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_DeviceID.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/SYSCTL/Driver/Intrinsics/Primitives/SYSCTL_Primitives.h>
#include <xDriver_MCU/SYSCTL/Peripheral/SYSCTL_Peripheral.h>

static SYSCTL_nERROR SYSCTL__enGetDIDField(SYSCTL_nMODULE enModuleArg, uintptr_t uptrAddressArg, UBase_t uxMaskArg,
                                           UBase_t uxShiftArg, UBase_t* puxValueArg);

static SYSCTL_nERROR SYSCTL__enGetDIDField(SYSCTL_nMODULE enModuleArg, uintptr_t uptrAddressArg, UBase_t uxMaskArg,
                                           UBase_t uxShiftArg, UBase_t* puxValueArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) puxValueArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        SYSCTL_Register_t stRegister;
        stRegister.uxShift = uxShiftArg;
        stRegister.uxMask = uxMaskArg;
        stRegister.uptrAddress = uptrAddressArg;
        enErrorReg = SYSCTL__enReadRegister(enModuleArg, &stRegister);
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            *puxValueArg = stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enGetDID0Version(SYSCTL_nMODULE enModuleArg, UBase_t* puxVersionArg)
{
    return SYSCTL__enGetDIDField(enModuleArg, DEVICE_ID0_OFFSET, DEVICE_ID0_R_VERSION_MASK, DEVICE_ID0_R_VERSION_BIT,
                                 puxVersionArg);
}

SYSCTL_nERROR SYSCTL__enGetDID0Class(SYSCTL_nMODULE enModuleArg, UBase_t* puxClassArg)
{
    return SYSCTL__enGetDIDField(enModuleArg, DEVICE_ID0_OFFSET, DEVICE_ID0_R_CLASS_MASK, DEVICE_ID0_R_CLASS_BIT,
                                 puxClassArg);
}

SYSCTL_nERROR SYSCTL__enGetDID0MajorRevision(SYSCTL_nMODULE enModuleArg, UBase_t* puxMajorRevisionArg)
{
    return SYSCTL__enGetDIDField(enModuleArg, DEVICE_ID0_OFFSET, DEVICE_ID0_R_MAJOR_REVISION_MASK,
                                 DEVICE_ID0_R_MAJOR_REVISION_BIT, puxMajorRevisionArg);
}

SYSCTL_nERROR SYSCTL__enGetDID0MinorRevision(SYSCTL_nMODULE enModuleArg, UBase_t* puxMinorRevisionArg)
{
    return SYSCTL__enGetDIDField(enModuleArg, DEVICE_ID0_OFFSET, DEVICE_ID0_R_MINOR_REVISION_MASK,
                                 DEVICE_ID0_R_MINOR_REVISION_BIT, puxMinorRevisionArg);
}

SYSCTL_nERROR SYSCTL__enGetDID1Version(SYSCTL_nMODULE enModuleArg, UBase_t* puxVersionArg)
{
    return SYSCTL__enGetDIDField(enModuleArg, DEVICE_ID1_OFFSET, DEVICE_ID1_R_VERSION_MASK, DEVICE_ID1_R_VERSION_BIT,
                                 puxVersionArg);
}

SYSCTL_nERROR SYSCTL__enGetDID1Family(SYSCTL_nMODULE enModuleArg, UBase_t* puxFamilyArg)
{
    return SYSCTL__enGetDIDField(enModuleArg, DEVICE_ID1_OFFSET, DEVICE_ID1_R_FAMILY_MASK, DEVICE_ID1_R_FAMILY_BIT,
                                 puxFamilyArg);
}

SYSCTL_nERROR SYSCTL__enGetDID1PartNo(SYSCTL_nMODULE enModuleArg, UBase_t* puxPartNoArg)
{
    return SYSCTL__enGetDIDField(enModuleArg, DEVICE_ID1_OFFSET, DEVICE_ID1_R_PARTNO_MASK, DEVICE_ID1_R_PARTNO_BIT,
                                 puxPartNoArg);
}

SYSCTL_nERROR SYSCTL__enGetDID1PinCount(SYSCTL_nMODULE enModuleArg, UBase_t* puxPinCountArg)
{
    return SYSCTL__enGetDIDField(enModuleArg, DEVICE_ID1_OFFSET, DEVICE_ID1_R_PINCOUNT_MASK,
                                 DEVICE_ID1_R_PINCOUNT_BIT, puxPinCountArg);
}

SYSCTL_nERROR SYSCTL__enGetDID1TempRange(SYSCTL_nMODULE enModuleArg, UBase_t* puxTempRangeArg)
{
    return SYSCTL__enGetDIDField(enModuleArg, DEVICE_ID1_OFFSET, DEVICE_ID1_R_TEMP_MASK, DEVICE_ID1_R_TEMP_BIT,
                                 puxTempRangeArg);
}

SYSCTL_nERROR SYSCTL__enGetDID1Package(SYSCTL_nMODULE enModuleArg, UBase_t* puxPackageArg)
{
    return SYSCTL__enGetDIDField(enModuleArg, DEVICE_ID1_OFFSET, DEVICE_ID1_R_PKG_MASK, DEVICE_ID1_R_PKG_BIT,
                                 puxPackageArg);
}

SYSCTL_nERROR SYSCTL__enGetDID1RoHS(SYSCTL_nMODULE enModuleArg, UBase_t* puxRoHSArg)
{
    return SYSCTL__enGetDIDField(enModuleArg, DEVICE_ID1_OFFSET, DEVICE_ID1_R_ROHS_MASK, DEVICE_ID1_R_ROHS_BIT,
                                 puxRoHSArg);
}

SYSCTL_nERROR SYSCTL__enGetDID1Qualification(SYSCTL_nMODULE enModuleArg, UBase_t* puxQualificationArg)
{
    return SYSCTL__enGetDIDField(enModuleArg, DEVICE_ID1_OFFSET, DEVICE_ID1_R_QUAL_MASK, DEVICE_ID1_R_QUAL_BIT,
                                 puxQualificationArg);
}
