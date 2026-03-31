/**
 *
 * @file SCB_SoftwareInterruptTrigger_Test.cpp
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
#include <xDriver_MCU/Core/SCB/Driver/xHeader/SCB_SoftwareInterruptTrigger.h>
#include <xDriver_MCU/Core/SCB/Peripheral/Register/xHeader/SCB_RegisterAddress.h>
#include <xDriver_MCU/Core/SCB/Peripheral/Register/RegisterDefines/SCB_RegisterDefines.h>
}

#include <tm4c129e_test/SCB_DriverMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Invoke;
using ::testing::Return;
using ::testing::StrictMock;

/**
 * @brief Validate software-trigger state field programming.
 * @summary Confirms that `SCB__enSetUnprivilegedSWTriggerEnableState` writes the
 *          CCR USERSETMPEND field with the expected address, mask, shift, and
 *          enum value.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SCB_DriverMock bridge
 * - Original source under test: SCB_SoftwareInterruptTrigger.c@endverbatim
 */
TEST(SCB_SoftwareInterruptTriggerTest, SetUnprivilegedSWTriggerUsesExpectedField)
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
            EXPECT_EQ((uintptr_t) SCB_CCR_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) SCB_CCR_USERSETMPEND_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) SCB_CCR_R_USERSETMPEND_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) SCB_enSTATE_ENA, pstRegisterDataArg->uxValue);
            return SCB_enERROR_OK;
        }));

    EXPECT_EQ(SCB_enERROR_OK,
              SCB__enSetUnprivilegedSWTriggerEnableState(SCB_enMODULE_0, SCB_enSTATE_ENA));
}

/**
 * @brief Validate wrapper delegation for enable and disable helpers.
 * @summary Confirms that the enable and disable wrapper helpers reach the same
 *          CCR USERSETMPEND write path with the expected state values.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SCB_DriverMock bridge
 * - Original source under test: SCB_SoftwareInterruptTrigger.c@endverbatim
 */
TEST(SCB_SoftwareInterruptTriggerTest, EnableAndDisableWrappersDelegateToStateSetter)
{
    StrictMock<SCB_DriverMock> stMock;
    SCB_DriverMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WriteRegister(SCB_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SCB_nMODULE, SCB_Register_t* pstRegisterDataArg) -> SCB_nERROR
        {
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SCB_enERROR_POINTER;
            }
            EXPECT_EQ((UBase_t) SCB_enSTATE_ENA, pstRegisterDataArg->uxValue);
            return SCB_enERROR_OK;
        }))
        .WillOnce(Invoke([](SCB_nMODULE, SCB_Register_t* pstRegisterDataArg) -> SCB_nERROR
        {
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SCB_enERROR_POINTER;
            }
            EXPECT_EQ((UBase_t) SCB_enSTATE_DIS, pstRegisterDataArg->uxValue);
            return SCB_enERROR_OK;
        }));

    EXPECT_EQ(SCB_enERROR_OK,
              SCB__enEnableUnprivilegedSWTrigger(SCB_enMODULE_0));
    EXPECT_EQ(SCB_enERROR_OK,
              SCB__enDisableUnprivilegedSWTrigger(SCB_enMODULE_0));
}

/**
 * @brief Validate software-trigger state read behavior and pointer rejection.
 * @summary Confirms that `SCB__enGetUnprivilegedSWTriggerEnableState` rejects a
 *          null output pointer and otherwise reads the CCR USERSETMPEND field
 *          with the expected address, mask, and shift.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SCB_DriverMock bridge
 * - Original source under test: SCB_SoftwareInterruptTrigger.c@endverbatim
 */
TEST(SCB_SoftwareInterruptTriggerTest, GetUnprivilegedSWTriggerUsesExpectedField)
{
    StrictMock<SCB_DriverMock> stMock;
    SCB_DriverMockScope stMockScope(&stMock);
    SCB_nSTATE enStateReg;

    EXPECT_EQ(SCB_enERROR_POINTER,
              SCB__enGetUnprivilegedSWTriggerEnableState(SCB_enMODULE_0, (SCB_nSTATE*) 0UL));

    enStateReg = SCB_enSTATE_UNDEF;

    EXPECT_CALL(stMock, ReadRegister(SCB_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SCB_nMODULE enModuleArg, SCB_Register_t* pstRegisterDataArg) -> SCB_nERROR
        {
            EXPECT_EQ(SCB_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SCB_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SCB_CCR_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) SCB_CCR_USERSETMPEND_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) SCB_CCR_R_USERSETMPEND_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) SCB_enSTATE_ENA;
            return SCB_enERROR_OK;
        }));

    EXPECT_EQ(SCB_enERROR_OK,
              SCB__enGetUnprivilegedSWTriggerEnableState(SCB_enMODULE_0, &enStateReg));
    EXPECT_EQ(SCB_enSTATE_ENA, enStateReg);
}