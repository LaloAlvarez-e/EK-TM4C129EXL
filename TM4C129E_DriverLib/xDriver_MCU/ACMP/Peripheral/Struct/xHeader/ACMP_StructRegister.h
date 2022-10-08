/**
 *
 * @file ACMP_StructRegister.h
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
 * @verbatim 28 nov. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 28 nov. 2020     vyldram    1.0         initial Version@endverbatim
 */
#ifndef XDRIVER_MCU_ACMP_PERIPHERAL_STRUCT_XHEADER_ACMP_STRUCTREGISTER_H_
#define XDRIVER_MCU_ACMP_PERIPHERAL_STRUCT_XHEADER_ACMP_STRUCTREGISTER_H_

#include <xDriver_MCU/ACMP/Peripheral/xHeader/ACMP_Enum.h>

/**
 *  Global Struct Definitions for ACMP
 */

typedef volatile struct
{
    volatile UBase_t IN0: 1;
    volatile UBase_t IN1: 1;
    volatile UBase_t IN2: 1;
    const UBase_t reserved: 29;
}ACMP_MIS_t;

typedef volatile struct
{
    volatile const UBase_t IN0: 1;
    volatile const UBase_t IN1: 1;
    volatile const UBase_t IN2: 1;
    const UBase_t reserved: 29;
}ACMP_RIS_t;

typedef volatile struct
{
    volatile UBase_t IN0: 1;
    volatile UBase_t IN1: 1;
    volatile UBase_t IN2: 1;
    const UBase_t reserved: 29;
}ACMP_INTEN_t;

typedef volatile struct
{
    volatile UBase_t VREF: 4;
    const UBase_t reserved: 4;
    volatile UBase_t RNG: 1;
    volatile UBase_t EN: 1;
    const UBase_t reserved1: 22;
}ACMP_REFCTL_t;

typedef volatile struct
{
    const UBase_t reserved: 1;
    volatile const UBase_t OVAL: 1;
    const UBase_t reserved1: 30;
}ACMP_STAT_t;

typedef volatile struct
{
    const UBase_t reserved: 1;
    volatile UBase_t CINV: 1;
    volatile UBase_t ISEN: 2;
    volatile UBase_t ISLVAL: 1;
    volatile UBase_t TSEN: 2;
    volatile UBase_t TSLVAL: 1;
    const UBase_t reserved1: 1;
    volatile UBase_t ASRCP: 2;
    volatile UBase_t TOEN: 1;
    const UBase_t reserved2: 20;
}ACMP_CTL_t;

typedef volatile struct
{
    volatile const UBase_t CMP0: 1;
    volatile const UBase_t CMP1: 1;
    volatile const UBase_t CMP2: 1;
    const UBase_t reserved: 13;
    volatile const UBase_t C0O: 1;
    volatile const UBase_t C1O: 1;
    volatile const UBase_t C2O: 1;
    const UBase_t reserved1: 13;
}ACMP_PP_t;

#endif /* XDRIVER_MCU_ACMP_PERIPHERAL_STRUCT_XHEADER_ACMP_STRUCTREGISTER_H_ */
