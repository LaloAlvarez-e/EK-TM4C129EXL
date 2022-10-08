/**
 *
 * @file I2C_MasterTransmit.c
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
 * @verbatim 31 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 31 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/I2C/Operations/xHeader/I2C_MasterTransmit.h>

#include <xApplication_MCU/I2C/Intrinsics/xHeader/I2C_Dependencies.h>
#include <xApplication_MCU/I2C/Operations/xHeader/I2C_Common.h>

I2C_nERROR I2C_Master_enTransmitGeneric(I2C_nMODULE enModule,
                                     I2C_nSTATE enMultiMasterArg,
                                     I2C_nSTATE enStopConditionArg,
                                     UBase_t uxSlaveAddressArg,
                                     const uint8_t *pu8Data,
                                     UBase_t uxDataSize)
{
    I2C_nERROR enErrorReg;
    UBase_t uxTimeout = I2C_TIMEOUT;
    I2C_nSTATUS enControllerBusy = I2C_enSTATUS_INACTIVE;
    I2C_nARBITRATION enArbitrationState = I2C_enARBITRATION_WON;
    I2C_nMODE enControllerMode;
    I2C_nOPERATION_ERROR enOperationError;
    UBase_t uxReg;
    uint8_t u8Reg;

    enOperationError = I2C_enOPERATION_ERROR_NONE;
    enControllerMode = I2C_enMODE_NONE;
    enErrorReg = I2C_enERROR_OK;
    if(0UL == (uintptr_t) pu8Data)
    {
        enErrorReg = I2C_enERROR_POINTER;
    }
    if(I2C_enERROR_OK == enErrorReg)
    {
        if(0UL == uxDataSize)
        {
            enErrorReg = I2C_enERROR_VALUE;
        }
    }
    if(I2C_enERROR_OK == enErrorReg)
    {
        enErrorReg = I2C__enGetMode(enModule, &enControllerMode);
    }
    if(I2C_enERROR_OK == enErrorReg)
    {
        if(0UL == ((UBase_t) I2C_enMODE_MASTER & enControllerMode))
        {
            enErrorReg = I2C_enERROR_VALUE;
        }
    }
    if(I2C_enERROR_OK == enErrorReg)
    {
        uxTimeout = I2C_TIMEOUT;
        do
        {
            enErrorReg = I2C_Master__enGetControllerStatus(enModule, &enControllerBusy);
            uxTimeout--;
        }while((I2C_enSTATUS_INACTIVE != enControllerBusy) && (0UL != uxTimeout) && (I2C_enERROR_OK == enErrorReg));

    }
    if(I2C_enERROR_OK == enErrorReg)
    {
        if(0UL == uxTimeout)
        {
            enErrorReg = I2C_enERROR_TIMEOUT;
        }
    }
    if(I2C_enERROR_OK == enErrorReg)
    {
        enErrorReg = I2C_Master__enSetSlaveAddressOperation(enModule, uxSlaveAddressArg, I2C_enOPERATION_TRANSMIT);
    }

    if(I2C_enERROR_OK == enErrorReg)
    {
        u8Reg = *pu8Data;
        uxReg = (UBase_t) u8Reg;
        enErrorReg = I2C_Master__enSetData(enModule, uxReg);
    }
    if(I2C_enERROR_OK == enErrorReg)
    {
        pu8Data += 1UL;
        uxDataSize -= 1UL;
        if(I2C_enSTATE_DIS != enMultiMasterArg)
        {
            enErrorReg = I2C_Master__enWaitMultiMaster(enModule, I2C_TIMEOUT);
        }
    }
    if(I2C_enERROR_OK == enErrorReg)
    {
        enErrorReg = I2C_Master__enSetControlState(enModule, I2C_enMASTER_CONTROL_RUN_START);
    }
    if(I2C_enERROR_OK == enErrorReg)
    {
        while((0UL != uxDataSize) && (I2C_enERROR_OK == enErrorReg))
        {
            uxTimeout = I2C_TIMEOUT;
            do
            {
                enErrorReg = I2C_Master__enGetControllerStatus(enModule, &enControllerBusy);
                uxTimeout--;
            }while((I2C_enSTATUS_INACTIVE != enControllerBusy) && (0UL != uxTimeout) && (I2C_enERROR_OK == enErrorReg));

            if(I2C_enERROR_OK == enErrorReg)
            {
                if(0UL == uxTimeout)
                {
                    enErrorReg = I2C_enERROR_TIMEOUT;
                }
            }

            if(I2C_enERROR_OK == enErrorReg)
            {
              enErrorReg = I2C_Master__enGetLastOperationErrorStatus(enModule, &enOperationError);
            }

            if(I2C_enERROR_OK == enErrorReg)
            {
                if(I2C_enOPERATION_ERROR_NONE != enOperationError)
                {
                    enErrorReg = I2C_Master__enGetArbitrationStatus(enModule, &enArbitrationState);

                    if(I2C_enERROR_OK == enErrorReg)
                    {
                        if(I2C_enARBITRATION_WON == enArbitrationState)
                        {
                            enErrorReg = I2C_Master__enSetControlState(enModule, I2C_enMASTER_CONTROL_STOP);
                        }
                    }
                    enErrorReg = I2C_enERROR_UNDEF;
                    /*Error Handling*/
                }
            }

            if(I2C_enERROR_OK == enErrorReg)
            {
                u8Reg = *pu8Data;
                uxReg = (UBase_t) u8Reg;
                enErrorReg = I2C_Master__enSetData(enModule, uxReg);
            }
            if(I2C_enERROR_OK == enErrorReg)
            {
                pu8Data += 1UL;
                uxDataSize -= 1UL;
                if(0UL != uxDataSize)
                {
                    enErrorReg = I2C_Master__enSetControlState(enModule, I2C_enMASTER_CONTROL_RUN);
                }
            }
        }
    }

    if(I2C_enERROR_OK == enErrorReg)
    {
        if(I2C_enSTATE_DIS != enStopConditionArg)
        {
            enErrorReg = I2C_Master__enGenerateStopCondition(enModule, I2C_TIMEOUT, (I2C_pvfIRQSourceHandler_t) 0UL);
        }
        else
        {
            enErrorReg = I2C_Master__enSetControlState(enModule, I2C_enMASTER_CONTROL_RUN);
        }
    }

    return (enErrorReg);
}

I2C_nERROR I2C_Master_enTransmitMultiByte(I2C_nMODULE enModule, UBase_t uxSlaveAddressArg, const uint8_t *pu8Data, UBase_t uxDataSize)
{
    I2C_nERROR enErrorReg;
    enErrorReg = I2C_Master_enTransmitGeneric(enModule, I2C_enSTATE_ENA, I2C_enSTATE_ENA, uxSlaveAddressArg, pu8Data, uxDataSize);
    return (enErrorReg);
}

I2C_nERROR I2C_Master_enTransmitByte(I2C_nMODULE enModule, UBase_t uxSlaveAddressArg, const uint8_t u8Data)
{
    I2C_nERROR enErrorReg;
    enErrorReg = I2C_Master_enTransmitGeneric(enModule, I2C_enSTATE_ENA, I2C_enSTATE_ENA, uxSlaveAddressArg, &u8Data, 1UL);
    return (enErrorReg);
}


