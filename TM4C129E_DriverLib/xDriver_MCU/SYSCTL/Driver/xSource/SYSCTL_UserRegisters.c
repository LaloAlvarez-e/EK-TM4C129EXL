/**
 *
 * @file SYSCTL_UserRegisters.c
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
 * @verbatim 5 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 5 abr. 2026    GitHub Copilot   1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_UserRegisters.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/SYSCTL/Driver/Intrinsics/Primitives/SYSCTL_Primitives.h>
#include <xDriver_MCU/SYSCTL/Peripheral/SYSCTL_Peripheral.h>

static SYSCTL_nERROR SYSCTL__enGetUserRegister(SYSCTL_nMODULE enModuleArg, uintptr_t uptrAddressArg,
                                               UBase_t uxMaskArg, UBase_t uxShiftArg,
                                               UBase_t* puxValueArg);

static SYSCTL_nERROR SYSCTL__enGetUserRegister(SYSCTL_nMODULE enModuleArg, uintptr_t uptrAddressArg,
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

SYSCTL_nERROR SYSCTL__enGetUserRegister0(SYSCTL_nMODULE enModuleArg, UBase_t* puxValueArg)
{
    return SYSCTL__enGetUserRegister(enModuleArg, USER_REG0_OFFSET, USER_REG0_DATA_MASK,
                                     USER_REG0_R_DATA_BIT, puxValueArg);
}

SYSCTL_nERROR SYSCTL__enGetUserRegister1(SYSCTL_nMODULE enModuleArg, UBase_t* puxValueArg)
{
    return SYSCTL__enGetUserRegister(enModuleArg, USER_REG1_OFFSET, USER_REG1_DATA_MASK,
                                     USER_REG1_R_DATA_BIT, puxValueArg);
}

SYSCTL_nERROR SYSCTL__enGetUserRegister2(SYSCTL_nMODULE enModuleArg, UBase_t* puxValueArg)
{
    return SYSCTL__enGetUserRegister(enModuleArg, USER_REG2_OFFSET, USER_REG2_DATA_MASK,
                                     USER_REG2_R_DATA_BIT, puxValueArg);
}

SYSCTL_nERROR SYSCTL__enGetUserRegister3(SYSCTL_nMODULE enModuleArg, UBase_t* puxValueArg)
{
    return SYSCTL__enGetUserRegister(enModuleArg, USER_REG3_OFFSET, USER_REG3_DATA_MASK,
                                     USER_REG3_R_DATA_BIT, puxValueArg);
}