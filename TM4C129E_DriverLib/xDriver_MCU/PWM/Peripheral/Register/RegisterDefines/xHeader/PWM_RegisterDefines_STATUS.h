/**
 *
 * @file PWM_RegisterDefines_STATUS.h
 * @copyright
 * @verbatim InDeviceMex 2021 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 24 dic. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 24 dic. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_PWM_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_PWM_REGISTERDEFINES_STATUS_H_
#define XDRIVER_MCU_PWM_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_PWM_REGISTERDEFINES_STATUS_H_

#include <xDriver_MCU/Common/xHeader/MCU_Variables.h>

/******************************************************************************************
************************************ 9 STATUS *********************************************
******************************************************************************************/
/*--------*/
#define PWM_STATUS_R_FAULT0_MASK    ((uint32_t) 0x00000001UL)
#define PWM_STATUS_R_FAULT0_BIT    ((uint32_t) 0UL)
#define PWM_STATUS_R_FAULT0_INACTIVE    ((uint32_t) 0x00000000UL)
#define PWM_STATUS_R_FAULT0_ACTIVE    ((uint32_t) 0x00000001UL)

#define PWM_STATUS_FAULT0_MASK    ((uint32_t) 0x00000001UL)
#define PWM_STATUS_FAULT0_INACTIVE    ((uint32_t) 0x00000000UL)
#define PWM_STATUS_FAULT0_ACTIVE    ((uint32_t) 0x00000001UL)
/*--------*/

/*--------*/
#define PWM_STATUS_R_FAULT1_MASK    ((uint32_t) 0x00000002UL)
#define PWM_STATUS_R_FAULT1_BIT    ((uint32_t) 1UL)
#define PWM_STATUS_R_FAULT1_INACTIVE    ((uint32_t) 0x00000000UL)
#define PWM_STATUS_R_FAULT1_ACTIVE    ((uint32_t) 0x00000002UL)

#define PWM_STATUS_FAULT1_MASK    ((uint32_t) 0x00000001UL)
#define PWM_STATUS_FAULT1_INACTIVE    ((uint32_t) 0x00000000UL)
#define PWM_STATUS_FAULT1_ACTIVE    ((uint32_t) 0x00000001UL)
/*--------*/

/*--------*/
#define PWM_STATUS_R_FAULT2_MASK    ((uint32_t) 0x00000004UL)
#define PWM_STATUS_R_FAULT2_BIT    ((uint32_t) 2UL)
#define PWM_STATUS_R_FAULT2_INACTIVE    ((uint32_t) 0x00000000UL)
#define PWM_STATUS_R_FAULT2_ACTIVE    ((uint32_t) 0x00000004UL)

#define PWM_STATUS_FAULT2_MASK    ((uint32_t) 0x00000001UL)
#define PWM_STATUS_FAULT2_INACTIVE    ((uint32_t) 0x00000000UL)
#define PWM_STATUS_FAULT2_ACTIVE    ((uint32_t) 0x00000001UL)
/*--------*/

/*--------*/
#define PWM_STATUS_R_FAULT3_MASK    ((uint32_t) 0x00000008UL)
#define PWM_STATUS_R_FAULT3_BIT    ((uint32_t) 3UL)
#define PWM_STATUS_R_FAULT3_INACTIVE    ((uint32_t) 0x00000000UL)
#define PWM_STATUS_R_FAULT3_ACTIVE    ((uint32_t) 0x00000008UL)

#define PWM_STATUS_FAULT3_MASK    ((uint32_t) 0x00000001UL)
#define PWM_STATUS_FAULT3_INACTIVE    ((uint32_t) 0x00000000UL)
#define PWM_STATUS_FAULT3_ACTIVE    ((uint32_t) 0x00000001UL)
/*--------*/

#endif /* XDRIVER_MCU_PWM_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_PWM_REGISTERDEFINES_STATUS_H_ */
