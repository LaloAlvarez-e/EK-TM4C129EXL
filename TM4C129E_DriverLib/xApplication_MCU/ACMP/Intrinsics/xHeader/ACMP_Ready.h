/**
 *
 * @file ACMP_Ready.h
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
 * @verbatim 20 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 20 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef XAPPLICATION_MCU_ACMP_INTRINSICS_XHEADER_ACMP_READY_H_
#define XAPPLICATION_MCU_ACMP_INTRINSICS_XHEADER_ACMP_READY_H_

#include <xApplication_MCU/ACMP/Intrinsics/xHeader/ACMP_Defines.h>

ACMP_nERROR ACMP__enSetReadyOnRunMode(ACMP_nMODULE enModuleArg);
ACMP_nERROR ACMP__enClearReadyOnRunMode(ACMP_nMODULE enModuleArg);
ACMP_nERROR ACMP__enReset(ACMP_nMODULE enModuleArg);
ACMP_nERROR ACMP__enIsReady(ACMP_nMODULE enModuleArg, ACMP_nBOOLEAN* penReadyArg);

#endif /* XAPPLICATION_MCU_ACMP_INTRINSICS_XHEADER_ACMP_READY_H_ */
