/**
 *
 * @file GPIO_RegisterPeripheral_Bitbanding_ModuleK.h
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

#ifndef XDRIVER_MCU_GPIO_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_BITBANDING_XHEADER_GPIO_REGISTERPERIPHERAL_BITBANDING_MODULEK_H_
#define XDRIVER_MCU_GPIO_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_BITBANDING_XHEADER_GPIO_REGISTERPERIPHERAL_BITBANDING_MODULEK_H_

#include <xDriver_MCU/GPIO/Peripheral/Register/xHeader/GPIO_RegisterAddress.h>
#include <xDriver_MCU/GPIO/Peripheral/Register/RegisterDefines/GPIO_RegisterDefines.h>
#include <xDriver_MCU/GPIO/Peripheral/Struct/xHeader/GPIO_StructPeripheral_Bitbanding.h>

#define GPIOK_BITBANDING    ((GPIO_BITBANDING_t*) (GPIO_BITBANDING_BASE + (GPIOK_OFFSET * 32UL)))
#define GPIOK_AUX_BITBANDING    ((GPIO_AUX_BITBANDING_t*) (GPIO_BITBANDING_BASE + (GPIOK_OFFSET * 32UL)))

/******************************************************************************************
 *********************************** * 1 DATA *********************************************
 ******************************************************************************************/

/* GPIOK DATA*/
#define GPIOK_BITBANDING_DATA_MASK    ((GPIO_BITBANDING_DATA_MASK_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DATA_MASK_OFFSET) * 32UL)))
#define GPIOK_BITBANDING_DATA    ((GPIO_BITBANDING_DATA_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DATA_OFFSET) * 32UL)))

/* GPIOK DATA BITBANDING*/
#define GPIOK_BITBANDING_DATA_PINMASK0_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DATA_PINMASK0_OFFSET) * 32UL) + (GPIO_DATA_R_PIN0_BIT * 4UL))))
#define GPIOK_BITBANDING_DATA_PINMASK1_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DATA_PINMASK1_OFFSET) * 32UL) + (GPIO_DATA_R_PIN1_BIT * 4UL))))
#define GPIOK_BITBANDING_DATA_PINMASK2_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DATA_PINMASK2_OFFSET) * 32UL) + (GPIO_DATA_R_PIN2_BIT * 4UL))))
#define GPIOK_BITBANDING_DATA_PINMASK3_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DATA_PINMASK3_OFFSET) * 32UL) + (GPIO_DATA_R_PIN3_BIT * 4UL))))
#define GPIOK_BITBANDING_DATA_PINMASK4_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DATA_PINMASK4_OFFSET) * 32UL) + (GPIO_DATA_R_PIN4_BIT * 4UL))))
#define GPIOK_BITBANDING_DATA_PINMASK5_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DATA_PINMASK5_OFFSET) * 32UL) + (GPIO_DATA_R_PIN5_BIT * 4UL))))
#define GPIOK_BITBANDING_DATA_PINMASK6_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DATA_PINMASK6_OFFSET) * 32UL) + (GPIO_DATA_R_PIN6_BIT * 4UL))))
#define GPIOK_BITBANDING_DATA_PINMASK7_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DATA_PINMASK7_OFFSET) * 32UL) + (GPIO_DATA_R_PIN7_BIT * 4UL))))

#define GPIOK_BITBANDING_DATA_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DATA_OFFSET) * 32UL) + (GPIO_DATA_R_PIN0_BIT * 4UL))))
#define GPIOK_BITBANDING_DATA_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DATA_OFFSET) * 32UL) + (GPIO_DATA_R_PIN1_BIT * 4UL))))
#define GPIOK_BITBANDING_DATA_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DATA_OFFSET) * 32UL) + (GPIO_DATA_R_PIN2_BIT * 4UL))))
#define GPIOK_BITBANDING_DATA_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DATA_OFFSET) * 32UL) + (GPIO_DATA_R_PIN3_BIT * 4UL))))
#define GPIOK_BITBANDING_DATA_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DATA_OFFSET) * 32UL) + (GPIO_DATA_R_PIN4_BIT * 4UL))))
#define GPIOK_BITBANDING_DATA_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DATA_OFFSET) * 32UL) + (GPIO_DATA_R_PIN5_BIT * 4UL))))
#define GPIOK_BITBANDING_DATA_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DATA_OFFSET) * 32UL) + (GPIO_DATA_R_PIN6_BIT * 4UL))))
#define GPIOK_BITBANDING_DATA_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DATA_OFFSET) * 32UL) + (GPIO_DATA_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 2 DIR *********************************************
 ******************************************************************************************/
/* GPIOK DIR*/
#define GPIOK_BITBANDING_DIR    ((GPIO_BITBANDING_DIR_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DIR_OFFSET) * 32UL)))

/* GPIOK DIR BITBANDING*/
#define GPIOK_BITBANDING_DIR_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DIR_OFFSET) * 32UL) + (GPIO_DIR_R_PIN0_BIT * 4UL))))
#define GPIOK_BITBANDING_DIR_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DIR_OFFSET) * 32UL) + (GPIO_DIR_R_PIN1_BIT * 4UL))))
#define GPIOK_BITBANDING_DIR_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DIR_OFFSET) * 32UL) + (GPIO_DIR_R_PIN2_BIT * 4UL))))
#define GPIOK_BITBANDING_DIR_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DIR_OFFSET) * 32UL) + (GPIO_DIR_R_PIN3_BIT * 4UL))))
#define GPIOK_BITBANDING_DIR_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DIR_OFFSET) * 32UL) + (GPIO_DIR_R_PIN4_BIT * 4UL))))
#define GPIOK_BITBANDING_DIR_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DIR_OFFSET) * 32UL) + (GPIO_DIR_R_PIN5_BIT * 4UL))))
#define GPIOK_BITBANDING_DIR_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DIR_OFFSET) * 32UL) + (GPIO_DIR_R_PIN6_BIT * 4UL))))
#define GPIOK_BITBANDING_DIR_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DIR_OFFSET) * 32UL) + (GPIO_DIR_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 3 IS *********************************************
 ******************************************************************************************/
/* GPIOK IS*/
#define GPIOK_BITBANDING_IS    ((GPIO_BITBANDING_IS_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IS_OFFSET) * 32UL)))

