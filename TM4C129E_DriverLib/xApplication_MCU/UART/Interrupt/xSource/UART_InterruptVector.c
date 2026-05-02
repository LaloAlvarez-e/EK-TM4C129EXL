/**
 *
 * @file UART_InterruptVector.c
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
 * @verbatim 13 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 13 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/UART/Interrupt/xHeader/UART_InterruptVector.h>

#include <xApplication_MCU/UART/Intrinsics/xHeader/UART_Dependencies.h>

static UART_nERROR UART__enGetInterruptVector(UART_nMODULE enModuleArg, NVIC_nVECTOR* enVectorArg);

static UART_nERROR UART__enGetInterruptVector(UART_nMODULE enModuleArg, NVIC_nVECTOR* enVectorArg)
{
    const NVIC_nVECTOR NVIC_VECTOR_UART[(UBase_t) UART_enMODULE_MAX]=
    {
        NVIC_enVECTOR_UART0, NVIC_enVECTOR_UART1, NVIC_enVECTOR_UART2, NVIC_enVECTOR_UART3,
        NVIC_enVECTOR_UART4, NVIC_enVECTOR_UART5, NVIC_enVECTOR_UART6, NVIC_enVECTOR_UART7
    };
    UART_nERROR enErrorReg;

    enErrorReg = (UART_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) UART_enMODULE_MAX);
    if(UART_enERROR_OK == enErrorReg)
    {
        *enVectorArg = NVIC_VECTOR_UART[(UBase_t) enModuleArg];
    }
    return (enErrorReg);
}

UART_nERROR UART__enSetInterruptVectorState(UART_nMODULE enModuleArg, UART_nSTATE enStateArg)
{
    NVIC_nVECTOR enVectorReg;
    UART_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_UART0;
    enErrorReg = UART__enGetInterruptVector(enModuleArg, &enVectorReg);
    if(UART_enERROR_OK == enErrorReg)
    {
        enErrorReg = (UART_nERROR) NVIC__enSetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE) enStateArg);
    }

    return (enErrorReg);
}

UART_nERROR UART__enSetInterruptVectorStateWithPriority(UART_nMODULE enModuleArg, UART_nSTATE enStateArg, UART_nPRIORITY enPriorityArg)
{
    NVIC_nVECTOR enVectorReg;
    UART_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_UART0;
    enErrorReg = UART__enGetInterruptVector(enModuleArg, &enVectorReg);
    if(UART_enERROR_OK == enErrorReg)
    {
        enErrorReg = (UART_nERROR) NVIC__enSetVectorPriority(NVIC_enMODULE_0, enVectorReg, (NVIC_nPRIORITY) enPriorityArg);
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        enErrorReg = (UART_nERROR) NVIC__enSetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE) enStateArg);
    }

    return (enErrorReg);
}

UART_nERROR UART__enGetInterruptVectorState(UART_nMODULE enModuleArg, UART_nSTATE* penStateArg)
{
    NVIC_nVECTOR enVectorReg;
    UART_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_UART0;
    enErrorReg = UART_enERROR_OK;
    if(0UL == (uintptr_t) penStateArg)
    {
        enErrorReg = UART_enERROR_POINTER;
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        enErrorReg = UART__enGetInterruptVector(enModuleArg, &enVectorReg);
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        enErrorReg = (UART_nERROR) NVIC__enGetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE*) penStateArg);
    }

    return (enErrorReg);
}

UART_nERROR UART__enGetInterruptVectorStateWithPriority(UART_nMODULE enModuleArg, UART_nSTATE* penStateArg, UART_nPRIORITY* penPriorityArg)
{
    NVIC_nVECTOR enVectorReg;
    UART_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_UART0;
    enErrorReg = UART_enERROR_OK;
    if((0UL == (uintptr_t) penStateArg) || (0UL == (uintptr_t) penPriorityArg))
    {
        enErrorReg = UART_enERROR_POINTER;
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        enErrorReg = UART__enGetInterruptVector(enModuleArg, &enVectorReg);
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        enErrorReg = (UART_nERROR) NVIC__enGetVectorPriority(NVIC_enMODULE_0, enVectorReg, (NVIC_nPRIORITY*) penPriorityArg);
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        enErrorReg = (UART_nERROR) NVIC__enGetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE*) penStateArg);
    }

    return (enErrorReg);
}

UART_nERROR UART__enEnableInterruptVector(UART_nMODULE enModuleArg)
{
    UART_nERROR enErrorReg;
    enErrorReg = UART__enSetInterruptVectorState(enModuleArg, UART_enSTATE_ENA);
    return (enErrorReg);
}

UART_nERROR UART__enEnableInterruptVectorWithPriority(UART_nMODULE enModuleArg, UART_nPRIORITY enPriorityArg)
{
    UART_nERROR enErrorReg;
    enErrorReg = UART__enSetInterruptVectorStateWithPriority(enModuleArg, UART_enSTATE_ENA, enPriorityArg);
    return (enErrorReg);
}

UART_nERROR UART__enDisableInterruptVector(UART_nMODULE enModuleArg)
{
    UART_nERROR enErrorReg;
    enErrorReg = UART__enSetInterruptVectorState(enModuleArg, UART_enSTATE_DIS);
    return (enErrorReg);
}

UART_nERROR UART__enDisableInterruptVectorWithPriority(UART_nMODULE enModuleArg, UART_nPRIORITY enPriorityArg)
{
    UART_nERROR enErrorReg;
    enErrorReg = UART__enSetInterruptVectorStateWithPriority(enModuleArg, UART_enSTATE_DIS, enPriorityArg);
    return (enErrorReg);
}
