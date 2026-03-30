/**
 *
 * @file SYSTICK_RegisterDefines.h
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
 * @verbatim 22 jun. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 22 jun. 2020     vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_DRIVER_HEADER_SYSTICK_SYSTICK_PERIPHERAL_SYSTICK_REGISTER_SYSTICK_REGISTERDEFINES_H_
#define XDRIVER_MCU_DRIVER_HEADER_SYSTICK_SYSTICK_PERIPHERAL_SYSTICK_REGISTER_SYSTICK_REGISTERDEFINES_H_

#include <xDriver_MCU/Core/SYSTICK/Peripheral/xHeader/SYSTICK_Enum.h>

/*********************************************************************************************
************************************** 1 CSR **********************************************
*********************************************************************************************/
/*--------*/
#define SYSTICK_CSR_R_COUNTFLAG_MASK    ((UBase_t) 0x00010000UL)
#define SYSTICK_CSR_R_COUNTFLAG_BIT    (16UL)
#define SYSTICK_CSR_R_COUNTFLAG_COMPLETE    ((UBase_t) 0x00010000UL)
#define SYSTICK_CSR_R_COUNTFLAG_NOCOMPLETE    ((UBase_t) 0x00000000UL)

#define SYSTICK_CSR_COUNTFLAG_MASK    ((UBase_t) 0x00000001UL)
#define SYSTICK_CSR_COUNTFLAG_COMPLETE    ((UBase_t) 0x00000001UL)
#define SYSTICK_CSR_COUNTFLAG_NOCOMPLETE    ((UBase_t) 0x00000000UL)
/*--------*/

/*--------*/
#define SYSTICK_CSR_R_CLKSOURCE_MASK    ((UBase_t) 0x00000004UL)
#define SYSTICK_CSR_R_CLKSOURCE_BIT    (2UL)
#define SYSTICK_CSR_R_CLKSOURCE_PIOSC4    ((UBase_t) 0x00000000UL)
#define SYSTICK_CSR_R_CLKSOURCE_SYSCLK ((UBase_t) 0x00000004UL)

#define SYSTICK_CSR_CLKSOURCE_MASK    ((UBase_t) 0x00000001UL)
#define SYSTICK_CSR_CLKSOURCE_PIOSC4    ((UBase_t) 0x00000000UL)
#define SYSTICK_CSR_CLKSOURCE_SYSCLK    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define SYSTICK_CSR_R_TICKINT_MASK    ((UBase_t) 0x00000002UL)
#define SYSTICK_CSR_R_TICKINT_BIT    (1UL)
#define SYSTICK_CSR_R_TICKINT_ENA    ((UBase_t) 0x00000002UL)
#define SYSTICK_CSR_R_TICKINT_DIS    ((UBase_t) 0x00000000UL)

#define SYSTICK_CSR_TICKINT_MASK    ((UBase_t) 0x00000001UL)
#define SYSTICK_CSR_TICKINT_ENA    ((UBase_t) 0x00000001UL)
#define SYSTICK_CSR_TICKINT_DIS    ((UBase_t) 0x00000000UL)
/*--------*/

/*--------*/
#define SYSTICK_CSR_R_ENABLE_MASK    ((UBase_t) 0x00000001UL)
#define SYSTICK_CSR_R_ENABLE_BIT    (0UL)
#define SYSTICK_CSR_R_ENABLE_ENA    ((UBase_t) 0x00000001UL)
#define SYSTICK_CSR_R_ENABLE_DIS    ((UBase_t) 0x00000000UL)

#define SYSTICK_CSR_ENABLE_MASK    ((UBase_t) 0x00000001UL)
#define SYSTICK_CSR_ENABLE_ENA    ((UBase_t) 0x00000001UL)
#define SYSTICK_CSR_ENABLE_DIS    ((UBase_t) 0x00000000UL)
/*--------*/

/*********************************************************************************************
************************************** 2 LOAD **********************************************
*********************************************************************************************/
/*--------*/
#define SYSTICK_RVR_R_RELOAD_MASK    ((UBase_t) 0x00FFFFFFUL)
#define SYSTICK_RVR_R_RELOAD_BIT    (0UL)

#define SYSTICK_RVR_RELOAD_MASK    ((UBase_t) 0x00FFFFFFUL)
/*--------*/

/*********************************************************************************************
**************************************** 3 VAL **********************************************
***********************************************************************************************/
/*--------*/
#define SYSTICK_CVR_R_CURRENT_MASK    ((UBase_t) 0x00FFFFFFUL)
#define SYSTICK_CVR_R_CURRENT_BIT    (0UL)

#define SYSTICK_CVR_CURRENT_MASK    ((UBase_t) 0x00FFFFFFUL)
/*--------*/

/*********************************************************************************************
**************************************** 3 CR **********************************************
***********************************************************************************************/
/*--------*/
#define SYSTICK_CR_R_TENMS_MASK    ((UBase_t) 0x00FFFFFFUL)
#define SYSTICK_CR_R_TENMS_BIT    (0UL)

#define SYSTICK_CR_TENMS_MASK    ((UBase_t) 0x00FFFFFFUL)
/*--------*/

/*--------*/
#define SYSTICK_CR_R_SKEW_MASK    ((UBase_t) 0x40000000UL)
#define SYSTICK_CR_R_SKEW_BIT    (30UL)
#define SYSTICK_CR_R_SKEW_EXACT    ((UBase_t) 0x00000000UL)
#define SYSTICK_CR_R_SKEW_INEXACT    ((UBase_t) 0x40000000UL)

#define SYSTICK_CR_SKEW_MASK    ((UBase_t) 0x00000001UL)
#define SYSTICK_CR_SKEW_EXACT    ((UBase_t) 0x00000000UL)
#define SYSTICK_CR_SKEW_INEXACT    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define SYSTICK_CR_R_NOREF_MASK    ((UBase_t) 0x80000000UL)
#define SYSTICK_CR_R_NOREF_BIT    (31UL)
#define SYSTICK_CR_R_NOREF_REFERENCE    ((UBase_t) 0x00000000UL)
#define SYSTICK_CR_R_NOREF_NOREFERENCE    ((UBase_t) 0x80000000UL)
#define SYSTICK_CR_R_NOREF_SAME    SYSTICK_CR_R_NOREF_NOREFERENCE
#define SYSTICK_CR_R_NOREF_OTHER    SYSTICK_CR_R_NOREF_REFERENCE

#define SYSTICK_CR_NOREF_MASK    ((UBase_t) 0x00000001UL)
#define SYSTICK_CR_NOREF_REFERENCE    ((UBase_t) 0x00000000UL)
#define SYSTICK_CR_NOREF_NOREFERENCE    ((UBase_t) 0x00000001UL)
#define SYSTICK_CR_NOREF_SAME    SYSTICK_CR_NOREF_NOREFERENCE
#define SYSTICK_CR_NOREF_OTHER    SYSTICK_CR_NOREF_REFERENCE
/*--------*/

#endif /* XDRIVER_MCU_DRIVER_HEADER_SYSTICK_SYSTICK_PERIPHERAL_SYSTICK_REGISTER_SYSTICK_REGISTERDEFINES_H_ */
