/**
 *
 * @file SCB_InterruptRoutine_NMI.c
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
 * @verbatim 18 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 18 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/Core/SCB/Interrupt/InterruptRoutine/xHeader/SCB_InterruptRoutine_NMI.h>

#include <xApplication_MCU/Core/SCB/Interrupt/InterruptRoutine/xHeader/SCB_InterruptRoutine_Source.h>
#include <xApplication_MCU/Core/SCB/Intrinsics/xHeader/SCB_Dependencies.h>

void NMI__vIRQVectorHandler(void)
{
    volatile uint32_t u32RegNMI = 0UL;
    volatile uint32_t u32RegNMITemp = 0UL;
    void(*pvfCallback)(void)  = (void(*)(void)) 0UL;

    u32RegNMI = SYSCTL_NMIC_R;

    if(0UL == ((uint32_t) SCB_enNMI_ALL & u32RegNMI))
    {
        pvfCallback = SCB_NMI__pvfGetIRQSourceHandler(SCB_enNMI_BIT_SW);
        pvfCallback();
    }
    else
    {
        if(0UL != ((uint32_t) SCB_enNMI_MOSCFAIL & u32RegNMI))
        {
            do
            {
                SYSCTL_NMIC_R &= ~ (uint32_t) SCB_enNMI_MOSCFAIL;
            }while(0UL != ((uint32_t) SCB_enNMI_MOSCFAIL & SYSCTL_NMIC_R));

            pvfCallback = SCB_NMI__pvfGetIRQSourceHandler(SCB_enNMI_BIT_MOSCFAIL);
            pvfCallback();
        }
        if(0UL != ((uint32_t) SCB_enNMI_TAMPER & u32RegNMI))
        {
            do
            {
                SYSCTL_NMIC_R &= ~(uint32_t) SCB_enNMI_TAMPER;
            }while(0UL != ((uint32_t) SCB_enNMI_TAMPER & SYSCTL_NMIC_R));

            /**
             * TODO: Check if TAMPER requires to be cleared in HIB module
             */
            pvfCallback = SCB_NMI__pvfGetIRQSourceHandler(SCB_enNMI_BIT_TAMPER);
            pvfCallback();
        }
        if(0UL != ((uint32_t) SCB_enNMI_WDT1 & u32RegNMI))
        {
            do
            {
                SYSCTL_NMIC_R &= ~(uint32_t) SCB_enNMI_WDT1;
            }while(0UL != ((uint32_t) SCB_enNMI_WDT1 & SYSCTL_NMIC_R));

            pvfCallback = SCB_NMI__pvfGetIRQSourceHandler(SCB_enNMI_BIT_WDT1);
            pvfCallback();
        }
        if(0UL != ((uint32_t) SCB_enNMI_WDT0 & u32RegNMI))
        {
            do
            {
                SYSCTL_NMIC_R &= ~(uint32_t) SCB_enNMI_WDT0;
            }while(0UL != ((uint32_t) SCB_enNMI_WDT0 & SYSCTL_NMIC_R));

            pvfCallback = SCB_NMI__pvfGetIRQSourceHandler(SCB_enNMI_BIT_WDT0);
            pvfCallback();
        }
        if(0UL != ((uint32_t) SCB_enNMI_POWER & u32RegNMI))
        {
            do
            {
                SYSCTL_NMIC_R &= ~(uint32_t) SCB_enNMI_POWER;
            }while(0UL != ((uint32_t) SCB_enNMI_POWER & SYSCTL_NMIC_R));

            pvfCallback = SCB_NMI__pvfGetIRQSourceHandler(SCB_enNMI_BIT_POWER);
            pvfCallback();
        }
        if(0UL != ((uint32_t) SCB_enNMI_EXTERNAL & u32RegNMI))
        {
            do
            {
                SYSCTL_NMIC_R &= ~(uint32_t) SCB_enNMI_EXTERNAL;
            }while(0UL != ((uint32_t) SCB_enNMI_EXTERNAL & SYSCTL_NMIC_R));

            pvfCallback = SCB_NMI__pvfGetIRQSourceHandler(SCB_enNMI_BIT_EXTERNAL);
            pvfCallback();
        }
    }
}
