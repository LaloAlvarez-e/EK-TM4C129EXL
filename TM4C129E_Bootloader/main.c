/**
 * main.c
 */
#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/Core/Core.h> /*Chapter 3*/

#include <xDriver_MCU/SYSCTL/SYSCTL.h>
#include <xDriver_MCU/GPIO/GPIO.h>
#include <xDriver_MCU/UART/UART.h>
#include <xDriver_MCU/TIMER/TIMER.h>

#include <xApplication_MCU/SYSCTL/SYSCTL.h>
#include <xApplication_MCU/GPIO/GPIO.h>
#include <xApplication_MCU/UART/UART.h>
#include <xApplication_MCU/TIMER/TIMER.h>

#include <xDriver_MCU/Core/SYSTICK/Peripheral/SYSTICK_Peripheral.h>

uint32_t main(void);
void MAIN__vGotoAppl(void);
void Led2ON(void);

void Led2ON(void)
{
    static uint32_t u32PinValue = (uint32_t) GPIO_enPIN_0;
    GPIO__vSetData(GPIO_enPORT_F, GPIO_enPIN_0, u32PinValue);
    u32PinValue ^= (uint32_t) GPIO_enPIN_0;

}


uint32_t main(void)
{
    volatile TIMER_nEVENT enEvent = TIMER_enEVENT_ALL;
    SYSCTL_CONFIG_t stClockConfig =
    {
        SYSCTL_enXTAL_25MHZ,
        SYSCTL_enOSC_MOSC,
        SYSCTL_enPLL,
        SYSCTL_enVCO_480MHZ,
    };
    UART_CONTROL_t enUart0Control =
    {
        UART_enEOT_ALL,
        UART_enLOOPBACK_DIS,
        UART_enLINE_ENA,
        UART_enLINE_ENA,
        UART_enRTS_MODE_SOFT,
        UART_enCTS_MODE_SOFT,
        UART_enLINE_DIS,
        UART_enLINE_DIS,
        UART_enLINE_DIS,
        UART_enLINE_DIS,
    };

    UART_LINE_CONTROL_t enUart0LineControl =
    {
     UART_enFIFO_ENA,
     UART_enSTOP_ONE,
     UART_enPARITY_DIS,
     UART_enPARITY_TYPE_EVEN,
     UART_enPARITY_STICK_DIS ,
     UART_enLENGTH_8BITS,
    };

    UART_LINE_t enUart0Line =
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
    SYSCTL__enSetSystemClock(120000000UL, stClockConfig);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enGPIOA);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enGPIOB);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enGPIOC);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enGPIOD);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enGPIOE);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enGPIOF);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enGPIOG);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enGPIOH);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enTIMER0);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enUART0);

    GPIO__vInit();
    TIMER__enInit();
    UART__vInit();

    GPIO__enSetDigitalConfig(GPIO_enGPIOF2, GPIO_enCONFIG_OUTPUT_2MA_PUSHPULL);
    GPIO__vSetData(GPIO_enPORT_F, GPIO_enPIN_2, 0UL);
    GPIO__enSetDigitalConfig(GPIO_enGPIOF0, GPIO_enCONFIG_OUTPUT_2MA_PUSHPULL);
    GPIO__vSetData(GPIO_enPORT_F, GPIO_enPIN_0, 0UL);

    UART__vSetEnable(UART_enMODULE_0, UART_enENABLE_STOP);
    UART__enSetConfig(UART_enMODULE_0, UART_enMODE_NORMAL,
                      &enUart0Control, &enUart0LineControl, 921600UL, &enUart0Line );
    UART__vSetEnable(UART_enMODULE_0, UART_enENABLE_START);

    TIMER__vRegisterIRQSourceHandler(&Led2ON, TIMER_enT0W, TIMER_enINTERRUPT_TIMEOUT);
    TIMER__vSetClockSource(TIMER_enT0W, TIMER_enCLOCK_SYSCLK);
    TIMER__enEnableInterruptVector(TIMER_enT0W, (TIMER_nPRIORITY) NVIC_enPriority_TIMER0A);
    TIMER__vEnInterruptSource(TIMER_enT0W, TIMER_enINT_TIMEOUT);
    TIMER__vSetStall(TIMER_enT0W, TIMER_enSTALL_FREEZE);
    TIMER__enSetMode_ReloadMatch(TIMER_enT0W, TIMER_enMODE_PERIODIC_WIDE_DOWN,
                                 30000000UL - 1UL, 0UL);
    TIMER__vSetEnable(TIMER_enT0W, TIMER_enENABLE_START);

    while(1UL)
    {
        MAIN__vGotoAppl();

    }
}


void MAIN__vGotoAppl(void)
{
    void (*pvfAppResetHandler) (void) = (void (*) (void)) 0UL;
    uint32_t u32ResetHandlerAddress = 0UL;
    uint32_t u32MSPStackValue = 0UL;
    UART__u32Printf(UART_enMODULE_0, "BL_DEBUG_MSG:bootloader_jimp_to_user_app\n\r");

    /*add a symbol for end of flash*/
    u32MSPStackValue = *((volatile uint32_t*) 0x00010000UL);
    UART__u32Printf(UART_enMODULE_0, "BL_DEBUG_MSG:MSP value: %#x\n\r", u32MSPStackValue);
    MCU__vSetMSPValue(u32MSPStackValue);

    SCB__vSetVectorOffset(0x00010000UL);
    u32ResetHandlerAddress = *((volatile uint32_t*) (0x00010000UL + 4UL));
    pvfAppResetHandler = (void (*) (void)) u32ResetHandlerAddress;
    UART__u32Printf(UART_enMODULE_0, "BL_DEBUG_MSG:App reset handler addr: %#x\n\r", u32ResetHandlerAddress);

    pvfAppResetHandler();
}

