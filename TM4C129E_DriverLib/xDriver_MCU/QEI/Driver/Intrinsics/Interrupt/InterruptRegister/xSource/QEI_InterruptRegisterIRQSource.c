/**
 *
 * @file QEI_InterruptRegisterIRQSource.c
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
 * @verbatim Apr 8, 2021 @endverbatim
 *
 * @author
 * @verbatim indevicemex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * Apr 8, 2021        indevicemex    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/QEI/Driver/Intrinsics/Interrupt/InterruptRegister/xHeader/QEI_InterruptRegisterIRQSource.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/QEI/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/QEI_InterruptRoutine_Source.h>
#include <xDriver_MCU/QEI/Peripheral/QEI_Peripheral.h>

QEI_nERROR QEI__enRegisterIRQSourceHandler(QEI_nMODULE enModuleArg, QEI_nINT enInterruptSourceArg, QEI_pvfIRQSourceHandler_t pfIrqSourceHandler)
{
    QEI_nERROR enErrorReg;
    enErrorReg = (QEI_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) QEI_enMODULE_MAX);
    if(QEI_enERROR_OK == enErrorReg)
    {
        enErrorReg = (QEI_nERROR) MCU__enCheckParams((UBase_t) enInterruptSourceArg, (UBase_t) QEI_enINT_MAX);
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        QEI_pvfIRQSourceHandler_t* pvfIrqHandler = QEI__pvfGetIRQSourceHandlerPointer(enModuleArg, enInterruptSourceArg);
        enErrorReg = (QEI_nERROR) MCU__enRegisterIRQSourceHandler(pfIrqSourceHandler, pvfIrqHandler, 0UL, 1UL);
    }
    return (enErrorReg);
}