/* GPIOK IS BITBANDING*/
#define GPIOK_BITBANDING_IS_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IS_OFFSET) * 32UL) + (GPIO_IS_R_PIN0_BIT * 4UL))))
#define GPIOK_BITBANDING_IS_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IS_OFFSET) * 32UL) + (GPIO_IS_R_PIN1_BIT * 4UL))))
#define GPIOK_BITBANDING_IS_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IS_OFFSET) * 32UL) + (GPIO_IS_R_PIN2_BIT * 4UL))))
#define GPIOK_BITBANDING_IS_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IS_OFFSET) * 32UL) + (GPIO_IS_R_PIN3_BIT * 4UL))))
#define GPIOK_BITBANDING_IS_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IS_OFFSET) * 32UL) + (GPIO_IS_R_PIN4_BIT * 4UL))))
#define GPIOK_BITBANDING_IS_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IS_OFFSET) * 32UL) + (GPIO_IS_R_PIN5_BIT * 4UL))))
#define GPIOK_BITBANDING_IS_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IS_OFFSET) * 32UL) + (GPIO_IS_R_PIN6_BIT * 4UL))))
#define GPIOK_BITBANDING_IS_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IS_OFFSET) * 32UL) + (GPIO_IS_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 4 IBE *********************************************
 ******************************************************************************************/
/* GPIOK IBE*/
#define GPIOK_BITBANDING_IBE    ((GPIO_BITBANDING_IBE_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IBE_OFFSET) * 32UL)))

/* GPIOK IBE BITBANDING*/
#define GPIOK_BITBANDING_IBE_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IBE_OFFSET) * 32UL) + (GPIO_IBE_R_PIN0_BIT * 4UL))))
#define GPIOK_BITBANDING_IBE_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IBE_OFFSET) * 32UL) + (GPIO_IBE_R_PIN1_BIT * 4UL))))
#define GPIOK_BITBANDING_IBE_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IBE_OFFSET) * 32UL) + (GPIO_IBE_R_PIN2_BIT * 4UL))))
#define GPIOK_BITBANDING_IBE_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IBE_OFFSET) * 32UL) + (GPIO_IBE_R_PIN3_BIT * 4UL))))
#define GPIOK_BITBANDING_IBE_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IBE_OFFSET) * 32UL) + (GPIO_IBE_R_PIN4_BIT * 4UL))))
#define GPIOK_BITBANDING_IBE_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IBE_OFFSET) * 32UL) + (GPIO_IBE_R_PIN5_BIT * 4UL))))
#define GPIOK_BITBANDING_IBE_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IBE_OFFSET) * 32UL) + (GPIO_IBE_R_PIN6_BIT * 4UL))))
#define GPIOK_BITBANDING_IBE_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IBE_OFFSET) * 32UL) + (GPIO_IBE_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 5 IEV *********************************************
 ******************************************************************************************/
/* GPIOK IEV*/
#define GPIOK_BITBANDING_IEV    ((GPIO_BITBANDING_IEV_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IEV_OFFSET) * 32UL)))

/* GPIOK IEV BITBANDING*/
#define GPIOK_BITBANDING_IEV_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IEV_OFFSET) * 32UL) + (GPIO_IEV_R_PIN0_BIT * 4UL))))
#define GPIOK_BITBANDING_IEV_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IEV_OFFSET) * 32UL) + (GPIO_IEV_R_PIN1_BIT * 4UL))))
#define GPIOK_BITBANDING_IEV_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IEV_OFFSET) * 32UL) + (GPIO_IEV_R_PIN2_BIT * 4UL))))
#define GPIOK_BITBANDING_IEV_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IEV_OFFSET) * 32UL) + (GPIO_IEV_R_PIN3_BIT * 4UL))))
#define GPIOK_BITBANDING_IEV_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IEV_OFFSET) * 32UL) + (GPIO_IEV_R_PIN4_BIT * 4UL))))
#define GPIOK_BITBANDING_IEV_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IEV_OFFSET) * 32UL) + (GPIO_IEV_R_PIN5_BIT * 4UL))))
#define GPIOK_BITBANDING_IEV_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IEV_OFFSET) * 32UL) + (GPIO_IEV_R_PIN6_BIT * 4UL))))
#define GPIOK_BITBANDING_IEV_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IEV_OFFSET) * 32UL) + (GPIO_IEV_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 6 IM *********************************************
 ******************************************************************************************/
/* GPIOK IME*/
#define GPIOK_BITBANDING_IM    ((GPIO_BITBANDING_IM_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IM_OFFSET) * 32UL)))

/* GPIOK IME BITBANDING*/
#define GPIOK_BITBANDING_IM_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IM_OFFSET) * 32UL) + (GPIO_IM_R_PIN0_BIT * 4UL))))
#define GPIOK_BITBANDING_IM_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IM_OFFSET) * 32UL) + (GPIO_IM_R_PIN1_BIT * 4UL))))
#define GPIOK_BITBANDING_IM_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IM_OFFSET) * 32UL) + (GPIO_IM_R_PIN2_BIT * 4UL))))
#define GPIOK_BITBANDING_IM_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IM_OFFSET) * 32UL) + (GPIO_IM_R_PIN3_BIT * 4UL))))
#define GPIOK_BITBANDING_IM_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IM_OFFSET) * 32UL) + (GPIO_IM_R_PIN4_BIT * 4UL))))
#define GPIOK_BITBANDING_IM_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IM_OFFSET) * 32UL) + (GPIO_IM_R_PIN5_BIT * 4UL))))
#define GPIOK_BITBANDING_IM_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IM_OFFSET) * 32UL) + (GPIO_IM_R_PIN6_BIT * 4UL))))
#define GPIOK_BITBANDING_IM_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IM_OFFSET) * 32UL) + (GPIO_IM_R_PIN7_BIT * 4UL))))
#define GPIOK_BITBANDING_IM_DMAIME    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IM_OFFSET) * 32UL) + (GPIO_IM_R_DMAIME_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 7 RIS *********************************************
 ******************************************************************************************/
/* GPIOK RIS*/
#define GPIOK_BITBANDING_RIS    ((GPIO_BITBANDING_RIS_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_RIS_OFFSET) * 32UL)))

