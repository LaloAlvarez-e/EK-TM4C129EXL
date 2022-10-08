/**
 *
 * @file TIMER_RegisterDefines_ModuleA_16_MIS.h
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

#ifndef XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_REGISTER_TIMER_REGISTERDEFINES_TIMER_REGISTERDEFINES_MODULEA_16_TIMER_REGISTERDEFINES_MODULEA_16_MIS_H_
#define XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_REGISTER_TIMER_REGISTERDEFINES_TIMER_REGISTERDEFINES_MODULEA_16_TIMER_REGISTERDEFINES_MODULEA_16_MIS_H_

#include <xDriver_MCU/TIMER/Peripheral/xHeader/TIMER_Enum.h>

/******************************************************************************************
************************************ 8 MIS *********************************************
******************************************************************************************/

/*----------*/
#define GPTM_TA_TnMIS_R_TnTOMIS_MASK    ((UBase_t) 0x00000001UL)
#define GPTM_TA_TnMIS_R_TnTOMIS_BIT    (0UL)
#define GPTM_TA_TnMIS_R_TnTOMIS_INACTIVE    ((UBase_t) 0x00000000UL)
#define GPTM_TA_TnMIS_R_TnTOMIS_ACTIVE    ((UBase_t) 0x00000001UL)

#define GPTM_TA_TnMIS_TnTOMIS_MASK    ((UBase_t) 0x00000001UL)
#define GPTM_TA_TnMIS_TnTOMIS_INACTIVE    ((UBase_t) 0x00000000UL)
#define GPTM_TA_TnMIS_TnTOMIS_ACTIVE    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define GPTM_TA_TnMIS_R_CnMMIS_MASK    ((UBase_t) 0x00000002UL)
#define GPTM_TA_TnMIS_R_CnMMIS_BIT    (1UL)
#define GPTM_TA_TnMIS_R_CnMMIS_INACTIVE    ((UBase_t) 0x00000000UL)
#define GPTM_TA_TnMIS_R_CnMMIS_ACTIVE    ((UBase_t) 0x00000002UL)

#define GPTM_TA_TnMIS_CnMMIS_MASK    ((UBase_t) 0x00000001UL)
#define GPTM_TA_TnMIS_CnMMIS_INACTIVE    ((UBase_t) 0x00000000UL)
#define GPTM_TA_TnMIS_CnMMIS_ACTIVE    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define GPTM_TA_TnMIS_R_CnEMIS_MASK    ((UBase_t) 0x00000004UL)
#define GPTM_TA_TnMIS_R_CnEMIS_BIT    (2UL)
#define GPTM_TA_TnMIS_R_CnEMIS_INACTIVE    ((UBase_t) 0x00000000UL)
#define GPTM_TA_TnMIS_R_CnEMIS_ACTIVE    ((UBase_t) 0x00000004UL)

#define GPTM_TA_TnMIS_CnEMIS_MASK    ((UBase_t) 0x00000001UL)
#define GPTM_TA_TnMIS_CnEMIS_INACTIVE    ((UBase_t) 0x00000000UL)
#define GPTM_TA_TnMIS_CnEMIS_ACTIVE    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define GPTM_TA_TnMIS_R_TnMMIS_MASK    ((UBase_t) 0x00000010UL)
#define GPTM_TA_TnMIS_R_TnMMIS_BIT    (4UL)
#define GPTM_TA_TnMIS_R_TnMMIS_INACTIVE    ((UBase_t) 0x00000000UL)
#define GPTM_TA_TnMIS_R_TnMMIS_ACTIVE    ((UBase_t) 0x00000010UL)

#define GPTM_TA_TnMIS_TnMMIS_MASK    ((UBase_t) 0x00000001UL)
#define GPTM_TA_TnMIS_TnMMIS_INACTIVE    ((UBase_t) 0x00000000UL)
#define GPTM_TA_TnMIS_TnMMIS_ACTIVE    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define GPTM_TA_TnMIS_R_DMAnMIS_MASK    ((UBase_t) 0x00000020UL)
#define GPTM_TA_TnMIS_R_DMAnMIS_BIT    (5UL)
#define GPTM_TA_TnMIS_R_DMAnMIS_INACTIVE    ((UBase_t) 0x00000000UL)
#define GPTM_TA_TnMIS_R_DMAnMIS_ACTIVE    ((UBase_t) 0x00000020UL)

#define GPTM_TA_TnMIS_DMAnMIS_MASK    ((UBase_t) 0x00000001UL)
#define GPTM_TA_TnMIS_DMAnMIS_INACTIVE    ((UBase_t) 0x00000000UL)
#define GPTM_TA_TnMIS_DMAnMIS_ACTIVE    ((UBase_t) 0x00000001UL)
/*----------*/

#endif /* XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_REGISTER_TIMER_REGISTERDEFINES_TIMER_REGISTERDEFINES_MODULEA_16_TIMER_REGISTERDEFINES_MODULEA_16_MIS_H_ */
