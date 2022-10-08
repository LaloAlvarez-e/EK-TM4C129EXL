/**
 *
 * @file I2C_RegisterDefines_SICR.h
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
 * @verbatim 7 mar. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 7 mar. 2021     vyldram    1.0         initial Version@endverbatim
 */
#ifndef XDRIVER_MCU_I2C_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_I2C_REGISTERDEFINES_SICR_H_
#define XDRIVER_MCU_I2C_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_I2C_REGISTERDEFINES_SICR_H_

#include <xDriver_MCU/I2C/Peripheral/xHeader/I2C_Enum.h>

/******************************************************************************************
************************************ 18 SICR *********************************************
******************************************************************************************/

/*--------*/
#define I2C_SLAVE_ICR_R_DATAIC_MASK    ((UBase_t) 0x00000001UL)
#define I2C_SLAVE_ICR_R_DATAIC_BIT    ((UBase_t) 0UL)
#define I2C_SLAVE_ICR_R_DATAIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SLAVE_ICR_R_DATAIC_CLEAR    ((UBase_t) 0x00000001UL)

#define I2C_SLAVE_ICR_DATAIC_MASK    ((UBase_t) 0x00000001UL)
#define I2C_SLAVE_ICR_DATAIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SLAVE_ICR_DATAIC_CLEAR    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SLAVE_ICR_R_STARTIC_MASK    ((UBase_t) 0x00000002UL)
#define I2C_SLAVE_ICR_R_STARTIC_BIT    ((UBase_t) 1UL)
#define I2C_SLAVE_ICR_R_STARTIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SLAVE_ICR_R_STARTIC_CLEAR    ((UBase_t) 0x00000002UL)

#define I2C_SLAVE_ICR_STARTIC_MASK    ((UBase_t) 0x00000001UL)
#define I2C_SLAVE_ICR_STARTIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SLAVE_ICR_STARTIC_CLEAR    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SLAVE_ICR_R_STOPIC_MASK    ((UBase_t) 0x00000004UL)
#define I2C_SLAVE_ICR_R_STOPIC_BIT    ((UBase_t) 2UL)
#define I2C_SLAVE_ICR_R_STOPIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SLAVE_ICR_R_STOPIC_CLEAR    ((UBase_t) 0x00000004UL)

#define I2C_SLAVE_ICR_STOPIC_MASK    ((UBase_t) 0x00000001UL)
#define I2C_SLAVE_ICR_STOPIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SLAVE_ICR_STOPIC_CLEAR    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SLAVE_ICR_R_DMARXIC_MASK    ((UBase_t) 0x00000008UL)
#define I2C_SLAVE_ICR_R_DMARXIC_BIT    ((UBase_t) 3UL)
#define I2C_SLAVE_ICR_R_DMARXIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SLAVE_ICR_R_DMARXIC_CLEAR    ((UBase_t) 0x00000008UL)

#define I2C_SLAVE_ICR_DMARXIC_MASK    ((UBase_t) 0x00000001UL)
#define I2C_SLAVE_ICR_DMARXIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SLAVE_ICR_DMARXIC_CLEAR    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SLAVE_ICR_R_DMATXIC_MASK    ((UBase_t) 0x00000010UL)
#define I2C_SLAVE_ICR_R_DMATXIC_BIT    ((UBase_t) 4UL)
#define I2C_SLAVE_ICR_R_DMATXIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SLAVE_ICR_R_DMATXIC_CLEAR    ((UBase_t) 0x00000010UL)

#define I2C_SLAVE_ICR_DMATXIC_MASK    ((UBase_t) 0x00000001UL)
#define I2C_SLAVE_ICR_DMATXIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SLAVE_ICR_DMATXIC_CLEAR    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SLAVE_ICR_R_TXIC_MASK    ((UBase_t) 0x00000020UL)
#define I2C_SLAVE_ICR_R_TXIC_BIT    ((UBase_t) 5UL)
#define I2C_SLAVE_ICR_R_TXIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SLAVE_ICR_R_TXIC_CLEAR    ((UBase_t) 0x00000020UL)

#define I2C_SLAVE_ICR_TXIC_MASK    ((UBase_t) 0x00000001UL)
#define I2C_SLAVE_ICR_TXIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SLAVE_ICR_TXIC_CLEAR    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SLAVE_ICR_R_RXIC_MASK    ((UBase_t) 0x00000040UL)
#define I2C_SLAVE_ICR_R_RXIC_BIT    ((UBase_t) 6UL)
#define I2C_SLAVE_ICR_R_RXIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SLAVE_ICR_R_RXIC_CLEAR    ((UBase_t) 0x00000040UL)

#define I2C_SLAVE_ICR_RXIC_MASK    ((UBase_t) 0x00000001UL)
#define I2C_SLAVE_ICR_RXIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SLAVE_ICR_RXIC_CLEAR    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SLAVE_ICR_R_TXFEIC_MASK    ((UBase_t) 0x00000080UL)
#define I2C_SLAVE_ICR_R_TXFEIC_BIT    ((UBase_t) 7UL)
#define I2C_SLAVE_ICR_R_TXFEIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SLAVE_ICR_R_TXFEIC_CLEAR    ((UBase_t) 0x00000080UL)

