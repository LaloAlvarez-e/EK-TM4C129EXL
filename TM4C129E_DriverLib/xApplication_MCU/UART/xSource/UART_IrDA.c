/**
 *
 * @file UART_IrDA.c
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
 * @verbatim 13 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 13 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/UART/xHeader/UART_IrDA.h>

#include <xApplication_MCU/UART/Intrinsics/xHeader/UART_Dependencies.h>


UART_nERROR UART__enSetIrDALowPowerFrequency(UART_nMODULE enModule)
{
    MCU_nSTATUS enFPUActive = MCU__enGetFPUContextActive();
    UART_nERROR enErrorReg;
    UBase_t uxSysClockReg;

    uxSysClockReg = 0UL;
    SYSCTL__enGetSystemClockFrequency(SYSCTL_enMODULE_0, &uxSysClockReg);
    float32_t f32DividerReg;
    f32DividerReg = (float32_t) uxSysClockReg;
    f32DividerReg /= 1843200.0f; /*IrDA Low Power frequency*/
    f32DividerReg += 0.5f;
    uxSysClockReg = (UBase_t) f32DividerReg;
    enErrorReg = UART__enSetIrDALowPowerDivisor(enModule, uxSysClockReg);
    MCU__vSetFPUContextActive(enFPUActive);
    return (enErrorReg);
}

UART_nERROR UART__enGetIrDALowPowerFrequency(UART_nMODULE enModule, UBase_t* puxFrequencyArg)
{
    MCU_nSTATUS enFPUActive = MCU__enGetFPUContextActive();
    UART_nERROR enErrorReg;
    UBase_t uxSysClockReg;
    UBase_t uxDividerReg;

    uxSysClockReg = 0UL;
    uxDividerReg = 0UL;

    enErrorReg = UART_enERROR_OK;
    if(0UL == (uintptr_t) puxFrequencyArg)
    {
        enErrorReg = UART_enERROR_POINTER;
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        enErrorReg = (UART_nERROR) SYSCTL__enGetSystemClockFrequency(SYSCTL_enMODULE_0, &uxSysClockReg);
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        enErrorReg = UART__enGetIrDALowPowerDivisor(enModule, &uxDividerReg);
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        float32_t f32DividerReg;
        f32DividerReg = (float32_t) uxSysClockReg;
        f32DividerReg /= (float32_t) uxDividerReg;
        *puxFrequencyArg = (UBase_t) f32DividerReg;
    }

    MCU__vSetFPUContextActive(enFPUActive);
    return (enErrorReg);
}
