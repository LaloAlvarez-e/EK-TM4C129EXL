/**
 *
 * @file PWM_InterruptRoutine_Source.c
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
 * @verbatim 28 dic. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 28 dic. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/PWM/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/PWM_InterruptRoutine_Source.h>

static PWM_pvfIRQSourceHandler_t PWM_Generator_vIRQSourceHandler[(UBase_t)PWM_enMODULE_MAX]
                                                                [(UBase_t)PWM_enGEN_MAX]
                                                                [(UBase_t)PWM_enEVENT_MAX] =
{
 {
     {
          &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
          &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy
     },
     {
          &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
          &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy
     },
     {
          &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
          &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy
     },
     {
          &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
          &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy
     }
 }
};

static PWM_pvfIRQSourceHandler_t PWM_FaultSW_vIRQSourceHandler[(UBase_t)PWM_enMODULE_MAX]=
{
     &MCU_vIRQSourceHandler_Dummy,
};


static PWM_pvfIRQSourceHandler_t PWM_FaultInput_vIRQSourceHandler[(UBase_t)PWM_enMODULE_MAX]
                                                                 [(UBase_t)PWM_enGEN_MAX]
                                                                 [(UBase_t)PWM_enFAULT_INPUT_MAX] =
{
  {
    {
     &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
    },
    {
     &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
    },
    {
     &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
    },
    {
     &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
    },
  }
};


static PWM_pvfIRQSourceHandler_t PWM_FaultDComp_vIRQSourceHandler[(UBase_t)PWM_enMODULE_MAX]
                                                                 [(UBase_t)PWM_enGEN_MAX]
                                                                 [(UBase_t)PWM_enFAULT_DCOMP_MAX] =
{
  {
    {
     &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
     &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
    },
    {
     &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
     &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
    },
    {
     &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
     &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
    },
    {
     &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
     &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
    },
  }
};

PWM_pvfIRQSourceHandler_t PWM_Generator__pvfGetIRQSourceHandler(PWM_nMODULE enModuleArg,
                                                             PWM_nGENERATOR enGeneratorArg,
                                                             PWM_nEVENT enEventArg)
{
    PWM_pvfIRQSourceHandler_t pvfFunctionReg;

    pvfFunctionReg = (PWM_pvfIRQSourceHandler_t) 0;
    if((PWM_enMODULE_MAX > enModuleArg) && (PWM_enGEN_MAX > enGeneratorArg) && (PWM_enEVENT_MAX > enEventArg))
    {
        pvfFunctionReg = PWM_Generator_vIRQSourceHandler[(UBase_t) enModuleArg] [(UBase_t)enGeneratorArg] [(UBase_t)enEventArg];
    }
    return (pvfFunctionReg);
}


PWM_pvfIRQSourceHandler_t* PWM_Generator__pvfGetIRQSourceHandlerPointer(PWM_nMODULE enModuleArg,
                                                                     PWM_nGENERATOR enGeneratorArg,
                                                                     PWM_nEVENT enEventArg)
{
    PWM_pvfIRQSourceHandler_t* pvfFunctionReg;

    pvfFunctionReg = (PWM_pvfIRQSourceHandler_t*) 0;
    if((PWM_enMODULE_MAX > enModuleArg) && (PWM_enGEN_MAX > enGeneratorArg) && (PWM_enEVENT_MAX > enEventArg))
    {
        pvfFunctionReg = &PWM_Generator_vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t)enGeneratorArg][(UBase_t)enEventArg];
    }
    return (pvfFunctionReg);
}

PWM_pvfIRQSourceHandler_t PWM_FaultSW__pvfGetIRQSourceHandler(PWM_nMODULE enModuleArg)
{
    PWM_pvfIRQSourceHandler_t pvfFunctionReg;

    pvfFunctionReg = (PWM_pvfIRQSourceHandler_t) 0;
    if(PWM_enMODULE_MAX > enModuleArg)
    {
        pvfFunctionReg = PWM_FaultSW_vIRQSourceHandler[(UBase_t) enModuleArg];
    }
    return (pvfFunctionReg);
}


PWM_pvfIRQSourceHandler_t* PWM_FaultSW__pvfGetIRQSourceHandlerPointer(PWM_nMODULE enModuleArg)
{
    PWM_pvfIRQSourceHandler_t* pvfFunctionReg;

    pvfFunctionReg = (PWM_pvfIRQSourceHandler_t*) 0;
    if(PWM_enMODULE_MAX > enModuleArg)
    {
        pvfFunctionReg = &PWM_FaultSW_vIRQSourceHandler[(UBase_t) enModuleArg];
    }
    return (pvfFunctionReg);
}

PWM_pvfIRQSourceHandler_t PWM_FaultInput__pvfGetIRQSourceHandler(PWM_nMODULE enModuleArg,
                                                                 PWM_nGENERATOR enGeneratorArg,
                                                                 PWM_nFAULT_INPUT enInputArg)
{
    PWM_pvfIRQSourceHandler_t pvfFunctionReg;

    pvfFunctionReg = (PWM_pvfIRQSourceHandler_t) 0;
    if((PWM_enMODULE_MAX > enModuleArg) && (PWM_enGEN_MAX > enGeneratorArg) && (PWM_enFAULT_INPUT_MAX > enInputArg))
    {
        pvfFunctionReg = PWM_FaultInput_vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t)enGeneratorArg][(UBase_t)enInputArg];
    }
    return (pvfFunctionReg);
}


PWM_pvfIRQSourceHandler_t* PWM_FaultInput__pvfGetIRQSourceHandlerPointer(PWM_nMODULE enModuleArg,
                                                                         PWM_nGENERATOR enGeneratorArg,
                                                                         PWM_nFAULT_INPUT enInputArg)
{
    PWM_pvfIRQSourceHandler_t* pvfFunctionReg;

    pvfFunctionReg = (PWM_pvfIRQSourceHandler_t*) 0;
    if((PWM_enMODULE_MAX > enModuleArg) && (PWM_enGEN_MAX > enGeneratorArg) && (PWM_enFAULT_INPUT_MAX > enInputArg))
    {
        pvfFunctionReg = &PWM_FaultInput_vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t)enGeneratorArg][(UBase_t)enInputArg];
    }
    return (pvfFunctionReg);
}



PWM_pvfIRQSourceHandler_t PWM_FaultDComp__pvfGetIRQSourceHandler(PWM_nMODULE enModuleArg,
                                                                 PWM_nGENERATOR enGeneratorArg,
                                                                 PWM_nFAULT_DCOMP enDCompArg)
{
    PWM_pvfIRQSourceHandler_t pvfFunctionReg;

    pvfFunctionReg = (PWM_pvfIRQSourceHandler_t) 0;
    if((PWM_enMODULE_MAX > enModuleArg) && (PWM_enGEN_MAX > enGeneratorArg) && (PWM_enFAULT_DCOMP_MAX > enDCompArg))
    {
        pvfFunctionReg = PWM_FaultDComp_vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t)enGeneratorArg][(UBase_t)enDCompArg];
    }
    return (pvfFunctionReg);
}


PWM_pvfIRQSourceHandler_t* PWM_FaultDComp__pvfGetIRQSourceHandlerPointer(PWM_nMODULE enModuleArg,
                                                                         PWM_nGENERATOR enGeneratorArg,
                                                                         PWM_nFAULT_DCOMP enDCompArg)
{
    PWM_pvfIRQSourceHandler_t* pvfFunctionReg;

    pvfFunctionReg = (PWM_pvfIRQSourceHandler_t*) 0;
    if((PWM_enMODULE_MAX > enModuleArg) && (PWM_enGEN_MAX > enGeneratorArg) && (PWM_enFAULT_DCOMP_MAX > enDCompArg))
    {
        pvfFunctionReg = &PWM_FaultDComp_vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t)enGeneratorArg][(UBase_t)enDCompArg];
    }
    return (pvfFunctionReg);
}
