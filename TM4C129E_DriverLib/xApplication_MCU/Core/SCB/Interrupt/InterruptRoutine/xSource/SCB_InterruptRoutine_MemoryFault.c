/**
 *
 * @file SCB_InterruptRoutine_MemoryFault.c
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
 * @verbatim 15 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 15 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/Core/SCB/Interrupt/InterruptRoutine/xHeader/SCB_InterruptRoutine_MemoryFault.h>

#include <xApplication_MCU/Core/SCB/Interrupt/InterruptRoutine/xHeader/SCB_InterruptRoutine_Source.h>
#include <xApplication_MCU/Core/SCB/Intrinsics/xHeader/SCB_Dependencies.h>

UBase_t SCB_MemoryFault_puxContext[8UL] = {0UL};

UART_CONTROL_t enUartMemoryControl =
{
    UART_enEOT_ALL,
    UART_enLOOPBACK_DIS,
    UART_enLINE_ENA,
    UART_enLINE_ENA,
    UART_enRTS_MODE_SOFT,
    UART_enCTS_MODE_SOFT,
    UART_enLINE_DIS,
    UART_enLINE_DIS,
    UART_enLINE_DIS,
    UART_enLINE_DIS,
};

UART_LINE_CONTROL_t enUartMemoryLineControl =
{
 UART_enFIFO_ENA,
 UART_enSTOP_ONE,
 UART_enPARITY_DIS,
 UART_enPARITY_TYPE_EVEN,
 UART_enPARITY_STICK_DIS ,
 UART_enLENGTH_8BITS,
};

UART_LINE_t enUartMemoryLine =
{
 UART_enLINE_SELECT_PRIMARY,
 UART_enLINE_SELECT_PRIMARY,
 UART_enLINE_SELECT_PRIMARY,
 UART_enLINE_SELECT_PRIMARY,
 UART_enLINE_SELECT_PRIMARY,
 UART_enLINE_SELECT_PRIMARY,
 UART_enLINE_SELECT_PRIMARY,
 UART_enLINE_SELECT_PRIMARY,
};

void MemoryFault__vSendValues(void)
{
    SYSCTL__vEnRunModePeripheral(SYSCTL_enGPIOA);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enUART0);
    UART__vInit();
    UART__vSetEnable(UART_enMODULE_0, UART_enENABLE_STOP);
    UART__enSetConfig(UART_enMODULE_0, UART_enMODE_NORMAL, &enUartMemoryControl, &enUartMemoryLineControl, 921600UL, &enUartMemoryLine );
    UART__vSetEnable(UART_enMODULE_0, UART_enENABLE_START);

    UART__uxPrintf(UART_enMODULE_0, "MEMORY FAULT exception Detected\n\r"
                    "Core Register dump:\n\r"
                    "R0: %X, R1: %X\n\r"
                    "R2: %X, R3: %X\n\r"
                    "R12: %X xPSR: %X\n\r"
                    "LR: %X, PC: %X\n\r",
                    SCB_MemoryFault_puxContext[0UL],
                    SCB_MemoryFault_puxContext[1UL],
                    SCB_MemoryFault_puxContext[2UL],
                    SCB_MemoryFault_puxContext[3UL],
                    SCB_MemoryFault_puxContext[4UL],
                    SCB_MemoryFault_puxContext[7UL],
                    SCB_MemoryFault_puxContext[5UL],
                    SCB_MemoryFault_puxContext[6UL]);
}


__attribute__((naked))
void MemoryFault__vIRQVectorHandler(void)
{
    __asm volatile(
    " PUSH {R4-R7}\n"
    " ubfx    R4, LR, #2, #1 \n"
    " cmp    R4, #0 \n"
    " beq    MainStackMemory \n"
    " b    ProcessStackMemory \n"

    "MainStackMemory: \n"
    " mrs    R4, MSP \n"
#if defined (__TI_ARM__ ) || defined (__MSP430__ )
    " movw R6, SCB_MemoryFault_puxContext\n"
    " movt R6, SCB_MemoryFault_puxContext\n"
#elif defined (__GNUC__ )
    " ldr R6, = SCB_MemoryFault_puxContext\n"
#endif
    " ldr R5, [R4, #0X10]\n"
    " str R5, [R6, #0x0]\n"/*SCB_MemoryFault_puxContext[0] R4*/
    " ldr R5, [R4, #0x14]\n"
    " str R5, [R6, #0x4]\n"/*SCB_MemoryFault_puxContext[1] R5*/
    " ldr R5, [R4, #0x18]\n"
    " str R5, [R6, #0x8]\n"/*SCB_MemoryFault_puxContext[2] R6*/
    " ldr R5, [R4, #0x1C]\n"
    " str R5, [R6, #0xC]\n"/*SCB_MemoryFault_puxContext[3] R3*/
    " ldr R5, [R4, #0x20]\n"
    " str R5, [R6, #0x10]\n"/*SCB_MemoryFault_puxContext[4] R52*/
    " ldr R5, [R4, #0x24]\n"
    " str R5, [R6, #0x14]\n"/*SCB_MemoryFault_puxContext[5] LR*/
    " ldr R5, [R4, #0x28]\n"
    " str R5, [R6, #0x18]\n"/*SCB_MemoryFault_puxContext[6] PC*/
    " ldr R5, [R4, #0x2C]\n"
    " str R5, [R6, #0x1C]\n"/*SCB_MemoryFault_puxContext[7] PSR*/
    " b    ProcessMemory \n"

    "ProcessStackMemory: \n"
    " mrs    R4, PSP \n"
