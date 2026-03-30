/**
 *
 * @file SYSTICK_CalibrationDriverMock.cpp
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
 * @verbatim 29 mar. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 29 mar. 2026   GitHub Copilot   1.0         initial Version@endverbatim
 */

#include <tm4c129e_test/SYSTICK_CalibrationDriverMock.h>

namespace
{
SYSTICK_CalibrationDriverMock* g_pstSYSTICKCalibrationDriverMock = nullptr;
}

void TM4C129E_DriverLib_Test__vSetSYSTICKCalibrationDriverMock(SYSTICK_CalibrationDriverMock* pstMockArg)
{
    g_pstSYSTICKCalibrationDriverMock = pstMockArg;
}

void TM4C129E_DriverLib_Test__vClearSYSTICKCalibrationDriverMock(void)
{
    g_pstSYSTICKCalibrationDriverMock = nullptr;
}

extern "C" SYSTICK_nERROR SYSTICK__enGetCalibrationValue(SYSTICK_nMODULE enModuleArg, UBase_t* puxValueArg)
{
    if(nullptr == g_pstSYSTICKCalibrationDriverMock)
    {
        return SYSTICK_enERROR_UNDEF;
    }

    return g_pstSYSTICKCalibrationDriverMock->GetCalibrationValue(enModuleArg, puxValueArg);
}

extern "C" SYSTICK_nERROR SYSTICK__enGetCalibrationSkew(SYSTICK_nMODULE enModuleArg, SYSTICK_nSKEW* penValueArg)
{
    if(nullptr == g_pstSYSTICKCalibrationDriverMock)
    {
        return SYSTICK_enERROR_UNDEF;
    }

    return g_pstSYSTICKCalibrationDriverMock->GetCalibrationSkew(enModuleArg, penValueArg);
}

extern "C" SYSTICK_nERROR SYSTICK__enGetCalibrationReference(SYSTICK_nMODULE enModuleArg, SYSTICK_nREFERENCE* penValueArg)
{
    if(nullptr == g_pstSYSTICKCalibrationDriverMock)
    {
        return SYSTICK_enERROR_UNDEF;
    }

    return g_pstSYSTICKCalibrationDriverMock->GetCalibrationReference(enModuleArg, penValueArg);
}