#define I2C_SLAVE_ICR_TXFEIC_MASK    ((UBase_t) 0x00000001UL)
#define I2C_SLAVE_ICR_TXFEIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SLAVE_ICR_TXFEIC_CLEAR    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SLAVE_ICR_R_RXFFIC_MASK    ((UBase_t) 0x00000100UL)
#define I2C_SLAVE_ICR_R_RXFFIC_BIT    ((UBase_t) 8UL)
#define I2C_SLAVE_ICR_R_RXFFIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SLAVE_ICR_R_RXFFIC_CLEAR    ((UBase_t) 0x00000100UL)

#define I2C_SLAVE_ICR_RXFFIC_MASK    ((UBase_t) 0x00000001UL)
#define I2C_SLAVE_ICR_RXFFIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SLAVE_ICR_RXFFIC_CLEAR    ((UBase_t) 0x00000001UL)
/*--------*/

/******************************************************************************************
************************************ 18 SICR *********************************************
******************************************************************************************/

/*--------*/
#define I2C_SICR_R_DATAIC_MASK    ((UBase_t) 0x00000001UL)
#define I2C_SICR_R_DATAIC_BIT    ((UBase_t) 0UL)
#define I2C_SICR_R_DATAIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SICR_R_DATAIC_CLEAR    ((UBase_t) 0x00000001UL)

#define I2C_SICR_DATAIC_MASK    ((UBase_t) 0x00000001UL)
#define I2C_SICR_DATAIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SICR_DATAIC_CLEAR    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SICR_R_STARTIC_MASK    ((UBase_t) 0x00000002UL)
#define I2C_SICR_R_STARTIC_BIT    ((UBase_t) 1UL)
#define I2C_SICR_R_STARTIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SICR_R_STARTIC_CLEAR    ((UBase_t) 0x00000002UL)

#define I2C_SICR_STARTIC_MASK    ((UBase_t) 0x00000001UL)
#define I2C_SICR_STARTIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SICR_STARTIC_CLEAR    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SICR_R_STOPIC_MASK    ((UBase_t) 0x00000004UL)
#define I2C_SICR_R_STOPIC_BIT    ((UBase_t) 2UL)
#define I2C_SICR_R_STOPIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SICR_R_STOPIC_CLEAR    ((UBase_t) 0x00000004UL)

#define I2C_SICR_STOPIC_MASK    ((UBase_t) 0x00000001UL)
#define I2C_SICR_STOPIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SICR_STOPIC_CLEAR    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SICR_R_DMARXIC_MASK    ((UBase_t) 0x00000008UL)
#define I2C_SICR_R_DMARXIC_BIT    ((UBase_t) 3UL)
#define I2C_SICR_R_DMARXIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SICR_R_DMARXIC_CLEAR    ((UBase_t) 0x00000008UL)

#define I2C_SICR_DMARXIC_MASK    ((UBase_t) 0x00000001UL)
#define I2C_SICR_DMARXIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SICR_DMARXIC_CLEAR    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SICR_R_DMATXIC_MASK    ((UBase_t) 0x00000010UL)
#define I2C_SICR_R_DMATXIC_BIT    ((UBase_t) 4UL)
#define I2C_SICR_R_DMATXIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SICR_R_DMATXIC_CLEAR    ((UBase_t) 0x00000010UL)

#define I2C_SICR_DMATXIC_MASK    ((UBase_t) 0x00000001UL)
#define I2C_SICR_DMATXIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SICR_DMATXIC_CLEAR    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SICR_R_TXIC_MASK    ((UBase_t) 0x00000020UL)
#define I2C_SICR_R_TXIC_BIT    ((UBase_t) 5UL)
#define I2C_SICR_R_TXIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SICR_R_TXIC_CLEAR    ((UBase_t) 0x00000020UL)

#define I2C_SICR_TXIC_MASK    ((UBase_t) 0x00000001UL)
#define I2C_SICR_TXIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SICR_TXIC_CLEAR    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SICR_R_RXIC_MASK    ((UBase_t) 0x00000040UL)
#define I2C_SICR_R_RXIC_BIT    ((UBase_t) 6UL)
#define I2C_SICR_R_RXIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SICR_R_RXIC_CLEAR    ((UBase_t) 0x00000040UL)

#define I2C_SICR_RXIC_MASK    ((UBase_t) 0x00000001UL)
#define I2C_SICR_RXIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SICR_RXIC_CLEAR    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SICR_R_TXFEIC_MASK    ((UBase_t) 0x00000080UL)
#define I2C_SICR_R_TXFEIC_BIT    ((UBase_t) 7UL)
#define I2C_SICR_R_TXFEIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SICR_R_TXFEIC_CLEAR    ((UBase_t) 0x00000080UL)

#define I2C_SICR_TXFEIC_MASK    ((UBase_t) 0x00000001UL)
#define I2C_SICR_TXFEIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SICR_TXFEIC_CLEAR    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SICR_R_RXFFIC_MASK    ((UBase_t) 0x00000100UL)
#define I2C_SICR_R_RXFFIC_BIT    ((UBase_t) 8UL)
#define I2C_SICR_R_RXFFIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SICR_R_RXFFIC_CLEAR    ((UBase_t) 0x00000100UL)

#define I2C_SICR_RXFFIC_MASK    ((UBase_t) 0x00000001UL)
#define I2C_SICR_RXFFIC_NOEFFECT    ((UBase_t) 0x00000000UL)
#define I2C_SICR_RXFFIC_CLEAR    ((UBase_t) 0x00000001UL)
/*--------*/
#endif /* XDRIVER_MCU_I2C_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_I2C_REGISTERDEFINES_SICR_H_ */
