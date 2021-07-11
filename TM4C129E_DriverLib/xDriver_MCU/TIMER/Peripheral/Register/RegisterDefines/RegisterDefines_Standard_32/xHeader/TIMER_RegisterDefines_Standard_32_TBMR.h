/**
 *
 * @file TIMER_RegisterDefines_Standard_32_TBMR.h
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

#ifndef XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_REGISTER_TIMER_REGISTERDEFINES_TIMER_REGISTERDEFINES_STANDARD_32_TIMER_REGISTERDEFINES_STANDARD_32_TBMR_H_
#define XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_REGISTER_TIMER_REGISTERDEFINES_TIMER_REGISTERDEFINES_STANDARD_32_TIMER_REGISTERDEFINES_STANDARD_32_TBMR_H_

#include <xUtils/Standard/Standard.h>

/******************************************************************************************
************************************ 3 TBMR *********************************************
******************************************************************************************/

/*----------*/
#define GPTM_TBMR_R_TBMR_MASK    ((uint32_t) 0x00000003UL)
#define GPTM_TBMR_R_TBMR_BIT    (0UL)
#define GPTM_TBMR_R_TBMR_ONESHOT    ((uint32_t) 0x00000001UL)
#define GPTM_TBMR_R_TBMR_PERIOD    ((uint32_t) 0x00000002UL)
#define GPTM_TBMR_R_TBMR_CAPTURE    ((uint32_t) 0x00000003UL)

#define GPTM_TBMR_TBMR_MASK    ((uint32_t) 0x00000003UL)
#define GPTM_TBMR_TBMR_ONESHOT    ((uint32_t) 0x00000001UL)
#define GPTM_TBMR_TBMR_PERIOD    ((uint32_t) 0x00000002UL)
#define GPTM_TBMR_TBMR_CAPTURE    ((uint32_t) 0x00000003UL)
/*----------*/

/*----------*/
#define GPTM_TBMR_R_TBCMR_MASK    ((uint32_t) 0x00000004UL)
#define GPTM_TBMR_R_TBCMR_BIT    (2UL)
#define GPTM_TBMR_R_TBCMR_EDGECOUNT    ((uint32_t) 0x00000000UL)
#define GPTM_TBMR_R_TBCMR_EDGETIME    ((uint32_t) 0x00000004UL)

#define GPTM_TBMR_TBCMR_MASK    ((uint32_t) 0x00000001UL)
#define GPTM_TBMR_TBCMR_EDGECOUNT    ((uint32_t) 0x00000000UL)
#define GPTM_TBMR_TBCMR_EDGETIME    ((uint32_t) 0x00000001UL)
/*----------*/

/*----------*/
#define GPTM_TBMR_R_TBAMS_MASK    ((uint32_t) 0x00000008UL)
#define GPTM_TBMR_R_TBAMS_BIT    (3UL)
#define GPTM_TBMR_R_TBAMS_CAPCOMP    ((uint32_t) 0x00000000UL)
#define GPTM_TBMR_R_TBAMS_PWM    ((uint32_t) 0x00000008UL)

#define GPTM_TBMR_TBAMS_MASK    ((uint32_t) 0x00000001UL)
#define GPTM_TBMR_TBAMS_CAPCOMP    ((uint32_t) 0x00000000UL)
#define GPTM_TBMR_TBAMS_PWM    ((uint32_t) 0x00000001UL)
/*----------*/

/*----------*/
#define GPTM_TBMR_R_TBCDIR_MASK    ((uint32_t) 0x00000010UL)
#define GPTM_TBMR_R_TBCDIR_BIT    (4UL)
#define GPTM_TBMR_R_TBCDIR_DOWN    ((uint32_t) 0x00000000UL)
#define GPTM_TBMR_R_TBCDIR_UP    ((uint32_t) 0x00000010UL)

#define GPTM_TBMR_TBCDIR_MASK    ((uint32_t) 0x00000001UL)
#define GPTM_TBMR_TBCDIR_DOWN    ((uint32_t) 0x00000000UL)
#define GPTM_TBMR_TBCDIR_UP    ((uint32_t) 0x00000001UL)
/*----------*/

