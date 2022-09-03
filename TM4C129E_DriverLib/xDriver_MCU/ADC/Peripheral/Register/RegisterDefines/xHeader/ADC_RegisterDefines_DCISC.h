/**
 *
 * @file ADC_RegisterDefines_DCISC.h
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
 * @verbatim 14 nov. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 14 nov. 2020     vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_ADC_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_ADC_REGISTERDEFINES_DCISC_H_
#define XDRIVER_MCU_ADC_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_ADC_REGISTERDEFINES_DCISC_H_

#include <xDriver_MCU/Common/xHeader/MCU_Variables.h>

/******************************************************************************************
************************************ 13 DC_ISC *********************************************
******************************************************************************************/
/*--------*/
#define ADC_DC_ISC_R_DCINT_MASK    ((uint32_t) 0x000000FFUL)
#define ADC_DC_ISC_R_DCINT_BIT    ((uint32_t) 0UL)
#define ADC_DC_ISC_R_DCINT_INACTIVE    ((uint32_t) 0x00000000UL)
#define ADC_DC_ISC_R_DCINT_ACTIVE    ((uint32_t) 0x000000FFUL)
#define ADC_DC_ISC_R_DCINT_CLEAR    ((uint32_t) 0x000000FFUL)

#define ADC_DC_ISC_DCINT_MASK    ((uint32_t) 0x00000001UL)
#define ADC_DC_ISC_DCINT_INACTIVE    ((uint32_t) 0x00000000UL)
#define ADC_DC_ISC_DCINT_ACTIVE    ((uint32_t) 0x00000001UL)
#define ADC_DC_ISC_DCINT_CLEAR    ((uint32_t) 0x00000001UL)
/*--------*/

/*--------*/
#define ADC_DC_ISC_R_DCINT0_MASK    ((uint32_t) 0x00000001UL)
#define ADC_DC_ISC_R_DCINT0_BIT    ((uint32_t) 0UL)
#define ADC_DC_ISC_R_DCINT0_INACTIVE    ((uint32_t) 0x00000000UL)
#define ADC_DC_ISC_R_DCINT0_ACTIVE    ((uint32_t) 0x00000001UL)
#define ADC_DC_ISC_R_DCINT0_CLEAR    ((uint32_t) 0x00000001UL)

#define ADC_DC_ISC_DCINT0_MASK    ((uint32_t) 0x00000001UL)
#define ADC_DC_ISC_DCINT0_INACTIVE    ((uint32_t) 0x00000000UL)
#define ADC_DC_ISC_DCINT0_ACTIVE    ((uint32_t) 0x00000001UL)
#define ADC_DC_ISC_DCINT0_CLEAR    ((uint32_t) 0x00000001UL)
/*--------*/

/*--------*/
#define ADC_DC_ISC_R_DCINT1_MASK    ((uint32_t) 0x00000002UL)
#define ADC_DC_ISC_R_DCINT1_BIT    ((uint32_t) 1UL)
#define ADC_DC_ISC_R_DCINT1_INACTIVE    ((uint32_t) 0x00000000UL)
#define ADC_DC_ISC_R_DCINT1_ACTIVE    ((uint32_t) 0x00000002UL)
#define ADC_DC_ISC_R_DCINT1_CLEAR    ((uint32_t) 0x00000002UL)

#define ADC_DC_ISC_DCINT1_MASK    ((uint32_t) 0x00000001UL)
#define ADC_DC_ISC_DCINT1_INACTIVE    ((uint32_t) 0x00000000UL)
#define ADC_DC_ISC_DCINT1_ACTIVE    ((uint32_t) 0x00000001UL)
#define ADC_DC_ISC_DCINT1_CLEAR    ((uint32_t) 0x00000001UL)
/*--------*/

/*--------*/
#define ADC_DC_ISC_R_DCINT2_MASK    ((uint32_t) 0x00000004UL)
#define ADC_DC_ISC_R_DCINT2_BIT    ((uint32_t) 2UL)
#define ADC_DC_ISC_R_DCINT2_INACTIVE    ((uint32_t) 0x00000000UL)
#define ADC_DC_ISC_R_DCINT2_ACTIVE    ((uint32_t) 0x00000004UL)
#define ADC_DC_ISC_R_DCINT2_CLEAR    ((uint32_t) 0x00000004UL)

#define ADC_DC_ISC_DCINT2_MASK    ((uint32_t) 0x00000001UL)
#define ADC_DC_ISC_DCINT2_INACTIVE    ((uint32_t) 0x00000000UL)
#define ADC_DC_ISC_DCINT2_ACTIVE    ((uint32_t) 0x00000001UL)
#define ADC_DC_ISC_DCINT2_CLEAR    ((uint32_t) 0x00000001UL)
/*--------*/

