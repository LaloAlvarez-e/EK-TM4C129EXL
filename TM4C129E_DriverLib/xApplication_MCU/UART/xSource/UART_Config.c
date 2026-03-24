/**
 *
 * @file UART_Config.c
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
 * @verbatim 13 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 13 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/UART/xHeader/UART_Config.h>

#include <xApplication_MCU/UART/LineControl/UART_LineControl.h>
#include <xApplication_MCU/UART/xHeader/UART_IrDA.h>
#include <xApplication_MCU/UART/Intrinsics/xHeader/UART_Dependencies.h>

#define RX_LINE (0UL)
#define TX_LINE (1UL)
#define CTS_LINE (2UL)
#define RTS_LINE (3UL)
#define DCD_LINE (4UL)
#define DSR_LINE (5UL)
#define DTR_LINE (6UL)
#define RI_LINE (7UL)
#define MAX_LINE (8UL)

#define MAX_CONFIG (3UL)

const GPIO_nDIGITAL_FUNCTION UART_enGpioInput[MAX_CONFIG] [(UBase_t) UART_enMODULE_MAX]
                                                     [(UBase_t) MAX_LINE] =
{
    {
        {GPIO_enU0Rx_A0, GPIO_enU0Tx_A1, GPIO_enU0CTS_B4, GPIO_enU0RTS_B5,
         GPIO_enU0DCD_H2, GPIO_enU0DSR_H3, GPIO_enU0DTR_P2, GPIO_enU0RI_K7},

        {GPIO_enU1Rx_B0, GPIO_enU1Tx_B1, GPIO_enU1CTS_N1, GPIO_enU1RTS_E0,
         GPIO_enU1DCD_E2, GPIO_enU1DSR_E1, GPIO_enU1DTR_E3, GPIO_enU1RI_E4},

        {GPIO_enU2Rx_A6, GPIO_enU2Tx_A7, GPIO_enU2CTS_D7, GPIO_enU2RTS_D6,
         GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF},

        {GPIO_enU3Rx_A4, GPIO_enU3Tx_A5, GPIO_enU3CTS_N5, GPIO_enU3RTS_N4,
         GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF},

        {GPIO_enU4Rx_A2, GPIO_enU4Tx_A3, GPIO_enU4CTS_K3, GPIO_enU4RTS_K2,
         GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF},

        {GPIO_enU5Rx_C6, GPIO_enU5Tx_C7, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF,
         GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF},

        {GPIO_enU6Rx_P0, GPIO_enU6Tx_P1, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF,
         GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF},

        {GPIO_enU7Rx_C4, GPIO_enU7Tx_C5, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF,
         GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF},
    },
    {
        {GPIO_enU0Rx_A0, GPIO_enU0Tx_A1, GPIO_enU0CTS_H1, GPIO_enU0RTS_H0,
         GPIO_enU0DCD_M5, GPIO_enU0DSR_M6, GPIO_enU0DTR_P2, GPIO_enU0RI_M7},

        {GPIO_enU1Rx_Q4, GPIO_enU1Tx_B1, GPIO_enU1CTS_P3, GPIO_enU1RTS_N0,
         GPIO_enU1DCD_N2, GPIO_enU1DSR_N3, GPIO_enU1DTR_N4, GPIO_enU1RI_N5},

        {GPIO_enU2Rx_D4, GPIO_enU2Tx_D5, GPIO_enU2CTS_N3, GPIO_enU2RTS_N2,
         GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF},

        {GPIO_enU3Rx_J0, GPIO_enU3Tx_J1, GPIO_enU3CTS_P5, GPIO_enU3RTS_P4,
         GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF},

        {GPIO_enU4Rx_K0, GPIO_enU4Tx_K1, GPIO_enU4CTS_K3, GPIO_enU4RTS_K2,
         GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF},

        {GPIO_enU5Rx_C6, GPIO_enU5Tx_C7, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF,
         GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF},

        {GPIO_enU6Rx_P0, GPIO_enU6Tx_P1, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF,
         GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF},

        {GPIO_enU7Rx_C4, GPIO_enU7Tx_C5, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF,
         GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF},
    },
    {
        {GPIO_enU0Rx_A0, GPIO_enU0Tx_A1, GPIO_enU0CTS_M4, GPIO_enU0RTS_H0,
         GPIO_enU0DCD_P3, GPIO_enU0DSR_P4, GPIO_enU0DTR_P2, GPIO_enU0RI_M7},

        {GPIO_enU1Rx_Q4, GPIO_enU1Tx_B1, GPIO_enU1CTS_P3, GPIO_enU1RTS_N0,
         GPIO_enU1DCD_N2, GPIO_enU1DSR_N3, GPIO_enU1DTR_N4, GPIO_enU1RI_N5},

        {GPIO_enU2Rx_D4, GPIO_enU2Tx_D5, GPIO_enU2CTS_N3, GPIO_enU2RTS_N2,
         GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF},

        {GPIO_enU3Rx_J0, GPIO_enU3Tx_J1, GPIO_enU3CTS_P5, GPIO_enU3RTS_P4,
         GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF},

        {GPIO_enU4Rx_K0, GPIO_enU4Tx_K1, GPIO_enU4CTS_K3, GPIO_enU4RTS_K2,
         GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF},

        {GPIO_enU5Rx_C6, GPIO_enU5Tx_C7, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF,
         GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF},

        {GPIO_enU6Rx_P0, GPIO_enU6Tx_P1, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF,
         GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF},

        {GPIO_enU7Rx_C4, GPIO_enU7Tx_C5, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF,
         GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF, GPIO_enGPIO_UNDEF},
    },
 };

UART_nERROR UART__enSetConfig(UART_nMODULE enModuleArg,
                              UART_nMODE enModeArg,
                              UBase_t uxBaudRateArg,
                              UBase_t uxOwnAddressArg,
                              UBase_t uxOwnAddressMaskArg,
                              const UART_CONTROL_t* pstControlConfigArg,
                              const UART_LINE_CONTROL_t* pstLineControlConfigArg,
                              const UART_LINE_t* pstLineConfigArg,
                              UBase_t uxTimeoutArg)
{
    UART_nERROR enErrorReg;
    UART_nBOOLEAN enIsBusyReg;
    UART_LINE_CONTROL_t stLineControlConfig;

    enErrorReg = UART_enERROR_OK;
    if((0UL == (uintptr_t) pstControlConfigArg) ||
       (0UL == (uintptr_t) pstLineControlConfigArg)  ||
       (0UL == (uintptr_t) pstLineConfigArg))
    {
        enErrorReg = UART_enERROR_POINTER;
    }
    if(0UL == uxBaudRateArg)
    {
        enErrorReg = UART_enERROR_VALUE;
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        enErrorReg = (UART_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) UART_enMODULE_MAX);
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        enErrorReg = UART__enSetState(enModuleArg, UART_enSTATE_DIS);
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        enIsBusyReg = UART_enFALSE;
        if(0UL == uxTimeoutArg)
        {
            do
            {
                enErrorReg = UART__enIsBusy(enModuleArg, &enIsBusyReg);
            }while ((UART_enFALSE != enIsBusyReg) &&
                    (UART_enERROR_OK == enErrorReg));
        }
        else
        {
            do
            {
                enErrorReg = UART__enIsBusy(enModuleArg, &enIsBusyReg);
                uxTimeoutArg--;
            }while ((UART_enFALSE != enIsBusyReg) &&
                    (UART_enERROR_OK == enErrorReg) &&
                    (0UL != uxTimeoutArg));

            if((UART_enFALSE != enIsBusyReg) &&
               (UART_enERROR_OK == enErrorReg) &&
               (0UL == uxTimeoutArg))
            {
                enErrorReg = UART_enERROR_TIMEOUT;
            }
        }
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        enErrorReg = UART__enSetFifoState(enModuleArg, UART_enSTATE_DIS);
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        if(UART_enSTATE_ENA == pstControlConfigArg->enRxLineState)
        {
            enErrorReg = (UART_nERROR) MCU__enCheckParams((UBase_t) pstLineConfigArg->enRx, MAX_CONFIG);
            if(UART_enERROR_OK == enErrorReg)
            {
                enErrorReg = (UART_nERROR) GPIO__enSetDigitalConfig(UART_enGpioInput[(UBase_t) pstLineConfigArg->enRx][(UBase_t) enModuleArg][RX_LINE],
                                                                    GPIO_enCONFIG_INPUT_2MA_PUSHPULL);
            }
        }
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        enErrorReg = UART__enSetReceiverState(enModuleArg, pstControlConfigArg->enRxLineState);
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        if(UART_enSTATE_ENA == pstControlConfigArg->enTxLineState)
        {
            enErrorReg = (UART_nERROR) MCU__enCheckParams((UBase_t) pstLineConfigArg->enTx, MAX_CONFIG);
            if(UART_enERROR_OK == enErrorReg)
            {
                enErrorReg = (UART_nERROR) GPIO__enSetDigitalConfig(UART_enGpioInput[(UBase_t) pstLineConfigArg->enTx][(UBase_t) enModuleArg][TX_LINE],
                                                                    GPIO_enCONFIG_OUTPUT_2MA_PUSHPULL);
            }
        }
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        enErrorReg = UART__enSetTransmitState(enModuleArg, pstControlConfigArg->enTxLineState);
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        if(UART_enLINE_MODE_HARD == pstControlConfigArg->enCTSMode)
        {
            if((UART_enMODULE_0 == enModuleArg) || (UART_enMODULE_1 == enModuleArg) || (UART_enMODULE_2 == enModuleArg) ||
               (UART_enMODULE_3 == enModuleArg) || (UART_enMODULE_4 == enModuleArg))
            {
                enErrorReg = (UART_nERROR) MCU__enCheckParams((UBase_t) pstLineConfigArg->enCTS, MAX_CONFIG);
                if(UART_enERROR_OK == enErrorReg)
                {
                    enErrorReg = (UART_nERROR) GPIO__enSetDigitalConfig(UART_enGpioInput[(UBase_t) pstLineConfigArg->enCTS] [(UBase_t) enModuleArg] [CTS_LINE],
                                                                        GPIO_enCONFIG_INPUT_2MA_PUSHPULL);
                }
            }
            else
            {
                enErrorReg = UART_enERROR_VALUE;
            }
        }
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        enErrorReg = UART__enSetClearToSendMode(enModuleArg, pstControlConfigArg->enCTSMode);
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        if(UART_enLINE_MODE_HARD == pstControlConfigArg->enRTSMode)
        {
            if((UART_enMODULE_0 == enModuleArg) || (UART_enMODULE_1 == enModuleArg) || (UART_enMODULE_2 == enModuleArg) ||
               (UART_enMODULE_3 == enModuleArg) || (UART_enMODULE_4 == enModuleArg))
            {
                enErrorReg = (UART_nERROR) MCU__enCheckParams((UBase_t) pstLineConfigArg->enRTS, MAX_CONFIG);
                if(UART_enERROR_OK == enErrorReg)
                {
                    enErrorReg = (UART_nERROR) GPIO__enSetDigitalConfig(UART_enGpioInput[(UBase_t) pstLineConfigArg->enRTS] [(UBase_t) enModuleArg] [RTS_LINE],
                                                                        GPIO_enCONFIG_OUTPUT_2MA_PUSHPULL);
                }
                if(UART_enERROR_OK == enErrorReg)
                {
                    enErrorReg = UART__enSetRequestToSendLevel(enModuleArg, pstControlConfigArg->enRTSLevel);
                }
            }
            else
            {
                enErrorReg = UART_enERROR_VALUE;
            }
        }
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        enErrorReg = UART__enSetRequestToSendMode(enModuleArg, pstControlConfigArg->enRTSMode);
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        if(UART_enSTATE_ENA == pstControlConfigArg->enDCDLineState)
        {
            if((UART_enMODULE_0 == enModuleArg) || (UART_enMODULE_1 == enModuleArg))
            {
                enErrorReg = (UART_nERROR) MCU__enCheckParams((UBase_t) pstLineConfigArg->enDCD, MAX_CONFIG);
                if(UART_enERROR_OK == enErrorReg)
                {
                    enErrorReg = (UART_nERROR) GPIO__enSetDigitalConfig(UART_enGpioInput[(UBase_t) pstLineConfigArg->enDCD][(UBase_t) enModuleArg][DCD_LINE],
                                                                        GPIO_enCONFIG_INPUT_2MA_PUSHPULL);
                }
            }
            else
            {
                enErrorReg = UART_enERROR_VALUE;
            }
        }
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        if(UART_enSTATE_ENA == pstControlConfigArg->enDSRLineState)
        {
            if((UART_enMODULE_0 == enModuleArg) || (UART_enMODULE_1 == enModuleArg))
            {
                enErrorReg = (UART_nERROR) MCU__enCheckParams((UBase_t) pstLineConfigArg->enDSR, MAX_CONFIG);
                if(UART_enERROR_OK == enErrorReg)
                {
                    enErrorReg = (UART_nERROR) GPIO__enSetDigitalConfig(UART_enGpioInput[(UBase_t) pstLineConfigArg->enDSR][(UBase_t) enModuleArg][DSR_LINE],
                                                                        GPIO_enCONFIG_INPUT_2MA_PUSHPULL);
                }
            }
            else
            {
                enErrorReg = UART_enERROR_VALUE;
            }
        }
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        if(UART_enSTATE_ENA == pstControlConfigArg->enDTRLineState)
        {
            if((UART_enMODULE_0 == enModuleArg) || (UART_enMODULE_1 == enModuleArg))
            {
                enErrorReg = (UART_nERROR) MCU__enCheckParams((UBase_t) pstLineConfigArg->enDTR, MAX_CONFIG);
                if(UART_enERROR_OK == enErrorReg)
                {
                    enErrorReg = (UART_nERROR) GPIO__enSetDigitalConfig(UART_enGpioInput[(UBase_t) pstLineConfigArg->enDTR][(UBase_t) enModuleArg][DTR_LINE],
                                                                        GPIO_enCONFIG_OUTPUT_2MA_PUSHPULL);
                }
                if(UART_enERROR_OK == enErrorReg)
                {
                    enErrorReg = UART__enSetDataTerminalReadyLevel(enModuleArg, pstControlConfigArg->enDTRLevel);
                }
            }
            else
            {
                enErrorReg = UART_enERROR_VALUE;
            }
        }
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        if(UART_enSTATE_ENA == pstControlConfigArg->enRILineState)
        {
            if((UART_enMODULE_0 == enModuleArg) || (UART_enMODULE_1 == enModuleArg))
            {
                enErrorReg = (UART_nERROR) MCU__enCheckParams((UBase_t) pstLineConfigArg->enRI, MAX_CONFIG);
                if(UART_enERROR_OK == enErrorReg)
                {
                    enErrorReg = (UART_nERROR) GPIO__enSetDigitalConfig(UART_enGpioInput[(UBase_t) pstLineConfigArg->enRI][(UBase_t) enModuleArg][RI_LINE],
                                                                        GPIO_enCONFIG_INPUT_2MA_PUSHPULL);
                }
            }
            else
            {
                enErrorReg = UART_enERROR_VALUE;
            }
        }
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        enErrorReg = UART__enSetLoopbackState(enModuleArg, pstControlConfigArg->enLoopbackState);
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        enErrorReg = UART__enSetEndOfTransmissionBehavior(enModuleArg, pstControlConfigArg->enEndOfTransmission);
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        if((UART_enPARITY_ADDRESS == pstLineControlConfigArg->enParityType) ||
           (UART_enPARITY_DATA == pstLineControlConfigArg->enParityType))
        {
            enErrorReg = UART__enSetMultiDropState(enModuleArg, UART_enSTATE_ENA);
            if(UART_enERROR_OK == enErrorReg)
            {
                enErrorReg = UART__enSetSelfAddressWithMask(enModuleArg, uxOwnAddressArg, uxOwnAddressMaskArg);
            }
        }
        else
        {
            enErrorReg = UART__enSetMultiDropState(enModuleArg, UART_enSTATE_DIS);
        }
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        if(UART_enMODE_IRDA_LP == enModeArg)
        {
            enErrorReg = UART__enSetIrDALowPowerState(enModuleArg, UART_enSTATE_ENA);
        }
        else
        {
            enErrorReg = UART__enSetIrDALowPowerState(enModuleArg, UART_enSTATE_DIS);
        }
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        if((UART_enMODE_IRDA == enModeArg) || (UART_enMODE_IRDA_LP == enModeArg))
        {
            enErrorReg = UART__enSetIrDAState(enModuleArg, UART_enSTATE_ENA);
        }
        else
        {
            enErrorReg = UART__enSetIrDAState(enModuleArg, UART_enSTATE_DIS);
        }
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        if(UART_enMODE_SMART_CARD == enModeArg)
        {
            enErrorReg = UART__enSetSmartCardState(enModuleArg, UART_enSTATE_ENA);
        }
        else
        {
            enErrorReg = UART__enSetSmartCardState(enModuleArg, UART_enSTATE_DIS);
        }
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        switch(enModeArg)
        {
        case UART_enMODE_NORMAL:
            enErrorReg = UART__enSetLineControlStructurePointer_BaudRate(enModuleArg, pstLineControlConfigArg, uxBaudRateArg);
            break;
        case UART_enMODE_IRDA:
            if(115200UL < uxBaudRateArg)
            {
                enErrorReg = UART_enERROR_VALUE;
            }
            if(UART_enERROR_OK == enErrorReg)
            {
                enErrorReg = UART__enSetLineControlStructurePointer_BaudRate(enModuleArg, pstLineControlConfigArg, uxBaudRateArg);
            }
            break;
        case UART_enMODE_IRDA_LP:
            enErrorReg = UART__enSetIrDALowPowerFrequency(enModuleArg);
            if(UART_enERROR_OK == enErrorReg)
            {
                enErrorReg = UART__enSetLineControlStructurePointer(enModuleArg, pstLineControlConfigArg);
            }
            break;
        case UART_enMODE_SMART_CARD:
            stLineControlConfig.enFifoState = pstLineControlConfigArg->enFifoState;
            stLineControlConfig.enStopBits = UART_enSTOP_TWO;
            stLineControlConfig.enDataLength = UART_enLENGTH_8BITS;
            stLineControlConfig.enParityType = UART_enPARITY_EVEN;
            enErrorReg = UART__enSetLineControlStructure_BaudRate(enModuleArg, stLineControlConfig, uxBaudRateArg);
            break;
        default:
            break;
        }
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        enErrorReg = UART__enSetState(enModuleArg, pstControlConfigArg->enModuleState);
    }
    return (enErrorReg);
}