/*----------*/
#define GPTM_TBMR_R_TBMIE_MASK    ((uint32_t) 0x00000020UL)
#define GPTM_TBMR_R_TBMIE_BIT    (5UL)
#define GPTM_TBMR_R_TBMIE_DIS    ((uint32_t) 0x00000000UL)
#define GPTM_TBMR_R_TBMIE_ENA    ((uint32_t) 0x00000020UL)

#define GPTM_TBMR_TBMIE_MASK    ((uint32_t) 0x00000001UL)
#define GPTM_TBMR_TBMIE_DIS    ((uint32_t) 0x00000000UL)
#define GPTM_TBMR_TBMIE_ENA    ((uint32_t) 0x00000001UL)
/*----------*/

/*----------*/
#define GPTM_TBMR_R_TBWOT_MASK    ((uint32_t) 0x00000040UL)
#define GPTM_TBMR_R_TBWOT_BIT    (6UL)
#define GPTM_TBMR_R_TBWOT_INSTBNT    ((uint32_t) 0x00000000UL)
#define GPTM_TBMR_R_TBWOT_TRIGGER    ((uint32_t) 0x00000040UL)

#define GPTM_TBMR_TBWOT_MASK    ((uint32_t) 0x00000001UL)
#define GPTM_TBMR_TBWOT_INSTBNT    ((uint32_t) 0x00000000UL)
#define GPTM_TBMR_TBWOT_TRIGGER    ((uint32_t) 0x00000001UL)
/*----------*/

/*----------*/
#define GPTM_TBMR_R_TBSNAPS_MASK    ((uint32_t) 0x00000080UL)
#define GPTM_TBMR_R_TBSNAPS_BIT    (7UL)
#define GPTM_TBMR_R_TBSNAPS_DIS    ((uint32_t) 0x00000000UL)
#define GPTM_TBMR_R_TBSNAPS_ENA    ((uint32_t) 0x00000080UL)

#define GPTM_TBMR_TBSNAPS_MASK    ((uint32_t) 0x00000001UL)
#define GPTM_TBMR_TBSNAPS_DIS    ((uint32_t) 0x00000000UL)
#define GPTM_TBMR_TBSNAPS_ENA    ((uint32_t) 0x00000001UL)
/*----------*/

/*----------*/
#define GPTM_TBMR_R_TBILD_MASK    ((uint32_t) 0x00000100UL)
#define GPTM_TBMR_R_TBILD_BIT    (8UL)
#define GPTM_TBMR_R_TBILD_NEXT    ((uint32_t) 0x00000000UL)
#define GPTM_TBMR_R_TBILD_TIMEOUT    ((uint32_t) 0x00000100UL)

#define GPTM_TBMR_TBILD_MASK    ((uint32_t) 0x00000001UL)
#define GPTM_TBMR_TBILD_NEXT    ((uint32_t) 0x00000000UL)
#define GPTM_TBMR_TBILD_TIMEOUT    ((uint32_t) 0x00000001UL)
/*----------*/

/*----------*/
#define GPTM_TBMR_R_TBPWMIE_MASK    ((uint32_t) 0x00000200UL)
#define GPTM_TBMR_R_TBPWMIE_BIT    (9UL)
#define GPTM_TBMR_R_TBPWMIE_DIS    ((uint32_t) 0x00000000UL)
#define GPTM_TBMR_R_TBPWMIE_ENA    ((uint32_t) 0x00000200UL)

#define GPTM_TBMR_TBPWMIE_MASK    ((uint32_t) 0x00000001UL)
#define GPTM_TBMR_TBPWMIE_DIS    ((uint32_t) 0x00000000UL)
#define GPTM_TBMR_TBPWMIE_ENA    ((uint32_t) 0x00000001UL)
/*----------*/

/*----------*/
#define GPTM_TBMR_R_TBMRSU_MASK    ((uint32_t) 0x00000400UL)
#define GPTM_TBMR_R_TBMRSU_BIT    (10UL)
#define GPTM_TBMR_R_TBMRSU_NEXT    ((uint32_t) 0x00000000UL)
#define GPTM_TBMR_R_TBMRSU_TIMEOUT    ((uint32_t) 0x00000400UL)

