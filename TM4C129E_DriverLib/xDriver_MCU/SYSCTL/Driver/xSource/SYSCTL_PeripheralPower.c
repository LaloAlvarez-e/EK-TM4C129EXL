/*
 * SYSCTL_PeripheralPower.c
 *
 *  Created on: 13 jun. 2021
 *      Author: InDeviceMex
 */
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_PeripheralPower.h>

#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_PeripheralGeneric.h>
#include <xDriver_MCU/SYSCTL/Peripheral/SYSCTL_Peripheral.h>


SYSCTL_nERROR SYSCTL__enSetPowerControlState(SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg, SYSCTL_nSTATE enStateArg)
{
    SYSCTL_Register_t stRegister;
    stRegister.uptrAddress = SYSCTL_PC_OFFSET;
    stRegister.uxValue = (UBase_t) enStateArg;

    SYSCTL_nERROR enErrorReg;
    enErrorReg =SYSCTL__enWritePeripheral(enModuleArg, enPeripheralArg, &stRegister);
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enPowerOn(SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg =SYSCTL__enSetPowerControlState(enModuleArg, enPeripheralArg, SYSCTL_enSTATE_ENA);
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enPowerOff(SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg =SYSCTL__enSetPowerControlState(enModuleArg, enPeripheralArg, SYSCTL_enSTATE_DIS);
    return (enErrorReg);
}


SYSCTL_nERROR SYSCTL__enGetPowerControlState(SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg, SYSCTL_nSTATE* penStateArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penStateArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK ==  enErrorReg)
    {
        SYSCTL_Register_t stRegister;
        stRegister.uptrAddress = SYSCTL_PC_OFFSET;
        enErrorReg =SYSCTL__enReadPeripheral(enModuleArg, enPeripheralArg, &stRegister);
        if(SYSCTL_enERROR_OK ==  enErrorReg)
        {
            *penStateArg = (SYSCTL_nSTATE) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}
