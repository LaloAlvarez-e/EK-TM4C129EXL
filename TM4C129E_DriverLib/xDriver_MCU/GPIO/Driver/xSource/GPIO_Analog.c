/**
 *
 * @file GPIO_Analog.c
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
 * @verbatim 17 sep. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 17 sep. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/GPIO/Driver/xHeader/GPIO_Analog.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/GPIO/Driver/Intrinsics/GPIO_Intrinsics.h>
#include <xDriver_MCU/GPIO/Peripheral/GPIO_Peripheral.h>

GPIO_nERROR GPIO__enSetAnalogModeByMask(GPIO_nPORT enPortArg, GPIO_nPINMASK enPinMaskArg,
                                        GPIO_nSTATE enStateArg)
{
    GPIO_Register_t stRegister;
    UBase_t uxValueReg;
    GPIO_nERROR enErrorReg;

    enErrorReg = (GPIO_nERROR) MCU__enCheckParams((UBase_t) enPinMaskArg, (UBase_t) GPIO_enPINMASK_MAX);
    if(GPIO_enERROR_OK == enErrorReg)
    {
        if(GPIO_enSTATE_DIS == enStateArg)
        {
            uxValueReg = 0UL;
        }
        else
        {
            uxValueReg = (UBase_t) enPinMaskArg;
        }
        stRegister.uxShift = GPIO_AMSEL_R_PIN0_BIT;
        stRegister.uxMask = (UBase_t) enPinMaskArg;
        stRegister.uptrAddress = GPIO_AMSEL_OFFSET;
        stRegister.uxValue = uxValueReg;
        enErrorReg = GPIO__enWriteRegister(enPortArg, &stRegister);
    }

    return (enErrorReg);
}

GPIO_nERROR GPIO__enSetAnalogModeByNumber(GPIO_nPORT enPortArg, GPIO_nPIN enPinArg,
                                             GPIO_nSTATE enStateArg)
{
    GPIO_Register_t stRegister;
    GPIO_nERROR enErrorReg;

    enErrorReg = (GPIO_nERROR) MCU__enCheckParams((UBase_t) enPinArg, (UBase_t) GPIO_enPIN_MAX);
    if(GPIO_enERROR_OK == enErrorReg)
    {
        stRegister.uxShift = (UBase_t) enPinArg;
        stRegister.uxShift += GPIO_AMSEL_R_PIN0_BIT;
        stRegister.uxMask = GPIO_AMSEL_PIN0_MASK;
        stRegister.uptrAddress = GPIO_AMSEL_OFFSET;
        stRegister.uxValue = (UBase_t) enStateArg;
        enErrorReg = GPIO__enWriteRegister(enPortArg, &stRegister);
    }

    return (enErrorReg);
}

GPIO_nERROR GPIO__enEnableAnalogModeByMask(GPIO_nPORT enPortArg, GPIO_nPINMASK enPinMaskArg)
{
    GPIO_nERROR enReturnReg;
    enReturnReg = GPIO__enSetAnalogModeByMask(enPortArg, enPinMaskArg, GPIO_enSTATE_ENA);
    return (enReturnReg);
}

GPIO_nERROR GPIO__enEnableAnalogModeByNumber(GPIO_nPORT enPortArg, GPIO_nPIN enPinArg)
{
    GPIO_nERROR enReturnReg;
    enReturnReg = GPIO__enSetAnalogModeByNumber(enPortArg, enPinArg, GPIO_enSTATE_ENA);
    return (enReturnReg);
}

GPIO_nERROR GPIO__enDisableAnalogModeByMask(GPIO_nPORT enPortArg, GPIO_nPINMASK enPinMaskArg)
{
    GPIO_nERROR enReturnReg;
    enReturnReg = GPIO__enSetAnalogModeByMask(enPortArg, enPinMaskArg, GPIO_enSTATE_DIS);
    return (enReturnReg);
}

GPIO_nERROR GPIO__enDisableAnalogModeByNumber(GPIO_nPORT enPortArg, GPIO_nPIN enPinArg)
{
    GPIO_nERROR enReturnReg;
    enReturnReg = GPIO__enSetAnalogModeByNumber(enPortArg, enPinArg, GPIO_enSTATE_DIS);
    return (enReturnReg);
}

GPIO_nERROR GPIO__enGetAnalogModeByMask(GPIO_nPORT enPortArg, GPIO_nPINMASK enPinMaskArg,
                                             GPIO_nPINMASK* penPinMaskReqArg)
{
    GPIO_Register_t stRegister;
    GPIO_nERROR enErrorReg;

    enErrorReg = GPIO_enERROR_OK;
    if(0UL == (uintptr_t) penPinMaskReqArg)
    {
        enErrorReg = GPIO_enERROR_POINTER;
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = (GPIO_nERROR) MCU__enCheckParams((UBase_t) enPinMaskArg, (UBase_t) GPIO_enPINMASK_MAX);
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        stRegister.uxShift = GPIO_AMSEL_R_PIN0_BIT;
        stRegister.uxMask = (UBase_t) enPinMaskArg;
        stRegister.uptrAddress = GPIO_AMSEL_OFFSET;
        enErrorReg = GPIO__enReadRegister(enPortArg, &stRegister);
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        *penPinMaskReqArg = (GPIO_nPINMASK) stRegister.uxValue;
    }
    return (enErrorReg);
}

GPIO_nERROR GPIO__enGetAnalogModeByNumber(GPIO_nPORT enPortArg, GPIO_nPIN enPinArg,
                                             GPIO_nSTATE* penStateArg)
{
    GPIO_Register_t stRegister;
    GPIO_nERROR enErrorReg;

    enErrorReg = GPIO_enERROR_OK;
    if(0UL == (uintptr_t) penStateArg)
    {
        enErrorReg = GPIO_enERROR_POINTER;
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = (GPIO_nERROR) MCU__enCheckParams((UBase_t) enPinArg, (UBase_t) GPIO_enPIN_MAX);
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        stRegister.uxShift = (UBase_t) enPinArg;
        stRegister.uxShift += GPIO_AMSEL_R_PIN0_BIT;
        stRegister.uxMask = GPIO_AMSEL_PIN0_MASK;
        stRegister.uptrAddress = GPIO_AMSEL_OFFSET;
        enErrorReg = GPIO__enReadRegister(enPortArg, &stRegister);
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        *penStateArg = (GPIO_nSTATE) stRegister.uxValue;
    }

    return (enErrorReg);
}




