/**
 *
 * @file SCB_StackAligment_Test.cpp
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
#include <xDriver_MCU/Core/SCB/Driver/xHeader/SCB_StackAligment.h>
#include <xDriver_MCU/Core/SCB/Peripheral/Register/xHeader/SCB_RegisterAddress.h>
#include <xDriver_MCU/Core/SCB/Peripheral/Register/RegisterDefines/SCB_RegisterDefines.h>
}

#include <tm4c129e_test/SCB_DriverMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Invoke;
using ::testing::StrictMock;

/**
 * @brief Validate stack-alignment write field selection.
 * @summary Confirms that `SCB__enSetStackAligment` writes the CCR STKALIGN field
 *          with the expected address, mask, shift, and enum value.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SCB_DriverMock bridge
 * - Original source under test: SCB_StackAligment.c@endverbatim
 */
TEST(SCB_StackAligmentTest, SetStackAligmentUsesExpectedField)
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
            EXPECT_EQ((UBase_t) SCB_CCR_STKALIGN_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) SCB_CCR_R_STKALIGN_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) SCB_enALIGN_8BYTE, pstRegisterDataArg->uxValue);
            return SCB_enERROR_OK;
        }));

    EXPECT_EQ(SCB_enERROR_OK,
              SCB__enSetStackAligment(SCB_enMODULE_0, SCB_enALIGN_8BYTE));
}

/**
 * @brief Validate stack-alignment read field access.
 * @summary Confirms that `SCB__enGetStackAligment` reads the CCR STKALIGN field
 *          with the expected address, mask, and shift and returns the enum value
 *          from the primitive read seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SCB_DriverMock bridge
 * - Original source under test: SCB_StackAligment.c@endverbatim
 */
TEST(SCB_StackAligmentTest, GetStackAligmentUsesExpectedField)
{
    StrictMock<SCB_DriverMock> stMock;
    SCB_DriverMockScope stMockScope(&stMock);
    SCB_nALIGN enAlignReg;

    enAlignReg = SCB_enALIGN_ERROR;

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
            EXPECT_EQ((UBase_t) SCB_CCR_STKALIGN_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) SCB_CCR_R_STKALIGN_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) SCB_enALIGN_4BYTE;
            return SCB_enERROR_OK;
        }));

    EXPECT_EQ(SCB_enERROR_OK,
              SCB__enGetStackAligment(SCB_enMODULE_0, &enAlignReg));
    EXPECT_EQ(SCB_enALIGN_4BYTE, enAlignReg);
}