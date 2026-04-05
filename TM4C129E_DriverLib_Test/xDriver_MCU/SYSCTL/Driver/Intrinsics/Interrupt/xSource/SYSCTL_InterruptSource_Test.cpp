/**
 *
 * @file SYSCTL_InterruptSource_Test.cpp
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
 * @verbatim 03 apr. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 03 apr. 2026   GitHub Copilot   1.0         initial Version@endverbatim
 */

extern "C"
{
#include <xDriver_MCU/Common/xHeader/MCU_Variables.h>
#include <xDriver_MCU/SYSCTL/Driver/Intrinsics/Interrupt/xHeader/SYSCTL_InterruptSource.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_IMC.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_MISC.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_RIS.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/xHeader/SYSCTL_RegisterAddress.h>
}

#include <tm4c129e_test/SYSCTL_MCURegisterAccessMock.h>
#include <tm4c129e_test/SYSCTL_PrimitivesMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::_;
using ::testing::InSequence;
using ::testing::Invoke;
using ::testing::Return;
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

void ExpectCheckParamsOk(SYSCTL_MCURegisterAccessMock& stMockArg, int s32TimesArg)
{
    EXPECT_CALL(stMockArg, CheckParams(_, _))
        .Times(s32TimesArg)
        .WillRepeatedly(Return(MCU_enERROR_OK));
}

}

/**
 * @brief Validate corrected single-bit IMC routing in the by-number enable and disable helpers.
 * @summary Confirms that the public by-number enable and disable wrappers map the
 *          selected source to the documented `IMC` bit shift and use a single-bit
 *          logical mask so the primitive seam preserves the requested interrupt state.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - SYSCTL_MCURegisterAccessMock bridge
 * - Original source under test: SYSCTL_InterruptSource.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-INTSRC-001@endverbatim
 */
TEST(SYSCTL_InterruptSourceTest, EnableAndDisableInterruptSourceByNumberUseSingleBitIMCField)
{
    StrictMock<SYSCTL_PrimitivesMock> stPrimitivesMock;
    SYSCTL_PrimitivesMockScope stPrimitivesMockScope(&stPrimitivesMock);
    StrictMock<SYSCTL_MCURegisterAccessMock> stMCUMock;
    SYSCTL_MCURegisterAccessMockScope stMCUMockScope(&stMCUMock);

    ExpectCheckParamsOk(stMCUMock, 6);

    EXPECT_CALL(stPrimitivesMock, WriteRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeWriteRegisterAction(SYSCTL_IMC_OFFSET,
                                                 SYSCTL_IMC_BOR_MASK,
                                                 SYSCTL_IMC_R_MOSC_POWERUP_BIT,
                                                 (UBase_t) SYSCTL_enSTATE_ENA)))
        .WillOnce(Invoke(MakeWriteRegisterAction(SYSCTL_IMC_OFFSET,
                                                 SYSCTL_IMC_BOR_MASK,
                                                 SYSCTL_IMC_R_PLL_LOCK_BIT,
                                                 (UBase_t) SYSCTL_enSTATE_DIS)));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enEnableInterruptSourceByNumber(SYSCTL_enMODULE_0,
                                                      SYSCTL_enINT_MOSC_POWERUP));
    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enDisableInterruptSourceByNumber(SYSCTL_enMODULE_0,
                                                       SYSCTL_enINT_PLL_LOCK));
}

/**
 * @brief Validate whole-mask IMC routing in the by-mask state helpers.
 * @summary Confirms that the by-mask enable, disable, and getter helpers access
 *          the `IMC` register with the caller-selected raw interrupt mask and
 *          preserve whole-mask semantics through the primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - SYSCTL_MCURegisterAccessMock bridge
 * - Original source under test: SYSCTL_InterruptSource.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-INTSRC-002@endverbatim
 */