/* GPIOK RIS BITBANDING*/
#define GPIOK_BITBANDING_RIS_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_RIS_OFFSET) * 32UL) + (GPIO_RIS_R_PIN0_BIT * 4UL))))
#define GPIOK_BITBANDING_RIS_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_RIS_OFFSET) * 32UL) + (GPIO_RIS_R_PIN1_BIT * 4UL))))
#define GPIOK_BITBANDING_RIS_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_RIS_OFFSET) * 32UL) + (GPIO_RIS_R_PIN2_BIT * 4UL))))
#define GPIOK_BITBANDING_RIS_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_RIS_OFFSET) * 32UL) + (GPIO_RIS_R_PIN3_BIT * 4UL))))
#define GPIOK_BITBANDING_RIS_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_RIS_OFFSET) * 32UL) + (GPIO_RIS_R_PIN4_BIT * 4UL))))
#define GPIOK_BITBANDING_RIS_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_RIS_OFFSET) * 32UL) + (GPIO_RIS_R_PIN5_BIT * 4UL))))
#define GPIOK_BITBANDING_RIS_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_RIS_OFFSET) * 32UL) + (GPIO_RIS_R_PIN6_BIT * 4UL))))
#define GPIOK_BITBANDING_RIS_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_RIS_OFFSET) * 32UL) + (GPIO_RIS_R_PIN7_BIT * 4UL))))
#define GPIOK_BITBANDING_IM_DMARIS    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IM_OFFSET) * 32UL) + (GPIO_IM_R_DMARIS_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 8 MIS *********************************************
 ******************************************************************************************/
/* GPIOK MIS*/
#define GPIOK_BITBANDING_MIS    ((GPIO_BITBANDING_MIS_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_MIS_OFFSET) * 32UL)))

/* GPIOK MIS BITBANDING*/
#define GPIOK_BITBANDING_MIS_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_MIS_OFFSET) * 32UL) + (GPIO_MIS_R_PIN0_BIT * 4UL))))
#define GPIOK_BITBANDING_MIS_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_MIS_OFFSET) * 32UL) + (GPIO_MIS_R_PIN1_BIT * 4UL))))
#define GPIOK_BITBANDING_MIS_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_MIS_OFFSET) * 32UL) + (GPIO_MIS_R_PIN2_BIT * 4UL))))
#define GPIOK_BITBANDING_MIS_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_MIS_OFFSET) * 32UL) + (GPIO_MIS_R_PIN3_BIT * 4UL))))
#define GPIOK_BITBANDING_MIS_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_MIS_OFFSET) * 32UL) + (GPIO_MIS_R_PIN4_BIT * 4UL))))
#define GPIOK_BITBANDING_MIS_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_MIS_OFFSET) * 32UL) + (GPIO_MIS_R_PIN5_BIT * 4UL))))
#define GPIOK_BITBANDING_MIS_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_MIS_OFFSET) * 32UL) + (GPIO_MIS_R_PIN6_BIT * 4UL))))
#define GPIOK_BITBANDING_MIS_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_MIS_OFFSET) * 32UL) + (GPIO_MIS_R_PIN7_BIT * 4UL))))
#define GPIOK_BITBANDING_IM_DMAMIS    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IM_OFFSET) * 32UL) + (GPIO_IM_R_DMAMIS_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 9 ICR *********************************************
 ******************************************************************************************/
/* GPIOK IC*/
#define GPIOK_BITBANDING_ICR    ((GPIO_BITBANDING_ICR_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_ICR_OFFSET) * 32UL)))

/* GPIOK IC BITBANDING*/
#define GPIOK_BITBANDING_ICR_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_ICR_OFFSET) * 32UL) + (GPIO_ICR_R_PIN0_BIT * 4UL))))
#define GPIOK_BITBANDING_ICR_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_ICR_OFFSET) * 32UL) + (GPIO_ICR_R_PIN1_BIT * 4UL))))
#define GPIOK_BITBANDING_ICR_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_ICR_OFFSET) * 32UL) + (GPIO_ICR_R_PIN2_BIT * 4UL))))
#define GPIOK_BITBANDING_ICR_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_ICR_OFFSET) * 32UL) + (GPIO_ICR_R_PIN3_BIT * 4UL))))
#define GPIOK_BITBANDING_ICR_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_ICR_OFFSET) * 32UL) + (GPIO_ICR_R_PIN4_BIT * 4UL))))
#define GPIOK_BITBANDING_ICR_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_ICR_OFFSET) * 32UL) + (GPIO_ICR_R_PIN5_BIT * 4UL))))
#define GPIOK_BITBANDING_ICR_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_ICR_OFFSET) * 32UL) + (GPIO_ICR_R_PIN6_BIT * 4UL))))
#define GPIOK_BITBANDING_ICR_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_ICR_OFFSET) * 32UL) + (GPIO_ICR_R_PIN7_BIT * 4UL))))
#define GPIOK_BITBANDING_IM_DMAIC    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_IM_OFFSET) * 32UL) + (GPIO_IM_R_DMAIC_BIT * 4UL))))
/******************************************************************************************
 *********************************** * 10 AFSEL *********************************************
 ******************************************************************************************/
/* GPIOK AFSEL*/
#define GPIOK_BITBANDING_AFSEL    ((BITBANDING_GPIO_AFSEL_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_AFSEL_OFFSET) * 32UL)))

/* GPIOK AFSEL BITBANDING*/
#define GPIOK_BITBANDING_AFSEL_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_AFSEL_OFFSET) * 32UL) + (GPIO_AFSEL_R_PIN0_BIT * 4UL))))
#define GPIOK_BITBANDING_AFSEL_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_AFSEL_OFFSET) * 32UL) + (GPIO_AFSEL_R_PIN1_BIT * 4UL))))
#define GPIOK_BITBANDING_AFSEL_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_AFSEL_OFFSET) * 32UL) + (GPIO_AFSEL_R_PIN2_BIT * 4UL))))
#define GPIOK_BITBANDING_AFSEL_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_AFSEL_OFFSET) * 32UL) + (GPIO_AFSEL_R_PIN3_BIT * 4UL))))
#define GPIOK_BITBANDING_AFSEL_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_AFSEL_OFFSET) * 32UL) + (GPIO_AFSEL_R_PIN4_BIT * 4UL))))
#define GPIOK_BITBANDING_AFSEL_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_AFSEL_OFFSET) * 32UL) + (GPIO_AFSEL_R_PIN5_BIT * 4UL))))
#define GPIOK_BITBANDING_AFSEL_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_AFSEL_OFFSET) * 32UL) + (GPIO_AFSEL_R_PIN6_BIT * 4UL))))
#define GPIOK_BITBANDING_AFSEL_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_AFSEL_OFFSET) * 32UL) + (GPIO_AFSEL_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 11 DRR ARRAY *********************************************
 ******************************************************************************************/
