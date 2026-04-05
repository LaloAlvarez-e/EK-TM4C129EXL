/**
 *
 * @file TIMER_Init.c
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
#include <xApplication_MCU/TIMER/xHeader/TIMER_Init.h>

#include <xApplication_MCU/TIMER/Interrupt/TIMER_Interrupt.h>

TIMER_nERROR TIMER__enInit(void)
{
    TIMER_pvfIRQVectorHandler_t pfIrqVectorHandlerReg;
    TIMER_nERROR enErrorReg;

    enErrorReg = TIMER_enERROR_OK;
    if(TIMER_enERROR_OK == enErrorReg)
    {
        pfIrqVectorHandlerReg = TIMER__pvfGetIRQVectorHandler(TIMER_enSUBMODULE_A, TIMER_enMODULE_NUM_0);
        enErrorReg = TIMER__enRegisterIRQVectorHandler(TIMER_enT0A, pfIrqVectorHandlerReg);
    }
    if(TIMER_enERROR_OK == enErrorReg)
    {
        pfIrqVectorHandlerReg = TIMER__pvfGetIRQVectorHandler(TIMER_enSUBMODULE_B, TIMER_enMODULE_NUM_0);
        enErrorReg = TIMER__enRegisterIRQVectorHandler(TIMER_enT0B, pfIrqVectorHandlerReg);
    }
    if(TIMER_enERROR_OK == enErrorReg)
    {
        pfIrqVectorHandlerReg = TIMER__pvfGetIRQVectorHandler(TIMER_enSUBMODULE_A, TIMER_enMODULE_NUM_1);
        enErrorReg = TIMER__enRegisterIRQVectorHandler(TIMER_enT1A, pfIrqVectorHandlerReg);
    }
    if(TIMER_enERROR_OK == enErrorReg)
    {
        pfIrqVectorHandlerReg = TIMER__pvfGetIRQVectorHandler(TIMER_enSUBMODULE_B, TIMER_enMODULE_NUM_1);
        enErrorReg = TIMER__enRegisterIRQVectorHandler(TIMER_enT1B, pfIrqVectorHandlerReg);
    }
    if(TIMER_enERROR_OK == enErrorReg)
    {
        pfIrqVectorHandlerReg = TIMER__pvfGetIRQVectorHandler(TIMER_enSUBMODULE_A, TIMER_enMODULE_NUM_2);
        enErrorReg = TIMER__enRegisterIRQVectorHandler(TIMER_enT2A, pfIrqVectorHandlerReg);
    }
    if(TIMER_enERROR_OK == enErrorReg)
    {
        pfIrqVectorHandlerReg = TIMER__pvfGetIRQVectorHandler(TIMER_enSUBMODULE_B, TIMER_enMODULE_NUM_2);
        enErrorReg = TIMER__enRegisterIRQVectorHandler(TIMER_enT2B, pfIrqVectorHandlerReg);
    }
    if(TIMER_enERROR_OK == enErrorReg)
    {
        pfIrqVectorHandlerReg = TIMER__pvfGetIRQVectorHandler(TIMER_enSUBMODULE_A, TIMER_enMODULE_NUM_3);
        enErrorReg = TIMER__enRegisterIRQVectorHandler(TIMER_enT3A, pfIrqVectorHandlerReg);
    }
    if(TIMER_enERROR_OK == enErrorReg)
    {
        pfIrqVectorHandlerReg = TIMER__pvfGetIRQVectorHandler(TIMER_enSUBMODULE_B, TIMER_enMODULE_NUM_3);
        enErrorReg = TIMER__enRegisterIRQVectorHandler(TIMER_enT3B, pfIrqVectorHandlerReg);
    }
    if(TIMER_enERROR_OK == enErrorReg)
    {
        pfIrqVectorHandlerReg = TIMER__pvfGetIRQVectorHandler(TIMER_enSUBMODULE_A, TIMER_enMODULE_NUM_4);
        enErrorReg = TIMER__enRegisterIRQVectorHandler(TIMER_enT4A, pfIrqVectorHandlerReg);
    }
    if(TIMER_enERROR_OK == enErrorReg)
    {
        pfIrqVectorHandlerReg = TIMER__pvfGetIRQVectorHandler(TIMER_enSUBMODULE_B, TIMER_enMODULE_NUM_4);
        enErrorReg = TIMER__enRegisterIRQVectorHandler(TIMER_enT4B, pfIrqVectorHandlerReg);
    }
    if(TIMER_enERROR_OK == enErrorReg)
    {
        pfIrqVectorHandlerReg = TIMER__pvfGetIRQVectorHandler(TIMER_enSUBMODULE_A, TIMER_enMODULE_NUM_5);
        enErrorReg = TIMER__enRegisterIRQVectorHandler(TIMER_enT5A, pfIrqVectorHandlerReg);
    }
    if(TIMER_enERROR_OK == enErrorReg)
    {
        pfIrqVectorHandlerReg = TIMER__pvfGetIRQVectorHandler(TIMER_enSUBMODULE_B, TIMER_enMODULE_NUM_5);
        enErrorReg = TIMER__enRegisterIRQVectorHandler(TIMER_enT5B, pfIrqVectorHandlerReg);
    }
    if(TIMER_enERROR_OK == enErrorReg)
    {
        pfIrqVectorHandlerReg = TIMER__pvfGetIRQVectorHandler(TIMER_enSUBMODULE_A, TIMER_enMODULE_NUM_6);
        enErrorReg = TIMER__enRegisterIRQVectorHandler(TIMER_enT6A, pfIrqVectorHandlerReg);
    }
    if(TIMER_enERROR_OK == enErrorReg)
    {
        pfIrqVectorHandlerReg = TIMER__pvfGetIRQVectorHandler(TIMER_enSUBMODULE_B, TIMER_enMODULE_NUM_6);
        enErrorReg = TIMER__enRegisterIRQVectorHandler(TIMER_enT6B, pfIrqVectorHandlerReg);
    }
    if(TIMER_enERROR_OK == enErrorReg)
    {
        pfIrqVectorHandlerReg = TIMER__pvfGetIRQVectorHandler(TIMER_enSUBMODULE_A, TIMER_enMODULE_NUM_7);
        enErrorReg = TIMER__enRegisterIRQVectorHandler(TIMER_enT7A, pfIrqVectorHandlerReg);
    }
    if(TIMER_enERROR_OK == enErrorReg)
    {
        pfIrqVectorHandlerReg = TIMER__pvfGetIRQVectorHandler(TIMER_enSUBMODULE_B, TIMER_enMODULE_NUM_7);
        enErrorReg = TIMER__enRegisterIRQVectorHandler(TIMER_enT7B, pfIrqVectorHandlerReg);
    }
    return (enErrorReg);
}
