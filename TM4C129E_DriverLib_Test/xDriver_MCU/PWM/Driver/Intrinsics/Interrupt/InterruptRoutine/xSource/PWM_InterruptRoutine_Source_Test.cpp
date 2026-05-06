/**
 *
 * @file PWM_InterruptRoutine_Source_Test.cpp
 * @copyright
 * @verbatim InDeviceMex 2026 @endverbatim
 */

extern "C"
{
#include <xDriver_MCU/Common/xHeader/MCU_Variables.h>
#include <xDriver_MCU/PWM/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/PWM_InterruptRoutine_Source.h>

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

void TM4C129E_DriverLib_Test__vCustomPWMIRQSourceHandler(uintptr_t uptrModuleArg, void* pvArgument)
{
    (void) uptrModuleArg;
    (void) pvArgument;
}
}

#include <gtest/gtest.h>

namespace
{
class PWM_InterruptRoutineSourceTest : public ::testing::Test
{
protected:
    static PWM_pvfIRQSourceHandler_t pvfExpectedDefault(UBase_t uxModule, UBase_t uxSelector)
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
        for(UBase_t uxModule = 0UL; uxModule < (UBase_t) PWM_enMODULE_MAX; ++uxModule)
        {
            PWM_pvfIRQSourceHandler_t* pvfFaultSWHandlerReg;

            pvfFaultSWHandlerReg = PWM_FaultSW__pvfGetIRQSourceHandlerPointer((PWM_nMODULE) uxModule);
            ASSERT_NE(nullptr, pvfFaultSWHandlerReg);
            *pvfFaultSWHandlerReg = pvfExpectedDefault(uxModule, 0UL);

            for(UBase_t uxGenerator = 0UL; uxGenerator < (UBase_t) PWM_enGEN_MAX; ++uxGenerator)
            {
                for(UBase_t uxEvent = 0UL; uxEvent < (UBase_t) PWM_enEVENT_MAX; ++uxEvent)
                {
                    PWM_pvfIRQSourceHandler_t* pvfGeneratorHandlerReg;

                    pvfGeneratorHandlerReg = PWM_Generator__pvfGetIRQSourceHandlerPointer((PWM_nMODULE) uxModule,
                                                                                          (PWM_nGENERATOR) uxGenerator,
                                                                                          (PWM_nEVENT) uxEvent);
                    ASSERT_NE(nullptr, pvfGeneratorHandlerReg);
                    *pvfGeneratorHandlerReg = pvfExpectedDefault(uxModule, uxEvent);
                }

                for(UBase_t uxInput = 0UL; uxInput < (UBase_t) PWM_enFAULT_INPUT_MAX; ++uxInput)
                {
                    PWM_pvfIRQSourceHandler_t* pvfFaultInputHandlerReg;

                    pvfFaultInputHandlerReg = PWM_FaultInput__pvfGetIRQSourceHandlerPointer((PWM_nMODULE) uxModule,
                                                                                            (PWM_nGENERATOR) uxGenerator,
                                                                                            (PWM_nFAULT_INPUT) uxInput);
                    ASSERT_NE(nullptr, pvfFaultInputHandlerReg);
                    *pvfFaultInputHandlerReg = pvfExpectedDefault(uxModule, uxInput);
                }

                for(UBase_t uxDComp = 0UL; uxDComp < (UBase_t) PWM_enFAULT_DCOMP_MAX; ++uxDComp)
                {
                    PWM_pvfIRQSourceHandler_t* pvfFaultDCompHandlerReg;

                    pvfFaultDCompHandlerReg = PWM_FaultDComp__pvfGetIRQSourceHandlerPointer((PWM_nMODULE) uxModule,
                                                                                            (PWM_nGENERATOR) uxGenerator,
                                                                                            (PWM_nFAULT_DCOMP) uxDComp);
                    ASSERT_NE(nullptr, pvfFaultDCompHandlerReg);
                    *pvfFaultDCompHandlerReg = pvfExpectedDefault(uxModule, uxDComp);
                }
            }
        }
    }
};
}

/**
 * @brief Validate PWM routine-source default handlers.
 */
