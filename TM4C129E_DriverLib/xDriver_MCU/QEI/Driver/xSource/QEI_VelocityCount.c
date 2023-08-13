/**
 *
 * @file QEI_VelocityCount.c
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
#include <xDriver_MCU/QEI/Driver/xHeader/QEI_VelocityCount.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/QEI/Driver/Intrinsics/Primitives/QEI_Primitives.h>
#include <xDriver_MCU/QEI/Peripheral/QEI_Peripheral.h>

QEI_nERROR QEI__enGetCurrentPulsesPerPeriod(QEI_nMODULE enModuleArg, UBase_t* puxPulsesArg)
{
    QEI_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) puxPulsesArg) ? QEI_enERROR_POINTER : QEI_enERROR_OK;

    if(QEI_enERROR_OK == enErrorReg)
    {
        QEI_Register_t stRegister;
        stRegister.uxShift = QEI_COUNT_R_COUNT_BIT;
        stRegister.uxMask = QEI_COUNT_COUNT_MASK;
        stRegister.uptrAddress = QEI_COUNT_OFFSET;
        enErrorReg = QEI__enReadRegister(enModuleArg, &stRegister);
        if(QEI_enERROR_OK == enErrorReg)
        {
            *puxPulsesArg = (UBase_t) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}
