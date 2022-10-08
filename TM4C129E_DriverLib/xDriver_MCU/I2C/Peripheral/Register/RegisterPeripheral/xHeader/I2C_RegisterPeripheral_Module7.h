/**
 *
 * @file I2C_RegisterPeripheral_Module7.h
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

#ifndef XDRIVER_MCU_I2C_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_I2C_REGISTERPERIPHERAL_MODULE7_H_
#define XDRIVER_MCU_I2C_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_I2C_REGISTERPERIPHERAL_MODULE7_H_

#include <xDriver_MCU/I2C/Peripheral/Register/xHeader/I2C_RegisterAddress.h>
#include <xDriver_MCU/I2C/Peripheral/Register/RegisterDefines/I2C_RegisterDefines.h>
#include <xDriver_MCU/I2C/Peripheral/Struct/xHeader/I2C_StructPeripheral.h>

/******************************************************************************************
************************************ I2C7 *********************************************
******************************************************************************************/
#define I2C7    ((I2C_t*) (I2C7_BASE))
#define I2C7_MASTER    ((I2C_MASTER_t*) (I2C7_BASE + I2C_MASTER_SA_OFFSET))
#define I2C7_SLAVE    ((I2C_SLAVE_t*) (I2C7_BASE + I2C_SLAVE_OAR_OFFSET))
#define I2C7_FIFO    ((I2C_SLAVE_t*) (I2C7_BASE + I2C_FIFO_DATA_OFFSET))
#define I2C7_CONTROL    ((I2C_CONTROL_t*) (I2C7_BASE + I2C_PP_OFFSET))

/******************************************************************************************
************************************ 1 MSA *********************************************
******************************************************************************************/
#define I2C7_MASTER_SA    ((I2C_MASTER_SA_t*) (I2C7_BASE + I2C_MASTER_SA_OFFSET ))
#define I2C7_MASTER_SA_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_MASTER_SA_OFFSET)))

/******************************************************************************************
************************************ 2 MCS *********************************************
******************************************************************************************/
#define I2C7_MASTER_STS    ((I2C_MASTER_STS_t*) (I2C7_BASE + I2C_MASTER_STS_OFFSET ))
#define I2C7_MASTER_CTL    ((I2C_MASTER_CTL_t*) (I2C7_BASE + I2C_MASTER_CTL_OFFSET ))
#define I2C7_MASTER_STS_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_MASTER_STS_OFFSET)))
#define I2C7_MASTER_CTL_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_MASTER_CTL_OFFSET)))

/******************************************************************************************
************************************ 3 MDR *********************************************
******************************************************************************************/
#define I2C7_MASTER_DATA    ((I2C_MASTER_DATA_t*) (I2C7_BASE + I2C_MASTER_DATA_OFFSET ))
#define I2C7_MASTER_DATA_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_MASTER_DATA_OFFSET)))

/******************************************************************************************
************************************ 4 MTPR *********************************************
******************************************************************************************/
#define I2C7_MASTER_TPR    ((I2C_MASTER_TPR_t*) (I2C7_BASE + I2C_MASTER_TPR_OFFSET ))
#define I2C7_MASTER_TPR_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_MASTER_TPR_OFFSET)))

/******************************************************************************************
************************************ 5 MIMR *********************************************
******************************************************************************************/
#define I2C7_MASTER_IMR    ((I2C_MASTER_IMR_t*) (I2C7_BASE + I2C_MASTER_IMR_OFFSET ))
#define I2C7_MASTER_IMR_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_MASTER_IMR_OFFSET)))

/******************************************************************************************
************************************ 6 MRIS *********************************************
******************************************************************************************/
#define I2C7_MASTER_RIS    ((I2C_MASTER_RIS_t*) (I2C7_BASE + I2C_MASTER_RIS_OFFSET ))
#define I2C7_MASTER_RIS_R    (*((volatile const UBase_t*) (I2C7_BASE + I2C_MASTER_RIS_OFFSET)))

/******************************************************************************************
************************************ 7 MMIS *********************************************
******************************************************************************************/
#define I2C7_MASTER_MIS    ((I2C_MASTER_MIS_t*) (I2C7_BASE + I2C_MASTER_MIS_OFFSET ))
#define I2C7_MASTER_MIS_R    (*((volatile const UBase_t*) (I2C7_BASE + I2C_MASTER_MIS_OFFSET)))

