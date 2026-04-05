/**
 *
 * @file SYSCTL_LDOVoltage_Test.cpp
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
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_LDOVoltage.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_LDO.h>
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
 * @brief Validate VLDO-field routing in the custom LDO voltage setters.
 * @summary Confirms that the sleep and deep-sleep custom-voltage setters write
 *          the documented `LDOSPCTL.VLDO` and `LDODPCTL.VLDO` fields with the
 *          caller-provided voltage encodings.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_LDOVoltage.c
 * - SYSCTL LDO register definitions@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-LDO-001@endverbatim
 */
TEST(SYSCTL_LDOVoltageTest, SetLDOCustomVoltageWrappersUseExpectedFields)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(LDO_SPCTL_OFFSET,
                                                     LDO_SPCTL_VLDO_MASK,
                                                     LDO_SPCTL_R_VLDO_BIT,
                                                     (UBase_t) SYSCTL_enLDO_VOTAGE_1_10V)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enSetLDOCustomVoltageOnSleepMode(SYSCTL_enMODULE_0,
                                                           SYSCTL_enLDO_VOTAGE_1_10V));
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(LDO_DPCTL_OFFSET,
                                                     LDO_DPCTL_VLDO_MASK,
                                                     LDO_DPCTL_R_VLDO_BIT,
                                                     (UBase_t) SYSCTL_enLDO_VOTAGE_1_05V)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enSetLDOCustomVoltageOnDeepSleepMode(SYSCTL_enMODULE_0,
                                                               SYSCTL_enLDO_VOTAGE_1_05V));
    }
}

/**
 * @brief Validate null-pointer rejection across the LDO getter family.
 * @summary Confirms that the custom-voltage, default-voltage, and custom-use
 *          getters reject null output pointers before any primitive register
 *          access occurs.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_LDOVoltage.c
 * - Public API parameter validation path@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-LDO-002@endverbatim
 */
