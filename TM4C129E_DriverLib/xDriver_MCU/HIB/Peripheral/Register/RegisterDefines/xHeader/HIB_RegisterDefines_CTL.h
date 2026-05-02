/**
 *
 * @file HIB_RegisterDefines_CTL.h
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
 * @verbatim 6 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 6 abr. 2026    vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_CTL_H_
#define XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_CTL_H_

#include <xDriver_MCU/HIB/Peripheral/xHeader/HIB_Enum.h>

/******************************************************************************************
************************************ 4 CTL ***********************************************
******************************************************************************************/
/*--------*/
#define HIB_CTL_R_WRC_MASK    ((UBase_t) 0x80000000UL)
#define HIB_CTL_R_WRC_BIT    ((UBase_t) 31UL)
#define HIB_CTL_R_WRC_PROGRESS    ((UBase_t) 0x00000000UL)
#define HIB_CTL_R_WRC_DONE    ((UBase_t) 0x80000000UL)

#define HIB_CTL_WRC_MASK    ((UBase_t) 0x00000001UL)
#define HIB_CTL_WRC_PROGRESS    ((UBase_t) 0x00000000UL)
#define HIB_CTL_WRC_DONE    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_CTL_R_RETCLR_MASK    ((UBase_t) 0x40000000UL)
#define HIB_CTL_R_RETCLR_BIT    ((UBase_t) 30UL)
#define HIB_CTL_R_RETCLR_RELEASE    ((UBase_t) 0x00000000UL)
#define HIB_CTL_R_RETCLR_RETAIN    ((UBase_t) 0x40000000UL)

#define HIB_CTL_RETCLR_MASK    ((UBase_t) 0x00000001UL)
#define HIB_CTL_RETCLR_RELEASE    ((UBase_t) 0x00000000UL)
#define HIB_CTL_RETCLR_RETAIN    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_CTL_R_OSCSEL_MASK    ((UBase_t) 0x00080000UL)
#define HIB_CTL_R_OSCSEL_BIT    ((UBase_t) 19UL)
#define HIB_CTL_R_OSCSEL_EXTERNAL    ((UBase_t) 0x00000000UL)
#define HIB_CTL_R_OSCSEL_LFIOSC    ((UBase_t) 0x00080000UL)

#define HIB_CTL_OSCSEL_MASK    ((UBase_t) 0x00000001UL)
#define HIB_CTL_OSCSEL_EXTERNAL    ((UBase_t) 0x00000000UL)
#define HIB_CTL_OSCSEL_LFIOSC    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_CTL_R_OSCDRV_MASK    ((UBase_t) 0x00020000UL)
#define HIB_CTL_R_OSCDRV_BIT    ((UBase_t) 17UL)
#define HIB_CTL_R_OSCDRV_LOW    ((UBase_t) 0x00000000UL)
#define HIB_CTL_R_OSCDRV_HIGH    ((UBase_t) 0x00020000UL)

#define HIB_CTL_OSCDRV_MASK    ((UBase_t) 0x00000001UL)
#define HIB_CTL_OSCDRV_LOW    ((UBase_t) 0x00000000UL)
#define HIB_CTL_OSCDRV_HIGH    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_CTL_R_OSCBYP_MASK    ((UBase_t) 0x00010000UL)
#define HIB_CTL_R_OSCBYP_BIT    ((UBase_t) 16UL)
#define HIB_CTL_R_OSCBYP_CRYSTAL    ((UBase_t) 0x00000000UL)
#define HIB_CTL_R_OSCBYP_BYPASS    ((UBase_t) 0x00010000UL)

#define HIB_CTL_OSCBYP_MASK    ((UBase_t) 0x00000001UL)
#define HIB_CTL_OSCBYP_CRYSTAL    ((UBase_t) 0x00000000UL)
#define HIB_CTL_OSCBYP_BYPASS    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_CTL_R_VBATSEL_MASK    ((UBase_t) 0x00006000UL)
#define HIB_CTL_R_VBATSEL_BIT    ((UBase_t) 13UL)
#define HIB_CTL_R_VBATSEL_1_9V    ((UBase_t) 0x00000000UL)
#define HIB_CTL_R_VBATSEL_2_1V    ((UBase_t) 0x00002000UL)
#define HIB_CTL_R_VBATSEL_2_3V    ((UBase_t) 0x00004000UL)
#define HIB_CTL_R_VBATSEL_2_5V    ((UBase_t) 0x00006000UL)

#define HIB_CTL_VBATSEL_MASK    ((UBase_t) 0x00000003UL)
#define HIB_CTL_VBATSEL_1_9V    ((UBase_t) 0x00000000UL)
#define HIB_CTL_VBATSEL_2_1V    ((UBase_t) 0x00000001UL)
#define HIB_CTL_VBATSEL_2_3V    ((UBase_t) 0x00000002UL)
#define HIB_CTL_VBATSEL_2_5V    ((UBase_t) 0x00000003UL)
/*--------*/

/*--------*/
#define HIB_CTL_R_BATCHK_MASK    ((UBase_t) 0x00000400UL)
#define HIB_CTL_R_BATCHK_BIT    ((UBase_t) 10UL)
#define HIB_CTL_R_BATCHK_IDLE    ((UBase_t) 0x00000000UL)
#define HIB_CTL_R_BATCHK_PROGRESS ((UBase_t) 0x00000400UL)
#define HIB_CTL_R_BATCHK_START    ((UBase_t) 0x00000400UL)

