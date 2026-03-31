/**
 *
 * @file SYSCTL_InternalOsc_Test.cpp
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
 * @verbatim 31 mar. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 31 mar. 2026   GitHub Copilot   1.0         initial Version@endverbatim
 */

extern "C"
{
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_InternalOsc.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_PIOSCCAL.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_PIOSCSTAT.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/xHeader/SYSCTL_RegisterAddress.h>
}

#include <tm4c129e_test/SYSCTL_PrimitivesMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::InSequence;
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
 * @brief Validate null-pointer rejection in the PIOSC status-value getters.
 * @summary Confirms that the public calibration-result, current-trim, and
 *          default-trim getters reject null output pointers before attempting
 *          any primitive register access.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_InternalOsc.c
 * - Public API parameter validation path@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-PIOSC-001@endverbatim
 */
TEST(SYSCTL_InternalOscTest, PIOSCStatusValueGettersRejectNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetPIOSCCalibrationResult(SYSCTL_enMODULE_0, (SYSCTL_nPIOSC_RESULT*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetPIOSCCalibrationValue(SYSCTL_enMODULE_0, (UBase_t*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetPIOSCDefaultCalibrationValue(SYSCTL_enMODULE_0, (UBase_t*) 0UL));
}

/**
 * @brief Validate PIOSCSTAT RESULT-field reads in the calibration-result getter.
 * @summary Confirms that `SYSCTL__enGetPIOSCCalibrationResult` reads the
 *          documented `PIOSCSTAT.RESULT` field from the status register and
 *          returns the decoded public result enum unchanged.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_InternalOsc.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-PIOSC-002@endverbatim
 */
TEST(SYSCTL_InternalOscTest, GetPIOSCCalibrationResultUsesPIOSCSTATResultField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nPIOSC_RESULT enResultReg;

    enResultReg = SYSCTL_enPIOSC_RESULT_NOTSTARTED;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(PIOSC_STAT_OFFSET,
                                                PIOSC_STAT_RESULT_MASK,
                                                PIOSC_STAT_R_RESULT_BIT,
                                                (UBase_t) SYSCTL_enPIOSC_RESULT_FAILED)));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetPIOSCCalibrationResult(SYSCTL_enMODULE_0, &enResultReg));
    EXPECT_EQ(SYSCTL_enPIOSC_RESULT_FAILED, enResultReg);
}

/**
 * @brief Validate read-error propagation in the calibration-result getter.
 * @summary Confirms that `SYSCTL__enGetPIOSCCalibrationResult` returns the
 *          primitive read error unchanged and preserves the caller output value.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_InternalOsc.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-PIOSC-003@endverbatim
 */
TEST(SYSCTL_InternalOscTest, GetPIOSCCalibrationResultPropagatesReadError)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nPIOSC_RESULT enResultReg;

    enResultReg = SYSCTL_enPIOSC_RESULT_FAILED;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(PIOSC_STAT_OFFSET,
                                                PIOSC_STAT_RESULT_MASK,
                                                PIOSC_STAT_R_RESULT_BIT,
                                                0UL,
                                                SYSCTL_enERROR_VALUE)));

    EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enGetPIOSCCalibrationResult(SYSCTL_enMODULE_0, &enResultReg));
    EXPECT_EQ(SYSCTL_enPIOSC_RESULT_FAILED, enResultReg);
}

/**
 * @brief Validate PIOSCSTAT CT and DT field reads in the trim-value getters.
 * @summary Confirms that the current-trim and default-trim getters read the
 *          documented `PIOSCSTAT.CT` and `PIOSCSTAT.DT` fields from the status register.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_InternalOsc.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-PIOSC-004@endverbatim
 */
