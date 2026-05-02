/**
 *
 * @file HIB_RegisterDefines_TPCTL.h
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

#ifndef XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_TPCTL_H_
#define XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_TPCTL_H_

#include <xDriver_MCU/HIB/Peripheral/xHeader/HIB_Enum.h>

/******************************************************************************************
************************************ 21 TPCTL ********************************************
******************************************************************************************/
/*--------*/
#define HIB_TPCTL_R_WAKE_MASK    ((UBase_t) 0x00000800UL)
#define HIB_TPCTL_R_WAKE_BIT    ((UBase_t) 11UL)
#define HIB_TPCTL_R_WAKE_DIS    ((UBase_t) 0x00000000UL)
#define HIB_TPCTL_R_WAKE_ENA    ((UBase_t) 0x00000800UL)

#define HIB_TPCTL_WAKE_MASK    ((UBase_t) 0x00000001UL)
#define HIB_TPCTL_WAKE_DIS    ((UBase_t) 0x00000000UL)
#define HIB_TPCTL_WAKE_ENA    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_TPCTL_R_MEMCLR_MASK    ((UBase_t) 0x00000300UL)
#define HIB_TPCTL_R_MEMCLR_BIT    ((UBase_t) 8UL)
#define HIB_TPCTL_R_MEMCLR_NONE    ((UBase_t) 0x00000000UL)
#define HIB_TPCTL_R_MEMCLR_LOWER    ((UBase_t) 0x00000100UL)
#define HIB_TPCTL_R_MEMCLR_UPPER    ((UBase_t) 0x00000200UL)
#define HIB_TPCTL_R_MEMCLR_ALL    ((UBase_t) 0x00000300UL)

#define HIB_TPCTL_MEMCLR_MASK    ((UBase_t) 0x00000003UL)
#define HIB_TPCTL_MEMCLR_NONE    ((UBase_t) 0x00000000UL)
#define HIB_TPCTL_MEMCLR_LOWER    ((UBase_t) 0x00000001UL)
#define HIB_TPCTL_MEMCLR_UPPER    ((UBase_t) 0x00000002UL)
#define HIB_TPCTL_MEMCLR_ALL    ((UBase_t) 0x00000003UL)
/*--------*/

/*--------*/
#define HIB_TPCTL_R_TPCLR_MASK    ((UBase_t) 0x00000010UL)
#define HIB_TPCTL_R_TPCLR_BIT    ((UBase_t) 4UL)
#define HIB_TPCTL_R_TPCLR_CLEAR    ((UBase_t) 0x00000010UL)

#define HIB_TPCTL_TPCLR_MASK    ((UBase_t) 0x00000001UL)
#define HIB_TPCTL_TPCLR_CLEAR    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_TPCTL_R_TPEN_MASK    ((UBase_t) 0x00000001UL)
#define HIB_TPCTL_R_TPEN_BIT    ((UBase_t) 0UL)
#define HIB_TPCTL_R_TPEN_DIS    ((UBase_t) 0x00000000UL)
#define HIB_TPCTL_R_TPEN_ENA    ((UBase_t) 0x00000001UL)

#define HIB_TPCTL_TPEN_MASK    ((UBase_t) 0x00000001UL)
#define HIB_TPCTL_TPEN_DIS    ((UBase_t) 0x00000000UL)
#define HIB_TPCTL_TPEN_ENA    ((UBase_t) 0x00000001UL)
/*--------*/

#endif /* XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_TPCTL_H_ */
