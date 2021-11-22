/**
 *
 * @file I2C_RegisterPeripheral_Module8.h
 * @copyright
 * @verbatim InDeviceMex 2021 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 30 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 30 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_I2C_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_I2C_REGISTERPERIPHERAL_MODULE8_H_
#define XDRIVER_MCU_I2C_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_I2C_REGISTERPERIPHERAL_MODULE8_H_

#include <xDriver_MCU/I2C/Peripheral/Register/xHeader/I2C_RegisterAddress.h>
#include <xDriver_MCU/I2C/Peripheral/Register/RegisterDefines/I2C_RegisterDefines.h>
#include <xDriver_MCU/I2C/Peripheral/Struct/xHeader/I2C_StructPeripheral.h>

/******************************************************************************************
************************************ I2C8 *********************************************
******************************************************************************************/

#define I2C8    ((I2C_t*) (I2C8_BASE))

/******************************************************************************************
************************************ 1 MSA *********************************************
******************************************************************************************/
#define I2C8_MSA    ((I2CMSA_t*) (I2C8_BASE + I2C_MSA_OFFSET ))
#define I2C8_MSA_R    (*((volatile uint32_t*) (I2C8_BASE + I2C_MSA_OFFSET)))

/******************************************************************************************
************************************ 2 MCS *********************************************
******************************************************************************************/
#define I2C8_MCS_STATUS    ((I2CMCS_STATUS_t*) (I2C8_BASE + I2C_MCS_OFFSET ))
#define I2C8_MCS_CONTROL    ((I2CMCS_CONTROL_t*) (I2C8_BASE + I2C_MCS_OFFSET ))
#define I2C8_MCS_R    (*((volatile uint32_t*) (I2C8_BASE + I2C_MCS_OFFSET)))

/******************************************************************************************
************************************ 3 MDR *********************************************
******************************************************************************************/
#define I2C8_MDR    ((I2CMDR_t*) (I2C8_BASE + I2C_MDR_OFFSET ))
#define I2C8_MDR_R    (*((volatile uint32_t*) (I2C8_BASE + I2C_MDR_OFFSET)))

/******************************************************************************************
************************************ 4 MTPR *********************************************
******************************************************************************************/
#define I2C8_MTPR    ((I2CMTPR_t*) (I2C8_BASE + I2C_MTPR_OFFSET ))
#define I2C8_MTPR_R    (*((volatile uint32_t*) (I2C8_BASE + I2C_MTPR_OFFSET)))

/******************************************************************************************
************************************ 5 MIMR *********************************************
******************************************************************************************/
#define I2C8_MIMR    ((I2CMIMR_t*) (I2C8_BASE + I2C_MIMR_OFFSET ))
#define I2C8_MIMR_R    (*((volatile uint32_t*) (I2C8_BASE + I2C_MIMR_OFFSET)))

/******************************************************************************************
************************************ 6 MRIS *********************************************
******************************************************************************************/
#define I2C8_MRIS    ((I2CMRIS_t*) (I2C8_BASE + I2C_MRIS_OFFSET ))
#define I2C8_MRIS_R    (*((volatile const uint32_t*) (I2C8_BASE + I2C_MRIS_OFFSET)))

/******************************************************************************************
************************************ 7 MMIS *********************************************
******************************************************************************************/
#define I2C8_MMIS    ((I2CMMIS_t*) (I2C8_BASE + I2C_MMIS_OFFSET ))
#define I2C8_MMIS_R    (*((volatile const uint32_t*) (I2C8_BASE + I2C_MMIS_OFFSET)))

/******************************************************************************************
************************************ 8 MICR *********************************************
******************************************************************************************/
#define I2C8_MICR    ((I2CMICR_t*) (I2C8_BASE + I2C_MICR_OFFSET ))
#define I2C8_MICR_R    (*((volatile uint32_t*) (I2C8_BASE + I2C_MICR_OFFSET)))

/******************************************************************************************
************************************ 9 MCR *********************************************
******************************************************************************************/
#define I2C8_MCR    ((I2CMCR_t*) (I2C8_BASE + I2C_MCR_OFFSET ))
#define I2C8_MCR_R    (*((volatile uint32_t*) (I2C8_BASE + I2C_MCR_OFFSET)))

/******************************************************************************************
************************************ 10 MCLKOCNT *********************************************
******************************************************************************************/
#define I2C8_MCLKOCNT    ((I2CMCLKOCNT_t*) (I2C8_BASE + I2C_MCLKOCNT_OFFSET ))
#define I2C8_MCLKOCNT_R    (*((volatile uint32_t*) (I2C8_BASE + I2C_MCLKOCNT_OFFSET)))

/******************************************************************************************
************************************ 11 MBMON *********************************************
******************************************************************************************/
#define I2C8_MBMON    ((I2CMBMON_t*) (I2C8_BASE + I2C_MBMON_OFFSET ))
#define I2C8_MBMON_R    (*((volatile const uint32_t*) (I2C8_BASE + I2C_MBMON_OFFSET)))

/******************************************************************************************
************************************ 12 MBLEN *********************************************
******************************************************************************************/
#define I2C8_MBLEN    ((I2CMBLEN_t*) (I2C8_BASE + I2C_MBLEN_OFFSET ))
#define I2C8_MBLEN_R    (*((volatile uint32_t*) (I2C8_BASE + I2C_MBLEN_OFFSET)))

/******************************************************************************************
************************************ 13 MBCNT *********************************************
******************************************************************************************/
#define I2C8_MBCNT    ((I2CMBCNT_t*) (I2C8_BASE + I2C_MBCNT_OFFSET ))
#define I2C8_MBCNT_R    (*((volatile uint32_t*) (I2C8_BASE + I2C_MBCNT_OFFSET)))

