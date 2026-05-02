/**
 *
 * @file HIB_Data.h
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
 * @verbatim 6 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 6 abr. 2026    vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_HIB_DRIVER_XHEADER_HIB_DATA_H_
#define XDRIVER_MCU_HIB_DRIVER_XHEADER_HIB_DATA_H_

#include <xDriver_MCU/HIB/Peripheral/xHeader/HIB_Enum.h>

HIB_nERROR HIB__enSetDataByNumber(HIB_nMODULE enModuleArg, HIB_nDATA enDataArg, UBase_t uxValueArg);
HIB_nERROR HIB__enGetDataByNumber(HIB_nMODULE enModuleArg, HIB_nDATA enDataArg, UBase_t* puxValueArg);

HIB_nERROR HIB__enWriteDataArray(HIB_nMODULE enModuleArg, HIB_nDATA enDataArg, const UBase_t* puxValueArg, UBase_t uxCountArg);
HIB_nERROR HIB__enReadDataArray(HIB_nMODULE enModuleArg, HIB_nDATA enDataArg, UBase_t* puxValueArg, UBase_t uxCountArg);

#endif /* XDRIVER_MCU_HIB_DRIVER_XHEADER_HIB_DATA_H_ */
