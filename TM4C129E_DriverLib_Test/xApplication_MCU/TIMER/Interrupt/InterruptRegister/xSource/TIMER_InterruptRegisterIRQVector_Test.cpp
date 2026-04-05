/**
 *
 * @file TIMER_InterruptRegisterIRQVector_Test.cpp
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
 * @verbatim 4 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 4 abr. 2026    GitHub Copilot   1.0         initial Version@endverbatim
 */

extern "C"
{
#include <xApplication_MCU/TIMER/Interrupt/InterruptRegister/xHeader/TIMER_InterruptRegisterIRQVector.h>
}

#include <tm4c129e_test/TIMER_InterruptRegisterMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::_;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::SetArgPointee;
using ::testing::StrictMock;

namespace
{
void TM4C129E_DriverLib_Test__vCustomTIMERIRQVectorHandler(void)
{
}
}

/**
 * @brief Validate SCB delegation for mapped TIMER IRQ vector registration.
 * @summary Confirms that `TIMER__enRegisterIRQVectorHandler` resolves the
 *          caller module into the expected TIMER fixed-vector selector,
 *          obtains the installed-handler storage pointer for that TIMER slot,
 *          and forwards the registration request through the SCB wrapper.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - TIMER_InterruptRegisterMock bridge
 * - Original source under test: TIMER_InterruptRegisterIRQVector.c@endverbatim
 */
TEST(TIMER_InterruptRegisterIRQVectorTest, RegisterIRQVectorHandlerDelegatesMappedTimerVectorToSCB)
{
    StrictMock<TIMER_InterruptRegisterMock> stMock;
    TIMER_InterruptRegisterMockScope stMockScope(&stMock);
    TIMER_TestIRQVectorHandler_t pfInstalledHandlerReg = (TIMER_TestIRQVectorHandler_t) 0UL;
    const TIMER_TestIRQVectorHandler_t pfIrqVectorHandlerReg = &TM4C129E_DriverLib_Test__vCustomTIMERIRQVectorHandler;

    EXPECT_CALL(stMock, GetSubParams(TIMER_enT3B, _, _))
        .WillOnce(DoAll(SetArgPointee<1>((UBase_t) TIMER_enSUBMODULE_B),
                        SetArgPointee<2>((UBase_t) TIMER_enMODULE_NUM_3)));
    EXPECT_CALL(stMock, GetIRQVectorHandlerPointer(TIMER_enSUBMODULE_B, TIMER_enMODULE_NUM_3))
        .WillOnce(Return(&pfInstalledHandlerReg));
    EXPECT_CALL(stMock,
                RegisterIRQVectorHandler(SCB_enMODULE_0,
                                         SCB_enVECISR_TIMER3B,
                                         pfIrqVectorHandlerReg,
                                         &pfInstalledHandlerReg))
        .WillOnce(Return(SCB_enERROR_OK));

    EXPECT_EQ(TIMER_enERROR_OK,
              TIMER__enRegisterIRQVectorHandler(pfIrqVectorHandlerReg, TIMER_enT3B));
}

/**
 * @brief Validate SCB error propagation in the TIMER IRQ registration wrapper.
 * @summary Confirms that `TIMER__enRegisterIRQVectorHandler` propagates the
 *          underlying SCB registration status for the selected mapped TIMER
 *          vector instead of silently returning success.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - TIMER_InterruptRegisterMock bridge
 * - Original source under test: TIMER_InterruptRegisterIRQVector.c@endverbatim
 */
TEST(TIMER_InterruptRegisterIRQVectorTest, RegisterIRQVectorHandlerPropagatesSCBError)
{
    StrictMock<TIMER_InterruptRegisterMock> stMock;
    TIMER_InterruptRegisterMockScope stMockScope(&stMock);
    TIMER_TestIRQVectorHandler_t pfInstalledHandlerReg = (TIMER_TestIRQVectorHandler_t) 0UL;
    const TIMER_TestIRQVectorHandler_t pfIrqVectorHandlerReg = &TM4C129E_DriverLib_Test__vCustomTIMERIRQVectorHandler;

    EXPECT_CALL(stMock, GetSubParams(TIMER_enT6A, _, _))
        .WillOnce(DoAll(SetArgPointee<1>((UBase_t) TIMER_enSUBMODULE_A),
                        SetArgPointee<2>((UBase_t) TIMER_enMODULE_NUM_6)));
    EXPECT_CALL(stMock, GetIRQVectorHandlerPointer(TIMER_enSUBMODULE_A, TIMER_enMODULE_NUM_6))
        .WillOnce(Return(&pfInstalledHandlerReg));
    EXPECT_CALL(stMock,
                RegisterIRQVectorHandler(SCB_enMODULE_0,
                                         SCB_enVECISR_TIMER6A,
                                         pfIrqVectorHandlerReg,
                                         &pfInstalledHandlerReg))
        .WillOnce(Return(SCB_enERROR_RANGE));

    EXPECT_EQ(TIMER_enERROR_RANGE,
              TIMER__enRegisterIRQVectorHandler(pfIrqVectorHandlerReg, TIMER_enT6A));
}

/**
 * @brief Validate null-handler suppression in the TIMER IRQ registration wrapper.
 * @summary Confirms that `TIMER__enRegisterIRQVectorHandler` skips TIMER module
 *          decoding and SCB registration when the caller supplies a null IRQ
 *          vector handler pointer.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - TIMER_InterruptRegisterMock bridge
 * - Original source under test: TIMER_InterruptRegisterIRQVector.c@endverbatim
 */
TEST(TIMER_InterruptRegisterIRQVectorTest, RegisterIRQVectorHandlerSkipsNullHandler)
{
    StrictMock<TIMER_InterruptRegisterMock> stMock;
    TIMER_InterruptRegisterMockScope stMockScope(&stMock);

    EXPECT_EQ(TIMER_enERROR_OK,
              TIMER__enRegisterIRQVectorHandler((TIMER_TestIRQVectorHandler_t) 0UL,
                                                TIMER_enT2B));
}