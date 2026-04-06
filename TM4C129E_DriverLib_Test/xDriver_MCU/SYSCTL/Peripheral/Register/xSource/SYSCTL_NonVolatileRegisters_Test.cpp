/**
 *
 * @file SYSCTL_NonVolatileRegisters_Test.cpp
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
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_BOOTCFG.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_NVMSTAT.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_USER_REG.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/xHeader/SYSCTL_RegisterAddress.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/xHeader/SYSCTL_RegisterPeripheral.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/xHeader/SYSCTL_RegisterPeripheral_Bitbanding.h>
}

#include <cstdint>
#include <type_traits>

#include <gtest/gtest.h>

namespace
{
constexpr uintptr_t SYSCTL__uptrGetBitbandWordAliasBase(uintptr_t uptrOffsetArg)
{
    return (uintptr_t) SYSCTL_BITBANDING_BASE
            + ((((uintptr_t) SYSCTL_OFFSET + uptrOffsetArg) * 32UL));
}

constexpr uintptr_t SYSCTL__uptrGetBitbandAliasAddress(uintptr_t uptrOffsetArg, uintptr_t uptrBitArg)
{
    return SYSCTL__uptrGetBitbandWordAliasBase(uptrOffsetArg) + (uptrBitArg * 4UL);
}
}

/**
 * @brief Validate the documented raw `NVMSTAT` register surface.
 * @summary Confirms that the raw `NVMSTAT` definitions preserve the documented
 *          offset, `FWB` bit position, read-only typed raw access, and read-only
 *          bit-band alias routing for the flash-write-buffer availability flag.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Production headers under test:
 *   SYSCTL_RegisterDefines_NVMSTAT.h
 *   SYSCTL_RegisterAddress.h
 *   SYSCTL_RegisterPeripheral.h
 *   SYSCTL_RegisterPeripheral_Bitbanding.h@endverbatim
 */
TEST(SYSCTLNonVolatileRegistersTest, NvmStatusRawSurfaceUsesDocumentedOffsetAndReadOnlyAliases)
{
    EXPECT_EQ((uintptr_t) 0x01A0UL, (uintptr_t) NVM_STAT_OFFSET);
    EXPECT_EQ((UBase_t) 0x00000001UL, (UBase_t) NVM_STAT_R_FWB_MASK);
    EXPECT_EQ((UBase_t) 0UL, (UBase_t) NVM_STAT_R_FWB_BIT);
    EXPECT_EQ((UBase_t) 0x00000001UL, (UBase_t) NVM_STAT_R_FWB_PRESENT);

    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) NVM_STAT_OFFSET,
              reinterpret_cast<uintptr_t>(SYSCTL_NVM_STAT));
    EXPECT_TRUE((std::is_same<volatile const UBase_t*, decltype(&SYSCTL_NVM_STAT_R)>::value));
    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) NVM_STAT_OFFSET,
              reinterpret_cast<uintptr_t>(&SYSCTL_NVM_STAT_R));

    EXPECT_TRUE((std::is_same<volatile const UBase_t*, decltype(&NVM_BITBANDING_STAT_FWB)>::value));
    EXPECT_EQ(SYSCTL__uptrGetBitbandAliasAddress((uintptr_t) NVM_STAT_OFFSET,
                                                 (uintptr_t) NVM_STAT_R_FWB_BIT),
              reinterpret_cast<uintptr_t>(&NVM_BITBANDING_STAT_FWB));
}

/**
 * @brief Validate the documented raw `BOOTCFG` register surface.
 * @summary Confirms that the raw `BOOTCFG` definitions preserve the documented
 *          offset, one-bit and multi-bit field locations plus encodings,
 *          writable typed raw access, and bit-band alias routing for the
 *          individually addressable control bits.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Production headers under test:
 *   SYSCTL_RegisterDefines_BOOTCFG.h
 *   SYSCTL_RegisterAddress.h
 *   SYSCTL_RegisterPeripheral.h
 *   SYSCTL_RegisterPeripheral_Bitbanding.h@endverbatim
 */
