/*******************************************************************************/
/**/
/* Startup code for use with TI's Code Composer Studio.*/
/**/
/* Copyright (c) 2011-2014 Texas Instruments Incorporated.  All rights reserved.*/
/* Software License Agreement*/
/* */
/* Software License Agreement*/
/**/
/* Texas Instruments (TI) is supplying this software for use solely and*/
/* exclusively on TI's microcontroller products. The software is owned by*/
/* TI and/or its suppliers, and is protected under applicable copyright*/
/* laws. You may not combine this software with "viral" open-source*/
/* software in order to form a larger program.*/
/**/
/* THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.*/
/* NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT*/
/* NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR*/
/* A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY*/
/* CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL*/
/* DAMAGES, FOR ANY REASON WHATSOEVER.*/
/**/
/*******************************************************************************/

#include <xUtils/Standard/Standard.h>
#include <xApplication_MCU/Core/SCB/SCB.h>
#include <xApplication_MCU/SYSEXC/SYSEXC.h>
#include <xApplication_MCU/SYSCTL/SYSCTL.h>
#include <xApplication_MCU/UART/UART.h>
#include <xDriver_MCU/Core/FPU/FPU.h>
#include <xDriver_MCU/Core/NVIC/NVIC.h>
#include <xApplication_MCU/FLASH/FLASH.h>

static const UART_CONTROL_t UART_stReportControl =
{
    UART_enEOT_ALL,
    UART_enSTATE_DIS,
    UART_enSTATE_ENA,
    UART_enSTATE_ENA,
    UART_enSTATE_ENA,
    UART_enLINE_MODE_SOFT,
    UART_enLINE_MODE_SOFT,
    UART_enSTATE_DIS,
    UART_enSTATE_DIS,
    UART_enSTATE_DIS,
    UART_enSTATE_DIS,
    UART_enLEVEL_LOW,
    UART_enLEVEL_LOW,
    UART_enLEVEL_LOW,
};

static const UART_LINE_CONTROL_t UART_stReportLineControl =
{
    UART_enSTATE_ENA,
    UART_enSTOP_ONE,
    UART_enPARITY_NONE,
    UART_enLENGTH_8BITS,
    UART_enFIFO_LEVEL_13_16,
    UART_enFIFO_LEVEL_13_16,
};

static const UART_LINE_t UART_stReportLine =
{
    UART_enLINE_SELECT_PRIMARY,
    UART_enLINE_SELECT_PRIMARY,
    UART_enLINE_SELECT_PRIMARY,
    UART_enLINE_SELECT_PRIMARY,
    UART_enLINE_SELECT_PRIMARY,
    UART_enLINE_SELECT_PRIMARY,
    UART_enLINE_SELECT_PRIMARY,
    UART_enLINE_SELECT_PRIMARY,
};

/*******************************************************************************/
/**/
/* Forward declaration of the default fault handlers.*/
/**/
/*******************************************************************************/
void ResetISR(void);
static void IntDefaultHandler(void);
extern void SYSTICKHandler(void);

/*******************************************************************************/
/**/
/* The entry point for the application.*/
/**/
/*******************************************************************************/
extern int main(void);

#if defined (__TI_ARM__ ) || defined (__MSP430__ )
extern void _c_int00(void);
#define STARTUP_VECTOR_SECTION
#pragma DATA_SECTION(g_pfnVectors, ".intvecs")
#elif defined (__GNUC__ )
#define STARTUP_VECTOR_SECTION __attribute__ ((section(".intvecs")))
#else
#define STARTUP_VECTOR_SECTION
#endif

extern UBase_t __stack;
extern UBase_t __stack_end__;
extern UBase_t __stack_size__;

/*******************************************************************************/
/**/
/* Linker variable that marks the top of the stack.*/
/**/
/*******************************************************************************/

