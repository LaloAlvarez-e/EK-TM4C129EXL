/**
 *
 * @file GPIO_InterruptVector.c
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
 * @verbatim 11 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 11 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/GPIO/Interrupt/xHeader/GPIO_InterruptVector.h>

#include <xApplication_MCU/GPIO/Intrinsics/xHeader/GPIO_Dependencies.h>

static GPIO_nERROR GPIO__enGetInterruptVector(GPIO_nPORT enPortArg, NVIC_nVECTOR* enVectorArg);

static GPIO_nERROR GPIO__enGetInterruptVector(GPIO_nPORT enPortArg, NVIC_nVECTOR* enVectorArg)
{
    const NVIC_nVECTOR NVIC_enVECTOR_GPIO[ (UBase_t) GPIO_enPORT_MAX] =
    {
      NVIC_enVECTOR_GPIOA, NVIC_enVECTOR_GPIOB, NVIC_enVECTOR_GPIOC, NVIC_enVECTOR_GPIOD, NVIC_enVECTOR_GPIOE,
      NVIC_enVECTOR_GPIOF, NVIC_enVECTOR_GPIOG, NVIC_enVECTOR_GPIOH, NVIC_enVECTOR_GPIOJ, NVIC_enVECTOR_GPIOK,
      NVIC_enVECTOR_GPIOL, NVIC_enVECTOR_GPIOM, NVIC_enVECTOR_GPION, NVIC_enVECTOR_GPIOP, NVIC_enVECTOR_GPIOQ
    };
    GPIO_nERROR enErrorReg;

    enErrorReg = (GPIO_nERROR) MCU__enCheckParams((UBase_t) enPortArg, (UBase_t) GPIO_enPORT_MAX);
    if(GPIO_enERROR_OK == enErrorReg)
    {
        *enVectorArg = NVIC_enVECTOR_GPIO[(UBase_t) enPortArg];
    }
    return (enErrorReg);
}

GPIO_nERROR GPIO__enSetInterruptVectorState(GPIO_nPORT enPortArg, GPIO_nSTATE enStateArg)
{
    NVIC_nVECTOR enVectorReg;
    GPIO_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_GPIOA;
    enErrorReg = GPIO__enGetInterruptVector(enPortArg, &enVectorReg);
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = (GPIO_nERROR) NVIC__enSetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE) enStateArg);
    }
    
    return (enErrorReg);
}

GPIO_nERROR GPIO__enSetInterruptVectorStateWithPriority(GPIO_nPORT enPortArg, GPIO_nSTATE enStateArg, GPIO_nPRIORITY enPriorityArg)
{
    NVIC_nVECTOR enVectorReg;
    GPIO_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_GPIOA;
    enErrorReg = GPIO__enGetInterruptVector(enPortArg, &enVectorReg);
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = (GPIO_nERROR) NVIC__enSetVectorPriority(NVIC_enMODULE_0, enVectorReg, (NVIC_nPRIORITY) enPriorityArg);
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = (GPIO_nERROR) NVIC__enSetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE) enStateArg);
    }
    return (enErrorReg);
}

GPIO_nERROR GPIO__enGetInterruptVectorState(GPIO_nPORT enPortArg, GPIO_nSTATE* penStateArg)
{
    NVIC_nVECTOR enVectorReg;
    GPIO_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_GPIOA;
    enErrorReg = GPIO_enERROR_OK;
    if(0UL == (uintptr_t) penStateArg)
    {
        enErrorReg = GPIO_enERROR_POINTER;
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = GPIO__enGetInterruptVector(enPortArg, &enVectorReg);
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = (GPIO_nERROR) NVIC__enGetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE*) penStateArg);
    }
    return (enErrorReg);
}

GPIO_nERROR GPIO__enGetInterruptVectorStateWithPriority(GPIO_nPORT enPortArg, GPIO_nSTATE* penStateArg, GPIO_nPRIORITY* penPriorityArg)
{
    NVIC_nVECTOR enVectorReg;
    GPIO_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_GPIOA;
    enErrorReg = GPIO_enERROR_OK;
    if((0UL == (uintptr_t) penStateArg) || (0UL == (uintptr_t) penPriorityArg))
    {
        enErrorReg = GPIO_enERROR_POINTER;
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = GPIO__enGetInterruptVector(enPortArg, &enVectorReg);
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = (GPIO_nERROR) NVIC__enGetVectorPriority(NVIC_enMODULE_0, enVectorReg, (NVIC_nPRIORITY*) penPriorityArg);
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = (GPIO_nERROR) NVIC__enGetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE*) penStateArg);
    }

    return (enErrorReg);
}

GPIO_nERROR GPIO__enEnableInterruptVector(GPIO_nPORT enPortArg)
{
    GPIO_nERROR enErrorReg;
    enErrorReg = GPIO__enSetInterruptVectorState(enPortArg, GPIO_enSTATE_ENA);
    return (enErrorReg);
}

GPIO_nERROR GPIO__enEnableInterruptVectorWithPriority(GPIO_nPORT enPortArg, GPIO_nPRIORITY enPriorityArg)
{
    GPIO_nERROR enErrorReg;
    enErrorReg = GPIO__enSetInterruptVectorStateWithPriority(enPortArg, GPIO_enSTATE_ENA, enPriorityArg);
    return (enErrorReg);
}

GPIO_nERROR GPIO__enDisableInterruptVector(GPIO_nPORT enPortArg)
{
    GPIO_nERROR enErrorReg;
    enErrorReg = GPIO__enSetInterruptVectorState(enPortArg, GPIO_enSTATE_DIS);
    return (enErrorReg);
}

GPIO_nERROR GPIO__enDisableInterruptVectorWithPriority(GPIO_nPORT enPortArg, GPIO_nPRIORITY enPriorityArg)
{
    GPIO_nERROR enErrorReg;
    enErrorReg = GPIO__enSetInterruptVectorStateWithPriority(enPortArg, GPIO_enSTATE_DIS, enPriorityArg);
    return (enErrorReg);
}

static GPIO_nERROR GPIO_PQ__enGetInterruptVector(GPIO_nPORT enPortArg, GPIO_nPIN enPinArg, NVIC_nVECTOR* enVectorArg);

static GPIO_nERROR GPIO_PQ__enGetInterruptVector(GPIO_nPORT enPortArg, GPIO_nPIN enPinArg, NVIC_nVECTOR* enVectorArg)
{
    const NVIC_nVECTOR NVIC_enVECTOR_GPIOPQ [(UBase_t) GPIO_enPORT_MAX - (UBase_t) GPIO_enPORT_P][(UBase_t) GPIO_enPIN_MAX] =
    {
      {
       NVIC_enVECTOR_GPIOP, NVIC_enVECTOR_GPIOP1, NVIC_enVECTOR_GPIOP2, NVIC_enVECTOR_GPIOP3,
       NVIC_enVECTOR_GPIOP4, NVIC_enVECTOR_GPIOP5, NVIC_enVECTOR_GPIOP6, NVIC_enVECTOR_GPIOP7
      },
      {
       NVIC_enVECTOR_GPIOQ, NVIC_enVECTOR_GPIOP1, NVIC_enVECTOR_GPIOP2, NVIC_enVECTOR_GPIOP3,
       NVIC_enVECTOR_GPIOQ4, NVIC_enVECTOR_GPIOQ5, NVIC_enVECTOR_GPIOQ6, NVIC_enVECTOR_GPIOQ7
      },
    };
    GPIO_nERROR enErrorReg;

    enErrorReg = GPIO_enERROR_OK;
    if((enPortArg != GPIO_enPORT_P) && (enPortArg != GPIO_enPORT_Q))
    {
        enErrorReg = GPIO_enERROR_RANGE;
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = (GPIO_nERROR) MCU__enCheckParams((UBase_t) enPinArg, (UBase_t) GPIO_enPIN_MAX);
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        if(GPIO_enPORT_P == enPortArg)
        {
            *enVectorArg = NVIC_enVECTOR_GPIOPQ[0UL][(UBase_t) enPinArg];
        }
        else if(GPIO_enPORT_Q == enPortArg)
        {
            *enVectorArg = NVIC_enVECTOR_GPIOPQ[1UL][(UBase_t) enPinArg];
        }

    }
    return (enErrorReg);
}

GPIO_nERROR GPIO_PQ__enSetInterruptVectorState(GPIO_nPORT enPortArg, GPIO_nPIN enPinArg, GPIO_nSTATE enStateArg)
{
    NVIC_nVECTOR enVectorReg;
    GPIO_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_GPIOA;
    enErrorReg = GPIO_PQ__enGetInterruptVector(enPortArg, enPinArg, &enVectorReg);
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = (GPIO_nERROR) NVIC__enSetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE) enStateArg);
    }

    return (enErrorReg);
}

GPIO_nERROR GPIO_PQ__enSetInterruptVectorStateWithPriority(GPIO_nPORT enPortArg, GPIO_nPIN enPinArg, GPIO_nSTATE enStateArg, GPIO_nPRIORITY enPriorityArg)
{
    NVIC_nVECTOR enVectorReg;
    GPIO_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_GPIOA;
    enErrorReg = GPIO_PQ__enGetInterruptVector(enPortArg, enPinArg, &enVectorReg);
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = (GPIO_nERROR) NVIC__enSetVectorPriority(NVIC_enMODULE_0, enVectorReg, (NVIC_nPRIORITY) enPriorityArg);
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = (GPIO_nERROR) NVIC__enSetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE) enStateArg);
    }

    return (enErrorReg);
}

GPIO_nERROR GPIO_PQ__enGetInterruptVectorState(GPIO_nPORT enPortArg, GPIO_nPIN enPinArg, GPIO_nSTATE* penStateArg)
{
    NVIC_nVECTOR enVectorReg;
    GPIO_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_GPIOA;
    enErrorReg = GPIO_enERROR_OK;
    if(0UL == (uintptr_t) penStateArg)
    {
        enErrorReg = GPIO_enERROR_POINTER;
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = GPIO_PQ__enGetInterruptVector(enPortArg, enPinArg, &enVectorReg);
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = (GPIO_nERROR) NVIC__enGetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE*) penStateArg);
    }

    return (enErrorReg);
}

GPIO_nERROR GPIO_PQ__enGetInterruptVectorStateWithPriority(GPIO_nPORT enPortArg, GPIO_nPIN enPinArg, GPIO_nSTATE* penStateArg, GPIO_nPRIORITY* penPriorityArg)
{
    NVIC_nVECTOR enVectorReg;
    GPIO_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_GPIOA;
    enErrorReg = GPIO_enERROR_OK;
    if((0UL == (uintptr_t) penStateArg) || (0UL == (uintptr_t) penPriorityArg))
    {
        enErrorReg = GPIO_enERROR_POINTER;
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = GPIO_PQ__enGetInterruptVector(enPortArg, enPinArg, &enVectorReg);
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = (GPIO_nERROR) NVIC__enGetVectorPriority(NVIC_enMODULE_0, enVectorReg, (NVIC_nPRIORITY*) penPriorityArg);
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = (GPIO_nERROR) NVIC__enGetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE*) penStateArg);
    }

    return (enErrorReg);
}

    GPIO_nERROR GPIO_PQ__enEnableInterruptVector(GPIO_nPORT enPortArg, GPIO_nPIN enPinArg)
{
    GPIO_nERROR enErrorReg;
    enErrorReg = GPIO_PQ__enSetInterruptVectorState(enPortArg, enPinArg, GPIO_enSTATE_ENA);
    return (enErrorReg);
}

GPIO_nERROR GPIO_PQ__enEnableInterruptVectorWithPriority(GPIO_nPORT enPortArg, GPIO_nPIN enPinArg, GPIO_nPRIORITY enPriorityArg)
{
    GPIO_nERROR enErrorReg;
    enErrorReg = GPIO_PQ__enSetInterruptVectorStateWithPriority(enPortArg, enPinArg, GPIO_enSTATE_ENA, enPriorityArg);
    return (enErrorReg);
}

GPIO_nERROR GPIO_PQ__enDisableInterruptVector(GPIO_nPORT enPortArg, GPIO_nPIN enPinArg)
{
    GPIO_nERROR enErrorReg;
    enErrorReg = GPIO_PQ__enSetInterruptVectorState(enPortArg, enPinArg, GPIO_enSTATE_DIS);
    return (enErrorReg);
}

GPIO_nERROR GPIO_PQ__enDisableInterruptVectorWithPriority(GPIO_nPORT enPortArg, GPIO_nPIN enPinArg, GPIO_nPRIORITY enPriorityArg)
{
    GPIO_nERROR enErrorReg;
    enErrorReg = GPIO_PQ__enSetInterruptVectorStateWithPriority(enPortArg, enPinArg, GPIO_enSTATE_DIS, enPriorityArg);
    return (enErrorReg);
}

