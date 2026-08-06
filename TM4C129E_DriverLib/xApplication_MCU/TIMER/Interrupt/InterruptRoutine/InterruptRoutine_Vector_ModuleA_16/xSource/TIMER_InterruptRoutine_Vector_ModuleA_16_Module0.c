/**
 *
 * @file TIMER_InterruptRoutine_Vector_ModuleA_16_Module0.c
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
 * @verbatim 14 jul. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 14 jul. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/TIMER/Interrupt/InterruptRoutine/InterruptRoutine_Vector_ModuleA_16/xHeader/TIMER_InterruptRoutine_Vector_ModuleA_16_Module0.h>

#include <xApplication_MCU/TIMER/Intrinsics/xHeader/TIMER_Dependencies.h>

void GPTM0A__vIRQVectorHandler(void)
{
    volatile UBase_t uxReg = 0UL;
    volatile UBase_t uxReady = 0U;
    void(*pvfCallback)(void)  = (void(*)(void)) 0UL;

    uxReady = SYSCTL_PRTIMER_R;
    if(SYSCTL_PRTIMER_R_TIMER0_NOREADY == (SYSCTL_PRTIMER_R_TIMER0_MASK & uxReady))
    {
        pvfCallback = TIMER__pvfGetIRQSourceHandler(TIMER_enSUBMODULE_A, TIMER_enMODULE_NUM_0, TIMER_enINTERRUPT_SW);
        pvfCallback(GPTM0_BASE, TIMER_enINTERRUPT_SW);
    }
    else
    {
        uxReg = (UBase_t) GPTM0_TA_TnMIS_R;

        if(0UL == ((UBase_t) TIMER_enINT_TA_ALL & uxReg))
        {
            pvfCallback = TIMER__pvfGetIRQSourceHandler(TIMER_enSUBMODULE_A, TIMER_enMODULE_NUM_0, TIMER_enINTERRUPT_SW);
            pvfCallback();
        }
        else
        {
            if((UBase_t) TIMER_enINT_TA_TIMEOUT & uxReg)
            {
                GPTM0_TA_TnICR_R = (UBase_t) TIMER_enINT_TA_TIMEOUT;
                pvfCallback = TIMER__pvfGetIRQSourceHandler(TIMER_enSUBMODULE_A,
                                                            TIMER_enMODULE_NUM_0,
                                                            TIMER_enINTERRUPT_TIMEOUT);
                pvfCallback();
            }
            if((UBase_t) TIMER_enINT_TA_CAPTURE_MATCH & uxReg)
            {
                GPTM0_TA_TnICR_R = (UBase_t) TIMER_enINT_TA_CAPTURE_MATCH;
                pvfCallback = TIMER__pvfGetIRQSourceHandler(TIMER_enSUBMODULE_A,
                                                            TIMER_enMODULE_NUM_0,
                                                            TIMER_enINTERRUPT_CAPTURE_MATCH);
                pvfCallback();
            }
            if((UBase_t) TIMER_enINT_TA_CAPTURE_EVENT & uxReg)
            {
                GPTM0_TA_TnICR_R = (UBase_t) TIMER_enINT_TA_CAPTURE_EVENT;
                pvfCallback = TIMER__pvfGetIRQSourceHandler(TIMER_enSUBMODULE_A,
                                                            TIMER_enMODULE_NUM_0,
                                                            TIMER_enINTERRUPT_CAPTURE_EVENT);
                pvfCallback();
            }
            if((UBase_t) TIMER_enINT_TW_RTC & uxReg)
            {
                GPTM0_TA_TnICR_R = (UBase_t) TIMER_enINT_TW_RTC;
                pvfCallback = TIMER__pvfGetIRQSourceHandler(TIMER_enSUBMODULE_A,
                                                            TIMER_enMODULE_NUM_0,
                                                            TIMER_enINTERRUPT_RTC);
                pvfCallback();
            }
            if((UBase_t) TIMER_enINT_TA_MATCH & uxReg)
            {
                GPTM0_TA_TnICR_R = (UBase_t) TIMER_enINT_TA_MATCH;
                pvfCallback = TIMER__pvfGetIRQSourceHandler(TIMER_enSUBMODULE_A,
                                                            TIMER_enMODULE_NUM_0,
                                                            TIMER_enINTERRUPT_MATCH);
                pvfCallback();
            }
            if((UBase_t) TIMER_enINT_TA_DMA & uxReg)
            {
                GPTM0_TA_TnICR_R = (UBase_t) TIMER_enINT_TA_DMA;
                pvfCallback = TIMER__pvfGetIRQSourceHandler(TIMER_enSUBMODULE_A,
                                                            TIMER_enMODULE_NUM_0,
                                                            TIMER_enINTERRUPT_DMA);
                pvfCallback();
            }
        }
    }
}
