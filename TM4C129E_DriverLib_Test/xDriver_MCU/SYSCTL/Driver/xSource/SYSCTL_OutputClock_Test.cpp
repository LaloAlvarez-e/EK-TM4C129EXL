/**
 *
 * @file SYSCTL_OutputClock_Test.cpp
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
 * @verbatim 30 mar. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 30 mar. 2026   GitHub Copilot   1.0         initial Version@endverbatim
 */

extern "C"
{
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_OutputClock.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_DIVSCLK.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/xHeader/SYSCTL_RegisterAddress.h>
}

#include <tm4c129e_test/SYSCTL_PrimitivesMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::InSequence;
using ::testing::Invoke;
using ::testing::Return;
using ::testing::StrictMock;

/**
 * @brief Validate DIVSCLK EN-field programming in the output-clock state setter.
 * @summary Confirms that `SYSCTL__enSetOutputClockState` writes the DIVSCLK EN
 *          field using the documented offset, normalized mask, and bit position,
 *          while forwarding the requested state unchanged through the primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_OutputClock.c
 * - SYSCTL DIVSCLK register definitions@endverbatim
 */
TEST(SYSCTL_OutputClockTest, SetOutputClockStateUsesExpectedDIVSCLKEnableField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) DIVSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) DIVSCLK_CFG_EN_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) DIVSCLK_CFG_R_EN_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) SYSCTL_enSTATE_ENA, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetOutputClockState(SYSCTL_enMODULE_0, SYSCTL_enSTATE_ENA));
}

/**
 * @brief Validate DIVSCLK SRC-field programming in the output-clock source setter.
 * @summary Confirms that `SYSCTL__enSetOutputClockSource` writes the DIVSCLK SRC
 *          field using the expected offset, mask, and shift and forwards the
 *          requested source unchanged through the primitive write seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_OutputClock.c
 * - SYSCTL DIVSCLK register definitions@endverbatim
 */
TEST(SYSCTL_OutputClockTest, SetOutputClockSourceUsesExpectedDIVSCLKSourceField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) DIVSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) DIVSCLK_CFG_SRC_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) DIVSCLK_CFG_R_SRC_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) SYSCTL_enOUTCLK_SRC_MOSC, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetOutputClockSource(SYSCTL_enMODULE_0, SYSCTL_enOUTCLK_SRC_MOSC));
}

/**
 * @brief Validate DIVSCLK DIV-field programming in the output-clock divisor setter.
 * @summary Confirms that `SYSCTL__enSetOutputClockDivisor` writes the DIVSCLK DIV
 *          field with the expected offset, mask, and shift and forwards the
 *          caller-provided divisor unchanged through the primitive write seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_OutputClock.c
 * - SYSCTL DIVSCLK register definitions@endverbatim
 */
TEST(SYSCTL_OutputClockTest, SetOutputClockDivisorUsesExpectedDIVSCLKDivField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) DIVSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) DIVSCLK_CFG_DIV_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) DIVSCLK_CFG_R_DIV_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) 0x5AUL, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetOutputClockDivisor(SYSCTL_enMODULE_0, (UBase_t) 0x5AUL));
}

/**
 * @brief Validate null-pointer rejection in the output-clock state getter.
 * @summary Confirms that `SYSCTL__enGetOutputClockState` rejects a null output
 *          pointer before attempting DIVSCLK primitive register access.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_OutputClock.c
 * - Public API parameter validation path@endverbatim
 */
TEST(SYSCTL_OutputClockTest, GetOutputClockStateRejectsNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetOutputClockState(SYSCTL_enMODULE_0, (SYSCTL_nSTATE*) 0UL));
}

/**
 * @brief Validate DIVSCLK EN-field reads in the output-clock state getter.
 * @summary Confirms that `SYSCTL__enGetOutputClockState` reads the DIVSCLK EN
 *          field with the expected offset, mask, and shift and returns the
 *          primitive value as the public enable-state enum.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_OutputClock.c@endverbatim
 */
