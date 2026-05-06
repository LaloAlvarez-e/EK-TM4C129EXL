/**
 *
 * @file HIB_RegisterPeripheral_Module0.h
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
 * @verbatim 7 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 7 abr. 2026    vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_HIB_REGISTERPERIPHERAL_MODULE0_H_
#define XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_HIB_REGISTERPERIPHERAL_MODULE0_H_

#include <xDriver_MCU/HIB/Peripheral/Register/xHeader/HIB_RegisterAddress.h>
#include <xDriver_MCU/HIB/Peripheral/Struct/xHeader/HIB_StructPeripheral.h>

/******************************************************************************************
************************************ HIB0 ************************************************
******************************************************************************************/

#define HIB0    ((HIB_t*) (HIB0_BASE))

/******************************************************************************************
************************************ 1 RTCC **********************************************
******************************************************************************************/
#define HIB0_RTCC    ((HIB_RTCC_t*) (HIB0_BASE + HIB_RTCC_OFFSET))
#define HIB0_RTCC_R    (*((volatile const UBase_t*) (HIB0_BASE + HIB_RTCC_OFFSET)))

/******************************************************************************************
************************************ 2 RTCM0 *********************************************
******************************************************************************************/
#define HIB0_RTCM0    ((HIB_RTCM0_t*) (HIB0_BASE + HIB_RTCM0_OFFSET))
#define HIB0_RTCM0_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_RTCM0_OFFSET)))

/******************************************************************************************
************************************ 3 RTCLD *********************************************
******************************************************************************************/
#define HIB0_RTCLD    ((HIB_RTCLD_t*) (HIB0_BASE + HIB_RTCLD_OFFSET))
#define HIB0_RTCLD_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_RTCLD_OFFSET)))

/******************************************************************************************
************************************ 4 CTL ***********************************************
******************************************************************************************/
#define HIB0_CTL    ((HIB_CTL_t*) (HIB0_BASE + HIB_CTL_OFFSET))
#define HIB0_CTL_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_CTL_OFFSET)))

/******************************************************************************************
************************************ 5 IM ************************************************
******************************************************************************************/
#define HIB0_IM    ((HIB_IM_t*) (HIB0_BASE + HIB_IM_OFFSET))
#define HIB0_IM_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_IM_OFFSET)))

/******************************************************************************************
************************************ 6 RIS ***********************************************
******************************************************************************************/
#define HIB0_RIS    ((HIB_RIS_t*) (HIB0_BASE + HIB_RIS_OFFSET))
#define HIB0_RIS_R    (*((volatile const UBase_t*) (HIB0_BASE + HIB_RIS_OFFSET)))

/******************************************************************************************
************************************ 7 MIS ***********************************************
******************************************************************************************/
#define HIB0_MIS    ((HIB_MIS_t*) (HIB0_BASE + HIB_MIS_OFFSET))
#define HIB0_MIS_R    (*((volatile const UBase_t*) (HIB0_BASE + HIB_MIS_OFFSET)))

/******************************************************************************************
************************************ 8 IC ************************************************
******************************************************************************************/
#define HIB0_IC    ((HIB_IC_t*) (HIB0_BASE + HIB_IC_OFFSET))
#define HIB0_IC_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_IC_OFFSET)))

/******************************************************************************************
************************************ 9 RTCT **********************************************
******************************************************************************************/
#define HIB0_RTCT    ((HIB_RTCT_t*) (HIB0_BASE + HIB_RTCT_OFFSET))
#define HIB0_RTCT_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_RTCT_OFFSET)))

/******************************************************************************************
************************************ 10 RTCSS ********************************************
******************************************************************************************/
#define HIB0_RTCSS    ((HIB_RTCSS_t*) (HIB0_BASE + HIB_RTCSS_OFFSET))
#define HIB0_RTCSS_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_RTCSS_OFFSET)))

/******************************************************************************************
************************************ 11 IO ***********************************************
******************************************************************************************/
#define HIB0_IO    ((HIB_IO_t*) (HIB0_BASE + HIB_IO_OFFSET))
#define HIB0_IO_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_IO_OFFSET)))

