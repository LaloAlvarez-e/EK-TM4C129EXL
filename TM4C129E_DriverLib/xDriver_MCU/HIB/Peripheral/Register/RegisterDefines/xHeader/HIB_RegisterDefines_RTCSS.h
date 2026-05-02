/**
 *
 * @file HIB_RegisterDefines_RTCSS.h
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

#ifndef XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_RTCSS_H_
#define XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_RTCSS_H_

#include <xDriver_MCU/HIB/Peripheral/xHeader/HIB_Enum.h>

/******************************************************************************************
************************************ 10 RTCSS ********************************************
******************************************************************************************/
/*--------*/
#define HIB_RTCSS_R_RTCSSM_MASK    ((UBase_t) 0x7FFF0000UL)
#define HIB_RTCSS_R_RTCSSM_BIT    ((UBase_t) 16UL)

#define HIB_RTCSS_RTCSSM_MASK    ((UBase_t) 0x00007FFFUL)
/*--------*/

/*--------*/
#define HIB_RTCSS_R_RTCSSC_MASK    ((UBase_t) 0x00007FFFUL)
#define HIB_RTCSS_R_RTCSSC_BIT    ((UBase_t) 0UL)

#define HIB_RTCSS_RTCSSC_MASK    ((UBase_t) 0x00007FFFUL)
/*--------*/

#endif /* XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_RTCSS_H_ */
