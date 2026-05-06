/**
 *
 * @file DMA_InterruptRoutine_Source_Software_Test.cpp
 * @copyright
 * @verbatim InDeviceMex 2026 @endverbatim
 */

extern "C"
{
#include <xDriver_MCU/Common/xHeader/MCU_Variables.h>
#include <xDriver_MCU/DMA/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/DMA_InterruptRoutine_Source_Software.h>

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

void TM4C129E_DriverLib_Test__vCustomDMAIRQSourceHandler(uintptr_t uptrModuleArg, void* pvArgument)
{
    (void) uptrModuleArg;
    (void) pvArgument;
}
}

#include <gtest/gtest.h>

namespace
{
class DMA_InterruptRoutineSourceSoftwareTest : public ::testing::Test
{
protected:
    static DMA_pvfIRQSourceHandler_t pvfExpectedDefault(UBase_t uxModule, UBase_t uxSelector)
    {
        (void) uxModule;
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
        for(UBase_t uxModule = 0UL; uxModule < (UBase_t) DMA_enMODULE_MAX; ++uxModule)
        {
            for(UBase_t uxInterruptSource = 0UL; uxInterruptSource < (UBase_t) DMA_enINT_ERROR_MAX; ++uxInterruptSource)
            {
                DMA_pvfIRQSourceHandler_t* pvfErrorHandlerReg;

                pvfErrorHandlerReg = DMA__pvfGetIRQSourceHandlerPointer_Error((DMA_nMODULE) uxModule,
                                                                              (DMA_nINT_ERROR) uxInterruptSource);
                ASSERT_NE(nullptr, pvfErrorHandlerReg);
                *pvfErrorHandlerReg = pvfExpectedDefault(uxModule, uxInterruptSource);
            }

            for(UBase_t uxChannel = 0UL; uxChannel < (((UBase_t) DMA_enCH_MAX) + 1UL); ++uxChannel)
            {
                DMA_pvfIRQSourceHandler_t* pvfSoftwareHandlerReg;

                pvfSoftwareHandlerReg = DMA_CH__pvfGetIRQSourceHandlerPointer_Software((DMA_nMODULE) uxModule,
                                                                                       (DMA_nCH) uxChannel);
                ASSERT_NE(nullptr, pvfSoftwareHandlerReg);
                *pvfSoftwareHandlerReg = pvfExpectedDefault(uxModule, uxChannel);
            }
        }
    }
};
}

/**
 * @brief Validate DMA routine-source default handlers.
 */
TEST_F(DMA_InterruptRoutineSourceSoftwareTest, InterruptSourceHandlersExposeExpectedDefaultHandlers)
{
    for(UBase_t uxModule = 0UL; uxModule < (UBase_t) DMA_enMODULE_MAX; ++uxModule)
    {
        for(UBase_t uxInterruptSource = 0UL; uxInterruptSource < (UBase_t) DMA_enINT_ERROR_MAX; ++uxInterruptSource)
        {
            EXPECT_EQ(pvfExpectedDefault(uxModule, uxInterruptSource),
                      DMA__pvfGetIRQSourceHandler_Error((DMA_nMODULE) uxModule,
                                                       (DMA_nINT_ERROR) uxInterruptSource));
        }

        for(UBase_t uxChannel = 0UL; uxChannel < (((UBase_t) DMA_enCH_MAX) + 1UL); ++uxChannel)
        {
            EXPECT_EQ(pvfExpectedDefault(uxModule, uxChannel),
                      DMA_CH__pvfGetIRQSourceHandler_Software((DMA_nMODULE) uxModule,
                                                              (DMA_nCH) uxChannel));
        }
    }
}

/**
 * @brief Validate DMA getters reject invalid selections.
 */
