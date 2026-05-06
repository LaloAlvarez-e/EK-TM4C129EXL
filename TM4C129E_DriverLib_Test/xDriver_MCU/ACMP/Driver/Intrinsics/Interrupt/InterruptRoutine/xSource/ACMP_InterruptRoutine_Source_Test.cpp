/**
 *
 * @file ACMP_InterruptRoutine_Source_Test.cpp
 * @copyright
 * @verbatim InDeviceMex 2026 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 5 may. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 5 may. 2026    GitHub Copilot   1.0         initial Version@endverbatim
 */

extern "C"
{
#include <xDriver_MCU/Common/xHeader/MCU_Variables.h>
#include <xDriver_MCU/ACMP/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/ACMP_InterruptRoutine_Source.h>

void MCU_vIRQSourceHandler_Dummy(uintptr_t uptrModuleArg, void* pvArgument)
{
    (void) uptrModuleArg;
    (void) pvArgument;
}

void TM4C129E_DriverLib_Test__vCustomACMPIRQSourceHandler(uintptr_t uptrModuleArg, void* pvArgument)
{
    (void) uptrModuleArg;
    (void) pvArgument;
}
}

#include <gtest/gtest.h>

namespace
{
class ACMP_InterruptRoutineSourceTest : public ::testing::Test
{
protected:
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
        for(UBase_t uxModule = 0UL; uxModule < (UBase_t) ACMP_enMODULE_MAX; ++uxModule)
        {
            for(UBase_t uxComparator = 0UL; uxComparator < (UBase_t) ACMP_enCOMP_MAX; ++uxComparator)
            {
                ACMP_pvfIRQSourceHandler_t* pvfSwHandlerReg;
                ACMP_pvfIRQSourceHandler_t* pvfComparatorHandlerReg;

                pvfSwHandlerReg = ACMP_SW__pvfGetIRQSourceHandlerPointer((ACMP_nMODULE) uxModule,
                                                                        (ACMP_nCOMP) uxComparator);
                pvfComparatorHandlerReg = ACMP__pvfGetIRQSourceHandlerPointer((ACMP_nMODULE) uxModule,
                                                                              (ACMP_nCOMP) uxComparator);

                ASSERT_NE(nullptr, pvfSwHandlerReg);
                ASSERT_NE(nullptr, pvfComparatorHandlerReg);

                *pvfSwHandlerReg = &MCU_vIRQSourceHandler_Dummy;
                *pvfComparatorHandlerReg = &MCU_vIRQSourceHandler_Dummy;
            }
        }
    }
};
}

/**
 * @brief Validate ACMP routine-source default handlers.
 * @summary Confirms that the ACMP software and comparator source-handler
 *          getters expose the expected default dummy handler for every valid
 *          module and comparator slot.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: ACMP_InterruptRoutine_Source.c
 * - Local non-blocking dummy symbol for MCU_vIRQSourceHandler_Dummy@endverbatim
 */
TEST_F(ACMP_InterruptRoutineSourceTest, InterruptSourceHandlersExposeExpectedDefaultHandlers)
{
    for(UBase_t uxModule = 0UL; uxModule < (UBase_t) ACMP_enMODULE_MAX; ++uxModule)
    {
        for(UBase_t uxComparator = 0UL; uxComparator < (UBase_t) ACMP_enCOMP_MAX; ++uxComparator)
        {
            EXPECT_EQ(&MCU_vIRQSourceHandler_Dummy,
                      ACMP_SW__pvfGetIRQSourceHandler((ACMP_nMODULE) uxModule,
                                                     (ACMP_nCOMP) uxComparator));
            EXPECT_EQ(&MCU_vIRQSourceHandler_Dummy,
                      ACMP__pvfGetIRQSourceHandler((ACMP_nMODULE) uxModule,
                                                  (ACMP_nCOMP) uxComparator));
        }
    }
}

/**
 * @brief Validate ACMP getters reject invalid selections.
 * @summary Confirms that the ACMP software and comparator source-handler
 *          getters return a null handler when the caller provides a module or
 *          comparator selector outside the public maxima.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: ACMP_InterruptRoutine_Source.c@endverbatim
 */