#if defined (__TI_ARM__ ) || defined (__MSP430__ )
    " movw R6, SCB_MemoryFault_puxContext\n"
    " movt R6, SCB_MemoryFault_puxContext\n"
#elif defined (__GNUC__ )
    " ldr R6, = SCB_MemoryFault_puxContext\n"
#endif
    " ldr R5, [R4, #0X0]\n"
    " str R5, [R6, #0x0]\n"/*SCB_MemoryFault_puxContext[0] R4*/
    " ldr R5, [R4, #0x4]\n"
    " str R5, [R6, #0x4]\n"/*SCB_MemoryFault_puxContext[1] R5*/
    " ldr R5, [R4, #0x8]\n"
    " str R5, [R6, #0x8]\n"/*SCB_MemoryFault_puxContext[2] R6*/
    " ldr R5, [R4, #0xC]\n"
    " str R5, [R6, #0xC]\n"/*SCB_MemoryFault_puxContext[3] R3*/
    " ldr R5, [R4, #0x10]\n"
    " str R5, [R6, #0x10]\n"/*SCB_MemoryFault_puxContext[4] R52*/
    " ldr R5, [R4, #0x14]\n"
    " str R5, [R6, #0x14]\n"/*SCB_MemoryFault_puxContext[5] LR*/
    " ldr R5, [R4, #0x18]\n"
    " str R5, [R6, #0x18]\n"/*SCB_MemoryFault_puxContext[6] PC*/
    " ldr R5, [R4, #0x1C]\n"
    " str R5, [R6, #0x1C]\n"/*SCB_MemoryFault_puxContext[7] PSR*/

    "ProcessMemory: \n"
    " pop {R4-R7}\n"
    " push {R0,R1,R2,LR} \n"
    " .global MemoryFault__vSendValues \n"
    " .global MemoryFault__vIRQVectorHandlerCustom \n"
#if defined (__TI_ARM__ ) || defined (__MSP430__ )
    " movw R2, MemoryFault__vSendValues\n"
    " movt R2, MemoryFault__vSendValues\n"
#elif defined (__GNUC__ )
    " ldr R2, = MemoryFault__vSendValues\n"
#endif
    " blx R2 \n"
    " movw R0, #0xE000\n"
    " movt R0, #0xE000\n"
#if defined (__TI_ARM__ ) || defined (__MSP430__ )
    " movw R1, SCB_MemoryFault_puxContext\n"
    " movt R1, SCB_MemoryFault_puxContext\n"
#elif defined (__GNUC__ )
    " ldr R1, = SCB_MemoryFault_puxContext\n"
#endif
#if defined (__TI_ARM__ ) || defined (__MSP430__ )
    " movw R2, MemoryFault__vIRQVectorHandlerCustom\n"
    " movt R2, MemoryFault__vIRQVectorHandlerCustom\n"
#elif defined (__GNUC__ )
    " ldr R2, = MemoryFault__vIRQVectorHandlerCustom\n"
#endif
    " blx R2 \n"
    " pop {R0,R1,R2,LR} \n"
    " BX LR \n");
}


