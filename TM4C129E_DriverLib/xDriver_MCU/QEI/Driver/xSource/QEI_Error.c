/**
 *
 * @file QEI_Error.c
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
 * @verbatim Apr 8, 2021 @endverbatim
 *
 * @author
 * @verbatim indevicemex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * Apr 8, 2021        indevicemex    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/QEI/Driver/xHeader/QEI_Error.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/QEI/Driver/Intrinsics/Primitives/QEI_Primitives.h>
#include <xDriver_MCU/QEI/Peripheral/QEI_Peripheral.h>

QEI_nERROR QEI__enIsErrorDetected(QEI_nMODULE enModuleArg, QEI_nBOOLEAN* penStatusArg)
{
    QEI_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penStatusArg) ? QEI_enERROR_POINTER : QEI_enERROR_OK;

    if(QEI_enERROR_OK == enErrorReg)
    {
        QEI_Register_t stRegister;
        stRegister.uxShift = QEI_STAT_R_ERROR_BIT;
        stRegister.uxMask = QEI_STAT_ERROR_MASK;
        stRegister.uptrAddress = QEI_STAT_OFFSET;
        enErrorReg = QEI__enReadRegister(enModuleArg, &stRegister);
        if(QEI_enERROR_OK == enErrorReg)
        {
            *penStatusArg = (QEI_nBOOLEAN) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

