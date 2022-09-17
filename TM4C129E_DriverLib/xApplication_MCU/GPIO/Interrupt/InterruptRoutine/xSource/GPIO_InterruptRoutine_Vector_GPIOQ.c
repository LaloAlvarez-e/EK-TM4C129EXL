/**
 *
 * @file GPIO_InterruptRoutine_Vector_GPIOQ.c
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
 * @verbatim 9 jul. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 9 jul. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/GPIO/Interrupt/InterruptRoutine/xHeader/GPIO_InterruptRoutine_Vector_GPIOQ.h>

#include <xApplication_MCU/GPIO/Intrinsics/xHeader/GPIO_Dependencies.h>

void GPIOQ__vIRQVectorHandler(void)
{
    volatile uint32_t u32Reg = 0UL;
    volatile uint32_t u32Ready = 0U;
    volatile uint32_t u32DMaReq = 0UL;
    volatile uint32_t u32IntType = 0UL;
    void(*pvfCallback)(void)  = (void(*)(void)) 0UL;

    u32Ready = SYSCTL_PRGPIO_R;
    if(SYSCTL_PRGPIO_R_GPIOQ_NOREADY == (SYSCTL_PRGPIO_R_GPIOQ_MASK & u32Ready))
    {
        pvfCallback = GPIO_SW__pvfGetIRQSourceHandler(GPIO_enPORT_Q);
        pvfCallback();
    }
    else
    {
        u32Reg = GPIOQ_MIS_R;
        u32IntType = GPIOQ_SI_R;
        u32IntType &= GPIO_SI_R_SUM_MASK;
        if(GPIO_SI_R_SUM_SINGLE == u32IntType)
        {
            if(0UL == (((uint32_t) GPIO_enPINMASK_ALL | GPIO_MIS_R_DMAMIS_ACTIVE) & u32Reg))
            {
                pvfCallback = GPIO_SW__pvfGetIRQSourceHandler(GPIO_enPORT_Q);
                pvfCallback();
            }
            else
            {
                if((uint32_t) GPIO_MIS_R_DMAMIS_ACTIVE & u32Reg)
                {
                    GPIOQ_ICR_R = GPIO_ICR_R_DMAIC_CLEAR;
                    pvfCallback = GPIO_DMA__pvfGetIRQSourceHandler(GPIO_enPORT_Q);
                    pvfCallback();
                }
                if((uint32_t) GPIO_enPINMASK_0 & u32Reg)
                {
                    GPIOQ_ICR_R = (uint32_t) GPIO_enPINMASK_0;
                    pvfCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_Q, GPIO_enPIN_0);
                    pvfCallback();
                }
                if((uint32_t) GPIO_enPINMASK_1 & u32Reg)
                {
                    GPIOQ_ICR_R = (uint32_t) GPIO_enPINMASK_1;
                    pvfCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_Q, GPIO_enPIN_1);
                    pvfCallback();
                }
                if((uint32_t) GPIO_enPINMASK_2 & u32Reg)
                {
                    GPIOQ_ICR_R = (uint32_t) GPIO_enPINMASK_2;
                    pvfCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_Q, GPIO_enPIN_2);
                    pvfCallback();
                }
                if((uint32_t) GPIO_enPINMASK_3 & u32Reg)
                {
                    GPIOQ_ICR_R = (uint32_t) GPIO_enPINMASK_3;
                    pvfCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_Q, GPIO_enPIN_3);
                    pvfCallback();
                }
                if((uint32_t) GPIO_enPINMASK_4 & u32Reg)
                {
                    GPIOQ_ICR_R = (uint32_t) GPIO_enPINMASK_4;
                    pvfCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_Q, GPIO_enPIN_4);
                    pvfCallback();
                }
                if((uint32_t) GPIO_enPINMASK_5 & u32Reg)
                {
                    GPIOQ_ICR_R = (uint32_t) GPIO_enPINMASK_5;
                    pvfCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_Q, GPIO_enPIN_5);
                    pvfCallback();
                }
                if((uint32_t) GPIO_enPINMASK_6 & u32Reg)
                {
                    GPIOQ_ICR_R = (uint32_t) GPIO_enPINMASK_6;
                    pvfCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_Q, GPIO_enPIN_6);
                    pvfCallback();
                }
                if((uint32_t) GPIO_enPINMASK_7 & u32Reg)
                {
                    GPIOQ_ICR_R = (uint32_t) GPIO_enPINMASK_7;
                    pvfCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_Q, GPIO_enPIN_7);
                    pvfCallback();
                }
            }
        }
        else
        {
            u32DMaReq = GPIOQ_DMACTL_R;
            if( GPIO_DMACTL_R_PIN0_ENA & u32DMaReq)
            {
                if(0UL == (((uint32_t) GPIO_enPINMASK_0 | GPIO_MIS_R_DMAMIS_ACTIVE) & u32Reg))
                {
                    pvfCallback = GPIO_SW__pvfGetIRQSourceHandler(GPIO_enPORT_Q);
                    pvfCallback();
                }
                else
                {
                    if(GPIO_MIS_R_DMAMIS_ACTIVE & u32Reg)
                    {
                        GPIOQ_ICR_R = GPIO_ICR_R_DMAIC_CLEAR;
                        pvfCallback = GPIO_DMA__pvfGetIRQSourceHandler(GPIO_enPORT_Q);
                        pvfCallback();
                    }
                    if((uint32_t) GPIO_enPINMASK_0 & u32Reg)
                    {
                        GPIOQ_ICR_R = (uint32_t) GPIO_enPINMASK_0;
                        pvfCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_Q,
                                                                   GPIO_enPIN_0);
                        pvfCallback();
                    }
                }
            }
            else
            {
                if((uint32_t) GPIO_enPINMASK_0 & u32Reg)
                {
                    GPIOQ_ICR_R = (uint32_t) GPIO_enPINMASK_0;
                    pvfCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_Q,
                                                               GPIO_enPIN_0);
                    pvfCallback();
                }
                else
                {
                    pvfCallback = GPIO_SW__pvfGetIRQSourceHandler(GPIO_enPORT_Q);
                    pvfCallback();
                }
            }
        }
    }
}

void GPIOQ1__vIRQVectorHandler(void)
{
    volatile uint32_t u32Reg = 0UL;
    volatile uint32_t u32Ready = 0U;
    volatile uint32_t u32DMaReq = 0UL;
    void(*pvfCallback)(void)  = (void(*)(void)) 0UL;

    u32Ready = SYSCTL_PRGPIO_R;
    if(SYSCTL_PRGPIO_R_GPIOQ_NOREADY == (SYSCTL_PRGPIO_R_GPIOQ_MASK & u32Ready))
    {
        pvfCallback = GPIO_SW__pvfGetIRQSourceHandler_PQ(GPIO_enPORT_Q,
                                                        GPIO_enPIN_1);
        pvfCallback();
    }
    else
    {
        u32Reg = GPIOQ_MIS_R;
        u32DMaReq = GPIOQ_DMACTL_R;
        if( GPIO_DMACTL_R_PIN1_ENA & u32DMaReq)
        {
            if(0UL == (((uint32_t) GPIO_enPINMASK_1 | GPIO_MIS_R_DMAMIS_ACTIVE) & u32Reg))
            {
                pvfCallback = GPIO_SW__pvfGetIRQSourceHandler_PQ(GPIO_enPORT_Q,
                                                                 GPIO_enPIN_1);
                pvfCallback();
            }
            else
            {
                if(GPIO_MIS_R_DMAMIS_ACTIVE & u32Reg)
                {
                    GPIOQ_ICR_R = GPIO_ICR_R_DMAIC_CLEAR;
                    pvfCallback = GPIO_DMA__pvfGetIRQSourceHandler(GPIO_enPORT_Q);
                    pvfCallback();
                }
                if((uint32_t) GPIO_enPINMASK_1 & u32Reg)
                {
                    GPIOQ_ICR_R = (uint32_t) GPIO_enPINMASK_1;
                    pvfCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_Q,
                                                               GPIO_enPIN_1);
                    pvfCallback();
                }
            }
        }
        else
        {
            if((uint32_t) GPIO_enPINMASK_1 & u32Reg)
            {
                GPIOQ_ICR_R = (uint32_t) GPIO_enPINMASK_1;
                pvfCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_Q,
                                                           GPIO_enPIN_1);
                pvfCallback();
            }
            else
            {
                pvfCallback = GPIO_SW__pvfGetIRQSourceHandler_PQ(GPIO_enPORT_Q,
                                                                 GPIO_enPIN_1);
                pvfCallback();
            }
        }
    }
}

void GPIOQ2__vIRQVectorHandler(void)
{
    volatile uint32_t u32Reg = 0UL;
    volatile uint32_t u32Ready = 0U;
    volatile uint32_t u32DMaReq = 0UL;
    void(*pvfCallback)(void)  = (void(*)(void)) 0UL;

    u32Ready = SYSCTL_PRGPIO_R;
    if(SYSCTL_PRGPIO_R_GPIOQ_NOREADY == (SYSCTL_PRGPIO_R_GPIOQ_MASK & u32Ready))
    {
        pvfCallback = GPIO_SW__pvfGetIRQSourceHandler_PQ(GPIO_enPORT_Q,
                                                        GPIO_enPIN_2);
        pvfCallback();
    }
    else
    {
        u32Reg = GPIOQ_MIS_R;
        u32DMaReq = GPIOQ_DMACTL_R;
        if( GPIO_DMACTL_R_PIN2_ENA & u32DMaReq)
        {
            if(0UL == (((uint32_t) GPIO_enPINMASK_2 | GPIO_MIS_R_DMAMIS_ACTIVE) & u32Reg))
            {
                pvfCallback = GPIO_SW__pvfGetIRQSourceHandler_PQ(GPIO_enPORT_Q,
                                                                 GPIO_enPIN_2);
                pvfCallback();
            }
            else
            {
                if(GPIO_MIS_R_DMAMIS_ACTIVE & u32Reg)
                {
                    GPIOQ_ICR_R = GPIO_ICR_R_DMAIC_CLEAR;
                    pvfCallback = GPIO_DMA__pvfGetIRQSourceHandler(GPIO_enPORT_Q);
                    pvfCallback();
                }
                if((uint32_t) GPIO_enPINMASK_2 & u32Reg)
                {
                    GPIOQ_ICR_R = (uint32_t) GPIO_enPINMASK_2;
                    pvfCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_Q,
                                                               GPIO_enPIN_2);
                    pvfCallback();
                }
            }
        }
        else
        {
            if((uint32_t) GPIO_enPINMASK_2 & u32Reg)
            {
                GPIOQ_ICR_R = (uint32_t) GPIO_enPINMASK_2;
                pvfCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_Q,
                                                           GPIO_enPIN_2);
                pvfCallback();
            }
            else
            {
                pvfCallback = GPIO_SW__pvfGetIRQSourceHandler_PQ(GPIO_enPORT_Q,
                                                                 GPIO_enPIN_2);
                pvfCallback();
            }
        }
    }
}

void GPIOQ3__vIRQVectorHandler(void)
{
    volatile uint32_t u32Reg = 0UL;
    volatile uint32_t u32Ready = 0U;
    volatile uint32_t u32DMaReq = 0UL;
    void(*pvfCallback)(void)  = (void(*)(void)) 0UL;

    u32Ready = SYSCTL_PRGPIO_R;
    if(SYSCTL_PRGPIO_R_GPIOQ_NOREADY == (SYSCTL_PRGPIO_R_GPIOQ_MASK & u32Ready))
    {
        pvfCallback = GPIO_SW__pvfGetIRQSourceHandler_PQ(GPIO_enPORT_Q,
                                                        GPIO_enPIN_3);
        pvfCallback();
    }
    else
    {
        u32Reg = GPIOQ_MIS_R;
        u32DMaReq = GPIOQ_DMACTL_R;
        if( GPIO_DMACTL_R_PIN3_ENA & u32DMaReq)
        {
            if(0UL == (((uint32_t) GPIO_enPINMASK_3 | GPIO_MIS_R_DMAMIS_ACTIVE) & u32Reg))
            {
                pvfCallback = GPIO_SW__pvfGetIRQSourceHandler_PQ(GPIO_enPORT_Q,
                                                                 GPIO_enPIN_3);
                pvfCallback();
            }
            else
            {
                if(GPIO_MIS_R_DMAMIS_ACTIVE & u32Reg)
                {
                    GPIOQ_ICR_R = GPIO_ICR_R_DMAIC_CLEAR;
                    pvfCallback = GPIO_DMA__pvfGetIRQSourceHandler(GPIO_enPORT_Q);
                    pvfCallback();
                }
                if((uint32_t) GPIO_enPINMASK_3 & u32Reg)
                {
                    GPIOQ_ICR_R = (uint32_t) GPIO_enPINMASK_3;
                    pvfCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_Q,
                                                               GPIO_enPIN_3);
                    pvfCallback();
                }
            }
        }
        else
        {
            if((uint32_t) GPIO_enPINMASK_3 & u32Reg)
            {
                GPIOQ_ICR_R = (uint32_t) GPIO_enPINMASK_3;
                pvfCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_Q,
                                                           GPIO_enPIN_3);
                pvfCallback();
            }
            else
            {
                pvfCallback = GPIO_SW__pvfGetIRQSourceHandler_PQ(GPIO_enPORT_Q,
                                                                 GPIO_enPIN_3);
                pvfCallback();
            }
        }
    }
}

void GPIOQ4__vIRQVectorHandler(void)
{
    volatile uint32_t u32Reg = 0UL;
    volatile uint32_t u32Ready = 0U;
    volatile uint32_t u32DMaReq = 0UL;
    void(*pvfCallback)(void)  = (void(*)(void)) 0UL;

    u32Ready = SYSCTL_PRGPIO_R;
    if(SYSCTL_PRGPIO_R_GPIOQ_NOREADY == (SYSCTL_PRGPIO_R_GPIOQ_MASK & u32Ready))
    {
        pvfCallback = GPIO_SW__pvfGetIRQSourceHandler_PQ(GPIO_enPORT_Q,
                                                        GPIO_enPIN_4);
        pvfCallback();
    }
    else
    {
        u32Reg = GPIOQ_MIS_R;
        u32DMaReq = GPIOQ_DMACTL_R;
        if( GPIO_DMACTL_R_PIN4_ENA & u32DMaReq)
        {
            if(0UL == (((uint32_t) GPIO_enPINMASK_4 | GPIO_MIS_R_DMAMIS_ACTIVE) & u32Reg))
            {
                pvfCallback = GPIO_SW__pvfGetIRQSourceHandler_PQ(GPIO_enPORT_Q,
                                                                 GPIO_enPIN_4);
                pvfCallback();
            }
            else
            {
                if(GPIO_MIS_R_DMAMIS_ACTIVE & u32Reg)
                {
                    GPIOQ_ICR_R = GPIO_ICR_R_DMAIC_CLEAR;
                    pvfCallback = GPIO_DMA__pvfGetIRQSourceHandler(GPIO_enPORT_Q);
                    pvfCallback();
                }
                if((uint32_t) GPIO_enPINMASK_4 & u32Reg)
                {
                    GPIOQ_ICR_R = (uint32_t) GPIO_enPINMASK_4;
                    pvfCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_Q,
                                                               GPIO_enPIN_4);
                    pvfCallback();
                }
            }
        }
        else
        {
            if((uint32_t) GPIO_enPINMASK_4 & u32Reg)
            {
                GPIOQ_ICR_R = (uint32_t) GPIO_enPINMASK_4;
                pvfCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_Q,
                                                           GPIO_enPIN_4);
                pvfCallback();
            }
            else
            {
                pvfCallback = GPIO_SW__pvfGetIRQSourceHandler_PQ(GPIO_enPORT_Q,
                                                                 GPIO_enPIN_4);
                pvfCallback();
            }
        }
    }
}

void GPIOQ5__vIRQVectorHandler(void)
{
    volatile uint32_t u32Reg = 0UL;
    volatile uint32_t u32Ready = 0U;
    volatile uint32_t u32DMaReq = 0UL;
    void(*pvfCallback)(void)  = (void(*)(void)) 0UL;

    u32Ready = SYSCTL_PRGPIO_R;
    if(SYSCTL_PRGPIO_R_GPIOQ_NOREADY == (SYSCTL_PRGPIO_R_GPIOQ_MASK & u32Ready))
    {
        pvfCallback = GPIO_SW__pvfGetIRQSourceHandler_PQ(GPIO_enPORT_Q,
                                                        GPIO_enPIN_5);
        pvfCallback();
    }
    else
    {
        u32Reg = GPIOQ_MIS_R;
        u32DMaReq = GPIOQ_DMACTL_R;
        if( GPIO_DMACTL_R_PIN5_ENA & u32DMaReq)
        {
            if(0UL == (((uint32_t) GPIO_enPINMASK_5 | GPIO_MIS_R_DMAMIS_ACTIVE) & u32Reg))
            {
                pvfCallback = GPIO_SW__pvfGetIRQSourceHandler_PQ(GPIO_enPORT_Q,
                                                                 GPIO_enPIN_5);
                pvfCallback();
            }
            else
            {
                if(GPIO_MIS_R_DMAMIS_ACTIVE & u32Reg)
                {
                    GPIOQ_ICR_R = GPIO_ICR_R_DMAIC_CLEAR;
                    pvfCallback = GPIO_DMA__pvfGetIRQSourceHandler(GPIO_enPORT_Q);
                    pvfCallback();
                }
                if((uint32_t) GPIO_enPINMASK_5 & u32Reg)
                {
                    GPIOQ_ICR_R = (uint32_t) GPIO_enPINMASK_5;
                    pvfCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_Q,
                                                               GPIO_enPIN_5);
                    pvfCallback();
                }
            }
        }
        else
        {
            if((uint32_t) GPIO_enPINMASK_5 & u32Reg)
            {
                GPIOQ_ICR_R = (uint32_t) GPIO_enPINMASK_5;
                pvfCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_Q,
                                                           GPIO_enPIN_5);
                pvfCallback();
            }
            else
            {
                pvfCallback = GPIO_SW__pvfGetIRQSourceHandler_PQ(GPIO_enPORT_Q,
                                                                 GPIO_enPIN_5);
                pvfCallback();
            }
        }
    }
}

void GPIOQ6__vIRQVectorHandler(void)
{
    volatile uint32_t u32Reg = 0UL;
    volatile uint32_t u32Ready = 0U;
    volatile uint32_t u32DMaReq = 0UL;
    void(*pvfCallback)(void)  = (void(*)(void)) 0UL;

    u32Ready = SYSCTL_PRGPIO_R;
    if(SYSCTL_PRGPIO_R_GPIOQ_NOREADY == (SYSCTL_PRGPIO_R_GPIOQ_MASK & u32Ready))
    {
        pvfCallback = GPIO_SW__pvfGetIRQSourceHandler_PQ(GPIO_enPORT_Q,
                                                        GPIO_enPIN_6);
        pvfCallback();
    }
    else
    {
        u32Reg = GPIOQ_MIS_R;
        u32DMaReq = GPIOQ_DMACTL_R;
        if( GPIO_DMACTL_R_PIN6_ENA & u32DMaReq)
        {
            if(0UL == (((uint32_t) GPIO_enPINMASK_6 | GPIO_MIS_R_DMAMIS_ACTIVE) & u32Reg))
            {
                pvfCallback = GPIO_SW__pvfGetIRQSourceHandler_PQ(GPIO_enPORT_Q,
                                                                 GPIO_enPIN_6);
                pvfCallback();
            }
            else
            {
                if(GPIO_MIS_R_DMAMIS_ACTIVE & u32Reg)
                {
                    GPIOQ_ICR_R = GPIO_ICR_R_DMAIC_CLEAR;
                    pvfCallback = GPIO_DMA__pvfGetIRQSourceHandler(GPIO_enPORT_Q);
                    pvfCallback();
                }
                if((uint32_t) GPIO_enPINMASK_6 & u32Reg)
                {
                    GPIOQ_ICR_R = (uint32_t) GPIO_enPINMASK_6;
                    pvfCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_Q,
                                                               GPIO_enPIN_6);
                    pvfCallback();
                }
            }
        }
        else
        {
            if((uint32_t) GPIO_enPINMASK_6 & u32Reg)
            {
                GPIOQ_ICR_R = (uint32_t) GPIO_enPINMASK_6;
                pvfCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_Q,
                                                           GPIO_enPIN_6);
                pvfCallback();
            }
            else
            {
                pvfCallback = GPIO_SW__pvfGetIRQSourceHandler_PQ(GPIO_enPORT_Q,
                                                                 GPIO_enPIN_6);
                pvfCallback();
            }
        }
    }
}

void GPIOQ7__vIRQVectorHandler(void)
{
    volatile uint32_t u32Reg = 0UL;
    volatile uint32_t u32Ready = 0U;
    volatile uint32_t u32DMaReq = 0UL;
    void(*pvfCallback)(void)  = (void(*)(void)) 0UL;

    u32Ready = SYSCTL_PRGPIO_R;
    if(SYSCTL_PRGPIO_R_GPIOQ_NOREADY == (SYSCTL_PRGPIO_R_GPIOQ_MASK & u32Ready))
    {
        pvfCallback = GPIO_SW__pvfGetIRQSourceHandler_PQ(GPIO_enPORT_Q,
                                                        GPIO_enPIN_7);
        pvfCallback();
    }
    else
    {
        u32Reg = GPIOQ_MIS_R;
        u32DMaReq = GPIOQ_DMACTL_R;
        if( GPIO_DMACTL_R_PIN7_ENA & u32DMaReq)
        {
            if(0UL == (((uint32_t) GPIO_enPINMASK_7 | GPIO_MIS_R_DMAMIS_ACTIVE) & u32Reg))
            {
                pvfCallback = GPIO_SW__pvfGetIRQSourceHandler_PQ(GPIO_enPORT_Q,
                                                                 GPIO_enPIN_7);
                pvfCallback();
            }
            else
            {
                if(GPIO_MIS_R_DMAMIS_ACTIVE & u32Reg)
                {
                    GPIOQ_ICR_R = GPIO_ICR_R_DMAIC_CLEAR;
                    pvfCallback = GPIO_DMA__pvfGetIRQSourceHandler(GPIO_enPORT_Q);
                    pvfCallback();
                }
                if((uint32_t) GPIO_enPINMASK_7 & u32Reg)
                {
                    GPIOQ_ICR_R = (uint32_t) GPIO_enPINMASK_7;
                    pvfCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_Q,
                                                               GPIO_enPIN_7);
                    pvfCallback();
                }
            }
        }
        else
        {
            if((uint32_t) GPIO_enPINMASK_7 & u32Reg)
            {
                GPIOQ_ICR_R = (uint32_t) GPIO_enPINMASK_7;
                pvfCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_Q,
                                                           GPIO_enPIN_7);
                pvfCallback();
            }
            else
            {
                pvfCallback = GPIO_SW__pvfGetIRQSourceHandler_PQ(GPIO_enPORT_Q,
                                                                 GPIO_enPIN_7);
                pvfCallback();
            }
        }
    }
}
