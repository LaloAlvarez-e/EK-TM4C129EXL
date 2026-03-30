/**
 *
 * @file NVIC_Enable.c
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
#include <xDriver_MCU/Core/NVIC/Driver/xHeader/NVIC_Enable.h>

#include <xDriver_MCU/Core/NVIC/Driver/xHeader/NVIC_ReadReg.h>
#include <xDriver_MCU/Core/NVIC/Driver/xHeader/NVIC_WriteReg.h>
#include <xDriver_MCU/Core/NVIC/Driver/xHeader/NVIC_Priority.h>
#include <xDriver_MCU/Core/NVIC/Peripheral/NVIC_Peripheral.h>

NVIC_nERROR NVIC__enGetVectorState(NVIC_nMODULE enModuleArg, NVIC_nVECTOR enVectorArg, NVIC_nSTATE* penStateArg)
{
    NVIC_nERROR enErrorReg;
    enErrorReg = NVIC__enReadValue(enModuleArg, enVectorArg, NVIC_ISER_OFFSET, (UBase_t*) penStateArg);
    return (enErrorReg);
}

NVIC_nERROR NVIC__enSetVectorState(NVIC_nMODULE enModuleArg, NVIC_nVECTOR enVectorArg, NVIC_nSTATE enStateArg)
{
    NVIC_nERROR enErrorReg;
    enErrorReg = (NVIC_enSTATE_ENA == enStateArg) ?
            NVIC__enSetWriteValue(enModuleArg, enVectorArg, NVIC_ISER_OFFSET, (UBase_t) NVIC_enSTATE_ENA) :
            NVIC__enSetWriteValue(enModuleArg, enVectorArg, NVIC_ICER_OFFSET, (UBase_t) NVIC_enSTATE_ENA);
    return (enErrorReg);

}

NVIC_nERROR NVIC__enEnableVector(NVIC_nMODULE enModuleArg, NVIC_nVECTOR enVectorArg, NVIC_nPRIORITY enPriority)
{
    NVIC_nERROR enErrorReg;
    enErrorReg = NVIC__enSetVectorPriority(enModuleArg, enVectorArg, enPriority);
    if(NVIC_enERROR_OK == enErrorReg)
    {
        enErrorReg = NVIC__enSetVectorState(enModuleArg, enVectorArg, NVIC_enSTATE_ENA);
    }
    return (enErrorReg);

}

NVIC_nERROR NVIC__enDisableVector(NVIC_nMODULE enModuleArg, NVIC_nVECTOR enVectorArg)
{
    NVIC_nERROR enErrorReg;
    enErrorReg = NVIC__enSetVectorState(enModuleArg, enVectorArg, NVIC_enSTATE_DIS);
    return (enErrorReg);
}
