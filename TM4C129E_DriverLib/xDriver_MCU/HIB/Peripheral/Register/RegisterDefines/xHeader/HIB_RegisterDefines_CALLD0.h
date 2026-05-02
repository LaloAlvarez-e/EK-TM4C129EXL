/**
 *
 * @file HIB_RegisterDefines_CALLD0.h
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

#ifndef XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_CALLD0_H_
#define XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_CALLD0_H_

#include <xDriver_MCU/HIB/Peripheral/xHeader/HIB_Enum.h>

/******************************************************************************************
************************************ 16 CALLD0 *******************************************
******************************************************************************************/
/*--------*/
#define HIB_CALLD0_R_AMPM_MASK    ((UBase_t) 0x00400000UL)
#define HIB_CALLD0_R_AMPM_BIT    ((UBase_t) 22UL)
#define HIB_CALLD0_R_AMPM_AM    ((UBase_t) 0x00000000UL)
#define HIB_CALLD0_R_AMPM_PM    ((UBase_t) 0x00400000UL)

#define HIB_CALLD0_AMPM_MASK    ((UBase_t) 0x00000001UL)
#define HIB_CALLD0_AMPM_AM    ((UBase_t) 0x00000000UL)
#define HIB_CALLD0_AMPM_PM    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_CALLD0_R_HR_MASK    ((UBase_t) 0x001F0000UL)
#define HIB_CALLD0_R_HR_BIT    ((UBase_t) 16UL)

#define HIB_CALLD0_HR_MASK    ((UBase_t) 0x0000001FUL)
/*--------*/

/*--------*/
#define HIB_CALLD0_R_MIN_MASK    ((UBase_t) 0x00003F00UL)
#define HIB_CALLD0_R_MIN_BIT    ((UBase_t) 8UL)

#define HIB_CALLD0_MIN_MASK    ((UBase_t) 0x0000003FUL)
/*--------*/

/*--------*/
#define HIB_CALLD0_R_SEC_MASK    ((UBase_t) 0x0000003FUL)
#define HIB_CALLD0_R_SEC_BIT    ((UBase_t) 0UL)

#define HIB_CALLD0_SEC_MASK    ((UBase_t) 0x0000003FUL)
/*--------*/

#endif /* XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_CALLD0_H_ */
