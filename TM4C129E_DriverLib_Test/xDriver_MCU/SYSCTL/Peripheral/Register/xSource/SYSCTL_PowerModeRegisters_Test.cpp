/**
 *
 * @file SYSCTL_PowerModeRegisters_Test.cpp
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
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_DSLPPWRCFG.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_SDPMST.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_SLPPWRCFG.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/xHeader/SYSCTL_RegisterAddress.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/xHeader/SYSCTL_RegisterPeripheral.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/xHeader/SYSCTL_RegisterPeripheral_Bitbanding.h>
}

#include <cstdint>
#include <type_traits>

#include <gtest/gtest.h>

namespace
{
constexpr uintptr_t SYSCTL__uptrGetBitbandAliasAddress(uintptr_t uptrOffsetArg, uintptr_t uptrBitArg)
{
    return (uintptr_t) SYSCTL_BITBANDING_BASE
            + ((((uintptr_t) SYSCTL_OFFSET + uptrOffsetArg) * 32UL))
            + (uptrBitArg * 4UL);
}
}

/**
 * @brief Validate the documented Sleep Power Configuration raw register surface.
 * @summary Confirms that the raw `SLPPWRCFG` register definitions preserve the
 *          documented register offset, `FLASHPM` field shift, and bit-band
 *          alias routing for the Chapter 5 sleep power configuration register.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Production headers under test:
 *   SYSCTL_RegisterDefines_SLPPWRCFG.h
 *   SYSCTL_RegisterAddress.h
 *   SYSCTL_RegisterPeripheral.h
 *   SYSCTL_RegisterPeripheral_Bitbanding.h@endverbatim
 */
TEST(SYSCTLPowerModeRegistersTest, SleepPowerConfigurationUsesDocumentedOffsetShiftAndBitbandAliases)
{
    EXPECT_EQ((uintptr_t) 0x0188UL, (uintptr_t) SLPPWR_CFG_OFFSET);
    EXPECT_EQ((UBase_t) 0x00000030UL, (UBase_t) SLPPWR_CFG_R_FLASH_PM_MASK);
    EXPECT_EQ((UBase_t) 4UL, (UBase_t) SLPPWR_CFG_R_FLASH_PM_BIT);
    EXPECT_EQ((UBase_t) 0x00000020UL, (UBase_t) SLPPWR_CFG_R_FLASH_PM_LOWPOWER);

    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) SLPPWR_CFG_OFFSET,
              reinterpret_cast<uintptr_t>(SYSCTL_SLPPWR_CFG));
    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) SLPPWR_CFG_OFFSET,
              reinterpret_cast<uintptr_t>(&SYSCTL_SLPPWR_CFG_R));

    EXPECT_EQ(SYSCTL__uptrGetBitbandAliasAddress((uintptr_t) SLPPWR_CFG_OFFSET,
                                                 (uintptr_t) SLPPWR_CFG_R_FLASH_PM_BIT),
              reinterpret_cast<uintptr_t>(&SLPPWR_BITBANDING_CFG_FLASH_PM_0));
    EXPECT_EQ(SYSCTL__uptrGetBitbandAliasAddress((uintptr_t) SLPPWR_CFG_OFFSET,
                                                 (uintptr_t) SLPPWR_CFG_R_FLASH_PM_BIT + 1UL),
              reinterpret_cast<uintptr_t>(&SLPPWR_BITBANDING_CFG_FLASH_PM_1));
}

/**
 * @brief Validate the documented Deep-Sleep Power Configuration raw surface.
 * @summary Confirms that the raw `DSLPPWRCFG` register definitions preserve the
 *          documented `FLASHPM`, `TSPD`, and `LDOSM` field positions and expose
 *          writable bit-band aliases for the programmable deep-sleep control
 *          bits.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Production headers under test:
 *   SYSCTL_RegisterDefines_DSLPPWRCFG.h
 *   SYSCTL_RegisterAddress.h
 *   SYSCTL_RegisterPeripheral.h
 *   SYSCTL_RegisterPeripheral_Bitbanding.h@endverbatim
 */
