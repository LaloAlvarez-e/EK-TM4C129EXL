/**
 *
 * @file GPIO_InterruptRoutine_Vector_GPIOJ.c
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
#include <xApplication_MCU/GPIO/Interrupt/InterruptRoutine/xHeader/GPIO_InterruptRoutine_Vector_GPIOJ.h>

#include <xApplication_MCU/GPIO/Intrinsics/xHeader/GPIO_Dependencies.h>

void GPIOJ__vIRQVectorHandler(void)
{
    volatile uint32_t u32Reg = 0UL;
    void(*pfvCallback)(void)  = (void(*)(void)) 0UL;

    u32Reg = GPIOJ_MIS_R;

    if((uint32_t) GPIO_MIS_R_DMAMIS_OCCUR & u32Reg)
    {
        GPIOJ_ICR_R = GPIO_ICR_R_DMAIC_CLEAR;
        pfvCallback = GPIO__pvfGetIRQSourceDMAHandler(GPIO_enPORT_J);
        pfvCallback();
    }
    if((uint32_t) GPIO_enPIN_0 & u32Reg)
    {
        GPIOJ_ICR_R = (uint32_t) GPIO_enPIN_0;
        pfvCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_J, GPIO_enPIN_NUMBER0);
        pfvCallback();
    }
    if((uint32_t) GPIO_enPIN_1 & u32Reg)
    {
        GPIOJ_ICR_R = (uint32_t) GPIO_enPIN_1;
        pfvCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_J, GPIO_enPIN_NUMBER1);
        pfvCallback();
    }
    if((uint32_t) GPIO_enPIN_2 & u32Reg)
    {
        GPIOJ_ICR_R = (uint32_t) GPIO_enPIN_2;
        pfvCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_J, GPIO_enPIN_NUMBER2);
        pfvCallback();
    }
    if((uint32_t) GPIO_enPIN_3 & u32Reg)
    {
        GPIOJ_ICR_R = (uint32_t) GPIO_enPIN_3;
        pfvCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_J, GPIO_enPIN_NUMBER3);
        pfvCallback();
    }
    if((uint32_t) GPIO_enPIN_4 & u32Reg)
    {
        GPIOJ_ICR_R = (uint32_t) GPIO_enPIN_4;
        pfvCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_J, GPIO_enPIN_NUMBER4);
        pfvCallback();
    }
    if((uint32_t) GPIO_enPIN_5 & u32Reg)
    {
        GPIOJ_ICR_R = (uint32_t) GPIO_enPIN_5;
        pfvCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_J, GPIO_enPIN_NUMBER5);
        pfvCallback();
    }
    if((uint32_t) GPIO_enPIN_6 & u32Reg)
    {
        GPIOJ_ICR_R = (uint32_t) GPIO_enPIN_6;
        pfvCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_J, GPIO_enPIN_NUMBER6);
        pfvCallback();
    }
    if((uint32_t) GPIO_enPIN_7 & u32Reg)
    {
        GPIOJ_ICR_R = (uint32_t) GPIO_enPIN_7;
        pfvCallback = GPIO__pvfGetIRQSourceHandler(GPIO_enPORT_J, GPIO_enPIN_NUMBER7);
        pfvCallback();
    }
}