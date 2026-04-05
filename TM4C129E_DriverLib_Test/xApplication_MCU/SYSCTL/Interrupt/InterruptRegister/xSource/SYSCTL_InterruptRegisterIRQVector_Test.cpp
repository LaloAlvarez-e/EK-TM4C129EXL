/**
 *
 * @file SYSCTL_InterruptRegisterIRQVector_Test.cpp
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
#include <xApplication_MCU/SYSCTL/Interrupt/InterruptRegister/xHeader/SYSCTL_InterruptRegisterIRQVector.h>
#include <xApplication_MCU/SYSCTL/Interrupt/InterruptRoutine/SYSCTL_InterruptRoutine.h>
}

#include <tm4c129e_test/SYSCTL_InterruptRegisterMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Return;
using ::testing::StrictMock;

namespace
{
void TM4C129E_DriverLib_Test__vCustomRegisteredSYSCTLIRQVectorHandler(void)
{
}

class SYSCTL_InterruptRegisterIRQVectorTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        void (**pvfInstalledHandlerPointerReg)(void);

        pvfInstalledHandlerPointerReg = SYSCTL__pvfGetIRQVectorHandlerPointer();
        ASSERT_NE(nullptr, pvfInstalledHandlerPointerReg);
        *pvfInstalledHandlerPointerReg = &SYSCTL__vIRQVectorHandler;
    }

    void TearDown() override
    {
        void (**pvfInstalledHandlerPointerReg)(void);

        pvfInstalledHandlerPointerReg = SYSCTL__pvfGetIRQVectorHandlerPointer();
        ASSERT_NE(nullptr, pvfInstalledHandlerPointerReg);
        *pvfInstalledHandlerPointerReg = &SYSCTL__vIRQVectorHandler;
    }
};
}

/**
 * @brief Validate SCB delegation for SYSCTL IRQ vector registration.
 * @summary Confirms that `SYSCTL__enRegisterIRQVectorHandler` forwards a non-null
 *          handler through `SCB__enRegisterIRQVectorHandler` using the fixed
 *          SYSCTL vector selector and the writable SYSCTL installed-handler
 *          storage pointer.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_InterruptRegisterMock bridge
 * - Original sources under test: SYSCTL_InterruptRegisterIRQVector.c,
 *   SYSCTL_InterruptRoutine.c, and SYSCTL_InterruptRoutine_Vector.c@endverbatim
 */
TEST_F(SYSCTL_InterruptRegisterIRQVectorTest, RegisterIRQVectorHandlerDelegatesFixedSYSCTLVectorToSCB)
{
    StrictMock<SYSCTL_InterruptRegisterMock> stMock;
    SYSCTL_InterruptRegisterMockScope stMockScope(&stMock);
    SCB_pvfIRQVectorHandler_t* pvfInstalledHandlerPointerReg;
    const SCB_pvfIRQVectorHandler_t pfIrqVectorHandlerReg = &TM4C129E_DriverLib_Test__vCustomRegisteredSYSCTLIRQVectorHandler;

    pvfInstalledHandlerPointerReg = SYSCTL__pvfGetIRQVectorHandlerPointer();

    ASSERT_NE(nullptr, pvfInstalledHandlerPointerReg);

    EXPECT_CALL(stMock,
                RegisterIRQVectorHandler(SCB_enMODULE_0,
                                         SCB_enVECISR_SYSCTL,
                                         pfIrqVectorHandlerReg,
                                         pvfInstalledHandlerPointerReg))
        .WillOnce(Return(SCB_enERROR_OK));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enRegisterIRQVectorHandler(pfIrqVectorHandlerReg));
}

/**
 * @brief Validate SCB error propagation in the SYSCTL IRQ registration wrapper.
 * @summary Confirms that `SYSCTL__enRegisterIRQVectorHandler` propagates the
 *          underlying SCB registration status for the fixed SYSCTL vector.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_InterruptRegisterMock bridge
 * - Original sources under test: SYSCTL_InterruptRegisterIRQVector.c,
 *   SYSCTL_InterruptRoutine.c, and SYSCTL_InterruptRoutine_Vector.c@endverbatim
 */
TEST_F(SYSCTL_InterruptRegisterIRQVectorTest, RegisterIRQVectorHandlerPropagatesSCBError)
{
    StrictMock<SYSCTL_InterruptRegisterMock> stMock;
    SYSCTL_InterruptRegisterMockScope stMockScope(&stMock);
    SCB_pvfIRQVectorHandler_t* pvfInstalledHandlerPointerReg;
    const SCB_pvfIRQVectorHandler_t pfIrqVectorHandlerReg = &TM4C129E_DriverLib_Test__vCustomRegisteredSYSCTLIRQVectorHandler;

    pvfInstalledHandlerPointerReg = SYSCTL__pvfGetIRQVectorHandlerPointer();

    ASSERT_NE(nullptr, pvfInstalledHandlerPointerReg);

    EXPECT_CALL(stMock,
                RegisterIRQVectorHandler(SCB_enMODULE_0,
                                         SCB_enVECISR_SYSCTL,
                                         pfIrqVectorHandlerReg,
                                         pvfInstalledHandlerPointerReg))
        .WillOnce(Return(SCB_enERROR_RANGE));

    EXPECT_EQ(SYSCTL_enERROR_RANGE,
              SYSCTL__enRegisterIRQVectorHandler(pfIrqVectorHandlerReg));
}

/**
 * @brief Validate null-handler suppression in the SYSCTL IRQ registration wrapper.
 * @summary Confirms that `SYSCTL__enRegisterIRQVectorHandler` does not delegate to
 *          SCB when the caller supplies a null handler pointer and leaves the
 *          installed SYSCTL vector-handler storage unchanged.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_InterruptRegisterMock bridge
 * - Original sources under test: SYSCTL_InterruptRegisterIRQVector.c,
 *   SYSCTL_InterruptRoutine.c, and SYSCTL_InterruptRoutine_Vector.c@endverbatim
 */
TEST_F(SYSCTL_InterruptRegisterIRQVectorTest, RegisterIRQVectorHandlerSkipsNullHandler)
{
    StrictMock<SYSCTL_InterruptRegisterMock> stMock;
    SYSCTL_InterruptRegisterMockScope stMockScope(&stMock);

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enRegisterIRQVectorHandler((SYSCTL_pvfIRQVectorHandler_t) 0UL));

    EXPECT_EQ(&SYSCTL__vIRQVectorHandler, SYSCTL__pvfGetIRQVectorHandler());
}