/******************************************************************************************
************************************ 8 MICR *********************************************
******************************************************************************************/
#define I2C7_MASTER_ICR    ((I2C_MASTER_ICR_t*) (I2C7_BASE + I2C_MASTER_ICR_OFFSET ))
#define I2C7_MASTER_ICR_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_MASTER_ICR_OFFSET)))

/******************************************************************************************
************************************ 9 MCR *********************************************
******************************************************************************************/
#define I2C7_MASTER_CR    ((I2C_MASTER_CR_t*) (I2C7_BASE + I2C_MASTER_CR_OFFSET ))
#define I2C7_MASTER_CR_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_MASTER_CR_OFFSET)))

/******************************************************************************************
************************************ 10 MCLKOCNT *********************************************
******************************************************************************************/
#define I2C7_MASTER_CLKOCNT    ((I2C_MASTER_CLKOCNT_t*) (I2C7_BASE + I2C_MASTER_CLKOCNT_OFFSET ))
#define I2C7_MASTER_CLKOCNT_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_MASTER_CLKOCNT_OFFSET)))

/******************************************************************************************
************************************ 11 MBMON *********************************************
******************************************************************************************/
#define I2C7_MASTER_BMON    ((I2C_MASTER_BMON_t*) (I2C7_BASE + I2C_MASTER_BMON_OFFSET ))
#define I2C7_MASTER_BMON_R    (*((volatile const UBase_t*) (I2C7_BASE + I2C_MASTER_BMON_OFFSET)))

/******************************************************************************************
************************************ 12 MBLEN *********************************************
******************************************************************************************/
#define I2C7_MASTER_BLEN    ((I2C_MASTER_BLEN_t*) (I2C7_BASE + I2C_MASTER_BLEN_OFFSET ))
#define I2C7_MASTER_BLEN_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_MASTER_BLEN_OFFSET)))

/******************************************************************************************
************************************ 13 MBCNT *********************************************
******************************************************************************************/
#define I2C7_MASTER_BCNT    ((I2C_MASTER_BCNT_t*) (I2C7_BASE + I2C_MASTER_BCNT_OFFSET ))
#define I2C7_MASTER_BCNT_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_MASTER_BCNT_OFFSET)))

/******************************************************************************************
************************************ 14 SOAR *********************************************
******************************************************************************************/
#define I2C7_SLAVE_OAR    ((I2C_SLAVE_OAR_t*) (I2C7_BASE + I2C_SLAVE_OAR_OFFSET ))
#define I2C7_SLAVE_OAR_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_SLAVE_OAR_OFFSET)))

/******************************************************************************************
************************************ 15 SCSR *********************************************
******************************************************************************************/
#define I2C7_SLAVE_STS    ((I2C_SLAVE_STS_t*) (I2C7_BASE + I2C_SLAVE_STS_OFFSET ))
#define I2C7_SLAVE_CTL    ((I2C_SLAVE_CTL_t*) (I2C7_BASE + I2C_SLAVE_CTL_OFFSET ))
#define I2C7_SLAVE_STS_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_SLAVE_STS_OFFSET)))
#define I2C7_SLAVE_CTL_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_SLAVE_CTL_OFFSET)))

/******************************************************************************************
************************************ 16 SDR *********************************************
******************************************************************************************/
#define I2C7_SLAVE_DATA    ((I2C_SLAVE_DATA_t*) (I2C7_BASE + I2C_SLAVE_DATA_OFFSET ))
#define I2C7_SLAVE_DATA_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_SLAVE_DATA_OFFSET)))

/******************************************************************************************
************************************ 17 SIMR *********************************************
******************************************************************************************/
#define I2C7_SLAVE_IMR    ((I2C_SLAVE_IMR_t*) (I2C7_BASE + I2C_SLAVE_IMR_OFFSET ))
#define I2C7_SLAVE_IMR_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_SLAVE_IMR_OFFSET)))

/******************************************************************************************
************************************ 18 SRIS *********************************************
******************************************************************************************/
#define I2C7_SLAVE_RIS    ((I2C_SLAVE_RIS_t*) (I2C7_BASE + I2C_SLAVE_RIS_OFFSET ))
#define I2C7_SLAVE_RIS_R    (*((volatile const UBase_t*) (I2C7_BASE + I2C_SLAVE_RIS_OFFSET)))

