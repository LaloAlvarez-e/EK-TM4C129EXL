/**
 *
 * @file HIB_Data.c
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
 * @verbatim 6 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 6 abr. 2026    vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/HIB/Driver/xHeader/HIB_Data.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/HIB/Driver/Intrinsics/HIB_Intrinsics.h>
#include <xDriver_MCU/HIB/Peripheral/HIB_Peripheral.h>

typedef HIB_nERROR (*HIB_pfnDataOperation_t)(HIB_nMODULE enModuleArg, uintptr_t uptrAddressArg, UBase_t* puxValueArg);

static HIB_nERROR HIB__enWriteDataRegister(HIB_nMODULE enModuleArg, uintptr_t uptrAddressArg,
                                           UBase_t* puxValueArg);
static HIB_nERROR HIB__enReadDataRegister(HIB_nMODULE enModuleArg, uintptr_t uptrAddressArg,
                                          UBase_t* puxValueArg);

static HIB_nERROR HIB__enWriteDataRegister(HIB_nMODULE enModuleArg, uintptr_t uptrAddressArg,
                                           UBase_t* puxValueArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) puxValueArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;

    if(HIB_enERROR_OK == enErrorReg)
    {
        HIB_Register_t stRegister;
        stRegister.uxShift = 0UL;
        stRegister.uxMask = MCU_MASK_BASE;
        stRegister.uptrAddress = uptrAddressArg;
        stRegister.uxValue = *puxValueArg;
        enErrorReg = HIB__enWriteRegister(enModuleArg, &stRegister);
    }

    return (enErrorReg);
}

static HIB_nERROR HIB__enReadDataRegister(HIB_nMODULE enModuleArg, uintptr_t uptrAddressArg,
                                          UBase_t* puxValueArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) puxValueArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        HIB_Register_t stRegister;

        stRegister.uxShift = 0UL;
        stRegister.uxMask = MCU_MASK_BASE;
        stRegister.uptrAddress = uptrAddressArg;
        stRegister.uxValue = 0UL;

        enErrorReg = HIB__enReadRegister(enModuleArg, &stRegister);
        if(HIB_enERROR_OK == enErrorReg)
        {
            *puxValueArg = stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enSetDataByNumber(HIB_nMODULE enModuleArg, HIB_nDATA enDataArg, UBase_t uxValueArg)
{
    HIB_nERROR enErrorReg;
    uintptr_t uptrAddressReg;

    enErrorReg = (HIB_enDATA_MAX <= (UBase_t) enDataArg) ? HIB_enERROR_RANGE : HIB_enERROR_OK;

    if(HIB_enERROR_OK == enErrorReg)
    {
        uptrAddressReg = HIB_DATA0_OFFSET + (((uintptr_t) enDataArg) << 2UL);
        enErrorReg = HIB__enWriteDataRegister(enModuleArg, uptrAddressReg, &uxValueArg);
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enGetDataByNumber(HIB_nMODULE enModuleArg, HIB_nDATA enDataArg, UBase_t* puxValueArg)
{
    HIB_nERROR enErrorReg;
    uintptr_t uptrAddressReg;

    enErrorReg = (0UL == (uintptr_t) puxValueArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;

    if(HIB_enERROR_OK == enErrorReg)
    {
        if (HIB_enDATA_MAX <= (UBase_t) enDataArg)
        {
            enErrorReg = HIB_enERROR_RANGE;
        }
    }

    if(HIB_enERROR_OK == enErrorReg)
    {
        uptrAddressReg = HIB_DATA0_OFFSET + (((uintptr_t) enDataArg) << 2UL);
        enErrorReg = HIB__enReadDataRegister(enModuleArg, uptrAddressReg, puxValueArg);
    }
    return (enErrorReg);
}



HIB_nERROR HIB__enDataArrayOperation(HIB_nMODULE enModuleArg, HIB_pfnDataOperation_t pfnDataOperationArg, HIB_nDATA enDataArg,
                                 const UBase_t* puxValueArg, UBase_t uxCountArg)
{
    HIB_nERROR enErrorReg;
    
    enErrorReg = ((0UL == (uintptr_t) puxValueArg) || (0UL == (uintptr_t) pfnDataOperationArg)) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    
    if(HIB_enERROR_OK == enErrorReg)
    {
        if(0UL == uxCountArg)
        {
            enErrorReg = HIB_enERROR_RANGE;    
        }
    }

    if(HIB_enERROR_OK == enErrorReg)
    {
        UBase_t uxLimitReg = (UBase_t) enDataArg + uxCountArg;
        if(HIB_enDATA_MAX < uxLimitReg)
        {
            enErrorReg = HIB_enERROR_RANGE;
        }
    }

    if(HIB_enERROR_OK == enErrorReg)
    {
        UBase_t uxIndexReg;
        const UBase_t* puxValueArgReg = puxValueArg;
        uintptr_t uptrAddressReg = HIB_DATA0_OFFSET + (((uintptr_t) enDataArg) << 2UL);
        
        for(uxIndexReg = 0UL; (uxIndexReg < uxCountArg) && (HIB_enERROR_OK == enErrorReg); uxIndexReg++)
        {
            enErrorReg = pfnDataOperationArg(enModuleArg, uptrAddressReg, (UBase_t*) puxValueArgReg);
            uptrAddressReg += 4UL;
            puxValueArgReg++;
        }
    }

    return (enErrorReg);
}

HIB_nERROR HIB__enWriteDataArray(HIB_nMODULE enModuleArg, HIB_nDATA enDataArg,
                                 const UBase_t* puxValueArg, UBase_t uxCountArg)
{
    HIB_nERROR enErrorReg;
    enErrorReg = HIB__enDataArrayOperation(enModuleArg, HIB__enWriteDataRegister, enDataArg, puxValueArg, uxCountArg);
    return (enErrorReg);
}

HIB_nERROR HIB__enReadDataArray(HIB_nMODULE enModuleArg, HIB_nDATA enDataArg,
                                UBase_t* puxValueArg, UBase_t uxCountArg)
{
    HIB_nERROR enErrorReg;
    enErrorReg = HIB__enDataArrayOperation(enModuleArg, HIB__enReadDataRegister, enDataArg, puxValueArg, uxCountArg);
    return (enErrorReg);
}
