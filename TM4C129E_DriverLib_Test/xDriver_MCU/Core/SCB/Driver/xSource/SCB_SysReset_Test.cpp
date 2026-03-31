/**
 *
 * @file SCB_SysReset_Test.cpp
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
#include <xDriver_MCU/Core/SCB/Driver/xHeader/SCB_SysReset.h>
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
 * @brief Validate VECTKEY readback rejection in the system-reset helper.
 * @summary Confirms that `SCB__enRequestSystemReset` rejects AIRCR reads whose
 *          key field does not match `SCB_AIRCR_VECTKEY_READ` and skips the write path.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SCB_DriverMock bridge
 * - Original source under test: SCB_SysReset.c@endverbatim
 */
TEST(SCB_SysResetTest, RequestSystemResetRejectsUnexpectedVectkeyRead)
{
    StrictMock<SCB_DriverMock> stMock;
    SCB_DriverMockScope stMockScope(&stMock);

    EXPECT_CALL(stMock, ReadRegister(SCB_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SCB_nMODULE enModuleArg, SCB_Register_t* pstRegisterDataArg) -> SCB_nERROR
        {
            EXPECT_EQ(SCB_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SCB_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SCB_AIRCR_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) SCB_AIRCR_VECTKEY_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) SCB_AIRCR_R_VECTKEY_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) 0UL;
            return SCB_enERROR_OK;
        }));

    EXPECT_EQ(SCB_enERROR_VALUE, SCB__enRequestSystemReset(SCB_enMODULE_0));
}

/**
 * @brief Validate AIRCR write composition for the system-reset helper.
 * @summary Confirms that `SCB__enRequestSystemReset` reads the VECTKEY field,
 *          issues a barrier, writes `VECTKEY | SYSRESETREQ` with a full-register
 *          mask, and propagates write errors instead of entering the fallback loop.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SCB_DriverMock bridge
 * - Original source under test: SCB_SysReset.c@endverbatim
 */
TEST(SCB_SysResetTest, RequestSystemResetWritesExpectedAircrValue)
{
    StrictMock<SCB_DriverMock> stMock;
    SCB_DriverMockScope stMockScope(&stMock);
    InSequence stSequence;

    EXPECT_CALL(stMock, ReadRegister(SCB_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SCB_nMODULE, SCB_Register_t* pstRegisterDataArg) -> SCB_nERROR
        {
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SCB_enERROR_POINTER;
            }
            pstRegisterDataArg->uxValue = SCB_AIRCR_VECTKEY_READ;
            return SCB_enERROR_OK;
        }));
    EXPECT_CALL(stMock, DataSyncBarrier());
    EXPECT_CALL(stMock, WriteRegister(SCB_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SCB_nMODULE enModuleArg, SCB_Register_t* pstRegisterDataArg) -> SCB_nERROR
        {
            EXPECT_EQ(SCB_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SCB_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SCB_AIRCR_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) MCU_MASK_32, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) 0UL, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) (SCB_AIRCR_R_VECTKEY_WRITE | SCB_AIRCR_R_SYSRESETREQ_RESET),
                      pstRegisterDataArg->uxValue);
            return SCB_enERROR_RANGE;
        }));

    EXPECT_EQ(SCB_enERROR_RANGE, SCB__enRequestSystemReset(SCB_enMODULE_0));
}

/**
 * @brief Validate AIRCR write composition for the debug reset helper.
 * @summary Confirms that `SCB__enRequestSystemReset_Debug` writes the AIRCR key
 *          and `VECTRESET` bit using a full-register mask and propagates write
 *          errors instead of entering the fallback loop.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SCB_DriverMock bridge
 * - Original source under test: SCB_SysReset.c@endverbatim
 */
TEST(SCB_SysResetTest, RequestSystemResetDebugWritesExpectedAircrValue)
{
    StrictMock<SCB_DriverMock> stMock;
    SCB_DriverMockScope stMockScope(&stMock);
    InSequence stSequence;

    EXPECT_CALL(stMock, ReadRegister(SCB_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SCB_nMODULE, SCB_Register_t* pstRegisterDataArg) -> SCB_nERROR
        {
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SCB_enERROR_POINTER;
            }
            pstRegisterDataArg->uxValue = SCB_AIRCR_VECTKEY_READ;
            return SCB_enERROR_OK;
        }));
    EXPECT_CALL(stMock, DataSyncBarrier());
    EXPECT_CALL(stMock, WriteRegister(SCB_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SCB_nMODULE enModuleArg, SCB_Register_t* pstRegisterDataArg) -> SCB_nERROR
        {
            EXPECT_EQ(SCB_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SCB_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) SCB_AIRCR_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) MCU_MASK_32, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) 0UL, pstRegisterDataArg->uxShift);
            EXPECT_EQ((UBase_t) (SCB_AIRCR_R_VECTKEY_WRITE | SCB_AIRCR_R_VECTRESET_NOUSE),
                      pstRegisterDataArg->uxValue);
            return SCB_enERROR_RANGE;
        }));

    EXPECT_EQ(SCB_enERROR_RANGE, SCB__enRequestSystemReset_Debug(SCB_enMODULE_0));
}