/**
 *
 * @file ST7735_Write.c
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
 * @verbatim 18 feb. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 18 feb. 2021     vyldram    1.0         initial Version@endverbatim
 */
#include <xApplication/ST7735/xHeader/ST7735_Write.h>
#include <xApplication/ST7735/xHeader/ST7735_Init.h>

#include <xApplication/ST7735/xHeader/ST7735_ChipSelect.h>
#include <xApplication/ST7735/xHeader/ST7735_DataCommand.h>
#include <xApplication/ST7735/xHeader/ST7735_Reset.h>

#include <xApplication/ST7735/xHeader/ST7735_Defines.h>

#include <xUtils/Colors/Colors.h>
#include <xUtils/Font/Font.h>

#include <xDriver_MCU/GPIO/GPIO.h>
#include <xDriver_MCU/SSI/SSI.h>
#include <xDriver_MCU/SSI/Peripheral/SSI_Peripheral.h>
#include <xDriver_MCU/Common/xHeader/MCU_Interrupt.h>
#include <xDriver_MCU/DMA/DMA.h>

#include <xTask/xHeader/xSemaphores.h>

void ST7735__vDMATxEndInterupt(void);
void ST7735__vDMATxLastBit(uintptr_t uptrModuleArg, void* pvArgument);
void ST7735__vDMATxInterupt(uintptr_t uptrModuleArg, void* pvArgument);
static void ST7735__vSetTransferSizeLeft(UBase_t uxSizeArg);
static void ST7735__vSetPrimaryTransferStruct(DMA_CH_CTL_t* pstTransfer);
static void ST7735__vSetAlternateTransferStruct(DMA_CH_CTL_t* pstTransfer);
UBase_t ST7735__uxGetTransferAddress(void);
UBase_t ST7735__uxGetTransferSizeLeft(void);
DMA_CH_CTL_t* ST7735__pstGetPrimaryTransferStruct(void);
DMA_CH_CTL_t* ST7735__pstGetAlternateTransferStruct(void);

static UBase_t ST7735_uxDMATransferSizeLeft = 0UL;
static UBase_t ST7735_uxDMATransferAddress = 0UL;
static DMA_CH_CTL_t* ST7735_pstDMAPrimaryTransferStruct = (DMA_CH_CTL_t*) 0UL;
static DMA_CH_CTL_t* ST7735_pstDMAAlternateTransferStruct = (DMA_CH_CTL_t*) 0UL;

static DMA_CH_CTL_t stDMAChControlPrimaryConstant = {
    DMA_enCH_MODE_STOP,
    DMA_enSTATE_DIS,
    0UL,
    DMA_enCH_ARBITRATION_SIZE_8,
    DMA_enCH_ACCESS_NON_PRIVILEGED,
    0UL,
    DMA_enCH_ACCESS_NON_PRIVILEGED,
    0UL,
    DMA_enCH_DATA_SIZE_HALF_WORD,
    DMA_enCH_INCREMENT_NO,
    DMA_enCH_DATA_SIZE_HALF_WORD,
    DMA_enCH_INCREMENT_NO,
};

static DMA_CH_CTL_t stDMAChControlAlternateConstant = {
    DMA_enCH_MODE_STOP,
    DMA_enSTATE_DIS,
    0UL,
    DMA_enCH_ARBITRATION_SIZE_8,
    DMA_enCH_ACCESS_NON_PRIVILEGED,
    0UL,
    DMA_enCH_ACCESS_NON_PRIVILEGED,
    0UL,
    DMA_enCH_DATA_SIZE_HALF_WORD,
    DMA_enCH_INCREMENT_NO,
    DMA_enCH_DATA_SIZE_HALF_WORD,
    DMA_enCH_INCREMENT_NO,
};
static DMA_CH_CTL_t stDMAChControlPrimaryBuffer = {
    DMA_enCH_MODE_STOP,
    DMA_enSTATE_DIS,
    0UL,
    DMA_enCH_ARBITRATION_SIZE_8,
    DMA_enCH_ACCESS_NON_PRIVILEGED,
    0UL,
    DMA_enCH_ACCESS_NON_PRIVILEGED,
    0UL,
    DMA_enCH_DATA_SIZE_HALF_WORD,
    DMA_enCH_INCREMENT_HALF_WORD,
    DMA_enCH_DATA_SIZE_HALF_WORD,
    DMA_enCH_INCREMENT_NO,
};

