/**
 *
 * @file GPIO_RegisterPeripheral_Bitbanding_ModuleP.h
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

#ifndef XDRIVER_MCU_GPIO_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_BITBANDING_XHEADER_GPIO_REGISTERPERIPHERAL_BITBANDING_MODULEP_H_
#define XDRIVER_MCU_GPIO_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_BITBANDING_XHEADER_GPIO_REGISTERPERIPHERAL_BITBANDING_MODULEP_H_

#include <xDriver_MCU/GPIO/Peripheral/Register/xHeader/GPIO_RegisterAddress.h>
#include <xDriver_MCU/GPIO/Peripheral/Register/RegisterDefines/GPIO_RegisterDefines.h>
#include <xDriver_MCU/GPIO/Peripheral/Struct/xHeader/GPIO_StructPeripheral_Bitbanding.h>

#define GPIOP_BITBANDING    ((GPIO_BITBANDING_t*) (GPIO_BITBANDING_BASE + (GPIOP_OFFSET * 32UL)))
#define GPIOP_AUX_BITBANDING    ((GPIO_AUX_BITBANDING_t*) (GPIO_BITBANDING_BASE + (GPIOP_OFFSET * 32UL)))

/******************************************************************************************
 *********************************** * 1 DATA *********************************************
 ******************************************************************************************/

/* GPIOP DATA*/
#define GPIOP_BITBANDING_DATA_MASK    ((GPIO_BITBANDING_DATA_MASK_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DATA_MASK_OFFSET) * 32UL)))
#define GPIOP_BITBANDING_DATA    ((GPIO_BITBANDING_DATA_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DATA_OFFSET) * 32UL)))

/* GPIOP DATA BITBANDING*/
#define GPIOP_BITBANDING_DATA_PINMASK0_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DATA_PINMASK0_OFFSET) * 32UL) + (GPIO_DATA_R_PIN0_BIT * 4UL))))
#define GPIOP_BITBANDING_DATA_PINMASK1_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DATA_PINMASK1_OFFSET) * 32UL) + (GPIO_DATA_R_PIN1_BIT * 4UL))))
#define GPIOP_BITBANDING_DATA_PINMASK2_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DATA_PINMASK2_OFFSET) * 32UL) + (GPIO_DATA_R_PIN2_BIT * 4UL))))
#define GPIOP_BITBANDING_DATA_PINMASK3_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DATA_PINMASK3_OFFSET) * 32UL) + (GPIO_DATA_R_PIN3_BIT * 4UL))))
#define GPIOP_BITBANDING_DATA_PINMASK4_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DATA_PINMASK4_OFFSET) * 32UL) + (GPIO_DATA_R_PIN4_BIT * 4UL))))
#define GPIOP_BITBANDING_DATA_PINMASK5_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DATA_PINMASK5_OFFSET) * 32UL) + (GPIO_DATA_R_PIN5_BIT * 4UL))))
#define GPIOP_BITBANDING_DATA_PINMASK6_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DATA_PINMASK6_OFFSET) * 32UL) + (GPIO_DATA_R_PIN6_BIT * 4UL))))
#define GPIOP_BITBANDING_DATA_PINMASK7_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DATA_PINMASK7_OFFSET) * 32UL) + (GPIO_DATA_R_PIN7_BIT * 4UL))))

#define GPIOP_BITBANDING_DATA_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DATA_OFFSET) * 32UL) + (GPIO_DATA_R_PIN0_BIT * 4UL))))
#define GPIOP_BITBANDING_DATA_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DATA_OFFSET) * 32UL) + (GPIO_DATA_R_PIN1_BIT * 4UL))))
#define GPIOP_BITBANDING_DATA_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DATA_OFFSET) * 32UL) + (GPIO_DATA_R_PIN2_BIT * 4UL))))
#define GPIOP_BITBANDING_DATA_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DATA_OFFSET) * 32UL) + (GPIO_DATA_R_PIN3_BIT * 4UL))))
#define GPIOP_BITBANDING_DATA_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DATA_OFFSET) * 32UL) + (GPIO_DATA_R_PIN4_BIT * 4UL))))
#define GPIOP_BITBANDING_DATA_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DATA_OFFSET) * 32UL) + (GPIO_DATA_R_PIN5_BIT * 4UL))))
#define GPIOP_BITBANDING_DATA_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DATA_OFFSET) * 32UL) + (GPIO_DATA_R_PIN6_BIT * 4UL))))
#define GPIOP_BITBANDING_DATA_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DATA_OFFSET) * 32UL) + (GPIO_DATA_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 2 DIR *********************************************
 ******************************************************************************************/
/* GPIOP DIR*/
#define GPIOP_BITBANDING_DIR    ((GPIO_BITBANDING_DIR_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DIR_OFFSET) * 32UL)))

/* GPIOP DIR BITBANDING*/
#define GPIOP_BITBANDING_DIR_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DIR_OFFSET) * 32UL) + (GPIO_DIR_R_PIN0_BIT * 4UL))))
#define GPIOP_BITBANDING_DIR_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DIR_OFFSET) * 32UL) + (GPIO_DIR_R_PIN1_BIT * 4UL))))
#define GPIOP_BITBANDING_DIR_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DIR_OFFSET) * 32UL) + (GPIO_DIR_R_PIN2_BIT * 4UL))))
#define GPIOP_BITBANDING_DIR_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DIR_OFFSET) * 32UL) + (GPIO_DIR_R_PIN3_BIT * 4UL))))
#define GPIOP_BITBANDING_DIR_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DIR_OFFSET) * 32UL) + (GPIO_DIR_R_PIN4_BIT * 4UL))))
#define GPIOP_BITBANDING_DIR_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DIR_OFFSET) * 32UL) + (GPIO_DIR_R_PIN5_BIT * 4UL))))
#define GPIOP_BITBANDING_DIR_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DIR_OFFSET) * 32UL) + (GPIO_DIR_R_PIN6_BIT * 4UL))))
#define GPIOP_BITBANDING_DIR_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DIR_OFFSET) * 32UL) + (GPIO_DIR_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 3 IS *********************************************
 ******************************************************************************************/
/* GPIOP IS*/
#define GPIOP_BITBANDING_IS    ((GPIO_BITBANDING_IS_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IS_OFFSET) * 32UL)))

