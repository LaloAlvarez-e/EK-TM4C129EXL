/**
 *
 * @file I2C_RegisterPeripheral_Module6.h
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

#ifndef XDRIVER_MCU_I2C_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_I2C_REGISTERPERIPHERAL_MODULE6_H_
#define XDRIVER_MCU_I2C_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_I2C_REGISTERPERIPHERAL_MODULE6_H_

#include <xDriver_MCU/I2C/Peripheral/Register/xHeader/I2C_RegisterAddress.h>
#include <xDriver_MCU/I2C/Peripheral/Register/RegisterDefines/I2C_RegisterDefines.h>
#include <xDriver_MCU/I2C/Peripheral/Struct/xHeader/I2C_StructPeripheral.h>

/******************************************************************************************
************************************ I2C6 *********************************************
******************************************************************************************/

#define I2C6    ((I2C_TypeDef*) (I2C6_BASE))

/******************************************************************************************
************************************ 1 MSA *********************************************
******************************************************************************************/
#define I2C6_MSA    ((I2CMSA_TypeDef*) (I2C6_BASE + I2C_MSA_OFFSET ))
#define I2C6_MSA_R    (*((volatile uint32_t*) (I2C6_BASE + I2C_MSA_OFFSET)))

/******************************************************************************************
************************************ 2 MCS *********************************************
******************************************************************************************/
#define I2C6_MCS_STATUS    ((I2CMCS_STATUS_TypeDef*) (I2C6_BASE + I2C_MCS_OFFSET ))
#define I2C6_MCS_CONTROL    ((I2CMCS_CONTROL_TypeDef*) (I2C6_BASE + I2C_MCS_OFFSET ))
#define I2C6_MCS_R    (*((volatile uint32_t*) (I2C6_BASE + I2C_MCS_OFFSET)))

/******************************************************************************************
************************************ 3 MDR *********************************************
******************************************************************************************/
#define I2C6_MDR    ((I2CMDR_TypeDef*) (I2C6_BASE + I2C_MDR_OFFSET ))
#define I2C6_MDR_R    (*((volatile uint32_t*) (I2C6_BASE + I2C_MDR_OFFSET)))

/******************************************************************************************
************************************ 4 MTPR *********************************************
******************************************************************************************/
#define I2C6_MTPR    ((I2CMTPR_TypeDef*) (I2C6_BASE + I2C_MTPR_OFFSET ))
#define I2C6_MTPR_R    (*((volatile uint32_t*) (I2C6_BASE + I2C_MTPR_OFFSET)))

/******************************************************************************************
************************************ 5 MIMR *********************************************
******************************************************************************************/
#define I2C6_MIMR    ((I2CMIMR_TypeDef*) (I2C6_BASE + I2C_MIMR_OFFSET ))
#define I2C6_MIMR_R    (*((volatile uint32_t*) (I2C6_BASE + I2C_MIMR_OFFSET)))

/******************************************************************************************
************************************ 6 MRIS *********************************************
******************************************************************************************/
#define I2C6_MRIS    ((I2CMRIS_TypeDef*) (I2C6_BASE + I2C_MRIS_OFFSET ))
#define I2C6_MRIS_R    (*((volatile const uint32_t*) (I2C6_BASE + I2C_MRIS_OFFSET)))

/******************************************************************************************
************************************ 7 MMIS *********************************************
******************************************************************************************/
#define I2C6_MMIS    ((I2CMMIS_TypeDef*) (I2C6_BASE + I2C_MMIS_OFFSET ))
#define I2C6_MMIS_R    (*((volatile const uint32_t*) (I2C6_BASE + I2C_MMIS_OFFSET)))

/******************************************************************************************
************************************ 8 MICR *********************************************
******************************************************************************************/
#define I2C6_MICR    ((I2CMICR_TypeDef*) (I2C6_BASE + I2C_MICR_OFFSET ))
#define I2C6_MICR_R    (*((volatile uint32_t*) (I2C6_BASE + I2C_MICR_OFFSET)))

/******************************************************************************************
************************************ 9 MCR *********************************************
******************************************************************************************/
#define I2C6_MCR    ((I2CMCR_TypeDef*) (I2C6_BASE + I2C_MCR_OFFSET ))
#define I2C6_MCR_R    (*((volatile uint32_t*) (I2C6_BASE + I2C_MCR_OFFSET)))

/******************************************************************************************
************************************ 10 MCLKOCNT *********************************************
******************************************************************************************/
#define I2C6_MCLKOCNT    ((I2CMCLKOCNT_TypeDef*) (I2C6_BASE + I2C_MCLKOCNT_OFFSET ))
#define I2C6_MCLKOCNT_R    (*((volatile uint32_t*) (I2C6_BASE + I2C_MCLKOCNT_OFFSET)))

/******************************************************************************************
************************************ 11 MBMON *********************************************
******************************************************************************************/
#define I2C6_MBMON    ((I2CMBMON_TypeDef*) (I2C6_BASE + I2C_MBMON_OFFSET ))
#define I2C6_MBMON_R    (*((volatile const uint32_t*) (I2C6_BASE + I2C_MBMON_OFFSET)))

/******************************************************************************************
************************************ 12 MBLEN *********************************************
******************************************************************************************/
#define I2C6_MBLEN    ((I2CMBLEN_TypeDef*) (I2C6_BASE + I2C_MBLEN_OFFSET ))
#define I2C6_MBLEN_R    (*((volatile uint32_t*) (I2C6_BASE + I2C_MBLEN_OFFSET)))

/******************************************************************************************
************************************ 13 MBCNT *********************************************
******************************************************************************************/
#define I2C6_MBCNT    ((I2CMBCNT_TypeDef*) (I2C6_BASE + I2C_MBCNT_OFFSET ))
#define I2C6_MBCNT_R    (*((volatile uint32_t*) (I2C6_BASE + I2C_MBCNT_OFFSET)))