static DMA_CH_CTL_t stDMAChControlAlternateBuffer = {
    DMA_enCH_MODE_STOP,
    DMA_enSTATE_DIS,
    0UL,
    DMA_enCH_ARBITRATION_SIZE_8,
    DMA_enCH_ACCESS_NON_PRIVILEGED,
    0UL,
    DMA_enCH_ACCESS_NON_PRIVILEGED,
    0UL,
    DMA_enCH_DATA_SIZE_HALF_WORD,
    DMA_enCH_INCREMENT_HALF_WORD,
    DMA_enCH_DATA_SIZE_HALF_WORD,
    DMA_enCH_INCREMENT_NO,
};

error_t ST7735__enInitWriteDMAConfig(void)
{
    error_t enErrorReg;
    DMA_CONFIG_t stDMAChConfig= {
        DMA_enSTATE_DIS,
        DMA_enCH_REQTYPE_BOTH,
        DMA_enCH_PERIPHERAL_ENA,
        DMA_enCH_CONTROL_PRIMARY ,
        DMA_enCH_PRIORITY_HIGH ,
        DMA_enCH_ENCODER_2
    };

    SSI__enRegisterIRQSourceHandler(ST7735_SSI, SSI_enINT_TRANSMIT_DMA, &ST7735__vDMATxInterupt);
    SSI__enRegisterIRQSourceHandler(ST7735_SSI, SSI_enINT_END_OF_TRANSMIT, &ST7735__vDMATxLastBit);
    enErrorReg = (error_t) DMA_CH_Primary__enSetDestinationEndAddressByNumber(DMA_enMODULE_0, DMA_enCH_13, (UBase_t) (SSI2_BASE + SSI_DR_OFFSET));
    if(ERROR_OK == enErrorReg)
    {
        enErrorReg = (error_t) DMA_CH_Alternate__enSetDestinationEndAddressByNumber(DMA_enMODULE_0, DMA_enCH_13, (UBase_t) (SSI2_BASE + SSI_DR_OFFSET));
    }
    if(ERROR_OK == enErrorReg)
    {
        enErrorReg = (error_t) DMA_CH_Primary__enSetSourceEndAddressByNumber(DMA_enMODULE_0, DMA_enCH_13, (UBase_t) 0UL);
    }
    if(ERROR_OK == enErrorReg)
    {
        enErrorReg = (error_t) DMA_CH_Alternate__enSetSourceEndAddressByNumber(DMA_enMODULE_0, DMA_enCH_13, (UBase_t) 0UL);
    }
    if(ERROR_OK == enErrorReg)
    {
        enErrorReg = (error_t) DMA_CH__enSetPriorityByNumber(DMA_enMODULE_0, DMA_enCH_13, DMA_enCH_PRIORITY_HIGH);
    }
    if(ERROR_OK == enErrorReg)
    {
        enErrorReg = (error_t) DMA_CH__enSetConfigParameters(DMA_enMODULE_0, DMA_enCH_13, &stDMAChConfig);
    }
    return (enErrorReg);
}

static void ST7735__vSetTransferSizeLeft(UBase_t uxSizeArg)
{
    ST7735_uxDMATransferSizeLeft = uxSizeArg;
}

UBase_t ST7735__uxGetTransferSizeLeft(void)
{
    UBase_t uxSizeArg;
    uxSizeArg = ST7735_uxDMATransferSizeLeft;
    return (uxSizeArg);
}

static void ST7735__vSetPrimaryTransferStruct(DMA_CH_CTL_t* pstTransfer)
{
    ST7735_pstDMAPrimaryTransferStruct = pstTransfer;
}

DMA_CH_CTL_t* ST7735__pstGetPrimaryTransferStruct(void)
{
    return (ST7735_pstDMAPrimaryTransferStruct);
}

