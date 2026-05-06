/**
 *
 * @file I2C_Slave_InterruptRoutine_Source.c
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
#include <xDriver_MCU/I2C/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/I2C_Slave_InterruptRoutine_Source.h>

static I2C_pvfIRQSourceHandler_t I2C_Slave_vIRQSourceHandler[(UBase_t) I2C_enMODULE_MAX][(UBase_t) I2C_enSLAVE_INT_MAX] =
{
 {
      &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
      &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
      &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
      &MCU_vIRQSourceHandler_Dummy
 },
 {
      &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
      &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
      &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
      &MCU_vIRQSourceHandler_Dummy
 },
 {
      &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
      &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
      &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
      &MCU_vIRQSourceHandler_Dummy
 },
 {
      &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
      &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
      &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
      &MCU_vIRQSourceHandler_Dummy
 },
 {
      &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
      &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
      &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
      &MCU_vIRQSourceHandler_Dummy
 },
 {
      &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
      &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
      &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
      &MCU_vIRQSourceHandler_Dummy
 },
 {
      &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
      &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
      &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
      &MCU_vIRQSourceHandler_Dummy
 },
 {
      &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
      &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
      &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
      &MCU_vIRQSourceHandler_Dummy
 },
 {
      &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
      &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
      &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
      &MCU_vIRQSourceHandler_Dummy
 },
 {
      &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
      &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
      &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
      &MCU_vIRQSourceHandler_Dummy
 },
};

I2C_pvfIRQSourceHandler_t I2C_Slave__pvfGetIRQSourceHandler(I2C_nMODULE enModuleArg, I2C_nSLAVE_INT enInterruptSourceArg)
{
    I2C_pvfIRQSourceHandler_t pvfFunctionReg;

    pvfFunctionReg = (I2C_pvfIRQSourceHandler_t) 0;
    if((I2C_enMODULE_MAX > enModuleArg) && (I2C_enSLAVE_INT_MAX > enInterruptSourceArg))
    {
        pvfFunctionReg = I2C_Slave_vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t) enInterruptSourceArg];
    }
    return (pvfFunctionReg);
}

I2C_pvfIRQSourceHandler_t* I2C_Slave__pvfGetIRQSourceHandlerPointer(I2C_nMODULE enModuleArg, I2C_nSLAVE_INT enInterruptSourceArg)
{
    I2C_pvfIRQSourceHandler_t* pvfFunctionReg;

    pvfFunctionReg = (I2C_pvfIRQSourceHandler_t*) 0;
    if((I2C_enMODULE_MAX > enModuleArg) && (I2C_enSLAVE_INT_MAX > enInterruptSourceArg))
    {
        pvfFunctionReg = &I2C_Slave_vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t) enInterruptSourceArg];
    }
    return (pvfFunctionReg);
}
