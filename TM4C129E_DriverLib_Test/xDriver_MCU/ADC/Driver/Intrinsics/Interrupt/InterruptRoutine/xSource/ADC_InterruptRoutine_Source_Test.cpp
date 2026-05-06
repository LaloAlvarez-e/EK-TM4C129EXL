/**
 *
 * @file ADC_InterruptRoutine_Source_Test.cpp
 * @copyright
 * @verbatim InDeviceMex 2026 @endverbatim
 */

extern "C"
{
#include <xDriver_MCU/Common/xHeader/MCU_Variables.h>
#include <xDriver_MCU/ADC/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/ADC_InterruptRoutine_Source.h>

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

void TM4C129E_DriverLib_Test__vCustomADCIRQSourceHandler(uintptr_t uptrModuleArg, void* pvArgument)
{
    (void) uptrModuleArg;
    (void) pvArgument;
}
}

#include <gtest/gtest.h>

namespace
{
class ADC_InterruptRoutineSourceTest : public ::testing::Test
{
protected:
    static ADC_pvfIRQSourceHandler_t pvfExpectedSWDefault(UBase_t uxModule, UBase_t uxSequencer)
    {
        (void) uxModule;
        (void) uxSequencer;
        return &MCU_vIRQSourceHandler_Dummy;
    }

    static ADC_pvfIRQSourceHandler_t pvfExpectedSequencerDefault(UBase_t uxModule, UBase_t uxSequencer, UBase_t uxInterruptType)
    {
        (void) uxInterruptType;
        if((1UL == uxModule) && ((((UBase_t) ADC_enSEQ_MAX) - 1UL) == uxSequencer))
        {
            return &MCU_vIRQSourceHandler_DummyNonBlocking;
        }
        return &MCU_vIRQSourceHandler_Dummy;
    }

    static ADC_pvfIRQSourceHandler_t pvfExpectedComparatorDefault(UBase_t uxModule, UBase_t uxSequencer, UBase_t uxComparator)
    {
        (void) uxModule;
        (void) uxSequencer;
        (void) uxComparator;
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
        for(UBase_t uxModule = 0UL; uxModule < (UBase_t) ADC_enMODULE_MAX; ++uxModule)
        {
            for(UBase_t uxSequencer = 0UL; uxSequencer < (UBase_t) ADC_enSEQ_MAX; ++uxSequencer)
            {
                ADC_pvfIRQSourceHandler_t* pvfSwHandlerReg;

                pvfSwHandlerReg = ADC_SW__pvfGetIRQSourceHandlerPointer((ADC_nMODULE) uxModule,
                                                                        (ADC_nSEQUENCER) uxSequencer);
                ASSERT_NE(nullptr, pvfSwHandlerReg);
                *pvfSwHandlerReg = pvfExpectedSWDefault(uxModule, uxSequencer);

                for(UBase_t uxInterruptType = 0UL; uxInterruptType < (UBase_t) ADC_enINT_TYPE_MAX; ++uxInterruptType)
                {
                    ADC_pvfIRQSourceHandler_t* pvfSequencerHandlerReg;

                    pvfSequencerHandlerReg = ADC_Sequencer__pvfGetIRQSourceHandlerPointer((ADC_nMODULE) uxModule,
                                                                                          (ADC_nSEQUENCER) uxSequencer,
                                                                                          (ADC_nINT_TYPE) uxInterruptType);
                    ASSERT_NE(nullptr, pvfSequencerHandlerReg);
                    *pvfSequencerHandlerReg = pvfExpectedSequencerDefault(uxModule, uxSequencer, uxInterruptType);
                }

                for(UBase_t uxComparator = 0UL; uxComparator < (UBase_t) ADC_enCOMPARATOR_MAX; ++uxComparator)
                {
                    ADC_pvfIRQSourceHandler_t* pvfComparatorHandlerReg;

                    pvfComparatorHandlerReg = ADC_Comparator__pvfGetIRQSourceHandlerPointer((ADC_nMODULE) uxModule,
                                                                                            (ADC_nSEQUENCER) uxSequencer,
                                                                                            (ADC_nCOMPARATOR) uxComparator);
                    ASSERT_NE(nullptr, pvfComparatorHandlerReg);
                    *pvfComparatorHandlerReg = pvfExpectedComparatorDefault(uxModule, uxSequencer, uxComparator);
                }
            }
        }
    }
};
}

/**
 * @brief Validate ADC routine-source default handlers.
 */