static void ST7735__vSetAlternateTransferStruct(DMA_CH_CTL_t* pstTransfer)
{
    ST7735_pstDMAAlternateTransferStruct = pstTransfer;
}

DMA_CH_CTL_t* ST7735__pstGetAlternateTransferStruct(void)
{
    return (ST7735_pstDMAAlternateTransferStruct);
}



UBase_t ST7735__uxGetTransferAddress(void)
{
    return (ST7735_uxDMATransferAddress);
}


error_t ST7735__enWriteCommand(uint16_t u16DataArg)
{
    error_t enErrorReg;
    UBase_t uxDataReg;

    OS_Semaphore__boTake(ST7735SemaphoreHandle, OS_ADAPT_MAX_DELAY);

    enErrorReg = ST7735__enEnableChipSelect();
    if(ERROR_OK == enErrorReg)
    {
        enErrorReg = ST7735__enSetCommand();
    }
    if(ERROR_OK == enErrorReg)
    {
        uxDataReg = (uint32_t) u16DataArg;
        (void) SSI__enSetDataTimeOut(ST7735_SSI, uxDataReg, 100UL);
        enErrorReg = ST7735__enDisableChipSelect();
    }
    OS_Semaphore__boGive(ST7735SemaphoreHandle);
    return (enErrorReg);
}

error_t ST7735__enWriteData(UBase_t uxDataArg)
{
    error_t enErrorReg;
    OS_Semaphore__boTake(ST7735SemaphoreHandle, OS_ADAPT_MAX_DELAY);

    enErrorReg = ST7735__enEnableChipSelect();
    if(ERROR_OK == enErrorReg)
    {
        enErrorReg = ST7735__enSetData();
    }
    if(ERROR_OK == enErrorReg)
    {
        (void) SSI__enSetDataTimeOut(ST7735_SSI, uxDataArg, 100UL);
        enErrorReg = ST7735__enDisableChipSelect();
    }
    OS_Semaphore__boGive(ST7735SemaphoreHandle);
    return (enErrorReg);
}



error_t ST7735__enWriteFifo(uint16_t u16DataArg, UBase_t uxBufferCant)
{
    error_t enErrorReg;
    UBase_t uxCountReg;
    OS_Semaphore__boTake(ST7735SemaphoreHandle, OS_ADAPT_MAX_DELAY);

    enErrorReg = ST7735__enEnableChipSelect();
    if(ERROR_OK == enErrorReg)
    {
        enErrorReg = ST7735__enSetData();
    }
    if(ERROR_OK == enErrorReg)
    {
        uxCountReg = uxBufferCant;
        (void) SSI__enSetFifoDataConst(ST7735_SSI,  (UBase_t)  u16DataArg, &uxCountReg);
        enErrorReg = ST7735__enDisableChipSelect();
    }
    OS_Semaphore__boGive(ST7735SemaphoreHandle);
    return (enErrorReg);
}


