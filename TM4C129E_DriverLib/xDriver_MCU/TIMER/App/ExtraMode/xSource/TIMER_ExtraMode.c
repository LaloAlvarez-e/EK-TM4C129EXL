/**
 *
 * @file TIMER_ExtraMode.c
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
 * @verbatim 16 jul. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 16 jul. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/TIMER/App/ExtraMode/TIMER_ExtraMode.h>

#include <stdlib.h>
#include <xDriver_MCU/TIMER/App/Mode/xHeader/TIMER_ModeStruct.h>
#include <xDriver_MCU/TIMER/Driver/TIMER_Driver.h>

TIMER_nSTATUS TIMER__enSetExtraModeStruct(TIMER_nMODULE enModule, const TIMER_EXTRAMODE_t* pstExtraMode)
{
    TIMER_nSTATUS enReturn = TIMER_enSTATUS_ERROR;
    if(0UL != (uint32_t) pstExtraMode)
    {
        TIMER__vSetWaitTrigger(enModule, pstExtraMode->enWaitTrigger);
        TIMER__vSetUpdateIntervalMode(enModule, pstExtraMode->enUpdateInterval);
        TIMER__vSetPWMInterrupt(enModule, pstExtraMode->enPWMInterrupt);
        TIMER__vSetMatchEventInterrupt(enModule, pstExtraMode->enEventInterrupt);
        TIMER__vSetUpdateMatchMode(enModule, pstExtraMode->enUpdateMatch);
        TIMER__vSetStall(enModule, pstExtraMode->enStall);
        TIMER__vSetRTCStall(enModule, pstExtraMode->enRTCStall);
        TIMER__vSetADCTrigger(enModule, pstExtraMode->enADCTrigger);
        TIMER__vSetTimeOutIntFunctionality(enModule, pstExtraMode->enTimeOutInterrupt);
        TIMER__vSetMatchEventAction(enModule,  pstExtraMode->enMatchEvent);
        enReturn = TIMER_enSTATUS_OK;
    }
    return (enReturn);
    /*Configure Reload and Match*/

    /*TIMER__vSetEnable(enModule, TIMER_enENABLE_START);*/


}

void TIMER__vGetExtraMode(TIMER_nMODULE enModule, TIMER_EXTRAMODE_t* pstExtraMode)
{
    if(0UL != (uint32_t) pstExtraMode)
    {
        pstExtraMode->enWaitTrigger = TIMER__enGetWaitTrigger(enModule);
        pstExtraMode->enUpdateInterval = TIMER__enGetUpdateIntervalMode(enModule);
        pstExtraMode->enPWMInterrupt = TIMER__enGetPWMInterrupt(enModule);
        pstExtraMode->enEventInterrupt = TIMER__enGetMatchEventInterrupt(enModule);
        pstExtraMode->enUpdateMatch = TIMER__enGetUpdateMatchMode(enModule);
        pstExtraMode->enStall = TIMER__enGetStall(enModule);
        pstExtraMode->enRTCStall = TIMER__enGetRTCStall(enModule);
        pstExtraMode->enADCTrigger = TIMER__enGetADCTrigger(enModule);
        pstExtraMode->enTimeOutInterrupt = TIMER__enGetTimeOutIntFunctionality(enModule);
        pstExtraMode->enMatchEvent = TIMER__enGetMatchEventAction(enModule);
    }
}



TIMER_EXTRAMODE_t* TIMER__pstGetExtraMode(TIMER_nMODULE enModule)
{
    TIMER_EXTRAMODE_t* pstExtraMode = 0UL;
    #if defined (__TI_ARM__ ) || defined (__MSP430__ )
    pstExtraMode = (TIMER_EXTRAMODE_t*) memalign((size_t) 4, (size_t) sizeof(TIMER_EXTRAMODE_t));
    #elif defined (__GNUC__ )
    pstExtraMode = (TIMER_EXTRAMODE_t*) malloc((size_t) sizeof(TIMER_EXTRAMODE_t));
    #endif

    if(0UL != (uint32_t) pstExtraMode)
    {
        pstExtraMode->enWaitTrigger = TIMER__enGetWaitTrigger(enModule);
        pstExtraMode->enUpdateInterval = TIMER__enGetUpdateIntervalMode(enModule);
        pstExtraMode->enPWMInterrupt = TIMER__enGetPWMInterrupt(enModule);
        pstExtraMode->enEventInterrupt = TIMER__enGetMatchEventInterrupt(enModule);
        pstExtraMode->enUpdateMatch = TIMER__enGetUpdateMatchMode(enModule);
        pstExtraMode->enStall = TIMER__enGetStall(enModule);
        pstExtraMode->enRTCStall = TIMER__enGetRTCStall(enModule);
        pstExtraMode->enADCTrigger = TIMER__enGetADCTrigger(enModule);
        pstExtraMode->enTimeOutInterrupt = TIMER__enGetTimeOutIntFunctionality(enModule);
        pstExtraMode->enMatchEvent = TIMER__enGetMatchEventAction(enModule);
    }
    return (pstExtraMode);
}
