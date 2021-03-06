/**
 *
 * @file GPIO_InterruptSource.c
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
 * @verbatim 2 jul. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 2 jul. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/GPIO/Driver/Intrinsics/Interrupt/xHeader/GPIO_InterruptSource.h>

#include <xDriver_MCU/GPIO/Driver/Intrinsics/Primitives/GPIO_Primitives.h>
#include <xDriver_MCU/GPIO/Peripheral/GPIO_Peripheral.h>

void GPIO__vEnInterruptSource(GPIO_nPORT enPort, GPIO_nPIN enPin)
{
    GPIO__vWriteRegister(enPort, GPIO_IM_OFFSET, (uint32_t) enPin, (uint32_t) enPin, 0UL);
}

void GPIO__vDisInterruptSource(GPIO_nPORT enPort, GPIO_nPIN enPin)
{
    GPIO__vWriteRegister(enPort, GPIO_IM_OFFSET, 0UL, (uint32_t) enPin, 0UL);
}

void GPIO__vClearInterruptSource(GPIO_nPORT enPort, GPIO_nPIN enPin)
{
    GPIO__vWriteRegister(enPort, GPIO_ICR_OFFSET,
             (uint32_t) enPin, (uint32_t) enPin, 0UL);
}

void GPIO__vEnInterruptSourceDMA(GPIO_nPORT enPort)
{
    GPIO__vWriteRegister(enPort, GPIO_IM_OFFSET,
         GPIO_IM_DMAIME_ENA, GPIO_IM_DMAIME_MASK, GPIO_IM_R_DMAIME_BIT);
}

void GPIO__vDisInterruptSourceDMA(GPIO_nPORT enPort)
{
    GPIO__vWriteRegister(enPort, GPIO_IM_OFFSET,
         GPIO_IM_DMAIME_DIS, GPIO_IM_DMAIME_MASK, GPIO_IM_R_DMAIME_BIT);
}

void GPIO__vClearInterruptSourceDMA(GPIO_nPORT enPort)
{
    GPIO__vWriteRegister(enPort, GPIO_ICR_OFFSET,
         GPIO_ICR_DMAIC_CLEAR, GPIO_ICR_DMAIC_MASK, GPIO_ICR_R_DMAIC_BIT);
}

GPIO_nPIN GPIO__enStatusInterruptSource(GPIO_nPORT enPort, GPIO_nPIN enPin)
{
    GPIO_nPIN enStatus = GPIO_enPIN_NONE;
    uint32_t u32Reg = 0UL;

    u32Reg = GPIO__u32ReadRegister(enPort, GPIO_RIS_OFFSET, (uint32_t) enPin, 0UL);
    enStatus = (GPIO_nPIN) u32Reg;

    return (enStatus);
}

GPIO_nINT_STATUS GPIO__enStatusInterruptSourceDMA(GPIO_nPORT enPort)
{
    GPIO_nINT_STATUS enStatus = GPIO_enINT_STATUS_NOOCCUR;
    uint32_t u32Reg = 0UL;

    u32Reg = GPIO__u32ReadRegister(enPort, GPIO_RIS_OFFSET,
                                   GPIO_RIS_DMARIS_MASK, GPIO_RIS_R_DMARIS_BIT);
    if(0UL != u32Reg)
    {
        enStatus = GPIO_enINT_STATUS_OCCUR;
    }
    else
    {
        enStatus = GPIO_enINT_STATUS_NOOCCUR;
    }
    return (enStatus);
}