error_t ST7735__enWriteDMA(UBase_t uxDataArg, UBase_t uxBufferCant)
{
    error_t enErrorReg;
    static UBase_t uxDataReg = 0UL;
    uxDataReg = uxDataArg;

    enErrorReg = ERROR_OK;
    if(0UL == uxBufferCant)
    {
        enErrorReg = ERROR_VALUE;
    }
    if(ERROR_OK == enErrorReg)
    {
        OS_Semaphore__boTake(ST7735SemaphoreHandle, OS_ADAPT_MAX_DELAY);

        SSI__enSetState(ST7735_SSI, SSI_enSTATE_DIS);
        SSI__enSetDataLength(ST7735_SSI, SSI_enLENGTH_16BITS);
        SSI__enSetState(ST7735_SSI, SSI_enSTATE_ENA);
    }
    if(ERROR_OK == enErrorReg)
    {
        enErrorReg = ST7735__enEnableChipSelect();
        if(ERROR_OK == enErrorReg)
        {
            enErrorReg = ST7735__enSetData();
        }
        if(ERROR_OK == enErrorReg)
        {
            ST7735_uxDMATransferAddress = (UBase_t) &uxDataReg;
            stDMAChControlPrimaryConstant.XFERMODE = (UBase_t) DMA_enCH_MODE_PING_PONG;
            stDMAChControlAlternateConstant.XFERMODE = (UBase_t) DMA_enCH_MODE_PING_PONG;
            if(uxBufferCant > 2048UL)
            {
                stDMAChControlPrimaryConstant.XFERMODE = (UBase_t) DMA_enCH_MODE_PING_PONG;
                stDMAChControlAlternateConstant.XFERMODE = (UBase_t) DMA_enCH_MODE_PING_PONG;
                stDMAChControlPrimaryConstant.XFERSIZE = 1024UL - 1UL;
                uxBufferCant -= 1024UL;
                enErrorReg = (error_t) DMA_CH_Primary__enSetSourceEndAddressByNumber(DMA_enMODULE_0, DMA_enCH_13, (UBase_t) &uxDataReg);
                stDMAChControlAlternateConstant.XFERSIZE = 1024UL - 1UL;
                uxBufferCant -= 1024UL;
                enErrorReg = (error_t) DMA_CH_Alternate__enSetSourceEndAddressByNumber(DMA_enMODULE_0, DMA_enCH_13,(UBase_t) &uxDataReg);
            }
            else if(uxBufferCant > 1024UL)
            {
                stDMAChControlPrimaryConstant.XFERMODE = (UBase_t) DMA_enCH_MODE_PING_PONG;
                stDMAChControlAlternateConstant.XFERMODE = (UBase_t) DMA_enCH_MODE_BASIC;
                stDMAChControlPrimaryConstant.XFERSIZE = 1024UL - 1UL;
                uxBufferCant -= 1024UL;
                enErrorReg = (error_t) DMA_CH_Primary__enSetSourceEndAddressByNumber(DMA_enMODULE_0, DMA_enCH_13, (UBase_t) &uxDataReg);
                stDMAChControlAlternateConstant.XFERSIZE = uxBufferCant - 1UL;
                uxBufferCant = 0UL;
                enErrorReg = (error_t) DMA_CH_Alternate__enSetSourceEndAddressByNumber(DMA_enMODULE_0, DMA_enCH_13, (UBase_t) &uxDataReg);
            }
            else
            {
                stDMAChControlPrimaryConstant.XFERMODE = (UBase_t) DMA_enCH_MODE_BASIC;
                stDMAChControlAlternateConstant.XFERMODE = (UBase_t) DMA_enCH_MODE_STOP;

                stDMAChControlPrimaryConstant.XFERSIZE = uxBufferCant - 1UL;
                uxBufferCant = 0UL;
                enErrorReg = (error_t) DMA_CH_Primary__enSetSourceEndAddressByNumber(DMA_enMODULE_0, DMA_enCH_13, (UBase_t) &uxDataReg);
                SSI2_ICR_R = (UBase_t) SSI_enINTMASK_END_OF_TRANSMIT;
                SSI2_IM_R |= (UBase_t) SSI_enINTMASK_END_OF_TRANSMIT;
            }
            ST7735__vSetTransferSizeLeft(uxBufferCant);
        }
        if(ERROR_OK == enErrorReg)
        {
            enErrorReg = (error_t) DMA_CH_Primary__enSetControlRegisterByNumber(DMA_enMODULE_0, DMA_enCH_13, &stDMAChControlPrimaryConstant);
        }
        if(ERROR_OK == enErrorReg)
        {
            enErrorReg = (error_t) DMA_CH_Alternate__enSetControlRegisterByNumber(DMA_enMODULE_0, DMA_enCH_13, &stDMAChControlAlternateConstant);
        }
        if(ERROR_OK == enErrorReg)
        {
            enErrorReg = (error_t) DMA_CH__enSetActiveControStructureByNumber(DMA_enMODULE_0, DMA_enCH_13, DMA_enCH_CONTROL_PRIMARY);
        }
        if(ERROR_OK == enErrorReg)
        {
            ST7735__vSetPrimaryTransferStruct(&stDMAChControlPrimaryConstant);
            ST7735__vSetAlternateTransferStruct(&stDMAChControlAlternateConstant);
            enErrorReg = (error_t) DMA_CH__enSetStateByNumber(DMA_enMODULE_0, DMA_enCH_13, DMA_enSTATE_ENA);
        }
        if(ERROR_OK == enErrorReg)
        {
            SSI__enClearInterruptSourceByMask(ST7735_SSI, (SSI_nINTMASK) (SSI_enINTMASK_TRANSMIT_DMA));
            SSI__enEnableInterruptSourceByMask(ST7735_SSI, (SSI_nINTMASK) (SSI_enINTMASK_TRANSMIT_DMA));
            SSI__enSetTransmitDMAState(ST7735_SSI, SSI_enSTATE_ENA);
        }
    }
    return (enErrorReg);
}

