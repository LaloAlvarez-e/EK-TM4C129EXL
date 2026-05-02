/**
 *
 * @file ACMP_RegisterPrimitives_Test.cpp
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
 * @verbatim 5 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 5 abr. 2026    GitHub Copilot   1.0         initial Version@endverbatim
 */

extern "C"
{
#include <xDriver_MCU/ACMP/Driver/Intrinsics/Primitives/xHeader/ACMP_ReadRegister.h>
#include <xDriver_MCU/ACMP/Driver/Intrinsics/Primitives/xHeader/ACMP_WriteRegister.h>
#include <xDriver_MCU/ACMP/Peripheral/Register/xHeader/ACMP_RegisterAddress.h>
}

#include <tm4c129e_test/ACMP_MCURegisterAccessMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Invoke;
using ::testing::Return;
using ::testing::StrictMock;

/**
 * @brief Validate null-pointer rejection in the primitive ACMP read helper.
 * @summary Confirms that `ACMP__enReadRegister` rejects a null register
 *          description before module validation or MCU register access occurs.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original sources under test: ACMP_ReadRegister.c and ACMP_WriteRegister.c
 * - Public API parameter validation path@endverbatim
 */
TEST(ACMP_RegisterPrimitivesTest, ReadRegisterRejectsNullPointer)
{
    EXPECT_EQ(ACMP_enERROR_POINTER,
              ACMP__enReadRegister(ACMP_enMODULE_0, (ACMP_Register_t*) 0UL));
}

/**
 * @brief Validate base-address addition in the primitive ACMP read helper.
 * @summary Confirms that `ACMP__enReadRegister` validates the module, adds the
 *          ACMP block base address to the caller-provided offset, and forwards
 *          the adjusted register description into `MCU__enReadRegister`.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - ACMP_MCURegisterAccessMock bridge
 * - Original source under test: ACMP_ReadRegister.c@endverbatim
 */
TEST(ACMP_RegisterPrimitivesTest, ReadRegisterAddsBlockBaseBeforeMCUAccess)
{
    StrictMock<ACMP_MCURegisterAccessMock> stMock;
    ACMP_MCURegisterAccessMockScope stMockScope(&stMock);
    ACMP_Register_t stRegister;

    stRegister.uptrAddress = ACMP_REFCTL_OFFSET;
    stRegister.uxMask = 0xFUL;
    stRegister.uxShift = 1UL;
    stRegister.uxValue = 0UL;

    EXPECT_CALL(stMock, CheckParams((UBase_t) ACMP_enMODULE_0, (UBase_t) ACMP_enMODULE_MAX))
        .WillOnce(Return(MCU_enERROR_OK));
    EXPECT_CALL(stMock, ReadRegister(testing::_))
        .WillOnce(Invoke([](MCU_Register_t* pstRegisterDataArg) -> MCU_nERROR
        {
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return MCU_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) (ACMP_BASE + ACMP_REFCTL_OFFSET), pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) 0xFUL, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) 1UL, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = 2UL;
            return MCU_enERROR_OK;
        }));

    EXPECT_EQ(ACMP_enERROR_OK, ACMP__enReadRegister(ACMP_enMODULE_0, &stRegister));
    EXPECT_EQ((UBase_t) 2UL, stRegister.uxValue);
}

/**
 * @brief Validate base-address addition in the primitive ACMP write helper.
 * @summary Confirms that `ACMP__enWriteRegister` validates the module, adds the
 *          ACMP block base address to the caller-provided offset, and forwards
 *          the adjusted register description into `MCU__enWriteRegister`.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - ACMP_MCURegisterAccessMock bridge
 * - Original source under test: ACMP_WriteRegister.c@endverbatim
 */
TEST(ACMP_RegisterPrimitivesTest, WriteRegisterAddsBlockBaseBeforeMCUAccess)
{
    StrictMock<ACMP_MCURegisterAccessMock> stMock;
    ACMP_MCURegisterAccessMockScope stMockScope(&stMock);
    ACMP_Register_t stRegister;

    stRegister.uptrAddress = ACMP_INTEN_OFFSET;
    stRegister.uxMask = 0x7UL;
    stRegister.uxShift = 0UL;
    stRegister.uxValue = 0x5UL;

    EXPECT_CALL(stMock, CheckParams((UBase_t) ACMP_enMODULE_0, (UBase_t) ACMP_enMODULE_MAX))
        .WillOnce(Return(MCU_enERROR_OK));
    EXPECT_CALL(stMock, WriteRegister(testing::_))
        .WillOnce(Invoke([](const MCU_Register_t* pstRegisterDataArg) -> MCU_nERROR
        {
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return MCU_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) (ACMP_BASE + ACMP_INTEN_OFFSET), pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) 0x7UL, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) 0UL, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) 0x5UL, pstRegisterDataArg->uxValue);
            return MCU_enERROR_OK;
        }));

    EXPECT_EQ(ACMP_enERROR_OK, ACMP__enWriteRegister(ACMP_enMODULE_0, &stRegister));
}

/**
 * @brief Validate module-parameter error propagation in the primitive ACMP write helper.
 * @summary Confirms that `ACMP__enWriteRegister` propagates `MCU__enCheckParams`
 *          errors and skips the MCU write path when the module value is invalid.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - ACMP_MCURegisterAccessMock bridge
 * - Original source under test: ACMP_WriteRegister.c@endverbatim
 */
TEST(ACMP_RegisterPrimitivesTest, WriteRegisterPropagatesModuleValidationError)
{
    StrictMock<ACMP_MCURegisterAccessMock> stMock;
    ACMP_MCURegisterAccessMockScope stMockScope(&stMock);
    ACMP_Register_t stRegister;

    stRegister.uptrAddress = ACMP_MIS_OFFSET;
    stRegister.uxMask = 0x1UL;
    stRegister.uxShift = 2UL;
    stRegister.uxValue = 1UL;

    EXPECT_CALL(stMock, CheckParams((UBase_t) ACMP_enMODULE_UNDEF, (UBase_t) ACMP_enMODULE_MAX))
        .WillOnce(Return(MCU_enERROR_VALUE));

    EXPECT_EQ(ACMP_enERROR_VALUE, ACMP__enWriteRegister(ACMP_enMODULE_UNDEF, &stRegister));
}