TEST(SYSCTL_LDOVoltageTest, LDOVoltageGettersRejectNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetLDOCustomVoltageOnSleepMode(SYSCTL_enMODULE_0, (SYSCTL_nLDO_VOTAGE*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetLDODefaultVoltageWithPLLOnSleepMode(SYSCTL_enMODULE_0, (SYSCTL_nLDO_VOTAGE*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetLDODefaultVoltageNoPLLOnSleepMode(SYSCTL_enMODULE_0, (SYSCTL_nLDO_VOTAGE*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enIsLDOCustomVoltageOnSleepModeUsed(SYSCTL_enMODULE_0, (SYSCTL_nBOOLEAN*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetLDOCustomVoltageOnDeepSleepMode(SYSCTL_enMODULE_0, (SYSCTL_nLDO_VOTAGE*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetLDODefaultVoltage30KHzOnDeepSleepMode(SYSCTL_enMODULE_0, (SYSCTL_nLDO_VOTAGE*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetLDODefaultVoltageNoPLLOnDeepSleepMode(SYSCTL_enMODULE_0, (SYSCTL_nLDO_VOTAGE*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enIsLDOCustomVoltageOnDeepSleepModeUsed(SYSCTL_enMODULE_0, (SYSCTL_nBOOLEAN*) 0UL));
}

/**
 * @brief Validate VLDO-field reads in the custom LDO voltage getters.
 * @summary Confirms that the sleep and deep-sleep custom-voltage getters read
 *          the documented `LDOSPCTL.VLDO` and `LDODPCTL.VLDO` fields and return
 *          the decoded voltage enums.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_LDOVoltage.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-LDO-003@endverbatim
 */
TEST(SYSCTL_LDOVoltageTest, GetLDOCustomVoltageWrappersUseExpectedFields)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nLDO_VOTAGE enVoltageReg;

        enVoltageReg = SYSCTL_enLDO_VOTAGE_UNDEF;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(LDO_SPCTL_OFFSET,
                                                    LDO_SPCTL_VLDO_MASK,
                                                    LDO_SPCTL_R_VLDO_BIT,
                                                    (UBase_t) SYSCTL_enLDO_VOTAGE_1_20V)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enGetLDOCustomVoltageOnSleepMode(SYSCTL_enMODULE_0, &enVoltageReg));
        EXPECT_EQ(SYSCTL_enLDO_VOTAGE_1_20V, enVoltageReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nLDO_VOTAGE enVoltageReg;

        enVoltageReg = SYSCTL_enLDO_VOTAGE_UNDEF;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(LDO_DPCTL_OFFSET,
                                                    LDO_DPCTL_VLDO_MASK,
                                                    LDO_DPCTL_R_VLDO_BIT,
                                                    (UBase_t) SYSCTL_enLDO_VOTAGE_0_95V)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enGetLDOCustomVoltageOnDeepSleepMode(SYSCTL_enMODULE_0, &enVoltageReg));
        EXPECT_EQ(SYSCTL_enLDO_VOTAGE_0_95V, enVoltageReg);
    }
}

/**
 * @brief Validate calibration-field reads in the default LDO voltage getters.
 * @summary Confirms that the default-voltage getters read the documented
 *          `LDOSPCAL.WITHPLL`, `LDOSPCAL.NOPLL`, `LDODPCAL.30KHZ`, and
 *          `LDODPCAL.NOPLL` fields and return the decoded voltage enums.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_LDOVoltage.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-LDO-004@endverbatim
 */
TEST(SYSCTL_LDOVoltageTest, GetLDODefaultVoltageWrappersUseExpectedFields)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nLDO_VOTAGE enVoltageReg;

        enVoltageReg = SYSCTL_enLDO_VOTAGE_UNDEF;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(LDO_SPCAL_OFFSET,
                                                    LDO_SPCAL_WITHPLL_MASK,
                                                    LDO_SPCAL_R_WITHPLL_BIT,
                                                    (UBase_t) SYSCTL_enLDO_VOTAGE_1_20V)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enGetLDODefaultVoltageWithPLLOnSleepMode(SYSCTL_enMODULE_0, &enVoltageReg));
        EXPECT_EQ(SYSCTL_enLDO_VOTAGE_1_20V, enVoltageReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nLDO_VOTAGE enVoltageReg;

        enVoltageReg = SYSCTL_enLDO_VOTAGE_UNDEF;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(LDO_SPCAL_OFFSET,
                                                    LDO_SPCAL_NOPLL_MASK,
                                                    LDO_SPCAL_R_NOPLL_BIT,
                                                    (UBase_t) SYSCTL_enLDO_VOTAGE_1_10V)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enGetLDODefaultVoltageNoPLLOnSleepMode(SYSCTL_enMODULE_0, &enVoltageReg));
        EXPECT_EQ(SYSCTL_enLDO_VOTAGE_1_10V, enVoltageReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nLDO_VOTAGE enVoltageReg;

        enVoltageReg = SYSCTL_enLDO_VOTAGE_UNDEF;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(LDO_DPCAL_OFFSET,
                                                    LDO_DPCAL_KHZ30_MASK,
                                                    LDO_DPCAL_R_KHZ30_BIT,
                                                    (UBase_t) SYSCTL_enLDO_VOTAGE_1_05V)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enGetLDODefaultVoltage30KHzOnDeepSleepMode(SYSCTL_enMODULE_0, &enVoltageReg));
        EXPECT_EQ(SYSCTL_enLDO_VOTAGE_1_05V, enVoltageReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nLDO_VOTAGE enVoltageReg;

        enVoltageReg = SYSCTL_enLDO_VOTAGE_UNDEF;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(LDO_DPCAL_OFFSET,
                                                    LDO_DPCAL_NOPLL_MASK,
                                                    LDO_DPCAL_R_NOPLL_BIT,
                                                    (UBase_t) SYSCTL_enLDO_VOTAGE_1_00V)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enGetLDODefaultVoltageNoPLLOnDeepSleepMode(SYSCTL_enMODULE_0, &enVoltageReg));
        EXPECT_EQ(SYSCTL_enLDO_VOTAGE_1_00V, enVoltageReg);
    }
}

/**
 * @brief Validate corrected single-bit VADJEN routing in the custom-use setters.
 * @summary Confirms that the sleep and deep-sleep custom-voltage enable
 *          setters write the documented `VADJEN` fields as single-bit logical
 *          masks through the primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_LDOVoltage.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-LDO-005@endverbatim
 */
TEST(SYSCTL_LDOVoltageTest, UseLDOCustomVoltageWrappersUseSingleBitMask)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(LDO_SPCTL_OFFSET,
                                                     LDO_SPCTL_VADJEN_MASK,
                                                     LDO_SPCTL_R_VADJEN_BIT,
                                                     (UBase_t) SYSCTL_enSTATE_ENA)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enUseLDOCustomVoltageOnSleepMode(SYSCTL_enMODULE_0, SYSCTL_enSTATE_ENA));
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(LDO_DPCTL_OFFSET,
                                                     LDO_DPCTL_VADJEN_MASK,
                                                     LDO_DPCTL_R_VADJEN_BIT,
                                                     (UBase_t) SYSCTL_enSTATE_DIS)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enUseLDOCustomVoltageOnDeepSleepMode(SYSCTL_enMODULE_0, SYSCTL_enSTATE_DIS));
    }
}

/**
 * @brief Validate corrected single-bit VADJEN reads in the custom-use getters.
 * @summary Confirms that the sleep and deep-sleep custom-voltage use-state
 *          getters read the documented `VADJEN` fields with the corrected
 *          single-bit logical mask and return the decoded booleans.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_LDOVoltage.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-LDO-006@endverbatim
 */
TEST(SYSCTL_LDOVoltageTest, IsLDOCustomVoltageUsedWrappersUseSingleBitMask)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nBOOLEAN enStateReg;

        enStateReg = SYSCTL_enFALSE;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(LDO_SPCTL_OFFSET,
                                                    LDO_SPCTL_VADJEN_MASK,
                                                    LDO_SPCTL_R_VADJEN_BIT,
                                                    (UBase_t) SYSCTL_enTRUE)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enIsLDOCustomVoltageOnSleepModeUsed(SYSCTL_enMODULE_0, &enStateReg));
        EXPECT_EQ(SYSCTL_enTRUE, enStateReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nBOOLEAN enStateReg;

        enStateReg = SYSCTL_enTRUE;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(LDO_DPCTL_OFFSET,
                                                    LDO_DPCTL_VADJEN_MASK,
                                                    LDO_DPCTL_R_VADJEN_BIT,
                                                    (UBase_t) SYSCTL_enFALSE)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enIsLDOCustomVoltageOnDeepSleepModeUsed(SYSCTL_enMODULE_0, &enStateReg));
        EXPECT_EQ(SYSCTL_enFALSE, enStateReg);
    }
}

