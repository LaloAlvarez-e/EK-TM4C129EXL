/**
 *
 * @file EEPROM_InterruptRoutine.h
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

#ifndef XAPPLICATION_MCU_EEPROM_INTERRUPT_INTERRUPTROUTINE_EEPROM_INTERRUPTROUTINE_H_
#define XAPPLICATION_MCU_EEPROM_INTERRUPT_INTERRUPTROUTINE_EEPROM_INTERRUPTROUTINE_H_

#include <xApplication_MCU/EEPROM/Interrupt/InterruptRoutine/xHeader/EEPROM_InterruptRoutine_Vector.h>

EEPROM_pvfIRQSourceHandler_t EEPROM__pvfGetIRQVectorHandler(EEPROM_nMODULE enModuleArg);
EEPROM_pvfIRQSourceHandler_t* EEPROM__pvfGetIRQVectorHandlerPointer(EEPROM_nMODULE enModuleArg);

#endif /* XAPPLICATION_MCU_EEPROM_INTERRUPT_INTERRUPTROUTINE_EEPROM_INTERRUPTROUTINE_H_ */
