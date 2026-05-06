/**
 *
 * @file SYSEXC_InterruptRoutine_Source_Test.cpp
 * @copyright
 * @verbatim InDeviceMex 2026 @endverbatim
 */

extern "C"
{
#include <xDriver_MCU/Common/xHeader/MCU_Variables.h>
#include <xDriver_MCU/SYSEXC/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/SYSEXC_InterruptRoutine_Source.h>

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

void TM4C129E_DriverLib_Test__vCustomSYSEXCIRQSourceHandler(uintptr_t uptrModuleArg, void* pvArgument)
{
    (void) uptrModuleArg;
    (void) pvArgument;
}
}

#include <gtest/gtest.h>

namespace
{
class SYSEXC_InterruptRoutineSourceTest : public ::testing::Test
{
protected:
    static SYSEXC_pvfIRQSourceHandler_t pvfExpectedDefault(UBase_t uxModule, UBase_t uxInterruptSource)
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
        for(UBase_t uxModule = 0UL; uxModule < (UBase_t) SYSEXC_enMODULE_MAX; ++uxModule)
        {
            for(UBase_t uxInterruptSource = 0UL; uxInterruptSource < (UBase_t) SYSEXC_enINT_MAX; ++uxInterruptSource)
            {
                SYSEXC_pvfIRQSourceHandler_t* pvfHandlerReg;

                pvfHandlerReg = SYSEXC__pvfGetIRQSourceHandlerPointer((SYSEXC_nMODULE) uxModule,
                                                                     (SYSEXC_nINT) uxInterruptSource);
                ASSERT_NE(nullptr, pvfHandlerReg);
                *pvfHandlerReg = pvfExpectedDefault(uxModule, uxInterruptSource);
            }
        }
    }
};
}

/**
 * @brief Validate SYSEXC routine-source default handlers.
 */
TEST_F(SYSEXC_InterruptRoutineSourceTest, InterruptSourceHandlersExposeExpectedDefaultHandlers)
{
    for(UBase_t uxModule = 0UL; uxModule < (UBase_t) SYSEXC_enMODULE_MAX; ++uxModule)
    {
        for(UBase_t uxInterruptSource = 0UL; uxInterruptSource < (UBase_t) SYSEXC_enINT_MAX; ++uxInterruptSource)
        {
            EXPECT_EQ(pvfExpectedDefault(uxModule, uxInterruptSource),
                      SYSEXC__pvfGetIRQSourceHandler((SYSEXC_nMODULE) uxModule,
                                                    (SYSEXC_nINT) uxInterruptSource));
        }
    }
}

/**
 * @brief Validate SYSEXC getters reject invalid selections.
 */
TEST_F(SYSEXC_InterruptRoutineSourceTest, InterruptSourceGettersRejectInvalidSelections)
{
    EXPECT_EQ((SYSEXC_pvfIRQSourceHandler_t) nullptr,
              SYSEXC__pvfGetIRQSourceHandler((SYSEXC_nMODULE) SYSEXC_enMODULE_MAX,
                                            (SYSEXC_nINT) 0UL));
    EXPECT_EQ((SYSEXC_pvfIRQSourceHandler_t) nullptr,
              SYSEXC__pvfGetIRQSourceHandler((SYSEXC_nMODULE) 0UL,
                                            (SYSEXC_nINT) SYSEXC_enINT_MAX));
}

/**
 * @brief Validate SYSEXC pointer helpers reject invalid selections.
 */
TEST_F(SYSEXC_InterruptRoutineSourceTest, InterruptSourceHandlerPointersRejectInvalidSelections)
{
    EXPECT_EQ(nullptr,
              SYSEXC__pvfGetIRQSourceHandlerPointer((SYSEXC_nMODULE) SYSEXC_enMODULE_MAX,
                                                   (SYSEXC_nINT) 0UL));
    EXPECT_EQ(nullptr,
              SYSEXC__pvfGetIRQSourceHandlerPointer((SYSEXC_nMODULE) 0UL,
                                                   (SYSEXC_nINT) SYSEXC_enINT_MAX));
}

/**
 * @brief Validate SYSEXC pointer helpers expose writable slots.
 */
TEST_F(SYSEXC_InterruptRoutineSourceTest, InterruptSourceHandlerPointersExposeWritableSlots)
{
    SYSEXC_pvfIRQSourceHandler_t* pvfHandlerReg;

    pvfHandlerReg = SYSEXC__pvfGetIRQSourceHandlerPointer((SYSEXC_nMODULE) 0UL,
                                                          (SYSEXC_nINT) 0UL);

    ASSERT_NE(nullptr, pvfHandlerReg);
    EXPECT_EQ(pvfExpectedDefault(0UL, 0UL), *pvfHandlerReg);

    *pvfHandlerReg = &TM4C129E_DriverLib_Test__vCustomSYSEXCIRQSourceHandler;

    EXPECT_EQ(&TM4C129E_DriverLib_Test__vCustomSYSEXCIRQSourceHandler,
              SYSEXC__pvfGetIRQSourceHandler((SYSEXC_nMODULE) 0UL,
                                            (SYSEXC_nINT) 0UL));
}