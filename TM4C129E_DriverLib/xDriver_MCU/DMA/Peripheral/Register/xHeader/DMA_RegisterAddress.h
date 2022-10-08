/**
 *
 * @file DMA_RegisterAddress.h
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
 * Date           Author     Version     Description
 * 28 jul. 2020     vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_DRIVER_HEADER_DMA_DMA_PERIPHERAL_DMA_REGISTER_DMA_REGISTERADDRESS_H_
#define XDRIVER_MCU_DRIVER_HEADER_DMA_DMA_PERIPHERAL_DMA_REGISTER_DMA_REGISTERADDRESS_H_

#include <xDriver_MCU/DMA/Peripheral/xHeader/DMA_Enum.h>

#define DMA_BASE    ((UBase_t) 0x400FF000UL)
#define DMA_OFFSET    ((UBase_t) 0x000FF000UL)

#define DMA_BITBANDING_BASE    ((UBase_t) 0x42000000UL)

#define DMA_STAT_OFFSET    ((UBase_t) 0x00000000UL)
#define DMA_CFG_OFFSET    ((UBase_t) 0x00000004UL)
#define DMA_CTLBASE_OFFSET    ((UBase_t) 0x00000008UL)
#define DMA_ALTBASE_OFFSET    ((UBase_t) 0x0000000CUL)
#define DMA_CH_WAITSTAT_OFFSET    ((UBase_t) 0x00000010UL)
#define DMA_CH_SWREQ_OFFSET    ((UBase_t) 0x00000014UL)
#define DMA_CH_USEBURSTSET_OFFSET    ((UBase_t) 0x00000018UL)
#define DMA_CH_USEBURSTCLR_OFFSET    ((UBase_t) 0x0000001CUL)
#define DMA_CH_REQMASKSET_OFFSET    ((UBase_t) 0x00000020UL)
#define DMA_CH_REQMASKCLR_OFFSET    ((UBase_t) 0x00000024UL)
#define DMA_CH_ENASET_OFFSET    ((UBase_t) 0x00000028UL)
#define DMA_CH_ENACLR_OFFSET    ((UBase_t) 0x0000002CUL)
#define DMA_CH_ALTSET_OFFSET    ((UBase_t) 0x00000030UL)
#define DMA_CH_ALTCLR_OFFSET    ((UBase_t) 0x00000034UL)
#define DMA_CH_PRIOSET_OFFSET    ((UBase_t) 0x00000038UL)
#define DMA_CH_PRIOCLR_OFFSET    ((UBase_t) 0x0000003CUL)
#define DMA_ERRCLR_OFFSET    ((UBase_t) 0x0000004CUL)
#define DMA_CH_ASGN_OFFSET    ((UBase_t) 0x00000500UL)
#define DMA_CH_IS_OFFSET    ((UBase_t) 0x00000504UL)
#define DMA_CH_MAP_OFFSET    ((UBase_t) 0x00000510UL)
#define DMA_CH_MAP0_OFFSET    ((UBase_t) 0x00000510UL)
#define DMA_CH_MAP1_OFFSET    ((UBase_t) 0x00000514UL)
#define DMA_CH_MAP2_OFFSET    ((UBase_t) 0x00000518UL)
#define DMA_CH_MAP3_OFFSET    ((UBase_t) 0x0000051CUL)
#define DMA_PeriphID0_OFFSET    ((UBase_t) 0x00000FE0UL)
#define DMA_PeriphID1_OFFSET    ((UBase_t) 0x00000FE4UL)
#define DMA_PeriphID2_OFFSET    ((UBase_t) 0x00000FE8UL)
#define DMA_PeriphID3_OFFSET    ((UBase_t) 0x00000FECUL)
#define DMA_PeriphID4_OFFSET    ((UBase_t) 0x00000FD0UL)
#define DMA_PCellID0_OFFSET    ((UBase_t) 0x00000FF0UL)
#define DMA_PCellID1_OFFSET    ((UBase_t) 0x00000FF4UL)
#define DMA_PCellID2_OFFSET    ((UBase_t) 0x00000FF8UL)
#define DMA_PCellID3_OFFSET    ((UBase_t) 0x00000FFCUL)

#endif /* XDRIVER_MCU_DRIVER_HEADER_DMA_DMA_PERIPHERAL_DMA_REGISTER_DMA_REGISTERADDRESS_H_ */
