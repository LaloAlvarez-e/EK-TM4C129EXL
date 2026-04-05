/**
 *
 * @file SYSCTL_BootConfig_Test.cpp
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
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_BootConfig.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_BOOTCFG.h>
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
using SYSCTL_BootConfigStateGetter_t = SYSCTL_nERROR (*)(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStateArg);
using SYSCTL_BootConfigValueGetter_t = SYSCTL_nERROR (*)(SYSCTL_nMODULE enModuleArg, UBase_t* puxValueArg);

typedef struct
{
    SYSCTL_BootConfigStateGetter_t pfGetter;
    UBase_t uxMask;
    UBase_t uxShift;
    SYSCTL_nBOOLEAN enExpectedState;
} SYSCTL_BootConfigStateGetterCase_t;

typedef struct
{
    SYSCTL_BootConfigValueGetter_t pfGetter;
    UBase_t uxMask;
    UBase_t uxShift;
    UBase_t uxExpectedValue;
} SYSCTL_BootConfigValueGetterCase_t;

const SYSCTL_BootConfigStateGetterCase_t gstStateGetterCases[] =
{
    {&SYSCTL__enGetBootConfigDebug0, BOOT_CFG_DBG0_MASK, BOOT_CFG_R_DBG0_BIT, SYSCTL_enFALSE},
    {&SYSCTL__enGetBootConfigDebug1, BOOT_CFG_DBG1_MASK, BOOT_CFG_R_DBG1_BIT, SYSCTL_enTRUE},
    {&SYSCTL__enGetBootConfigKey, BOOT_CFG_KEY_MASK, BOOT_CFG_R_KEY_BIT, SYSCTL_enTRUE},
    {&SYSCTL__enGetBootConfigGPIOEnable, BOOT_CFG_EN_MASK, BOOT_CFG_R_EN_BIT, SYSCTL_enFALSE},
    {&SYSCTL__enGetBootConfigGPIOPolarity, BOOT_CFG_POL_MASK, BOOT_CFG_R_POL_BIT, SYSCTL_enTRUE},
    {&SYSCTL__enGetBootConfigNotWritten, BOOT_CFG_NW_MASK, BOOT_CFG_R_NW_BIT, SYSCTL_enTRUE},
};

const SYSCTL_BootConfigValueGetterCase_t gstValueGetterCases[] =
{
    {&SYSCTL__enGetBootConfigGPIOPin, BOOT_CFG_PIN_MASK, BOOT_CFG_R_PIN_BIT, BOOT_CFG_PIN_6},
    {&SYSCTL__enGetBootConfigGPIOPort, BOOT_CFG_PORT_MASK, BOOT_CFG_R_PORT_BIT, BOOT_CFG_PORT_G},
};
}

/**
 * @brief Validate null-pointer rejection in the BOOTCFG state getter family.
 * @summary Confirms that `SYSCTL__enGetBootConfigDebug0` rejects a null output
 *          pointer before attempting the BOOTCFG register read through the
 *          SYSCTL primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_BootConfig.c
 * - Public API parameter validation path@endverbatim
 */
TEST(SYSCTL_BootConfigTest, GetBootConfigDebug0RejectsNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetBootConfigDebug0(SYSCTL_enMODULE_0, (SYSCTL_nBOOLEAN*) 0UL));
}

/**
 * @brief Validate null-pointer rejection in the BOOTCFG value getter family.
 * @summary Confirms that `SYSCTL__enGetBootConfigGPIOPin` rejects a null output
 *          pointer before attempting the BOOTCFG register read through the
 *          SYSCTL primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_BootConfig.c
 * - Public API parameter validation path@endverbatim
 */
TEST(SYSCTL_BootConfigTest, GetBootConfigGPIOPinRejectsNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetBootConfigGPIOPin(SYSCTL_enMODULE_0, (UBase_t*) 0UL));
}

/**
 * @brief Validate BOOTCFG one-bit field routing across the state getters.
 * @summary Confirms that each public BOOTCFG state getter reads the documented
 *          BOOTCFG register using the expected field mask and shift, then
 *          returns the primitive field value as a boolean state.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_BootConfig.c@endverbatim
 */
TEST(SYSCTL_BootConfigTest, StateGettersUseExpectedBOOTCFGMasksAndShifts)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    InSequence stSequence;

    for(const SYSCTL_BootConfigStateGetterCase_t& stCaseReg : gstStateGetterCases)
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
                EXPECT_EQ((uintptr_t) BOOT_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
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
 * @brief Validate BOOTCFG multi-bit field routing across the value getters.
 * @summary Confirms that each public BOOTCFG value getter reads the documented
 *          BOOTCFG register using the expected field mask and shift, then
 *          returns the decoded numeric field value unchanged.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_BootConfig.c@endverbatim
 */
TEST(SYSCTL_BootConfigTest, ValueGettersUseExpectedBOOTCFGMasksAndShifts)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    InSequence stSequence;

    for(const SYSCTL_BootConfigValueGetterCase_t& stCaseReg : gstValueGetterCases)
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
                EXPECT_EQ((uintptr_t) BOOT_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
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
 * @brief Validate read-error propagation in the BOOTCFG state getter family.
 * @summary Confirms that `SYSCTL__enGetBootConfigNotWritten` returns the
 *          SYSCTL primitive read error unchanged and preserves the caller
 *          output value when the BOOTCFG read path fails.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_BootConfig.c@endverbatim
 */
TEST(SYSCTL_BootConfigTest, GetBootConfigNotWrittenPropagatesReadError)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nBOOLEAN enStateReg;

    enStateReg = SYSCTL_enTRUE;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE,
              SYSCTL__enGetBootConfigNotWritten(SYSCTL_enMODULE_0, &enStateReg));
    EXPECT_EQ(SYSCTL_enTRUE, enStateReg);
}

/**
 * @brief Validate read-error propagation in the BOOTCFG value getter family.
 * @summary Confirms that `SYSCTL__enGetBootConfigGPIOPort` returns the SYSCTL
 *          primitive read error unchanged and preserves the caller output value
 *          when the BOOTCFG read path fails.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_BootConfig.c@endverbatim
 */
TEST(SYSCTL_BootConfigTest, GetBootConfigGPIOPortPropagatesReadError)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    UBase_t uxPortReg;

    uxPortReg = BOOT_CFG_PORT_F;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE,
              SYSCTL__enGetBootConfigGPIOPort(SYSCTL_enMODULE_0, &uxPortReg));
    EXPECT_EQ((UBase_t) BOOT_CFG_PORT_F, uxPortReg);
}