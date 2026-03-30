/**
 *
 * @file SYSTICK_CalibrationDriverMock.h
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

#ifndef TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSTICK_CALIBRATIONDRIVERMOCK_H_
#define TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSTICK_CALIBRATIONDRIVERMOCK_H_

extern "C"
{
#include <xDriver_MCU/Core/SYSTICK/Driver/xHeader/SYSTICK_Calibration.h>
}

#include <gmock/gmock.h>

class SYSTICK_CalibrationDriverMock
{
public:
    MOCK_METHOD(SYSTICK_nERROR, GetCalibrationValue, (SYSTICK_nMODULE enModuleArg, UBase_t* puxValueArg));
    MOCK_METHOD(SYSTICK_nERROR, GetCalibrationSkew, (SYSTICK_nMODULE enModuleArg, SYSTICK_nSKEW* penValueArg));
    MOCK_METHOD(SYSTICK_nERROR, GetCalibrationReference, (SYSTICK_nMODULE enModuleArg, SYSTICK_nREFERENCE* penValueArg));
};

void TM4C129E_DriverLib_Test__vSetSYSTICKCalibrationDriverMock(SYSTICK_CalibrationDriverMock* pstMockArg);
void TM4C129E_DriverLib_Test__vClearSYSTICKCalibrationDriverMock(void);

class SYSTICK_CalibrationDriverMockScope
{
public:
    explicit SYSTICK_CalibrationDriverMockScope(SYSTICK_CalibrationDriverMock* pstMockArg)
    {
        TM4C129E_DriverLib_Test__vSetSYSTICKCalibrationDriverMock(pstMockArg);
    }

    ~SYSTICK_CalibrationDriverMockScope()
    {
        TM4C129E_DriverLib_Test__vClearSYSTICKCalibrationDriverMock();
    }
};

#endif /* TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_SYSTICK_CALIBRATIONDRIVERMOCK_H_ */
