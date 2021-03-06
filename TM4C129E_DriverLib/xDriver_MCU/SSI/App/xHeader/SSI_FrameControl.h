/**
 *
 * @file SSI_FrameControl.h
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
 * @verbatim 11 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 11 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_SSI_APP_XHEADER_SSI_FRAMECONTROL_H_
#define XDRIVER_MCU_SSI_APP_XHEADER_SSI_FRAMECONTROL_H_

#include <xDriver_MCU/SSI/Peripheral/xHeader/SSI_Enum.h>

void SSI__vSetFormatControl(SSI_nMODULE enModule,
                            SSI_nFORMAT enFormatArg,
                            SSI_nLENGTH enLengthDataArg,
                            SSI_nCLOCK_PHASE enClockPhaseArg,
                            SSI_nCLOCK_POLARITY enClockPolarityArg);
void SSI__vSetFormatControlStruct(SSI_nMODULE enModule,
                                  const SSI_FRAME_CONTROL_t stFormatControl);
void SSI__vSetFormatControlStructPointer(SSI_nMODULE enModule,
                                         const SSI_FRAME_CONTROL_t* pstFormatControl);

#endif /* XDRIVER_MCU_SSI_APP_XHEADER_SSI_FRAMECONTROL_H_ */
