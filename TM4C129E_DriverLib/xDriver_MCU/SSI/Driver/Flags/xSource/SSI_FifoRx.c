/**
 *
 * @file SSI_FifoRx.c
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
 * @verbatim 17 feb. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 17 feb. 2021     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/SSI/Driver/Flags/xHeader/SSI_FifoRx.h>

#include <xDriver_MCU/SSI/Driver/Intrinsics/Primitives/SSI_Primitives.h>
#include <xDriver_MCU/SSI/Peripheral/SSI_Peripheral.h>

SSI_nFIFO_EMPTY SSI__enIsFifoReceiveEmpty(SSI_nMODULE enModule)
{
    uint32_t u32Reg = 0UL;
    u32Reg = SSI__u32ReadRegister(enModule,
          SSI_SR_OFFSET, SSI_SR_RNE_MASK, SSI_SR_R_RNE_BIT);
    u32Reg ^= (uint32_t) 0x1UL;
    return ((SSI_nFIFO_EMPTY) u32Reg);
}

SSI_nFIFO_FULL SSI__enIsFifoReceiveFull(SSI_nMODULE enModule)
{
    SSI_nFIFO_FULL enFifoReg = SSI_enFIFO_NO_FULL;
    enFifoReg = (SSI_nFIFO_FULL) SSI__u32ReadRegister(enModule,
              SSI_SR_OFFSET, SSI_SR_RFF_MASK, SSI_SR_R_RFF_BIT);
    return (enFifoReg);
}
