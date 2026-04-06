/**
 *
 * @file SYSCTL_ModulePower_Test.cpp
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
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_ModulePower.h>
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
 * @brief Validate control-register routing in the public module-memory setter.
 * @summary Confirms that the public module-memory power-control setter selects
 *          the documented `USBMPC`, `EMACMPC`, `CAN0MPC`, or `CAN1MPC`
 *          register offset and writes the requested OFF, retention, or ON field
 *          encoding through the SYSCTL primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_ModulePower.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MODPWR-001@endverbatim
 */
TEST(SYSCTL_ModulePowerTest, SetModuleMemoryPowerControlStateUsesExpectedModuleControlRegisters)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(USB_MPC_OFFSET,
                                                     0x00000003UL,
                                                     0UL,
                                                     (UBase_t) SYSCTL_enMODULE_MEMORY_POWER_RETENTION)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enSetModuleMemoryPowerControlState(SYSCTL_enMODULE_0,
                                                             SYSCTL_enUSB,
                                                             SYSCTL_enMODULE_MEMORY_POWER_RETENTION));
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(EMAC_MPC_OFFSET,
                                                     0x00000003UL,
                                                     0UL,
                                                     (UBase_t) SYSCTL_enMODULE_MEMORY_POWER_ON)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enSetModuleMemoryPowerControlState(SYSCTL_enMODULE_0,
                                                             SYSCTL_enEMAC,
                                                             SYSCTL_enMODULE_MEMORY_POWER_ON));
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(CAN0_MPC_OFFSET,
                                                     0x00000003UL,
                                                     0UL,
                                                     (UBase_t) SYSCTL_enMODULE_MEMORY_POWER_OFF)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enSetModuleMemoryPowerControlState(SYSCTL_enMODULE_0,
                                                             SYSCTL_enCAN0,
                                                             SYSCTL_enMODULE_MEMORY_POWER_OFF));
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(CAN1_MPC_OFFSET,
                                                     0x00000003UL,
                                                     0UL,
                                                     (UBase_t) SYSCTL_enMODULE_MEMORY_POWER_ON)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enSetModuleMemoryPowerControlState(SYSCTL_enMODULE_0,
                                                             SYSCTL_enCAN1,
                                                             SYSCTL_enMODULE_MEMORY_POWER_ON));
    }
}

/**
 * @brief Validate convenience-wrapper routing and unsupported-retention rejection.
 * @summary Confirms that the ON, OFF, and retention wrappers delegate through
 *          the same documented `MPC` field shape and that retention requests are
 *          rejected for modules whose manual descriptions only allow OFF and ON.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_ModulePower.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MODPWR-002@endverbatim
 */
TEST(SYSCTL_ModulePowerTest, ModuleMemoryControlWrappersUseExpectedValuesAndRejectUnsupportedRetention)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(CAN0_MPC_OFFSET,
                                                     0x00000003UL,
                                                     0UL,
                                                     (UBase_t) SYSCTL_enMODULE_MEMORY_POWER_ON)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enPowerOnModuleMemory(SYSCTL_enMODULE_0, SYSCTL_enCAN0));
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(EMAC_MPC_OFFSET,
                                                     0x00000003UL,
                                                     0UL,
                                                     (UBase_t) SYSCTL_enMODULE_MEMORY_POWER_OFF)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enPowerOffModuleMemory(SYSCTL_enMODULE_0, SYSCTL_enEMAC));
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);

        EXPECT_CALL(stMock, WriteRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeWriteRegisterAction(USB_MPC_OFFSET,
                                                     0x00000003UL,
                                                     0UL,
                                                     (UBase_t) SYSCTL_enMODULE_MEMORY_POWER_RETENTION)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enRetainModuleMemory(SYSCTL_enMODULE_0, SYSCTL_enUSB));
    }

    EXPECT_EQ(SYSCTL_enERROR_VALUE,
              SYSCTL__enRetainModuleMemory(SYSCTL_enMODULE_0, SYSCTL_enEMAC));
    EXPECT_EQ(SYSCTL_enERROR_VALUE,
              SYSCTL__enSetModuleMemoryPowerControlState(SYSCTL_enMODULE_0,
                                                         SYSCTL_enGPIOA,
                                                         SYSCTL_enMODULE_MEMORY_POWER_ON));
}

