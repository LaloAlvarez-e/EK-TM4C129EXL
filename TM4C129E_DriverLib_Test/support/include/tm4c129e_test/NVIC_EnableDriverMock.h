/**
 *
 * @file NVIC_EnableDriverMock.h
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

#ifndef B01BAABA_038F_43A4_BD88_B939B76BF17C
#define B01BAABA_038F_43A4_BD88_B939B76BF17C

#ifndef TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_NVIC_ENABLEDRIVERMOCK_H_
#define TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_NVIC_ENABLEDRIVERMOCK_H_

extern "C"
{
#include <xDriver_MCU/Core/NVIC/Driver/xHeader/NVIC_ReadReg.h>
#include <xDriver_MCU/Core/NVIC/Driver/xHeader/NVIC_WriteReg.h>
#include <xDriver_MCU/Core/NVIC/Driver/xHeader/NVIC_Priority.h>
}

#include <gmock/gmock.h>

class NVIC_EnableDriverMock
{
public:
    MOCK_METHOD(NVIC_nERROR, ReadValue, (NVIC_nMODULE enModuleArg, NVIC_nVECTOR enVectorArg, uintptr_t uptrRegisterOffsetArg, UBase_t* puxValueArg));
    MOCK_METHOD(NVIC_nERROR, SetWriteValue, (NVIC_nMODULE enModuleArg, NVIC_nVECTOR enVectorArg, uintptr_t uptrRegisterOffsetArg, UBase_t uxValueArg));
    MOCK_METHOD(NVIC_nERROR, SetVectorPriority, (NVIC_nMODULE enModuleArg, NVIC_nVECTOR enVectorArg, NVIC_nPRIORITY enPriorityArg));
};

void TM4C129E_DriverLib_Test__vSetNVICEnableDriverMock(NVIC_EnableDriverMock* pstMockArg);
void TM4C129E_DriverLib_Test__vClearNVICEnableDriverMock(void);

class NVIC_EnableDriverMockScope
{
public:
    explicit NVIC_EnableDriverMockScope(NVIC_EnableDriverMock* pstMockArg)
    {
        TM4C129E_DriverLib_Test__vSetNVICEnableDriverMock(pstMockArg);
    }

    ~NVIC_EnableDriverMockScope()
    {
        TM4C129E_DriverLib_Test__vClearNVICEnableDriverMock();
    }
};

#endif /* TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_TM4C129E_TEST_NVIC_ENABLEDRIVERMOCK_H_ */


#endif /* B01BAABA_038F_43A4_BD88_B939B76BF17C */