/******************************************************************************************
************************************ 19 SMIS *********************************************
******************************************************************************************/
#define I2C7_SLAVE_MIS    ((I2C_SLAVE_MIS_t*) (I2C7_BASE + I2C_SLAVE_MIS_OFFSET ))
#define I2C7_SLAVE_MIS_R    (*((volatile const UBase_t*) (I2C7_BASE + I2C_SLAVE_MIS_OFFSET)))

/******************************************************************************************
************************************ 20 SICR *********************************************
******************************************************************************************/
#define I2C7_SLAVE_ICR    ((I2C_SLAVE_ICR_t*) (I2C7_BASE + I2C_SLAVE_ICR_OFFSET ))
#define I2C7_SLAVE_ICR_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_SLAVE_ICR_OFFSET)))

/******************************************************************************************
************************************ 21 SOAR2 *********************************************
******************************************************************************************/
#define I2C7_SLAVE_OAR2    ((I2C_SLAVE_OAR2_t*) (I2C7_BASE + I2C_SLAVE_OAR2_OFFSET ))
#define I2C7_SLAVE_OAR2_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_SLAVE_OAR2_OFFSET)))

/******************************************************************************************
************************************ 22 SACKCTL *********************************************
******************************************************************************************/
#define I2C7_SLAVE_ACKCTL    ((I2C_SLAVE_ACKCTL_t*) (I2C7_BASE + I2C_SLAVE_ACKCTL_OFFSET ))
#define I2C7_SLAVE_ACKCTL_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_SLAVE_ACKCTL_OFFSET)))

/******************************************************************************************
************************************ 23 FIFODATA *********************************************
******************************************************************************************/
#define I2C7_FIFO_DATA    ((I2C_FIFO_DATA_t*) (I2C7_BASE + I2C_FIFO_DATA_OFFSET ))
#define I2C7_FIFO_DATA_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_FIFO_DATA_OFFSET)))

/******************************************************************************************
************************************ 24 FIFOCTL *********************************************
******************************************************************************************/
#define I2C7_FIFO_CTL    ((I2C_FIFO_CTL_t*) (I2C7_BASE + I2C_FIFO_CTL_OFFSET ))
#define I2C7_FIFO_CTL_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_FIFO_CTL_OFFSET)))

/******************************************************************************************
************************************ 25 FIFOSTATUS *********************************************
******************************************************************************************/
#define I2C7_FIFO_STS    ((I2C_FIFO_STS_t*) (I2C7_BASE + I2C_FIFO_STS_OFFSET ))
#define I2C7_FIFO_STS_R    (*((volatile const UBase_t*) (I2C7_BASE + I2C_FIFO_STS_OFFSET)))

/******************************************************************************************
************************************ 26 PP *********************************************
******************************************************************************************/
#define I2C7_CONTROL_PP    ((I2C_PP_t*) (I2C7_BASE + I2C_PP_OFFSET ))
#define I2C7_CONTROL_PP_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_PP_OFFSET)))

/******************************************************************************************
************************************ 27 PC *********************************************
******************************************************************************************/
#define I2C7_CONTROL_PC    ((I2C_PC_t*) (I2C7_BASE + I2C_PC_OFFSET ))
#define I2C7_CONTROL_PC_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_PC_OFFSET)))



/******************************************************************************************
************************************ 1 MSA *********************************************
******************************************************************************************/
#define I2C7_MSA    ((I2C_MASTER_SA_t*) (I2C7_BASE + I2C_MASTER_SA_OFFSET ))
#define I2C7_MSA_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_MASTER_SA_OFFSET)))

/******************************************************************************************
************************************ 2 MCS *********************************************
******************************************************************************************/
#define I2C7_MCS_STATUS     ((I2C_MASTER_STS_t*) (I2C7_BASE + I2C_MASTER_STS_OFFSET ))
#define I2C7_MCS_CONTROL    ((I2C_MASTER_CTL_t*) (I2C7_BASE + I2C_MASTER_CTL_OFFSET ))
#define I2C7_MCS_STATUS_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_MASTER_STS_OFFSET)))
#define I2C7_MCS_CONTROL_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_MASTER_CTL_OFFSET)))

/******************************************************************************************
************************************ 3 MDR *********************************************
******************************************************************************************/
#define I2C7_MDR    ((I2C_MASTER_DATA_t*) (I2C7_BASE + I2C_MASTER_DATA_OFFSET ))
#define I2C7_MDR_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_MASTER_DATA_OFFSET)))

