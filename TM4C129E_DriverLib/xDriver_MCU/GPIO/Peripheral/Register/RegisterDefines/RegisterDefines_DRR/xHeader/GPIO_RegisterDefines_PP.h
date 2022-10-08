/**
 *
 * @file GPIO_RegisterDefines_PP.h
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
 * @verbatim 9 jul. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 9 jul. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_GPIO_PERIPHERAL_REGISTER_REGISTERDEFINES_REGISTERDEFINES_DRR_XHEADER_GPIO_REGISTERDEFINES_PP_H_
#define XDRIVER_MCU_GPIO_PERIPHERAL_REGISTER_REGISTERDEFINES_REGISTERDEFINES_DRR_XHEADER_GPIO_REGISTERDEFINES_PP_H_

#include <xDriver_MCU/GPIO/Peripheral/xHeader/GPIO_Enum.h>

/******************************************************************************************
 ************************************ 30 PP *********************************************
 ******************************************************************************************/
/*----------*/
#define GPIO_PP_R_PIN_MASK    ((UBase_t) 0x00000001UL)
#define GPIO_PP_R_PIN_BIT    (0UL)
#define GPIO_PP_R_PIN_NORMAL    ((UBase_t) 0x00000000UL)
#define GPIO_PP_R_PIN_EXTENDED    ((UBase_t) 0x00000001UL)

#define GPIO_PP_PIN_MASK    ((UBase_t) 0x00000001UL)
#define GPIO_PP_PIN_NORMAL    ((UBase_t) 0x00000000UL)
#define GPIO_PP_PIN_EXTENDED    ((UBase_t) 0x00000001UL)
/*----------*/

#endif /* XDRIVER_MCU_GPIO_PERIPHERAL_REGISTER_REGISTERDEFINES_REGISTERDEFINES_DRR_XHEADER_GPIO_REGISTERDEFINES_PP_H_ */
