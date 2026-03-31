/**
 *
 * @file SYSCTL_AlternateClock_Test.cpp
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
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_AlternateClock.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_ALTCLKCFG.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/xHeader/SYSCTL_RegisterAddress.h>
}

#include <tm4c129e_test/SYSCTL_PrimitivesMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Invoke;
using ::testing::Return;
using ::testing::StrictMock;

/**
 * @brief Validate ALTCLKCFG write-field composition in the alternate-clock setter.
 * @summary Confirms that `SYSCTL__enSetAlternateClockSource` forwards the module,
 *          register offset, field mask, and field shift that correspond to the
 *          ALTCLKCFG ALTCLK field, and writes the caller-provided alternate clock
 *          source unchanged through the primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_AlternateClock.c
 * - SYSCTL ALTCLKCFG register definitions@endverbatim
 */
TEST(SYSCTL_AlternateClockTest, SetAlternateClockSourceUsesExpectedALTCLKCFGField)
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
            EXPECT_EQ((uintptr_t) ALTCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) ALTCLK_CFG_ALTCLK_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) ALTCLK_CFG_R_ALTCLK_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) SYSCTL_enALTCLK_SRC_LFIOSC, pstRegisterDataArg->uxValue);
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enSetAlternateClockSource(SYSCTL_enMODULE_0, SYSCTL_enALTCLK_SRC_LFIOSC));
}

/**
 * @brief Validate null-pointer rejection in the alternate-clock getter.
 * @summary Confirms that `SYSCTL__enGetAlternateClockSource` rejects a null
 *          destination pointer before attempting primitive register access.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_AlternateClock.c
 * - Public API parameter validation path@endverbatim
 */
TEST(SYSCTL_AlternateClockTest, GetAlternateClockSourceRejectsNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetAlternateClockSource(SYSCTL_enMODULE_0, (SYSCTL_nALTCLK_SRC*) 0UL));
}

/**
 * @brief Validate ALTCLKCFG read-field composition in the alternate-clock getter.
 * @summary Confirms that `SYSCTL__enGetAlternateClockSource` reads the ALTCLKCFG
 *          ALTCLK field with the expected offset, mask, and shift, then returns
 *          the primitive value as the public alternate clock source enum.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_AlternateClock.c
 * - SYSCTL ALTCLKCFG register definitions@endverbatim
 */
TEST(SYSCTL_AlternateClockTest, GetAlternateClockSourceUsesExpectedALTCLKCFGField)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nALTCLK_SRC enSourceReg;

    enSourceReg = SYSCTL_enALTCLK_SRC_UNDEF;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) ALTCLK_CFG_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) ALTCLK_CFG_ALTCLK_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) ALTCLK_CFG_R_ALTCLK_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) SYSCTL_enALTCLK_SRC_RTCOSC;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enGetAlternateClockSource(SYSCTL_enMODULE_0, &enSourceReg));
    EXPECT_EQ(SYSCTL_enALTCLK_SRC_RTCOSC, enSourceReg);
}

/**
 * @brief Validate read-error propagation in the alternate-clock getter.
 * @summary Confirms that `SYSCTL__enGetAlternateClockSource` returns the
 *          primitive read error unchanged and does not overwrite the caller's
 *          output variable when the ALTCLKCFG read path fails.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_AlternateClock.c@endverbatim
 */
TEST(SYSCTL_AlternateClockTest, GetAlternateClockSourcePropagatesReadError)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nALTCLK_SRC enSourceReg;

    enSourceReg = SYSCTL_enALTCLK_SRC_PIOSC;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE,
              SYSCTL__enGetAlternateClockSource(SYSCTL_enMODULE_0, &enSourceReg));
    EXPECT_EQ(SYSCTL_enALTCLK_SRC_PIOSC, enSourceReg);
}