/**
 *
 * @file HIB_RegisterDefines_MIS.h
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

#ifndef XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_MIS_H_
#define XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_MIS_H_

#include <xDriver_MCU/HIB/Peripheral/xHeader/HIB_Enum.h>

/******************************************************************************************
************************************ 7 MIS ***********************************************
******************************************************************************************/
/*--------*/
#define HIB_MIS_R_VDDFAIL_MASK    ((UBase_t) 0x00000080UL)
#define HIB_MIS_R_VDDFAIL_BIT    ((UBase_t) 7UL)
#define HIB_MIS_R_VDDFAIL_INACTIVE    ((UBase_t) 0x00000000UL)
#define HIB_MIS_R_VDDFAIL_ACTIVE    ((UBase_t) 0x00000080UL)

#define HIB_MIS_VDDFAIL_MASK    ((UBase_t) 0x00000001UL)
#define HIB_MIS_VDDFAIL_INACTIVE    ((UBase_t) 0x00000000UL)
#define HIB_MIS_VDDFAIL_ACTIVE    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_MIS_R_RSTWK_MASK    ((UBase_t) 0x00000040UL)
#define HIB_MIS_R_RSTWK_BIT    ((UBase_t) 6UL)
#define HIB_MIS_R_RSTWK_INACTIVE    ((UBase_t) 0x00000000UL)
#define HIB_MIS_R_RSTWK_ACTIVE    ((UBase_t) 0x00000040UL)

#define HIB_MIS_RSTWK_MASK    ((UBase_t) 0x00000001UL)
#define HIB_MIS_RSTWK_INACTIVE    ((UBase_t) 0x00000000UL)
#define HIB_MIS_RSTWK_ACTIVE    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_MIS_R_PADIOWK_MASK    ((UBase_t) 0x00000020UL)
#define HIB_MIS_R_PADIOWK_BIT    ((UBase_t) 5UL)
#define HIB_MIS_R_PADIOWK_INACTIVE    ((UBase_t) 0x00000000UL)
#define HIB_MIS_R_PADIOWK_ACTIVE    ((UBase_t) 0x00000020UL)

#define HIB_MIS_PADIOWK_MASK    ((UBase_t) 0x00000001UL)
#define HIB_MIS_PADIOWK_INACTIVE    ((UBase_t) 0x00000000UL)
#define HIB_MIS_PADIOWK_ACTIVE    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_MIS_R_WC_MASK    ((UBase_t) 0x00000010UL)
#define HIB_MIS_R_WC_BIT    ((UBase_t) 4UL)
#define HIB_MIS_R_WC_INACTIVE    ((UBase_t) 0x00000000UL)
#define HIB_MIS_R_WC_ACTIVE    ((UBase_t) 0x00000010UL)

#define HIB_MIS_WC_MASK    ((UBase_t) 0x00000001UL)
#define HIB_MIS_WC_INACTIVE    ((UBase_t) 0x00000000UL)
#define HIB_MIS_WC_ACTIVE    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_MIS_R_EXTW_MASK    ((UBase_t) 0x00000008UL)
#define HIB_MIS_R_EXTW_BIT    ((UBase_t) 3UL)
#define HIB_MIS_R_EXTW_INACTIVE    ((UBase_t) 0x00000000UL)
#define HIB_MIS_R_EXTW_ACTIVE    ((UBase_t) 0x00000008UL)

#define HIB_MIS_EXTW_MASK    ((UBase_t) 0x00000001UL)
#define HIB_MIS_EXTW_INACTIVE    ((UBase_t) 0x00000000UL)
#define HIB_MIS_EXTW_ACTIVE    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_MIS_R_LOWBAT_MASK    ((UBase_t) 0x00000004UL)
#define HIB_MIS_R_LOWBAT_BIT    ((UBase_t) 2UL)
#define HIB_MIS_R_LOWBAT_INACTIVE    ((UBase_t) 0x00000000UL)
#define HIB_MIS_R_LOWBAT_ACTIVE    ((UBase_t) 0x00000004UL)

#define HIB_MIS_LOWBAT_MASK    ((UBase_t) 0x00000001UL)
#define HIB_MIS_LOWBAT_INACTIVE    ((UBase_t) 0x00000000UL)
#define HIB_MIS_LOWBAT_ACTIVE    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_MIS_R_RTCALT0_MASK    ((UBase_t) 0x00000001UL)
#define HIB_MIS_R_RTCALT0_BIT    ((UBase_t) 0UL)
#define HIB_MIS_R_RTCALT0_INACTIVE    ((UBase_t) 0x00000000UL)
#define HIB_MIS_R_RTCALT0_ACTIVE    ((UBase_t) 0x00000001UL)

#define HIB_MIS_RTCALT0_MASK    ((UBase_t) 0x00000001UL)
#define HIB_MIS_RTCALT0_INACTIVE    ((UBase_t) 0x00000000UL)
#define HIB_MIS_RTCALT0_ACTIVE    ((UBase_t) 0x00000001UL)
/*--------*/

#endif /* XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_MIS_H_ */
