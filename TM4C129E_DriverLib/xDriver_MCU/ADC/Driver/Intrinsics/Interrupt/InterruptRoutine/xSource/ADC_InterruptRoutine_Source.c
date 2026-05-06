/**
 *
 * @file ADC_InterruptRoutine_Source.c
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
 * @verbatim 19 nov. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 19 nov. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/ADC/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/ADC_InterruptRoutine_Source.h>

static ADC_pvfIRQSourceHandler_t ADC_Sequencer_vIRQSourceHandler[(UBase_t)ADC_enMODULE_MAX]
                                                               [(UBase_t)ADC_enSEQ_MAX]
                                                               [(UBase_t)ADC_enINT_TYPE_MAX] =
{
 {
     {
          &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
          &MCU_vIRQSourceHandler_Dummy
     },
     {
          &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
          &MCU_vIRQSourceHandler_Dummy
     },
     {
          &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
          &MCU_vIRQSourceHandler_Dummy
     },
     {
          &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
          &MCU_vIRQSourceHandler_Dummy
     }
 },

 {
     {
          &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
          &MCU_vIRQSourceHandler_Dummy
     },
     {
          &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
          &MCU_vIRQSourceHandler_Dummy
     },
     {
          &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
          &MCU_vIRQSourceHandler_Dummy
     },
     {
          &MCU_vIRQSourceHandler_DummyNonBlocking, &MCU_vIRQSourceHandler_DummyNonBlocking,
          &MCU_vIRQSourceHandler_DummyNonBlocking
     }
 },
};

static ADC_pvfIRQSourceHandler_t ADC_SW_vIRQSourceHandler[(UBase_t)ADC_enMODULE_MAX]
                                                           [(UBase_t)ADC_enSEQ_MAX] =
{
    {
        &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy
    },

    {
        &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy
    },
};


static ADC_pvfIRQSourceHandler_t ADC_Comparator_vIRQSourceHandler[(UBase_t)ADC_enMODULE_MAX]
                                                             [(UBase_t)ADC_enSEQ_MAX]
                                                             [(UBase_t)ADC_enCOMPARATOR_MAX] =
{
  {
   {
       &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
       &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
       &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
       &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy
   },
   {
        &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy
    },
    {
         &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy
     },
     {
          &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
          &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
          &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
          &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy
      },
  },
  {
   {
       &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
       &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
       &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
       &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy
   },
   {
        &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy
    },
    {
         &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy
     },
     {
          &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
          &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
          &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
          &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy
      },
  },
};

ADC_pvfIRQSourceHandler_t ADC_SW__pvfGetIRQSourceHandler(ADC_nMODULE enModuleArg,
                                                         ADC_nSEQUENCER enSequencerArg)
{
    ADC_pvfIRQSourceHandler_t pvfFunctionReg;

    pvfFunctionReg = (ADC_pvfIRQSourceHandler_t) 0;
    if((ADC_enMODULE_MAX > enModuleArg) && (ADC_enSEQ_MAX > enSequencerArg))
    {
        pvfFunctionReg = ADC_SW_vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t) enSequencerArg];
    }
    return (pvfFunctionReg);
}


ADC_pvfIRQSourceHandler_t* ADC_SW__pvfGetIRQSourceHandlerPointer(ADC_nMODULE enModuleArg,
                                                                 ADC_nSEQUENCER enSequencerArg)
{
    ADC_pvfIRQSourceHandler_t* pvfFunctionReg;

    pvfFunctionReg = (ADC_pvfIRQSourceHandler_t*) 0;
    if((ADC_enMODULE_MAX > enModuleArg) && (ADC_enSEQ_MAX > enSequencerArg))
    {
        pvfFunctionReg = &ADC_SW_vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t) enSequencerArg];
    }
    return (pvfFunctionReg);
}

ADC_pvfIRQSourceHandler_t ADC_Sequencer__pvfGetIRQSourceHandler(ADC_nMODULE enModuleArg,
                                                             ADC_nSEQUENCER enSequencerArg,
                                                             ADC_nINT_TYPE enIntTypeArg)
{
    ADC_pvfIRQSourceHandler_t pvfFunctionReg;

    pvfFunctionReg = (ADC_pvfIRQSourceHandler_t) 0;
    if((ADC_enMODULE_MAX > enModuleArg) && (ADC_enSEQ_MAX > enSequencerArg) && (ADC_enINT_TYPE_MAX > enIntTypeArg))
    {
        pvfFunctionReg = ADC_Sequencer_vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t)enSequencerArg][(UBase_t)enIntTypeArg];
    }
    return (pvfFunctionReg);
}

ADC_pvfIRQSourceHandler_t* ADC_Sequencer__pvfGetIRQSourceHandlerPointer(ADC_nMODULE enModuleArg,
                                                                     ADC_nSEQUENCER enSequencerArg,
                                                                     ADC_nINT_TYPE enIntTypeArg)
{
    ADC_pvfIRQSourceHandler_t* pvfFunctionReg;

    pvfFunctionReg = (ADC_pvfIRQSourceHandler_t*) 0;
    if((ADC_enMODULE_MAX > enModuleArg) && (ADC_enSEQ_MAX > enSequencerArg) && (ADC_enINT_TYPE_MAX > enIntTypeArg))
    {
        pvfFunctionReg = &ADC_Sequencer_vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t)enSequencerArg][(UBase_t)enIntTypeArg];
    }
    return (pvfFunctionReg);
}

ADC_pvfIRQSourceHandler_t ADC_Comparator__pvfGetIRQSourceHandler(ADC_nMODULE enModuleArg,
                                                             ADC_nSEQUENCER enSequencerArg,
                                                             ADC_nCOMPARATOR enComparatorArg)
{
    ADC_pvfIRQSourceHandler_t pvfFunctionReg;

    pvfFunctionReg = (ADC_pvfIRQSourceHandler_t) 0;
    if((ADC_enMODULE_MAX > enModuleArg) && (ADC_enSEQ_MAX > enSequencerArg) && (ADC_enCOMPARATOR_MAX > enComparatorArg))
    {
        pvfFunctionReg = ADC_Comparator_vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t)enSequencerArg][(UBase_t)enComparatorArg];
    }
    return (pvfFunctionReg);
}

ADC_pvfIRQSourceHandler_t* ADC_Comparator__pvfGetIRQSourceHandlerPointer(ADC_nMODULE enModuleArg,
                                                                     ADC_nSEQUENCER enSequencerArg,
                                                                     ADC_nCOMPARATOR enComparatorArg)
{
    ADC_pvfIRQSourceHandler_t* pvfFunctionReg;

    pvfFunctionReg = (ADC_pvfIRQSourceHandler_t*) 0;
    if((ADC_enMODULE_MAX > enModuleArg) && (ADC_enSEQ_MAX > enSequencerArg) && (ADC_enCOMPARATOR_MAX > enComparatorArg))
    {
        pvfFunctionReg = &ADC_Comparator_vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t)enSequencerArg][(UBase_t)enComparatorArg];
    }
    return (pvfFunctionReg);
}
