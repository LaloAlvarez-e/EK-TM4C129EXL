/**
 *
 * @file SYSCTL_Voltage_Test.cpp
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
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_Voltage.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_PTBOCTL.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_PWRTC.h>
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
 * @brief Validate PTBOCTL field routing in the individual brown-out action setters.
 * @summary Confirms that the VDD and VDDA brown-out action setters write the
 *          documented `PTBOCTL.VDD_UBOR` and `PTBOCTL.VDDA_UBOR` fields with
 *          the caller-provided event-action encodings.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_Voltage.c
 * - SYSCTL PTBOCTL register definitions@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-VOLT-001@endverbatim
 */
TEST(SYSCTL_VoltageTest, SetBrownOutEventActionFieldWrappersUseExpectedFields)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(PTBO_CTL_OFFSET,
                                                     PTBO_CTL_VDD_UBOR_MASK,
                                                     PTBO_CTL_R_VDD_UBOR_BIT,
                                                     (UBase_t) SYSCTL_enBOR_EVENT_RESET)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enSetBrownOutEventAction_VDD(SYSCTL_enMODULE_0, SYSCTL_enBOR_EVENT_RESET));
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(PTBO_CTL_OFFSET,
                                                     PTBO_CTL_VDDA_UBOR_MASK,
                                                     PTBO_CTL_R_VDDA_UBOR_BIT,
                                                     (UBase_t) SYSCTL_enBOR_EVENT_NMI)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enSetBrownOutEventAction_VDDA(SYSCTL_enMODULE_0, SYSCTL_enBOR_EVENT_NMI));
    }
}

/**
 * @brief Validate null-pointer rejection in the individual brown-out getters.
 * @summary Confirms that the individual action and trip-status getters reject
 *          null output pointers before any primitive register access occurs.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_Voltage.c
 * - Public API parameter validation path@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-VOLT-002@endverbatim
 */
TEST(SYSCTL_VoltageTest, BrownOutIndividualGettersRejectNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetBrownOutEventAction_VDD(SYSCTL_enMODULE_0, (SYSCTL_nBOR_EVENT*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetBrownOutEventAction_VDDA(SYSCTL_enMODULE_0, (SYSCTL_nBOR_EVENT*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enIsBrownOutTripped_VDD(SYSCTL_enMODULE_0, (SYSCTL_nBOOLEAN*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enIsBrownOutTripped_VDDA(SYSCTL_enMODULE_0, (SYSCTL_nBOOLEAN*) 0UL));
}

/**
 * @brief Validate PTBOCTL field reads in the individual brown-out action getters.
 * @summary Confirms that the VDD and VDDA brown-out action getters read the
 *          documented `PTBOCTL` fields and return the decoded event enums.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_Voltage.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-VOLT-003@endverbatim
 */
TEST(SYSCTL_VoltageTest, GetBrownOutEventActionFieldWrappersUseExpectedFields)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nBOR_EVENT enEventReg;

        enEventReg = SYSCTL_enBOR_EVENT_NONE;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(PTBO_CTL_OFFSET,
                                                    PTBO_CTL_VDD_UBOR_MASK,
                                                    PTBO_CTL_R_VDD_UBOR_BIT,
                                                    (UBase_t) SYSCTL_enBOR_EVENT_SYSINT)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enGetBrownOutEventAction_VDD(SYSCTL_enMODULE_0, &enEventReg));
        EXPECT_EQ(SYSCTL_enBOR_EVENT_SYSINT, enEventReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nBOR_EVENT enEventReg;

        enEventReg = SYSCTL_enBOR_EVENT_NONE;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(PTBO_CTL_OFFSET,
                                                    PTBO_CTL_VDDA_UBOR_MASK,
                                                    PTBO_CTL_R_VDDA_UBOR_BIT,
                                                    (UBase_t) SYSCTL_enBOR_EVENT_RESET)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enGetBrownOutEventAction_VDDA(SYSCTL_enMODULE_0, &enEventReg));
        EXPECT_EQ(SYSCTL_enBOR_EVENT_RESET, enEventReg);
    }
}

/**
 * @brief Validate sequencing and error propagation in the grouped brown-out action setter.
 * @summary Confirms that the grouped setter writes VDD first and then VDDA,
 *          stops immediately on the first write failure, and propagates the
 *          second write failure unchanged after a successful VDD write.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_Voltage.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-VOLT-004@endverbatim
 */
TEST(SYSCTL_VoltageTest, SetBrownOutEventActionGroupedWrapperSequencesAndPropagatesErrors)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        InSequence stSequence;

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(PTBO_CTL_OFFSET,
                                                     PTBO_CTL_VDD_UBOR_MASK,
                                                     PTBO_CTL_R_VDD_UBOR_BIT,
                                                     (UBase_t) SYSCTL_enBOR_EVENT_SYSINT)));
        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(PTBO_CTL_OFFSET,
                                                     PTBO_CTL_VDDA_UBOR_MASK,
                                                     PTBO_CTL_R_VDDA_UBOR_BIT,
                                                     (UBase_t) SYSCTL_enBOR_EVENT_NMI)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enSetBrownOutEventAction(SYSCTL_enMODULE_0,
                                                   SYSCTL_enBOR_EVENT_SYSINT,
                                                   SYSCTL_enBOR_EVENT_NMI));
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(PTBO_CTL_OFFSET,
                                                     PTBO_CTL_VDD_UBOR_MASK,
                                                     PTBO_CTL_R_VDD_UBOR_BIT,
                                                     (UBase_t) SYSCTL_enBOR_EVENT_RESET,
                                                     SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE,
                  SYSCTL__enSetBrownOutEventAction(SYSCTL_enMODULE_0,
                                                   SYSCTL_enBOR_EVENT_RESET,
                                                   SYSCTL_enBOR_EVENT_NONE));
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        InSequence stSequence;

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(PTBO_CTL_OFFSET,
                                                     PTBO_CTL_VDD_UBOR_MASK,
                                                     PTBO_CTL_R_VDD_UBOR_BIT,
                                                     (UBase_t) SYSCTL_enBOR_EVENT_NMI)));
        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(PTBO_CTL_OFFSET,
                                                     PTBO_CTL_VDDA_UBOR_MASK,
                                                     PTBO_CTL_R_VDDA_UBOR_BIT,
                                                     (UBase_t) SYSCTL_enBOR_EVENT_RESET,
                                                     SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE,
                  SYSCTL__enSetBrownOutEventAction(SYSCTL_enMODULE_0,
                                                   SYSCTL_enBOR_EVENT_NMI,
                                                   SYSCTL_enBOR_EVENT_RESET));
    }
}

