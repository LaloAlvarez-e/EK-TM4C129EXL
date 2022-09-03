/**
 *
 * @file SYSTICK_ReadRegister.c
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
#include <xDriver_MCU/Core/SYSTICK/Driver/Intrinsics/Primitives/xHeader/SYSTICK_ReadRegister.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/Core/SYSTICK/Peripheral/SYSTICK_Peripheral.h>

SYSTICK_nERROR SYSTICK__enReadRegister(SYSTICK_nMODULE enModuleArg, SYSTICK_Register_t* pstRegisterDataArg)
{
    uintptr_t uptrModuleBase;
    SYSTICK_nERROR enErrorReg;
    if(0UL != (uint32_t) pstRegisterDataArg)
    {
        enErrorReg = (SYSTICK_nERROR) MCU__enCheckParams((uint32_t) enModuleArg, (uint32_t) SYSTICK_enMODULE_MAX);
        if(SYSTICK_enERROR_OK == enErrorReg)
        {
            uptrModuleBase = SYSTICK__uptrBlockBaseAddress(enModuleArg);
            pstRegisterDataArg->uptrAddress += uptrModuleBase;
            enErrorReg = (SYSTICK_nERROR) MCU__enReadRegister(pstRegisterDataArg);
        }
    }
    else
    {
        enErrorReg = SYSTICK_enERROR_POINTER;
    }
    return (enErrorReg);
}



