/**
 *
 * @file xTask9_TFT.c
 * @copyright
 * @verbatim InDeviceMex 2021 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 5 sep. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 5 sep. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xTask/xHeader/xTask9_TFT.h>
#include <xTask/xHeader/xSemaphores.h>

#include <xApplication/EDUMKII/EDUMKII.h>
#include <xApplication/ST7735/ST7735.h>
#include <xApplication/SHARP96_96/SHARP96_96.h>

#include <xApplication_MCU/xApplication_MCU.h>

#include <xUtils/Colors/Colors.h>
#include <xUtils/Math/Math.h>
#include <xImages/xImages.h>

#include <xOS/xOS.h>

static uint16_t u16BufferSPI[128UL * 128UL] __attribute__((aligned(4))) ;
static uint16_t u16BufferSPI2[128UL * 128UL] __attribute__((aligned(4))) ;
static uint16_t* pu16WriteBuffer = u16BufferSPI;
static uint16_t* pu16CurrentBuffer = u16BufferSPI2;

error_t TFT__enInitWriteDMAConfig(void);
void TFT__vDMATxInterupt(uintptr_t uptrModuleArg, void* pvArgument);
void TFT__vDMALayerInterrupt(uintptr_t uptrModuleArg, void* pvArgument);
void TFT__vDMALayerConstantInterrupt(uintptr_t uptrModuleArg, void* pvArgument);
error_t TFT__enWriteDMALayerConstant(uint16_t u16Constant, UBase_t uxBufferOut, UBase_t uxWidthArg, UBase_t uxHeightArg,
                             UBase_t uxStartXOutArg, UBase_t uxStartYOutArg, UBase_t uxMaxWidthOutArg, UBase_t uxMaxHeightOutArg);
error_t TFT__enWriteDMAConstant(UBase_t* uxBufferIn, UBase_t uxDataArg, UBase_t uxBufferCant);
error_t TFT__enWriteDMALayer16Bits(UBase_t uxBufferIn, UBase_t uxBufferOut, UBase_t uxWidthArg, UBase_t uxHeightArg,
                             UBase_t uxStartXInArg, UBase_t uxStartYInArg, UBase_t uxMaxWidthInArg, UBase_t uxMaxHeightInArg,
                             UBase_t uxStartXOutArg, UBase_t uxStartYOutArg, UBase_t uxMaxWidthOutArg, UBase_t uxMaxHeightOutArg);

void xTask9_TFT(void* pvParams)
{
    /*Period Handling*/
    const UBase_t uxPeriodTaskMin = 1UL;
    const UBase_t uxPeriodTaskMax = 240UL;
    UBase_t uxLastWakeTime;
    UBase_t uxPeriodTicks;
    UBase_t uxPeriodTicksOld;
    UBase_t uxPeriodResult;
    UBase_t uxPeriodTask = (UBase_t) pvParams;

    UBase_t uxJostickValue[2UL];
    Base_t sxAccelValue[3UL];
    char* pcStateButton[3UL];
    char* pcButtonOne;
    char* pcButtonTwo;

    UBase_t uxLcdPosXCurrent = 0UL;
    UBase_t uxLcdPosYCurrent = 0UL;
    UBase_t uxCountImage = 0UL;
    UBase_t uxCount= 0U;
    UBase_t uxImage= 0U;
    char pcConvert1[50UL];
    char pcConvert2[50UL];
    char pcConvert3[50UL];
    char pcConvert4[50UL];
    const uint16_t* pu16Pointer = (const uint16_t*) Images__pu8BicyclePointer();
    OS_Boolean_t boResult;
    OS_Boolean_t boPeriodUpdate;
    uint16_t* pu16TempBuffer;

    pcButtonOne = (char*) 0UL;
    pcButtonTwo = (char*) 0UL;
    GPIO__enSetReadyOnRunMode(GPIO_enPORT_F);
    GPIO__enSetDataByNumber(GPIO_enPORT_F, GPIO_enPIN_2, GPIO_enLEVEL_LOW);
    OS_Semaphore__boGive(MainSemaphoreHandle);
    OS_Semaphore__boGive(DMASemaphoreHandle);
    OS_Semaphore__boGive(ST7735SemaphoreHandle);
    ST7735__enInitRModel(ST7735_enINITFLAGS_GREEN);
    TFT__enInitWriteDMAConfig();
    GPIO__enSetDataByNumber(GPIO_enPORT_F, GPIO_enPIN_2, GPIO_enLEVEL_HIGH);

    uxLastWakeTime = OS_Task__uxGetTickCount ();
    uxPeriodTicksOld = 0UL;
    while(1UL)
    {
        uxPeriodTicks = OS_Task__uxGetTickCount();
        uxPeriodResult = uxPeriodTicks - uxPeriodTicksOld;
        uxPeriodTicksOld = uxPeriodTicks;
        OS_Semaphore__boTake(ST7735SemaphoreHandle, OS_ADAPT_MAX_DELAY);
        OS_Semaphore__boGive(ST7735SemaphoreHandle);
        TFT__enWriteDMAConstant((UBase_t*)(pu16CurrentBuffer), 0UL, (128UL *128UL / 2UL));
        if(0UL == uxCountImage)
        {
            if(uxImage)
            {
                pu16Pointer = (const uint16_t*) Images__pu8DolphinPointer();
            }
            else
            {
                pu16Pointer = (const uint16_t*) Images__pu8BicyclePointer();
            }
        }
        boResult = OS_Queue__boPeek(YoystickQueueHandle, uxJostickValue, 0UL);
        if(TRUE == boResult)
        {
             Math__enMapUnsigned(uxJostickValue[0UL], &uxLcdPosXCurrent, 4096UL, 0UL, 128UL - 120UL, 0UL);
             Math__enMapSigned((Base_t) uxJostickValue[1UL], (Base_t*) &uxLcdPosYCurrent, 4096, 0, 0, 128 - 76);
        }
        OS_Queue__boPeek(AccelerometerQueueHandle, sxAccelValue, 0UL);
        boResult = OS_Queue__boPeek(ButtonQueueHandle, pcStateButton, 0UL);
        boPeriodUpdate = FALSE;
        if(TRUE == boResult)
        {
            if(pcStateButton[0UL] != pcButtonOne)
            {
                pcButtonOne = pcStateButton[0UL];
                if(*(pcButtonOne + 1UL) == 'N')
                {
                    if(uxPeriodTaskMin < uxPeriodTask)
                    {
                        uxPeriodTask--;
                        boPeriodUpdate = TRUE;
                    }
                }
            }
            if(pcStateButton[1UL] != pcButtonTwo)
            {
                pcButtonTwo = pcStateButton[1UL];
                if(*(pcButtonTwo + 1UL) == 'N')
                {
                    if(uxPeriodTaskMax > uxPeriodTask)
                    {
                        uxPeriodTask++;
                        boPeriodUpdate = TRUE;
                    }
                }
            }
        }
        if(FALSE != boPeriodUpdate)
        {
            uxLastWakeTime = OS_Task__uxGetTickCount();
            uxPeriodTicksOld = uxLastWakeTime;
        }
        TFT__enWriteDMALayer16Bits((UBase_t) pu16Pointer, (UBase_t) pu16CurrentBuffer, 120UL, 76UL,
                                     0UL, 0UL, 120UL, 76UL,
                                     uxLcdPosXCurrent, uxLcdPosYCurrent, 128UL, 128UL);
        sprintf__uxUser(pcConvert1, "YOYSTICK\n\rX:%4d Y:%4d",
                         uxJostickValue[0UL],
                         uxJostickValue[1UL]
                         );
        sprintf__uxUser(pcConvert2, "ACCELEROMETER\n\rX:%4dY:%4dZ:%4d",
                         sxAccelValue[0UL],
                         sxAccelValue[1UL],
                         sxAccelValue[2UL]
                         );
        sprintf__uxUser(pcConvert3, "BUTTON\n\r1:%s 2:%s 3:%s",
                         pcStateButton[0UL],
                         pcStateButton[1UL],
                         pcStateButton[2UL]
                         );
        sprintf__uxUser(pcConvert4, "PERIOD\n\rEXP:%2d CUR:%2d", uxPeriodTask, uxPeriodResult);
        OS_Semaphore__boTake(DMASemaphoreHandle, OS_ADAPT_MAX_DELAY);
        ST7735__vBufferString(pu16CurrentBuffer, 0UL, 0UL, pcConvert3, 0xFFFFUL, &FONT_s5x7);
        ST7735__vBufferString(pu16CurrentBuffer, 0UL, 16UL, pcConvert1, 0xFFFFUL, &FONT_s5x7);
        ST7735__vBufferString(pu16CurrentBuffer, 0UL, 32UL, pcConvert2, 0xFFFFUL, &FONT_s5x7);
        ST7735__vBufferString(pu16CurrentBuffer, 0UL, 48UL, pcConvert4, 0xFFFFUL, &FONT_s5x7);
        OS_Semaphore__boGive(DMASemaphoreHandle);

        pu16TempBuffer = pu16WriteBuffer;
        pu16WriteBuffer = pu16CurrentBuffer;
        pu16CurrentBuffer = pu16TempBuffer;
        ST7735__vDrawBuffer(0UL, 0UL, 128UL, 128UL, pu16WriteBuffer);

        uxCountImage++;
        if(uxCountImage > 60UL)
        {
            uxImage ^= 1UL;
            uxCountImage = 0UL;
        }
        uxCount++;


        OS_Task__vDelayUntil(&uxLastWakeTime, uxPeriodTask);
    }
}

