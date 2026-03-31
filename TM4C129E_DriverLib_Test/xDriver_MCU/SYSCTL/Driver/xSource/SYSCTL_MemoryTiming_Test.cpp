/**
 *
 * @file SYSCTL_MemoryTiming_Test.cpp
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
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_MemoryTiming.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_MEMTIM0.h>
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
 * @brief Validate paired FLASH and EEPROM BCHT writes in the high-time setter.
 * @summary Confirms that `SYSCTL__enSetMemoryHighTime` writes the documented
 *          `MEMTIM0.FLASHBCHT` field first and then mirrors the same public
 *          value into `MEMTIM0.EEPROMBCHT` through the primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_MemoryTiming.c
 * - SYSCTL MEMTIM0 register definitions@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MEMTIM0-001@endverbatim
 */
TEST(SYSCTL_MemoryTimingTest, SetMemoryHighTimeWritesFlashThenEEPROM)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    InSequence stSequence;

    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeWriteRegisterAction(MEMORY_TIM0_OFFSET,
                                                 MEMORY_TIM0_FLASH_BCHT_MASK,
                                                 MEMORY_TIM0_R_FLASH_BCHT_BIT,
                                                 (UBase_t) SYSCTL_enMEM_HIGHTIME_2_5)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeWriteRegisterAction(MEMORY_TIM0_OFFSET,
                                                 MEMORY_TIM0_EEPROM_BCHT_MASK,
                                                 MEMORY_TIM0_R_EEPROM_BCHT_BIT,
                                                 (UBase_t) SYSCTL_enMEM_HIGHTIME_2_5)));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetMemoryHighTime(SYSCTL_enMODULE_0, SYSCTL_enMEM_HIGHTIME_2_5));
}

/**
 * @brief Validate write-error propagation in the high-time setter.
 * @summary Confirms that `SYSCTL__enSetMemoryHighTime` returns the first FLASH
 *          write error immediately and, when the FLASH write succeeds, returns
 *          the EEPROM write error unchanged.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_MemoryTiming.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MEMTIM0-002@endverbatim
 */
TEST(SYSCTL_MemoryTimingTest, SetMemoryHighTimePropagatesWriteFailures)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(MEMORY_TIM0_OFFSET,
                                                     MEMORY_TIM0_FLASH_BCHT_MASK,
                                                     MEMORY_TIM0_R_FLASH_BCHT_BIT,
                                                     (UBase_t) SYSCTL_enMEM_HIGHTIME_1_5,
                                                     SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE,
                  SYSCTL__enSetMemoryHighTime(SYSCTL_enMODULE_0, SYSCTL_enMEM_HIGHTIME_1_5));
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        InSequence stSequence;

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(MEMORY_TIM0_OFFSET,
                                                     MEMORY_TIM0_FLASH_BCHT_MASK,
                                                     MEMORY_TIM0_R_FLASH_BCHT_BIT,
                                                     (UBase_t) SYSCTL_enMEM_HIGHTIME_3_0)));
        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(MEMORY_TIM0_OFFSET,
                                                     MEMORY_TIM0_EEPROM_BCHT_MASK,
                                                     MEMORY_TIM0_R_EEPROM_BCHT_BIT,
                                                     (UBase_t) SYSCTL_enMEM_HIGHTIME_3_0,
                                                     SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE,
                  SYSCTL__enSetMemoryHighTime(SYSCTL_enMODULE_0, SYSCTL_enMEM_HIGHTIME_3_0));
    }
}

/**
 * @brief Validate null-pointer rejection in the individual memory-field getters.
 * @summary Confirms that the public BCHT, wait-state, and clock-edge getters
 *          reject null output pointers before attempting any primitive register access.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_MemoryTiming.c
 * - Public API parameter validation path@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MEMTIM0-003@endverbatim
 */
