/**
 *
 * @file SYSCTL_NMICause_Test.cpp
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
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_NMICause.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/xHeader/SYSCTL_RegisterAddress.h>
}

#include <tm4c129e_test/SYSCTL_PrimitivesMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Invoke;
using ::testing::Return;
using ::testing::StrictMock;

/**
 * @brief Validate null-pointer rejection in the NMI-cause getter.
 * @summary Confirms that `SYSCTL__enGetNMICause` rejects a null destination
 *          pointer before attempting the NMIC register read through the primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_NMICause.c
 * - Public API parameter validation path@endverbatim
 */
TEST(SYSCTL_NMICauseTest, GetNMICauseRejectsNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetNMICause(SYSCTL_enMODULE_0, (SYSCTL_nNMI*) 0UL));
}

/**
 * @brief Validate NMIC read-field composition in the NMI-cause getter.
 * @summary Confirms that `SYSCTL__enGetNMICause` reads the complete NMI-cause
 *          bitmask from `SYSCTL_NMIC_OFFSET` with zero shift and the documented
 *          `SYSCTL_enNMI_ALL` mask, then returns the primitive value unchanged.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_NMICause.c@endverbatim
 */
TEST(SYSCTL_NMICauseTest, GetNMICauseUsesExpectedNMICRegisterMask)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nNMI enCauseReg;

    enCauseReg = SYSCTL_enNMI_UNDEF;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SYSCTL_NMIC_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) SYSCTL_enNMI_ALL, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) 0UL, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) SYSCTL_enNMI_MOSC_FAILURE;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetNMICause(SYSCTL_enMODULE_0, &enCauseReg));
    EXPECT_EQ(SYSCTL_enNMI_MOSC_FAILURE, enCauseReg);
}

/**
 * @brief Validate read-error propagation in the NMI-cause getter.
 * @summary Confirms that `SYSCTL__enGetNMICause` returns the primitive read
 *          error unchanged and preserves the caller output value when the NMIC
 *          read path fails.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_NMICause.c@endverbatim
 */
TEST(SYSCTL_NMICauseTest, GetNMICausePropagatesReadError)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nNMI enCauseReg;

    enCauseReg = SYSCTL_enNMI_EXTERNAL;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enGetNMICause(SYSCTL_enMODULE_0, &enCauseReg));
    EXPECT_EQ(SYSCTL_enNMI_EXTERNAL, enCauseReg);
}

/**
 * @brief Validate NMIC clear-write composition in the NMI-cause clearer.
 * @summary Confirms that `SYSCTL__enClearNMICause` writes `SYSCTL_NMIC_OFFSET`
 *          with zero shift, a mask equal to the selected NMI-cause bitmask, and
 *          a zero write value through the primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_NMICause.c@endverbatim
 */
TEST(SYSCTL_NMICauseTest, ClearNMICauseUsesExpectedNMICRegisterMask)
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
            EXPECT_EQ((uintptr_t) SYSCTL_NMIC_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) SYSCTL_enNMI_MOSC_FAILURE, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) 0UL, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) 0UL, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enClearNMICause(SYSCTL_enMODULE_0, SYSCTL_enNMI_MOSC_FAILURE));
}