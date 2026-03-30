/**
 *
 * @file SYSTICK_Calibration.h
 * @copyright
 * @verbatim InDeviceMex 2026 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 29 mar. 2026 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 29 mar. 2026     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef F1B6847F_47B6_4B59_88FB_98BC2D10F0E8
#define F1B6847F_47B6_4B59_88FB_98BC2D10F0E8

#ifndef XDRIVER_MCU_CORE_SYSTICK_DRIVER_XHEADER_SYSTICK_CALIBRATION_H_
#define XDRIVER_MCU_CORE_SYSTICK_DRIVER_XHEADER_SYSTICK_CALIBRATION_H_

#include <xDriver_MCU/Core/SYSTICK/Peripheral/xHeader/SYSTICK_Enum.h>

SYSTICK_nERROR SYSTICK__enGetCalibrationValue(SYSTICK_nMODULE enModuleArg, UBase_t* puxValueArg);
SYSTICK_nERROR SYSTICK__enGetCalibrationSkew(SYSTICK_nMODULE enModuleArg, SYSTICK_nSKEW* penValueArg);
SYSTICK_nERROR SYSTICK__enGetCalibrationReference(SYSTICK_nMODULE enModuleArg, SYSTICK_nREFERENCE* penValueArg);

#endif /* XDRIVER_MCU_CORE_SYSTICK_DRIVER_XHEADER_SYSTICK_CALIBRATION_H_ */


#endif /* F1B6847F_47B6_4B59_88FB_98BC2D10F0E8 */