/* GPIOK DRV2*/
#define GPIOK_BITBANDING_DRR    ((GPIO_BITBANDING_DRR_ARRAY_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR2R_OFFSET) * 32UL)))

/******************************************************************************************
 *********************************** * 11 DR2R *********************************************
 ******************************************************************************************/
/* GPIOK DRV2*/
#define GPIOK_BITBANDING_DR2R    ((GPIO_BITBANDING_DR2R_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR2R_OFFSET) * 32UL)))

/* GPIOK DRV2 BITBANDING*/
#define GPIOK_BITBANDING_DR2R_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR2R_OFFSET) * 32UL) + (GPIO_DR2R_R_PIN0_BIT * 4UL))))
#define GPIOK_BITBANDING_DR2R_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR2R_OFFSET) * 32UL) + (GPIO_DR2R_R_PIN1_BIT * 4UL))))
#define GPIOK_BITBANDING_DR2R_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR2R_OFFSET) * 32UL) + (GPIO_DR2R_R_PIN2_BIT * 4UL))))
#define GPIOK_BITBANDING_DR2R_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR2R_OFFSET) * 32UL) + (GPIO_DR2R_R_PIN3_BIT * 4UL))))
#define GPIOK_BITBANDING_DR2R_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR2R_OFFSET) * 32UL) + (GPIO_DR2R_R_PIN4_BIT * 4UL))))
#define GPIOK_BITBANDING_DR2R_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR2R_OFFSET) * 32UL) + (GPIO_DR2R_R_PIN5_BIT * 4UL))))
#define GPIOK_BITBANDING_DR2R_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR2R_OFFSET) * 32UL) + (GPIO_DR2R_R_PIN6_BIT * 4UL))))
#define GPIOK_BITBANDING_DR2R_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR2R_OFFSET) * 32UL) + (GPIO_DR2R_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 12 DR4R *********************************************
 ******************************************************************************************/
/* GPIOK DRV4*/
#define GPIOK_BITBANDING_DR4R    ((GPIO_BITBANDING_DR4R_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR4R_OFFSET) * 32UL)))

/* GPIOK DRV4 BITBANDING*/
#define GPIOK_BITBANDING_DR4R_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR4R_OFFSET) * 32UL) + (GPIO_DR4R_R_PIN0_BIT * 4UL))))
#define GPIOK_BITBANDING_DR4R_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR4R_OFFSET) * 32UL) + (GPIO_DR4R_R_PIN1_BIT * 4UL))))
#define GPIOK_BITBANDING_DR4R_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR4R_OFFSET) * 32UL) + (GPIO_DR4R_R_PIN2_BIT * 4UL))))
#define GPIOK_BITBANDING_DR4R_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR4R_OFFSET) * 32UL) + (GPIO_DR4R_R_PIN3_BIT * 4UL))))
#define GPIOK_BITBANDING_DR4R_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR4R_OFFSET) * 32UL) + (GPIO_DR4R_R_PIN4_BIT * 4UL))))
#define GPIOK_BITBANDING_DR4R_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR4R_OFFSET) * 32UL) + (GPIO_DR4R_R_PIN5_BIT * 4UL))))
#define GPIOK_BITBANDING_DR4R_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR4R_OFFSET) * 32UL) + (GPIO_DR4R_R_PIN6_BIT * 4UL))))
#define GPIOK_BITBANDING_DR4R_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR4R_OFFSET) * 32UL) + (GPIO_DR4R_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 13 DR8R *********************************************
 ******************************************************************************************/
/* GPIOK DRV8*/
#define GPIOK_BITBANDING_DR8R    ((GPIO_BITBANDING_DR8R_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR8R_OFFSET) * 32UL)))

/* GPIOK DRV8 BITBANDING*/
#define GPIOK_BITBANDING_DR8R_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR8R_OFFSET) * 32UL) + (GPIO_DR8R_R_PIN0_BIT * 4UL))))
#define GPIOK_BITBANDING_DR8R_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR8R_OFFSET) * 32UL) + (GPIO_DR8R_R_PIN1_BIT * 4UL))))
#define GPIOK_BITBANDING_DR8R_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR8R_OFFSET) * 32UL) + (GPIO_DR8R_R_PIN2_BIT * 4UL))))
#define GPIOK_BITBANDING_DR8R_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR8R_OFFSET) * 32UL) + (GPIO_DR8R_R_PIN3_BIT * 4UL))))
#define GPIOK_BITBANDING_DR8R_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR8R_OFFSET) * 32UL) + (GPIO_DR8R_R_PIN4_BIT * 4UL))))
#define GPIOK_BITBANDING_DR8R_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR8R_OFFSET) * 32UL) + (GPIO_DR8R_R_PIN5_BIT * 4UL))))
#define GPIOK_BITBANDING_DR8R_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR8R_OFFSET) * 32UL) + (GPIO_DR8R_R_PIN6_BIT * 4UL))))
#define GPIOK_BITBANDING_DR8R_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR8R_OFFSET) * 32UL) + (GPIO_DR8R_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 14 ODR *********************************************
 ******************************************************************************************/
/* GPIOK ODE*/
#define GPIOK_BITBANDING_ODR    ((GPIO_BITBANDING_ODR_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_ODR_OFFSET) * 32UL)))

/* GPIOK ODE BITBANDING*/
#define GPIOK_BITBANDING_ODR_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_ODR_OFFSET) * 32UL) + (GPIO_ODR_R_PIN0_BIT * 4UL))))
#define GPIOK_BITBANDING_ODR_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_ODR_OFFSET) * 32UL) + (GPIO_ODR_R_PIN1_BIT * 4UL))))
#define GPIOK_BITBANDING_ODR_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_ODR_OFFSET) * 32UL) + (GPIO_ODR_R_PIN2_BIT * 4UL))))
#define GPIOK_BITBANDING_ODR_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_ODR_OFFSET) * 32UL) + (GPIO_ODR_R_PIN3_BIT * 4UL))))
#define GPIOK_BITBANDING_ODR_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_ODR_OFFSET) * 32UL) + (GPIO_ODR_R_PIN4_BIT * 4UL))))
#define GPIOK_BITBANDING_ODR_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_ODR_OFFSET) * 32UL) + (GPIO_ODR_R_PIN5_BIT * 4UL))))
#define GPIOK_BITBANDING_ODR_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_ODR_OFFSET) * 32UL) + (GPIO_ODR_R_PIN6_BIT * 4UL))))
#define GPIOK_BITBANDING_ODR_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_ODR_OFFSET) * 32UL) + (GPIO_ODR_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 15 PUR *********************************************
 ******************************************************************************************/
