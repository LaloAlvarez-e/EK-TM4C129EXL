/**
 *
 * @file SYSEXC_InterruptRegisterIRQSource.c
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
 * @verbatim 19 oct. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 19 oct. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/SYSEXC/Driver/Intrinsics/Interrupt/InterruptRegister/xHeader/SYSEXC_InterruptRegisterIRQSource.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/SYSEXC/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/SYSEXC_InterruptRoutine_Source.h>
#include <xDriver_MCU/SYSEXC/Peripheral/SYSEXC_Peripheral.h>

SYSEXC_nERROR SYSEXC__enRegisterIRQSourceHandler(SYSEXC_nMODULE enModuleArg, SYSEXC_nINT enInterruptSourceArg, SYSEXC_pvfIRQSourceHandler_t pfIrqSourceHandler)
{
    SYSEXC_nERROR enErrorReg;
    enErrorReg = (SYSEXC_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) SYSEXC_enMODULE_MAX);
    if(SYSEXC_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SYSEXC_nERROR) MCU__enCheckParams((UBase_t) enInterruptSourceArg, (UBase_t) SYSEXC_enINT_MAX);
    }
    if(SYSEXC_enERROR_OK == enErrorReg)
    {
        SYSEXC_pvfIRQSourceHandler_t* pvfIrqHandler = SYSEXC__pvfGetIRQSourceHandlerPointer(enModuleArg, enInterruptSourceArg);
        enErrorReg = (SYSEXC_nERROR) MCU__enRegisterIRQSourceHandler(pfIrqSourceHandler, pvfIrqHandler, 0UL, 1UL);
    }

    return (enErrorReg);
}
