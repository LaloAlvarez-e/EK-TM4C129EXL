/**
 *
 * @file GPIO_InterruptVector.h
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

#ifndef XAPPLICATION_MCU_GPIO_INTERRUPT_XHEADER_GPIO_INTERRUPTVECTOR_H_
#define XAPPLICATION_MCU_GPIO_INTERRUPT_XHEADER_GPIO_INTERRUPTVECTOR_H_

#include <xApplication_MCU/GPIO/Intrinsics/xHeader/GPIO_Defines.h>

void GPIO__vEnInterruptVector(GPIO_nPORT enPort, GPIO_nPRIORITY enGPIOPriority);
void GPIO__vDisInterruptVector(GPIO_nPORT enPort);

void GPIO__vDisInterruptVectorPin(GPIO_nPORT enPort, GPIO_nPIN_NUMBER enPinNumber);
void GPIO__vEnInterruptVectorPin(GPIO_nPORT enPort, GPIO_nPIN_NUMBER enPinNumber, GPIO_nPRIORITY enGPIOPriority);

#endif /* XAPPLICATION_MCU_GPIO_INTERRUPT_XHEADER_GPIO_INTERRUPTVECTOR_H_ */