/* GPIOP IS BITBANDING*/
#define GPIOP_BITBANDING_IS_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IS_OFFSET) * 32UL) + (GPIO_IS_R_PIN0_BIT * 4UL))))
#define GPIOP_BITBANDING_IS_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IS_OFFSET) * 32UL) + (GPIO_IS_R_PIN1_BIT * 4UL))))
#define GPIOP_BITBANDING_IS_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IS_OFFSET) * 32UL) + (GPIO_IS_R_PIN2_BIT * 4UL))))
#define GPIOP_BITBANDING_IS_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IS_OFFSET) * 32UL) + (GPIO_IS_R_PIN3_BIT * 4UL))))
#define GPIOP_BITBANDING_IS_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IS_OFFSET) * 32UL) + (GPIO_IS_R_PIN4_BIT * 4UL))))
#define GPIOP_BITBANDING_IS_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IS_OFFSET) * 32UL) + (GPIO_IS_R_PIN5_BIT * 4UL))))
#define GPIOP_BITBANDING_IS_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IS_OFFSET) * 32UL) + (GPIO_IS_R_PIN6_BIT * 4UL))))
#define GPIOP_BITBANDING_IS_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IS_OFFSET) * 32UL) + (GPIO_IS_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 4 IBE *********************************************
 ******************************************************************************************/
/* GPIOP IBE*/
#define GPIOP_BITBANDING_IBE    ((GPIO_BITBANDING_IBE_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IBE_OFFSET) * 32UL)))

/* GPIOP IBE BITBANDING*/
#define GPIOP_BITBANDING_IBE_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IBE_OFFSET) * 32UL) + (GPIO_IBE_R_PIN0_BIT * 4UL))))
#define GPIOP_BITBANDING_IBE_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IBE_OFFSET) * 32UL) + (GPIO_IBE_R_PIN1_BIT * 4UL))))
#define GPIOP_BITBANDING_IBE_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IBE_OFFSET) * 32UL) + (GPIO_IBE_R_PIN2_BIT * 4UL))))
#define GPIOP_BITBANDING_IBE_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IBE_OFFSET) * 32UL) + (GPIO_IBE_R_PIN3_BIT * 4UL))))
#define GPIOP_BITBANDING_IBE_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IBE_OFFSET) * 32UL) + (GPIO_IBE_R_PIN4_BIT * 4UL))))
#define GPIOP_BITBANDING_IBE_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IBE_OFFSET) * 32UL) + (GPIO_IBE_R_PIN5_BIT * 4UL))))
#define GPIOP_BITBANDING_IBE_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IBE_OFFSET) * 32UL) + (GPIO_IBE_R_PIN6_BIT * 4UL))))
#define GPIOP_BITBANDING_IBE_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IBE_OFFSET) * 32UL) + (GPIO_IBE_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 5 IEV *********************************************
 ******************************************************************************************/
/* GPIOP IEV*/
#define GPIOP_BITBANDING_IEV    ((GPIO_BITBANDING_IEV_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IEV_OFFSET) * 32UL)))

/* GPIOP IEV BITBANDING*/
#define GPIOP_BITBANDING_IEV_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IEV_OFFSET) * 32UL) + (GPIO_IEV_R_PIN0_BIT * 4UL))))
#define GPIOP_BITBANDING_IEV_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IEV_OFFSET) * 32UL) + (GPIO_IEV_R_PIN1_BIT * 4UL))))
#define GPIOP_BITBANDING_IEV_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IEV_OFFSET) * 32UL) + (GPIO_IEV_R_PIN2_BIT * 4UL))))
#define GPIOP_BITBANDING_IEV_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IEV_OFFSET) * 32UL) + (GPIO_IEV_R_PIN3_BIT * 4UL))))
#define GPIOP_BITBANDING_IEV_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IEV_OFFSET) * 32UL) + (GPIO_IEV_R_PIN4_BIT * 4UL))))
#define GPIOP_BITBANDING_IEV_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IEV_OFFSET) * 32UL) + (GPIO_IEV_R_PIN5_BIT * 4UL))))
#define GPIOP_BITBANDING_IEV_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IEV_OFFSET) * 32UL) + (GPIO_IEV_R_PIN6_BIT * 4UL))))
#define GPIOP_BITBANDING_IEV_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IEV_OFFSET) * 32UL) + (GPIO_IEV_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 6 IM *********************************************
 ******************************************************************************************/
/* GPIOP IME*/
#define GPIOP_BITBANDING_IM    ((GPIO_BITBANDING_IM_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IM_OFFSET) * 32UL)))

/* GPIOP IME BITBANDING*/
#define GPIOP_BITBANDING_IM_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IM_OFFSET) * 32UL) + (GPIO_IM_R_PIN0_BIT * 4UL))))
#define GPIOP_BITBANDING_IM_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IM_OFFSET) * 32UL) + (GPIO_IM_R_PIN1_BIT * 4UL))))
#define GPIOP_BITBANDING_IM_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IM_OFFSET) * 32UL) + (GPIO_IM_R_PIN2_BIT * 4UL))))
#define GPIOP_BITBANDING_IM_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IM_OFFSET) * 32UL) + (GPIO_IM_R_PIN3_BIT * 4UL))))
#define GPIOP_BITBANDING_IM_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IM_OFFSET) * 32UL) + (GPIO_IM_R_PIN4_BIT * 4UL))))
#define GPIOP_BITBANDING_IM_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IM_OFFSET) * 32UL) + (GPIO_IM_R_PIN5_BIT * 4UL))))
#define GPIOP_BITBANDING_IM_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IM_OFFSET) * 32UL) + (GPIO_IM_R_PIN6_BIT * 4UL))))
#define GPIOP_BITBANDING_IM_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IM_OFFSET) * 32UL) + (GPIO_IM_R_PIN7_BIT * 4UL))))
#define GPIOP_BITBANDING_IM_DMAIME    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IM_OFFSET) * 32UL) + (GPIO_IM_R_DMAIME_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 7 RIS *********************************************
 ******************************************************************************************/
/* GPIOP RIS*/
#define GPIOP_BITBANDING_RIS    ((GPIO_BITBANDING_RIS_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_RIS_OFFSET) * 32UL)))

