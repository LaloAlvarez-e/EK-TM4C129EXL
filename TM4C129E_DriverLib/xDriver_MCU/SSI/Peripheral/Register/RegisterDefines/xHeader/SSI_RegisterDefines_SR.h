/**
 *
 * @file SSI_RegisterDefines_SR.h
 * @copyright
 * @verbatim InDeviceMex 2020 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 17 feb. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 17 feb. 2021     vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_SSI_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_SSI_REGISTERDEFINES_SR_H_
#define XDRIVER_MCU_SSI_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_SSI_REGISTERDEFINES_SR_H_

#include <xDriver_MCU/SSI/Peripheral/xHeader/SSI_Enum.h>

/******************************************************************************************
************************************ 4 SR *********************************************
******************************************************************************************/

/*--------*/
#define SSI_SR_R_TFE_MASK    ((UBase_t) 0x00000001UL)
#define SSI_SR_R_TFE_BIT    ((UBase_t) 0UL)
#define SSI_SR_R_TFE_NOEMPTY    ((UBase_t) 0x00000000UL)
#define SSI_SR_R_TFE_EMPTY    ((UBase_t) 0x00000001UL)

#define SSI_SR_TFE_MASK    ((UBase_t) 0x00000001UL)
#define SSI_SR_TFE_NOEMPTY    ((UBase_t) 0x00000000UL)
#define SSI_SR_TFE_EMPTY    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define SSI_SR_R_TNF_MASK    ((UBase_t) 0x00000002UL)
#define SSI_SR_R_TNF_BIT    ((UBase_t) 1UL)
#define SSI_SR_R_TNF_FULL    ((UBase_t) 0x00000000UL)
#define SSI_SR_R_TNF_NOFULL    ((UBase_t) 0x00000002UL)

#define SSI_SR_TNF_MASK    ((UBase_t) 0x00000001UL)
#define SSI_SR_TNF_FULL    ((UBase_t) 0x00000000UL)
#define SSI_SR_TNF_NOFULL    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define SSI_SR_R_RNE_MASK    ((UBase_t) 0x00000004UL)
#define SSI_SR_R_RNE_BIT    ((UBase_t) 2UL)
#define SSI_SR_R_RNE_EMPTY    ((UBase_t) 0x00000000UL)
#define SSI_SR_R_RNE_NOEMPTY    ((UBase_t) 0x00000004UL)

#define SSI_SR_RNE_MASK    ((UBase_t) 0x00000001UL)
#define SSI_SR_RNE_EMPTY    ((UBase_t) 0x00000000UL)
#define SSI_SR_RNE_NOEMPTY    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define SSI_SR_R_RFF_MASK    ((UBase_t) 0x0000008UL)
#define SSI_SR_R_RFF_BIT    ((UBase_t) 3UL)
#define SSI_SR_R_RFF_NOFULL    ((UBase_t) 0x00000000UL)
#define SSI_SR_R_RFF_FULL    ((UBase_t) 0x00000008UL)

#define SSI_SR_RFF_MASK    ((UBase_t) 0x00000001UL)
#define SSI_SR_RFF_NOFULL    ((UBase_t) 0x00000000UL)
#define SSI_SR_RFF_FULL    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define SSI_SR_R_BSY_MASK    ((UBase_t) 0x00000010UL)
#define SSI_SR_R_BSY_BIT    ((UBase_t) 4UL)
#define SSI_SR_R_BSY_IDLE    ((UBase_t) 0x00000000UL)
#define SSI_SR_R_BSY_BSY    ((UBase_t) 0x00000010UL)

#define SSI_SR_BSY_MASK    ((UBase_t) 0x00000001UL)
#define SSI_SR_BSY_IDLE    ((UBase_t) 0x00000000UL)
#define SSI_SR_BSY_BSY    ((UBase_t) 0x00000001UL)
/*--------*/

#endif /* XDRIVER_MCU_SSI_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_SSI_REGISTERDEFINES_SR_H_ */
