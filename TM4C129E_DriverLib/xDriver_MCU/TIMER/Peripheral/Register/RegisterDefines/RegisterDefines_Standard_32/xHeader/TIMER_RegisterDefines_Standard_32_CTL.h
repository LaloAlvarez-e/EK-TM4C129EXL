/**
 *
 * @file TIMER_RegisterDefines_Standard_32_CTL.h
 * @copyright
 * @verbatim InDeviceMex 2020 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 6 jul. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 6 jul. 2020     vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_REGISTER_TIMER_REGISTERDEFINES_TIMER_REGISTERDEFINES_STANDARD_32_TIMER_REGISTERDEFINES_STANDARD_32_CTL_H_
#define XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_REGISTER_TIMER_REGISTERDEFINES_TIMER_REGISTERDEFINES_STANDARD_32_TIMER_REGISTERDEFINES_STANDARD_32_CTL_H_

#include <xDriver_MCU/TIMER/Peripheral/xHeader/TIMER_Enum.h>

/******************************************************************************************
************************************ 4 CTL *********************************************
******************************************************************************************/

/*----------*/
#define GPTM_CTL_R_TAEN_MASK    ((UBase_t) 0x00000001UL)
#define GPTM_CTL_R_TAEN_BIT    (0UL)
#define GPTM_CTL_R_TAEN_DIS    ((UBase_t) 0x00000000UL)
#define GPTM_CTL_R_TAEN_ENA    ((UBase_t) 0x00000001UL)

#define GPTM_CTL_TAEN_MASK    ((UBase_t) 0x00000001UL)
#define GPTM_CTL_TAEN_DIS    ((UBase_t) 0x00000000UL)
#define GPTM_CTL_TAEN_ENA    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define GPTM_CTL_R_TASTALL_MASK    ((UBase_t) 0x00000002UL)
#define GPTM_CTL_R_TASTALL_BIT    (1UL)
#define GPTM_CTL_R_TASTALL_CONTINUE    ((UBase_t) 0x00000000UL)
#define GPTM_CTL_R_TASTALL_FREEZE    ((UBase_t) 0x00000002UL)

#define GPTM_CTL_TASTALL_MASK    ((UBase_t) 0x00000001UL)
#define GPTM_CTL_TASTALL_CONTINUE    ((UBase_t) 0x00000000UL)
#define GPTM_CTL_TASTALL_FREEZE    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define GPTM_CTL_R_TAEVENT_MASK    ((UBase_t) 0x0000000CUL)
#define GPTM_CTL_R_TAEVENT_BIT    (2UL)
#define GPTM_CTL_R_TAEVENT_POS    ((UBase_t) 0x00000000UL)
#define GPTM_CTL_R_TAEVENT_NEG    ((UBase_t) 0x00000004UL)
#define GPTM_CTL_R_TAEVENT_BOTH    ((UBase_t) 0x0000000CUL)

#define GPTM_CTL_TAEVENT_MASK    ((UBase_t) 0x00000003UL)
#define GPTM_CTL_TAEVENT_NEG    ((UBase_t) 0x00000000UL)
#define GPTM_CTL_TAEVENT_POS    ((UBase_t) 0x00000001UL)
#define GPTM_CTL_TAEVENT_BOTH    ((UBase_t) 0x00000003UL)
/*----------*/

/*----------*/
#define GPTM_CTL_R_RTCEN_MASK    ((UBase_t) 0x00000010UL)
#define GPTM_CTL_R_RTCEN_BIT    (4UL)
#define GPTM_CTL_R_RTCEN_CONTINUE    ((UBase_t) 0x00000000UL)
#define GPTM_CTL_R_RTCEN_FREEZE    ((UBase_t) 0x00000010UL)

#define GPTM_CTL_RTCEN_MASK    ((UBase_t) 0x00000001UL)
#define GPTM_CTL_RTCEN_CONTINUE    ((UBase_t) 0x00000000UL)
#define GPTM_CTL_RTCEN_FREEZE    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define GPTM_CTL_R_TAOTE_MASK    ((UBase_t) 0x00000020UL)
#define GPTM_CTL_R_TAOTE_BIT    (5UL)
#define GPTM_CTL_R_TAOTE_DIS    ((UBase_t) 0x00000000UL)
#define GPTM_CTL_R_TAOTE_ENA    ((UBase_t) 0x00000020UL)

