/**
 *
 * @file GPIO_RegisterPeripheral_ModuleD.h
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

#ifndef XDRIVER_MCU_GPIO_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_GPIO_REGISTERPERIPHERAL_MODULED_H_
#define XDRIVER_MCU_GPIO_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_GPIO_REGISTERPERIPHERAL_MODULED_H_

#include <xDriver_MCU/GPIO/Peripheral/Register/xHeader/GPIO_RegisterAddress.h>
#include <xDriver_MCU/GPIO/Peripheral/Struct/xHeader/GPIO_StructPeripheral.h>

#define GPIOD    ((GPIO_t*) (GPIOD_BASE))
#define GPIOD_AUX    ((GPIO_AUX_t*) (GPIOD_BASE))

/******************************************************************************************
 ************************************ 1 DATA *********************************************
 ******************************************************************************************/
/* GPIOD DATA*/
#define GPIOD_DATA_MASK    ((GPIO_DATA_MASK_t*) (GPIOD_BASE + GPIO_DATA_MASK_OFFSET))
#define GPIOD_DATA_PINMASK0_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_DATA_PINMASK0_OFFSET )))
#define GPIOD_DATA_PINMASK1_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_DATA_PINMASK1_OFFSET )))
#define GPIOD_DATA_PINMASK2_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_DATA_PINMASK2_OFFSET )))
#define GPIOD_DATA_PINMASK3_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_DATA_PINMASK3_OFFSET )))
#define GPIOD_DATA_PINMASK4_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_DATA_PINMASK4_OFFSET )))
#define GPIOD_DATA_PINMASK5_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_DATA_PINMASK5_OFFSET )))
#define GPIOD_DATA_PINMASK6_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_DATA_PINMASK6_OFFSET )))
#define GPIOD_DATA_PINMASK7_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_DATA_PINMASK7_OFFSET )))

#define GPIOD_DATA    ((GPIO_DATA_t*) (GPIOD_BASE + GPIO_DATA_OFFSET))
#define GPIOD_DATA_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_DATA_OFFSET)))

/******************************************************************************************
 ************************************ 2 DIR *********************************************
 ******************************************************************************************/
/* GPIOD DIR*/
#define GPIOD_DIR    ((GPIO_DIR_t*) (GPIOD_BASE + GPIO_DIR_OFFSET))
#define GPIOD_DIR_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_DIR_OFFSET)))

/******************************************************************************************
 ************************************ 3 IS *********************************************
 ******************************************************************************************/
/* GPIOD IS*/
#define GPIOD_IS    ((GPIO_IS_t*) (GPIOD_BASE + GPIO_IS_OFFSET))
#define GPIOD_IS_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_IS_OFFSET)))

/******************************************************************************************
 ************************************ 4 IBE *********************************************
 ******************************************************************************************/
/* GPIOD IBE*/
#define GPIOD_IBE    ((GPIO_IBE_t*) (GPIOD_BASE + GPIO_IBE_OFFSET))
#define GPIOD_IBE_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_IBE_OFFSET)))

/******************************************************************************************
 ************************************ 5 IEV *********************************************
 ******************************************************************************************/
/* GPIOD IEV*/
#define GPIOD_IEV    ((GPIO_IEV_t*) (GPIOD_BASE + GPIO_IEV_OFFSET))
#define GPIOD_IEV_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_IEV_OFFSET)))

/******************************************************************************************
 ************************************ 6 IM *********************************************
 ******************************************************************************************/
/* GPIOD IME*/
#define GPIOD_IM    ((GPIO_IM_t*) (GPIOD_BASE + GPIO_IM_OFFSET))
#define GPIOD_IM_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_IM_OFFSET)))

/******************************************************************************************
 ************************************ 7 RIS *********************************************
 ******************************************************************************************/
/* GPIOD RIS*/
#define GPIOD_RIS    ((GPIO_RIS_t*) (GPIOD_BASE + GPIO_RIS_OFFSET))
#define GPIOD_RIS_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_RIS_OFFSET)))

/******************************************************************************************
 ************************************ 8 MIS *********************************************
 ******************************************************************************************/
/* GPIOD MIS*/
#define GPIOD_MIS    ((GPIO_MIS_t*) (GPIOD_BASE + GPIO_MIS_OFFSET))
#define GPIOD_MIS_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_MIS_OFFSET)))

