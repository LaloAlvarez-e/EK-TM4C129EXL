/**
 *
 * @file SYSCTL_ModulePowerRegisters_Test.cpp
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
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_CAN0MPC.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_CAN0PDS.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_CAN1MPC.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_CAN1PDS.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_EMACMPC.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_EMACPDS.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_USBMPC.h>
#include <xDriver_MCU/SYSCTL/Peripheral/Register/RegisterDefines/xHeader/SYSCTL_RegisterDefines_USBPDS.h>
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
 * @brief Validate the documented USB module power-domain raw register surface.
 * @summary Confirms that the raw `USBPDS` and `USBMPC` definitions preserve the
 *          documented offsets, field masks, value encodings, typed raw access
 *          mutability, and bit-band alias routing for the USB SRAM power block.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Production headers under test:
 *   SYSCTL_RegisterDefines_USBPDS.h
 *   SYSCTL_RegisterDefines_USBMPC.h
 *   SYSCTL_RegisterAddress.h
 *   SYSCTL_RegisterPeripheral.h
 *   SYSCTL_RegisterPeripheral_Bitbanding.h@endverbatim
 */
TEST(SYSCTLModulePowerRegistersTest, UsbModulePowerRegistersUseDocumentedOffsetsValuesAndMutability)
{
    EXPECT_EQ((uintptr_t) 0x0280UL, (uintptr_t) USB_PDS_OFFSET);
    EXPECT_EQ((uintptr_t) 0x0284UL, (uintptr_t) USB_MPC_OFFSET);

    EXPECT_EQ((UBase_t) 0x00000003UL, (UBase_t) USB_PDS_R_PWRSTAT_MASK);
    EXPECT_EQ((UBase_t) 0UL, (UBase_t) USB_PDS_R_PWRSTAT_BIT);
    EXPECT_EQ((UBase_t) 0x0000000CUL, (UBase_t) USB_PDS_R_MEMSTAT_MASK);
    EXPECT_EQ((UBase_t) 2UL, (UBase_t) USB_PDS_R_MEMSTAT_BIT);
    EXPECT_EQ((UBase_t) 0x00000004UL, (UBase_t) USB_PDS_R_MEMSTAT_RET);

    EXPECT_EQ((UBase_t) 0x00000003UL, (UBase_t) USB_MPC_R_PWRCTL_MASK);
    EXPECT_EQ((UBase_t) 0UL, (UBase_t) USB_MPC_R_PWRCTL_BIT);
    EXPECT_EQ((UBase_t) 0x00000001UL, (UBase_t) USB_MPC_R_PWRCTL_RET);
    EXPECT_EQ((UBase_t) 0x00000003UL, (UBase_t) USB_MPC_R_PWRCTL_ON);

    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) USB_PDS_OFFSET,
              reinterpret_cast<uintptr_t>(SYSCTL_USB_PDS));
    EXPECT_TRUE((std::is_same<volatile const UBase_t*, decltype(&SYSCTL_USB_PDS_R)>::value));
    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) USB_PDS_OFFSET,
              reinterpret_cast<uintptr_t>(&SYSCTL_USB_PDS_R));

    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) USB_MPC_OFFSET,
              reinterpret_cast<uintptr_t>(SYSCTL_USB_MPC));
    EXPECT_TRUE((std::is_same<volatile UBase_t*, decltype(&SYSCTL_USB_MPC_R)>::value));
    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) USB_MPC_OFFSET,
              reinterpret_cast<uintptr_t>(&SYSCTL_USB_MPC_R));

    EXPECT_TRUE((std::is_same<volatile const UBase_t*, decltype(&USB_BITBANDING_PDS_PWRSTAT_0)>::value));
    EXPECT_TRUE((std::is_same<volatile const UBase_t*, decltype(&USB_BITBANDING_PDS_MEMSTAT_0)>::value));
    EXPECT_TRUE((std::is_same<volatile UBase_t*, decltype(&USB_BITBANDING_MPC_PWRCTL_0)>::value));

    EXPECT_EQ(SYSCTL__uptrGetBitbandAliasAddress((uintptr_t) USB_PDS_OFFSET,
                                                 (uintptr_t) USB_PDS_R_PWRSTAT_BIT),
              reinterpret_cast<uintptr_t>(&USB_BITBANDING_PDS_PWRSTAT_0));
    EXPECT_EQ(SYSCTL__uptrGetBitbandAliasAddress((uintptr_t) USB_PDS_OFFSET,
                                                 (uintptr_t) USB_PDS_R_MEMSTAT_BIT),
              reinterpret_cast<uintptr_t>(&USB_BITBANDING_PDS_MEMSTAT_0));
    EXPECT_EQ(SYSCTL__uptrGetBitbandAliasAddress((uintptr_t) USB_MPC_OFFSET,
                                                 (uintptr_t) USB_MPC_R_PWRCTL_BIT),
              reinterpret_cast<uintptr_t>(&USB_BITBANDING_MPC_PWRCTL_0));
}

