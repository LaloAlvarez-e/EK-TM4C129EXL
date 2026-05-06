/**
 *
 * @file SYSCTL_InterruptRegisterIRQSource.c
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
 * @verbatim 17 feb. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 17 feb. 2021     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/SYSCTL/Driver/Intrinsics/Interrupt/InterruptRegister/xHeader/SYSCTL_InterruptRegisterIRQSource.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/SYSCTL/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/SYSCTL_InterruptRoutine_Source.h>
#include <xDriver_MCU/SYSCTL/Peripheral/SYSCTL_Peripheral.h>

SYSCTL_nERROR SYSCTL__enRegisterIRQSourceHandler(SYSCTL_nMODULE enModuleArg, SYSCTL_nINT enInterruptSourceArg, SYSCTL_pvfIRQSourceHandler_t pfIrqSourceHandler)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (SYSCTL_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) SYSCTL_enMODULE_MAX);
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SYSCTL_nERROR) MCU__enCheckParams((UBase_t) enInterruptSourceArg, (UBase_t) SYSCTL_enINT_MAX);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        SYSCTL_pvfIRQSourceHandler_t* pvfIrqHandler = SYSCTL__pvfGetIRQSourceHandlerPointer(enModuleArg, enInterruptSourceArg);
        enErrorReg = (SYSCTL_nERROR) MCU__enRegisterIRQSourceHandler(pfIrqSourceHandler, pvfIrqHandler, 0UL, 1UL);
    }

    return (enErrorReg);
}