TEST_F(PWM_InterruptRoutineSourceTest, InterruptSourceHandlersExposeExpectedDefaultHandlers)
{
    for(UBase_t uxModule = 0UL; uxModule < (UBase_t) PWM_enMODULE_MAX; ++uxModule)
    {
        EXPECT_EQ(pvfExpectedDefault(uxModule, 0UL),
                  PWM_FaultSW__pvfGetIRQSourceHandler((PWM_nMODULE) uxModule));

        for(UBase_t uxGenerator = 0UL; uxGenerator < (UBase_t) PWM_enGEN_MAX; ++uxGenerator)
        {
            for(UBase_t uxEvent = 0UL; uxEvent < (UBase_t) PWM_enEVENT_MAX; ++uxEvent)
            {
                EXPECT_EQ(pvfExpectedDefault(uxModule, uxEvent),
                          PWM_Generator__pvfGetIRQSourceHandler((PWM_nMODULE) uxModule,
                                                                (PWM_nGENERATOR) uxGenerator,
                                                                (PWM_nEVENT) uxEvent));
            }

            for(UBase_t uxInput = 0UL; uxInput < (UBase_t) PWM_enFAULT_INPUT_MAX; ++uxInput)
            {
                EXPECT_EQ(pvfExpectedDefault(uxModule, uxInput),
                          PWM_FaultInput__pvfGetIRQSourceHandler((PWM_nMODULE) uxModule,
                                                                 (PWM_nGENERATOR) uxGenerator,
                                                                 (PWM_nFAULT_INPUT) uxInput));
            }

            for(UBase_t uxDComp = 0UL; uxDComp < (UBase_t) PWM_enFAULT_DCOMP_MAX; ++uxDComp)
            {
                EXPECT_EQ(pvfExpectedDefault(uxModule, uxDComp),
                          PWM_FaultDComp__pvfGetIRQSourceHandler((PWM_nMODULE) uxModule,
                                                                 (PWM_nGENERATOR) uxGenerator,
                                                                 (PWM_nFAULT_DCOMP) uxDComp));
            }
        }
    }
}

/**
 * @brief Validate PWM getters reject invalid selections.
 */
TEST_F(PWM_InterruptRoutineSourceTest, InterruptSourceGettersRejectInvalidSelections)
{
    EXPECT_EQ((PWM_pvfIRQSourceHandler_t) nullptr,
              PWM_Generator__pvfGetIRQSourceHandler((PWM_nMODULE) PWM_enMODULE_MAX,
                                                   (PWM_nGENERATOR) 0UL,
                                                   (PWM_nEVENT) 0UL));
    EXPECT_EQ((PWM_pvfIRQSourceHandler_t) nullptr,
              PWM_Generator__pvfGetIRQSourceHandler((PWM_nMODULE) 0UL,
                                                   (PWM_nGENERATOR) PWM_enGEN_MAX,
                                                   (PWM_nEVENT) 0UL));
    EXPECT_EQ((PWM_pvfIRQSourceHandler_t) nullptr,
              PWM_Generator__pvfGetIRQSourceHandler((PWM_nMODULE) 0UL,
                                                   (PWM_nGENERATOR) 0UL,
                                                   (PWM_nEVENT) PWM_enEVENT_MAX));

    EXPECT_EQ((PWM_pvfIRQSourceHandler_t) nullptr,
              PWM_FaultSW__pvfGetIRQSourceHandler((PWM_nMODULE) PWM_enMODULE_MAX));

    EXPECT_EQ((PWM_pvfIRQSourceHandler_t) nullptr,
              PWM_FaultInput__pvfGetIRQSourceHandler((PWM_nMODULE) PWM_enMODULE_MAX,
                                                    (PWM_nGENERATOR) 0UL,
                                                    (PWM_nFAULT_INPUT) 0UL));
    EXPECT_EQ((PWM_pvfIRQSourceHandler_t) nullptr,
              PWM_FaultInput__pvfGetIRQSourceHandler((PWM_nMODULE) 0UL,
                                                    (PWM_nGENERATOR) PWM_enGEN_MAX,
                                                    (PWM_nFAULT_INPUT) 0UL));
    EXPECT_EQ((PWM_pvfIRQSourceHandler_t) nullptr,
              PWM_FaultInput__pvfGetIRQSourceHandler((PWM_nMODULE) 0UL,
                                                    (PWM_nGENERATOR) 0UL,
                                                    (PWM_nFAULT_INPUT) PWM_enFAULT_INPUT_MAX));

    EXPECT_EQ((PWM_pvfIRQSourceHandler_t) nullptr,
              PWM_FaultDComp__pvfGetIRQSourceHandler((PWM_nMODULE) PWM_enMODULE_MAX,
                                                    (PWM_nGENERATOR) 0UL,
                                                    (PWM_nFAULT_DCOMP) 0UL));
    EXPECT_EQ((PWM_pvfIRQSourceHandler_t) nullptr,
              PWM_FaultDComp__pvfGetIRQSourceHandler((PWM_nMODULE) 0UL,
                                                    (PWM_nGENERATOR) PWM_enGEN_MAX,
                                                    (PWM_nFAULT_DCOMP) 0UL));
    EXPECT_EQ((PWM_pvfIRQSourceHandler_t) nullptr,
              PWM_FaultDComp__pvfGetIRQSourceHandler((PWM_nMODULE) 0UL,
                                                    (PWM_nGENERATOR) 0UL,
                                                    (PWM_nFAULT_DCOMP) PWM_enFAULT_DCOMP_MAX));
}

