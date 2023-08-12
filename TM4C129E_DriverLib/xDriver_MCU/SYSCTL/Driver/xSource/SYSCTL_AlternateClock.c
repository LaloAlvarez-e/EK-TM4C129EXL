/*
 * SYSCTL_AlternateClock.c
 *
 *  Created on: 13 jun. 2021
 *      Author: InDeviceMex
 */
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_AlternateClock.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/SYSCTL/Driver/Intrinsics/Primitives/SYSCTL_Primitives.h>
#include <xDriver_MCU/SYSCTL/Peripheral/SYSCTL_Peripheral.h>

SYSCTL_nERROR SYSCTL__enSetAlternateClockSource(SYSCTL_nMODULE enModuleArg, SYSCTL_nALTCLK_SRC enSourceArg)
{
    SYSCTL_Register_t stRegister;
    stRegister.uxShift = ALTCLK_CFG_R_ALTCLK_BIT;
    stRegister.uxMask = ALTCLK_CFG_ALTCLK_MASK;
    stRegister.uptrAddress = ALTCLK_CFG_OFFSET;
    stRegister.uxValue = (UBase_t) enSourceArg;

    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL__enWriteRegister(enModuleArg, &stRegister);
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enGetAlternateClockSource(SYSCTL_nMODULE enModuleArg, SYSCTL_nALTCLK_SRC* penSourceArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penSourceArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        SYSCTL_Register_t stRegister;
        stRegister.uxShift = ALTCLK_CFG_R_ALTCLK_BIT;
        stRegister.uxMask = ALTCLK_CFG_ALTCLK_MASK;
        stRegister.uptrAddress = ALTCLK_CFG_OFFSET;
        enErrorReg = SYSCTL__enReadRegister(enModuleArg, &stRegister);
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            *penSourceArg = (SYSCTL_nALTCLK_SRC) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

