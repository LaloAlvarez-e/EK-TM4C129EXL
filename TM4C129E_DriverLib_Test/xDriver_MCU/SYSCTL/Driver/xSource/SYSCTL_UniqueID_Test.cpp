/**
 *
 * @file SYSCTL_UniqueID_Test.cpp
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
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_UniqueID.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_UNIQUEID.h>
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
using SYSCTL_UniqueIDGetter_t = SYSCTL_nERROR (*)(SYSCTL_nMODULE enModuleArg, UBase_t* puxValueArg);

typedef struct
{
    SYSCTL_UniqueIDGetter_t pfGetter;
    uintptr_t uptrAddress;
    UBase_t uxMask;
    UBase_t uxShift;
    UBase_t uxExpectedValue;
} SYSCTL_UniqueIDGetterCase_t;

const SYSCTL_UniqueIDGetterCase_t gstGetterCases[] =
{
    {&SYSCTL__enGetUniqueID0, UNIQUE_ID0_OFFSET, UNIQUE_ID0_R_ID_MASK, UNIQUE_ID0_R_ID_BIT, (UBase_t) 0x01234567UL},
    {&SYSCTL__enGetUniqueID1, UNIQUE_ID1_OFFSET, UNIQUE_ID1_R_ID_MASK, UNIQUE_ID1_R_ID_BIT, (UBase_t) 0x89ABCDEFUL},
    {&SYSCTL__enGetUniqueID2, UNIQUE_ID2_OFFSET, UNIQUE_ID2_R_ID_MASK, UNIQUE_ID2_R_ID_BIT, (UBase_t) 0x55AA55AAUL},
    {&SYSCTL__enGetUniqueID3, UNIQUE_ID3_OFFSET, UNIQUE_ID3_R_ID_MASK, UNIQUE_ID3_R_ID_BIT, (UBase_t) 0xC33CC33CUL},
};
}

/**
 * @brief Validate null-pointer rejection in the Unique ID getter family.
 * @summary Confirms that `SYSCTL__enGetUniqueID0` rejects a null output pointer
 *          before attempting the UNIQUEID register read through the SYSCTL
 *          primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_UniqueID.c
 * - Public API parameter validation path@endverbatim
 */
TEST(SYSCTL_UniqueIDTest, GetUniqueID0RejectsNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetUniqueID0(SYSCTL_enMODULE_0, (UBase_t*) 0UL));
}

/**
 * @brief Validate UNIQUEID register routing across the Unique ID getter family.
 * @summary Confirms that each public Unique ID getter reads the documented
 *          UNIQUEID0 through UNIQUEID3 offset with the expected full-width mask
 *          and shift, then returns the raw identifier word unchanged.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_UniqueID.c@endverbatim
 */
TEST(SYSCTL_UniqueIDTest, GettersUseExpectedUniqueIDOffsetsMasksAndShifts)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);

    for(const SYSCTL_UniqueIDGetterCase_t& stCaseReg : gstGetterCases)
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
 * @brief Validate read-error propagation in the Unique ID getter family.
 * @summary Confirms that `SYSCTL__enGetUniqueID2` returns the SYSCTL primitive
 *          read error unchanged and preserves the caller output value when the
 *          UNIQUEID read path fails.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_UniqueID.c@endverbatim
 */
TEST(SYSCTL_UniqueIDTest, GetUniqueID2PropagatesReadError)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    UBase_t uxUniqueID2Reg;

    uxUniqueID2Reg = (UBase_t) 0x55AA55AAUL;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE,
              SYSCTL__enGetUniqueID2(SYSCTL_enMODULE_0, &uxUniqueID2Reg));
    EXPECT_EQ((UBase_t) 0x55AA55AAUL, uxUniqueID2Reg);
}