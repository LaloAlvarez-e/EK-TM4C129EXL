/**
 *
 * @file SCB_UnalignTrap_Test.cpp
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
#include <xDriver_MCU/Core/SCB/Driver/Traps/xHeader/SCB_UnalignTrap.h>
#include <xDriver_MCU/Core/SCB/Peripheral/Register/xHeader/SCB_RegisterAddress.h>
#include <xDriver_MCU/Core/SCB/Peripheral/Register/RegisterDefines/SCB_RegisterDefines.h>
}

#include <tm4c129e_test/SCB_DriverMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Invoke;
using ::testing::StrictMock;

/**
 * @brief Validate UNALIGN_TRP field programming.
 * @summary Confirms that `SCB__enSetUnalignTrapEnableState` writes the CCR
 *          `UNALIGN_TRP` field with the expected address, mask, shift, and state.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SCB_DriverMock bridge
 * - Original source under test: SCB_UnalignTrap.c@endverbatim
 */
TEST(SCB_UnalignTrapTest, SetUnalignTrapUsesExpectedField)
{
    StrictMock<SCB_DriverMock> stMock;
    SCB_DriverMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WriteRegister(SCB_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SCB_nMODULE enModuleArg, SCB_Register_t* pstRegisterDataArg) -> SCB_nERROR
        {
            EXPECT_EQ(SCB_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SCB_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SCB_CCR_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) SCB_CCR_UNALIGN_TRP_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) SCB_CCR_R_UNALIGN_TRP_BIT, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) SCB_enSTATE_ENA, pstRegisterDataArg->uxValue);
            return SCB_enERROR_OK;
        }));

    EXPECT_EQ(SCB_enERROR_OK,
              SCB__enSetUnalignTrapEnableState(SCB_enMODULE_0, SCB_enSTATE_ENA));
}

/**
 * @brief Validate enable and disable wrapper delegation for unaligned-access trapping.
 * @summary Confirms that the wrapper helpers delegate to the same CCR field write
 *          path with the expected enable and disable states.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SCB_DriverMock bridge
 * - Original source under test: SCB_UnalignTrap.c@endverbatim
 */
TEST(SCB_UnalignTrapTest, EnableAndDisableUnalignTrapDelegateToStateSetter)
{
    StrictMock<SCB_DriverMock> stMock;
    SCB_DriverMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, WriteRegister(SCB_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SCB_nMODULE, SCB_Register_t* pstRegisterDataArg) -> SCB_nERROR
        {
            EXPECT_EQ((UBase_t) SCB_enSTATE_ENA, pstRegisterDataArg->uxValue);
            return SCB_enERROR_OK;
        }))
        .WillOnce(Invoke([](SCB_nMODULE, SCB_Register_t* pstRegisterDataArg) -> SCB_nERROR
        {
            EXPECT_EQ((UBase_t) SCB_enSTATE_DIS, pstRegisterDataArg->uxValue);
            return SCB_enERROR_OK;
        }));

    EXPECT_EQ(SCB_enERROR_OK, SCB__enEnableUnalignTrap(SCB_enMODULE_0));
    EXPECT_EQ(SCB_enERROR_OK, SCB__enDisableUnalignTrap(SCB_enMODULE_0));
}

/**
 * @brief Validate UNALIGN_TRP getter behavior and null-pointer rejection.
 * @summary Confirms that `SCB__enGetUnalignTrapEnableState` rejects a null output
 *          pointer and otherwise reads the expected CCR field.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SCB_DriverMock bridge
 * - Original source under test: SCB_UnalignTrap.c@endverbatim
 */
TEST(SCB_UnalignTrapTest, GetUnalignTrapUsesExpectedField)
{
    StrictMock<SCB_DriverMock> stMock;
    SCB_DriverMockScope stMockScope(&stMock);
    SCB_nSTATE enStateReg;

    EXPECT_EQ(SCB_enERROR_POINTER,
              SCB__enGetUnalignTrapEnableState(SCB_enMODULE_0, (SCB_nSTATE*) 0UL));

    enStateReg = SCB_enSTATE_UNDEF;

    EXPECT_CALL(stMock, ReadRegister(SCB_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SCB_nMODULE enModuleArg, SCB_Register_t* pstRegisterDataArg) -> SCB_nERROR
        {
            EXPECT_EQ(SCB_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SCB_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SCB_CCR_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) SCB_CCR_UNALIGN_TRP_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) SCB_CCR_R_UNALIGN_TRP_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) SCB_enSTATE_ENA;
            return SCB_enERROR_OK;
        }));

    EXPECT_EQ(SCB_enERROR_OK,
              SCB__enGetUnalignTrapEnableState(SCB_enMODULE_0, &enStateReg));
    EXPECT_EQ(SCB_enSTATE_ENA, enStateReg);
}