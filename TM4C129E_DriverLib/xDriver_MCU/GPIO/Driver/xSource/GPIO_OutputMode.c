/**
 *
 * @file GPIO_OutputMode.c
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
#include <xDriver_MCU/GPIO/Driver/xHeader/GPIO_OutputMode.h>

#include <xDriver_MCU/GPIO/Driver/Intrinsics/GPIO_Intrinsics.h>
#include <xDriver_MCU/GPIO/Peripheral/GPIO_Peripheral.h>

void GPIO__vSetOutputMode(GPIO_nPORT enPort, GPIO_nPIN enPin, GPIO_nOUTMODE enModeArg)
{
    GPIO__vSetGeneric(enPort, GPIO_ODR_OFFSET, enPin, (uint32_t) enModeArg);
}

GPIO_nOUTMODE GPIO__enGetOutputMode(GPIO_nPORT enPort, GPIO_nPIN enPin)
{
    GPIO_nOUTMODE enOutModeReg = GPIO_enOUTMODE_PP;
    enOutModeReg = (GPIO_nOUTMODE) GPIO__u32GetGeneric(enPort, GPIO_ODR_OFFSET, enPin);
    return (enOutModeReg);
}