TEST(SYSCTL_OutputClockTest, GetOutputClockStateUsesExpectedDIVSCLKEnableField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nSTATE enStateReg;

    enStateReg = SYSCTL_enSTATE_UNDEF;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) DIVSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) DIVSCLK_CFG_EN_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) DIVSCLK_CFG_R_EN_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) SYSCTL_enSTATE_DIS;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enGetOutputClockState(SYSCTL_enMODULE_0, &enStateReg));
    EXPECT_EQ(SYSCTL_enSTATE_DIS, enStateReg);
}

/**
 * @brief Validate DIVSCLK SRC-field reads in the output-clock source getter.
 * @summary Confirms that `SYSCTL__enGetOutputClockSource` reads the DIVSCLK SRC
 *          field with the expected offset, mask, and shift and returns the
 *          primitive value as the public output-clock source enum.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_OutputClock.c@endverbatim
 */
TEST(SYSCTL_OutputClockTest, GetOutputClockSourceUsesExpectedDIVSCLKSourceField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nOUTCLK_SRC enSourceReg;

    enSourceReg = SYSCTL_enOUTCLK_SRC_UNDEF;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) DIVSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) DIVSCLK_CFG_SRC_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) DIVSCLK_CFG_R_SRC_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) SYSCTL_enOUTCLK_SRC_PIOSC;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enGetOutputClockSource(SYSCTL_enMODULE_0, &enSourceReg));
    EXPECT_EQ(SYSCTL_enOUTCLK_SRC_PIOSC, enSourceReg);
}

/**
 * @brief Validate DIVSCLK DIV-field reads in the output-clock divisor getter.
 * @summary Confirms that `SYSCTL__enGetOutputClockDivisor` reads the DIVSCLK DIV
 *          field with the expected offset, mask, and shift and returns the raw
 *          divisor value unchanged to the caller.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_OutputClock.c@endverbatim
 */
TEST(SYSCTL_OutputClockTest, GetOutputClockDivisorUsesExpectedDIVSCLKDivField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    UBase_t uxDivisorReg;

    uxDivisorReg = 0UL;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) DIVSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) DIVSCLK_CFG_DIV_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) DIVSCLK_CFG_R_DIV_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) 0x44UL;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enGetOutputClockDivisor(SYSCTL_enMODULE_0, &uxDivisorReg));
    EXPECT_EQ((UBase_t) 0x44UL, uxDivisorReg);
}

/**
 * @brief Validate configuration write ordering in the output-clock config setter.
 * @summary Confirms that `SYSCTL__enSetOutputClockConfig` disables the output
 *          clock first, then programs divisor, then source, and finally restores
 *          the requested final enable state through the same DIVSCLK register.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_OutputClock.c@endverbatim
 */
TEST(SYSCTL_OutputClockTest, SetOutputClockConfigUsesDisableDivisorSourceStateOrdering)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    InSequence stSequence;

    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ((uintptr_t) DIVSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) DIVSCLK_CFG_EN_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) DIVSCLK_CFG_R_EN_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) SYSCTL_enSTATE_DIS, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ((uintptr_t) DIVSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) DIVSCLK_CFG_DIV_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) DIVSCLK_CFG_R_DIV_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) 7UL, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ((uintptr_t) DIVSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) DIVSCLK_CFG_SRC_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) DIVSCLK_CFG_R_SRC_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) SYSCTL_enOUTCLK_SRC_MOSC, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ((uintptr_t) DIVSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) DIVSCLK_CFG_EN_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) DIVSCLK_CFG_R_EN_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) SYSCTL_enSTATE_ENA, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetOutputClockConfig(SYSCTL_enMODULE_0,
                                            SYSCTL_enSTATE_ENA,
                                            SYSCTL_enOUTCLK_SRC_MOSC,
                                            (UBase_t) 7UL));
}