/******************************************************************************************
 ************************************ 9 ICR *********************************************
 ******************************************************************************************/
/* GPIOD IC*/
#define GPIOD_ICR    ((GPIO_ICR_t*) (GPIOD_BASE + GPIO_ICR_OFFSET))
#define GPIOD_ICR_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_ICR_OFFSET)))

/******************************************************************************************
 ************************************ 10 AFSEL *********************************************
 ******************************************************************************************/
/* GPIOD AFSEL*/
#define GPIOD_AFSEL    ((GPIO_AFSEL_t*) (GPIOD_BASE + GPIO_AFSEL_OFFSET))
#define GPIOD_AFSEL_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_AFSEL_OFFSET)))

/******************************************************************************************
 ************************************ 11 DRR ARRAY *********************************************
 ******************************************************************************************/
/* GPIOD DRV2*/
#define GPIOD_DRR    ((GPIO_DRR_ARRAY_t*) (GPIOD_BASE + GPIO_DR2R_OFFSET))

/******************************************************************************************
 ************************************ 11 DR2R *********************************************
 ******************************************************************************************/
/* GPIOD DRV2*/
#define GPIOD_DR2R    ((GPIO_DR2R_t*) (GPIOD_BASE + GPIO_DR2R_OFFSET))
#define GPIOD_DR2R_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_DR2R_OFFSET)))

/******************************************************************************************
 ************************************ 12 DR4R *********************************************
 ******************************************************************************************/
/* GPIOD DRV4*/
#define GPIOD_DR4R    ((GPIO_DR4R_t*) (GPIOD_BASE + GPIO_DR4R_OFFSET))
#define GPIOD_DR4R_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_DR4R_OFFSET)))

/******************************************************************************************
 ************************************ 13 DR8R *********************************************
 ******************************************************************************************/
/* GPIOD DRV8*/
#define GPIOD_DR8R    ((GPIO_DR8R_t*) (GPIOD_BASE + GPIO_DR8R_OFFSET))
#define GPIOD_DR8R_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_DR8R_OFFSET)))

/******************************************************************************************
 ************************************ 14 ODR *********************************************
 ******************************************************************************************/
/* GPIOD ODE*/
#define GPIOD_ODR    ((GPIO_ODR_t*) (GPIOD_BASE + GPIO_ODR_OFFSET))
#define GPIOD_ODR_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_ODR_OFFSET)))

/******************************************************************************************
 ************************************ 15 PUR *********************************************
 ******************************************************************************************/
/* GPIOD PUE*/
#define GPIOD_PUR    ((GPIO_PUR_t*) (GPIOD_BASE + GPIO_PUR_OFFSET))
#define GPIOD_PUR_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_PUR_OFFSET)))

/******************************************************************************************
 ************************************ 16 PDR *********************************************
 ******************************************************************************************/
/* GPIOD PDE*/
#define GPIOD_PDR    ((GPIO_PDR_t*) (GPIOD_BASE + GPIO_PDR_OFFSET))
#define GPIOD_PDR_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_PDR_OFFSET)))

/******************************************************************************************
 ************************************ 17 SLR *********************************************
 ******************************************************************************************/
/* GPIOD SLR*/
#define GPIOD_SLR    ((GPIO_SLR_t*) (GPIOD_BASE + GPIO_SLR_OFFSET))
#define GPIOD_SLR_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_SLR_OFFSET)))

/******************************************************************************************
 ************************************ 18 DEN *********************************************
 ******************************************************************************************/
/* GPIOD DEN*/
#define GPIOD_DEN    ((GPIO_DEN_t*) (GPIOD_BASE + GPIO_DEN_OFFSET))
#define GPIOD_DEN_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_DEN_OFFSET)))

/******************************************************************************************
 ************************************ 19 LOCK *********************************************
 ******************************************************************************************/
/* GPIOD LOCK*/
#define GPIOD_LOCK    ((GPIO_LOCK_t*) (GPIOD_BASE + GPIO_LOCK_OFFSET))
#define GPIOD_LOCK_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_LOCK_OFFSET)))

/******************************************************************************************
 ************************************ 20 CR *********************************************
 ******************************************************************************************/
/* GPIOD CR*/
#define GPIOD_CR    ((GPIO_CR_t*) (GPIOD_BASE + GPIO_CR_OFFSET))
#define GPIOD_CR_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_CR_OFFSET)))