TEST(SYSCTL_InternalOscTest, GetPIOSCCalibrationValueAndDefaultValueUsePIOSCSTATFields)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    UBase_t uxCalibrationValueReg;
    UBase_t uxDefaultValueReg;

    uxCalibrationValueReg = 0UL;
    uxDefaultValueReg = 0UL;

    {
        InSequence stSequence;
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(PIOSC_STAT_OFFSET,
                                                    PIOSC_STAT_CT_MASK,
                                                    PIOSC_STAT_R_CT_BIT,
                                                    (UBase_t) 0x24UL)));
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(PIOSC_STAT_OFFSET,
                                                    PIOSC_STAT_DT_MASK,
                                                    PIOSC_STAT_R_DT_BIT,
                                                    (UBase_t) 0x35UL)));
    }

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetPIOSCCalibrationValue(SYSCTL_enMODULE_0, &uxCalibrationValueReg));
    EXPECT_EQ((UBase_t) 0x24UL, uxCalibrationValueReg);
    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetPIOSCDefaultCalibrationValue(SYSCTL_enMODULE_0, &uxDefaultValueReg));
    EXPECT_EQ((UBase_t) 0x35UL, uxDefaultValueReg);
}

/**
 * @brief Validate PIOSCCAL UT-field access in the user-trim setter and getter.
 * @summary Confirms that `SYSCTL__enSetPIOSCUserCalibrationValue` and
 *          `SYSCTL__enGetPIOSCUserCalibrationValue` target the documented
 *          `PIOSCCAL.UT` field through the primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_InternalOsc.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-PIOSC-005@endverbatim
 */
TEST(SYSCTL_InternalOscTest, SetAndGetPIOSCUserCalibrationValueUsePIOSCCALUTField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    UBase_t uxValueReg;

    uxValueReg = 0UL;

    {
        InSequence stSequence;
        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(PIOSC_CAL_OFFSET,
                                                     PIOSC_CAL_UT_MASK,
                                                     PIOSC_CAL_R_UT_BIT,
                                                     (UBase_t) 0x2AUL)));
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(PIOSC_CAL_OFFSET,
                                                    PIOSC_CAL_UT_MASK,
                                                    PIOSC_CAL_R_UT_BIT,
                                                    (UBase_t) 0x2AUL)));
    }

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enSetPIOSCUserCalibrationValue(SYSCTL_enMODULE_0, (UBase_t) 0x2AUL));
    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetPIOSCUserCalibrationValue(SYSCTL_enMODULE_0, &uxValueReg));
    EXPECT_EQ((UBase_t) 0x2AUL, uxValueReg);
}

/**
 * @brief Validate null-pointer rejection in the remaining PIOSC trim and status getters.
 * @summary Confirms that the user-trim getter plus the UTEN, UPDATE, and CAL
 *          status getters reject null output pointers before attempting primitive access.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_InternalOsc.c
 * - Public API parameter validation path@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-PIOSC-006@endverbatim
 */
TEST(SYSCTL_InternalOscTest, PIOSCUserTrimAndStatusGettersRejectNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetPIOSCUserCalibrationValue(SYSCTL_enMODULE_0, (UBase_t*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enIsPIOSCUserCalibrationValueUsed(SYSCTL_enMODULE_0, (SYSCTL_nBOOLEAN*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enIsPIOCCalibrationValueUpdateOngoing(SYSCTL_enMODULE_0, (SYSCTL_nBOOLEAN*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enIsPIOCCalibrationOngoing(SYSCTL_enMODULE_0, (SYSCTL_nBOOLEAN*) 0UL));
}

/**
 * @brief Validate PIOSCCAL UTEN-field writes in the user-trim enable setter.
 * @summary Confirms that `SYSCTL__enUsePIOSCUserCalibrationValue` writes the
 *          documented `PIOSCCAL.UTEN` field using the caller-provided boolean state.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_InternalOsc.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-PIOSC-007@endverbatim
 */
TEST(SYSCTL_InternalOscTest, UsePIOSCUserCalibrationValueUsesPIOSCCALUTENField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeWriteRegisterAction(PIOSC_CAL_OFFSET,
                                                 PIOSC_CAL_UTEN_MASK,
                                                 PIOSC_CAL_R_UTEN_BIT,
                                                 (UBase_t) SYSCTL_enTRUE)));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enUsePIOSCUserCalibrationValue(SYSCTL_enMODULE_0, SYSCTL_enTRUE));
}

/**
 * @brief Validate PIOSCCAL UTEN-field reads in the user-trim enable-status getter.
 * @summary Confirms that `SYSCTL__enIsPIOSCUserCalibrationValueUsed` reads the
 *          documented `PIOSCCAL.UTEN` field and returns the boolean value unchanged.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_InternalOsc.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-PIOSC-008@endverbatim
 */
TEST(SYSCTL_InternalOscTest, IsPIOSCUserCalibrationValueUsedUsesPIOSCCALUTENField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nBOOLEAN enStatusReg;

    enStatusReg = SYSCTL_enFALSE;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(PIOSC_CAL_OFFSET,
                                                PIOSC_CAL_UTEN_MASK,
                                                PIOSC_CAL_R_UTEN_BIT,
                                                (UBase_t) SYSCTL_enTRUE)));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enIsPIOSCUserCalibrationValueUsed(SYSCTL_enMODULE_0, &enStatusReg));
    EXPECT_EQ(SYSCTL_enTRUE, enStatusReg);
}

