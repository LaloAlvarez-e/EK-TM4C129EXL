/**
 *
 * @file HIB_RegisterDefines_CAL1.h
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

#ifndef XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_CAL1_H_
#define XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_CAL1_H_

#include <xDriver_MCU/HIB/Peripheral/xHeader/HIB_Enum.h>

/******************************************************************************************
************************************ 15 CAL1 *********************************************
******************************************************************************************/
/*--------*/
#define HIB_CAL1_R_VALID_MASK    ((UBase_t) 0x80000000UL)
#define HIB_CAL1_R_VALID_BIT    ((UBase_t) 31UL)
#define HIB_CAL1_R_VALID_PROGRESS    ((UBase_t) 0x00000000UL)
#define HIB_CAL1_R_VALID_READY    ((UBase_t) 0x80000000UL)

#define HIB_CAL1_VALID_MASK    ((UBase_t) 0x00000001UL)
#define HIB_CAL1_VALID_PROGRESS    ((UBase_t) 0x00000000UL)
#define HIB_CAL1_VALID_READY    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_CAL1_R_DOW_MASK    ((UBase_t) 0x07000000UL)
#define HIB_CAL1_R_DOW_BIT    ((UBase_t) 24UL)

#define HIB_CAL1_DOW_MASK    ((UBase_t) 0x00000007UL)
/*--------*/

/*--------*/
#define HIB_CAL1_R_YEAR_MASK    ((UBase_t) 0x007F0000UL)
#define HIB_CAL1_R_YEAR_BIT    ((UBase_t) 16UL)

#define HIB_CAL1_YEAR_MASK    ((UBase_t) 0x0000007FUL)
/*--------*/

/*--------*/
#define HIB_CAL1_R_MON_MASK    ((UBase_t) 0x00000F00UL)
#define HIB_CAL1_R_MON_BIT    ((UBase_t) 8UL)

#define HIB_CAL1_MON_MASK    ((UBase_t) 0x0000000FUL)
/*--------*/

/*--------*/
#define HIB_CAL1_R_DOM_MASK    ((UBase_t) 0x0000001FUL)
#define HIB_CAL1_R_DOM_BIT    ((UBase_t) 0UL)

#define HIB_CAL1_DOM_MASK    ((UBase_t) 0x0000001FUL)
/*--------*/

#endif /* XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_CAL1_H_ */