/* GPIOP RIS BITBANDING*/
#define GPIOP_BITBANDING_RIS_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_RIS_OFFSET) * 32UL) + (GPIO_RIS_R_PIN0_BIT * 4UL))))
#define GPIOP_BITBANDING_RIS_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_RIS_OFFSET) * 32UL) + (GPIO_RIS_R_PIN1_BIT * 4UL))))
#define GPIOP_BITBANDING_RIS_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_RIS_OFFSET) * 32UL) + (GPIO_RIS_R_PIN2_BIT * 4UL))))
#define GPIOP_BITBANDING_RIS_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_RIS_OFFSET) * 32UL) + (GPIO_RIS_R_PIN3_BIT * 4UL))))
#define GPIOP_BITBANDING_RIS_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_RIS_OFFSET) * 32UL) + (GPIO_RIS_R_PIN4_BIT * 4UL))))
#define GPIOP_BITBANDING_RIS_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_RIS_OFFSET) * 32UL) + (GPIO_RIS_R_PIN5_BIT * 4UL))))
#define GPIOP_BITBANDING_RIS_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_RIS_OFFSET) * 32UL) + (GPIO_RIS_R_PIN6_BIT * 4UL))))
#define GPIOP_BITBANDING_RIS_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_RIS_OFFSET) * 32UL) + (GPIO_RIS_R_PIN7_BIT * 4UL))))
#define GPIOP_BITBANDING_IM_DMARIS    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IM_OFFSET) * 32UL) + (GPIO_IM_R_DMARIS_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 8 MIS *********************************************
 ******************************************************************************************/
/* GPIOP MIS*/
#define GPIOP_BITBANDING_MIS    ((GPIO_BITBANDING_MIS_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_MIS_OFFSET) * 32UL)))

/* GPIOP MIS BITBANDING*/
#define GPIOP_BITBANDING_MIS_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_MIS_OFFSET) * 32UL) + (GPIO_MIS_R_PIN0_BIT * 4UL))))
#define GPIOP_BITBANDING_MIS_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_MIS_OFFSET) * 32UL) + (GPIO_MIS_R_PIN1_BIT * 4UL))))
#define GPIOP_BITBANDING_MIS_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_MIS_OFFSET) * 32UL) + (GPIO_MIS_R_PIN2_BIT * 4UL))))
#define GPIOP_BITBANDING_MIS_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_MIS_OFFSET) * 32UL) + (GPIO_MIS_R_PIN3_BIT * 4UL))))
#define GPIOP_BITBANDING_MIS_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_MIS_OFFSET) * 32UL) + (GPIO_MIS_R_PIN4_BIT * 4UL))))
#define GPIOP_BITBANDING_MIS_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_MIS_OFFSET) * 32UL) + (GPIO_MIS_R_PIN5_BIT * 4UL))))
#define GPIOP_BITBANDING_MIS_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_MIS_OFFSET) * 32UL) + (GPIO_MIS_R_PIN6_BIT * 4UL))))
#define GPIOP_BITBANDING_MIS_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_MIS_OFFSET) * 32UL) + (GPIO_MIS_R_PIN7_BIT * 4UL))))
#define GPIOP_BITBANDING_IM_DMAMIS    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IM_OFFSET) * 32UL) + (GPIO_IM_R_DMAMIS_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 9 ICR *********************************************
 ******************************************************************************************/
/* GPIOP IC*/
#define GPIOP_BITBANDING_ICR    ((GPIO_BITBANDING_ICR_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_ICR_OFFSET) * 32UL)))

/* GPIOP IC BITBANDING*/
#define GPIOP_BITBANDING_ICR_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_ICR_OFFSET) * 32UL) + (GPIO_ICR_R_PIN0_BIT * 4UL))))
#define GPIOP_BITBANDING_ICR_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_ICR_OFFSET) * 32UL) + (GPIO_ICR_R_PIN1_BIT * 4UL))))
#define GPIOP_BITBANDING_ICR_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_ICR_OFFSET) * 32UL) + (GPIO_ICR_R_PIN2_BIT * 4UL))))
#define GPIOP_BITBANDING_ICR_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_ICR_OFFSET) * 32UL) + (GPIO_ICR_R_PIN3_BIT * 4UL))))
#define GPIOP_BITBANDING_ICR_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_ICR_OFFSET) * 32UL) + (GPIO_ICR_R_PIN4_BIT * 4UL))))
#define GPIOP_BITBANDING_ICR_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_ICR_OFFSET) * 32UL) + (GPIO_ICR_R_PIN5_BIT * 4UL))))
#define GPIOP_BITBANDING_ICR_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_ICR_OFFSET) * 32UL) + (GPIO_ICR_R_PIN6_BIT * 4UL))))
#define GPIOP_BITBANDING_ICR_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_ICR_OFFSET) * 32UL) + (GPIO_ICR_R_PIN7_BIT * 4UL))))
#define GPIOP_BITBANDING_IM_DMAIC    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_IM_OFFSET) * 32UL) + (GPIO_IM_R_DMAIC_BIT * 4UL))))
/******************************************************************************************
 *********************************** * 10 AFSEL *********************************************
 ******************************************************************************************/
/* GPIOP AFSEL*/
#define GPIOP_BITBANDING_AFSEL    ((BITBANDING_GPIO_AFSEL_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_AFSEL_OFFSET) * 32UL)))

/* GPIOP AFSEL BITBANDING*/
#define GPIOP_BITBANDING_AFSEL_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_AFSEL_OFFSET) * 32UL) + (GPIO_AFSEL_R_PIN0_BIT * 4UL))))
#define GPIOP_BITBANDING_AFSEL_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_AFSEL_OFFSET) * 32UL) + (GPIO_AFSEL_R_PIN1_BIT * 4UL))))
#define GPIOP_BITBANDING_AFSEL_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_AFSEL_OFFSET) * 32UL) + (GPIO_AFSEL_R_PIN2_BIT * 4UL))))
#define GPIOP_BITBANDING_AFSEL_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_AFSEL_OFFSET) * 32UL) + (GPIO_AFSEL_R_PIN3_BIT * 4UL))))
#define GPIOP_BITBANDING_AFSEL_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_AFSEL_OFFSET) * 32UL) + (GPIO_AFSEL_R_PIN4_BIT * 4UL))))
#define GPIOP_BITBANDING_AFSEL_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_AFSEL_OFFSET) * 32UL) + (GPIO_AFSEL_R_PIN5_BIT * 4UL))))
#define GPIOP_BITBANDING_AFSEL_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_AFSEL_OFFSET) * 32UL) + (GPIO_AFSEL_R_PIN6_BIT * 4UL))))
#define GPIOP_BITBANDING_AFSEL_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_AFSEL_OFFSET) * 32UL) + (GPIO_AFSEL_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 11 DRR ARRAY *********************************************
 ******************************************************************************************/