static UBase_t uxTranferLeft = 0UL;
static UBase_t uxTranferSize = 0UL;
static volatile DMA_CH_CTL_t* TFT_pstDMATransferStruct = (DMA_CH_CTL_t*) 0UL;

error_t TFT__enInitWriteDMAConfig(void)
{
    error_t enErrorReg;
    DMA_CONFIG_t stDMAChConfig= {
        DMA_enSTATE_DIS,
        DMA_enCH_REQTYPE_BURST,
        DMA_enCH_PERIPHERAL_DIS,
        DMA_enCH_CONTROL_PRIMARY,
        DMA_enCH_PRIORITY_LOW,
        DMA_enCH_ENCODER_0
    };
    DMA__enEnableInterruptVectorWithPriority(DMA_enMODULE_0, DMA_enVECTOR_SOFTWARE, DMA_enPRI4);
    enErrorReg = (error_t) DMA_CH__enRegisterIRQSourceHandler_Software(&TFT__vDMATxInterupt, DMA_enMODULE_0, DMA_enCH_30);
    if(ERROR_OK == enErrorReg)
    {
        enErrorReg = (error_t) DMA_CH__enSetPriorityByNumber(DMA_enMODULE_0, DMA_enCH_30, DMA_enCH_PRIORITY_HIGH);
    }
    if(ERROR_OK == enErrorReg)
    {
        enErrorReg = (error_t) DMA_CH__enSetConfigParameters(DMA_enMODULE_0, DMA_enCH_30, &stDMAChConfig);
    }
    return (enErrorReg);
}

