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
 * @verbatim 11 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 11 abr. 2026   vyldram    1.0         initial Version@endverbatim
 */

#ifndef EDF89A03_49C4_4721_80CD_4E211EE4D9AC
#define EDF89A03_49C4_4721_80CD_4E211EE4D9AC

#ifndef XAPPLICATION_MCU_HIB_DATA_XHEADER_HIB_DATA_H_
#define XAPPLICATION_MCU_HIB_DATA_XHEADER_HIB_DATA_H_

#include <xApplication_MCU/HIB/Intrinsics/xHeader/HIB_Defines.h>

HIB_nERROR HIB__enSetProtectedDataByNumber(HIB_nMODULE enModuleArg, HIB_nDATA enDataArg,
                                           UBase_t uxValueArg);
HIB_nERROR HIB__enGetProtectedDataByNumber(HIB_nMODULE enModuleArg, HIB_nDATA enDataArg,
                                           UBase_t* puxValueArg);

HIB_nERROR HIB__enWriteProtectedDataArray(HIB_nMODULE enModuleArg, HIB_nDATA enDataArg,
                                          const UBase_t* puxValueArg, UBase_t uxCountArg);
HIB_nERROR HIB__enReadProtectedDataArray(HIB_nMODULE enModuleArg, HIB_nDATA enDataArg,
                                         UBase_t* puxValueArg, UBase_t uxCountArg);

#endif /* XAPPLICATION_MCU_HIB_DATA_XHEADER_HIB_DATA_H_ */


#endif /* EDF89A03_49C4_4721_80CD_4E211EE4D9AC */
