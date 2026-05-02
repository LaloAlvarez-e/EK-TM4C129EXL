/**
 *
 * @file HIB_Counter.c
 * @copyright
 * @verbatim InDeviceMex 2026 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 6 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 6 abr. 2026    vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/HIB/Driver/xHeader/HIB_Counter.h>

#include <xDriver_MCU/HIB/Driver/Intrinsics/HIB_Intrinsics.h>
#include <xDriver_MCU/HIB/Peripheral/HIB_Peripheral.h>


HIB_nERROR HIB__enSetRTCCounterTrim(HIB_nMODULE enModuleArg, UBase_t uxSubSecondsArg)
{
    HIB_nERROR enErrorReg;
    HIB_Register_t stRegister;

    stRegister.uxShift = HIB_RTCT_R_TRIM_BIT;
    stRegister.uxMask = HIB_RTCT_R_TRIM_MASK;
    stRegister.uptrAddress = HIB_RTCT_OFFSET;
    stRegister.uxValue = uxSubSecondsArg;
    
    enErrorReg = HIB__enWriteRegister(enModuleArg, &stRegister);

    return (enErrorReg);
}


HIB_nERROR HIB__enGetRTCCounterTrim(HIB_nMODULE enModuleArg, UBase_t* puxSubSecondsArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) puxSubSecondsArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        HIB_Register_t stRegister;
        stRegister.uxShift = HIB_RTCT_R_TRIM_BIT;
        stRegister.uxMask = HIB_RTCT_R_TRIM_MASK;
        stRegister.uptrAddress = HIB_RTCT_OFFSET;
        stRegister.uxValue = 0UL;
        enErrorReg = HIB__enReadRegister(enModuleArg, &stRegister);
        if(HIB_enERROR_OK == enErrorReg)
        {
            *puxSubSecondsArg = stRegister.uxValue;
        }
    }

    return (enErrorReg);
}

HIB_nERROR HIB__enSetRTCCounterTrimRelative(HIB_nMODULE enModuleArg, int16_t s16ChangeArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxCurrentTrim;
    
    enErrorReg = HIB__enGetRTCCounterTrim(enModuleArg, &uxCurrentTrim);
    if(HIB_enERROR_OK == enErrorReg)
    {
        uxCurrentTrim += s16ChangeArg;
        enErrorReg = HIB__enSetRTCCounterTrim(enModuleArg, uxCurrentTrim);
    }

    return (enErrorReg);
}

HIB_nERROR HIB__enSetRTCCounterMatch(HIB_nMODULE enModuleArg, UBase_t uxSecondsArg, UBase_t uxSubSecondsArg)
{
    HIB_nERROR enErrorReg;
    HIB_Register_t stRegisterMatch;
    HIB_Register_t stSubRegisterMatch;

    stRegisterMatch.uxShift = HIB_RTCM0_R_RTCM0_BIT;
    stRegisterMatch.uxMask = HIB_RTCM0_R_RTCM0_MASK;
    stRegisterMatch.uptrAddress = HIB_RTCM0_OFFSET;
    stRegisterMatch.uxValue = uxSecondsArg;

    stSubRegisterMatch.uxShift = HIB_RTCSS_R_RTCSSM_BIT;
    stSubRegisterMatch.uxMask = HIB_RTCSS_R_RTCSSM_MASK;
    stSubRegisterMatch.uptrAddress = HIB_RTCSS_OFFSET;
    stSubRegisterMatch.uxValue = uxSubSecondsArg;

    enErrorReg = HIB__enWriteRegister(enModuleArg, &stRegisterMatch);

    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enWriteRegister(enModuleArg, &stSubRegisterMatch);
    }

    return (enErrorReg);
}

HIB_nERROR HIB__enGetRTCCounterMatch(HIB_nMODULE enModuleArg, UBase_t* puxSecondsArg, UBase_t* puxSubSecondsArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = ((0UL == (uintptr_t) puxSecondsArg) || (0UL == (uintptr_t) puxSubSecondsArg)) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        HIB_Register_t stRegister;
        stRegister.uxShift = HIB_RTCM0_R_RTCM0_BIT;
        stRegister.uxMask = HIB_RTCM0_R_RTCM0_MASK;
        stRegister.uptrAddress = HIB_RTCM0_OFFSET;
        stRegister.uxValue = 0UL;
        enErrorReg = HIB__enReadRegister(enModuleArg, &stRegister);
        if(HIB_enERROR_OK == enErrorReg)
        {
            *puxSecondsArg = stRegister.uxValue;
        }
    }

    if(HIB_enERROR_OK == enErrorReg)
    {
        HIB_Register_t stSubRegister;
        stSubRegister.uxShift = HIB_RTCSS_R_RTCSSM_BIT;
        stSubRegister.uxMask = HIB_RTCSS_R_RTCSSM_MASK;
        stSubRegister.uptrAddress = HIB_RTCSS_OFFSET;
        stSubRegister.uxValue = 0UL;
        enErrorReg = HIB__enReadRegister(enModuleArg, &stSubRegister);
        if(HIB_enERROR_OK == enErrorReg)
        {
            *puxSubSecondsArg = stSubRegister.uxValue;
        }
    }

    return (enErrorReg);
}

HIB_nERROR HIB__enSetRTCCounterValue(HIB_nMODULE enModuleArg, UBase_t uxValueArg)
{
    /*Subsecond counter is cleared to 0 when the RTC load register is written*/
    HIB_nERROR enErrorReg;
    HIB_Register_t stRegister;

    stRegister.uxShift = HIB_RTCLD_R_RTCLD_BIT;
    stRegister.uxMask = HIB_RTCLD_RTCLD_MASK;
    stRegister.uptrAddress = HIB_RTCLD_OFFSET;
    stRegister.uxValue = uxValueArg;

    enErrorReg = HIB__enUnlock(enModuleArg);
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enWriteRegister(enModuleArg, &stRegister);
    }
    HIB__enLock(enModuleArg);

    return (enErrorReg);
}

