/**
 *
 * @file HIB_WriteRegister.c
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
#include <xDriver_MCU/HIB/Driver/Intrinsics/Primitives/xHeader/HIB_WriteRegister.h>

#include <xDriver_MCU/HIB/Driver/Intrinsics/Primitives/xHeader/HIB_Wait.h>
#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/HIB/Peripheral/HIB_Peripheral.h>

HIB_nERROR HIB__enWriteRegisterTimeout(HIB_nMODULE enModuleArg, HIB_Register_t* pstRegisterDataArg, UBase_t uxTimeoutArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) pstRegisterDataArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = (HIB_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) HIB_enMODULE_MAX);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enWaitWrite(enModuleArg, uxTimeoutArg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        uintptr_t uptrModuleBase;

        uptrModuleBase = HIB__uptrBlockBaseAddress(enModuleArg);
        pstRegisterDataArg->uptrAddress += uptrModuleBase;
        enErrorReg = (HIB_nERROR) MCU__enWriteRegister(pstRegisterDataArg);
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enWriteRegister(HIB_nMODULE enModuleArg, HIB_Register_t* pstRegisterDataArg)
{
    HIB_nERROR enErrorReg;
    enErrorReg = HIB__enWriteRegisterTimeout(enModuleArg, pstRegisterDataArg, 0UL);
    return (enErrorReg);
}