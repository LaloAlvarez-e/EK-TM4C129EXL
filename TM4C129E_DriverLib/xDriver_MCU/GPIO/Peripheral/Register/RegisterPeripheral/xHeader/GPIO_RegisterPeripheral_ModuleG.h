/**
 *
 * @file GPIO_RegisterPeripheral_ModuleG.h
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

#ifndef XDRIVER_MCU_GPIO_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_GPIO_REGISTERPERIPHERAL_MODULEG_H_
#define XDRIVER_MCU_GPIO_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_GPIO_REGISTERPERIPHERAL_MODULEG_H_

#include <xDriver_MCU/GPIO/Peripheral/Register/xHeader/GPIO_RegisterAddress.h>
#include <xDriver_MCU/GPIO/Peripheral/Struct/xHeader/GPIO_StructPeripheral.h>

#define GPIOG    ((GPIO_t*) (GPIOG_BASE))
#define GPIOG_AUX    ((GPIO_AUX_t*) (GPIOG_BASE))

/******************************************************************************************
 ************************************ 1 DATA *********************************************
 ******************************************************************************************/
/* GPIOG DATA*/
#define GPIOG_DATA_MASK    ((GPIO_DATA_MASK_t*) (GPIOG_BASE + GPIO_DATA_MASK_OFFSET))
#define GPIOG_DATA_PINMASK0_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_DATA_PINMASK0_OFFSET )))
#define GPIOG_DATA_PINMASK1_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_DATA_PINMASK1_OFFSET )))
#define GPIOG_DATA_PINMASK2_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_DATA_PINMASK2_OFFSET )))
#define GPIOG_DATA_PINMASK3_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_DATA_PINMASK3_OFFSET )))
#define GPIOG_DATA_PINMASK4_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_DATA_PINMASK4_OFFSET )))
#define GPIOG_DATA_PINMASK5_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_DATA_PINMASK5_OFFSET )))
#define GPIOG_DATA_PINMASK6_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_DATA_PINMASK6_OFFSET )))
#define GPIOG_DATA_PINMASK7_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_DATA_PINMASK7_OFFSET )))

#define GPIOG_DATA    ((GPIO_DATA_t*) (GPIOG_BASE + GPIO_DATA_OFFSET))
#define GPIOG_DATA_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_DATA_OFFSET)))

/******************************************************************************************
 ************************************ 2 DIR *********************************************
 ******************************************************************************************/
/* GPIOG DIR*/
#define GPIOG_DIR    ((GPIO_DIR_t*) (GPIOG_BASE + GPIO_DIR_OFFSET))
#define GPIOG_DIR_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_DIR_OFFSET)))

/******************************************************************************************
 ************************************ 3 IS *********************************************
 ******************************************************************************************/
/* GPIOG IS*/
#define GPIOG_IS    ((GPIO_IS_t*) (GPIOG_BASE + GPIO_IS_OFFSET))
#define GPIOG_IS_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_IS_OFFSET)))

/******************************************************************************************
 ************************************ 4 IBE *********************************************
 ******************************************************************************************/
/* GPIOG IBE*/
#define GPIOG_IBE    ((GPIO_IBE_t*) (GPIOG_BASE + GPIO_IBE_OFFSET))
#define GPIOG_IBE_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_IBE_OFFSET)))

/******************************************************************************************
 ************************************ 5 IEV *********************************************
 ******************************************************************************************/
/* GPIOG IEV*/
#define GPIOG_IEV    ((GPIO_IEV_t*) (GPIOG_BASE + GPIO_IEV_OFFSET))
#define GPIOG_IEV_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_IEV_OFFSET)))

/******************************************************************************************
 ************************************ 6 IM *********************************************
 ******************************************************************************************/
/* GPIOG IME*/
#define GPIOG_IM    ((GPIO_IM_t*) (GPIOG_BASE + GPIO_IM_OFFSET))
#define GPIOG_IM_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_IM_OFFSET)))

/******************************************************************************************
 ************************************ 7 RIS *********************************************
 ******************************************************************************************/
/* GPIOG RIS*/
#define GPIOG_RIS    ((GPIO_RIS_t*) (GPIOG_BASE + GPIO_RIS_OFFSET))
#define GPIOG_RIS_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_RIS_OFFSET)))

/******************************************************************************************
 ************************************ 8 MIS *********************************************
 ******************************************************************************************/