/******************************************************************************************
************************************ 14 SOAR *********************************************
******************************************************************************************/
#define I2C8_SOAR    ((I2CSOAR_t*) (I2C8_BASE + I2C_SOAR_OFFSET ))
#define I2C8_SOAR_R    (*((volatile uint32_t*) (I2C8_BASE + I2C_SOAR_OFFSET)))

/******************************************************************************************
************************************ 15 SCSR *********************************************
******************************************************************************************/
#define I2C8_SCSR_STATUS    ((I2CSCSR_STATUS_t*) (I2C8_BASE + I2C_SCSR_OFFSET ))
#define I2C8_SCSR_CONTROL    ((I2CSCSR_CONTROL_t*) (I2C8_BASE + I2C_SCSR_OFFSET ))
#define I2C8_SCSR_R    (*((volatile uint32_t*) (I2C8_BASE + I2C_SCSR_OFFSET)))

/******************************************************************************************
************************************ 16 SDR *********************************************
******************************************************************************************/
#define I2C8_SDR    ((I2CSDR_t*) (I2C8_BASE + I2C_SDR_OFFSET ))
#define I2C8_SDR_R    (*((volatile uint32_t*) (I2C8_BASE + I2C_SDR_OFFSET)))

/******************************************************************************************
************************************ 17 SIMR *********************************************
******************************************************************************************/
#define I2C8_SIMR    ((I2CSIMR_t*) (I2C8_BASE + I2C_SIMR_OFFSET ))
#define I2C8_SIMR_R    (*((volatile uint32_t*) (I2C8_BASE + I2C_SIMR_OFFSET)))

/******************************************************************************************
************************************ 18 SRIS *********************************************
******************************************************************************************/
#define I2C8_SRIS    ((I2CSRIS_t*) (I2C8_BASE + I2C_SRIS_OFFSET ))
#define I2C8_SRIS_R    (*((volatile const uint32_t*) (I2C8_BASE + I2C_SRIS_OFFSET)))

/******************************************************************************************
************************************ 19 SMIS *********************************************
******************************************************************************************/
#define I2C8_SMIS    ((I2CSMIS_t*) (I2C8_BASE + I2C_SMIS_OFFSET ))
#define I2C8_SMIS_R    (*((volatile const uint32_t*) (I2C8_BASE + I2C_SMIS_OFFSET)))

/******************************************************************************************
************************************ 20 SICR *********************************************
******************************************************************************************/
#define I2C8_SICR    ((I2CSICR_t*) (I2C8_BASE + I2C_SICR_OFFSET ))
#define I2C8_SICR_R    (*((volatile uint32_t*) (I2C8_BASE + I2C_SICR_OFFSET)))

/******************************************************************************************
************************************ 21 SOAR2 *********************************************
******************************************************************************************/
#define I2C8_SOAR2    ((I2CSOAR2_t*) (I2C8_BASE + I2C_SOAR2_OFFSET ))
#define I2C8_SOAR2_R    (*((volatile uint32_t*) (I2C8_BASE + I2C_SOAR2_OFFSET)))

/******************************************************************************************
************************************ 22 SACKCTL *********************************************
******************************************************************************************/
#define I2C8_SACKCTL    ((I2CSACKCTL_t*) (I2C8_BASE + I2C_SACKCTL_OFFSET ))
#define I2C8_SACKCTL_R    (*((volatile uint32_t*) (I2C8_BASE + I2C_SACKCTL_OFFSET)))

/******************************************************************************************
************************************ 23 FIFODATA *********************************************
******************************************************************************************/
#define I2C8_FIFODATA    ((I2CFIFODATA_t*) (I2C8_BASE + I2C_FIFODATA_OFFSET ))
#define I2C8_FIFODATA_R    (*((volatile uint32_t*) (I2C8_BASE + I2C_FIFODATA_OFFSET)))

/******************************************************************************************
************************************ 24 FIFOCTL *********************************************
******************************************************************************************/
#define I2C8_FIFOCTL    ((I2CFIFOCTL_t*) (I2C8_BASE + I2C_FIFOCTL_OFFSET ))
#define I2C8_FIFOCTL_R    (*((volatile uint32_t*) (I2C8_BASE + I2C_FIFOCTL_OFFSET)))

/******************************************************************************************
************************************ 25 FIFOSTATUS *********************************************
******************************************************************************************/
#define I2C8_FIFOSTATUS    ((I2CFIFOSTATUS_t*) (I2C8_BASE + I2C_FIFOSTATUS_OFFSET ))
#define I2C8_FIFOSTATUS_R    (*((volatile const uint32_t*) (I2C8_BASE + I2C_FIFOSTATUS_OFFSET)))

/******************************************************************************************
************************************ 26 PP *********************************************
******************************************************************************************/
#define I2C8_PP    ((I2CPP_t*) (I2C8_BASE + I2C_PP_OFFSET ))
#define I2C8_PP_R    (*((volatile uint32_t*) (I2C8_BASE + I2C_PP_OFFSET)))

/******************************************************************************************
************************************ 27 PC *********************************************
******************************************************************************************/
#define I2C8_PC    ((I2CPC_t*) (I2C8_BASE + I2C_PC_OFFSET ))
#define I2C8_PC_R    (*((volatile uint32_t*) (I2C8_BASE + I2C_PC_OFFSET)))

#endif /* XDRIVER_MCU_I2C_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_I2C_REGISTERPERIPHERAL_MODULE8_H_ */
