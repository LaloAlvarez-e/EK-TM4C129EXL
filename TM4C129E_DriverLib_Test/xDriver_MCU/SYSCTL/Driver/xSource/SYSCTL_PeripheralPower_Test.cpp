/**
 *
 * @file SYSCTL_PeripheralPower_Test.cpp
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
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_PeripheralPower.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/xHeader/SYSCTL_RegisterAddress.h>
}

#include <tm4c129e_test/SYSCTL_PeripheralGenericMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Invoke;
using ::testing::Return;
using ::testing::StrictMock;

/**
 * @brief Validate peripheral-generic write composition in the power-control setter.
 * @summary Confirms that `SYSCTL__enSetPowerControlState` writes to
 *          `SYSCTL_PC_OFFSET`, forwards the caller peripheral selector unchanged,
 *          and passes the requested state value into the peripheral-generic seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PeripheralGenericMock bridge
 * - Original source under test: SYSCTL_PeripheralPower.c@endverbatim
 */
TEST(SYSCTL_PeripheralPowerTest, SetPowerControlStateUsesExpectedPeripheralWrite)
{
    StrictMock<SYSCTL_PeripheralGenericMock> stMock;
    SYSCTL_PeripheralGenericMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WritePeripheral(SYSCTL_enMODULE_0, SYSCTL_enUSB, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg,
                            SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_EQ(SYSCTL_enUSB, enPeripheralArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SYSCTL_PC_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) SYSCTL_enSTATE_ENA, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetPowerControlState(SYSCTL_enMODULE_0, SYSCTL_enUSB, SYSCTL_enSTATE_ENA));
}

/**
 * @brief Validate enable-wrapper delegation in the power-on helper.
 * @summary Confirms that `SYSCTL__enPowerOn` writes through the peripheral-generic
 *          seam using `SYSCTL_PC_OFFSET` and the enabled state value.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PeripheralGenericMock bridge
 * - Original source under test: SYSCTL_PeripheralPower.c@endverbatim
 */
TEST(SYSCTL_PeripheralPowerTest, PowerOnUsesEnabledState)
{
    StrictMock<SYSCTL_PeripheralGenericMock> stMock;
    SYSCTL_PeripheralGenericMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WritePeripheral(SYSCTL_enMODULE_0, SYSCTL_enEMAC, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg,
                            SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_EQ(SYSCTL_enEMAC, enPeripheralArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SYSCTL_PC_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) SYSCTL_enSTATE_ENA, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enPowerOn(SYSCTL_enMODULE_0, SYSCTL_enEMAC));
}

/**
 * @brief Validate disable-wrapper delegation in the power-off helper.
 * @summary Confirms that `SYSCTL__enPowerOff` writes through the peripheral-generic
 *          seam using `SYSCTL_PC_OFFSET` and the disabled state value.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PeripheralGenericMock bridge
 * - Original source under test: SYSCTL_PeripheralPower.c@endverbatim
 */
TEST(SYSCTL_PeripheralPowerTest, PowerOffUsesDisabledState)
{
    StrictMock<SYSCTL_PeripheralGenericMock> stMock;
    SYSCTL_PeripheralGenericMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WritePeripheral(SYSCTL_enMODULE_0, SYSCTL_enCAN1, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg,
                            SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_EQ(SYSCTL_enCAN1, enPeripheralArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SYSCTL_PC_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) SYSCTL_enSTATE_DIS, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enPowerOff(SYSCTL_enMODULE_0, SYSCTL_enCAN1));
}

/**
 * @brief Validate null-pointer rejection in the power-control getter.
 * @summary Confirms that `SYSCTL__enGetPowerControlState` rejects a null output
 *          pointer before attempting the peripheral-generic read seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_PeripheralPower.c
 * - Public API parameter validation path@endverbatim
 */
TEST(SYSCTL_PeripheralPowerTest, GetPowerControlStateRejectsNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetPowerControlState(SYSCTL_enMODULE_0, SYSCTL_enUSB, (SYSCTL_nSTATE*) 0UL));
}

/**
 * @brief Validate peripheral-generic read composition in the power-control getter.
 * @summary Confirms that `SYSCTL__enGetPowerControlState` reads from
 *          `SYSCTL_PC_OFFSET`, forwards the caller peripheral selector unchanged,
 *          and returns the state value from the peripheral-generic seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PeripheralGenericMock bridge
 * - Original source under test: SYSCTL_PeripheralPower.c@endverbatim
 */
TEST(SYSCTL_PeripheralPowerTest, GetPowerControlStateUsesExpectedPeripheralRead)
{
    StrictMock<SYSCTL_PeripheralGenericMock> stMock;
    SYSCTL_PeripheralGenericMockScope stMockScope(&stMock);
    SYSCTL_nSTATE enStateReg;

    enStateReg = SYSCTL_enSTATE_UNDEF;

    EXPECT_CALL(stMock, ReadPeripheral(SYSCTL_enMODULE_0, SYSCTL_enUSB, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg,
                            SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_EQ(SYSCTL_enUSB, enPeripheralArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SYSCTL_PC_OFFSET, pstRegisterDataArg->uptrAddress);
            pstRegisterDataArg->uxValue = (UBase_t) SYSCTL_enSTATE_ENA;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK, SYSCTL__enGetPowerControlState(SYSCTL_enMODULE_0, SYSCTL_enUSB, &enStateReg));
    EXPECT_EQ(SYSCTL_enSTATE_ENA, enStateReg);
}

/**
 * @brief Validate read-error propagation in the power-control getter.
 * @summary Confirms that `SYSCTL__enGetPowerControlState` returns the
 *          peripheral-generic read error unchanged and preserves the caller
 *          output value when the seam reports failure.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PeripheralGenericMock bridge
 * - Original source under test: SYSCTL_PeripheralPower.c@endverbatim
 */
TEST(SYSCTL_PeripheralPowerTest, GetPowerControlStatePropagatesReadError)
{
    StrictMock<SYSCTL_PeripheralGenericMock> stMock;
    SYSCTL_PeripheralGenericMockScope stMockScope(&stMock);
    SYSCTL_nSTATE enStateReg;

    enStateReg = SYSCTL_enSTATE_DIS;

    EXPECT_CALL(stMock, ReadPeripheral(SYSCTL_enMODULE_0, SYSCTL_enEMAC, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE, SYSCTL__enGetPowerControlState(SYSCTL_enMODULE_0, SYSCTL_enEMAC, &enStateReg));
    EXPECT_EQ(SYSCTL_enSTATE_DIS, enStateReg);
}