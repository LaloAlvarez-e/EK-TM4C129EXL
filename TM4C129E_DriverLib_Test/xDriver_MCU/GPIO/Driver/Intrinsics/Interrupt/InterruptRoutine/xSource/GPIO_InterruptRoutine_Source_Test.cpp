/**
 *
 * @file GPIO_InterruptRoutine_Source_Test.cpp
 * @copyright
 * @verbatim InDeviceMex 2026 @endverbatim
 */

extern "C"
{
#include <xDriver_MCU/Common/xHeader/MCU_Variables.h>
#include <xDriver_MCU/GPIO/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/GPIO_InterruptRoutine_Source.h>

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

void TM4C129E_DriverLib_Test__vCustomGPIOIRQSourceHandler(uintptr_t uptrModuleArg, void* pvArgument)
{
    (void) uptrModuleArg;
    (void) pvArgument;
}
}

#include <gtest/gtest.h>

namespace
{
class GPIO_InterruptRoutineSourceTest : public ::testing::Test
{
protected:
    static GPIO_pvfIRQSourceHandler_t pvfExpectedDefault(UBase_t uxPort, UBase_t uxSelector)
    {
        (void) uxPort;
        (void) uxSelector;
        return &MCU_vIRQSourceHandler_Dummy;
    }

    void SetUp() override
    {
        vResetHandlerTables();
    }

    void TearDown() override
    {
        vResetHandlerTables();
    }

    void vResetHandlerTables()
    {
        for(UBase_t uxPort = 0UL; uxPort < (UBase_t) GPIO_enPORT_MAX; ++uxPort)
        {
            GPIO_pvfIRQSourceHandler_t* pvfSWHandlerReg;

            pvfSWHandlerReg = GPIO_SW__pvfGetIRQSourceHandlerPointer((GPIO_nPORT) uxPort);
            ASSERT_NE(nullptr, pvfSWHandlerReg);
            *pvfSWHandlerReg = pvfExpectedDefault(uxPort, 0UL);

            for(UBase_t uxPin = 0UL; uxPin < (UBase_t) GPIO_enPIN_MAX; ++uxPin)
            {
                GPIO_pvfIRQSourceHandler_t* pvfHandlerReg;
                GPIO_pvfIRQSourceHandler_t* pvfDMAHandlerReg;

                pvfHandlerReg = GPIO__pvfGetIRQSourceHandlerPointer((GPIO_nPORT) uxPort,
                                                                    (GPIO_nPIN) uxPin);
                pvfDMAHandlerReg = GPIO_DMA__pvfGetIRQSourceHandlerPointer((GPIO_nPORT) uxPort,
                                                                           (GPIO_nPIN) uxPin);

                ASSERT_NE(nullptr, pvfHandlerReg);
                ASSERT_NE(nullptr, pvfDMAHandlerReg);

                *pvfHandlerReg = pvfExpectedDefault(uxPort, uxPin);
                *pvfDMAHandlerReg = pvfExpectedDefault(uxPort, uxPin);
            }
        }

        for(UBase_t uxPin = 0UL; uxPin < (UBase_t) GPIO_enPIN_MAX; ++uxPin)
        {
            GPIO_pvfIRQSourceHandler_t* pvfPQPortPHandlerReg;
            GPIO_pvfIRQSourceHandler_t* pvfPQPortQHandlerReg;

            pvfPQPortPHandlerReg = GPIO_PQ__pvfGetIRQSourceHandlerPointer(GPIO_enPORT_P,
                                                                          (GPIO_nPIN) uxPin);
            pvfPQPortQHandlerReg = GPIO_PQ__pvfGetIRQSourceHandlerPointer(GPIO_enPORT_Q,
                                                                          (GPIO_nPIN) uxPin);

            ASSERT_NE(nullptr, pvfPQPortPHandlerReg);
            ASSERT_NE(nullptr, pvfPQPortQHandlerReg);

            *pvfPQPortPHandlerReg = pvfExpectedDefault((UBase_t) GPIO_enPORT_P, uxPin);
            *pvfPQPortQHandlerReg = pvfExpectedDefault((UBase_t) GPIO_enPORT_Q, uxPin);
        }
    }
};
}

/**
 * @brief Validate GPIO routine-source default handlers.
 */