/* GPIOP DRV2*/
#define GPIOP_BITBANDING_DRR    ((GPIO_BITBANDING_DRR_ARRAY_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR2R_OFFSET) * 32UL)))

/******************************************************************************************
 *********************************** * 11 DR2R *********************************************
 ******************************************************************************************/
/* GPIOP DRV2*/
#define GPIOP_BITBANDING_DR2R    ((GPIO_BITBANDING_DR2R_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR2R_OFFSET) * 32UL)))

/* GPIOP DRV2 BITBANDING*/
#define GPIOP_BITBANDING_DR2R_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR2R_OFFSET) * 32UL) + (GPIO_DR2R_R_PIN0_BIT * 4UL))))
#define GPIOP_BITBANDING_DR2R_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR2R_OFFSET) * 32UL) + (GPIO_DR2R_R_PIN1_BIT * 4UL))))
#define GPIOP_BITBANDING_DR2R_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR2R_OFFSET) * 32UL) + (GPIO_DR2R_R_PIN2_BIT * 4UL))))
#define GPIOP_BITBANDING_DR2R_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR2R_OFFSET) * 32UL) + (GPIO_DR2R_R_PIN3_BIT * 4UL))))
#define GPIOP_BITBANDING_DR2R_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR2R_OFFSET) * 32UL) + (GPIO_DR2R_R_PIN4_BIT * 4UL))))
#define GPIOP_BITBANDING_DR2R_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR2R_OFFSET) * 32UL) + (GPIO_DR2R_R_PIN5_BIT * 4UL))))
#define GPIOP_BITBANDING_DR2R_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR2R_OFFSET) * 32UL) + (GPIO_DR2R_R_PIN6_BIT * 4UL))))
#define GPIOP_BITBANDING_DR2R_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR2R_OFFSET) * 32UL) + (GPIO_DR2R_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 12 DR4R *********************************************
 ******************************************************************************************/
/* GPIOP DRV4*/
#define GPIOP_BITBANDING_DR4R    ((GPIO_BITBANDING_DR4R_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR4R_OFFSET) * 32UL)))

/* GPIOP DRV4 BITBANDING*/
#define GPIOP_BITBANDING_DR4R_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR4R_OFFSET) * 32UL) + (GPIO_DR4R_R_PIN0_BIT * 4UL))))
#define GPIOP_BITBANDING_DR4R_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR4R_OFFSET) * 32UL) + (GPIO_DR4R_R_PIN1_BIT * 4UL))))
#define GPIOP_BITBANDING_DR4R_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR4R_OFFSET) * 32UL) + (GPIO_DR4R_R_PIN2_BIT * 4UL))))
#define GPIOP_BITBANDING_DR4R_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR4R_OFFSET) * 32UL) + (GPIO_DR4R_R_PIN3_BIT * 4UL))))
#define GPIOP_BITBANDING_DR4R_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR4R_OFFSET) * 32UL) + (GPIO_DR4R_R_PIN4_BIT * 4UL))))
#define GPIOP_BITBANDING_DR4R_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR4R_OFFSET) * 32UL) + (GPIO_DR4R_R_PIN5_BIT * 4UL))))
#define GPIOP_BITBANDING_DR4R_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR4R_OFFSET) * 32UL) + (GPIO_DR4R_R_PIN6_BIT * 4UL))))
#define GPIOP_BITBANDING_DR4R_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR4R_OFFSET) * 32UL) + (GPIO_DR4R_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 13 DR8R *********************************************
 ******************************************************************************************/
/* GPIOP DRV8*/
#define GPIOP_BITBANDING_DR8R    ((GPIO_BITBANDING_DR8R_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR8R_OFFSET) * 32UL)))

/* GPIOP DRV8 BITBANDING*/
#define GPIOP_BITBANDING_DR8R_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR8R_OFFSET) * 32UL) + (GPIO_DR8R_R_PIN0_BIT * 4UL))))
#define GPIOP_BITBANDING_DR8R_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR8R_OFFSET) * 32UL) + (GPIO_DR8R_R_PIN1_BIT * 4UL))))
#define GPIOP_BITBANDING_DR8R_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR8R_OFFSET) * 32UL) + (GPIO_DR8R_R_PIN2_BIT * 4UL))))
#define GPIOP_BITBANDING_DR8R_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR8R_OFFSET) * 32UL) + (GPIO_DR8R_R_PIN3_BIT * 4UL))))
#define GPIOP_BITBANDING_DR8R_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR8R_OFFSET) * 32UL) + (GPIO_DR8R_R_PIN4_BIT * 4UL))))
#define GPIOP_BITBANDING_DR8R_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR8R_OFFSET) * 32UL) + (GPIO_DR8R_R_PIN5_BIT * 4UL))))
#define GPIOP_BITBANDING_DR8R_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR8R_OFFSET) * 32UL) + (GPIO_DR8R_R_PIN6_BIT * 4UL))))
#define GPIOP_BITBANDING_DR8R_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR8R_OFFSET) * 32UL) + (GPIO_DR8R_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 14 ODR *********************************************
 ******************************************************************************************/
/* GPIOP ODE*/
#define GPIOP_BITBANDING_ODR    ((GPIO_BITBANDING_ODR_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_ODR_OFFSET) * 32UL)))

/* GPIOP ODE BITBANDING*/
#define GPIOP_BITBANDING_ODR_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_ODR_OFFSET) * 32UL) + (GPIO_ODR_R_PIN0_BIT * 4UL))))
#define GPIOP_BITBANDING_ODR_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_ODR_OFFSET) * 32UL) + (GPIO_ODR_R_PIN1_BIT * 4UL))))
#define GPIOP_BITBANDING_ODR_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_ODR_OFFSET) * 32UL) + (GPIO_ODR_R_PIN2_BIT * 4UL))))
#define GPIOP_BITBANDING_ODR_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_ODR_OFFSET) * 32UL) + (GPIO_ODR_R_PIN3_BIT * 4UL))))
#define GPIOP_BITBANDING_ODR_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_ODR_OFFSET) * 32UL) + (GPIO_ODR_R_PIN4_BIT * 4UL))))
#define GPIOP_BITBANDING_ODR_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_ODR_OFFSET) * 32UL) + (GPIO_ODR_R_PIN5_BIT * 4UL))))
#define GPIOP_BITBANDING_ODR_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_ODR_OFFSET) * 32UL) + (GPIO_ODR_R_PIN6_BIT * 4UL))))
#define GPIOP_BITBANDING_ODR_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_ODR_OFFSET) * 32UL) + (GPIO_ODR_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 15 PUR *********************************************
 ******************************************************************************************/