/* GPIOK PUE*/
#define GPIOK_BITBANDING_PUR    ((GPIO_BITBANDING_PUR_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PUR_OFFSET) * 32UL)))

/* GPIOK PUE BITBANDING*/
#define GPIOK_BITBANDING_PUR_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PUR_OFFSET) * 32UL) + (GPIO_PUR_R_PIN0_BIT * 4UL))))
#define GPIOK_BITBANDING_PUR_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PUR_OFFSET) * 32UL) + (GPIO_PUR_R_PIN1_BIT * 4UL))))
#define GPIOK_BITBANDING_PUR_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PUR_OFFSET) * 32UL) + (GPIO_PUR_R_PIN2_BIT * 4UL))))
#define GPIOK_BITBANDING_PUR_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PUR_OFFSET) * 32UL) + (GPIO_PUR_R_PIN3_BIT * 4UL))))
#define GPIOK_BITBANDING_PUR_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PUR_OFFSET) * 32UL) + (GPIO_PUR_R_PIN4_BIT * 4UL))))
#define GPIOK_BITBANDING_PUR_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PUR_OFFSET) * 32UL) + (GPIO_PUR_R_PIN5_BIT * 4UL))))
#define GPIOK_BITBANDING_PUR_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PUR_OFFSET) * 32UL) + (GPIO_PUR_R_PIN6_BIT * 4UL))))
#define GPIOK_BITBANDING_PUR_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PUR_OFFSET) * 32UL) + (GPIO_PUR_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 16 PDR *********************************************
 ******************************************************************************************/
/* GPIOK PDE*/
#define GPIOK_BITBANDING_PDR    ((GPIO_BITBANDING_PDR_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PDR_OFFSET) * 32UL)))

/* GPIOK PDE BITBANDING*/
#define GPIOK_BITBANDING_PDR_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PDR_OFFSET) * 32UL) + (GPIO_PDR_R_PIN0_BIT * 4UL))))
#define GPIOK_BITBANDING_PDR_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PDR_OFFSET) * 32UL) + (GPIO_PDR_R_PIN1_BIT * 4UL))))
#define GPIOK_BITBANDING_PDR_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PDR_OFFSET) * 32UL) + (GPIO_PDR_R_PIN2_BIT * 4UL))))
#define GPIOK_BITBANDING_PDR_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PDR_OFFSET) * 32UL) + (GPIO_PDR_R_PIN3_BIT * 4UL))))
#define GPIOK_BITBANDING_PDR_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PDR_OFFSET) * 32UL) + (GPIO_PDR_R_PIN4_BIT * 4UL))))
#define GPIOK_BITBANDING_PDR_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PDR_OFFSET) * 32UL) + (GPIO_PDR_R_PIN5_BIT * 4UL))))
#define GPIOK_BITBANDING_PDR_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PDR_OFFSET) * 32UL) + (GPIO_PDR_R_PIN6_BIT * 4UL))))
#define GPIOK_BITBANDING_PDR_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PDR_OFFSET) * 32UL) + (GPIO_PDR_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 17 SLR *********************************************
 ******************************************************************************************/
/* GPIOK SLR*/
#define GPIOK_BITBANDING_SLR    ((GPIO_BITBANDING_SLR_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_SLR_OFFSET) * 32UL)))

/* GPIOK SLR BITBANDING*/
#define GPIOK_BITBANDING_SLR_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_SLR_OFFSET) * 32UL) + (GPIO_SLR_R_PIN0_BIT * 4UL))))
#define GPIOK_BITBANDING_SLR_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_SLR_OFFSET) * 32UL) + (GPIO_SLR_R_PIN1_BIT * 4UL))))
#define GPIOK_BITBANDING_SLR_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_SLR_OFFSET) * 32UL) + (GPIO_SLR_R_PIN2_BIT * 4UL))))
#define GPIOK_BITBANDING_SLR_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_SLR_OFFSET) * 32UL) + (GPIO_SLR_R_PIN3_BIT * 4UL))))
#define GPIOK_BITBANDING_SLR_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_SLR_OFFSET) * 32UL) + (GPIO_SLR_R_PIN4_BIT * 4UL))))
#define GPIOK_BITBANDING_SLR_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_SLR_OFFSET) * 32UL) + (GPIO_SLR_R_PIN5_BIT * 4UL))))
#define GPIOK_BITBANDING_SLR_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_SLR_OFFSET) * 32UL) + (GPIO_SLR_R_PIN6_BIT * 4UL))))
#define GPIOK_BITBANDING_SLR_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_SLR_OFFSET) * 32UL) + (GPIO_SLR_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 18 DEN *********************************************
 ******************************************************************************************/
/* GPIOK DEN*/
#define GPIOK_BITBANDING_DEN    ((GPIO_BITBANDING_DEN_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DEN_OFFSET) * 32UL)))

/* GPIOK DEN BITBANDING*/
#define GPIOK_BITBANDING_DEN_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DEN_OFFSET) * 32UL) + (GPIO_DEN_R_PIN0_BIT * 4UL))))
#define GPIOK_BITBANDING_DEN_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DEN_OFFSET) * 32UL) + (GPIO_DEN_R_PIN1_BIT * 4UL))))
#define GPIOK_BITBANDING_DEN_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DEN_OFFSET) * 32UL) + (GPIO_DEN_R_PIN2_BIT * 4UL))))
#define GPIOK_BITBANDING_DEN_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DEN_OFFSET) * 32UL) + (GPIO_DEN_R_PIN3_BIT * 4UL))))
#define GPIOK_BITBANDING_DEN_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DEN_OFFSET) * 32UL) + (GPIO_DEN_R_PIN4_BIT * 4UL))))
#define GPIOK_BITBANDING_DEN_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DEN_OFFSET) * 32UL) + (GPIO_DEN_R_PIN5_BIT * 4UL))))
#define GPIOK_BITBANDING_DEN_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DEN_OFFSET) * 32UL) + (GPIO_DEN_R_PIN6_BIT * 4UL))))
#define GPIOK_BITBANDING_DEN_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DEN_OFFSET) * 32UL) + (GPIO_DEN_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 19 LOCK *********************************************
 ******************************************************************************************/
/* GPIOK LOCK*/
#define GPIOK_BITBANDING_LOCK    ((GPIO_BITBANDING_LOCK_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_LOCK_OFFSET) * 32UL)))