/******************************************************************************************
************************************ 12 DATA *********************************************
******************************************************************************************/
#define HIB0_DATA    ((HIB_DATA_t*) (HIB0_BASE + HIB_DATA_OFFSET))
#define HIB0_DATA0    ((HIB_DATA_t*) (HIB0_BASE + HIB_DATA0_OFFSET))
#define HIB0_DATA0_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_DATA0_OFFSET)))
#define HIB0_DATA1    ((HIB_DATA_t*) (HIB0_BASE + HIB_DATA1_OFFSET))
#define HIB0_DATA1_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_DATA1_OFFSET)))
#define HIB0_DATA2    ((HIB_DATA_t*) (HIB0_BASE + HIB_DATA2_OFFSET))
#define HIB0_DATA2_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_DATA2_OFFSET)))
#define HIB0_DATA3    ((HIB_DATA_t*) (HIB0_BASE + HIB_DATA3_OFFSET))
#define HIB0_DATA3_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_DATA3_OFFSET)))
#define HIB0_DATA4    ((HIB_DATA_t*) (HIB0_BASE + HIB_DATA4_OFFSET))
#define HIB0_DATA4_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_DATA4_OFFSET)))
#define HIB0_DATA5    ((HIB_DATA_t*) (HIB0_BASE + HIB_DATA5_OFFSET))
#define HIB0_DATA5_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_DATA5_OFFSET)))
#define HIB0_DATA6    ((HIB_DATA_t*) (HIB0_BASE + HIB_DATA6_OFFSET))
#define HIB0_DATA6_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_DATA6_OFFSET)))
#define HIB0_DATA7    ((HIB_DATA_t*) (HIB0_BASE + HIB_DATA7_OFFSET))
#define HIB0_DATA7_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_DATA7_OFFSET)))
#define HIB0_DATA8    ((HIB_DATA_t*) (HIB0_BASE + HIB_DATA8_OFFSET))
#define HIB0_DATA8_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_DATA8_OFFSET)))
#define HIB0_DATA9    ((HIB_DATA_t*) (HIB0_BASE + HIB_DATA9_OFFSET))
#define HIB0_DATA9_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_DATA9_OFFSET)))
#define HIB0_DATA10    ((HIB_DATA_t*) (HIB0_BASE + HIB_DATA10_OFFSET))
#define HIB0_DATA10_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_DATA10_OFFSET)))
#define HIB0_DATA11    ((HIB_DATA_t*) (HIB0_BASE + HIB_DATA11_OFFSET))
#define HIB0_DATA11_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_DATA11_OFFSET)))
#define HIB0_DATA12    ((HIB_DATA_t*) (HIB0_BASE + HIB_DATA12_OFFSET))
#define HIB0_DATA12_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_DATA12_OFFSET)))
#define HIB0_DATA13    ((HIB_DATA_t*) (HIB0_BASE + HIB_DATA13_OFFSET))
#define HIB0_DATA13_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_DATA13_OFFSET)))
#define HIB0_DATA14    ((HIB_DATA_t*) (HIB0_BASE + HIB_DATA14_OFFSET))
#define HIB0_DATA14_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_DATA14_OFFSET)))
#define HIB0_DATA15    ((HIB_DATA_t*) (HIB0_BASE + HIB_DATA15_OFFSET))
#define HIB0_DATA15_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_DATA15_OFFSET)))

/******************************************************************************************
************************************ 13 CALCTL *******************************************
******************************************************************************************/
#define HIB0_CALCTL    ((HIB_CALCTL_t*) (HIB0_BASE + HIB_CALCTL_OFFSET))
#define HIB0_CALCTL_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_CALCTL_OFFSET)))

/******************************************************************************************
************************************ 14 CAL0 *********************************************
******************************************************************************************/
#define HIB0_CAL0    ((HIB_CAL0_t*) (HIB0_BASE + HIB_CAL0_OFFSET))
#define HIB0_CAL0_R    (*((volatile const UBase_t*) (HIB0_BASE + HIB_CAL0_OFFSET)))

/******************************************************************************************
************************************ 15 CAL1 *********************************************
******************************************************************************************/
#define HIB0_CAL1    ((HIB_CAL1_t*) (HIB0_BASE + HIB_CAL1_OFFSET))
#define HIB0_CAL1_R    (*((volatile const UBase_t*) (HIB0_BASE + HIB_CAL1_OFFSET)))

/******************************************************************************************
************************************ 16 CALLD0 *******************************************
******************************************************************************************/
#define HIB0_CALLD0    ((HIB_CALLD0_t*) (HIB0_BASE + HIB_CALLD0_OFFSET))
#define HIB0_CALLD0_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_CALLD0_OFFSET)))

/******************************************************************************************
************************************ 17 CALLD1 *******************************************
******************************************************************************************/
#define HIB0_CALLD1    ((HIB_CALLD1_t*) (HIB0_BASE + HIB_CALLD1_OFFSET))
#define HIB0_CALLD1_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_CALLD1_OFFSET)))

/******************************************************************************************
************************************ 18 CALM0 ********************************************
******************************************************************************************/
#define HIB0_CALM0    ((HIB_CALM0_t*) (HIB0_BASE + HIB_CALM0_OFFSET))
#define HIB0_CALM0_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_CALM0_OFFSET)))

/******************************************************************************************
************************************ 19 CALM1 ********************************************
******************************************************************************************/
#define HIB0_CALM1    ((HIB_CALM1_t*) (HIB0_BASE + HIB_CALM1_OFFSET))
#define HIB0_CALM1_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_CALM1_OFFSET)))

/******************************************************************************************
************************************ 20 LOCK *********************************************
******************************************************************************************/
#define HIB0_LOCK    ((HIB_LOCK_t*) (HIB0_BASE + HIB_LOCK_OFFSET))
#define HIB0_LOCK_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_LOCK_OFFSET)))