HIB_nERROR HIB__enGetRTCCounterValue(HIB_nMODULE enModuleArg, UBase_t* puxSecondsArg, UBase_t* puxSubSecondsArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxRetry;
    UBase_t uxOldValue;
    UBase_t uxNewValue;
    UBase_t uxSubSecondsValue;
    HIB_Register_t stRegister;
    HIB_Register_t stSubRegister;

    uxRetry = 1000UL;
    uxOldValue = 0UL;
    uxNewValue = 0UL;
    uxSubSecondsValue = 0UL;
    
    stRegister.uxShift = HIB_RTCC_R_RTCC_BIT;
    stRegister.uxMask = HIB_RTCC_RTCC_MASK;
    stRegister.uptrAddress = HIB_RTCC_OFFSET;
    stRegister.uxValue = 0UL;

    stSubRegister.uxShift = HIB_RTCSS_R_RTCSSC_BIT;
    stSubRegister.uxMask = HIB_RTCSS_RTCSSC_MASK;
    stSubRegister.uptrAddress = HIB_RTCSS_OFFSET;
    stSubRegister.uxValue = 0UL;

    enErrorReg = ((0UL == (uintptr_t) puxSecondsArg) || (0UL == (uintptr_t) puxSubSecondsArg)) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadRegister(enModuleArg, &stRegister);
    }

    if(HIB_enERROR_OK == enErrorReg)
    {
        uxOldValue = stRegister.uxValue;
        /*Subseconds will be set in the New value second*/
        enErrorReg = HIB__enReadRegister(enModuleArg, &stSubRegister);
    }
    
    if(HIB_enERROR_OK == enErrorReg)
    {
        boolean_t uxValid = FALSE;
        do
        {   
            stRegister.uxValue = 0UL;
            enErrorReg = HIB__enReadRegister(enModuleArg, &stRegister);

            if(HIB_enERROR_OK == enErrorReg)
            {
                /*Set the subseconds value with the previous read value*/
                uxSubSecondsValue = stSubRegister.uxValue;
                stSubRegister.uxValue = 0UL;
                enErrorReg = HIB__enReadRegister(enModuleArg, &stSubRegister);
            }

            if(HIB_enERROR_OK == enErrorReg)
            {
                uxNewValue = stRegister.uxValue;
                if(uxOldValue == uxNewValue)
                {
                    uxValid = TRUE;
                }
                uxOldValue = uxNewValue;
            }
            uxRetry--;
        }while((FALSE == uxValid) && (0UL < uxRetry) && (HIB_enERROR_OK == enErrorReg));

        
        if(HIB_enERROR_OK == enErrorReg)
        {
            if((FALSE == uxValid) && (0UL == uxRetry))
            {
                enErrorReg = HIB_enERROR_TIMEOUT;
            }
        }    
    }
    
    if(HIB_enERROR_OK == enErrorReg)
    {
        *puxSecondsArg = uxNewValue;
        *puxSubSecondsArg = uxSubSecondsValue;
    }

    return (enErrorReg);
}