TEST(SYSCTLPowerModeRegistersTest, DeepSleepPowerConfigurationUsesDocumentedOffsetsAndWritableBitAliases)
{
    EXPECT_EQ((uintptr_t) 0x018CUL, (uintptr_t) DSLPPWR_CFG_OFFSET);
    EXPECT_EQ((UBase_t) 4UL, (UBase_t) DSLPPWR_CFG_R_FLASH_PM_BIT);
    EXPECT_EQ((UBase_t) 8UL, (UBase_t) DSLPPWR_CFG_R_TS_PD_BIT);
    EXPECT_EQ((UBase_t) 9UL, (UBase_t) DSLPPWR_CFG_R_LDO_SM_BIT);

    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) DSLPPWR_CFG_OFFSET,
              reinterpret_cast<uintptr_t>(SYSCTL_DSLPPWR_CFG));
    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) DSLPPWR_CFG_OFFSET,
              reinterpret_cast<uintptr_t>(&SYSCTL_DSLPPWR_CFG_R));

    EXPECT_TRUE((std::is_same<volatile UBase_t*, decltype(&DSLPPWR_BITBANDING_CFG_TS_PD)>::value));
    EXPECT_TRUE((std::is_same<volatile UBase_t*, decltype(&DSLPPWR_BITBANDING_CFG_LDO_SM)>::value));

    EXPECT_EQ(SYSCTL__uptrGetBitbandAliasAddress((uintptr_t) DSLPPWR_CFG_OFFSET,
                                                 (uintptr_t) DSLPPWR_CFG_R_FLASH_PM_BIT),
              reinterpret_cast<uintptr_t>(&DSLPPWR_BITBANDING_CFG_FLASH_PM_0));
    EXPECT_EQ(SYSCTL__uptrGetBitbandAliasAddress((uintptr_t) DSLPPWR_CFG_OFFSET,
                                                 (uintptr_t) DSLPPWR_CFG_R_FLASH_PM_BIT + 1UL),
              reinterpret_cast<uintptr_t>(&DSLPPWR_BITBANDING_CFG_FLASH_PM_1));
    EXPECT_EQ(SYSCTL__uptrGetBitbandAliasAddress((uintptr_t) DSLPPWR_CFG_OFFSET,
                                                 (uintptr_t) DSLPPWR_CFG_R_TS_PD_BIT),
              reinterpret_cast<uintptr_t>(&DSLPPWR_BITBANDING_CFG_TS_PD));
    EXPECT_EQ(SYSCTL__uptrGetBitbandAliasAddress((uintptr_t) DSLPPWR_CFG_OFFSET,
                                                 (uintptr_t) DSLPPWR_CFG_R_LDO_SM_BIT),
              reinterpret_cast<uintptr_t>(&DSLPPWR_BITBANDING_CFG_LDO_SM));
}

/**
 * @brief Validate the documented status and adjacent reset-control raw macros.
 * @summary Confirms that the raw `SDPMST` status macros preserve the documented
 *          offset and status-bit positions while the adjacent `RESBEHAVCTL`
 *          typed pointer macros remain routed to the documented offset with
 *          writable access semantics.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Production headers under test:
 *   SYSCTL_RegisterDefines_SDPMST.h
 *   SYSCTL_RegisterAddress.h
 *   SYSCTL_RegisterPeripheral.h
 *   SYSCTL_RegisterPeripheral_Bitbanding.h@endverbatim
 */
TEST(SYSCTLPowerModeRegistersTest, StatusAndResetTypedPointerMacrosUseDocumentedOffsets)
{
    EXPECT_EQ((uintptr_t) 0x01CCUL, (uintptr_t) SDP_MST_OFFSET);
    EXPECT_EQ((UBase_t) 16UL, (UBase_t) SDP_MST_R_LOW_ACTIVE_BIT);
    EXPECT_EQ((UBase_t) 17UL, (UBase_t) SDP_MST_R_LOW_PWR_BIT);
    EXPECT_EQ((UBase_t) 18UL, (UBase_t) SDP_MST_R_FLASH_LP_BIT);
    EXPECT_EQ((UBase_t) 19UL, (UBase_t) SDP_MST_R_LDO_UA_BIT);

    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) SDP_MST_OFFSET,
              reinterpret_cast<uintptr_t>(SYSCTL_SDP_MST));
    EXPECT_TRUE((std::is_same<volatile const UBase_t*, decltype(&SYSCTL_SDP_MST_R)>::value));
    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) SDP_MST_OFFSET,
              reinterpret_cast<uintptr_t>(&SYSCTL_SDP_MST_R));

    EXPECT_EQ(SYSCTL__uptrGetBitbandAliasAddress((uintptr_t) SDP_MST_OFFSET,
                                                 (uintptr_t) SDP_MST_R_LOW_ACTIVE_BIT),
              reinterpret_cast<uintptr_t>(&SDP_BITBANDING_MST_LOW_ACTIVE));
    EXPECT_EQ(SYSCTL__uptrGetBitbandAliasAddress((uintptr_t) SDP_MST_OFFSET,
                                                 (uintptr_t) SDP_MST_R_LOW_PWR_BIT),
              reinterpret_cast<uintptr_t>(&SDP_BITBANDING_MST_LOW_PWR));
    EXPECT_EQ(SYSCTL__uptrGetBitbandAliasAddress((uintptr_t) SDP_MST_OFFSET,
                                                 (uintptr_t) SDP_MST_R_FLASH_LP_BIT),
              reinterpret_cast<uintptr_t>(&SDP_BITBANDING_MST_FLASH_LP));
    EXPECT_EQ(SYSCTL__uptrGetBitbandAliasAddress((uintptr_t) SDP_MST_OFFSET,
                                                 (uintptr_t) SDP_MST_R_LDO_UA_BIT),
              reinterpret_cast<uintptr_t>(&SDP_BITBANDING_MST_LDO_UA));

    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) RESET_BEHAVCTL_OFFSET,
              reinterpret_cast<uintptr_t>(SYSCTL_RESET_BEHAVCTL));
    EXPECT_TRUE((std::is_same<volatile UBase_t*, decltype(&SYSCTL_RESET_BEHAVCTL_R)>::value));
    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) RESET_BEHAVCTL_OFFSET,
              reinterpret_cast<uintptr_t>(&SYSCTL_RESET_BEHAVCTL_R));
}