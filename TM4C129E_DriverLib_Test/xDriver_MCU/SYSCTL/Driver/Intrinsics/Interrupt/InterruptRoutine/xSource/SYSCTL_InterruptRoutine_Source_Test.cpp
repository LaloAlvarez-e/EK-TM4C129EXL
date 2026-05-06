/**
 *
 * @file SYSCTL_InterruptRoutine_Source_Test.cpp
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

extern "C"
{
#include <xDriver_MCU/Common/xHeader/MCU_Variables.h>
#include <xDriver_MCU/SYSCTL/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/SYSCTL_InterruptRoutine_Source.h>

void MCU_vIRQSourceHandler_Dummy(uintptr_t uptrModuleArg, void* pvArgument)
{
    (void) uptrModuleArg;
    (void) pvArgument;
}

void TM4C129E_DriverLib_Test__vCustomSYSCTLIRQSourceHandler(uintptr_t uptrModuleArg, void* pvArgument)
{
    (void) uptrModuleArg;
    (void) pvArgument;
}
}

#include <gtest/gtest.h>

namespace
{
class SYSCTL_InterruptRoutineSourceTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        vResetHandlerTable();
    }

    void TearDown() override
    {
        vResetHandlerTable();
    }

    void vResetHandlerTable()
    {
        for(UBase_t uxInterruptSource = 0UL; uxInterruptSource < (UBase_t) SYSCTL_enINT_MAX; ++uxInterruptSource)
        {
            SYSCTL_pvfIRQSourceHandler_t* pvfHandlerReg;

            pvfHandlerReg = SYSCTL__pvfGetIRQSourceHandlerPointer(SYSCTL_enMODULE_0,
                                                                  (SYSCTL_nINT) uxInterruptSource);
            ASSERT_NE(nullptr, pvfHandlerReg);
            *pvfHandlerReg = &MCU_vIRQSourceHandler_Dummy;
        }
    }
};
}

/**
 * @brief Validate default SYSCTL source-handler table initialization.
 * @summary Confirms that every architected SYSCTL interrupt source initially
 *          resolves through the shared dummy handler stored by
 *          `SYSCTL_InterruptRoutine_Source.c`.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_InterruptRoutine_Source.c
 * - Local non-blocking dummy symbol for MCU_vIRQSourceHandler_Dummy@endverbatim
 */
TEST_F(SYSCTL_InterruptRoutineSourceTest, AllInterruptSourcesDefaultToDummyHandler)
{
    for(UBase_t uxInterruptSource = 0UL; uxInterruptSource < (UBase_t) SYSCTL_enINT_MAX; ++uxInterruptSource)
    {
        EXPECT_EQ(&MCU_vIRQSourceHandler_Dummy,
                  SYSCTL__pvfGetIRQSourceHandler(SYSCTL_enMODULE_0,
                                                (SYSCTL_nINT) uxInterruptSource));
    }
}

/**
 * @brief Validate invalid SYSCTL getter selections return a null handler.
 * @summary Confirms that `SYSCTL__pvfGetIRQSourceHandler` rejects module and
 *          interrupt-source selectors outside the documented public maxima and
 *          reports those invalid selections through a null handler result.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_InterruptRoutine_Source.c
 * - Local non-blocking dummy symbol for MCU_vIRQSourceHandler_Dummy@endverbatim
 */
TEST_F(SYSCTL_InterruptRoutineSourceTest, InterruptSourceGetterRejectsInvalidSelections)
{
    EXPECT_EQ(nullptr,
              SYSCTL__pvfGetIRQSourceHandler((SYSCTL_nMODULE) SYSCTL_enMODULE_MAX,
                                            SYSCTL_enINT_PLL_LOCK));
    EXPECT_EQ(nullptr,
              SYSCTL__pvfGetIRQSourceHandler(SYSCTL_enMODULE_0,
                                            (SYSCTL_nINT) SYSCTL_enINT_MAX));
}

/**
 * @brief Validate invalid SYSCTL pointer-helper selections return a null slot.
 * @summary Confirms that `SYSCTL__pvfGetIRQSourceHandlerPointer` rejects module
 *          and interrupt-source selectors outside the documented public maxima
 *          and reports those invalid selections through a null storage pointer.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_InterruptRoutine_Source.c
 * - Local non-blocking dummy symbol for MCU_vIRQSourceHandler_Dummy@endverbatim
 */
TEST_F(SYSCTL_InterruptRoutineSourceTest, InterruptSourceHandlerPointerRejectsInvalidSelections)
{
    EXPECT_EQ(nullptr,
              SYSCTL__pvfGetIRQSourceHandlerPointer((SYSCTL_nMODULE) SYSCTL_enMODULE_MAX,
                                                   SYSCTL_enINT_PLL_LOCK));
    EXPECT_EQ(nullptr,
              SYSCTL__pvfGetIRQSourceHandlerPointer(SYSCTL_enMODULE_0,
                                                   (SYSCTL_nINT) SYSCTL_enINT_MAX));
}

/**
 * @brief Validate writable access to one SYSCTL source-handler slot.
 * @summary Confirms that `SYSCTL__pvfGetIRQSourceHandlerPointer` exposes the
 *          backing storage for a selected SYSCTL source, that writing through
 *          the returned pointer updates the getter view, and that unrelated
 *          source slots remain unchanged.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_InterruptRoutine_Source.c
 * - Local non-blocking dummy symbol for MCU_vIRQSourceHandler_Dummy@endverbatim
 */
TEST_F(SYSCTL_InterruptRoutineSourceTest, InterruptSourceHandlerPointerExposesWritableSourceSlot)
{
    SYSCTL_pvfIRQSourceHandler_t* pvfHandlerReg;

    pvfHandlerReg = SYSCTL__pvfGetIRQSourceHandlerPointer(SYSCTL_enMODULE_0,
                                                          SYSCTL_enINT_PLL_LOCK);

    ASSERT_NE(nullptr, pvfHandlerReg);
    EXPECT_EQ(&MCU_vIRQSourceHandler_Dummy, *pvfHandlerReg);

    *pvfHandlerReg = &TM4C129E_DriverLib_Test__vCustomSYSCTLIRQSourceHandler;

    EXPECT_EQ(&TM4C129E_DriverLib_Test__vCustomSYSCTLIRQSourceHandler,
              *pvfHandlerReg);
    EXPECT_EQ(&TM4C129E_DriverLib_Test__vCustomSYSCTLIRQSourceHandler,
              SYSCTL__pvfGetIRQSourceHandler(SYSCTL_enMODULE_0,
                                            SYSCTL_enINT_PLL_LOCK));
    EXPECT_EQ(&MCU_vIRQSourceHandler_Dummy,
              SYSCTL__pvfGetIRQSourceHandler(SYSCTL_enMODULE_0,
                                            SYSCTL_enINT_SW));
}