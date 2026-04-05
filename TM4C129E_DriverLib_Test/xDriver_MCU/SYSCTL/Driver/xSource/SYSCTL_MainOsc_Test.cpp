/**
 *
 * @file SYSCTL_MainOsc_Test.cpp
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
 * @verbatim 02 apr. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 02 apr. 2026   GitHub Copilot   1.0         initial Version@endverbatim
 */

extern "C"
{
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_MainOsc.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_MOSCCTL.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/xHeader/SYSCTL_RegisterAddress.h>
}

#include <tm4c129e_test/SYSCTL_PrimitivesMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Invoke;
using ::testing::StrictMock;

namespace
{

auto MakeWriteRegisterAction(uintptr_t uptrAddressArg,
                             UBase_t uxMaskArg,
                             UBase_t uxShiftArg,
                             UBase_t uxValueArg,
                             SYSCTL_nERROR enErrorArg = SYSCTL_enERROR_OK)
{
    return [=](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
    {
        EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
        EXPECT_NE(nullptr, pstRegisterDataArg);
        if(nullptr == pstRegisterDataArg)
        {
            return SYSCTL_enERROR_POINTER;
        }

        EXPECT_EQ(uptrAddressArg, pstRegisterDataArg->uptrAddress);
        EXPECT_EQ(uxMaskArg, pstRegisterDataArg->uxMask);
        EXPECT_EQ(uxShiftArg, pstRegisterDataArg->uxShift);
        EXPECT_EQ(uxValueArg, pstRegisterDataArg->uxValue);
        return enErrorArg;
    };
}

auto MakeReadRegisterAction(uintptr_t uptrAddressArg,
                            UBase_t uxMaskArg,
                            UBase_t uxShiftArg,
                            UBase_t uxValueArg,
                            SYSCTL_nERROR enErrorArg = SYSCTL_enERROR_OK)
{
    return [=](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
    {
        EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
        EXPECT_NE(nullptr, pstRegisterDataArg);
        if(nullptr == pstRegisterDataArg)
        {
            return SYSCTL_enERROR_POINTER;
        }

        EXPECT_EQ(uptrAddressArg, pstRegisterDataArg->uptrAddress);
        EXPECT_EQ(uxMaskArg, pstRegisterDataArg->uxMask);
        EXPECT_EQ(uxShiftArg, pstRegisterDataArg->uxShift);
        if(SYSCTL_enERROR_OK == enErrorArg)
        {
            pstRegisterDataArg->uxValue = uxValueArg;
        }
        return enErrorArg;
    };
}

}

/**
 * @brief Validate CVAL-field programming in the MOSC monitor setter.
 * @summary Confirms that `SYSCTL__enSetMOSCMonitorState` writes the documented
 *          `MOSCCTL.CVAL` field with the caller-provided state.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_MainOsc.c
 * - SYSCTL MOSCCTL register definitions@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MOSCCTL-001@endverbatim
 */
TEST(SYSCTL_MainOscTest, SetMOSCMonitorStateUsesExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeWriteRegisterAction(MOSC_CTL_OFFSET,
                                                 MOSC_CTL_CVAL_MASK,
                                                 MOSC_CTL_R_CVAL_BIT,
                                                 (UBase_t) SYSCTL_enSTATE_ENA)));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetMOSCMonitorState(SYSCTL_enMODULE_0, SYSCTL_enSTATE_ENA));
}

/**
 * @brief Validate MOSCIM-field programming in the failure-action setter.
 * @summary Confirms that `SYSCTL__enSetMOSCFailureAction` writes the documented
 *          `MOSCCTL.MOSCIM` field with the caller-provided failure action.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_MainOsc.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MOSCCTL-002@endverbatim
 */
TEST(SYSCTL_MainOscTest, SetMOSCFailureActionUsesExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeWriteRegisterAction(MOSC_CTL_OFFSET,
                                                 MOSC_CTL_MOSCIM_MASK,
                                                 MOSC_CTL_R_MOSCIM_BIT,
                                                 (UBase_t) SYSCTL_enMOSC_FAILURE_SYSINT)));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetMOSCFailureAction(SYSCTL_enMODULE_0, SYSCTL_enMOSC_FAILURE_SYSINT));
}