/**
 * @brief Validate public getter parameter validation and selector rejection.
 * @summary Confirms that the public module-memory control and status getters
 *          reject null output pointers before register access and reject
 *          unsupported peripheral selectors before invoking the primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_ModulePower.c
 * - Public API parameter validation path@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MODPWR-003@endverbatim
 */
TEST(SYSCTL_ModulePowerTest, ModuleMemoryGettersRejectInvalidSelectorsAndNullPointers)
{
    SYSCTL_nMODULE_MEMORY_POWER enControlStateReg;
    SYSCTL_nMODULE_POWER_STATUS enPowerStateReg;
    SYSCTL_nMODULE_MEMORY_POWER enMemoryStateReg;

    enControlStateReg = SYSCTL_enMODULE_MEMORY_POWER_ON;
    enPowerStateReg = SYSCTL_enMODULE_POWER_STATUS_ON;
    enMemoryStateReg = SYSCTL_enMODULE_MEMORY_POWER_OFF;

    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetModuleMemoryPowerControlState(SYSCTL_enMODULE_0,
                                                         SYSCTL_enUSB,
                                                         (SYSCTL_nMODULE_MEMORY_POWER*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetModulePowerState(SYSCTL_enMODULE_0,
                                            SYSCTL_enUSB,
                                            (SYSCTL_nMODULE_POWER_STATUS*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetModuleMemoryState(SYSCTL_enMODULE_0,
                                             SYSCTL_enUSB,
                                             (SYSCTL_nMODULE_MEMORY_POWER*) 0UL));

    EXPECT_EQ(SYSCTL_enERROR_VALUE,
              SYSCTL__enGetModuleMemoryPowerControlState(SYSCTL_enMODULE_0,
                                                         SYSCTL_enGPIOA,
                                                         &enControlStateReg));
    EXPECT_EQ(SYSCTL_enERROR_VALUE,
              SYSCTL__enGetModulePowerState(SYSCTL_enMODULE_0,
                                            SYSCTL_enGPIOA,
                                            &enPowerStateReg));
    EXPECT_EQ(SYSCTL_enERROR_VALUE,
              SYSCTL__enGetModuleMemoryState(SYSCTL_enMODULE_0,
                                             SYSCTL_enGPIOA,
                                             &enMemoryStateReg));
}

/**
 * @brief Validate public control and status field reads across the module-power block.
 * @summary Confirms that the public getters read the documented `USBMPC`,
 *          `EMACPDS`, and `CAN1PDS` fields with the expected offsets, masks,
 *          and shifts and return the decoded control or status values.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_ModulePower.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MODPWR-004@endverbatim
 */
TEST(SYSCTL_ModulePowerTest, GetModuleMemoryPowerControlAndStatesUseExpectedRegisters)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nMODULE_MEMORY_POWER enControlStateReg;

        enControlStateReg = SYSCTL_enMODULE_MEMORY_POWER_OFF;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(USB_MPC_OFFSET,
                                                    0x00000003UL,
                                                    0UL,
                                                    (UBase_t) SYSCTL_enMODULE_MEMORY_POWER_RETENTION)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enGetModuleMemoryPowerControlState(SYSCTL_enMODULE_0,
                                                             SYSCTL_enUSB,
                                                             &enControlStateReg));
        EXPECT_EQ(SYSCTL_enMODULE_MEMORY_POWER_RETENTION, enControlStateReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nMODULE_POWER_STATUS enPowerStateReg;

        enPowerStateReg = SYSCTL_enMODULE_POWER_STATUS_OFF;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(EMAC_PDS_OFFSET,
                                                    0x00000003UL,
                                                    0UL,
                                                    (UBase_t) SYSCTL_enMODULE_POWER_STATUS_ON)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enGetModulePowerState(SYSCTL_enMODULE_0,
                                                SYSCTL_enEMAC,
                                                &enPowerStateReg));
        EXPECT_EQ(SYSCTL_enMODULE_POWER_STATUS_ON, enPowerStateReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nMODULE_MEMORY_POWER enMemoryStateReg;

        enMemoryStateReg = SYSCTL_enMODULE_MEMORY_POWER_OFF;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(CAN1_PDS_OFFSET,
                                                    0x00000003UL,
                                                    2UL,
                                                    (UBase_t) SYSCTL_enMODULE_MEMORY_POWER_ON)));

        EXPECT_EQ(SYSCTL_enERROR_OK,
                  SYSCTL__enGetModuleMemoryState(SYSCTL_enMODULE_0,
                                                 SYSCTL_enCAN1,
                                                 &enMemoryStateReg));
        EXPECT_EQ(SYSCTL_enMODULE_MEMORY_POWER_ON, enMemoryStateReg);
    }
}

