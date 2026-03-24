/**
 *
 * @file GPIO_AnalogFunction.c
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
 * @verbatim 3 jul. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 3 jul. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/GPIO/App/xHeader/GPIO_AnalogFunction.h>

#include <xDriver_MCU/GPIO/App/Config/GPIO_Config.h>
#include <xDriver_MCU/GPIO/Driver/GPIO_Driver.h>

GPIO_nERROR GPIO__enSetAnalogFunction(GPIO_nANALOG_FUNCTION enFunctionArg)
{
    GPIO_nERROR enErrorReg;
    enErrorReg = (GPIO_enAIN_UNDEF == enFunctionArg) ? GPIO_enERROR_VALUE : GPIO_enERROR_OK;

    UBase_t uxPortReg;
    UBase_t uxPinReg;
    uxPortReg = 0UL;
    uxPinReg = 0UL;
    if(GPIO_enERROR_OK == enErrorReg)
    {
        uxPortReg = (UBase_t) enFunctionArg;
        uxPortReg >>= 8UL;
        uxPortReg &= 0xFFUL;

        uxPinReg = (UBase_t) enFunctionArg;
        uxPinReg >>= 0UL;
        uxPinReg &= 0xFFUL;
    }

    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = GPIO__enSetCommitStateByNumber((GPIO_nPORT) uxPortReg, (GPIO_nPIN) uxPinReg, GPIO_enSTATE_ENA);
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = GPIO__enSetConfigByNumber((GPIO_nPORT) uxPortReg, (GPIO_nPIN) uxPinReg, GPIO_enCONFIG_INPUT_2MA_PUSHPULL);
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = GPIO__enDisableADCTriggerByNumber((GPIO_nPORT) uxPortReg, (GPIO_nPIN) uxPinReg);
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = GPIO__enSetFunctionByNumber((GPIO_nPORT) uxPortReg, (GPIO_nPIN) uxPinReg, GPIO_enFUNCTION_GPIO);
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = GPIO__enDisableDigitalModeByNumber((GPIO_nPORT) uxPortReg, (GPIO_nPIN) uxPinReg);
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = GPIO__enEnableAnalogModeByNumber((GPIO_nPORT) uxPortReg, (GPIO_nPIN) uxPinReg);
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = GPIO__enSetCommitStateByNumber((GPIO_nPORT) uxPortReg, (GPIO_nPIN) uxPinReg, GPIO_enSTATE_DIS);
    }

    return (enErrorReg);
}
