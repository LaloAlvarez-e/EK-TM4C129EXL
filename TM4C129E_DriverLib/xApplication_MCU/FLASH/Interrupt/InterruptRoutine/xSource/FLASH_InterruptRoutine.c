/**
 *
 * @file FLASH_InterruptRoutine.c
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
 * @verbatim 11 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 11 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/FLASH/Interrupt/InterruptRoutine/FLASH_InterruptRoutine.h>

static void (*FLASH__pvIRQVectorHandler[1UL]) (void) =
{
    &FLASH__vIRQVectorHandler
};

void (*FLASH__pvfGetIRQVectorHandler(void))(void)
{
    void(*pvfFunctionReg)(void) = (void(*)(void)) 0UL;
    pvfFunctionReg = FLASH__pvIRQVectorHandler[0UL];
    return (pvfFunctionReg);
}

void (**FLASH__pvfGetIRQVectorHandlerPointer(void))(void)
{
    void(**pvfFunctionReg)(void) = (void(**)(void)) 0UL;
    pvfFunctionReg = (void(**)(void)) &FLASH__pvIRQVectorHandler[0UL];
    return (pvfFunctionReg);
}