TEST(SYSCTL_MemoryTimingTest, GetMemoryFieldGettersRejectNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetMemoryHighTime(SYSCTL_enMODULE_0, (SYSCTL_nMEM_HIGHTIME*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetMemoryWaitState(SYSCTL_enMODULE_0, (SYSCTL_nMEM_WAITSTATE*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetMemoryClockEdge(SYSCTL_enMODULE_0, (SYSCTL_nMEM_CLOCKEDGE*) 0UL));
}

/**
 * @brief Validate matching BCHT reads across FLASH and EEPROM fields.
 * @summary Confirms that `SYSCTL__enGetMemoryHighTime` reads the documented
 *          `MEMTIM0.FLASHBCHT` and `MEMTIM0.EEPROMBCHT` fields in order and
 *          returns the shared value when both decoded fields match.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_MemoryTiming.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MEMTIM0-004@endverbatim
 */
TEST(SYSCTL_MemoryTimingTest, GetMemoryHighTimeUsesMatchingFlashAndEEPROMValues)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nMEM_HIGHTIME enHighTimeReg;

    enHighTimeReg = SYSCTL_enMEM_HIGHTIME_UNDEF;

    {
        InSequence stSequence;
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(MEMORY_TIM0_OFFSET,
                                                    MEMORY_TIM0_FLASH_BCHT_MASK,
                                                    MEMORY_TIM0_R_FLASH_BCHT_BIT,
                                                    (UBase_t) SYSCTL_enMEM_HIGHTIME_3_0)));
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(MEMORY_TIM0_OFFSET,
                                                    MEMORY_TIM0_EEPROM_BCHT_MASK,
                                                    MEMORY_TIM0_R_EEPROM_BCHT_BIT,
                                                    (UBase_t) SYSCTL_enMEM_HIGHTIME_3_0)));
    }

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetMemoryHighTime(SYSCTL_enMODULE_0, &enHighTimeReg));
    EXPECT_EQ(SYSCTL_enMEM_HIGHTIME_3_0, enHighTimeReg);
}

/**
 * @brief Validate flash-read error propagation and mismatch rejection in the BCHT getter.
 * @summary Confirms that `SYSCTL__enGetMemoryHighTime` propagates a FLASH-field
 *          read failure unchanged and rejects mismatched FLASH versus EEPROM field values.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_MemoryTiming.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MEMTIM0-005@endverbatim
 */
TEST(SYSCTL_MemoryTimingTest, GetMemoryHighTimePropagatesFlashReadErrorAndRejectsMismatchedFields)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nMEM_HIGHTIME enHighTimeReg;

        enHighTimeReg = SYSCTL_enMEM_HIGHTIME_UNDEF;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(MEMORY_TIM0_OFFSET,
                                                    MEMORY_TIM0_FLASH_BCHT_MASK,
                                                    MEMORY_TIM0_R_FLASH_BCHT_BIT,
                                                    0UL,
                                                    SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enGetMemoryHighTime(SYSCTL_enMODULE_0, &enHighTimeReg));
        EXPECT_EQ(SYSCTL_enMEM_HIGHTIME_UNDEF, enHighTimeReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nMEM_HIGHTIME enHighTimeReg;

        enHighTimeReg = SYSCTL_enMEM_HIGHTIME_UNDEF;

        {
            InSequence stSequence;
            EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
                .WillOnce(Invoke(MakeReadRegisterAction(MEMORY_TIM0_OFFSET,
                                                        MEMORY_TIM0_FLASH_BCHT_MASK,
                                                        MEMORY_TIM0_R_FLASH_BCHT_BIT,
                                                        (UBase_t) SYSCTL_enMEM_HIGHTIME_1_0)));
            EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
                .WillOnce(Invoke(MakeReadRegisterAction(MEMORY_TIM0_OFFSET,
                                                        MEMORY_TIM0_EEPROM_BCHT_MASK,
                                                        MEMORY_TIM0_R_EEPROM_BCHT_BIT,
                                                        (UBase_t) SYSCTL_enMEM_HIGHTIME_1_5)));
        }

        EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enGetMemoryHighTime(SYSCTL_enMODULE_0, &enHighTimeReg));
        EXPECT_EQ(SYSCTL_enMEM_HIGHTIME_UNDEF, enHighTimeReg);
    }
}

/**
 * @brief Validate paired FLASH and EEPROM wait-state writes.
 * @summary Confirms that `SYSCTL__enSetMemoryWaitState` writes the documented
 *          `MEMTIM0.FLASHWS` field first and then mirrors the same public value
 *          into `MEMTIM0.EEPROMWS` through the primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_MemoryTiming.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MEMTIM0-006@endverbatim
 */
