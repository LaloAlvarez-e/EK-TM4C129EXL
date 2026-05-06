/**
 *
 * @file FLASH_InterruptRoutine_Source_Test.cpp
 * @copyright
 * @verbatim InDeviceMex 2026 @endverbatim
 */

extern "C"
{
#include <xDriver_MCU/Common/xHeader/MCU_Variables.h>
#include <xDriver_MCU/FLASH/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/FLASH_InterruptRoutine_Source.h>

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

void TM4C129E_DriverLib_Test__vCustomFLASHIRQSourceHandler(uintptr_t uptrModuleArg, void* pvArgument)
{
    (void) uptrModuleArg;
    (void) pvArgument;
}
}

#include <gtest/gtest.h>

namespace
{
class FLASH_InterruptRoutineSourceTest : public ::testing::Test
{
protected:
    static FLASH_pvfIRQSourceHandler_t pvfExpectedDefault(UBase_t uxModule, UBase_t uxInterruptSource)
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
        for(UBase_t uxModule = 0UL; uxModule < (UBase_t) FLASH_enMODULE_MAX; ++uxModule)
        {
            for(UBase_t uxInterruptSource = 0UL; uxInterruptSource < (UBase_t) FLASH_enINT_MAX; ++uxInterruptSource)
            {
                FLASH_pvfIRQSourceHandler_t* pvfHandlerReg;

                pvfHandlerReg = FLASH__pvfGetIRQSourceHandlerPointer((FLASH_nMODULE) uxModule,
                                                                    (FLASH_nINT) uxInterruptSource);
                ASSERT_NE(nullptr, pvfHandlerReg);
                *pvfHandlerReg = pvfExpectedDefault(uxModule, uxInterruptSource);
            }
        }
    }
};
}

/**
 * @brief Validate FLASH routine-source default handlers.
 */
TEST_F(FLASH_InterruptRoutineSourceTest, InterruptSourceHandlersExposeExpectedDefaultHandlers)
{
    for(UBase_t uxModule = 0UL; uxModule < (UBase_t) FLASH_enMODULE_MAX; ++uxModule)
    {
        for(UBase_t uxInterruptSource = 0UL; uxInterruptSource < (UBase_t) FLASH_enINT_MAX; ++uxInterruptSource)
        {
            EXPECT_EQ(pvfExpectedDefault(uxModule, uxInterruptSource),
                      FLASH__pvfGetIRQSourceHandler((FLASH_nMODULE) uxModule,
                                                   (FLASH_nINT) uxInterruptSource));
        }
    }
}

/**
 * @brief Validate FLASH getters reject invalid selections.
 */
TEST_F(FLASH_InterruptRoutineSourceTest, InterruptSourceGettersRejectInvalidSelections)
{
    EXPECT_EQ((FLASH_pvfIRQSourceHandler_t) nullptr,
              FLASH__pvfGetIRQSourceHandler((FLASH_nMODULE) FLASH_enMODULE_MAX,
                                           (FLASH_nINT) 0UL));
    EXPECT_EQ((FLASH_pvfIRQSourceHandler_t) nullptr,
              FLASH__pvfGetIRQSourceHandler((FLASH_nMODULE) 0UL,
                                           (FLASH_nINT) FLASH_enINT_MAX));
}

/**
 * @brief Validate FLASH pointer helpers reject invalid selections.
 */
TEST_F(FLASH_InterruptRoutineSourceTest, InterruptSourceHandlerPointersRejectInvalidSelections)
{
    EXPECT_EQ(nullptr,
              FLASH__pvfGetIRQSourceHandlerPointer((FLASH_nMODULE) FLASH_enMODULE_MAX,
                                                  (FLASH_nINT) 0UL));
    EXPECT_EQ(nullptr,
              FLASH__pvfGetIRQSourceHandlerPointer((FLASH_nMODULE) 0UL,
                                                  (FLASH_nINT) FLASH_enINT_MAX));
}

/**
 * @brief Validate FLASH pointer helpers expose writable slots.
 */
TEST_F(FLASH_InterruptRoutineSourceTest, InterruptSourceHandlerPointersExposeWritableSlots)
{
    FLASH_pvfIRQSourceHandler_t* pvfHandlerReg;

    pvfHandlerReg = FLASH__pvfGetIRQSourceHandlerPointer((FLASH_nMODULE) 0UL,
                                                         (FLASH_nINT) 0UL);

    ASSERT_NE(nullptr, pvfHandlerReg);
    EXPECT_EQ(pvfExpectedDefault(0UL, 0UL), *pvfHandlerReg);

    *pvfHandlerReg = &TM4C129E_DriverLib_Test__vCustomFLASHIRQSourceHandler;

    EXPECT_EQ(&TM4C129E_DriverLib_Test__vCustomFLASHIRQSourceHandler,
              FLASH__pvfGetIRQSourceHandler((FLASH_nMODULE) 0UL,
                                           (FLASH_nINT) 0UL));
}