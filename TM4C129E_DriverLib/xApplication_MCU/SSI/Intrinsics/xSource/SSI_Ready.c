/**
 *
 * @file SSI_Ready.c
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
 * @verbatim 11 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 11 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/SSI/Intrinsics/xHeader/SSI_Ready.h>

#include <xApplication_MCU/SSI/Intrinsics/xHeader/SSI_Dependencies.h>

#if !defined(Opt_Check)
static SYSCTL_nPERIPHERAL SYSCTL_VECTOR_SSI[(uint32_t) SSI_enMODULE_MAX] =
{SYSCTL_enSSI0, SYSCTL_enSSI1, SYSCTL_enSSI2, SYSCTL_enSSI3};
#endif

void SSI__vSetReady(SSI_nMODULE enModule)
{
#if !defined(Opt_Check)
    SSI_nREADY enReady = SSI_enNOREADY;
    SYSCTL_nPERIPHERAL enPeripheral = SYSCTL_enSSI0;
    uint32_t u32Module = 0UL;

    u32Module = MCU__u32CheckParams((uint32_t) enModule, (uint32_t) SSI_enMODULE_MAX);

    enPeripheral = SYSCTL_VECTOR_SSI[u32Module];
    enReady = SSI__enIsReady((SSI_nMODULE) u32Module);
    if(SSI_enNOREADY == enReady)
    {
        SYSCTL__vSetReady(enPeripheral);
        SYSCTL__vReset(enPeripheral);
        SYSCTL__vSetReady(enPeripheral);
    }
#endif
}

void SSI__vClearReady(SSI_nMODULE enModule)
{
#if defined(Opt_Check)
    SYSCTL_nPERIPHERAL SYSCTL_VECTOR_SSI[(uint32_t) SSI_enMODULE_MAX] =
    {SYSCTL_enSSI0, SYSCTL_enSSI1, SYSCTL_enSSI2, SYSCTL_enSSI3};
#endif
    SYSCTL_nPERIPHERAL enPeripheral = SYSCTL_enSSI0;
    uint32_t u32Module = 0UL;
    u32Module = MCU__u32CheckParams((uint32_t) enModule, (uint32_t) SSI_enMODULE_MAX);
    enPeripheral = SYSCTL_VECTOR_SSI[u32Module];
    SYSCTL__vClearReady(enPeripheral);
}

SSI_nREADY SSI__enIsReady(SSI_nMODULE enModule)
{
#if !defined(Opt_Check)
    SSI_nREADY enReady = SSI_enNOREADY;
    SYSCTL_nPERIPHERAL enPeripheral = SYSCTL_enSSI0;
    uint32_t u32Module =0UL;
    u32Module = MCU__u32CheckParams((uint32_t) enModule, (uint32_t) SSI_enMODULE_MAX);
    enPeripheral = SYSCTL_VECTOR_SSI[u32Module];
    enReady = (SSI_nREADY) SYSCTL__enIsReady(enPeripheral);
#else
    SSI_nREADY enReady = SSI_enREADY;
#endif
    return (enReady);
}