/******************************************************************************************
 *********************************** * 20 CR *********************************************
 ******************************************************************************************/
/* GPIOK CR*/
#define GPIOK_BITBANDING_CR    ((GPIO_BITBANDING_CR_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_CR_OFFSET) * 32UL)))

/* GPIOK CR BITBANDING*/
#define GPIOK_BITBANDING_CR_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_CR_OFFSET) * 32UL) + (GPIO_CR_R_PIN0_BIT * 4UL))))
#define GPIOK_BITBANDING_CR_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_CR_OFFSET) * 32UL) + (GPIO_CR_R_PIN1_BIT * 4UL))))
#define GPIOK_BITBANDING_CR_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_CR_OFFSET) * 32UL) + (GPIO_CR_R_PIN2_BIT * 4UL))))
#define GPIOK_BITBANDING_CR_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_CR_OFFSET) * 32UL) + (GPIO_CR_R_PIN3_BIT * 4UL))))
#define GPIOK_BITBANDING_CR_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_CR_OFFSET) * 32UL) + (GPIO_CR_R_PIN4_BIT * 4UL))))
#define GPIOK_BITBANDING_CR_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_CR_OFFSET) * 32UL) + (GPIO_CR_R_PIN5_BIT * 4UL))))
#define GPIOK_BITBANDING_CR_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_CR_OFFSET) * 32UL) + (GPIO_CR_R_PIN6_BIT * 4UL))))
#define GPIOK_BITBANDING_CR_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_CR_OFFSET) * 32UL) + (GPIO_CR_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 21 AMSEL *********************************************
 ******************************************************************************************/
/* GPIOK AMSEL*/
#define GPIOK_BITBANDING_AMSEL    ((BITBANDING_GPIO_AMSEL_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_AMSEL_OFFSET) * 32UL)))

/* GPIOK AMSEL BITBANDING*/
#define GPIOK_BITBANDING_AMSEL_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_AMSEL_OFFSET) * 32UL) + (GPIO_AMSEL_R_PIN0_BIT * 4UL))))
#define GPIOK_BITBANDING_AMSEL_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_AMSEL_OFFSET) * 32UL) + (GPIO_AMSEL_R_PIN1_BIT * 4UL))))
#define GPIOK_BITBANDING_AMSEL_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_AMSEL_OFFSET) * 32UL) + (GPIO_AMSEL_R_PIN2_BIT * 4UL))))
#define GPIOK_BITBANDING_AMSEL_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_AMSEL_OFFSET) * 32UL) + (GPIO_AMSEL_R_PIN3_BIT * 4UL))))
#define GPIOK_BITBANDING_AMSEL_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_AMSEL_OFFSET) * 32UL) + (GPIO_AMSEL_R_PIN4_BIT * 4UL))))
#define GPIOK_BITBANDING_AMSEL_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_AMSEL_OFFSET) * 32UL) + (GPIO_AMSEL_R_PIN5_BIT * 4UL))))
#define GPIOK_BITBANDING_AMSEL_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_AMSEL_OFFSET) * 32UL) + (GPIO_AMSEL_R_PIN6_BIT * 4UL))))
#define GPIOK_BITBANDING_AMSEL_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_AMSEL_OFFSET) * 32UL) + (GPIO_AMSEL_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 22 PCTL *********************************************
 ******************************************************************************************/
/* GPIOK PCTL*/
#define GPIOK_BITBANDING_PCTL    ((GPIO_BITBANDING_PCTL_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PCTL_OFFSET) * 32UL)))

/******************************************************************************************
 *********************************** * 23 ADCCTL *********************************************
 ******************************************************************************************/
/* GPIOK ADCCTL*/
#define GPIOK_BITBANDING_ADCCTL    ((BITBANDING_GPIO_ADCCTL_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_ADCCTL_OFFSET) * 32UL)))

/* GPIOK ADCCTL BITBANDING*/
#define GPIOK_BITBANDING_ADCCTL_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_ADCCTL_OFFSET) * 32UL) + (GPIO_ADCCTL_R_PIN0_BIT * 4UL))))
#define GPIOK_BITBANDING_ADCCTL_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_ADCCTL_OFFSET) * 32UL) + (GPIO_ADCCTL_R_PIN1_BIT * 4UL))))
#define GPIOK_BITBANDING_ADCCTL_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_ADCCTL_OFFSET) * 32UL) + (GPIO_ADCCTL_R_PIN2_BIT * 4UL))))
#define GPIOK_BITBANDING_ADCCTL_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_ADCCTL_OFFSET) * 32UL) + (GPIO_ADCCTL_R_PIN3_BIT * 4UL))))
#define GPIOK_BITBANDING_ADCCTL_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_ADCCTL_OFFSET) * 32UL) + (GPIO_ADCCTL_R_PIN4_BIT * 4UL))))
#define GPIOK_BITBANDING_ADCCTL_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_ADCCTL_OFFSET) * 32UL) + (GPIO_ADCCTL_R_PIN5_BIT * 4UL))))
#define GPIOK_BITBANDING_ADCCTL_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_ADCCTL_OFFSET) * 32UL) + (GPIO_ADCCTL_R_PIN6_BIT * 4UL))))
#define GPIOK_BITBANDING_ADCCTL_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_ADCCTL_OFFSET) * 32UL) + (GPIO_ADCCTL_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 24 DMACTL *********************************************
 ******************************************************************************************/
/* GPIOK DMACTL*/
#define GPIOK_BITBANDING_DMACTL    ((GPIO_BITBANDING_DMACTL_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DMACTL_OFFSET) * 32UL)))

/* GPIOK DMACTL BITBANDING*/
#define GPIOK_BITBANDING_DMACTL_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DMACTL_OFFSET) * 32UL) + (GPIO_DMACTL_R_PIN0_BIT * 4UL))))
#define GPIOK_BITBANDING_DMACTL_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DMACTL_OFFSET) * 32UL) + (GPIO_DMACTL_R_PIN1_BIT * 4UL))))
#define GPIOK_BITBANDING_DMACTL_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DMACTL_OFFSET) * 32UL) + (GPIO_DMACTL_R_PIN2_BIT * 4UL))))
#define GPIOK_BITBANDING_DMACTL_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DMACTL_OFFSET) * 32UL) + (GPIO_DMACTL_R_PIN3_BIT * 4UL))))
#define GPIOK_BITBANDING_DMACTL_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DMACTL_OFFSET) * 32UL) + (GPIO_DMACTL_R_PIN4_BIT * 4UL))))
#define GPIOK_BITBANDING_DMACTL_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DMACTL_OFFSET) * 32UL) + (GPIO_DMACTL_R_PIN5_BIT * 4UL))))
#define GPIOK_BITBANDING_DMACTL_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DMACTL_OFFSET) * 32UL) + (GPIO_DMACTL_R_PIN6_BIT * 4UL))))
#define GPIOK_BITBANDING_DMACTL_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DMACTL_OFFSET) * 32UL) + (GPIO_DMACTL_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 25 SI *********************************************
 ******************************************************************************************/
