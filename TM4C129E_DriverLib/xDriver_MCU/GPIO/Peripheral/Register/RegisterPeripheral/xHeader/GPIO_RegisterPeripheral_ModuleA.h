/**
 *
 * @file GPIO_RegisterPeripheral_ModuleA.h
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
 * @verbatim 9 jul. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 9 jul. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_GPIO_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_GPIO_REGISTERPERIPHERAL_MODULEA_H_
#define XDRIVER_MCU_GPIO_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_GPIO_REGISTERPERIPHERAL_MODULEA_H_

#include <xDriver_MCU/GPIO/Peripheral/Register/xHeader/GPIO_RegisterAddress.h>
#include <xDriver_MCU/GPIO/Peripheral/Struct/xHeader/GPIO_StructPeripheral.h>

#define GPIOA    ((GPIO_t*) (GPIOA_BASE))
#define GPIOA_AUX    ((GPIO_AUX_t*) (GPIOA_BASE))

/******************************************************************************************
 ************************************ 1 DATA *********************************************
 ******************************************************************************************/
/* GPIOA DATA*/
#define GPIOA_DATA_MASK    ((GPIODATA_MASK_t*) (GPIOA_BASE + GPIO_DATA_MASK_OFFSET))
#define GPIOA_DATA0_MASK_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_DATA0_MASK_OFFSET )))
#define GPIOA_DATA1_MASK_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_DATA1_MASK_OFFSET )))
#define GPIOA_DATA2_MASK_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_DATA2_MASK_OFFSET )))
#define GPIOA_DATA3_MASK_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_DATA3_MASK_OFFSET )))
#define GPIOA_DATA4_MASK_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_DATA4_MASK_OFFSET )))
#define GPIOA_DATA5_MASK_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_DATA5_MASK_OFFSET )))
#define GPIOA_DATA6_MASK_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_DATA6_MASK_OFFSET )))
#define GPIOA_DATA7_MASK_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_DATA7_MASK_OFFSET )))

#define GPIOA_DATA    ((GPIODATA_t*) (GPIOA_BASE + GPIO_DATA_OFFSET))
#define GPIOA_DATA_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_DATA_OFFSET)))

/******************************************************************************************
 ************************************ 2 DIR *********************************************
 ******************************************************************************************/
/* GPIOA DIR*/
#define GPIOA_DIR    ((GPIODIR_t*) (GPIOA_BASE + GPIO_DIR_OFFSET))
#define GPIOA_DIR_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_DIR_OFFSET)))

/******************************************************************************************
 ************************************ 3 IS *********************************************
 ******************************************************************************************/
/* GPIOA IS*/
#define GPIOA_IS    ((GPIOIS_t*) (GPIOA_BASE + GPIO_IS_OFFSET))
#define GPIOA_IS_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_IS_OFFSET)))

/******************************************************************************************
 ************************************ 4 IBE *********************************************
 ******************************************************************************************/
/* GPIOA IBE*/
#define GPIOA_IBE    ((GPIOIBE_t*) (GPIOA_BASE + GPIO_IBE_OFFSET))
#define GPIOA_IBE_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_IBE_OFFSET)))

/******************************************************************************************
 ************************************ 5 IEV *********************************************
 ******************************************************************************************/
/* GPIOA IEV*/
#define GPIOA_IEV    ((GPIOIEV_t*) (GPIOA_BASE + GPIO_IEV_OFFSET))
#define GPIOA_IEV_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_IEV_OFFSET)))

/******************************************************************************************
 ************************************ 6 IM *********************************************
 ******************************************************************************************/
/* GPIOA IME*/
#define GPIOA_IM    ((GPIOIM_t*) (GPIOA_BASE + GPIO_IM_OFFSET))
#define GPIOA_IM_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_IM_OFFSET)))

/******************************************************************************************
 ************************************ 7 RIS *********************************************
 ******************************************************************************************/
/* GPIOA RIS*/
#define GPIOA_RIS    ((GPIORIS_t*) (GPIOA_BASE + GPIO_RIS_OFFSET))
#define GPIOA_RIS_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_RIS_OFFSET)))

/******************************************************************************************
 ************************************ 8 MIS *********************************************
 ******************************************************************************************/
/* GPIOA MIS*/
#define GPIOA_MIS    ((GPIOMIS_t*) (GPIOA_BASE + GPIO_MIS_OFFSET))
#define GPIOA_MIS_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_MIS_OFFSET)))

