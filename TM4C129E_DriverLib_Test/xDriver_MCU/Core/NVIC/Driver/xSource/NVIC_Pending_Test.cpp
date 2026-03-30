/**
 *
 * @file NVIC_Pending_Test.cpp
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
#include <xDriver_MCU/Core/NVIC/Driver/xHeader/NVIC_Pending.h>
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
 * @brief Validate that pending-state reads use the ISPR register family.
 * @summary Confirms that `NVIC__enIsVectorPending` delegates to
 *          `NVIC__enReadValue` with `NVIC_ISPR_OFFSET` and forwards the returned
 *          pending state to the caller.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - NVIC_EnableDriverMock bridge
 * - Original source under test: NVIC_Pending.c@endverbatim
 */
TEST(NVIC_PendingTest, IsVectorPendingUsesISPRReadPath)
{
    StrictMock<NVIC_EnableDriverMock> stMock;
    NVIC_EnableDriverMockScope stMockScope(&stMock);
    NVIC_nBOOLEAN enStateReg;

    enStateReg = NVIC_enBOOLEAN_UNDEF;

    EXPECT_CALL(stMock, ReadValue(NVIC_enMODULE_0, NVIC_enVECTOR_GPIOB, (uintptr_t) NVIC_ISPR_OFFSET, testing::_))
        .WillOnce(DoAll(SetArgPointee<3>((UBase_t) NVIC_enTRUE), Return(NVIC_enERROR_OK)));

    EXPECT_EQ(NVIC_enERROR_OK,
              NVIC__enIsVectorPending(NVIC_enMODULE_0, NVIC_enVECTOR_GPIOB, &enStateReg));
    EXPECT_EQ(NVIC_enTRUE, enStateReg);
}

/**
 * @brief Validate that true pending state writes through the ISPR path.
 * @summary Confirms that `NVIC__enSetPendingVectorState` uses `NVIC_ISPR_OFFSET`
 *          when the requested pending-state value is true.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - NVIC_EnableDriverMock bridge
 * - Original source under test: NVIC_Pending.c@endverbatim
 */
TEST(NVIC_PendingTest, SetPendingVectorStateUsesISPRForTrue)
{
    StrictMock<NVIC_EnableDriverMock> stMock;
    NVIC_EnableDriverMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock,
                SetWriteValue(NVIC_enMODULE_0,
                              NVIC_enVECTOR_UART2,
                              (uintptr_t) NVIC_ISPR_OFFSET,
                              (UBase_t) NVIC_enSTATE_ENA))
        .WillOnce(Return(NVIC_enERROR_OK));

    EXPECT_EQ(NVIC_enERROR_OK,
              NVIC__enSetPendingVectorState(NVIC_enMODULE_0, NVIC_enVECTOR_UART2, NVIC_enTRUE));
}

/**
 * @brief Validate that false pending state writes through the ICPR path.
 * @summary Confirms that `NVIC__enSetPendingVectorState` uses `NVIC_ICPR_OFFSET`
 *          when the requested pending-state value is false.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - NVIC_EnableDriverMock bridge
 * - Original source under test: NVIC_Pending.c@endverbatim
 */
TEST(NVIC_PendingTest, SetPendingVectorStateUsesICPRForFalse)
{
    StrictMock<NVIC_EnableDriverMock> stMock;
    NVIC_EnableDriverMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock,
                SetWriteValue(NVIC_enMODULE_0,
                              NVIC_enVECTOR_UART3,
                              (uintptr_t) NVIC_ICPR_OFFSET,
                              (UBase_t) NVIC_enSTATE_ENA))
        .WillOnce(Return(NVIC_enERROR_OK));

    EXPECT_EQ(NVIC_enERROR_OK,
              NVIC__enSetPendingVectorState(NVIC_enMODULE_0, NVIC_enVECTOR_UART3, NVIC_enFALSE));
}

/**
 * @brief Validate that the set-pending wrapper delegates through the true path.
 * @summary Confirms that `NVIC__enSetPendingVector` reaches the same ISPR write
 *          path as `NVIC__enSetPendingVectorState(..., NVIC_enTRUE)`.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - NVIC_EnableDriverMock bridge
 * - Original source under test: NVIC_Pending.c@endverbatim
 */
TEST(NVIC_PendingTest, SetPendingVectorUsesSetPath)
{
    StrictMock<NVIC_EnableDriverMock> stMock;
    NVIC_EnableDriverMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock,
                SetWriteValue(NVIC_enMODULE_0,
                              NVIC_enVECTOR_GPIOE,
                              (uintptr_t) NVIC_ISPR_OFFSET,
                              (UBase_t) NVIC_enSTATE_ENA))
        .WillOnce(Return(NVIC_enERROR_OK));

    EXPECT_EQ(NVIC_enERROR_OK,
              NVIC__enSetPendingVector(NVIC_enMODULE_0, NVIC_enVECTOR_GPIOE));
}

/**
 * @brief Validate that the clear-pending wrapper delegates through the clear path.
 * @summary Confirms that `NVIC__enClearPendingVector` reaches the same ICPR write
 *          path as `NVIC__enSetPendingVectorState(..., NVIC_enFALSE)`.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - NVIC_EnableDriverMock bridge
 * - Original source under test: NVIC_Pending.c@endverbatim
 */
TEST(NVIC_PendingTest, ClearPendingVectorUsesClearPath)
{
    StrictMock<NVIC_EnableDriverMock> stMock;
    NVIC_EnableDriverMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock,
                SetWriteValue(NVIC_enMODULE_0,
                              NVIC_enVECTOR_GPIOF,
                              (uintptr_t) NVIC_ICPR_OFFSET,
                              (UBase_t) NVIC_enSTATE_ENA))
        .WillOnce(Return(NVIC_enERROR_OK));

    EXPECT_EQ(NVIC_enERROR_OK,
              NVIC__enClearPendingVector(NVIC_enMODULE_0, NVIC_enVECTOR_GPIOF));
}