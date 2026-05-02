/**
 *
 * @file HIB_InterruptRoutine.h
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

#ifndef XAPPLICATION_MCU_HIB_INTERRUPT_INTERRUPTROUTINE_HIB_INTERRUPTROUTINE_H_
#define XAPPLICATION_MCU_HIB_INTERRUPT_INTERRUPTROUTINE_HIB_INTERRUPTROUTINE_H_

#include <xApplication_MCU/HIB/Intrinsics/xHeader/HIB_Defines.h>
#include <xApplication_MCU/HIB/Interrupt/InterruptRoutine/xHeader/HIB_InterruptRoutine_Vector.h>

HIB_pvfIRQVectorHandler_t HIB__pvfGetIRQVectorHandler(HIB_nMODULE enModuleArg);
HIB_pvfIRQVectorHandler_t* HIB__pvfGetIRQVectorHandlerPointer(HIB_nMODULE enModuleArg);

#endif /* XAPPLICATION_MCU_HIB_INTERRUPT_INTERRUPTROUTINE_HIB_INTERRUPTROUTINE_H_ */
