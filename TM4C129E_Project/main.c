

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

void NMISW(void);


void NMISW(void)
{
    MCU__vNoOperation();
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
    SYSCTL__vEnRunModePeripheral(SYSCTL_enCAN0);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enCAN1);
    EEPROM__enInit();
    DMA__vInit();
    GPIO__vInit();
    TIMER__vInit();
    ADC__vInit();
    UART__vInit();
    SSI__vInit();
    PWM__vInit();

    EDUMKII_Button_vInit(EDUMKII_enBUTTON_ALL);
    EDUMKII_Accelerometer_vInit();
    EDUMKII_Microphone_vInit();
    EDUMKII_Joystick_vInit();
/*
    UART__vSetEnable(UART_enMODULE_0, UART_enENABLE_STOP);
    UART__enSetConfig(UART_enMODULE_0, UART_enMODE_NORMAL,
                      &enUart0Control, &enUart0LineControl, 921600UL, &enUart0Line );
    UART__vSetEnable(UART_enMODULE_0, UART_enENABLE_START);
*/

/*
    GraphTerm__vClearScreen(UART_enMODULE_0);
    GraphTerm__vHideCursor(UART_enMODULE_0);
    GraphTerm__vSetFontColor(UART_enMODULE_0, 0xFFUL, 0UL,0UL );
*/


    SYSCTL__vEnRunModePeripheral(SYSCTL_enPWM0);
    PWM_Generator__enSetPeriod_us(PWM_enMODULE_0, PWM_enGEN_0, 30000UL);
    volatile uint32_t u32Load = PWM_Generator__u32GetPeriod_us(PWM_enMODULE_0, PWM_enGEN_0);
    SHARP_96_96__vInitDisplay();

    YoystickQueueHandle = OS_Queue__pvCreate(1UL, 2UL * sizeof(uint32_t));
    AccelerometerQueueHandle = OS_Queue__pvCreate(1UL, 3UL * sizeof(uint32_t));
    ButtonQueueHandle = OS_Queue__pvCreate(1UL, 3UL * sizeof(char*));
    YoystickSemaphoreHandle = OS_Semaphore__pvCreateBinary();
    UartSemaphoreHandle = OS_Semaphore__pvCreateMutex();

    OS_Task_Handle_t TaskHandeler[7UL] = {0UL};
   /* OS_Task__uxCreate(&xTask1_AccelerometerLog, "Task 1", 300UL,
                                  (void*) 160UL, 4UL, &TaskHandeler[0UL]);
    OS_Task__uxCreate(&xTask2_JoystickLog, "Task 2", 300UL,
                                  (void*) 30UL, 2UL, &TaskHandeler[1UL]);
    OS_Task__uxCreate(&xTask3_ButtonsLog, "Task 3", 300UL,
                                  (void*) 75UL, 5UL, &TaskHandeler[2UL]);
    OS_Task__uxCreate(&xTask4_LedBlueLog, "Task 4", 300UL,
                                  (void*) 0UL, 3UL, &TaskHandeler[3UL]);
    OS_Task__uxCreate(&xTask5_LedGreenLog, "Task 5", 300UL,
                                  (void*) 100UL, 3UL, &TaskHandeler[4UL]);*/
    OS_Task__uxCreate(&xTask6_Commands, "Task 6", 900UL,
                                  (void*) 10UL, 2UL, &TaskHandeler[5UL]);
    /*
    OS_Task__uxCreate(&xTask7_ControllerCar , "Task 7", 900UL,
                                  (void*) 30UL, 3UL, &TaskHandeler[6UL]);
*/
    OS_Task__vStartScheduler(1000UL);
    while(1UL)
    {

    }
}