/* GPIOP PUE*/
#define GPIOP_BITBANDING_PUR    ((GPIO_BITBANDING_PUR_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PUR_OFFSET) * 32UL)))

/* GPIOP PUE BITBANDING*/
#define GPIOP_BITBANDING_PUR_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PUR_OFFSET) * 32UL) + (GPIO_PUR_R_PIN0_BIT * 4UL))))
#define GPIOP_BITBANDING_PUR_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PUR_OFFSET) * 32UL) + (GPIO_PUR_R_PIN1_BIT * 4UL))))
#define GPIOP_BITBANDING_PUR_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PUR_OFFSET) * 32UL) + (GPIO_PUR_R_PIN2_BIT * 4UL))))
#define GPIOP_BITBANDING_PUR_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PUR_OFFSET) * 32UL) + (GPIO_PUR_R_PIN3_BIT * 4UL))))
#define GPIOP_BITBANDING_PUR_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PUR_OFFSET) * 32UL) + (GPIO_PUR_R_PIN4_BIT * 4UL))))
#define GPIOP_BITBANDING_PUR_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PUR_OFFSET) * 32UL) + (GPIO_PUR_R_PIN5_BIT * 4UL))))
#define GPIOP_BITBANDING_PUR_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PUR_OFFSET) * 32UL) + (GPIO_PUR_R_PIN6_BIT * 4UL))))
#define GPIOP_BITBANDING_PUR_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PUR_OFFSET) * 32UL) + (GPIO_PUR_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 16 PDR *********************************************
 ******************************************************************************************/
/* GPIOP PDE*/
#define GPIOP_BITBANDING_PDR    ((GPIO_BITBANDING_PDR_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PDR_OFFSET) * 32UL)))

/* GPIOP PDE BITBANDING*/
#define GPIOP_BITBANDING_PDR_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PDR_OFFSET) * 32UL) + (GPIO_PDR_R_PIN0_BIT * 4UL))))
#define GPIOP_BITBANDING_PDR_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PDR_OFFSET) * 32UL) + (GPIO_PDR_R_PIN1_BIT * 4UL))))
#define GPIOP_BITBANDING_PDR_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PDR_OFFSET) * 32UL) + (GPIO_PDR_R_PIN2_BIT * 4UL))))
#define GPIOP_BITBANDING_PDR_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PDR_OFFSET) * 32UL) + (GPIO_PDR_R_PIN3_BIT * 4UL))))
#define GPIOP_BITBANDING_PDR_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PDR_OFFSET) * 32UL) + (GPIO_PDR_R_PIN4_BIT * 4UL))))
#define GPIOP_BITBANDING_PDR_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PDR_OFFSET) * 32UL) + (GPIO_PDR_R_PIN5_BIT * 4UL))))
#define GPIOP_BITBANDING_PDR_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PDR_OFFSET) * 32UL) + (GPIO_PDR_R_PIN6_BIT * 4UL))))
#define GPIOP_BITBANDING_PDR_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PDR_OFFSET) * 32UL) + (GPIO_PDR_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 17 SLR *********************************************
 ******************************************************************************************/
/* GPIOP SLR*/
#define GPIOP_BITBANDING_SLR    ((GPIO_BITBANDING_SLR_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_SLR_OFFSET) * 32UL)))

/* GPIOP SLR BITBANDING*/
#define GPIOP_BITBANDING_SLR_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_SLR_OFFSET) * 32UL) + (GPIO_SLR_R_PIN0_BIT * 4UL))))
#define GPIOP_BITBANDING_SLR_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_SLR_OFFSET) * 32UL) + (GPIO_SLR_R_PIN1_BIT * 4UL))))
#define GPIOP_BITBANDING_SLR_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_SLR_OFFSET) * 32UL) + (GPIO_SLR_R_PIN2_BIT * 4UL))))
#define GPIOP_BITBANDING_SLR_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_SLR_OFFSET) * 32UL) + (GPIO_SLR_R_PIN3_BIT * 4UL))))
#define GPIOP_BITBANDING_SLR_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_SLR_OFFSET) * 32UL) + (GPIO_SLR_R_PIN4_BIT * 4UL))))
#define GPIOP_BITBANDING_SLR_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_SLR_OFFSET) * 32UL) + (GPIO_SLR_R_PIN5_BIT * 4UL))))
#define GPIOP_BITBANDING_SLR_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_SLR_OFFSET) * 32UL) + (GPIO_SLR_R_PIN6_BIT * 4UL))))
#define GPIOP_BITBANDING_SLR_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_SLR_OFFSET) * 32UL) + (GPIO_SLR_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 18 DEN *********************************************
 ******************************************************************************************/
/* GPIOP DEN*/
#define GPIOP_BITBANDING_DEN    ((GPIO_BITBANDING_DEN_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DEN_OFFSET) * 32UL)))

/* GPIOP DEN BITBANDING*/
#define GPIOP_BITBANDING_DEN_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DEN_OFFSET) * 32UL) + (GPIO_DEN_R_PIN0_BIT * 4UL))))
#define GPIOP_BITBANDING_DEN_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DEN_OFFSET) * 32UL) + (GPIO_DEN_R_PIN1_BIT * 4UL))))
#define GPIOP_BITBANDING_DEN_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DEN_OFFSET) * 32UL) + (GPIO_DEN_R_PIN2_BIT * 4UL))))
#define GPIOP_BITBANDING_DEN_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DEN_OFFSET) * 32UL) + (GPIO_DEN_R_PIN3_BIT * 4UL))))
#define GPIOP_BITBANDING_DEN_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DEN_OFFSET) * 32UL) + (GPIO_DEN_R_PIN4_BIT * 4UL))))
#define GPIOP_BITBANDING_DEN_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DEN_OFFSET) * 32UL) + (GPIO_DEN_R_PIN5_BIT * 4UL))))
#define GPIOP_BITBANDING_DEN_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DEN_OFFSET) * 32UL) + (GPIO_DEN_R_PIN6_BIT * 4UL))))
#define GPIOP_BITBANDING_DEN_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DEN_OFFSET) * 32UL) + (GPIO_DEN_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 19 LOCK *********************************************
 ******************************************************************************************/
