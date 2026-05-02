/**
 *
 * @file HIB_InterruptRoutine_Source.h
 * @copyright
 * @verbatim InDeviceMex 2026 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 6 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 6 abr. 2026    vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_DRIVER_HEADER_HIB_HIB_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_XHEADER_HIB_INTERRUPTROUTINE_SOURCE_H_
#define XDRIVER_MCU_DRIVER_HEADER_HIB_HIB_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_XHEADER_HIB_INTERRUPTROUTINE_SOURCE_H_

#include <xDriver_MCU/HIB/Peripheral/xHeader/HIB_Enum.h>

HIB_pvfIRQSourceHandler_t HIB__pvfGetIRQSourceHandler(HIB_nMODULE enModuleArg, HIB_nINT enInterruptSourceArg);
HIB_pvfIRQSourceHandler_t* HIB__pvfGetIRQSourceHandlerPointer(HIB_nMODULE enModuleArg, HIB_nINT enInterruptSourceArg);

#endif /* XDRIVER_MCU_DRIVER_HEADER_HIB_HIB_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_XHEADER_HIB_INTERRUPTROUTINE_SOURCE_H_ */
