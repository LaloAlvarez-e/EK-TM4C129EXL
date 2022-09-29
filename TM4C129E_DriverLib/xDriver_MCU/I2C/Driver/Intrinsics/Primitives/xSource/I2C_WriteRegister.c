/**
 *
 * @file I2C_WriteRegister.c
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
 * @verbatim 7 mar. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 7 mar. 2021     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/I2C/Driver/Intrinsics/Primitives/xHeader/I2C_WriteRegister.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/I2C/Peripheral/I2C_Peripheral.h>

I2C_nERROR I2C__enWriteRegister(I2C_nMODULE enModuleArg, I2C_Register_t* pstRegisterDataArg)
{
    uintptr_t uptrModuleBase;
    I2C_nERROR enErrorReg;
    enErrorReg = I2C_enERROR_OK;
    if(0UL == (uintptr_t) pstRegisterDataArg)
    {
        enErrorReg = I2C_enERROR_POINTER;
    }
    if(I2C_enERROR_OK == enErrorReg)
    {
        enErrorReg = (I2C_nERROR) MCU__enCheckParams((uint32_t) enModuleArg, (uint32_t) I2C_enMODULE_MAX);
    }
    if(I2C_enERROR_OK == enErrorReg)
    {
        uptrModuleBase = I2C__uptrBlockBaseAddress(enModuleArg);
        pstRegisterDataArg->uptrAddress += uptrModuleBase;
        enErrorReg = (I2C_nERROR) MCU__enWriteRegister(pstRegisterDataArg);
    }

    return (enErrorReg);
}
