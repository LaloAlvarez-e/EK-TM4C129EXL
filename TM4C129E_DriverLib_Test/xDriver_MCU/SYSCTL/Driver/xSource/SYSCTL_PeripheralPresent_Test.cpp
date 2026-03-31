/**
 *
 * @file SYSCTL_PeripheralPresent_Test.cpp
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
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_PeripheralPresent.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/xHeader/SYSCTL_RegisterAddress.h>
}

#include <tm4c129e_test/SYSCTL_PeripheralGenericMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Invoke;
using ::testing::Return;
using ::testing::StrictMock;

/**
 * @brief Validate null-pointer rejection in the peripheral-present query.
 * @summary Confirms that `SYSCTL__enIsPeripheralPresent` rejects a null output
 *          pointer before attempting the peripheral-generic read seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_PeripheralPresent.c
 * - Public API parameter validation path@endverbatim
 */
TEST(SYSCTL_PeripheralPresentTest, IsPeripheralPresentRejectsNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enIsPeripheralPresent(SYSCTL_enMODULE_0, SYSCTL_enGPIOA, (SYSCTL_nBOOLEAN*) 0UL));
}

/**
 * @brief Validate peripheral-generic read composition in the presence query.
 * @summary Confirms that `SYSCTL__enIsPeripheralPresent` reads from
 *          `SYSCTL_PP_OFFSET`, forwards the caller peripheral selector unchanged
 *          into `SYSCTL__enReadPeripheral`, and returns the boolean value from
 *          the seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PeripheralGenericMock bridge
 * - Original source under test: SYSCTL_PeripheralPresent.c@endverbatim
 */
TEST(SYSCTL_PeripheralPresentTest, IsPeripheralPresentUsesExpectedPeripheralRead)
{
    StrictMock<SYSCTL_PeripheralGenericMock> stMock;
    SYSCTL_PeripheralGenericMockScope stMockScope(&stMock);
    SYSCTL_nBOOLEAN enStateReg;

    enStateReg = SYSCTL_enFALSE;

    EXPECT_CALL(stMock, ReadPeripheral(SYSCTL_enMODULE_0, SYSCTL_enGPIOQ, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg,
                            SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_EQ(SYSCTL_enGPIOQ, enPeripheralArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SYSCTL_PP_OFFSET, pstRegisterDataArg->uptrAddress);
            pstRegisterDataArg->uxValue = (UBase_t) SYSCTL_enTRUE;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enIsPeripheralPresent(SYSCTL_enMODULE_0, SYSCTL_enGPIOQ, &enStateReg));
    EXPECT_EQ(SYSCTL_enTRUE, enStateReg);
}

/**
 * @brief Validate read-error propagation in the peripheral-present query.
 * @summary Confirms that `SYSCTL__enIsPeripheralPresent` returns the
 *          peripheral-generic read error unchanged and preserves the caller
 *          output value when the seam reports failure.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PeripheralGenericMock bridge
 * - Original source under test: SYSCTL_PeripheralPresent.c@endverbatim
 */
TEST(SYSCTL_PeripheralPresentTest, IsPeripheralPresentPropagatesReadError)
{
    StrictMock<SYSCTL_PeripheralGenericMock> stMock;
    SYSCTL_PeripheralGenericMockScope stMockScope(&stMock);
    SYSCTL_nBOOLEAN enStateReg;

    enStateReg = SYSCTL_enFALSE;

    EXPECT_CALL(stMock, ReadPeripheral(SYSCTL_enMODULE_0, SYSCTL_enGPIOA, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enIsPeripheralPresent(SYSCTL_enMODULE_0, SYSCTL_enGPIOA, &enStateReg));
    EXPECT_EQ(SYSCTL_enFALSE, enStateReg);
}