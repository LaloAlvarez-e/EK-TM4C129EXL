/**
 *
 * @file ACMP_VoltageReference.h
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
 * @verbatim 21 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 21 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef XAPPLICATION_MCU_ACMP_XHEADER_ACMP_VOLTAGEREFERENCE_H_
#define XAPPLICATION_MCU_ACMP_XHEADER_ACMP_VOLTAGEREFERENCE_H_

#include <xApplication_MCU/ACMP/Intrinsics/xHeader/ACMP_Defines.h>

float32_t ACMP__f32SetVoltageReference(ACMP_nMODULE enModule,
                                       float32_t f32VoltageReferencePorcentage);
float32_t ACMP__f32GetVoltageReference(ACMP_nMODULE enModule);

#endif /* XAPPLICATION_MCU_ACMP_XHEADER_ACMP_VOLTAGEREFERENCE_H_ */
