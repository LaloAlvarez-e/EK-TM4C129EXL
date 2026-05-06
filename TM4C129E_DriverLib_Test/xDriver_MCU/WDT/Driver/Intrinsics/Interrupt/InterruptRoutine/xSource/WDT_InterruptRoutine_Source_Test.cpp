/**
 *
 * @file WDT_InterruptRoutine_Source_Test.cpp
 * @copyright
 * @verbatim InDeviceMex 2026 @endverbatim
 */

extern "C"
{
#include <xDriver_MCU/Common/xHeader/MCU_Variables.h>
#include <xDriver_MCU/WDT/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/WDT_InterruptRoutine_Source.h>

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

void TM4C129E_DriverLib_Test__vCustomWDTIRQSourceHandler(uintptr_t uptrModuleArg, void* pvArgument)
{
    (void) uptrModuleArg;
    (void) pvArgument;
}
}

#include <gtest/gtest.h>

namespace
{
class WDT_InterruptRoutineSourceTest : public ::testing::Test
{
protected:
    static WDT_pvfIRQSourceHandler_t pvfExpectedDefault(UBase_t uxModule, UBase_t uxInterruptSource)
    {
        (void) uxModule;
        if((((UBase_t) WDT_enINT_MAX) - 1UL) == uxInterruptSource)
        {
            return &MCU_vIRQSourceHandler_DummyNonBlocking;
        }
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
        for(UBase_t uxModule = 0UL; uxModule < (UBase_t) WDT_enMODULE_MAX; ++uxModule)
        {
            for(UBase_t uxInterruptSource = 0UL; uxInterruptSource < (UBase_t) WDT_enINT_MAX; ++uxInterruptSource)
            {
                WDT_pvfIRQSourceHandler_t* pvfHandlerReg;

                pvfHandlerReg = WDT__pvfGetIRQSourceHandlerPointer((WDT_nMODULE) uxModule,
                                                                  (WDT_nINT) uxInterruptSource);
                ASSERT_NE(nullptr, pvfHandlerReg);
                *pvfHandlerReg = pvfExpectedDefault(uxModule, uxInterruptSource);
            }
        }
    }
};
}

/**
 * @brief Validate WDT routine-source default handlers.
 */
TEST_F(WDT_InterruptRoutineSourceTest, InterruptSourceHandlersExposeExpectedDefaultHandlers)
{
    for(UBase_t uxModule = 0UL; uxModule < (UBase_t) WDT_enMODULE_MAX; ++uxModule)
    {
        for(UBase_t uxInterruptSource = 0UL; uxInterruptSource < (UBase_t) WDT_enINT_MAX; ++uxInterruptSource)
        {
            EXPECT_EQ(pvfExpectedDefault(uxModule, uxInterruptSource),
                      WDT__pvfGetIRQSourceHandler((WDT_nMODULE) uxModule,
                                                 (WDT_nINT) uxInterruptSource));
        }
    }
}

/**
 * @brief Validate WDT getters reject invalid selections.
 */
TEST_F(WDT_InterruptRoutineSourceTest, InterruptSourceGettersRejectInvalidSelections)
{
    EXPECT_EQ((WDT_pvfIRQSourceHandler_t) nullptr,
              WDT__pvfGetIRQSourceHandler((WDT_nMODULE) WDT_enMODULE_MAX,
                                         (WDT_nINT) 0UL));
    EXPECT_EQ((WDT_pvfIRQSourceHandler_t) nullptr,
              WDT__pvfGetIRQSourceHandler((WDT_nMODULE) 0UL,
                                         (WDT_nINT) WDT_enINT_MAX));
}

/**
 * @brief Validate WDT pointer helpers reject invalid selections.
 */
TEST_F(WDT_InterruptRoutineSourceTest, InterruptSourceHandlerPointersRejectInvalidSelections)
{
    EXPECT_EQ(nullptr,
              WDT__pvfGetIRQSourceHandlerPointer((WDT_nMODULE) WDT_enMODULE_MAX,
                                                (WDT_nINT) 0UL));
    EXPECT_EQ(nullptr,
              WDT__pvfGetIRQSourceHandlerPointer((WDT_nMODULE) 0UL,
                                                (WDT_nINT) WDT_enINT_MAX));
}

/**
 * @brief Validate WDT pointer helpers expose writable slots.
 */
TEST_F(WDT_InterruptRoutineSourceTest, InterruptSourceHandlerPointersExposeWritableSlots)
{
    WDT_pvfIRQSourceHandler_t* pvfHandlerReg;
    const UBase_t uxResetInterrupt = ((UBase_t) WDT_enINT_MAX) - 1UL;

    pvfHandlerReg = WDT__pvfGetIRQSourceHandlerPointer((WDT_nMODULE) 0UL,
                                                       (WDT_nINT) uxResetInterrupt);

    ASSERT_NE(nullptr, pvfHandlerReg);
    EXPECT_EQ(pvfExpectedDefault(0UL, uxResetInterrupt), *pvfHandlerReg);

    *pvfHandlerReg = &TM4C129E_DriverLib_Test__vCustomWDTIRQSourceHandler;

    EXPECT_EQ(&TM4C129E_DriverLib_Test__vCustomWDTIRQSourceHandler,
              WDT__pvfGetIRQSourceHandler((WDT_nMODULE) 0UL,
                                         (WDT_nINT) uxResetInterrupt));
}