TEST(SYSCTL_InterruptSourceTest, SetAndGetInterruptSourceStateByMaskUseWholeIMCField)
{
    StrictMock<SYSCTL_PrimitivesMock> stPrimitivesMock;
    SYSCTL_PrimitivesMockScope stPrimitivesMockScope(&stPrimitivesMock);
    StrictMock<SYSCTL_MCURegisterAccessMock> stMCUMock;
    SYSCTL_MCURegisterAccessMockScope stMCUMockScope(&stMCUMock);
    SYSCTL_nINTMASK enInterruptMaskReg;
    const UBase_t uxInterruptMaskReg = (UBase_t) SYSCTL_enINTMASK_BOR | (UBase_t) SYSCTL_enINTMASK_PLL_LOCK;

    enInterruptMaskReg = SYSCTL_enINTMASK_NONE;

    ExpectCheckParamsOk(stMCUMock, 3);

    {
        InSequence stSequence;
        EXPECT_CALL(stPrimitivesMock, WriteRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeWriteRegisterAction(SYSCTL_IMC_OFFSET,
                                                     (UBase_t) SYSCTL_enINTMASK_ALL,
                                                     0UL,
                                                     (UBase_t) SYSCTL_enINTMASK_ALL)));
        EXPECT_CALL(stPrimitivesMock, WriteRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeWriteRegisterAction(SYSCTL_IMC_OFFSET,
                                                     (UBase_t) SYSCTL_enINTMASK_MOSC_FAILURE,
                                                     0UL,
                                                     0UL)));
        EXPECT_CALL(stPrimitivesMock, ReadRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeReadRegisterAction(SYSCTL_IMC_OFFSET,
                                                    uxInterruptMaskReg,
                                                    0UL,
                                                    uxInterruptMaskReg)));
    }

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enEnableInterruptSourceByMask(SYSCTL_enMODULE_0,
                                                    SYSCTL_enINTMASK_ALL));
    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enDisableInterruptSourceByMask(SYSCTL_enMODULE_0,
                                                     SYSCTL_enINTMASK_MOSC_FAILURE));
    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enGetInterruptSourceStateByMask(SYSCTL_enMODULE_0,
                                                      (SYSCTL_nINTMASK) uxInterruptMaskReg,
                                                      &enInterruptMaskReg));
    EXPECT_EQ((SYSCTL_nINTMASK) uxInterruptMaskReg, enInterruptMaskReg);
}

/**
 * @brief Validate corrected single-bit IMC reads in the by-number getter.
 * @summary Confirms that the by-number state getter reads the documented `IMC`
 *          source bit with a single-bit logical mask and returns the decoded
 *          enabled or disabled state.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - SYSCTL_MCURegisterAccessMock bridge
 * - Original source under test: SYSCTL_InterruptSource.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-INTSRC-003@endverbatim
 */
TEST(SYSCTL_InterruptSourceTest, GetInterruptSourceStateByNumberUsesSingleBitIMCField)
{
    StrictMock<SYSCTL_PrimitivesMock> stPrimitivesMock;
    SYSCTL_PrimitivesMockScope stPrimitivesMockScope(&stPrimitivesMock);
    StrictMock<SYSCTL_MCURegisterAccessMock> stMCUMock;
    SYSCTL_MCURegisterAccessMockScope stMCUMockScope(&stMCUMock);
    SYSCTL_nSTATE enStateReg;

    enStateReg = SYSCTL_enSTATE_UNDEF;

    ExpectCheckParamsOk(stMCUMock, 3);

    EXPECT_CALL(stPrimitivesMock, ReadRegister(SYSCTL_enMODULE_0, _))
        .WillOnce(Invoke(MakeReadRegisterAction(SYSCTL_IMC_OFFSET,
                                                SYSCTL_IMC_BOR_MASK,
                                                SYSCTL_IMC_R_MOSC_FAILURE_BIT,
                                                (UBase_t) SYSCTL_enSTATE_ENA)));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enGetInterruptSourceStateByNumber(SYSCTL_enMODULE_0,
                                                        SYSCTL_enINT_MOSC_FAILURE,
                                                        &enStateReg));
    EXPECT_EQ(SYSCTL_enSTATE_ENA, enStateReg);
}

/**
 * @brief Validate null-pointer rejection across the SYSCTL interrupt getter family.
 * @summary Confirms that the state, raw-status, and masked-status getters reject
 *          null output pointers before attempting parameter validation or primitive
 *          register access.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_InterruptSource.c
 * - Public API parameter validation path@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-INTSRC-004@endverbatim
 */
