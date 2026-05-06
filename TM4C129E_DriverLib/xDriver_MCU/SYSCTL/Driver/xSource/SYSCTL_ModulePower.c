/**
 *
 * @file SYSCTL_ModulePower.c
 * @copyright
 * @verbatim InDeviceMex 2026 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 5 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 5 abr. 2026    GitHub Copilot   1.0         initial Version@endverbatim
 */

#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_ModulePower.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/SYSCTL/Driver/Intrinsics/Primitives/SYSCTL_Primitives.h>
#include <xDriver_MCU/SYSCTL/Peripheral/SYSCTL_Peripheral.h>

#define SYSCTL_MODULEPOWER_PWRCTL_MASK    ((UBase_t) 0x00000003UL)
#define SYSCTL_MODULEPOWER_PWRCTL_BIT     (0UL)
#define SYSCTL_MODULEPOWER_PWRSTAT_MASK   ((UBase_t) 0x00000003UL)
#define SYSCTL_MODULEPOWER_PWRSTAT_BIT    (0UL)
#define SYSCTL_MODULEPOWER_MEMSTAT_MASK   ((UBase_t) 0x00000003UL)
#define SYSCTL_MODULEPOWER_MEMSTAT_BIT    (2UL)

typedef struct
{
    UBase_t uxStatusAddress;
    UBase_t uxControlAddress;
    SYSCTL_nBOOLEAN enRetentionSupport;
} SYSCTL_ModulePowerContext_t;

static SYSCTL_nERROR SYSCTL__enGetModulePowerContext(SYSCTL_nPERIPHERAL enPeripheralArg,
                                                     SYSCTL_ModulePowerContext_t* pstContextArg);
static SYSCTL_nERROR SYSCTL__enValidateModuleMemoryPowerControl(SYSCTL_nMODULE_MEMORY_POWER enPowerControlArg,
                                                                SYSCTL_nBOOLEAN enRetentionSupportArg);
static SYSCTL_nERROR SYSCTL__enSetModulePowerField(SYSCTL_nMODULE enModuleArg, UBase_t uxAddressArg,
                                                   UBase_t uxMaskArg, UBase_t uxShiftArg, UBase_t uxValueArg);
static SYSCTL_nERROR SYSCTL__enGetModulePowerField(SYSCTL_nMODULE enModuleArg, UBase_t uxAddressArg,
                                                   UBase_t uxMaskArg, UBase_t uxShiftArg, UBase_t* puxValueArg);

static SYSCTL_nERROR SYSCTL__enGetModulePowerContext(SYSCTL_nPERIPHERAL enPeripheralArg,
                                                     SYSCTL_ModulePowerContext_t* pstContextArg)
{
    SYSCTL_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) pstContextArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        switch(enPeripheralArg)
        {
            case SYSCTL_enUSB:
                pstContextArg->uxStatusAddress = USB_PDS_OFFSET;
                pstContextArg->uxControlAddress = USB_MPC_OFFSET;
                pstContextArg->enRetentionSupport = SYSCTL_enTRUE;
                break;
            case SYSCTL_enEMAC:
                pstContextArg->uxStatusAddress = EMAC_PDS_OFFSET;
                pstContextArg->uxControlAddress = EMAC_MPC_OFFSET;
                pstContextArg->enRetentionSupport = SYSCTL_enFALSE;
                break;
            case SYSCTL_enCAN0:
                pstContextArg->uxStatusAddress = CAN0_PDS_OFFSET;
                pstContextArg->uxControlAddress = CAN0_MPC_OFFSET;
                pstContextArg->enRetentionSupport = SYSCTL_enFALSE;
                break;
            case SYSCTL_enCAN1:
                pstContextArg->uxStatusAddress = CAN1_PDS_OFFSET;
                pstContextArg->uxControlAddress = CAN1_MPC_OFFSET;
                pstContextArg->enRetentionSupport = SYSCTL_enFALSE;
                break;
            default:
                enErrorReg = SYSCTL_enERROR_VALUE;
                break;
        }
    }
    return (enErrorReg);
}

static SYSCTL_nERROR SYSCTL__enValidateModuleMemoryPowerControl(SYSCTL_nMODULE_MEMORY_POWER enPowerControlArg,
                                                                SYSCTL_nBOOLEAN enRetentionSupportArg)
{
    SYSCTL_nERROR enErrorReg;

    enErrorReg = SYSCTL_enERROR_OK;
    switch(enPowerControlArg)
    {
        case SYSCTL_enMODULE_MEMORY_POWER_OFF:
        case SYSCTL_enMODULE_MEMORY_POWER_ON:
            break;
        case SYSCTL_enMODULE_MEMORY_POWER_RETENTION:
            enErrorReg = (SYSCTL_enTRUE == enRetentionSupportArg) ? SYSCTL_enERROR_OK : SYSCTL_enERROR_VALUE;
            break;
        default:
            enErrorReg = SYSCTL_enERROR_VALUE;
            break;
    }
    return (enErrorReg);
}

static SYSCTL_nERROR SYSCTL__enSetModulePowerField(SYSCTL_nMODULE enModuleArg, UBase_t uxAddressArg,
                                                   UBase_t uxMaskArg, UBase_t uxShiftArg, UBase_t uxValueArg)
{
    SYSCTL_Register_t stRegister;

    stRegister.uxShift = uxShiftArg;
    stRegister.uxMask = uxMaskArg;
    stRegister.uptrAddress = uxAddressArg;
    stRegister.uxValue = uxValueArg;

    return (SYSCTL__enWriteRegister(enModuleArg, &stRegister));
}