/**
 * @brief Validate early exit in the output-clock config setter.
 * @summary Confirms that `SYSCTL__enSetOutputClockConfig` stops after the first
 *          failing primitive write and does not attempt later divisor, source,
 *          or final-state updates once the disable step fails.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_OutputClock.c@endverbatim
 */
TEST(SYSCTL_OutputClockTest, SetOutputClockConfigStopsOnFirstWriteError)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE,
              SYSCTL__enSetOutputClockConfig(SYSCTL_enMODULE_0,
                                            SYSCTL_enSTATE_ENA,
                                            SYSCTL_enOUTCLK_SRC_SYSCLK,
                                            (UBase_t) 2UL));
}

/**
 * @brief Validate configuration read ordering in the output-clock config getter.
 * @summary Confirms that `SYSCTL__enGetOutputClockConfig` reads divisor first,
 *          then source, then state, and returns all three primitive values to
 *          the caller when each DIVSCLK field read succeeds.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_OutputClock.c@endverbatim
 */
TEST(SYSCTL_OutputClockTest, GetOutputClockConfigUsesDivisorSourceStateOrdering)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    InSequence stSequence;
    SYSCTL_nSTATE enStateReg;
    SYSCTL_nOUTCLK_SRC enSourceReg;
    UBase_t uxDivisorReg;

    enStateReg = SYSCTL_enSTATE_UNDEF;
    enSourceReg = SYSCTL_enOUTCLK_SRC_UNDEF;
    uxDivisorReg = 0UL;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ((uintptr_t) DIVSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) DIVSCLK_CFG_DIV_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) DIVSCLK_CFG_R_DIV_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) 9UL;
            return SYSCTL_enERROR_OK;
        }));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ((uintptr_t) DIVSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) DIVSCLK_CFG_SRC_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) DIVSCLK_CFG_R_SRC_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) SYSCTL_enOUTCLK_SRC_PIOSC;
            return SYSCTL_enERROR_OK;
        }));
    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ((uintptr_t) DIVSCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) DIVSCLK_CFG_EN_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) DIVSCLK_CFG_R_EN_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) SYSCTL_enSTATE_ENA;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enGetOutputClockConfig(SYSCTL_enMODULE_0,
                                            &enStateReg,
                                            &enSourceReg,
                                            &uxDivisorReg));
    EXPECT_EQ(SYSCTL_enSTATE_ENA, enStateReg);
    EXPECT_EQ(SYSCTL_enOUTCLK_SRC_PIOSC, enSourceReg);
    EXPECT_EQ((UBase_t) 9UL, uxDivisorReg);
}

/**
 * @brief Validate early exit in the output-clock config getter.
 * @summary Confirms that `SYSCTL__enGetOutputClockConfig` returns the first read
 *          error unchanged and stops before the later source and state reads when
 *          the initial divisor read fails.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_OutputClock.c@endverbatim
 */
TEST(SYSCTL_OutputClockTest, GetOutputClockConfigStopsOnFirstReadError)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nSTATE enStateReg;
    SYSCTL_nOUTCLK_SRC enSourceReg;
    UBase_t uxDivisorReg;

    enStateReg = SYSCTL_enSTATE_UNDEF;
    enSourceReg = SYSCTL_enOUTCLK_SRC_UNDEF;
    uxDivisorReg = 0UL;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_RANGE));

    EXPECT_EQ(SYSCTL_enERROR_RANGE,
              SYSCTL__enGetOutputClockConfig(SYSCTL_enMODULE_0,
                                            &enStateReg,
                                            &enSourceReg,
                                            &uxDivisorReg));
    EXPECT_EQ(SYSCTL_enSTATE_UNDEF, enStateReg);
    EXPECT_EQ(SYSCTL_enOUTCLK_SRC_UNDEF, enSourceReg);
    EXPECT_EQ((UBase_t) 0UL, uxDivisorReg);
}