/**
 *
 * @file GPIO_RegisterPeripheral_ModuleK.h
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

#ifndef XDRIVER_MCU_GPIO_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_GPIO_REGISTERPERIPHERAL_MODULEK_H_
#define XDRIVER_MCU_GPIO_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_GPIO_REGISTERPERIPHERAL_MODULEK_H_

#include <xDriver_MCU/GPIO/Peripheral/Register/xHeader/GPIO_RegisterAddress.h>
#include <xDriver_MCU/GPIO/Peripheral/Struct/xHeader/GPIO_StructPeripheral.h>

#define GPIOK    ((GPIO_t*) (GPIOK_BASE))
#define GPIOK_AUX    ((GPIO_AUX_t*) (GPIOK_BASE))

/******************************************************************************************
 ************************************ 1 DATA *********************************************
 ******************************************************************************************/
/* GPIOK DATA*/
#define GPIOK_DATA_MASK    ((GPIOKATA_MASK_t*) (GPIOK_BASE + GPIO_DATA_MASK_OFFSET))
#define GPIOK_DATA0_MASK_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_DATA0_MASK_OFFSET )))
#define GPIOK_DATA1_MASK_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_DATA1_MASK_OFFSET )))
#define GPIOK_DATA2_MASK_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_DATA2_MASK_OFFSET )))
#define GPIOK_DATA3_MASK_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_DATA3_MASK_OFFSET )))
#define GPIOK_DATA4_MASK_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_DATA4_MASK_OFFSET )))
#define GPIOK_DATA5_MASK_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_DATA5_MASK_OFFSET )))
#define GPIOK_DATA6_MASK_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_DATA6_MASK_OFFSET )))
#define GPIOK_DATA7_MASK_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_DATA7_MASK_OFFSET )))

#define GPIOK_DATA    ((GPIOKATA_t*) (GPIOK_BASE + GPIO_DATA_OFFSET))
#define GPIOK_DATA_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_DATA_OFFSET)))

/******************************************************************************************
 ************************************ 2 DIR *********************************************
 ******************************************************************************************/
/* GPIOK DIR*/
#define GPIOK_DIR    ((GPIOKIR_t*) (GPIOK_BASE + GPIO_DIR_OFFSET))
#define GPIOK_DIR_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_DIR_OFFSET)))

/******************************************************************************************
 ************************************ 3 IS *********************************************
 ******************************************************************************************/
/* GPIOK IS*/
#define GPIOK_IS    ((GPIOIS_t*) (GPIOK_BASE + GPIO_IS_OFFSET))
#define GPIOK_IS_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_IS_OFFSET)))

/******************************************************************************************
 ************************************ 4 IBE *********************************************
 ******************************************************************************************/
/* GPIOK IBE*/
#define GPIOK_IBE    ((GPIOIBE_t*) (GPIOK_BASE + GPIO_IBE_OFFSET))
#define GPIOK_IBE_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_IBE_OFFSET)))

/******************************************************************************************
 ************************************ 5 IEV *********************************************
 ******************************************************************************************/
/* GPIOK IEV*/
#define GPIOK_IEV    ((GPIOIEV_t*) (GPIOK_BASE + GPIO_IEV_OFFSET))
#define GPIOK_IEV_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_IEV_OFFSET)))

/******************************************************************************************
 ************************************ 6 IM *********************************************
 ******************************************************************************************/
/* GPIOK IME*/
#define GPIOK_IM    ((GPIOIM_t*) (GPIOK_BASE + GPIO_IM_OFFSET))
#define GPIOK_IM_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_IM_OFFSET)))

/******************************************************************************************
 ************************************ 7 RIS *********************************************
 ******************************************************************************************/
/* GPIOK RIS*/
#define GPIOK_RIS    ((GPIORIS_t*) (GPIOK_BASE + GPIO_RIS_OFFSET))
#define GPIOK_RIS_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_RIS_OFFSET)))

/******************************************************************************************
 ************************************ 8 MIS *********************************************
 ******************************************************************************************/
/* GPIOK MIS*/
#define GPIOK_MIS    ((GPIOMIS_t*) (GPIOK_BASE + GPIO_MIS_OFFSET))
#define GPIOK_MIS_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_MIS_OFFSET)))

