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
 * @verbatim 11 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 11 abr. 2026   vyldram    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/HIB/Data/xHeader/HIB_Data.h>

#include <xDriver_MCU/Core/SCB/SCB.h>
#include <xDriver_MCU/HIB/HIB.h>

static HIB_nERROR HIB__enCheckProtectedDataRange(HIB_nDATA enDataArg, UBase_t uxCountArg);
static HIB_nERROR HIB__enCheckProtectedDataAccess(HIB_nDATA enDataArg, UBase_t uxCountArg);

static HIB_nERROR HIB__enCheckProtectedDataRange(HIB_nDATA enDataArg, UBase_t uxCountArg)
{
    HIB_nERROR enErrorReg;
    UBase_t uxLimitReg;

    enErrorReg = (HIB_enDATA_MAX <= (UBase_t) enDataArg) ? HIB_enERROR_RANGE : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        if((UBase_t) HIB_enDATA_8 > (UBase_t) enDataArg)
        {
            enErrorReg = HIB_enERROR_VALUE;
        }
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        uxLimitReg = (UBase_t) enDataArg + uxCountArg;
        if(HIB_enDATA_MAX < uxLimitReg)
        {
            enErrorReg = HIB_enERROR_RANGE;
        }
    }
    return (enErrorReg);
}

static HIB_nERROR HIB__enCheckProtectedDataAccess(HIB_nDATA enDataArg, UBase_t uxCountArg)
{
    HIB_nERROR enErrorReg;
    SCB_nERROR enErrorSCBReg;
    SCB_nSTATE enPrivilegeStateReg;

    enErrorReg = HIB__enCheckProtectedDataRange(enDataArg, uxCountArg);
    if((HIB_enERROR_OK == enErrorReg) && (0UL != uxCountArg))
    {
        enPrivilegeStateReg = SCB_enSTATE_DIS;
        enErrorSCBReg = SCB__enIsPrivilegedExecution(SCB_enMODULE_0, &enPrivilegeStateReg);
        if((SCB_enERROR_OK != enErrorSCBReg) || (SCB_enSTATE_ENA != enPrivilegeStateReg))
        {
            enErrorReg = HIB_enERROR_VALUE;
        }
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enSetProtectedDataByNumber(HIB_nMODULE enModuleArg, HIB_nDATA enDataArg,
                                           UBase_t uxValueArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = HIB__enCheckProtectedDataAccess(enDataArg, 1UL);
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enSetDataByNumber(enModuleArg, enDataArg, uxValueArg);
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enGetProtectedDataByNumber(HIB_nMODULE enModuleArg, HIB_nDATA enDataArg,
                                           UBase_t* puxValueArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = HIB__enCheckProtectedDataAccess(enDataArg, 1UL);
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enGetDataByNumber(enModuleArg, enDataArg, puxValueArg);
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enWriteProtectedDataArray(HIB_nMODULE enModuleArg, HIB_nDATA enDataArg,
                                          const UBase_t* puxValueArg, UBase_t uxCountArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = HIB__enCheckProtectedDataAccess(enDataArg, uxCountArg);
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enWriteDataArray(enModuleArg, enDataArg, puxValueArg, uxCountArg);
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enReadProtectedDataArray(HIB_nMODULE enModuleArg, HIB_nDATA enDataArg,
                                         UBase_t* puxValueArg, UBase_t uxCountArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = HIB__enCheckProtectedDataAccess(enDataArg, uxCountArg);
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enReadDataArray(enModuleArg, enDataArg, puxValueArg, uxCountArg);
    }
    return (enErrorReg);
}
