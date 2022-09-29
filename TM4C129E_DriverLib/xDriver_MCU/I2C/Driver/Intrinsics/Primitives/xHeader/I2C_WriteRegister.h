/**
 *
 * @file I2C_WriteRegister.h
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
#ifndef XDRIVER_MCU_I2C_DRIVER_INTRINSICS_PRIMITIVES_XHEADER_I2C_WRITEREGISTER_H_
#define XDRIVER_MCU_I2C_DRIVER_INTRINSICS_PRIMITIVES_XHEADER_I2C_WRITEREGISTER_H_

#include <xDriver_MCU/I2C/Peripheral/xHeader/I2C_Enum.h>

I2C_nERROR I2C__enWriteRegister(I2C_nMODULE enModuleArg, I2C_Register_t* pstRegisterDataArg);

#endif /* XDRIVER_MCU_I2C_DRIVER_INTRINSICS_PRIMITIVES_XHEADER_I2C_WRITEREGISTER_H_ */
