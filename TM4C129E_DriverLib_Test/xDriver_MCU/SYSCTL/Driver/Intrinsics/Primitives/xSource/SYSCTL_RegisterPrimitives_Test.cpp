/**
 *
 * @file SYSCTL_RegisterPrimitives_Test.cpp
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
#include <xDriver_MCU/SYSCTL/Driver/Intrinsics/Primitives/xHeader/SYSCTL_ReadRegister.h>
#include <xDriver_MCU/SYSCTL/Driver/Intrinsics/Primitives/xHeader/SYSCTL_WriteRegister.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/xHeader/SYSCTL_RegisterAddress.h>
}

#include <tm4c129e_test/SYSCTL_MCURegisterAccessMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Invoke;
using ::testing::Return;
using ::testing::StrictMock;

/**
 * @brief Validate null-pointer rejection in the primitive SYSCTL read helper.
 * @summary Confirms that `SYSCTL__enReadRegister` rejects a null register
 *          description before module validation or MCU register access occurs.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original sources under test: SYSCTL_ReadRegister.c and SYSCTL_WriteRegister.c
 * - Public API parameter validation path@endverbatim
 */
TEST(SYSCTL_RegisterPrimitivesTest, ReadRegisterRejectsNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enReadRegister(SYSCTL_enMODULE_0, (SYSCTL_Register_t*) 0UL));
}

/**
 * @brief Validate base-address addition in the primitive SYSCTL read helper.
 * @summary Confirms that `SYSCTL__enReadRegister` validates the module, adds the
 *          SYSCTL block base address to the caller-provided offset, and forwards
 *          the adjusted register description into `MCU__enReadRegister`.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_MCURegisterAccessMock bridge
 * - Original source under test: SYSCTL_ReadRegister.c@endverbatim
 */
TEST(SYSCTL_RegisterPrimitivesTest, ReadRegisterAddsBlockBaseBeforeMCUAccess)
{
    StrictMock<SYSCTL_MCURegisterAccessMock> stMock;
    SYSCTL_MCURegisterAccessMockScope stMockScope(&stMock);
    SYSCTL_Register_t stRegister;

    stRegister.uptrAddress = ALTCLK_CFG_OFFSET;
    stRegister.uxMask = 0xFUL;
    stRegister.uxShift = 2UL;
    stRegister.uxValue = 0UL;

    EXPECT_CALL(stMock, CheckParams((UBase_t) SYSCTL_enMODULE_0, (UBase_t) SYSCTL_enMODULE_MAX))
        .WillOnce(Return(MCU_enERROR_OK));
    EXPECT_CALL(stMock, ReadRegister(testing::_))
        .WillOnce(Invoke([](MCU_Register_t* pstRegisterDataArg) -> MCU_nERROR
        {
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return MCU_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) (SYSCTL_BASE + ALTCLK_CFG_OFFSET), pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) 0xFUL, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) 2UL, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = 3UL;
            return MCU_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enReadRegister(SYSCTL_enMODULE_0, &stRegister));
    EXPECT_EQ((UBase_t) 3UL, stRegister.uxValue);
}

/**
 * @brief Validate base-address addition in the primitive SYSCTL write helper.
 * @summary Confirms that `SYSCTL__enWriteRegister` validates the module, adds the
 *          SYSCTL block base address to the caller-provided offset, and forwards
 *          the adjusted register description into `MCU__enWriteRegister`.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_MCURegisterAccessMock bridge
 * - Original source under test: SYSCTL_WriteRegister.c@endverbatim
 */
TEST(SYSCTL_RegisterPrimitivesTest, WriteRegisterAddsBlockBaseBeforeMCUAccess)
{
    StrictMock<SYSCTL_MCURegisterAccessMock> stMock;
    SYSCTL_MCURegisterAccessMockScope stMockScope(&stMock);
    SYSCTL_Register_t stRegister;

    stRegister.uptrAddress = DIVSCLK_CFG_OFFSET;
    stRegister.uxMask = 0xFFUL;
    stRegister.uxShift = 0UL;
    stRegister.uxValue = 0x2AUL;

    EXPECT_CALL(stMock, CheckParams((UBase_t) SYSCTL_enMODULE_0, (UBase_t) SYSCTL_enMODULE_MAX))
        .WillOnce(Return(MCU_enERROR_OK));
    EXPECT_CALL(stMock, WriteRegister(testing::_))
        .WillOnce(Invoke([](const MCU_Register_t* pstRegisterDataArg) -> MCU_nERROR
        {
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return MCU_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) (SYSCTL_BASE + DIVSCLK_CFG_OFFSET), pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) 0xFFUL, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) 0UL, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) 0x2AUL, pstRegisterDataArg->uxValue);
            return MCU_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enWriteRegister(SYSCTL_enMODULE_0, &stRegister));
}

/**
 * @brief Validate module-parameter error propagation in the primitive SYSCTL write helper.
 * @summary Confirms that `SYSCTL__enWriteRegister` propagates `MCU__enCheckParams`
 *          errors and skips the MCU write path when the module value is invalid.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_MCURegisterAccessMock bridge
 * - Original source under test: SYSCTL_WriteRegister.c@endverbatim
 */
TEST(SYSCTL_RegisterPrimitivesTest, WriteRegisterPropagatesModuleValidationError)
{
    StrictMock<SYSCTL_MCURegisterAccessMock> stMock;
    SYSCTL_MCURegisterAccessMockScope stMockScope(&stMock);
    SYSCTL_Register_t stRegister;

    stRegister.uptrAddress = SYSCTL_MISC_OFFSET;
    stRegister.uxMask = 0x1UL;
    stRegister.uxShift = 1UL;
    stRegister.uxValue = 1UL;

    EXPECT_CALL(stMock, CheckParams((UBase_t) SYSCTL_enMODULE_UNDEF, (UBase_t) SYSCTL_enMODULE_MAX))
        .WillOnce(Return(MCU_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enWriteRegister(SYSCTL_enMODULE_UNDEF, &stRegister));
}