TEST_F(ADC_InterruptRoutineSourceTest, InterruptSourceHandlersExposeExpectedDefaultHandlers)
{
    for(UBase_t uxModule = 0UL; uxModule < (UBase_t) ADC_enMODULE_MAX; ++uxModule)
    {
        for(UBase_t uxSequencer = 0UL; uxSequencer < (UBase_t) ADC_enSEQ_MAX; ++uxSequencer)
        {
            EXPECT_EQ(pvfExpectedSWDefault(uxModule, uxSequencer),
                      ADC_SW__pvfGetIRQSourceHandler((ADC_nMODULE) uxModule,
                                                    (ADC_nSEQUENCER) uxSequencer));

            for(UBase_t uxInterruptType = 0UL; uxInterruptType < (UBase_t) ADC_enINT_TYPE_MAX; ++uxInterruptType)
            {
                EXPECT_EQ(pvfExpectedSequencerDefault(uxModule, uxSequencer, uxInterruptType),
                          ADC_Sequencer__pvfGetIRQSourceHandler((ADC_nMODULE) uxModule,
                                                                (ADC_nSEQUENCER) uxSequencer,
                                                                (ADC_nINT_TYPE) uxInterruptType));
            }

            for(UBase_t uxComparator = 0UL; uxComparator < (UBase_t) ADC_enCOMPARATOR_MAX; ++uxComparator)
            {
                EXPECT_EQ(pvfExpectedComparatorDefault(uxModule, uxSequencer, uxComparator),
                          ADC_Comparator__pvfGetIRQSourceHandler((ADC_nMODULE) uxModule,
                                                                 (ADC_nSEQUENCER) uxSequencer,
                                                                 (ADC_nCOMPARATOR) uxComparator));
            }
        }
    }
}

/**
 * @brief Validate ADC getters reject invalid selections.
 */
TEST_F(ADC_InterruptRoutineSourceTest, InterruptSourceGettersRejectInvalidSelections)
{
    EXPECT_EQ((ADC_pvfIRQSourceHandler_t) nullptr,
              ADC_SW__pvfGetIRQSourceHandler((ADC_nMODULE) ADC_enMODULE_MAX,
                                            (ADC_nSEQUENCER) 0UL));
    EXPECT_EQ((ADC_pvfIRQSourceHandler_t) nullptr,
              ADC_SW__pvfGetIRQSourceHandler((ADC_nMODULE) 0UL,
                                            (ADC_nSEQUENCER) ADC_enSEQ_MAX));

    EXPECT_EQ((ADC_pvfIRQSourceHandler_t) nullptr,
              ADC_Sequencer__pvfGetIRQSourceHandler((ADC_nMODULE) ADC_enMODULE_MAX,
                                                   (ADC_nSEQUENCER) 0UL,
                                                   (ADC_nINT_TYPE) 0UL));
    EXPECT_EQ((ADC_pvfIRQSourceHandler_t) nullptr,
              ADC_Sequencer__pvfGetIRQSourceHandler((ADC_nMODULE) 0UL,
                                                   (ADC_nSEQUENCER) ADC_enSEQ_MAX,
                                                   (ADC_nINT_TYPE) 0UL));
    EXPECT_EQ((ADC_pvfIRQSourceHandler_t) nullptr,
              ADC_Sequencer__pvfGetIRQSourceHandler((ADC_nMODULE) 0UL,
                                                   (ADC_nSEQUENCER) 0UL,
                                                   (ADC_nINT_TYPE) ADC_enINT_TYPE_MAX));

    EXPECT_EQ((ADC_pvfIRQSourceHandler_t) nullptr,
              ADC_Comparator__pvfGetIRQSourceHandler((ADC_nMODULE) ADC_enMODULE_MAX,
                                                    (ADC_nSEQUENCER) 0UL,
                                                    (ADC_nCOMPARATOR) 0UL));
    EXPECT_EQ((ADC_pvfIRQSourceHandler_t) nullptr,
              ADC_Comparator__pvfGetIRQSourceHandler((ADC_nMODULE) 0UL,
                                                    (ADC_nSEQUENCER) ADC_enSEQ_MAX,
                                                    (ADC_nCOMPARATOR) 0UL));
    EXPECT_EQ((ADC_pvfIRQSourceHandler_t) nullptr,
              ADC_Comparator__pvfGetIRQSourceHandler((ADC_nMODULE) 0UL,
                                                    (ADC_nSEQUENCER) 0UL,
                                                    (ADC_nCOMPARATOR) ADC_enCOMPARATOR_MAX));
}

/**
 * @brief Validate ADC pointer helpers reject invalid selections.
 */
