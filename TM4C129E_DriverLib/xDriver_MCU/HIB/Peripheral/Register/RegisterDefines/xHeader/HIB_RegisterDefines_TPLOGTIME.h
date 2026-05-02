/**
 *
 * @file HIB_RegisterDefines_TPLOGTIME.h
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

#ifndef XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_TPLOGTIME_H_
#define XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_TPLOGTIME_H_

#include <xDriver_MCU/HIB/Peripheral/xHeader/HIB_Enum.h>

/******************************************************************************************
************************************ 24 TPLOGTIME ****************************************
******************************************************************************************/
/*--------*/
#define HIB_TPLOGTIME_R_TIME_MASK    ((UBase_t) 0xFFFFFFFFUL)
#define HIB_TPLOGTIME_R_TIME_BIT    ((UBase_t) 0UL)

#define HIB_TPLOGTIME_TIME_MASK    ((UBase_t) 0xFFFFFFFFUL)
/*--------*/

/*--------*/
#define HIB_TPLOGTIME_R_YEAR_MASK    ((UBase_t) 0xFC000000UL)
#define HIB_TPLOGTIME_R_YEAR_BIT    ((UBase_t) 26UL)

#define HIB_TPLOGTIME_YEAR_MASK    ((UBase_t) 0x0000003FUL)
/*--------*/

/*--------*/
#define HIB_TPLOGTIME_R_MON_MASK    ((UBase_t) 0x03C00000UL)
#define HIB_TPLOGTIME_R_MON_BIT    ((UBase_t) 22UL)

#define HIB_TPLOGTIME_MON_MASK    ((UBase_t) 0x0000000FUL)
/*--------*/

/*--------*/
#define HIB_TPLOGTIME_R_DOM_MASK    ((UBase_t) 0x003E0000UL)
#define HIB_TPLOGTIME_R_DOM_BIT    ((UBase_t) 17UL)

#define HIB_TPLOGTIME_DOM_MASK    ((UBase_t) 0x0000001FUL)
/*--------*/

/*--------*/
#define HIB_TPLOGTIME_R_HR_MASK    ((UBase_t) 0x0001F000UL)
#define HIB_TPLOGTIME_R_HR_BIT    ((UBase_t) 12UL)

#define HIB_TPLOGTIME_HR_MASK    ((UBase_t) 0x0000001FUL)
/*--------*/

/*--------*/
#define HIB_TPLOGTIME_R_MIN_MASK    ((UBase_t) 0x00000FC0UL)
#define HIB_TPLOGTIME_R_MIN_BIT    ((UBase_t) 6UL)

#define HIB_TPLOGTIME_MIN_MASK    ((UBase_t) 0x0000003FUL)
/*--------*/

/*--------*/
#define HIB_TPLOGTIME_R_SEC_MASK    ((UBase_t) 0x0000003FUL)
#define HIB_TPLOGTIME_R_SEC_BIT    ((UBase_t) 0UL)

#define HIB_TPLOGTIME_SEC_MASK    ((UBase_t) 0x0000003FUL)
/*--------*/

#endif /* XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_TPLOGTIME_H_ */

