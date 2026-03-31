/**
 *
 * @file SCB_WakeUp_Test.cpp
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
#include <xDriver_MCU/Core/SCB/Driver/xHeader/SCB_WakeUp.h>
#include <xDriver_MCU/Core/SCB/Peripheral/Register/xHeader/SCB_RegisterAddress.h>
#include <xDriver_MCU/Core/SCB/Peripheral/Register/RegisterDefines/SCB_RegisterDefines.h>
}

#include <tm4c129e_test/SCB_DriverMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Invoke;
using ::testing::StrictMock;

/**
 * @brief Validate wake-up source write field selection.
 * @summary Confirms that `SCB__enSetWakeUpSource` writes the SCR SEVONPEND field
 *          with the expected address, mask, shift, and enum value.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SCB_DriverMock bridge
 * - Original source under test: SCB_WakeUp.c@endverbatim
 */
TEST(SCB_WakeUpTest, SetWakeUpSourceUsesSevOnPendField)
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
            EXPECT_EQ((UBase_t) SCB_SCR_SEVONPEND_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) SCB_SCR_R_SEVONPEND_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) SCB_enWAKEUP_ALL, pstRegisterDataArg->uxValue);
            return SCB_enERROR_OK;
        }));

    EXPECT_EQ(SCB_enERROR_OK,
              SCB__enSetWakeUpSource(SCB_enMODULE_0, SCB_enWAKEUP_ALL));
}

/**
 * @brief Validate wake-up source read mask and shift behavior.
 * @summary Confirms that `SCB__enGetWakeUpSource` reads the SCR SEVONPEND field
 *          with the expected address, mask, and shift and returns the enum value
 *          from the primitive read seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SCB_DriverMock bridge
 * - Original source under test: SCB_WakeUp.c@endverbatim
 */
TEST(SCB_WakeUpTest, GetWakeUpSourceUsesSevOnPendField)
{
    StrictMock<SCB_DriverMock> stMock;
    SCB_DriverMockScope stMockScope(&stMock);
    SCB_nWAKEUP enWakeUpReg;

    enWakeUpReg = SCB_enWAKEUP_UNDEF;

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
            EXPECT_EQ((UBase_t) SCB_SCR_SEVONPEND_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) SCB_SCR_R_SEVONPEND_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) SCB_enWAKEUP_ONLY;
            return SCB_enERROR_OK;
        }));

    EXPECT_EQ(SCB_enERROR_OK,
              SCB__enGetWakeUpSource(SCB_enMODULE_0, &enWakeUpReg));
    EXPECT_EQ(SCB_enWAKEUP_ONLY, enWakeUpReg);
}