/**
 *
 * @file SYSCTL_NonVolatileMemoryInfo_Test.cpp
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
 * @verbatim 5 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 5 abr. 2026    GitHub Copilot   1.0         initial Version@endverbatim
 */

extern "C"
{
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_NonVolatileMemoryInfo.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_NVMSTAT.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/xHeader/SYSCTL_RegisterAddress.h>
}

#include <tm4c129e_test/SYSCTL_PrimitivesMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Invoke;
using ::testing::Return;
using ::testing::StrictMock;

/**
 * @brief Validate null-pointer rejection in the NVMSTAT getter.
 * @summary Confirms that `SYSCTL__enIsFlashWriteBufferAvailable` rejects a
 *          null output pointer before attempting the NVMSTAT register read
 *          through the SYSCTL primitive seam.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Original source under test: SYSCTL_NonVolatileMemoryInfo.c
 * - Public API parameter validation path@endverbatim
 */
TEST(SYSCTL_NonVolatileMemoryInfoTest, IsFlashWriteBufferAvailableRejectsNullPointer)
{
    EXPECT_EQ(SYSCTL_enERROR_POINTER,
              SYSCTL__enIsFlashWriteBufferAvailable(SYSCTL_enMODULE_0, (SYSCTL_nBOOLEAN*) 0UL));
}

/**
 * @brief Validate NVMSTAT field routing in the flash-write-buffer getter.
 * @summary Confirms that `SYSCTL__enIsFlashWriteBufferAvailable` reads the
 *          documented `NVMSTAT.FWB` field using the expected register offset,
 *          mask, and shift, then returns the primitive field value as a
 *          boolean availability state.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_NonVolatileMemoryInfo.c@endverbatim
 */
TEST(SYSCTL_NonVolatileMemoryInfoTest, IsFlashWriteBufferAvailableUsesExpectedOffsetMaskAndShift)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nBOOLEAN enStateReg;

    enStateReg = SYSCTL_enFALSE;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Invoke([](SYSCTL_nMODULE enModuleArg, SYSCTL_Register_t* pstRegisterDataArg) -> SYSCTL_nERROR
        {
            EXPECT_EQ(SYSCTL_enMODULE_0, enModuleArg);
            EXPECT_NE(nullptr, pstRegisterDataArg);
            if(nullptr == pstRegisterDataArg)
            {
                return SYSCTL_enERROR_POINTER;
            }
            EXPECT_EQ((uintptr_t) NVM_STAT_OFFSET, pstRegisterDataArg->uptrAddress);
            EXPECT_EQ((UBase_t) NVM_STAT_FWB_MASK, pstRegisterDataArg->uxMask);
            EXPECT_EQ((UBase_t) NVM_STAT_R_FWB_BIT, pstRegisterDataArg->uxShift);
            pstRegisterDataArg->uxValue = (UBase_t) SYSCTL_enTRUE;
            return SYSCTL_enERROR_OK;
        }));

    EXPECT_EQ(SYSCTL_enERROR_OK,
              SYSCTL__enIsFlashWriteBufferAvailable(SYSCTL_enMODULE_0, &enStateReg));
    EXPECT_EQ(SYSCTL_enTRUE, enStateReg);
}

/**
 * @brief Validate read-error propagation in the NVMSTAT getter.
 * @summary Confirms that `SYSCTL__enIsFlashWriteBufferAvailable` returns the
 *          SYSCTL primitive read error unchanged and preserves the caller
 *          output value when the NVMSTAT read path fails.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSCTL_PrimitivesMock bridge
 * - Original source under test: SYSCTL_NonVolatileMemoryInfo.c@endverbatim
 */
TEST(SYSCTL_NonVolatileMemoryInfoTest, IsFlashWriteBufferAvailablePropagatesReadError)
{
    StrictMock<SYSCTL_PrimitivesMock> stMock;
    SYSCTL_PrimitivesMockScope stMockScope(&stMock);
    SYSCTL_nBOOLEAN enStateReg;

    enStateReg = SYSCTL_enTRUE;

    EXPECT_CALL(stMock, ReadRegister(SYSCTL_enMODULE_0, testing::_))
        .WillOnce(Return(SYSCTL_enERROR_VALUE));

    EXPECT_EQ(SYSCTL_enERROR_VALUE,
              SYSCTL__enIsFlashWriteBufferAvailable(SYSCTL_enMODULE_0, &enStateReg));
    EXPECT_EQ(SYSCTL_enTRUE, enStateReg);
}