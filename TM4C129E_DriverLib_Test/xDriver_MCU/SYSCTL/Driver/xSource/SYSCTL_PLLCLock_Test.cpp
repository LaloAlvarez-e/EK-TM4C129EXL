/**
 *
 * @file SYSCTL_PLLCLock_Test.cpp
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
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_PLLCLock.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_PLLFREQ.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_PLLSTAT.h>
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
 * @brief Validate PLLPWR-field programming in the PLL state setter.
 * @summary Confirms that `SYSCTL__enSetPLLClockState` writes the documented
 *          `PLLFREQ0.PLLPWR` field using the public enabled and disabled state
 *          encodings through the primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_PLLCLock.c
 * - SYSCTL PLLFREQ0 register definitions@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-PLL-001@endverbatim
 */
TEST(SYSCTL_PLLCLockTest, SetPLLClockStateUsesExpectedField)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(PLL_FREQ0_OFFSET,
                                                     PLL_FREQ0_PLL_PWR_MASK,
                                                     PLL_FREQ0_R_PLL_PWR_BIT,
                                                     (UBase_t) SYSCTL_enSTATE_ENA)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enSetPLLClockState(SYSCTL_enMODULE_0, SYSCTL_enSTATE_ENA));
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(PLL_FREQ0_OFFSET,
                                                     PLL_FREQ0_PLL_PWR_MASK,
                                                     PLL_FREQ0_R_PLL_PWR_BIT,
                                                     (UBase_t) SYSCTL_enSTATE_DIS)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enSetPLLClockState(SYSCTL_enMODULE_0, SYSCTL_enSTATE_DIS));
    }
}

/**
 * @brief Validate null-pointer rejection across the PLL getter family.
 * @summary Confirms that the PLL state, value, and lock-status getters reject
 *          null output pointers before attempting any primitive register access.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_PLLCLock.c
 * - Public API parameter validation path@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-PLL-002@endverbatim
 */
TEST(SYSCTL_PLLCLockTest, PLLStateAndValueGettersRejectNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetPLLClockState(SYSCTL_enMODULE_0, (SYSCTL_nSTATE*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetPLLClockIntegerValue_M(SYSCTL_enMODULE_0, (UBase_t*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetPLLClockFractionalValue_M(SYSCTL_enMODULE_0, (UBase_t*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetPLLClockValue_Q(SYSCTL_enMODULE_0, (UBase_t*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetPLLClockValue_N(SYSCTL_enMODULE_0, (UBase_t*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enIsPLLClockLocked(SYSCTL_enMODULE_0, (SYSCTL_nBOOLEAN*) 0UL));
}

/**
 * @brief Validate PLLPWR-field reads in the PLL state getter.
 * @summary Confirms that `SYSCTL__enGetPLLClockState` reads the documented
 *          `PLLFREQ0.PLLPWR` field and returns the decoded public state value.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_PLLCLock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-PLL-003@endverbatim
 */
TEST(SYSCTL_PLLCLockTest, GetPLLClockStateUsesExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nSTATE enStateReg;

    enStateReg = SYSCTL_enSTATE_DIS;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(PLL_FREQ0_OFFSET,
                                                PLL_FREQ0_PLL_PWR_MASK,
                                                PLL_FREQ0_R_PLL_PWR_BIT,
                                                (UBase_t) SYSCTL_enSTATE_ENA)));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetPLLClockState(SYSCTL_enMODULE_0, &enStateReg));
    EXPECT_EQ(SYSCTL_enSTATE_ENA, enStateReg);
}

/**
 * @brief Validate PLLFREQ0 MINT-field access in the integer-divider helpers.
 * @summary Confirms that the MINT setter and getter access the documented
 *          `PLLFREQ0.MINT` field through the primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_PLLCLock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-PLL-004@endverbatim
 */
TEST(SYSCTL_PLLCLockTest, SetAndGetPLLClockIntegerValueMUseExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    UBase_t uxValueReg;

    uxValueReg = 0UL;

    {
        InSequence stSequence;
        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(PLL_FREQ0_OFFSET,
                                                     PLL_FREQ0_PLL_M_INT_MASK,
                                                     PLL_FREQ0_R_PLL_M_INT_BIT,
                                                     (UBase_t) 0x155UL)));
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(PLL_FREQ0_OFFSET,
                                                    PLL_FREQ0_PLL_M_INT_MASK,
                                                    PLL_FREQ0_R_PLL_M_INT_BIT,
                                                    (UBase_t) 0x155UL)));
    }

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetPLLClockIntegerValue_M(SYSCTL_enMODULE_0, (UBase_t) 0x155UL));
    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enGetPLLClockIntegerValue_M(SYSCTL_enMODULE_0, &uxValueReg));
    EXPECT_EQ((UBase_t) 0x155UL, uxValueReg);
}