/* GPIOK SI*/
#define GPIOK_BITBANDING_SI    ((GPIO_BITBANDING_SI_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_SI_OFFSET) * 32UL)))

/* GPIOK SI BITBANDING*/
#define GPIOK_BITBANDING_SI_SUM    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_SI_OFFSET) * 32UL) + (GPIO_SI_R_SUM_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 26 DR12R *********************************************
 ******************************************************************************************/
/* GPIOK DR12R*/
#define GPIOK_BITBANDING_DR12R    ((GPIO_BITBANDING_DR12R_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR12R_OFFSET) * 32UL)))

/* GPIOK DR12R BITBANDING*/
#define GPIOK_BITBANDING_DR12R_PIN0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR12R_OFFSET) * 32UL) + (GPIO_DR12R_R_PIN0_BIT * 4UL))))
#define GPIOK_BITBANDING_DR12R_PIN1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR12R_OFFSET) * 32UL) + (GPIO_DR12R_R_PIN1_BIT * 4UL))))
#define GPIOK_BITBANDING_DR12R_PIN2    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR12R_OFFSET) * 32UL) + (GPIO_DR12R_R_PIN2_BIT * 4UL))))
#define GPIOK_BITBANDING_DR12R_PIN3    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR12R_OFFSET) * 32UL) + (GPIO_DR12R_R_PIN3_BIT * 4UL))))
#define GPIOK_BITBANDING_DR12R_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR12R_OFFSET) * 32UL) + (GPIO_DR12R_R_PIN4_BIT * 4UL))))
#define GPIOK_BITBANDING_DR12R_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR12R_OFFSET) * 32UL) + (GPIO_DR12R_R_PIN5_BIT * 4UL))))
#define GPIOK_BITBANDING_DR12R_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR12R_OFFSET) * 32UL) + (GPIO_DR12R_R_PIN6_BIT * 4UL))))
#define GPIOK_BITBANDING_DR12R_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_DR12R_OFFSET) * 32UL) + (GPIO_DR12R_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 27 WAKEPEN *********************************************
 ******************************************************************************************/
/* GPIOK WAKEPEN*/
#define GPIOK_BITBANDING_WAKEPEN    ((GPIO_BITBANDING_WAKEPEN_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_WAKEPEN_OFFSET) * 32UL)))

/* GPIOK WAKEPEN BITBANDING*/
#define GPIOK_BITBANDING_WAKEPEN_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_WAKEPEN_OFFSET) * 32UL) + (GPIO_WAKEPEN_R_PIN4_BIT * 4UL))))
#define GPIOK_BITBANDING_WAKEPEN_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_WAKEPEN_OFFSET) * 32UL) + (GPIO_WAKEPEN_R_PIN5_BIT * 4UL))))
#define GPIOK_BITBANDING_WAKEPEN_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_WAKEPEN_OFFSET) * 32UL) + (GPIO_WAKEPEN_R_PIN6_BIT * 4UL))))
#define GPIOK_BITBANDING_WAKEPEN_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_WAKEPEN_OFFSET) * 32UL) + (GPIO_WAKEPEN_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 28 WAKELVL *********************************************
 ******************************************************************************************/
/* GPIOK WAKELVL*/
#define GPIOK_BITBANDING_WAKELVL    ((GPIO_BITBANDING_WAKELVL_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_WAKELVL_OFFSET) * 32UL)))

/* GPIOK WAKELVL BITBANDING*/
#define GPIOK_BITBANDING_WAKELVL_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_WAKELVL_OFFSET) * 32UL) + (GPIO_WAKELVL_R_PIN4_BIT * 4UL))))
#define GPIOK_BITBANDING_WAKELVL_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_WAKELVL_OFFSET) * 32UL) + (GPIO_WAKELVL_R_PIN5_BIT * 4UL))))
#define GPIOK_BITBANDING_WAKELVL_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_WAKELVL_OFFSET) * 32UL) + (GPIO_WAKELVL_R_PIN6_BIT * 4UL))))
#define GPIOK_BITBANDING_WAKELVL_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_WAKELVL_OFFSET) * 32UL) + (GPIO_WAKELVL_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 29 WAKESTAT *********************************************
 ******************************************************************************************/
/* GPIOK WAKESTAT*/
#define GPIOK_BITBANDING_WAKESTAT    ((GPIO_BITBANDING_WAKESTAT_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_WAKESTAT_OFFSET) * 32UL)))

/* GPIOK WAKESTAT BITBANDING*/
#define GPIOK_BITBANDING_WAKESTAT_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_WAKESTAT_OFFSET) * 32UL) + (GPIO_WAKESTAT_R_PIN4_BIT * 4UL))))
#define GPIOK_BITBANDING_WAKESTAT_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_WAKESTAT_OFFSET) * 32UL) + (GPIO_WAKESTAT_R_PIN5_BIT * 4UL))))
#define GPIOK_BITBANDING_WAKESTAT_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_WAKESTAT_OFFSET) * 32UL) + (GPIO_WAKESTAT_R_PIN6_BIT * 4UL))))
#define GPIOK_BITBANDING_WAKESTAT_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_WAKESTAT_OFFSET) * 32UL) + (GPIO_WAKESTAT_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 30 PP *********************************************
 ******************************************************************************************/
/* GPIOK PP*/
#define GPIOK_BITBANDING_PP    ((GPIO_BITBANDING_PP_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PP_OFFSET) * 32UL)))

/* GPIOK PP BITBANDING*/
#define GPIOK_BITBANDING_PP_PIN4    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PP_OFFSET) * 32UL) + (GPIO_PP_R_PIN4_BIT * 4UL))))
#define GPIOK_BITBANDING_PP_PIN5    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PP_OFFSET) * 32UL) + (GPIO_PP_R_PIN5_BIT * 4UL))))
#define GPIOK_BITBANDING_PP_PIN6    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PP_OFFSET) * 32UL) + (GPIO_PP_R_PIN6_BIT * 4UL))))
#define GPIOK_BITBANDING_PP_PIN7    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PP_OFFSET) * 32UL) + (GPIO_PP_R_PIN7_BIT * 4UL))))

