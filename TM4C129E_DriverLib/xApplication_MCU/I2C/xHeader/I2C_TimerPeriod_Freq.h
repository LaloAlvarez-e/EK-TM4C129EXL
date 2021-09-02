/**
 *
 * @file I2C_TimerPeriod_Freq.h
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
 * @verbatim 31 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 31 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef XAPPLICATION_MCU_I2C_XHEADER_I2C_TIMERPERIOD_FREQ_H_
#define XAPPLICATION_MCU_I2C_XHEADER_I2C_TIMERPERIOD_FREQ_H_

#include <xApplication_MCU/I2C/Intrinsics/xHeader/I2C_Defines.h>

I2C_nSTATUS I2C_Master__enSetFrequency(I2C_nMODULE enModule, uint32_t u32FrequencyArg);
uint32_t I2C_Master__u32GetFrequency(I2C_nMODULE enModule);

#endif /* XAPPLICATION_MCU_I2C_XHEADER_I2C_TIMERPERIOD_FREQ_H_ */