/******************************************************************************************
 ************************************ 21 AMSEL *********************************************
 ******************************************************************************************/
/* GPIOD AMSEL*/
#define GPIOD_AMSEL    ((GPIO_AMSEL_t*) (GPIOD_BASE + GPIO_AMSEL_OFFSET))
#define GPIOD_AMSEL_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_AMSEL_OFFSET)))

/******************************************************************************************
 ************************************ 22 PCTL *********************************************
 ******************************************************************************************/
/* GPIOD PCTL*/
#define GPIOD_PCTL    ((GPIO_PCTL_t*) (GPIOD_BASE + GPIO_PCTL_OFFSET))
#define GPIOD_PCTL_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_PCTL_OFFSET)))

/******************************************************************************************
 ************************************ 23 ADCCTL *********************************************
 ******************************************************************************************/
/* GPIOD ADCCTL*/
#define GPIOD_ADCCTL    ((GPIO_ADCCTL_t*) (GPIOD_BASE + GPIO_ADCCTL_OFFSET))
#define GPIOD_ADCCTL_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_ADCCTL_OFFSET)))

/******************************************************************************************
 ************************************ 24 DMACTL *********************************************
 ******************************************************************************************/
/* GPIOD DMACTL*/
#define GPIOD_DMACTL    ((GPIO_DMACTL_t*) (GPIOD_BASE + GPIO_DMACTL_OFFSET))
#define GPIOD_DMACTL_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_DMACTL_OFFSET)))

/******************************************************************************************
 ************************************ 25 SI *********************************************
 ******************************************************************************************/
/* GPIOD SI*/
#define GPIOD_SI    ((GPIO_SI_t*) (GPIOD_BASE + GPIO_SI_OFFSET))
#define GPIOD_SI_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_SI_OFFSET)))

/******************************************************************************************
 ************************************ 26 DR12R *********************************************
 ******************************************************************************************/
/* GPIOD DR12R*/
#define GPIOD_DR12R    ((GPIO_DR12R_t*) (GPIOD_BASE + GPIO_DR12R_OFFSET))
#define GPIOD_DR12R_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_DR12R_OFFSET)))

/******************************************************************************************
 ************************************ 27 WAKEPEN *********************************************
 ******************************************************************************************/
/* GPIOD WAKEPEN*/
#define GPIOD_WAKEPEN    ((GPIO_WAKEPEN_t*) (GPIOD_BASE + GPIO_WAKEPEN_OFFSET))
#define GPIOD_WAKEPEN_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_WAKEPEN_OFFSET)))

/******************************************************************************************
 ************************************ 28 WAKELVL *********************************************
 ******************************************************************************************/
/* GPIOD WAKELVL*/
#define GPIOD_WAKELVL    ((GPIO_WAKELVL_t*) (GPIOD_BASE + GPIO_WAKELVL_OFFSET))
#define GPIOD_WAKELVL_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_WAKELVL_OFFSET)))

/******************************************************************************************
 ************************************ 29 WAKESTAT *********************************************
 ******************************************************************************************/
/* GPIOD WAKESTAT*/
#define GPIOD_WAKESTAT    ((GPIO_WAKESTAT_t*) (GPIOD_BASE + GPIO_WAKESTAT_OFFSET))
#define GPIOD_WAKESTAT_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_WAKESTAT_OFFSET)))

/******************************************************************************************
 ************************************ 30 PP *********************************************
 ******************************************************************************************/
/* GPIOD PP*/
#define GPIOD_PP    ((GPIO_PP_t*) (GPIOD_BASE + GPIO_PP_OFFSET))
#define GPIOD_PP_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_PP_OFFSET)))

/******************************************************************************************
 ************************************ 31 PC *********************************************
 ******************************************************************************************/
/* GPIOD PC*/
#define GPIOD_PC    ((GPIO_PC_t*) (GPIOD_BASE + GPIO_PC_OFFSET))
#define GPIOD_PC_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_PC_OFFSET)))

/******************************************************************************************
 ************************************ 32 PeriphID4 *********************************************
 ******************************************************************************************/
/* GPIOD PID4*/
#define GPIOD_PeriphID4    ((GPIO_PeriphID4_t*) (GPIOD_BASE + GPIO_PeriphID4_OFFSET))
#define GPIOD_PeriphID4_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_PeriphID4_OFFSET)))

