/**
 *
 * @file SYSCTL_ResetCause_Test.cpp
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
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_ResetCause.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/xHeader/SYSCTL_RegisterAddress.h>
}

#include <tm4c129e_test/SYSCTL_PrimitivesMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Invoke;
using ::testing::Return;
using ::testing::StrictMock;

/**
 * @brief Validate null-pointer rejection in the reset-cause getter.
 * @summary Confirms that `SYSCTL__enGetResetCause` rejects a null destination
 *          pointer before attempting the RESC register read through the primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_ResetCause.c
 * - Public API parameter validation path@endverbatim
 */
TEST(SYSCTL_ResetCauseTest, GetResetCauseRejectsNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetResetCause(SYSCTL_enMODULE_0, (SYSCTL_nRESET*) 0UL));
}

/**
 * @brief Validate RESC read-field composition in the reset-cause getter.
 * @summary Confirms that `SYSCTL__enGetResetCause` reads the complete reset-cause
 *          bitmask from `SYSCTL_RESC_OFFSET` with zero shift and the documented
 *          `SYSCTL_enRESET_ALL` mask, then returns the primitive value unchanged.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_ResetCause.c@endverbatim
 */
TEST(SYSCTL_ResetCauseTest, GetResetCauseUsesExpectedRESCRegisterMask)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nRESET enCauseReg;

    enCauseReg = SYSCTL_enRESET_UNDEF;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SYSCTL_RESC_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) SYSCTL_enRESET_ALL, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) 0UL, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) SYSCTL_enRESET_SW;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetResetCause(SYSCTL_enMODULE_0, &enCauseReg));
    EXPECT_EQ(SYSCTL_enRESET_SW, enCauseReg);
}

/**
 * @brief Validate read-error propagation in the reset-cause getter.
 * @summary Confirms that `SYSCTL__enGetResetCause` returns the primitive read
 *          error unchanged and preserves the caller output value when the RESC
 *          read path fails.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_ResetCause.c@endverbatim
 */
TEST(SYSCTL_ResetCauseTest, GetResetCausePropagatesReadError)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nRESET enCauseReg;

    enCauseReg = SYSCTL_enRESET_EXTERNAL;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enGetResetCause(SYSCTL_enMODULE_0, &enCauseReg));
    EXPECT_EQ(SYSCTL_enRESET_EXTERNAL, enCauseReg);
}

/**
 * @brief Validate RESC clear-write composition in the reset-cause clearer.
 * @summary Confirms that `SYSCTL__enClearResetCause` writes `SYSCTL_RESC_OFFSET`
 *          with zero shift, a mask equal to the selected reset-cause bitmask, and
 *          a zero write value through the primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_ResetCause.c@endverbatim
 */
TEST(SYSCTL_ResetCauseTest, ClearResetCauseUsesExpectedRESCRegisterMask)
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
            EXPECT_EQ((uintptr_t) SYSCTL_RESC_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) SYSCTL_enRESET_MOSC_FAILURE, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) 0UL, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) 0UL, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enClearResetCause(SYSCTL_enMODULE_0, SYSCTL_enRESET_MOSC_FAILURE));
}