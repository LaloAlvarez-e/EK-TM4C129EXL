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

SSI_nERROR SSI__enSetConfig(SSI_nMODULE enModule,
                             SSI_nMS enMasterSlaveArg ,
                             const SSI_CONTROL_t* const pstControlConfig,
                             SSI_FRAME_CONTROL_t* const pstFrameControlConfig,
                             UBase_t uxClockArg, const SSI_LINE_t* pstLineConfig)
{
    SSI_nERROR enReturn = SSI_enERROR_POINTER;
    SSI_nSTATE enEnableModule = SSI_enSTATE_DIS;
    SSI_nMODULE enModuleFilter = SSI_enMODULE_0;
    SSI_nBUSY enBusyModule = SSI_enBUSY_IDLE;
    SSI_nSTATE enFssHoldReg = SSI_enSTATE_DIS;
    SSI_nDIRECTION enDirectionReg = SSI_enDIRECTION_TX;
    UBase_t uxLine[MAX_LINE] = {0UL};

    if((0UL != (UBase_t) pstControlConfig) &&
       (0UL != (UBase_t) pstFrameControlConfig) &&
       (0UL != (UBase_t) pstLineConfig))
    {
        enDirectionReg = pstControlConfig->enDirection;
        enFssHoldReg = pstControlConfig->enFssHold;
        enModuleFilter = (SSI_nMODULE) MCU__uxCheckParams((UBase_t) enModule,
                                                           (UBase_t) SSI_enMODULE_MAX);
        enEnableModule = SSI__enGetEnable(enModuleFilter);
        if(SSI_enSTATE_ENA == enEnableModule)
        {
            SSI__vSetEnable(enModuleFilter, SSI_enSTATE_DIS);
            do
            {
                enBusyModule = SSI__enGetBusyState(enModuleFilter);
            }while (SSI_enBUSY_IDLE != enBusyModule);
        }
        uxLine[TX_LINE] = MCU__uxCheckParams((UBase_t) pstLineConfig->enTx, MAX_CONFIG);
        uxLine[RX_LINE] = MCU__uxCheckParams((UBase_t) pstLineConfig->enRx, MAX_CONFIG);
        uxLine[DAT2_LINE] = MCU__uxCheckParams((UBase_t) pstLineConfig->enDat2, MAX_CONFIG);
        uxLine[DAT3_LINE] = MCU__uxCheckParams((UBase_t) pstLineConfig->enDat3, MAX_CONFIG);
        uxLine[CLK_LINE] = MCU__uxCheckParams((UBase_t) pstLineConfig->enClk, MAX_CONFIG);
        uxLine[FSS_LINE] = MCU__uxCheckParams((UBase_t) pstLineConfig->enFss, MAX_CONFIG);

        if(SSI_enSTATE_ENA == pstControlConfig->enFssLine)
        {
            if(SSI_enMS_MASTER == enMasterSlaveArg)
            {
                GPIO__enSetDigitalConfig(SSI_enGpioInput[uxLine[FSS_LINE]]
                                                        [(UBase_t) enModuleFilter]
                                                        [FSS_LINE],
                                         GPIO_enCONFIG_OUTPUT_2MA_PUSHPULL);
            }
            else
            {
                GPIO__enSetDigitalConfig(SSI_enGpioInput[uxLine[FSS_LINE]]
                                                        [(UBase_t) enModuleFilter]
                                                        [FSS_LINE],
                                         GPIO_enCONFIG_INPUT_2MA_OPENDRAIN_PULLUP);
            }
        }
        if(SSI_enSTATE_ENA == pstControlConfig->enClkLine)
        {
            if(SSI_enMS_MASTER == enMasterSlaveArg)
            {
                GPIO__enSetDigitalConfig(SSI_enGpioInput[uxLine[CLK_LINE]]
                                                        [(UBase_t) enModuleFilter]
                                                        [CLK_LINE],
                                         GPIO_enCONFIG_OUTPUT_2MA_PUSHPULL_PULLUP);
            }
            else
            {
                GPIO__enSetDigitalConfig(SSI_enGpioInput[uxLine[CLK_LINE]]
                                                        [(UBase_t) enModuleFilter]
                                                        [CLK_LINE],
                                         GPIO_enCONFIG_INPUT_2MA_OPENDRAIN_PULLUP);
            }
        }

        if(SSI_enMODE_LEGACY != pstControlConfig->enSSIMode)
        {
            pstFrameControlConfig->enClockPhase = SSI_enPHASE_FIRST;
            pstFrameControlConfig->enClockPolarity = SSI_enPOLARITY_LOW;
            pstFrameControlConfig->enLengthData = SSI_enLENGTH_8BITS;
            pstFrameControlConfig->enFormat = SSI_enFORMAT_FREESCALE;

            switch(enDirectionReg)
            {
            case SSI_enDIRECTION_TX:
                switch (pstControlConfig->enSSIMode)
                {
                case SSI_enMODE_BI:
                    if(SSI_enSTATE_ENA == pstControlConfig->enTxLine)
                    {
                        GPIO__enSetDigitalConfig(SSI_enGpioInput[uxLine[TX_LINE]]
                                                                [(UBase_t) enModuleFilter]
                                                                [TX_LINE],
                                                 GPIO_enCONFIG_OUTPUT_2MA_PUSHPULL_PULLUP);
                    }
                    if(SSI_enSTATE_ENA == pstControlConfig->enRxLine)
                    {
                        GPIO__enSetDigitalConfig(SSI_enGpioInput[uxLine[RX_LINE]]
                                                                [(UBase_t) enModuleFilter]
                                                                [RX_LINE],
                                                 GPIO_enCONFIG_OUTPUT_2MA_PUSHPULL_PULLUP);
                    }
                    break;
                case SSI_enMODE_QUAD:
                    if(SSI_enSTATE_ENA == pstControlConfig->enTxLine)
                    {
                        GPIO__enSetDigitalConfig(SSI_enGpioInput[uxLine[TX_LINE]]
                                                                [(UBase_t) enModuleFilter]
                                                                [TX_LINE],
                                                 GPIO_enCONFIG_OUTPUT_2MA_PUSHPULL_PULLUP);
                    }
                    if(SSI_enSTATE_ENA == pstControlConfig->enRxLine)
                    {
                        GPIO__enSetDigitalConfig(SSI_enGpioInput[uxLine[RX_LINE]]
                                                                [(UBase_t) enModuleFilter]
                                                                [RX_LINE],
                                                 GPIO_enCONFIG_OUTPUT_2MA_PUSHPULL_PULLUP);
                    }
                    if(SSI_enSTATE_ENA == pstControlConfig->enDat2Line)
                    {
                        GPIO__enSetDigitalConfig(SSI_enGpioInput[uxLine[DAT2_LINE]]
                                                                [(UBase_t) enModuleFilter]
                                                                [DAT2_LINE],
                                                 GPIO_enCONFIG_OUTPUT_2MA_PUSHPULL_PULLUP);
                    }
                    if(SSI_enSTATE_ENA == pstControlConfig->enDat3Line)
                    {
                        GPIO__enSetDigitalConfig(SSI_enGpioInput[uxLine[DAT3_LINE]]
                                                                [(UBase_t) enModuleFilter]
                                                                [DAT3_LINE],
                                                 GPIO_enCONFIG_OUTPUT_2MA_PUSHPULL_PULLUP);
                    }
                    break;
                case SSI_enMODE_ADVANCED:
                    if(SSI_enSTATE_ENA == pstControlConfig->enTxLine)
                    {
                        GPIO__enSetDigitalConfig(SSI_enGpioInput[uxLine[TX_LINE]]
                                                                [(UBase_t) enModuleFilter]
                                                                [TX_LINE],
                                                 GPIO_enCONFIG_OUTPUT_2MA_PUSHPULL);
                    }
                    break;
                default:
                    break;
                }
                break;
            case SSI_enDIRECTION_RX:
                switch (pstControlConfig->enSSIMode)
                {
                case SSI_enMODE_BI:

                    if(SSI_enSTATE_ENA == pstControlConfig->enTxLine)
                    {
                        GPIO__enSetDigitalConfig(SSI_enGpioInput[uxLine[TX_LINE]]
                                                                [(UBase_t) enModuleFilter]
                                                                [TX_LINE],
                                                 GPIO_enCONFIG_INPUT_2MA_OPENDRAIN_PULLUP);
                    }
                    if(SSI_enSTATE_ENA == pstControlConfig->enRxLine)
                    {
                        GPIO__enSetDigitalConfig(SSI_enGpioInput[uxLine[RX_LINE]]
                                                                [(UBase_t) enModuleFilter]
                                                                [RX_LINE],
                                                 GPIO_enCONFIG_INPUT_2MA_OPENDRAIN_PULLUP);
                    }
                    break;
                case SSI_enMODE_QUAD:
                    if(SSI_enSTATE_ENA == pstControlConfig->enTxLine)
                    {
                        GPIO__enSetDigitalConfig(SSI_enGpioInput[uxLine[TX_LINE]]
                                                                [(UBase_t) enModuleFilter]
                                                                [TX_LINE],
                                                 GPIO_enCONFIG_INPUT_2MA_OPENDRAIN_PULLUP);
                    }
                    if(SSI_enSTATE_ENA == pstControlConfig->enRxLine)
                    {
                        GPIO__enSetDigitalConfig(SSI_enGpioInput[uxLine[RX_LINE]]
                                                                [(UBase_t) enModuleFilter]
                                                                [RX_LINE],
                                                 GPIO_enCONFIG_INPUT_2MA_OPENDRAIN_PULLUP);
                    }
                    if(SSI_enSTATE_ENA == pstControlConfig->enDat2Line)
                    {
                        GPIO__enSetDigitalConfig(SSI_enGpioInput[uxLine[DAT2_LINE]]
                                                                [(UBase_t) enModuleFilter]
                                                                [DAT2_LINE],
                                                 GPIO_enCONFIG_INPUT_2MA_OPENDRAIN_PULLUP);
                    }
                    if(SSI_enSTATE_ENA == pstControlConfig->enDat3Line)
                    {
                        GPIO__enSetDigitalConfig(SSI_enGpioInput[uxLine[DAT3_LINE]]
                                                                [(UBase_t) enModuleFilter]
                                                                [DAT3_LINE],
                                                 GPIO_enCONFIG_INPUT_2MA_OPENDRAIN_PULLUP);
                    }
                    break;
                case SSI_enMODE_ADVANCED:
                    if(SSI_enSTATE_ENA == pstControlConfig->enRxLine)
                    {
                        GPIO__enSetDigitalConfig(SSI_enGpioInput[uxLine[RX_LINE]]
                                                                [(UBase_t) enModuleFilter]
                                                                [RX_LINE],
                                                 GPIO_enCONFIG_INPUT_2MA_OPENDRAIN_PULLUP);
                    }
                    if(SSI_enSTATE_ENA == pstControlConfig->enTxLine)
                    {
                        GPIO__enSetDigitalConfig(SSI_enGpioInput[uxLine[TX_LINE]]
                                                                [(UBase_t) enModuleFilter]
                                                                [TX_LINE],
                                                 GPIO_enCONFIG_OUTPUT_2MA_PUSHPULL);
                    }
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
        }
        else
        {
            enDirectionReg = SSI_enDIRECTION_TX;
            if(SSI_enLENGTH_8BITS != pstFrameControlConfig->enLengthData)
            {
                enFssHoldReg = SSI_enSTATE_DIS;
            }

            if(SSI_enSTATE_ENA == pstControlConfig->enRxLine)
            {
                GPIO__enSetDigitalConfig(SSI_enGpioInput[uxLine[RX_LINE]]
                                                        [(UBase_t) enModuleFilter]
                                                        [RX_LINE],
                                         GPIO_enCONFIG_INPUT_2MA_OPENDRAIN_PULLUP);
            }
            if(SSI_enSTATE_ENA == pstControlConfig->enTxLine)
            {
                GPIO__enSetDigitalConfig(SSI_enGpioInput[uxLine[TX_LINE]]
                                                        [(UBase_t) enModuleFilter]
                                                        [TX_LINE],
                                         GPIO_enCONFIG_OUTPUT_2MA_PUSHPULL);
            }
        }

        SSI__vSetClockAndFormatControlStructPointer(enModuleFilter,
                                                    pstFrameControlConfig,
                                                    uxClockArg);

        SSI__vSetFssHold(enModuleFilter, enFssHoldReg);
        SSI__vSetDirection(enModuleFilter, enDirectionReg);
        SSI__vSetMode(enModuleFilter, pstControlConfig->enSSIMode);
        SSI__vSetEndTransmission(enModuleFilter, pstControlConfig->enEndOfTransmission);
        SSI__vSetMasterSlave(enModuleFilter, enMasterSlaveArg);
        SSI__vSetLoopback(enModuleFilter, pstControlConfig->enLoopback);


        if(SSI_enSTATE_ENA == enEnableModule)
        {
            SSI__vSetEnable(enModuleFilter, SSI_enSTATE_ENA);
        }
        enReturn = SSI_enERROR_OK;
    }
    return (enReturn);
}