TEST(SYSCTL_InterruptSourceTest, InterruptSourceGettersRejectNullPointers)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetInterruptSourceStateByMask(SYSCTL_enMODULE_0,
                                                      SYSCTL_enINTMASK_BOR,
                                                      (SYSCTL_nINTMASK*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enGetInterruptSourceStateByNumber(SYSCTL_enMODULE_0,
                                                        SYSCTL_enINT_BOR,
                                                        (SYSCTL_nSTATE*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enStatusInterruptSourceByMask(SYSCTL_enMODULE_0,
                                                    SYSCTL_enINTMASK_BOR,
                                                    (SYSCTL_nINTMASK*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enStatusInterruptSourceByNumber(SYSCTL_enMODULE_0,
                                                      SYSCTL_enINT_BOR,
                                                      (SYSCTL_nSTATUS*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enStatusMaskedInterruptSourceByMask(SYSCTL_enMODULE_0,
                                                          SYSCTL_enINTMASK_BOR,
                                                          (SYSCTL_nINTMASK*) 0UL));
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enStatusMaskedInterruptSourceByNumber(SYSCTL_enMODULE_0,
                                                            SYSCTL_enINT_BOR,
                                                            (SYSCTL_nSTATUS*) 0UL));
}

/**
 * @brief Validate MISC clear-register routing in the interrupt clear helpers.
 * @summary Confirms that the by-mask and by-number clear helpers write the
 *          documented `MISC` RW1C bits with base-wide mask semantics and the
 *          expected raw interrupt bit values.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - SYSCTL_MCURegisterAccessMock bridge
 * - Original source under test: SYSCTL_InterruptSource.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-INTSRC-005@endverbatim
 */
TEST(SYSCTL_InterruptSourceTest, ClearInterruptSourceWrappersUseMISCRegister)
{
    StrictMock<SYSCTL_PrimitivesMock> stPrimitivesMock;
    SYSCTL_PrimitivesMockScope stPrimitivesMockScope(&stPrimitivesMock);
    StrictMock<SYSCTL_MCURegisterAccessMock> stMCUMock;
    SYSCTL_MCURegisterAccessMockScope stMCUMockScope(&stMCUMock);

    ExpectCheckParamsOk(stMCUMock, 4);

    {
        InSequence stSequence;
        EXPECT_CALL(stPrimitivesMock, WriteRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeWriteRegisterAction(SYSCTL_MISC_OFFSET,
                                                     MCU_MASK_BASE,
                                                     0UL,
                                                     (UBase_t) SYSCTL_enINTMASK_ALL)));
        EXPECT_CALL(stPrimitivesMock, WriteRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeWriteRegisterAction(SYSCTL_MISC_OFFSET,
                                                     MCU_MASK_BASE,
                                                     0UL,
                                                     SYSCTL_MISC_R_MOSC_FAILURE_MASK)));
    }

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enClearInterruptSourceByMask(SYSCTL_enMODULE_0,
                                                   SYSCTL_enINTMASK_ALL));
    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enClearInterruptSourceByNumber(SYSCTL_enMODULE_0,
                                                     SYSCTL_enINT_MOSC_FAILURE));
}

/**
 * @brief Validate RIS raw-status routing in the interrupt status helpers.
 * @summary Confirms that the raw-status helpers read the documented `RIS`
 *          register with whole-mask semantics for by-mask access and single-bit
 *          logical semantics for by-number access.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - SYSCTL_MCURegisterAccessMock bridge
 * - Original source under test: SYSCTL_InterruptSource.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-INTSRC-006@endverbatim
 */
TEST(SYSCTL_InterruptSourceTest, StatusInterruptSourceWrappersReadRISRegister)
{
    StrictMock<SYSCTL_PrimitivesMock> stPrimitivesMock;
    SYSCTL_PrimitivesMockScope stPrimitivesMockScope(&stPrimitivesMock);
    StrictMock<SYSCTL_MCURegisterAccessMock> stMCUMock;
    SYSCTL_MCURegisterAccessMockScope stMCUMockScope(&stMCUMock);
    SYSCTL_nINTMASK enInterruptMaskReg;
    SYSCTL_nSTATUS enStatusReg;
    const UBase_t uxInterruptMaskReg = (UBase_t) SYSCTL_enINTMASK_BOR | (UBase_t) SYSCTL_enINTMASK_MOSC_POWERUP;

    enInterruptMaskReg = SYSCTL_enINTMASK_NONE;
    enStatusReg = SYSCTL_enSTATUS_UNDEF;

    ExpectCheckParamsOk(stMCUMock, 4);

    {
        InSequence stSequence;
        EXPECT_CALL(stPrimitivesMock, ReadRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeReadRegisterAction(SYSCTL_RIS_OFFSET,
                                                    uxInterruptMaskReg,
                                                    0UL,
                                                    uxInterruptMaskReg)));
        EXPECT_CALL(stPrimitivesMock, ReadRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeReadRegisterAction(SYSCTL_RIS_OFFSET,
                                                    SYSCTL_RIS_BOR_MASK,
                                                    SYSCTL_RIS_R_PLL_LOCK_BIT,
                                                    (UBase_t) SYSCTL_enSTATUS_ACTIVE)));
    }

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enStatusInterruptSourceByMask(SYSCTL_enMODULE_0,
                                                    (SYSCTL_nINTMASK) uxInterruptMaskReg,
                                                    &enInterruptMaskReg));
    EXPECT_EQ((SYSCTL_nINTMASK) uxInterruptMaskReg, enInterruptMaskReg);
    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enStatusInterruptSourceByNumber(SYSCTL_enMODULE_0,
                                                      SYSCTL_enINT_PLL_LOCK,
                                                      &enStatusReg));
    EXPECT_EQ(SYSCTL_enSTATUS_ACTIVE, enStatusReg);
}

