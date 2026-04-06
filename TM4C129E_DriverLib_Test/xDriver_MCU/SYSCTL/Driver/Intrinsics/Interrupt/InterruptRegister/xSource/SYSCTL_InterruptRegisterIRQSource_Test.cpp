/**
 *
 * @file SYSCTL_InterruptRegisterIRQSource_Test.cpp
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
 * @verbatim 5 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 5 abr. 2026    GitHub Copilot   1.0         initial Version@endverbatim
 */

extern "C"
{
#include <xDriver_MCU/Common/xHeader/MCU_Variables.h>
#include <xDriver_MCU/SYSCTL/Driver/Intrinsics/Interrupt/InterruptRegister/xHeader/SYSCTL_InterruptRegisterIRQSource.h>
#include <xDriver_MCU/SYSCTL/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/SYSCTL_InterruptRoutine_Source.h>

void MCU_vIRQSourceHandler_Dummy(uintptr_t uptrModuleArg, void* pvArgument)
{
    (void) uptrModuleArg;
    (void) pvArgument;
}

void TM4C129E_DriverLib_Test__vCustomSYSCTLIRQSourceHandler(uintptr_t uptrModuleArg, void* pvArgument)
{
    (void) uptrModuleArg;
    (void) pvArgument;
}
}

#include <cstdint>

#include <gtest/gtest.h>

namespace
{
std::uintptr_t TM4C129E_DriverLib_Test__uptrCastIRQSourceHandler(SYSCTL_pvfIRQSourceHandler_t pvfHandler)
{
    return reinterpret_cast<std::uintptr_t>(pvfHandler);
}

std::uintptr_t TM4C129E_DriverLib_Test__uptrExpectedEncodedIRQSourceHandler(SYSCTL_pvfIRQSourceHandler_t pvfHandler)
{
    UBase_t uxExpectedHandler;

    uxExpectedHandler = (UBase_t) reinterpret_cast<std::uintptr_t>(pvfHandler);
    uxExpectedHandler |= 1UL;
    return (std::uintptr_t) uxExpectedHandler;
}

class SYSCTL_InterruptRegisterIRQSourceTest : public ::testing::Test
{
protected:
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
        for(UBase_t uxInterruptSource = 0UL; uxInterruptSource < (UBase_t) SYSCTL_enINT_MAX; ++uxInterruptSource)
        {
            SYSCTL_pvfIRQSourceHandler_t* pvfHandlerReg;

            pvfHandlerReg = SYSCTL__pvfGetIRQSourceHandlerPointer(SYSCTL_enMODULE_0,
                                                                  (SYSCTL_nINT) uxInterruptSource);
            ASSERT_NE(nullptr, pvfHandlerReg);
            *pvfHandlerReg = &MCU_vIRQSourceHandler_Dummy;
        }
    }
};
}

/**
 * @brief Validate module-range rejection in the SYSCTL source registration helper.
 * @summary Confirms that `SYSCTL__enRegisterIRQSourceHandler` stops at module
 *          validation when the caller selects an out-of-range SYSCTL module and
 *          leaves the existing source slot untouched.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original sources under test: SYSCTL_InterruptRegisterIRQSource.c,
 *   SYSCTL_InterruptRoutine_Source.c, MCU_CheckParams.c, and
 *   MCU_RegisterSourceIRQ.c
 * - Local non-blocking dummy symbol for MCU_vIRQSourceHandler_Dummy@endverbatim
 */
TEST_F(SYSCTL_InterruptRegisterIRQSourceTest, RegisterIRQSourceRejectsInvalidModule)
{
    EXPECT_EQ(SYSCTL_enERROR_RANGE,
              SYSCTL__enRegisterIRQSourceHandler(SYSCTL_enMODULE_MAX,
                                                 SYSCTL_enINT_BOR,
                                                 &TM4C129E_DriverLib_Test__vCustomSYSCTLIRQSourceHandler));
    EXPECT_EQ(&MCU_vIRQSourceHandler_Dummy,
              SYSCTL__pvfGetIRQSourceHandler(SYSCTL_enMODULE_0,
                                            SYSCTL_enINT_BOR));
}