STARTUP_VECTOR_SECTION
void (* const g_pfnVectors[130UL])(void) =
{
    (void (*)(void))(&__stack_end__),        /* The initial stack pointer*/
    &ResetISR,                               /* The reset handler*/
    &IntDefaultHandler,                      /* The NMI handler*/
    &IntDefaultHandler,                      /* The hard fault handler*/
    &IntDefaultHandler,                      /* The MPU fault handler*/
    &IntDefaultHandler,                      /* The bus fault handler*/
    &IntDefaultHandler,                      /* The usage fault handler*/
    0,                                       /* Reserved*/
    0,                                       /* Reserved*/
    0,                                       /* Reserved*/
    0,                                       /* Reserved*/
    &IntDefaultHandler,                      /* SVCall handler*/
    &IntDefaultHandler,                      /* Debug monitor handler*/
    0,                                       /* Reserved*/
    &IntDefaultHandler,                      /* The PendSV handler*/
    &IntDefaultHandler,                         /* The SYSTICK handler*/
    &IntDefaultHandler,                      /* GPIO Port A*/
    &IntDefaultHandler,                      /* GPIO Port B*/
    &IntDefaultHandler,                      /* GPIO Port C*/
    &IntDefaultHandler,                      /* GPIO Port D*/
    &IntDefaultHandler,                      /* GPIO Port E*/
    &IntDefaultHandler,                      /* UART0 Rx and Tx*/
    &IntDefaultHandler,                      /* UART1 Rx and Tx*/
    &IntDefaultHandler,                      /* SSI0 Rx and Tx*/
    &IntDefaultHandler,                      /* I2C0 Master and Slave*/
    &IntDefaultHandler,                      /* PWM Fault*/
    &IntDefaultHandler,                      /* PWM Generator 0*/
    &IntDefaultHandler,                      /* PWM Generator 1*/
    &IntDefaultHandler,                      /* PWM Generator 2*/
    &IntDefaultHandler,                      /* Quadrature Encoder 0*/
    &IntDefaultHandler,                      /* ADC Sequence 0*/
    &IntDefaultHandler,                      /* ADC Sequence 1*/
    &IntDefaultHandler,                      /* ADC Sequence 2*/
    &IntDefaultHandler,                      /* ADC Sequence 3*/
    &IntDefaultHandler,                      /* Watchdog timer*/
    &IntDefaultHandler,                      /* Timer 0 subtimer A*/
    &IntDefaultHandler,                      /* Timer 0 subtimer B*/
    &IntDefaultHandler,                      /* Timer 1 subtimer A*/
    &IntDefaultHandler,                      /* Timer 1 subtimer B*/
    &IntDefaultHandler,                      /* Timer 2 subtimer A*/
    &IntDefaultHandler,                      /* Timer 2 subtimer B*/
    &IntDefaultHandler,                      /* Analog Comparator 0*/
    &IntDefaultHandler,                      /* Analog Comparator 1*/
    &IntDefaultHandler,                      /* Analog Comparator 2*/
    &IntDefaultHandler,                      /* System Control (PLL, OSC, BO)*/
    &IntDefaultHandler,                      /* FLASH Control*/
    &IntDefaultHandler,                      /* GPIO Port F*/
    &IntDefaultHandler,                      /* GPIO Port G*/
    &IntDefaultHandler,                      /* GPIO Port H*/
    &IntDefaultHandler,                      /* UART2 Rx and Tx*/
    &IntDefaultHandler,                      /* SSI1 Rx and Tx*/
    &IntDefaultHandler,                      /* Timer 3 subtimer A*/
    &IntDefaultHandler,                      /* Timer 3 subtimer B*/
    &IntDefaultHandler,                      /* I2C1 Master and Slave*/
    &IntDefaultHandler,                      /* CAN0*/
    &IntDefaultHandler,                      /* CAN1*/
    &IntDefaultHandler,                      /* Ethernet*/
    &IntDefaultHandler,                      /* Hibernate*/
    &IntDefaultHandler,                      /* USB0*/
    &IntDefaultHandler,                      /* PWM Generator 3*/
    &IntDefaultHandler,                      /* uDMA Software Transfer*/
    &IntDefaultHandler,                      /* uDMA Error*/
    &IntDefaultHandler,                      /* ADC1 Sequence 0*/
    &IntDefaultHandler,                      /* ADC1 Sequence 1*/
    &IntDefaultHandler,                      /* ADC1 Sequence 2*/
    &IntDefaultHandler,                      /* ADC1 Sequence 3*/
    &IntDefaultHandler,                      /* External Bus Interface 0*/
    &IntDefaultHandler,                      /* GPIO Port J*/
    &IntDefaultHandler,                      /* GPIO Port K*/
    &IntDefaultHandler,                      /* GPIO Port L*/
    &IntDefaultHandler,                      /* SSI2 Rx and Tx*/
    &IntDefaultHandler,                      /* SSI3 Rx and Tx*/
    &IntDefaultHandler,                      /* UART3 Rx and Tx*/
    &IntDefaultHandler,                      /* UART4 Rx and Tx*/
    &IntDefaultHandler,                      /* UART5 Rx and Tx*/
    &IntDefaultHandler,                      /* UART6 Rx and Tx*/
    &IntDefaultHandler,                      /* UART7 Rx and Tx*/
    &IntDefaultHandler,                      /* I2C2 Master and Slave*/
    &IntDefaultHandler,                      /* I2C3 Master and Slave*/
    &IntDefaultHandler,                      /* Timer 4 subtimer A*/
    &IntDefaultHandler,                      /* Timer 4 subtimer B*/
    &IntDefaultHandler,                      /* Timer 5 subtimer A*/
    &IntDefaultHandler,                      /* Timer 5 subtimer B*/
    &IntDefaultHandler,                      /* FPU (SYSEXC)*/
    0,                                       /* Reserved*/
    0,                                       /* Reserved*/
    &IntDefaultHandler,                      /* I2C4 Master and Slave*/
    &IntDefaultHandler,                      /* I2C5 Master and Slave*/
    &IntDefaultHandler,                      /* GPIO Port M*/
    &IntDefaultHandler,                      /* GPIO Port N*/
    0,                                       /* Reserved*/
    &IntDefaultHandler,                      /* Tamper*/
    &IntDefaultHandler,                      /* GPIO Port P (Summary or P0)*/
    &IntDefaultHandler,                      /* GPIO Port P1*/
    &IntDefaultHandler,                      /* GPIO Port P2*/
    &IntDefaultHandler,                      /* GPIO Port P3*/
    &IntDefaultHandler,                      /* GPIO Port P4*/
    &IntDefaultHandler,                      /* GPIO Port P5*/
    &IntDefaultHandler,                      /* GPIO Port P6*/
    &IntDefaultHandler,                      /* GPIO Port P7*/
    &IntDefaultHandler,                      /* GPIO Port Q (Summary or Q0)*/
    &IntDefaultHandler,                      /* GPIO Port Q1*/
    &IntDefaultHandler,                      /* GPIO Port Q2*/
    &IntDefaultHandler,                      /* GPIO Port Q3*/
    &IntDefaultHandler,                      /* GPIO Port Q4*/
    &IntDefaultHandler,                      /* GPIO Port Q5*/
    &IntDefaultHandler,                      /* GPIO Port Q6*/
    &IntDefaultHandler,                      /* GPIO Port Q7*/
    &IntDefaultHandler,                      /* GPIO Port R*/
    &IntDefaultHandler,                      /* GPIO Port S*/
    &IntDefaultHandler,                      /* SHA/MD5 0*/
    &IntDefaultHandler,                      /* AES 0*/
    &IntDefaultHandler,                      /* DES3DES 0*/
    &IntDefaultHandler,                      /* LCD Controller 0*/
    &IntDefaultHandler,                      /* Timer 6 subtimer A*/
    &IntDefaultHandler,                      /* Timer 6 subtimer B*/
    &IntDefaultHandler,                      /* Timer 7 subtimer A*/
    &IntDefaultHandler,                      /* Timer 7 subtimer B*/
    &IntDefaultHandler,                      /* I2C6 Master and Slave*/
    &IntDefaultHandler,                      /* I2C7 Master and Slave*/
    &IntDefaultHandler,                      /* HIM Scan Matrix Keyboard 0*/
    &IntDefaultHandler,                      /* One Wire 0*/
    &IntDefaultHandler,                      /* HIM PS/2 0*/
    &IntDefaultHandler,                      /* HIM LED Sequencer 0*/
    &IntDefaultHandler,                      /* HIM Consumer IR 0*/
    &IntDefaultHandler,                      /* I2C8 Master and Slave*/
    &IntDefaultHandler,                      /* I2C9 Master and Slave*/
    &IntDefaultHandler,                      /* GPIO Port T*/
    &IntDefaultHandler,                      /* Fan 1*/
    0,                                       /* Reserved*/
};