TEST_F(GPIO_InterruptRoutineSourceTest, InterruptSourceHandlersExposeExpectedDefaultHandlers)
{
    for(UBase_t uxPort = 0UL; uxPort < (UBase_t) GPIO_enPORT_MAX; ++uxPort)
    {
        EXPECT_EQ(pvfExpectedDefault(uxPort, 0UL),
                  GPIO_SW__pvfGetIRQSourceHandler((GPIO_nPORT) uxPort));

        for(UBase_t uxPin = 0UL; uxPin < (UBase_t) GPIO_enPIN_MAX; ++uxPin)
        {
            EXPECT_EQ(pvfExpectedDefault(uxPort, uxPin),
                      GPIO__pvfGetIRQSourceHandler((GPIO_nPORT) uxPort,
                                                  (GPIO_nPIN) uxPin));
            EXPECT_EQ(pvfExpectedDefault(uxPort, uxPin),
                      GPIO_DMA__pvfGetIRQSourceHandler((GPIO_nPORT) uxPort,
                                                      (GPIO_nPIN) uxPin));
        }
    }

    for(UBase_t uxPin = 0UL; uxPin < (UBase_t) GPIO_enPIN_MAX; ++uxPin)
    {
        EXPECT_EQ(pvfExpectedDefault((UBase_t) GPIO_enPORT_P, uxPin),
                  GPIO_PQ__pvfGetIRQSourceHandler(GPIO_enPORT_P,
                                                 (GPIO_nPIN) uxPin));
        EXPECT_EQ(pvfExpectedDefault((UBase_t) GPIO_enPORT_Q, uxPin),
                  GPIO_PQ__pvfGetIRQSourceHandler(GPIO_enPORT_Q,
                                                 (GPIO_nPIN) uxPin));
    }
}

/**
 * @brief Validate GPIO getters reject invalid selections.
 */
TEST_F(GPIO_InterruptRoutineSourceTest, InterruptSourceGettersRejectInvalidSelections)
{
    EXPECT_EQ((GPIO_pvfIRQSourceHandler_t) nullptr,
              GPIO__pvfGetIRQSourceHandler((GPIO_nPORT) GPIO_enPORT_MAX,
                                          (GPIO_nPIN) 0UL));
    EXPECT_EQ((GPIO_pvfIRQSourceHandler_t) nullptr,
              GPIO__pvfGetIRQSourceHandler((GPIO_nPORT) 0UL,
                                          (GPIO_nPIN) GPIO_enPIN_MAX));

    EXPECT_EQ((GPIO_pvfIRQSourceHandler_t) nullptr,
              GPIO_DMA__pvfGetIRQSourceHandler((GPIO_nPORT) GPIO_enPORT_MAX,
                                              (GPIO_nPIN) 0UL));
    EXPECT_EQ((GPIO_pvfIRQSourceHandler_t) nullptr,
              GPIO_DMA__pvfGetIRQSourceHandler((GPIO_nPORT) 0UL,
                                              (GPIO_nPIN) GPIO_enPIN_MAX));

    EXPECT_EQ((GPIO_pvfIRQSourceHandler_t) nullptr,
              GPIO_SW__pvfGetIRQSourceHandler((GPIO_nPORT) GPIO_enPORT_MAX));

    EXPECT_EQ((GPIO_pvfIRQSourceHandler_t) nullptr,
              GPIO_PQ__pvfGetIRQSourceHandler((GPIO_nPORT) 0UL,
                                             (GPIO_nPIN) 0UL));
    EXPECT_EQ((GPIO_pvfIRQSourceHandler_t) nullptr,
              GPIO_PQ__pvfGetIRQSourceHandler(GPIO_enPORT_P,
                                             (GPIO_nPIN) GPIO_enPIN_MAX));
}

/**
 * @brief Validate GPIO pointer helpers reject invalid selections.
 */
