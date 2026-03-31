/**
 *
 * @file SCB_SleepMode_Test.cpp
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
 * @verbatim 29 mar. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 29 mar. 2026   GitHub Copilot   1.0         initial Version@endverbatim
 */

extern "C"
{
#include <xDriver_MCU/Core/SCB/Driver/xHeader/SCB_SleepMode.h>
#include <xDriver_MCU/Core/SCB/Peripheral/Register/xHeader/SCB_RegisterAddress.h>
#include <xDriver_MCU/Core/SCB/Peripheral/Register/RegisterDefines/SCB_RegisterDefines.h>
}

#include <tm4c129e_test/SCB_DriverMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::InSequence;
using ::testing::Invoke;
using ::testing::Return;
using ::testing::StrictMock;

/**
 * @brief Validate sleep-mode write field selection.
 * @summary Confirms that `SCB__enSetSleepMode` writes the SCR SLEEPDEEP field
 *          with the expected address, mask, shift, and enum value.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SCB_DriverMock bridge
 * - Original source under test: SCB_SleepMode.c@endverbatim
 */
TEST(SCB_SleepModeTest, SetSleepModeUsesSleepDeepField)
{
    StrictMock<SCB_DriverMock> stMock;
    SCB_DriverMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WriteRegister(SCB_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SCB_nMODULE enModuleArg, SCB_Register_t* pstRegisterDataArg) -> SCB_nERROR
        {
            EXPECT_EQ(SCB_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SCB_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SCB_SCR_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) SCB_SCR_SLEEPDEEP_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) SCB_SCR_R_SLEEPDEEP_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) SCB_enSLEEPMODE_DEEPSLEEP, pstRegisterDataArg->uxValue);
            return SCB_enERROR_OK;
        }));

    EXPECT_EQ(SCB_enERROR_OK,
              SCB__enSetSleepMode(SCB_enMODULE_0, SCB_enSLEEPMODE_DEEPSLEEP));
}

/**
 * @brief Validate sleep-mode read mask and shift behavior.
 * @summary Confirms that `SCB__enGetSleepMode` reads the SCR SLEEPDEEP field
 *          with the expected address, mask, and shift and returns the enum value
 *          from the primitive read seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SCB_DriverMock bridge
 * - Original source under test: SCB_SleepMode.c@endverbatim
 */
TEST(SCB_SleepModeTest, GetSleepModeUsesSleepDeepField)
{
    StrictMock<SCB_DriverMock> stMock;
    SCB_DriverMockScope stMockScope(&stMock);
    SCB_nSLEEPMODE enSleepModeReg;

    enSleepModeReg = SCB_enSLEEPMODE_UNDEF;

    EXPECT_CALL(stMock, ReadRegister(SCB_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SCB_nMODULE enModuleArg, SCB_Register_t* pstRegisterDataArg) -> SCB_nERROR
        {
            EXPECT_EQ(SCB_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SCB_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SCB_SCR_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) SCB_SCR_SLEEPDEEP_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) SCB_SCR_R_SLEEPDEEP_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) SCB_enSLEEPMODE_SLEEP;
            return SCB_enERROR_OK;
        }));

    EXPECT_EQ(SCB_enERROR_OK,
              SCB__enGetSleepMode(SCB_enMODULE_0, &enSleepModeReg));
    EXPECT_EQ(SCB_enSLEEPMODE_SLEEP, enSleepModeReg);
}

/**
 * @brief Validate sleep entry ordering for deep sleep.
 * @summary Confirms that `SCB__enEnterDeepSleep` first programs deep-sleep mode
 *          through the write seam and then executes the wait-for-interrupt hook.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SCB_DriverMock bridge
 * - Original source under test: SCB_SleepMode.c@endverbatim
 */
TEST(SCB_SleepModeTest, EnterDeepSleepProgramsModeBeforeWaiting)
{
    StrictMock<SCB_DriverMock> stMock;
    SCB_DriverMockScope stMockScope(&stMock);
    InSequence stSequence;

    EXPECT_CALL(stMock, WriteRegister(SCB_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SCB_nMODULE enModuleArg, SCB_Register_t* pstRegisterDataArg) -> SCB_nERROR
        {
            EXPECT_EQ(SCB_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SCB_enERROR_POINTER;
            }
            EXPECT_EQ((UBase_t) SCB_enSLEEPMODE_DEEPSLEEP, pstRegisterDataArg->uxValue);
            return SCB_enERROR_OK;
        }));
    EXPECT_CALL(stMock, WaitForInterrupt());

    EXPECT_EQ(SCB_enERROR_OK,
              SCB__enEnterDeepSleep(SCB_enMODULE_0));
}

/**
 * @brief Validate sleep-on-exit field access.
 * @summary Confirms that the set/get sleep-on-exit helpers use the SCR
 *          SLEEPONEXIT field with the expected address, mask, and shift.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SCB_DriverMock bridge
 * - Original source under test: SCB_SleepMode.c@endverbatim
 */
TEST(SCB_SleepModeTest, SleepOnExitUsesExpectedField)
{
    StrictMock<SCB_DriverMock> stMock;
    SCB_DriverMockScope stMockScope(&stMock);
    SCB_nSLEEPONEXIT enSleepOnExitReg;

    enSleepOnExitReg = SCB_enSLEEPONEXIT_UNDEF;

    EXPECT_CALL(stMock, WriteRegister(SCB_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SCB_nMODULE enModuleArg, SCB_Register_t* pstRegisterDataArg) -> SCB_nERROR
        {
            EXPECT_EQ(SCB_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SCB_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SCB_SCR_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) SCB_SCR_SLEEPONEXIT_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) SCB_SCR_R_SLEEPONEXIT_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) SCB_enSLEEPONEXIT_SLEEP, pstRegisterDataArg->uxValue);
            return SCB_enERROR_OK;
        }));
    EXPECT_CALL(stMock, ReadRegister(SCB_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SCB_nMODULE enModuleArg, SCB_Register_t* pstRegisterDataArg) -> SCB_nERROR
        {
            EXPECT_EQ(SCB_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SCB_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SCB_SCR_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) SCB_SCR_SLEEPONEXIT_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) SCB_SCR_R_SLEEPONEXIT_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) SCB_enSLEEPONEXIT_SLEEP;
            return SCB_enERROR_OK;
        }));

    EXPECT_EQ(SCB_enERROR_OK,
              SCB__enSetSleepOnExit(SCB_enMODULE_0, SCB_enSLEEPONEXIT_SLEEP));
    EXPECT_EQ(SCB_enERROR_OK,
              SCB__enGetSleepOnExit(SCB_enMODULE_0, &enSleepOnExitReg));
    EXPECT_EQ(SCB_enSLEEPONEXIT_SLEEP, enSleepOnExitReg);
}