error_t ST7735__enWriteBuffer16bDMA(uint16_t* pu16DataArg, UBase_t uxBufferCant)
{
    error_t enErrorReg;

    enErrorReg = ERROR_OK;
    if(0UL == uxBufferCant)
    {
        enErrorReg = ERROR_VALUE;
    }
    if(ERROR_OK == enErrorReg)
    {
        if(0UL == (uintptr_t) pu16DataArg)
        {
            enErrorReg = ERROR_POINTER;
        }
    }
    if(ERROR_OK == enErrorReg)
    {
        OS_Semaphore__boTake(ST7735SemaphoreHandle, OS_ADAPT_MAX_DELAY);

        SSI__enSetState(ST7735_SSI, SSI_enSTATE_DIS);
        SSI__enSetDataLength(ST7735_SSI, SSI_enLENGTH_16BITS);
        SSI__enSetState(ST7735_SSI, SSI_enSTATE_ENA);
    }
    if(ERROR_OK == enErrorReg)
    {
        enErrorReg = ST7735__enEnableChipSelect();
    }
    if(ERROR_OK == enErrorReg)
    {
        enErrorReg = ST7735__enSetData();
    }
    if(ERROR_OK == enErrorReg)
    {
        if(uxBufferCant >= 2048UL)
        {
            stDMAChControlPrimaryBuffer.XFERMODE = (UBase_t) DMA_enCH_MODE_PING_PONG;
            stDMAChControlAlternateBuffer.XFERMODE = (UBase_t) DMA_enCH_MODE_PING_PONG;
            stDMAChControlPrimaryBuffer.XFERSIZE = 1024UL - 1UL;
            pu16DataArg += 1024UL;
            pu16DataArg -= 1UL;
            ST7735_uxDMATransferAddress = (UBase_t) pu16DataArg;
            uxBufferCant -= 1024UL;
            enErrorReg = (error_t) DMA_CH_Primary__enSetSourceEndAddressByNumber(DMA_enMODULE_0, DMA_enCH_13, ST7735_uxDMATransferAddress);
            stDMAChControlAlternateBuffer.XFERSIZE = 1024UL - 1UL;
            pu16DataArg += 1024UL;
            ST7735_uxDMATransferAddress = (UBase_t) pu16DataArg;
            uxBufferCant -= 1024UL;
            enErrorReg = (error_t) DMA_CH_Alternate__enSetSourceEndAddressByNumber(DMA_enMODULE_0, DMA_enCH_13, ST7735_uxDMATransferAddress);
        }
        else if(uxBufferCant > 1024UL)
        {
            stDMAChControlPrimaryBuffer.XFERMODE = (UBase_t) DMA_enCH_MODE_PING_PONG;
            stDMAChControlAlternateBuffer.XFERMODE = (UBase_t) DMA_enCH_MODE_BASIC;
            stDMAChControlPrimaryBuffer.XFERSIZE = 1024UL - 1UL;
            pu16DataArg += 1024UL;
            pu16DataArg -= 1UL;
            ST7735_uxDMATransferAddress = (UBase_t) pu16DataArg;
            uxBufferCant -= 1024UL;
            enErrorReg = (error_t) DMA_CH_Primary__enSetSourceEndAddressByNumber(DMA_enMODULE_0, DMA_enCH_13, ST7735_uxDMATransferAddress);
            stDMAChControlAlternateBuffer.XFERSIZE = uxBufferCant - 1UL;
            pu16DataArg += uxBufferCant;
            ST7735_uxDMATransferAddress = (UBase_t) pu16DataArg;
            uxBufferCant = 0UL;
            enErrorReg = (error_t) DMA_CH_Alternate__enSetSourceEndAddressByNumber(DMA_enMODULE_0, DMA_enCH_13, ST7735_uxDMATransferAddress);
        }
        else
        {
            stDMAChControlPrimaryBuffer.XFERMODE = (UBase_t) DMA_enCH_MODE_BASIC;
            stDMAChControlAlternateBuffer.XFERMODE = (UBase_t) DMA_enCH_MODE_STOP;

            stDMAChControlPrimaryBuffer.XFERSIZE = uxBufferCant - 1UL;
            pu16DataArg += uxBufferCant;
            pu16DataArg -= 1UL;
            ST7735_uxDMATransferAddress = (UBase_t) pu16DataArg;
            uxBufferCant = 0UL;
            enErrorReg = (error_t) DMA_CH_Primary__enSetSourceEndAddressByNumber(DMA_enMODULE_0, DMA_enCH_13, ST7735_uxDMATransferAddress);
            SSI2_ICR_R = (UBase_t) SSI_enINTMASK_END_OF_TRANSMIT;
            SSI2_IM_R |= (UBase_t) SSI_enINTMASK_END_OF_TRANSMIT;
        }
        ST7735__vSetTransferSizeLeft(uxBufferCant);
    }
    if(ERROR_OK == enErrorReg)
    {
        enErrorReg = (error_t) DMA_CH_Primary__enSetControlRegisterByNumber(DMA_enMODULE_0, DMA_enCH_13, &stDMAChControlPrimaryBuffer);
    }
    if(ERROR_OK == enErrorReg)
    {
        enErrorReg = (error_t) DMA_CH_Alternate__enSetControlRegisterByNumber(DMA_enMODULE_0, DMA_enCH_13, &stDMAChControlAlternateBuffer);
    }
    if(ERROR_OK == enErrorReg)
    {
        enErrorReg = (error_t) DMA_CH__enSetActiveControStructureByNumber(DMA_enMODULE_0, DMA_enCH_13, DMA_enCH_CONTROL_PRIMARY);
    }
    if(ERROR_OK == enErrorReg)
    {
        ST7735__vSetPrimaryTransferStruct(&stDMAChControlPrimaryBuffer);
        ST7735__vSetAlternateTransferStruct(&stDMAChControlAlternateBuffer);
        enErrorReg = (error_t) DMA_CH__enSetStateByNumber(DMA_enMODULE_0, DMA_enCH_13, DMA_enSTATE_ENA);
    }
    if(ERROR_OK == enErrorReg)
    {
        SSI__enClearInterruptSourceByMask(ST7735_SSI, (SSI_nINTMASK) (SSI_enINTMASK_TRANSMIT_DMA));
        SSI__enEnableInterruptSourceByMask(ST7735_SSI, (SSI_nINTMASK) (SSI_enINTMASK_TRANSMIT_DMA));
        SSI__enSetTransmitDMAState(ST7735_SSI, SSI_enSTATE_ENA);
    }
    return (enErrorReg);
}

