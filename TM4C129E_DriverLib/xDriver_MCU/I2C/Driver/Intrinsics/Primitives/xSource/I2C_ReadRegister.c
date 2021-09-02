/**
 *
 * @file I2C_ReadRegister.c
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
#include <xDriver_MCU/I2C/Driver/Intrinsics/Primitives/xHeader/I2C_ReadRegister.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/I2C/Peripheral/I2C_Peripheral.h>

uint32_t I2C__u32ReadRegister(I2C_nMODULE enModule, uint32_t u32OffsetRegister,
                             uint32_t u32MaskFeature, uint32_t u32BitFeature)
{
    uint32_t u32FeatureValue = 0UL;
    uint32_t u32I2cBase = 0UL;
    uint32_t u32Module = 0UL;
    u32Module = MCU__u32CheckParams((uint32_t) enModule, (uint32_t) I2C_enMODULE_MAX);

    u32I2cBase = I2C__u32BlockBaseAddress((I2C_nMODULE) u32Module);
    u32FeatureValue = MCU__u32ReadRegister(u32I2cBase, u32OffsetRegister,
                                           u32MaskFeature, u32BitFeature);
    return (u32FeatureValue);
}


