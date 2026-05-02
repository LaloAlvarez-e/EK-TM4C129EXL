/**
 *
 * @file HIB_RegisterDefines_IC.h
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

#ifndef XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_IC_H_
#define XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_IC_H_

#include <xDriver_MCU/HIB/Peripheral/xHeader/HIB_Enum.h>

/******************************************************************************************
************************************ 8 IC ************************************************
******************************************************************************************/
/*--------*/
#define HIB_IC_R_VDDFAIL_MASK    ((UBase_t) 0x00000080UL)
#define HIB_IC_R_VDDFAIL_BIT    ((UBase_t) 7UL)
#define HIB_IC_R_VDDFAIL_CLEAR    ((UBase_t) 0x00000080UL)

#define HIB_IC_VDDFAIL_MASK    ((UBase_t) 0x00000001UL)
#define HIB_IC_VDDFAIL_CLEAR    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_IC_R_RSTWK_MASK    ((UBase_t) 0x00000040UL)
#define HIB_IC_R_RSTWK_BIT    ((UBase_t) 6UL)
#define HIB_IC_R_RSTWK_CLEAR    ((UBase_t) 0x00000040UL)

#define HIB_IC_RSTWK_MASK    ((UBase_t) 0x00000001UL)
#define HIB_IC_RSTWK_CLEAR    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_IC_R_PADIOWK_MASK    ((UBase_t) 0x00000020UL)
#define HIB_IC_R_PADIOWK_BIT    ((UBase_t) 5UL)
#define HIB_IC_R_PADIOWK_CLEAR    ((UBase_t) 0x00000020UL)

#define HIB_IC_PADIOWK_MASK    ((UBase_t) 0x00000001UL)
#define HIB_IC_PADIOWK_CLEAR    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_IC_R_WC_MASK    ((UBase_t) 0x00000010UL)
#define HIB_IC_R_WC_BIT    ((UBase_t) 4UL)
#define HIB_IC_R_WC_CLEAR    ((UBase_t) 0x00000010UL)

#define HIB_IC_WC_MASK    ((UBase_t) 0x00000001UL)
#define HIB_IC_WC_CLEAR    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_IC_R_EXTW_MASK    ((UBase_t) 0x00000008UL)
#define HIB_IC_R_EXTW_BIT    ((UBase_t) 3UL)
#define HIB_IC_R_EXTW_CLEAR    ((UBase_t) 0x00000008UL)

#define HIB_IC_EXTW_MASK    ((UBase_t) 0x00000001UL)
#define HIB_IC_EXTW_CLEAR    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_IC_R_LOWBAT_MASK    ((UBase_t) 0x00000004UL)
#define HIB_IC_R_LOWBAT_BIT    ((UBase_t) 2UL)
#define HIB_IC_R_LOWBAT_CLEAR    ((UBase_t) 0x00000004UL)

#define HIB_IC_LOWBAT_MASK    ((UBase_t) 0x00000001UL)
#define HIB_IC_LOWBAT_CLEAR    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_IC_R_RTCALT0_MASK    ((UBase_t) 0x00000001UL)
#define HIB_IC_R_RTCALT0_BIT    ((UBase_t) 0UL)
#define HIB_IC_R_RTCALT0_CLEAR    ((UBase_t) 0x00000001UL)

#define HIB_IC_RTCALT0_MASK    ((UBase_t) 0x00000001UL)
#define HIB_IC_RTCALT0_CLEAR    ((UBase_t) 0x00000001UL)
/*--------*/

#endif /* XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_IC_H_ */

