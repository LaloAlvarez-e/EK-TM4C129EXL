/**
 *
 * @file CAN_RegisterDefines_IFn_MCTL.h
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
 * @verbatim Apr 30, 2021 @endverbatim
 *
 * @author
 * @verbatim indevicemex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * Apr 30, 2021        indevicemex    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_CAN_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_CAN_REGISTERDEFINES_IFNMCTL_H_
#define XDRIVER_MCU_CAN_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_CAN_REGISTERDEFINES_IFNMCTL_H_

#include <xDriver_MCU/CAN/Peripheral/xHeader/CAN_Enum.h>

/******************************************************************************************
************************************ 20-21 IFn_MCTL *********************************************
******************************************************************************************/
/*--------*/
#define CAN_IFn_MCTL_R_DLC_MASK    ((UBase_t) 0x0000000FUL)
#define CAN_IFn_MCTL_R_DLC_BIT    ((UBase_t) 0UL)
#define CAN_IFn_MCTL_R_DLC_0BYTES    ((UBase_t) 0x00000000UL)
#define CAN_IFn_MCTL_R_DLC_1BYTES    ((UBase_t) 0x00000001UL)
#define CAN_IFn_MCTL_R_DLC_2BYTES    ((UBase_t) 0x00000002UL)
#define CAN_IFn_MCTL_R_DLC_3BYTES    ((UBase_t) 0x00000003UL)
#define CAN_IFn_MCTL_R_DLC_4BYTES    ((UBase_t) 0x00000004UL)
#define CAN_IFn_MCTL_R_DLC_5BYTES    ((UBase_t) 0x00000005UL)
#define CAN_IFn_MCTL_R_DLC_6BYTES    ((UBase_t) 0x00000006UL)
#define CAN_IFn_MCTL_R_DLC_7BYTES    ((UBase_t) 0x00000007UL)
#define CAN_IFn_MCTL_R_DLC_8BYTES    ((UBase_t) 0x00000008UL)

#define CAN_IFn_MCTL_DLC_MASK    ((UBase_t) 0x0000000FUL)
#define CAN_IFn_MCTL_DLC_0BYTES    ((UBase_t) 0x00000000UL)
#define CAN_IFn_MCTL_DLC_1BYTES    ((UBase_t) 0x00000001UL)
#define CAN_IFn_MCTL_DLC_2BYTES    ((UBase_t) 0x00000002UL)
#define CAN_IFn_MCTL_DLC_3BYTES    ((UBase_t) 0x00000003UL)
#define CAN_IFn_MCTL_DLC_4BYTES    ((UBase_t) 0x00000004UL)
#define CAN_IFn_MCTL_DLC_5BYTES    ((UBase_t) 0x00000005UL)
#define CAN_IFn_MCTL_DLC_6BYTES    ((UBase_t) 0x00000006UL)
#define CAN_IFn_MCTL_DLC_7BYTES    ((UBase_t) 0x00000007UL)
#define CAN_IFn_MCTL_DLC_8BYTES    ((UBase_t) 0x00000008UL)
/*--------*/

/*--------*/
#define CAN_IFn_MCTL_R_EOB_MASK    ((UBase_t) 0x00000080UL)
#define CAN_IFn_MCTL_R_EOB_BIT    ((UBase_t) 7UL)
#define CAN_IFn_MCTL_R_EOB_LEFT    ((UBase_t) 0x00000000UL)
#define CAN_IFn_MCTL_R_EOB_END    ((UBase_t) 0x00000080UL)

#define CAN_IFn_MCTL_EOB_MASK    ((UBase_t) 0x00000001UL)
#define CAN_IFn_MCTL_EOB_LEFT    ((UBase_t) 0x00000000UL)
#define CAN_IFn_MCTL_EOB_END    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define CAN_IFn_MCTL_R_TXRQST_MASK    ((UBase_t) 0x00000100UL)
#define CAN_IFn_MCTL_R_TXRQST_BIT    ((UBase_t) 8UL)
#define CAN_IFn_MCTL_R_TXRQST_IDLE    ((UBase_t) 0x00000000UL)
#define CAN_IFn_MCTL_R_TXRQST_REQ    ((UBase_t) 0x00000100UL)

#define CAN_IFn_MCTL_TXRQST_MASK    ((UBase_t) 0x00000001UL)
#define CAN_IFn_MCTL_TXRQST_IDLE    ((UBase_t) 0x00000000UL)
#define CAN_IFn_MCTL_TXRQST_REQ    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define CAN_IFn_MCTL_R_RMTEN_MASK    ((UBase_t) 0x00000200UL)
#define CAN_IFn_MCTL_R_RMTEN_BIT    ((UBase_t) 9UL)
#define CAN_IFn_MCTL_R_RMTEN_UNCHANGED    ((UBase_t) 0x00000000UL)
#define CAN_IFn_MCTL_R_RMTEN_SET    ((UBase_t) 0x00000200UL)

