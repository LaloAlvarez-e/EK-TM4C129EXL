/**
 *
 * @file PWM_RegisterAddress.h
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
 * @verbatim 23 dic. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 23 dic. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_PWM_PERIPHERAL_REGISTER_XHEADER_PWM_REGISTERADDRESS_H_
#define XDRIVER_MCU_PWM_PERIPHERAL_REGISTER_XHEADER_PWM_REGISTERADDRESS_H_

#include <xDriver_MCU/Common/xHeader/MCU_Variables.h>

#define PWM_GEN_REGISTER_NUM    ((uint32_t) 16UL)
#define PWM_GEN_EXT_REGISTER_NUM    ((uint32_t) 32UL)

#define PWM_BASE    ((uint32_t) 0x40028000UL)
#define PWM0_BASE    ((uint32_t) 0x40028000UL)

#define PWM_OFFSET    ((uint32_t) 0x00028000UL)
#define PWM0_OFFSET    ((uint32_t) 0x00028000UL)

#define PWM_BITBANDING_BASE    ((uint32_t) 0x42000000UL)

#define PWM_CTL_OFFSET    ((uint32_t) 0x0000UL)
#define PWM_SYNC_OFFSET    ((uint32_t) 0x0004UL)
#define PWM_ENABLE_OFFSET    ((uint32_t) 0x0008UL)
#define PWM_INVERT_OFFSET    ((uint32_t) 0x000CUL)
#define PWM_FAULT_OFFSET    ((uint32_t) 0x0010UL)
#define PWM_INTEN_OFFSET    ((uint32_t) 0x0014UL)
#define PWM_RIS_OFFSET    ((uint32_t) 0x0018UL)
#define PWM_ISC_OFFSET    ((uint32_t) 0x001CUL)
#define PWM_STATUS_OFFSET    ((uint32_t) 0x0020UL)
#define PWM_FAULTVAL_OFFSET    ((uint32_t) 0x0024UL)
#define PWM_ENUPD_OFFSET    ((uint32_t) 0x0028UL)

#define PWM_GEN_CTL_OFFSET    ((uint32_t) 0x0000UL)
#define PWM_GEN_INTEN_OFFSET    ((uint32_t) 0x0004UL)
#define PWM_GEN_RIS_OFFSET    ((uint32_t) 0x0008UL)
#define PWM_GEN_ISC_OFFSET    ((uint32_t) 0x000CUL)
#define PWM_GEN_LOAD_OFFSET    ((uint32_t) 0x0010UL)
#define PWM_GEN_COUNT_OFFSET    ((uint32_t) 0x0014UL)
#define PWM_GEN_CMPA_OFFSET    ((uint32_t) 0x0018UL)
#define PWM_GEN_CMPB_OFFSET    ((uint32_t) 0x001CUL)
#define PWM_GEN_GENA_OFFSET    ((uint32_t) 0x0020UL)
#define PWM_GEN_GENB_OFFSET    ((uint32_t) 0x0024UL)
#define PWM_GEN_DBCTL_OFFSET    ((uint32_t) 0x0028UL)
#define PWM_GEN_DBRISE_OFFSET    ((uint32_t) 0x002CUL)
#define PWM_GEN_DBFALL_OFFSET    ((uint32_t) 0x0030UL)
#define PWM_GEN_FLTSRC0_OFFSET    ((uint32_t) 0x0034UL)
#define PWM_GEN_FLTSRC1_OFFSET    ((uint32_t) 0x0038UL)
#define PWM_GEN_MINFLTPER_OFFSET    ((uint32_t) 0x003CUL)

#define PWM_GEN_REGISTER_BASE_OFFSET    ((uint32_t) 0x0040UL)
#define PWM_GEN_REGISTER_OFFSET    ((uint32_t) 0x0040UL)

#define PWM_GEN0_CTL_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 0UL) + PWM_GEN_CTL_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN0_INTEN_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 0UL) + PWM_GEN_INTEN_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN0_RIS_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 0UL) + PWM_GEN_RIS_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN0_ISC_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 0UL) + PWM_GEN_ISC_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN0_LOAD_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 0UL) + PWM_GEN_LOAD_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN0_COUNT_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 0UL) + PWM_GEN_COUNT_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN0_CMPA_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 0UL) + PWM_GEN_CMPA_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN0_CMPB_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 0UL) + PWM_GEN_CMPB_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN0_GENA_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 0UL) + PWM_GEN_GENA_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN0_GENB_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 0UL) + PWM_GEN_GENB_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN0_DBCTL_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 0UL) + PWM_GEN_DBCTL_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN0_DBRISE_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 0UL) + PWM_GEN_DBRISE_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN0_DBFALL_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 0UL) + PWM_GEN_DBFALL_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN0_FLTSRC0_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 0UL) + PWM_GEN_FLTSRC0_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN0_FLTSRC1_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 0UL) + PWM_GEN_FLTSRC1_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN0_MINFLTPER_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 0UL) + PWM_GEN_MINFLPER_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))

#define PWM_GEN1_CTL_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 1UL) + PWM_GEN_CTL_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN1_INTEN_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 1UL) + PWM_GEN_INTEN_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN1_RIS_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 1UL) + PWM_GEN_RIS_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN1_ISC_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 1UL) + PWM_GEN_ISC_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN1_LOAD_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 1UL) + PWM_GEN_LOAD_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN1_COUNT_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 1UL) + PWM_GEN_COUNT_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN1_CMPA_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 1UL) + PWM_GEN_CMPA_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN1_CMPB_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 1UL) + PWM_GEN_CMPB_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN1_GENA_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 1UL) + PWM_GEN_GENA_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN1_GENB_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 1UL) + PWM_GEN_GENB_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN1_DBCTL_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 1UL) + PWM_GEN_DBCTL_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN1_DBRISE_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 1UL) + PWM_GEN_DBRISE_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN1_DBFALL_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 1UL) + PWM_GEN_DBFALL_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN1_FLTSRC0_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 1UL) + PWM_GEN_FLTSRC0_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN1_FLTSRC1_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 1UL) + PWM_GEN_FLTSRC1_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN1_MINFLTPER_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 1UL) + PWM_GEN_MINFLPER_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))

#define PWM_GEN2_CTL_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 2UL) + PWM_GEN_CTL_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN2_INTEN_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 2UL) + PWM_GEN_INTEN_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN2_RIS_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 2UL) + PWM_GEN_RIS_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN2_ISC_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 2UL) + PWM_GEN_ISC_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN2_LOAD_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 2UL) + PWM_GEN_LOAD_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN2_COUNT_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 2UL) + PWM_GEN_COUNT_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN2_CMPA_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 2UL) + PWM_GEN_CMPA_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN2_CMPB_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 2UL) + PWM_GEN_CMPB_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN2_GENA_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 2UL) + PWM_GEN_GENA_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN2_GENB_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 2UL) + PWM_GEN_GENB_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN2_DBCTL_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 2UL) + PWM_GEN_DBCTL_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN2_DBRISE_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 2UL) + PWM_GEN_DBRISE_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN2_DBFALL_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 2UL) + PWM_GEN_DBFALL_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN2_FLTSRC0_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 2UL) + PWM_GEN_FLTSRC0_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN2_FLTSRC1_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 2UL) + PWM_GEN_FLTSRC1_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN2_MINFLTPER_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 2UL) + PWM_GEN_MINFLPER_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))

#define PWM_GEN3_CTL_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 3UL) + PWM_GEN_CTL_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN3_INTEN_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 3UL) + PWM_GEN_INTEN_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN3_RIS_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 3UL) + PWM_GEN_RIS_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN3_ISC_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 3UL) + PWM_GEN_ISC_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN3_LOAD_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 3UL) + PWM_GEN_LOAD_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN3_COUNT_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 3UL) + PWM_GEN_COUNT_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN3_CMPA_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 3UL) + PWM_GEN_CMPA_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN3_CMPB_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 3UL) + PWM_GEN_CMPB_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN3_GENA_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 3UL) + PWM_GEN_GENA_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN3_GENB_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 3UL) + PWM_GEN_GENB_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN3_DBCTL_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 3UL) + PWM_GEN_DBCTL_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN3_DBRISE_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 3UL) + PWM_GEN_DBRISE_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN3_DBFALL_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 3UL) + PWM_GEN_DBFALL_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN3_FLTSRC0_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 3UL) + PWM_GEN_FLTSRC0_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN3_FLTSRC1_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 3UL) + PWM_GEN_FLTSRC1_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))
#define PWM_GEN3_MINFLTPER_OFFSET    ((uint32_t) ((PWM_GEN_REGISTER_OFFSET * 3UL) + PWM_GEN_MINFLPER_OFFSET + PWM_GEN_REGISTER_BASE_OFFSET))

#define PWM_GEN_EXT_FLTSEN_OFFSET    ((uint32_t) 0x0000UL)
#define PWM_GEN_EXT_FLTSTAT0_OFFSET    ((uint32_t) 0x0004UL)
#define PWM_GEN_EXT_FLTSTAT1_OFFSET    ((uint32_t) 0x0008UL)

#define PWM_GEN_EXT_REGISTER_BASE_OFFSET    ((uint32_t) 0x0800UL)
#define PWM_GEN_EXT_REGISTER_OFFSET    ((uint32_t) 0x0080UL)

#define PWM_GEN0_EXT_FLTSEN_OFFSET    ((uint32_t) ((PWM_GEN_EXT_REGISTER_OFFSET * 0UL) + PWM_GEN_EXT_FLTSEN_OFFSET + PWM_GEN_EXT_REGISTER_BASE_OFFSET))
#define PWM_GEN0_EXT_FLTSTAT0_OFFSET    ((uint32_t) ((PWM_GEN_EXT_REGISTER_OFFSET * 0UL) + PWM_GEN_EXT_FLTSTAT0_OFFSET + PWM_GEN_EXT_REGISTER_BASE_OFFSET))
#define PWM_GEN0_EXT_FLTSTAT1_OFFSET    ((uint32_t) ((PWM_GEN_EXT_REGISTER_OFFSET * 0UL) + PWM_GEN_EXT_FLTSTAT1_OFFSET + PWM_GEN_EXT_REGISTER_BASE_OFFSET))

#define PWM_GEN1_EXT_FLTSEN_OFFSET    ((uint32_t) ((PWM_GEN_EXT_REGISTER_OFFSET * 1UL) + PWM_GEN_EXT_FLTSEN_OFFSET + PWM_GEN_EXT_REGISTER_BASE_OFFSET))
#define PWM_GEN1_EXT_FLTSTAT0_OFFSET    ((uint32_t) ((PWM_GEN_EXT_REGISTER_OFFSET * 1UL) + PWM_GEN_EXT_FLTSTAT0_OFFSET + PWM_GEN_EXT_REGISTER_BASE_OFFSET))
#define PWM_GEN1_EXT_FLTSTAT1_OFFSET    ((uint32_t) ((PWM_GEN_EXT_REGISTER_OFFSET * 1UL) + PWM_GEN_EXT_FLTSTAT1_OFFSET + PWM_GEN_EXT_REGISTER_BASE_OFFSET))

#define PWM_GEN2_EXT_FLTSEN_OFFSET    ((uint32_t) ((PWM_GEN_EXT_REGISTER_OFFSET * 2UL) + PWM_GEN_EXT_FLTSEN_OFFSET + PWM_GEN_EXT_REGISTER_BASE_OFFSET))
#define PWM_GEN2_EXT_FLTSTAT0_OFFSET    ((uint32_t) ((PWM_GEN_EXT_REGISTER_OFFSET * 2UL) + PWM_GEN_EXT_FLTSTAT0_OFFSET + PWM_GEN_EXT_REGISTER_BASE_OFFSET))
#define PWM_GEN2_EXT_FLTSTAT1_OFFSET    ((uint32_t) ((PWM_GEN_EXT_REGISTER_OFFSET * 2UL) + PWM_GEN_EXT_FLTSTAT1_OFFSET + PWM_GEN_EXT_REGISTER_BASE_OFFSET))

#define PWM_GEN3_EXT_FLTSEN_OFFSET    ((uint32_t) ((PWM_GEN_EXT_REGISTER_OFFSET * 3UL) + PWM_GEN_EXT_FLTSEN_OFFSET + PWM_GEN_EXT_REGISTER_BASE_OFFSET))
#define PWM_GEN3_EXT_FLTSTAT0_OFFSET    ((uint32_t) ((PWM_GEN_EXT_REGISTER_OFFSET * 3UL) + PWM_GEN_EXT_FLTSTAT0_OFFSET + PWM_GEN_EXT_REGISTER_BASE_OFFSET))
#define PWM_GEN3_EXT_FLTSTAT1_OFFSET    ((uint32_t) ((PWM_GEN_EXT_REGISTER_OFFSET * 3UL) + PWM_GEN_EXT_FLTSTAT1_OFFSET + PWM_GEN_EXT_REGISTER_BASE_OFFSET))

#define PWM_PP_OFFSET    ((uint32_t) 0x0FC0UL)
#define PWM_CC_OFFSET    ((uint32_t) 0x0FC8UL)

#endif /* XDRIVER_MCU_PWM_PERIPHERAL_REGISTER_XHEADER_PWM_REGISTERADDRESS_H_ */