/**
 * @brief Validate read-error propagation across the LDO getter family.
 * @summary Confirms that the custom-voltage, default-voltage, and custom-use
 *          getters return primitive read failures unchanged and preserve caller
 *          output state.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_LDOVoltage.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-LDO-007@endverbatim
 */
TEST(SYSCTL_LDOVoltageTest, LDOVoltageGettersPropagateReadErrors)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nLDO_VOTAGE enVoltageReg;

        enVoltageReg = SYSCTL_enLDO_VOTAGE_0_90V;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(LDO_SPCTL_OFFSET,
                                                    LDO_SPCTL_VLDO_MASK,
                                                    LDO_SPCTL_R_VLDO_BIT,
                                                    0UL,
                                                    SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE,
                  SYSCTL__enGetLDOCustomVoltageOnSleepMode(SYSCTL_enMODULE_0, &enVoltageReg));
        EXPECT_EQ(SYSCTL_enLDO_VOTAGE_0_90V, enVoltageReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nLDO_VOTAGE enVoltageReg;

        enVoltageReg = SYSCTL_enLDO_VOTAGE_1_20V;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(LDO_SPCAL_OFFSET,
                                                    LDO_SPCAL_WITHPLL_MASK,
                                                    LDO_SPCAL_R_WITHPLL_BIT,
                                                    0UL,
                                                    SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE,
                  SYSCTL__enGetLDODefaultVoltageWithPLLOnSleepMode(SYSCTL_enMODULE_0, &enVoltageReg));
        EXPECT_EQ(SYSCTL_enLDO_VOTAGE_1_20V, enVoltageReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nLDO_VOTAGE enVoltageReg;

        enVoltageReg = SYSCTL_enLDO_VOTAGE_1_15V;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(LDO_SPCAL_OFFSET,
                                                    LDO_SPCAL_NOPLL_MASK,
                                                    LDO_SPCAL_R_NOPLL_BIT,
                                                    0UL,
                                                    SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE,
                  SYSCTL__enGetLDODefaultVoltageNoPLLOnSleepMode(SYSCTL_enMODULE_0, &enVoltageReg));
        EXPECT_EQ(SYSCTL_enLDO_VOTAGE_1_15V, enVoltageReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nBOOLEAN enStateReg;

        enStateReg = SYSCTL_enTRUE;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(LDO_SPCTL_OFFSET,
                                                    LDO_SPCTL_VADJEN_MASK,
                                                    LDO_SPCTL_R_VADJEN_BIT,
                                                    0UL,
                                                    SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE,
                  SYSCTL__enIsLDOCustomVoltageOnSleepModeUsed(SYSCTL_enMODULE_0, &enStateReg));
        EXPECT_EQ(SYSCTL_enTRUE, enStateReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nLDO_VOTAGE enVoltageReg;

        enVoltageReg = SYSCTL_enLDO_VOTAGE_1_00V;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(LDO_DPCTL_OFFSET,
                                                    LDO_DPCTL_VLDO_MASK,
                                                    LDO_DPCTL_R_VLDO_BIT,
                                                    0UL,
                                                    SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE,
                  SYSCTL__enGetLDOCustomVoltageOnDeepSleepMode(SYSCTL_enMODULE_0, &enVoltageReg));
        EXPECT_EQ(SYSCTL_enLDO_VOTAGE_1_00V, enVoltageReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nLDO_VOTAGE enVoltageReg;

        enVoltageReg = SYSCTL_enLDO_VOTAGE_1_10V;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(LDO_DPCAL_OFFSET,
                                                    LDO_DPCAL_KHZ30_MASK,
                                                    LDO_DPCAL_R_KHZ30_BIT,
                                                    0UL,
                                                    SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE,
                  SYSCTL__enGetLDODefaultVoltage30KHzOnDeepSleepMode(SYSCTL_enMODULE_0, &enVoltageReg));
        EXPECT_EQ(SYSCTL_enLDO_VOTAGE_1_10V, enVoltageReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nLDO_VOTAGE enVoltageReg;

        enVoltageReg = SYSCTL_enLDO_VOTAGE_1_05V;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(LDO_DPCAL_OFFSET,
                                                    LDO_DPCAL_NOPLL_MASK,
                                                    LDO_DPCAL_R_NOPLL_BIT,
                                                    0UL,
                                                    SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE,
                  SYSCTL__enGetLDODefaultVoltageNoPLLOnDeepSleepMode(SYSCTL_enMODULE_0, &enVoltageReg));
        EXPECT_EQ(SYSCTL_enLDO_VOTAGE_1_05V, enVoltageReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nBOOLEAN enStateReg;

        enStateReg = SYSCTL_enFALSE;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(LDO_DPCTL_OFFSET,
                                                    LDO_DPCTL_VADJEN_MASK,
                                                    LDO_DPCTL_R_VADJEN_BIT,
                                                    0UL,
                                                    SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE,
                  SYSCTL__enIsLDOCustomVoltageOnDeepSleepModeUsed(SYSCTL_enMODULE_0, &enStateReg));
        EXPECT_EQ(SYSCTL_enFALSE, enStateReg);
    }
}