/******************************************************************************************
************************************ 14 SOAR *********************************************
******************************************************************************************/
#define I2C6_SOAR    ((I2CSOAR_TypeDef*) (I2C6_BASE + I2C_SOAR_OFFSET ))
#define I2C6_SOAR_R    (*((volatile uint32_t*) (I2C6_BASE + I2C_SOAR_OFFSET)))

/******************************************************************************************
************************************ 15 SCSR *********************************************
******************************************************************************************/
#define I2C6_SCSR_STATUS    ((I2CSCSR_STATUS_TypeDef*) (I2C6_BASE + I2C_SCSR_OFFSET ))
#define I2C6_SCSR_CONTROL    ((I2CSCSR_CONTROL_TypeDef*) (I2C6_BASE + I2C_SCSR_OFFSET ))
#define I2C6_SCSR_R    (*((volatile uint32_t*) (I2C6_BASE + I2C_SCSR_OFFSET)))

/******************************************************************************************
************************************ 16 SDR *********************************************
******************************************************************************************/
#define I2C6_SDR    ((I2CSDR_TypeDef*) (I2C6_BASE + I2C_SDR_OFFSET ))
#define I2C6_SDR_R    (*((volatile uint32_t*) (I2C6_BASE + I2C_SDR_OFFSET)))

/******************************************************************************************
************************************ 17 SIMR *********************************************
******************************************************************************************/
#define I2C6_SIMR    ((I2CSIMR_TypeDef*) (I2C6_BASE + I2C_SIMR_OFFSET ))
#define I2C6_SIMR_R    (*((volatile uint32_t*) (I2C6_BASE + I2C_SIMR_OFFSET)))

/******************************************************************************************
************************************ 18 SRIS *********************************************
******************************************************************************************/
#define I2C6_SRIS    ((I2CSRIS_TypeDef*) (I2C6_BASE + I2C_SRIS_OFFSET ))
#define I2C6_SRIS_R    (*((volatile const uint32_t*) (I2C6_BASE + I2C_SRIS_OFFSET)))

/******************************************************************************************
************************************ 19 SMIS *********************************************
******************************************************************************************/
#define I2C6_SMIS    ((I2CSMIS_TypeDef*) (I2C6_BASE + I2C_SMIS_OFFSET ))
#define I2C6_SMIS_R    (*((volatile const uint32_t*) (I2C6_BASE + I2C_SMIS_OFFSET)))

/******************************************************************************************
************************************ 20 SICR *********************************************
******************************************************************************************/
#define I2C6_SICR    ((I2CSICR_TypeDef*) (I2C6_BASE + I2C_SICR_OFFSET ))
#define I2C6_SICR_R    (*((volatile uint32_t*) (I2C6_BASE + I2C_SICR_OFFSET)))

/******************************************************************************************
************************************ 21 SOAR2 *********************************************
******************************************************************************************/
#define I2C6_SOAR2    ((I2CSOAR2_TypeDef*) (I2C6_BASE + I2C_SOAR2_OFFSET ))
#define I2C6_SOAR2_R    (*((volatile uint32_t*) (I2C6_BASE + I2C_SOAR2_OFFSET)))

/******************************************************************************************
************************************ 22 SACKCTL *********************************************
******************************************************************************************/
#define I2C6_SACKCTL    ((I2CSACKCTL_TypeDef*) (I2C6_BASE + I2C_SACKCTL_OFFSET ))
#define I2C6_SACKCTL_R    (*((volatile uint32_t*) (I2C6_BASE + I2C_SACKCTL_OFFSET)))

/******************************************************************************************
************************************ 23 FIFODATA *********************************************
******************************************************************************************/
#define I2C6_FIFODATA    ((I2CFIFODATA_TypeDef*) (I2C6_BASE + I2C_FIFODATA_OFFSET ))
#define I2C6_FIFODATA_R    (*((volatile uint32_t*) (I2C6_BASE + I2C_FIFODATA_OFFSET)))

/******************************************************************************************
************************************ 24 FIFOCTL *********************************************
******************************************************************************************/
#define I2C6_FIFOCTL    ((I2CFIFOCTL_TypeDef*) (I2C6_BASE + I2C_FIFOCTL_OFFSET ))
#define I2C6_FIFOCTL_R    (*((volatile uint32_t*) (I2C6_BASE + I2C_FIFOCTL_OFFSET)))

/******************************************************************************************
************************************ 25 FIFOSTATUS *********************************************
******************************************************************************************/
#define I2C6_FIFOSTATUS    ((I2CFIFOSTATUS_TypeDef*) (I2C6_BASE + I2C_FIFOSTATUS_OFFSET ))
#define I2C6_FIFOSTATUS_R    (*((volatile const uint32_t*) (I2C6_BASE + I2C_FIFOSTATUS_OFFSET)))

/******************************************************************************************
************************************ 26 PP *********************************************
******************************************************************************************/
#define I2C6_PP    ((I2CPP_TypeDef*) (I2C6_BASE + I2C_PP_OFFSET ))
#define I2C6_PP_R    (*((volatile uint32_t*) (I2C6_BASE + I2C_PP_OFFSET)))

/******************************************************************************************
************************************ 27 PC *********************************************
******************************************************************************************/
#define I2C6_PC    ((I2CPC_TypeDef*) (I2C6_BASE + I2C_PC_OFFSET ))
#define I2C6_PC_R    (*((volatile uint32_t*) (I2C6_BASE + I2C_PC_OFFSET)))

#endif /* XDRIVER_MCU_I2C_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_I2C_REGISTERPERIPHERAL_MODULE6_H_ */