static DMA_CH_CTL_t stDMAChControl = {
    DMA_enCH_MODE_AUTO_REQ,
    DMA_enSTATE_DIS,
    0UL,
    DMA_enCH_ARBITRATION_SIZE_1024,
    DMA_enCH_ACCESS_NON_PRIVILEGED,
    0UL,
    DMA_enCH_ACCESS_NON_PRIVILEGED,
    0UL,
    DMA_enCH_DATA_SIZE_WORD,
    DMA_enCH_INCREMENT_NO,
    DMA_enCH_DATA_SIZE_WORD,
    DMA_enCH_INCREMENT_WORD,
};

error_t TFT__enWriteDMAConstant(UBase_t* uxBufferIn, UBase_t uxDataArg, UBase_t uxBufferCant)
{
    error_t enErrorReg;
    static UBase_t uxDataReg = 0UL;
    uxDataReg = uxDataArg;

    enErrorReg = ERROR_OK;
    if(0UL == (uintptr_t) uxBufferIn)
    {
        enErrorReg = ERROR_VALUE;
    }
    if(0UL == uxBufferCant)
    {
        enErrorReg = ERROR_VALUE;
    }
    if(ERROR_OK == enErrorReg)
    {
        OS_Semaphore__boTake(DMASemaphoreHandle, OS_ADAPT_MAX_DELAY);
    }
    if(ERROR_OK == enErrorReg)
    {
        stDMAChControl.XFERMODE = (UBase_t) DMA_enCH_MODE_AUTO_REQ;
        if(uxBufferCant > 1024UL)
        {
            stDMAChControl.XFERSIZE = 1024UL - 1UL;
            uxBufferCant -= 1024UL;
            uxTranferSize = 1024UL;
        }
        else
        {
            stDMAChControl.XFERSIZE = uxBufferCant - 1UL;
            uxTranferSize = uxBufferCant;
            uxBufferCant = 0UL;
        }
        uxTranferLeft = uxBufferCant;
    }
    if(ERROR_OK == enErrorReg)
    {
        enErrorReg = (error_t) DMA_CH__enRegisterIRQSourceHandler_Software(&TFT__vDMATxInterupt, DMA_enMODULE_0, DMA_enCH_30);
    }
    if(ERROR_OK == enErrorReg)
    {
        enErrorReg = (error_t) DMA_CH_Primary__enSetSourceEndAddressByNumber(DMA_enMODULE_0, DMA_enCH_30, (UBase_t) &uxDataReg);
    }
    if(ERROR_OK == enErrorReg)
    {
        enErrorReg = (error_t) DMA_CH_Primary__enSetDestinationEndAddressByNumber(DMA_enMODULE_0, DMA_enCH_30, (UBase_t) (uxBufferIn + uxTranferSize - 1UL));
    }
    if(ERROR_OK == enErrorReg)
    {
        enErrorReg = (error_t) DMA_CH_Primary__enSetControlRegisterByNumber(DMA_enMODULE_0, DMA_enCH_30, &stDMAChControl);
    }
    if(ERROR_OK == enErrorReg)
    {
        TFT_pstDMATransferStruct = &stDMAChControl;
        enErrorReg = (error_t) DMA_CH__enSetStateByNumber(DMA_enMODULE_0, DMA_enCH_30, DMA_enSTATE_ENA);
    }
    if(ERROR_OK == enErrorReg)
    {
        DMA_CH__enSetStateByNumber(DMA_enMODULE_0, DMA_enCH_30, DMA_enSTATE_ENA);
        DMA_CH__enSetSoftwareRequestByNumber(DMA_enMODULE_0, DMA_enCH_30);
    }
    return (enErrorReg);
}


