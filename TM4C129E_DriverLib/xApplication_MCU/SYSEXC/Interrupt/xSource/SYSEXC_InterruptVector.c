/**
 *
 * @file SYSEXC_InterruptVector.c
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
 * @verbatim 11 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 11 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/SYSEXC/Interrupt/xHeader/SYSEXC_InterruptVector.h>

#include <xApplication_MCU/SYSEXC/Intrinsics/xHeader/SYSEXC_Dependencies.h>

void SYSEXC__vEnInterruptVector(SYSEXC_nPRIORITY enSYSEXCPriority)
{
    NVIC_nSTIR enVector = NVIC_enSTIR_SYSEXC;

    enSYSEXCPriority &= 0x7U;
    NVIC__vSetEnableIRQ(enVector, (NVIC_nPRIORITY) enSYSEXCPriority);
}

void SYSEXC__vDisInterruptVector(void)
{
    NVIC_nSTIR enVector = NVIC_enSTIR_SYSEXC;
    NVIC__vClearEnableIRQ(enVector);
}
