/**
 *
 * @file QEI_InterruptRoutine_Source.c
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
#include <xDriver_MCU/QEI/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/QEI_InterruptRoutine_Source.h>

static QEI_pvfIRQSourceHandler_t QEI_vIRQSourceHandler[(UBase_t) QEI_enMODULE_MAX][(UBase_t) QEI_enINT_MAX] =
{
 {
  &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
  &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
  &MCU_vIRQSourceHandler_Dummy
 },
};

QEI_pvfIRQSourceHandler_t QEI__pvfGetIRQSourceHandler(QEI_nMODULE enModuleArg, QEI_nINT enInterruptSourceArg)
{
    QEI_pvfIRQSourceHandler_t pvfFunctionReg;

    pvfFunctionReg = (QEI_pvfIRQSourceHandler_t) 0;
    if((QEI_enMODULE_MAX > enModuleArg) && (QEI_enINT_MAX > enInterruptSourceArg))
    {
        pvfFunctionReg = QEI_vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t) enInterruptSourceArg];
    }
    return (pvfFunctionReg);
}

QEI_pvfIRQSourceHandler_t* QEI__pvfGetIRQSourceHandlerPointer(QEI_nMODULE enModuleArg, QEI_nINT enInterruptSourceArg)
{
    QEI_pvfIRQSourceHandler_t* pvfFunctionReg;

    pvfFunctionReg = (QEI_pvfIRQSourceHandler_t*) 0;
    if((QEI_enMODULE_MAX > enModuleArg) && (QEI_enINT_MAX > enInterruptSourceArg))
    {
        pvfFunctionReg = &QEI_vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t) enInterruptSourceArg];
    }
    return (pvfFunctionReg);
}

