/**
 *
 * @file UART_InterruptRoutine_Source_Test.cpp
 * @copyright
 * @verbatim InDeviceMex 2026 @endverbatim
 */

extern "C"
{
#include <xDriver_MCU/Common/xHeader/MCU_Variables.h>
#include <xDriver_MCU/UART/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/UART_InterruptRoutine_Source.h>

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

void TM4C129E_DriverLib_Test__vCustomUARTIRQSourceHandler(uintptr_t uptrModuleArg, void* pvArgument)
{
    (void) uptrModuleArg;
    (void) pvArgument;
}
}

#include <gtest/gtest.h>

namespace
{
class UART_InterruptRoutineSourceTest : public ::testing::Test
{
protected:
    static UART_pvfIRQSourceHandler_t pvfExpectedDefault(UBase_t uxModule, UBase_t uxInterruptSource)
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
        for(UBase_t uxModule = 0UL; uxModule < (UBase_t) UART_enMODULE_MAX; ++uxModule)
        {
            for(UBase_t uxInterruptSource = 0UL; uxInterruptSource < (UBase_t) UART_enINT_MAX; ++uxInterruptSource)
            {
                UART_pvfIRQSourceHandler_t* pvfHandlerReg;

                pvfHandlerReg = UART__pvfGetIRQSourceHandlerPointer((UART_nMODULE) uxModule,
                                                                   (UART_nINT) uxInterruptSource);
                ASSERT_NE(nullptr, pvfHandlerReg);
                *pvfHandlerReg = pvfExpectedDefault(uxModule, uxInterruptSource);
            }
        }
    }
};
}

/**
 * @brief Validate UART routine-source default handlers.
 */
TEST_F(UART_InterruptRoutineSourceTest, InterruptSourceHandlersExposeExpectedDefaultHandlers)
{
    for(UBase_t uxModule = 0UL; uxModule < (UBase_t) UART_enMODULE_MAX; ++uxModule)
    {
        for(UBase_t uxInterruptSource = 0UL; uxInterruptSource < (UBase_t) UART_enINT_MAX; ++uxInterruptSource)
        {
            EXPECT_EQ(pvfExpectedDefault(uxModule, uxInterruptSource),
                      UART__pvfGetIRQSourceHandler((UART_nMODULE) uxModule,
                                                  (UART_nINT) uxInterruptSource));
        }
    }
}

/**
 * @brief Validate UART getters reject invalid selections.
 */
TEST_F(UART_InterruptRoutineSourceTest, InterruptSourceGettersRejectInvalidSelections)
{
    EXPECT_EQ((UART_pvfIRQSourceHandler_t) nullptr,
              UART__pvfGetIRQSourceHandler((UART_nMODULE) UART_enMODULE_MAX,
                                          (UART_nINT) 0UL));
    EXPECT_EQ((UART_pvfIRQSourceHandler_t) nullptr,
              UART__pvfGetIRQSourceHandler((UART_nMODULE) 0UL,
                                          (UART_nINT) UART_enINT_MAX));
}

/**
 * @brief Validate UART pointer helpers reject invalid selections.
 */
TEST_F(UART_InterruptRoutineSourceTest, InterruptSourceHandlerPointersRejectInvalidSelections)
{
    EXPECT_EQ(nullptr,
              UART__pvfGetIRQSourceHandlerPointer((UART_nMODULE) UART_enMODULE_MAX,
                                                 (UART_nINT) 0UL));
    EXPECT_EQ(nullptr,
              UART__pvfGetIRQSourceHandlerPointer((UART_nMODULE) 0UL,
                                                 (UART_nINT) UART_enINT_MAX));
}

/**
 * @brief Validate UART pointer helpers expose writable slots.
 */
TEST_F(UART_InterruptRoutineSourceTest, InterruptSourceHandlerPointersExposeWritableSlots)
{
    UART_pvfIRQSourceHandler_t* pvfHandlerReg;

    pvfHandlerReg = UART__pvfGetIRQSourceHandlerPointer((UART_nMODULE) 0UL,
                                                        (UART_nINT) 0UL);

    ASSERT_NE(nullptr, pvfHandlerReg);
    EXPECT_EQ(pvfExpectedDefault(0UL, 0UL), *pvfHandlerReg);

    *pvfHandlerReg = &TM4C129E_DriverLib_Test__vCustomUARTIRQSourceHandler;

    EXPECT_EQ(&TM4C129E_DriverLib_Test__vCustomUARTIRQSourceHandler,
              UART__pvfGetIRQSourceHandler((UART_nMODULE) 0UL,
                                          (UART_nINT) 0UL));
}