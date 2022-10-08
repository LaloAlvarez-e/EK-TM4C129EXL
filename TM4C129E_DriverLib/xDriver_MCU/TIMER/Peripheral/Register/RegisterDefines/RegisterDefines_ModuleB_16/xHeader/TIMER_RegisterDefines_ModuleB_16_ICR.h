/**
 *
 * @file TIMER_RegisterDefines_ModuleB_16_ICR.h
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
 * @verbatim 7 jul. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 7 jul. 2020     vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_REGISTER_TIMER_REGISTERDEFINES_TIMER_REGISTERDEFINES_MODULEB_16_TIMER_REGISTERDEFINES_MODULEB_16_ICR_H_
#define XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_REGISTER_TIMER_REGISTERDEFINES_TIMER_REGISTERDEFINES_MODULEB_16_TIMER_REGISTERDEFINES_MODULEB_16_ICR_H_

#include <xDriver_MCU/TIMER/Peripheral/xHeader/TIMER_Enum.h>

/******************************************************************************************
************************************ 9 ICR *********************************************
******************************************************************************************/

/*----------*/
#define GPTM_TB_TnICR_R_TnTOCINT_MASK    ((UBase_t) 0x00000100UL)
#define GPTM_TB_TnICR_R_TnTOCINT_BIT    (8UL)
#define GPTM_TB_TnICR_R_TnTOCINT_DIS    ((UBase_t) 0x00000000UL)
#define GPTM_TB_TnICR_R_TnTOCINT_ENA    ((UBase_t) 0x00000100UL)

#define GPTM_TB_TnICR_TnTOCINT_MASK    ((UBase_t) 0x00000001UL)
#define GPTM_TB_TnICR_TnTOCINT_DIS    ((UBase_t) 0x00000000UL)
#define GPTM_TB_TnICR_TnTOCINT_ENA    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define GPTM_TB_TnICR_R_CnMCINT_MASK    ((UBase_t) 0x00000200UL)
#define GPTM_TB_TnICR_R_CnMCINT_BIT    (9UL)
#define GPTM_TB_TnICR_R_CnMCINT_DIS    ((UBase_t) 0x00000000UL)
#define GPTM_TB_TnICR_R_CnMCINT_ENA    ((UBase_t) 0x00000200UL)

#define GPTM_TB_TnICR_CnMCINT_MASK    ((UBase_t) 0x00000001UL)
#define GPTM_TB_TnICR_CnMCINT_DIS    ((UBase_t) 0x00000000UL)
#define GPTM_TB_TnICR_CnMCINT_ENA    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define GPTM_TB_TnICR_R_CnECINT_MASK    ((UBase_t) 0x00000400UL)
#define GPTM_TB_TnICR_R_CnECINT_BIT    (10UL)
#define GPTM_TB_TnICR_R_CnECINT_DIS    ((UBase_t) 0x00000000UL)
#define GPTM_TB_TnICR_R_CnECINT_ENA    ((UBase_t) 0x00000400UL)

#define GPTM_TB_TnICR_CnECINT_MASK    ((UBase_t) 0x00000001UL)
#define GPTM_TB_TnICR_CnECINT_DIS    ((UBase_t) 0x00000000UL)
#define GPTM_TB_TnICR_CnECINT_ENA    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define GPTM_TB_TnICR_R_TnMCINT_MASK    ((UBase_t) 0x00000800UL)
#define GPTM_TB_TnICR_R_TnMCINT_BIT    (11UL)
#define GPTM_TB_TnICR_R_TnMCINT_DIS    ((UBase_t) 0x00000000UL)
#define GPTM_TB_TnICR_R_TnMCINT_ENA    ((UBase_t) 0x00000800UL)

#define GPTM_TB_TnICR_TnMCINT_MASK    ((UBase_t) 0x00000001UL)
#define GPTM_TB_TnICR_TnMCINT_DIS    ((UBase_t) 0x00000000UL)
#define GPTM_TB_TnICR_TnMCINT_ENA    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define GPTM_TB_TnICR_R_DMAnINT_MASK    ((UBase_t) 0x00002000UL)
#define GPTM_TB_TnICR_R_DMAnINT_BIT    (13UL)
#define GPTM_TB_TnICR_R_DMAnINT_DIS    ((UBase_t) 0x00000000UL)
#define GPTM_TB_TnICR_R_DMAnINT_ENA    ((UBase_t) 0x00002000UL)

#define GPTM_TB_TnICR_DMAnINT_MASK    ((UBase_t) 0x00000001UL)
#define GPTM_TB_TnICR_DMAnINT_DIS    ((UBase_t) 0x00000000UL)
#define GPTM_TB_TnICR_DMAnINT_ENA    ((UBase_t) 0x00000001UL)
/*----------*/

#endif /* XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_REGISTER_TIMER_REGISTERDEFINES_TIMER_REGISTERDEFINES_MODULEB_16_TIMER_REGISTERDEFINES_MODULEB_16_ICR_H_ */
