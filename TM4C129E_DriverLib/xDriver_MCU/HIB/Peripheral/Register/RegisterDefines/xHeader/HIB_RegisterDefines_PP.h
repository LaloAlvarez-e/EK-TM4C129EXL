/**
 *
 * @file HIB_RegisterDefines_PP.h
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

#ifndef XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_PP_H_
#define XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_PP_H_

#include <xDriver_MCU/HIB/Peripheral/xHeader/HIB_Enum.h>

/******************************************************************************************
************************************ 26 PP ***********************************************
******************************************************************************************/
/*--------*/
#define HIB_PP_R_TAMPER_MASK    ((UBase_t) 0x00000002UL)
#define HIB_PP_R_TAMPER_BIT    ((UBase_t) 1UL)
#define HIB_PP_R_TAMPER_NOTPRESENT    ((UBase_t) 0x00000000UL)
#define HIB_PP_R_TAMPER_PRESENT    ((UBase_t) 0x00000002UL)

#define HIB_PP_TAMPER_MASK    ((UBase_t) 0x00000001UL)
#define HIB_PP_TAMPER_NOTPRESENT    ((UBase_t) 0x00000000UL)
#define HIB_PP_TAMPER_PRESENT    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_PP_R_WAKENC_MASK    ((UBase_t) 0x00000001UL)
#define HIB_PP_R_WAKENC_BIT    ((UBase_t) 0UL)
#define HIB_PP_R_WAKENC_PRESENT    ((UBase_t) 0x00000000UL)
#define HIB_PP_R_WAKENC_NOPIN    ((UBase_t) 0x00000001UL)

#define HIB_PP_WAKENC_MASK    ((UBase_t) 0x00000001UL)
#define HIB_PP_WAKENC_PRESENT    ((UBase_t) 0x00000000UL)
#define HIB_PP_WAKENC_NOPIN    ((UBase_t) 0x00000001UL)
/*--------*/

#endif /* XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_PP_H_ */