/**
 * @brief Validate MISC masked-status routing in the interrupt status helpers.
 * @summary Confirms that the masked-status helpers read the documented `MISC`
 *          register with whole-mask semantics for by-mask access and single-bit
 *          logical semantics for by-number access.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - SYSCTL_MCURegisterAccessMock bridge
 * - Original source under test: SYSCTL_InterruptSource.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-INTSRC-007@endverbatim
 */
TEST(SYSCTL_InterruptSourceTest, StatusMaskedInterruptSourceWrappersReadMISCRegister)
{
    StrictMock<SYSCTL_PrimitivesMock> stPrimitivesMock;
    SYSCTL_PrimitivesMockScope stPrimitivesMockScope(&stPrimitivesMock);
    StrictMock<SYSCTL_MCURegisterAccessMock> stMCUMock;
    SYSCTL_MCURegisterAccessMockScope stMCUMockScope(&stMCUMock);
    SYSCTL_nINTMASK enInterruptMaskReg;
    SYSCTL_nSTATUS enStatusReg;
    const UBase_t uxInterruptMaskReg = (UBase_t) SYSCTL_enINTMASK_MOSC_FAILURE | (UBase_t) SYSCTL_enINTMASK_PLL_LOCK;

    enInterruptMaskReg = SYSCTL_enINTMASK_NONE;
    enStatusReg = SYSCTL_enSTATUS_UNDEF;

    ExpectCheckParamsOk(stMCUMock, 4);

    {
        InSequence stSequence;
        EXPECT_CALL(stPrimitivesMock, ReadRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeReadRegisterAction(SYSCTL_MISC_OFFSET,
                                                    uxInterruptMaskReg,
                                                    0UL,
                                                    uxInterruptMaskReg)));
        EXPECT_CALL(stPrimitivesMock, ReadRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeReadRegisterAction(SYSCTL_MISC_OFFSET,
                                                    SYSCTL_MISC_BOR_MASK,
                                                    SYSCTL_MISC_R_MOSC_POWERUP_BIT,
                                                    (UBase_t) SYSCTL_enSTATUS_ACTIVE)));
    }

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enStatusMaskedInterruptSourceByMask(SYSCTL_enMODULE_0,
                                                          (SYSCTL_nINTMASK) uxInterruptMaskReg,
                                                          &enInterruptMaskReg));
    EXPECT_EQ((SYSCTL_nINTMASK) uxInterruptMaskReg, enInterruptMaskReg);
    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enStatusMaskedInterruptSourceByNumber(SYSCTL_enMODULE_0,
                                                            SYSCTL_enINT_MOSC_POWERUP,
                                                            &enStatusReg));
    EXPECT_EQ(SYSCTL_enSTATUS_ACTIVE, enStatusReg);
}

/**
 * @brief Validate validation-error and primitive-error propagation in the SYSCTL interrupt helpers.
 * @summary Confirms that invalid by-mask and by-number requests stop at the
 *          `MCU__enCheckParams` layer without primitive access and that valid
 *          helpers propagate primitive read and write failures unchanged.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - SYSCTL_MCURegisterAccessMock bridge
 * - Original source under test: SYSCTL_InterruptSource.c@endverbatim
 * @requirements
 * @verbatim
 * - REQ-SYSCTL-INTSRC-008@endverbatim
 */