/******************************************************************************************
 ************************************ 9 ICR *********************************************
 ******************************************************************************************/
/* GPIOA IC*/
#define GPIOA_ICR    ((GPIOICR_t*) (GPIOA_BASE + GPIO_ICR_OFFSET))
#define GPIOA_ICR_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_ICR_OFFSET)))

/******************************************************************************************
 ************************************ 10 AFSEL *********************************************
 ******************************************************************************************/
/* GPIOA AFSEL*/
#define GPIOA_AFSEL    ((GPIOAFSEL_t*) (GPIOA_BASE + GPIO_AFSEL_OFFSET))
#define GPIOA_AFSEL_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_AFSEL_OFFSET)))

/******************************************************************************************
 ************************************ 11 DRR ARRAY *********************************************
 ******************************************************************************************/
/* GPIOA DRV2*/
#define GPIOA_DRR    ((GPIODRR_ARRAY_t*) (GPIOA_BASE + GPIO_DR2R_OFFSET))

/******************************************************************************************
 ************************************ 11 DR2R *********************************************
 ******************************************************************************************/
/* GPIOA DRV2*/
#define GPIOA_DR2R    ((GPIODR2R_t*) (GPIOA_BASE + GPIO_DR2R_OFFSET))
#define GPIOA_DR2R_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_DR2R_OFFSET)))

/******************************************************************************************
 ************************************ 12 DR4R *********************************************
 ******************************************************************************************/
/* GPIOA DRV4*/
#define GPIOA_DR4R    ((GPIODR4R_t*) (GPIOA_BASE + GPIO_DR4R_OFFSET))
#define GPIOA_DR4R_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_DR4R_OFFSET)))

/******************************************************************************************
 ************************************ 13 DR8R *********************************************
 ******************************************************************************************/
/* GPIOA DRV8*/
#define GPIOA_DR8R    ((GPIODR8R_t*) (GPIOA_BASE + GPIO_DR8R_OFFSET))
#define GPIOA_DR8R_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_DR8R_OFFSET)))

/******************************************************************************************
 ************************************ 14 ODR *********************************************
 ******************************************************************************************/
/* GPIOA ODE*/
#define GPIOA_ODR    ((GPIOODR_t*) (GPIOA_BASE + GPIO_ODR_OFFSET))
#define GPIOA_ODR_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_ODR_OFFSET)))

/******************************************************************************************
 ************************************ 15 PUR *********************************************
 ******************************************************************************************/
/* GPIOA PUE*/
#define GPIOA_PUR    ((GPIOPUR_t*) (GPIOA_BASE + GPIO_PUR_OFFSET))
#define GPIOA_PUR_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_PUR_OFFSET)))

/******************************************************************************************
 ************************************ 16 PDR *********************************************
 ******************************************************************************************/
/* GPIOA PDE*/
#define GPIOA_PDR    ((GPIOPDR_t*) (GPIOA_BASE + GPIO_PDR_OFFSET))
#define GPIOA_PDR_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_PDR_OFFSET)))

/******************************************************************************************
 ************************************ 17 SLR *********************************************
 ******************************************************************************************/
/* GPIOA SLR*/
#define GPIOA_SLR    ((GPIOSLR_t*) (GPIOA_BASE + GPIO_SLR_OFFSET))
#define GPIOA_SLR_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_SLR_OFFSET)))

/******************************************************************************************
 ************************************ 18 DEN *********************************************
 ******************************************************************************************/
/* GPIOA DEN*/
#define GPIOA_DEN    ((GPIODEN_t*) (GPIOA_BASE + GPIO_DEN_OFFSET))
#define GPIOA_DEN_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_DEN_OFFSET)))

/******************************************************************************************
 ************************************ 19 LOCK *********************************************
 ******************************************************************************************/
/* GPIOA LOCK*/
#define GPIOA_LOCK    ((GPIOLOCK_t*) (GPIOA_BASE + GPIO_LOCK_OFFSET))
#define GPIOA_LOCK_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_LOCK_OFFSET)))

/******************************************************************************************
 ************************************ 20 CR *********************************************
 ******************************************************************************************/
