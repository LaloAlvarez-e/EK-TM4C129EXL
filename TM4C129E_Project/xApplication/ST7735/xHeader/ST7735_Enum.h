/**
 *
 * @file ST7735_Enum.h
 * @copyright
 * @verbatim InDeviceMex 2020 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 17 feb. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 17 feb. 2021     vyldram    1.0         initial Version@endverbatim
 */
#ifndef XAPPLICATION_ST7735_XHEADER_ST7735_ENUM_H_
#define XAPPLICATION_ST7735_XHEADER_ST7735_ENUM_H_


typedef enum {
    ST7735_enINITFLAGS_NONE,
    ST7735_enINITFLAGS_GREEN,
    ST7735_enINITFLAGS_RED,
    ST7735_enINITFLAGS_BLACK,
}ST7735_nINITFLAGS;

typedef enum{
    ST7735_enCOMMAND_NOP = 0x00U,
    ST7735_enCOMMAND_SWRESET = 0x01U,
    ST7735_enCOMMAND_RDDID = 0x04U,
    ST7735_enCOMMAND_RDDST = 0x09U,

    ST7735_enCOMMAND_SLPIN = 0x10U,
    ST7735_enCOMMAND_SLPOUT = 0x11U,
    ST7735_enCOMMAND_PTLON = 0x12U,
    ST7735_enCOMMAND_NORON = 0x13U,

    ST7735_enCOMMAND_INVOFF = 0x20U,
    ST7735_enCOMMAND_INVON = 0x21U,
    ST7735_enCOMMAND_DISPOFF = 0x28U,
    ST7735_enCOMMAND_DISPON = 0x29U,
    ST7735_enCOMMAND_CASET = 0x2AU,
    ST7735_enCOMMAND_RASET = 0x2BU,
    ST7735_enCOMMAND_RAMWR = 0x2CU,
    ST7735_enCOMMAND_RAMRD = 0x2EU,

    ST7735_enCOMMAND_PTLAR = 0x30U,
    ST7735_enCOMMAND_COLMOD = 0x3AU,
    ST7735_enCOMMAND_MADCTL = 0x36U,

    ST7735_enCOMMAND_DELAY = 0x80U,

    ST7735_enCOMMAND_FRMCTR1 = 0xB1U,
    ST7735_enCOMMAND_FRMCTR2 = 0xB2U,
    ST7735_enCOMMAND_FRMCTR3 = 0xB3U,
    ST7735_enCOMMAND_INVCTR = 0xB4U,
    ST7735_enCOMMAND_DISSET5 = 0xB6U,

    ST7735_enCOMMAND_PWCTR1 = 0xC0U,
    ST7735_enCOMMAND_PWCTR2 = 0xC1U,
    ST7735_enCOMMAND_PWCTR3 = 0xC2U,
    ST7735_enCOMMAND_PWCTR4 = 0xC3U,
    ST7735_enCOMMAND_PWCTR5 = 0xC4U,
    ST7735_enCOMMAND_VMCTR1 = 0xC5U,
    ST7735_enCOMMAND_VMOFCTR = 0xC7U,

    ST7735_enCOMMAND_NVFCTR1 = 0xDAU,
    ST7735_enCOMMAND_RDID1 = 0xDAU,
    ST7735_enCOMMAND_RDID2 = 0xDBU,
    ST7735_enCOMMAND_RDID3 = 0xDCU,
    ST7735_enCOMMAND_RDID4 = 0xDDU,

    ST7735_enCOMMAND_PWCTR6 = 0xFCU,

    ST7735_enCOMMAND_GMCTRP1 = 0xE0U,
    ST7735_enCOMMAND_GMCTRN1 = 0xE1U,

}ST7735_nCOMMAND;

#endif /* XAPPLICATION_ST7735_XHEADER_ST7735_ENUM_H_ */