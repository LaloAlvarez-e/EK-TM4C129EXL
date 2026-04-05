/**
 *
 * @file SYSCTL_InterruptVector_Test.cpp
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

extern "C"
{
#include <xApplication_MCU/SYSCTL/Interrupt/xHeader/SYSCTL_InterruptVector.h>
}

#include <tm4c129e_test/SYSCTL_InterruptVectorDriverMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Return;
using ::testing::StrictMock;

/**
 * @brief Validate SYSCTL vector enable delegation.
 * @summary Confirms that `SYSCTL__enEnableInterruptVector` masks the public priority
 *          to three bits and enables the fixed SYSCTL NVIC vector through the
 *          NVIC wrapper seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_InterruptVectorDriverMock bridge
 * - Original source under test: SYSCTL_InterruptVector.c@endverbatim
 */
TEST(SYSCTL_InterruptVectorTest, EnInterruptVectorMasksPriorityAndUsesSYSCTLVector)
{
    StrictMock<SYSCTL_InterruptVectorDriverMock> stMock;
    SYSCTL_InterruptVectorDriverMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, EnableVector(NVIC_enMODULE_0, NVIC_enVECTOR_SYSCTL, (NVIC_nPRIORITY) 0x7UL))
        .WillOnce(Return(NVIC_enERROR_OK));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enEnableInterruptVector((SYSCTL_nPRIORITY) 0xFUL));
}

/**
 * @brief Validate SYSCTL vector enable error propagation.
 * @summary Confirms that `SYSCTL__enEnableInterruptVector` propagates the
 *          underlying NVIC enable-vector status.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_InterruptVectorDriverMock bridge
 * - Original source under test: SYSCTL_InterruptVector.c@endverbatim
 */
TEST(SYSCTL_InterruptVectorTest, EnableInterruptVectorPropagatesNVICError)
{
    StrictMock<SYSCTL_InterruptVectorDriverMock> stMock;
    SYSCTL_InterruptVectorDriverMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, EnableVector(NVIC_enMODULE_0, NVIC_enVECTOR_SYSCTL, (NVIC_nPRIORITY) 0x3UL))
        .WillOnce(Return(NVIC_enERROR_RANGE));

    EXPECT_EQ(SYSCTL_enERROR_RANGE,
              SYSCTL__enEnableInterruptVector((SYSCTL_nPRIORITY) 0x3UL));
}

/**
 * @brief Validate SYSCTL vector disable delegation.
 * @summary Confirms that `SYSCTL__enDisableInterruptVector` disables the fixed SYSCTL
 *          NVIC vector through the NVIC wrapper seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_InterruptVectorDriverMock bridge
 * - Original source under test: SYSCTL_InterruptVector.c@endverbatim
 */
TEST(SYSCTL_InterruptVectorTest, DisInterruptVectorUsesSYSCTLVector)
{
    StrictMock<SYSCTL_InterruptVectorDriverMock> stMock;
    SYSCTL_InterruptVectorDriverMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, DisableVector(NVIC_enMODULE_0, NVIC_enVECTOR_SYSCTL))
        .WillOnce(Return(NVIC_enERROR_OK));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enDisableInterruptVector());
}

/**
 * @brief Validate SYSCTL vector disable error propagation.
 * @summary Confirms that `SYSCTL__enDisableInterruptVector` propagates the
 *          underlying NVIC disable-vector status.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_InterruptVectorDriverMock bridge
 * - Original source under test: SYSCTL_InterruptVector.c@endverbatim
 */
TEST(SYSCTL_InterruptVectorTest, DisableInterruptVectorPropagatesNVICError)
{
    StrictMock<SYSCTL_InterruptVectorDriverMock> stMock;
    SYSCTL_InterruptVectorDriverMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, DisableVector(NVIC_enMODULE_0, NVIC_enVECTOR_SYSCTL))
        .WillOnce(Return(NVIC_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE,
              SYSCTL__enDisableInterruptVector());
}