static DMA_CH_CTL_t stDMAChLayer = {
    DMA_enCH_MODE_AUTO_REQ,
    DMA_enSTATE_DIS,
    0UL,
    DMA_enCH_ARBITRATION_SIZE_128,
    DMA_enCH_ACCESS_PRIVILEGED,
    0UL,
    DMA_enCH_ACCESS_PRIVILEGED,
    0UL,
    DMA_enCH_DATA_SIZE_HALF_WORD,
    DMA_enCH_INCREMENT_HALF_WORD,
    DMA_enCH_DATA_SIZE_HALF_WORD,
    DMA_enCH_INCREMENT_HALF_WORD,
};

static uint16_t* pu16StartXInAddress;
static uint16_t* pu16StartXOutAddress;

static UBase_t uxWidthMaxInImage;
static UBase_t uxWidthMaxOutImage;
static UBase_t uxWidthImage;
static UBase_t uxHeightImage;

error_t TFT__enWriteDMALayer16Bits(UBase_t uxBufferIn, UBase_t uxBufferOut, UBase_t uxWidthArg, UBase_t uxHeightArg,
                             UBase_t uxStartXInArg, UBase_t uxStartYInArg, UBase_t uxMaxWidthInArg, UBase_t uxMaxHeightInArg,
                             UBase_t uxStartXOutArg, UBase_t uxStartYOutArg, UBase_t uxMaxWidthOutArg, UBase_t uxMaxHeightOutArg)
{
    error_t enErrorReg;
    uint16_t* pu16InAddress;
    uint16_t* pu16OutAddress;

    enErrorReg = ERROR_OK;
    if((0UL == (uintptr_t) uxBufferIn) || (0UL == (uintptr_t) uxBufferOut))
    {
        enErrorReg = ERROR_VALUE;
    }
    if((0UL == uxWidthArg) || (0UL == uxHeightArg) ||
       (0UL == uxMaxWidthInArg) || (0UL == uxMaxHeightInArg) ||
       (0UL == uxMaxWidthOutArg) || (0UL == uxMaxHeightOutArg))
    {
        enErrorReg = ERROR_VALUE;
    }
    if((uxMaxWidthInArg < (uxStartXInArg + uxWidthArg)) || (uxMaxHeightInArg < (uxStartYInArg + uxHeightArg)) ||
       (uxMaxWidthOutArg < (uxStartXOutArg + uxWidthArg)) || (uxMaxHeightOutArg < (uxStartYOutArg + uxHeightArg)))
    {
        enErrorReg = ERROR_VALUE;
    }
    if(ERROR_OK == enErrorReg)
    {
        OS_Semaphore__boTake(DMASemaphoreHandle, OS_ADAPT_MAX_DELAY);
    }
    if(ERROR_OK == enErrorReg)
    {
        pu16StartXInAddress = (uint16_t*) uxBufferIn;
        pu16StartXInAddress += (uxStartYInArg * uxMaxWidthInArg);
        pu16StartXInAddress += uxStartXInArg;
        uxWidthMaxInImage = uxMaxWidthInArg;

        pu16StartXOutAddress = (uint16_t*) uxBufferOut;
        pu16StartXOutAddress += (uxStartYOutArg * uxMaxWidthOutArg);
        pu16StartXOutAddress += uxStartXOutArg;
        uxWidthMaxOutImage = uxMaxWidthOutArg;

        uxWidthImage = uxWidthArg;
        uxHeightImage = uxHeightArg;

        stDMAChLayer.XFERMODE = (UBase_t) DMA_enCH_MODE_AUTO_REQ;
        stDMAChLayer.XFERSIZE = uxWidthArg - 1UL;
        uxHeightImage--;
    }
    if(ERROR_OK == enErrorReg)
    {
        enErrorReg = (error_t) DMA_CH__enRegisterIRQSourceHandler_Software(&TFT__vDMALayerInterrupt, DMA_enMODULE_0, DMA_enCH_30);
    }
    if(ERROR_OK == enErrorReg)
    {
        pu16InAddress = pu16StartXInAddress;
        pu16InAddress += uxWidthImage;
        pu16InAddress -= 1UL;
        enErrorReg = (error_t) DMA_CH_Primary__enSetSourceEndAddressByNumber(DMA_enMODULE_0, DMA_enCH_30, (UBase_t) pu16InAddress);
    }
    if(ERROR_OK == enErrorReg)
    {
        pu16OutAddress = pu16StartXOutAddress;
        pu16OutAddress += uxWidthImage;
        pu16OutAddress -= 1UL;
        enErrorReg = (error_t) DMA_CH_Primary__enSetDestinationEndAddressByNumber(DMA_enMODULE_0, DMA_enCH_30, (UBase_t) pu16OutAddress);
    }
    if(ERROR_OK == enErrorReg)
    {
        enErrorReg = (error_t) DMA_CH_Primary__enSetControlRegisterByNumber(DMA_enMODULE_0, DMA_enCH_30, &stDMAChLayer);
    }
    if(ERROR_OK == enErrorReg)
    {
        TFT_pstDMATransferStruct = &stDMAChLayer;
        enErrorReg = (error_t) DMA_CH__enSetStateByNumber(DMA_enMODULE_0, DMA_enCH_30, DMA_enSTATE_ENA);
    }
    if(ERROR_OK == enErrorReg)
    {
        DMA_CH__enSetStateByNumber(DMA_enMODULE_0, DMA_enCH_30, DMA_enSTATE_ENA);
        DMA_CH__enSetSoftwareRequestByNumber(DMA_enMODULE_0, DMA_enCH_30);
    }
    return (enErrorReg);
}

