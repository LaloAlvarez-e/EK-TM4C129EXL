/**
 *
 * @file DMA_ReadRegister.h
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
 * @verbatim 29 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 29 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_DMA_DRIVER_INTRINSICS_PRIMITIVES_XHEADER_DMA_READREGISTER_H_
#define XDRIVER_MCU_DMA_DRIVER_INTRINSICS_PRIMITIVES_XHEADER_DMA_READREGISTER_H_

#include <xDriver_MCU/DMA/Peripheral/xHeader/DMA_Enum.h>

uint32_t DMA__u32ReadRegister(uint32_t u32OffsetRegister, uint32_t u32MaskFeature, uint32_t u32BitFeature);

#endif /* XDRIVER_MCU_DMA_DRIVER_INTRINSICS_PRIMITIVES_XHEADER_DMA_READREGISTER_H_ */