/**
 * @brief Validate source-range rejection in the SYSCTL source registration helper.
 * @summary Confirms that `SYSCTL__enRegisterIRQSourceHandler` rejects an
 *          out-of-range SYSCTL interrupt-source selector before it reaches the
 *          backing handler-table slot.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original sources under test: SYSCTL_InterruptRegisterIRQSource.c,
 *   SYSCTL_InterruptRoutine_Source.c, MCU_CheckParams.c, and
 *   MCU_RegisterSourceIRQ.c
 * - Local non-blocking dummy symbol for MCU_vIRQSourceHandler_Dummy@endverbatim
 */
TEST_F(SYSCTL_InterruptRegisterIRQSourceTest, RegisterIRQSourceRejectsInvalidInterruptSource)
{
    EXPECT_EQ(SYSCTL_enERROR_RANGE,
              SYSCTL__enRegisterIRQSourceHandler(SYSCTL_enMODULE_0,
                                                 SYSCTL_enINT_MAX,
                                                 &TM4C129E_DriverLib_Test__vCustomSYSCTLIRQSourceHandler));
    EXPECT_EQ(&MCU_vIRQSourceHandler_Dummy,
              SYSCTL__pvfGetIRQSourceHandler(SYSCTL_enMODULE_0,
                                            SYSCTL_enINT_MOSC_FAILURE));
}

/**
 * @brief Validate null-handler propagation in the SYSCTL source registration helper.
 * @summary Confirms that a null SYSCTL source handler is rejected through the
 *          shared MCU registration primitive and that the previously installed
 *          handler remains unchanged for the selected source slot.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original sources under test: SYSCTL_InterruptRegisterIRQSource.c,
 *   SYSCTL_InterruptRoutine_Source.c, MCU_CheckParams.c, and
 *   MCU_RegisterSourceIRQ.c
 * - Local non-blocking dummy symbol for MCU_vIRQSourceHandler_Dummy@endverbatim
 */
TEST_F(SYSCTL_InterruptRegisterIRQSourceTest, RegisterIRQSourceRejectsNullHandlerPointerWithoutClobberingExistingSlot)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enRegisterIRQSourceHandler(SYSCTL_enMODULE_0,
                                                 SYSCTL_enINT_PLL_LOCK,
                                                 nullptr));
    EXPECT_EQ(&MCU_vIRQSourceHandler_Dummy,
              SYSCTL__pvfGetIRQSourceHandler(SYSCTL_enMODULE_0,
                                            SYSCTL_enINT_PLL_LOCK));
}

/**
 * @brief Validate successful registration into the selected SYSCTL source slot.
 * @summary Confirms that `SYSCTL__enRegisterIRQSourceHandler` stores the MCU
 *          encoded handler value into the requested SYSCTL source slot and does
 *          not disturb neighboring source entries in the same handler table.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original sources under test: SYSCTL_InterruptRegisterIRQSource.c,
 *   SYSCTL_InterruptRoutine_Source.c, MCU_CheckParams.c, and
 *   MCU_RegisterSourceIRQ.c
 * - Local non-blocking dummy symbol for MCU_vIRQSourceHandler_Dummy@endverbatim
 */
TEST_F(SYSCTL_InterruptRegisterIRQSourceTest, RegisterIRQSourceStoresEncodedHandlerInSelectedSlotOnly)
{
    const std::uintptr_t uptrExpectedHandler =
        TM4C129E_DriverLib_Test__uptrExpectedEncodedIRQSourceHandler(
            &TM4C129E_DriverLib_Test__vCustomSYSCTLIRQSourceHandler);

    ASSERT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enRegisterIRQSourceHandler(SYSCTL_enMODULE_0,
                                                 SYSCTL_enINT_MOSC_POWERUP,
                                                 &TM4C129E_DriverLib_Test__vCustomSYSCTLIRQSourceHandler));
    EXPECT_EQ(uptrExpectedHandler,
              TM4C129E_DriverLib_Test__uptrCastIRQSourceHandler(
                      SYSCTL__pvfGetIRQSourceHandler(SYSCTL_enMODULE_0,
                                                    SYSCTL_enINT_MOSC_POWERUP)));
    EXPECT_EQ(reinterpret_cast<std::uintptr_t>(&MCU_vIRQSourceHandler_Dummy),
              TM4C129E_DriverLib_Test__uptrCastIRQSourceHandler(
                      SYSCTL__pvfGetIRQSourceHandler(SYSCTL_enMODULE_0,
                                                    SYSCTL_enINT_BOR)));
}