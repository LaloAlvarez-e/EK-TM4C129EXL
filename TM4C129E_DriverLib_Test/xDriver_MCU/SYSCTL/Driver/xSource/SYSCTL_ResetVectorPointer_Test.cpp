/**
 *
 * @file SYSCTL_ResetVectorPointer_Test.cpp
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
 * @verbatim 4 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 4 abr. 2026    GitHub Copilot   1.0         initial Version@endverbatim
 */

extern "C"
{
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_ResetVectorPointer.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_RVP.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/xHeader/SYSCTL_RegisterAddress.h>
}

#include <tm4c129e_test/SYSCTL_PrimitivesMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Invoke;
using ::testing::Return;
using ::testing::StrictMock;

/**
 * @brief Validate null-pointer rejection in the reset-vector-pointer getter.
 * @summary Confirms that `SYSCTL__enGetResetVectorPointer` rejects a null
 *          output pointer before attempting the RVP register read through the
 *          SYSCTL primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_ResetVectorPointer.c
 * - Public API parameter validation path@endverbatim
 */
TEST(SYSCTL_ResetVectorPointerTest, GetResetVectorPointerRejectsNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetResetVectorPointer(SYSCTL_enMODULE_0, (UBase_t*) 0UL));
}

/**
 * @brief Validate RVP field routing in the reset-vector-pointer getter.
 * @summary Confirms that `SYSCTL__enGetResetVectorPointer` reads the documented
 *          RVP offset with the expected mask and shift, then returns the raw
 *          reset-vector address unchanged.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_ResetVectorPointer.c@endverbatim
 */
TEST(SYSCTL_ResetVectorPointerTest, GetResetVectorPointerUsesExpectedOffsetMaskAndShift)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    UBase_t uxResetVectorPointerReg;

    uxResetVectorPointerReg = 0UL;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SYSCTL_RVP_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) SYSCTL_RVP_R_RV_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) SYSCTL_RVP_R_RV_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) SYSCTL_RVP_R_RV_ADDRESS;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enGetResetVectorPointer(SYSCTL_enMODULE_0, &uxResetVectorPointerReg));
    EXPECT_EQ((UBase_t) SYSCTL_RVP_R_RV_ADDRESS, uxResetVectorPointerReg);
}

/**
 * @brief Validate read-error propagation in the reset-vector-pointer getter.
 * @summary Confirms that `SYSCTL__enGetResetVectorPointer` returns the SYSCTL
 *          primitive read error unchanged and preserves the caller output value
 *          when the RVP read path fails.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_ResetVectorPointer.c@endverbatim
 */
TEST(SYSCTL_ResetVectorPointerTest, GetResetVectorPointerPropagatesReadError)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    UBase_t uxResetVectorPointerReg;

    uxResetVectorPointerReg = (UBase_t) SYSCTL_RVP_R_RV_ADDRESS;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE,
              SYSCTL__enGetResetVectorPointer(SYSCTL_enMODULE_0, &uxResetVectorPointerReg));
    EXPECT_EQ((UBase_t) SYSCTL_RVP_R_RV_ADDRESS, uxResetVectorPointerReg);
}