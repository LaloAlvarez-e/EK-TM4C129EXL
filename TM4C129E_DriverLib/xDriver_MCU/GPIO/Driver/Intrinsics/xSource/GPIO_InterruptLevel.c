/**
 *
 * @file GPIO_InterruptLevel.c
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
 * @verbatim Apr 6, 2021 @endverbatim
 *
 * @author
 * @verbatim indevicemex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * Apr 6, 2021        indevicemex    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/GPIO/Driver/Intrinsics/xHeader/GPIO_InterruptLevel.h>

#include <xDriver_MCU/GPIO/Driver/Intrinsics/xHeader/GPIO_InterruptSense.h>
#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/GPIO/Driver/Intrinsics/Primitives/GPIO_Primitives.h>
#include <xDriver_MCU/GPIO/Peripheral/GPIO_Peripheral.h>

GPIO_nERROR GPIO__enSetInterruptLevelByMask(GPIO_nPORT enPortArg, GPIO_nPINMASK enPinMaskArg,
                                            GPIO_nLEVEL enLevelArg)
{
    GPIO_nERROR enErrorReg;
    enErrorReg = (GPIO_nERROR) MCU__enCheckParams((UBase_t) enPinMaskArg, (UBase_t) GPIO_enPINMASK_MAX);
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = GPIO__enSetInterruptSenseByMask(enPortArg, enPinMaskArg, GPIO_enSENSE_LEVEL);
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        UBase_t uxValueReg = (GPIO_enLEVEL_LOW == enLevelArg) ? 0UL : (UBase_t) enPinMaskArg;
        GPIO_Register_t stRegister;
        stRegister.uxShift = GPIO_IEV_R_PIN0_BIT;
        stRegister.uxMask = (UBase_t) enPinMaskArg;
        stRegister.uptrAddress = GPIO_IEV_OFFSET;
        stRegister.uxValue = uxValueReg;
        enErrorReg = GPIO__enWriteRegister(enPortArg, &stRegister);
    }
    return (enErrorReg);
}

GPIO_nERROR GPIO__enSetInterruptLevelByNumber(GPIO_nPORT enPortArg, GPIO_nPIN enPinArg,
                                              GPIO_nLEVEL enLevelArg)
{
    GPIO_nERROR enErrorReg;
    enErrorReg = (GPIO_nERROR) MCU__enCheckParams((UBase_t) enPinArg, (UBase_t) GPIO_enPIN_MAX);
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = GPIO__enSetInterruptSenseByNumber(enPortArg, enPinArg, GPIO_enSENSE_LEVEL);
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        GPIO_Register_t stRegister;
        stRegister.uxShift = (UBase_t) enPinArg;
        stRegister.uxShift += GPIO_IEV_R_PIN0_BIT;
        stRegister.uxMask = GPIO_IEV_PIN0_MASK;
        stRegister.uptrAddress = GPIO_IEV_OFFSET;
        stRegister.uxValue = (UBase_t) enLevelArg;
        enErrorReg = GPIO__enWriteRegister(enPortArg, &stRegister);
    }
    return (enErrorReg);
}

GPIO_nERROR GPIO__enGetInterruptLevelByMask(GPIO_nPORT enPortArg, GPIO_nPINMASK enPinMaskArg,
                                            GPIO_nPINMASK* penPinMaskReqArg)
{
    GPIO_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penPinMaskReqArg) ? GPIO_enERROR_POINTER : GPIO_enERROR_OK;

    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = (GPIO_nERROR) MCU__enCheckParams((UBase_t) enPinMaskArg, (UBase_t) GPIO_enPINMASK_MAX);
    }

    UBase_t uxPinMaskReg;
    uxPinMaskReg = 0UL;
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = GPIO__enGetInterruptSenseByMask(enPortArg, enPinMaskArg, (GPIO_nPINMASK*) &uxPinMaskReg);
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        GPIO_Register_t stRegister;
        stRegister.uxShift = GPIO_IEV_R_PIN0_BIT;
        stRegister.uxMask = (UBase_t) enPinMaskArg;
        stRegister.uptrAddress = GPIO_IEV_OFFSET;
        enErrorReg = GPIO__enReadRegister(enPortArg, &stRegister);
        if(GPIO_enERROR_OK == enErrorReg)
        {
            uxPinMaskReg &= stRegister.uxValue;
            *penPinMaskReqArg = (GPIO_nPINMASK) uxPinMaskReg;
        }
    }
    return (enErrorReg);
}

GPIO_nERROR GPIO__enGetInterruptLevelByNumber(GPIO_nPORT enPortArg, GPIO_nPIN enPinArg,
                                              GPIO_nLEVEL* penLevelArg)
{
    GPIO_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penLevelArg) ? GPIO_enERROR_POINTER : GPIO_enERROR_OK;

    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = (GPIO_nERROR) MCU__enCheckParams((UBase_t) enPinArg, (UBase_t) GPIO_enPIN_MAX);
    }

    GPIO_nSENSE enSenseReg;
    enSenseReg = GPIO_enSENSE_UNDEF;
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = GPIO__enGetInterruptSenseByNumber(enPortArg, enPinArg, &enSenseReg);
    }

    if(GPIO_enERROR_OK == enErrorReg)
    {
        if(GPIO_enSENSE_LEVEL == enSenseReg)
        {
            GPIO_Register_t stRegister;
            stRegister.uxShift = (UBase_t) enPinArg;
            stRegister.uxShift += GPIO_IEV_R_PIN0_BIT;
            stRegister.uxMask = GPIO_IEV_PIN0_MASK;
            stRegister.uptrAddress = GPIO_IEV_OFFSET;
            enErrorReg = GPIO__enReadRegister(enPortArg, &stRegister);
            if(GPIO_enERROR_OK == enErrorReg)
            {
                *penLevelArg = (GPIO_nLEVEL) stRegister.uxValue;
            }
        }
        else
        {
            *penLevelArg = GPIO_enLEVEL_UNDEF;
        }
    }

    return (enErrorReg);
}

