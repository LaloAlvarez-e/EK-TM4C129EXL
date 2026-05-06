/**
 *
 * @file ACMP_InterruptRoutine_Source.c
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
#include <xDriver_MCU/ACMP/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/ACMP_InterruptRoutine_Source.h>

static ACMP_pvfIRQSourceHandler_t ACMP_SW__vIRQSourceHandler[(UBase_t)ACMP_enMODULE_MAX][(UBase_t)ACMP_enCOMP_MAX] =
{
    {
     &MCU_vIRQSourceHandler_Dummy,
     &MCU_vIRQSourceHandler_Dummy,
     &MCU_vIRQSourceHandler_Dummy
    }
};

static ACMP_pvfIRQSourceHandler_t ACMP__vIRQSourceHandler[(UBase_t)ACMP_enMODULE_MAX][(UBase_t)ACMP_enCOMP_MAX] =
{
    {
     &MCU_vIRQSourceHandler_Dummy,
     &MCU_vIRQSourceHandler_Dummy,
     &MCU_vIRQSourceHandler_Dummy
    }
};

ACMP_pvfIRQSourceHandler_t ACMP_SW__pvfGetIRQSourceHandler(ACMP_nMODULE enModuleArg,
                                                           ACMP_nCOMP enComparatorArg)
{
    ACMP_pvfIRQSourceHandler_t pvfFunctionReg;

    pvfFunctionReg = (ACMP_pvfIRQSourceHandler_t) 0;
    if((ACMP_enMODULE_MAX > enModuleArg) && (ACMP_enCOMP_MAX > enComparatorArg))
    {
        pvfFunctionReg = ACMP_SW__vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t) enComparatorArg];
    }
    return (pvfFunctionReg);
}

ACMP_pvfIRQSourceHandler_t* ACMP_SW__pvfGetIRQSourceHandlerPointer(ACMP_nMODULE enModuleArg,
                                                                   ACMP_nCOMP enComparatorArg)
{
    ACMP_pvfIRQSourceHandler_t* pvfFunctionReg;

    pvfFunctionReg = (ACMP_pvfIRQSourceHandler_t*) 0;
    if((ACMP_enMODULE_MAX > enModuleArg) && (ACMP_enCOMP_MAX > enComparatorArg))
    {
        pvfFunctionReg = &ACMP_SW__vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t) enComparatorArg];
    }
    return (pvfFunctionReg);
}

ACMP_pvfIRQSourceHandler_t ACMP__pvfGetIRQSourceHandler(ACMP_nMODULE enModuleArg,
                                                        ACMP_nCOMP enComparatorArg)
{
    ACMP_pvfIRQSourceHandler_t pvfFunctionReg;

    pvfFunctionReg = (ACMP_pvfIRQSourceHandler_t) 0;
    if((ACMP_enMODULE_MAX > enModuleArg) && (ACMP_enCOMP_MAX > enComparatorArg))
    {
        pvfFunctionReg = ACMP__vIRQSourceHandler[(UBase_t) enModuleArg] [(UBase_t) enComparatorArg];
    }
    return (pvfFunctionReg);
}

ACMP_pvfIRQSourceHandler_t* ACMP__pvfGetIRQSourceHandlerPointer(ACMP_nMODULE enModuleArg,
                                                               ACMP_nCOMP enComparatorArg)
{
    ACMP_pvfIRQSourceHandler_t* pvfFunctionReg;

    pvfFunctionReg = (ACMP_pvfIRQSourceHandler_t*) 0;
    if((ACMP_enMODULE_MAX > enModuleArg) && (ACMP_enCOMP_MAX > enComparatorArg))
    {
        pvfFunctionReg = &ACMP__vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t) enComparatorArg];
    }
    return (pvfFunctionReg);
}
