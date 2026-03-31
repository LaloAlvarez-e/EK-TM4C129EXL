/**
 *
 * @file SYSEXC_RegisterPrimitives_Test.cpp
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
#include <xDriver_MCU/SYSEXC/Driver/Intrinsics/Primitives/xHeader/SYSEXC_ReadRegister.h>
#include <xDriver_MCU/SYSEXC/Driver/Intrinsics/Primitives/xHeader/SYSEXC_WriteRegister.h>
#include <xDriver_MCU/SYSEXC/Peripheral/Register/xHeader/SYSEXC_RegisterAddress.h>
}

#include <tm4c129e_test/SYSEXC_MCURegisterAccessMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Invoke;
using ::testing::Return;
using ::testing::StrictMock;

/**
 * @brief Validate null-pointer rejection in the primitive SYSEXC read helper.
 * @summary Confirms that `SYSEXC__enReadRegister` rejects a null register
 *          description before module validation or MCU register access occurs.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original sources under test: SYSEXC_ReadRegister.c and SYSEXC_WriteRegister.c
 * - Public API parameter validation path@endverbatim
 */
TEST(SYSEXC_RegisterPrimitivesTest, ReadRegisterRejectsNullPointer)
{
    EXPECT_EQ(SYSEXC_enERROR_POINTER,
              SYSEXC__enReadRegister(SYSEXC_enMODULE_0, (SYSEXC_Register_t*) 0UL));
}

/**
 * @brief Validate base-address addition in the primitive SYSEXC read helper.
 * @summary Confirms that `SYSEXC__enReadRegister` validates the module, adds the
 *          SYSEXC block base address to the caller-provided offset, and forwards
 *          the adjusted register description into `MCU__enReadRegister`.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSEXC_MCURegisterAccessMock bridge
 * - Original source under test: SYSEXC_ReadRegister.c@endverbatim
 */
TEST(SYSEXC_RegisterPrimitivesTest, ReadRegisterAddsBlockBaseBeforeMCUAccess)
{
    StrictMock<SYSEXC_MCURegisterAccessMock> stMock;
    SYSEXC_MCURegisterAccessMockScope stMockScope(&stMock);
    SYSEXC_Register_t stRegister;

    stRegister.uptrAddress = SYSEXC_MIS_OFFSET;
    stRegister.uxMask = 0x1UL;
    stRegister.uxShift = 5UL;
    stRegister.uxValue = 0UL;

    EXPECT_CALL(stMock, CheckParams((UBase_t) SYSEXC_enMODULE_0, (UBase_t) SYSEXC_enMODULE_MAX))
        .WillOnce(Return(MCU_enERROR_OK));
    EXPECT_CALL(stMock, ReadRegister(testing::_))
        .WillOnce(Invoke([](MCU_Register_t* pstRegisterDataArg) -> MCU_nERROR
        {
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return MCU_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) (SYSEXC_BASE + SYSEXC_MIS_OFFSET), pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) 0x1UL, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) 5UL, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = 1UL;
            return MCU_enERROR_OK;
        }));

    EXPECT_EQ(SYSEXC_enERROR_OK, SYSEXC__enReadRegister(SYSEXC_enMODULE_0, &stRegister));
    EXPECT_EQ((UBase_t) 1UL, stRegister.uxValue);
}

/**
 * @brief Validate base-address addition in the primitive SYSEXC write helper.
 * @summary Confirms that `SYSEXC__enWriteRegister` validates the module, adds the
 *          SYSEXC block base address to the caller-provided offset, and forwards
 *          the adjusted register description into `MCU__enWriteRegister`.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSEXC_MCURegisterAccessMock bridge
 * - Original source under test: SYSEXC_WriteRegister.c@endverbatim
 */
TEST(SYSEXC_RegisterPrimitivesTest, WriteRegisterAddsBlockBaseBeforeMCUAccess)
{
    StrictMock<SYSEXC_MCURegisterAccessMock> stMock;
    SYSEXC_MCURegisterAccessMockScope stMockScope(&stMock);
    SYSEXC_Register_t stRegister;

    stRegister.uptrAddress = SYSEXC_IC_OFFSET;
    stRegister.uxMask = 0x3FUL;
    stRegister.uxShift = 0UL;
    stRegister.uxValue = 0x3FUL;

    EXPECT_CALL(stMock, CheckParams((UBase_t) SYSEXC_enMODULE_0, (UBase_t) SYSEXC_enMODULE_MAX))
        .WillOnce(Return(MCU_enERROR_OK));
    EXPECT_CALL(stMock, WriteRegister(testing::_))
        .WillOnce(Invoke([](const MCU_Register_t* pstRegisterDataArg) -> MCU_nERROR
        {
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return MCU_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) (SYSEXC_BASE + SYSEXC_IC_OFFSET), pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) 0x3FUL, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) 0UL, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) 0x3FUL, pstRegisterDataArg->uxValue);
            return MCU_enERROR_OK;
        }));

    EXPECT_EQ(SYSEXC_enERROR_OK, SYSEXC__enWriteRegister(SYSEXC_enMODULE_0, &stRegister));
}

/**
 * @brief Validate module-parameter error propagation in the primitive SYSEXC write helper.
 * @summary Confirms that `SYSEXC__enWriteRegister` propagates `MCU__enCheckParams`
 *          errors and skips the MCU write path when the module value is invalid.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSEXC_MCURegisterAccessMock bridge
 * - Original source under test: SYSEXC_WriteRegister.c@endverbatim
 */
TEST(SYSEXC_RegisterPrimitivesTest, WriteRegisterPropagatesModuleValidationError)
{
    StrictMock<SYSEXC_MCURegisterAccessMock> stMock;
    SYSEXC_MCURegisterAccessMockScope stMockScope(&stMock);
    SYSEXC_Register_t stRegister;

    stRegister.uptrAddress = SYSEXC_IM_OFFSET;
    stRegister.uxMask = 0x1UL;
    stRegister.uxShift = 1UL;
    stRegister.uxValue = 1UL;

    EXPECT_CALL(stMock, CheckParams((UBase_t) SYSEXC_enMODULE_UNDEF, (UBase_t) SYSEXC_enMODULE_MAX))
        .WillOnce(Return(MCU_enERROR_VALUE));

    EXPECT_EQ(SYSEXC_enERROR_VALUE, SYSEXC__enWriteRegister(SYSEXC_enMODULE_UNDEF, &stRegister));
}