#define HIB_CTL_BATCHK_MASK    ((UBase_t) 0x00000001UL)
#define HIB_CTL_BATCHK_IDLE    ((UBase_t) 0x00000000UL)
#define HIB_CTL_BATCHK_PROGRESS ((UBase_t) 0x00000001UL)
#define HIB_CTL_BATCHK_START    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_CTL_R_BATWKEN_MASK    ((UBase_t) 0x00000200UL)
#define HIB_CTL_R_BATWKEN_BIT    ((UBase_t) 9UL)
#define HIB_CTL_R_BATWKEN_DIS    ((UBase_t) 0x00000000UL)
#define HIB_CTL_R_BATWKEN_ENA    ((UBase_t) 0x00000200UL)

#define HIB_CTL_BATWKEN_MASK    ((UBase_t) 0x00000001UL)
#define HIB_CTL_BATWKEN_DIS    ((UBase_t) 0x00000000UL)
#define HIB_CTL_BATWKEN_ENA    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_CTL_R_VDD3ON_MASK    ((UBase_t) 0x00000100UL)
#define HIB_CTL_R_VDD3ON_BIT    ((UBase_t) 8UL)
#define HIB_CTL_R_VDD3ON_DIS    ((UBase_t) 0x00000000UL)
#define HIB_CTL_R_VDD3ON_ENA    ((UBase_t) 0x00000100UL)

#define HIB_CTL_VDD3ON_MASK    ((UBase_t) 0x00000001UL)
#define HIB_CTL_VDD3ON_DIS    ((UBase_t) 0x00000000UL)
#define HIB_CTL_VDD3ON_ENA    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_CTL_R_VABORT_MASK    ((UBase_t) 0x00000080UL)
#define HIB_CTL_R_VABORT_BIT    ((UBase_t) 7UL)
#define HIB_CTL_R_VABORT_DIS    ((UBase_t) 0x00000000UL)
#define HIB_CTL_R_VABORT_ENA    ((UBase_t) 0x00000080UL)

#define HIB_CTL_VABORT_MASK    ((UBase_t) 0x00000001UL)
#define HIB_CTL_VABORT_DIS    ((UBase_t) 0x00000000UL)
#define HIB_CTL_VABORT_ENA    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_CTL_R_CLK32EN_MASK    ((UBase_t) 0x00000040UL)
#define HIB_CTL_R_CLK32EN_BIT    ((UBase_t) 6UL)
#define HIB_CTL_R_CLK32EN_DIS    ((UBase_t) 0x00000000UL)
#define HIB_CTL_R_CLK32EN_ENA    ((UBase_t) 0x00000040UL)

#define HIB_CTL_CLK32EN_MASK    ((UBase_t) 0x00000001UL)
#define HIB_CTL_CLK32EN_DIS    ((UBase_t) 0x00000000UL)
#define HIB_CTL_CLK32EN_ENA    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_CTL_R_PINWEN_MASK    ((UBase_t) 0x00000010UL)
#define HIB_CTL_R_PINWEN_BIT    ((UBase_t) 4UL)
#define HIB_CTL_R_PINWEN_DIS    ((UBase_t) 0x00000000UL)
#define HIB_CTL_R_PINWEN_ENA    ((UBase_t) 0x00000010UL)

#define HIB_CTL_PINWEN_MASK    ((UBase_t) 0x00000001UL)
#define HIB_CTL_PINWEN_DIS    ((UBase_t) 0x00000000UL)
#define HIB_CTL_PINWEN_ENA    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_CTL_R_RTCWEN_MASK    ((UBase_t) 0x00000008UL)
#define HIB_CTL_R_RTCWEN_BIT    ((UBase_t) 3UL)
#define HIB_CTL_R_RTCWEN_DIS    ((UBase_t) 0x00000000UL)
#define HIB_CTL_R_RTCWEN_ENA    ((UBase_t) 0x00000008UL)

#define HIB_CTL_RTCWEN_MASK    ((UBase_t) 0x00000001UL)
#define HIB_CTL_RTCWEN_DIS    ((UBase_t) 0x00000000UL)
#define HIB_CTL_RTCWEN_ENA    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_CTL_R_HIBREQ_MASK    ((UBase_t) 0x00000002UL)
#define HIB_CTL_R_HIBREQ_BIT    ((UBase_t) 1UL)
#define HIB_CTL_R_HIBREQ_NOREQ    ((UBase_t) 0x00000000UL)
#define HIB_CTL_R_HIBREQ_REQ    ((UBase_t) 0x00000002UL)

#define HIB_CTL_HIBREQ_MASK    ((UBase_t) 0x00000001UL)
#define HIB_CTL_HIBREQ_NOREQ    ((UBase_t) 0x00000000UL)
#define HIB_CTL_HIBREQ_REQ    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_CTL_R_RTCEN_MASK    ((UBase_t) 0x00000001UL)
#define HIB_CTL_R_RTCEN_BIT    ((UBase_t) 0UL)
#define HIB_CTL_R_RTCEN_DIS    ((UBase_t) 0x00000000UL)
#define HIB_CTL_R_RTCEN_ENA    ((UBase_t) 0x00000001UL)

#define HIB_CTL_RTCEN_MASK    ((UBase_t) 0x00000001UL)
#define HIB_CTL_RTCEN_DIS    ((UBase_t) 0x00000000UL)
#define HIB_CTL_RTCEN_ENA    ((UBase_t) 0x00000001UL)
/*--------*/

#endif /* XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_CTL_H_ */
