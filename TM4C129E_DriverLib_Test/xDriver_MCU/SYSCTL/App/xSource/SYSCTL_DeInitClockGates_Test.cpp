/**
 *
 * @file SYSCTL_DeInitClockGates_Test.cpp
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
 * @verbatim 4 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 4 abr. 2026    GitHub Copilot   1.0         initial Version@endverbatim
 */

#include <array>

extern "C"
{
#include <xDriver_MCU/SYSCTL/App/xHeader/SYSCTL_DeInitClockGates.h>
}

#include <tm4c129e_test/SYSCTL_DeInitClockGatesMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::InSequence;
using ::testing::Return;
using ::testing::StrictMock;

namespace
{
constexpr std::array<SYSCTL_nPERIPHERAL, 70U> gau32Peripherals =
{{
    SYSCTL_enWDT0,
    SYSCTL_enWDT1,
    SYSCTL_enTIMER0,
    SYSCTL_enTIMER1,
    SYSCTL_enTIMER2,
    SYSCTL_enTIMER3,
    SYSCTL_enTIMER4,
    SYSCTL_enTIMER5,
    SYSCTL_enTIMER6,
    SYSCTL_enTIMER7,
    SYSCTL_enGPIOA,
    SYSCTL_enGPIOB,
    SYSCTL_enGPIOC,
    SYSCTL_enGPIOD,
    SYSCTL_enGPIOE,
    SYSCTL_enGPIOF,
    SYSCTL_enGPIOG,
    SYSCTL_enGPIOH,
    SYSCTL_enGPIOJ,
    SYSCTL_enGPIOK,
    SYSCTL_enGPIOL,
    SYSCTL_enGPIOM,
    SYSCTL_enGPION,
    SYSCTL_enGPIOP,
    SYSCTL_enGPIOQ,
    SYSCTL_enDMA,
    SYSCTL_enEPI,
    SYSCTL_enHIB,
    SYSCTL_enUART0,
    SYSCTL_enUART1,
    SYSCTL_enUART2,
    SYSCTL_enUART3,
    SYSCTL_enUART4,
    SYSCTL_enUART5,
    SYSCTL_enUART6,
    SYSCTL_enUART7,
    SYSCTL_enSSI0,
    SYSCTL_enSSI1,
    SYSCTL_enSSI2,
    SYSCTL_enSSI3,
    SYSCTL_enI2C0,
    SYSCTL_enI2C1,
    SYSCTL_enI2C2,
    SYSCTL_enI2C3,
    SYSCTL_enI2C4,
    SYSCTL_enI2C5,
    SYSCTL_enI2C6,
    SYSCTL_enI2C7,
    SYSCTL_enI2C8,
    SYSCTL_enI2C9,
    SYSCTL_enUSB,
    SYSCTL_enEPHY,
    SYSCTL_enCAN0,
    SYSCTL_enCAN1,
    SYSCTL_enADC0,
    SYSCTL_enADC1,
    SYSCTL_enACMP,
    SYSCTL_enPWM0,
    SYSCTL_enQEI0,
    SYSCTL_enLPC,
    SYSCTL_enPECI,
    SYSCTL_enFAN,
    SYSCTL_enEEPROM,
    SYSCTL_enRTS,
    SYSCTL_enCCM,
    SYSCTL_enLCD,
    SYSCTL_enOWIRE,
    SYSCTL_enEMAC,
    SYSCTL_enPRB,
    SYSCTL_enHIM,
}};
}

/**
 * @brief Validate full SYSCTL clock-gate deinitialization ordering.
 * @summary Confirms that `SYSCTL__enDeInitClockGates` iterates the current
 *          peripheral inventory in source order and delegates each entry to
 *          `SYSCTL__enClearReadyOnRunMode` for the selected module.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_DeInitClockGatesMock bridge
 * - Original source under test: SYSCTL_DeInitClockGates.c@endverbatim
 */
TEST(SYSCTL_DeInitClockGatesTest, DeInitClockGatesIteratesAllPeripheralsInOrder)
{
    StrictMock<SYSCTL_DeInitClockGatesMock> stMock;
    SYSCTL_DeInitClockGatesMockScope stMockScope(&stMock);
    InSequence stSequence;

    for(const SYSCTL_nPERIPHERAL enPeripheralReg : gau32Peripherals)
    {
        EXPECT_CALL(stMock, ClearReadyOnRunMode(SYSCTL_enMODULE_0, enPeripheralReg))
            .WillOnce(Return(SYSCTL_enERROR_OK));
    }

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enDeInitClockGates(SYSCTL_enMODULE_0));
}

/**
 * @brief Validate early exit on the first deinitialization failure.
 * @summary Confirms that `SYSCTL__enDeInitClockGates` stops at the first
 *          failing `SYSCTL__enClearReadyOnRunMode` result and returns that
 *          error without attempting later peripherals.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_DeInitClockGatesMock bridge
 * - Original source under test: SYSCTL_DeInitClockGates.c@endverbatim
 */
TEST(SYSCTL_DeInitClockGatesTest, DeInitClockGatesStopsOnFirstError)
{
    StrictMock<SYSCTL_DeInitClockGatesMock> stMock;
    SYSCTL_DeInitClockGatesMockScope stMockScope(&stMock);
    InSequence stSequence;

    EXPECT_CALL(stMock, ClearReadyOnRunMode(SYSCTL_enMODULE_0, SYSCTL_enWDT0))
        .WillOnce(Return(SYSCTL_enERROR_OK));
    EXPECT_CALL(stMock, ClearReadyOnRunMode(SYSCTL_enMODULE_0, SYSCTL_enWDT1))
        .WillOnce(Return(SYSCTL_enERROR_OK));
    EXPECT_CALL(stMock, ClearReadyOnRunMode(SYSCTL_enMODULE_0, SYSCTL_enTIMER0))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enDeInitClockGates(SYSCTL_enMODULE_0));
}