TEST_F(ACMP_InterruptRoutineSourceTest, InterruptSourceGettersRejectInvalidSelections)
{
    EXPECT_EQ((ACMP_pvfIRQSourceHandler_t) nullptr,
              ACMP_SW__pvfGetIRQSourceHandler((ACMP_nMODULE) ACMP_enMODULE_MAX,
                                             (ACMP_nCOMP) 0UL));
    EXPECT_EQ((ACMP_pvfIRQSourceHandler_t) nullptr,
              ACMP_SW__pvfGetIRQSourceHandler((ACMP_nMODULE) 0UL,
                                             (ACMP_nCOMP) ACMP_enCOMP_MAX));
    EXPECT_EQ((ACMP_pvfIRQSourceHandler_t) nullptr,
              ACMP__pvfGetIRQSourceHandler((ACMP_nMODULE) ACMP_enMODULE_MAX,
                                          (ACMP_nCOMP) 0UL));
    EXPECT_EQ((ACMP_pvfIRQSourceHandler_t) nullptr,
              ACMP__pvfGetIRQSourceHandler((ACMP_nMODULE) 0UL,
                                          (ACMP_nCOMP) ACMP_enCOMP_MAX));
}

/**
 * @brief Validate ACMP pointer helpers reject invalid selections.
 * @summary Confirms that the ACMP software and comparator source-handler
 *          pointer helpers return a null storage pointer when the caller
 *          provides a module or comparator selector outside the public maxima.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: ACMP_InterruptRoutine_Source.c@endverbatim
 */
TEST_F(ACMP_InterruptRoutineSourceTest, InterruptSourceHandlerPointersRejectInvalidSelections)
{
    EXPECT_EQ(nullptr,
              ACMP_SW__pvfGetIRQSourceHandlerPointer((ACMP_nMODULE) ACMP_enMODULE_MAX,
                                                    (ACMP_nCOMP) 0UL));
    EXPECT_EQ(nullptr,
              ACMP_SW__pvfGetIRQSourceHandlerPointer((ACMP_nMODULE) 0UL,
                                                    (ACMP_nCOMP) ACMP_enCOMP_MAX));
    EXPECT_EQ(nullptr,
              ACMP__pvfGetIRQSourceHandlerPointer((ACMP_nMODULE) ACMP_enMODULE_MAX,
                                                 (ACMP_nCOMP) 0UL));
    EXPECT_EQ(nullptr,
              ACMP__pvfGetIRQSourceHandlerPointer((ACMP_nMODULE) 0UL,
                                                 (ACMP_nCOMP) ACMP_enCOMP_MAX));
}

/**
 * @brief Validate ACMP pointer helpers expose writable slots.
 * @summary Confirms that the ACMP software and comparator pointer helpers
 *          expose writable backing storage and that the corresponding getters
 *          reflect updates written through those storage pointers.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: ACMP_InterruptRoutine_Source.c@endverbatim
 */
TEST_F(ACMP_InterruptRoutineSourceTest, InterruptSourceHandlerPointersExposeWritableSlots)
{
    ACMP_pvfIRQSourceHandler_t* pvfSwHandlerReg;
    ACMP_pvfIRQSourceHandler_t* pvfComparatorHandlerReg;

    pvfSwHandlerReg = ACMP_SW__pvfGetIRQSourceHandlerPointer((ACMP_nMODULE) 0UL,
                                                            (ACMP_nCOMP) 0UL);
    pvfComparatorHandlerReg = ACMP__pvfGetIRQSourceHandlerPointer((ACMP_nMODULE) 0UL,
                                                                  (ACMP_nCOMP) 0UL);

    ASSERT_NE(nullptr, pvfSwHandlerReg);
    ASSERT_NE(nullptr, pvfComparatorHandlerReg);

    EXPECT_EQ(&MCU_vIRQSourceHandler_Dummy, *pvfSwHandlerReg);
    EXPECT_EQ(&MCU_vIRQSourceHandler_Dummy, *pvfComparatorHandlerReg);

    *pvfSwHandlerReg = &TM4C129E_DriverLib_Test__vCustomACMPIRQSourceHandler;
    *pvfComparatorHandlerReg = &TM4C129E_DriverLib_Test__vCustomACMPIRQSourceHandler;

    EXPECT_EQ(&TM4C129E_DriverLib_Test__vCustomACMPIRQSourceHandler,
              ACMP_SW__pvfGetIRQSourceHandler((ACMP_nMODULE) 0UL,
                                             (ACMP_nCOMP) 0UL));
    EXPECT_EQ(&TM4C129E_DriverLib_Test__vCustomACMPIRQSourceHandler,
              ACMP__pvfGetIRQSourceHandler((ACMP_nMODULE) 0UL,
                                          (ACMP_nCOMP) 0UL));
}