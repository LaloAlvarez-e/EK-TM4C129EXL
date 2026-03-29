/**
 *
 * @file SCB_InterruptRoutine_NMI.h
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
 * @verbatim 18 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 18 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef XAPPLICATION_MCU_CORE_SCB_INTERRUPT_INTERRUPTROUTINE_XHEADER_SCB_INTERRUPTROUTINE_NMI_H_
#define XAPPLICATION_MCU_CORE_SCB_INTERRUPT_INTERRUPTROUTINE_XHEADER_SCB_INTERRUPTROUTINE_NMI_H_

#include <xApplication_MCU/Core/SCB/Intrinsics/xHeader/SCB_Defines.h>

void NMI__vIRQVectorHandler(void);
void NMI__vIRQVectorHandlerReport(uintptr_t uptrModuleArg, void* pvArgument);
void NMI__vIRQVectorHandlerCustom(uintptr_t uptrModuleArg, void* pvArgument);

#endif /* XAPPLICATION_MCU_CORE_SCB_INTERRUPT_INTERRUPTROUTINE_XHEADER_SCB_INTERRUPTROUTINE_NMI_H_ */
