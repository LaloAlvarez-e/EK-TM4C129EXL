/**
 *
 * @file SYSCTL_ResetBehavior_Test.cpp
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
 * @verbatim 30 mar. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 30 mar. 2026   GitHub Copilot   1.0         initial Version@endverbatim
 */

extern "C"
{
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_ResetBehavior.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_RESBEHAVCTL.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/xHeader/SYSCTL_RegisterAddress.h>
}

#include <tm4c129e_test/SYSCTL_PrimitivesMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Invoke;
using ::testing::Return;
using ::testing::StrictMock;

/**
 * @brief Validate RESET_BEHAVCTL field composition for external reset behavior writes.
 * @summary Confirms that `SYSCTL__enSetResetBehavior_External` writes the
 *          external-reset field in `RESET_BEHAVCTL_OFFSET` using the documented
 *          mask and shift while forwarding the caller behavior value unchanged.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_ResetBehavior.c@endverbatim
 */
TEST(SYSCTL_ResetBehaviorTest, SetResetBehaviorExternalUsesExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) RESET_BEHAVCTL_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) RESET_BEHAVCTL_EXTERNAL_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) RESET_BEHAVCTL_R_EXTERNAL_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) SYSCTL_enRESET_BEHAVIOR_POR, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetResetBehavior_External(SYSCTL_enMODULE_0, SYSCTL_enRESET_BEHAVIOR_POR));
}

/**
 * @brief Validate pointer rejection in the external reset-behavior getter.
 * @summary Confirms that `SYSCTL__enGetResetBehavior_External` rejects a null
 *          destination pointer before attempting any primitive register read.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_ResetBehavior.c
 * - Public API parameter validation path@endverbatim
 */
TEST(SYSCTL_ResetBehaviorTest, GetResetBehaviorExternalRejectsNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetResetBehavior_External(SYSCTL_enMODULE_0, (SYSCTL_nRESET_BEHAVIOR*) 0UL));
}

/**
 * @brief Validate RESET_BEHAVCTL field composition for external reset-behavior reads.
 * @summary Confirms that `SYSCTL__enGetResetBehavior_External` reads the
 *          external-reset field from `RESET_BEHAVCTL_OFFSET` using the
 *          documented mask and shift and returns the primitive value unchanged.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_ResetBehavior.c@endverbatim
 */
TEST(SYSCTL_ResetBehaviorTest, GetResetBehaviorExternalUsesExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nRESET_BEHAVIOR enBehaviorReg;

    enBehaviorReg = SYSCTL_enRESET_BEHAVIOR_UNDEF;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) RESET_BEHAVCTL_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) RESET_BEHAVCTL_EXTERNAL_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) RESET_BEHAVCTL_R_EXTERNAL_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) SYSCTL_enRESET_BEHAVIOR_SYSRESET;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetResetBehavior_External(SYSCTL_enMODULE_0, &enBehaviorReg));
    EXPECT_EQ(SYSCTL_enRESET_BEHAVIOR_SYSRESET, enBehaviorReg);
}

/**
 * @brief Validate RESET_BEHAVCTL field composition for BOR reset-behavior writes.
 * @summary Confirms that `SYSCTL__enSetResetBehavior_BOR` writes the BOR field
 *          in `RESET_BEHAVCTL_OFFSET` using the documented mask and shift.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_ResetBehavior.c@endverbatim
 */
TEST(SYSCTL_ResetBehaviorTest, SetResetBehaviorBORUsesExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) RESET_BEHAVCTL_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) RESET_BEHAVCTL_BOR_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) RESET_BEHAVCTL_R_BOR_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) SYSCTL_enRESET_BEHAVIOR_SYSRESET, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetResetBehavior_BOR(SYSCTL_enMODULE_0, SYSCTL_enRESET_BEHAVIOR_SYSRESET));
}

/**
 * @brief Validate RESET_BEHAVCTL field composition for BOR reset-behavior reads.
 * @summary Confirms that `SYSCTL__enGetResetBehavior_BOR` reads the BOR field
 *          from `RESET_BEHAVCTL_OFFSET` using the documented mask and shift.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_ResetBehavior.c@endverbatim
 */
TEST(SYSCTL_ResetBehaviorTest, GetResetBehaviorBORUsesExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nRESET_BEHAVIOR enBehaviorReg;

    enBehaviorReg = SYSCTL_enRESET_BEHAVIOR_UNDEF;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) RESET_BEHAVCTL_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) RESET_BEHAVCTL_BOR_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) RESET_BEHAVCTL_R_BOR_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) SYSCTL_enRESET_BEHAVIOR_POR;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetResetBehavior_BOR(SYSCTL_enMODULE_0, &enBehaviorReg));
    EXPECT_EQ(SYSCTL_enRESET_BEHAVIOR_POR, enBehaviorReg);
}