/*******************************************************************************/
/**/
/* The following are constructs created by the linker, indicating where the*/
/* the "data" and "bss" segments reside in memory.  The initializers for the*/
/* for the "data" segment resides immediately following the "text" segment.*/
/**/
/*******************************************************************************/
extern UBase_t __ramcode_load__;
extern UBase_t __ramcode_start__;
extern UBase_t __ramcode_end__;

extern UBase_t __data_load__;
extern UBase_t __data_start__;
extern UBase_t __data_end__;

extern UBase_t __bss_start__;
extern UBase_t __bss_end__;

/*******************************************************************************/
/**/
/* This is the code that gets called when the processor first starts execution*/
/* following a reset event.  Only the absolutely necessary set is performed,*/
/* after which the application supplied entry() routine is called.  Any fancy*/
/* actions (such as making decisions based on the reset cause register, and*/
/* resetting the bits in that register) are left solely in the hands of the*/
/* application.*/
/**/
/*******************************************************************************/
void
ResetISR(void)
{
    UBase_t *pui32SrcRamCode = (UBase_t*) 0UL;
    UBase_t *pui32DestRamCode = (UBase_t*) 0UL;
    UBase_t *pui32SrcData = (UBase_t*) 0UL;
    UBase_t *pui32DestData = (UBase_t*) 0UL;
    UBase_t *pui32DestBss = (UBase_t*) 0UL;


    {__asm volatile(" cpsid i");}
    /**/
    /* Copy the ramcode segment initializers from flash to SRAM.*/
    /**/
    pui32SrcRamCode = &__ramcode_load__;
    pui32DestRamCode = &__ramcode_start__;
    while(pui32DestRamCode <= &__ramcode_end__)
    {
        *pui32DestRamCode = *pui32SrcRamCode;
        pui32SrcRamCode += 1UL;
        pui32DestRamCode += 1UL;
    }

    /**/
    /* Copy the ramcode segment initializers from flash to SRAM.*/
    /**/
    pui32SrcData = (UBase_t*) &__data_load__;
    pui32DestData = (UBase_t*) &__data_start__;
    while(pui32DestData <= &__data_end__)
    {
        *pui32DestData = *pui32SrcData;
        pui32SrcData += 1UL;
        pui32DestData += 1UL;
    }


    /**/
    /* Copy the ramcode segment initializers from flash to SRAM.*/
    /**/
    pui32DestBss = (UBase_t*) &__bss_start__;
    while(pui32DestBss <= &__bss_end__)
    {
        *pui32DestBss = 0UL;
        pui32DestBss += 1UL;
    }
    /**/
    /* Enable the float32_ting-point unit.  This must be done here to handle the*/
    /* case where main() uses float32_ting-point and the function prologue saves*/
    /* float32_ting-point registers (which will fault if float32_ting-point is not*/
    /* enabled).  Any configuration of the float32_ting-point unit using DriverLib*/
    /* APIs must be done here prior to the float32_ting-point unit being enabled.*/

    FPU__enInit(FPU_enMODULE_0);
    NVIC__enDisableAllInterrupts(NVIC_enMODULE_0);
    SCB__enInit(SCB_enMODULE_0);
    FLASH__enInit(FLASH_enMODULE_0);
    FLASH__enSetPrefetchMode(FLASH_enMODULE_0, FLASH_enPREFETCH_MODE_DUAL);
    FLASH__enEnablePrefetch(FLASH_enMODULE_0);
    SYSCTL__enEnableRunMode(SYSCTL_enMODULE_0, SYSCTL_enGPIOC);
    UART__enInit(UART_enMODULE_7);
    UART__enSetConfig(UART_enMODULE_7, UART_enMODE_NORMAL, 115200UL, 0UL, 0UL,
                      &UART_stReportControl, &UART_stReportLineControl, &UART_stReportLine, 0UL);
    SYSEXC__enRegisterReportHandler( (void*) (uintptr_t) UART_enMODULE_7, &UART__enSysExcReportCallback);
    /**/
    /* Call the application's entry point.*/
    /**/


    {__asm volatile(" cpsid i");}

    main();
}


static void
IntDefaultHandler(void)
{
    /**/
    /* Go into an infinite loop.*/
    /**/
    while(1U)
    {
    }
}
