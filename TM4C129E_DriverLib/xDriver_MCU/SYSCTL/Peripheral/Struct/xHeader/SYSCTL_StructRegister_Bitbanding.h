/**
 *
 * @file SYSCTL_StructRegister_Bitbanding.h
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

#ifndef XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_PERIPHERAL_SYSCTL_STRUCT_SYSCTL_STRUCTREGISTER_BITBANDING_H_
#define XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_PERIPHERAL_SYSCTL_STRUCT_SYSCTL_STRUCTREGISTER_BITBANDING_H_

#include <xDriver_MCU/SYSCTL/Peripheral/xHeader/SYSCTL_Enum.h>

typedef volatile struct
{
    volatile const UBase_t MINOR_REVISION[8UL];
    volatile const UBase_t MAJOR_REVISION[8UL];
    volatile const UBase_t CLASS[8UL];
    const UBase_t reserved[4UL];
    volatile const UBase_t VERSION[3UL];
    const UBase_t reserved1;
}DEVICE_BITBANDING_ID0_t;

typedef volatile struct
{
    volatile const UBase_t QUAL[2UL];
    volatile const UBase_t ROHS;
    volatile const UBase_t PKG[2UL];
    volatile const UBase_t TEMP[3UL];
    const UBase_t reserved[5UL];
    volatile const UBase_t PINCOUNT[3UL];
    volatile const UBase_t PARTNO[8UL];
    volatile const UBase_t FAMILY[4UL];
    volatile const UBase_t VERSION[4UL];
}DEVICE_BITBANDING_ID1_t;

typedef volatile struct
{
    volatile UBase_t VDD_UBOR[2UL];
    const UBase_t reserved[6UL];
    volatile UBase_t VDDA_UBOR[2UL];
    const UBase_t reserved1[22UL];
}PTBO_BITBANDING_CTL_t;

typedef volatile struct
{
    const UBase_t reserved;
    volatile const UBase_t BOR;
    const UBase_t reserved1;
    volatile const UBase_t MOSC_FAILURE;
    const UBase_t reserved2[2UL];
    volatile const UBase_t PLL_LOCK;
    volatile const UBase_t reserved3;
    volatile const UBase_t MOSC_POWERUP;
    const UBase_t reserved4[23UL];
}SYSCTL_BITBANDING_RIS_t;

typedef volatile struct
{
    const UBase_t reserved;
    volatile UBase_t BOR;
    const UBase_t reserved1;
    volatile UBase_t MOSC_FAILURE;
    const UBase_t reserved2[2UL];
    volatile UBase_t PLL_LOCK;
    volatile UBase_t reserved3;
    volatile UBase_t MOSC_POWERUP;
    const UBase_t reserved4[23UL];
}SYSCTL_BITBANDING_IMC_t;

typedef volatile struct
{
    const UBase_t reserved;
    volatile UBase_t BOR;
    const UBase_t reserved1;
    volatile UBase_t MOSC_FAILURE;
    const UBase_t reserved2[2UL];
    volatile UBase_t PLL_LOCK;
    volatile UBase_t reserved3;
    volatile UBase_t MOSC_POWERUP;
    const UBase_t reserved4[23UL];
}SYSCTL_BITBANDING_MISC_t;

typedef volatile struct
{
    volatile UBase_t EXTERNAL;
    volatile UBase_t POR;
    volatile UBase_t BOR;
    volatile UBase_t WDT0_;
    volatile UBase_t SW;
    volatile UBase_t WDT1_;
    const UBase_t reserved[6UL];
    volatile UBase_t HSSR;
    const UBase_t reserved1[3UL];
    volatile UBase_t MOSC_FAILURE;
    const UBase_t reserved2[15UL];
}SYSCTL_BITBANDING_RESC_t;

typedef volatile struct
{
    volatile UBase_t VDD_UBOR;
    const UBase_t reserved[3UL];
    volatile UBase_t VDDA_UBOR;
    const UBase_t reserved1[27UL];
}SYSCTL_BITBANDING_PWRTC_t;

typedef volatile struct
{
    volatile UBase_t EXTERNAL;
    const UBase_t reserved;
    volatile UBase_t POWER;
    volatile UBase_t WDT0_;
    const UBase_t reserved1;
    volatile UBase_t WDT1_;
    const UBase_t reserved2[3UL];
    volatile UBase_t TAMPER;
    const UBase_t reserved3[6UL];
    volatile UBase_t MOSC_FAILURE;
    const UBase_t reserved4[15UL];
}SYSCTL_BITBANDING_NMIC_t;

typedef volatile struct
{
    volatile UBase_t CVAL;
    volatile UBase_t MOSCIM;
    volatile UBase_t NOXTAL;
    volatile UBase_t PWRDN;
    volatile UBase_t OSCRNG;
    const UBase_t reserved[27UL];
}MOSC_BITBANDING_CTL_t;

typedef volatile struct
{
    volatile const UBase_t RVP[32UL];
}SYSCTL_BITBANDING_RVP_t;

typedef volatile struct
{
    volatile UBase_t READ_ENABLE0;
    volatile UBase_t READ_ENABLE1;
    volatile UBase_t READ_ENABLE2;
    volatile UBase_t READ_ENABLE3;
    volatile UBase_t READ_ENABLE4;
    volatile UBase_t READ_ENABLE5;
    volatile UBase_t READ_ENABLE6;
    volatile UBase_t READ_ENABLE7;
    volatile UBase_t READ_ENABLE8;
    volatile UBase_t READ_ENABLE9;
    volatile UBase_t READ_ENABLE10;
    volatile UBase_t READ_ENABLE11;
    volatile UBase_t READ_ENABLE12;
    volatile UBase_t READ_ENABLE13;
    volatile UBase_t READ_ENABLE14;
    volatile UBase_t READ_ENABLE15;
    volatile UBase_t READ_ENABLE16;
    volatile UBase_t READ_ENABLE17;
    volatile UBase_t READ_ENABLE18;
    volatile UBase_t READ_ENABLE19;
    volatile UBase_t READ_ENABLE20;
    volatile UBase_t READ_ENABLE21;
    volatile UBase_t READ_ENABLE22;
    volatile UBase_t READ_ENABLE23;
    volatile UBase_t READ_ENABLE24;
    volatile UBase_t READ_ENABLE25;
    volatile UBase_t READ_ENABLE26;
    volatile UBase_t READ_ENABLE27;
    volatile UBase_t READ_ENABLE28;
    volatile UBase_t READ_ENABLE29;
    volatile UBase_t READ_ENABLE30;
    volatile UBase_t READ_ENABLE31;
}FLASH_BITBANDING_PRE_t;

typedef volatile struct
{
    volatile UBase_t PROG_ENABLE0;
    volatile UBase_t PROG_ENABLE1;
    volatile UBase_t PROG_ENABLE2;
    volatile UBase_t PROG_ENABLE3;
    volatile UBase_t PROG_ENABLE4;
    volatile UBase_t PROG_ENABLE5;
    volatile UBase_t PROG_ENABLE6;
    volatile UBase_t PROG_ENABLE7;
    volatile UBase_t PROG_ENABLE8;
    volatile UBase_t PROG_ENABLE9;
    volatile UBase_t PROG_ENABLE10;
    volatile UBase_t PROG_ENABLE11;
    volatile UBase_t PROG_ENABLE12;
    volatile UBase_t PROG_ENABLE13;
    volatile UBase_t PROG_ENABLE14;
    volatile UBase_t PROG_ENABLE15;
    volatile UBase_t PROG_ENABLE16;
    volatile UBase_t PROG_ENABLE17;
    volatile UBase_t PROG_ENABLE18;
    volatile UBase_t PROG_ENABLE19;
    volatile UBase_t PROG_ENABLE20;
    volatile UBase_t PROG_ENABLE21;
    volatile UBase_t PROG_ENABLE22;
    volatile UBase_t PROG_ENABLE23;
    volatile UBase_t PROG_ENABLE24;
    volatile UBase_t PROG_ENABLE25;
    volatile UBase_t PROG_ENABLE26;
    volatile UBase_t PROG_ENABLE27;
    volatile UBase_t PROG_ENABLE28;
    volatile UBase_t PROG_ENABLE29;
    volatile UBase_t PROG_ENABLE30;
    volatile UBase_t PROG_ENABLE31;
}FLASH_BITBANDING_PPE_t;

typedef volatile struct
{
    volatile UBase_t PLL_SYSDIV[10UL];
    volatile UBase_t OSC_SYSDIV[10UL];
    volatile UBase_t OSC_SRC[4UL];
    volatile UBase_t PLL_SRC[4UL];
    volatile UBase_t USEPLL;
    volatile UBase_t ACG;
    volatile UBase_t NEW_PLLFREQ;
    volatile UBase_t MEMTIMU;
}RSCLK_BITBANDING_CFG_t;

typedef volatile struct
{
    volatile UBase_t FLASH_WS[4UL];
    const UBase_t reserved;
    volatile UBase_t FLASH_BCE;
    volatile UBase_t FLASH_BCHT[4UL];
    const UBase_t reserved1[6UL];
    volatile UBase_t EEPROM_WS[4UL];
    const UBase_t reserved2;
    volatile UBase_t EEPROM_BCE;
    volatile UBase_t EEPROM_BCHT[4UL];
    const UBase_t reserved3[6UL];
}MEMORY_BITBANDING_TIM0_t;

typedef volatile struct
{
    volatile UBase_t ALTCLK[4UL];
    const UBase_t reserved[28UL];
}ALTCLK_BITBANDING_CFG_t;

typedef volatile struct
{
    volatile UBase_t DEEPSLEEP_SYSDIV[10UL];
    const UBase_t reserved[10UL];
    volatile UBase_t DEEPSLEEP_OSC_SRC[4UL];
    const UBase_t reserved1[6UL];
    volatile UBase_t MOSC_DPD;
    volatile UBase_t PIOSC_PD;
}DSCLK_BITBANDING_CFG_t;

typedef volatile struct
{
    volatile UBase_t DIV[8UL];
    const UBase_t reserved[8UL];
    volatile UBase_t SRC[2UL];
    const UBase_t reserved1[13UL];
    volatile UBase_t EN;
}DIVSCLK_BITBANDING_CFG_t;

typedef volatile struct
{
    volatile const UBase_t FPU_;
    const UBase_t reserved[4UL];
    volatile const UBase_t LDO_SEQ;
    const UBase_t reserved1[2UL];
    volatile const UBase_t FLASH_LPM;
    const UBase_t reserved2;
    volatile const UBase_t SRAM_LPM;
    volatile const UBase_t SRAM_SM;
    volatile const UBase_t PIOSC_PDE;
    const UBase_t reserved3[3UL];
    volatile const UBase_t TS_PDE;
    volatile const UBase_t LDO_SME;
    const UBase_t reserved4[14UL];
}SYSCTL_BITBANDING_PROP_t;

typedef volatile struct
{
    volatile UBase_t UT[7UL];
    const UBase_t reserved;
    volatile UBase_t UPDATE;
    volatile UBase_t CAL;
    const UBase_t reserved1[21UL];
    volatile UBase_t UTEN;
}PIOSC_BITBANDING_CAL_t;

typedef volatile struct
{
    volatile const UBase_t CT[7UL];
    const UBase_t reserved;
    volatile const UBase_t RESULT[2UL];
    const UBase_t reserved1[6UL];
    volatile const UBase_t DT[7UL];
    const UBase_t reserved2[9UL];
}PIOSC_BITBANDING_STAT_t;

typedef volatile struct
{
    volatile const UBase_t PLL_M_INT[10UL];
    volatile const UBase_t PLL_M_FRAC[10UL];
    const UBase_t reserved[3UL];
    volatile const UBase_t PLL_PWR;
    const UBase_t reserved1[8UL];
}PLL_BITBANDING_FREQ0_t;

typedef volatile struct
{
    volatile UBase_t PLL_N_VALUE[5UL];
    const UBase_t reserved[3UL];
    volatile UBase_t PLL_Q_VALUE[5UL];
    const UBase_t reserved1[19UL];
}PLL_BITBANDING_FREQ1_t;

typedef volatile struct
{
    volatile const UBase_t LOCK;
    const UBase_t reserved[31UL];
}PLL_BITBANDING_STAT_t;

typedef volatile struct
{
    volatile UBase_t SRAM_PM[2UL];
    const UBase_t reserved[2UL];
    volatile UBase_t FLASH_PM[2UL];
    const UBase_t reserved1[26UL];
}SLPPWR_BITBANDING_CFG_t;

typedef volatile struct
{
    volatile UBase_t SRAM_PM[2UL];
    const UBase_t reserved[2UL];
    volatile UBase_t FLASH_PM[2UL];
    const UBase_t reserved1[2UL];
    volatile UBase_t TS_PD;
    volatile UBase_t LDO_SM;
    const UBase_t reserved2[22UL];
}DSLPPWR_BITBANDING_CFG_t;

typedef volatile struct
{
    volatile const UBase_t FWB;
    const UBase_t reserved[31UL];
}NVM_BITBANDING_STAT_t;

typedef volatile struct
{
    volatile UBase_t VLDO[8UL];
    const UBase_t reserved[23UL];
    volatile UBase_t VADJEN;
}LDO_BITBANDING_SPCTL_t;

typedef volatile struct
{
    volatile const UBase_t NOPLL[8UL];
    volatile const UBase_t WITHPLL[8UL];
    const UBase_t reserved[16UL];
}LDO_BITBANDING_SPCAL_t;

typedef volatile struct
{
    volatile UBase_t VLDO[8UL];
    const UBase_t reserved[23UL];
    volatile UBase_t VADJEN;
}LDO_BITBANDING_DPCTL_t;

typedef volatile struct
{
    volatile const UBase_t KHZ30[8UL];
    volatile const UBase_t NOPLL[8UL];
    const UBase_t reserved[16UL];
}LDO_BITBANDING_DPCAL_t;

typedef volatile struct
{
    volatile const UBase_t SRAM_PD_ERR;
    volatile const UBase_t FLASH_PD_ERR;
    volatile const UBase_t PIOSC_PD_ERR;
    volatile const UBase_t VLDO_DMIN_ERR;
    volatile const UBase_t VLDO_SMIN_ERR;
    const UBase_t reserved;
    volatile const UBase_t VLDO_MAX_ERR;
    volatile const UBase_t PIOSC_PD_WARNING;
    const UBase_t reserved1[8UL];
    volatile const UBase_t LOW_ACTIVE;
    volatile const UBase_t LOW_PWR;
    volatile const UBase_t FLASH_LP;
    volatile const UBase_t LDO_UA;
    const UBase_t reserved2[12UL];
}SDP_BITBANDING_MST_t;

typedef volatile struct
{
    volatile UBase_t EXTERNAL[2UL];
    volatile UBase_t BOR[2UL];
    volatile UBase_t WDG0_[2UL];
    volatile UBase_t WDG1_[2UL];
    const UBase_t reserved[24UL];
}RESET_BITBANDING_BEHAVCTL_t;

typedef volatile struct
{
    volatile UBase_t CDOFF[24UL];
    volatile UBase_t KEY[8UL];
}SYSCTL_BITBANDING_HSSR_t;

typedef volatile struct
{
    volatile const UBase_t PWRSTAT[2UL];
    volatile const UBase_t MEMSTAT[2UL];
    const UBase_t reserved[28UL];
}USB_BITBANDING_PDS_t;

typedef volatile struct
{
    volatile UBase_t PWRCTL[2UL];
    const UBase_t reserved[30UL];
}USB_BITBANDING_MPC_t;

typedef volatile struct
{
    volatile const UBase_t PWRSTAT[2UL];
    volatile const UBase_t MEMSTAT[2UL];
    const UBase_t reserved[28UL];
}EMAC_BITBANDING_PDS_t;

typedef volatile struct
{
    volatile UBase_t PWRCTL[2UL];
    const UBase_t reserved[30UL];
}EMAC_BITBANDING_MPC_t;

typedef volatile struct
{
    volatile const UBase_t PWRSTAT[2UL];
    volatile const UBase_t MEMSTAT[2UL];
    const UBase_t reserved[28UL];
}CAN0_BITBANDING_PDS_t;

typedef volatile struct
{
    volatile UBase_t PWRCTL[2UL];
    const UBase_t reserved[30UL];
}CAN0_BITBANDING_MPC_t;

typedef volatile struct
{
    volatile const UBase_t PWRSTAT[2UL];
    volatile const UBase_t MEMSTAT[2UL];
    const UBase_t reserved[28UL];
}CAN1_BITBANDING_PDS_t;

typedef volatile struct
{
    volatile UBase_t PWRCTL[2UL];
    const UBase_t reserved[30UL];
}CAN1_BITBANDING_MPC_t;

typedef volatile struct
{
    volatile const UBase_t DBG0;
    volatile const UBase_t DBG1;
    const UBase_t reserved[2UL];
    volatile const UBase_t KEY;
    const UBase_t reserved1[3UL];
    volatile const UBase_t EN;
    volatile const UBase_t POL;
    volatile const UBase_t PIN[3UL];
    volatile const UBase_t PORT[3UL];
    const UBase_t reserved2[15UL];
    volatile const UBase_t NW;
}BOOT_BITBANDING_CFG_t;

typedef volatile struct
{
    volatile const UBase_t DATA[32UL];
}USER_BITBANDING_REG_t;

typedef volatile struct
{
    volatile UBase_t P0;
    volatile UBase_t P1;
    volatile UBase_t P2;
    volatile UBase_t P3;
    volatile UBase_t P4;
    volatile UBase_t P5;
    volatile UBase_t P6;
    volatile UBase_t P7;
    volatile UBase_t P8;
    volatile UBase_t P9;
    volatile UBase_t P10;
    volatile UBase_t P11;
    volatile UBase_t P12;
    volatile UBase_t P13;
    volatile UBase_t P14;
    volatile UBase_t P15;
    volatile UBase_t P16;
    volatile UBase_t P17;
    volatile UBase_t P18;
    volatile UBase_t P19;
    volatile UBase_t P20;
    volatile UBase_t P21;
    volatile UBase_t P22;
    volatile UBase_t P23;
    volatile UBase_t P24;
    volatile UBase_t P25;
    volatile UBase_t P26;
    volatile UBase_t P27;
    volatile UBase_t P28;
    volatile UBase_t P29;
    volatile UBase_t P30;
    volatile UBase_t P31;
}PERIPHERAL_BITBANDING_t;

typedef volatile struct
{
    volatile UBase_t WDT0_;
    volatile UBase_t WDT1_;
    const UBase_t reserved[30UL];
}PERIPHERAL_BITBANDING_WD_t;

typedef volatile struct
{
    volatile UBase_t TIMER0_;
    volatile UBase_t TIMER1_;
    volatile UBase_t TIMER2_;
    volatile UBase_t TIMER3_;
    volatile UBase_t TIMER4_;
    volatile UBase_t TIMER5_;
    volatile UBase_t TIMER6_;
    volatile UBase_t TIMER7_;
    const UBase_t reserved[24UL];
}PERIPHERAL_BITBANDING_TIMER_t;

typedef volatile struct
{
    volatile UBase_t GPIOA_;
    volatile UBase_t GPIOB_;
    volatile UBase_t GPIOC_;
    volatile UBase_t GPIOD_;
    volatile UBase_t GPIOE_;
    volatile UBase_t GPIOF_;
    volatile UBase_t GPIOG_;
    volatile UBase_t GPIOH_;
    volatile UBase_t GPIOJ_;
    volatile UBase_t GPIOK_;
    volatile UBase_t GPIOL_;
    volatile UBase_t GPIOM_;
    volatile UBase_t GPION_;
    volatile UBase_t GPIOP_;
    volatile UBase_t GPIOQ_;
    const UBase_t reserved[17UL];
}PERIPHERAL_BITBANDING_GPIO_t;

typedef volatile struct
{
    volatile UBase_t UDMA_;
    const UBase_t reserved[31UL];
}PERIPHERAL_BITBANDING_DMA_t;

typedef volatile struct
{
    volatile UBase_t EPI0_;
    const UBase_t reserved[31UL];
}PERIPHERAL_BITBANDING_EPI_t;

typedef volatile struct
{
    volatile UBase_t HIB_;
    const UBase_t reserved[31UL];
}PERIPHERAL_BITBANDING_HIB_t;

typedef volatile struct
{
    volatile UBase_t UART0_;
    volatile UBase_t UART1_;
    volatile UBase_t UART2_;
    volatile UBase_t UART3_;
    volatile UBase_t UART4_;
    volatile UBase_t UART5_;
    volatile UBase_t UART6_;
    volatile UBase_t UART7_;
    const UBase_t reserved[24UL];
}PERIPHERAL_BITBANDING_UART_t;

typedef volatile struct
{
    volatile UBase_t SSI0_;
    volatile UBase_t SSI1_;
    volatile UBase_t SSI2_;
    volatile UBase_t SSI3_;
    const UBase_t reserved[28UL];
}PERIPHERAL_BITBANDING_SSI_t;

typedef volatile struct
{
    volatile UBase_t I2C0_;
    volatile UBase_t I2C1_;
    volatile UBase_t I2C2_;
    volatile UBase_t I2C3_;
    volatile UBase_t I2C4_;
    volatile UBase_t I2C5_;
    volatile UBase_t I2C6_;
    volatile UBase_t I2C7_;
    volatile UBase_t I2C8_;
    volatile UBase_t I2C9_;
    const UBase_t reserved[22UL];
}PERIPHERAL_BITBANDING_I2C_t;

typedef volatile struct
{
    volatile UBase_t USB_;
    const UBase_t reserved[31UL];
}PERIPHERAL_BITBANDING_USB_t;

typedef volatile struct
{
    volatile UBase_t EPHY_;
    const UBase_t reserved[31UL];
}PERIPHERAL_BITBANDING_EPHY_t;

typedef volatile struct
{
    volatile UBase_t CAN0_;
    volatile UBase_t CAN1_;
    const UBase_t reserved[30UL];
}PERIPHERAL_BITBANDING_CAN_t;

typedef volatile struct
{
    volatile UBase_t ADC0_;
    volatile UBase_t ADC1_;
    const UBase_t reserved[30UL];
}PERIPHERAL_BITBANDING_ADC_t;

typedef volatile struct
{
    volatile UBase_t ACMP_;
    const UBase_t reserved[31UL];
}PERIPHERAL_BITBANDING_ACMP_t;

typedef volatile struct
{
    volatile UBase_t PWM0_;
    const UBase_t reserved[31UL];
}PERIPHERAL_BITBANDING_PWM_t;

typedef volatile struct
{
    volatile UBase_t QEI0_;
    const UBase_t reserved[31UL];
}PERIPHERAL_BITBANDING_QEI_t;

typedef volatile struct
{
    volatile UBase_t LPC_;
    const UBase_t reserved[31UL];
}PERIPHERAL_BITBANDING_LPC_t;

typedef volatile struct
{
    volatile UBase_t PECI_;
    const UBase_t reserved[31UL];
}PERIPHERAL_BITBANDING_PECI_t;

typedef volatile struct
{
    volatile UBase_t FAN_;
    const UBase_t reserved[31UL];
}PERIPHERAL_BITBANDING_FAN_t;

typedef volatile struct
{
    volatile UBase_t EEPROM_;
    const UBase_t reserved[31UL];
}PERIPHERAL_BITBANDING_EEPROM_t;

typedef volatile struct
{
    volatile UBase_t WTIMER0_;
    const UBase_t reserved[31UL];
}PERIPHERAL_BITBANDING_WTIMER_t;

typedef volatile struct
{
    volatile UBase_t RTS_;
    const UBase_t reserved[31UL];
}PERIPHERAL_BITBANDING_RTS_t;

typedef volatile struct
{
    volatile UBase_t CCM_;
    const UBase_t reserved[31UL];
}PERIPHERAL_BITBANDING_CCM_t;

typedef volatile struct
{
    volatile UBase_t LCD_;
    const UBase_t reserved[31UL];
}PERIPHERAL_BITBANDING_LCD_t;

typedef volatile struct
{
    volatile UBase_t OWIRE_;
    const UBase_t reserved[31UL];
}PERIPHERAL_BITBANDING_OWIRE_t;

typedef volatile struct
{
    volatile UBase_t EMAC_;
    const UBase_t reserved[31UL];
}PERIPHERAL_BITBANDING_EMAC_t;

typedef volatile struct
{
    volatile UBase_t PRB_;
    const UBase_t reserved[31UL];
}PERIPHERAL_BITBANDING_PRB_t;

typedef volatile struct
{
    volatile UBase_t HIM_;
    const UBase_t reserved[31UL];
}PERIPHERAL_BITBANDING_HIM_t;

typedef volatile struct
{
    volatile const UBase_t ID[32UL];
}UNIQUE_BITBANDING_ID_t;/*0x00000008*/

typedef volatile struct
{
    volatile UBase_t SHACFG;
    volatile UBase_t AESCFG;
    volatile UBase_t DESCFG;
    const UBase_t reserved[29UL];
}CCM_BITBANDING_CGREQ_t;

#endif /* XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_PERIPHERAL_SYSCTL_STRUCT_SYSCTL_STRUCTREGISTER_BITBANDING_H_ */
