/**
 *
 * @file NVIC_Priority_Test.cpp
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
#include <xDriver_MCU/Core/NVIC/Driver/xHeader/NVIC_Priority.h>
#include <xDriver_MCU/Core/NVIC/Peripheral/Register/xHeader/NVIC_RegisterAddress.h>
}

#include <tm4c129e_test/NVIC_RegisterPrimitivesMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Invoke;
using ::testing::Return;
using ::testing::StrictMock;

/**
 * @brief Validate null-pointer rejection in the priority read helper.
 * @summary Confirms that `NVIC__enGetVectorPriority` rejects a null output
 *          pointer before vector validation or primitive register access occurs.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: NVIC_Priority.c@endverbatim
 */
TEST(NVIC_PriorityTest, GetVectorPriorityRejectsNullPointer)
{
    EXPECT_EQ(NVIC_enERROR_POINTER,
              NVIC__enGetVectorPriority(NVIC_enMODULE_0,
                                        NVIC_enVECTOR_SYSEXC,
                                        (NVIC_nPRIORITY*) 0UL));
}

/**
 * @brief Validate NVIC priority read-path register offset and bit-position math.
 * @summary Confirms that `NVIC__enGetVectorPriority` maps vector 67 into the
 *          expected IPR byte offset and priority-field bit position before
 *          reading the priority through the primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - NVIC_RegisterPrimitivesMock bridge
 * - Original source under test: NVIC_Priority.c@endverbatim
 */
TEST(NVIC_PriorityTest, GetVectorPriorityUsesExpectedRegisterOffsetAndBit)
{
    StrictMock<NVIC_RegisterPrimitivesMock> stMock;
    NVIC_RegisterPrimitivesMockScope stMockScope(&stMock);
    NVIC_nPRIORITY enPriorityReg;

    enPriorityReg = NVIC_enPRI_UNDEF;

    EXPECT_CALL(stMock, CheckParams((UBase_t) NVIC_enVECTOR_SYSEXC, (UBase_t) NVIC_enVECTOR_MAX))
        .WillOnce(Return(MCU_enERROR_OK));

    EXPECT_CALL(stMock, ReadRegister(NVIC_enMODULE_0, testing::_))
        .WillOnce(Invoke([](NVIC_nMODULE enModuleArg, NVIC_Register_t* pstRegisterDataArg) -> NVIC_nERROR
        {
            EXPECT_EQ(NVIC_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return NVIC_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) (NVIC_IPR_OFFSET + 64UL), pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) NVIC_PRI_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) 29UL, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) NVIC_enPRI3;
            return NVIC_enERROR_OK;
        }));

    EXPECT_EQ(NVIC_enERROR_OK,
              NVIC__enGetVectorPriority(NVIC_enMODULE_0, NVIC_enVECTOR_SYSEXC, &enPriorityReg));
    EXPECT_EQ(NVIC_enPRI3, enPriorityReg);
}

/**
 * @brief Validate NVIC priority write-path register offset and bit-position math.
 * @summary Confirms that `NVIC__enSetVectorPriority` maps vector 95 into the
 *          expected IPR byte offset and priority-field bit position before
 *          forwarding the requested priority through the primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - NVIC_RegisterPrimitivesMock bridge
 * - Original source under test: NVIC_Priority.c@endverbatim
 */
TEST(NVIC_PriorityTest, SetVectorPriorityUsesExpectedRegisterOffsetAndBit)
{
    StrictMock<NVIC_RegisterPrimitivesMock> stMock;
    NVIC_RegisterPrimitivesMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, CheckParams((UBase_t) NVIC_enVECTOR_AES, (UBase_t) NVIC_enVECTOR_MAX))
        .WillOnce(Return(MCU_enERROR_OK));

    EXPECT_CALL(stMock, WriteRegister(NVIC_enMODULE_0, testing::_))
        .WillOnce(Invoke([](NVIC_nMODULE enModuleArg, NVIC_Register_t* pstRegisterDataArg) -> NVIC_nERROR
        {
            EXPECT_EQ(NVIC_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return NVIC_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) (NVIC_IPR_OFFSET + 92UL), pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) NVIC_PRI_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) 29UL, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) NVIC_enPRI5, pstRegisterDataArg->uxValue);
            return NVIC_enERROR_OK;
        }));

    EXPECT_EQ(NVIC_enERROR_OK,
              NVIC__enSetVectorPriority(NVIC_enMODULE_0, NVIC_enVECTOR_AES, NVIC_enPRI5));
}

/**
 * @brief Validate vector-validation error propagation in the priority write helper.
 * @summary Confirms that `NVIC__enSetVectorPriority` propagates the validation
 *          error from `MCU__enCheckParams` and skips primitive register access
 *          when the vector is invalid.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - NVIC_RegisterPrimitivesMock bridge
 * - Original source under test: NVIC_Priority.c@endverbatim
 */
TEST(NVIC_PriorityTest, SetVectorPriorityPropagatesVectorValidationError)
{
    StrictMock<NVIC_RegisterPrimitivesMock> stMock;
    NVIC_RegisterPrimitivesMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, CheckParams((UBase_t) NVIC_enVECTOR_UNDEF, (UBase_t) NVIC_enVECTOR_MAX))
        .WillOnce(Return(MCU_enERROR_VALUE));

    EXPECT_EQ(NVIC_enERROR_VALUE,
              NVIC__enSetVectorPriority(NVIC_enMODULE_0, NVIC_enVECTOR_UNDEF, NVIC_enPRI1));
}