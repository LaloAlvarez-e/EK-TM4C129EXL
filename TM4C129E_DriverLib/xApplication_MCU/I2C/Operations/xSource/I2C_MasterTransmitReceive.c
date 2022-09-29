/**
 *
 * @file I2C_MasterTransmitReceive.c
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
#include <xApplication_MCU/I2C/Operations/xHeader/I2C_MasterTransmitReceive.h>
#include <xApplication_MCU/I2C/Operations/xHeader/I2C_MasterTransmit.h>
#include <xApplication_MCU/I2C/Operations/xHeader/I2C_MasterReceive.h>

I2C_nERROR I2C_Master_enTransmitReceive(I2C_nMODULE enModule, uint32_t u32SlaveAddressArg,
                                         const uint8_t *pu8DataTransmit, uint32_t u32DataTransmitSize,
                                         uint8_t *pu8DataReceive, uint32_t u32DataReceiveSize)
{
    I2C_nERROR enStatus;
    enStatus = I2C_Master_enTransmitGeneric(enModule, I2C_enSTATE_ENA, I2C_enSTATE_DIS, u32SlaveAddressArg, pu8DataTransmit, u32DataTransmitSize);
    if(I2C_enERROR_OK == enStatus)
    {
        enStatus = I2C_Master_enReceiveGeneric(enModule, I2C_enSTATE_DIS, I2C_enSTATE_ENA, u32SlaveAddressArg, pu8DataReceive, u32DataReceiveSize);
    }
    return enStatus;
}

I2C_nERROR I2C_Master_enReceiveTransmit(I2C_nMODULE enModule, uint32_t u32SlaveAddressArg,
                                         const uint8_t *pu8DataTransmit, uint32_t u32DataTransmitSize,
                                         uint8_t *pu8DataReceive, uint32_t u32DataReceiveSize)
{
    I2C_nERROR enStatus;
    enStatus = I2C_Master_enReceiveGeneric(enModule, I2C_enSTATE_ENA, I2C_enSTATE_DIS, u32SlaveAddressArg, pu8DataReceive, u32DataReceiveSize);
    if(I2C_enERROR_OK == enStatus)
    {
        enStatus = I2C_Master_enTransmitGeneric(enModule, I2C_enSTATE_DIS, I2C_enSTATE_ENA, u32SlaveAddressArg, pu8DataTransmit, u32DataTransmitSize);
    }
    return enStatus;
}