/******************************************************************************************
************************************ 4 MTPR *********************************************
******************************************************************************************/
#define I2C7_MTPR    ((I2C_MASTER_TPR_t*) (I2C7_BASE + I2C_MASTER_TPR_OFFSET ))
#define I2C7_MTPR_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_MASTER_TPR_OFFSET)))

/******************************************************************************************
************************************ 5 MIMR *********************************************
******************************************************************************************/
#define I2C7_MIMR    ((I2C_MASTER_IMR_t*) (I2C7_BASE + I2C_MASTER_IMR_OFFSET ))
#define I2C7_MIMR_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_MASTER_IMR_OFFSET)))

/******************************************************************************************
************************************ 6 MRIS *********************************************
******************************************************************************************/
#define I2C7_MRIS    ((I2C_MASTER_RIS_t*) (I2C7_BASE + I2C_MASTER_RIS_OFFSET ))
#define I2C7_MRIS_R    (*((volatile const UBase_t*) (I2C7_BASE + I2C_MASTER_RIS_OFFSET)))

/******************************************************************************************
************************************ 7 MMIS *********************************************
******************************************************************************************/
#define I2C7_MMIS    ((I2C_MASTER_MIS_t*) (I2C7_BASE + I2C_MASTER_MIS_OFFSET ))
#define I2C7_MMIS_R    (*((volatile const UBase_t*) (I2C7_BASE + I2C_MASTER_MIS_OFFSET)))

/******************************************************************************************
************************************ 8 MICR *********************************************
******************************************************************************************/
#define I2C7_MICR    ((I2C_MASTER_ICR_t*) (I2C7_BASE + I2C_MASTER_ICR_OFFSET ))
#define I2C7_MICR_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_MASTER_ICR_OFFSET)))

/******************************************************************************************
************************************ 9 MCR *********************************************
******************************************************************************************/
#define I2C7_MCR    ((I2C_MASTER_CR_t*) (I2C7_BASE + I2C_MASTER_CR_OFFSET ))
#define I2C7_MCR_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_MASTER_CR_OFFSET)))

/******************************************************************************************
************************************ 10 MCLKOCNT *********************************************
******************************************************************************************/
#define I2C7_MCLKOCNT    ((I2C_MASTER_CLKOCNT_t*) (I2C7_BASE + I2C_MASTER_CLKOCNT_OFFSET ))
#define I2C7_MCLKOCNT_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_MASTER_CLKOCNT_OFFSET)))

/******************************************************************************************
************************************ 11 MBMON *********************************************
******************************************************************************************/
#define I2C7_MBMON    ((I2C_MASTER_BMON_t*) (I2C7_BASE + I2C_MASTER_BMON_OFFSET ))
#define I2C7_MBMON_R    (*((volatile const UBase_t*) (I2C7_BASE + I2C_MASTER_BMON_OFFSET)))

/******************************************************************************************
************************************ 12 MBLEN *********************************************
******************************************************************************************/
#define I2C7_MBLEN    ((I2C_MASTER_BLEN_t*) (I2C7_BASE + I2C_MASTER_BLEN_OFFSET ))
#define I2C7_MBLEN_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_MASTER_BLEN_OFFSET)))

/******************************************************************************************
************************************ 13 MBCNT *********************************************
******************************************************************************************/
#define I2C7_MBCNT    ((I2C_MASTER_BCNT_t*) (I2C7_BASE + I2C_MASTER_BCNT_OFFSET ))
#define I2C7_MBCNT_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_MASTER_BCNT_OFFSET)))

/******************************************************************************************
************************************ 14 SOAR *********************************************
******************************************************************************************/
#define I2C7_SOAR    ((I2C_SLAVE_OAR_t*) (I2C7_BASE + I2C_SLAVE_OAR_OFFSET ))
#define I2C7_SOAR_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_SLAVE_OAR_OFFSET)))

/******************************************************************************************
************************************ 15 SCSR *********************************************
******************************************************************************************/
#define I2C7_SCSR_STATUS    ((I2C_SLAVE_STS_t*) (I2C7_BASE + I2C_SLAVE_STS_OFFSET ))
#define I2C7_SCSR_CONTROL    ((I2C_SLAVE_CTL_t*) (I2C7_BASE + I2C_SLAVE_CTL_OFFSET ))
#define I2C7_SCSR_STATUS_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_SLAVE_STS_OFFSET)))
#define I2C7_SCSR_CONTROL_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_SLAVE_CTS_OFFSET)))
#define I2C7_SCSR_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_SLAVE_CTS_OFFSET)))

