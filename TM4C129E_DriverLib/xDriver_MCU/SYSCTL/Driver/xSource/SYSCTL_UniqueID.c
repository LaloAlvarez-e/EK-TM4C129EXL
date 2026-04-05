/**
 *
 * @file SYSCTL_UniqueID.c
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
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_UniqueID.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/SYSCTL/Driver/Intrinsics/Primitives/SYSCTL_Primitives.h>
#include <xDriver_MCU/SYSCTL/Peripheral/SYSCTL_Peripheral.h>

static SYSCTL_nERROR SYSCTL__enGetUniqueIDRegister(SYSCTL_nMODULE enModuleArg, uintptr_t uptrAddressArg,
                                                   UBase_t uxMaskArg, UBase_t uxShiftArg,
                                                   UBase_t* puxValueArg);

static SYSCTL_nERROR SYSCTL__enGetUniqueIDRegister(SYSCTL_nMODULE enModuleArg, uintptr_t uptrAddressArg,
                                                   UBase_t uxMaskArg, UBase_t uxShiftArg,
                                                   UBase_t* puxValueArg)
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

SYSCTL_nERROR SYSCTL__enGetUniqueID0(SYSCTL_nMODULE enModuleArg, UBase_t* puxUniqueID0Arg)
{
    return SYSCTL__enGetUniqueIDRegister(enModuleArg, UNIQUE_ID0_OFFSET, UNIQUE_ID0_R_ID_MASK,
                                         UNIQUE_ID0_R_ID_BIT, puxUniqueID0Arg);
}

SYSCTL_nERROR SYSCTL__enGetUniqueID1(SYSCTL_nMODULE enModuleArg, UBase_t* puxUniqueID1Arg)
{
    return SYSCTL__enGetUniqueIDRegister(enModuleArg, UNIQUE_ID1_OFFSET, UNIQUE_ID1_R_ID_MASK,
                                         UNIQUE_ID1_R_ID_BIT, puxUniqueID1Arg);
}

SYSCTL_nERROR SYSCTL__enGetUniqueID2(SYSCTL_nMODULE enModuleArg, UBase_t* puxUniqueID2Arg)
{
    return SYSCTL__enGetUniqueIDRegister(enModuleArg, UNIQUE_ID2_OFFSET, UNIQUE_ID2_R_ID_MASK,
                                         UNIQUE_ID2_R_ID_BIT, puxUniqueID2Arg);
}

SYSCTL_nERROR SYSCTL__enGetUniqueID3(SYSCTL_nMODULE enModuleArg, UBase_t* puxUniqueID3Arg)
{
    return SYSCTL__enGetUniqueIDRegister(enModuleArg, UNIQUE_ID3_OFFSET, UNIQUE_ID3_R_ID_MASK,
                                         UNIQUE_ID3_R_ID_BIT, puxUniqueID3Arg);
}