/**
 * @brief Validate RESET_BEHAVCTL field composition for WDG0 reset-behavior writes.
 * @summary Confirms that `SYSCTL__enSetResetBehavior_WDG0` writes the WDG0
 *          field in `RESET_BEHAVCTL_OFFSET` using the documented mask and shift.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_ResetBehavior.c@endverbatim
 */
TEST(SYSCTL_ResetBehaviorTest, SetResetBehaviorWDG0UsesExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) RESET_BEHAVCTL_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) RESET_BEHAVCTL_WDG0_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) RESET_BEHAVCTL_R_WDG0_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) SYSCTL_enRESET_BEHAVIOR_POR, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetResetBehavior_WDG0(SYSCTL_enMODULE_0, SYSCTL_enRESET_BEHAVIOR_POR));
}

/**
 * @brief Validate RESET_BEHAVCTL field composition for WDG0 reset-behavior reads.
 * @summary Confirms that `SYSCTL__enGetResetBehavior_WDG0` reads the WDG0
 *          field from `RESET_BEHAVCTL_OFFSET` using the documented mask and shift.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_ResetBehavior.c@endverbatim
 */
TEST(SYSCTL_ResetBehaviorTest, GetResetBehaviorWDG0UsesExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nRESET_BEHAVIOR enBehaviorReg;

    enBehaviorReg = SYSCTL_enRESET_BEHAVIOR_UNDEF;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) RESET_BEHAVCTL_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) RESET_BEHAVCTL_WDG0_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) RESET_BEHAVCTL_R_WDG0_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) SYSCTL_enRESET_BEHAVIOR_SYSRESET;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetResetBehavior_WDG0(SYSCTL_enMODULE_0, &enBehaviorReg));
    EXPECT_EQ(SYSCTL_enRESET_BEHAVIOR_SYSRESET, enBehaviorReg);
}

/**
 * @brief Validate RESET_BEHAVCTL field composition for WDG1 reset-behavior writes.
 * @summary Confirms that `SYSCTL__enSetResetBehavior_WDG1` writes the WDG1
 *          field in `RESET_BEHAVCTL_OFFSET` using the documented mask and shift.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_ResetBehavior.c@endverbatim
 */
TEST(SYSCTL_ResetBehaviorTest, SetResetBehaviorWDG1UsesExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) RESET_BEHAVCTL_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) RESET_BEHAVCTL_WDG1_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) RESET_BEHAVCTL_R_WDG1_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) SYSCTL_enRESET_BEHAVIOR_SYSRESET, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetResetBehavior_WDG1(SYSCTL_enMODULE_0, SYSCTL_enRESET_BEHAVIOR_SYSRESET));
}

/**
 * @brief Validate RESET_BEHAVCTL field composition for WDG1 reset-behavior reads.
 * @summary Confirms that `SYSCTL__enGetResetBehavior_WDG1` reads the WDG1
 *          field from `RESET_BEHAVCTL_OFFSET` using the documented mask and shift.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_ResetBehavior.c@endverbatim
 */
TEST(SYSCTL_ResetBehaviorTest, GetResetBehaviorWDG1UsesExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nRESET_BEHAVIOR enBehaviorReg;

    enBehaviorReg = SYSCTL_enRESET_BEHAVIOR_UNDEF;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) RESET_BEHAVCTL_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) RESET_BEHAVCTL_WDG1_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) RESET_BEHAVCTL_R_WDG1_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) SYSCTL_enRESET_BEHAVIOR_POR;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetResetBehavior_WDG1(SYSCTL_enMODULE_0, &enBehaviorReg));
    EXPECT_EQ(SYSCTL_enRESET_BEHAVIOR_POR, enBehaviorReg);
}

/**
 * @brief Validate read-error propagation in the WDG1 reset-behavior getter.
 * @summary Confirms that `SYSCTL__enGetResetBehavior_WDG1` returns the
 *          primitive read error unchanged and preserves the caller output value
 *          when the RESET_BEHAVCTL read path fails.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_ResetBehavior.c@endverbatim
 */
TEST(SYSCTL_ResetBehaviorTest, GetResetBehaviorWDG1PropagatesReadError)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nRESET_BEHAVIOR enBehaviorReg;

    enBehaviorReg = SYSCTL_enRESET_BEHAVIOR_SYSRESET;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enGetResetBehavior_WDG1(SYSCTL_enMODULE_0, &enBehaviorReg));
    EXPECT_EQ(SYSCTL_enRESET_BEHAVIOR_SYSRESET, enBehaviorReg);
}