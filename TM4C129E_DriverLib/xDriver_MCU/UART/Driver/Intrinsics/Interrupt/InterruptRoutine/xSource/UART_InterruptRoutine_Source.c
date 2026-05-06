/**
 *
 * @file UART_InterruptRoutine_Source.c
 * @copyright
 * @verbatim InDeviceMex 2020 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 23 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 23 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/UART/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/UART_InterruptRoutine_Source.h>

static UART_pvfIRQSourceHandler_t UART_vIRQSourceHandler[(UBase_t) UART_enMODULE_MAX][(UBase_t) UART_enINT_MAX] =
{
    {
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy
    },
    {
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy
    },
    {
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy
    },
    {
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy
    },
    {
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy
    },
    {
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy
    },
    {
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy
    },
    {
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy
    },
};

UART_pvfIRQSourceHandler_t UART__pvfGetIRQSourceHandler(UART_nMODULE enModuleArg, UART_nINT enInterruptSourceArg)
{
    UART_pvfIRQSourceHandler_t pvfFunctionReg;

    pvfFunctionReg = (UART_pvfIRQSourceHandler_t) 0;
    if((UART_enMODULE_MAX > enModuleArg) && (UART_enINT_MAX > enInterruptSourceArg))
    {
        pvfFunctionReg = UART_vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t) enInterruptSourceArg];
    }
    return (pvfFunctionReg);
}

UART_pvfIRQSourceHandler_t* UART__pvfGetIRQSourceHandlerPointer(UART_nMODULE enModuleArg, UART_nINT enInterruptSourceArg)
{
    UART_pvfIRQSourceHandler_t* pvfFunctionReg;

    pvfFunctionReg = (UART_pvfIRQSourceHandler_t*) 0;
    if((UART_enMODULE_MAX > enModuleArg) && (UART_enINT_MAX > enInterruptSourceArg))
    {
        pvfFunctionReg = &UART_vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t) enInterruptSourceArg];
    }
    return (pvfFunctionReg);
}