TEST(SYSCTL_MemoryTimingTest, SetMemoryWaitStateWritesFlashThenEEPROM)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    InSequence stSequence;

    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeWriteRegisterAction(MEMORY_TIM0_OFFSET,
                                                 MEMORY_TIM0_FLASH_WS_MASK,
                                                 MEMORY_TIM0_R_FLASH_WS_BIT,
                                                 (UBase_t) SYSCTL_enMEM_WAITSTATE_5)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeWriteRegisterAction(MEMORY_TIM0_OFFSET,
                                                 MEMORY_TIM0_EEPROM_WS_MASK,
                                                 MEMORY_TIM0_R_EEPROM_WS_BIT,
                                                 (UBase_t) SYSCTL_enMEM_WAITSTATE_5)));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetMemoryWaitState(SYSCTL_enMODULE_0, SYSCTL_enMEM_WAITSTATE_5));
}

/**
 * @brief Validate matching wait-state reads across FLASH and EEPROM fields.
 * @summary Confirms that `SYSCTL__enGetMemoryWaitState` reads the documented
 *          FLASH and EEPROM wait-state fields in order and returns the shared value
 *          when both decoded fields match.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_MemoryTiming.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MEMTIM0-007@endverbatim
 */
TEST(SYSCTL_MemoryTimingTest, GetMemoryWaitStateUsesMatchingFlashAndEEPROMValues)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nMEM_WAITSTATE enWaitStateReg;

    enWaitStateReg = SYSCTL_enMEM_WAITSTATE_UNDEF;

    {
        InSequence stSequence;
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(MEMORY_TIM0_OFFSET,
                                                    MEMORY_TIM0_FLASH_WS_MASK,
                                                    MEMORY_TIM0_R_FLASH_WS_BIT,
                                                    (UBase_t) SYSCTL_enMEM_WAITSTATE_4)));
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(MEMORY_TIM0_OFFSET,
                                                    MEMORY_TIM0_EEPROM_WS_MASK,
                                                    MEMORY_TIM0_R_EEPROM_WS_BIT,
                                                    (UBase_t) SYSCTL_enMEM_WAITSTATE_4)));
    }

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetMemoryWaitState(SYSCTL_enMODULE_0, &enWaitStateReg));
    EXPECT_EQ(SYSCTL_enMEM_WAITSTATE_4, enWaitStateReg);
}

/**
 * @brief Validate EEPROM-read error propagation in the wait-state getter.
 * @summary Confirms that `SYSCTL__enGetMemoryWaitState` returns the EEPROM-field
 *          read error unchanged after the FLASH-field read succeeds.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_MemoryTiming.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MEMTIM0-008@endverbatim
 */
TEST(SYSCTL_MemoryTimingTest, GetMemoryWaitStatePropagatesEEPROMReadError)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nMEM_WAITSTATE enWaitStateReg;

    enWaitStateReg = SYSCTL_enMEM_WAITSTATE_UNDEF;

    {
        InSequence stSequence;
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(MEMORY_TIM0_OFFSET,
                                                    MEMORY_TIM0_FLASH_WS_MASK,
                                                    MEMORY_TIM0_R_FLASH_WS_BIT,
                                                    (UBase_t) SYSCTL_enMEM_WAITSTATE_2)));
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(MEMORY_TIM0_OFFSET,
                                                    MEMORY_TIM0_EEPROM_WS_MASK,
                                                    MEMORY_TIM0_R_EEPROM_WS_BIT,
                                                    0UL,
                                                    SYSCTL_enERROR_VALUE)));
    }

    EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enGetMemoryWaitState(SYSCTL_enMODULE_0, &enWaitStateReg));
    EXPECT_EQ(SYSCTL_enMEM_WAITSTATE_UNDEF, enWaitStateReg);
}

/**
 * @brief Validate paired FLASH and EEPROM BCE writes.
 * @summary Confirms that `SYSCTL__enSetMemoryClockEdge` writes the documented
 *          `MEMTIM0.FLASHBCE` field first and then mirrors the same public value
 *          into `MEMTIM0.EEPROMBCE` through the primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_MemoryTiming.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MEMTIM0-009@endverbatim
 */