/* GPIOG MIS*/
#define GPIOG_MIS    ((GPIO_MIS_t*) (GPIOG_BASE + GPIO_MIS_OFFSET))
#define GPIOG_MIS_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_MIS_OFFSET)))

/******************************************************************************************
 ************************************ 9 ICR *********************************************
 ******************************************************************************************/
/* GPIOG IC*/
#define GPIOG_ICR    ((GPIO_ICR_t*) (GPIOG_BASE + GPIO_ICR_OFFSET))
#define GPIOG_ICR_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_ICR_OFFSET)))

/******************************************************************************************
 ************************************ 10 AFSEL *********************************************
 ******************************************************************************************/
/* GPIOG AFSEL*/
#define GPIOG_AFSEL    ((GPIO_AFSEL_t*) (GPIOG_BASE + GPIO_AFSEL_OFFSET))
#define GPIOG_AFSEL_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_AFSEL_OFFSET)))

/******************************************************************************************
 ************************************ 11 DRR ARRAY *********************************************
 ******************************************************************************************/
/* GPIOG DRV2*/
#define GPIOG_DRR    ((GPIO_DRR_ARRAY_t*) (GPIOG_BASE + GPIO_DR2R_OFFSET))

/******************************************************************************************
 ************************************ 11 DR2R *********************************************
 ******************************************************************************************/
/* GPIOG DRV2*/
#define GPIOG_DR2R    ((GPIO_DR2R_t*) (GPIOG_BASE + GPIO_DR2R_OFFSET))
#define GPIOG_DR2R_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_DR2R_OFFSET)))

/******************************************************************************************
 ************************************ 12 DR4R *********************************************
 ******************************************************************************************/
/* GPIOG DRV4*/
#define GPIOG_DR4R    ((GPIO_DR4R_t*) (GPIOG_BASE + GPIO_DR4R_OFFSET))
#define GPIOG_DR4R_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_DR4R_OFFSET)))

/******************************************************************************************
 ************************************ 13 DR8R *********************************************
 ******************************************************************************************/
/* GPIOG DRV8*/
#define GPIOG_DR8R    ((GPIO_DR8R_t*) (GPIOG_BASE + GPIO_DR8R_OFFSET))
#define GPIOG_DR8R_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_DR8R_OFFSET)))

/******************************************************************************************
 ************************************ 14 ODR *********************************************
 ******************************************************************************************/
/* GPIOG ODE*/
#define GPIOG_ODR    ((GPIO_ODR_t*) (GPIOG_BASE + GPIO_ODR_OFFSET))
#define GPIOG_ODR_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_ODR_OFFSET)))

/******************************************************************************************
 ************************************ 15 PUR *********************************************
 ******************************************************************************************/
/* GPIOG PUE*/
#define GPIOG_PUR    ((GPIO_PUR_t*) (GPIOG_BASE + GPIO_PUR_OFFSET))
#define GPIOG_PUR_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_PUR_OFFSET)))

/******************************************************************************************
 ************************************ 16 PDR *********************************************
 ******************************************************************************************/
/* GPIOG PDE*/
#define GPIOG_PDR    ((GPIO_PDR_t*) (GPIOG_BASE + GPIO_PDR_OFFSET))
#define GPIOG_PDR_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_PDR_OFFSET)))

/******************************************************************************************
 ************************************ 17 SLR *********************************************
 ******************************************************************************************/
/* GPIOG SLR*/
#define GPIOG_SLR    ((GPIO_SLR_t*) (GPIOG_BASE + GPIO_SLR_OFFSET))
#define GPIOG_SLR_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_SLR_OFFSET)))

/******************************************************************************************
 ************************************ 18 DEN *********************************************
 ******************************************************************************************/
/* GPIOG DEN*/
#define GPIOG_DEN    ((GPIO_DEN_t*) (GPIOG_BASE + GPIO_DEN_OFFSET))
#define GPIOG_DEN_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_DEN_OFFSET)))

/******************************************************************************************
 ************************************ 19 LOCK *********************************************
 ******************************************************************************************/
/* GPIOG LOCK*/
#define GPIOG_LOCK    ((GPIO_LOCK_t*) (GPIOG_BASE + GPIO_LOCK_OFFSET))
#define GPIOG_LOCK_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_LOCK_OFFSET)))

/******************************************************************************************
 ************************************ 20 CR *********************************************
 ******************************************************************************************/
