/**
 *
 * @file HIB_InterruptRegisterIRQVector.h
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

#ifndef XAPPLICATION_MCU_HIB_INTERRUPT_INTERRUPTREGISTER_XHEADER_HIB_INTERRUPTREGISTERIRQVECTOR_H_
#define XAPPLICATION_MCU_HIB_INTERRUPT_INTERRUPTREGISTER_XHEADER_HIB_INTERRUPTREGISTERIRQVECTOR_H_

#include <xApplication_MCU/HIB/Intrinsics/xHeader/HIB_Defines.h>

HIB_nERROR HIB__enRegisterIRQVectorHandler(HIB_nMODULE enModuleArg, HIB_pvfIRQVectorHandler_t pfIrqVectorHandlerArg);

#endif /* XAPPLICATION_MCU_HIB_INTERRUPT_INTERRUPTREGISTER_XHEADER_HIB_INTERRUPTREGISTERIRQVECTOR_H_ */
