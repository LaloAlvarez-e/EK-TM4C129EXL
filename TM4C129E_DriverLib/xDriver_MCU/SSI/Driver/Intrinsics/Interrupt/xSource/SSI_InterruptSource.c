/**
 *
 * @file SSI_InterruptSource.c
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
#include <xDriver_MCU/SSI/Driver/Intrinsics/Interrupt/xHeader/SSI_InterruptSource.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/SSI/Driver/Intrinsics/Primitives/SSI_Primitives.h>
#include <xDriver_MCU/SSI/Peripheral/SSI_Peripheral.h>

void SSI__vEnInterruptSource(SSI_nMODULE enModule, SSI_nINT_SOURCE enSourceInt)
{
    uint32_t u32SourceInt = 0UL;
    u32SourceInt = (uint32_t) enSourceInt;
    u32SourceInt &= (uint32_t) SSI_enINT_SOURCE_ALL;
    SSI__vWriteRegister(enModule , SSI_IM_OFFSET, u32SourceInt, u32SourceInt, 0UL);
}

void SSI__vDisInterruptSource(SSI_nMODULE enModule, SSI_nINT_SOURCE enSourceInt)
{
    uint32_t u32SourceInt = 0UL;
    u32SourceInt = (uint32_t) enSourceInt;
    u32SourceInt &= (uint32_t) SSI_enINT_SOURCE_ALL;
    SSI__vWriteRegister(enModule , SSI_IM_OFFSET, 0UL, u32SourceInt, 0UL);
}

void SSI__vClearInterruptSource(SSI_nMODULE enModule, SSI_nINT_SOURCE enSourceInt)
{
    uint32_t u32SourceInt = 0UL;
    u32SourceInt = (uint32_t) enSourceInt;
    u32SourceInt &= (uint32_t) SSI_enINT_SOURCE_ALL;
    SSI__vWriteRegister(enModule , SSI_ICR_OFFSET, u32SourceInt, 0xFFFFFFFFUL, 0UL);
}

SSI_nINT_SOURCE SSI__enStatusInterruptSource(SSI_nMODULE enModule, SSI_nINT_SOURCE enSourceInt)
{
    SSI_nINT_SOURCE enInterruptReg = SSI_enINT_SOURCE_NONE;
    uint32_t u32SourceInt = 0UL;
    uint32_t u32Register= 0UL;
    u32SourceInt = (uint32_t) enSourceInt;
    u32SourceInt &= (uint32_t) SSI_enINT_SOURCE_ALL;
    u32Register = SSI__u32ReadRegister(enModule , SSI_RIS_OFFSET, (uint32_t) u32SourceInt, 0UL);
    enInterruptReg = (SSI_nINT_SOURCE) u32Register;

    return (enInterruptReg);
}
