/**
 *
 * @file SYSCTL_InterruptRoutine.c
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
 * @verbatim 12 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 12 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/SYSCTL/Interrupt/InterruptRoutine/SYSCTL_InterruptRoutine.h>

static SYSCTL_pvfIRQVectorHandler_t SYSCTL__pvIRQVectorHandler[1UL] =
{
    &SYSCTL__vIRQVectorHandler
};

SYSCTL_pvfIRQVectorHandler_t SYSCTL__pvfGetIRQVectorHandler(void)
{
    SYSCTL_pvfIRQVectorHandler_t pvfFunctionReg = (SYSCTL_pvfIRQVectorHandler_t) 0UL;
    pvfFunctionReg = SYSCTL__pvIRQVectorHandler[(UBase_t) 0UL];
    return (pvfFunctionReg);
}

SYSCTL_pvfIRQVectorHandler_t* SYSCTL__pvfGetIRQVectorHandlerPointer(void)
{
    SYSCTL_pvfIRQVectorHandler_t* pvfFunctionReg = (SYSCTL_pvfIRQVectorHandler_t*) 0UL;
    pvfFunctionReg = (SYSCTL_pvfIRQVectorHandler_t*) &SYSCTL__pvIRQVectorHandler[(UBase_t) 0UL];
    return (pvfFunctionReg);
}
