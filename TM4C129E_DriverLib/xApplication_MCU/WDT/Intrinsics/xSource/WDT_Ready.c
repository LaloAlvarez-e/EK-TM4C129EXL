/**
 *
 * @file WDT_Ready.c
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
 * @verbatim 26 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 26 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/WDT/Intrinsics/xHeader/WDT_Ready.h>

#include <xApplication_MCU/WDT/Intrinsics/xHeader/WDT_Dependencies.h>

void WDT__vSetReady(WDT_nMODULE enModule)
{
#if !defined(Opt_Check)
    SYSCTL_nPERIPHERAL enPeripheral = SYSCTL_enWDT0;
    uint32_t u32Module = 0UL;
    u32Module = MCU__u32CheckParams((uint32_t) enModule, (uint32_t) WDT_enMODULE_MAX);
    enPeripheral |= u32Module;
    SYSCTL__vSetReady(enPeripheral);
#endif
}

void WDT__vReset(WDT_nMODULE enModule)
{
    SYSCTL_nPERIPHERAL enPeripheral = SYSCTL_enWDT0;
    uint32_t u32Module = 0UL;
    u32Module = MCU__u32CheckParams((uint32_t) enModule, (uint32_t) WDT_enMODULE_MAX);
    enPeripheral |= u32Module;
    SYSCTL__vReset(enPeripheral);
}

void WDT__vClearReady(WDT_nMODULE enModule)
{
    SYSCTL_nPERIPHERAL enPeripheral = SYSCTL_enWDT0;
    uint32_t u32Module = 0UL;
    u32Module = MCU__u32CheckParams((uint32_t) enModule, (uint32_t) WDT_enMODULE_MAX);
    enPeripheral |= u32Module;
    SYSCTL__vClearReady(enPeripheral);
}

WDT_nREADY WDT__enIsReady(WDT_nMODULE enModule)
{
#if !defined(Opt_Check)
    WDT_nREADY enReady = WDT_enNOREADY;
    SYSCTL_nPERIPHERAL enPeripheral = SYSCTL_enWDT0;
    uint32_t u32Module = 0UL;
    u32Module = MCU__u32CheckParams((uint32_t) enModule, (uint32_t) WDT_enMODULE_MAX);
    enPeripheral |= u32Module;
    enReady = (WDT_nREADY) SYSCTL__enIsReady(enPeripheral);
#else
    WDT_nREADY enReady = WDT_enREADY;
#endif
    return (enReady);
}
