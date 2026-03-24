/*
 * SYSCTL_MemoryTiming.c
 *
 *  Created on: 14 jun. 2021
 *      Author: InDeviceMex
 */
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_MemoryTiming.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/SYSCTL/Driver/Intrinsics/Primitives/SYSCTL_Primitives.h>
#include <xDriver_MCU/SYSCTL/Peripheral/SYSCTL_Peripheral.h>

#define TIMING_SIZE (6UL)
#define MAX_FREQ (120000000UL)

typedef struct
{
    UBase_t uxFrequency;
    SYSCTL_nMEM_HIGHTIME enMemoryHighTimeTiming;
    SYSCTL_nMEM_WAITSTATE enMemoryWaitStateTiming;
    SYSCTL_nMEM_CLOCKEDGE enMemoryClockEdgeTiming;
}SYSCTL_MEM_t;

static SYSCTL_nERROR SYSCTL__enGetPredefineMemoryTiming(UBase_t uxSystemClockArg,
                                              SYSCTL_nMEM_HIGHTIME* penMemoryHighTimeArg,
                                              SYSCTL_nMEM_WAITSTATE* penMemoryWaitStateArg,
                                              SYSCTL_nMEM_CLOCKEDGE* penMemoryClockEdgeArg);

static SYSCTL_nERROR SYSCTL__enGetPredefineMemoryTiming(UBase_t uxSystemClockArg,
                                              SYSCTL_nMEM_HIGHTIME* penMemoryHighTimeArg,
                                              SYSCTL_nMEM_WAITSTATE* penMemoryWaitStateArg,
                                              SYSCTL_nMEM_CLOCKEDGE* penMemoryClockEdgeArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL_enERROR_OK;
    if((0UL == (uintptr_t) penMemoryHighTimeArg)  ||
       (0UL == (uintptr_t) penMemoryWaitStateArg) ||
       (0UL == (uintptr_t) penMemoryClockEdgeArg))
    {
        enErrorReg = SYSCTL_enERROR_POINTER;
    }

    if((SYSCTL_enERROR_OK == enErrorReg) && (MAX_FREQ < uxSystemClockArg))
    {
        enErrorReg = SYSCTL_enERROR_VALUE;
    }

    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        static const SYSCTL_MEM_t stMemoryTiming[TIMING_SIZE] =
        {
            { 16000000UL, SYSCTL_enMEM_HIGHTIME_0_5, SYSCTL_enMEM_WAITSTATE_0, SYSCTL_enMEM_CLOCKEDGE_FAILING },
            { 40000000UL, SYSCTL_enMEM_HIGHTIME_1_5, SYSCTL_enMEM_WAITSTATE_1, SYSCTL_enMEM_CLOCKEDGE_RISING  },
            { 60000000UL, SYSCTL_enMEM_HIGHTIME_2_0, SYSCTL_enMEM_WAITSTATE_2, SYSCTL_enMEM_CLOCKEDGE_RISING  },
            { 80000000UL, SYSCTL_enMEM_HIGHTIME_2_5, SYSCTL_enMEM_WAITSTATE_3, SYSCTL_enMEM_CLOCKEDGE_RISING  },
            {100000000UL, SYSCTL_enMEM_HIGHTIME_3_0, SYSCTL_enMEM_WAITSTATE_4, SYSCTL_enMEM_CLOCKEDGE_RISING  },
            {120000000UL, SYSCTL_enMEM_HIGHTIME_3_5, SYSCTL_enMEM_WAITSTATE_5, SYSCTL_enMEM_CLOCKEDGE_RISING  },
        };
        UBase_t uxIterReg = 0UL;
        UBase_t uxFrequencyReg= 16000000UL;

        while(uxSystemClockArg > uxFrequencyReg)
        {
            uxIterReg += 1UL;
            uxFrequencyReg = (UBase_t) stMemoryTiming[uxIterReg].uxFrequency;
        }
        *penMemoryHighTimeArg = stMemoryTiming[uxIterReg].enMemoryHighTimeTiming;
        *penMemoryWaitStateArg = stMemoryTiming[uxIterReg].enMemoryWaitStateTiming;
        *penMemoryClockEdgeArg = stMemoryTiming[uxIterReg].enMemoryClockEdgeTiming;
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enSetMemoryHighTime(SYSCTL_nMODULE enModuleArg, SYSCTL_nMEM_HIGHTIME enHighTimeArg)
{
    SYSCTL_Register_t stRegister;
    stRegister.uxShift = MEMORY_TIM0_R_FLASH_BCHT_BIT;
    stRegister.uxMask = MEMORY_TIM0_FLASH_BCHT_MASK;
    stRegister.uptrAddress = MEMORY_TIM0_OFFSET;
    stRegister.uxValue = (UBase_t) enHighTimeArg;

    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL__enWriteRegister(enModuleArg, &stRegister);
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        stRegister.uxShift = MEMORY_TIM0_R_EEPROM_BCHT_BIT;
        stRegister.uxMask = MEMORY_TIM0_EEPROM_BCHT_MASK;
        stRegister.uptrAddress = MEMORY_TIM0_OFFSET;
        stRegister.uxValue = (UBase_t) enHighTimeArg;
        enErrorReg = SYSCTL__enWriteRegister(enModuleArg, &stRegister);
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enGetMemoryHighTime(SYSCTL_nMODULE enModuleArg, SYSCTL_nMEM_HIGHTIME* penHighTimeArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penHighTimeArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;

    SYSCTL_Register_t stRegister;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        stRegister.uxShift = MEMORY_TIM0_R_FLASH_BCHT_BIT;
        stRegister.uxMask = MEMORY_TIM0_FLASH_BCHT_MASK;
        stRegister.uptrAddress = MEMORY_TIM0_OFFSET;
        enErrorReg = SYSCTL__enReadRegister(enModuleArg, &stRegister);
    }

    UBase_t uxFlashValue;
    uxFlashValue = 0UL;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        uxFlashValue = stRegister.uxValue;

        stRegister.uxShift = MEMORY_TIM0_R_EEPROM_BCHT_BIT;
        stRegister.uxMask = MEMORY_TIM0_EEPROM_BCHT_MASK;
        stRegister.uptrAddress = MEMORY_TIM0_OFFSET;
        enErrorReg = SYSCTL__enReadRegister(enModuleArg, &stRegister);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        UBase_t uxEEPROMValue = stRegister.uxValue;
        if(uxEEPROMValue == uxFlashValue)
        {
            *penHighTimeArg = (SYSCTL_nMEM_HIGHTIME) stRegister.uxValue;
        }
        else
        {
            enErrorReg = SYSCTL_enERROR_VALUE;
        }
    }
    return (enErrorReg);
}


