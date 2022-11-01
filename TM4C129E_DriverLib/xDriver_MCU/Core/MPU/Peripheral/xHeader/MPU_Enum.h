/**
 *
 * @file MPU_Enum.h
 * @copyright
 * @verbatim InDeviceMex 2020 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 19 jun. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 19 jun. 2020     vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_DRIVER_HEADER_MPU_PERIPHERAL_MPU_ENUM_H_
#define XDRIVER_MCU_DRIVER_HEADER_MPU_PERIPHERAL_MPU_ENUM_H_

#include <xDriver_MCU/Common/xHeader/MCU_Enum.h>

typedef enum
{
    MPU_enOK = 0UL,
    MPU_enERROR = 1UL,
    MPU_enERROR_UNDEF = UNDEF_VALUE,
}MPU_nSTATUS;

#endif /* XDRIVER_MCU_DRIVER_HEADER_MPU_PERIPHERAL_MPU_ENUM_H_ */
