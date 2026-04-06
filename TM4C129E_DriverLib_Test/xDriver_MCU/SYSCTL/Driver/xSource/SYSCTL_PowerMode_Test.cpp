/**
 *
 * @file SYSCTL_PowerMode_Test.cpp
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
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_PowerMode.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_DSLPPWRCFG.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_SDPMST.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_SLPPWRCFG.h>
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
 * @brief Validate sleep and deep-sleep field routing in the individual power-mode setters.
 * @summary Confirms that the SRAMPM, FLASHPM, TSPD, and LDOSM public setters
 *          write the documented `SLPPWRCFG` and `DSLPPWRCFG` fields with the
 *          caller-provided mode or state encodings.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_PowerMode.c
 * - SYSCTL power-mode register definitions@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-PWRMODE-001@endverbatim
 */
TEST(SYSCTL_PowerModeTest, SetPowerModeFieldWrappersUseExpectedSleepAndDeepSleepFields)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(SLPPWR_CFG_OFFSET,
                                                     SLPPWR_CFG_SRAM_PM_MASK,
                                                     SLPPWR_CFG_R_SRAM_PM_BIT,
                                                     (UBase_t) SYSCTL_enSRAM_POWER_MODE_STANDBY)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enSetSRAMPowerModeOnSleepMode(SYSCTL_enMODULE_0,
                                                        SYSCTL_enSRAM_POWER_MODE_STANDBY));
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(SLPPWR_CFG_OFFSET,
                                                     SLPPWR_CFG_FLASH_PM_MASK,
                                                     SLPPWR_CFG_R_FLASH_PM_BIT,
                                                     (UBase_t) SYSCTL_enFLASH_POWER_MODE_LOW_POWER)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enSetFlashPowerModeOnSleepMode(SYSCTL_enMODULE_0,
                                                         SYSCTL_enFLASH_POWER_MODE_LOW_POWER));
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(DSLPPWR_CFG_OFFSET,
                                                     DSLPPWR_CFG_SRAM_PM_MASK,
                                                     DSLPPWR_CFG_R_SRAM_PM_BIT,
                                                     (UBase_t) SYSCTL_enSRAM_POWER_MODE_LOW_POWER)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enSetSRAMPowerModeOnDeepSleepMode(SYSCTL_enMODULE_0,
                                                            SYSCTL_enSRAM_POWER_MODE_LOW_POWER));
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(DSLPPWR_CFG_OFFSET,
                                                     DSLPPWR_CFG_FLASH_PM_MASK,
                                                     DSLPPWR_CFG_R_FLASH_PM_BIT,
                                                     (UBase_t) SYSCTL_enFLASH_POWER_MODE_LOW_POWER)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enSetFlashPowerModeOnDeepSleepMode(SYSCTL_enMODULE_0,
                                                             SYSCTL_enFLASH_POWER_MODE_LOW_POWER));
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(DSLPPWR_CFG_OFFSET,
                                                     DSLPPWR_CFG_TS_PD_MASK,
                                                     DSLPPWR_CFG_R_TS_PD_BIT,
                                                     (UBase_t) SYSCTL_enSTATE_ENA)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enUseTempSensorPowerDownOnDeepSleepMode(SYSCTL_enMODULE_0,
                                                                  SYSCTL_enSTATE_ENA));
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(DSLPPWR_CFG_OFFSET,
                                                     DSLPPWR_CFG_LDO_SM_MASK,
                                                     DSLPPWR_CFG_R_LDO_SM_BIT,
                                                     (UBase_t) SYSCTL_enSTATE_ENA)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enUseLDOSleepModeOnDeepSleepMode(SYSCTL_enMODULE_0,
                                                           SYSCTL_enSTATE_ENA));
    }
}

/**
 * @brief Validate null-pointer rejection across the individual power-mode getters.
 * @summary Confirms that the individual mode, state, and status getters reject
 *          null destination pointers before any primitive register access occurs.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_PowerMode.c
 * - Public API parameter validation path@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-PWRMODE-002@endverbatim
 */