/**
 * @brief Validate PIOSCCAL UPDATE-field access in the update helper and status getter.
 * @summary Confirms that the update command helper writes the documented
 *          `PIOSCCAL.UPDATE` field and the update-status getter reads that same field.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_InternalOsc.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-PIOSC-009@endverbatim
 */
TEST(SYSCTL_InternalOscTest, UpdatePIOSCCalibrationValueAndStatusUseUpdateField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nBOOLEAN enStatusReg;

    enStatusReg = SYSCTL_enFALSE;

    {
        InSequence stSequence;
        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(PIOSC_CAL_OFFSET,
                                                     PIOSC_CAL_UPDATE_MASK,
                                                     PIOSC_CAL_R_UPDATE_BIT,
                                                     (UBase_t) PIOSC_CAL_UPDATE_UPDATE)));
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(PIOSC_CAL_OFFSET,
                                                    PIOSC_CAL_UPDATE_MASK,
                                                    PIOSC_CAL_R_UPDATE_BIT,
                                                    (UBase_t) SYSCTL_enTRUE)));
    }

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enUpdatePIOSCCalibrationValue(SYSCTL_enMODULE_0));
    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enIsPIOCCalibrationValueUpdateOngoing(SYSCTL_enMODULE_0, &enStatusReg));
    EXPECT_EQ(SYSCTL_enTRUE, enStatusReg);
}

/**
 * @brief Validate PIOSCCAL CAL-field writes in the calibration-start helper.
 * @summary Confirms that `SYSCTL__enStartPIOSCCalibration` writes the documented
 *          `PIOSCCAL.CAL` start command through the primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_InternalOsc.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-PIOSC-010@endverbatim
 */
TEST(SYSCTL_InternalOscTest, StartPIOSCCalibrationUsesCalField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeWriteRegisterAction(PIOSC_CAL_OFFSET,
                                                 PIOSC_CAL_CAL_MASK,
                                                 PIOSC_CAL_R_CAL_BIT,
                                                 (UBase_t) PIOSC_CAL_CAL_START)));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enStartPIOSCCalibration(SYSCTL_enMODULE_0));
}

/**
 * @brief Validate PIOSCCAL CAL-field reads in the calibration-ongoing getter.
 * @summary Confirms that `SYSCTL__enIsPIOCCalibrationOngoing` reads the
 *          documented `PIOSCCAL.CAL` field and returns the boolean status unchanged.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_InternalOsc.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-PIOSC-011@endverbatim
 */
TEST(SYSCTL_InternalOscTest, IsPIOCCalibrationOngoingUsesCalField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nBOOLEAN enStatusReg;

    enStatusReg = SYSCTL_enFALSE;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(PIOSC_CAL_OFFSET,
                                                PIOSC_CAL_CAL_MASK,
                                                PIOSC_CAL_R_CAL_BIT,
                                                (UBase_t) SYSCTL_enTRUE)));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enIsPIOCCalibrationOngoing(SYSCTL_enMODULE_0, &enStatusReg));
    EXPECT_EQ(SYSCTL_enTRUE, enStatusReg);
}