/**
 * @brief Validate PWM pointer helpers reject invalid selections.
 */
TEST_F(PWM_InterruptRoutineSourceTest, InterruptSourceHandlerPointersRejectInvalidSelections)
{
    EXPECT_EQ(nullptr,
              PWM_Generator__pvfGetIRQSourceHandlerPointer((PWM_nMODULE) PWM_enMODULE_MAX,
                                                          (PWM_nGENERATOR) 0UL,
                                                          (PWM_nEVENT) 0UL));
    EXPECT_EQ(nullptr,
              PWM_Generator__pvfGetIRQSourceHandlerPointer((PWM_nMODULE) 0UL,
                                                          (PWM_nGENERATOR) PWM_enGEN_MAX,
                                                          (PWM_nEVENT) 0UL));
    EXPECT_EQ(nullptr,
              PWM_Generator__pvfGetIRQSourceHandlerPointer((PWM_nMODULE) 0UL,
                                                          (PWM_nGENERATOR) 0UL,
                                                          (PWM_nEVENT) PWM_enEVENT_MAX));

    EXPECT_EQ(nullptr,
              PWM_FaultSW__pvfGetIRQSourceHandlerPointer((PWM_nMODULE) PWM_enMODULE_MAX));

    EXPECT_EQ(nullptr,
              PWM_FaultInput__pvfGetIRQSourceHandlerPointer((PWM_nMODULE) PWM_enMODULE_MAX,
                                                           (PWM_nGENERATOR) 0UL,
                                                           (PWM_nFAULT_INPUT) 0UL));
    EXPECT_EQ(nullptr,
              PWM_FaultInput__pvfGetIRQSourceHandlerPointer((PWM_nMODULE) 0UL,
                                                           (PWM_nGENERATOR) PWM_enGEN_MAX,
                                                           (PWM_nFAULT_INPUT) 0UL));
    EXPECT_EQ(nullptr,
              PWM_FaultInput__pvfGetIRQSourceHandlerPointer((PWM_nMODULE) 0UL,
                                                           (PWM_nGENERATOR) 0UL,
                                                           (PWM_nFAULT_INPUT) PWM_enFAULT_INPUT_MAX));

    EXPECT_EQ(nullptr,
              PWM_FaultDComp__pvfGetIRQSourceHandlerPointer((PWM_nMODULE) PWM_enMODULE_MAX,
                                                           (PWM_nGENERATOR) 0UL,
                                                           (PWM_nFAULT_DCOMP) 0UL));
    EXPECT_EQ(nullptr,
              PWM_FaultDComp__pvfGetIRQSourceHandlerPointer((PWM_nMODULE) 0UL,
                                                           (PWM_nGENERATOR) PWM_enGEN_MAX,
                                                           (PWM_nFAULT_DCOMP) 0UL));
    EXPECT_EQ(nullptr,
              PWM_FaultDComp__pvfGetIRQSourceHandlerPointer((PWM_nMODULE) 0UL,
                                                           (PWM_nGENERATOR) 0UL,
                                                           (PWM_nFAULT_DCOMP) PWM_enFAULT_DCOMP_MAX));
}