static DMA_CH_CTL_t stDMAChLayerConstant = {
    DMA_enCH_MODE_AUTO_REQ,
    DMA_enSTATE_DIS,
    0UL,
    DMA_enCH_ARBITRATION_SIZE_128,
    DMA_enCH_ACCESS_PRIVILEGED,
    0UL,
    DMA_enCH_ACCESS_PRIVILEGED,
    0UL,
    DMA_enCH_DATA_SIZE_HALF_WORD,
    DMA_enCH_INCREMENT_NO,
    DMA_enCH_DATA_SIZE_HALF_WORD,
    DMA_enCH_INCREMENT_HALF_WORD,
};
error_t TFT__enWriteDMALayerConstant(uint16_t u16Constant, UBase_t uxBufferOut, UBase_t uxWidthArg, UBase_t uxHeightArg,
                             UBase_t uxStartXOutArg, UBase_t uxStartYOutArg, UBase_t uxMaxWidthOutArg, UBase_t uxMaxHeightOutArg)
{
    error_t enErrorReg;
    uint16_t* pu16OutAddress;
    static uint16_t u16DataReg = 0UL;
    u16DataReg = u16Constant;

    enErrorReg = ERROR_OK;
    if(0UL == (uintptr_t) uxBufferOut)
    {
        enErrorReg = ERROR_VALUE;
    }
    if((0UL == uxWidthArg) || (0UL == uxHeightArg) ||
       (0UL == uxMaxWidthOutArg) || (0UL == uxMaxHeightOutArg))
    {
        enErrorReg = ERROR_VALUE;
    }
    if((uxMaxWidthOutArg < (uxStartXOutArg + uxWidthArg)) || (uxMaxHeightOutArg < (uxStartYOutArg + uxHeightArg)))
    {
        enErrorReg = ERROR_VALUE;
    }
    if(ERROR_OK == enErrorReg)
    {
        OS_Semaphore__boTake(DMASemaphoreHandle, OS_ADAPT_MAX_DELAY);
    }
    if(ERROR_OK == enErrorReg)
    {
        pu16StartXOutAddress = (uint16_t*) uxBufferOut;
        pu16StartXOutAddress += (uxStartYOutArg * uxMaxWidthOutArg);
        pu16StartXOutAddress += uxStartXOutArg;
        uxWidthMaxOutImage = uxMaxWidthOutArg;

        uxWidthImage = uxWidthArg;
        uxHeightImage = uxHeightArg;

        stDMAChLayerConstant.XFERMODE = (UBase_t) DMA_enCH_MODE_AUTO_REQ;
        stDMAChLayerConstant.XFERSIZE = uxWidthArg - 1UL;
        uxHeightImage--;
    }
    if(ERROR_OK == enErrorReg)
    {
        enErrorReg = (error_t) DMA_CH__enRegisterIRQSourceHandler_Software(&TFT__vDMALayerConstantInterrupt, DMA_enMODULE_0, DMA_enCH_30);
    }
    if(ERROR_OK == enErrorReg)
    {
        enErrorReg = (error_t) DMA_CH_Primary__enSetSourceEndAddressByNumber(DMA_enMODULE_0, DMA_enCH_30, (UBase_t) &u16DataReg);
    }
    if(ERROR_OK == enErrorReg)
    {
        pu16OutAddress = pu16StartXOutAddress;
        pu16OutAddress += uxWidthImage;
        pu16OutAddress -= 1UL;
        enErrorReg = (error_t) DMA_CH_Primary__enSetDestinationEndAddressByNumber(DMA_enMODULE_0, DMA_enCH_30, (UBase_t) pu16OutAddress);
    }
    if(ERROR_OK == enErrorReg)
    {
        enErrorReg = (error_t) DMA_CH_Primary__enSetControlRegisterByNumber(DMA_enMODULE_0, DMA_enCH_30, &stDMAChLayerConstant);
    }
    if(ERROR_OK == enErrorReg)
    {
        TFT_pstDMATransferStruct = &stDMAChLayerConstant;
        enErrorReg = (error_t) DMA_CH__enSetStateByNumber(DMA_enMODULE_0, DMA_enCH_30, DMA_enSTATE_ENA);
    }
    if(ERROR_OK == enErrorReg)
    {
        DMA_CH__enSetStateByNumber(DMA_enMODULE_0, DMA_enCH_30, DMA_enSTATE_ENA);
        DMA_CH__enSetSoftwareRequestByNumber(DMA_enMODULE_0, DMA_enCH_30);
    }
    return (enErrorReg);
}

