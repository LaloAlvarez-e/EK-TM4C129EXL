/**
 *
 * @file SYSTICK_Init.c
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
 * @verbatim 20 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 20 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/Core/SYSTICK/xHeader/SYSTICK_Init.h>

#include <xApplication_MCU/Core/SYSTICK/Interrupt/SYSTICK_Interrupt.h>
#include <xApplication_MCU/Core/SYSTICK/Delay/SYSTICK_Delay.h>
#include <xApplication_MCU/Core/SYSTICK/Intrinsics/xHeader/SYSTICK_Dependencies.h>

#define SYSTICK_PIOSC4_MHZ (4UL)
#define SYSTICK_MAXVALUE (0x1000000UL) /*24 bits*/
#define SYSTICK_PICOSECONDS_PER_MICROSECOND (1000000ULL)

static void SYSTICK_vClarAllCounter(void);
void SYSTICK_Delay__vIRQVectorHandler(void);

void SYSTICK_Delay__vIRQVectorHandler(void)
{
    UBase_t uxCount = SYSTICK__uxGetFreeCount();
    uxCount++;
    SYSTICK__vSetFreeCount(uxCount);
}

SYSTICK_nERROR SYSTICK__enInitTickVector(SYSTICK_nMODULE enModuleArg, UBase_t uxTickArg, SYSTICK_nPRIORITY enPriorityArg,
                                          SYSTICK_nCLKSOURCE enClockSourceArg, SYSTICK_pvfIRQVectorHandler_t pvfVectorArg)
{
    MCU_nSTATUS enFPUActive = MCU__enGetFPUContextActive();
    SYSTICK_nERROR enErrorReg;

    enErrorReg = SYSTICK_enERROR_OK;
    if((2UL > uxTickArg) || (SYSTICK_MAXVALUE < uxTickArg))
    {
        enErrorReg = SYSTICK_enERROR_VALUE;
    }
    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        UBase_t uxSystemFrequencyMHz = 0U;
        uint64_t u64TickPicoSeconds = 0ULL;
        uint64_t u64PeriodPicoSeconds = 0ULL;
        SYSTICK_vClarAllCounter();
        if(SYSTICK_enPIOSC4 != enClockSourceArg)
        {
            enErrorReg = (SYSTICK_nERROR) SYSCTL__enGetSystemClockFrequency(SYSCTL_enMODULE_0, &uxSystemFrequencyMHz);
            if(SYSTICK_enERROR_OK == enErrorReg)
            {
                uxSystemFrequencyMHz /= 1000000UL;
            }
        }
        else
        {
            uxSystemFrequencyMHz = SYSTICK_PIOSC4_MHZ;
        }
        if(SYSTICK_enERROR_OK == enErrorReg)
        {
            u64TickPicoSeconds = SYSTICK_PICOSECONDS_PER_MICROSECOND;
            u64TickPicoSeconds += ((uint64_t) uxSystemFrequencyMHz / 2ULL);
            u64TickPicoSeconds /= (uint64_t) uxSystemFrequencyMHz;

            u64PeriodPicoSeconds = SYSTICK_PICOSECONDS_PER_MICROSECOND * (uint64_t) uxTickArg;
            u64PeriodPicoSeconds += ((uint64_t) uxSystemFrequencyMHz / 2ULL);
            u64PeriodPicoSeconds /= (uint64_t) uxSystemFrequencyMHz;

            SYSTICK__vSetTickPs((UBase_t) u64TickPicoSeconds);
            SYSTICK__vSetPsPeriod(u64PeriodPicoSeconds);
        }
        SYSTICK__vSetTickPeriod(uxTickArg);
    }
    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSTICK__enDisableInterruptVector(enModuleArg);
    }
    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSTICK__enDisable(enModuleArg);
    }
    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSTICK__enClearCurrentValue(enModuleArg);
    }
    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSTICK__enSetClockSource(enModuleArg, enClockSourceArg);
    }
    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSTICK__enRegisterIRQVectorHandler(enModuleArg, pvfVectorArg);
    }
    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSTICK__enEnableInterruptVectorWithPriority(enModuleArg, enPriorityArg);
    }
    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSTICK__enSetReloadValue(enModuleArg, uxTickArg - 1U);
    }
    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSTICK__enClearCurrentValue(enModuleArg);
    }
    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSTICK__enEnable(SYSTICK_enMODULE_0);
    }
    MCU__vSetFPUContextActive(enFPUActive);
    return (enErrorReg);
}