/**
 * @brief Validate sequencing and error propagation in the grouped brown-out action getter.
 * @summary Confirms that the grouped getter reads VDD first and then VDDA,
 *          returns both decoded events on success, and propagates primitive read
 *          failures while preserving any caller state that was not updated yet.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_Voltage.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-VOLT-005@endverbatim
 */
TEST(SYSCTL_VoltageTest, GetBrownOutEventActionGroupedWrapperSequencesAndPropagatesErrors)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        InSequence stSequence;
        SYSCTL_nBOR_EVENT enVDDEventReg;
        SYSCTL_nBOR_EVENT enVDDAEventReg;

        enVDDEventReg = SYSCTL_enBOR_EVENT_NONE;
        enVDDAEventReg = SYSCTL_enBOR_EVENT_NONE;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(PTBO_CTL_OFFSET,
                                                    PTBO_CTL_VDD_UBOR_MASK,
                                                    PTBO_CTL_R_VDD_UBOR_BIT,
                                                    (UBase_t) SYSCTL_enBOR_EVENT_SYSINT)));
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(PTBO_CTL_OFFSET,
                                                    PTBO_CTL_VDDA_UBOR_MASK,
                                                    PTBO_CTL_R_VDDA_UBOR_BIT,
                                                    (UBase_t) SYSCTL_enBOR_EVENT_RESET)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enGetBrownOutEventAction(SYSCTL_enMODULE_0, &enVDDEventReg, &enVDDAEventReg));
        EXPECT_EQ(SYSCTL_enBOR_EVENT_SYSINT, enVDDEventReg);
        EXPECT_EQ(SYSCTL_enBOR_EVENT_RESET, enVDDAEventReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nBOR_EVENT enVDDEventReg;
        SYSCTL_nBOR_EVENT enVDDAEventReg;

        enVDDEventReg = SYSCTL_enBOR_EVENT_NMI;
        enVDDAEventReg = SYSCTL_enBOR_EVENT_RESET;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(PTBO_CTL_OFFSET,
                                                    PTBO_CTL_VDD_UBOR_MASK,
                                                    PTBO_CTL_R_VDD_UBOR_BIT,
                                                    0UL,
                                                    SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE,
                  SYSCTL__enGetBrownOutEventAction(SYSCTL_enMODULE_0, &enVDDEventReg, &enVDDAEventReg));
        EXPECT_EQ(SYSCTL_enBOR_EVENT_NMI, enVDDEventReg);
        EXPECT_EQ(SYSCTL_enBOR_EVENT_RESET, enVDDAEventReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        InSequence stSequence;
        SYSCTL_nBOR_EVENT enVDDEventReg;
        SYSCTL_nBOR_EVENT enVDDAEventReg;

        enVDDEventReg = SYSCTL_enBOR_EVENT_NONE;
        enVDDAEventReg = SYSCTL_enBOR_EVENT_NMI;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(PTBO_CTL_OFFSET,
                                                    PTBO_CTL_VDD_UBOR_MASK,
                                                    PTBO_CTL_R_VDD_UBOR_BIT,
                                                    (UBase_t) SYSCTL_enBOR_EVENT_RESET)));
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(PTBO_CTL_OFFSET,
                                                    PTBO_CTL_VDDA_UBOR_MASK,
                                                    PTBO_CTL_R_VDDA_UBOR_BIT,
                                                    0UL,
                                                    SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE,
                  SYSCTL__enGetBrownOutEventAction(SYSCTL_enMODULE_0, &enVDDEventReg, &enVDDAEventReg));
        EXPECT_EQ(SYSCTL_enBOR_EVENT_RESET, enVDDEventReg);
        EXPECT_EQ(SYSCTL_enBOR_EVENT_NMI, enVDDAEventReg);
    }
}

