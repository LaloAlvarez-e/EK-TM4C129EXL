/**
 *
 * @file GPIO_InterruptRoutine_Source.c
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
 * @verbatim 30 jun. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 30 jun. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/GPIO/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/GPIO_InterruptRoutine_Source.h>

static GPIO_pvfIRQSourceHandler_t GPIO_vIRQSourceHandler[(UBase_t) GPIO_enPORT_MAX]
                                                          [(UBase_t) GPIO_enPIN_MAX] =
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
};

static GPIO_pvfIRQSourceHandler_t GPIO_DMA_vIRQSourceHandler[(UBase_t) GPIO_enPORT_MAX]
                                                             [(UBase_t) GPIO_enPIN_MAX] =
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
   };

static GPIO_pvfIRQSourceHandler_t GPIO_SW_vIRQSourceHandler[(UBase_t) GPIO_enPORT_MAX] =
{
    &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
    &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
    &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
    &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
    &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
    &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
    &MCU_vIRQSourceHandler_Dummy, &MCU_vIRQSourceHandler_Dummy,
    &MCU_vIRQSourceHandler_Dummy
};

static GPIO_pvfIRQSourceHandler_t GPIO_PQ_vIRQSourceHandler[(UBase_t) GPIO_enPORT_MAX - (UBase_t) GPIO_enPORT_P]
                                                              [(UBase_t) GPIO_enPIN_MAX] =
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
    }
};

GPIO_pvfIRQSourceHandler_t GPIO__pvfGetIRQSourceHandler(GPIO_nPORT enPortArg,
                                                        GPIO_nPIN enPinArg)
{
    GPIO_pvfIRQSourceHandler_t pvfFunctionReg;

    pvfFunctionReg = (GPIO_pvfIRQSourceHandler_t) 0;
    if((GPIO_enPORT_MAX > enPortArg) && (GPIO_enPIN_MAX > enPinArg))
    {
        pvfFunctionReg = GPIO_vIRQSourceHandler[(UBase_t) enPortArg][(UBase_t) enPinArg];
    }
    return (pvfFunctionReg);
}

GPIO_pvfIRQSourceHandler_t* GPIO__pvfGetIRQSourceHandlerPointer(GPIO_nPORT enPortArg,
                                                                GPIO_nPIN enPinArg)
{
    GPIO_pvfIRQSourceHandler_t* pvfFunctionReg;

    pvfFunctionReg = (GPIO_pvfIRQSourceHandler_t*) 0;
    if((GPIO_enPORT_MAX > enPortArg) && (GPIO_enPIN_MAX > enPinArg))
    {
        pvfFunctionReg = &GPIO_vIRQSourceHandler[(UBase_t) enPortArg][(UBase_t) enPinArg];
    }
    return (pvfFunctionReg);
}


GPIO_pvfIRQSourceHandler_t GPIO_DMA__pvfGetIRQSourceHandler(GPIO_nPORT enPortArg,
                                                            GPIO_nPIN enPinArg)
{
    GPIO_pvfIRQSourceHandler_t pvfFunctionReg;

    pvfFunctionReg = (GPIO_pvfIRQSourceHandler_t) 0;
    if((GPIO_enPORT_MAX > enPortArg) && (GPIO_enPIN_MAX > enPinArg))
    {
        pvfFunctionReg = GPIO_DMA_vIRQSourceHandler[(UBase_t) enPortArg][(UBase_t) enPinArg];
    }
    return (pvfFunctionReg);
}

GPIO_pvfIRQSourceHandler_t* GPIO_DMA__pvfGetIRQSourceHandlerPointer(GPIO_nPORT enPortArg,
                                                                    GPIO_nPIN enPinArg)
{
    GPIO_pvfIRQSourceHandler_t* pvfFunctionReg;

    pvfFunctionReg = (GPIO_pvfIRQSourceHandler_t*) 0;
    if((GPIO_enPORT_MAX > enPortArg) && (GPIO_enPIN_MAX > enPinArg))
    {
        pvfFunctionReg = &GPIO_DMA_vIRQSourceHandler[(UBase_t) enPortArg][(UBase_t) enPinArg];
    }
    return (pvfFunctionReg);
}

GPIO_pvfIRQSourceHandler_t GPIO_SW__pvfGetIRQSourceHandler(GPIO_nPORT enPortArg)
{
    GPIO_pvfIRQSourceHandler_t pvfFunctionReg;

    pvfFunctionReg = (GPIO_pvfIRQSourceHandler_t) 0;
    if(GPIO_enPORT_MAX > enPortArg)
    {
        pvfFunctionReg = GPIO_SW_vIRQSourceHandler[(UBase_t) enPortArg];
    }
    return (pvfFunctionReg);
}

GPIO_pvfIRQSourceHandler_t* GPIO_SW__pvfGetIRQSourceHandlerPointer(GPIO_nPORT enPortArg)
{
    GPIO_pvfIRQSourceHandler_t* pvfFunctionReg;

    pvfFunctionReg = (GPIO_pvfIRQSourceHandler_t*) 0;
    if(GPIO_enPORT_MAX > enPortArg)
    {
        pvfFunctionReg = &GPIO_SW_vIRQSourceHandler[(UBase_t) enPortArg];
    }
    return (pvfFunctionReg);
}

GPIO_pvfIRQSourceHandler_t GPIO_PQ__pvfGetIRQSourceHandler(GPIO_nPORT enPortArg,
                                                           GPIO_nPIN enPinArg)
{
    GPIO_pvfIRQSourceHandler_t pvfFunctionReg;

    if((GPIO_enPORT_P == enPortArg) && (GPIO_enPIN_MAX > enPinArg))
    {
        pvfFunctionReg = GPIO_PQ_vIRQSourceHandler[0UL] [(UBase_t) enPinArg];
    }
    else if((GPIO_enPORT_Q == enPortArg) && (GPIO_enPIN_MAX > enPinArg))
    {
        pvfFunctionReg = GPIO_PQ_vIRQSourceHandler[1UL] [(UBase_t) enPinArg];
    }
    else
    {
        pvfFunctionReg = (GPIO_pvfIRQSourceHandler_t) 0UL;
    }

    return (pvfFunctionReg);
}

GPIO_pvfIRQSourceHandler_t* GPIO_PQ__pvfGetIRQSourceHandlerPointer(GPIO_nPORT enPortArg,
                                                                   GPIO_nPIN enPinArg)
{
    GPIO_pvfIRQSourceHandler_t* pvfFunctionReg;

    if((GPIO_enPORT_P == enPortArg) && (GPIO_enPIN_MAX > enPinArg))
    {
        pvfFunctionReg = &GPIO_PQ_vIRQSourceHandler[0UL] [(UBase_t) enPinArg];
    }
    else if((GPIO_enPORT_Q == enPortArg) && (GPIO_enPIN_MAX > enPinArg))
    {
        pvfFunctionReg = &GPIO_PQ_vIRQSourceHandler[1UL] [(UBase_t) enPinArg];
    }
    else
    {
        pvfFunctionReg = (GPIO_pvfIRQSourceHandler_t*) 0UL;
    }

    return (pvfFunctionReg);
}
