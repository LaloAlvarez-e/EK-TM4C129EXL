/**
 *
 * @file HIB_RegisterAddress.h
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
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 5 abr. 2026    vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_DRIVER_HEADER_HIB_HIB_PERIPHERAL_REGISTER_XHEADER_HIB_REGISTERADDRESS_H_
#define XDRIVER_MCU_DRIVER_HEADER_HIB_HIB_PERIPHERAL_REGISTER_XHEADER_HIB_REGISTERADDRESS_H_

#include <xDriver_MCU/HIB/Peripheral/xHeader/HIB_Enum.h>

#define HIB_BASE    ((UBase_t) 0x400FC000UL)
#define HIB0_BASE    ((UBase_t) 0x400FC000UL)

#define HIB_OFFSET    ((UBase_t) 0x000FC000UL)
#define HIB0_OFFSET    ((UBase_t) 0x000FC000UL)

#define HIB_BITBANDING_BASE    ((UBase_t) 0x42000000UL)

#define HIB_RTCC_OFFSET    ((UBase_t) 0x0000UL)
#define HIB_RTCM0_OFFSET    ((UBase_t) 0x0004UL)
#define HIB_RTCLD_OFFSET    ((UBase_t) 0x000CUL)
#define HIB_CTL_OFFSET    ((UBase_t) 0x0010UL)
#define HIB_IM_OFFSET    ((UBase_t) 0x0014UL)
#define HIB_RIS_OFFSET    ((UBase_t) 0x0018UL)
#define HIB_MIS_OFFSET    ((UBase_t) 0x001CUL)
#define HIB_IC_OFFSET    ((UBase_t) 0x0020UL)
#define HIB_RTCT_OFFSET    ((UBase_t) 0x0024UL)
#define HIB_RTCSS_OFFSET    ((UBase_t) 0x0028UL)
#define HIB_IO_OFFSET    ((UBase_t) 0x002CUL)

#define HIB_DATA_OFFSET    ((UBase_t) 0x0030UL)
#define HIB_DATA0_OFFSET    ((UBase_t) 0x0030UL)
#define HIB_DATA1_OFFSET    ((UBase_t) 0x0034UL)
#define HIB_DATA2_OFFSET    ((UBase_t) 0x0038UL)
#define HIB_DATA3_OFFSET    ((UBase_t) 0x003CUL)
#define HIB_DATA4_OFFSET    ((UBase_t) 0x0040UL)
#define HIB_DATA5_OFFSET    ((UBase_t) 0x0044UL)
#define HIB_DATA6_OFFSET    ((UBase_t) 0x0048UL)
#define HIB_DATA7_OFFSET    ((UBase_t) 0x004CUL)
#define HIB_DATA8_OFFSET    ((UBase_t) 0x0050UL)
#define HIB_DATA9_OFFSET    ((UBase_t) 0x0054UL)
#define HIB_DATA10_OFFSET    ((UBase_t) 0x0058UL)
#define HIB_DATA11_OFFSET    ((UBase_t) 0x005CUL)
#define HIB_DATA12_OFFSET    ((UBase_t) 0x0060UL)
#define HIB_DATA13_OFFSET    ((UBase_t) 0x0064UL)
#define HIB_DATA14_OFFSET    ((UBase_t) 0x0068UL)
#define HIB_DATA15_OFFSET    ((UBase_t) 0x006CUL)

#define HIB_CALCTL_OFFSET    ((UBase_t) 0x0300UL)
#define HIB_CAL0_OFFSET    ((UBase_t) 0x0310UL)
#define HIB_CAL1_OFFSET    ((UBase_t) 0x0314UL)
#define HIB_CALLD0_OFFSET    ((UBase_t) 0x0320UL)
#define HIB_CALLD1_OFFSET    ((UBase_t) 0x0324UL)
#define HIB_CALM0_OFFSET    ((UBase_t) 0x0330UL)
#define HIB_CALM1_OFFSET    ((UBase_t) 0x0334UL)
#define HIB_LOCK_OFFSET    ((UBase_t) 0x0360UL)

#define HIB_TPCTL_OFFSET    ((UBase_t) 0x0400UL)
#define HIB_TPSTAT_OFFSET    ((UBase_t) 0x0404UL)
#define HIB_TPIO_OFFSET    ((UBase_t) 0x0410UL)

#define HIB_TPLOGTIME0_OFFSET    ((UBase_t) 0x04E0UL)
#define HIB_TPLOGTRIG0_OFFSET    ((UBase_t) 0x04E4UL)
#define HIB_TPLOGTIME1_OFFSET    ((UBase_t) 0x04E8UL)
#define HIB_TPLOGTRIG1_OFFSET    ((UBase_t) 0x04ECUL)
#define HIB_TPLOGTIME2_OFFSET    ((UBase_t) 0x04F0UL)
#define HIB_TPLOGTRIG2_OFFSET    ((UBase_t) 0x04F4UL)
#define HIB_TPLOGTIME3_OFFSET    ((UBase_t) 0x04F8UL)
#define HIB_TPLOGTRIG3_OFFSET    ((UBase_t) 0x04FCUL)

#define HIB_PP_OFFSET    ((UBase_t) 0x0FC0UL)
#define HIB_CC_OFFSET    ((UBase_t) 0x0FC8UL)

#endif /* XDRIVER_MCU_DRIVER_HEADER_HIB_HIB_PERIPHERAL_REGISTER_XHEADER_HIB_REGISTERADDRESS_H_ */
