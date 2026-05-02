/**
 *
 * @file HIB_RegisterDefines_LOCK.h
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

#ifndef XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_LOCK_H_
#define XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_LOCK_H_

#include <xDriver_MCU/HIB/Peripheral/xHeader/HIB_Enum.h>

/******************************************************************************************
************************************ 20 LOCK *********************************************
******************************************************************************************/
/*--------*/
#define HIB_LOCK_R_HIBLOCK_MASK    ((UBase_t) 0xFFFFFFFFUL)
#define HIB_LOCK_R_HIBLOCK_BIT    ((UBase_t) 0UL)
#define HIB_LOCK_R_HIBLOCK_KEY    ((UBase_t) 0xA3359554UL)
#define HIB_LOCK_R_HIBLOCK_LOCK    ((UBase_t) 0x00000001UL)
#define HIB_LOCK_R_HIBLOCK_UNLOCK    ((UBase_t) 0x00000000UL)

#define HIB_LOCK_HIBLOCK_MASK    ((UBase_t) 0xFFFFFFFFUL)
#define HIB_LOCK_HIBLOCK_KEY    ((UBase_t) 0xA3359554UL)
#define HIB_LOCK_HIBLOCK_LOCK    ((UBase_t) 0x00000001UL)
#define HIB_LOCK_HIBLOCK_UNLOCK    ((UBase_t) 0x00000000UL)
/*--------*/

#endif /* XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_LOCK_H_ */