TEST_F(GPIO_InterruptRoutineSourceTest, InterruptSourceHandlerPointersRejectInvalidSelections)
{
    EXPECT_EQ(nullptr,
              GPIO__pvfGetIRQSourceHandlerPointer((GPIO_nPORT) GPIO_enPORT_MAX,
                                                 (GPIO_nPIN) 0UL));
    EXPECT_EQ(nullptr,
              GPIO__pvfGetIRQSourceHandlerPointer((GPIO_nPORT) 0UL,
                                                 (GPIO_nPIN) GPIO_enPIN_MAX));

    EXPECT_EQ(nullptr,
              GPIO_DMA__pvfGetIRQSourceHandlerPointer((GPIO_nPORT) GPIO_enPORT_MAX,
                                                     (GPIO_nPIN) 0UL));
    EXPECT_EQ(nullptr,
              GPIO_DMA__pvfGetIRQSourceHandlerPointer((GPIO_nPORT) 0UL,
                                                     (GPIO_nPIN) GPIO_enPIN_MAX));

    EXPECT_EQ(nullptr,
              GPIO_SW__pvfGetIRQSourceHandlerPointer((GPIO_nPORT) GPIO_enPORT_MAX));

    EXPECT_EQ(nullptr,
              GPIO_PQ__pvfGetIRQSourceHandlerPointer((GPIO_nPORT) 0UL,
                                                    (GPIO_nPIN) 0UL));
    EXPECT_EQ(nullptr,
              GPIO_PQ__pvfGetIRQSourceHandlerPointer(GPIO_enPORT_P,
                                                    (GPIO_nPIN) GPIO_enPIN_MAX));
}

/**
 * @brief Validate GPIO pointer helpers expose writable slots.
 */
TEST_F(GPIO_InterruptRoutineSourceTest, InterruptSourceHandlerPointersExposeWritableSlots)
{
    GPIO_pvfIRQSourceHandler_t* pvfHandlerReg;
    GPIO_pvfIRQSourceHandler_t* pvfDMAHandlerReg;
    GPIO_pvfIRQSourceHandler_t* pvfSWHandlerReg;
    GPIO_pvfIRQSourceHandler_t* pvfPQHandlerReg;

    pvfHandlerReg = GPIO__pvfGetIRQSourceHandlerPointer((GPIO_nPORT) 0UL,
                                                        (GPIO_nPIN) 0UL);
    pvfDMAHandlerReg = GPIO_DMA__pvfGetIRQSourceHandlerPointer((GPIO_nPORT) 0UL,
                                                               (GPIO_nPIN) 0UL);
    pvfSWHandlerReg = GPIO_SW__pvfGetIRQSourceHandlerPointer((GPIO_nPORT) 0UL);
    pvfPQHandlerReg = GPIO_PQ__pvfGetIRQSourceHandlerPointer(GPIO_enPORT_P,
                                                             (GPIO_nPIN) 0UL);

    ASSERT_NE(nullptr, pvfHandlerReg);
    ASSERT_NE(nullptr, pvfDMAHandlerReg);
    ASSERT_NE(nullptr, pvfSWHandlerReg);
    ASSERT_NE(nullptr, pvfPQHandlerReg);

    *pvfHandlerReg = &TM4C129E_DriverLib_Test__vCustomGPIOIRQSourceHandler;
    *pvfDMAHandlerReg = &TM4C129E_DriverLib_Test__vCustomGPIOIRQSourceHandler;
    *pvfSWHandlerReg = &TM4C129E_DriverLib_Test__vCustomGPIOIRQSourceHandler;
    *pvfPQHandlerReg = &TM4C129E_DriverLib_Test__vCustomGPIOIRQSourceHandler;

    EXPECT_EQ(&TM4C129E_DriverLib_Test__vCustomGPIOIRQSourceHandler,
              GPIO__pvfGetIRQSourceHandler((GPIO_nPORT) 0UL,
                                          (GPIO_nPIN) 0UL));
    EXPECT_EQ(&TM4C129E_DriverLib_Test__vCustomGPIOIRQSourceHandler,
              GPIO_DMA__pvfGetIRQSourceHandler((GPIO_nPORT) 0UL,
                                              (GPIO_nPIN) 0UL));
    EXPECT_EQ(&TM4C129E_DriverLib_Test__vCustomGPIOIRQSourceHandler,
              GPIO_SW__pvfGetIRQSourceHandler((GPIO_nPORT) 0UL));
    EXPECT_EQ(&TM4C129E_DriverLib_Test__vCustomGPIOIRQSourceHandler,
              GPIO_PQ__pvfGetIRQSourceHandler(GPIO_enPORT_P,
                                             (GPIO_nPIN) 0UL));
}