/******************************************************************************************
 ************************************ 9 ICR *********************************************
 ******************************************************************************************/
/* GPIOK IC*/
#define GPIOK_ICR    ((GPIOICR_t*) (GPIOK_BASE + GPIO_ICR_OFFSET))
#define GPIOK_ICR_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_ICR_OFFSET)))

/******************************************************************************************
 ************************************ 10 AFSEL *********************************************
 ******************************************************************************************/
/* GPIOK AFSEL*/
#define GPIOK_AFSEL    ((GPIOKFSEL_t*) (GPIOK_BASE + GPIO_AFSEL_OFFSET))
#define GPIOK_AFSEL_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_AFSEL_OFFSET)))

/******************************************************************************************
 ************************************ 11 DRR ARRAY *********************************************
 ******************************************************************************************/
/* GPIOK DRV2*/
#define GPIOK_DRR    ((GPIOKRR_ARRAY_t*) (GPIOK_BASE + GPIO_DR2R_OFFSET))

/******************************************************************************************
 ************************************ 11 DR2R *********************************************
 ******************************************************************************************/
/* GPIOK DRV2*/
#define GPIOK_DR2R    ((GPIOKR2R_t*) (GPIOK_BASE + GPIO_DR2R_OFFSET))
#define GPIOK_DR2R_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_DR2R_OFFSET)))

/******************************************************************************************
 ************************************ 12 DR4R *********************************************
 ******************************************************************************************/
/* GPIOK DRV4*/
#define GPIOK_DR4R    ((GPIOKR4R_t*) (GPIOK_BASE + GPIO_DR4R_OFFSET))
#define GPIOK_DR4R_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_DR4R_OFFSET)))

/******************************************************************************************
 ************************************ 13 DR8R *********************************************
 ******************************************************************************************/
/* GPIOK DRV8*/
#define GPIOK_DR8R    ((GPIOKR8R_t*) (GPIOK_BASE + GPIO_DR8R_OFFSET))
#define GPIOK_DR8R_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_DR8R_OFFSET)))

/******************************************************************************************
 ************************************ 14 ODR *********************************************
 ******************************************************************************************/
/* GPIOK ODE*/
#define GPIOK_ODR    ((GPIOODR_t*) (GPIOK_BASE + GPIO_ODR_OFFSET))
#define GPIOK_ODR_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_ODR_OFFSET)))

/******************************************************************************************
 ************************************ 15 PUR *********************************************
 ******************************************************************************************/
/* GPIOK PUE*/
#define GPIOK_PUR    ((GPIOPUR_t*) (GPIOK_BASE + GPIO_PUR_OFFSET))
#define GPIOK_PUR_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_PUR_OFFSET)))

/******************************************************************************************
 ************************************ 16 PDR *********************************************
 ******************************************************************************************/
/* GPIOK PDE*/
#define GPIOK_PDR    ((GPIOPDR_t*) (GPIOK_BASE + GPIO_PDR_OFFSET))
#define GPIOK_PDR_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_PDR_OFFSET)))

/******************************************************************************************
 ************************************ 17 SLR *********************************************
 ******************************************************************************************/
/* GPIOK SLR*/
#define GPIOK_SLR    ((GPIOSLR_t*) (GPIOK_BASE + GPIO_SLR_OFFSET))
#define GPIOK_SLR_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_SLR_OFFSET)))

/******************************************************************************************
 ************************************ 18 DEN *********************************************
 ******************************************************************************************/
/* GPIOK DEN*/
#define GPIOK_DEN    ((GPIOKEN_t*) (GPIOK_BASE + GPIO_DEN_OFFSET))
#define GPIOK_DEN_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_DEN_OFFSET)))

/******************************************************************************************
 ************************************ 19 LOCK *********************************************
 ******************************************************************************************/
/* GPIOK LOCK*/
#define GPIOK_LOCK    ((GPIOLOCK_t*) (GPIOK_BASE + GPIO_LOCK_OFFSET))
#define GPIOK_LOCK_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_LOCK_OFFSET)))

/******************************************************************************************
 ************************************ 20 CR *********************************************
 ******************************************************************************************/
/* GPIOK CR*/
#define GPIOK_CR    ((GPIOKR_t*) (GPIOK_BASE + GPIO_CR_OFFSET))
#define GPIOK_CR_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_CR_OFFSET)))