TEST(SYSCTL_MemoryTimingTest, SetMemoryClockEdgeWritesFlashThenEEPROM)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    InSequence stSequence;

    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeWriteRegisterAction(MEMORY_TIM0_OFFSET,
                                                 MEMORY_TIM0_FLASH_BCE_MASK,
                                                 MEMORY_TIM0_R_FLASH_BCE_BIT,
                                                 (UBase_t) SYSCTL_enMEM_CLOCKEDGE_FAILING)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeWriteRegisterAction(MEMORY_TIM0_OFFSET,
                                                 MEMORY_TIM0_EEPROM_BCE_MASK,
                                                 MEMORY_TIM0_R_EEPROM_BCE_BIT,
                                                 (UBase_t) SYSCTL_enMEM_CLOCKEDGE_FAILING)));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetMemoryClockEdge(SYSCTL_enMODULE_0, SYSCTL_enMEM_CLOCKEDGE_FAILING));
}

/**
 * @brief Validate matching BCE reads across FLASH and EEPROM fields.
 * @summary Confirms that `SYSCTL__enGetMemoryClockEdge` reads the documented
 *          FLASH and EEPROM clock-edge fields in order and returns the shared value
 *          when both decoded fields match.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_MemoryTiming.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MEMTIM0-010@endverbatim
 */
TEST(SYSCTL_MemoryTimingTest, GetMemoryClockEdgeUsesMatchingFlashAndEEPROMValues)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nMEM_CLOCKEDGE enClockEdgeReg;

    enClockEdgeReg = SYSCTL_enMEM_CLOCKEDGE_UNDEF;

    {
        InSequence stSequence;
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(MEMORY_TIM0_OFFSET,
                                                    MEMORY_TIM0_FLASH_BCE_MASK,
                                                    MEMORY_TIM0_R_FLASH_BCE_BIT,
                                                    (UBase_t) SYSCTL_enMEM_CLOCKEDGE_RISING)));
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(MEMORY_TIM0_OFFSET,
                                                    MEMORY_TIM0_EEPROM_BCE_MASK,
                                                    MEMORY_TIM0_R_EEPROM_BCE_BIT,
                                                    (UBase_t) SYSCTL_enMEM_CLOCKEDGE_RISING)));
    }

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetMemoryClockEdge(SYSCTL_enMODULE_0, &enClockEdgeReg));
    EXPECT_EQ(SYSCTL_enMEM_CLOCKEDGE_RISING, enClockEdgeReg);
}

/**
 * @brief Validate mismatch rejection in the clock-edge getter.
 * @summary Confirms that `SYSCTL__enGetMemoryClockEdge` rejects mismatched
 *          FLASH versus EEPROM edge-field values instead of returning an incoherent result.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_MemoryTiming.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MEMTIM0-011@endverbatim
 */
TEST(SYSCTL_MemoryTimingTest, GetMemoryClockEdgeRejectsMismatchedFields)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nMEM_CLOCKEDGE enClockEdgeReg;

    enClockEdgeReg = SYSCTL_enMEM_CLOCKEDGE_UNDEF;

    {
        InSequence stSequence;
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(MEMORY_TIM0_OFFSET,
                                                    MEMORY_TIM0_FLASH_BCE_MASK,
                                                    MEMORY_TIM0_R_FLASH_BCE_BIT,
                                                    (UBase_t) SYSCTL_enMEM_CLOCKEDGE_RISING)));
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(MEMORY_TIM0_OFFSET,
                                                    MEMORY_TIM0_EEPROM_BCE_MASK,
                                                    MEMORY_TIM0_R_EEPROM_BCE_BIT,
                                                    (UBase_t) SYSCTL_enMEM_CLOCKEDGE_FAILING)));
    }

    EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enGetMemoryClockEdge(SYSCTL_enMODULE_0, &enClockEdgeReg));
    EXPECT_EQ(SYSCTL_enMEM_CLOCKEDGE_UNDEF, enClockEdgeReg);
}