/* GPIOA CR*/
#define GPIOA_CR    ((GPIOCR_t*) (GPIOA_BASE + GPIO_CR_OFFSET))
#define GPIOA_CR_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_CR_OFFSET)))

/******************************************************************************************
 ************************************ 21 AMSEL *********************************************
 ******************************************************************************************/
/* GPIOA AMSEL*/
#define GPIOA_AMSEL    ((GPIOAMSEL_t*) (GPIOA_BASE + GPIO_AMSEL_OFFSET))
#define GPIOA_AMSEL_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_AMSEL_OFFSET)))

/******************************************************************************************
 ************************************ 22 PCTL *********************************************
 ******************************************************************************************/
/* GPIOA PCTL*/
#define GPIOA_PCTL    ((GPIOPCTL_t*) (GPIOA_BASE + GPIO_PCTL_OFFSET))
#define GPIOA_PCTL_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_PCTL_OFFSET)))

/******************************************************************************************
 ************************************ 23 ADCCTL *********************************************
 ******************************************************************************************/
/* GPIOA ADCCTL*/
#define GPIOA_ADCCTL    ((GPIOADCCTL_t*) (GPIOA_BASE + GPIO_ADCCTL_OFFSET))
#define GPIOA_ADCCTL_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_ADCCTL_OFFSET)))

/******************************************************************************************
 ************************************ 24 DMACTL *********************************************
 ******************************************************************************************/
/* GPIOA DMACTL*/
#define GPIOA_DMACTL    ((GPIODMACTL_t*) (GPIOA_BASE + GPIO_DMACTL_OFFSET))
#define GPIOA_DMACTL_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_DMACTL_OFFSET)))

/******************************************************************************************
 ************************************ 25 SI *********************************************
 ******************************************************************************************/
/* GPIOA SI*/
#define GPIOA_SI    ((GPIOSI_t*) (GPIOA_BASE + GPIO_SI_OFFSET))
#define GPIOA_SI_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_SI_OFFSET)))

/******************************************************************************************
 ************************************ 26 DR12R *********************************************
 ******************************************************************************************/
/* GPIOA DR12R*/
#define GPIOA_DR12R    ((GPIODR12R_t*) (GPIOA_BASE + GPIO_DR12R_OFFSET))
#define GPIOA_DR12R_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_DR12R_OFFSET)))

/******************************************************************************************
 ************************************ 27 WAKEPEN *********************************************
 ******************************************************************************************/
/* GPIOA WAKEPEN*/
#define GPIOA_WAKEPEN    ((GPIOWAKEPEN_t*) (GPIOA_BASE + GPIO_WAKEPEN_OFFSET))
#define GPIOA_WAKEPEN_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_WAKEPEN_OFFSET)))

/******************************************************************************************
 ************************************ 28 WAKELVL *********************************************
 ******************************************************************************************/
/* GPIOA WAKELVL*/
#define GPIOA_WAKELVL    ((GPIOWAKELVL_t*) (GPIOA_BASE + GPIO_WAKELVL_OFFSET))
#define GPIOA_WAKELVL_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_WAKELVL_OFFSET)))

/******************************************************************************************
 ************************************ 29 WAKESTAT *********************************************
 ******************************************************************************************/
/* GPIOA WAKESTAT*/
#define GPIOA_WAKESTAT    ((GPIOWAKESTAT_t*) (GPIOA_BASE + GPIO_WAKESTAT_OFFSET))
#define GPIOA_WAKESTAT_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_WAKESTAT_OFFSET)))

/******************************************************************************************
 ************************************ 30 PP *********************************************
 ******************************************************************************************/
/* GPIOA PP*/
#define GPIOA_PP    ((GPIOPP_t*) (GPIOA_BASE + GPIO_PP_OFFSET))
#define GPIOA_PP_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_PP_OFFSET)))

/******************************************************************************************
 ************************************ 31 PC *********************************************
 ******************************************************************************************/
/* GPIOA PC*/
#define GPIOA_PC    ((GPIOPC_t*) (GPIOA_BASE + GPIO_PC_OFFSET))
#define GPIOA_PC_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_PC_OFFSET)))

/******************************************************************************************
 ************************************ 32 PeriphID4 *********************************************
 ******************************************************************************************/
/* GPIOA PID4*/
#define GPIOA_PeriphID4    ((GPIOPeriphID4_t*) (GPIOA_BASE + GPIO_PeriphID4_OFFSET))
#define GPIOA_PeriphID4_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_PeriphID4_OFFSET)))

