/**
 *
 * @file NVIC_Pending.c
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
 * @verbatim 20 jun. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 20 jun. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/Core/NVIC/Driver/xHeader/NVIC_Pending.h>

#include <xDriver_MCU/Core/NVIC/Driver/xHeader/NVIC_ReadReg.h>
#include <xDriver_MCU/Core/NVIC/Driver/xHeader/NVIC_WriteReg.h>
#include <xDriver_MCU/Core/NVIC/Peripheral/NVIC_Peripheral.h>

NVIC_nERROR NVIC__enIsVectorPending(NVIC_nMODULE enModuleArg, NVIC_nVECTOR enVectorArg, NVIC_nBOOLEAN* penStateArg)
{
    NVIC_nERROR enErrorReg;
    enErrorReg = NVIC__enReadValue(enModuleArg, enVectorArg, NVIC_ISPR_OFFSET, (UBase_t*) penStateArg);
    return (enErrorReg);
}

NVIC_nERROR NVIC__enSetPendingVectorState(NVIC_nMODULE enModuleArg, NVIC_nVECTOR enVectorArg, NVIC_nBOOLEAN enStateArg)
{
    NVIC_nERROR enErrorReg;
    enErrorReg = (NVIC_enTRUE == enStateArg) ?
            NVIC__enSetWriteValue(enModuleArg, enVectorArg, NVIC_ISPR_OFFSET, (UBase_t) NVIC_enSTATE_ENA) :
            NVIC__enSetWriteValue(enModuleArg, enVectorArg, NVIC_ICPR_OFFSET, (UBase_t) NVIC_enSTATE_ENA);
    return (enErrorReg);

}

NVIC_nERROR NVIC__enSetPendingVector(NVIC_nMODULE enModuleArg, NVIC_nVECTOR enVectorArg)
{
    NVIC_nERROR enErrorReg;
    enErrorReg = NVIC__enSetPendingVectorState(enModuleArg, enVectorArg, NVIC_enTRUE);
    return (enErrorReg);

}

NVIC_nERROR NVIC__enClearPendingVector(NVIC_nMODULE enModuleArg, NVIC_nVECTOR enVectorArg)
{
    NVIC_nERROR enErrorReg;
    enErrorReg = NVIC__enSetPendingVectorState(enModuleArg, enVectorArg, NVIC_enFALSE);
    return (enErrorReg);
}