/**
 * @brief Validate the 16 MHz predefined timing entry in the composite setter.
 * @summary Confirms that `SYSCTL__enSetMemoryTiming` selects the documented
 *          16 MHz MEMTIM0 table entry and applies BCHT, wait-state, and edge-field
 *          writes in high-time, wait-state, and clock-edge order.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_MemoryTiming.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MEMTIM0-012@endverbatim
 */
TEST(SYSCTL_MemoryTimingTest, SetMemoryTimingUses16MHzEntry)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    InSequence stSequence;

    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeWriteRegisterAction(MEMORY_TIM0_OFFSET,
                                                 MEMORY_TIM0_FLASH_BCHT_MASK,
                                                 MEMORY_TIM0_R_FLASH_BCHT_BIT,
                                                 (UBase_t) SYSCTL_enMEM_HIGHTIME_0_5)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeWriteRegisterAction(MEMORY_TIM0_OFFSET,
                                                 MEMORY_TIM0_EEPROM_BCHT_MASK,
                                                 MEMORY_TIM0_R_EEPROM_BCHT_BIT,
                                                 (UBase_t) SYSCTL_enMEM_HIGHTIME_0_5)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeWriteRegisterAction(MEMORY_TIM0_OFFSET,
                                                 MEMORY_TIM0_FLASH_WS_MASK,
                                                 MEMORY_TIM0_R_FLASH_WS_BIT,
                                                 (UBase_t) SYSCTL_enMEM_WAITSTATE_0)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeWriteRegisterAction(MEMORY_TIM0_OFFSET,
                                                 MEMORY_TIM0_EEPROM_WS_MASK,
                                                 MEMORY_TIM0_R_EEPROM_WS_BIT,
                                                 (UBase_t) SYSCTL_enMEM_WAITSTATE_0)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeWriteRegisterAction(MEMORY_TIM0_OFFSET,
                                                 MEMORY_TIM0_FLASH_BCE_MASK,
                                                 MEMORY_TIM0_R_FLASH_BCE_BIT,
                                                 (UBase_t) SYSCTL_enMEM_CLOCKEDGE_FAILING)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeWriteRegisterAction(MEMORY_TIM0_OFFSET,
                                                 MEMORY_TIM0_EEPROM_BCE_MASK,
                                                 MEMORY_TIM0_R_EEPROM_BCE_BIT,
                                                 (UBase_t) SYSCTL_enMEM_CLOCKEDGE_FAILING)));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enSetMemoryTiming(SYSCTL_enMODULE_0, 16000000UL));
}

/**
 * @brief Validate the 120 MHz predefined timing entry in the composite setter.
 * @summary Confirms that `SYSCTL__enSetMemoryTiming` selects the documented
 *          120 MHz MEMTIM0 table entry and applies the corresponding BCHT,
 *          wait-state, and edge-field writes.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_MemoryTiming.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MEMTIM0-013@endverbatim
 */
TEST(SYSCTL_MemoryTimingTest, SetMemoryTimingUses120MHzEntry)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    InSequence stSequence;

    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeWriteRegisterAction(MEMORY_TIM0_OFFSET,
                                                 MEMORY_TIM0_FLASH_BCHT_MASK,
                                                 MEMORY_TIM0_R_FLASH_BCHT_BIT,
                                                 (UBase_t) SYSCTL_enMEM_HIGHTIME_3_5)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeWriteRegisterAction(MEMORY_TIM0_OFFSET,
                                                 MEMORY_TIM0_EEPROM_BCHT_MASK,
                                                 MEMORY_TIM0_R_EEPROM_BCHT_BIT,
                                                 (UBase_t) SYSCTL_enMEM_HIGHTIME_3_5)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeWriteRegisterAction(MEMORY_TIM0_OFFSET,
                                                 MEMORY_TIM0_FLASH_WS_MASK,
                                                 MEMORY_TIM0_R_FLASH_WS_BIT,
                                                 (UBase_t) SYSCTL_enMEM_WAITSTATE_5)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeWriteRegisterAction(MEMORY_TIM0_OFFSET,
                                                 MEMORY_TIM0_EEPROM_WS_MASK,
                                                 MEMORY_TIM0_R_EEPROM_WS_BIT,
                                                 (UBase_t) SYSCTL_enMEM_WAITSTATE_5)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeWriteRegisterAction(MEMORY_TIM0_OFFSET,
                                                 MEMORY_TIM0_FLASH_BCE_MASK,
                                                 MEMORY_TIM0_R_FLASH_BCE_BIT,
                                                 (UBase_t) SYSCTL_enMEM_CLOCKEDGE_RISING)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeWriteRegisterAction(MEMORY_TIM0_OFFSET,
                                                 MEMORY_TIM0_EEPROM_BCE_MASK,
                                                 MEMORY_TIM0_R_EEPROM_BCE_BIT,
                                                 (UBase_t) SYSCTL_enMEM_CLOCKEDGE_RISING)));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enSetMemoryTiming(SYSCTL_enMODULE_0, 120000000UL));
}

