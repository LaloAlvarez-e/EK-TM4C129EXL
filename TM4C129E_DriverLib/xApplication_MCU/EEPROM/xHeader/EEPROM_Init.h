/**
 *
 * @file EEPROM_Init.h
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

#ifndef XAPPLICATION_MCU_EEPROM_XHEADER_EEPROM_INIT_H_
#define XAPPLICATION_MCU_EEPROM_XHEADER_EEPROM_INIT_H_

#include <xApplication_MCU/EEPROM/Intrinsics/xHeader/EEPROM_Defines.h>

/**
 * @brief EEPROM Initialization Function
 * @section Initialization
 * @details This function reset, disable and then enable the EEPROM Peripheral.
 * Also it Obtains the max number of blocks and Worlds
 * @return Return Function Status
 * @retval EEPROM_enERROR_OK All operations are OK
 * @retval EEPROM_enERROR An operations inside the function had an error
 *
 * @code{.c}
 * main()
 * {
 *      EEPROM__enInit();
 * }
 * @endcode
 *
 * @remark This function must be call before any other EEPROM Driver function
 * @note This function can be call anytime the EEPROM peripheral needs to be re-initialize
 */
EEPROM_nERROR EEPROM__enInit (EEPROM_nMODULE enModuleArg);

/**
 * @brief EEPROM De-Initialization Function
 * @details This function reset and disable the EEPROM Peripheral.
 * @code{.c}
 * main()
 * {
 *      EEPROM__enDeInit();
 * }
 * @endcode
 * @remark This function could be call after EEPROM Initialization @ref EEPROM__enInit
 * @note This function can be call any time when the EEPROM peripheral requires to be de-Initialized
 */
EEPROM_nERROR EEPROM__enDeInit (EEPROM_nMODULE enModuleArg);

#endif /* XAPPLICATION_MCU_EEPROM_XHEADER_EEPROM_INIT_H_ */
