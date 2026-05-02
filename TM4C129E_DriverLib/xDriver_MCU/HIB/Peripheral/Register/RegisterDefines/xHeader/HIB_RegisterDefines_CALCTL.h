/**
 *
 * @file HIB_RegisterDefines_CALCTL.h
 * @copyright
 * @verbatim InDeviceMex 2026 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 6 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 6 abr. 2026    vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_CALCTL_H_
#define XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_CALCTL_H_

#include <xDriver_MCU/HIB/Peripheral/xHeader/HIB_Enum.h>

/******************************************************************************************
************************************ 13 CALCTL *******************************************
******************************************************************************************/
/*--------*/
#define HIB_CALCTL_R_CAL24_MASK    ((UBase_t) 0x00000004UL)
#define HIB_CALCTL_R_CAL24_BIT    ((UBase_t) 2UL)
#define HIB_CALCTL_R_CAL24_12H    ((UBase_t) 0x00000000UL)
#define HIB_CALCTL_R_CAL24_24H    ((UBase_t) 0x00000004UL)

#define HIB_CALCTL_CAL24_MASK    ((UBase_t) 0x00000001UL)
#define HIB_CALCTL_CAL24_12H    ((UBase_t) 0x00000000UL)
#define HIB_CALCTL_CAL24_24H    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_CALCTL_R_CALEN_MASK    ((UBase_t) 0x00000001UL)
#define HIB_CALCTL_R_CALEN_BIT    ((UBase_t) 0UL)
#define HIB_CALCTL_R_CALEN_COUNTER    ((UBase_t) 0x00000000UL)
#define HIB_CALCTL_R_CALEN_CALENDAR    ((UBase_t) 0x00000001UL)

#define HIB_CALCTL_CALEN_MASK    ((UBase_t) 0x00000001UL)
#define HIB_CALCTL_CALEN_COUNTER    ((UBase_t) 0x00000000UL)
#define HIB_CALCTL_CALEN_CALENDAR    ((UBase_t) 0x00000001UL)
/*--------*/

#endif /* XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_CALCTL_H_ */