/******************************************************************************************
************************************ 21 TPCTL ********************************************
******************************************************************************************/
#define HIB0_TPCTL    ((HIB_TPCTL_t*) (HIB0_BASE + HIB_TPCTL_OFFSET))
#define HIB0_TPCTL_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_TPCTL_OFFSET)))

/******************************************************************************************
************************************ 22 TPSTAT *******************************************
******************************************************************************************/
#define HIB0_TPSTAT    ((HIB_TPSTAT_t*) (HIB0_BASE + HIB_TPSTAT_OFFSET))
#define HIB0_TPSTAT_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_TPSTAT_OFFSET)))

/******************************************************************************************
************************************ 23 TPIO *********************************************
******************************************************************************************/
#define HIB0_TPIO    ((HIB_TPIO_t*) (HIB0_BASE + HIB_TPIO_OFFSET))
#define HIB0_TPIO_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_TPIO_OFFSET)))

/******************************************************************************************
************************************ 24 TPLOG ********************************************
******************************************************************************************/
#define HIB0_TPLOG    ((HIB_TPLOG_ARRAY_t*) (HIB0_BASE + HIB_TPLOG_OFFSET))

#define HIB0_TPLOG0        ((HIB_TPLOG_t*) (HIB0_BASE + HIB_TPLOG0_OFFSET))
#define HIB0_TPLOGTIME0    ((HIB_TPLOGTIME_t*) (HIB0_BASE + HIB_TPLOGTIME0_OFFSET))
#define HIB0_TPLOGTIME0_R  (*((volatile const UBase_t*) (HIB0_BASE + HIB_TPLOGTIME0_OFFSET)))
#define HIB0_TPLOGTRIG0    ((HIB_TPLOGTRIG_t*) (HIB0_BASE + HIB_TPLOGTRIG0_OFFSET))
#define HIB0_TPLOGTRIG0_R  (*((volatile const UBase_t*) (HIB0_BASE + HIB_TPLOGTRIG0_OFFSET)))

#define HIB0_TPLOG1        ((HIB_TPLOG_t*) (HIB0_BASE + HIB_TPLOG1_OFFSET))
#define HIB0_TPLOGTIME1    ((HIB_TPLOGTIME_t*) (HIB0_BASE + HIB_TPLOGTIME1_OFFSET))
#define HIB0_TPLOGTIME1_R  (*((volatile const UBase_t*) (HIB0_BASE + HIB_TPLOGTIME1_OFFSET)))
#define HIB0_TPLOGTRIG1    ((HIB_TPLOGTRIG_t*) (HIB0_BASE + HIB_TPLOGTRIG1_OFFSET))
#define HIB0_TPLOGTRIG1_R  (*((volatile const UBase_t*) (HIB0_BASE + HIB_TPLOGTRIG1_OFFSET)))

#define HIB0_TPLOG2        ((HIB_TPLOG_t*) (HIB0_BASE + HIB_TPLOG2_OFFSET))
#define HIB0_TPLOGTIME2    ((HIB_TPLOGTIME_t*) (HIB0_BASE + HIB_TPLOGTIME2_OFFSET))
#define HIB0_TPLOGTIME2_R  (*((volatile const UBase_t*) (HIB0_BASE + HIB_TPLOGTIME2_OFFSET)))
#define HIB0_TPLOGTRIG2    ((HIB_TPLOGTRIG_t*) (HIB0_BASE + HIB_TPLOGTRIG2_OFFSET))
#define HIB0_TPLOGTRIG2_R  (*((volatile const UBase_t*) (HIB0_BASE + HIB_TPLOGTRIG2_OFFSET)))

#define HIB0_TPLOG3        ((HIB_TPLOG_t*) (HIB0_BASE + HIB_TPLOG3_OFFSET))
#define HIB0_TPLOGTIME3    ((HIB_TPLOGTIME_t*) (HIB0_BASE + HIB_TPLOGTIME3_OFFSET))
#define HIB0_TPLOGTIME3_R    (*((volatile const UBase_t*) (HIB0_BASE + HIB_TPLOGTIME3_OFFSET)))
#define HIB0_TPLOGTRIG3    ((HIB_TPLOGTRIG_t*) (HIB0_BASE + HIB_TPLOGTRIG3_OFFSET))
#define HIB0_TPLOGTRIG3_R    (*((volatile const UBase_t*) (HIB0_BASE + HIB_TPLOGTRIG3_OFFSET)))

/******************************************************************************************
************************************ 25 PP ***********************************************
******************************************************************************************/
#define HIB0_PP    ((HIB_PP_t*) (HIB0_BASE + HIB_PP_OFFSET))
#define HIB0_PP_R    (*((volatile const UBase_t*) (HIB0_BASE + HIB_PP_OFFSET)))

/******************************************************************************************
************************************ 26 CC ***********************************************
******************************************************************************************/
#define HIB0_CC    ((HIB_CC_t*) (HIB0_BASE + HIB_CC_OFFSET))
#define HIB0_CC_R    (*((volatile UBase_t*) (HIB0_BASE + HIB_CC_OFFSET)))

#endif /* XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_HIB_REGISTERPERIPHERAL_MODULE0_H_ */
