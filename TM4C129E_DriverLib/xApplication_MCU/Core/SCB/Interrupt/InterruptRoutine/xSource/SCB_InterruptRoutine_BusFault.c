 /**
 *
 * @file SCB_InterruptRoutine_BusFault.c
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
#include <xApplication_MCU/Core/SCB/Interrupt/InterruptRoutine/xHeader/SCB_InterruptRoutine_BusFault.h>

#include <xApplication_MCU/Core/SCB/Interrupt/InterruptRoutine/xHeader/SCB_InterruptRoutine_Source.h>
#include <xApplication_MCU/Core/SCB/Intrinsics/xHeader/SCB_Dependencies.h>

UBase_t SCB_BusFault_puxContext[8UL] = {0UL};

UART_CONTROL_t enUartBusControl =
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

UART_LINE_CONTROL_t enUartBusLineControl =
{
 UART_enFIFO_ENA,
 UART_enSTOP_ONE,
 UART_enPARITY_DIS,
 UART_enPARITY_TYPE_EVEN,
 UART_enPARITY_STICK_DIS ,
 UART_enLENGTH_8BITS,
};

UART_LINE_t enUartBusLine =
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

void BusFault__vSendValues(void)
{
    SYSCTL__vEnRunModePeripheral(SYSCTL_enGPIOA);
    SYSCTL__vEnRunModePeripheral(SYSCTL_enUART0);
    UART__vInit();
    UART__vSetEnable(UART_enMODULE_0, UART_enENABLE_STOP);
    UART__enSetConfig(UART_enMODULE_0, UART_enMODE_NORMAL, &enUartBusControl, &enUartBusLineControl, 921600UL, &enUartBusLine );
    UART__vSetEnable(UART_enMODULE_0, UART_enENABLE_START);

    UART__uxPrintf(UART_enMODULE_0, "BUS FAULT exception Detected\n\r"
                    "Core Register dump:\n\r"
                    "R0: %X, R1: %X\n\r"
                    "R2: %X, R3: %X\n\r"
                    "R12: %X xPSR: %X\n\r"
                    "LR: %X, PC: %X\n\r",
                    SCB_BusFault_puxContext[0UL],
                    SCB_BusFault_puxContext[1UL],
                    SCB_BusFault_puxContext[2UL],
                    SCB_BusFault_puxContext[3UL],
                    SCB_BusFault_puxContext[4UL],
                    SCB_BusFault_puxContext[7UL],
                    SCB_BusFault_puxContext[5UL],
                    SCB_BusFault_puxContext[6UL]);
}


__attribute__((naked))
void BusFault__vIRQVectorHandler(void)
{
    __asm volatile(
    " PUSH {R4-R7}\n"
    " ubfx    R4, LR, #2, #1 \n"
    " cmp    R4, #0 \n"
    " beq    MainStackBus \n"
    " b    ProcessStackBus \n"

    "MainStackBus: \n"
    " mrs    R4, MSP \n"
#if defined (__TI_ARM__ ) || defined (__MSP430__ )
    " movw R6, SCB_BusFault_puxContext\n"
    " movt R6, SCB_BusFault_puxContext\n"
#elif defined (__GNUC__ )
    " ldr R6, = SCB_BusFault_puxContext\n"
#endif
    " ldr R5, [R4, #0X10]\n"
    " str R5, [R6, #0x0]\n"/*SCB_BusFault_puxContext[0] R4*/
    " ldr R5, [R4, #0x14]\n"
    " str R5, [R6, #0x4]\n"/*SCB_BusFault_puxContext[1] R5*/
    " ldr R5, [R4, #0x18]\n"
    " str R5, [R6, #0x8]\n"/*SCB_BusFault_puxContext[2] R6*/
    " ldr R5, [R4, #0x1C]\n"
    " str R5, [R6, #0xC]\n"/*SCB_BusFault_puxContext[3] R3*/
    " ldr R5, [R4, #0x20]\n"
    " str R5, [R6, #0x10]\n"/*SCB_BusFault_puxContext[4] R52*/
    " ldr R5, [R4, #0x24]\n"
    " str R5, [R6, #0x14]\n"/*SCB_BusFault_puxContext[5] LR*/
    " ldr R5, [R4, #0x28]\n"
    " str R5, [R6, #0x18]\n"/*SCB_BusFault_puxContext[6] PC*/
    " ldr R5, [R4, #0x2C]\n"
    " str R5, [R6, #0x1C]\n"/*SCB_BusFault_puxContext[7] PSR*/
    " b    ProcessBus \n"

    "ProcessStackBus: \n"
    " mrs    R4, PSP \n"