#define GPTM_CTL_TAOTE_MASK    ((UBase_t) 0x00000001UL)
#define GPTM_CTL_TAOTE_DIS    ((UBase_t) 0x00000000UL)
#define GPTM_CTL_TAOTE_ENA    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define GPTM_CTL_R_TAPWML_MASK    ((UBase_t) 0x00000040UL)
#define GPTM_CTL_R_TAPWML_BIT    (6UL)
#define GPTM_CTL_R_TAPWML_NA    ((UBase_t) 0x00000000UL)
#define GPTM_CTL_R_TAPWML_INV    ((UBase_t) 0x00000040UL)

#define GPTM_CTL_TAPWML_MASK    ((UBase_t) 0x00000001UL)
#define GPTM_CTL_TAPWML_NA    ((UBase_t) 0x00000000UL)
#define GPTM_CTL_TAPWML_INV    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define GPTM_CTL_R_TBEN_MASK    ((UBase_t) 0x00000100UL)
#define GPTM_CTL_R_TBEN_BIT    (8UL)
#define GPTM_CTL_R_TBEN_DIS    ((UBase_t) 0x00000000UL)
#define GPTM_CTL_R_TBEN_ENA    ((UBase_t) 0x00000100UL)

#define GPTM_CTL_TBEN_MASK    ((UBase_t) 0x00000001UL)
#define GPTM_CTL_TBEN_DIS    ((UBase_t) 0x00000000UL)
#define GPTM_CTL_TBEN_ENA    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define GPTM_CTL_R_TBSTALL_MASK    ((UBase_t) 0x00000200UL)
#define GPTM_CTL_R_TBSTALL_BIT    (9UL)
#define GPTM_CTL_R_TBSTALL_CONTINUE    ((UBase_t) 0x00000000UL)
#define GPTM_CTL_R_TBSTALL_FREEZE    ((UBase_t) 0x00000200UL)

#define GPTM_CTL_TBSTALL_MASK    ((UBase_t) 0x00000001UL)
#define GPTM_CTL_TBSTALL_CONTINUE    ((UBase_t) 0x00000000UL)
#define GPTM_CTL_TBSTALL_FREEZE    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define GPTM_CTL_R_TBEVENT_MASK    ((UBase_t) 0x00000C00UL)
#define GPTM_CTL_R_TBEVENT_BIT    (10UL)
#define GPTM_CTL_R_TBEVENT_POS    ((UBase_t) 0x00000000UL)
#define GPTM_CTL_R_TBEVENT_NEG    ((UBase_t) 0x00000400UL)
#define GPTM_CTL_R_TBEVENT_BOTH    ((UBase_t) 0x00000C00UL)

#define GPTM_CTL_TBEVENT_MASK    ((UBase_t) 0x00000003UL)
#define GPTM_CTL_TBEVENT_NEG    ((UBase_t) 0x00000000UL)
#define GPTM_CTL_TBEVENT_POS    ((UBase_t) 0x00000001UL)
#define GPTM_CTL_TBEVENT_BOTH    ((UBase_t) 0x00000003UL)
/*----------*/

/*----------*/
#define GPTM_CTL_R_TBOTE_MASK    ((UBase_t) 0x00002000UL)
#define GPTM_CTL_R_TBOTE_BIT    (13UL)
#define GPTM_CTL_R_TBOTE_DIS    ((UBase_t) 0x00000000UL)
#define GPTM_CTL_R_TBOTE_ENA    ((UBase_t) 0x00002000UL)

#define GPTM_CTL_TBOTE_MASK    ((UBase_t) 0x00000001UL)
#define GPTM_CTL_TBOTE_DIS    ((UBase_t) 0x00000000UL)
#define GPTM_CTL_TBOTE_ENA    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define GPTM_CTL_R_TBPWML_MASK    ((UBase_t) 0x00004000UL)
#define GPTM_CTL_R_TBPWML_BIT    (14UL)
#define GPTM_CTL_R_TBPWML_NA    ((UBase_t) 0x00000000UL)
#define GPTM_CTL_R_TBPWML_INV    ((UBase_t) 0x00004000UL)

#define GPTM_CTL_TBPWML_MASK    ((UBase_t) 0x00000001UL)
#define GPTM_CTL_TBPWML_NA    ((UBase_t) 0x00000000UL)
#define GPTM_CTL_TBPWML_INV    ((UBase_t) 0x00000001UL)
/*----------*/

#endif /* XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_REGISTER_TIMER_REGISTERDEFINES_TIMER_REGISTERDEFINES_STANDARD_32_TIMER_REGISTERDEFINES_STANDARD_32_CTL_H_ */
