/**
 *
 * @file SSI_InterruptRoutine_Source_Test.cpp
 * @copyright
 * @verbatim InDeviceMex 2026 @endverbatim
 */

extern "C"
{
#include <xDriver_MCU/Common/xHeader/MCU_Variables.h>
#include <xDriver_MCU/SSI/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/SSI_InterruptRoutine_Source.h>

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

void TM4C129E_DriverLib_Test__vCustomSSIIRQSourceHandler(uintptr_t uptrModuleArg, void* pvArgument)
{
    (void) uptrModuleArg;
    (void) pvArgument;
}
}

#include <gtest/gtest.h>

namespace
{
class SSI_InterruptRoutineSourceTest : public ::testing::Test
{
protected:
    static SSI_pvfIRQSourceHandler_t pvfExpectedDefault(UBase_t uxModule, UBase_t uxInterruptSource)
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
        for(UBase_t uxModule = 0UL; uxModule < (UBase_t) SSI_enMODULE_MAX; ++uxModule)
        {
            for(UBase_t uxInterruptSource = 0UL; uxInterruptSource < (UBase_t) SSI_enINT_MAX; ++uxInterruptSource)
            {
                SSI_pvfIRQSourceHandler_t* pvfHandlerReg;

                pvfHandlerReg = SSI__pvfGetIRQSourceHandlerPointer((SSI_nMODULE) uxModule,
                                                                  (SSI_nINT) uxInterruptSource);
                ASSERT_NE(nullptr, pvfHandlerReg);
                *pvfHandlerReg = pvfExpectedDefault(uxModule, uxInterruptSource);
            }
        }
    }
};
}

/**
 * @brief Validate SSI routine-source default handlers.
 */
TEST_F(SSI_InterruptRoutineSourceTest, InterruptSourceHandlersExposeExpectedDefaultHandlers)
{
    for(UBase_t uxModule = 0UL; uxModule < (UBase_t) SSI_enMODULE_MAX; ++uxModule)
    {
        for(UBase_t uxInterruptSource = 0UL; uxInterruptSource < (UBase_t) SSI_enINT_MAX; ++uxInterruptSource)
        {
            EXPECT_EQ(pvfExpectedDefault(uxModule, uxInterruptSource),
                      SSI__pvfGetIRQSourceHandler((SSI_nMODULE) uxModule,
                                                 (SSI_nINT) uxInterruptSource));
        }
    }
}

/**
 * @brief Validate SSI getters reject invalid selections.
 */
TEST_F(SSI_InterruptRoutineSourceTest, InterruptSourceGettersRejectInvalidSelections)
{
    EXPECT_EQ((SSI_pvfIRQSourceHandler_t) nullptr,
              SSI__pvfGetIRQSourceHandler((SSI_nMODULE) SSI_enMODULE_MAX,
                                         (SSI_nINT) 0UL));
    EXPECT_EQ((SSI_pvfIRQSourceHandler_t) nullptr,
              SSI__pvfGetIRQSourceHandler((SSI_nMODULE) 0UL,
                                         (SSI_nINT) SSI_enINT_MAX));
}

/**
 * @brief Validate SSI pointer helpers reject invalid selections.
 */
TEST_F(SSI_InterruptRoutineSourceTest, InterruptSourceHandlerPointersRejectInvalidSelections)
{
    EXPECT_EQ(nullptr,
              SSI__pvfGetIRQSourceHandlerPointer((SSI_nMODULE) SSI_enMODULE_MAX,
                                                (SSI_nINT) 0UL));
    EXPECT_EQ(nullptr,
              SSI__pvfGetIRQSourceHandlerPointer((SSI_nMODULE) 0UL,
                                                (SSI_nINT) SSI_enINT_MAX));
}

/**
 * @brief Validate SSI pointer helpers expose writable slots.
 */
TEST_F(SSI_InterruptRoutineSourceTest, InterruptSourceHandlerPointersExposeWritableSlots)
{
    SSI_pvfIRQSourceHandler_t* pvfHandlerReg;

    pvfHandlerReg = SSI__pvfGetIRQSourceHandlerPointer((SSI_nMODULE) 0UL,
                                                       (SSI_nINT) 0UL);

    ASSERT_NE(nullptr, pvfHandlerReg);
    EXPECT_EQ(pvfExpectedDefault(0UL, 0UL), *pvfHandlerReg);

    *pvfHandlerReg = &TM4C129E_DriverLib_Test__vCustomSSIIRQSourceHandler;

    EXPECT_EQ(&TM4C129E_DriverLib_Test__vCustomSSIIRQSourceHandler,
              SSI__pvfGetIRQSourceHandler((SSI_nMODULE) 0UL,
                                         (SSI_nINT) 0UL));
}