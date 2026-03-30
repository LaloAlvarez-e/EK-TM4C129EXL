/**
 *
 * @file NVIC_Active_Test.cpp
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
 * @verbatim 29 mar. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 29 mar. 2026   GitHub Copilot   1.0         initial Version@endverbatim
 */

extern "C"
{
#include <xDriver_MCU/Core/NVIC/Driver/xHeader/NVIC_Active.h>
#include <xDriver_MCU/Core/NVIC/Peripheral/Register/xHeader/NVIC_RegisterAddress.h>
}

#include <tm4c129e_test/NVIC_EnableDriverMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::DoAll;
using ::testing::Return;
using ::testing::SetArgPointee;
using ::testing::StrictMock;

/**
 * @brief Validate that active-state reads use the IABR register family.
 * @summary Confirms that `NVIC__enGetActiveVector` delegates to
 *          `NVIC__enReadValue` with `NVIC_IABR_OFFSET` and forwards the returned
 *          active-state value to the caller.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - NVIC_EnableDriverMock bridge
 * - Original source under test: NVIC_Active.c@endverbatim
 */
TEST(NVIC_ActiveTest, GetActiveVectorUsesIABRReadPath)
{
    StrictMock<NVIC_EnableDriverMock> stMock;
    NVIC_EnableDriverMockScope stMockScope(&stMock);
    NVIC_nSTATUS enStatusReg;

    enStatusReg = NVIC_enSTATUS_UNDEF;

    EXPECT_CALL(stMock, ReadValue(NVIC_enMODULE_0, NVIC_enVECTOR_TIMER0A, (uintptr_t) NVIC_IABR_OFFSET, testing::_))
        .WillOnce(DoAll(SetArgPointee<3>((UBase_t) NVIC_enSTATUS_ACTIVE), Return(NVIC_enERROR_OK)));

    EXPECT_EQ(NVIC_enERROR_OK,
              NVIC__enGetActiveVector(NVIC_enMODULE_0, NVIC_enVECTOR_TIMER0A, &enStatusReg));
    EXPECT_EQ(NVIC_enSTATUS_ACTIVE, enStatusReg);
}

/**
 * @brief Validate read-error propagation in the active-state wrapper.
 * @summary Confirms that `NVIC__enGetActiveVector` propagates the error returned
 *          by `NVIC__enReadValue` without altering it.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - NVIC_EnableDriverMock bridge
 * - Original source under test: NVIC_Active.c@endverbatim
 */
TEST(NVIC_ActiveTest, GetActiveVectorPropagatesReadError)
{
    StrictMock<NVIC_EnableDriverMock> stMock;
    NVIC_EnableDriverMockScope stMockScope(&stMock);
    NVIC_nSTATUS enStatusReg;

    enStatusReg = NVIC_enSTATUS_UNDEF;

    EXPECT_CALL(stMock, ReadValue(NVIC_enMODULE_0, NVIC_enVECTOR_TIMER0B, (uintptr_t) NVIC_IABR_OFFSET, testing::_))
        .WillOnce(Return(NVIC_enERROR_VALUE));

    EXPECT_EQ(NVIC_enERROR_VALUE,
              NVIC__enGetActiveVector(NVIC_enMODULE_0, NVIC_enVECTOR_TIMER0B, &enStatusReg));
}