TEST(SYSCTL_PowerModeTest, PowerModeIndividualGettersRejectNullPointer)
{
    SYSCTL_nFLASH_POWER_MODE enFlashPowerModeReg;

    enFlashPowerModeReg = SYSCTL_enFLASH_POWER_MODE_ACTIVE;

    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetSRAMPowerModeOnSleepMode(SYSCTL_enMODULE_0, (SYSCTL_nSRAM_POWER_MODE*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetFlashPowerModeOnSleepMode(SYSCTL_enMODULE_0, (SYSCTL_nFLASH_POWER_MODE*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetPowerModeOnSleepMode(SYSCTL_enMODULE_0,
                                                (SYSCTL_nSRAM_POWER_MODE*) 0UL,
                                                &enFlashPowerModeReg));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetSRAMPowerModeOnDeepSleepMode(SYSCTL_enMODULE_0, (SYSCTL_nSRAM_POWER_MODE*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetFlashPowerModeOnDeepSleepMode(SYSCTL_enMODULE_0, (SYSCTL_nFLASH_POWER_MODE*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetPowerModeOnDeepSleepMode(SYSCTL_enMODULE_0,
                                                    (SYSCTL_nSRAM_POWER_MODE*) 0UL,
                                                    &enFlashPowerModeReg));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enIsTempSensorPowerDownOnDeepSleepModeUsed(SYSCTL_enMODULE_0, (SYSCTL_nBOOLEAN*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enIsLDOSleepModeOnDeepSleepModeUsed(SYSCTL_enMODULE_0, (SYSCTL_nBOOLEAN*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enIsSRAMPowerDownRequestError(SYSCTL_enMODULE_0, (SYSCTL_nBOOLEAN*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enIsFlashPowerDownRequestError(SYSCTL_enMODULE_0, (SYSCTL_nBOOLEAN*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enIsPIOSCPowerDownRequestError(SYSCTL_enMODULE_0, (SYSCTL_nBOOLEAN*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enIsDeepSleepLDOMinimumVoltageError(SYSCTL_enMODULE_0, (SYSCTL_nBOOLEAN*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enIsSleepLDOMinimumVoltageError(SYSCTL_enMODULE_0, (SYSCTL_nBOOLEAN*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enIsLDOMaximumVoltageError(SYSCTL_enMODULE_0, (SYSCTL_nBOOLEAN*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enIsPIOSCPowerDownRequestWarning(SYSCTL_enMODULE_0, (SYSCTL_nBOOLEAN*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enIsPowerModeRequestActive(SYSCTL_enMODULE_0, (SYSCTL_nBOOLEAN*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enIsLowPowerModeActive(SYSCTL_enMODULE_0, (SYSCTL_nBOOLEAN*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enIsFlashLowPowerModeActive(SYSCTL_enMODULE_0, (SYSCTL_nBOOLEAN*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enIsLDOUpdateActive(SYSCTL_enMODULE_0, (SYSCTL_nBOOLEAN*) 0UL));
}

/**
 * @brief Validate sleep and deep-sleep field reads in the individual power-mode getters.
 * @summary Confirms that the SRAMPM, FLASHPM, TSPD, and LDOSM public getters
 *          read the documented `SLPPWRCFG` and `DSLPPWRCFG` fields and return
 *          the decoded mode or state values.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_PowerMode.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-PWRMODE-003@endverbatim
 */
TEST(SYSCTL_PowerModeTest, GetPowerModeFieldWrappersUseExpectedSleepAndDeepSleepFields)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nSRAM_POWER_MODE enPowerModeReg;

        enPowerModeReg = SYSCTL_enSRAM_POWER_MODE_ACTIVE;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(SLPPWR_CFG_OFFSET,
                                                    SLPPWR_CFG_SRAM_PM_MASK,
                                                    SLPPWR_CFG_R_SRAM_PM_BIT,
                                                    (UBase_t) SYSCTL_enSRAM_POWER_MODE_LOW_POWER)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enGetSRAMPowerModeOnSleepMode(SYSCTL_enMODULE_0, &enPowerModeReg));
        EXPECT_EQ(SYSCTL_enSRAM_POWER_MODE_LOW_POWER, enPowerModeReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nFLASH_POWER_MODE enPowerModeReg;

        enPowerModeReg = SYSCTL_enFLASH_POWER_MODE_ACTIVE;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(SLPPWR_CFG_OFFSET,
                                                    SLPPWR_CFG_FLASH_PM_MASK,
                                                    SLPPWR_CFG_R_FLASH_PM_BIT,
                                                    (UBase_t) SYSCTL_enFLASH_POWER_MODE_LOW_POWER)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enGetFlashPowerModeOnSleepMode(SYSCTL_enMODULE_0, &enPowerModeReg));
        EXPECT_EQ(SYSCTL_enFLASH_POWER_MODE_LOW_POWER, enPowerModeReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nSRAM_POWER_MODE enPowerModeReg;

        enPowerModeReg = SYSCTL_enSRAM_POWER_MODE_ACTIVE;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(DSLPPWR_CFG_OFFSET,
                                                    DSLPPWR_CFG_SRAM_PM_MASK,
                                                    DSLPPWR_CFG_R_SRAM_PM_BIT,
                                                    (UBase_t) SYSCTL_enSRAM_POWER_MODE_STANDBY)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enGetSRAMPowerModeOnDeepSleepMode(SYSCTL_enMODULE_0, &enPowerModeReg));
        EXPECT_EQ(SYSCTL_enSRAM_POWER_MODE_STANDBY, enPowerModeReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nFLASH_POWER_MODE enPowerModeReg;

        enPowerModeReg = SYSCTL_enFLASH_POWER_MODE_ACTIVE;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(DSLPPWR_CFG_OFFSET,
                                                    DSLPPWR_CFG_FLASH_PM_MASK,
                                                    DSLPPWR_CFG_R_FLASH_PM_BIT,
                                                    (UBase_t) SYSCTL_enFLASH_POWER_MODE_LOW_POWER)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enGetFlashPowerModeOnDeepSleepMode(SYSCTL_enMODULE_0, &enPowerModeReg));
        EXPECT_EQ(SYSCTL_enFLASH_POWER_MODE_LOW_POWER, enPowerModeReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nBOOLEAN enStateReg;

        enStateReg = SYSCTL_enFALSE;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(DSLPPWR_CFG_OFFSET,
                                                    DSLPPWR_CFG_TS_PD_MASK,
                                                    DSLPPWR_CFG_R_TS_PD_BIT,
                                                    (UBase_t) SYSCTL_enTRUE)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enIsTempSensorPowerDownOnDeepSleepModeUsed(SYSCTL_enMODULE_0, &enStateReg));
        EXPECT_EQ(SYSCTL_enTRUE, enStateReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nBOOLEAN enStateReg;

        enStateReg = SYSCTL_enFALSE;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(DSLPPWR_CFG_OFFSET,
                                                    DSLPPWR_CFG_LDO_SM_MASK,
                                                    DSLPPWR_CFG_R_LDO_SM_BIT,
                                                    (UBase_t) SYSCTL_enTRUE)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enIsLDOSleepModeOnDeepSleepModeUsed(SYSCTL_enMODULE_0, &enStateReg));
        EXPECT_EQ(SYSCTL_enTRUE, enStateReg);
    }
}

/**
 * @brief Validate sequencing and error propagation in the grouped sleep-mode wrappers.
 * @summary Confirms that the grouped sleep-mode setters and getters route SRAM
 *          before Flash, stop on the first primitive failure, and preserve the
 *          caller state that has not yet been updated.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_PowerMode.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-PWRMODE-004@endverbatim
 */
TEST(SYSCTL_PowerModeTest, SleepPowerModeGroupedWrappersSequenceAndPropagateErrors)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        InSequence stSequence;

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(SLPPWR_CFG_OFFSET,
                                                     SLPPWR_CFG_SRAM_PM_MASK,
                                                     SLPPWR_CFG_R_SRAM_PM_BIT,
                                                     (UBase_t) SYSCTL_enSRAM_POWER_MODE_STANDBY)));
        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(SLPPWR_CFG_OFFSET,
                                                     SLPPWR_CFG_FLASH_PM_MASK,
                                                     SLPPWR_CFG_R_FLASH_PM_BIT,
                                                     (UBase_t) SYSCTL_enFLASH_POWER_MODE_LOW_POWER)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enSetPowerModeOnSleepMode(SYSCTL_enMODULE_0,
                                                    SYSCTL_enSRAM_POWER_MODE_STANDBY,
                                                    SYSCTL_enFLASH_POWER_MODE_LOW_POWER));
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(SLPPWR_CFG_OFFSET,
                                                     SLPPWR_CFG_SRAM_PM_MASK,
                                                     SLPPWR_CFG_R_SRAM_PM_BIT,
                                                     (UBase_t) SYSCTL_enSRAM_POWER_MODE_LOW_POWER,
                                                     SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE,
                  SYSCTL__enSetPowerModeOnSleepMode(SYSCTL_enMODULE_0,
                                                    SYSCTL_enSRAM_POWER_MODE_LOW_POWER,
                                                    SYSCTL_enFLASH_POWER_MODE_ACTIVE));
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        InSequence stSequence;

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(SLPPWR_CFG_OFFSET,
                                                     SLPPWR_CFG_SRAM_PM_MASK,
                                                     SLPPWR_CFG_R_SRAM_PM_BIT,
                                                     (UBase_t) SYSCTL_enSRAM_POWER_MODE_ACTIVE)));
        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(SLPPWR_CFG_OFFSET,
                                                     SLPPWR_CFG_FLASH_PM_MASK,
                                                     SLPPWR_CFG_R_FLASH_PM_BIT,
                                                     (UBase_t) SYSCTL_enFLASH_POWER_MODE_LOW_POWER,
                                                     SYSCTL_enERROR_RANGE)));

        EXPECT_EQ(SYSCTL_enERROR_RANGE,
                  SYSCTL__enSetPowerModeOnSleepMode(SYSCTL_enMODULE_0,
                                                    SYSCTL_enSRAM_POWER_MODE_ACTIVE,
                                                    SYSCTL_enFLASH_POWER_MODE_LOW_POWER));
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        InSequence stSequence;
        SYSCTL_nSRAM_POWER_MODE enSRAMPowerModeReg;
        SYSCTL_nFLASH_POWER_MODE enFlashPowerModeReg;

        enSRAMPowerModeReg = SYSCTL_enSRAM_POWER_MODE_ACTIVE;
        enFlashPowerModeReg = SYSCTL_enFLASH_POWER_MODE_ACTIVE;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(SLPPWR_CFG_OFFSET,
                                                    SLPPWR_CFG_SRAM_PM_MASK,
                                                    SLPPWR_CFG_R_SRAM_PM_BIT,
                                                    (UBase_t) SYSCTL_enSRAM_POWER_MODE_LOW_POWER)));
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(SLPPWR_CFG_OFFSET,
                                                    SLPPWR_CFG_FLASH_PM_MASK,
                                                    SLPPWR_CFG_R_FLASH_PM_BIT,
                                                    (UBase_t) SYSCTL_enFLASH_POWER_MODE_LOW_POWER)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enGetPowerModeOnSleepMode(SYSCTL_enMODULE_0,
                                                    &enSRAMPowerModeReg,
                                                    &enFlashPowerModeReg));
        EXPECT_EQ(SYSCTL_enSRAM_POWER_MODE_LOW_POWER, enSRAMPowerModeReg);
        EXPECT_EQ(SYSCTL_enFLASH_POWER_MODE_LOW_POWER, enFlashPowerModeReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nSRAM_POWER_MODE enSRAMPowerModeReg;
        SYSCTL_nFLASH_POWER_MODE enFlashPowerModeReg;

        enSRAMPowerModeReg = SYSCTL_enSRAM_POWER_MODE_STANDBY;
        enFlashPowerModeReg = SYSCTL_enFLASH_POWER_MODE_LOW_POWER;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(SLPPWR_CFG_OFFSET,
                                                    SLPPWR_CFG_SRAM_PM_MASK,
                                                    SLPPWR_CFG_R_SRAM_PM_BIT,
                                                    (UBase_t) SYSCTL_enSRAM_POWER_MODE_ACTIVE,
                                                    SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE,
                  SYSCTL__enGetPowerModeOnSleepMode(SYSCTL_enMODULE_0,
                                                    &enSRAMPowerModeReg,
                                                    &enFlashPowerModeReg));
        EXPECT_EQ(SYSCTL_enSRAM_POWER_MODE_STANDBY, enSRAMPowerModeReg);
        EXPECT_EQ(SYSCTL_enFLASH_POWER_MODE_LOW_POWER, enFlashPowerModeReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        InSequence stSequence;
        SYSCTL_nSRAM_POWER_MODE enSRAMPowerModeReg;
        SYSCTL_nFLASH_POWER_MODE enFlashPowerModeReg;

        enSRAMPowerModeReg = SYSCTL_enSRAM_POWER_MODE_ACTIVE;
        enFlashPowerModeReg = SYSCTL_enFLASH_POWER_MODE_ACTIVE;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(SLPPWR_CFG_OFFSET,
                                                    SLPPWR_CFG_SRAM_PM_MASK,
                                                    SLPPWR_CFG_R_SRAM_PM_BIT,
                                                    (UBase_t) SYSCTL_enSRAM_POWER_MODE_STANDBY)));
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(SLPPWR_CFG_OFFSET,
                                                    SLPPWR_CFG_FLASH_PM_MASK,
                                                    SLPPWR_CFG_R_FLASH_PM_BIT,
                                                    (UBase_t) SYSCTL_enFLASH_POWER_MODE_LOW_POWER,
                                                    SYSCTL_enERROR_TIMEOUT)));

        EXPECT_EQ(SYSCTL_enERROR_TIMEOUT,
                  SYSCTL__enGetPowerModeOnSleepMode(SYSCTL_enMODULE_0,
                                                    &enSRAMPowerModeReg,
                                                    &enFlashPowerModeReg));
        EXPECT_EQ(SYSCTL_enSRAM_POWER_MODE_STANDBY, enSRAMPowerModeReg);
        EXPECT_EQ(SYSCTL_enFLASH_POWER_MODE_ACTIVE, enFlashPowerModeReg);
    }
}

/**
 * @brief Validate sequencing and error propagation in the grouped deep-sleep wrappers.
 * @summary Confirms that the grouped deep-sleep setters and getters route SRAM
 *          before Flash, stop on the first primitive failure, and preserve the
 *          caller state that has not yet been updated.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_PowerMode.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-PWRMODE-005@endverbatim
 */
TEST(SYSCTL_PowerModeTest, DeepSleepPowerModeGroupedWrappersSequenceAndPropagateErrors)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        InSequence stSequence;

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(DSLPPWR_CFG_OFFSET,
                                                     DSLPPWR_CFG_SRAM_PM_MASK,
                                                     DSLPPWR_CFG_R_SRAM_PM_BIT,
                                                     (UBase_t) SYSCTL_enSRAM_POWER_MODE_LOW_POWER)));
        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(DSLPPWR_CFG_OFFSET,
                                                     DSLPPWR_CFG_FLASH_PM_MASK,
                                                     DSLPPWR_CFG_R_FLASH_PM_BIT,
                                                     (UBase_t) SYSCTL_enFLASH_POWER_MODE_LOW_POWER)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enSetPowerModeOnDeepSleepMode(SYSCTL_enMODULE_0,
                                                        SYSCTL_enSRAM_POWER_MODE_LOW_POWER,
                                                        SYSCTL_enFLASH_POWER_MODE_LOW_POWER));
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(DSLPPWR_CFG_OFFSET,
                                                     DSLPPWR_CFG_SRAM_PM_MASK,
                                                     DSLPPWR_CFG_R_SRAM_PM_BIT,
                                                     (UBase_t) SYSCTL_enSRAM_POWER_MODE_STANDBY,
                                                     SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE,
                  SYSCTL__enSetPowerModeOnDeepSleepMode(SYSCTL_enMODULE_0,
                                                        SYSCTL_enSRAM_POWER_MODE_STANDBY,
                                                        SYSCTL_enFLASH_POWER_MODE_ACTIVE));
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        InSequence stSequence;

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(DSLPPWR_CFG_OFFSET,
                                                     DSLPPWR_CFG_SRAM_PM_MASK,
                                                     DSLPPWR_CFG_R_SRAM_PM_BIT,
                                                     (UBase_t) SYSCTL_enSRAM_POWER_MODE_ACTIVE)));
        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(DSLPPWR_CFG_OFFSET,
                                                     DSLPPWR_CFG_FLASH_PM_MASK,
                                                     DSLPPWR_CFG_R_FLASH_PM_BIT,
                                                     (UBase_t) SYSCTL_enFLASH_POWER_MODE_LOW_POWER,
                                                     SYSCTL_enERROR_RANGE)));

        EXPECT_EQ(SYSCTL_enERROR_RANGE,
                  SYSCTL__enSetPowerModeOnDeepSleepMode(SYSCTL_enMODULE_0,
                                                        SYSCTL_enSRAM_POWER_MODE_ACTIVE,
                                                        SYSCTL_enFLASH_POWER_MODE_LOW_POWER));
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        InSequence stSequence;
        SYSCTL_nSRAM_POWER_MODE enSRAMPowerModeReg;
        SYSCTL_nFLASH_POWER_MODE enFlashPowerModeReg;

        enSRAMPowerModeReg = SYSCTL_enSRAM_POWER_MODE_ACTIVE;
        enFlashPowerModeReg = SYSCTL_enFLASH_POWER_MODE_ACTIVE;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(DSLPPWR_CFG_OFFSET,
                                                    DSLPPWR_CFG_SRAM_PM_MASK,
                                                    DSLPPWR_CFG_R_SRAM_PM_BIT,
                                                    (UBase_t) SYSCTL_enSRAM_POWER_MODE_STANDBY)));
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(DSLPPWR_CFG_OFFSET,
                                                    DSLPPWR_CFG_FLASH_PM_MASK,
                                                    DSLPPWR_CFG_R_FLASH_PM_BIT,
                                                    (UBase_t) SYSCTL_enFLASH_POWER_MODE_LOW_POWER)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enGetPowerModeOnDeepSleepMode(SYSCTL_enMODULE_0,
                                                        &enSRAMPowerModeReg,
                                                        &enFlashPowerModeReg));
        EXPECT_EQ(SYSCTL_enSRAM_POWER_MODE_STANDBY, enSRAMPowerModeReg);
        EXPECT_EQ(SYSCTL_enFLASH_POWER_MODE_LOW_POWER, enFlashPowerModeReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nSRAM_POWER_MODE enSRAMPowerModeReg;
        SYSCTL_nFLASH_POWER_MODE enFlashPowerModeReg;

        enSRAMPowerModeReg = SYSCTL_enSRAM_POWER_MODE_LOW_POWER;
        enFlashPowerModeReg = SYSCTL_enFLASH_POWER_MODE_LOW_POWER;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(DSLPPWR_CFG_OFFSET,
                                                    DSLPPWR_CFG_SRAM_PM_MASK,
                                                    DSLPPWR_CFG_R_SRAM_PM_BIT,
                                                    (UBase_t) SYSCTL_enSRAM_POWER_MODE_ACTIVE,
                                                    SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE,
                  SYSCTL__enGetPowerModeOnDeepSleepMode(SYSCTL_enMODULE_0,
                                                        &enSRAMPowerModeReg,
                                                        &enFlashPowerModeReg));
        EXPECT_EQ(SYSCTL_enSRAM_POWER_MODE_LOW_POWER, enSRAMPowerModeReg);
        EXPECT_EQ(SYSCTL_enFLASH_POWER_MODE_LOW_POWER, enFlashPowerModeReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        InSequence stSequence;
        SYSCTL_nSRAM_POWER_MODE enSRAMPowerModeReg;
        SYSCTL_nFLASH_POWER_MODE enFlashPowerModeReg;

        enSRAMPowerModeReg = SYSCTL_enSRAM_POWER_MODE_ACTIVE;
        enFlashPowerModeReg = SYSCTL_enFLASH_POWER_MODE_ACTIVE;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(DSLPPWR_CFG_OFFSET,
                                                    DSLPPWR_CFG_SRAM_PM_MASK,
                                                    DSLPPWR_CFG_R_SRAM_PM_BIT,
                                                    (UBase_t) SYSCTL_enSRAM_POWER_MODE_LOW_POWER)));
        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(DSLPPWR_CFG_OFFSET,
                                                    DSLPPWR_CFG_FLASH_PM_MASK,
                                                    DSLPPWR_CFG_R_FLASH_PM_BIT,
                                                    (UBase_t) SYSCTL_enFLASH_POWER_MODE_ACTIVE,
                                                    SYSCTL_enERROR_TIMEOUT)));

        EXPECT_EQ(SYSCTL_enERROR_TIMEOUT,
                  SYSCTL__enGetPowerModeOnDeepSleepMode(SYSCTL_enMODULE_0,
                                                        &enSRAMPowerModeReg,
                                                        &enFlashPowerModeReg));
        EXPECT_EQ(SYSCTL_enSRAM_POWER_MODE_LOW_POWER, enSRAMPowerModeReg);
        EXPECT_EQ(SYSCTL_enFLASH_POWER_MODE_ACTIVE, enFlashPowerModeReg);
    }
}