/**
 * @brief Validate PLLFREQ0 MFRAC-field access in the fractional-divider helpers.
 * @summary Confirms that the MFRAC setter and getter access the documented
 *          `PLLFREQ0.MFRAC` field through the primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_PLLCLock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-PLL-005@endverbatim
 */
TEST(SYSCTL_PLLCLockTest, SetAndGetPLLClockFractionalValueMUseExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    UBase_t uxValueReg;

    uxValueReg = 0UL;

    {
        InSequence stSequence;
        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(PLL_FREQ0_OFFSET,
                                                     PLL_FREQ0_PLL_M_FRAC_MASK,
                                                     PLL_FREQ0_R_PLL_M_FRAC_BIT,
                                                     (UBase_t) 0x2AAUL)));
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(PLL_FREQ0_OFFSET,
                                                    PLL_FREQ0_PLL_M_FRAC_MASK,
                                                    PLL_FREQ0_R_PLL_M_FRAC_BIT,
                                                    (UBase_t) 0x2AAUL)));
    }

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetPLLClockFractionalValue_M(SYSCTL_enMODULE_0, (UBase_t) 0x2AAUL));
    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enGetPLLClockFractionalValue_M(SYSCTL_enMODULE_0, &uxValueReg));
    EXPECT_EQ((UBase_t) 0x2AAUL, uxValueReg);
}

/**
 * @brief Validate PLLFREQ1 Q-field access in the Q-divider helpers.
 * @summary Confirms that the Q setter and getter access the documented
 *          `PLLFREQ1.Q` field through the primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_PLLCLock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-PLL-006@endverbatim
 */
TEST(SYSCTL_PLLCLockTest, SetAndGetPLLClockValueQUseExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    UBase_t uxValueReg;

    uxValueReg = 0UL;

    {
        InSequence stSequence;
        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(PLL_FREQ1_OFFSET,
                                                     PLL_FREQ1_PLL_Q_VALUE_MASK,
                                                     PLL_FREQ1_R_PLL_Q_VALUE_BIT,
                                                     (UBase_t) 0x1BUL)));
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(PLL_FREQ1_OFFSET,
                                                    PLL_FREQ1_PLL_Q_VALUE_MASK,
                                                    PLL_FREQ1_R_PLL_Q_VALUE_BIT,
                                                    (UBase_t) 0x1BUL)));
    }

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetPLLClockValue_Q(SYSCTL_enMODULE_0, (UBase_t) 0x1BUL));
    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enGetPLLClockValue_Q(SYSCTL_enMODULE_0, &uxValueReg));
    EXPECT_EQ((UBase_t) 0x1BUL, uxValueReg);
}

/**
 * @brief Validate PLLFREQ1 N-field access in the N-divider helpers.
 * @summary Confirms that the N setter and getter access the documented
 *          `PLLFREQ1.N` field through the primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_PLLCLock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-PLL-007@endverbatim
 */
TEST(SYSCTL_PLLCLockTest, SetAndGetPLLClockValueNUseExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    UBase_t uxValueReg;

    uxValueReg = 0UL;

    {
        InSequence stSequence;
        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(PLL_FREQ1_OFFSET,
                                                     PLL_FREQ1_PLL_N_VALUE_MASK,
                                                     PLL_FREQ1_R_PLL_N_VALUE_BIT,
                                                     (UBase_t) 0x13UL)));
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(PLL_FREQ1_OFFSET,
                                                    PLL_FREQ1_PLL_N_VALUE_MASK,
                                                    PLL_FREQ1_R_PLL_N_VALUE_BIT,
                                                    (UBase_t) 0x13UL)));
    }

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetPLLClockValue_N(SYSCTL_enMODULE_0, (UBase_t) 0x13UL));
    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enGetPLLClockValue_N(SYSCTL_enMODULE_0, &uxValueReg));
    EXPECT_EQ((UBase_t) 0x13UL, uxValueReg);
}

