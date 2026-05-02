/**
 *
 * @file xDriver_MCU.h
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
 * @verbatim 19 jun. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 19 jun. 2020     vyldram    1.0         initial Version@endverbatim
 */
#ifndef XDRIVER_MCU_DRIVER_HEADER_DRIVER_H_
#define XDRIVER_MCU_DRIVER_HEADER_DRIVER_H_

/**TODO:
 * IN GPIO module add the functionality of ByNumber to modify only 1 bit of the register
 * Modify every register defines referenced to bit shift example:
 * #define PORT_DIR_R_PIN_ALL_BIT ((uint8_t) 0U)
 * #define PORT_DIR_R_PIN_ALL_MASK ((uint8_t) 0xFFU << PORT_DIR_R_PIN0_BIT)
 * #define PORT_DIR_R_PIN_ALL_INPUT ((uint8_t) 0x00U << PORT_DIR_R_PIN0_BIT)
 * #define PORT_DIR_R_PIN_ALL_OUTPUT ((uint8_t) 0xFFU << PORT_DIR_R_PIN0_BIT)

 * #define PORT_DIR_PIN_ALL_MASK ((uint8_t) 0xFFU)
 * #define PORT_DIR_PIN_ALL_INPUT ((uint8_t) 0x00U)
 * #define PORT_DIR_PIN_ALL_OUTPUT ((uint8_t) 0xFFU)
 * Create a new typedef of the protoype fo every source interrupt
 * typedef uint16_t (*MCU__pu16fIRQSourceHandler_t)(uintptr_t uptrModule, uint8_t u8IntSource);
 * Add two parameter a every source interrupt routines*/

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/Core/Core.h> /*Chapter 3*/

#include <xDriver_MCU/SYSCTL/SYSCTL.h> /*Chapter 5*/
#include <xDriver_MCU/SYSEXC/SYSEXC.h> /*Chapter 6*/
#include <xDriver_MCU/HIB/HIB.h>       /*Chapter 7*/
#include <xDriver_MCU/FLASH/FLASH.h>   /*Chapter 8.4*/
#include <xDriver_MCU/EEPROM/EEPROM.h> /*Chapter 8.5*/
#include <xDriver_MCU/DMA/DMA.h>       /*Chapter 9*/
#include <xDriver_MCU/GPIO/GPIO.h>     /*Chapter 10*/
/*#include <xDriver_MCU/EPI/EPI.h>       Chapter 11*/
/*#include <xDriver_MCU/CRC/CRC.h>       Chapter 12*/
/*#include <xDriver_MCU/AES/AES.h>       Chapter 13*/
/*#include <xDriver_MCU/DES/DES.h>       Chapter 14*/
/*#include <xDriver_MCU/SHA/SHA.h>       Chapter 15*/
#include <xDriver_MCU/TIMER/TIMER.h>   /*Chapter 16*/
#include <xDriver_MCU/WDT/WDT.h>       /*Chapter 17*/
#include <xDriver_MCU/ADC/ADC.h>       /*Chapter 18*/
#include <xDriver_MCU/UART/UART.h>     /*Chapter 19*/
#include <xDriver_MCU/SSI/SSI.h>       /*Chapter 20*/
#include <xDriver_MCU/I2C/I2C.h>       /*Chapter 21 TODO: DMA handling is pending*/
#include <xDriver_MCU/CAN/CAN.h>       /*Chapter 22 TODO: All the features*/
/*#include <xDriver_MCU/ETH/ETH.h>       Chapter 23*/
/*#include <xDriver_MCU/USB/USB.h>       Chapter 24*/
#include <xDriver_MCU/ACMP/ACMP.h>     /*Chapter 25*/
#include <xDriver_MCU/PWM/PWM.h>       /*Chapter 26*/
#include <xDriver_MCU/QEI/QEI.h>       /*Chapter 27*/

#endif /* XDRIVER_MCU_DRIVER_HEADER_DRIVER_H_ */