/******************************************************************************************
 ************************************ 21 AMSEL *********************************************
 ******************************************************************************************/
/* GPIOK AMSEL*/
#define GPIOK_AMSEL    ((GPIOKMSEL_t*) (GPIOK_BASE + GPIO_AMSEL_OFFSET))
#define GPIOK_AMSEL_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_AMSEL_OFFSET)))

/******************************************************************************************
 ************************************ 22 PCTL *********************************************
 ******************************************************************************************/
/* GPIOK PCTL*/
#define GPIOK_PCTL    ((GPIOPCTL_t*) (GPIOK_BASE + GPIO_PCTL_OFFSET))
#define GPIOK_PCTL_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_PCTL_OFFSET)))

/******************************************************************************************
 ************************************ 23 ADCCTL *********************************************
 ******************************************************************************************/
/* GPIOK ADCCTL*/
#define GPIOK_ADCCTL    ((GPIOKDCCTL_t*) (GPIOK_BASE + GPIO_ADCCTL_OFFSET))
#define GPIOK_ADCCTL_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_ADCCTL_OFFSET)))

/******************************************************************************************
 ************************************ 24 DMACTL *********************************************
 ******************************************************************************************/
/* GPIOK DMACTL*/
#define GPIOK_DMACTL    ((GPIOKMACTL_t*) (GPIOK_BASE + GPIO_DMACTL_OFFSET))
#define GPIOK_DMACTL_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_DMACTL_OFFSET)))

/******************************************************************************************
 ************************************ 25 SI *********************************************
 ******************************************************************************************/
/* GPIOK SI*/
#define GPIOK_SI    ((GPIOSI_t*) (GPIOK_BASE + GPIO_SI_OFFSET))
#define GPIOK_SI_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_SI_OFFSET)))

/******************************************************************************************
 ************************************ 26 DR12R *********************************************
 ******************************************************************************************/
/* GPIOK DR12R*/
#define GPIOK_DR12R    ((GPIOKR12R_t*) (GPIOK_BASE + GPIO_DR12R_OFFSET))
#define GPIOK_DR12R_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_DR12R_OFFSET)))

/******************************************************************************************
 ************************************ 27 WAKEPEN *********************************************
 ******************************************************************************************/
/* GPIOK WAKEPEN*/
#define GPIOK_WAKEPEN    ((GPIOWAKEPEN_t*) (GPIOK_BASE + GPIO_WAKEPEN_OFFSET))
#define GPIOK_WAKEPEN_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_WAKEPEN_OFFSET)))

/******************************************************************************************
 ************************************ 28 WAKELVL *********************************************
 ******************************************************************************************/
/* GPIOK WAKELVL*/
#define GPIOK_WAKELVL    ((GPIOWAKELVL_t*) (GPIOK_BASE + GPIO_WAKELVL_OFFSET))
#define GPIOK_WAKELVL_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_WAKELVL_OFFSET)))

/******************************************************************************************
 ************************************ 29 WAKESTAT *********************************************
 ******************************************************************************************/
/* GPIOK WAKESTAT*/
#define GPIOK_WAKESTAT    ((GPIOWAKESTAT_t*) (GPIOK_BASE + GPIO_WAKESTAT_OFFSET))
#define GPIOK_WAKESTAT_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_WAKESTAT_OFFSET)))

/******************************************************************************************
 ************************************ 30 PP *********************************************
 ******************************************************************************************/
/* GPIOK PP*/
#define GPIOK_PP    ((GPIOPP_t*) (GPIOK_BASE + GPIO_PP_OFFSET))
#define GPIOK_PP_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_PP_OFFSET)))

/******************************************************************************************
 ************************************ 31 PC *********************************************
 ******************************************************************************************/
/* GPIOK PC*/
#define GPIOK_PC    ((GPIOPC_t*) (GPIOK_BASE + GPIO_PC_OFFSET))
#define GPIOK_PC_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_PC_OFFSET)))

/******************************************************************************************
 ************************************ 32 PeriphID4 *********************************************
 ******************************************************************************************/
/* GPIOK PID4*/
#define GPIOK_PeriphID4    ((GPIOPeriphID4_t*) (GPIOK_BASE + GPIO_PeriphID4_OFFSET))
#define GPIOK_PeriphID4_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_PeriphID4_OFFSET)))

