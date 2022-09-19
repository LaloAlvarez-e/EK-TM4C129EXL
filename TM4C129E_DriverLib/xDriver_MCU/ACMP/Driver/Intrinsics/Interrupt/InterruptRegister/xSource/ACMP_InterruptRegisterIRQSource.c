/**
 *
 * @file ACMP_InterruptRegisterIRQSource.c
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
 * @verbatim 4 dic. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 4 dic. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/ACMP/Driver/Intrinsics/Interrupt/InterruptRegister/xHeader/ACMP_InterruptRegisterIRQSource.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/ACMP/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/ACMP_InterruptRoutine_Source.h>
#include <xDriver_MCU/ACMP/Peripheral/ACMP_Peripheral.h>

ACMP_nERROR ACMP__enRegisterIRQSourceHandler(ACMP_pvfIRQSourceHandler_t pfIrqSourceHandler,
                                         ACMP_nMODULE enModuleArg,
                                         ACMP_nCOMP enComparatorArg)
{
    ACMP_pvfIRQSourceHandler_t* pvfIrqHandler;
    ACMP_nERROR enErrorReg;

    enErrorReg = (ACMP_nERROR) MCU__enCheckParams((uint32_t) enModuleArg, (uint32_t) ACMP_enMODULE_MAX);
    if(ACMP_enERROR_OK == enErrorReg)
    {
        enErrorReg = (ACMP_nERROR) MCU__enCheckParams((uint32_t) enComparatorArg, (uint32_t) ACMP_enCOMP_MAX);
    }
    if(ACMP_enERROR_OK == enErrorReg)
    {
        pvfIrqHandler = ACMP__pvfGetIRQSourceHandlerPointer(enModuleArg, enComparatorArg);
        enErrorReg = (ACMP_nERROR) MCU__enRegisterIRQSourceHandler(pfIrqSourceHandler, pvfIrqHandler, 0UL, 1UL);
    }
    return (enErrorReg);
}