/* GPIOP LOCK*/
#define GPIOP_BITBANDING_LOCK    ((GPIO_BITBANDING_LOCK_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_LOCK_OFFSET) * 32UL)))

/******************************************************************************************
 *********************************** * 20 CR *********************************************
 ******************************************************************************************/
/* GPIOP CR*/
#define GPIOP_BITBANDING_CR    ((GPIO_BITBANDING_CR_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_CR_OFFSET) * 32UL)))

/* GPIOP CR BITBANDING*/
#define GPIOP_BITBANDING_CR_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_CR_OFFSET) * 32UL) + (GPIO_CR_R_PIN0_BIT * 4UL))))
#define GPIOP_BITBANDING_CR_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_CR_OFFSET) * 32UL) + (GPIO_CR_R_PIN1_BIT * 4UL))))
#define GPIOP_BITBANDING_CR_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_CR_OFFSET) * 32UL) + (GPIO_CR_R_PIN2_BIT * 4UL))))
#define GPIOP_BITBANDING_CR_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_CR_OFFSET) * 32UL) + (GPIO_CR_R_PIN3_BIT * 4UL))))
#define GPIOP_BITBANDING_CR_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_CR_OFFSET) * 32UL) + (GPIO_CR_R_PIN4_BIT * 4UL))))
#define GPIOP_BITBANDING_CR_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_CR_OFFSET) * 32UL) + (GPIO_CR_R_PIN5_BIT * 4UL))))
#define GPIOP_BITBANDING_CR_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_CR_OFFSET) * 32UL) + (GPIO_CR_R_PIN6_BIT * 4UL))))
#define GPIOP_BITBANDING_CR_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_CR_OFFSET) * 32UL) + (GPIO_CR_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 21 AMSEL *********************************************
 ******************************************************************************************/
/* GPIOP AMSEL*/
#define GPIOP_BITBANDING_AMSEL    ((BITBANDING_GPIO_AMSEL_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_AMSEL_OFFSET) * 32UL)))

/* GPIOP AMSEL BITBANDING*/
#define GPIOP_BITBANDING_AMSEL_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_AMSEL_OFFSET) * 32UL) + (GPIO_AMSEL_R_PIN0_BIT * 4UL))))
#define GPIOP_BITBANDING_AMSEL_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_AMSEL_OFFSET) * 32UL) + (GPIO_AMSEL_R_PIN1_BIT * 4UL))))
#define GPIOP_BITBANDING_AMSEL_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_AMSEL_OFFSET) * 32UL) + (GPIO_AMSEL_R_PIN2_BIT * 4UL))))
#define GPIOP_BITBANDING_AMSEL_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_AMSEL_OFFSET) * 32UL) + (GPIO_AMSEL_R_PIN3_BIT * 4UL))))
#define GPIOP_BITBANDING_AMSEL_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_AMSEL_OFFSET) * 32UL) + (GPIO_AMSEL_R_PIN4_BIT * 4UL))))
#define GPIOP_BITBANDING_AMSEL_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_AMSEL_OFFSET) * 32UL) + (GPIO_AMSEL_R_PIN5_BIT * 4UL))))
#define GPIOP_BITBANDING_AMSEL_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_AMSEL_OFFSET) * 32UL) + (GPIO_AMSEL_R_PIN6_BIT * 4UL))))
#define GPIOP_BITBANDING_AMSEL_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_AMSEL_OFFSET) * 32UL) + (GPIO_AMSEL_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 22 PCTL *********************************************
 ******************************************************************************************/
/* GPIOP PCTL*/
#define GPIOP_BITBANDING_PCTL    ((GPIO_BITBANDING_PCTL_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PCTL_OFFSET) * 32UL)))

/******************************************************************************************
 *********************************** * 23 ADCCTL *********************************************
 ******************************************************************************************/
/* GPIOP ADCCTL*/
#define GPIOP_BITBANDING_ADCCTL    ((BITBANDING_GPIO_ADCCTL_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_ADCCTL_OFFSET) * 32UL)))

/* GPIOP ADCCTL BITBANDING*/
#define GPIOP_BITBANDING_ADCCTL_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_ADCCTL_OFFSET) * 32UL) + (GPIO_ADCCTL_R_PIN0_BIT * 4UL))))
#define GPIOP_BITBANDING_ADCCTL_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_ADCCTL_OFFSET) * 32UL) + (GPIO_ADCCTL_R_PIN1_BIT * 4UL))))
#define GPIOP_BITBANDING_ADCCTL_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_ADCCTL_OFFSET) * 32UL) + (GPIO_ADCCTL_R_PIN2_BIT * 4UL))))
#define GPIOP_BITBANDING_ADCCTL_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_ADCCTL_OFFSET) * 32UL) + (GPIO_ADCCTL_R_PIN3_BIT * 4UL))))
#define GPIOP_BITBANDING_ADCCTL_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_ADCCTL_OFFSET) * 32UL) + (GPIO_ADCCTL_R_PIN4_BIT * 4UL))))
#define GPIOP_BITBANDING_ADCCTL_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_ADCCTL_OFFSET) * 32UL) + (GPIO_ADCCTL_R_PIN5_BIT * 4UL))))
#define GPIOP_BITBANDING_ADCCTL_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_ADCCTL_OFFSET) * 32UL) + (GPIO_ADCCTL_R_PIN6_BIT * 4UL))))
#define GPIOP_BITBANDING_ADCCTL_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_ADCCTL_OFFSET) * 32UL) + (GPIO_ADCCTL_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 24 DMACTL *********************************************
 ******************************************************************************************/
/* GPIOP DMACTL*/
#define GPIOP_BITBANDING_DMACTL    ((GPIO_BITBANDING_DMACTL_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DMACTL_OFFSET) * 32UL)))

