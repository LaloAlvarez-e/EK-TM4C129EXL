/**
 *
 * @file GPIO_Resistor.c
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
 * @verbatim 30 jun. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 30 jun. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/GPIO/Driver/xHeader/GPIO_Resistor.h>

#include <xDriver_MCU/GPIO/Driver/Intrinsics/xHeader/GPIO_Commit.h>
#include <xDriver_MCU/GPIO/Driver/Intrinsics/GPIO_Intrinsics.h>
#include <xDriver_MCU/GPIO/Peripheral/GPIO_Peripheral.h>

void GPIO__vSetResistorMode(GPIO_nPORT enPort, GPIO_nPIN enPin, GPIO_nRESMODE enModeArg)
{
    GPIO_nPORT enPortReg = enPort;
    GPIO_nPIN enPinReg = enPin;
    GPIO_nRESMODE enModeReg = enModeArg;

    GPIO__vSetCommit(enPortReg, enPinReg, GPIO_enCOMMIT_ENA);
    switch(enModeReg)
    {
        case GPIO_enRESMODE_INACTIVE:
            GPIO__vDisGeneric(enPortReg, GPIO_PUR_OFFSET, enPinReg);
            GPIO__vDisGeneric(enPortReg, GPIO_PDR_OFFSET, enPinReg);
            break;
        case GPIO_enRESMODE_PULLUP:
            GPIO__vEnGeneric(enPortReg, GPIO_PUR_OFFSET, enPinReg);
            GPIO__vDisGeneric(enPortReg, GPIO_PDR_OFFSET, enPinReg);
            break;
        case GPIO_enRESMODE_PULLDOWN:
            GPIO__vDisGeneric(enPortReg, GPIO_PUR_OFFSET, enPinReg);
            GPIO__vEnGeneric(enPortReg, GPIO_PDR_OFFSET, enPinReg);
            break;
        default:
            break;
    }
}

GPIO_nRESMODE GPIO__enGetResistorMode(GPIO_nPORT enPort, GPIO_nPIN enPin)
{
    GPIO_nRESMODE enResistorType = GPIO_enRESMODE_INACTIVE;
    uint32_t u32PullUp = 0UL;
    uint32_t u32PullDown = 0UL;
    u32PullUp = GPIO__u32GetGeneric(enPort, GPIO_PUR_OFFSET, enPin);
    u32PullDown = GPIO__u32GetGeneric(enPort, GPIO_PDR_OFFSET, enPin);

    if((0UL == u32PullUp) && (0UL == u32PullDown))
    {
        enResistorType = GPIO_enRESMODE_INACTIVE;
    }
    else if(0UL != u32PullUp)
    {
        enResistorType = GPIO_enRESMODE_PULLUP;
    }
    else if(0UL != u32PullDown)
    {
        enResistorType = GPIO_enRESMODE_PULLDOWN;
    }
    else{}

    return (enResistorType);
}