/******************************************************************************************
 ************************************ 33 PeriphID5 *********************************************
 ******************************************************************************************/
/* GPIOD PID5*/
#define GPIOD_PeriphID5    ((GPIO_PeriphID5_t*) (GPIOD_BASE + GPIO_PeriphID5_OFFSET))
#define GPIOD_PeriphID5_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_PeriphID5_OFFSET)))

/******************************************************************************************
 ************************************ 34 PeriphID6 *********************************************
 ******************************************************************************************/
/* GPIOD PID6*/
#define GPIOD_PeriphID6    ((GPIO_PeriphID6_t*) (GPIOD_BASE + GPIO_PeriphID6_OFFSET))
#define GPIOD_PeriphID6_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_PeriphID6_OFFSET)))

/******************************************************************************************
 ************************************ 35 PeriphID7 *********************************************
 ******************************************************************************************/
/* GPIOD PID7*/
#define GPIOD_PeriphID7    ((GPIO_PeriphID7_t*) (GPIOD_BASE + GPIO_PeriphID7_OFFSET))
#define GPIOD_PeriphID7_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_PeriphID7_OFFSET)))

/******************************************************************************************
 ************************************ 36 PeriphID0 *********************************************
 ******************************************************************************************/
/* GPIOD PID0*/
#define GPIOD_PeriphID0    ((GPIO_PeriphID0_t*) (GPIOD_BASE + GPIO_PeriphID0_OFFSET))
#define GPIOD_PeriphID0_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_PeriphID0_OFFSET)))

/******************************************************************************************
 ************************************ 37 PeriphID1 *********************************************
 ******************************************************************************************/
/* GPIOD PID1*/
#define GPIOD_PeriphID1    ((GPIO_PeriphID1_t*) (GPIOD_BASE + GPIO_PeriphID1_OFFSET))
#define GPIOD_PeriphID1_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_PeriphID1_OFFSET)))

/******************************************************************************************
 ************************************ 38 PeriphID2 *********************************************
 ******************************************************************************************/
/* GPIOD PID2*/
#define GPIOD_PeriphID2    ((GPIO_PeriphID2_t*) (GPIOD_BASE + GPIO_PeriphID2_OFFSET))
#define GPIOD_PeriphID2_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_PeriphID2_OFFSET)))

/******************************************************************************************
 ************************************ 39 PeriphID3 *********************************************
 ******************************************************************************************/
/* GPIOD PID3*/
#define GPIOD_PeriphID3    ((GPIO_PeriphID3_t*) (GPIOD_BASE + GPIO_PeriphID3_OFFSET))
#define GPIOD_PeriphID3_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_PeriphID3_OFFSET)))

/******************************************************************************************
 ************************************ 40 CellID0 *********************************************
 ******************************************************************************************/
/* GPIOD CID0*/
#define GPIOD_PCellID0    ((GPIO_PCellID0_t*) (GPIOD_BASE + GPIO_PCellID0_OFFSET))
#define GPIOD_PCellID0_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_PCellID0_OFFSET)))

/******************************************************************************************
 ************************************ 41 CellID1 *********************************************
 ******************************************************************************************/
/* GPIOD CID1*/
#define GPIOD_PCellID1    ((GPIO_PCellID1_t*) (GPIOD_BASE + GPIO_PCellID1_OFFSET))
#define GPIOD_PCellID1_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_PCellID1_OFFSET)))

/******************************************************************************************
 ************************************ 42 CellID2 *********************************************
 ******************************************************************************************/
/* GPIOD CID2*/
#define GPIOD_PCellID2    ((GPIO_PCellID2_t*) (GPIOD_BASE + GPIO_PCellID2_OFFSET))
#define GPIOD_PCellID2_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_PCellID2_OFFSET)))

/******************************************************************************************
 ************************************ 43 CellID3 *********************************************
 ******************************************************************************************/
/* GPIOD CID3*/
#define GPIOD_PCellID3    ((GPIO_PCellID3_t*) (GPIOD_BASE + GPIO_PCellID3_OFFSET))
#define GPIOD_PCellID3_R    (*((volatile UBase_t *) (GPIOD_BASE + GPIO_PCellID3_OFFSET)))

#endif /* XDRIVER_MCU_GPIO_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_GPIO_REGISTERPERIPHERAL_MODULED_H_ */
