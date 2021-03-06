/**
 *
 * @file TIMER_RegisterDefines_Standard_32_PP.h
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
 * @verbatim 9 jul. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 9 jul. 2020     vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_REGISTER_TIMER_REGISTERDEFINES_TIMER_REGISTERDEFINES_STANDARD_32_TIMER_REGISTERDEFINES_STANDARD_32_PP_H_
#define XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_REGISTER_TIMER_REGISTERDEFINES_TIMER_REGISTERDEFINES_STANDARD_32_TIMER_REGISTERDEFINES_STANDARD_32_PP_H_

#include <xDriver_MCU/Common/xHeader/MCU_Variables.h>

/******************************************************************************************
************************************ 27 PP *********************************************
******************************************************************************************/

/*----------*/
#define GPTM_PP_R_SIZE_MASK    ((uint32_t) 0x0000000FUL)
#define GPTM_PP_R_SIZE_BIT    (0UL)
#define GPTM_PP_R_SIZE_16b    ((uint32_t) 0x00000000UL)
#define GPTM_PP_R_SIZE_32b    ((uint32_t) 0x00000001UL)

#define GPTM_PP_SIZE_MASK    ((uint32_t) 0x0000000FUL)
#define GPTM_PP_SIZE_BOTH    ((uint32_t) 0x00000000UL)
#define GPTM_PP_SIZE_16b    ((uint32_t) 0x00000000UL)
#define GPTM_PP_SIZE_32b    ((uint32_t) 0x00000001UL)
/*----------*/

/*----------*/
#define GPTM_PP_R_CHAIN_MASK    ((uint32_t) 0x00000010UL)
#define GPTM_PP_R_CHAIN_BIT    (4UL)
#define GPTM_PP_R_CHAIN_NO    ((uint32_t) 0x00000000UL)
#define GPTM_PP_R_CHAIN_YES    ((uint32_t) 0x00000010UL)

#define GPTM_PP_CHAIN_MASK    ((uint32_t) 0x00000001UL)
#define GPTM_PP_CHAIN_NO    ((uint32_t) 0x00000000UL)
#define GPTM_PP_CHAIN_YES    ((uint32_t) 0x00000001UL)
/*----------*/

/*----------*/
#define GPTM_PP_R_SYNCCNT_MASK    ((uint32_t) 0x00000020UL)
#define GPTM_PP_R_SYNCCNT_BIT    (5UL)
#define GPTM_PP_R_SYNCCNT_NO    ((uint32_t) 0x00000000UL)
#define GPTM_PP_R_SYNCCNT_YES    ((uint32_t) 0x00000020UL)

#define GPTM_PP_SYNCCNT_MASK    ((uint32_t) 0x00000001UL)
#define GPTM_PP_SYNCCNT_NO    ((uint32_t) 0x00000000UL)
#define GPTM_PP_SYNCCNT_YES    ((uint32_t) 0x00000001UL)
/*----------*/

/*----------*/
#define GPTM_PP_R_ALTCLK_MASK    ((uint32_t) 0x00000040UL)
#define GPTM_PP_R_ALTCLK_BIT    (6UL)
#define GPTM_PP_R_ALTCLK_NO    ((uint32_t) 0x00000000UL)
#define GPTM_PP_R_ALTCLK_YES    ((uint32_t) 0x00000040UL)

#define GPTM_PP_ALTCLK_MASK    ((uint32_t) 0x00000001UL)
#define GPTM_PP_ALTCLK_NO    ((uint32_t) 0x00000000UL)
#define GPTM_PP_ALTCLK_YES    ((uint32_t) 0x00000001UL)
/*----------*/

#endif /* XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_REGISTER_TIMER_REGISTERDEFINES_TIMER_REGISTERDEFINES_STANDARD_32_TIMER_REGISTERDEFINES_STANDARD_32_PP_H_ */
