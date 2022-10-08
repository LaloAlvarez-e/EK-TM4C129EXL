/**
 *
 * @file QEI_StructRegister.h
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
 * @verbatim Apr 5, 2021 @endverbatim
 *
 * @author
 * @verbatim indevicemex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * Apr 5, 2021        indevicemex    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_QEI_PERIPHERAL_STRUCT_XHEADER_QEI_STRUCTREGISTER_H_
#define XDRIVER_MCU_QEI_PERIPHERAL_STRUCT_XHEADER_QEI_STRUCTREGISTER_H_

#include <xDriver_MCU/QEI/Peripheral/xHeader/QEI_Enum.h>

/**
 *  Global Struct Definitions for QEI
 */

typedef volatile struct
{
    volatile UBase_t ENABLE: 1;
    volatile UBase_t SWAP: 1;
    volatile UBase_t SIGMODE: 1;
    volatile UBase_t CAPMODE: 1;
    volatile UBase_t RESMODE: 1;
    volatile UBase_t VELEN: 1;
    volatile UBase_t VELDIV: 3;
    volatile UBase_t INVA: 1;
    volatile UBase_t INVB: 1;
    volatile UBase_t INVI: 1;
    volatile UBase_t STALLEN: 1;
    volatile UBase_t FILTEN: 1;
    const UBase_t reserved: 2;
    volatile UBase_t FILTCNT: 4;
    const UBase_t reserved2: 12;
}QEICTL_t;

typedef volatile struct
{
    volatile const UBase_t ERROR: 1;
    volatile const UBase_t DIRECTION: 1;
    const UBase_t reserved: 30;
}QEISTAT_t;

typedef volatile struct
{
    volatile UBase_t POSITION: 32;
}QEIPOS_t;

typedef volatile struct
{
    volatile UBase_t MAXPOS: 32;
}QEIMAXPOS_t;

typedef volatile struct
{
    volatile UBase_t LOAD: 32;
}QEILOAD_t;

typedef volatile struct
{
    volatile const UBase_t TIME: 32;
}QEITIME_t;

typedef volatile struct
{
    volatile const UBase_t COUNT: 32;
}QEICOUNT_t;

typedef volatile struct
{
    volatile const UBase_t SPEED: 32;
}QEISPEED_t;

typedef volatile struct
{
    volatile UBase_t INTINDEX: 1;
    volatile UBase_t INTTIMER: 1;
    volatile UBase_t INTDIR: 1;
    volatile UBase_t INTERROR: 1;
    const UBase_t reserved: 28;
}QEIINTEN_t;

typedef volatile struct
{
    volatile const UBase_t INTINDEX: 1;
    volatile const UBase_t INTTIMER: 1;
    volatile const UBase_t INTDIR: 1;
    volatile const UBase_t INTERROR: 1;
    const UBase_t reserved: 28;
}QEIRIS_t;

typedef volatile struct
{
    volatile UBase_t INTINDEX: 1;
    volatile UBase_t INTTIMER: 1;
    volatile UBase_t INTDIR: 1;
    volatile UBase_t INTERROR: 1;
    const UBase_t reserved: 28;
}QEIISC_t;

#endif /* XDRIVER_MCU_QEI_PERIPHERAL_STRUCT_XHEADER_QEI_STRUCTREGISTER_H_ */
