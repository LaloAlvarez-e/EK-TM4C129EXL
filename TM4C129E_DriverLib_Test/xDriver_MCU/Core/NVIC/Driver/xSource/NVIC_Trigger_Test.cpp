/**
 *
 * @file NVIC_Trigger_Test.cpp
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
#include <xDriver_MCU/Core/NVIC/Driver/xHeader/NVIC_Trigger.h>
#include <xDriver_MCU/Core/NVIC/Peripheral/Register/xHeader/NVIC_RegisterAddress.h>
#include <xDriver_MCU/Core/NVIC/Peripheral/Register/RegisterDefines/xHeader/NVIC_RegisterDefines_STIR.h>
}

#include <tm4c129e_test/NVIC_RegisterPrimitivesMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Invoke;
using ::testing::Return;
using ::testing::StrictMock;

/**
 * @brief Validate STIR field programming for software-triggered interrupts.
 * @summary Confirms that `NVIC__enTriggerVector` validates the vector number and
 *          writes the expected STIR INTID field through the primitive register seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - NVIC_RegisterPrimitivesMock bridge
 * - Original source under test: NVIC_Trigger.c@endverbatim
 */
TEST(NVIC_TriggerTest, TriggerVectorWritesSTIRIntidField)
{
    StrictMock<NVIC_RegisterPrimitivesMock> stMock;
    NVIC_RegisterPrimitivesMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, CheckParams((UBase_t) NVIC_enVECTOR_TIMER7B, (UBase_t) NVIC_enVECTOR_MAX))
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
            EXPECT_EQ((uintptr_t) NVIC_STIR_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) NVIC_STIR_R_INTID_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) NVIC_STIR_R_INTID_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) NVIC_enVECTOR_TIMER7B, pstRegisterDataArg->uxValue);
            return NVIC_enERROR_OK;
        }));

    EXPECT_EQ(NVIC_enERROR_OK,
              NVIC__enTriggerVector(NVIC_enMODULE_0, NVIC_enVECTOR_TIMER7B));
}

/**
 * @brief Validate vector-range error propagation in the software-trigger helper.
 * @summary Confirms that `NVIC__enTriggerVector` propagates `MCU__enCheckParams`
 *          failures and does not attempt a STIR write when the vector is invalid.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - NVIC_RegisterPrimitivesMock bridge
 * - Original source under test: NVIC_Trigger.c@endverbatim
 */
TEST(NVIC_TriggerTest, TriggerVectorPropagatesValidationError)
{
    StrictMock<NVIC_RegisterPrimitivesMock> stMock;
    NVIC_RegisterPrimitivesMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, CheckParams((UBase_t) NVIC_enVECTOR_UNDEF, (UBase_t) NVIC_enVECTOR_MAX))
        .WillOnce(Return(MCU_enERROR_VALUE));

    EXPECT_EQ(NVIC_enERROR_VALUE,
              NVIC__enTriggerVector(NVIC_enMODULE_0, NVIC_enVECTOR_UNDEF));
}