/**
 * @brief Validate NOXTAL-field encodings in the MOSC state setter.
 * @summary Confirms that `SYSCTL__enSetMOSCState` translates the public enabled
 *          and disabled states into the documented `MOSCCTL.NOXTAL` field encodings.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_MainOsc.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MOSCCTL-003@endverbatim
 */
TEST(SYSCTL_MainOscTest, SetMOSCStateMapsPublicStateToNOXTALField)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(MOSC_CTL_OFFSET,
                                                     MOSC_CTL_NOXTAL_MASK,
                                                     MOSC_CTL_R_NOXTAL_BIT,
                                                     (UBase_t) MOSC_CTL_NOXTAL_CONNECTED)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enSetMOSCState(SYSCTL_enMODULE_0, SYSCTL_enSTATE_ENA));
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(MOSC_CTL_OFFSET,
                                                     MOSC_CTL_NOXTAL_MASK,
                                                     MOSC_CTL_R_NOXTAL_BIT,
                                                     (UBase_t) MOSC_CTL_NOXTAL_NOCONNECTED)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enSetMOSCState(SYSCTL_enMODULE_0, SYSCTL_enSTATE_DIS));
    }
}

/**
 * @brief Validate PWRDN-field encodings in the MOSC power-state setter.
 * @summary Confirms that `SYSCTL__enSetMOSCPowerState` translates the public
 *          enabled and disabled states into the documented `MOSCCTL.PWRDN` encodings.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_MainOsc.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MOSCCTL-004@endverbatim
 */
TEST(SYSCTL_MainOscTest, SetMOSCPowerStateMapsPublicStateToPWRDNField)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(MOSC_CTL_OFFSET,
                                                     MOSC_CTL_PWRDN_MASK,
                                                     MOSC_CTL_R_PWRDN_BIT,
                                                     (UBase_t) MOSC_CTL_PWRDN_POWERUP)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enSetMOSCPowerState(SYSCTL_enMODULE_0, SYSCTL_enSTATE_ENA));
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(MOSC_CTL_OFFSET,
                                                     MOSC_CTL_PWRDN_MASK,
                                                     MOSC_CTL_R_PWRDN_BIT,
                                                     (UBase_t) MOSC_CTL_PWRDN_POWERDOWN)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enSetMOSCPowerState(SYSCTL_enMODULE_0, SYSCTL_enSTATE_DIS));
    }
}

/**
 * @brief Validate OSCRNG-field programming in the MOSC frequency-range setter.
 * @summary Confirms that `SYSCTL__enSetMOSCFrequencyRange` writes the documented
 *          `MOSCCTL.OSCRNG` field with the caller-provided range enum.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_MainOsc.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MOSCCTL-005@endverbatim
 */
TEST(SYSCTL_MainOscTest, SetMOSCFrequencyRangeUsesExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeWriteRegisterAction(MOSC_CTL_OFFSET,
                                                 MOSC_CTL_OSCRNG_MASK,
                                                 MOSC_CTL_R_OSCRNG_BIT,
                                                 (UBase_t) SYSCTL_enMOSC_RANGE_HIGH)));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetMOSCFrequencyRange(SYSCTL_enMODULE_0, SYSCTL_enMOSC_RANGE_HIGH));
}

/**
 * @brief Validate null-pointer rejection across the MOSC getter family.
 * @summary Confirms that the MOSC monitor, failure-action, state, power-state,
 *          and frequency-range getters reject null output pointers before any
 *          primitive register access occurs.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_MainOsc.c
 * - Public API parameter validation path@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MOSCCTL-006@endverbatim
 */
