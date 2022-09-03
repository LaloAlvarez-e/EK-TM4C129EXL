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

static void SYSTICK_vClarAllCounter(void);
void SYSTICK_Delay__vIRQVectorHandler(void);

void SYSTICK_Delay__vIRQVectorHandler(void)
{
    uint32_t u32Count = SYSTICK__u32GetFreeCount();
    u32Count++;
    SYSTICK__vSetFreeCount(u32Count);
    /*
    if(0U == u32Count)
    {
        uint32_t u32CountOv = SYSTICK__u32GetFreeCountOv();
        u32CountOv++;
        SYSTICK__vSetFreeCountOv(u32CountOv);
    }
    */
}

SYSTICK_nERROR SYSTICK__enInitTickVector(uint32_t u32Tick, SYSTICK_nPRIORITY enPriority,
                                          SYSTICK_nCLKSOURCE enClockSource, void(*pvfVector) (void))
{
    MCU_nSTATUS enFPUActive = MCU_enSTATUS_INACTIVE;
    enFPUActive = MCU__enGetFPUContextActive();
    SYSTICK_nERROR enReturn = SYSTICK_enERROR_UNDEF;
    uint32_t u32SystemFrequencyMHz = SYSTICK_PIOSC4_MHZ;
    float32_t f32PicoSeconds = 1000000.0f;
    float32_t f32PicoSecondsTemp = 1000000.0f;

    SYSTICK__vDisInterruptVector();
    SYSTICK__enDisable(SYSTICK_enMODULE_0);
    SYSTICK__enClearCurrentValue(SYSTICK_enMODULE_0);
    SYSTICK__enSetClockSource(SYSTICK_enMODULE_0, enClockSource);

    SYSTICK_vClarAllCounter();

    if(SYSTICK_enPIOSC4 != enClockSource)
    {
        u32SystemFrequencyMHz = SYSCTL__u32GetSystemClock();
        u32SystemFrequencyMHz /= 1000000UL;
    }

    if(0UL != u32Tick)
    {
        if(SYSTICK_MAXVALUE < u32Tick)
        {
            u32Tick = SYSTICK_MAXVALUE;
        }
        f32PicoSeconds /= (float32_t) u32SystemFrequencyMHz;
        f32PicoSecondsTemp = f32PicoSeconds + 0.5f;
        SYSTICK__vSetTickPs((uint32_t) f32PicoSecondsTemp);

        f32PicoSeconds *=  (float32_t) u32Tick;
        f32PicoSeconds += 0.5f;
        SYSTICK__vSetPsPeriod((uint64_t) f32PicoSeconds);
        SYSTICK__vSetTickPeriod(u32Tick);


        SYSTICK__vRegisterIRQVectorHandler(pvfVector);
        SYSTICK__vEnInterruptVector(enPriority);
        SYSTICK__enSetReloadValue(SYSTICK_enMODULE_0, u32Tick - 1U);
        SYSTICK__enClearCurrentValue(SYSTICK_enMODULE_0);
        SYSTICK__enEnable(SYSTICK_enMODULE_0);
        enReturn = SYSTICK_enERROR_OK;
    }
    MCU__vSetFPUContextActive(enFPUActive);
    return (enReturn);
}

SYSTICK_nERROR SYSTICK__enInitTick(uint32_t u32Tick, SYSTICK_nPRIORITY enPriority, SYSTICK_nCLKSOURCE enClockSource)
{
    return (SYSTICK__enInitTickVector(u32Tick, enPriority, enClockSource, &SYSTICK_Delay__vIRQVectorHandler));
}

SYSTICK_nERROR SYSTICK__enInitUsVector(uint32_t u32TimeUs, SYSTICK_nPRIORITY enPriority, void(*pvfVector) (void))
{
    SYSTICK_nCLKSOURCE enClockSource = SYSTICK_enSYSCLK;
    SYSTICK_nERROR enReturn = SYSTICK_enERROR_UNDEF;
    uint32_t u32Tick_Sysclk = 0UL;
    uint32_t u32Tick_Piosc4 = 0UL;
    uint32_t u32Tick = 0UL;
    uint32_t u32SYSTICKFrequencyMHz_Sysclk = SYSCTL__u32GetSystemClock()/1000000UL;
    uint32_t u32SYSTICKFrequencyMHz_Piosc4 = SYSTICK_PIOSC4_MHZ;

    if(0UL != u32TimeUs)
    {

        SYSTICK_vClarAllCounter();

        u32Tick_Sysclk = u32SYSTICKFrequencyMHz_Sysclk * u32TimeUs;
        u32Tick_Piosc4 = u32SYSTICKFrequencyMHz_Piosc4 * u32TimeUs;
        u32Tick = u32Tick_Sysclk;
        enReturn = SYSTICK_enERROR_OK;
        if(SYSTICK_MAXVALUE < u32Tick_Sysclk)
        {
            enClockSource = SYSTICK_enPIOSC4;
            u32Tick = u32Tick_Piosc4;
            if(SYSTICK_MAXVALUE < u32Tick_Piosc4)
            {
                enReturn = SYSTICK_enERROR_VALUE;
            }
        }
    }


    if(SYSTICK_enERROR_OK == enReturn)
    {
        enReturn = SYSTICK__enInitTickVector(u32Tick, enPriority, enClockSource, pvfVector);
    }
    return (enReturn);
}

SYSTICK_nERROR SYSTICK__enInitUs(uint32_t u32TimeUs, SYSTICK_nPRIORITY enPriority)
{
    return (SYSTICK__enInitUsVector(u32TimeUs, enPriority, &SYSTICK_Delay__vIRQVectorHandler));
}

static void SYSTICK_vClarAllCounter(void)
{
    SYSTICK__vClearFreeCount();
    SYSTICK__vClearFreeCountOv();
    SYSTICK__vClearPsPeriod();
    SYSTICK__vClearTickPs();
    SYSTICK__vClearTickPeriod();
}