/******************************************************************************************
 *********************************** * 31 PC *********************************************
 ******************************************************************************************/
/* GPIOK PC*/
#define GPIOK_BITBANDING_PC    ((GPIO_BITBANDING_PC_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PC_OFFSET) * 32UL)))

/* GPIOK PC BITBANDING*/
#define GPIOK_BITBANDING_PC_PIN0_0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN0_BIT + 0UL) * 4UL))))
#define GPIOK_BITBANDING_PC_PIN0_1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN0_BIT + 1UL) * 4UL))))
#define GPIOK_BITBANDING_PC_PIN1_0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN1_BIT + 0UL) * 4UL))))
#define GPIOK_BITBANDING_PC_PIN1_1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN1_BIT + 1UL) * 4UL))))
#define GPIOK_BITBANDING_PC_PIN2_0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN2_BIT + 0UL) * 4UL))))
#define GPIOK_BITBANDING_PC_PIN2_1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN2_BIT + 1UL) * 4UL))))
#define GPIOK_BITBANDING_PC_PIN3_0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN3_BIT + 0UL) * 4UL))))
#define GPIOK_BITBANDING_PC_PIN3_1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN3_BIT + 1UL) * 4UL))))
#define GPIOK_BITBANDING_PC_PIN4_0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN4_BIT + 0UL) * 4UL))))
#define GPIOK_BITBANDING_PC_PIN4_1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN4_BIT + 1UL) * 4UL))))
#define GPIOK_BITBANDING_PC_PIN5_0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN5_BIT + 0UL) * 4UL))))
#define GPIOK_BITBANDING_PC_PIN5_1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN5_BIT + 1UL) * 4UL))))
#define GPIOK_BITBANDING_PC_PIN6_0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN6_BIT + 0UL) * 4UL))))
#define GPIOK_BITBANDING_PC_PIN6_1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN6_BIT + 1UL) * 4UL))))
#define GPIOK_BITBANDING_PC_PIN7_0    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN7_BIT + 0UL) * 4UL))))
#define GPIOK_BITBANDING_PC_PIN7_1    (*((volatile UBase_t *) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PC_OFFSET) * 32UL) + ((GPIO_PC_R_PIN7_BIT + 1UL) * 4UL))))

/******************************************************************************************
 *********************************** * 32 PeriphID4 *********************************************
 ******************************************************************************************/
/* GPIOK PID4*/
#define GPIOK_BITBANDING_PeriphID4    ((GPIO_BITBANDING_PeriphID4_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PeriphID4_OFFSET) * 32UL)))

/******************************************************************************************
 *********************************** * 33 PeriphID5 *********************************************
 ******************************************************************************************/
/* GPIOK PID5*/
#define GPIOK_BITBANDING_PeriphID5    ((GPIO_BITBANDING_PeriphID5_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PeriphID5_OFFSET) * 32UL)))

/******************************************************************************************
 *********************************** * 34 PeriphID6 *********************************************
 ******************************************************************************************/
/* GPIOK PID6*/
#define GPIOK_BITBANDING_PeriphID6    ((GPIO_BITBANDING_PeriphID6_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PeriphID6_OFFSET) * 32UL)))

/******************************************************************************************
 *********************************** * 35 PeriphID7 *********************************************
 ******************************************************************************************/
/* GPIOK PID7*/
#define GPIOK_BITBANDING_PeriphID7    ((GPIO_BITBANDING_PeriphID7_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PeriphID7_OFFSET) * 32UL)))

/******************************************************************************************
 *********************************** * 36 PeriphID0 *********************************************
 ******************************************************************************************/
/* GPIOK PID0*/
#define GPIOK_BITBANDING_PeriphID0    ((GPIO_BITBANDING_PeriphID0_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PeriphID0_OFFSET) * 32UL)))

/******************************************************************************************
 *********************************** * 37 PeriphID1 *********************************************
 ******************************************************************************************/
/* GPIOK PID1*/
#define GPIOK_BITBANDING_PeriphID1    ((GPIO_BITBANDING_PeriphID1_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PeriphID1_OFFSET) * 32UL)))

/******************************************************************************************
 *********************************** * 38 PeriphID2 *********************************************
 ******************************************************************************************/
/* GPIOK PID2*/
#define GPIOK_BITBANDING_PeriphID2    ((GPIO_BITBANDING_PeriphID2_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PeriphID2_OFFSET) * 32UL)))

/******************************************************************************************
 *********************************** * 39 PeriphID3 *********************************************
 ******************************************************************************************/
/* GPIOK PID3*/
#define GPIOK_BITBANDING_PeriphID3    ((GPIO_BITBANDING_PeriphID3_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PeriphID3_OFFSET) * 32UL)))

/******************************************************************************************
 *********************************** * 40 CellID0 *********************************************
 ******************************************************************************************/
/* GPIOK CID0*/
#define GPIOK_BITBANDING_PCellID0    ((GPIO_BITBANDING_PCellID0_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PCellID0_OFFSET) * 32UL)))

/******************************************************************************************
 *********************************** * 41 CellID1 *********************************************
 ******************************************************************************************/
/* GPIOK CID1*/
#define GPIOK_BITBANDING_PCellID1    ((GPIO_BITBANDING_PCellID1_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PCellID1_OFFSET) * 32UL)))

/******************************************************************************************
 *********************************** * 42 CellID2 *********************************************
 ******************************************************************************************/
/* GPIOK CID2*/
#define GPIOK_BITBANDING_PCellID2    ((GPIO_BITBANDING_PCellID2_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PCellID2_OFFSET) * 32UL)))

/******************************************************************************************
 *********************************** * 43 CellID3 *********************************************
 ******************************************************************************************/
/* GPIOK CID3*/
#define GPIOK_BITBANDING_PCellID3    ((GPIO_BITBANDING_PCellID3_t*) (GPIO_BITBANDING_BASE + ((GPIOK_OFFSET + GPIO_PCellID3_OFFSET) * 32UL)))

#endif /* XDRIVER_MCU_GPIO_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_BITBANDING_XHEADER_GPIO_REGISTERPERIPHERAL_BITBANDING_MODULEK_H_ */
