/**
 *
 * @file SSI_InterruptRegisterIRQSource.c
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
#include <xDriver_MCU/SSI/Driver/Intrinsics/Interrupt/InterruptRegister/xHeader/SSI_InterruptRegisterIRQSource.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/SSI/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/SSI_InterruptRoutine_Source.h>
#include <xDriver_MCU/SSI/Peripheral/SSI_Peripheral.h>

SSI_nERROR SSI__enRegisterIRQSourceHandler(SSI_nMODULE enModuleArg, SSI_nINT enInterruptSourceArg, SSI_pvfIRQSourceHandler_t pfIrqSourceHandler)
{
    SSI_nERROR enErrorReg;
    enErrorReg = (SSI_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) SSI_enMODULE_MAX);
    if(SSI_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SSI_nERROR) MCU__enCheckParams((UBase_t) enInterruptSourceArg, (UBase_t) SSI_enINT_MAX);
    }
    if(SSI_enERROR_OK == enErrorReg)
    {
        SSI_pvfIRQSourceHandler_t* pvfIrqHandler = SSI__pvfGetIRQSourceHandlerPointer(enModuleArg, enInterruptSourceArg);
        enErrorReg = (SSI_nERROR) MCU__enRegisterIRQSourceHandler(pfIrqSourceHandler, pvfIrqHandler, 0UL, 1UL);
    }

    return (enErrorReg);
}
