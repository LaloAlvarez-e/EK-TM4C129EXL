/**
 *
 * @file NVIC_RegisterAccess_Test.cpp
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
#include <xDriver_MCU/Core/NVIC/Driver/xHeader/NVIC_ReadReg.h>
#include <xDriver_MCU/Core/NVIC/Driver/xHeader/NVIC_WriteReg.h>
#include <xDriver_MCU/Core/NVIC/Peripheral/Register/xHeader/NVIC_RegisterAddress.h>
}

#include <tm4c129e_test/NVIC_RegisterPrimitivesMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Invoke;
using ::testing::Return;
using ::testing::StrictMock;

/**
 * @brief Validate null-pointer rejection in the NVIC read helper.
 * @summary Confirms that `NVIC__enReadValue` rejects a null output pointer before
 *          attempting vector validation or primitive register access.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original sources under test: NVIC_ReadReg.c and NVIC_WriteReg.c
 * - Public API parameter validation path@endverbatim
 */
TEST(NVIC_RegisterAccessTest, ReadValueRejectsNullPointer)
{
    EXPECT_EQ(NVIC_enERROR_POINTER,
              NVIC__enReadValue(NVIC_enMODULE_0,
                                NVIC_enVECTOR_SYSEXC,
                                NVIC_ISER_OFFSET,
                                (UBase_t*) 0UL));
}

/**
 * @brief Validate NVIC read-path vector mapping into register offset and bit position.
 * @summary Confirms that `NVIC__enReadValue` maps vector 67 into the third ISER
 *          register byte offset and bit 3, then returns the primitive read value
 *          to the caller.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - NVIC_RegisterPrimitivesMock bridge
 * - Original source under test: NVIC_ReadReg.c
 * - NVIC register address definitions@endverbatim
 */
TEST(NVIC_RegisterAccessTest, ReadValueUsesExpectedRegisterOffsetAndBit)
{
    StrictMock<NVIC_RegisterPrimitivesMock> stMock;
    NVIC_RegisterPrimitivesMockScope stMockScope(&stMock);
    UBase_t uxValueReg;

    uxValueReg = 0UL;

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
            EXPECT_EQ((uintptr_t) NVIC_ISER2_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) 0x1UL, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) 3UL, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) NVIC_enSTATE_ENA;
            return NVIC_enERROR_OK;
        }));

    EXPECT_EQ(NVIC_enERROR_OK,
              NVIC__enReadValue(NVIC_enMODULE_0,
                                NVIC_enVECTOR_SYSEXC,
                                NVIC_ISER_OFFSET,
                                &uxValueReg));
    EXPECT_EQ((UBase_t) NVIC_enSTATE_ENA, uxValueReg);
}

/**
 * @brief Validate NVIC write-path vector mapping into register offset and bit position.
 * @summary Confirms that `NVIC__enSetWriteValue` maps vector 95 into the third ICER
 *          register byte offset and bit 31, and forwards the caller-provided value
 *          unchanged through the primitive write seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - NVIC_RegisterPrimitivesMock bridge
 * - Original source under test: NVIC_WriteReg.c
 * - NVIC register address definitions@endverbatim
 */
TEST(NVIC_RegisterAccessTest, WriteValueUsesExpectedRegisterOffsetAndBit)
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
            EXPECT_EQ((uintptr_t) NVIC_ICER2_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) 0x1UL, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) 31UL, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) NVIC_enSTATE_ENA, pstRegisterDataArg->uxValue);
            return NVIC_enERROR_OK;
        }));

    EXPECT_EQ(NVIC_enERROR_OK,
              NVIC__enSetWriteValue(NVIC_enMODULE_0,
                                    NVIC_enVECTOR_AES,
                                    NVIC_ICER_OFFSET,
                                    (UBase_t) NVIC_enSTATE_ENA));
}

/**
 * @brief Validate invalid-vector propagation in the NVIC write helper.
 * @summary Confirms that `NVIC__enSetWriteValue` returns the parameter-validation
 *          error from `MCU__enCheckParams` and does not attempt primitive register
 *          access when the vector is outside the supported range.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - NVIC_RegisterPrimitivesMock bridge
 * - Original source under test: NVIC_WriteReg.c
 * - Parameter validation seam@endverbatim
 */
TEST(NVIC_RegisterAccessTest, WriteValuePropagatesVectorValidationError)
{
    StrictMock<NVIC_RegisterPrimitivesMock> stMock;
    NVIC_RegisterPrimitivesMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, CheckParams((UBase_t) NVIC_enVECTOR_UNDEF, (UBase_t) NVIC_enVECTOR_MAX))
        .WillOnce(Return(MCU_enERROR_VALUE));

    EXPECT_EQ(NVIC_enERROR_VALUE,
              NVIC__enSetWriteValue(NVIC_enMODULE_0,
                                    NVIC_enVECTOR_UNDEF,
                                    NVIC_ICER_OFFSET,
                                    (UBase_t) NVIC_enSTATE_ENA));
}