/**
 * @brief Validate PWRTC field reads in the brown-out trip-status getters.
 * @summary Confirms that the VDD and VDDA trip-status getters read the
 *          documented `PWRTC.VDD_UBOR` and `PWRTC.VDDA_UBOR` cause bits and
 *          return the decoded booleans.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_Voltage.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-VOLT-006@endverbatim
 */
TEST(SYSCTL_VoltageTest, BrownOutTripStatusGettersUsePWRTCFields)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nBOOLEAN enStatusReg;

        enStatusReg = SYSCTL_enFALSE;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(SYSCTL_PWRTC_OFFSET,
                                                    SYSCTL_PWRTC_VDD_UBOR_MASK,
                                                    SYSCTL_PWRTC_R_VDD_UBOR_BIT,
                                                    (UBase_t) SYSCTL_enTRUE)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enIsBrownOutTripped_VDD(SYSCTL_enMODULE_0, &enStatusReg));
        EXPECT_EQ(SYSCTL_enTRUE, enStatusReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nBOOLEAN enStatusReg;

        enStatusReg = SYSCTL_enTRUE;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(SYSCTL_PWRTC_OFFSET,
                                                    SYSCTL_PWRTC_VDDA_UBOR_MASK,
                                                    SYSCTL_PWRTC_R_VDDA_UBOR_BIT,
                                                    (UBase_t) SYSCTL_enFALSE)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enIsBrownOutTripped_VDDA(SYSCTL_enMODULE_0, &enStatusReg));
        EXPECT_EQ(SYSCTL_enFALSE, enStatusReg);
    }
}

/**
 * @brief Validate RW1C PWRTC writes in the brown-out cause clear helpers.
 * @summary Confirms that the VDD, VDDA, and combined brown-out clear helpers
 *          write the documented `PWRTC` RW1C cause bits with full-register
 *          values that target the requested per-rail latch or both latches.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_Voltage.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-VOLT-007@endverbatim
 */
TEST(SYSCTL_VoltageTest, ClearBrownOutStatusWrappersUsePWRTCRW1CValues)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(SYSCTL_PWRTC_OFFSET,
                                                     MCU_MASK_32,
                                                     0UL,
                                                     SYSCTL_PWRTC_R_VDD_UBOR_MASK)));

        EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enClearBrownOutStatus_VDD(SYSCTL_enMODULE_0));
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(SYSCTL_PWRTC_OFFSET,
                                                     MCU_MASK_32,
                                                     0UL,
                                                     SYSCTL_PWRTC_R_VDDA_UBOR_MASK)));

        EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enClearBrownOutStatus_VDDA(SYSCTL_enMODULE_0));
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(SYSCTL_PWRTC_OFFSET,
                                                     MCU_MASK_32,
                                                     0UL,
                                                     SYSCTL_PWRTC_R_VDDA_UBOR_MASK | SYSCTL_PWRTC_R_VDD_UBOR_MASK)));

        EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enClearBrownOutStatus(SYSCTL_enMODULE_0));
    }
}

/**
 * @brief Validate read-error propagation in the brown-out trip-status getters.
 * @summary Confirms that the VDD and VDDA trip-status getters return primitive
 *          read failures unchanged and preserve caller output state.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_Voltage.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-VOLT-008@endverbatim
 */
TEST(SYSCTL_VoltageTest, BrownOutTripStatusGettersPropagateReadErrors)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nBOOLEAN enStatusReg;

        enStatusReg = SYSCTL_enTRUE;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(SYSCTL_PWRTC_OFFSET,
                                                    SYSCTL_PWRTC_VDD_UBOR_MASK,
                                                    SYSCTL_PWRTC_R_VDD_UBOR_BIT,
                                                    0UL,
                                                    SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE,
                  SYSCTL__enIsBrownOutTripped_VDD(SYSCTL_enMODULE_0, &enStatusReg));
        EXPECT_EQ(SYSCTL_enTRUE, enStatusReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nBOOLEAN enStatusReg;

        enStatusReg = SYSCTL_enFALSE;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(SYSCTL_PWRTC_OFFSET,
                                                    SYSCTL_PWRTC_VDDA_UBOR_MASK,
                                                    SYSCTL_PWRTC_R_VDDA_UBOR_BIT,
                                                    0UL,
                                                    SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE,
                  SYSCTL__enIsBrownOutTripped_VDDA(SYSCTL_enMODULE_0, &enStatusReg));
        EXPECT_EQ(SYSCTL_enFALSE, enStatusReg);
    }
}