TEST(SYSCTLNonVolatileRegistersTest, BootConfigRawSurfaceUsesDocumentedOffsetsMasksAndBitAliases)
{
    EXPECT_EQ((uintptr_t) 0x01D0UL, (uintptr_t) BOOT_CFG_OFFSET);
    EXPECT_EQ((UBase_t) 0UL, (UBase_t) BOOT_CFG_R_DBG0_BIT);
    EXPECT_EQ((UBase_t) 1UL, (UBase_t) BOOT_CFG_R_DBG1_BIT);
    EXPECT_EQ((UBase_t) 4UL, (UBase_t) BOOT_CFG_R_KEY_BIT);
    EXPECT_EQ((UBase_t) 8UL, (UBase_t) BOOT_CFG_R_EN_BIT);
    EXPECT_EQ((UBase_t) 9UL, (UBase_t) BOOT_CFG_R_POL_BIT);
    EXPECT_EQ((UBase_t) 10UL, (UBase_t) BOOT_CFG_R_PIN_BIT);
    EXPECT_EQ((UBase_t) 13UL, (UBase_t) BOOT_CFG_R_PORT_BIT);
    EXPECT_EQ((UBase_t) 31UL, (UBase_t) BOOT_CFG_R_NW_BIT);

    EXPECT_EQ((UBase_t) 0x00000010UL, (UBase_t) BOOT_CFG_R_KEY_A442);
    EXPECT_EQ((UBase_t) 0x00001C00UL, (UBase_t) BOOT_CFG_R_PIN_7);
    EXPECT_EQ((UBase_t) 0x0000E000UL, (UBase_t) BOOT_CFG_R_PORT_H);
    EXPECT_EQ((UBase_t) 0x80000000UL, (UBase_t) BOOT_CFG_R_NW_ENA);

    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) BOOT_CFG_OFFSET,
              reinterpret_cast<uintptr_t>(SYSCTL_BOOT_CFG));
    EXPECT_TRUE((std::is_same<volatile UBase_t*, decltype(&SYSCTL_BOOT_CFG_R)>::value));
    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) BOOT_CFG_OFFSET,
              reinterpret_cast<uintptr_t>(&SYSCTL_BOOT_CFG_R));
    EXPECT_EQ(SYSCTL__uptrGetBitbandWordAliasBase((uintptr_t) BOOT_CFG_OFFSET),
              reinterpret_cast<uintptr_t>(BOOT_BITBANDING_CFG));

    EXPECT_TRUE((std::is_same<volatile UBase_t*, decltype(&BOOT_BITBANDING_CFG_NW)>::value));
    EXPECT_EQ(SYSCTL__uptrGetBitbandAliasAddress((uintptr_t) BOOT_CFG_OFFSET,
                                                 (uintptr_t) BOOT_CFG_R_DBG0_BIT),
              reinterpret_cast<uintptr_t>(&BOOT_BITBANDING_CFG_DBG0));
    EXPECT_EQ(SYSCTL__uptrGetBitbandAliasAddress((uintptr_t) BOOT_CFG_OFFSET,
                                                 (uintptr_t) BOOT_CFG_R_DBG1_BIT),
              reinterpret_cast<uintptr_t>(&BOOT_BITBANDING_CFG_DBG1));
    EXPECT_EQ(SYSCTL__uptrGetBitbandAliasAddress((uintptr_t) BOOT_CFG_OFFSET,
                                                 (uintptr_t) BOOT_CFG_R_KEY_BIT),
              reinterpret_cast<uintptr_t>(&BOOT_BITBANDING_CFG_KEY));
    EXPECT_EQ(SYSCTL__uptrGetBitbandAliasAddress((uintptr_t) BOOT_CFG_OFFSET,
                                                 (uintptr_t) BOOT_CFG_R_EN_BIT),
              reinterpret_cast<uintptr_t>(&BOOT_BITBANDING_CFG_ENA));
    EXPECT_EQ(SYSCTL__uptrGetBitbandAliasAddress((uintptr_t) BOOT_CFG_OFFSET,
                                                 (uintptr_t) BOOT_CFG_R_POL_BIT),
              reinterpret_cast<uintptr_t>(&BOOT_BITBANDING_CFG_POL));
    EXPECT_EQ(SYSCTL__uptrGetBitbandAliasAddress((uintptr_t) BOOT_CFG_OFFSET,
                                                 (uintptr_t) BOOT_CFG_R_NW_BIT),
              reinterpret_cast<uintptr_t>(&BOOT_BITBANDING_CFG_NW));
}

