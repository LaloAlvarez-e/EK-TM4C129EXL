/**
 *
 * @file HIB_ReadRegister.c
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
#include <xDriver_MCU/HIB/Driver/Intrinsics/Primitives/xHeader/HIB_ReadRegister.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/HIB/Peripheral/HIB_Peripheral.h>

HIB_nERROR HIB__enReadRegister(HIB_nMODULE enModuleArg, HIB_Register_t* pstRegisterDataArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) pstRegisterDataArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = (HIB_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) HIB_enMODULE_MAX);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        uintptr_t uptrModuleBase;

        uptrModuleBase = HIB__uptrBlockBaseAddress(enModuleArg);
        pstRegisterDataArg->uptrAddress += uptrModuleBase;
        enErrorReg = (HIB_nERROR) MCU__enReadRegister(pstRegisterDataArg);
    }
    return (enErrorReg);
}
