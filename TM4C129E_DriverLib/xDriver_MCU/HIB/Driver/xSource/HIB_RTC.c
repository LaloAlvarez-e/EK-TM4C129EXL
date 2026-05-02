/**
 *
 * @file HIB_RTC.c
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
 * @verbatim 6 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 6 abr. 2026    vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/HIB/Driver/xHeader/HIB_RTC.h>

#include <xDriver_MCU/HIB/Driver/Intrinsics/HIB_Intrinsics.h>
#include <xDriver_MCU/HIB/Peripheral/HIB_Peripheral.h>

static HIB_nERROR HIB__enWriteRTCField(HIB_nMODULE enModuleArg, uintptr_t uptrAddressArg,
                                       UBase_t uxMaskArg, UBase_t uxShiftArg,
                                       UBase_t uxValueArg);
static HIB_nERROR HIB__enReadRTCField(HIB_nMODULE enModuleArg, uintptr_t uptrAddressArg,
                                      UBase_t uxMaskArg, UBase_t uxShiftArg,
                                      UBase_t* puxValueArg);

static HIB_nERROR HIB__enWriteRTCField(HIB_nMODULE enModuleArg, uintptr_t uptrAddressArg,
                                       UBase_t uxMaskArg, UBase_t uxShiftArg,
                                       UBase_t uxValueArg)
{
    HIB_Register_t stRegister;

    stRegister.uxShift = uxShiftArg;
    stRegister.uxMask = uxMaskArg;
    stRegister.uptrAddress = uptrAddressArg;
    stRegister.uxValue = uxValueArg;

    return HIB__enWriteRegister(enModuleArg, &stRegister);
}

static HIB_nERROR HIB__enReadRTCField(HIB_nMODULE enModuleArg, uintptr_t uptrAddressArg,
                                      UBase_t uxMaskArg, UBase_t uxShiftArg,
                                      UBase_t* puxValueArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) puxValueArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        HIB_Register_t stRegister;

        stRegister.uxShift = uxShiftArg;
        stRegister.uxMask = uxMaskArg;
        stRegister.uptrAddress = uptrAddressArg;
        stRegister.uxValue = 0UL;

        enErrorReg = HIB__enReadRegister(enModuleArg, &stRegister);
        if(HIB_enERROR_OK == enErrorReg)
        {
            *puxValueArg = stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enSetRTCState(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg)
{
    UBase_t uxValueReg;

    uxValueReg = (HIB_enSTATE_ENA == enStateArg) ? HIB_CTL_RTCEN_ENA : HIB_CTL_RTCEN_DIS;
    return HIB__enWriteRTCField(enModuleArg, HIB_CTL_OFFSET, HIB_CTL_RTCEN_MASK,
                                HIB_CTL_R_RTCEN_BIT, uxValueReg);
}

HIB_nERROR HIB__enGetRTCState(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxValueReg;

    enErrorReg = (0UL == (uintptr_t) penStateArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadRTCField(enModuleArg, HIB_CTL_OFFSET, HIB_CTL_RTCEN_MASK,
                                         HIB_CTL_R_RTCEN_BIT, &uxValueReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        *penStateArg = (0UL != uxValueReg) ? HIB_enSTATE_ENA : HIB_enSTATE_DIS;
    }
    return (enErrorReg);
}
