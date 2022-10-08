/**
 *
 * @file DMA_StructRegisterChannel_Bitbanding.h
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
 * @verbatim 28 jul. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date Author Version Description
 * 28 jul. 2020 vyldram 1.0 initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_DRIVER_HEADER_DMA_DMA_PERIPHERAL_DMA_STRUCT_DMA_STRUCTREGISTERCHANNEL_BITBANDING_H_
#define XDRIVER_MCU_DRIVER_HEADER_DMA_DMA_PERIPHERAL_DMA_STRUCT_DMA_STRUCTREGISTERCHANNEL_BITBANDING_H_

#include <xDriver_MCU/DMA/Peripheral/xHeader/DMA_Enum.h>

typedef volatile struct
{
    volatile UBase_t ADDR [32UL];
}DMA_CH_BITBANDING_SRCENDP_t;

typedef volatile struct
{
    volatile UBase_t ADDR [32UL];
}DMA_CH_BITBANDING_DSTENDP_t;

typedef volatile struct
{
    volatile UBase_t XFERMODE [3UL];
    volatile UBase_t NXTUSEBURST;
    volatile UBase_t XFERSIZE [10UL];
    volatile UBase_t ARBSIZE [4UL];
    volatile UBase_t SRCPROT0;
    const UBase_t reserved [2UL];
    volatile UBase_t DSTPROT0;
    const UBase_t reserved1 [2UL];
    volatile UBase_t SRCSIZE [2UL];
    volatile UBase_t SRCINC [2UL];
    volatile UBase_t DSTSIZE [2UL];
    volatile UBase_t DSTINC [2UL];
}DMA_CH_BITBANDING_CTL_t;

#endif /* XDRIVER_MCU_DRIVER_HEADER_DMA_DMA_PERIPHERAL_DMA_STRUCT_DMA_STRUCTREGISTERCHANNEL_BITBANDING_H_ */