/* GPIOP DMACTL BITBANDING*/
#define GPIOP_BITBANDING_DMACTL_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DMACTL_OFFSET) * 32UL) + (GPIO_DMACTL_R_PIN0_BIT * 4UL))))
#define GPIOP_BITBANDING_DMACTL_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DMACTL_OFFSET) * 32UL) + (GPIO_DMACTL_R_PIN1_BIT * 4UL))))
#define GPIOP_BITBANDING_DMACTL_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DMACTL_OFFSET) * 32UL) + (GPIO_DMACTL_R_PIN2_BIT * 4UL))))
#define GPIOP_BITBANDING_DMACTL_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DMACTL_OFFSET) * 32UL) + (GPIO_DMACTL_R_PIN3_BIT * 4UL))))
#define GPIOP_BITBANDING_DMACTL_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DMACTL_OFFSET) * 32UL) + (GPIO_DMACTL_R_PIN4_BIT * 4UL))))
#define GPIOP_BITBANDING_DMACTL_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DMACTL_OFFSET) * 32UL) + (GPIO_DMACTL_R_PIN5_BIT * 4UL))))
#define GPIOP_BITBANDING_DMACTL_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DMACTL_OFFSET) * 32UL) + (GPIO_DMACTL_R_PIN6_BIT * 4UL))))
#define GPIOP_BITBANDING_DMACTL_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DMACTL_OFFSET) * 32UL) + (GPIO_DMACTL_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 25 SI *********************************************
 ******************************************************************************************/
/* GPIOP SI*/
#define GPIOP_BITBANDING_SI    ((GPIO_BITBANDING_SI_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_SI_OFFSET) * 32UL)))

/* GPIOP SI BITBANDING*/
#define GPIOP_BITBANDING_SI_SUM    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_SI_OFFSET) * 32UL) + (GPIO_SI_R_SUM_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 26 DR12R *********************************************
 ******************************************************************************************/
/* GPIOP DR12R*/
#define GPIOP_BITBANDING_DR12R    ((GPIO_BITBANDING_DR12R_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR12R_OFFSET) * 32UL)))

/* GPIOP DR12R BITBANDING*/
#define GPIOP_BITBANDING_DR12R_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR12R_OFFSET) * 32UL) + (GPIO_DR12R_R_PIN0_BIT * 4UL))))
#define GPIOP_BITBANDING_DR12R_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR12R_OFFSET) * 32UL) + (GPIO_DR12R_R_PIN1_BIT * 4UL))))
#define GPIOP_BITBANDING_DR12R_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR12R_OFFSET) * 32UL) + (GPIO_DR12R_R_PIN2_BIT * 4UL))))
#define GPIOP_BITBANDING_DR12R_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR12R_OFFSET) * 32UL) + (GPIO_DR12R_R_PIN3_BIT * 4UL))))
#define GPIOP_BITBANDING_DR12R_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR12R_OFFSET) * 32UL) + (GPIO_DR12R_R_PIN4_BIT * 4UL))))
#define GPIOP_BITBANDING_DR12R_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR12R_OFFSET) * 32UL) + (GPIO_DR12R_R_PIN5_BIT * 4UL))))
#define GPIOP_BITBANDING_DR12R_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR12R_OFFSET) * 32UL) + (GPIO_DR12R_R_PIN6_BIT * 4UL))))
#define GPIOP_BITBANDING_DR12R_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_DR12R_OFFSET) * 32UL) + (GPIO_DR12R_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 27 WAKEPEN *********************************************
 ******************************************************************************************/
/* GPIOP WAKEPEN*/
#define GPIOP_BITBANDING_WAKEPEN    ((GPIO_BITBANDING_WAKEPEN_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_WAKEPEN_OFFSET) * 32UL)))

/* GPIOP WAKEPEN BITBANDING*/
#define GPIOP_BITBANDING_WAKEPEN_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_WAKEPEN_OFFSET) * 32UL) + (GPIO_WAKEPEN_R_PIN4_BIT * 4UL))))
#define GPIOP_BITBANDING_WAKEPEN_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_WAKEPEN_OFFSET) * 32UL) + (GPIO_WAKEPEN_R_PIN5_BIT * 4UL))))
#define GPIOP_BITBANDING_WAKEPEN_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_WAKEPEN_OFFSET) * 32UL) + (GPIO_WAKEPEN_R_PIN6_BIT * 4UL))))
#define GPIOP_BITBANDING_WAKEPEN_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_WAKEPEN_OFFSET) * 32UL) + (GPIO_WAKEPEN_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 28 WAKELVL *********************************************
 ******************************************************************************************/
/* GPIOP WAKELVL*/
#define GPIOP_BITBANDING_WAKELVL    ((GPIO_BITBANDING_WAKELVL_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_WAKELVL_OFFSET) * 32UL)))

/* GPIOP WAKELVL BITBANDING*/
#define GPIOP_BITBANDING_WAKELVL_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_WAKELVL_OFFSET) * 32UL) + (GPIO_WAKELVL_R_PIN4_BIT * 4UL))))
#define GPIOP_BITBANDING_WAKELVL_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_WAKELVL_OFFSET) * 32UL) + (GPIO_WAKELVL_R_PIN5_BIT * 4UL))))
#define GPIOP_BITBANDING_WAKELVL_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_WAKELVL_OFFSET) * 32UL) + (GPIO_WAKELVL_R_PIN6_BIT * 4UL))))
#define GPIOP_BITBANDING_WAKELVL_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_WAKELVL_OFFSET) * 32UL) + (GPIO_WAKELVL_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 29 WAKESTAT *********************************************
 ******************************************************************************************/
/* GPIOP WAKESTAT*/
#define GPIOP_BITBANDING_WAKESTAT    ((GPIO_BITBANDING_WAKESTAT_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_WAKESTAT_OFFSET) * 32UL)))

/* GPIOP WAKESTAT BITBANDING*/
#define GPIOP_BITBANDING_WAKESTAT_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_WAKESTAT_OFFSET) * 32UL) + (GPIO_WAKESTAT_R_PIN4_BIT * 4UL))))
#define GPIOP_BITBANDING_WAKESTAT_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_WAKESTAT_OFFSET) * 32UL) + (GPIO_WAKESTAT_R_PIN5_BIT * 4UL))))
#define GPIOP_BITBANDING_WAKESTAT_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_WAKESTAT_OFFSET) * 32UL) + (GPIO_WAKESTAT_R_PIN6_BIT * 4UL))))
#define GPIOP_BITBANDING_WAKESTAT_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_WAKESTAT_OFFSET) * 32UL) + (GPIO_WAKESTAT_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 30 PP *********************************************
 ******************************************************************************************/
/* GPIOP PP*/
#define GPIOP_BITBANDING_PP    ((GPIO_BITBANDING_PP_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PP_OFFSET) * 32UL)))