#define CAN_IFn_MCTL_RMTEN_MASK    ((UBase_t) 0x00000001UL)
#define CAN_IFn_MCTL_RMTEN_UNCHANGED    ((UBase_t) 0x00000000UL)
#define CAN_IFn_MCTL_RMTEN_SET    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define CAN_IFn_MCTL_R_RXIE_MASK    ((UBase_t) 0x00000400UL)
#define CAN_IFn_MCTL_R_RXIE_BIT    ((UBase_t) 10UL)
#define CAN_IFn_MCTL_R_RXIE_UNCHANGED    ((UBase_t) 0x00000000UL)
#define CAN_IFn_MCTL_R_RXIE_SET    ((UBase_t) 0x00000400UL)

#define CAN_IFn_MCTL_RXIE_MASK    ((UBase_t) 0x00000001UL)
#define CAN_IFn_MCTL_RXIE_UNCHANGED    ((UBase_t) 0x00000000UL)
#define CAN_IFn_MCTL_RXIE_SET    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define CAN_IFn_MCTL_R_TXIE_MASK    ((UBase_t) 0x00000800UL)
#define CAN_IFn_MCTL_R_TXIE_BIT    ((UBase_t) 11UL)
#define CAN_IFn_MCTL_R_TXIE_UNCHANGED    ((UBase_t) 0x00000000UL)
#define CAN_IFn_MCTL_R_TXIE_SET    ((UBase_t) 0x00000800UL)

#define CAN_IFn_MCTL_TXIE_MASK    ((UBase_t) 0x00000001UL)
#define CAN_IFn_MCTL_TXIE_UNCHANGED    ((UBase_t) 0x00000000UL)
#define CAN_IFn_MCTL_TXIE_SET    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define CAN_IFn_MCTL_R_UMASK_MASK    ((UBase_t) 0x00001000UL)
#define CAN_IFn_MCTL_R_UMASK_BIT    ((UBase_t) 12UL)
#define CAN_IFn_MCTL_R_UMASK_IGNORED    ((UBase_t) 0x00000000UL)
#define CAN_IFn_MCTL_R_UMASK_USE    ((UBase_t) 0x00001000UL)

#define CAN_IFn_MCTL_UMASK_MASK    ((UBase_t) 0x00000001UL)
#define CAN_IFn_MCTL_UMASK_IGNORED    ((UBase_t) 0x00000000UL)
#define CAN_IFn_MCTL_UMASK_USE    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define CAN_IFn_MCTL_R_INTPND_MASK    ((UBase_t) 0x00002000UL)
#define CAN_IFn_MCTL_R_INTPND_BIT    ((UBase_t) 13UL)
#define CAN_IFn_MCTL_R_INTPND_INACTIVE    ((UBase_t) 0x00000000UL)
#define CAN_IFn_MCTL_R_INTPND_ACTIVE    ((UBase_t) 0x00002000UL)

#define CAN_IFn_MCTL_INTPND_MASK    ((UBase_t) 0x00000001UL)
#define CAN_IFn_MCTL_INTPND_INACTIVE    ((UBase_t) 0x00000000UL)
#define CAN_IFn_MCTL_INTPND_ACTIVE    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define CAN_IFn_MCTL_R_MSGLST_MASK    ((UBase_t) 0x00004000UL)
#define CAN_IFn_MCTL_R_MSGLST_BIT    ((UBase_t) 14UL)
#define CAN_IFn_MCTL_R_MSGLST_NOLOST    ((UBase_t) 0x00000000UL)
#define CAN_IFn_MCTL_R_MSGLST_LOST    ((UBase_t) 0x00004000UL)

#define CAN_IFn_MCTL_MSGLST_MASK    ((UBase_t) 0x00000001UL)
#define CAN_IFn_MCTL_MSGLST_NOLOST    ((UBase_t) 0x00000000UL)
#define CAN_IFn_MCTL_MSGLST_LOST    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define CAN_IFn_MCTL_R_NEWDAT_MASK    ((UBase_t) 0x00008000UL)
#define CAN_IFn_MCTL_R_NEWDAT_BIT    ((UBase_t) 15UL)
#define CAN_IFn_MCTL_R_NEWDAT_NO    ((UBase_t) 0x00000000UL)
#define CAN_IFn_MCTL_R_NEWDAT_NEW    ((UBase_t) 0x00008000UL)

#define CAN_IFn_MCTL_NEWDAT_MASK    ((UBase_t) 0x00000001UL)
#define CAN_IFn_MCTL_NEWDAT_NO    ((UBase_t) 0x00000000UL)
#define CAN_IFn_MCTL_NEWDAT_NEW    ((UBase_t) 0x00000001UL)
/*--------*/

#endif /* XDRIVER_MCU_CAN_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_CAN_REGISTERDEFINES_IFNMCTL_H_ */