TEST_F(ADC_InterruptRoutineSourceTest, InterruptSourceHandlerPointersRejectInvalidSelections)
{
    EXPECT_EQ(nullptr,
              ADC_SW__pvfGetIRQSourceHandlerPointer((ADC_nMODULE) ADC_enMODULE_MAX,
                                                   (ADC_nSEQUENCER) 0UL));
    EXPECT_EQ(nullptr,
              ADC_SW__pvfGetIRQSourceHandlerPointer((ADC_nMODULE) 0UL,
                                                   (ADC_nSEQUENCER) ADC_enSEQ_MAX));

    EXPECT_EQ(nullptr,
              ADC_Sequencer__pvfGetIRQSourceHandlerPointer((ADC_nMODULE) ADC_enMODULE_MAX,
                                                          (ADC_nSEQUENCER) 0UL,
                                                          (ADC_nINT_TYPE) 0UL));
    EXPECT_EQ(nullptr,
              ADC_Sequencer__pvfGetIRQSourceHandlerPointer((ADC_nMODULE) 0UL,
                                                          (ADC_nSEQUENCER) ADC_enSEQ_MAX,
                                                          (ADC_nINT_TYPE) 0UL));
    EXPECT_EQ(nullptr,
              ADC_Sequencer__pvfGetIRQSourceHandlerPointer((ADC_nMODULE) 0UL,
                                                          (ADC_nSEQUENCER) 0UL,
                                                          (ADC_nINT_TYPE) ADC_enINT_TYPE_MAX));

    EXPECT_EQ(nullptr,
              ADC_Comparator__pvfGetIRQSourceHandlerPointer((ADC_nMODULE) ADC_enMODULE_MAX,
                                                           (ADC_nSEQUENCER) 0UL,
                                                           (ADC_nCOMPARATOR) 0UL));
    EXPECT_EQ(nullptr,
              ADC_Comparator__pvfGetIRQSourceHandlerPointer((ADC_nMODULE) 0UL,
                                                           (ADC_nSEQUENCER) ADC_enSEQ_MAX,
                                                           (ADC_nCOMPARATOR) 0UL));
    EXPECT_EQ(nullptr,
              ADC_Comparator__pvfGetIRQSourceHandlerPointer((ADC_nMODULE) 0UL,
                                                           (ADC_nSEQUENCER) 0UL,
                                                           (ADC_nCOMPARATOR) ADC_enCOMPARATOR_MAX));
}

/**
 * @brief Validate ADC pointer helpers expose writable slots.
 */
TEST_F(ADC_InterruptRoutineSourceTest, InterruptSourceHandlerPointersExposeWritableSlots)
{
    ADC_pvfIRQSourceHandler_t* pvfSwHandlerReg;
    ADC_pvfIRQSourceHandler_t* pvfSequencerHandlerReg;
    ADC_pvfIRQSourceHandler_t* pvfComparatorHandlerReg;
    const UBase_t uxBoundarySequencer = ((UBase_t) ADC_enSEQ_MAX) - 1UL;

    pvfSwHandlerReg = ADC_SW__pvfGetIRQSourceHandlerPointer((ADC_nMODULE) 0UL,
                                                            (ADC_nSEQUENCER) 0UL);
    pvfSequencerHandlerReg = ADC_Sequencer__pvfGetIRQSourceHandlerPointer((ADC_nMODULE) 1UL,
                                                                          (ADC_nSEQUENCER) uxBoundarySequencer,
                                                                          (ADC_nINT_TYPE) 0UL);
    pvfComparatorHandlerReg = ADC_Comparator__pvfGetIRQSourceHandlerPointer((ADC_nMODULE) 0UL,
                                                                            (ADC_nSEQUENCER) 0UL,
                                                                            (ADC_nCOMPARATOR) 0UL);

    ASSERT_NE(nullptr, pvfSwHandlerReg);
    ASSERT_NE(nullptr, pvfSequencerHandlerReg);
    ASSERT_NE(nullptr, pvfComparatorHandlerReg);

    EXPECT_EQ(pvfExpectedSWDefault(0UL, 0UL), *pvfSwHandlerReg);
    EXPECT_EQ(pvfExpectedSequencerDefault(1UL, uxBoundarySequencer, 0UL), *pvfSequencerHandlerReg);
    EXPECT_EQ(pvfExpectedComparatorDefault(0UL, 0UL, 0UL), *pvfComparatorHandlerReg);

    *pvfSwHandlerReg = &TM4C129E_DriverLib_Test__vCustomADCIRQSourceHandler;
    *pvfSequencerHandlerReg = &TM4C129E_DriverLib_Test__vCustomADCIRQSourceHandler;
    *pvfComparatorHandlerReg = &TM4C129E_DriverLib_Test__vCustomADCIRQSourceHandler;

    EXPECT_EQ(&TM4C129E_DriverLib_Test__vCustomADCIRQSourceHandler,
              ADC_SW__pvfGetIRQSourceHandler((ADC_nMODULE) 0UL,
                                            (ADC_nSEQUENCER) 0UL));
    EXPECT_EQ(&TM4C129E_DriverLib_Test__vCustomADCIRQSourceHandler,
              ADC_Sequencer__pvfGetIRQSourceHandler((ADC_nMODULE) 1UL,
                                                   (ADC_nSEQUENCER) uxBoundarySequencer,
                                                   (ADC_nINT_TYPE) 0UL));
    EXPECT_EQ(&TM4C129E_DriverLib_Test__vCustomADCIRQSourceHandler,
              ADC_Comparator__pvfGetIRQSourceHandler((ADC_nMODULE) 0UL,
                                                    (ADC_nSEQUENCER) 0UL,
                                                    (ADC_nCOMPARATOR) 0UL));
}