/**
 *
 * @file OS_Adapt_Critical.c
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
 * @verbatim 15 jul. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 15 jul. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xOS/Adapt/xHeader/OS_Adapt_Critical.h>

static void OS_Adapt_Fault(void);

static uint32_t u32CriticalNesting = 0xaaaaaaaa;

void OS_Adapt__vEnterCritical(void)
{
    OS_ADAPT_DISABLE_INTERRUPTS();
    u32CriticalNesting++;

    /*
    if(1UL == u32CriticalNesting)
    {
        if(0UL != OS_ADAPT_IS_INTERRUPT_ACTIVE)
        {
            OS_Adapt_Fault();
        }
    }
        */
}


void OS_Adapt__vExitCritical(void)
{
    if(0UL != u32CriticalNesting)
    {
        u32CriticalNesting--;
        if(0UL == u32CriticalNesting)
        {
            OS_ADAPT_ENABLE_INTERRUPTS();
        }
    }
}


uint32_t OS_Adapt__u32GetCriticalNesting(void)
{
    return (u32CriticalNesting);
}

void OS_Adapt__vSetCriticalNesting(uint32_t u32NestingValue)
{
    u32CriticalNesting = u32NestingValue;
}

void OS_Adapt__vIncreaseCriticalNesting(void)
{
    u32CriticalNesting++;
}


static void OS_Adapt_Fault(void)
{
    OS_ADAPT_DISABLE_INTERRUPTS();
    while(1UL){}
}