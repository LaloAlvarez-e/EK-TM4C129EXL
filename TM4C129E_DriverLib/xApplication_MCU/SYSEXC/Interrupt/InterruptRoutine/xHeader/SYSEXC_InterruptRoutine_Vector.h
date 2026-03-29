/**
 *
 * @file SYSEXC_InterruptRoutine_Vector.h
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
 * @verbatim 11 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 11 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef XAPPLICATION_MCU_SYSEXC_INTERRUPT_INTERRUPTROUTINE_XHEADER_SYSEXC_INTERRUPTROUTINE_VECTOR_H_
#define XAPPLICATION_MCU_SYSEXC_INTERRUPT_INTERRUPTROUTINE_XHEADER_SYSEXC_INTERRUPTROUTINE_VECTOR_H_

#include <xApplication_MCU/Core/SCB/Intrinsics/xHeader/SCB_Defines.h>

extern UBase_t SYSEXC_puxContext[8UL];

void SYSEXC__vIRQVectorHandler(void);
void SYSEXC__vIRQVectorHandlerReport(uintptr_t uptrModuleArg, void* pvArgument);
void SYSEXC__vIRQVectorHandlerCustom(uintptr_t uptrModuleArg, void* pvArgument);

#endif /* XAPPLICATION_MCU_SYSEXC_INTERRUPT_INTERRUPTROUTINE_XHEADER_SYSEXC_INTERRUPTROUTINE_VECTOR_H_ */