TEST_F(DMA_InterruptRoutineSourceSoftwareTest, InterruptSourceGettersRejectInvalidSelections)
{
    EXPECT_EQ((DMA_pvfIRQSourceHandler_t) nullptr,
              DMA__pvfGetIRQSourceHandler_Error((DMA_nMODULE) DMA_enMODULE_MAX,
                                               (DMA_nINT_ERROR) 0UL));
    EXPECT_EQ((DMA_pvfIRQSourceHandler_t) nullptr,
              DMA__pvfGetIRQSourceHandler_Error((DMA_nMODULE) 0UL,
                                               (DMA_nINT_ERROR) DMA_enINT_ERROR_MAX));

    EXPECT_EQ((DMA_pvfIRQSourceHandler_t) nullptr,
              DMA_CH__pvfGetIRQSourceHandler_Software((DMA_nMODULE) DMA_enMODULE_MAX,
                                                     (DMA_nCH) 0UL));
    EXPECT_EQ((DMA_pvfIRQSourceHandler_t) nullptr,
              DMA_CH__pvfGetIRQSourceHandler_Software((DMA_nMODULE) 0UL,
                                                     (DMA_nCH) (((UBase_t) DMA_enCH_MAX) + 1UL)));
}

/**
 * @brief Validate DMA pointer helpers reject invalid selections.
 */
TEST_F(DMA_InterruptRoutineSourceSoftwareTest, InterruptSourceHandlerPointersRejectInvalidSelections)
{
    EXPECT_EQ(nullptr,
              DMA__pvfGetIRQSourceHandlerPointer_Error((DMA_nMODULE) DMA_enMODULE_MAX,
                                                      (DMA_nINT_ERROR) 0UL));
    EXPECT_EQ(nullptr,
              DMA__pvfGetIRQSourceHandlerPointer_Error((DMA_nMODULE) 0UL,
                                                      (DMA_nINT_ERROR) DMA_enINT_ERROR_MAX));

    EXPECT_EQ(nullptr,
              DMA_CH__pvfGetIRQSourceHandlerPointer_Software((DMA_nMODULE) DMA_enMODULE_MAX,
                                                            (DMA_nCH) 0UL));
    EXPECT_EQ(nullptr,
              DMA_CH__pvfGetIRQSourceHandlerPointer_Software((DMA_nMODULE) 0UL,
                                                            (DMA_nCH) (((UBase_t) DMA_enCH_MAX) + 1UL)));
}

/**
 * @brief Validate DMA pointer helpers expose writable slots.
 */
TEST_F(DMA_InterruptRoutineSourceSoftwareTest, InterruptSourceHandlerPointersExposeWritableSlots)
{
    DMA_pvfIRQSourceHandler_t* pvfErrorHandlerReg;
    DMA_pvfIRQSourceHandler_t* pvfSoftwareHandlerReg;

    pvfErrorHandlerReg = DMA__pvfGetIRQSourceHandlerPointer_Error((DMA_nMODULE) 0UL,
                                                                  (DMA_nINT_ERROR) 0UL);
    pvfSoftwareHandlerReg = DMA_CH__pvfGetIRQSourceHandlerPointer_Software((DMA_nMODULE) 0UL,
                                                                           (DMA_nCH) DMA_enCH_MAX);

    ASSERT_NE(nullptr, pvfErrorHandlerReg);
    ASSERT_NE(nullptr, pvfSoftwareHandlerReg);

    EXPECT_EQ(pvfExpectedDefault(0UL, 0UL), *pvfErrorHandlerReg);
    EXPECT_EQ(pvfExpectedDefault(0UL, (UBase_t) DMA_enCH_MAX), *pvfSoftwareHandlerReg);

    *pvfErrorHandlerReg = &TM4C129E_DriverLib_Test__vCustomDMAIRQSourceHandler;
    *pvfSoftwareHandlerReg = &TM4C129E_DriverLib_Test__vCustomDMAIRQSourceHandler;

    EXPECT_EQ(&TM4C129E_DriverLib_Test__vCustomDMAIRQSourceHandler,
              DMA__pvfGetIRQSourceHandler_Error((DMA_nMODULE) 0UL,
                                               (DMA_nINT_ERROR) 0UL));
    EXPECT_EQ(&TM4C129E_DriverLib_Test__vCustomDMAIRQSourceHandler,
              DMA_CH__pvfGetIRQSourceHandler_Software((DMA_nMODULE) 0UL,
                                                     (DMA_nCH) DMA_enCH_MAX));
}