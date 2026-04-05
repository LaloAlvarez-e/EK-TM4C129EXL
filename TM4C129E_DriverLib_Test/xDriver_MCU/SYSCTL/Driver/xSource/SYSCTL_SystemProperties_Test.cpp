/**
 *
 * @file SYSCTL_SystemProperties_Test.cpp
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
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_SystemProperties.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_SYSPROP.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/xHeader/SYSCTL_RegisterAddress.h>
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
using SYSCTL_SystemPropertyGetter_t = SYSCTL_nERROR (*)(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStateArg);

typedef struct
{
    SYSCTL_SystemPropertyGetter_t pfGetter;
    UBase_t uxMask;
    UBase_t uxShift;
    SYSCTL_nBOOLEAN enExpectedState;
} SYSCTL_SystemPropertyGetterCase_t;

const SYSCTL_SystemPropertyGetterCase_t gstGetterCases[] =
{
    {&SYSCTL__enIsFPUPresent, SYSCTL_PROP_FPU_MASK, SYSCTL_PROP_R_FPU_BIT, SYSCTL_enTRUE},
    {&SYSCTL__enIsLDOSequenceSupported, SYSCTL_PROP_LDO_SEQ_MASK, SYSCTL_PROP_R_LDO_SEQ_BIT, SYSCTL_enTRUE},
    {&SYSCTL__enIsFlashLowPowerModeSupported, SYSCTL_PROP_FLASH_LPM_MASK, SYSCTL_PROP_R_FLASH_LPM_BIT, SYSCTL_enFALSE},
    {&SYSCTL__enIsSRAMLowPowerModeSupported, SYSCTL_PROP_SRAM_LPM_MASK, SYSCTL_PROP_R_SRAM_LPM_BIT, SYSCTL_enTRUE},
    {&SYSCTL__enIsSRAMStandbyModeSupported, SYSCTL_PROP_SRAM_SM_MASK, SYSCTL_PROP_R_SRAM_SM_BIT, SYSCTL_enFALSE},
    {&SYSCTL__enIsPIOSCPowerDownModeSupported, SYSCTL_PROP_PIOSC_PDE_MASK, SYSCTL_PROP_R_PIOSC_PDE_BIT, SYSCTL_enTRUE},
    {&SYSCTL__enIsTempSensorPowerDownModeSupported, SYSCTL_PROP_TS_PDE_MASK, SYSCTL_PROP_R_TS_PDE_BIT, SYSCTL_enFALSE},
    {&SYSCTL__enIsLDOSleepModeSupported, SYSCTL_PROP_LDO_SME_MASK, SYSCTL_PROP_R_LDO_SME_BIT, SYSCTL_enTRUE},
};
}

/**
 * @brief Validate null-pointer rejection in the SYSPROP getter family.
 * @summary Confirms that `SYSCTL__enIsFPUPresent` rejects a null output
 *          pointer before attempting the SYSPROP register read through the
 *          SYSCTL primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_SystemProperties.c
 * - Public API parameter validation path@endverbatim
 */
TEST(SYSCTL_SystemPropertiesTest, IsFPUPresentRejectsNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enIsFPUPresent(SYSCTL_enMODULE_0, (SYSCTL_nBOOLEAN*) 0UL));
}

/**
 * @brief Validate SYSPROP field routing across the system-properties getters.
 * @summary Confirms that each public SYSPROP getter reads the documented
 *          `SYSPROP` register using the expected field mask and shift, then
 *          returns the primitive field value as a boolean support state.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_SystemProperties.c@endverbatim
 */
TEST(SYSCTL_SystemPropertiesTest, GettersUseExpectedSYSPROPMasksAndShifts)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    InSequence stSequence;

    for(const SYSCTL_SystemPropertyGetterCase_t& stCaseReg : gstGetterCases)
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
                EXPECT_EQ((uintptr_t) SYSCTL_PROP_OFFSET, pstRegisterDataArg->uptrAddress);
                EXPECT_EQ(stCaseReg.uxMask, pstRegisterDataArg->uxMask);
                EXPECT_EQ(stCaseReg.uxShift, pstRegisterDataArg->uxShift);
                pstRegisterDataArg->uxValue = (UBase_t) stCaseReg.enExpectedState;
                return SYSCTL_enERROR_OK;
            }));

        SYSCTL_nBOOLEAN enStateReg;
        enStateReg = SYSCTL_enFALSE;
        EXPECT_EQ(SYSCTL_enERROR_OK, stCaseReg.pfGetter(SYSCTL_enMODULE_0, &enStateReg));
        EXPECT_EQ(stCaseReg.enExpectedState, enStateReg);
    }
}

/**
 * @brief Validate read-error propagation in the SYSPROP getter family.
 * @summary Confirms that `SYSCTL__enIsLDOSleepModeSupported` returns the
 *          SYSCTL primitive read error unchanged and preserves the caller
 *          output value when the SYSPROP read path fails.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_SystemProperties.c@endverbatim
 */
TEST(SYSCTL_SystemPropertiesTest, IsLDOSleepModeSupportedPropagatesReadError)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nBOOLEAN enStateReg;

    enStateReg = SYSCTL_enTRUE;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE,
              SYSCTL__enIsLDOSleepModeSupported(SYSCTL_enMODULE_0, &enStateReg));
    EXPECT_EQ(SYSCTL_enTRUE, enStateReg);
}