void MemoryFault__vIRQVectorHandlerCustom(uintptr_t uptrModuleArg, void* pvArgument)
{
    SCB_t* pstSCBReg;
    UBase_t uxMemoryFault;
    UBase_t uxMemoryAddressValid;
    UBase_t uxMemoryAddressFault;
    SCB_pvfIRQSourceHandler_t pvfCallback;

    UBase_t* puxContext;
    UBase_t* puxContextOffset;

    pstSCBReg = (SCB_t*) uptrModuleArg;
    puxContext = (UBase_t*) pvArgument;

    uxMemoryAddressValid = 0UL;
    uxMemoryFault = pstSCBReg->CFSR;
    uxMemoryFault >>= 0UL;
    uxMemoryFault &= (UBase_t) SCB_enMEMORY_ALL;
    if(0UL == ((UBase_t) SCB_enMEMORY_ALL & uxMemoryFault))
    {
        UART__uxPrintf(UART_enMODULE_0, "Memory Fault Exception triggered by Software \n\r");
        pvfCallback = SCB_MemoryFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enMEMORY_BIT_SW);
        pvfCallback(SCB_BASE, (void*) SCB_enMEMORY_BIT_SW);
    }
    else
    {
        if((UBase_t) SCB_enMEMORY_MLSPERR & uxMemoryFault)
        {
            pstSCBReg->CFSR = SCB_CFSR_R_MLSPERR_CLEAR;
            UART__uxPrintf(UART_enMODULE_0, "Memory Fault on FPU Lazy State Preservation \n\r");
            pvfCallback = SCB_MemoryFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enMEMORY_BIT_MLSPERR);
            pvfCallback(SCB_BASE, (void*) SCB_enMEMORY_BIT_MLSPERR);
        }
        if((UBase_t) SCB_enMEMORY_MSTKERR & uxMemoryFault)
        {
            pstSCBReg->CFSR = SCB_CFSR_R_MSTKERR_CLEAR;
            UART__uxPrintf(UART_enMODULE_0,"Stacking Memory Fault, it occurred on an Exception/IRQ entry\n\r"
                                            "Context Values cannot be valid\n\r");
            pvfCallback = SCB_MemoryFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enMEMORY_BIT_MSTKERR);
            pvfCallback(SCB_BASE, (void*) SCB_enMEMORY_BIT_MSTKERR);
        }
        if((UBase_t) SCB_enMEMORY_MUNSTKERR & uxMemoryFault)
        {
            pstSCBReg->CFSR = SCB_CFSR_R_MUNSTKERR_CLEAR;
            UART__uxPrintf(UART_enMODULE_0,"Un-stacking Memory Fault, it occurred on an Exception/IRQ exit\n\r"
                                            "Context Values are related to the previous context\n\r");
            pvfCallback = SCB_MemoryFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enMEMORY_BIT_MUNSTKERR);
            pvfCallback(SCB_BASE, (void*) SCB_enMEMORY_BIT_MUNSTKERR);
        }
        if((UBase_t) SCB_enMEMORY_MMARVALID & uxMemoryFault)
        {
            pstSCBReg->CFSR = SCB_CFSR_R_MMARVALID_CLEAR;
            uxMemoryAddressValid = 1UL;
            pvfCallback = SCB_MemoryFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enMEMORY_BIT_MMARVALID);
            pvfCallback(SCB_BASE, (void*) SCB_enMEMORY_BIT_MMARVALID);
        }
        if((UBase_t) SCB_enMEMORY_DACCVIOL & uxMemoryFault)
        {
            pstSCBReg->CFSR = SCB_CFSR_R_DACCVIOL_CLEAR;
            UART__uxPrintf(UART_enMODULE_0, "Data Access Violation Memory Fault\n\r");
            if(1UL == uxMemoryAddressValid)
            {
                uxMemoryAddressFault = pstSCBReg->MMFAR;
                UART__uxPrintf(UART_enMODULE_0, "Attemp Data Access Fault Address: %X\n\r", uxMemoryAddressFault);
            }
            puxContextOffset = puxContext;
            puxContextOffset += 6UL;
            uxMemoryAddressFault = *puxContextOffset;
            UART__uxPrintf(UART_enMODULE_0, "Instruction Fault Address: %X\n\r", uxMemoryAddressFault);
            pvfCallback = SCB_MemoryFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enMEMORY_BIT_DACCVIOL);
            pvfCallback(SCB_BASE, (void*) SCB_enMEMORY_BIT_DACCVIOL);
        }
        if((UBase_t) SCB_enMEMORY_IACCVIOL & uxMemoryFault)
        {
            pstSCBReg->CFSR = SCB_CFSR_R_IACCVIOL_CLEAR;
            puxContextOffset = puxContext;
            puxContextOffset += 6UL;
            uxMemoryAddressFault = *puxContextOffset;
            UART__uxPrintf(UART_enMODULE_0, "Instruction Access Fault Address: %X\n\r", uxMemoryAddressFault);
            pvfCallback = SCB_MemoryFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enMEMORY_BIT_IACCVIOL);
            pvfCallback(SCB_BASE, (void*) SCB_enMEMORY_BIT_IACCVIOL);
        }
    }

}