void TFT__vDMALayerConstantInterrupt(uintptr_t uptrModuleArg, void* pvArgument)
{
    uint16_t* pu16AddressOut;
    DMA_CH_CTL_t* pstDMAChannel;
    if(0UL != uxHeightImage)
    {
        uxHeightImage -= 1UL;
        pstDMAChannel = TFT_pstDMATransferStruct;
        pstDMAChannel->XFERSIZE = uxWidthImage - 1UL;
        pu16AddressOut = (uint16_t*) (DMA_CH_PRIMARY->CH[30UL].DSTENDP);
        pu16AddressOut += uxWidthMaxOutImage;

        DMA_CH_PRIMARY->CH[30UL].DSTENDP = (UBase_t) pu16AddressOut;
        DMA_CH_PRIMARY->CH[30UL].CTL = *((volatile UBase_t*) pstDMAChannel);
        DMA->CH_ENASET = (UBase_t)  DMA_enSTATE_ENA << 30UL;
        DMA->CH_SWREQ = (UBase_t) 1UL << (UBase_t) 30UL;
    }
    else
    {
        OS_Boolean_t boHigherPriorityTaskWoken = FALSE;
        OS_Semaphore__boGiveFromISR(DMASemaphoreHandle, &boHigherPriorityTaskWoken);
        OS_Adapt__vYieldFromISR(boHigherPriorityTaskWoken);
    }
}