static SYSCTL_nERROR SYSCTL__enGetModulePowerField(SYSCTL_nMODULE enModuleArg, UBase_t uxAddressArg,
                                                   UBase_t uxMaskArg, UBase_t uxShiftArg, UBase_t* puxValueArg)
{
    SYSCTL_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) puxValueArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        SYSCTL_Register_t stRegister;
        stRegister.uxShift = uxShiftArg;
        stRegister.uxMask = uxMaskArg;
        stRegister.uptrAddress = uxAddressArg;
        enErrorReg = SYSCTL__enReadRegister(enModuleArg, &stRegister);
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            *puxValueArg = stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enSetModuleMemoryPowerControlState(SYSCTL_nMODULE enModuleArg,
                                                         SYSCTL_nPERIPHERAL enPeripheralArg,
                                                         SYSCTL_nMODULE_MEMORY_POWER enPowerControlArg)
{
    SYSCTL_ModulePowerContext_t stContext;
    SYSCTL_nERROR enErrorReg;

    enErrorReg = SYSCTL__enGetModulePowerContext(enPeripheralArg, &stContext);
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enValidateModuleMemoryPowerControl(enPowerControlArg, stContext.enRetentionSupport);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enSetModulePowerField(enModuleArg, stContext.uxControlAddress,
                                                   SYSCTL_MODULEPOWER_PWRCTL_MASK,
                                                   SYSCTL_MODULEPOWER_PWRCTL_BIT,
                                                   (UBase_t) enPowerControlArg);
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enGetModuleMemoryPowerControlState(SYSCTL_nMODULE enModuleArg,
                                                         SYSCTL_nPERIPHERAL enPeripheralArg,
                                                         SYSCTL_nMODULE_MEMORY_POWER* penPowerControlArg)
{
    SYSCTL_ModulePowerContext_t stContext;
    UBase_t uxValueReg;
    SYSCTL_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) penPowerControlArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetModulePowerContext(enPeripheralArg, &stContext);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetModulePowerField(enModuleArg, stContext.uxControlAddress,
                                                   SYSCTL_MODULEPOWER_PWRCTL_MASK,
                                                   SYSCTL_MODULEPOWER_PWRCTL_BIT,
                                                   &uxValueReg);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        *penPowerControlArg = (SYSCTL_nMODULE_MEMORY_POWER) uxValueReg;
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enPowerOnModuleMemory(SYSCTL_nMODULE enModuleArg,
                                            SYSCTL_nPERIPHERAL enPeripheralArg)
{
    return SYSCTL__enSetModuleMemoryPowerControlState(enModuleArg, enPeripheralArg,
                                                      SYSCTL_enMODULE_MEMORY_POWER_ON);
}

SYSCTL_nERROR SYSCTL__enPowerOffModuleMemory(SYSCTL_nMODULE enModuleArg,
                                             SYSCTL_nPERIPHERAL enPeripheralArg)
{
    return SYSCTL__enSetModuleMemoryPowerControlState(enModuleArg, enPeripheralArg,
                                                      SYSCTL_enMODULE_MEMORY_POWER_OFF);
}

SYSCTL_nERROR SYSCTL__enRetainModuleMemory(SYSCTL_nMODULE enModuleArg,
                                           SYSCTL_nPERIPHERAL enPeripheralArg)
{
    return SYSCTL__enSetModuleMemoryPowerControlState(enModuleArg, enPeripheralArg,
                                                      SYSCTL_enMODULE_MEMORY_POWER_RETENTION);
}

SYSCTL_nERROR SYSCTL__enGetModulePowerState(SYSCTL_nMODULE enModuleArg,
                                            SYSCTL_nPERIPHERAL enPeripheralArg,
                                            SYSCTL_nMODULE_POWER_STATUS* penPowerStateArg)
{
    SYSCTL_ModulePowerContext_t stContext;
    UBase_t uxValueReg;
    SYSCTL_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) penPowerStateArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetModulePowerContext(enPeripheralArg, &stContext);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetModulePowerField(enModuleArg, stContext.uxStatusAddress,
                                                   SYSCTL_MODULEPOWER_PWRSTAT_MASK,
                                                   SYSCTL_MODULEPOWER_PWRSTAT_BIT,
                                                   &uxValueReg);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        *penPowerStateArg = (SYSCTL_nMODULE_POWER_STATUS) uxValueReg;
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enGetModuleMemoryState(SYSCTL_nMODULE enModuleArg,
                                             SYSCTL_nPERIPHERAL enPeripheralArg,
                                             SYSCTL_nMODULE_MEMORY_POWER* penMemoryStateArg)
{
    SYSCTL_ModulePowerContext_t stContext;
    UBase_t uxValueReg;
    SYSCTL_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) penMemoryStateArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetModulePowerContext(enPeripheralArg, &stContext);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enGetModulePowerField(enModuleArg, stContext.uxStatusAddress,
                                                   SYSCTL_MODULEPOWER_MEMSTAT_MASK,
                                                   SYSCTL_MODULEPOWER_MEMSTAT_BIT,
                                                   &uxValueReg);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        *penMemoryStateArg = (SYSCTL_nMODULE_MEMORY_POWER) uxValueReg;
    }
    return (enErrorReg);
}
