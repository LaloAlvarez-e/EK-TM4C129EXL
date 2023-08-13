/**
 *
 * @file GPIO_InterruptEdge.c
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
#include <xDriver_MCU/GPIO/Driver/Intrinsics/xHeader/GPIO_InterruptEdge.h>

#include <xDriver_MCU/GPIO/Driver/Intrinsics/xHeader/GPIO_InterruptSense.h>
#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/GPIO/Driver/Intrinsics/Primitives/GPIO_Primitives.h>
#include <xDriver_MCU/GPIO/Peripheral/GPIO_Peripheral.h>

GPIO_nERROR GPIO__enSetInterruptEdgeByMask(GPIO_nPORT enPortArg, GPIO_nPINMASK enPinMaskArg,
                                           GPIO_nEDGE enEdgeArg)
{
    GPIO_nERROR enErrorReg;
    enErrorReg = (GPIO_nERROR) MCU__enCheckParams((UBase_t) enPinMaskArg, (UBase_t) GPIO_enPINMASK_MAX);
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = GPIO__enSetInterruptSenseByMask(enPortArg, enPinMaskArg, GPIO_enSENSE_EDGE);
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        UBase_t uxValueBothReg = (GPIO_enEDGE_BOTH == enEdgeArg) ? (UBase_t) enPinMaskArg : 0UL;
        GPIO_Register_t stRegister;
        stRegister.uxShift = GPIO_IBE_R_PIN0_BIT;
        stRegister.uxMask = (UBase_t) enPinMaskArg;
        stRegister.uptrAddress = GPIO_IBE_OFFSET;
        stRegister.uxValue = uxValueBothReg;
        enErrorReg = GPIO__enWriteRegister(enPortArg, &stRegister);
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        UBase_t uxValueEdgeReg;
        if(GPIO_enEDGE_BOTH == enEdgeArg)
        {
            uxValueEdgeReg = 0UL;
        }
        else
        {
            uxValueEdgeReg = (GPIO_enEDGE_FALLING == enEdgeArg) ? 0UL : (UBase_t) enPinMaskArg;
        }
        GPIO_Register_t stRegister;
        stRegister.uxShift = GPIO_IEV_R_PIN0_BIT;
        stRegister.uxMask = (UBase_t) enPinMaskArg;
        stRegister.uptrAddress = GPIO_IEV_OFFSET;
        stRegister.uxValue = uxValueEdgeReg;
        enErrorReg = GPIO__enWriteRegister(enPortArg, &stRegister);
    }
    return (enErrorReg);
}

GPIO_nERROR GPIO__enSetInterruptEdgeByNumber(GPIO_nPORT enPortArg, GPIO_nPIN enPinArg,
                                              GPIO_nEDGE enEdgeArg)
{
    GPIO_nERROR enErrorReg;
    enErrorReg = (GPIO_nERROR) MCU__enCheckParams((UBase_t) enPinArg, (UBase_t) GPIO_enPIN_MAX);
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = GPIO__enSetInterruptSenseByNumber(enPortArg, enPinArg, GPIO_enSENSE_EDGE);
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        UBase_t uxValueBothReg = (GPIO_enEDGE_BOTH == enEdgeArg) ? GPIO_IBE_PIN0_BOTH : GPIO_IBE_PIN0_SINGLE;
        GPIO_Register_t stRegister;
        stRegister.uxShift = (UBase_t) enPinArg;
        stRegister.uxShift += GPIO_IBE_R_PIN0_BIT;
        stRegister.uxMask = GPIO_IBE_PIN0_MASK;
        stRegister.uptrAddress = GPIO_IBE_OFFSET;
        stRegister.uxValue = uxValueBothReg;
        enErrorReg = GPIO__enWriteRegister(enPortArg, &stRegister);
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        UBase_t uxValueEdgeReg = (GPIO_enEDGE_BOTH == enEdgeArg) ? GPIO_IEV_PIN0_FALLING : (UBase_t) enEdgeArg;
        GPIO_Register_t stRegister;
        stRegister.uxShift = (UBase_t) enPinArg;
        stRegister.uxShift += GPIO_IEV_R_PIN0_BIT;
        stRegister.uxMask = GPIO_IEV_PIN0_MASK;
        stRegister.uptrAddress = GPIO_IEV_OFFSET;
        stRegister.uxValue = uxValueEdgeReg;
        enErrorReg = GPIO__enWriteRegister(enPortArg, &stRegister);
    }
    return (enErrorReg);
}

GPIO_nERROR GPIO__enGetInterruptEdgeByNumber(GPIO_nPORT enPortArg, GPIO_nPIN enPinArg,
                                              GPIO_nEDGE* penEdgeArg)
{
    GPIO_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penEdgeArg) ? GPIO_enERROR_POINTER : GPIO_enERROR_OK;
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
    if((GPIO_enERROR_OK == enErrorReg) && (GPIO_enSENSE_EDGE != enSenseReg))
    {
        *penEdgeArg = GPIO_enEDGE_UNDEF;
    }

    if((GPIO_enERROR_OK == enErrorReg) && (GPIO_enSENSE_EDGE == enSenseReg))
    {
        GPIO_Register_t stRegister;
        stRegister.uxShift = (UBase_t) enPinArg;
        stRegister.uxShift += GPIO_IBE_R_PIN0_BIT;
        stRegister.uxMask = GPIO_IBE_PIN0_MASK;
        stRegister.uptrAddress = GPIO_IBE_OFFSET;
        enErrorReg = GPIO__enReadRegister(enPortArg, &stRegister);
        if(GPIO_enERROR_OK == enErrorReg)
        {
            if(GPIO_IBE_PIN0_SINGLE == stRegister.uxValue)
            {
                stRegister.uxShift = (UBase_t) enPinArg;
                stRegister.uxShift += GPIO_IEV_R_PIN0_BIT;
                stRegister.uxMask = GPIO_IEV_PIN0_MASK;
                stRegister.uptrAddress = GPIO_IEV_OFFSET;
                enErrorReg = GPIO__enReadRegister(enPortArg, &stRegister);
                if(GPIO_enERROR_OK == enErrorReg)
                {
                    *penEdgeArg = (GPIO_nEDGE) stRegister.uxValue;
                }
            }
            else
            {
                *penEdgeArg = GPIO_enEDGE_BOTH;
            }
        }
    }
    return (enErrorReg);
}
