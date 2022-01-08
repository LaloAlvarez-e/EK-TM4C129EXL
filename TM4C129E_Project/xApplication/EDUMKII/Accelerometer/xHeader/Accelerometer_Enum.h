/**
 *
 * @file Accelerometer_Enum.h
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
 * @verbatim 17 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 17 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */
#ifndef XAPPLICATION_EDUMKII_ACCELEROMETER_XHEADER_ACCELEROMETER_ENUM_H_
#define XAPPLICATION_EDUMKII_ACCELEROMETER_XHEADER_ACCELEROMETER_ENUM_H_

#include <xUtils/Standard/Standard.h>

#if defined(BOOSTER_PACK1)
#define EDUMKII_ACCEL_AXIS_X (GPIO_enAIN3)
#define EDUMKII_ACCEL_AXIS_X_INPUT (ADC_enSEQ_INPUT_3)

#define EDUMKII_ACCEL_AXIS_Y (GPIO_enAIN2)
#define EDUMKII_ACCEL_AXIS_Y_INPUT (ADC_enSEQ_INPUT_2)

#define EDUMKII_ACCEL_AXIS_Z (GPIO_enAIN1)
#define EDUMKII_ACCEL_AXIS_Z_INPUT (ADC_enSEQ_INPUT_1)
#else
#define EDUMKII_ACCEL_AXIS_X (GPIO_enAIN10)
#define EDUMKII_ACCEL_AXIS_X_INPUT (ADC_enSEQ_INPUT_10)

#define EDUMKII_ACCEL_AXIS_Y (GPIO_enAIN11)
#define EDUMKII_ACCEL_AXIS_Y_INPUT (ADC_enSEQ_INPUT_11)

#define EDUMKII_ACCEL_AXIS_Z (GPIO_enAIN16)
#define EDUMKII_ACCEL_AXIS_Z_INPUT (ADC_enSEQ_INPUT_16)
#endif



#endif /* XAPPLICATION_EDUMKII_ACCELEROMETER_XHEADER_ACCELEROMETER_ENUM_H_ */
