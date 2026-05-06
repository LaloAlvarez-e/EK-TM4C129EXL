/**
 *
 * @file HIB_InterruptVector.h
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

#ifndef XAPPLICATION_MCU_HIB_INTERRUPT_XHEADER_HIB_INTERRUPTVECTOR_H_
#define XAPPLICATION_MCU_HIB_INTERRUPT_XHEADER_HIB_INTERRUPTVECTOR_H_

#include <xApplication_MCU/HIB/Intrinsics/xHeader/HIB_Defines.h>

HIB_nERROR HIB__enSetInterruptVectorState(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg);
HIB_nERROR HIB__enSetInterruptVectorStateWithPriority(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg, HIB_nPRIORITY enPriorityArg);

HIB_nERROR HIB__enGetInterruptVectorState(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg);
HIB_nERROR HIB__enGetInterruptVectorStateWithPriority(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg, HIB_nPRIORITY* penPriorityArg);

HIB_nERROR HIB__enEnableInterruptVector(HIB_nMODULE enModuleArg);
HIB_nERROR HIB__enEnableInterruptVectorWithPriority(HIB_nMODULE enModuleArg, HIB_nPRIORITY enPriorityArg);

HIB_nERROR HIB__enDisableInterruptVector(HIB_nMODULE enModuleArg);
HIB_nERROR HIB__enDisableInterruptVectorWithPriority(HIB_nMODULE enModuleArg, HIB_nPRIORITY enPriorityArg);

#endif /* XAPPLICATION_MCU_HIB_INTERRUPT_XHEADER_HIB_INTERRUPTVECTOR_H_ */
