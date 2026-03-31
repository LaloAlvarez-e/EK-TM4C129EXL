/**
 *
 * @file SCB_PriorityGroup_Test.cpp
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
#include <xDriver_MCU/Core/SCB/Driver/xHeader/SCB_PriorityGroup.h>
#include <xDriver_MCU/Core/SCB/Peripheral/Register/xHeader/SCB_RegisterAddress.h>
#include <xDriver_MCU/Core/SCB/Peripheral/Register/RegisterDefines/SCB_RegisterDefines.h>
}

#include <tm4c129e_test/SCB_DriverMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::DoAll;
using ::testing::InSequence;
using ::testing::Invoke;
using ::testing::Return;
using ::testing::SetArgPointee;
using ::testing::StrictMock;

/**
 * @brief Validate priority-group write composition and barrier ordering.
 * @summary Confirms that `SCB__enSetPriorityGroup` validates the requested group,
 *          writes the PRIGROUP field together with the AIRCR write key, and
 *          executes data-sync barriers before and after the write.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SCB_DriverMock bridge
 * - Original source under test: SCB_PriorityGroup.c@endverbatim
 */
TEST(SCB_PriorityGroupTest, SetPriorityGroupUsesWriteKeyAndBarrierSequence)
{
    StrictMock<SCB_DriverMock> stMock;
    SCB_DriverMockScope stMockScope(&stMock);
    InSequence stSequence;

    EXPECT_CALL(stMock, CheckParams((UBase_t) SCB_enPRIGROUP_XYY, (UBase_t) SCB_enPRIGROUP_MAX))
        .WillOnce(Return(MCU_enERROR_OK));
    EXPECT_CALL(stMock, DataSyncBarrier());
    EXPECT_CALL(stMock, WriteRegister(SCB_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SCB_nMODULE enModuleArg, SCB_Register_t* pstRegisterDataArg) -> SCB_nERROR
        {
            EXPECT_EQ(SCB_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SCB_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SCB_AIRCR_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) (SCB_AIRCR_R_VECTKEY_MASK | SCB_AIRCR_R_PRIGROUP_MASK), pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) 0UL, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) (SCB_AIRCR_R_VECTKEY_WRITE | ((UBase_t) SCB_enPRIGROUP_XYY << SCB_AIRCR_R_PRIGROUP_BIT)), pstRegisterDataArg->uxValue);
            return SCB_enERROR_OK;
        }));
    EXPECT_CALL(stMock, DataSyncBarrier());

    EXPECT_EQ(SCB_enERROR_OK,
              SCB__enSetPriorityGroup(SCB_enMODULE_0, SCB_enPRIGROUP_XYY));
}

/**
 * @brief Validate null-pointer rejection in the priority-group getter.
 * @summary Confirms that `SCB__enGetPriorityGroup` rejects a null output pointer
 *          before attempting primitive register access.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SCB_PriorityGroup.c@endverbatim
 */
TEST(SCB_PriorityGroupTest, GetPriorityGroupRejectsNullPointer)
{
    EXPECT_EQ(SCB_enERROR_POINTER,
              SCB__enGetPriorityGroup(SCB_enMODULE_0, (SCB_nPRIGROUP*) 0UL));
}

/**
 * @brief Validate priority-group read mask and shift behavior.
 * @summary Confirms that `SCB__enGetPriorityGroup` reads the AIRCR PRIGROUP
 *          field with the expected address, mask, and bit shift and returns the
 *          raw priority-group enum value to the caller.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SCB_DriverMock bridge
 * - Original source under test: SCB_PriorityGroup.c@endverbatim
 */
TEST(SCB_PriorityGroupTest, GetPriorityGroupUsesExpectedMaskAndShift)
{
    StrictMock<SCB_DriverMock> stMock;
    SCB_DriverMockScope stMockScope(&stMock);
    SCB_nPRIGROUP enGroupReg;

    enGroupReg = SCB_enPRIGROUP_ERROR;

    EXPECT_CALL(stMock, ReadRegister(SCB_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SCB_nMODULE enModuleArg, SCB_Register_t* pstRegisterDataArg) -> SCB_nERROR
        {
            EXPECT_EQ(SCB_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SCB_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SCB_AIRCR_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) SCB_AIRCR_PRIGROUP_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) SCB_AIRCR_R_PRIGROUP_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) SCB_enPRIGROUP_YYY;
            return SCB_enERROR_OK;
        }));

    EXPECT_EQ(SCB_enERROR_OK,
              SCB__enGetPriorityGroup(SCB_enMODULE_0, &enGroupReg));
    EXPECT_EQ(SCB_enPRIGROUP_YYY, enGroupReg);
}