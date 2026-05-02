/**
 *
 * @file HIB_InterruptRoutine_Vector.c
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
#include <xApplication_MCU/HIB/Interrupt/InterruptRoutine/xHeader/HIB_InterruptRoutine_Vector.h>

#include <xApplication_MCU/HIB/Intrinsics/xHeader/HIB_Dependencies.h>

void HIB__vIRQVectorHandler(void)
{
    volatile UBase_t uxReady;
    UBase_t uxStatus;
    HIB_pvfIRQSourceHandler_t pfIrqSourceHandlerReg;

    uxReady = SYSCTL_PRHIB_R;
    if(0UL == (SYSCTL_PRHIB_R_HIB_MASK & uxReady))
    {
        return;
    }

    uxStatus = HIB0_MIS_R;
    if(0UL != ((UBase_t) HIB_enINTMASK_RTCALT0 & uxStatus))
    {
        HIB__enWaitWrite(HIB_enMODULE_0, 0);
        HIB0_IC_R = (UBase_t) HIB_enINTMASK_RTCALT0;
        pfIrqSourceHandlerReg = HIB__pvfGetIRQSourceHandler(HIB_enMODULE_0, HIB_enINT_RTCALT0);
        pfIrqSourceHandlerReg(HIB_BASE, (void*) HIB_enINT_RTCALT0);
    }
    if(0UL != ((UBase_t) HIB_enINTMASK_LOWBAT & uxStatus))
    {
        HIB__enWaitWrite(HIB_enMODULE_0, 0);
        HIB0_IC_R = (UBase_t) HIB_enINTMASK_LOWBAT;
        pfIrqSourceHandlerReg = HIB__pvfGetIRQSourceHandler(HIB_enMODULE_0, HIB_enINT_LOWBAT);
        pfIrqSourceHandlerReg(HIB_BASE, (void*) HIB_enINT_LOWBAT);
    }
    if(0UL != ((UBase_t) HIB_enINTMASK_EXTW & uxStatus))
    {
        HIB__enWaitWrite(HIB_enMODULE_0, 0);
        HIB0_IC_R = (UBase_t) HIB_enINTMASK_EXTW;
        pfIrqSourceHandlerReg = HIB__pvfGetIRQSourceHandler(HIB_enMODULE_0, HIB_enINT_EXTW);
        pfIrqSourceHandlerReg(HIB_BASE, (void*) HIB_enINT_EXTW);
    }
    if(0UL != ((UBase_t) HIB_enINTMASK_WC & uxStatus))
    {
        /*No wait required*/
        HIB0_IC_R = (UBase_t) HIB_enINTMASK_WC;
        pfIrqSourceHandlerReg = HIB__pvfGetIRQSourceHandler(HIB_enMODULE_0, HIB_enINT_WC);
        pfIrqSourceHandlerReg(HIB_BASE, (void*) HIB_enINT_WC);
    }
    if(0UL != ((UBase_t) HIB_enINTMASK_PADIOWK & uxStatus))
    {
        /*No wait required*/
        HIB0_IC_R = (UBase_t) HIB_enINTMASK_PADIOWK;
        pfIrqSourceHandlerReg = HIB__pvfGetIRQSourceHandler(HIB_enMODULE_0, HIB_enINT_PADIOWK);
        pfIrqSourceHandlerReg(HIB_BASE, (void*) HIB_enINT_PADIOWK);
    }
    if(0UL != ((UBase_t) HIB_enINTMASK_RSTWK & uxStatus))
    {
        /*No wait required*/
        HIB0_IC_R = (UBase_t) HIB_enINTMASK_RSTWK;
        pfIrqSourceHandlerReg = HIB__pvfGetIRQSourceHandler(HIB_enMODULE_0, HIB_enINT_RSTWK);
        pfIrqSourceHandlerReg(HIB_BASE, (void*) HIB_enINT_RSTWK);
    }
    if(0UL != ((UBase_t) HIB_enINTMASK_VDDFAIL & uxStatus))
    {
        HIB__enWaitWrite(HIB_enMODULE_0, 0);
        HIB0_IC_R = (UBase_t) HIB_enINTMASK_VDDFAIL;
        pfIrqSourceHandlerReg = HIB__pvfGetIRQSourceHandler(HIB_enMODULE_0, HIB_enINT_VDDFAIL);
        pfIrqSourceHandlerReg(HIB_BASE, (void*) HIB_enINT_VDDFAIL);
    }
}
