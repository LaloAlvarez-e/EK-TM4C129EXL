/**
 *
 * @file NVIC_RegisterPrimitives_Test.cpp
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
#include <xDriver_MCU/Core/NVIC/Driver/Intrinsics/Primitives/xHeader/NVIC_ReadRegister.h>
#include <xDriver_MCU/Core/NVIC/Driver/Intrinsics/Primitives/xHeader/NVIC_WriteRegister.h>
#include <xDriver_MCU/Core/NVIC/Peripheral/Register/xHeader/NVIC_RegisterAddress.h>
}

#include <tm4c129e_test/NVIC_MCURegisterAccessMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Invoke;
using ::testing::Return;
using ::testing::StrictMock;

/**
 * @brief Validate null-pointer rejection in the primitive NVIC read-register helper.
 * @summary Confirms that `NVIC__enReadRegister` rejects a null register structure
 *          before module validation or MCU register access occurs.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original sources under test: NVIC_ReadRegister.c and NVIC_WriteRegister.c
 * - Public API parameter validation path@endverbatim
 */
TEST(NVIC_RegisterPrimitivesTest, ReadRegisterRejectsNullPointer)
{
    EXPECT_EQ(NVIC_enERROR_POINTER,
              NVIC__enReadRegister(NVIC_enMODULE_0, (NVIC_Register_t*) 0UL));
}

/**
 * @brief Validate base-address addition in the primitive NVIC read-register helper.
 * @summary Confirms that `NVIC__enReadRegister` validates the module, adds the
 *          NVIC block base address to the caller-provided offset, and forwards the
 *          adjusted register description into `MCU__enReadRegister`.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - NVIC_MCURegisterAccessMock bridge
 * - Original source under test: NVIC_ReadRegister.c@endverbatim
 */
TEST(NVIC_RegisterPrimitivesTest, ReadRegisterAddsBlockBaseBeforeMCUAccess)
{
    StrictMock<NVIC_MCURegisterAccessMock> stMock;
    NVIC_MCURegisterAccessMockScope stMockScope(&stMock);
    NVIC_Register_t stRegister;

    stRegister.uptrAddress = NVIC_ISER1_OFFSET;
    stRegister.uxMask = 0x1UL;
    stRegister.uxShift = 7UL;
    stRegister.uxValue = 0UL;

    EXPECT_CALL(stMock, CheckParams((UBase_t) NVIC_enMODULE_0, (UBase_t) NVIC_enMODULE_MAX))
        .WillOnce(Return(MCU_enERROR_OK));
    EXPECT_CALL(stMock, ReadRegister(testing::_))
        .WillOnce(Invoke([](MCU_Register_t* pstRegisterDataArg) -> MCU_nERROR
        {
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return MCU_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) (NVIC_BASE + NVIC_ISER1_OFFSET), pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) 0x1UL, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) 7UL, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = 1UL;
            return MCU_enERROR_OK;
        }));

    EXPECT_EQ(NVIC_enERROR_OK, NVIC__enReadRegister(NVIC_enMODULE_0, &stRegister));
    EXPECT_EQ((UBase_t) 1UL, stRegister.uxValue);
}

/**
 * @brief Validate base-address addition in the primitive NVIC write-register helper.
 * @summary Confirms that `NVIC__enWriteRegister` validates the module, adds the
 *          NVIC block base address to the caller-provided offset, and forwards the
 *          adjusted register description into `MCU__enWriteRegister`.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - NVIC_MCURegisterAccessMock bridge
 * - Original source under test: NVIC_WriteRegister.c@endverbatim
 */
TEST(NVIC_RegisterPrimitivesTest, WriteRegisterAddsBlockBaseBeforeMCUAccess)
{
    StrictMock<NVIC_MCURegisterAccessMock> stMock;
    NVIC_MCURegisterAccessMockScope stMockScope(&stMock);
    NVIC_Register_t stRegister;

    stRegister.uptrAddress = NVIC_ICER0_OFFSET;
    stRegister.uxMask = 0x1UL;
    stRegister.uxShift = 4UL;
    stRegister.uxValue = 1UL;

    EXPECT_CALL(stMock, CheckParams((UBase_t) NVIC_enMODULE_0, (UBase_t) NVIC_enMODULE_MAX))
        .WillOnce(Return(MCU_enERROR_OK));
    EXPECT_CALL(stMock, WriteRegister(testing::_))
        .WillOnce(Invoke([](const MCU_Register_t* pstRegisterDataArg) -> MCU_nERROR
        {
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return MCU_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) (NVIC_BASE + NVIC_ICER0_OFFSET), pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) 0x1UL, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) 4UL, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) 1UL, pstRegisterDataArg->uxValue);
            return MCU_enERROR_OK;
        }));

    EXPECT_EQ(NVIC_enERROR_OK, NVIC__enWriteRegister(NVIC_enMODULE_0, &stRegister));
}

/**
 * @brief Validate module-parameter error propagation in the primitive write helper.
 * @summary Confirms that `NVIC__enWriteRegister` propagates `MCU__enCheckParams`
 *          errors and skips the MCU write path when the module value is invalid.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - NVIC_MCURegisterAccessMock bridge
 * - Original source under test: NVIC_WriteRegister.c@endverbatim
 */
TEST(NVIC_RegisterPrimitivesTest, WriteRegisterPropagatesModuleValidationError)
{
    StrictMock<NVIC_MCURegisterAccessMock> stMock;
    NVIC_MCURegisterAccessMockScope stMockScope(&stMock);
    NVIC_Register_t stRegister;

    stRegister.uptrAddress = NVIC_ICER0_OFFSET;
    stRegister.uxMask = 0x1UL;
    stRegister.uxShift = 0UL;
    stRegister.uxValue = 1UL;

    EXPECT_CALL(stMock, CheckParams((UBase_t) NVIC_enMODULE_UNDEF, (UBase_t) NVIC_enMODULE_MAX))
        .WillOnce(Return(MCU_enERROR_VALUE));

    EXPECT_EQ(NVIC_enERROR_VALUE, NVIC__enWriteRegister(NVIC_enMODULE_UNDEF, &stRegister));
}