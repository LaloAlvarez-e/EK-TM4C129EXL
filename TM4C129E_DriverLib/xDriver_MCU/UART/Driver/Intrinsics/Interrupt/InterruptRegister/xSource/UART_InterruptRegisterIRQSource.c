/**
 *
 * @file UART_InterruptRegisterIRQSource.c
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
#include <xDriver_MCU/UART/Driver/Intrinsics/Interrupt/InterruptRegister/xHeader/UART_InterruptRegisterIRQSource.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/UART/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/UART_InterruptRoutine_Source.h>
#include <xDriver_MCU/UART/Peripheral/UART_Peripheral.h>

UART_nERROR UART__enRegisterIRQSourceHandler(UART_nMODULE enModuleArg, UART_nINT enInterruptSourceArg, UART_pvfIRQSourceHandler_t pfIrqSourceHandler)
{
    UART_pvfIRQSourceHandler_t* pvfIrqHandler;
    UART_nERROR enErrorReg;

    enErrorReg = (UART_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) UART_enMODULE_MAX);
    if(UART_enERROR_OK == enErrorReg)
    {
        enErrorReg = (UART_nERROR) MCU__enCheckParams((UBase_t) enInterruptSourceArg, (UBase_t) UART_enINT_MAX);
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        pvfIrqHandler = UART__pvfGetIRQSourceHandlerPointer(enModuleArg, enInterruptSourceArg);
        enErrorReg = (UART_nERROR) MCU__enRegisterIRQSourceHandler(pfIrqSourceHandler, pvfIrqHandler, 0UL, 1UL);
    }

    return (enErrorReg);
}