void TFT__vDMALayerInterrupt(uintptr_t uptrModuleArg, void* pvArgument)
{
    uint16_t* pu16AddressIn;
    uint16_t* pu16AddressOut;
    DMA_CH_CTL_t* pstDMAChannel;
    if(0UL != uxHeightImage)
    {
        uxHeightImage -= 1UL;
        pstDMAChannel = TFT_pstDMATransferStruct;
        pstDMAChannel->XFERSIZE = uxWidthImage - 1UL;
        pu16AddressIn = (uint16_t*) (DMA_CH_PRIMARY->CH[30UL].SRCENDP);
        pu16AddressOut = (uint16_t*) (DMA_CH_PRIMARY->CH[30UL].DSTENDP);
        pu16AddressIn += uxWidthMaxInImage;
        pu16AddressOut += uxWidthMaxOutImage;

        DMA_CH_PRIMARY->CH[30UL].SRCENDP = (UBase_t) pu16AddressIn;
        DMA_CH_PRIMARY->CH[30UL].DSTENDP = (UBase_t) pu16AddressOut;
        DMA_CH_PRIMARY->CH[30UL].CTL = *((volatile UBase_t*) pstDMAChannel);
        DMA->CH_ENASET = (UBase_t)  DMA_enSTATE_ENA << 30UL;
        DMA->CH_SWREQ = (UBase_t) 1UL << (UBase_t) 30UL;
    }
    else
    {
        OS_Boolean_t boHigherPriorityTaskWoken = FALSE;
        OS_Semaphore__boGiveFromISR(DMASemaphoreHandle, &boHigherPriorityTaskWoken);
        OS_Adapt__vYieldFromISR(boHigherPriorityTaskWoken);
    }
}

void TFT__vDMATxInterupt(uintptr_t uptrModuleArg, void* pvArgument)
{
    UBase_t* puxAddress;
    DMA_CH_CTL_t* pstDMAChannel;
    if(0UL != uxTranferLeft)
    {
        pstDMAChannel = TFT_pstDMATransferStruct;
        puxAddress = (UBase_t*) (DMA_CH_PRIMARY->CH[30UL].DSTENDP);
        if(uxTranferLeft > 1024UL)
        {
            pstDMAChannel->XFERSIZE = 1024UL - 1UL;
            puxAddress += 1024UL;
            uxTranferLeft -= 1024UL;
        }
        else
        {
            pstDMAChannel->XFERSIZE = uxTranferLeft - 1UL;
            puxAddress += uxTranferLeft;
            uxTranferLeft = 0UL;

        }
        DMA_CH_PRIMARY->CH[30UL].DSTENDP = (UBase_t) puxAddress;
        DMA_CH_PRIMARY->CH[30UL].CTL = *((volatile UBase_t*) pstDMAChannel);
        DMA->CH_ENASET = (UBase_t)  DMA_enSTATE_ENA << 30UL;
        DMA->CH_SWREQ = (UBase_t) 1UL << (UBase_t) 30UL;
    }
    else
    {
        OS_Boolean_t boHigherPriorityTaskWoken = FALSE;
        OS_Semaphore__boGiveFromISR(DMASemaphoreHandle, &boHigherPriorityTaskWoken);
        OS_Adapt__vYieldFromISR(boHigherPriorityTaskWoken);
    }
}

