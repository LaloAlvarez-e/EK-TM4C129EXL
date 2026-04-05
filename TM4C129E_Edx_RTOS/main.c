

/**
 * main.c
 */
#include <xTask/xTask.h>

#include <xApplication/EDUMKII/EDUMKII.h>
#include <xApplication/SHARP96_96/SHARP96_96.h>

#include <xDriver_MCU/xDriver_MCU.h>
#include <xApplication_MCU/xApplication_MCU.h>
#include <xOS/xOS.h>

#include <xDriver_MCU/Core/SYSTICK/Peripheral/SYSTICK_Peripheral.h>

uint32_t main(void);

void Led2ON(void);
void NMISW(void);


void NMISW(void)
{
    MCU__vNoOperation();
}

void Led2ON(void)
{
    static uint32_t u32PinValue = (uint32_t) GPIO_enPIN_0;
    GPIO__vSetData(GPIO_enPORT_F, GPIO_enPIN_0, u32PinValue);
    u32PinValue ^= (uint32_t) GPIO_enPIN_0;

}


uint32_t main(void)

{
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
    SYSCTL__vEnRunModePeripheral(SYSCTL_enGPIOF);
    GPIO__enSetDigitalConfig(GPIO_enGPIOF2, GPIO_enCONFIG_OUTPUT_2MA_PUSHPULL);
    GPIO__vSetData(GPIO_enPORT_F, GPIO_enPIN_2, 0UL);
    GPIO__enSetDigitalConfig(GPIO_enGPIOF0, GPIO_enCONFIG_OUTPUT_2MA_PUSHPULL);
    GPIO__vSetData(GPIO_enPORT_F, GPIO_enPIN_0, 0UL);

    SYSCTL__enSetSystemClock(120000000UL, stClockConfig);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enEEPROM);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enUDMA);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enGPIOA);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enGPIOB);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enGPIOC);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enGPIOD);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enGPIOE);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enGPIOG);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enGPIOH);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enGPIOJ);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enGPIOK);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enGPIOL);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enGPIOM);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enGPION);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enGPIOP);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enGPIOQ);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enTIMER0);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enTIMER1);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enUART0);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enUART2);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enADC0);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enADC1);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enSSI2);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enSSI3);
    EEPROM__enInit();
    DMA__vInit();
    GPIO__vInit();
    TIMER__enInit();
    ADC__vInit();
    UART__vInit();
    SSI__vInit();

    EDUMKII_Button_vInit(EDUMKII_enBUTTON_ALL);
    EDUMKII_Accelerometer_vInit();
    EDUMKII_Microphone_vInit();
    EDUMKII_Joystick_vInit();

    UART__vSetEnable(UART_enMODULE_0, UART_enENABLE_STOP);
    UART__enSetConfig(UART_enMODULE_0, UART_enMODE_NORMAL,
                      &enUart0Control, &enUart0LineControl, 921600UL, &enUart0Line );
    UART__vSetEnable(UART_enMODULE_0, UART_enENABLE_START);

    GraphTerm__vClearScreen(UART_enMODULE_0);
    GraphTerm__vHideCursor(UART_enMODULE_0);
    GraphTerm__vSetFontColor(UART_enMODULE_0, 0xFFUL, 0UL,0UL );

    SHARP_96_96__vInitDisplay();

    TIMER__vRegisterIRQSourceHandler(&Led2ON, TIMER_enT0W, TIMER_enINTERRUPT_TIMEOUT);
    TIMER__vSetClockSource(TIMER_enT0W, TIMER_enCLOCK_SYSCLK);
    TIMER__enEnableInterruptVector(TIMER_enT0W, (TIMER_nPRIORITY) NVIC_enPriority_TIMER0A);
    TIMER__vEnInterruptSource(TIMER_enT0W, TIMER_enINT_TIMEOUT);
    TIMER__vSetStall(TIMER_enT0W, TIMER_enSTALL_FREEZE);
    TIMER__enSetMode_ReloadMatch(TIMER_enT0W, TIMER_enMODE_PERIODIC_WIDE_DOWN,
                                 30000000UL - 1UL, 0UL);
    TIMER__vSetEnable(TIMER_enT0W, TIMER_enENABLE_START);

    OS_Task_Handle_t TaskHandeler[5UL] = {0UL};
    OS_Task__uxGenericCreate(&xTask1_AccelerometerLog, "Task 1", 300UL,
                                  (void*) 0UL, 4UL, &TaskHandeler[0UL],(uint32_t*) 0UL);
    OS_Task__uxGenericCreate(&xTask2_JoystickLog, "Task 2", 300UL,
                                  (void*) 0UL, 2UL, &TaskHandeler[1UL],(uint32_t*) 0UL);
    OS_Task__uxGenericCreate(&xTask3_ButtonsLog, "Task 3", 300UL,
                                  (void*) 0UL, 5UL, &TaskHandeler[2UL],(uint32_t*) 0UL);
    OS_Task__uxGenericCreate(&xTask4_LedBlueLog, "Task 4", 300UL,
                                  (void*) 0UL, 3UL, &TaskHandeler[3UL],(uint32_t*) 0UL);
    OS_Task__uxGenericCreate(&xTask5_LedGreenLog, "Task 5", 300UL,
                                  (void*) 0UL, 3UL, &TaskHandeler[4UL],(uint32_t*) 0UL);
    OS_Task__uxGenericCreate(&xTask6_Commands, "Task 6", 900UL,
                                  (void*) 0UL, 2UL, &TaskHandeler[5UL],(uint32_t*) 0UL);

    OS_Task__vStartScheduler(1000UL);
    while(1UL)
    {

    }
}