TEST(SYSCTL_InterruptSourceTest, InterruptSourceHelpersPropagateValidationAndPrimitiveErrors)
{
    {
        StrictMock<SYSCTL_PrimitivesMock> stPrimitivesMock;
        SYSCTL_PrimitivesMockScope stPrimitivesMockScope(&stPrimitivesMock);
        StrictMock<SYSCTL_MCURegisterAccessMock> stMCUMock;
        SYSCTL_MCURegisterAccessMockScope stMCUMockScope(&stMCUMock);

        EXPECT_CALL(stMCUMock,
                    CheckParams((UBase_t) SYSCTL_enINTMASK_MAX,
                                (UBase_t) SYSCTL_enINTMASK_MAX))
            .WillOnce(Return(MCU_enERROR_RANGE));

        EXPECT_EQ(SYSCTL_enERROR_RANGE,
                  SYSCTL__enEnableInterruptSourceByMask(SYSCTL_enMODULE_0,
                                                        SYSCTL_enINTMASK_MAX));
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stPrimitivesMock;
        SYSCTL_PrimitivesMockScope stPrimitivesMockScope(&stPrimitivesMock);
        StrictMock<SYSCTL_MCURegisterAccessMock> stMCUMock;
        SYSCTL_MCURegisterAccessMockScope stMCUMockScope(&stMCUMock);

        EXPECT_CALL(stMCUMock,
                    CheckParams((UBase_t) SYSCTL_enINT_SW,
                                (UBase_t) SYSCTL_enINT_SW))
            .WillOnce(Return(MCU_enERROR_RANGE));

        EXPECT_EQ(SYSCTL_enERROR_RANGE,
                  SYSCTL__enEnableInterruptSourceByNumber(SYSCTL_enMODULE_0,
                                                          SYSCTL_enINT_SW));
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stPrimitivesMock;
        SYSCTL_PrimitivesMockScope stPrimitivesMockScope(&stPrimitivesMock);
        StrictMock<SYSCTL_MCURegisterAccessMock> stMCUMock;
        SYSCTL_MCURegisterAccessMockScope stMCUMockScope(&stMCUMock);

        ExpectCheckParamsOk(stMCUMock, 3);

        EXPECT_CALL(stPrimitivesMock, WriteRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeWriteRegisterAction(SYSCTL_IMC_OFFSET,
                                                     SYSCTL_IMC_BOR_MASK,
                                                     SYSCTL_IMC_R_BOR_BIT,
                                                     (UBase_t) SYSCTL_enSTATE_ENA,
                                                     SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE,
                  SYSCTL__enEnableInterruptSourceByNumber(SYSCTL_enMODULE_0,
                                                          SYSCTL_enINT_BOR));
    }

    {
        StrictMock<SYSCTL_PrimitivesMock> stPrimitivesMock;
        SYSCTL_PrimitivesMockScope stPrimitivesMockScope(&stPrimitivesMock);
        StrictMock<SYSCTL_MCURegisterAccessMock> stMCUMock;
        SYSCTL_MCURegisterAccessMockScope stMCUMockScope(&stMCUMock);
        SYSCTL_nSTATUS enStatusReg;

        enStatusReg = SYSCTL_enSTATUS_UNDEF;

        ExpectCheckParamsOk(stMCUMock, 3);

        EXPECT_CALL(stPrimitivesMock, ReadRegister(SYSCTL_enMODULE_0, _))
            .WillOnce(Invoke(MakeReadRegisterAction(SYSCTL_MISC_OFFSET,
                                                    SYSCTL_MISC_BOR_MASK,
                                                    SYSCTL_MISC_R_BOR_BIT,
                                                    0UL,
                                                    SYSCTL_enERROR_VALUE)));

        EXPECT_EQ(SYSCTL_enERROR_VALUE,
                  SYSCTL__enStatusMaskedInterruptSourceByNumber(SYSCTL_enMODULE_0,
                                                                SYSCTL_enINT_BOR,
                                                                &enStatusReg));
        EXPECT_EQ(SYSCTL_enSTATUS_UNDEF, enStatusReg);
    }
}