TEST(SYSCTL_MainOscTest, MOSCGettersRejectNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetMOSCMonitorState(SYSCTL_enMODULE_0, (SYSCTL_nSTATE*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetMOSCFailureAction(SYSCTL_enMODULE_0, (SYSCTL_nMOSC_FAILURE*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetMOSCState(SYSCTL_enMODULE_0, (SYSCTL_nSTATE*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetMOSCPowerState(SYSCTL_enMODULE_0, (SYSCTL_nSTATE*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetMOSCFrequencyRange(SYSCTL_enMODULE_0, (SYSCTL_nMOSC_RANGE*) 0UL));
}

/**
 * @brief Validate CVAL-field reads in the MOSC monitor getter.
 * @summary Confirms that `SYSCTL__enGetMOSCMonitorState` reads the documented
 *          `MOSCCTL.CVAL` field and returns the decoded public state.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_MainOsc.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MOSCCTL-007@endverbatim
 */
TEST(SYSCTL_MainOscTest, GetMOSCMonitorStateUsesExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nSTATE enStateReg;

    enStateReg = SYSCTL_enSTATE_DIS;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(MOSC_CTL_OFFSET,
                                                MOSC_CTL_CVAL_MASK,
                                                MOSC_CTL_R_CVAL_BIT,
                                                (UBase_t) SYSCTL_enSTATE_ENA)));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetMOSCMonitorState(SYSCTL_enMODULE_0, &enStateReg));
    EXPECT_EQ(SYSCTL_enSTATE_ENA, enStateReg);
}

/**
 * @brief Validate MOSCIM-field reads in the MOSC failure-action getter.
 * @summary Confirms that `SYSCTL__enGetMOSCFailureAction` reads the documented
 *          `MOSCCTL.MOSCIM` field and returns the decoded public action enum.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_MainOsc.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MOSCCTL-008@endverbatim
 */
TEST(SYSCTL_MainOscTest, GetMOSCFailureActionUsesExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nMOSC_FAILURE enActionReg;

    enActionReg = SYSCTL_enMOSC_FAILURE_RESET;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(MOSC_CTL_OFFSET,
                                                MOSC_CTL_MOSCIM_MASK,
                                                MOSC_CTL_R_MOSCIM_BIT,
                                                (UBase_t) SYSCTL_enMOSC_FAILURE_SYSINT)));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetMOSCFailureAction(SYSCTL_enMODULE_0, &enActionReg));
    EXPECT_EQ(SYSCTL_enMOSC_FAILURE_SYSINT, enActionReg);
}

/**
 * @brief Validate NOXTAL-field decoding in the MOSC state getter.
 * @summary Confirms that `SYSCTL__enGetMOSCState` translates the documented
 *          connected and no-crystal `MOSCCTL.NOXTAL` encodings into public states.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_MainOsc.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MOSCCTL-009@endverbatim
 */
TEST(SYSCTL_MainOscTest, GetMOSCStateMapsNOXTALFieldToPublicState)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nSTATE enStateReg;

        enStateReg = SYSCTL_enSTATE_DIS;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(MOSC_CTL_OFFSET,
                                                    MOSC_CTL_NOXTAL_MASK,
                                                    MOSC_CTL_R_NOXTAL_BIT,
                                                    (UBase_t) MOSC_CTL_NOXTAL_CONNECTED)));

        EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetMOSCState(SYSCTL_enMODULE_0, &enStateReg));
        EXPECT_EQ(SYSCTL_enSTATE_ENA, enStateReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nSTATE enStateReg;

        enStateReg = SYSCTL_enSTATE_ENA;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(MOSC_CTL_OFFSET,
                                                    MOSC_CTL_NOXTAL_MASK,
                                                    MOSC_CTL_R_NOXTAL_BIT,
                                                    (UBase_t) MOSC_CTL_NOXTAL_NOCONNECTED)));

        EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetMOSCState(SYSCTL_enMODULE_0, &enStateReg));
        EXPECT_EQ(SYSCTL_enSTATE_DIS, enStateReg);
    }
}

/**
 * @brief Validate PWRDN-field decoding in the MOSC power-state getter.
 * @summary Confirms that `SYSCTL__enGetMOSCPowerState` translates the documented
 *          power-up and power-down `MOSCCTL.PWRDN` encodings into public states.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_MainOsc.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MOSCCTL-010@endverbatim
 */
TEST(SYSCTL_MainOscTest, GetMOSCPowerStateMapsPWRDNFieldToPublicState)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nSTATE enStateReg;

        enStateReg = SYSCTL_enSTATE_DIS;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(MOSC_CTL_OFFSET,
                                                    MOSC_CTL_PWRDN_MASK,
                                                    MOSC_CTL_R_PWRDN_BIT,
                                                    (UBase_t) MOSC_CTL_PWRDN_POWERUP)));

        EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetMOSCPowerState(SYSCTL_enMODULE_0, &enStateReg));
        EXPECT_EQ(SYSCTL_enSTATE_ENA, enStateReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nSTATE enStateReg;

        enStateReg = SYSCTL_enSTATE_ENA;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(MOSC_CTL_OFFSET,
                                                    MOSC_CTL_PWRDN_MASK,
                                                    MOSC_CTL_R_PWRDN_BIT,
                                                    (UBase_t) MOSC_CTL_PWRDN_POWERDOWN)));

        EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetMOSCPowerState(SYSCTL_enMODULE_0, &enStateReg));
        EXPECT_EQ(SYSCTL_enSTATE_DIS, enStateReg);
    }
}