void ST7735__vDMATxInterupt(uintptr_t uptrModuleArg, void* pvArgument)
{
    UBase_t uxMultiWord;
    UBase_t CurrentStructure;
    UBase_t ModePrimary;
    UBase_t ModeAlternate;
    UBase_t uxMulti;
    DMA_CH_CTL_t* pstDMAChannel;

    ModePrimary = DMA_CH_PRIMARY->CH[13UL].CTL_Bit.XFERMODE;
    ModeAlternate = DMA_CH_ALTERNATE->CH[13UL].CTL_Bit.XFERMODE;
    if(0UL != ST7735_uxDMATransferSizeLeft)
    {
        DMA->CH_ENASET = (UBase_t)  DMA_enSTATE_ENA << 13UL;
        SSI2_DMACTL_R |= SSI_DMACTL_R_TXDMAE_MASK;

        CurrentStructure = DMA_CH_ALTSET_R;
        CurrentStructure &= DMA_CH_ALTSET_R_SET13_MASK;
        if(DMA_CH_ALTSET_R_SET13_PRIM == CurrentStructure) /*fill alternate*/
        {
            pstDMAChannel = ST7735__pstGetAlternateTransferStruct();
        }
        else
        {
            pstDMAChannel = ST7735__pstGetPrimaryTransferStruct();
        }

        uxMulti = pstDMAChannel->SRCINC;
        uxMulti += 1UL;
        uxMulti &= 0x3UL;
        if((UBase_t) 3 == uxMulti)
        {
            uxMulti = 4UL;
        }

        if(ST7735_uxDMATransferSizeLeft > 1024UL)
        {
            pstDMAChannel->XFERMODE = (UBase_t) DMA_enCH_MODE_PING_PONG;
            pstDMAChannel->XFERSIZE = 1024UL - 1UL;
            uxMultiWord = (1024UL);
            uxMultiWord *= uxMulti;
            ST7735_uxDMATransferAddress += uxMultiWord;
            ST7735_uxDMATransferSizeLeft -= 1024UL;
        }
        else
        {
            pstDMAChannel->XFERMODE = (UBase_t) DMA_enCH_MODE_BASIC;
            pstDMAChannel->XFERSIZE = ST7735_uxDMATransferSizeLeft - 1UL;
            uxMultiWord = (ST7735_uxDMATransferSizeLeft);
            uxMultiWord *= uxMulti;
            ST7735_uxDMATransferAddress += uxMultiWord;
            ST7735_uxDMATransferSizeLeft = 0UL;
        }

        if(DMA_CH_ALTSET_R_SET13_PRIM == CurrentStructure) /*fill alternate*/
        {
            DMA_CH_ALTERNATE->CH[13UL].SRCENDP = (UBase_t) ST7735_uxDMATransferAddress;
            DMA_CH_ALTERNATE->CH[13UL].CTL = *((volatile UBase_t*) pstDMAChannel);
        }
        else
        {
            DMA_CH_PRIMARY->CH[13UL].SRCENDP = (UBase_t) ST7735_uxDMATransferAddress;
            DMA_CH_PRIMARY->CH[13UL].CTL = *((volatile UBase_t*) pstDMAChannel);
        }
    }
    else if((0UL != ModePrimary) || (0UL != ModeAlternate))
    {
        DMA->CH_ENASET = (UBase_t)  DMA_enSTATE_ENA << 13UL;
        SSI2_DMACTL_R |= SSI_DMACTL_R_TXDMAE_MASK;
        SSI2_ICR_R = (UBase_t) SSI_enINTMASK_END_OF_TRANSMIT;
        SSI2_IM_R |= (UBase_t) SSI_enINTMASK_END_OF_TRANSMIT;
    }
    else
    {
        SSI2_IM_R &= ~ (UBase_t) SSI_enINTMASK_TRANSMIT_DMA;
    }
}

void ST7735__vDMATxLastBit(uintptr_t uptrModuleArg, void* pvArgument)
{
    OS_Boolean_t boHigherPriorityTaskWoken = FALSE;
    SSI2_IM_R &= ~ (UBase_t) SSI_enINTMASK_END_OF_TRANSMIT;
    ST7735__enDisableChipSelect();

    SSI2_CR1->SSE = (UBase_t) SSI_enSTATE_DIS;
    SSI2_CR0->DSS = (UBase_t) SSI_enLENGTH_8BITS;
    SSI2_CR1->SSE = (UBase_t) SSI_enSTATE_ENA;
    OS_Semaphore__boGiveFromISR(ST7735SemaphoreHandle, &boHigherPriorityTaskWoken);
    OS_Adapt__vYieldFromISR(boHigherPriorityTaskWoken);
}