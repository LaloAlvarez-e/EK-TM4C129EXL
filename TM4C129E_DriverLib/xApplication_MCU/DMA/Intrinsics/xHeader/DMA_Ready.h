/**
 *
 * @file DMA_Ready.h
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
 * @verbatim 10 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 10 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef XAPPLICATION_MCU_DMA_INTRINSICS_XHEADER_DMA_READY_H_
#define XAPPLICATION_MCU_DMA_INTRINSICS_XHEADER_DMA_READY_H_

#include <xApplication_MCU/DMA/Intrinsics/xHeader/DMA_Defines.h>

DMA_nERROR DMA__enSetReadyOnRunMode(DMA_nMODULE enModuleArg);
DMA_nERROR DMA__enClearReadyOnRunMode(DMA_nMODULE enModuleArg);
DMA_nERROR DMA__enReset(DMA_nMODULE enModuleArg);
DMA_nERROR DMA__enIsReady(DMA_nMODULE enModuleArg, DMA_nBOOLEAN* penReadyArg);

#endif /* XAPPLICATION_MCU_DMA_INTRINSICS_XHEADER_DMA_READY_H_ */
