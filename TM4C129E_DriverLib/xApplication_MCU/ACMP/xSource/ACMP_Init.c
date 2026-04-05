/**
 *
 * @file ACMP_Init.c
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
 * @verbatim 21 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 21 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/ACMP/xHeader/ACMP_Init.h>

#include <xApplication_MCU/ACMP/Intrinsics/xHeader/ACMP_Ready.h>
#include <xApplication_MCU/ACMP/Interrupt/ACMP_Interrupt.h>
#include <xApplication_MCU/ACMP/Intrinsics/xHeader/ACMP_Dependencies.h>

ACMP_nERROR ACMP__enInit(ACMP_nMODULE enModuleArg)
{
    ACMP_nERROR enErrorReg;
    UBase_t uxCompReg;
    ACMP_pvfIRQVectorHandler_t pfIrqVectorHandlerReg;

    uxCompReg = 0UL;
    enErrorReg = ACMP__enSetReadyOnRunMode(enModuleArg);
    while((uxCompReg < (UBase_t) ACMP_enCOMP_MAX) && (ACMP_enERROR_OK == enErrorReg))
    {
        pfIrqVectorHandlerReg = ACMP__pvfGetIRQVectorHandler(enModuleArg, (ACMP_nCOMP) uxCompReg);
        enErrorReg = ACMP__enRegisterIRQVectorHandler(enModuleArg, (ACMP_nCOMP) uxCompReg, pfIrqVectorHandlerReg);
        uxCompReg++;
    }

    return (enErrorReg);
}

