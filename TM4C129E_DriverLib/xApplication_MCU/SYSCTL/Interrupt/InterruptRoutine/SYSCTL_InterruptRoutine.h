/**
 *
 * @file SYSCTL_InterruptRoutine.h
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
 * @verbatim 12 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 12 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef XAPPLICATION_MCU_SYSCTL_INTERRUPT_INTERRUPTROUTINE_SYSCTL_INTERRUPTROUTINE_H_
#define XAPPLICATION_MCU_SYSCTL_INTERRUPT_INTERRUPTROUTINE_SYSCTL_INTERRUPTROUTINE_H_

#include <xApplication_MCU/SYSCTL/Intrinsics/xHeader/SYSCTL_Defines.h>
#include <xApplication_MCU/SYSCTL/Interrupt/InterruptRoutine/xHeader/SYSCTL_InterruptRoutine_Vector.h>

SYSCTL_pvfIRQVectorHandler_t SYSCTL__pvfGetIRQVectorHandler(void);
SYSCTL_pvfIRQVectorHandler_t* SYSCTL__pvfGetIRQVectorHandlerPointer(void);

#endif /* XAPPLICATION_MCU_SYSCTL_INTERRUPT_INTERRUPTROUTINE_SYSCTL_INTERRUPTROUTINE_H_ */
