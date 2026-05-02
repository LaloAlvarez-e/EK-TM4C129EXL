/**
 *
 * @file HIB_Init.c
 * @copyright
 * @verbatim InDeviceMex 2026 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 6 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 6 abr. 2026    vyldram    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/HIB/xHeader/HIB_Init.h>

#include <xApplication_MCU/HIB/Intrinsics/xHeader/HIB_Ready.h>
#include <xApplication_MCU/HIB/Interrupt/HIB_Interrupt.h>

HIB_nERROR HIB__enInit(HIB_nMODULE enModuleArg)
{
    HIB_nERROR enErrorReg;
    HIB_pvfIRQVectorHandler_t pfIrqVectorHandlerReg;

    enErrorReg = HIB__enSetReadyOnRunMode(enModuleArg);
    if(HIB_enERROR_OK == enErrorReg)
    {
        pfIrqVectorHandlerReg = HIB__pvfGetIRQVectorHandler(enModuleArg);
        enErrorReg = HIB__enRegisterIRQVectorHandler(enModuleArg, pfIrqVectorHandlerReg);
    }
    return (enErrorReg);
}