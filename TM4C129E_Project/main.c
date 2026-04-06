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

int main(void);
static void MAIN__vSetTransferSizeLeft(UBase_t uxSizeArg);
static void MAIN__vSetPrimaryTransferStruct(DMA_CH_CTL_t* pstTransfer);
static DMA_CH_CTL_t* MAIN__pstGetPrimaryTransferStruct(void);
static void MAIN__vSetAlternateTransferStruct(DMA_CH_CTL_t* pstTransfer);
static DMA_CH_CTL_t* MAIN__pstGetAlternateTransferStruct(void);
static UART_nERROR MAIN__enInitUartDMAConfig(void);
static UART_nERROR MAIN__enCustomWriteBuffer(UART_nMODULE enModuleArg, const uint8_t* pu8DataArg, UBase_t* puxBufferCant);
static UART_nERROR MAIN__enWriteBufferDMA(UART_nMODULE enModuleArg, const uint8_t* pu8DataArg, UBase_t* puxBufferCant);
static void MAIN__vDMATxInterupt(uintptr_t uptrModuleArg, void* pvArgument);
static void MAIN__vDMATxLastBit(uintptr_t uptrModuleArg, void* pvArgument);

int main(void)
{
    SYSCTL_CONFIG_t stClockConfig =
    {
        SYSCTL_enXTAL_25MHZ,
        SYSCTL_enOSCCLK_SRC_MOSC,
        SYSCTL_enSYSCLK_SRC_PLLCLK,
        SYSCTL_enVCO_480MHZ,
    };
    UART_CONTROL_t enUart0Control =
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

    UART_LINE_CONTROL_t enUart0LineControl =
    {
     UART_enSTATE_ENA,
     UART_enSTOP_ONE,
     UART_enPARITY_NONE,
     UART_enLENGTH_8BITS,
     UART_enFIFO_LEVEL_13_16,
     UART_enFIFO_LEVEL_13_16,
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
    SYSCTL__enEnableRunMode(SYSCTL_enMODULE_0, SYSCTL_enGPIOF);
    GPIO__enSetDigitalConfig(GPIO_enGPIOF2, GPIO_enCONFIG_OUTPUT_2MA_PUSHPULL);
    GPIO__enSetDataByNumber(GPIO_enPORT_F, GPIO_enPIN_2, GPIO_enLEVEL_LOW);
    GPIO__enSetDigitalConfig(GPIO_enGPIOF0, GPIO_enCONFIG_OUTPUT_2MA_PUSHPULL);
    GPIO__enSetDataByNumber(GPIO_enPORT_F, GPIO_enPIN_0, GPIO_enLEVEL_LOW);

    SYSCTL__enSetSystemClock(SYSCTL_enMODULE_0, 120000000UL, &stClockConfig, 0UL);
    SYSCTL__enEnableRunMode(SYSCTL_enMODULE_0, SYSCTL_enGPIOA);
    SYSCTL__enEnableRunMode(SYSCTL_enMODULE_0, SYSCTL_enGPIOB);
    SYSCTL__enEnableRunMode(SYSCTL_enMODULE_0, SYSCTL_enGPIOC);
    SYSCTL__enEnableRunMode(SYSCTL_enMODULE_0, SYSCTL_enGPIOD);
    SYSCTL__enEnableRunMode(SYSCTL_enMODULE_0, SYSCTL_enGPIOE);
    SYSCTL__enEnableRunMode(SYSCTL_enMODULE_0, SYSCTL_enGPIOG);
    SYSCTL__enEnableRunMode(SYSCTL_enMODULE_0, SYSCTL_enGPIOH);
    SYSCTL__enEnableRunMode(SYSCTL_enMODULE_0, SYSCTL_enGPIOJ);
    SYSCTL__enEnableRunMode(SYSCTL_enMODULE_0, SYSCTL_enGPIOK);
    SYSCTL__enEnableRunMode(SYSCTL_enMODULE_0, SYSCTL_enGPIOL);
    SYSCTL__enEnableRunMode(SYSCTL_enMODULE_0, SYSCTL_enGPIOM);
    SYSCTL__enEnableRunMode(SYSCTL_enMODULE_0, SYSCTL_enGPION);
    SYSCTL__enEnableRunMode(SYSCTL_enMODULE_0, SYSCTL_enGPIOP);
    SYSCTL__enEnableRunMode(SYSCTL_enMODULE_0, SYSCTL_enGPIOQ);
    SYSCTL__enEnableRunMode(SYSCTL_enMODULE_0, SYSCTL_enTIMER0);
    SYSCTL__enEnableRunMode(SYSCTL_enMODULE_0, SYSCTL_enTIMER1);
    EEPROM__enInit(EEPROM_enMODULE_0);
    DMA__enInit(DMA_enMODULE_0);
    GPIO__enInit();
    TIMER__enInit();
    ADC__enInit(ADC_enMODULE_0);
    ADC__enInit(ADC_enMODULE_1);
    UART__enInit(UART_enMODULE_0);
    SSI__enInit(SSI_enMODULE_0);
    SSI__enInit(SSI_enMODULE_2);
    SSI__enInit(SSI_enMODULE_3);
    PWM__enInit(PWM_enMODULE_0);

    FLASH_DMASZ_R = 512UL;
    FLASH_DMAST_R = 0UL;

    EDUMKII_Button_vInit(EDUMKII_enBUTTON_ALL);
    EDUMKII_Accelerometer_vInit();
    EDUMKII_Microphone_vInit();
    EDUMKII_Joystick_vInit();

    UART__enEnableInterruptVectorWithPriority(UART_enMODULE_0, (UART_nPRIORITY) NVIC_enVECTOR_PRI_UART0);
    UART__enSetCustomPrintfHandle(UART_enMODULE_0, &MAIN__enCustomWriteBuffer);
    MAIN__enInitUartDMAConfig();
    UART__enSetConfig(UART_enMODULE_0, UART_enMODE_NORMAL, 4000000UL, 0UL, 0UL,
                      &enUart0Control, &enUart0LineControl, &enUart0Line, 0UL);

    SYSCTL__enEnableRunMode(SYSCTL_enMODULE_0, SYSCTL_enPWM0);
    PWM_Generator__enSetPeriod_us(PWM_enMODULE_0, PWM_enGEN_0, 30000UL);
    SHARP_96_96__vInitDisplay();

    YoystickQueueHandle = OS_Queue__pvCreate(1UL, 2UL * sizeof(UBase_t));
    AccelerometerQueueHandle = OS_Queue__pvCreate(1UL, 3UL * sizeof(UBase_t));
    ButtonQueueHandle = OS_Queue__pvCreate(1UL, 3UL * sizeof(char*));
    TFTQueueSetHandle = OS_Queue__pvCreateSet(3UL);
    OS_Queue__boAddToSet(YoystickQueueHandle, TFTQueueSetHandle);
    OS_Queue__boAddToSet(AccelerometerQueueHandle, TFTQueueSetHandle);
    OS_Queue__boAddToSet(ButtonQueueHandle, TFTQueueSetHandle);
    MainSemaphoreHandle = OS_Semaphore__pvCreateBinary();
    DebugDataSemaphoreHandle = OS_Semaphore__pvCreateCounting(255UL, 0UL);
    TFTSemaphoreHandle = OS_Semaphore__pvCreateBinary();
    UARTSemaphoreHandle = OS_Semaphore__pvCreateBinary();
    DMASemaphoreHandle = OS_Semaphore__pvCreateBinary();
    ST7735SemaphoreHandle = OS_Semaphore__pvCreateBinary();


    OS_Semaphore__boGive(UARTSemaphoreHandle);
    OS_Task_Handle_t TaskHandeler[7UL] = {0UL};
    OS_Task__uxCreate(&xTask8_Debug, "UART Task", 900UL, (void*) 200UL, 4UL, &TaskHandeler[3UL]);
    OS_Task__uxCreate(&xTask3_ButtonsLog, "Button Task", 400UL, (void*) 60UL, 3UL, &TaskHandeler[1UL]);
    OS_Task__uxCreate(&xTask1_AccelerometerLog, "Accelerometer Task", 400UL, (void*) 60UL, 3UL, &TaskHandeler[0UL]);
    OS_Task__uxCreate(&xTask2_JoystickLog, "Joystick Task", 400UL, (void*) 60UL, 3UL, &TaskHandeler[2UL]);
    OS_Task__uxCreate(&xTask9_TFT, "TFT Task", 900UL, (void*) 30UL, 2UL, &TaskHandeler[4UL]);

    OS_Task__vStartScheduler(1000UL);
    return (0UL);
}


static UBase_t MAIN_uxDMATransferSizeLeft = 0UL;
static UBase_t MAIN_uxDMATransferAddress = 0UL;
static DMA_CH_CTL_t* MAIN_pstDMAPrimaryTransferStruct = (DMA_CH_CTL_t*) 0UL;
static DMA_CH_CTL_t* MAIN_pstDMAAlternateTransferStruct = (DMA_CH_CTL_t*) 0UL;


static DMA_CH_CTL_t stDMAChControlUARTPrimaryBuffer = {
    DMA_enCH_MODE_STOP,
    DMA_enSTATE_DIS,
    0UL,
    DMA_enCH_ARBITRATION_SIZE_16,
    DMA_enCH_ACCESS_NON_PRIVILEGED,
    0UL,
    DMA_enCH_ACCESS_NON_PRIVILEGED,
    0UL,
    DMA_enCH_DATA_SIZE_BYTE,
    DMA_enCH_INCREMENT_BYTE,
    DMA_enCH_DATA_SIZE_BYTE,
    DMA_enCH_INCREMENT_NO,
};

static DMA_CH_CTL_t stDMAChControlUARTAlternateBuffer = {
    DMA_enCH_MODE_STOP,
    DMA_enSTATE_DIS,
    0UL,
    DMA_enCH_ARBITRATION_SIZE_16,
    DMA_enCH_ACCESS_NON_PRIVILEGED,
    0UL,
    DMA_enCH_ACCESS_NON_PRIVILEGED,
    0UL,
    DMA_enCH_DATA_SIZE_BYTE,
    DMA_enCH_INCREMENT_BYTE,
    DMA_enCH_DATA_SIZE_BYTE,
    DMA_enCH_INCREMENT_NO,
};

static void MAIN__vSetTransferSizeLeft(UBase_t uxSizeArg)
{
    MAIN_uxDMATransferSizeLeft = uxSizeArg;
}

static void MAIN__vSetPrimaryTransferStruct(DMA_CH_CTL_t* pstTransfer)
{
    MAIN_pstDMAPrimaryTransferStruct = pstTransfer;
}

static DMA_CH_CTL_t* MAIN__pstGetPrimaryTransferStruct(void)
{
    return (MAIN_pstDMAPrimaryTransferStruct);
}

static void MAIN__vSetAlternateTransferStruct(DMA_CH_CTL_t* pstTransfer)
{
    MAIN_pstDMAAlternateTransferStruct = pstTransfer;
}

static DMA_CH_CTL_t* MAIN__pstGetAlternateTransferStruct(void)
{
    return (MAIN_pstDMAAlternateTransferStruct);
}

UART_nERROR MAIN__enInitUartDMAConfig(void)
{
    UART_nERROR enErrorReg;
    DMA_CONFIG_t stDMAChConfig= {
        DMA_enSTATE_DIS,
        DMA_enCH_REQTYPE_BOTH,
        DMA_enCH_PERIPHERAL_ENA,
        DMA_enCH_CONTROL_PRIMARY ,
        DMA_enCH_PRIORITY_HIGH ,
        DMA_enCH_ENCODER_0
    };

    UART__enRegisterIRQSourceHandler(UART_enMODULE_0, UART_enINT_DMA_TRANSMIT, &MAIN__vDMATxInterupt);
    UART__enRegisterIRQSourceHandler(UART_enMODULE_0, UART_enINT_END_OF_TRANSMISSION, &MAIN__vDMATxLastBit);
    enErrorReg = (UART_nERROR) DMA_CH_Primary__enSetDestinationEndAddressByNumber(DMA_enMODULE_0, DMA_enCH_9, (UBase_t) (UART0_BASE + UART_DR_OFFSET));
    if(UART_enERROR_OK == enErrorReg)
    {
        enErrorReg = (UART_nERROR) DMA_CH_Alternate__enSetDestinationEndAddressByNumber(DMA_enMODULE_0, DMA_enCH_9, (UBase_t) (UART0_BASE + UART_DR_OFFSET));
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        enErrorReg = (UART_nERROR) DMA_CH_Primary__enSetSourceEndAddressByNumber(DMA_enMODULE_0, DMA_enCH_9, (UBase_t) 0UL);
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        enErrorReg = (UART_nERROR) DMA_CH_Alternate__enSetSourceEndAddressByNumber(DMA_enMODULE_0, DMA_enCH_9, (UBase_t) 0UL);
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        enErrorReg = (UART_nERROR) DMA_CH__enSetConfigParameters(DMA_enMODULE_0, DMA_enCH_9, &stDMAChConfig);
    }
    return (enErrorReg);
}

static UART_nERROR MAIN__enCustomWriteBuffer(UART_nMODULE enModuleArg, const uint8_t* pu8DataArg, UBase_t* puxBufferCant)
{
    UART_nERROR enErrorReg;
    OS_Semaphore__boTake(UARTSemaphoreHandle, OS_ADAPT_MAX_DELAY);
    enErrorReg = UART__enSetFifoDataByte(enModuleArg, pu8DataArg, puxBufferCant);
    OS_Semaphore__boGive(UARTSemaphoreHandle);
    return (enErrorReg);
}

static UART_nERROR MAIN__enWriteBufferDMA(UART_nMODULE enModuleArg, const uint8_t* pu8DataArg, UBase_t* puxBufferCant)
{
    UART_nERROR enErrorReg;
    UBase_t uxBufferCant;

    uxBufferCant = 0UL;
    enErrorReg = UART_enERROR_OK;
    if((0UL == (uintptr_t) puxBufferCant) || (0UL == (uintptr_t) pu8DataArg))
    {
        enErrorReg = UART_enERROR_POINTER;
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        if(0UL == *puxBufferCant)
        {
            enErrorReg = UART_enERROR_VALUE;
        }
        else
        {
            uxBufferCant = *puxBufferCant;
        }
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        OS_Semaphore__boTake(UARTSemaphoreHandle, OS_ADAPT_MAX_DELAY);
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        if(uxBufferCant >= 2048UL)
        {
            stDMAChControlUARTPrimaryBuffer.XFERMODE = (UBase_t) DMA_enCH_MODE_PING_PONG;
            stDMAChControlUARTAlternateBuffer.XFERMODE = (UBase_t) DMA_enCH_MODE_PING_PONG;
            stDMAChControlUARTPrimaryBuffer.XFERSIZE = 1024UL - 1UL;
            pu8DataArg += 1024UL;
            pu8DataArg -= 1UL;
            MAIN_uxDMATransferAddress = (UBase_t) pu8DataArg;
            uxBufferCant -= 1024UL;
            enErrorReg = (UART_nERROR) DMA_CH_Primary__enSetSourceEndAddressByNumber(DMA_enMODULE_0, DMA_enCH_9, MAIN_uxDMATransferAddress);
            stDMAChControlUARTAlternateBuffer.XFERSIZE = 1024UL - 1UL;
            pu8DataArg += 1024UL;
            MAIN_uxDMATransferAddress = (UBase_t) pu8DataArg;
            uxBufferCant -= 1024UL;
            enErrorReg = (UART_nERROR) DMA_CH_Alternate__enSetSourceEndAddressByNumber(DMA_enMODULE_0, DMA_enCH_9, MAIN_uxDMATransferAddress);
        }
        else if(uxBufferCant > 1024UL)
        {
            stDMAChControlUARTPrimaryBuffer.XFERMODE = (UBase_t) DMA_enCH_MODE_PING_PONG;
            stDMAChControlUARTAlternateBuffer.XFERMODE = (UBase_t) DMA_enCH_MODE_BASIC;
            stDMAChControlUARTPrimaryBuffer.XFERSIZE = 1024UL - 1UL;
            pu8DataArg += 1024UL;
            pu8DataArg -= 1UL;
            MAIN_uxDMATransferAddress = (UBase_t) pu8DataArg;
            uxBufferCant -= 1024UL;
            enErrorReg = (UART_nERROR) DMA_CH_Primary__enSetSourceEndAddressByNumber(DMA_enMODULE_0, DMA_enCH_9, MAIN_uxDMATransferAddress);
            stDMAChControlUARTAlternateBuffer.XFERSIZE = uxBufferCant - 1UL;
            pu8DataArg += uxBufferCant;
            MAIN_uxDMATransferAddress = (UBase_t) pu8DataArg;
            uxBufferCant = 0UL;
            enErrorReg = (UART_nERROR) DMA_CH_Alternate__enSetSourceEndAddressByNumber(DMA_enMODULE_0, DMA_enCH_9, MAIN_uxDMATransferAddress);
        }
        else
        {
            stDMAChControlUARTPrimaryBuffer.XFERMODE = (UBase_t) DMA_enCH_MODE_BASIC;
            stDMAChControlUARTAlternateBuffer.XFERMODE = (UBase_t) DMA_enCH_MODE_STOP;

            stDMAChControlUARTPrimaryBuffer.XFERSIZE = uxBufferCant - 1UL;
            pu8DataArg += uxBufferCant;
            pu8DataArg -= 1UL;
            MAIN_uxDMATransferAddress = (UBase_t) pu8DataArg;
            uxBufferCant = 0UL;
            enErrorReg = (UART_nERROR) DMA_CH_Primary__enSetSourceEndAddressByNumber(DMA_enMODULE_0, DMA_enCH_9, MAIN_uxDMATransferAddress);
            UART0_ICR_R = (UBase_t) UART_enINTMASK_END_OF_TRANSMISSION;
        }
        MAIN__vSetTransferSizeLeft(uxBufferCant);
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        enErrorReg = (UART_nERROR) DMA_CH_Primary__enSetControlRegisterByNumber(DMA_enMODULE_0, DMA_enCH_9, &stDMAChControlUARTPrimaryBuffer);
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        enErrorReg = (UART_nERROR) DMA_CH_Alternate__enSetControlRegisterByNumber(DMA_enMODULE_0, DMA_enCH_9, &stDMAChControlUARTAlternateBuffer);
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        enErrorReg = (UART_nERROR) DMA_CH__enSetActiveControStructureByNumber(DMA_enMODULE_0, DMA_enCH_9, DMA_enCH_CONTROL_PRIMARY);
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        MAIN__vSetPrimaryTransferStruct(&stDMAChControlUARTPrimaryBuffer);
        MAIN__vSetAlternateTransferStruct(&stDMAChControlUARTAlternateBuffer);
        enErrorReg = (UART_nERROR) DMA_CH__enSetStateByNumber(DMA_enMODULE_0, DMA_enCH_9, DMA_enSTATE_ENA);
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        UART__enClearInterruptSourceByMask(UART_enMODULE_0, (UART_nINTMASK) (UART_enINTMASK_DMA_TRANSMIT));
        UART__enEnableInterruptSourceByMask(UART_enMODULE_0, (UART_nINTMASK) (UART_enINTMASK_DMA_TRANSMIT));
        UART__enSetTransmitDMAState(UART_enMODULE_0, UART_enSTATE_ENA);
    }
    return (enErrorReg);
}

static void MAIN__vDMATxInterupt(uintptr_t uptrModuleArg, void* pvArgument)
{
    UBase_t uxMultiWord;
    UBase_t CurrentStructure;
    UBase_t ModePrimary;
    UBase_t ModeAlternate;
    UBase_t uxMulti;
    DMA_CH_CTL_t* pstDMAChannel;

    ModePrimary = DMA_CH_PRIMARY->CH[9UL].CTL_Bit.XFERMODE;
    ModeAlternate = DMA_CH_ALTERNATE->CH[9UL].CTL_Bit.XFERMODE;
    if(0UL != MAIN_uxDMATransferSizeLeft)
    {
        DMA->CH_ENASET = (UBase_t)  DMA_enSTATE_ENA << 9UL;
        UART0_DMACTL_R |= UART_DMACTL_R_TXDMAE_MASK;

        CurrentStructure = DMA_CH_ALTSET_R;
        CurrentStructure &= DMA_CH_ALTSET_R_SET9_MASK;
        if(DMA_CH_ALTSET_R_SET9_PRIM == CurrentStructure) /*fill alternate*/
        {
            pstDMAChannel = MAIN__pstGetAlternateTransferStruct();
        }
        else
        {
            pstDMAChannel = MAIN__pstGetPrimaryTransferStruct();
        }

        uxMulti = pstDMAChannel->SRCINC;
        uxMulti += 1UL;
        uxMulti &= 0x3UL;
        if((UBase_t) 3 == uxMulti)
        {
            uxMulti = 4UL;
        }

        if(MAIN_uxDMATransferSizeLeft > 1024UL)
        {
            pstDMAChannel->XFERMODE = (UBase_t) DMA_enCH_MODE_PING_PONG;
            pstDMAChannel->XFERSIZE = 1024UL - 1UL;
            uxMultiWord = (1024UL);
            uxMultiWord *= uxMulti;
            MAIN_uxDMATransferAddress += uxMultiWord;
            MAIN_uxDMATransferSizeLeft -= 1024UL;
        }
        else
        {
            pstDMAChannel->XFERMODE = (UBase_t) DMA_enCH_MODE_BASIC;
            pstDMAChannel->XFERSIZE = MAIN_uxDMATransferSizeLeft - 1UL;
            uxMultiWord = (MAIN_uxDMATransferSizeLeft);
            uxMultiWord *= uxMulti;
            MAIN_uxDMATransferAddress += uxMultiWord;
            MAIN_uxDMATransferSizeLeft = 0UL;
        }

        if(DMA_CH_ALTSET_R_SET9_PRIM == CurrentStructure) /*fill alternate*/
        {
            DMA_CH_ALTERNATE->CH[9UL].SRCENDP = (UBase_t) MAIN_uxDMATransferAddress;
            DMA_CH_ALTERNATE->CH[9UL].CTL = *((volatile UBase_t*) pstDMAChannel);
        }
        else
        {
            DMA_CH_PRIMARY->CH[9UL].SRCENDP = (UBase_t) MAIN_uxDMATransferAddress;
            DMA_CH_PRIMARY->CH[9UL].CTL = *((volatile UBase_t*) pstDMAChannel);
        }
    }
    else if((0UL != ModePrimary) || (0UL != ModeAlternate))
    {
        DMA->CH_ENASET = (UBase_t)  DMA_enSTATE_ENA << 9UL;
        UART0_ICR_R = (UBase_t) UART_enINTMASK_END_OF_TRANSMISSION;
        UART0_IM_R |= (UBase_t) UART_enINTMASK_END_OF_TRANSMISSION;
        UART0_DMACTL_R |= UART_DMACTL_R_TXDMAE_MASK;
    }
    else
    {
        UART0_IM_R |= (UBase_t) UART_enINTMASK_END_OF_TRANSMISSION;
        UART0_IM_R &= ~ (UBase_t) UART_enINTMASK_DMA_TRANSMIT;
    }
}


static void MAIN__vDMATxLastBit(uintptr_t uptrModuleArg, void* pvArgument)
{
    OS_Boolean_t boHigherPriorityTaskWoken = FALSE;
    UART0_IM_R &= ~ (UBase_t) UART_enINTMASK_END_OF_TRANSMISSION;
    OS_Semaphore__boGiveFromISR(UARTSemaphoreHandle, &boHigherPriorityTaskWoken);
    OS_Adapt__vYieldFromISR(boHigherPriorityTaskWoken);

}
