/**
 *
 * @file xTask8_Debug.c
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
 * @verbatim 5 sep. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 5 sep. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#include <xTask/xHeader/xTask8_Debug.h>
#include <xTask/xHeader/xSemaphores.h>

#include <xApplication/EDUMKII/EDUMKII.h>
#include <xApplication_MCU/xApplication_MCU.h>

#include <xOS/xOS.h>

static char xTask8__cGetBootPortName(UBase_t uxBootPortArg);
static void xTask8__vClearRows(UBase_t uxRowInitArg, UBase_t uxRowEndArg);
static void xTask8__vReportSystemInfo(void);
static void xTask8__vSetSystemInfoMode(void);
static void xTask8__vSetLiveDataMode(void);

static char xTask8__cGetBootPortName(UBase_t uxBootPortArg)
{
    char cPortReg;

    cPortReg = '?';
    if(8UL > uxBootPortArg)
    {
        cPortReg = (char) ('A' + (char) uxBootPortArg);
    }
    return (cPortReg);
}

static void xTask8__vClearRows(UBase_t uxRowInitArg, UBase_t uxRowEndArg)
{
    UBase_t uxRowReg;

    uxRowReg = uxRowInitArg;
    while(uxRowReg <= uxRowEndArg)
    {
        GraphTerm__uxPrintf(UART_enMODULE_0, 0UL, uxRowReg,
                             "                                        "
                             );
        uxRowReg++;
    }
}

static void xTask8__vReportSystemInfo(void)
{
    UBase_t uxDID0MajorRevisionReg;
    UBase_t uxDID0MinorRevisionReg;
    UBase_t uxDID1FamilyReg;
    UBase_t uxDID1PartNoReg;
    UBase_t uxResetVectorPointerReg;
    UBase_t uxBootPinReg;
    UBase_t uxBootPortReg;
    UBase_t uxUniqueID0Reg;
    UBase_t uxUniqueID1Reg;
    UBase_t uxUniqueID2Reg;
    UBase_t uxUniqueID3Reg;
    UBase_t uxUserRegister0Reg;
    UBase_t uxUserRegister1Reg;
    UBase_t uxUserRegister2Reg;
    UBase_t uxUserRegister3Reg;
    SYSCTL_nBOOLEAN enFlashWriteBufferReg;
    SYSCTL_nBOOLEAN enFPUPresentReg;
    SYSCTL_nBOOLEAN enFlashLowPowerModeReg;
    SYSCTL_nBOOLEAN enLDOSequenceReg;
    SYSCTL_nBOOLEAN enBootConfigDebug0Reg;
    SYSCTL_nBOOLEAN enBootConfigDebug1Reg;
    SYSCTL_nBOOLEAN enBootConfigKeyReg;
    SYSCTL_nBOOLEAN enBootConfigGPIOEnableReg;
    SYSCTL_nBOOLEAN enBootConfigGPIOPolarityReg;
    SYSCTL_nBOOLEAN enBootConfigNotWrittenReg;

    uxDID0MajorRevisionReg = 0UL;
    uxDID0MinorRevisionReg = 0UL;
    uxDID1FamilyReg = 0UL;
    uxDID1PartNoReg = 0UL;
    uxResetVectorPointerReg = 0UL;
    uxBootPinReg = 0UL;
    uxBootPortReg = 0UL;
    uxUniqueID0Reg = 0UL;
    uxUniqueID1Reg = 0UL;
    uxUniqueID2Reg = 0UL;
    uxUniqueID3Reg = 0UL;
    uxUserRegister0Reg = 0UL;
    uxUserRegister1Reg = 0UL;
    uxUserRegister2Reg = 0UL;
    uxUserRegister3Reg = 0UL;
    enFlashWriteBufferReg = (SYSCTL_nBOOLEAN) 0UL;
    enFPUPresentReg = (SYSCTL_nBOOLEAN) 0UL;
    enFlashLowPowerModeReg = (SYSCTL_nBOOLEAN) 0UL;
    enLDOSequenceReg = (SYSCTL_nBOOLEAN) 0UL;
    enBootConfigDebug0Reg = (SYSCTL_nBOOLEAN) 0UL;
    enBootConfigDebug1Reg = (SYSCTL_nBOOLEAN) 0UL;
    enBootConfigKeyReg = (SYSCTL_nBOOLEAN) 0UL;
    enBootConfigGPIOEnableReg = (SYSCTL_nBOOLEAN) 0UL;
    enBootConfigGPIOPolarityReg = (SYSCTL_nBOOLEAN) 0UL;
    enBootConfigNotWrittenReg = (SYSCTL_nBOOLEAN) 0UL;

    (void) SYSCTL__enGetDID0MajorRevision(SYSCTL_enMODULE_0, &uxDID0MajorRevisionReg);
    (void) SYSCTL__enGetDID0MinorRevision(SYSCTL_enMODULE_0, &uxDID0MinorRevisionReg);
    (void) SYSCTL__enGetDID1Family(SYSCTL_enMODULE_0, &uxDID1FamilyReg);
    (void) SYSCTL__enGetDID1PartNo(SYSCTL_enMODULE_0, &uxDID1PartNoReg);
    (void) SYSCTL__enIsFlashWriteBufferAvailable(SYSCTL_enMODULE_0, &enFlashWriteBufferReg);
    (void) SYSCTL__enIsFPUPresent(SYSCTL_enMODULE_0, &enFPUPresentReg);
    (void) SYSCTL__enIsFlashLowPowerModeSupported(SYSCTL_enMODULE_0, &enFlashLowPowerModeReg);
    (void) SYSCTL__enIsLDOSequenceSupported(SYSCTL_enMODULE_0, &enLDOSequenceReg);
    (void) SYSCTL__enGetBootConfigDebug0(SYSCTL_enMODULE_0, &enBootConfigDebug0Reg);
    (void) SYSCTL__enGetBootConfigDebug1(SYSCTL_enMODULE_0, &enBootConfigDebug1Reg);
    (void) SYSCTL__enGetBootConfigKey(SYSCTL_enMODULE_0, &enBootConfigKeyReg);
    (void) SYSCTL__enGetBootConfigGPIOEnable(SYSCTL_enMODULE_0, &enBootConfigGPIOEnableReg);
    (void) SYSCTL__enGetBootConfigGPIOPolarity(SYSCTL_enMODULE_0, &enBootConfigGPIOPolarityReg);
    (void) SYSCTL__enGetBootConfigGPIOPin(SYSCTL_enMODULE_0, &uxBootPinReg);
    (void) SYSCTL__enGetBootConfigGPIOPort(SYSCTL_enMODULE_0, &uxBootPortReg);
    (void) SYSCTL__enGetBootConfigNotWritten(SYSCTL_enMODULE_0, &enBootConfigNotWrittenReg);
    (void) SYSCTL__enGetResetVectorPointer(SYSCTL_enMODULE_0, &uxResetVectorPointerReg);
    (void) SYSCTL__enGetUniqueID0(SYSCTL_enMODULE_0, &uxUniqueID0Reg);
    (void) SYSCTL__enGetUniqueID1(SYSCTL_enMODULE_0, &uxUniqueID1Reg);
    (void) SYSCTL__enGetUniqueID2(SYSCTL_enMODULE_0, &uxUniqueID2Reg);
    (void) SYSCTL__enGetUniqueID3(SYSCTL_enMODULE_0, &uxUniqueID3Reg);
    (void) SYSCTL__enGetUserRegister0(SYSCTL_enMODULE_0, &uxUserRegister0Reg);
    (void) SYSCTL__enGetUserRegister1(SYSCTL_enMODULE_0, &uxUserRegister1Reg);
    (void) SYSCTL__enGetUserRegister2(SYSCTL_enMODULE_0, &uxUserRegister2Reg);
    (void) SYSCTL__enGetUserRegister3(SYSCTL_enMODULE_0, &uxUserRegister3Reg);

    GraphTerm__uxPrintf(UART_enMODULE_0, 0UL, 4UL,
                         "SYS PART:%u FAM:%u REV:%u.%u            ",
                         (unsigned int) uxDID1PartNoReg,
                         (unsigned int) uxDID1FamilyReg,
                         (unsigned int) uxDID0MajorRevisionReg,
                         (unsigned int) uxDID0MinorRevisionReg);
    GraphTerm__uxPrintf(UART_enMODULE_0, 0UL, 5UL,
                         "SYS FWB:%u FPU:%u FLP:%u LDOSEQ:%u      ",
                         (unsigned int) enFlashWriteBufferReg,
                         (unsigned int) enFPUPresentReg,
                         (unsigned int) enFlashLowPowerModeReg,
                         (unsigned int) enLDOSequenceReg);
    GraphTerm__uxPrintf(UART_enMODULE_0, 0UL, 6UL,
                         "BOOT D0:%u D1:%u KEY:%u EN:%u           ",
                         (unsigned int) enBootConfigDebug0Reg,
                         (unsigned int) enBootConfigDebug1Reg,
                         (unsigned int) enBootConfigKeyReg,
                         (unsigned int) enBootConfigGPIOEnableReg);
    GraphTerm__uxPrintf(UART_enMODULE_0, 0UL, 7UL,
                         "BOOT P%c%u POL:%u NW:%u RVP:%08X        ",
                         xTask8__cGetBootPortName(uxBootPortReg),
                         (unsigned int) uxBootPinReg,
                         (unsigned int) enBootConfigGPIOPolarityReg,
                         (unsigned int) enBootConfigNotWrittenReg,
                         (unsigned int) uxResetVectorPointerReg);
    GraphTerm__uxPrintf(UART_enMODULE_0, 0UL, 8UL,
                         "UID0:%08X UID1:%08X                     ",
                         (unsigned int) uxUniqueID0Reg,
                         (unsigned int) uxUniqueID1Reg);
    GraphTerm__uxPrintf(UART_enMODULE_0, 0UL, 9UL,
                         "UID2:%08X UID3:%08X                     ",
                         (unsigned int) uxUniqueID2Reg,
                         (unsigned int) uxUniqueID3Reg);
    GraphTerm__uxPrintf(UART_enMODULE_0, 0UL, 10UL,
                         "USR0:%08X USR1:%08X                     ",
                         (unsigned int) uxUserRegister0Reg,
                         (unsigned int) uxUserRegister1Reg);
    GraphTerm__uxPrintf(UART_enMODULE_0, 0UL, 11UL,
                         "USR2:%08X USR3:%08X                     ",
                         (unsigned int) uxUserRegister2Reg,
                         (unsigned int) uxUserRegister3Reg);
}

static void xTask8__vSetSystemInfoMode(void)
{
    xTask8__vClearRows(0UL, 11UL);
    GraphTerm__uxPrintf(UART_enMODULE_0, 0UL, 0UL,
                         "MODE:SYSTEM INFO SELECT->LIVE           "
                         );
    GraphTerm__uxPrintf(UART_enMODULE_0, 0UL, 1UL,
                         "SYSTEM INFO ACTIVE                       "
                         );
    GraphTerm__uxPrintf(UART_enMODULE_0, 0UL, 2UL,
                         "PRESS JOYSTICK SELECT FOR LIVE DATA     "
                         );
    GraphTerm__uxPrintf(UART_enMODULE_0, 0UL, 3UL,
                         "WAITING FOR TOGGLE...                   "
                         );
    xTask8__vReportSystemInfo();
}

static void xTask8__vSetLiveDataMode(void)
{
    xTask8__vClearRows(0UL, 11UL);
    GraphTerm__uxPrintf(UART_enMODULE_0, 0UL, 0UL,
                         "MODE:LIVE DATA SELECT->SYSTEM           "
                         );
    GraphTerm__uxPrintf(UART_enMODULE_0, 0UL, 1UL,
                         "BUTTON DATA LOADING...                  "
                         );
    GraphTerm__uxPrintf(UART_enMODULE_0, 0UL, 2UL,
                         "JOYSTICK DATA LOADING...                "
                         );
    GraphTerm__uxPrintf(UART_enMODULE_0, 0UL, 3UL,
                         "ACCEL DATA LOADING...                   "
                         );
}

void xTask8_Debug(void* pvParams)
{
    /*Period Handling*/
    UBase_t uxLastWakeTime;
    UBase_t uxPeriodTask = (UBase_t) pvParams;
    OS_Boolean_t boResult;
    OS_Boolean_t boLiveDataMode;

    UBase_t uxJostickValue[2UL];
    Base_t sxAccelValue[3UL];
    char* pcStateButton[3UL];

    GraphTerm__uxPrintf(UART_enMODULE_0, 0UL, 0UL,
                         "TASK8 WAITING FOR MAIN INIT...          "
                         );
    OS_Semaphore__boTake(MainSemaphoreHandle, 2000UL);
    boLiveDataMode = FALSE;
    xTask8__vSetSystemInfoMode();
    uxLastWakeTime = OS_Task__uxGetTickCount ();
    while(1UL)
    {
        while(TRUE == OS_Semaphore__boTake(DebugDataSemaphoreHandle, 0UL))
        {
            if(TRUE == boLiveDataMode)
            {
                boLiveDataMode = FALSE;
                xTask8__vSetSystemInfoMode();
            }
            else
            {
                boLiveDataMode = TRUE;
                xTask8__vSetLiveDataMode();
            }
        }

        if(TRUE == boLiveDataMode)
        {
            boResult = OS_Queue__boPeek(AccelerometerQueueHandle, sxAccelValue, 0UL);
            if(TRUE == boResult)
            {
                GraphTerm__uxPrintf(UART_enMODULE_0, 0UL, 3UL,
                                     "Accelerometer X: %d Y: %d Z: %d        ",
                                     sxAccelValue[0UL],
                                     sxAccelValue[1UL],
                                     sxAccelValue[2UL]
                                     );
            }
            boResult = OS_Queue__boPeek(ButtonQueueHandle, pcStateButton, 0UL);
            if(TRUE == boResult)
            {
                GraphTerm__uxPrintf(UART_enMODULE_0, 0UL, 1UL,
                                     "BUTTON1: %s BUTTON2: %s SELECT: %s     ",
                                     pcStateButton[0UL],
                                     pcStateButton[1UL],
                                     pcStateButton[2UL]
                                     );
            }
            boResult = OS_Queue__boPeek(YoystickQueueHandle, uxJostickValue, 0UL);
            if(TRUE == boResult)
            {
                GraphTerm__uxPrintf(UART_enMODULE_0, 0UL, 2UL,
                                     "YOYSTICK POS X: %d Y: %d            ",
                                     uxJostickValue[0UL],
                                     uxJostickValue[1UL]
                                     );
            }
        }

        OS_Task__vDelayUntil(&uxLastWakeTime, uxPeriodTask);
    }
}