/**
 * @brief Validate the documented EMAC module power-domain raw register surface.
 * @summary Confirms that the raw `EMACPDS` and `EMACMPC` definitions preserve
 *          the documented offsets, field masks, typed raw access mutability,
 *          and bit-band alias routing for the Ethernet MAC SRAM power block.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Production headers under test:
 *   SYSCTL_RegisterDefines_EMACPDS.h
 *   SYSCTL_RegisterDefines_EMACMPC.h
 *   SYSCTL_RegisterAddress.h
 *   SYSCTL_RegisterPeripheral.h
 *   SYSCTL_RegisterPeripheral_Bitbanding.h@endverbatim
 */
TEST(SYSCTLModulePowerRegistersTest, EmacModulePowerRegistersUseDocumentedOffsetsValuesAndMutability)
{
    EXPECT_EQ((uintptr_t) 0x0288UL, (uintptr_t) EMAC_PDS_OFFSET);
    EXPECT_EQ((uintptr_t) 0x028CUL, (uintptr_t) EMAC_MPC_OFFSET);

    EXPECT_EQ((UBase_t) 0x00000003UL, (UBase_t) EMAC_PDS_R_PWRSTAT_MASK);
    EXPECT_EQ((UBase_t) 0UL, (UBase_t) EMAC_PDS_R_PWRSTAT_BIT);
    EXPECT_EQ((UBase_t) 0x0000000CUL, (UBase_t) EMAC_PDS_R_MEMSTAT_MASK);
    EXPECT_EQ((UBase_t) 2UL, (UBase_t) EMAC_PDS_R_MEMSTAT_BIT);
    EXPECT_EQ((UBase_t) 0x00000003UL, (UBase_t) EMAC_MPC_R_PWRCTL_ON);

    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) EMAC_PDS_OFFSET,
              reinterpret_cast<uintptr_t>(SYSCTL_EMAC_PDS));
    EXPECT_TRUE((std::is_same<volatile const UBase_t*, decltype(&SYSCTL_EMAC_PDS_R)>::value));
    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) EMAC_PDS_OFFSET,
              reinterpret_cast<uintptr_t>(&SYSCTL_EMAC_PDS_R));

    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) EMAC_MPC_OFFSET,
              reinterpret_cast<uintptr_t>(SYSCTL_EMAC_MPC));
    EXPECT_TRUE((std::is_same<volatile UBase_t*, decltype(&SYSCTL_EMAC_MPC_R)>::value));
    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) EMAC_MPC_OFFSET,
              reinterpret_cast<uintptr_t>(&SYSCTL_EMAC_MPC_R));

    EXPECT_TRUE((std::is_same<volatile const UBase_t*, decltype(&EMAC_BITBANDING_PDS_PWRSTAT_0)>::value));
    EXPECT_TRUE((std::is_same<volatile const UBase_t*, decltype(&EMAC_BITBANDING_PDS_MEMSTAT_0)>::value));
    EXPECT_TRUE((std::is_same<volatile UBase_t*, decltype(&EMAC_BITBANDING_MPC_PWRCTL_0)>::value));

    EXPECT_EQ(SYSCTL__uptrGetBitbandAliasAddress((uintptr_t) EMAC_PDS_OFFSET,
                                                 (uintptr_t) EMAC_PDS_R_PWRSTAT_BIT),
              reinterpret_cast<uintptr_t>(&EMAC_BITBANDING_PDS_PWRSTAT_0));
    EXPECT_EQ(SYSCTL__uptrGetBitbandAliasAddress((uintptr_t) EMAC_PDS_OFFSET,
                                                 (uintptr_t) EMAC_PDS_R_MEMSTAT_BIT),
              reinterpret_cast<uintptr_t>(&EMAC_BITBANDING_PDS_MEMSTAT_0));
    EXPECT_EQ(SYSCTL__uptrGetBitbandAliasAddress((uintptr_t) EMAC_MPC_OFFSET,
                                                 (uintptr_t) EMAC_MPC_R_PWRCTL_BIT),
              reinterpret_cast<uintptr_t>(&EMAC_BITBANDING_MPC_PWRCTL_0));
}

/**
 * @brief Validate the documented CAN module power-domain raw register surface.
 * @summary Confirms that the raw `CAN0PDS/CAN0MPC` and `CAN1PDS/CAN1MPC`
 *          definitions preserve the documented offsets, field masks, typed raw
 *          access mutability, and bit-band alias routing for both CAN SRAM
 *          power blocks.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - Production headers under test:
 *   SYSCTL_RegisterDefines_CAN0PDS.h
 *   SYSCTL_RegisterDefines_CAN0MPC.h
 *   SYSCTL_RegisterDefines_CAN1PDS.h
 *   SYSCTL_RegisterDefines_CAN1MPC.h
 *   SYSCTL_RegisterAddress.h
 *   SYSCTL_RegisterPeripheral.h
 *   SYSCTL_RegisterPeripheral_Bitbanding.h@endverbatim
 */