/******************************************************************************************
 ************************************ 33 PeriphID5 *********************************************
 ******************************************************************************************/
/* GPIOK PID5*/
#define GPIOK_PeriphID5    ((GPIOPeriphID5_t*) (GPIOK_BASE + GPIO_PeriphID5_OFFSET))
#define GPIOK_PeriphID5_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_PeriphID5_OFFSET)))

/******************************************************************************************
 ************************************ 34 PeriphID6 *********************************************
 ******************************************************************************************/
/* GPIOK PID6*/
#define GPIOK_PeriphID6    ((GPIOPeriphID6_t*) (GPIOK_BASE + GPIO_PeriphID6_OFFSET))
#define GPIOK_PeriphID6_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_PeriphID6_OFFSET)))

/******************************************************************************************
 ************************************ 35 PeriphID7 *********************************************
 ******************************************************************************************/
/* GPIOK PID7*/
#define GPIOK_PeriphID7    ((GPIOPeriphID7_t*) (GPIOK_BASE + GPIO_PeriphID7_OFFSET))
#define GPIOK_PeriphID7_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_PeriphID7_OFFSET)))

/******************************************************************************************
 ************************************ 36 PeriphID0 *********************************************
 ******************************************************************************************/
/* GPIOK PID0*/
#define GPIOK_PeriphID0    ((GPIOPeriphID0_t*) (GPIOK_BASE + GPIO_PeriphID0_OFFSET))
#define GPIOK_PeriphID0_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_PeriphID0_OFFSET)))

/******************************************************************************************
 ************************************ 37 PeriphID1 *********************************************
 ******************************************************************************************/
/* GPIOK PID1*/
#define GPIOK_PeriphID1    ((GPIOPeriphID1_t*) (GPIOK_BASE + GPIO_PeriphID1_OFFSET))
#define GPIOK_PeriphID1_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_PeriphID1_OFFSET)))

/******************************************************************************************
 ************************************ 38 PeriphID2 *********************************************
 ******************************************************************************************/
/* GPIOK PID2*/
#define GPIOK_PeriphID2    ((GPIOPeriphID2_t*) (GPIOK_BASE + GPIO_PeriphID2_OFFSET))
#define GPIOK_PeriphID2_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_PeriphID2_OFFSET)))

/******************************************************************************************
 ************************************ 39 PeriphID3 *********************************************
 ******************************************************************************************/
/* GPIOK PID3*/
#define GPIOK_PeriphID3    ((GPIOPeriphID3_t*) (GPIOK_BASE + GPIO_PeriphID3_OFFSET))
#define GPIOK_PeriphID3_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_PeriphID3_OFFSET)))

/******************************************************************************************
 ************************************ 40 CellID0 *********************************************
 ******************************************************************************************/
/* GPIOK CID0*/
#define GPIOK_CellID0    ((GPIOKellID0_t*) (GPIOK_BASE + GPIO_CellID0_OFFSET))
#define GPIOK_CellID0_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_CellID0_OFFSET)))

/******************************************************************************************
 ************************************ 41 CellID1 *********************************************
 ******************************************************************************************/
/* GPIOK CID1*/
#define GPIOK_CellID1    ((GPIOKellID1_t*) (GPIOK_BASE + GPIO_CellID1_OFFSET))
#define GPIOK_CellID1_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_CellID1_OFFSET)))

/******************************************************************************************
 ************************************ 42 CellID2 *********************************************
 ******************************************************************************************/
/* GPIOK CID2*/
#define GPIOK_CellID2    ((GPIOKellID2_t*) (GPIOK_BASE + GPIO_CellID2_OFFSET))
#define GPIOK_CellID2_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_CellID2_OFFSET)))

/******************************************************************************************
 ************************************ 43 CellID3 *********************************************
 ******************************************************************************************/
/* GPIOK CID3*/
#define GPIOK_CellID3    ((GPIOKellID3_t*) (GPIOK_BASE + GPIO_CellID3_OFFSET))
#define GPIOK_CellID3_R    (*((volatile uint32_t *) (GPIOK_BASE + GPIO_CellID3_OFFSET)))

#endif /* XDRIVER_MCU_GPIO_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_XHEADER_GPIO_REGISTERPERIPHERAL_MODULEK_H_ */
