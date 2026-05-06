/**
 *
 * @file HIB_InterruptRoutine_Source_Test.cpp
 * @copyright
 * @verbatim InDeviceMex 2026 @endverbatim
 */

extern "C"
{
#include <xDriver_MCU/Common/xHeader/MCU_Variables.h>
#include <xDriver_MCU/HIB/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/HIB_InterruptRoutine_Source.h>

void MCU_vIRQSourceHandler_Dummy(uintptr_t uptrModuleArg, void* pvArgument)
{
    (void) uptrModuleArg;
    (void) pvArgument;
}

void MCU_vIRQSourceHandler_DummyNonBlocking(uintptr_t uptrModuleArg, void* pvArgument)
{
    (void) uptrModuleArg;
    (void) pvArgument;
}

void TM4C129E_DriverLib_Test__vCustomHIBIRQSourceHandler(uintptr_t uptrModuleArg, void* pvArgument)
{
    (void) uptrModuleArg;
    (void) pvArgument;
}
}

#include <gtest/gtest.h>

namespace
{
class HIB_InterruptRoutineSourceTest : public ::testing::Test
{
protected:
    static HIB_pvfIRQSourceHandler_t pvfExpectedDefault(UBase_t uxModule, UBase_t uxInterruptSource)
    {
        (void) uxModule;
        (void) uxInterruptSource;
        return &MCU_vIRQSourceHandler_Dummy;
    }

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
        for(UBase_t uxModule = 0UL; uxModule < (UBase_t) HIB_enMODULE_MAX; ++uxModule)
        {
            for(UBase_t uxInterruptSource = 0UL; uxInterruptSource < (UBase_t) HIB_enINT_MAX; ++uxInterruptSource)
            {
                HIB_pvfIRQSourceHandler_t* pvfHandlerReg;

                pvfHandlerReg = HIB__pvfGetIRQSourceHandlerPointer((HIB_nMODULE) uxModule,
                                                                  (HIB_nINT) uxInterruptSource);
                ASSERT_NE(nullptr, pvfHandlerReg);
                *pvfHandlerReg = pvfExpectedDefault(uxModule, uxInterruptSource);
            }
        }
    }
};
}

/**
 * @brief Validate HIB routine-source default handlers.
 */
TEST_F(HIB_InterruptRoutineSourceTest, InterruptSourceHandlersExposeExpectedDefaultHandlers)
{
    for(UBase_t uxModule = 0UL; uxModule < (UBase_t) HIB_enMODULE_MAX; ++uxModule)
    {
        for(UBase_t uxInterruptSource = 0UL; uxInterruptSource < (UBase_t) HIB_enINT_MAX; ++uxInterruptSource)
        {
            EXPECT_EQ(pvfExpectedDefault(uxModule, uxInterruptSource),
                      HIB__pvfGetIRQSourceHandler((HIB_nMODULE) uxModule,
                                                 (HIB_nINT) uxInterruptSource));
        }
    }
}

/**
 * @brief Validate HIB getters reject invalid selections.
 */
TEST_F(HIB_InterruptRoutineSourceTest, InterruptSourceGettersRejectInvalidSelections)
{
    EXPECT_EQ((HIB_pvfIRQSourceHandler_t) nullptr,
              HIB__pvfGetIRQSourceHandler((HIB_nMODULE) HIB_enMODULE_MAX,
                                         (HIB_nINT) 0UL));
    EXPECT_EQ((HIB_pvfIRQSourceHandler_t) nullptr,
              HIB__pvfGetIRQSourceHandler((HIB_nMODULE) 0UL,
                                         (HIB_nINT) HIB_enINT_MAX));
}

/**
 * @brief Validate HIB pointer helpers reject invalid selections.
 */
TEST_F(HIB_InterruptRoutineSourceTest, InterruptSourceHandlerPointersRejectInvalidSelections)
{
    EXPECT_EQ(nullptr,
              HIB__pvfGetIRQSourceHandlerPointer((HIB_nMODULE) HIB_enMODULE_MAX,
                                                (HIB_nINT) 0UL));
    EXPECT_EQ(nullptr,
              HIB__pvfGetIRQSourceHandlerPointer((HIB_nMODULE) 0UL,
                                                (HIB_nINT) HIB_enINT_MAX));
}

/**
 * @brief Validate HIB pointer helpers expose writable slots.
 */
TEST_F(HIB_InterruptRoutineSourceTest, InterruptSourceHandlerPointersExposeWritableSlots)
{
    HIB_pvfIRQSourceHandler_t* pvfHandlerReg;

    pvfHandlerReg = HIB__pvfGetIRQSourceHandlerPointer((HIB_nMODULE) 0UL,
                                                       (HIB_nINT) 0UL);

    ASSERT_NE(nullptr, pvfHandlerReg);
    EXPECT_EQ(pvfExpectedDefault(0UL, 0UL), *pvfHandlerReg);

    *pvfHandlerReg = &TM4C129E_DriverLib_Test__vCustomHIBIRQSourceHandler;

    EXPECT_EQ(&TM4C129E_DriverLib_Test__vCustomHIBIRQSourceHandler,
              HIB__pvfGetIRQSourceHandler((HIB_nMODULE) 0UL,
                                         (HIB_nINT) 0UL));
}