TEST(SYSCTLModulePowerRegistersTest, CanModulePowerRegistersUseDocumentedOffsetsValuesAndMutability)
{
    EXPECT_EQ((uintptr_t) 0x0298UL, (uintptr_t) CAN0_PDS_OFFSET);
    EXPECT_EQ((uintptr_t) 0x029CUL, (uintptr_t) CAN0_MPC_OFFSET);
    EXPECT_EQ((uintptr_t) 0x02A0UL, (uintptr_t) CAN1_PDS_OFFSET);
    EXPECT_EQ((uintptr_t) 0x02A4UL, (uintptr_t) CAN1_MPC_OFFSET);

    EXPECT_EQ((UBase_t) 0x00000003UL, (UBase_t) CAN0_PDS_R_PWRSTAT_MASK);
    EXPECT_EQ((UBase_t) 0x0000000CUL, (UBase_t) CAN0_PDS_R_MEMSTAT_MASK);
    EXPECT_EQ((UBase_t) 0x00000003UL, (UBase_t) CAN0_MPC_R_PWRCTL_ON);
    EXPECT_EQ((UBase_t) 0x00000003UL, (UBase_t) CAN1_PDS_R_PWRSTAT_MASK);
    EXPECT_EQ((UBase_t) 0x0000000CUL, (UBase_t) CAN1_PDS_R_MEMSTAT_MASK);
    EXPECT_EQ((UBase_t) 0x00000003UL, (UBase_t) CAN1_MPC_R_PWRCTL_ON);

    EXPECT_TRUE((std::is_same<volatile const UBase_t*, decltype(&SYSCTL_CAN0_PDS_R)>::value));
    EXPECT_TRUE((std::is_same<volatile UBase_t*, decltype(&SYSCTL_CAN0_MPC_R)>::value));
    EXPECT_TRUE((std::is_same<volatile const UBase_t*, decltype(&SYSCTL_CAN1_PDS_R)>::value));
    EXPECT_TRUE((std::is_same<volatile UBase_t*, decltype(&SYSCTL_CAN1_MPC_R)>::value));

    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) CAN0_PDS_OFFSET,
              reinterpret_cast<uintptr_t>(&SYSCTL_CAN0_PDS_R));
    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) CAN0_MPC_OFFSET,
              reinterpret_cast<uintptr_t>(&SYSCTL_CAN0_MPC_R));
    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) CAN1_PDS_OFFSET,
              reinterpret_cast<uintptr_t>(&SYSCTL_CAN1_PDS_R));
    EXPECT_EQ((uintptr_t) SYSCTL_BASE + (uintptr_t) CAN1_MPC_OFFSET,
              reinterpret_cast<uintptr_t>(&SYSCTL_CAN1_MPC_R));

    EXPECT_TRUE((std::is_same<volatile const UBase_t*, decltype(&CAN0_BITBANDING_PDS_PWRSTAT_0)>::value));
    EXPECT_TRUE((std::is_same<volatile UBase_t*, decltype(&CAN0_BITBANDING_MPC_PWRCTL_0)>::value));
    EXPECT_TRUE((std::is_same<volatile const UBase_t*, decltype(&CAN1_BITBANDING_PDS_PWRSTAT_0)>::value));
    EXPECT_TRUE((std::is_same<volatile UBase_t*, decltype(&CAN1_BITBANDING_MPC_PWRCTL_0)>::value));

    EXPECT_EQ(SYSCTL__uptrGetBitbandAliasAddress((uintptr_t) CAN0_PDS_OFFSET,
                                                 (uintptr_t) CAN0_PDS_R_PWRSTAT_BIT),
              reinterpret_cast<uintptr_t>(&CAN0_BITBANDING_PDS_PWRSTAT_0));
    EXPECT_EQ(SYSCTL__uptrGetBitbandAliasAddress((uintptr_t) CAN0_PDS_OFFSET,
                                                 (uintptr_t) CAN0_PDS_R_MEMSTAT_BIT),
              reinterpret_cast<uintptr_t>(&CAN0_BITBANDING_PDS_MEMSTAT_0));
    EXPECT_EQ(SYSCTL__uptrGetBitbandAliasAddress((uintptr_t) CAN0_MPC_OFFSET,
                                                 (uintptr_t) CAN0_MPC_R_PWRCTL_BIT),
              reinterpret_cast<uintptr_t>(&CAN0_BITBANDING_MPC_PWRCTL_0));

    EXPECT_EQ(SYSCTL__uptrGetBitbandAliasAddress((uintptr_t) CAN1_PDS_OFFSET,
                                                 (uintptr_t) CAN1_PDS_R_PWRSTAT_BIT),
              reinterpret_cast<uintptr_t>(&CAN1_BITBANDING_PDS_PWRSTAT_0));
    EXPECT_EQ(SYSCTL__uptrGetBitbandAliasAddress((uintptr_t) CAN1_PDS_OFFSET,
                                                 (uintptr_t) CAN1_PDS_R_MEMSTAT_BIT),
              reinterpret_cast<uintptr_t>(&CAN1_BITBANDING_PDS_MEMSTAT_0));
    EXPECT_EQ(SYSCTL__uptrGetBitbandAliasAddress((uintptr_t) CAN1_MPC_OFFSET,
                                                 (uintptr_t) CAN1_MPC_R_PWRCTL_BIT),
              reinterpret_cast<uintptr_t>(&CAN1_BITBANDING_MPC_PWRCTL_0));
}