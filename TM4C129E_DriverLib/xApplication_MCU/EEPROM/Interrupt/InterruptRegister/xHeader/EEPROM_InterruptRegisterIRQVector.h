/**
 *
 * @file EEPROM_InterruptRegisterIRQVector.h
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

#ifndef XAPPLICATION_MCU_EEPROM_INTERRUPT_INTERRUPTREGISTER_XHEADER_EEPROM_INTERRUPTREGISTERIRQVECTOR_H_
#define XAPPLICATION_MCU_EEPROM_INTERRUPT_INTERRUPTREGISTER_XHEADER_EEPROM_INTERRUPTREGISTERIRQVECTOR_H_

#include <xApplication_MCU/EEPROM/Intrinsics/xHeader/EEPROM_Defines.h>

EEPROM_nERROR EEPROM__enRegisterIRQVectorHandler(EEPROM_nMODULE enModuleArg, EEPROM_pvfIRQSourceHandler_t pfIrqVectorHandlerArg);

#endif /* XAPPLICATION_MCU_EEPROM_INTERRUPT_INTERRUPTREGISTER_XHEADER_EEPROM_INTERRUPTREGISTERIRQVECTOR_H_ */
