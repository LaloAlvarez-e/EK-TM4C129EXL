/*
 * SYSCTL_GatingClock.c
 *
 *  Created on: 13 jun. 2021
 *      Author: InDeviceMex
 */
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_GatingClock.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/SYSCTL/Driver/Intrinsics/Primitives/SYSCTL_Primitives.h>
#include <xDriver_MCU/SYSCTL/Peripheral/SYSCTL_Peripheral.h>

SYSCTL_nERROR SYSCTL__enUpdateMemoryTiming(SYSCTL_nMODULE enModuleArg)
{
    SYSCTL_Register_t stRegister;
    stRegister.uxShift = RSCLK_CFG_R_MEMTIMU_BIT;
    stRegister.uxMask = RSCLK_CFG_MEMTIMU_MASK;
    stRegister.uptrAddress = RSCLK_CFG_OFFSET;
    stRegister.uxValue = RSCLK_CFG_MEMTIMU_UPDATE;

    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL__enWriteRegister(enModuleArg, &stRegister);
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enUpdatePLLValues(SYSCTL_nMODULE enModuleArg)
{
    SYSCTL_Register_t stRegister;
    stRegister.uxShift = RSCLK_CFG_R_NEW_PLLFREQ_BIT;
    stRegister.uxMask = RSCLK_CFG_NEW_PLLFREQ_MASK;
    stRegister.uptrAddress = RSCLK_CFG_OFFSET;
    stRegister.uxValue = RSCLK_CFG_NEW_PLLFREQ_UPDATE;

    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL__enWriteRegister(enModuleArg, &stRegister);
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enAllowChangeToSleepMode(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN enStateArg)
{
    SYSCTL_Register_t stRegister;
    stRegister.uxShift = RSCLK_CFG_R_ACG_BIT;
    stRegister.uxMask = RSCLK_CFG_ACG_MASK;
    stRegister.uptrAddress = RSCLK_CFG_OFFSET;
    stRegister.uxValue = (UBase_t) enStateArg;

    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL__enWriteRegister(enModuleArg, &stRegister);
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enIsAllowedChangeToSleepMode(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStateArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penStateArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        SYSCTL_Register_t stRegister;
        stRegister.uxShift = RSCLK_CFG_R_ACG_BIT;
        stRegister.uxMask = RSCLK_CFG_ACG_MASK;
        stRegister.uptrAddress = RSCLK_CFG_OFFSET;
        enErrorReg = SYSCTL__enReadRegister(enModuleArg, &stRegister);
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            *penStateArg = (SYSCTL_nBOOLEAN) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enSetSystemClockSource(SYSCTL_nMODULE enModuleArg, SYSCTL_nSYSCLK_SRC enSourceArg)
{
    SYSCTL_Register_t stRegister;
    stRegister.uxShift = RSCLK_CFG_R_USEPLL_BIT;
    stRegister.uxMask = RSCLK_CFG_USEPLL_MASK;
    stRegister.uptrAddress = RSCLK_CFG_OFFSET;
    stRegister.uxValue = (UBase_t) enSourceArg;

    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL__enWriteRegister(enModuleArg, &stRegister);
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enGetSystemClockSource(SYSCTL_nMODULE enModuleArg, SYSCTL_nSYSCLK_SRC* penSourceArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penSourceArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        SYSCTL_Register_t stRegister;
        stRegister.uxShift = RSCLK_CFG_R_USEPLL_BIT;
        stRegister.uxMask = RSCLK_CFG_USEPLL_MASK;
        stRegister.uptrAddress = RSCLK_CFG_OFFSET;
        enErrorReg = SYSCTL__enReadRegister(enModuleArg, &stRegister);
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            *penSourceArg = (SYSCTL_nSYSCLK_SRC) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enSetPLLClockSource(SYSCTL_nMODULE enModuleArg, SYSCTL_nOSCCLK_SRC enSourceArg)
{
    SYSCTL_Register_t stRegister;
    stRegister.uxShift = RSCLK_CFG_R_PLL_SRC_BIT;
    stRegister.uxMask = RSCLK_CFG_PLL_SRC_MASK;
    stRegister.uptrAddress = RSCLK_CFG_OFFSET;
    stRegister.uxValue = (UBase_t) enSourceArg;

    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL__enWriteRegister(enModuleArg, &stRegister);
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enGetPLLClockSource(SYSCTL_nMODULE enModuleArg, SYSCTL_nOSCCLK_SRC* penSourceArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penSourceArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        SYSCTL_Register_t stRegister;
        stRegister.uxShift = RSCLK_CFG_R_PLL_SRC_BIT;
        stRegister.uxMask = RSCLK_CFG_PLL_SRC_MASK;
        stRegister.uptrAddress = RSCLK_CFG_OFFSET;
        enErrorReg = SYSCTL__enReadRegister(enModuleArg, &stRegister);
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            *penSourceArg = (SYSCTL_nOSCCLK_SRC) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enSetOscillatorClockSource(SYSCTL_nMODULE enModuleArg, SYSCTL_nOSCCLK_SRC enSourceArg)
{
    SYSCTL_Register_t stRegister;
    stRegister.uxShift = RSCLK_CFG_R_OSC_SRC_BIT;
    stRegister.uxMask = RSCLK_CFG_OSC_SRC_MASK;
    stRegister.uptrAddress = RSCLK_CFG_OFFSET;
    stRegister.uxValue = (UBase_t) enSourceArg;

    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL__enWriteRegister(enModuleArg, &stRegister);
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enGetOscillatorClockSource(SYSCTL_nMODULE enModuleArg, SYSCTL_nOSCCLK_SRC* penSourceArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penSourceArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        SYSCTL_Register_t stRegister;
        stRegister.uxShift = RSCLK_CFG_R_OSC_SRC_BIT;
        stRegister.uxMask = RSCLK_CFG_OSC_SRC_MASK;
        stRegister.uptrAddress = RSCLK_CFG_OFFSET;
        enErrorReg = SYSCTL__enReadRegister(enModuleArg, &stRegister);
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            *penSourceArg = (SYSCTL_nOSCCLK_SRC) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}


SYSCTL_nERROR SYSCTL__enSetOscillatorClockDivisor(SYSCTL_nMODULE enModuleArg, UBase_t uxDivisorArg)
{
    SYSCTL_Register_t stRegister;
    stRegister.uxShift = RSCLK_CFG_R_OSC_SYSDIV_BIT;
    stRegister.uxMask = RSCLK_CFG_OSC_SYSDIV_MASK;
    stRegister.uptrAddress = RSCLK_CFG_OFFSET;
    stRegister.uxValue = (UBase_t) uxDivisorArg;

    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL__enWriteRegister(enModuleArg, &stRegister);
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enGetOscillatorClockDivisor(SYSCTL_nMODULE enModuleArg, UBase_t* puxDivisorArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) puxDivisorArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        SYSCTL_Register_t stRegister;
        stRegister.uxShift = RSCLK_CFG_R_OSC_SYSDIV_BIT;
        stRegister.uxMask = RSCLK_CFG_OSC_SYSDIV_MASK;
        stRegister.uptrAddress = RSCLK_CFG_OFFSET;
        enErrorReg = SYSCTL__enReadRegister(enModuleArg, &stRegister);
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            *puxDivisorArg = (UBase_t) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enSetPLLClockDivisor(SYSCTL_nMODULE enModuleArg, UBase_t uxDivisorArg)
{
    SYSCTL_Register_t stRegister;
    stRegister.uxShift = RSCLK_CFG_R_PLL_SYSDIV_BIT;
    stRegister.uxMask = RSCLK_CFG_PLL_SYSDIV_MASK;
    stRegister.uptrAddress = RSCLK_CFG_OFFSET;
    stRegister.uxValue = (UBase_t) uxDivisorArg;

    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL__enWriteRegister(enModuleArg, &stRegister);
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enGetPLLClockDivisor(SYSCTL_nMODULE enModuleArg, UBase_t* puxDivisorArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) puxDivisorArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        SYSCTL_Register_t stRegister;
        stRegister.uxShift = RSCLK_CFG_R_PLL_SYSDIV_BIT;
        stRegister.uxMask = RSCLK_CFG_PLL_SYSDIV_MASK;
        stRegister.uptrAddress = RSCLK_CFG_OFFSET;
        enErrorReg = SYSCTL__enReadRegister(enModuleArg, &stRegister);
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            *puxDivisorArg = (UBase_t) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}