/**
 * @brief Validate OSCRNG-field reads in the MOSC frequency-range getter.
 * @summary Confirms that `SYSCTL__enGetMOSCFrequencyRange` reads the documented
 *          `MOSCCTL.OSCRNG` field and returns the decoded range enum.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_MainOsc.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MOSCCTL-011@endverbatim
 */
TEST(SYSCTL_MainOscTest, GetMOSCFrequencyRangeUsesExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nMOSC_RANGE enRangeReg;

    enRangeReg = SYSCTL_enMOSC_RANGE_LOW;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(MOSC_CTL_OFFSET,
                                                MOSC_CTL_OSCRNG_MASK,
                                                MOSC_CTL_R_OSCRNG_BIT,
                                                (UBase_t) SYSCTL_enMOSC_RANGE_HIGH)));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetMOSCFrequencyRange(SYSCTL_enMODULE_0, &enRangeReg));
    EXPECT_EQ(SYSCTL_enMOSC_RANGE_HIGH, enRangeReg);
}

/**
 * @brief Validate read-error propagation across the MOSC getter family.
 * @summary Confirms that the MOSC monitor, failure-action, state, power-state,
 *          and frequency-range getters return primitive read failures unchanged
 *          and preserve caller state.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_MainOsc.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MOSCCTL-012@endverbatim
 */
TEST(SYSCTL_MainOscTest, MOSCGettersPropagateReadError)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nSTATE enStateReg;

        enStateReg = SYSCTL_enSTATE_ENA;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(MOSC_CTL_OFFSET,
                                                    MOSC_CTL_CVAL_MASK,
                                                    MOSC_CTL_R_CVAL_BIT,
                                                    0UL,
                                                    SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enGetMOSCMonitorState(SYSCTL_enMODULE_0, &enStateReg));
        EXPECT_EQ(SYSCTL_enSTATE_ENA, enStateReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nMOSC_FAILURE enActionReg;

        enActionReg = SYSCTL_enMOSC_FAILURE_SYSINT;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(MOSC_CTL_OFFSET,
                                                    MOSC_CTL_MOSCIM_MASK,
                                                    MOSC_CTL_R_MOSCIM_BIT,
                                                    0UL,
                                                    SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enGetMOSCFailureAction(SYSCTL_enMODULE_0, &enActionReg));
        EXPECT_EQ(SYSCTL_enMOSC_FAILURE_SYSINT, enActionReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nSTATE enStateReg;

        enStateReg = SYSCTL_enSTATE_ENA;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(MOSC_CTL_OFFSET,
                                                    MOSC_CTL_NOXTAL_MASK,
                                                    MOSC_CTL_R_NOXTAL_BIT,
                                                    0UL,
                                                    SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enGetMOSCState(SYSCTL_enMODULE_0, &enStateReg));
        EXPECT_EQ(SYSCTL_enSTATE_ENA, enStateReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nSTATE enStateReg;

        enStateReg = SYSCTL_enSTATE_ENA;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(MOSC_CTL_OFFSET,
                                                    MOSC_CTL_PWRDN_MASK,
                                                    MOSC_CTL_R_PWRDN_BIT,
                                                    0UL,
                                                    SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enGetMOSCPowerState(SYSCTL_enMODULE_0, &enStateReg));
        EXPECT_EQ(SYSCTL_enSTATE_ENA, enStateReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nMOSC_RANGE enRangeReg;

        enRangeReg = SYSCTL_enMOSC_RANGE_HIGH;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(MOSC_CTL_OFFSET,
                                                    MOSC_CTL_OSCRNG_MASK,
                                                    MOSC_CTL_R_OSCRNG_BIT,
                                                    0UL,
                                                    SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enGetMOSCFrequencyRange(SYSCTL_enMODULE_0, &enRangeReg));
        EXPECT_EQ(SYSCTL_enMOSC_RANGE_HIGH, enRangeReg);
    }
}