/**
 * @brief Validate out-of-range rejection and early exit on wait-state write failure.
 * @summary Confirms that `SYSCTL__enSetMemoryTiming` rejects frequencies above
 *          the documented table range before any writes occur and stops immediately
 *          when the wait-state programming stage reports a write error.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_MemoryTiming.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MEMTIM0-014@endverbatim
 */
TEST(SYSCTL_MemoryTimingTest, SetMemoryTimingRejectsOutOfRangeFrequencyAndStopsOnWaitStateError)
{
    EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enSetMemoryTiming(SYSCTL_enMODULE_0, 120000001UL));

    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    InSequence stSequence;

    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeWriteRegisterAction(MEMORY_TIM0_OFFSET,
                                                 MEMORY_TIM0_FLASH_BCHT_MASK,
                                                 MEMORY_TIM0_R_FLASH_BCHT_BIT,
                                                 (UBase_t) SYSCTL_enMEM_HIGHTIME_1_5)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeWriteRegisterAction(MEMORY_TIM0_OFFSET,
                                                 MEMORY_TIM0_EEPROM_BCHT_MASK,
                                                 MEMORY_TIM0_R_EEPROM_BCHT_BIT,
                                                 (UBase_t) SYSCTL_enMEM_HIGHTIME_1_5)));
    EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke(MakeWriteRegisterAction(MEMORY_TIM0_OFFSET,
                                                 MEMORY_TIM0_FLASH_WS_MASK,
                                                 MEMORY_TIM0_R_FLASH_WS_BIT,
                                                 (UBase_t) SYSCTL_enMEM_WAITSTATE_1,
                                                 SYSCTL_enERROR_VALUE)));

    EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enSetMemoryTiming(SYSCTL_enMODULE_0, 40000000UL));
}

/**
 * @brief Validate composite getter ordering and early exit on the first read failure.
 * @summary Confirms that `SYSCTL__enGetMemoryTiming` reads BCHT, then wait state,
 *          then clock edge in that order and stops immediately when a later stage fails.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_MemoryTiming.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MEMTIM0-015@endverbatim
 */