/* GPIOG CR*/
#define GPIOG_CR    ((GPIO_CR_t*) (GPIOG_BASE + GPIO_CR_OFFSET))
#define GPIOG_CR_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_CR_OFFSET)))

/******************************************************************************************
 ************************************ 21 AMSEL *********************************************
 ******************************************************************************************/
/* GPIOG AMSEL*/
#define GPIOG_AMSEL    ((GPIO_AMSEL_t*) (GPIOG_BASE + GPIO_AMSEL_OFFSET))
#define GPIOG_AMSEL_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_AMSEL_OFFSET)))

/******************************************************************************************
 ************************************ 22 PCTL *********************************************
 ******************************************************************************************/
/* GPIOG PCTL*/
#define GPIOG_PCTL    ((GPIO_PCTL_t*) (GPIOG_BASE + GPIO_PCTL_OFFSET))
#define GPIOG_PCTL_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_PCTL_OFFSET)))

/******************************************************************************************
 ************************************ 23 ADCCTL *********************************************
 ******************************************************************************************/
/* GPIOG ADCCTL*/
#define GPIOG_ADCCTL    ((GPIO_ADCCTL_t*) (GPIOG_BASE + GPIO_ADCCTL_OFFSET))
#define GPIOG_ADCCTL_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_ADCCTL_OFFSET)))

/******************************************************************************************
 ************************************ 24 DMACTL *********************************************
 ******************************************************************************************/
/* GPIOG DMACTL*/
#define GPIOG_DMACTL    ((GPIO_DMACTL_t*) (GPIOG_BASE + GPIO_DMACTL_OFFSET))
#define GPIOG_DMACTL_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_DMACTL_OFFSET)))

/******************************************************************************************
 ************************************ 25 SI *********************************************
 ******************************************************************************************/
/* GPIOG SI*/
#define GPIOG_SI    ((GPIO_SI_t*) (GPIOG_BASE + GPIO_SI_OFFSET))
#define GPIOG_SI_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_SI_OFFSET)))

/******************************************************************************************
 ************************************ 26 DR12R *********************************************
 ******************************************************************************************/
/* GPIOG DR12R*/
#define GPIOG_DR12R    ((GPIO_DR12R_t*) (GPIOG_BASE + GPIO_DR12R_OFFSET))
#define GPIOG_DR12R_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_DR12R_OFFSET)))

/******************************************************************************************
 ************************************ 27 WAKEPEN *********************************************
 ******************************************************************************************/
/* GPIOG WAKEPEN*/
#define GPIOG_WAKEPEN    ((GPIO_WAKEPEN_t*) (GPIOG_BASE + GPIO_WAKEPEN_OFFSET))
#define GPIOG_WAKEPEN_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_WAKEPEN_OFFSET)))

/******************************************************************************************
 ************************************ 28 WAKELVL *********************************************
 ******************************************************************************************/
/* GPIOG WAKELVL*/
#define GPIOG_WAKELVL    ((GPIO_WAKELVL_t*) (GPIOG_BASE + GPIO_WAKELVL_OFFSET))
#define GPIOG_WAKELVL_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_WAKELVL_OFFSET)))

/******************************************************************************************
 ************************************ 29 WAKESTAT *********************************************
 ******************************************************************************************/
/* GPIOG WAKESTAT*/
#define GPIOG_WAKESTAT    ((GPIO_WAKESTAT_t*) (GPIOG_BASE + GPIO_WAKESTAT_OFFSET))
#define GPIOG_WAKESTAT_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_WAKESTAT_OFFSET)))

/******************************************************************************************
 ************************************ 30 PP *********************************************
 ******************************************************************************************/
/* GPIOG PP*/
#define GPIOG_PP    ((GPIO_PP_t*) (GPIOG_BASE + GPIO_PP_OFFSET))
#define GPIOG_PP_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_PP_OFFSET)))

/******************************************************************************************
 ************************************ 31 PC *********************************************
 ******************************************************************************************/
/* GPIOG PC*/
#define GPIOG_PC    ((GPIO_PC_t*) (GPIOG_BASE + GPIO_PC_OFFSET))
#define GPIOG_PC_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_PC_OFFSET)))

/******************************************************************************************
 ************************************ 32 PeriphID4 *********************************************
 ******************************************************************************************/
/* GPIOG PID4*/
#define GPIOG_PeriphID4    ((GPIO_PeriphID4_t*) (GPIOG_BASE + GPIO_PeriphID4_OFFSET))
#define GPIOG_PeriphID4_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_PeriphID4_OFFSET)))

