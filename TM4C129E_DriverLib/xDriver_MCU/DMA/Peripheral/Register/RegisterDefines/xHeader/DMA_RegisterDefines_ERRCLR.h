/**
 *
 * @file DMA_RegisterDefines_ERRCLR.h
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

#ifndef XDRIVER_MCU_DRIVER_HEADER_DMA_DMA_PERIPHERAL_DMA_REGISTER_DMA_REGISTERDEFINES_DMA_REGISTERDEFINES_ERRCLR_H_
#define XDRIVER_MCU_DRIVER_HEADER_DMA_DMA_PERIPHERAL_DMA_REGISTER_DMA_REGISTERDEFINES_DMA_REGISTERDEFINES_ERRCLR_H_

#include <xDriver_MCU/DMA/Peripheral/xHeader/DMA_Enum.h>

/**************************************************************************************
************************************* 20 ERRCLR *************************************
****************************************************************************************/

/*--------*/
#define DMA_ERRCLR_R_ERRCLR_MASK    ((UBase_t) 0x00000001UL)
#define DMA_ERRCLR_R_ERRCLR_BIT    ((UBase_t) 0UL)
#define DMA_ERRCLR_R_ERRCLR_NOERROR    ((UBase_t) 0x00000000UL)
#define DMA_ERRCLR_R_ERRCLR_ERROR    ((UBase_t) 0x00000001UL)
#define DMA_ERRCLR_R_ERRCLR_CLEAR    ((UBase_t) 0x00000001UL)

#define DMA_ERRCLR_ERRCLR_MASK    ((UBase_t) 0x00000001UL)
#define DMA_ERRCLR_ERRCLR_NOERROR    ((UBase_t) 0x00000000UL)
#define DMA_ERRCLR_ERRCLR_ERROR    ((UBase_t) 0x00000001UL)
#define DMA_ERRCLR_ERRCLR_CLEAR    ((UBase_t) 0x00000001UL)
/*--------*/

#endif /* XDRIVER_MCU_DRIVER_HEADER_DMA_DMA_PERIPHERAL_DMA_REGISTER_DMA_REGISTERDEFINES_DMA_REGISTERDEFINES_ERRCLR_H_ */
