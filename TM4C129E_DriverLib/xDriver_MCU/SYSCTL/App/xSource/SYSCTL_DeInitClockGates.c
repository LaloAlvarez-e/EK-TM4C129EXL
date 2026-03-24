/**
 *
 * @file SYSCTL_DeInitClockGates.c
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
 * @verbatim 24 jul. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 24 jul. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/SYSCTL/App/xHeader/SYSCTL_DeInitClockGates.h>

#include <xDriver_MCU/SYSCTL/App/xHeader/SYSCTL_Ready.h>
#include <xDriver_MCU/SYSCTL/Driver/SYSCTL_Driver.h>

SYSCTL_nERROR SYSCTL__enDeInitClockGates(SYSCTL_nMODULE enModuleArg)
{
    const SYSCTL_nPERIPHERAL enPeripheralReg[70UL] =
    {
     SYSCTL_enWDT0 ,
     SYSCTL_enWDT1 ,
     SYSCTL_enTIMER0 ,
     SYSCTL_enTIMER1 ,
     SYSCTL_enTIMER2 ,
     SYSCTL_enTIMER3 ,
     SYSCTL_enTIMER4 ,
     SYSCTL_enTIMER5 ,
     SYSCTL_enTIMER6 ,
     SYSCTL_enTIMER7 ,
     SYSCTL_enGPIOA ,
     SYSCTL_enGPIOB ,
     SYSCTL_enGPIOC ,
     SYSCTL_enGPIOD ,
     SYSCTL_enGPIOE ,
     SYSCTL_enGPIOF ,
     SYSCTL_enGPIOG ,
     SYSCTL_enGPIOH ,
     SYSCTL_enGPIOJ ,
     SYSCTL_enGPIOK ,
     SYSCTL_enGPIOL ,
     SYSCTL_enGPIOM ,
     SYSCTL_enGPION ,
     SYSCTL_enGPIOP ,
     SYSCTL_enGPIOQ ,
     SYSCTL_enDMA ,
     SYSCTL_enEPI ,
     SYSCTL_enHIB ,
     SYSCTL_enUART0 ,
     SYSCTL_enUART1 ,
     SYSCTL_enUART2 ,
     SYSCTL_enUART3 ,
     SYSCTL_enUART4 ,
     SYSCTL_enUART5 ,
     SYSCTL_enUART6 ,
     SYSCTL_enUART7 ,
     SYSCTL_enSSI0 ,
     SYSCTL_enSSI1 ,
     SYSCTL_enSSI2 ,
     SYSCTL_enSSI3 ,
     SYSCTL_enI2C0 ,
     SYSCTL_enI2C1 ,
     SYSCTL_enI2C2 ,
     SYSCTL_enI2C3 ,
     SYSCTL_enI2C4 ,
     SYSCTL_enI2C5 ,
     SYSCTL_enI2C6 ,
     SYSCTL_enI2C7 ,
     SYSCTL_enI2C8 ,
     SYSCTL_enI2C9 ,
     SYSCTL_enUSB ,
     SYSCTL_enEPHY ,
     SYSCTL_enCAN0 ,
     SYSCTL_enCAN1 ,
     SYSCTL_enADC0 ,
     SYSCTL_enADC1 ,
     SYSCTL_enACMP ,
     SYSCTL_enPWM0 ,
     SYSCTL_enQEI0 ,
     SYSCTL_enLPC ,
     SYSCTL_enPECI ,
     SYSCTL_enFAN ,
     SYSCTL_enEEPROM ,
     SYSCTL_enRTS ,
     SYSCTL_enCCM ,
     SYSCTL_enLCD ,
     SYSCTL_enOWIRE ,
     SYSCTL_enEMAC ,
     SYSCTL_enPRB ,
     SYSCTL_enHIM ,
    };
    UBase_t uxIterReg;
    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL_enERROR_OK;
    for(uxIterReg = 0UL; uxIterReg < 70UL; uxIterReg++)
    {
        enErrorReg = SYSCTL__enClearReadyOnRunMode(enModuleArg, enPeripheralReg[uxIterReg]);
        if(SYSCTL_enERROR_OK != enErrorReg)
        {
            break;
        }
    }
    return (enErrorReg);
}