/******************************************************************************************
 ************************************ 33 PeriphID5 *********************************************
 ******************************************************************************************/
/* GPIOA PID5*/
#define GPIOA_PeriphID5    ((GPIOPeriphID5_t*) (GPIOA_BASE + GPIO_PeriphID5_OFFSET))
#define GPIOA_PeriphID5_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_PeriphID5_OFFSET)))

/******************************************************************************************
 ************************************ 34 PeriphID6 *********************************************
 ******************************************************************************************/
/* GPIOA PID6*/
#define GPIOA_PeriphID6    ((GPIOPeriphID6_t*) (GPIOA_BASE + GPIO_PeriphID6_OFFSET))
#define GPIOA_PeriphID6_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_PeriphID6_OFFSET)))

/******************************************************************************************
 ************************************ 35 PeriphID7 *********************************************
 ******************************************************************************************/
/* GPIOA PID7*/
#define GPIOA_PeriphID7    ((GPIOPeriphID7_t*) (GPIOA_BASE + GPIO_PeriphID7_OFFSET))
#define GPIOA_PeriphID7_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_PeriphID7_OFFSET)))

/******************************************************************************************
 ************************************ 36 PeriphID0 *********************************************
 ******************************************************************************************/
/* GPIOA PID0*/
#define GPIOA_PeriphID0    ((GPIOPeriphID0_t*) (GPIOA_BASE + GPIO_PeriphID0_OFFSET))
#define GPIOA_PeriphID0_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_PeriphID0_OFFSET)))

/******************************************************************************************
 ************************************ 37 PeriphID1 *********************************************
 ******************************************************************************************/
/* GPIOA PID1*/
#define GPIOA_PeriphID1    ((GPIOPeriphID1_t*) (GPIOA_BASE + GPIO_PeriphID1_OFFSET))
#define GPIOA_PeriphID1_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_PeriphID1_OFFSET)))

/******************************************************************************************
 ************************************ 38 PeriphID2 *********************************************
 ******************************************************************************************/
/* GPIOA PID2*/
#define GPIOA_PeriphID2    ((GPIOPeriphID2_t*) (GPIOA_BASE + GPIO_PeriphID2_OFFSET))
#define GPIOA_PeriphID2_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_PeriphID2_OFFSET)))

/******************************************************************************************
 ************************************ 39 PeriphID3 *********************************************
 ******************************************************************************************/
/* GPIOA PID3*/
#define GPIOA_PeriphID3    ((GPIOPeriphID3_t*) (GPIOA_BASE + GPIO_PeriphID3_OFFSET))
#define GPIOA_PeriphID3_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_PeriphID3_OFFSET)))

/******************************************************************************************
 ************************************ 40 CellID0 *********************************************
 ******************************************************************************************/
/* GPIOA CID0*/
#define GPIOA_CellID0    ((GPIOCellID0_t*) (GPIOA_BASE + GPIO_CellID0_OFFSET))
#define GPIOA_CellID0_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_CellID0_OFFSET)))

/******************************************************************************************
 ************************************ 41 CellID1 *********************************************
 ******************************************************************************************/
/* GPIOA CID1*/
#define GPIOA_CellID1    ((GPIOCellID1_t*) (GPIOA_BASE + GPIO_CellID1_OFFSET))
#define GPIOA_CellID1_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_CellID1_OFFSET)))

/******************************************************************************************
 ************************************ 42 CellID2 *********************************************
 ******************************************************************************************/
/* GPIOA CID2*/
#define GPIOA_CellID2    ((GPIOCellID2_t*) (GPIOA_BASE + GPIO_CellID2_OFFSET))
#define GPIOA_CellID2_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_CellID2_OFFSET)))

/******************************************************************************************
 ************************************ 43 CellID3 *********************************************
 ******************************************************************************************/
/* GPIOA CID3*/
#define GPIOA_CellID3    ((GPIOCellID3_t*) (GPIOA_BASE + GPIO_CellID3_OFFSET))
#define GPIOA_CellID3_R    (*((volatile uint32_t *) (GPIOA_BASE + GPIO_CellID3_OFFSET)))

#endif /* XDRIVER_MCU_GPIO_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_GPIO_REGISTERPERIPHERAL_MODULEA_H_ */
