/**
 *
 * @file SYSCTL_UserRegisters_Test.cpp
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
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_UserRegisters.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_USER_REG.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/xHeader/SYSCTL_RegisterAddress.h>
}

#include <tm4c129e_test/SYSCTL_PrimitivesMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Invoke;
using ::testing::Return;
using ::testing::StrictMock;

namespace
{
using SYSCTL_UserRegisterGetter_t = SYSCTL_nERROR (*)(SYSCTL_nMODULE enModuleArg, UBase_t* puxValueArg);

typedef struct
{
    SYSCTL_UserRegisterGetter_t pfGetter;
    uintptr_t uptrAddress;
    UBase_t uxMask;
    UBase_t uxShift;
    UBase_t uxExpectedValue;
} SYSCTL_UserRegisterGetterCase_t;

const SYSCTL_UserRegisterGetterCase_t gstGetterCases[] =
{
    {&SYSCTL__enGetUserRegister0, USER_REG0_OFFSET, USER_REG0_DATA_MASK, USER_REG0_R_DATA_BIT, (UBase_t) 0x01234567UL},
    {&SYSCTL__enGetUserRegister1, USER_REG1_OFFSET, USER_REG1_DATA_MASK, USER_REG1_R_DATA_BIT, (UBase_t) 0x89ABCDEFUL},
    {&SYSCTL__enGetUserRegister2, USER_REG2_OFFSET, USER_REG2_DATA_MASK, USER_REG2_R_DATA_BIT, (UBase_t) 0x55AA55AAUL},
    {&SYSCTL__enGetUserRegister3, USER_REG3_OFFSET, USER_REG3_DATA_MASK, USER_REG3_R_DATA_BIT, (UBase_t) 0xC33CC33CUL},
};
}

/**
 * @brief Validate null-pointer rejection in the USER_REG getter family.
 * @summary Confirms that `SYSCTL__enGetUserRegister0` rejects a null output
 *          pointer before attempting the USER_REG register read through the
 *          SYSCTL primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_UserRegisters.c
 * - Public API parameter validation path@endverbatim
 */
TEST(SYSCTL_UserRegistersTest, GetUserRegister0RejectsNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetUserRegister0(SYSCTL_enMODULE_0, (UBase_t*) 0UL));
}

/**
 * @brief Validate USER_REG offset routing across the user-register getter family.
 * @summary Confirms that each public USER_REG getter reads the documented
 *          USER_REG0 through USER_REG3 offset with the expected full-width mask
 *          and shift, then returns the raw register word unchanged.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_UserRegisters.c@endverbatim
 */
TEST(SYSCTL_UserRegistersTest, GettersUseExpectedUserRegisterOffsetsMasksAndShifts)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);

    for(const SYSCTL_UserRegisterGetterCase_t& stCaseReg : gstGetterCases)
    {
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke([&stCaseReg](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
            {
                EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
                EXPECT_NE(nullptr, pstRegisterDataArg);
                if(nullptr == pstRegisterDataArg)
                {
                    return SYSCTL_enERROR_POINTER;
                }
                EXPECT_EQ(stCaseReg.uptrAddress, pstRegisterDataArg->uptrAddress);
                EXPECT_EQ(stCaseReg.uxMask, pstRegisterDataArg->uxMask);
                EXPECT_EQ(stCaseReg.uxShift, pstRegisterDataArg->uxShift);
                pstRegisterDataArg->uxValue = stCaseReg.uxExpectedValue;
                return SYSCTL_enERROR_OK;
            }));

        UBase_t uxValueReg;
        uxValueReg = 0UL;
        EXPECT_EQ(SYSCTL_enERROR_OK, stCaseReg.pfGetter(SYSCTL_enMODULE_0, &uxValueReg));
        EXPECT_EQ(stCaseReg.uxExpectedValue, uxValueReg);
    }
}

/**
 * @brief Validate read-error propagation in the USER_REG getter family.
 * @summary Confirms that `SYSCTL__enGetUserRegister2` returns the SYSCTL
 *          primitive read error unchanged and preserves the caller output value
 *          when the USER_REG read path fails.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_UserRegisters.c@endverbatim
 */
TEST(SYSCTL_UserRegistersTest, GetUserRegister2PropagatesReadError)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    UBase_t uxUserRegister2Reg;

    uxUserRegister2Reg = (UBase_t) 0x55AA55AAUL;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE,
              SYSCTL__enGetUserRegister2(SYSCTL_enMODULE_0, &uxUserRegister2Reg));
    EXPECT_EQ((UBase_t) 0x55AA55AAUL, uxUserRegister2Reg);
}