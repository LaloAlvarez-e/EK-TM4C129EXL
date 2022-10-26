/**
 *
 * @file UART_InterruptRoutine_Vector_Module4.c
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
 * @verbatim 23 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 23 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/UART/Interrupt/InterruptRoutine/xHeader/UART_InterruptRoutine_Vector_Module4.h>

#include <xApplication_MCU/UART/Intrinsics/xHeader/UART_Dependencies.h>

void UART4__vIRQVectorHandler(void)
{
    UBase_t uxReady;
    UART_pvfIRQSourceHandler_t pvfCallback;

    uxReady = SYSCTL_PRUART_R;
    if(SYSCTL_PRUART_R_UART4_NOREADY == (SYSCTL_PRUART_R_UART4_MASK & uxReady))
    {
        pvfCallback = UART__pvfGetIRQSourceHandler(UART_enMODULE_4, UART_enINT_SW);
        pvfCallback(UART4_BASE, (void*) UART_enINT_SW);
    }
    else
    {
        UART_nBOOLEAN boErrorFlag;
        UBase_t uxReg;

        boErrorFlag = UART_enFALSE;
        uxReg = (UBase_t) UART4_MIS_R;
        if(0UL == ((UBase_t) UART_enINTMASK_ALL & uxReg))
        {
            pvfCallback = UART__pvfGetIRQSourceHandler(UART_enMODULE_4, UART_enINT_SW);
            pvfCallback(UART4_BASE, (void*) UART_enINT_SW);
        }
        else
        {
            if((UBase_t) UART_enINTMASK_RING_INDICATOR & uxReg)
            {
                UART4_ICR_R = (UBase_t) UART_enINTMASK_RING_INDICATOR;
                pvfCallback = UART__pvfGetIRQSourceHandler(UART_enMODULE_4, UART_enINT_RING_INDICATOR);
                pvfCallback(UART4_BASE, (void*) UART_enINT_RING_INDICATOR);
            }
            if((UBase_t) UART_enINTMASK_CLEAR_TO_SEND & uxReg)
            {
                UART4_ICR_R = (UBase_t) UART_enINTMASK_CLEAR_TO_SEND;
                pvfCallback = UART__pvfGetIRQSourceHandler(UART_enMODULE_4, UART_enINT_CLEAR_TO_SEND);
                pvfCallback(UART4_BASE, (void*) UART_enINT_CLEAR_TO_SEND);
            }
            if((UBase_t) UART_enINTMASK_DATA_CARRIER_DETECT & uxReg)
            {
                UART4_ICR_R = (UBase_t) UART_enINTMASK_DATA_CARRIER_DETECT;
                pvfCallback = UART__pvfGetIRQSourceHandler(UART_enMODULE_4,  UART_enINT_DATA_CARRIER_DETECT);
                pvfCallback(UART4_BASE, (void*) UART_enINT_DATA_CARRIER_DETECT);
            }
            if((UBase_t) UART_enINTMASK_DATA_SET_READY & uxReg)
            {
                UART4_ICR_R = (UBase_t) UART_enINTMASK_DATA_SET_READY;
                pvfCallback = UART__pvfGetIRQSourceHandler(UART_enMODULE_4, UART_enINT_DATA_SET_READY);
                pvfCallback(UART4_BASE, (void*) UART_enINT_DATA_SET_READY);
            }
            if((UBase_t) UART_enINTMASK_RECEIVE & uxReg)
            {
                UART4_ICR_R = (UBase_t) UART_enINTMASK_RECEIVE;
                pvfCallback = UART__pvfGetIRQSourceHandler(UART_enMODULE_4, UART_enINT_RECEIVE);
                pvfCallback(UART4_BASE, (void*) UART_enINT_RECEIVE);
            }
            if((UBase_t) UART_enINTMASK_TRANSMIT & uxReg)
            {
                UART4_ICR_R = (UBase_t) UART_enINTMASK_TRANSMIT;
                pvfCallback = UART__pvfGetIRQSourceHandler(UART_enMODULE_4, UART_enINT_TRANSMIT);
                pvfCallback(UART4_BASE, (void*) UART_enINT_TRANSMIT);
            }
            if((UBase_t) UART_enINTMASK_RECEIVE_TIMEOUT & uxReg)
            {
                UART4_ICR_R = (UBase_t) UART_enINTMASK_RECEIVE_TIMEOUT;
                pvfCallback = UART__pvfGetIRQSourceHandler(UART_enMODULE_4, UART_enINT_RECEIVE_TIMEOUT);
                pvfCallback(UART4_BASE, (void*) UART_enINT_RECEIVE_TIMEOUT);
            }
            if((UBase_t) UART_enINTMASK_FRAME_ERROR & uxReg)
            {
                boErrorFlag = UART_enTRUE;
                UART4_ICR_R = (UBase_t) UART_enINTMASK_FRAME_ERROR;
                pvfCallback = UART__pvfGetIRQSourceHandler(UART_enMODULE_4, UART_enINT_FRAME_ERROR);
                pvfCallback(UART4_BASE, (void*) UART_enINT_FRAME_ERROR);
            }
            if((UBase_t) UART_enINTMASK_PARITY_ERROR & uxReg)
            {
                boErrorFlag = UART_enTRUE;
                UART4_ICR_R = (UBase_t) UART_enINTMASK_PARITY_ERROR;
                pvfCallback = UART__pvfGetIRQSourceHandler(UART_enMODULE_4, UART_enINT_PARITY_ERROR);
                pvfCallback(UART4_BASE, (void*) UART_enINT_PARITY_ERROR);
            }
            if((UBase_t) UART_enINTMASK_BREAK_ERROR & uxReg)
            {
                boErrorFlag = UART_enTRUE;
                UART4_ICR_R = (UBase_t) UART_enINTMASK_BREAK_ERROR;
                pvfCallback = UART__pvfGetIRQSourceHandler(UART_enMODULE_4, UART_enINT_BREAK_ERROR);
                pvfCallback(UART4_BASE, (void*) UART_enINT_BREAK_ERROR);
            }
            if((UBase_t) UART_enINTMASK_OVERRUN_ERROR & uxReg)
            {
                boErrorFlag = UART_enTRUE;
                UART4_ICR_R = (UBase_t) UART_enINTMASK_OVERRUN_ERROR;
                pvfCallback = UART__pvfGetIRQSourceHandler(UART_enMODULE_4, UART_enINT_OVERRUN_ERROR);
                pvfCallback(UART4_BASE, (void*) UART_enINT_OVERRUN_ERROR);
            }
            if((UBase_t) UART_enINTMASK_BIT9_MODE & uxReg)
            {
                UART4_ICR_R = (UBase_t) UART_enINTMASK_BIT9_MODE;
                pvfCallback = UART__pvfGetIRQSourceHandler(UART_enMODULE_4, UART_enINT_BIT9_MODE);
                pvfCallback(UART4_BASE, (void*) UART_enINT_BIT9_MODE);
            }
            if((UBase_t) UART_enINTMASK_DMA_RECEIVE & uxReg)
            {
                UART4_ICR_R = (UBase_t) UART_enINTMASK_DMA_RECEIVE;
                pvfCallback = UART__pvfGetIRQSourceHandler(UART_enMODULE_4,  UART_enINT_DMA_RECEIVE);
                pvfCallback(UART4_BASE, (void*) UART_enINT_DMA_RECEIVE);
            }
            if((UBase_t) UART_enINTMASK_DMA_TRANSMIT & uxReg)
            {
                UART4_DMACTL_R &= ~UART_DMACTL_R_TXDMAE_MASK;
                UART4_ICR_R = (UBase_t) UART_enINTMASK_DMA_TRANSMIT;
                pvfCallback = UART__pvfGetIRQSourceHandler(UART_enMODULE_4, UART_enINT_DMA_TRANSMIT);
                pvfCallback(UART4_BASE, (void*) UART_enINT_DMA_TRANSMIT);
            }
            if((UBase_t) UART_enINTMASK_END_OF_TRANSMISSION & uxReg)
            {
                UART4_ICR_R = (UBase_t) UART_enINTMASK_END_OF_TRANSMISSION;
                pvfCallback = UART__pvfGetIRQSourceHandler(UART_enMODULE_4, UART_enINT_END_OF_TRANSMISSION);
                pvfCallback(UART4_BASE, (void*) UART_enINT_END_OF_TRANSMISSION);
            }

            if(UART_enTRUE == boErrorFlag)
            {
                UART4_ECR_R = UART_ECR_R_DATA_CLEAR;
            }
        }
    }
}
