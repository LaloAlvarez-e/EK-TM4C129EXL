/**
 *
 * @file EEPROM_Ready.h
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

#ifndef XAPPLICATION_MCU_EEPROM_INTRINSICS_XHEADER_EEPROM_READY_H_
#define XAPPLICATION_MCU_EEPROM_INTRINSICS_XHEADER_EEPROM_READY_H_

#include <xApplication_MCU/EEPROM/Intrinsics/xHeader/EEPROM_Defines.h>

EEPROM_nERROR EEPROM__enSetReadyOnRunMode(EEPROM_nMODULE enModuleArg);
EEPROM_nERROR EEPROM__enClearReadyOnRunMode(EEPROM_nMODULE enModuleArg);
EEPROM_nERROR EEPROM__enReset(EEPROM_nMODULE enModuleArg);
EEPROM_nERROR EEPROM__enIsReady(EEPROM_nMODULE enModuleArg, EEPROM_nBOOLEAN* penReadyArg);

#endif /* XAPPLICATION_MCU_EEPROM_INTRINSICS_XHEADER_EEPROM_READY_H_ */