/**
 * @brief Validate PWM pointer helpers expose writable slots.
 */
TEST_F(PWM_InterruptRoutineSourceTest, InterruptSourceHandlerPointersExposeWritableSlots)
{
    PWM_pvfIRQSourceHandler_t* pvfGeneratorHandlerReg;
    PWM_pvfIRQSourceHandler_t* pvfFaultSWHandlerReg;
    PWM_pvfIRQSourceHandler_t* pvfFaultInputHandlerReg;
    PWM_pvfIRQSourceHandler_t* pvfFaultDCompHandlerReg;
    const UBase_t uxBoundaryEvent = ((UBase_t) PWM_enEVENT_MAX) - 1UL;

    pvfGeneratorHandlerReg = PWM_Generator__pvfGetIRQSourceHandlerPointer((PWM_nMODULE) 0UL,
                                                                          (PWM_nGENERATOR) 0UL,
                                                                          (PWM_nEVENT) uxBoundaryEvent);
    pvfFaultSWHandlerReg = PWM_FaultSW__pvfGetIRQSourceHandlerPointer((PWM_nMODULE) 0UL);
    pvfFaultInputHandlerReg = PWM_FaultInput__pvfGetIRQSourceHandlerPointer((PWM_nMODULE) 0UL,
                                                                            (PWM_nGENERATOR) 0UL,
                                                                            (PWM_nFAULT_INPUT) 0UL);
    pvfFaultDCompHandlerReg = PWM_FaultDComp__pvfGetIRQSourceHandlerPointer((PWM_nMODULE) 0UL,
                                                                            (PWM_nGENERATOR) 0UL,
                                                                            (PWM_nFAULT_DCOMP) 0UL);

    ASSERT_NE(nullptr, pvfGeneratorHandlerReg);
    ASSERT_NE(nullptr, pvfFaultSWHandlerReg);
    ASSERT_NE(nullptr, pvfFaultInputHandlerReg);
    ASSERT_NE(nullptr, pvfFaultDCompHandlerReg);

    *pvfGeneratorHandlerReg = &TM4C129E_DriverLib_Test__vCustomPWMIRQSourceHandler;
    *pvfFaultSWHandlerReg = &TM4C129E_DriverLib_Test__vCustomPWMIRQSourceHandler;
    *pvfFaultInputHandlerReg = &TM4C129E_DriverLib_Test__vCustomPWMIRQSourceHandler;
    *pvfFaultDCompHandlerReg = &TM4C129E_DriverLib_Test__vCustomPWMIRQSourceHandler;

    EXPECT_EQ(&TM4C129E_DriverLib_Test__vCustomPWMIRQSourceHandler,
              PWM_Generator__pvfGetIRQSourceHandler((PWM_nMODULE) 0UL,
                                                   (PWM_nGENERATOR) 0UL,
                                                   (PWM_nEVENT) uxBoundaryEvent));
    EXPECT_EQ(&TM4C129E_DriverLib_Test__vCustomPWMIRQSourceHandler,
              PWM_FaultSW__pvfGetIRQSourceHandler((PWM_nMODULE) 0UL));
    EXPECT_EQ(&TM4C129E_DriverLib_Test__vCustomPWMIRQSourceHandler,
              PWM_FaultInput__pvfGetIRQSourceHandler((PWM_nMODULE) 0UL,
                                                    (PWM_nGENERATOR) 0UL,
                                                    (PWM_nFAULT_INPUT) 0UL));
    EXPECT_EQ(&TM4C129E_DriverLib_Test__vCustomPWMIRQSourceHandler,
              PWM_FaultDComp__pvfGetIRQSourceHandler((PWM_nMODULE) 0UL,
                                                    (PWM_nGENERATOR) 0UL,
                                                    (PWM_nFAULT_DCOMP) 0UL));
}