/**
 * @brief Validate primitive read-error propagation across the module-memory getters.
 * @summary Confirms that the control, power-state, and memory-state getters
 *          return primitive read failures unchanged and preserve caller output
 *          storage when the register read does not complete successfully.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_ModulePower.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-MODPWR-005@endverbatim
 */
TEST(SYSCTL_ModulePowerTest, ModuleMemoryReadGettersPropagateErrorsAndPreserveCallerState)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nMODULE_MEMORY_POWER enControlStateReg;

        enControlStateReg = SYSCTL_enMODULE_MEMORY_POWER_ON;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(USB_MPC_OFFSET,
                                                    0x00000003UL,
                                                    0UL,
                                                    0UL,
                                                    SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE,
                  SYSCTL__enGetModuleMemoryPowerControlState(SYSCTL_enMODULE_0,
                                                             SYSCTL_enUSB,
                                                             &enControlStateReg));
        EXPECT_EQ(SYSCTL_enMODULE_MEMORY_POWER_ON, enControlStateReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nMODULE_POWER_STATUS enPowerStateReg;

        enPowerStateReg = SYSCTL_enMODULE_POWER_STATUS_OFF;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(CAN0_PDS_OFFSET,
                                                    0x00000003UL,
                                                    0UL,
                                                    0UL,
                                                    SYSCTL_enERROR_TIMEOUT)));

        EXPECT_EQ(SYSCTL_enERROR_TIMEOUT,
                  SYSCTL__enGetModulePowerState(SYSCTL_enMODULE_0,
                                                SYSCTL_enCAN0,
                                                &enPowerStateReg));
        EXPECT_EQ(SYSCTL_enMODULE_POWER_STATUS_OFF, enPowerStateReg);
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stMock;
        SYSCTL_PrimitivesMockScope stMockScope(&stMock);
        SYSCTL_nMODULE_MEMORY_POWER enMemoryStateReg;

        enMemoryStateReg = SYSCTL_enMODULE_MEMORY_POWER_RETENTION;

        EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
            .WillOnce(Invoke(MakeReadRegisterAction(EMAC_PDS_OFFSET,
                                                    0x00000003UL,
                                                    2UL,
                                                    0UL,
                                                    SYSCTL_enERROR_RANGE)));

        EXPECT_EQ(SYSCTL_enERROR_RANGE,
                  SYSCTL__enGetModuleMemoryState(SYSCTL_enMODULE_0,
                                                 SYSCTL_enEMAC,
                                                 &enMemoryStateReg));
        EXPECT_EQ(SYSCTL_enMODULE_MEMORY_POWER_RETENTION, enMemoryStateReg);
    }
}