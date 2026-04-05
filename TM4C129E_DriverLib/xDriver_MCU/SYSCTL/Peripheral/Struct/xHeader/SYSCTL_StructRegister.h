/**
 *
 * @file SYSCTL_Struct.h
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
 * @verbatim 20 jun. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date Author Version Description
 * 20 jun. 2020 vyldram 1.0 initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_PERIPHERAL_SYSCTL_STRUCT_SYSCTL_STRUCTREGISTER_H_
#define XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_PERIPHERAL_SYSCTL_STRUCT_SYSCTL_STRUCTREGISTER_H_

#include <xDriver_MCU/SYSCTL/Peripheral/xHeader/SYSCTL_Enum.h>

typedef volatile struct
{
    volatile const UBase_t MINOR_REVISION :8;
    volatile const UBase_t MAJOR_REVISION :8;
    volatile const UBase_t CLASS :8;
    const UBase_t reserved :4;
    volatile const UBase_t VERSION :3;
    const UBase_t reserved1 :1;
}DEVICE_ID0_t;

typedef volatile struct
{
    volatile const UBase_t QUAL :2;
    volatile const UBase_t ROHS :1;
    volatile const UBase_t PKG :2;
    volatile const UBase_t TEMP :3;
    const UBase_t reserved :5;
    volatile const UBase_t PINCOUNT :3;
    volatile const UBase_t PARTNO :8;
    volatile const UBase_t FAMILY :4;
    volatile const UBase_t VERSION :4;
}DEVICE_ID1_t;

typedef volatile struct
{
    volatile UBase_t VDD_UBOR :2;
    const UBase_t reserved :6;
    volatile UBase_t VDDA_UBOR :2;
    const UBase_t reserved1 :22;
}PTBO_CTL_t;

typedef volatile struct
{
    const UBase_t reserved :1;
    volatile const UBase_t BOR :1;
    const UBase_t reserved1 :1;
    volatile const UBase_t MOSC_FAILURE :1;
    const UBase_t reserved2 :2;
    volatile const UBase_t PLL_LOCK :1;
    volatile const UBase_t reserved3 :1;
    volatile const UBase_t MOSC_POWERUP :1;
    const UBase_t reserved4 :23;
}SYSCTL_RIS_t;

typedef volatile struct
{
    const UBase_t reserved :1;
    volatile UBase_t BOR :1;
    const UBase_t reserved1 :1;
    volatile UBase_t MOSC_FAILURE :1;
    const UBase_t reserved2 :2;
    volatile UBase_t PLL_LOCK :1;
    volatile UBase_t reserved3 :1;
    volatile UBase_t MOSC_POWERUP :1;
    const UBase_t reserved4 :23;
}SYSCTL_IMC_t;

typedef volatile struct
{
    const UBase_t reserved :1;
    volatile UBase_t BOR :1;
    const UBase_t reserved1 :1;
    volatile UBase_t MOSC_FAILURE :1;
    const UBase_t reserved2 :2;
    volatile UBase_t PLL_LOCK :1;
    volatile UBase_t reserved3 :1;
    volatile UBase_t MOSC_POWERUP :1;
    const UBase_t reserved4 :23;
}SYSCTL_MISC_t;

typedef volatile struct
{
    volatile UBase_t EXTERNAL :1;
    volatile UBase_t POR :1;
    volatile UBase_t BOR:1;
    volatile UBase_t WDT0_ :1;
    volatile UBase_t SW :1;
    volatile UBase_t WDT1_ :1;
    const UBase_t reserved :6;
    volatile UBase_t HSSR :1;
    const UBase_t reserved1 :3;
    volatile UBase_t MOSC_FAILURE :1;
    const UBase_t reserved2:15;
}SYSCTL_RESC_t;

typedef volatile struct
{
    volatile UBase_t VDD_UBOR :1;
    const UBase_t reserved :3;
    volatile UBase_t VDDA_UBOR :1;
    const UBase_t reserved1 :27;
}SYSCTL_PWRTC_t;

typedef volatile struct
{
    volatile UBase_t EXTERNAL :1;
    const UBase_t reserved :1;
    volatile UBase_t POWER :1;
    volatile UBase_t WDT0_ :1;
    const UBase_t reserved1 :1;
    volatile UBase_t WDT1_ :1;
    const UBase_t reserved2 :3;
    volatile UBase_t TAMPER :1;
    const UBase_t reserved3 :6;
    volatile UBase_t MOSC_FAILURE :1;
    const UBase_t reserved4:15;
}SYSCTL_NMIC_t;

typedef volatile struct
{
    volatile UBase_t CVAL :1;
    volatile UBase_t MOSCIM :1;
    volatile UBase_t NOXTAL :1;
    volatile UBase_t PWRDN :1;
    volatile UBase_t OSCRNG :1;
    const UBase_t reserved :27;
}MOSC_CTL_t;

typedef volatile struct
{
    volatile const UBase_t RVP :32;
}SYSCTL_RVP_t;

typedef volatile struct
{
    volatile UBase_t READ_ENABLE0 :1;
    volatile UBase_t READ_ENABLE1 :1;
    volatile UBase_t READ_ENABLE2 :1;
    volatile UBase_t READ_ENABLE3 :1;
    volatile UBase_t READ_ENABLE4 :1;
    volatile UBase_t READ_ENABLE5 :1;
    volatile UBase_t READ_ENABLE6 :1;
    volatile UBase_t READ_ENABLE7 :1;
    volatile UBase_t READ_ENABLE8 :1;
    volatile UBase_t READ_ENABLE9 :1;
    volatile UBase_t READ_ENABLE10 :1;
    volatile UBase_t READ_ENABLE11 :1;
    volatile UBase_t READ_ENABLE12 :1;
    volatile UBase_t READ_ENABLE13 :1;
    volatile UBase_t READ_ENABLE14 :1;
    volatile UBase_t READ_ENABLE15 :1;
    volatile UBase_t READ_ENABLE16 :1;
    volatile UBase_t READ_ENABLE17 :1;
    volatile UBase_t READ_ENABLE18 :1;
    volatile UBase_t READ_ENABLE19 :1;
    volatile UBase_t READ_ENABLE20 :1;
    volatile UBase_t READ_ENABLE21 :1;
    volatile UBase_t READ_ENABLE22 :1;
    volatile UBase_t READ_ENABLE23 :1;
    volatile UBase_t READ_ENABLE24 :1;
    volatile UBase_t READ_ENABLE25 :1;
    volatile UBase_t READ_ENABLE26 :1;
    volatile UBase_t READ_ENABLE27 :1;
    volatile UBase_t READ_ENABLE28 :1;
    volatile UBase_t READ_ENABLE29 :1;
    volatile UBase_t READ_ENABLE30 :1;
    volatile UBase_t READ_ENABLE31 :1;
}FLASH_PRE_t;

typedef volatile struct
{
    volatile UBase_t PROG_ENABLE0 :1;
    volatile UBase_t PROG_ENABLE1 :1;
    volatile UBase_t PROG_ENABLE2 :1;
    volatile UBase_t PROG_ENABLE3 :1;
    volatile UBase_t PROG_ENABLE4 :1;
    volatile UBase_t PROG_ENABLE5 :1;
    volatile UBase_t PROG_ENABLE6 :1;
    volatile UBase_t PROG_ENABLE7 :1;
    volatile UBase_t PROG_ENABLE8 :1;
    volatile UBase_t PROG_ENABLE9 :1;
    volatile UBase_t PROG_ENABLE10 :1;
    volatile UBase_t PROG_ENABLE11 :1;
    volatile UBase_t PROG_ENABLE12 :1;
    volatile UBase_t PROG_ENABLE13 :1;
    volatile UBase_t PROG_ENABLE14 :1;
    volatile UBase_t PROG_ENABLE15 :1;
    volatile UBase_t PROG_ENABLE16 :1;
    volatile UBase_t PROG_ENABLE17 :1;
    volatile UBase_t PROG_ENABLE18 :1;
    volatile UBase_t PROG_ENABLE19 :1;
    volatile UBase_t PROG_ENABLE20 :1;
    volatile UBase_t PROG_ENABLE21 :1;
    volatile UBase_t PROG_ENABLE22 :1;
    volatile UBase_t PROG_ENABLE23 :1;
    volatile UBase_t PROG_ENABLE24 :1;
    volatile UBase_t PROG_ENABLE25 :1;
    volatile UBase_t PROG_ENABLE26 :1;
    volatile UBase_t PROG_ENABLE27 :1;
    volatile UBase_t PROG_ENABLE28 :1;
    volatile UBase_t PROG_ENABLE29 :1;
    volatile UBase_t PROG_ENABLE30 :1;
    volatile UBase_t PROG_ENABLE31 :1;
}FLASH_PPE_t;

typedef volatile struct
{
    volatile UBase_t PLL_SYSDIV :10;
    volatile UBase_t OSC_SYSDIV :10;
    volatile UBase_t OSC_SRC :4;
    volatile UBase_t PLL_SRC :4;
    volatile UBase_t USEPLL :1;
    volatile UBase_t ACG :1;
    volatile UBase_t NEW_PLLFREQ :1;
    volatile UBase_t MEMTIMU :1;
}RSCLK_CFG_t;

typedef volatile struct
{
    volatile UBase_t FLASH_WS :4;
    const UBase_t reserved :1;
    volatile UBase_t FLASH_BCE :1;
    volatile UBase_t FLASH_BCHT :4;
    const UBase_t reserved1 :6;
    volatile UBase_t EEPROM_WS :4;
    const UBase_t reserved2 :1;
    volatile UBase_t EEPROM_BCE :1;
    volatile UBase_t EEPROM_BCHT :4;
    const UBase_t reserved3 :6;
}MEMORY_TIM0_t;

typedef volatile struct
{
    volatile UBase_t ALTCLK :4;
    const UBase_t reserved :28;
}ALTCLK_CFG_t;

typedef volatile struct
{
    volatile UBase_t DEEPSLEEP_SYSDIV :10;
    const UBase_t reserved :10;
    volatile UBase_t DEEPSLEEP_OSC_SRC :4;
    const UBase_t reserved1 :6;
    volatile UBase_t MOSC_DPD :1;
    volatile UBase_t PIOSC_PD :1;
}DSCLK_CFG_t;

typedef volatile struct
{
    volatile UBase_t DIV :8;
    const UBase_t reserved :8;
    volatile UBase_t SRC :2;
    const UBase_t reserved1 :13;
    volatile UBase_t EN :1;
}DIVSCLK_CFG_t;

typedef volatile struct
{
    volatile const UBase_t FPU_ :1;
    const UBase_t reserved :4;
    volatile const UBase_t LDO_SEQ :1;
    const UBase_t reserved1 :2;
    volatile const UBase_t FLASH_LPM :1;
    const UBase_t reserved2 :1;
    volatile const UBase_t SRAM_LPM :1;
    volatile const UBase_t SRAM_SM :1;
    volatile const UBase_t PIOSC_PDE :1;
    const UBase_t reserved3 :3;
    volatile const UBase_t TS_PDE :1;
    volatile const UBase_t LDO_SME :1;
    const UBase_t reserved4 :14;
}SYSCTL_PROP_t;

typedef volatile struct
{
    volatile UBase_t UT :7;
    const UBase_t reserved :1;
    volatile UBase_t UPDATE :1;
    volatile UBase_t CAL :1;
    const UBase_t reserved1 :21;
    volatile UBase_t UTEN :1;
}PIOSC_CAL_t;

typedef volatile struct
{
    volatile const UBase_t CT :7;
    const UBase_t reserved :1;
    volatile const UBase_t RESULT :2;
    const UBase_t reserved1 :6;
    volatile const UBase_t DT :7;
    const UBase_t reserved2 :9;
}PIOSC_STAT_t;

typedef volatile struct
{
    volatile const UBase_t PLL_M_INT :10;
    volatile const UBase_t PLL_M_FRAC :10;
    const UBase_t reserved :3;
    volatile const UBase_t PLL_PWR :1;
    const UBase_t reserved1 :8;
}PLL_FREQ0_t;

typedef volatile struct
{
    volatile UBase_t PLL_N_VALUE :5;
    const UBase_t reserved :3;
    volatile UBase_t PLL_Q_VALUE :5;
    const UBase_t reserved1 :19;
}PLL_FREQ1_t;

typedef volatile struct
{
    volatile const UBase_t LOCK :1;
    const UBase_t reserved :31;
}PLL_STAT_t;

typedef volatile struct
{
    volatile UBase_t SRAM_PM :2;
    const UBase_t reserved :2;
    volatile UBase_t FLASH_PM :2;
    const UBase_t reserved1 :26;
}SLPPWR_CFG_t;

typedef volatile struct
{
    volatile UBase_t SRAM_PM :2;
    const UBase_t reserved :2;
    volatile UBase_t FLASH_PM :2;
    const UBase_t reserved1 :2;
    volatile UBase_t TS_PD :1;
    volatile UBase_t LDO_SM :1;
    const UBase_t reserved2 :22;
}DSLPPWR_CFG_t;

typedef volatile struct
{
    volatile const UBase_t FWB :1;
    const UBase_t reserved :31;
}NVM_STAT_t;

typedef volatile struct
{
    volatile UBase_t VLDO :8;
    const UBase_t reserved :23;
    volatile UBase_t VADJEN :1;
}LDO_SPCTL_t;

typedef volatile struct
{
    volatile const UBase_t NOPLL :8;
    volatile const UBase_t WITHPLL :8;
    const UBase_t reserved :16;
}LDO_SPCAL_t;

typedef volatile struct
{
    volatile UBase_t VLDO :8;
    const UBase_t reserved :23;
    volatile UBase_t VADJEN :1;
}LDO_DPCTL_t;

typedef volatile struct
{
    volatile const UBase_t KHZ30 :8;
    volatile const UBase_t NOPLL :8;
    const UBase_t reserved :16;
}LDO_DPCAL_t;

typedef volatile struct
{
    volatile const UBase_t SRAM_PD_ERR :1;
    volatile const UBase_t FLASH_PD_ERR :1;
    volatile const UBase_t PIOSC_PD_ERR :1;
    volatile const UBase_t VLDO_DMIN_ERR :1;
    volatile const UBase_t VLDO_SMIN_ERR :1;
    const UBase_t reserved :1;
    volatile const UBase_t VLDO_MAX_ERR :1;
    volatile const UBase_t PIOSC_PD_WARNING :1;
    const UBase_t reserved1:8;
    volatile const UBase_t LOW_ACTIVE :1;
    volatile const UBase_t LOW_PWR :1;
    volatile const UBase_t FLASH_LP :1;
    volatile const UBase_t LDO_UA :1;
    const UBase_t reserved2:12;
}SDP_MST_t;

typedef volatile struct
{
    volatile UBase_t EXTERNAL :2;
    volatile UBase_t BOR :2;
    volatile UBase_t WDG0_ :2;
    volatile UBase_t WDG1_ :2;
    const UBase_t reserved :24;
}RESET_BEHAVCTL_t;

typedef volatile struct
{
    volatile UBase_t CDOFF :24;
    volatile UBase_t KEY :8;
}SYSCTL_HSSR_t;

typedef volatile struct
{
    volatile const UBase_t PWRSTAT :2;
    volatile const UBase_t MEMSTAT :2;
    const UBase_t reserved :28;
}USB_PDS_t;

typedef volatile struct
{
    volatile UBase_t PWRCTL :2;
    const UBase_t reserved :30;
}USB_MPC_t;

typedef volatile struct
{
    volatile const UBase_t PWRSTAT :2;
    volatile const UBase_t MEMSTAT :2;
    const UBase_t reserved :28;
}EMAC_PDS_t;

typedef volatile struct
{
    volatile UBase_t PWRCTL :2;
    const UBase_t reserved :30;
}EMAC_MPC_t;

typedef volatile struct
{
    volatile const UBase_t PWRSTAT :2;
    volatile const UBase_t MEMSTAT :2;
    const UBase_t reserved :28;
}CAN0_PDS_t;

typedef volatile struct
{
    volatile UBase_t PWRCTL :2;
    const UBase_t reserved :30;
}CAN0_MPC_t;

typedef volatile struct
{
    volatile const UBase_t PWRSTAT :2;
    volatile const UBase_t MEMSTAT :2;
    const UBase_t reserved :28;
}CAN1_PDS_t;

typedef volatile struct
{
    volatile UBase_t PWRCTL :2;
    const UBase_t reserved :30;
}CAN1_MPC_t;

typedef volatile struct
{
    volatile const UBase_t DBG0 :1;
    volatile const UBase_t DBG1 :1;
    const UBase_t reserved :2;
    volatile const UBase_t KEY :1;
    const UBase_t reserved1 :3;
    volatile const UBase_t EN :1;
    volatile const UBase_t POL :1;
    volatile const UBase_t PIN :3;
    volatile const UBase_t PORT :3;
    const UBase_t reserved2 :15;
    volatile const UBase_t NW :1;
}BOOT_CFG_t;

typedef volatile struct
{
    volatile const UBase_t DATA :32;
}USER_REG_t;

typedef volatile struct
{
    volatile UBase_t P0 :1;
    volatile UBase_t P1 :1;
    volatile UBase_t P2 :1;
    volatile UBase_t P3 :1;
    volatile UBase_t P4 :1;
    volatile UBase_t P5 :1;
    volatile UBase_t P6 :1;
    volatile UBase_t P7 :1;
    volatile UBase_t P8 :1;
    volatile UBase_t P9 :1;
    volatile UBase_t P10 :1;
    volatile UBase_t P11 :1;
    volatile UBase_t P12 :1;
    volatile UBase_t P13 :1;
    volatile UBase_t P14 :1;
    volatile UBase_t P15 :1;
    volatile UBase_t P16 :1;
    volatile UBase_t P17 :1;
    volatile UBase_t P18 :1;
    volatile UBase_t P19 :1;
    volatile UBase_t P20 :1;
    volatile UBase_t P21 :1;
    volatile UBase_t P22 :1;
    volatile UBase_t P23 :1;
    volatile UBase_t P24 :1;
    volatile UBase_t P25 :1;
    volatile UBase_t P26 :1;
    volatile UBase_t P27 :1;
    volatile UBase_t P28 :1;
    volatile UBase_t P29 :1;
    volatile UBase_t P30 :1;
    volatile UBase_t P31 :1;
}PERIPHERAL_t;

typedef volatile struct
{
    volatile UBase_t WDT0_ :1;
    volatile UBase_t WDT1_ :1;
    const UBase_t reserved:30;
}PERIPHERAL_WD_t;

typedef volatile struct
{
    volatile UBase_t TIMER0_ :1;
    volatile UBase_t TIMER1_ :1;
    volatile UBase_t TIMER2_ :1;
    volatile UBase_t TIMER3_ :1;
    volatile UBase_t TIMER4_ :1;
    volatile UBase_t TIMER5_ :1;
    volatile UBase_t TIMER6_ :1;
    volatile UBase_t TIMER7_ :1;
    const UBase_t reserved :24;
}PERIPHERAL_TIMER_t;

typedef volatile struct
{
    volatile UBase_t GPIOA_ :1;
    volatile UBase_t GPIOB_ :1;
    volatile UBase_t GPIOC_ :1;
    volatile UBase_t GPIOD_ :1;
    volatile UBase_t GPIOE_ :1;
    volatile UBase_t GPIOF_ :1;
    volatile UBase_t GPIOG_ :1;
    volatile UBase_t GPIOH_ :1;
    volatile UBase_t GPIOJ_ :1;
    volatile UBase_t GPIOK_ :1;
    volatile UBase_t GPIOL_ :1;
    volatile UBase_t GPIOM_ :1;
    volatile UBase_t GPION_ :1;
    volatile UBase_t GPIOP_ :1;
    volatile UBase_t GPIOQ_ :1;
    const UBase_t reserved :17;
}PERIPHERAL_GPIO_t;

typedef volatile struct
{
    volatile UBase_t UDMA_ :1;
    const UBase_t reserved :31;
}PERIPHERAL_DMA_t;

typedef volatile struct
{
    volatile UBase_t EPI0_ :1;
    const UBase_t reserved :31;
}PERIPHERAL_EPI_t;

typedef volatile struct
{
    volatile UBase_t HIB_ :1;
    const UBase_t reserved :31;
}PERIPHERAL_HIB_t;

typedef volatile struct
{
    volatile UBase_t UART0_ :1;
    volatile UBase_t UART1_ :1;
    volatile UBase_t UART2_ :1;
    volatile UBase_t UART3_ :1;
    volatile UBase_t UART4_ :1;
    volatile UBase_t UART5_ :1;
    volatile UBase_t UART6_ :1;
    volatile UBase_t UART7_ :1;
    const UBase_t reserved :24;
}PERIPHERAL_UART_t;

typedef volatile struct
{
    volatile UBase_t SSI0_ :1;
    volatile UBase_t SSI1_ :1;
    volatile UBase_t SSI2_ :1;
    volatile UBase_t SSI3_ :1;
    const UBase_t reserved :28;
}PERIPHERAL_SSI_t;

typedef volatile struct
{
    volatile UBase_t I2C0_ :1;
    volatile UBase_t I2C1_ :1;
    volatile UBase_t I2C2_ :1;
    volatile UBase_t I2C3_ :1;
    volatile UBase_t I2C4_ :1;
    volatile UBase_t I2C5_ :1;
    volatile UBase_t I2C6_ :1;
    volatile UBase_t I2C7_ :1;
    volatile UBase_t I2C8_ :1;
    volatile UBase_t I2C9_ :1;
    const UBase_t reserved :22;
}PERIPHERAL_I2C_t;

typedef volatile struct
{
    volatile UBase_t USB_ :1;
    const UBase_t reserved :31;
}PERIPHERAL_USB_t;

typedef volatile struct
{
    volatile UBase_t EPHY_ :1;
    const UBase_t reserved :31;
}PERIPHERAL_EPHY_t;

typedef volatile struct
{
    volatile UBase_t CAN0_ :1;
    volatile UBase_t CAN1_ :1;
    const UBase_t reserved :30;
}PERIPHERAL_CAN_t;

typedef volatile struct
{
    volatile UBase_t ADC0_ :1;
    volatile UBase_t ADC1_ :1;
    const UBase_t reserved:30;
}PERIPHERAL_ADC_t;

typedef volatile struct
{
    volatile UBase_t ACMP_ :1;
    const UBase_t reserved:31;
}PERIPHERAL_ACMP_t;

typedef volatile struct
{
    volatile UBase_t PWM0_ :1;
    const UBase_t reserved:31;
}PERIPHERAL_PWM_t;

typedef volatile struct
{
    volatile UBase_t QEI0_ :1;
    const UBase_t reserved:31;
}PERIPHERAL_QEI_t;

typedef volatile struct
{
    volatile UBase_t LPC_ :1;
    const UBase_t reserved:31;
}PERIPHERAL_LPC_t;

typedef volatile struct
{
    volatile UBase_t PECI_ :1;
    const UBase_t reserved:31;
}PERIPHERAL_PECI_t;

typedef volatile struct
{
    volatile UBase_t FAN_ :1;
    const UBase_t reserved:31;
}PERIPHERAL_FAN_t;

typedef volatile struct
{
    volatile UBase_t EEPROM_ :1;
    const UBase_t reserved:31;
}PERIPHERAL_EEPROM_t;

typedef volatile struct
{
    volatile UBase_t WTIMER0_ :1;
    const UBase_t reserved :31;
}PERIPHERAL_WTIMER_t;

typedef volatile struct
{
    volatile UBase_t RTS_ :1;
    const UBase_t reserved :31;
}PERIPHERAL_RTS_t;

typedef volatile struct
{
    volatile UBase_t CCM_ :1;
    const UBase_t reserved :31;
}PERIPHERAL_CCM_t;

typedef volatile struct
{
    volatile UBase_t LCD_ :1;
    const UBase_t reserved :31;
}PERIPHERAL_LCD_t;

typedef volatile struct
{
    volatile UBase_t OWIRE_ :1;
    const UBase_t reserved :31;
}PERIPHERAL_OWIRE_t;

typedef volatile struct
{
    volatile UBase_t EMAC_ :1;
    const UBase_t reserved :31;
}PERIPHERAL_EMAC_t;

typedef volatile struct
{
    volatile UBase_t PRB_ :1;
    const UBase_t reserved :31;
}PERIPHERAL_PRB_t;

typedef volatile struct
{
    volatile UBase_t HIM_ :1;
    const UBase_t reserved :31;
}PERIPHERAL_HIM_t;

typedef volatile struct
{
    volatile const UBase_t ID :32;
}UNIQUE_ID_t;/*0x00000008*/

typedef volatile struct
{
    volatile UBase_t SHACFG :1;
    volatile UBase_t AESCFG :1;
    volatile UBase_t DESCFG :1;
    const UBase_t reserved :29;
}CCM_CGREQ_t;

#endif /* XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_PERIPHERAL_SYSCTL_STRUCT_SYSCTL_STRUCTREGISTER_H_ */