/* GPIOP PP BITBANDING*/
#define GPIOP_BITBANDING_PP_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PP_OFFSET) * 32UL) + (GPIO_PP_R_PIN4_BIT * 4UL))))
#define GPIOP_BITBANDING_PP_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PP_OFFSET) * 32UL) + (GPIO_PP_R_PIN5_BIT * 4UL))))
#define GPIOP_BITBANDING_PP_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PP_OFFSET) * 32UL) + (GPIO_PP_R_PIN6_BIT * 4UL))))
#define GPIOP_BITBANDING_PP_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PP_OFFSET) * 32UL) + (GPIO_PP_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 31 PC *********************************************
 ******************************************************************************************/
/* GPIOP PC*/
#define GPIOP_BITBANDING_PC    ((GPIO_BITBANDING_PC_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PC_OFFSET) * 32UL)))

/* GPIOP PC BITBANDING*/
#define GPIOP_BITBANDING_PC_PIN0_0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN0_BIT + 0UL) * 4UL))))
#define GPIOP_BITBANDING_PC_PIN0_1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN0_BIT + 1UL) * 4UL))))
#define GPIOP_BITBANDING_PC_PIN1_0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN1_BIT + 0UL) * 4UL))))
#define GPIOP_BITBANDING_PC_PIN1_1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN1_BIT + 1UL) * 4UL))))
#define GPIOP_BITBANDING_PC_PIN2_0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN2_BIT + 0UL) * 4UL))))
#define GPIOP_BITBANDING_PC_PIN2_1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN2_BIT + 1UL) * 4UL))))
#define GPIOP_BITBANDING_PC_PIN3_0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN3_BIT + 0UL) * 4UL))))
#define GPIOP_BITBANDING_PC_PIN3_1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN3_BIT + 1UL) * 4UL))))
#define GPIOP_BITBANDING_PC_PIN4_0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN4_BIT + 0UL) * 4UL))))
#define GPIOP_BITBANDING_PC_PIN4_1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN4_BIT + 1UL) * 4UL))))
#define GPIOP_BITBANDING_PC_PIN5_0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN5_BIT + 0UL) * 4UL))))
#define GPIOP_BITBANDING_PC_PIN5_1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN5_BIT + 1UL) * 4UL))))
#define GPIOP_BITBANDING_PC_PIN6_0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN6_BIT + 0UL) * 4UL))))
#define GPIOP_BITBANDING_PC_PIN6_1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN6_BIT + 1UL) * 4UL))))
#define GPIOP_BITBANDING_PC_PIN7_0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN7_BIT + 0UL) * 4UL))))
#define GPIOP_BITBANDING_PC_PIN7_1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN7_BIT + 1UL) * 4UL))))

/******************************************************************************************
 *********************************** * 32 PeriphID4 *********************************************
 ******************************************************************************************/
/* GPIOP PID4*/
#define GPIOP_BITBANDING_PeriphID4    ((GPIO_BITBANDING_PeriphID4_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PeriphID4_OFFSET) * 32UL)))

/******************************************************************************************
 *********************************** * 33 PeriphID5 *********************************************
 ******************************************************************************************/
/* GPIOP PID5*/
#define GPIOP_BITBANDING_PeriphID5    ((GPIO_BITBANDING_PeriphID5_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PeriphID5_OFFSET) * 32UL)))

/******************************************************************************************
 *********************************** * 34 PeriphID6 *********************************************
 ******************************************************************************************/
/* GPIOP PID6*/
#define GPIOP_BITBANDING_PeriphID6    ((GPIO_BITBANDING_PeriphID6_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PeriphID6_OFFSET) * 32UL)))

/******************************************************************************************
 *********************************** * 35 PeriphID7 *********************************************
 ******************************************************************************************/
/* GPIOP PID7*/
#define GPIOP_BITBANDING_PeriphID7    ((GPIO_BITBANDING_PeriphID7_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PeriphID7_OFFSET) * 32UL)))

/******************************************************************************************
 *********************************** * 36 PeriphID0 *********************************************
 ******************************************************************************************/
/* GPIOP PID0*/
#define GPIOP_BITBANDING_PeriphID0    ((GPIO_BITBANDING_PeriphID0_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PeriphID0_OFFSET) * 32UL)))

/******************************************************************************************
 *********************************** * 37 PeriphID1 *********************************************
 ******************************************************************************************/
/* GPIOP PID1*/
#define GPIOP_BITBANDING_PeriphID1    ((GPIO_BITBANDING_PeriphID1_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PeriphID1_OFFSET) * 32UL)))

/******************************************************************************************
 *********************************** * 38 PeriphID2 *********************************************
 ******************************************************************************************/
/* GPIOP PID2*/
#define GPIOP_BITBANDING_PeriphID2    ((GPIO_BITBANDING_PeriphID2_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PeriphID2_OFFSET) * 32UL)))

/******************************************************************************************
 *********************************** * 39 PeriphID3 *********************************************
 ******************************************************************************************/
/* GPIOP PID3*/
#define GPIOP_BITBANDING_PeriphID3    ((GPIO_BITBANDING_PeriphID3_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PeriphID3_OFFSET) * 32UL)))

/******************************************************************************************
 *********************************** * 40 CellID0 *********************************************
 ******************************************************************************************/
/* GPIOP CID0*/
#define GPIOP_BITBANDING_PCellID0    ((GPIO_BITBANDING_PCellID0_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PCellID0_OFFSET) * 32UL)))

/******************************************************************************************
 *********************************** * 41 CellID1 *********************************************
 ******************************************************************************************/
/* GPIOP CID1*/
#define GPIOP_BITBANDING_PCellID1    ((GPIO_BITBANDING_PCellID1_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PCellID1_OFFSET) * 32UL)))

/******************************************************************************************
 *********************************** * 42 CellID2 *********************************************
 ******************************************************************************************/
/* GPIOP CID2*/
#define GPIOP_BITBANDING_PCellID2    ((GPIO_BITBANDING_PCellID2_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PCellID2_OFFSET) * 32UL)))

/******************************************************************************************
 *********************************** * 43 CellID3 *********************************************
 ******************************************************************************************/
/* GPIOP CID3*/
#define GPIOP_BITBANDING_PCellID3    ((GPIO_BITBANDING_PCellID3_t*) (GPIO_BITBANDING_BASE + ((GPIOP_OFFSET + GPIO_PCellID3_OFFSET) * 32UL)))

#endif /* XDRIVER_MCU_GPIO_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_BITBANDING_XHEADER_GPIO_REGISTERPERIPHERAL_BITBANDING_MODULEP_H_ */
