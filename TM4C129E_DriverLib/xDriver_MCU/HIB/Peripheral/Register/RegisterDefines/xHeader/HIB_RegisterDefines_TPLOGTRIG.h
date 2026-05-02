/**
 *
 * @file HIB_RegisterDefines_TPLOGTRIG.h
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

#ifndef XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_TPLOGTRIG_H_
#define XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_TPLOGTRIG_H_

#include <xDriver_MCU/HIB/Peripheral/xHeader/HIB_Enum.h>

/******************************************************************************************
************************************ 25 TPLOGTRIG ****************************************
******************************************************************************************/
/*--------*/
#define HIB_TPLOGTRIG_R_XOSC_MASK    ((UBase_t) 0x00010000UL)
#define HIB_TPLOGTRIG_R_XOSC_BIT    ((UBase_t) 16UL)
#define HIB_TPLOGTRIG_R_XOSC_DEFAULT    ((UBase_t) 0x00000000UL)
#define HIB_TPLOGTRIG_R_XOSC_FAIL    ((UBase_t) 0x00010000UL)

#define HIB_TPLOGTRIG_XOSC_MASK    ((UBase_t) 0x00000001UL)
#define HIB_TPLOGTRIG_XOSC_DEFAULT    ((UBase_t) 0x00000000UL)
#define HIB_TPLOGTRIG_XOSC_FAIL    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_TPLOGTRIG_R_TRIG3_MASK    ((UBase_t) 0x00000008UL)
#define HIB_TPLOGTRIG_R_TRIG3_BIT    ((UBase_t) 3UL)
#define HIB_TPLOGTRIG_R_TRIG3_DEFAULT    ((UBase_t) 0x00000000UL)
#define HIB_TPLOGTRIG_R_TRIG3_DETECTED    ((UBase_t) 0x00000008UL)

#define HIB_TPLOGTRIG_TRIG3_MASK    ((UBase_t) 0x00000001UL)
#define HIB_TPLOGTRIG_TRIG3_DEFAULT    ((UBase_t) 0x00000000UL)
#define HIB_TPLOGTRIG_TRIG3_DETECTED    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_TPLOGTRIG_R_TRIG2_MASK    ((UBase_t) 0x00000004UL)
#define HIB_TPLOGTRIG_R_TRIG2_BIT    ((UBase_t) 2UL)
#define HIB_TPLOGTRIG_R_TRIG2_DEFAULT    ((UBase_t) 0x00000000UL)
#define HIB_TPLOGTRIG_R_TRIG2_DETECTED    ((UBase_t) 0x00000004UL)

#define HIB_TPLOGTRIG_TRIG2_MASK    ((UBase_t) 0x00000001UL)
#define HIB_TPLOGTRIG_TRIG2_DEFAULT    ((UBase_t) 0x00000000UL)
#define HIB_TPLOGTRIG_TRIG2_DETECTED    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_TPLOGTRIG_R_TRIG1_MASK    ((UBase_t) 0x00000002UL)
#define HIB_TPLOGTRIG_R_TRIG1_BIT    ((UBase_t) 1UL)
#define HIB_TPLOGTRIG_R_TRIG1_DEFAULT    ((UBase_t) 0x00000000UL)
#define HIB_TPLOGTRIG_R_TRIG1_DETECTED    ((UBase_t) 0x00000002UL)

#define HIB_TPLOGTRIG_TRIG1_MASK    ((UBase_t) 0x00000001UL)
#define HIB_TPLOGTRIG_TRIG1_DEFAULT    ((UBase_t) 0x00000000UL)
#define HIB_TPLOGTRIG_TRIG1_DETECTED    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_TPLOGTRIG_R_TRIG0_MASK    ((UBase_t) 0x00000001UL)
#define HIB_TPLOGTRIG_R_TRIG0_BIT    ((UBase_t) 0UL)
#define HIB_TPLOGTRIG_R_TRIG0_DEFAULT    ((UBase_t) 0x00000000UL)
#define HIB_TPLOGTRIG_R_TRIG0_DETECTED    ((UBase_t) 0x00000001UL)

#define HIB_TPLOGTRIG_TRIG0_MASK    ((UBase_t) 0x00000001UL)
#define HIB_TPLOGTRIG_TRIG0_DEFAULT    ((UBase_t) 0x00000000UL)
#define HIB_TPLOGTRIG_TRIG0_DETECTED    ((UBase_t) 0x00000001UL)
/*--------*/

#endif /* XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_TPLOGTRIG_H_ */