/**
 * @brief Validate SDPMST bit reads in the public power-mode status getters.
 * @summary Confirms that the power-mode status getters read the documented
 *          error, warning, and live-status bits from `SDPMST` and return the
 *          decoded boolean state.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_PowerMode.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-PWRMODE-006@endverbatim
 */
TEST(SYSCTL_PowerModeTest, PowerModeStatusGettersUseExpectedStatusBits)
{
    using tPowerModeStatusGetter = SYSCTL_nERROR (*)(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStatusArg);

    auto RunStatusGetter = [](tPowerModeStatusGetter pfGetterArg, UBase_t uxMaskArg, UBase_t uxShiftArg)
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nBOOLEAN enStatusReg;

        enStatusReg = SYSCTL_enFALSE;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(SDP_MST_OFFSET,
                                                    uxMaskArg,
                                                    uxShiftArg,
                                                    (UBase_t) SYSCTL_enTRUE)));

        EXPECT_EQ(SYSCTL_enERROR_OK, pfGetterArg(SYSCTL_enMODULE_0, &enStatusReg));
        EXPECT_EQ(SYSCTL_enTRUE, enStatusReg);
    };

    RunStatusGetter(&SYSCTL__enIsSRAMPowerDownRequestError, SDP_MST_SRAM_PD_ERR_MASK,
                    SDP_MST_R_SRAM_PD_ERR_BIT);
    RunStatusGetter(&SYSCTL__enIsFlashPowerDownRequestError, SDP_MST_FLASH_PD_ERR_MASK,
                    SDP_MST_R_FLASH_PD_ERR_BIT);
    RunStatusGetter(&SYSCTL__enIsPIOSCPowerDownRequestError, SDP_MST_PIOSC_PD_ERR_MASK,
                    SDP_MST_R_PIOSC_PD_ERR_BIT);
    RunStatusGetter(&SYSCTL__enIsDeepSleepLDOMinimumVoltageError, SDP_MST_VLDO_DMIN_ERR_MASK,
                    SDP_MST_R_VLDO_DMIN_ERR_BIT);
    RunStatusGetter(&SYSCTL__enIsSleepLDOMinimumVoltageError, SDP_MST_VLDO_SMIN_ERR_MASK,
                    SDP_MST_R_VLDO_SMIN_ERR_BIT);
    RunStatusGetter(&SYSCTL__enIsLDOMaximumVoltageError, SDP_MST_VLDO_MAX_ERR_MASK,
                    SDP_MST_R_VLDO_MAX_ERR_BIT);
    RunStatusGetter(&SYSCTL__enIsPIOSCPowerDownRequestWarning, SDP_MST_PIOSC_PD_WARNING_MASK,
                    SDP_MST_R_PIOSC_PD_WARNING_BIT);
    RunStatusGetter(&SYSCTL__enIsPowerModeRequestActive, SDP_MST_LOW_ACTIVE_MASK,
                    SDP_MST_R_LOW_ACTIVE_BIT);
    RunStatusGetter(&SYSCTL__enIsLowPowerModeActive, SDP_MST_LOW_PWR_MASK,
                    SDP_MST_R_LOW_PWR_BIT);
    RunStatusGetter(&SYSCTL__enIsFlashLowPowerModeActive, SDP_MST_FLASH_LP_MASK,
                    SDP_MST_R_FLASH_LP_BIT);
    RunStatusGetter(&SYSCTL__enIsLDOUpdateActive, SDP_MST_LDO_UA_MASK,
                    SDP_MST_R_LDO_UA_BIT);
}