/******************************************************************************************
************************************ 16 SDR *********************************************
******************************************************************************************/
#define I2C7_SDR    ((I2C_SLAVE_DATA_t*) (I2C7_BASE + I2C_SLAVE_DATA_OFFSET ))
#define I2C7_SDR_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_SLAVE_DATA_OFFSET)))

/******************************************************************************************
************************************ 17 SIMR *********************************************
******************************************************************************************/
#define I2C7_SIMR    ((I2C_SLAVE_IMR_t*) (I2C7_BASE + I2C_SLAVE_IMR_OFFSET ))
#define I2C7_SIMR_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_SLAVE_IMR_OFFSET)))

/******************************************************************************************
************************************ 18 SRIS *********************************************
******************************************************************************************/
#define I2C7_SRIS    ((I2C_SLAVE_RIS_t*) (I2C7_BASE + I2C_SLAVE_RIS_OFFSET ))
#define I2C7_SRIS_R    (*((volatile const UBase_t*) (I2C7_BASE + I2C_SLAVE_RIS_OFFSET)))

/******************************************************************************************
************************************ 19 SMIS *********************************************
******************************************************************************************/
#define I2C7_SMIS    ((I2C_SLAVE_MIS_t*) (I2C7_BASE + I2C_SLAVE_MIS_OFFSET ))
#define I2C7_SMIS_R    (*((volatile const UBase_t*) (I2C7_BASE + I2C_SLAVE_MIS_OFFSET)))

/******************************************************************************************
************************************ 20 SICR *********************************************
******************************************************************************************/
#define I2C7_SICR    ((I2C_SLAVE_ICR_t*) (I2C7_BASE + I2C_SLAVE_ICR_OFFSET ))
#define I2C7_SICR_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_SLAVE_ICR_OFFSET)))

/******************************************************************************************
************************************ 21 SOAR2 *********************************************
******************************************************************************************/
#define I2C7_SOAR2    ((I2C_SLAVE_OAR2_t*) (I2C7_BASE + I2C_SLAVE_OAR2_OFFSET ))
#define I2C7_SOAR2_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_SLAVE_OAR2_OFFSET)))

/******************************************************************************************
************************************ 22 SACKCTL *********************************************
******************************************************************************************/
#define I2C7_SACKCTL    ((I2C_SLAVE_ACKCTL_t*) (I2C7_BASE + I2C_SLAVE_ACKCTL_OFFSET ))
#define I2C7_SACKCTL_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_SLAVE_ACKCTL_OFFSET)))

/******************************************************************************************
************************************ 23 FIFODATA *********************************************
******************************************************************************************/
#define I2C7_FIFODATA    ((I2C_FIFO_DATA_t*) (I2C7_BASE + I2C_FIFO_DATA_OFFSET ))
#define I2C7_FIFODATA_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_FIFO_DATA_OFFSET)))

/******************************************************************************************
************************************ 24 FIFOCTL *********************************************
******************************************************************************************/
#define I2C7_FIFOCTL    ((I2C_FIFO_CTL_t*) (I2C7_BASE + I2C_FIFO_CTL_OFFSET ))
#define I2C7_FIFOCTL_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_FIFO_CTL_OFFSET)))

/******************************************************************************************
************************************ 25 FIFOSTATUS *********************************************
******************************************************************************************/
#define I2C7_FIFOSTS    ((I2C_FIFO_STS_t*) (I2C7_BASE + I2C_FIFO_STS_OFFSET ))
#define I2C7_FIFOSTS_R    (*((volatile const UBase_t*) (I2C7_BASE + I2C_FIFO_STS_OFFSET)))

/******************************************************************************************
************************************ 26 PP *********************************************
******************************************************************************************/
#define I2C7_PP    ((I2C_PP_t*) (I2C7_BASE + I2C_PP_OFFSET ))
#define I2C7_PP_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_PP_OFFSET)))

/******************************************************************************************
************************************ 27 PC *********************************************
******************************************************************************************/
#define I2C7_PC    ((I2C_PC_t*) (I2C7_BASE + I2C_PC_OFFSET ))
#define I2C7_PC_R    (*((volatile UBase_t*) (I2C7_BASE + I2C_PC_OFFSET)))

#endif /* XDRIVER_MCU_I2C_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_I2C_REGISTERPERIPHERAL_MODULE7_H_ */
