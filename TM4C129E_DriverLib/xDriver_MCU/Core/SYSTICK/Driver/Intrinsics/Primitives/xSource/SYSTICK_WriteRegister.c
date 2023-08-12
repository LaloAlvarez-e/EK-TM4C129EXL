/**
 *
 * @file SYSTICK_WriteRegister.c
 * @copyright
 * @verbatim InDeviceMex 2021 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 1 sep. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 1 sep. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/Core/SYSTICK/Driver/Intrinsics/Primitives/xHeader/SYSTICK_WriteRegister.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/Core/SYSTICK/Peripheral/SYSTICK_Peripheral.h>

SYSTICK_nERROR SYSTICK__enWriteRegister(SYSTICK_nMODULE enModuleArg, SYSTICK_Register_t* pstRegisterDataArg)
{
    SYSTICK_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) pstRegisterDataArg) ? SYSTICK_enERROR_POINTER : SYSTICK_enERROR_OK;
    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SYSTICK_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) SYSTICK_enMODULE_MAX);
    }
    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        uintptr_t uptrModuleBase = SYSTICK__uptrBlockBaseAddress(enModuleArg);
        pstRegisterDataArg->uptrAddress += uptrModuleBase;
        enErrorReg = (SYSTICK_nERROR) MCU__enWriteRegister(pstRegisterDataArg);
    }
    return (enErrorReg);
}