/******************************************************************************************
 ************************************ 33 PeriphID5 *********************************************
 ******************************************************************************************/
/* GPIOG PID5*/
#define GPIOG_PeriphID5    ((GPIO_PeriphID5_t*) (GPIOG_BASE + GPIO_PeriphID5_OFFSET))
#define GPIOG_PeriphID5_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_PeriphID5_OFFSET)))

/******************************************************************************************
 ************************************ 34 PeriphID6 *********************************************
 ******************************************************************************************/
/* GPIOG PID6*/
#define GPIOG_PeriphID6    ((GPIO_PeriphID6_t*) (GPIOG_BASE + GPIO_PeriphID6_OFFSET))
#define GPIOG_PeriphID6_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_PeriphID6_OFFSET)))

/******************************************************************************************
 ************************************ 35 PeriphID7 *********************************************
 ******************************************************************************************/
/* GPIOG PID7*/
#define GPIOG_PeriphID7    ((GPIO_PeriphID7_t*) (GPIOG_BASE + GPIO_PeriphID7_OFFSET))
#define GPIOG_PeriphID7_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_PeriphID7_OFFSET)))

/******************************************************************************************
 ************************************ 36 PeriphID0 *********************************************
 ******************************************************************************************/
/* GPIOG PID0*/
#define GPIOG_PeriphID0    ((GPIO_PeriphID0_t*) (GPIOG_BASE + GPIO_PeriphID0_OFFSET))
#define GPIOG_PeriphID0_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_PeriphID0_OFFSET)))

/******************************************************************************************
 ************************************ 37 PeriphID1 *********************************************
 ******************************************************************************************/
/* GPIOG PID1*/
#define GPIOG_PeriphID1    ((GPIO_PeriphID1_t*) (GPIOG_BASE + GPIO_PeriphID1_OFFSET))
#define GPIOG_PeriphID1_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_PeriphID1_OFFSET)))

/******************************************************************************************
 ************************************ 38 PeriphID2 *********************************************
 ******************************************************************************************/
/* GPIOG PID2*/
#define GPIOG_PeriphID2    ((GPIO_PeriphID2_t*) (GPIOG_BASE + GPIO_PeriphID2_OFFSET))
#define GPIOG_PeriphID2_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_PeriphID2_OFFSET)))

/******************************************************************************************
 ************************************ 39 PeriphID3 *********************************************
 ******************************************************************************************/
/* GPIOG PID3*/
#define GPIOG_PeriphID3    ((GPIO_PeriphID3_t*) (GPIOG_BASE + GPIO_PeriphID3_OFFSET))
#define GPIOG_PeriphID3_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_PeriphID3_OFFSET)))

/******************************************************************************************
 ************************************ 40 CellID0 *********************************************
 ******************************************************************************************/
/* GPIOG CID0*/
#define GPIOG_PCellID0    ((GPIO_PCellID0_t*) (GPIOG_BASE + GPIO_PCellID0_OFFSET))
#define GPIOG_PCellID0_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_PCellID0_OFFSET)))

/******************************************************************************************
 ************************************ 41 CellID1 *********************************************
 ******************************************************************************************/
/* GPIOG CID1*/
#define GPIOG_PCellID1    ((GPIO_PCellID1_t*) (GPIOG_BASE + GPIO_PCellID1_OFFSET))
#define GPIOG_PCellID1_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_PCellID1_OFFSET)))

/******************************************************************************************
 ************************************ 42 CellID2 *********************************************
 ******************************************************************************************/
/* GPIOG CID2*/
#define GPIOG_PCellID2    ((GPIO_PCellID2_t*) (GPIOG_BASE + GPIO_PCellID2_OFFSET))
#define GPIOG_PCellID2_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_PCellID2_OFFSET)))

/******************************************************************************************
 ************************************ 43 CellID3 *********************************************
 ******************************************************************************************/
/* GPIOG CID3*/
#define GPIOG_PCellID3    ((GPIO_PCellID3_t*) (GPIOG_BASE + GPIO_PCellID3_OFFSET))
#define GPIOG_PCellID3_R    (*((volatile uint32_t *) (GPIOG_BASE + GPIO_PCellID3_OFFSET)))

#endif /* XDRIVER_MCU_GPIO_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_GPIO_REGISTERPERIPHERAL_MODULEG_H_ */
