/**
 *
 * @file SSI_Config.c
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
 * @verbatim 11 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 11 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/SSI/xHeader/SSI_Config.h>

#include <xApplication_MCU/SSI/xHeader/SSI_FrameControl.h>
#include <xApplication_MCU/SSI/Intrinsics/xHeader/SSI_Dependencies.h>

#define TX_LINE (0UL)
#define RX_LINE (1UL)
#define DAT2_LINE (2UL)
#define DAT3_LINE (3UL)
#define CLK_LINE (4UL)
#define FSS_LINE (5UL)
#define MAX_LINE (6UL)

#define MAX_CONFIG (2UL)

GPIO_nDIGITAL_FUNCTION SSI_enGpioInput[MAX_CONFIG]
                                      [(UBase_t) SSI_enMODULE_MAX]
                                      [(UBase_t) MAX_LINE] =
{
    {
        {
         GPIO_enSSI0Tx_A4, GPIO_enSSI0Rx_A5,
         GPIO_enSSI0XDAT2_A6, GPIO_enSSI0XDAT3_A7,
         GPIO_enSSI0Clk_A2, GPIO_enSSI0Fss_A3
        },
        {
         GPIO_enSSI1Tx_E4, GPIO_enSSI1Rx_E5,
         GPIO_enSSI1XDAT2_D4, GPIO_enSSI1XDAT3_D5,
         GPIO_enSSI1Clk_B5, GPIO_enSSI1Fss_B4
        },
        {
         GPIO_enSSI2Tx_D1, GPIO_enSSI2Rx_D0,
         GPIO_enSSI2XDAT2_D7, GPIO_enSSI2XDAT3_D6,
         GPIO_enSSI2Clk_D3, GPIO_enSSI2Fss_D2
        },
        {
         GPIO_enSSI3Tx_F1, GPIO_enSSI3Rx_F0,
         GPIO_enSSI3XDAT2_F4, GPIO_enSSI3XDAT3_P1,
         GPIO_enSSI3Clk_F3, GPIO_enSSI3Fss_F2
        },
    },
    {
        {
         GPIO_enSSI0Tx_A4, GPIO_enSSI0Rx_A5,
         GPIO_enSSI0XDAT2_A6, GPIO_enSSI0XDAT3_A7,
         GPIO_enSSI0Clk_A2, GPIO_enSSI0Fss_A3
        },
        {
         GPIO_enSSI1Tx_E4, GPIO_enSSI1Rx_E5,
         GPIO_enSSI1XDAT2_D4, GPIO_enSSI1XDAT3_D5,
         GPIO_enSSI1Clk_B5, GPIO_enSSI1Fss_B4
        },
        {
         GPIO_enSSI2Tx_D1, GPIO_enSSI2Rx_D0,
         GPIO_enSSI2XDAT2_D7, GPIO_enSSI2XDAT3_D6,
         GPIO_enSSI2Clk_D3, GPIO_enSSI2Fss_D2
        },
        {
         GPIO_enSSI3Tx_Q2, GPIO_enSSI3Rx_Q3,
         GPIO_enSSI3XDAT2_P0, GPIO_enSSI3XDAT3_P1,
         GPIO_enSSI3Clk_Q0, GPIO_enSSI3Fss_Q1
        },
    },
 };

SSI_nERROR SSI__enSetConfig(SSI_nMODULE enModuleArg,
                             SSI_nOPERATION enMasterSlaveArg,
                             UBase_t uxClockArg,
                             const SSI_CONTROL_t* const pstControlConfigArg,
                             SSI_FRAME_CONTROL_t* const pstFrameControlConfigArg,
                             const SSI_LINE_t* pstLineConfigArg)
{
    SSI_nSTATE enEnableModule = SSI_enSTATE_DIS;
    SSI_nSTATE enFssHoldReg = SSI_enSTATE_DIS;
    SSI_nDIRECTION enDirectionReg = SSI_enDIRECTION_TX;

    GPIO_nCONFIG enGpioConfigRx;
    GPIO_nCONFIG enGpioConfigTx;
    GPIO_nCONFIG enGpioConfigDat2;
    GPIO_nCONFIG enGpioConfigDat3;
    SSI_nERROR enErrorReg;

    enGpioConfigTx = GPIO_enCONFIG_UNDEF;
    enGpioConfigRx = GPIO_enCONFIG_UNDEF;
    enGpioConfigDat2 = GPIO_enCONFIG_UNDEF;
    enGpioConfigDat3 = GPIO_enCONFIG_UNDEF;
    enErrorReg = SSI_enERROR_OK;
    if((0UL == (uintptr_t) pstControlConfigArg) || (0UL == (uintptr_t) pstFrameControlConfigArg) || (0UL == (uintptr_t) pstLineConfigArg))
    {
        enErrorReg = SSI_enERROR_POINTER;
    }
    if(SSI_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SSI_nERROR) MCU__enCheckParams((UBase_t) pstLineConfigArg->enTx, MAX_CONFIG);
    }
    if(SSI_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SSI_nERROR) MCU__enCheckParams((UBase_t) pstLineConfigArg->enRx, MAX_CONFIG);
    }
    if(SSI_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SSI_nERROR) MCU__enCheckParams((UBase_t) pstLineConfigArg->enDat2, MAX_CONFIG);
    }
    if(SSI_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SSI_nERROR) MCU__enCheckParams((UBase_t) pstLineConfigArg->enDat3, MAX_CONFIG);
    }
    if(SSI_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SSI_nERROR) MCU__enCheckParams((UBase_t) pstLineConfigArg->enClk, MAX_CONFIG);
    }
    if(SSI_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SSI_nERROR) MCU__enCheckParams((UBase_t) pstLineConfigArg->enFss, MAX_CONFIG);
    }
    if(SSI_enERROR_OK == enErrorReg)
    {
        enErrorReg = SSI__enGetState(enModuleArg, &enEnableModule);
    }
    if(SSI_enERROR_OK == enErrorReg)
    {
        SSI_nBOOLEAN enIsBusyModule;
        UBase_t uxTimeout = 10000000UL;
        if(SSI_enSTATE_ENA == enEnableModule)
        {
            enIsBusyModule = SSI_enFALSE;
            do
            {
                enErrorReg = SSI__enIsBusy(enModuleArg, &enIsBusyModule);
                uxTimeout--;
            }while ((SSI_enFALSE != enIsBusyModule) &&
                    (SSI_enERROR_OK == enErrorReg) &&
                    (0UL != uxTimeout));

            if(SSI_enERROR_OK == enErrorReg)
            {
                if(0UL == uxTimeout)
                {
                    enErrorReg = SSI_enERROR_TIMEOUT;
                }
            }
            if(SSI_enERROR_OK == enErrorReg)
            {
                enErrorReg = SSI__enSetState(enModuleArg, SSI_enSTATE_DIS);
            }
        }
    }
    if(SSI_enERROR_OK == enErrorReg)
    {
        if(SSI_enSTATE_ENA == pstControlConfigArg->enFssLine)
        {
            GPIO_nCONFIG enGpioConfigFss;
            if(SSI_enOPERATION_MASTER == enMasterSlaveArg)
            {
                enGpioConfigFss = GPIO_enCONFIG_OUTPUT_12MA_PUSHPULL;
            }
            else
            {
                enGpioConfigFss = GPIO_enCONFIG_INPUT_12MA_PUSHPULL_PULLUP;
            }
            enErrorReg = (SSI_nERROR) GPIO__enSetDigitalConfig(SSI_enGpioInput[(UBase_t) pstLineConfigArg->enFss][(UBase_t) enModuleArg][FSS_LINE],
                                                               enGpioConfigFss);
        }
    }
    if(SSI_enERROR_OK == enErrorReg)
    {
        if(SSI_enSTATE_ENA == pstControlConfigArg->enClkLine)
        {
            GPIO_nCONFIG enGpioConfigClk;
            if(SSI_enOPERATION_MASTER == enMasterSlaveArg)
            {
                enGpioConfigClk = GPIO_enCONFIG_OUTPUT_12MA_PUSHPULL_PULLUP;
            }
            else
            {
                enGpioConfigClk = GPIO_enCONFIG_INPUT_12MA_PUSHPULL_PULLUP;
            }
            enErrorReg = (SSI_nERROR) GPIO__enSetDigitalConfig(SSI_enGpioInput[(UBase_t) pstLineConfigArg->enClk][(UBase_t) enModuleArg][CLK_LINE],
                                                               enGpioConfigClk);
        }
    }
    if(SSI_enERROR_OK == enErrorReg)
    {
        enFssHoldReg = pstControlConfigArg->enFssHold;
        if(SSI_enMODE_LEGACY != pstControlConfigArg->enSSIMode)
        {
            enDirectionReg = pstControlConfigArg->enDirection;
            pstFrameControlConfigArg->enClockPhase = SSI_enPHASE_FIRST;
            pstFrameControlConfigArg->enClockPolarity = SSI_enPOLARITY_LOW;
            pstFrameControlConfigArg->enLengthData = SSI_enLENGTH_8BITS;
            pstFrameControlConfigArg->enFormat = SSI_enFORMAT_FREESCALE;

            if(SSI_enDIRECTION_TX == enDirectionReg)
            {
                enGpioConfigTx = GPIO_enCONFIG_OUTPUT_12MA_PUSHPULL_PULLUP;
                enGpioConfigRx = GPIO_enCONFIG_OUTPUT_12MA_PUSHPULL_PULLUP;
                enGpioConfigDat2 = GPIO_enCONFIG_OUTPUT_12MA_PUSHPULL_PULLUP;
                enGpioConfigDat3 = GPIO_enCONFIG_OUTPUT_12MA_PUSHPULL_PULLUP;
            }
            if(SSI_enDIRECTION_RX == enDirectionReg)
            {
                enGpioConfigRx = GPIO_enCONFIG_INPUT_12MA_PUSHPULL_PULLUP;
                enGpioConfigDat2 = GPIO_enCONFIG_INPUT_12MA_PUSHPULL_PULLUP;
                enGpioConfigDat3 = GPIO_enCONFIG_INPUT_12MA_PUSHPULL_PULLUP;
                if(SSI_enMODE_ADVANCED == pstControlConfigArg->enSSIMode)
                {
                    enGpioConfigTx = GPIO_enCONFIG_OUTPUT_12MA_PUSHPULL_PULLUP;
                }
                else
                {
                    enGpioConfigTx = GPIO_enCONFIG_INPUT_12MA_PUSHPULL_PULLUP;
                }
            }
        }
        else
        {
            enDirectionReg = SSI_enDIRECTION_TX;
            if(SSI_enLENGTH_8BITS != pstFrameControlConfigArg->enLengthData)
            {
                enFssHoldReg = SSI_enSTATE_DIS;
            }
            enGpioConfigTx = GPIO_enCONFIG_OUTPUT_12MA_PUSHPULL_PULLUP;
            enGpioConfigRx = GPIO_enCONFIG_INPUT_12MA_PUSHPULL_PULLUP;
        }
    }
    if(SSI_enERROR_OK == enErrorReg)
    {
        if(SSI_enSTATE_ENA == pstControlConfigArg->enTxLine)
        {
            enErrorReg = (SSI_nERROR) GPIO__enSetDigitalConfig(SSI_enGpioInput[(UBase_t) pstLineConfigArg->enTx][(UBase_t) enModuleArg][TX_LINE],
                                                  enGpioConfigTx);
        }
    }
    if(SSI_enERROR_OK == enErrorReg)
    {
        if((SSI_enMODE_ADVANCED != pstControlConfigArg->enSSIMode) ||
           (SSI_enDIRECTION_TX != enDirectionReg))
        {
            if(SSI_enSTATE_ENA == pstControlConfigArg->enRxLine)
            {
                enErrorReg = (SSI_nERROR) GPIO__enSetDigitalConfig(SSI_enGpioInput[(UBase_t) pstLineConfigArg->enRx][(UBase_t) enModuleArg][RX_LINE],
                                                      enGpioConfigRx);
            }
        }
    }
    if(SSI_enERROR_OK == enErrorReg)
    {
        if((SSI_enMODE_LEGACY != pstControlConfigArg->enSSIMode) && (SSI_enMODE_QUAD == pstControlConfigArg->enSSIMode))
        {
            if(SSI_enSTATE_ENA == pstControlConfigArg->enDat2Line)
            {
                enErrorReg = (SSI_nERROR) GPIO__enSetDigitalConfig(SSI_enGpioInput[(UBase_t) pstLineConfigArg->enDat2][(UBase_t) enModuleArg][DAT2_LINE],
                                                      enGpioConfigDat2);
            }
            if(SSI_enERROR_OK == enErrorReg)
            {
                if(SSI_enSTATE_ENA == pstControlConfigArg->enDat3Line)
                {
                    enErrorReg = (SSI_nERROR) GPIO__enSetDigitalConfig(SSI_enGpioInput[(UBase_t) pstLineConfigArg->enDat3][(UBase_t) enModuleArg][DAT3_LINE],
                                                          enGpioConfigDat3);
                }
            }
        }
    }
    if(SSI_enERROR_OK == enErrorReg)
    {
        enErrorReg = SSI__enSetClockAndFormatControlStructure(enModuleArg, pstFrameControlConfigArg, uxClockArg);
    }
    if(SSI_enERROR_OK == enErrorReg)
    {
        enErrorReg = SSI__enSetChipSelectHoldState(enModuleArg, enFssHoldReg);
    }
    if(SSI_enERROR_OK == enErrorReg)
    {
        enErrorReg = SSI__enSetDirection(enModuleArg, enDirectionReg);
    }
    if(SSI_enERROR_OK == enErrorReg)
    {
        enErrorReg = SSI__enSetMode(enModuleArg, pstControlConfigArg->enSSIMode);
    }
    if(SSI_enERROR_OK == enErrorReg)
    {
        enErrorReg = SSI__enSetOperation(enModuleArg, enMasterSlaveArg);
    }
    if(SSI_enERROR_OK == enErrorReg)
    {
        enErrorReg = SSI__enSetLoopbackState(enModuleArg, pstControlConfigArg->enLoopback);
    }
    if(SSI_enERROR_OK == enErrorReg)
    {
        if(SSI_enSTATE_ENA == enEnableModule)
        {
            enErrorReg = SSI__enSetState(enModuleArg, SSI_enSTATE_ENA);
        }
    }
    return (enErrorReg);
}