SYSCTL_nERROR SYSCTL__enSetMemoryWaitState(SYSCTL_nMODULE enModuleArg, SYSCTL_nMEM_WAITSTATE enWaitStateArg)
{
    SYSCTL_Register_t stRegister;
    stRegister.uxShift = MEMORY_TIM0_R_FLASH_WS_BIT;
    stRegister.uxMask = MEMORY_TIM0_FLASH_WS_MASK;
    stRegister.uptrAddress = MEMORY_TIM0_OFFSET;
    stRegister.uxValue = (UBase_t) enWaitStateArg;

    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL__enWriteRegister(enModuleArg, &stRegister);
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        stRegister.uxShift = MEMORY_TIM0_R_EEPROM_WS_BIT;
        stRegister.uxMask = MEMORY_TIM0_EEPROM_WS_MASK;
        stRegister.uptrAddress = MEMORY_TIM0_OFFSET;
        stRegister.uxValue = (UBase_t) enWaitStateArg;
        enErrorReg = SYSCTL__enWriteRegister(enModuleArg, &stRegister);
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enGetMemoryWaitState(SYSCTL_nMODULE enModuleArg, SYSCTL_nMEM_WAITSTATE* penWaitStateArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penWaitStateArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;

    SYSCTL_Register_t stRegister;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        stRegister.uxShift = MEMORY_TIM0_R_FLASH_WS_BIT;
        stRegister.uxMask = MEMORY_TIM0_FLASH_WS_MASK;
        stRegister.uptrAddress = MEMORY_TIM0_OFFSET;
        enErrorReg = SYSCTL__enReadRegister(enModuleArg, &stRegister);
    }

    UBase_t uxFlashValue;
    uxFlashValue = 0UL;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        uxFlashValue = stRegister.uxValue;

        stRegister.uxShift = MEMORY_TIM0_R_EEPROM_WS_BIT;
        stRegister.uxMask = MEMORY_TIM0_EEPROM_WS_MASK;
        stRegister.uptrAddress = MEMORY_TIM0_OFFSET;
        enErrorReg = SYSCTL__enReadRegister(enModuleArg, &stRegister);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        UBase_t uxEEPROMValue = stRegister.uxValue;

        if(uxEEPROMValue == uxFlashValue)
        {
            *penWaitStateArg = (SYSCTL_nMEM_WAITSTATE) stRegister.uxValue;
        }
        else
        {
            enErrorReg = SYSCTL_enERROR_VALUE;
        }
    }
    return (enErrorReg);
}