SYSTICK_nERROR SYSTICK__enInitTick(SYSTICK_nMODULE enModuleArg, UBase_t uxTickArg, SYSTICK_nPRIORITY enPriorityArg, SYSTICK_nCLKSOURCE enClockSourceArg)
{
    SYSTICK_nERROR enErrorReg;
    enErrorReg = SYSTICK__enInitTickVector(enModuleArg, uxTickArg, enPriorityArg, enClockSourceArg, &SYSTICK_Delay__vIRQVectorHandler);
    return (enErrorReg);
}

SYSTICK_nERROR SYSTICK__enInitUsVector(SYSTICK_nMODULE enModuleArg, UBase_t uxTimeUsArg, SYSTICK_nPRIORITY enPriorityArg, SYSTICK_pvfIRQVectorHandler_t pvfVectorArg)
{
    UBase_t uxTick;
    UBase_t uxTick_Sysclk;
    UBase_t uxTick_Piosc4;
    UBase_t uxSYSTICKFrequencyMHz_Sysclk;
    UBase_t uxSYSTICKFrequencyMHz_Piosc4;
    SYSTICK_nCLKSOURCE enClockSource;
    SYSTICK_nERROR enErrorReg;

    uxTick = 0UL;
    uxSYSTICKFrequencyMHz_Sysclk = 0UL;
    enClockSource = SYSTICK_enSYSCLK;
    enErrorReg = SYSTICK_enERROR_OK;
    if(0UL == uxTimeUsArg)
    {
        enErrorReg = SYSTICK_enERROR_VALUE;
    }
    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SYSTICK_nERROR) SYSCTL__enGetSystemClockFrequency(SYSCTL_enMODULE_0, &uxSYSTICKFrequencyMHz_Sysclk);
    }
    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        uxSYSTICKFrequencyMHz_Piosc4 = SYSTICK_PIOSC4_MHZ;
        uxSYSTICKFrequencyMHz_Sysclk /= 1000000UL;
        SYSTICK_vClarAllCounter();

        uxTick_Sysclk = uxSYSTICKFrequencyMHz_Sysclk * uxTimeUsArg;
        uxTick_Piosc4 = uxSYSTICKFrequencyMHz_Piosc4 * uxTimeUsArg;
        uxTick = uxTick_Sysclk;
        if(SYSTICK_MAXVALUE < uxTick_Sysclk)
        {
            enClockSource = SYSTICK_enPIOSC4;
            uxTick = uxTick_Piosc4;
            if(SYSTICK_MAXVALUE < uxTick_Piosc4)
            {
                enErrorReg = SYSTICK_enERROR_VALUE;
            }
        }
    }

    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSTICK__enInitTickVector(enModuleArg, uxTick, enPriorityArg, enClockSource, pvfVectorArg);
    }
    return (enErrorReg);
}

SYSTICK_nERROR SYSTICK__enInitUs(SYSTICK_nMODULE enModuleArg, UBase_t uxTimeUsArg, SYSTICK_nPRIORITY enPriorityArg)
{
    SYSTICK_nERROR enErrorReg;
    enErrorReg = SYSTICK__enInitUsVector(enModuleArg, uxTimeUsArg, enPriorityArg, &SYSTICK_Delay__vIRQVectorHandler);
    return (enErrorReg);
}

static void SYSTICK_vClarAllCounter(void)
{
    SYSTICK__vClearFreeCount();
    SYSTICK__vClearFreeCountOv();
    SYSTICK__vClearPsPeriod();
    SYSTICK__vClearTickPs();
    SYSTICK__vClearTickPeriod();
}
