/**
 *
 * @file SCB_VectorOffset_Test.cpp
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
#include <xDriver_MCU/Core/SCB/Driver/xHeader/SCB_VectorOffset.h>
#include <xDriver_MCU/Core/SCB/Peripheral/Register/xHeader/SCB_RegisterAddress.h>
#include <xDriver_MCU/Core/SCB/Peripheral/Register/RegisterDefines/SCB_RegisterDefines.h>
}

#include <tm4c129e_test/SCB_DriverMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::InSequence;
using ::testing::Invoke;
using ::testing::Return;
using ::testing::StrictMock;

/**
 * @brief Validate vector-offset write sequencing around global interrupt state.
 * @summary Confirms that `SCB__enSetVectorOffset` disables global interrupts,
 *          writes the VTOR offset field with the expected mask and address,
 *          executes a data-sync barrier, and restores the previous interrupt state.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SCB_DriverMock bridge
 * - Original source under test: SCB_VectorOffset.c@endverbatim
 */
TEST(SCB_VectorOffsetTest, SetVectorOffsetUsesInterruptGuardAndBarrier)
{
    StrictMock<SCB_DriverMock> stMock;
    SCB_DriverMockScope stMockScope(&stMock);
    InSequence stSequence;

    EXPECT_CALL(stMock, DisableGlobalInterrupt())
        .WillOnce(Return(MCU_enSTATE_ENA));
    EXPECT_CALL(stMock, WriteRegister(SCB_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SCB_nMODULE enModuleArg, SCB_Register_t* pstRegisterDataArg) -> SCB_nERROR
        {
            EXPECT_EQ(SCB_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SCB_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SCB_VTOR_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) SCB_VTOR_R_TBLOFF_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) 0UL, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) 0x00002000UL, pstRegisterDataArg->uxValue);
            return SCB_enERROR_OK;
        }));
    EXPECT_CALL(stMock, DataSyncBarrier());
    EXPECT_CALL(stMock, SetGlobalInterrupt(MCU_enSTATE_ENA));

    EXPECT_EQ(SCB_enERROR_OK,
              SCB__enSetVectorOffset(SCB_enMODULE_0, 0x00002000UL));
}

/**
 * @brief Validate null-pointer rejection in the vector-offset getter.
 * @summary Confirms that `SCB__enGetVectorOffset` rejects a null output pointer
 *          before attempting primitive register access.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SCB_VectorOffset.c@endverbatim
 */
TEST(SCB_VectorOffsetTest, GetVectorOffsetRejectsNullPointer)
{
    EXPECT_EQ(SCB_enERROR_POINTER,
              SCB__enGetVectorOffset(SCB_enMODULE_0, (UBase_t*) 0UL));
}

/**
 * @brief Validate vector-offset read mask behavior.
 * @summary Confirms that `SCB__enGetVectorOffset` reads the VTOR offset field
 *          with the expected address, mask, and zero shift and returns the value
 *          from the primitive read seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SCB_DriverMock bridge
 * - Original source under test: SCB_VectorOffset.c@endverbatim
 */
TEST(SCB_VectorOffsetTest, GetVectorOffsetUsesExpectedMask)
{
    StrictMock<SCB_DriverMock> stMock;
    SCB_DriverMockScope stMockScope(&stMock);
    UBase_t uxOffsetReg;

    uxOffsetReg = 0UL;

    EXPECT_CALL(stMock, ReadRegister(SCB_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SCB_nMODULE enModuleArg, SCB_Register_t* pstRegisterDataArg) -> SCB_nERROR
        {
            EXPECT_EQ(SCB_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SCB_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SCB_VTOR_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) SCB_VTOR_R_TBLOFF_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) 0UL, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = 0x00004000UL;
            return SCB_enERROR_OK;
        }));

    EXPECT_EQ(SCB_enERROR_OK,
              SCB__enGetVectorOffset(SCB_enMODULE_0, &uxOffsetReg));
    EXPECT_EQ((UBase_t) 0x00004000UL, uxOffsetReg);
}