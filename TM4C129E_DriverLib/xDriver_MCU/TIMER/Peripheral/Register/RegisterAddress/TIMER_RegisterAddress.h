/**
 *
 * @file TIMER_RegisterAddress.h
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
 * @verbatim 4 jul. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 4 jul. 2020     vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_REGISTER_TIMER_REGISTERADDRESS_H_
#define XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_REGISTER_TIMER_REGISTERADDRESS_H_

#include <xDriver_MCU/TIMER/Peripheral/Register/RegisterAddress/xHeader/TIMER_RegisterAddress_Control_32.h>
#include <xDriver_MCU/TIMER/Peripheral/Register/RegisterAddress/xHeader/TIMER_RegisterAddress_ModuleA_16.h>
#include <xDriver_MCU/TIMER/Peripheral/Register/RegisterAddress/xHeader/TIMER_RegisterAddress_ModuleB_16.h>
#include <xDriver_MCU/TIMER/Peripheral/Register/RegisterAddress/xHeader/TIMER_RegisterAddress_Standard_32.h>
#include <xDriver_MCU/TIMER/Peripheral/Register/RegisterAddress/xHeader/TIMER_RegisterAddress_ModuleW_32.h>


#define GPTM_BASE    ((UBase_t) 0x40030000UL)
#define GPTM0_BASE    ((UBase_t) 0x40030000UL)
#define GPTM1_BASE    ((UBase_t) 0x40031000UL)
#define GPTM2_BASE    ((UBase_t) 0x40032000UL)
#define GPTM3_BASE    ((UBase_t) 0x40033000UL)
#define GPTM4_BASE    ((UBase_t) 0x40034000UL)
#define GPTM5_BASE    ((UBase_t) 0x40035000UL)
#define GPTM6_BASE    ((UBase_t) 0x400E0000UL)
#define GPTM7_BASE    ((UBase_t) 0x400E1000UL)

#define GPTM_OFFSET    ((UBase_t) 0x00030000UL)
#define GPTM0_OFFSET    ((UBase_t) 0x00030000UL)
#define GPTM1_OFFSET    ((UBase_t) 0x00031000UL)
#define GPTM2_OFFSET    ((UBase_t) 0x00032000UL)
#define GPTM3_OFFSET    ((UBase_t) 0x00033000UL)
#define GPTM4_OFFSET    ((UBase_t) 0x00034000UL)
#define GPTM5_OFFSET    ((UBase_t) 0x00035000UL)
#define GPTM6_OFFSET    ((UBase_t) 0x000E0000UL)
#define GPTM7_OFFSET    ((UBase_t) 0x000E1000UL)

#define GPTM_BASE_BITBANDING    ((UBase_t) 0x42000000UL)

#endif /* XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_REGISTER_TIMER_REGISTERADDRESS_H_ */