/*--------*/
#define ADC_DC_ISC_R_DCINT3_MASK    ((uint32_t) 0x00000008UL)
#define ADC_DC_ISC_R_DCINT3_BIT    ((uint32_t) 3UL)
#define ADC_DC_ISC_R_DCINT3_INACTIVE    ((uint32_t) 0x00000000UL)
#define ADC_DC_ISC_R_DCINT3_ACTIVE    ((uint32_t) 0x00000008UL)
#define ADC_DC_ISC_R_DCINT3_CLEAR    ((uint32_t) 0x00000008UL)

#define ADC_DC_ISC_DCINT3_MASK    ((uint32_t) 0x00000001UL)
#define ADC_DC_ISC_DCINT3_INACTIVE    ((uint32_t) 0x00000000UL)
#define ADC_DC_ISC_DCINT3_ACTIVE    ((uint32_t) 0x00000001UL)
#define ADC_DC_ISC_DCINT3_CLEAR    ((uint32_t) 0x00000001UL)
/*--------*/

/*--------*/
#define ADC_DC_ISC_R_DCINT4_MASK    ((uint32_t) 0x00000010UL)
#define ADC_DC_ISC_R_DCINT4_BIT    ((uint32_t) 4UL)
#define ADC_DC_ISC_R_DCINT4_INACTIVE    ((uint32_t) 0x00000000UL)
#define ADC_DC_ISC_R_DCINT4_ACTIVE    ((uint32_t) 0x00000010UL)
#define ADC_DC_ISC_R_DCINT4_CLEAR    ((uint32_t) 0x00000010UL)

#define ADC_DC_ISC_DCINT4_MASK    ((uint32_t) 0x00000001UL)
#define ADC_DC_ISC_DCINT4_INACTIVE    ((uint32_t) 0x00000000UL)
#define ADC_DC_ISC_DCINT4_ACTIVE    ((uint32_t) 0x00000001UL)
#define ADC_DC_ISC_DCINT4_CLEAR    ((uint32_t) 0x00000001UL)
/*--------*/

/*--------*/
#define ADC_DC_ISC_R_DCINT5_MASK    ((uint32_t) 0x00000020UL)
#define ADC_DC_ISC_R_DCINT5_BIT    ((uint32_t) 5UL)
#define ADC_DC_ISC_R_DCINT5_INACTIVE    ((uint32_t) 0x00000000UL)
#define ADC_DC_ISC_R_DCINT5_ACTIVE    ((uint32_t) 0x00000020UL)
#define ADC_DC_ISC_R_DCINT5_CLEAR    ((uint32_t) 0x00000020UL)

#define ADC_DC_ISC_DCINT5_MASK    ((uint32_t) 0x00000001UL)
#define ADC_DC_ISC_DCINT5_INACTIVE    ((uint32_t) 0x00000000UL)
#define ADC_DC_ISC_DCINT5_ACTIVE    ((uint32_t) 0x00000001UL)
#define ADC_DC_ISC_DCINT5_CLEAR    ((uint32_t) 0x00000001UL)
/*--------*/

/*--------*/
#define ADC_DC_ISC_R_DCINT6_MASK    ((uint32_t) 0x00000040UL)
#define ADC_DC_ISC_R_DCINT6_BIT    ((uint32_t) 6UL)
#define ADC_DC_ISC_R_DCINT6_INACTIVE    ((uint32_t) 0x00000000UL)
#define ADC_DC_ISC_R_DCINT6_ACTIVE    ((uint32_t) 0x00000040UL)
#define ADC_DC_ISC_R_DCINT6_CLEAR    ((uint32_t) 0x00000040UL)

#define ADC_DC_ISC_DCINT6_MASK    ((uint32_t) 0x00000001UL)
#define ADC_DC_ISC_DCINT6_INACTIVE    ((uint32_t) 0x00000000UL)
#define ADC_DC_ISC_DCINT6_ACTIVE    ((uint32_t) 0x00000001UL)
#define ADC_DC_ISC_DCINT6_CLEAR    ((uint32_t) 0x00000001UL)
/*--------*/

/*--------*/
#define ADC_DC_ISC_R_DCINT7_MASK    ((uint32_t) 0x00000080UL)
#define ADC_DC_ISC_R_DCINT7_BIT    ((uint32_t) 7UL)
#define ADC_DC_ISC_R_DCINT7_INACTIVE    ((uint32_t) 0x00000000UL)
#define ADC_DC_ISC_R_DCINT7_ACTIVE    ((uint32_t) 0x00000080UL)
#define ADC_DC_ISC_R_DCINT7_CLEAR    ((uint32_t) 0x00000080UL)

#define ADC_DC_ISC_DCINT7_MASK    ((uint32_t) 0x00000001UL)
#define ADC_DC_ISC_DCINT7_INACTIVE    ((uint32_t) 0x00000000UL)
#define ADC_DC_ISC_DCINT7_ACTIVE    ((uint32_t) 0x00000001UL)
#define ADC_DC_ISC_DCINT7_CLEAR    ((uint32_t) 0x00000001UL)
/*--------*/

#endif /* XDRIVER_MCU_ADC_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_ADC_REGISTERDEFINES_DCISC_H_ */