/**
 * @brief Validate the documented raw `USER_REG0` through `USER_REG3` surface.
 * @summary Confirms that the raw user-register definitions preserve the
 *          documented staged offsets, full-width data mask, writable typed raw
 *          access, and bit-band word-alias base routing for all four committed
 *          user register slots.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Production headers under test:
 *   SYSCTL_RegisterDefines_USER_REG.h
 *   SYSCTL_RegisterAddress.h
 *   SYSCTL_RegisterPeripheral.h
 *   SYSCTL_RegisterPeripheral_Bitbanding.h@endverbatim
 */
TEST(SYSCTLNonVolatileRegistersTest, UserRegistersRawSurfaceUsesDocumentedOffsetsMasksAndBitbandBases)
{
    EXPECT_EQ((uintptr_t) 0x01E0UL, (uintptr_t) USER_REG0_OFFSET);
    EXPECT_EQ((uintptr_t) 0x01E4UL, (uintptr_t) USER_REG1_OFFSET);
    EXPECT_EQ((uintptr_t) 0x01E8UL, (uintptr_t) USER_REG2_OFFSET);
    EXPECT_EQ((uintptr_t) 0x01ECUL, (uintptr_t) USER_REG3_OFFSET);

    EXPECT_EQ((UBase_t) 0xFFFFFFFFUL, (UBase_t) USER_REG_R_DATA_MASK);
    EXPECT_EQ((UBase_t) 0UL, (UBase_t) USER_REG_R_DATA_BIT);
    EXPECT_EQ((UBase_t) 0xFFFFFFFFUL, (UBase_t) USER_REG3_R_DATA_MASK);

    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) USER_REG0_OFFSET,
              reinterpret_cast<uintptr_t>(USER_REG0));
    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) USER_REG1_OFFSET,
              reinterpret_cast<uintptr_t>(USER_REG1));
    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) USER_REG2_OFFSET,
              reinterpret_cast<uintptr_t>(USER_REG2));
    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) USER_REG3_OFFSET,
              reinterpret_cast<uintptr_t>(USER_REG3));

    EXPECT_TRUE((std::is_same<volatile UBase_t*, decltype(&USER_REG0_R)>::value));
    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) USER_REG0_OFFSET,
              reinterpret_cast<uintptr_t>(&USER_REG0_R));
    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) USER_REG1_OFFSET,
              reinterpret_cast<uintptr_t>(&USER_REG1_R));
    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) USER_REG2_OFFSET,
              reinterpret_cast<uintptr_t>(&USER_REG2_R));
    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) USER_REG3_OFFSET,
              reinterpret_cast<uintptr_t>(&USER_REG3_R));

    EXPECT_EQ(SYSCTL__uptrGetBitbandWordAliasBase((uintptr_t) USER_REG0_OFFSET),
              reinterpret_cast<uintptr_t>(USER_BITBANDING_REG0));
    EXPECT_EQ(SYSCTL__uptrGetBitbandWordAliasBase((uintptr_t) USER_REG1_OFFSET),
              reinterpret_cast<uintptr_t>(USER_BITBANDING_REG1));
    EXPECT_EQ(SYSCTL__uptrGetBitbandWordAliasBase((uintptr_t) USER_REG2_OFFSET),
              reinterpret_cast<uintptr_t>(USER_BITBANDING_REG2));
    EXPECT_EQ(SYSCTL__uptrGetBitbandWordAliasBase((uintptr_t) USER_REG3_OFFSET),
              reinterpret_cast<uintptr_t>(USER_BITBANDING_REG3));
}