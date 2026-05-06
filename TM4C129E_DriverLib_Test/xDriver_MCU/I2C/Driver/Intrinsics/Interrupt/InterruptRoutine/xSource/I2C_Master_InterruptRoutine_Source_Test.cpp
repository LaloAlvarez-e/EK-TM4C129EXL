/**
 *
 * @file I2C_Master_InterruptRoutine_Source_Test.cpp
 * @copyright
 * @verbatim InDeviceMex 2026 @endverbatim
 */

extern "C"
{
#include <xDriver_MCU/Common/xHeader/MCU_Variables.h>
#include <xDriver_MCU/I2C/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/I2C_Master_InterruptRoutine_Source.h>

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

void TM4C129E_DriverLib_Test__vCustomI2CMasterIRQSourceHandler(uintptr_t uptrModuleArg, void* pvArgument)
{
    (void) uptrModuleArg;
    (void) pvArgument;
}
}

#include <gtest/gtest.h>

namespace
{
class I2C_Master_InterruptRoutineSourceTest : public ::testing::Test
{
protected:
    static I2C_pvfIRQSourceHandler_t pvfExpectedDefault(UBase_t uxModule, UBase_t uxInterruptSource)
    {
        (void) uxModule;
        if((((UBase_t) I2C_enMASTER_INT_MAX) - 1UL) == uxInterruptSource)
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
        for(UBase_t uxModule = 0UL; uxModule < (UBase_t) I2C_enMODULE_MAX; ++uxModule)
        {
            for(UBase_t uxInterruptSource = 0UL; uxInterruptSource < (UBase_t) I2C_enMASTER_INT_MAX; ++uxInterruptSource)
            {
                I2C_pvfIRQSourceHandler_t* pvfHandlerReg;

                pvfHandlerReg = I2C_Master__pvfGetIRQSourceHandlerPointer((I2C_nMODULE) uxModule,
                                                                         (I2C_nMASTER_INT) uxInterruptSource);
                ASSERT_NE(nullptr, pvfHandlerReg);
                *pvfHandlerReg = pvfExpectedDefault(uxModule, uxInterruptSource);
            }
        }
    }
};
}

/**
 * @brief Validate I2C master routine-source default handlers.
 */
TEST_F(I2C_Master_InterruptRoutineSourceTest, InterruptSourceHandlersExposeExpectedDefaultHandlers)
{
    for(UBase_t uxModule = 0UL; uxModule < (UBase_t) I2C_enMODULE_MAX; ++uxModule)
    {
        for(UBase_t uxInterruptSource = 0UL; uxInterruptSource < (UBase_t) I2C_enMASTER_INT_MAX; ++uxInterruptSource)
        {
            EXPECT_EQ(pvfExpectedDefault(uxModule, uxInterruptSource),
                      I2C_Master__pvfGetIRQSourceHandler((I2C_nMODULE) uxModule,
                                                        (I2C_nMASTER_INT) uxInterruptSource));
        }
    }
}

/**
 * @brief Validate I2C master getters reject invalid selections.
 */
TEST_F(I2C_Master_InterruptRoutineSourceTest, InterruptSourceGettersRejectInvalidSelections)
{
    EXPECT_EQ((I2C_pvfIRQSourceHandler_t) nullptr,
              I2C_Master__pvfGetIRQSourceHandler((I2C_nMODULE) I2C_enMODULE_MAX,
                                                (I2C_nMASTER_INT) 0UL));
    EXPECT_EQ((I2C_pvfIRQSourceHandler_t) nullptr,
              I2C_Master__pvfGetIRQSourceHandler((I2C_nMODULE) 0UL,
                                                (I2C_nMASTER_INT) I2C_enMASTER_INT_MAX));
}

/**
 * @brief Validate I2C master pointer helpers reject invalid selections.
 */
TEST_F(I2C_Master_InterruptRoutineSourceTest, InterruptSourceHandlerPointersRejectInvalidSelections)
{
    EXPECT_EQ(nullptr,
              I2C_Master__pvfGetIRQSourceHandlerPointer((I2C_nMODULE) I2C_enMODULE_MAX,
                                                       (I2C_nMASTER_INT) 0UL));
    EXPECT_EQ(nullptr,
              I2C_Master__pvfGetIRQSourceHandlerPointer((I2C_nMODULE) 0UL,
                                                       (I2C_nMASTER_INT) I2C_enMASTER_INT_MAX));
}

/**
 * @brief Validate I2C master pointer helpers expose writable slots.
 */
TEST_F(I2C_Master_InterruptRoutineSourceTest, InterruptSourceHandlerPointersExposeWritableSlots)
{
    I2C_pvfIRQSourceHandler_t* pvfHandlerReg;
    const UBase_t uxTimeoutInterrupt = ((UBase_t) I2C_enMASTER_INT_MAX) - 1UL;

    pvfHandlerReg = I2C_Master__pvfGetIRQSourceHandlerPointer((I2C_nMODULE) 0UL,
                                                             (I2C_nMASTER_INT) uxTimeoutInterrupt);

    ASSERT_NE(nullptr, pvfHandlerReg);
    EXPECT_EQ(pvfExpectedDefault(0UL, uxTimeoutInterrupt), *pvfHandlerReg);

    *pvfHandlerReg = &TM4C129E_DriverLib_Test__vCustomI2CMasterIRQSourceHandler;

    EXPECT_EQ(&TM4C129E_DriverLib_Test__vCustomI2CMasterIRQSourceHandler,
              I2C_Master__pvfGetIRQSourceHandler((I2C_nMODULE) 0UL,
                                                (I2C_nMASTER_INT) uxTimeoutInterrupt));
}