TEST(SYSCTL_MemoryTimingTest, GetMemoryTimingUsesHighWaitStateClockEdgeOrderingAndStopsOnFirstError)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nMEM_HIGHTIME enHighTimeReg;
        SYSCTL_nMEM_WAITSTATE enWaitStateReg;
        SYSCTL_nMEM_CLOCKEDGE enClockEdgeReg;

        enHighTimeReg = SYSCTL_enMEM_HIGHTIME_UNDEF;
        enWaitStateReg = SYSCTL_enMEM_WAITSTATE_UNDEF;
        enClockEdgeReg = SYSCTL_enMEM_CLOCKEDGE_UNDEF;

        {
            InSequence stSequence;
            EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
                .WillOnce(Invoke(MakeReadRegisterAction(MEMORY_TIM0_OFFSET,
                                                        MEMORY_TIM0_FLASH_BCHT_MASK,
                                                        MEMORY_TIM0_R_FLASH_BCHT_BIT,
                                                        (UBase_t) SYSCTL_enMEM_HIGHTIME_3_5)));
            EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
                .WillOnce(Invoke(MakeReadRegisterAction(MEMORY_TIM0_OFFSET,
                                                        MEMORY_TIM0_EEPROM_BCHT_MASK,
                                                        MEMORY_TIM0_R_EEPROM_BCHT_BIT,
                                                        (UBase_t) SYSCTL_enMEM_HIGHTIME_3_5)));
            EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
                .WillOnce(Invoke(MakeReadRegisterAction(MEMORY_TIM0_OFFSET,
                                                        MEMORY_TIM0_FLASH_WS_MASK,
                                                        MEMORY_TIM0_R_FLASH_WS_BIT,
                                                        (UBase_t) SYSCTL_enMEM_WAITSTATE_5)));
            EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
                .WillOnce(Invoke(MakeReadRegisterAction(MEMORY_TIM0_OFFSET,
                                                        MEMORY_TIM0_EEPROM_WS_MASK,
                                                        MEMORY_TIM0_R_EEPROM_WS_BIT,
                                                        (UBase_t) SYSCTL_enMEM_WAITSTATE_5)));
            EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
                .WillOnce(Invoke(MakeReadRegisterAction(MEMORY_TIM0_OFFSET,
                                                        MEMORY_TIM0_FLASH_BCE_MASK,
                                                        MEMORY_TIM0_R_FLASH_BCE_BIT,
                                                        (UBase_t) SYSCTL_enMEM_CLOCKEDGE_FAILING)));
            EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
                .WillOnce(Invoke(MakeReadRegisterAction(MEMORY_TIM0_OFFSET,
                                                        MEMORY_TIM0_EEPROM_BCE_MASK,
                                                        MEMORY_TIM0_R_EEPROM_BCE_BIT,
                                                        (UBase_t) SYSCTL_enMEM_CLOCKEDGE_FAILING)));
        }

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enGetMemoryTiming(SYSCTL_enMODULE_0, &enHighTimeReg, &enWaitStateReg, &enClockEdgeReg));
        EXPECT_EQ(SYSCTL_enMEM_HIGHTIME_3_5, enHighTimeReg);
        EXPECT_EQ(SYSCTL_enMEM_WAITSTATE_5, enWaitStateReg);
        EXPECT_EQ(SYSCTL_enMEM_CLOCKEDGE_FAILING, enClockEdgeReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nMEM_HIGHTIME enHighTimeReg;
        SYSCTL_nMEM_WAITSTATE enWaitStateReg;
        SYSCTL_nMEM_CLOCKEDGE enClockEdgeReg;

        enHighTimeReg = SYSCTL_enMEM_HIGHTIME_UNDEF;
        enWaitStateReg = SYSCTL_enMEM_WAITSTATE_UNDEF;
        enClockEdgeReg = SYSCTL_enMEM_CLOCKEDGE_UNDEF;

        {
            InSequence stSequence;
            EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
                .WillOnce(Invoke(MakeReadRegisterAction(MEMORY_TIM0_OFFSET,
                                                        MEMORY_TIM0_FLASH_BCHT_MASK,
                                                        MEMORY_TIM0_R_FLASH_BCHT_BIT,
                                                        (UBase_t) SYSCTL_enMEM_HIGHTIME_1_5)));
            EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
                .WillOnce(Invoke(MakeReadRegisterAction(MEMORY_TIM0_OFFSET,
                                                        MEMORY_TIM0_EEPROM_BCHT_MASK,
                                                        MEMORY_TIM0_R_EEPROM_BCHT_BIT,
                                                        (UBase_t) SYSCTL_enMEM_HIGHTIME_1_5)));
            EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
                .WillOnce(Invoke(MakeReadRegisterAction(MEMORY_TIM0_OFFSET,
                                                        MEMORY_TIM0_FLASH_WS_MASK,
                                                        MEMORY_TIM0_R_FLASH_WS_BIT,
                                                        0UL,
                                                        SYSCTL_enERROR_VALUE)));
        }

        EXPECT_EQ(SYSCTL_enERROR_VALUE,
                  SYSCTL__enGetMemoryTiming(SYSCTL_enMODULE_0, &enHighTimeReg, &enWaitStateReg, &enClockEdgeReg));
        EXPECT_EQ(SYSCTL_enMEM_HIGHTIME_1_5, enHighTimeReg);
        EXPECT_EQ(SYSCTL_enMEM_WAITSTATE_UNDEF, enWaitStateReg);
        EXPECT_EQ(SYSCTL_enMEM_CLOCKEDGE_UNDEF, enClockEdgeReg);
    }
}
