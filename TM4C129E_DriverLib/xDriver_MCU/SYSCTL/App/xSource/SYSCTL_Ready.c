/**
 *
 * @file SYSCTL_Ready.c
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
 * @verbatim 8 ago. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 8 ago. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/SYSCTL/App/xHeader/SYSCTL_Ready.h>

#include <xDriver_MCU/SYSCTL/Driver/SYSCTL_Driver.h>

SYSCTL_nERROR SYSCTL__enSetReadyOnRunMode(SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg)
{
    SYSCTL_nERROR enErrorReg;
    SYSCTL_nBOOLEAN enReady;
    enReady = SYSCTL_enFALSE;
    enErrorReg = SYSCTL__enIsPeripheralReady(enModuleArg, enPeripheralArg, &enReady);
    if((SYSCTL_enERROR_OK == enErrorReg) && (SYSCTL_enFALSE == enReady))
    {
        enErrorReg = SYSCTL__enEnableRunMode(enModuleArg, enPeripheralArg);
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            enErrorReg = SYSCTL__enSetPeripheralReset(enModuleArg, enPeripheralArg);
        }
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enClearReadyOnRunMode(SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg)
{
    SYSCTL_nERROR enErrorReg;
    SYSCTL_nBOOLEAN enReady;
    enReady = SYSCTL_enFALSE;
    enErrorReg = SYSCTL__enIsPeripheralReady(enModuleArg, enPeripheralArg, &enReady);
    if((SYSCTL_enERROR_OK == enErrorReg) && (SYSCTL_enTRUE == enReady))
    {
        enErrorReg = SYSCTL__enSetPeripheralReset(enModuleArg, enPeripheralArg);
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            enErrorReg = SYSCTL__enDisableRunMode(enModuleArg, enPeripheralArg);
        }
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enReset(SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg)
{
    SYSCTL_nERROR enErrorReg;
    SYSCTL_nBOOLEAN enReady;
    enReady = SYSCTL_enFALSE;
    enErrorReg = SYSCTL__enIsPeripheralReady(enModuleArg, enPeripheralArg, &enReady);
    if((SYSCTL_enERROR_OK == enErrorReg) && (SYSCTL_enTRUE == enReady))
    {
        enErrorReg = SYSCTL__enSetPeripheralReset(enModuleArg, enPeripheralArg);
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enIsReady(SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg, SYSCTL_nBOOLEAN* penReadyArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL__enIsPeripheralReady(enModuleArg, enPeripheralArg, penReadyArg);
    return (enErrorReg);
}
