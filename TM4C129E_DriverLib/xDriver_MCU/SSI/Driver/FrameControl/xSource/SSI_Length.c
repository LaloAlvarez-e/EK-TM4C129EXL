/**
 *
 * @file SSI_Length.c
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
#include <xDriver_MCU/SSI/Driver/FrameControl/xHeader/SSI_Length.h>

#include <xDriver_MCU/SSI/Driver/Intrinsics/Primitives/SSI_Primitives.h>
#include <xDriver_MCU/SSI/Peripheral/SSI_Peripheral.h>

SSI_nLENGTH SSI__enGetDataLength(SSI_nMODULE enModule)
{
    SSI_nLENGTH enLengthReg = SSI_enLENGTH_4BITS;
    enLengthReg = (SSI_nLENGTH) SSI__u32ReadRegister(enModule, SSI_CR0_OFFSET,
                                 SSI_CR0_DSS_MASK, SSI_CR0_R_DSS_BIT);

    return (enLengthReg);
}

void SSI__vSetDataLength(SSI_nMODULE enModule, SSI_nLENGTH enDataLength)
{
    SSI__vWriteRegister(enModule, SSI_CR0_OFFSET,
            (uint32_t) enDataLength, SSI_CR0_DSS_MASK, SSI_CR0_R_DSS_BIT);
}
