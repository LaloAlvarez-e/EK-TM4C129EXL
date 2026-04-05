/**
 *
 * @file SYSCTL_DeviceID_Test.cpp
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

#include <array>

extern "C"
{
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_DeviceID.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/xHeader/SYSCTL_RegisterAddress.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_DID.h>
}

#include <tm4c129e_test/SYSCTL_PrimitivesMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::InSequence;
using ::testing::Invoke;
using ::testing::Return;
using ::testing::StrictMock;

namespace
{
using SYSCTL_DeviceIDGetter_t = SYSCTL_nERROR (*)(SYSCTL_nMODULE enModuleArg, UBase_t* puxValueArg);

typedef struct
{
    SYSCTL_DeviceIDGetter_t pfGetter;
    uintptr_t uptrAddress;
    UBase_t uxMask;
    UBase_t uxShift;
    UBase_t uxExpectedValue;
} SYSCTL_DeviceIDGetterCase_t;

const SYSCTL_DeviceIDGetterCase_t gstGetterCases[] =
{
    {&SYSCTL__enGetDID0Version, DEVICE_ID0_OFFSET, DEVICE_ID0_R_VERSION_MASK, DEVICE_ID0_R_VERSION_BIT, DEVICE_ID0_VERSION_DID0},
    {&SYSCTL__enGetDID0Class, DEVICE_ID0_OFFSET, DEVICE_ID0_R_CLASS_MASK, DEVICE_ID0_R_CLASS_BIT, DEVICE_ID0_CLASS_TIVAS},
    {&SYSCTL__enGetDID0MajorRevision, DEVICE_ID0_OFFSET, DEVICE_ID0_R_MAJOR_REVISION_MASK, DEVICE_ID0_R_MAJOR_REVISION_BIT, DEVICE_ID0_MAJOR_REVISION_REVC},
    {&SYSCTL__enGetDID0MinorRevision, DEVICE_ID0_OFFSET, DEVICE_ID0_R_MINOR_REVISION_MASK, DEVICE_ID0_R_MINOR_REVISION_BIT, DEVICE_ID0_MINOR_REVISION_2METAL},
    {&SYSCTL__enGetDID1Version, DEVICE_ID1_OFFSET, DEVICE_ID1_R_VERSION_MASK, DEVICE_ID1_R_VERSION_BIT, DEVICE_ID1_VERSION_SECOND},
    {&SYSCTL__enGetDID1Family, DEVICE_ID1_OFFSET, DEVICE_ID1_R_FAMILY_MASK, DEVICE_ID1_R_FAMILY_BIT, DEVICE_ID1_FAMILY_TIVAC},
    {&SYSCTL__enGetDID1PartNo, DEVICE_ID1_OFFSET, DEVICE_ID1_R_PARTNO_MASK, DEVICE_ID1_R_PARTNO_BIT, DEVICE_ID1_PARTNO_TM4C123E},
    {&SYSCTL__enGetDID1PinCount, DEVICE_ID1_OFFSET, DEVICE_ID1_R_PINCOUNT_MASK, DEVICE_ID1_R_PINCOUNT_BIT, DEVICE_ID1_PINCOUNT_144},
    {&SYSCTL__enGetDID1TempRange, DEVICE_ID1_OFFSET, DEVICE_ID1_R_TEMP_MASK, DEVICE_ID1_R_TEMP_BIT, DEVICE_ID1_TEMP_EXT},
    {&SYSCTL__enGetDID1Package, DEVICE_ID1_OFFSET, DEVICE_ID1_R_PKG_MASK, DEVICE_ID1_R_PKG_BIT, DEVICE_ID1_PKG_BGA},
    {&SYSCTL__enGetDID1RoHS, DEVICE_ID1_OFFSET, DEVICE_ID1_R_ROHS_MASK, DEVICE_ID1_R_ROHS_BIT, DEVICE_ID1_ROHS_ROHS},
    {&SYSCTL__enGetDID1Qualification, DEVICE_ID1_OFFSET, DEVICE_ID1_R_QUAL_MASK, DEVICE_ID1_R_QUAL_BIT, DEVICE_ID1_QUAL_FULLY},
};
}

/**
 * @brief Validate null-pointer rejection in the DID getter family.
 * @summary Confirms that `SYSCTL__enGetDID0MinorRevision` rejects a null output
 *          pointer before attempting the DID register read through the SYSCTL
 *          primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_DeviceID.c
 * - Public API parameter validation path@endverbatim
 */
TEST(SYSCTL_DeviceIDTest, GetDID0MinorRevisionRejectsNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetDID0MinorRevision(SYSCTL_enMODULE_0, (UBase_t*) 0UL));
}

/**
 * @brief Validate DID0 and DID1 field routing across the Device ID getter family.
 * @summary Confirms that each public DID getter reads the documented DID0 or
 *          DID1 register offset with the expected mask and shift, then returns
 *          the primitive field value unchanged.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_DeviceID.c@endverbatim
 */
TEST(SYSCTL_DeviceIDTest, GettersUseExpectedDIDOffsetsMasksAndShifts)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    InSequence stSequence;

    for(const SYSCTL_DeviceIDGetterCase_t& stCaseReg : gstGetterCases)
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
 * @brief Validate read-error propagation in the DID getter family.
 * @summary Confirms that `SYSCTL__enGetDID1Version` returns the SYSCTL
 *          primitive read error unchanged and preserves the caller output value
 *          when the DID1 read path fails.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_DeviceID.c@endverbatim
 */
TEST(SYSCTL_DeviceIDTest, GetDID1VersionPropagatesReadError)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    UBase_t uxVersionReg;

    uxVersionReg = DEVICE_ID1_VERSION_INI;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE,
              SYSCTL__enGetDID1Version(SYSCTL_enMODULE_0, &uxVersionReg));
    EXPECT_EQ((UBase_t) DEVICE_ID1_VERSION_INI, uxVersionReg);
}