/**
 * @brief Validate PLLSTAT LOCK-field reads in the lock-status getter.
 * @summary Confirms that `SYSCTL__enIsPLLClockLocked` reads the documented
 *          `PLLSTAT.LOCK` field and returns the decoded public boolean value.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_PLLCLock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-PLL-008@endverbatim
 */
TEST(SYSCTL_PLLCLockTest, IsPLLClockLockedUsesExpectedField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nBOOLEAN enStateReg;

    enStateReg = SYSCTL_enFALSE;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeReadRegisterAction(PLL_STAT_OFFSET,
                                                PLL_STAT_LOCK_MASK,
                                                PLL_STAT_R_LOCK_BIT,
                                                (UBase_t) SYSCTL_enTRUE)));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enIsPLLClockLocked(SYSCTL_enMODULE_0, &enStateReg));
    EXPECT_EQ(SYSCTL_enTRUE, enStateReg);
}

/**
 * @brief Validate read-error propagation across the PLL getter family.
 * @summary Confirms that the PLL state, value, and lock-status getters return
 *          primitive read failures unchanged and preserve caller state.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_PLLCLock.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-PLL-009@endverbatim
 */
TEST(SYSCTL_PLLCLockTest, PLLStateAndValueGettersPropagateReadErrors)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nSTATE enStateReg;

        enStateReg = SYSCTL_enSTATE_ENA;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(PLL_FREQ0_OFFSET,
                                                    PLL_FREQ0_PLL_PWR_MASK,
                                                    PLL_FREQ0_R_PLL_PWR_BIT,
                                                    0UL,
                                                    SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enGetPLLClockState(SYSCTL_enMODULE_0, &enStateReg));
        EXPECT_EQ(SYSCTL_enSTATE_ENA, enStateReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        UBase_t uxValueReg;

        uxValueReg = (UBase_t) 0x10UL;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(PLL_FREQ0_OFFSET,
                                                    PLL_FREQ0_PLL_M_INT_MASK,
                                                    PLL_FREQ0_R_PLL_M_INT_BIT,
                                                    0UL,
                                                    SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE,
                  SYSCTL__enGetPLLClockIntegerValue_M(SYSCTL_enMODULE_0, &uxValueReg));
        EXPECT_EQ((UBase_t) 0x10UL, uxValueReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        UBase_t uxValueReg;

        uxValueReg = (UBase_t) 0x20UL;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(PLL_FREQ0_OFFSET,
                                                    PLL_FREQ0_PLL_M_FRAC_MASK,
                                                    PLL_FREQ0_R_PLL_M_FRAC_BIT,
                                                    0UL,
                                                    SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE,
                  SYSCTL__enGetPLLClockFractionalValue_M(SYSCTL_enMODULE_0, &uxValueReg));
        EXPECT_EQ((UBase_t) 0x20UL, uxValueReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        UBase_t uxValueReg;

        uxValueReg = (UBase_t) 0x11UL;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(PLL_FREQ1_OFFSET,
                                                    PLL_FREQ1_PLL_Q_VALUE_MASK,
                                                    PLL_FREQ1_R_PLL_Q_VALUE_BIT,
                                                    0UL,
                                                    SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE,
                  SYSCTL__enGetPLLClockValue_Q(SYSCTL_enMODULE_0, &uxValueReg));
        EXPECT_EQ((UBase_t) 0x11UL, uxValueReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        UBase_t uxValueReg;

        uxValueReg = (UBase_t) 0x12UL;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(PLL_FREQ1_OFFSET,
                                                    PLL_FREQ1_PLL_N_VALUE_MASK,
                                                    PLL_FREQ1_R_PLL_N_VALUE_BIT,
                                                    0UL,
                                                    SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE,
                  SYSCTL__enGetPLLClockValue_N(SYSCTL_enMODULE_0, &uxValueReg));
        EXPECT_EQ((UBase_t) 0x12UL, uxValueReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nBOOLEAN enStateReg;

        enStateReg = SYSCTL_enTRUE;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(PLL_STAT_OFFSET,
                                                    PLL_STAT_LOCK_MASK,
                                                    PLL_STAT_R_LOCK_BIT,
                                                    0UL,
                                                    SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enIsPLLClockLocked(SYSCTL_enMODULE_0, &enStateReg));
        EXPECT_EQ(SYSCTL_enTRUE, enStateReg);
    }
}