#if defined (__TI_ARM__ ) || defined (__MSP430__ )
    " movw R6, SCB_BusFault_puxContext\n"
    " movt R6, SCB_BusFault_puxContext\n"
#elif defined (__GNUC__ )
    " ldr R6, = SCB_BusFault_puxContext\n"
#endif
    " ldr R5, [R4, #0X0]\n"
    " str R5, [R6, #0x0]\n"/*SCB_BusFault_puxContext[0] R4*/
    " ldr R5, [R4, #0x4]\n"
    " str R5, [R6, #0x4]\n"/*SCB_BusFault_puxContext[1] R5*/
    " ldr R5, [R4, #0x8]\n"
    " str R5, [R6, #0x8]\n"/*SCB_BusFault_puxContext[2] R6*/
    " ldr R5, [R4, #0xC]\n"
    " str R5, [R6, #0xC]\n"/*SCB_BusFault_puxContext[3] R3*/
    " ldr R5, [R4, #0x10]\n"
    " str R5, [R6, #0x10]\n"/*SCB_BusFault_puxContext[4] R52*/
    " ldr R5, [R4, #0x14]\n"
    " str R5, [R6, #0x14]\n"/*SCB_BusFault_puxContext[5] LR*/
    " ldr R5, [R4, #0x18]\n"
    " str R5, [R6, #0x18]\n"/*SCB_BusFault_puxContext[6] PC*/
    " ldr R5, [R4, #0x1C]\n"
    " str R5, [R6, #0x1C]\n"/*SCB_BusFault_puxContext[7] PSR*/

    "ProcessBus: \n"
    " pop {R4-R7}\n"
    " push {R0,R1,R2,LR} \n"
    " .global BusFault__vSendValues \n"
    " .global BusFault__vIRQVectorHandlerCustom \n"
    " .global BusFault__vSendValues \n"
#if defined (__TI_ARM__ ) || defined (__MSP430__ )
    " movw R2, BusFault__vSendValues\n"
    " movt R2, BusFault__vSendValues\n"
#elif defined (__GNUC__ )
    " ldr R2, = BusFault__vSendValues\n"
#endif
    " blx R2 \n"
    " movw R0, #0xE000\n"
    " movt R0, #0xE000\n"
#if defined (__TI_ARM__ ) || defined (__MSP430__ )
    " movw R1, SCB_BusFault_puxContext\n"
    " movt R1, SCB_BusFault_puxContext\n"
#elif defined (__GNUC__ )
    " ldr R1, = SCB_BusFault_puxContext\n"
#endif
#if defined (__TI_ARM__ ) || defined (__MSP430__ )
    " movw R2, BusFault__vIRQVectorHandlerCustom\n"
    " movt R2, BusFault__vIRQVectorHandlerCustom\n"
#elif defined (__GNUC__ )
    " ldr R2, = BusFault__vIRQVectorHandlerCustom\n"
#endif
    " blx R2 \n"
    " pop {R0,R1,R2,LR} \n"
    " BX LR \n");
}

