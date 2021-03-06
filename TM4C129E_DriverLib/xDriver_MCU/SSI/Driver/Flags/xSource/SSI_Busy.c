/**
 *
 * @file SSI_Busy.c
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
#include <xDriver_MCU/SSI/Driver/Flags/xHeader/SSI_Busy.h>

#include <xDriver_MCU/SSI/Driver/Intrinsics/Primitives/SSI_Primitives.h>
#include <xDriver_MCU/SSI/Peripheral/SSI_Peripheral.h>

SSI_nBUSY SSI__enGetBusyState(SSI_nMODULE enModule)
{
    SSI_nBUSY enBusyReg = SSI_enBUSY_IDLE;
    enBusyReg = (SSI_nBUSY) SSI__u32ReadRegister(enModule,
              SSI_SR_OFFSET, SSI_SR_BSY_MASK, SSI_SR_R_BSY_BIT);
    return (enBusyReg);
}
