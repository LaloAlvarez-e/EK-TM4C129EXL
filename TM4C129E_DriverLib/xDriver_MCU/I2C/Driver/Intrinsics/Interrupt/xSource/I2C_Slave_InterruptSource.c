/**
 *
 * @file I2C_Slave_InterruptSource.c
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
 * @verbatim Mar 24, 2021 @endverbatim
 *
 * @author
 * @verbatim indevicemex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * Mar 24, 2021        indevicemex    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/I2C/Driver/Intrinsics/Interrupt/xHeader/I2C_Slave_InterruptSource.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/I2C/Driver/Intrinsics/Primitives/I2C_Primitives.h>
#include <xDriver_MCU/I2C/Peripheral/I2C_Peripheral.h>


void I2C_Slave__vEnInterruptSource(I2C_nMODULE enModule, I2C_nSLAVE_INT_SOURCE enSourceInt)
{
    uint32_t u32SourceInt = 0UL;
    u32SourceInt = (uint32_t) enSourceInt;
    u32SourceInt &= (uint32_t) I2C_enSLAVE_INT_SOURCE_ALL;
    I2C__vWriteRegister(enModule , I2C_SIMR_OFFSET, u32SourceInt, u32SourceInt, 0UL);
}

void I2C_Slave__vDisInterruptSource(I2C_nMODULE enModule, I2C_nSLAVE_INT_SOURCE enSourceInt)
{
    uint32_t u32SourceInt = 0UL;
    u32SourceInt = (uint32_t) enSourceInt;
    u32SourceInt &= (uint32_t) I2C_enSLAVE_INT_SOURCE_ALL;
    I2C__vWriteRegister(enModule , I2C_SIMR_OFFSET, 0UL, u32SourceInt, 0UL);
}

void I2C_Slave__vClearInterruptSource(I2C_nMODULE enModule, I2C_nSLAVE_INT_SOURCE enSourceInt)
{
    uint32_t u32SourceInt = 0UL;
    u32SourceInt = (uint32_t) enSourceInt;
    u32SourceInt &= (uint32_t) I2C_enSLAVE_INT_SOURCE_ALL;
    I2C__vWriteRegister(enModule , I2C_SICR_OFFSET, u32SourceInt, 0xFFFFFFFFUL, 0UL);
}

I2C_nSLAVE_INT_SOURCE I2C_Slave__enStatusInterruptSource(I2C_nMODULE enModule,
                                                   I2C_nSLAVE_INT_SOURCE enSourceInt)
{
    I2C_nSLAVE_INT_SOURCE enInterruptReg = I2C_enSLAVE_INT_SOURCE_NONE;
    uint32_t u32SourceInt = (uint32_t) enSourceInt;
    uint32_t u32Register= 0UL;
    u32SourceInt &= (uint32_t) I2C_enSLAVE_INT_SOURCE_ALL;
    u32Register = I2C__u32ReadRegister(enModule , I2C_SRIS_OFFSET,
                                       (uint32_t) u32SourceInt, 0UL);
    enInterruptReg = (I2C_nSLAVE_INT_SOURCE) u32Register;

    return (enInterruptReg);
}