void BusFault__vIRQVectorHandlerCustom(uintptr_t uptrModuleArg, void* pvArgument)
{
    SCB_t* pstSCBReg;
    UBase_t uxBusFault;
    SCB_pvfIRQSourceHandler_t pvfCallback;
    UBase_t uxBusAddressValid;
    UBase_t uxBusAddressFault;
    UBase_t* puxContext;
    UBase_t* puxContextOffset;

    pstSCBReg = (SCB_t*) uptrModuleArg;
    puxContext = (UBase_t*) pvArgument;

    uxBusAddressValid = 0UL;
    uxBusFault = pstSCBReg->CFSR;
    uxBusFault >>= 8UL;
    uxBusFault &= (UBase_t) SCB_enBUS_ALL;
    if(0UL == ((UBase_t) SCB_enBUS_ALL & uxBusFault))
    {
        UART__uxPrintf(UART_enMODULE_0, "Bus Fault Exception triggered by Software \n\r");
        pvfCallback = SCB_BusFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enBUS_BIT_SW);
        pvfCallback(SCB_BASE, (void*) SCB_enBUS_BIT_SW);
    }
    else
    {
        if((UBase_t) SCB_enBUS_LSPERR & uxBusFault)
        {
            pstSCBReg->CFSR = SCB_CFSR_R_LSPERR_CLEAR;
            UART__uxPrintf(UART_enMODULE_0, "Bus Fault on FPU Lazy State Preservation \n\r");
            pvfCallback = SCB_BusFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enBUS_BIT_LSPERR);
            pvfCallback(SCB_BASE, (void*) SCB_enBUS_BIT_LSPERR);
        }
        if((UBase_t) SCB_enBUS_STKERR & uxBusFault)
        {
            pstSCBReg->CFSR = SCB_CFSR_R_STKERR_CLEAR;
            UART__uxPrintf(UART_enMODULE_0,"Stacking Bus Fault, it occurred on an Exception/IRQ entry\n\r"
                                            "Context Values cannot be valid\n\r");
            pvfCallback = SCB_BusFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enBUS_BIT_STKERR);
            pvfCallback(SCB_BASE, (void*) SCB_enBUS_BIT_STKERR);
        }
        if((UBase_t) SCB_enBUS_UNSTKERR & uxBusFault)
        {
            pstSCBReg->CFSR = SCB_CFSR_R_UNSTKERR_CLEAR;
            UART__uxPrintf(UART_enMODULE_0,"Un-stacking Bus Fault, it occurred on an Exception/IRQ exit\n\r"
                                            "Context Values are related to the previous context\n\r");
            pvfCallback = SCB_BusFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enBUS_BIT_UNSTKERR);
            pvfCallback(SCB_BASE, (void*) SCB_enBUS_BIT_UNSTKERR);
        }
        if((UBase_t) SCB_enBUS_IMPRECISERR & uxBusFault)
        {
            pstSCBReg->CFSR = SCB_CFSR_R_IMPRECISERR_CLEAR;
            puxContextOffset = puxContext;
            puxContextOffset += 6UL;
            uxBusAddressFault = *puxContextOffset;
            UART__uxPrintf(UART_enMODULE_0, "Imprecise Data Bus Fault\n\r"
                            "Fault Address (Possible or near): %X\n\r", uxBusAddressFault);
            pvfCallback = SCB_BusFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enBUS_BIT_IMPRECISERR);
            pvfCallback(SCB_BASE, (void*) SCB_enBUS_BIT_IMPRECISERR);
        }
        if((UBase_t) SCB_enBUS_BFARVALID & uxBusFault)
        {
            pstSCBReg->CFSR = SCB_CFSR_R_BFARVALID_CLEAR;
            uxBusAddressValid = 1UL;
            pvfCallback = SCB_BusFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enBUS_BIT_BFARVALID);
            pvfCallback(SCB_BASE, (void*) SCB_enBUS_BIT_BFARVALID);
        }
        if((UBase_t) SCB_enBUS_PRECISERR & uxBusFault)
        {

            pstSCBReg->CFSR = SCB_CFSR_R_PRECISERR_CLEAR;
            UART__uxPrintf(UART_enMODULE_0, "Precise Data Bus Fault\n\r");
            if(1UL == uxBusAddressValid)
            {
                uxBusAddressFault = pstSCBReg->BFAR;
                UART__uxPrintf(UART_enMODULE_0, "Fault Address (Exact): %X\n\r", uxBusAddressFault);
            }
            puxContextOffset = puxContext;
            puxContextOffset += 6UL;
            uxBusAddressFault = *puxContextOffset;
            UART__uxPrintf(UART_enMODULE_0, "Fault Address (Possible): %X\n\r", uxBusAddressFault);
            pvfCallback = SCB_BusFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enBUS_BIT_PRECISERR);
            pvfCallback(SCB_BASE, (void*) SCB_enBUS_BIT_PRECISERR);
        }
        if((UBase_t) SCB_enBUS_IBUSERR & uxBusFault)
        {
            pstSCBReg->CFSR = SCB_CFSR_R_IBUSERR_CLEAR;
            puxContextOffset = puxContext;
            puxContextOffset += 6UL;
            uxBusAddressFault = *puxContextOffset;
            UART__uxPrintf(UART_enMODULE_0, "Instruction Bus Access Fault Address: %X\n\r", uxBusAddressFault);
            pvfCallback = SCB_BusFault__pvfGetIRQSourceHandler(SCB_enMODULE_0, SCB_enBUS_BIT_IBUSERR);
            pvfCallback(SCB_BASE, (void*) SCB_enBUS_BIT_IBUSERR);
        }
    }

}


