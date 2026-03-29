/**
 *
 * @file SYSEXC_InterruptSource_Test.cpp
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
 * @verbatim 28 mar. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 28 mar. 2026   GitHub Copilot   1.0         initial Version@endverbatim
 */

extern "C"
{
#include <xDriver_MCU/SYSEXC/Driver/Intrinsics/Interrupt/xHeader/SYSEXC_InterruptSource.h>
#include <xDriver_MCU/SYSEXC/Peripheral/Register/xHeader/SYSEXC_RegisterAddress.h>
#include <xDriver_MCU/SYSEXC/Peripheral/Register/xHeader/SYSEXC_RegisterDefines.h>
}

#include <tm4c129e_test/SYSEXC_PrimitivesMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::_;
using ::testing::Invoke;
using ::testing::Return;
using ::testing::StrictMock;

/**
 * @brief Validate enable-by-number register programming for the DIV0 source.
 * @summary Confirms that the public helper maps `SYSEXC_enINT_DIV0` to the expected
 *          interrupt-mask register offset, shift, mask, and enabled value.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSEXC_PrimitivesMock bridge
 * - Original source under test: SYSEXC_InterruptSource.c
 * - GoogleTest / GoogleMock expectation support@endverbatim
 */
TEST(SYSEXC_InterruptSourceTest, EnableInterruptSourceByNumberUsesExpectedRegisterShift)
{
    StrictMock<SYSEXC_PrimitivesMock> stMock;
    SYSEXC_PrimitivesMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, CheckParams(_, _))
        .Times(3)
        .WillRepeatedly(Return(MCU_enERROR_OK));

    EXPECT_CALL(stMock, WriteRegister(SYSEXC_enMODULE_0, _))
        .WillOnce(Invoke([](SYSEXC_nMODULE enModuleArg, SYSEXC_Register_t* pstRegisterDataArg) -> SYSEXC_nERROR
        {
            EXPECT_EQ(SYSEXC_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSEXC_enERROR_POINTER;
            }
            EXPECT_EQ(SYSEXC_IM_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ(SYSEXC_IM_FPIDC_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ(SYSEXC_IM_R_FPDZC_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) SYSEXC_enSTATE_ENA, pstRegisterDataArg->uxValue);
            return SYSEXC_enERROR_OK;
        }));

    EXPECT_EQ(SYSEXC_enERROR_OK, SYSEXC__enEnableInterruptSourceByNumber(SYSEXC_enMODULE_0, SYSEXC_enINT_DIV0));
}

/**
 * @brief Validate null-pointer rejection in the mask getter API.
 * @summary Confirms that the getter returns `SYSEXC_enERROR_POINTER` immediately
 *          when the output storage pointer is null.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSEXC_InterruptSource.c
 * - Public API parameter validation path@endverbatim
 */
TEST(SYSEXC_InterruptSourceTest, GetInterruptSourceStateByMaskRejectsNullPointer)
{
    EXPECT_EQ(SYSEXC_enERROR_POINTER,
              SYSEXC__enGetInterruptSourceStateByMask(SYSEXC_enMODULE_0,
                                                      SYSEXC_enINTMASK_DIV0,
                                                      (SYSEXC_nINTMASK*) 0UL));
}

/**
 * @brief Validate masked-status reads for a numbered interrupt source.
 * @summary Confirms that the public masked-status helper reads the MIS register,
 *          uses the expected bit shift for overflow, and translates an active bit
 *          into `SYSEXC_enSTATUS_ACTIVE`.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSEXC_PrimitivesMock bridge
 * - Original source under test: SYSEXC_InterruptSource.c
 * - MIS register definitions@endverbatim
 */
TEST(SYSEXC_InterruptSourceTest, StatusMaskedInterruptSourceByNumberReadsMaskedStatusRegister)
{
    StrictMock<SYSEXC_PrimitivesMock> stMock;
    SYSEXC_PrimitivesMockScope stMockScope(&stMock);
    SYSEXC_nSTATUS enStatusReg;

    enStatusReg = SYSEXC_enSTATUS_UNDEF;

    EXPECT_CALL(stMock, CheckParams(_, _))
        .Times(3)
        .WillRepeatedly(Return(MCU_enERROR_OK));

    EXPECT_CALL(stMock, ReadRegister(SYSEXC_enMODULE_0, _))
        .WillOnce(Invoke([](SYSEXC_nMODULE enModuleArg, SYSEXC_Register_t* pstRegisterDataArg) -> SYSEXC_nERROR
        {
            EXPECT_EQ(SYSEXC_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSEXC_enERROR_POINTER;
            }
            EXPECT_EQ(SYSEXC_MIS_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ(SYSEXC_MIS_FPIDC_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ(SYSEXC_RIS_R_FPOFC_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) SYSEXC_MIS_FPIDC_ACTIVE;
            return SYSEXC_enERROR_OK;
        }));

    EXPECT_EQ(SYSEXC_enERROR_OK,
              SYSEXC__enStatusMaskedInterruptSourceByNumber(SYSEXC_enMODULE_0,
                                                            SYSEXC_enINT_OVERFLOW,
                                                            &enStatusReg));
    EXPECT_EQ(SYSEXC_enSTATUS_ACTIVE, enStatusReg);
}

/**
 * @brief Validate clear-by-mask writes into the interrupt-clear register path.
 * @summary Confirms that the clear-by-mask API writes the full interrupt mask,
 *          zero shift, and base-wide mask into the `SYSEXC_IC_OFFSET` register path.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSEXC_PrimitivesMock bridge
 * - Original source under test: SYSEXC_InterruptSource.c
 * - IC register definitions@endverbatim
 */
TEST(SYSEXC_InterruptSourceTest, ClearInterruptSourceByMaskWritesWholeInterruptMask)
{
    StrictMock<SYSEXC_PrimitivesMock> stMock;
    SYSEXC_PrimitivesMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, CheckParams((UBase_t) SYSEXC_enINTMASK_OVERFLOW, (UBase_t) SYSEXC_enINTMASK_MAX))
        .WillOnce(Return(MCU_enERROR_OK));

    EXPECT_CALL(stMock, WriteRegister(SYSEXC_enMODULE_0, _))
        .WillOnce(Invoke([](SYSEXC_nMODULE enModuleArg, SYSEXC_Register_t* pstRegisterDataArg) -> SYSEXC_nERROR
        {
            EXPECT_EQ(SYSEXC_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSEXC_enERROR_POINTER;
            }
            EXPECT_EQ(SYSEXC_IC_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ(MCU_MASK_BASE, pstRegisterDataArg->uxMask);
            EXPECT_EQ(0U, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) SYSEXC_enINTMASK_OVERFLOW, pstRegisterDataArg->uxValue);
            return SYSEXC_enERROR_OK;
        }));

    EXPECT_EQ(SYSEXC_enERROR_OK,
              SYSEXC__enClearInterruptSourceByMask(SYSEXC_enMODULE_0, SYSEXC_enINTMASK_OVERFLOW));
}