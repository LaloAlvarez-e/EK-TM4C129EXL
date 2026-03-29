/**
 *
 * @file SYSCTL_PeripheralDeepSleepMode.c
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
 * @verbatim 24 jun. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 24 jun. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_PeripheralDeepSleepMode.h>

#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_PeripheralReady.h>
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_PeripheralGeneric.h>
#include <xDriver_MCU/SYSCTL/Peripheral/SYSCTL_Peripheral.h>


SYSCTL_nERROR SYSCTL__enSetDeepSleepModeState(SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg, SYSCTL_nSTATE enStateArg)
{

    SYSCTL_Register_t stRegister;
    stRegister.uptrAddress = SYSCTL_DCGC_OFFSET;
    stRegister.uxValue = (UBase_t) enStateArg;

    SYSCTL_nERROR enErrorReg;
    enErrorReg =SYSCTL__enWritePeripheral(enModuleArg, enPeripheralArg, &stRegister);
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        SYSCTL_nBOOLEAN enStatusReg = SYSCTL_enFALSE;
        do
        {
            enErrorReg = SYSCTL__enIsPeripheralReady(enModuleArg, enPeripheralArg, &enStatusReg);
        }while((SYSCTL_enERROR_OK == enErrorReg) && (SYSCTL_enFALSE == enStatusReg));
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enEnableDeepSleepMode(SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg =SYSCTL__enSetDeepSleepModeState(enModuleArg, enPeripheralArg, SYSCTL_enSTATE_ENA);
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enDisableDeepSleepMode(SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg =SYSCTL__enSetDeepSleepModeState(enModuleArg, enPeripheralArg, SYSCTL_enSTATE_DIS);
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enGetDeepSleepModeState(SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg, SYSCTL_nSTATE* penStateArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penStateArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK ==  enErrorReg)
    {
        SYSCTL_Register_t stRegister;
        stRegister.uptrAddress = SYSCTL_DCGC_OFFSET;
        enErrorReg =SYSCTL__enReadPeripheral(enModuleArg, enPeripheralArg, &stRegister);
        if(SYSCTL_enERROR_OK ==  enErrorReg)
        {
            *penStateArg = (SYSCTL_nSTATE) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}