SYSCTL_nERROR SYSCTL__enSetMemoryClockEdge(SYSCTL_nMODULE enModuleArg, SYSCTL_nMEM_CLOCKEDGE enClockEdgeArg)
{
    SYSCTL_Register_t stRegister;
    stRegister.uxShift = MEMORY_TIM0_R_FLASH_BCE_BIT;
    stRegister.uxMask = MEMORY_TIM0_FLASH_BCE_MASK;
    stRegister.uptrAddress = MEMORY_TIM0_OFFSET;
    stRegister.uxValue = (UBase_t) enClockEdgeArg;

    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL__enWriteRegister(enModuleArg, &stRegister);
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        stRegister.uxShift = MEMORY_TIM0_R_EEPROM_BCE_BIT;
        stRegister.uxMask = MEMORY_TIM0_EEPROM_BCE_MASK;
        stRegister.uptrAddress = MEMORY_TIM0_OFFSET;
        stRegister.uxValue = (UBase_t) enClockEdgeArg;
        enErrorReg = SYSCTL__enWriteRegister(enModuleArg, &stRegister);
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enGetMemoryClockEdge(SYSCTL_nMODULE enModuleArg, SYSCTL_nMEM_CLOCKEDGE* penClockEdgeArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penClockEdgeArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;

    SYSCTL_Register_t stRegister;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        stRegister.uxShift = MEMORY_TIM0_R_FLASH_BCE_BIT;
        stRegister.uxMask = MEMORY_TIM0_FLASH_BCE_MASK;
        stRegister.uptrAddress = MEMORY_TIM0_OFFSET;
        enErrorReg = SYSCTL__enReadRegister(enModuleArg, &stRegister);
    }

    UBase_t uxFlashValue;
    uxFlashValue = 0UL;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        uxFlashValue = stRegister.uxValue;

        stRegister.uxShift = MEMORY_TIM0_R_EEPROM_BCE_BIT;
        stRegister.uxMask = MEMORY_TIM0_EEPROM_BCE_MASK;
        stRegister.uptrAddress = MEMORY_TIM0_OFFSET;
        enErrorReg = SYSCTL__enReadRegister(enModuleArg, &stRegister);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        UBase_t uxEEPROMValue = stRegister.uxValue;
        if(uxEEPROMValue == uxFlashValue)
        {
            *penClockEdgeArg = (SYSCTL_nMEM_CLOCKEDGE) stRegister.uxValue;
        }
        else
        {
            enErrorReg = SYSCTL_enERROR_VALUE;
        }
    }
    return (enErrorReg);
}



SYSCTL_nERROR SYSCTL__enSetMemoryTiming(SYSCTL_nMODULE enModuleArg, UBase_t uxSystemClockArg)
{
    SYSCTL_nMEM_HIGHTIME enMemoryHighTimeReg;
    SYSCTL_nMEM_WAITSTATE enMemoryWaitStateReg;
    SYSCTL_nMEM_CLOCKEDGE enMemoryClockEdge;
    SYSCTL_nERROR enErrorReg;

    enMemoryHighTimeReg = SYSCTL_enMEM_HIGHTIME_0_5;
    enMemoryWaitStateReg = SYSCTL_enMEM_WAITSTATE_0;
    enMemoryClockEdge = SYSCTL_enMEM_CLOCKEDGE_RISING;
    enErrorReg = SYSCTL__enGetPredefineMemoryTiming(uxSystemClockArg, &enMemoryHighTimeReg,
                                                    &enMemoryWaitStateReg, &enMemoryClockEdge);
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enSetMemoryHighTime(enModuleArg, enMemoryHighTimeReg);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enSetMemoryWaitState(enModuleArg, enMemoryWaitStateReg);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enSetMemoryClockEdge(enModuleArg, enMemoryClockEdge);
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enGetMemoryTiming(SYSCTL_nMODULE enModuleArg,
                                        SYSCTL_nMEM_HIGHTIME* penMemoryHighTime,
                                        SYSCTL_nMEM_WAITSTATE* penMemoryWaitState,
                                        SYSCTL_nMEM_CLOCKEDGE* penMemoryClockEdge)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL__enGetMemoryHighTime(enModuleArg, penMemoryHighTime);
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetMemoryWaitState(enModuleArg, penMemoryWaitState);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetMemoryClockEdge(enModuleArg, penMemoryClockEdge);
    }
    return (enErrorReg);
}
