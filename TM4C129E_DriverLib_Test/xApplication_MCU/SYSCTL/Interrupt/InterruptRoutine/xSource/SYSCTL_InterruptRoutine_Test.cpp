/**
 *
 * @file SYSCTL_InterruptRoutine_Test.cpp
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
#include <xApplication_MCU/SYSCTL/Interrupt/InterruptRoutine/SYSCTL_InterruptRoutine.h>
}

#include <gtest/gtest.h>

namespace
{
void TM4C129E_DriverLib_Test__vCustomSYSCTLIRQVectorHandler(void)
{
}

class SYSCTL_InterruptRoutineTest : public ::testing::Test
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
 * @brief Validate the current SYSCTL IRQ vector-handler getter.
 * @summary Confirms that `SYSCTL__pvfGetIRQVectorHandler` returns the currently
 *          installed SYSCTL IRQ vector handler and defaults to the production
 *          SYSCTL vector routine.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original sources under test: SYSCTL_InterruptRoutine.c and
 *   SYSCTL_InterruptRoutine_Vector.c
 * - Existing SYSCTL interrupt routine host seam for vector-source linkage@endverbatim
 */
TEST_F(SYSCTL_InterruptRoutineTest, IRQVectorHandlerGetterReturnsInstalledHandler)
{
    EXPECT_EQ(&SYSCTL__vIRQVectorHandler, SYSCTL__pvfGetIRQVectorHandler());
}

/**
 * @brief Validate direct access to the installed SYSCTL IRQ vector-handler storage.
 * @summary Confirms that `SYSCTL__pvfGetIRQVectorHandlerPointer` exposes the
 *          writable handler storage used by the SYSCTL registration layer and
 *          that updating the pointed value changes the getter result.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original sources under test: SYSCTL_InterruptRoutine.c and
 *   SYSCTL_InterruptRoutine_Vector.c
 * - Existing SYSCTL interrupt routine host seam for vector-source linkage@endverbatim
 */
TEST_F(SYSCTL_InterruptRoutineTest, IRQVectorHandlerPointerExposesWritableInstalledHandlerStorage)
{
    void (**pvfInstalledHandlerPointerReg)(void);

    pvfInstalledHandlerPointerReg = SYSCTL__pvfGetIRQVectorHandlerPointer();

    ASSERT_NE(nullptr, pvfInstalledHandlerPointerReg);
    EXPECT_EQ(&SYSCTL__vIRQVectorHandler, *pvfInstalledHandlerPointerReg);

    *pvfInstalledHandlerPointerReg = &TM4C129E_DriverLib_Test__vCustomSYSCTLIRQVectorHandler;

    EXPECT_EQ(&TM4C129E_DriverLib_Test__vCustomSYSCTLIRQVectorHandler,
              SYSCTL__pvfGetIRQVectorHandler());
    EXPECT_EQ(&TM4C129E_DriverLib_Test__vCustomSYSCTLIRQVectorHandler,
              *SYSCTL__pvfGetIRQVectorHandlerPointer());
}