#define GPTM_TBMR_TBMRSU_MASK    ((uint32_t) 0x00000001UL)
#define GPTM_TBMR_TBMRSU_NEXT    ((uint32_t) 0x00000000UL)
#define GPTM_TBMR_TBMRSU_TIMEOUT    ((uint32_t) 0x00000001UL)
/*----------*/

/*----------*/
#define GPTM_TBMR_R_TBPLO_MASK    ((uint32_t) 0x00000800UL)
#define GPTM_TBMR_R_TBPLO_BIT    (11UL)
#define GPTM_TBMR_R_TBPLO_LOW    ((uint32_t) 0x00000000UL)
#define GPTM_TBMR_R_TBPLO_HIGH    ((uint32_t) 0x00000800UL)

#define GPTM_TBMR_TBPLO_MASK    ((uint32_t) 0x00000001UL)
#define GPTM_TBMR_TBPLO_LOW    ((uint32_t) 0x00000000UL)
#define GPTM_TBMR_TBPLO_HIGH    ((uint32_t) 0x00000001UL)
/*----------*/

/*----------*/
#define GPTM_TnMR_R_TnCINTD_MASK    ((uint32_t) 0x00001000UL)
#define GPTM_TnMR_R_TnCINTD_BIT    (12UL)
#define GPTM_TnMR_R_TnCINTD_NORMAL    ((uint32_t) 0x00000000UL)
#define GPTM_TnMR_R_TnCINTD_DIS    ((uint32_t) 0x00001000UL)

#define GPTM_TnMR_TnCINTD_MASK    ((uint32_t) 0x00000001UL)
#define GPTM_TnMR_TnCINTD_NORMAL    ((uint32_t) 0x00000000UL)
#define GPTM_TnMR_TnCINTD_DIS    ((uint32_t) 0x00000001UL)
/*----------*/

/*----------*/
#define GPTM_TnMR_R_TCACT_MASK    ((uint32_t) 0x0000E000UL)
#define GPTM_TnMR_R_TCACT_BIT    (13UL)
#define GPTM_TnMR_R_TCACT_DIS    ((uint32_t) 0x00000000UL)
#define GPTM_TnMR_R_TCACT_TOOGLE_TO    ((uint32_t) 0x00002000UL)
#define GPTM_TnMR_R_TCACT_CLEAR_TO    ((uint32_t) 0x00004000UL)
#define GPTM_TnMR_R_TCACT_SET_TO    ((uint32_t) 0x00006000UL)
#define GPTM_TnMR_R_TCACT_SET_INM_TOOGLE_TO    ((uint32_t) 0x00008000UL)
#define GPTM_TnMR_R_TCACT_CLEAR_INM_TOOGLE_TO    ((uint32_t) 0x0000A000UL)
#define GPTM_TnMR_R_TCACT_SET_INM_CLEAR_TO    ((uint32_t) 0x0000C000UL)
#define GPTM_TnMR_R_TCACT_CLEAR_INM_SET_TO    ((uint32_t) 0x0000E000UL)

#define GPTM_TnMR_TCACT_MASK    ((uint32_t) 0x00000007UL)
#define GPTM_TnMR_TCACT_DIS    ((uint32_t) 0x00000000UL)
#define GPTM_TnMR_TCACT_TOOGLE_TO    ((uint32_t) 0x00000001UL)
#define GPTM_TnMR_TCACT_CLEAR_TO    ((uint32_t) 0x00000002UL)
#define GPTM_TnMR_TCACT_SET_TO    ((uint32_t) 0x00000003UL)
#define GPTM_TnMR_TCACT_SET_INM_TOOGLE_TO    ((uint32_t) 0x00000004UL)
#define GPTM_TnMR_TCACT_CLEAR_INM_TOOGLE_TO    ((uint32_t) 0x00000005UL)
#define GPTM_TnMR_TCACT_SET_INM_CLEAR_TO    ((uint32_t) 0x00000006UL)
#define GPTM_TnMR_TCACT_CLEAR_INM_SET_TO    ((uint32_t) 0x00000007UL)
/*----------*/

#endif /* XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_REGISTER_TIMER_REGISTERDEFINES_TIMER_REGISTERDEFINES_STANDARD_32_TIMER_REGISTERDEFINES_STANDARD_32_TBMR_H_ */
