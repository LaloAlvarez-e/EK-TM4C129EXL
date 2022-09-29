/**
 *
 * @file I2C_RegisterDefines_SMIS.h
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
#ifndef XDRIVER_MCU_I2C_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_I2C_REGISTERDEFINES_SMIS_H_
#define XDRIVER_MCU_I2C_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_I2C_REGISTERDEFINES_SMIS_H_

#include <xDriver_MCU/I2C/Peripheral/xHeader/I2C_Enum.h>

/******************************************************************************************
************************************ 18 SMIS *********************************************
******************************************************************************************/

/*--------*/
#define I2C_SLAVE_MIS_R_DATAMIS_MASK    ((uint32_t) 0x00000001UL)
#define I2C_SLAVE_MIS_R_DATAMIS_BIT    ((uint32_t) 0UL)
#define I2C_SLAVE_MIS_R_DATAMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SLAVE_MIS_R_DATAMIS_ACTIVE    ((uint32_t) 0x00000001UL)

#define I2C_SLAVE_MIS_DATAMIS_MASK    ((uint32_t) 0x00000001UL)
#define I2C_SLAVE_MIS_DATAMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SLAVE_MIS_DATAMIS_ACTIVE    ((uint32_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SLAVE_MIS_R_STARTMIS_MASK    ((uint32_t) 0x00000002UL)
#define I2C_SLAVE_MIS_R_STARTMIS_BIT    ((uint32_t) 1UL)
#define I2C_SLAVE_MIS_R_STARTMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SLAVE_MIS_R_STARTMIS_ACTIVE    ((uint32_t) 0x00000002UL)

#define I2C_SLAVE_MIS_STARTMIS_MASK    ((uint32_t) 0x00000001UL)
#define I2C_SLAVE_MIS_STARTMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SLAVE_MIS_STARTMIS_ACTIVE    ((uint32_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SLAVE_MIS_R_STOPMIS_MASK    ((uint32_t) 0x00000004UL)
#define I2C_SLAVE_MIS_R_STOPMIS_BIT    ((uint32_t) 2UL)
#define I2C_SLAVE_MIS_R_STOPMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SLAVE_MIS_R_STOPMIS_ACTIVE    ((uint32_t) 0x00000004UL)

#define I2C_SLAVE_MIS_STOPMIS_MASK    ((uint32_t) 0x00000001UL)
#define I2C_SLAVE_MIS_STOPMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SLAVE_MIS_STOPMIS_ACTIVE    ((uint32_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SLAVE_MIS_R_DMARXMIS_MASK    ((uint32_t) 0x00000008UL)
#define I2C_SLAVE_MIS_R_DMARXMIS_BIT    ((uint32_t) 3UL)
#define I2C_SLAVE_MIS_R_DMARXMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SLAVE_MIS_R_DMARXMIS_ACTIVE    ((uint32_t) 0x00000008UL)

#define I2C_SLAVE_MIS_DMARXMIS_MASK    ((uint32_t) 0x00000001UL)
#define I2C_SLAVE_MIS_DMARXMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SLAVE_MIS_DMARXMIS_ACTIVE    ((uint32_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SLAVE_MIS_R_DMATXMIS_MASK    ((uint32_t) 0x00000010UL)
#define I2C_SLAVE_MIS_R_DMATXMIS_BIT    ((uint32_t) 4UL)
#define I2C_SLAVE_MIS_R_DMATXMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SLAVE_MIS_R_DMATXMIS_ACTIVE    ((uint32_t) 0x00000010UL)

#define I2C_SLAVE_MIS_DMATXMIS_MASK    ((uint32_t) 0x00000001UL)
#define I2C_SLAVE_MIS_DMATXMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SLAVE_MIS_DMATXMIS_ACTIVE    ((uint32_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SLAVE_MIS_R_TXMIS_MASK    ((uint32_t) 0x00000020UL)
#define I2C_SLAVE_MIS_R_TXMIS_BIT    ((uint32_t) 5UL)
#define I2C_SLAVE_MIS_R_TXMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SLAVE_MIS_R_TXMIS_ACTIVE    ((uint32_t) 0x00000020UL)

#define I2C_SLAVE_MIS_TXMIS_MASK    ((uint32_t) 0x00000001UL)
#define I2C_SLAVE_MIS_TXMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SLAVE_MIS_TXMIS_ACTIVE    ((uint32_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SLAVE_MIS_R_RXMIS_MASK    ((uint32_t) 0x00000040UL)
#define I2C_SLAVE_MIS_R_RXMIS_BIT    ((uint32_t) 6UL)
#define I2C_SLAVE_MIS_R_RXMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SLAVE_MIS_R_RXMIS_ACTIVE    ((uint32_t) 0x00000040UL)

#define I2C_SLAVE_MIS_RXMIS_MASK    ((uint32_t) 0x00000001UL)
#define I2C_SLAVE_MIS_RXMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SLAVE_MIS_RXMIS_ACTIVE    ((uint32_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SLAVE_MIS_R_TXFEMIS_MASK    ((uint32_t) 0x00000080UL)
#define I2C_SLAVE_MIS_R_TXFEMIS_BIT    ((uint32_t) 7UL)
#define I2C_SLAVE_MIS_R_TXFEMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SLAVE_MIS_R_TXFEMIS_ACTIVE    ((uint32_t) 0x00000080UL)

#define I2C_SLAVE_MIS_TXFEMIS_MASK    ((uint32_t) 0x00000001UL)
#define I2C_SLAVE_MIS_TXFEMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SLAVE_MIS_TXFEMIS_ACTIVE    ((uint32_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SLAVE_MIS_R_RXFFMIS_MASK    ((uint32_t) 0x00000100UL)
#define I2C_SLAVE_MIS_R_RXFFMIS_BIT    ((uint32_t) 8UL)
#define I2C_SLAVE_MIS_R_RXFFMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SLAVE_MIS_R_RXFFMIS_ACTIVE    ((uint32_t) 0x00000100UL)

#define I2C_SLAVE_MIS_RXFFMIS_MASK    ((uint32_t) 0x00000001UL)
#define I2C_SLAVE_MIS_RXFFMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SLAVE_MIS_RXFFMIS_ACTIVE    ((uint32_t) 0x00000001UL)
/*--------*/

/******************************************************************************************
************************************ 18 SMIS *********************************************
******************************************************************************************/

/*--------*/
#define I2C_SMIS_R_DATAMIS_MASK    ((uint32_t) 0x00000001UL)
#define I2C_SMIS_R_DATAMIS_BIT    ((uint32_t) 0UL)
#define I2C_SMIS_R_DATAMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SMIS_R_DATAMIS_ACTIVE    ((uint32_t) 0x00000001UL)

#define I2C_SMIS_DATAMIS_MASK    ((uint32_t) 0x00000001UL)
#define I2C_SMIS_DATAMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SMIS_DATAMIS_ACTIVE    ((uint32_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SMIS_R_STARTMIS_MASK    ((uint32_t) 0x00000002UL)
#define I2C_SMIS_R_STARTMIS_BIT    ((uint32_t) 1UL)
#define I2C_SMIS_R_STARTMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SMIS_R_STARTMIS_ACTIVE    ((uint32_t) 0x00000002UL)

#define I2C_SMIS_STARTMIS_MASK    ((uint32_t) 0x00000001UL)
#define I2C_SMIS_STARTMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SMIS_STARTMIS_ACTIVE    ((uint32_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SMIS_R_STOPMIS_MASK    ((uint32_t) 0x00000004UL)
#define I2C_SMIS_R_STOPMIS_BIT    ((uint32_t) 2UL)
#define I2C_SMIS_R_STOPMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SMIS_R_STOPMIS_ACTIVE    ((uint32_t) 0x00000004UL)

#define I2C_SMIS_STOPMIS_MASK    ((uint32_t) 0x00000001UL)
#define I2C_SMIS_STOPMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SMIS_STOPMIS_ACTIVE    ((uint32_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SMIS_R_DMARXMIS_MASK    ((uint32_t) 0x00000008UL)
#define I2C_SMIS_R_DMARXMIS_BIT    ((uint32_t) 3UL)
#define I2C_SMIS_R_DMARXMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SMIS_R_DMARXMIS_ACTIVE    ((uint32_t) 0x00000008UL)

#define I2C_SMIS_DMARXMIS_MASK    ((uint32_t) 0x00000001UL)
#define I2C_SMIS_DMARXMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SMIS_DMARXMIS_ACTIVE    ((uint32_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SMIS_R_DMATXMIS_MASK    ((uint32_t) 0x00000010UL)
#define I2C_SMIS_R_DMATXMIS_BIT    ((uint32_t) 4UL)
#define I2C_SMIS_R_DMATXMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SMIS_R_DMATXMIS_ACTIVE    ((uint32_t) 0x00000010UL)

#define I2C_SMIS_DMATXMIS_MASK    ((uint32_t) 0x00000001UL)
#define I2C_SMIS_DMATXMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SMIS_DMATXMIS_ACTIVE    ((uint32_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SMIS_R_TXMIS_MASK    ((uint32_t) 0x00000020UL)
#define I2C_SMIS_R_TXMIS_BIT    ((uint32_t) 5UL)
#define I2C_SMIS_R_TXMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SMIS_R_TXMIS_ACTIVE    ((uint32_t) 0x00000020UL)

#define I2C_SMIS_TXMIS_MASK    ((uint32_t) 0x00000001UL)
#define I2C_SMIS_TXMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SMIS_TXMIS_ACTIVE    ((uint32_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SMIS_R_RXMIS_MASK    ((uint32_t) 0x00000040UL)
#define I2C_SMIS_R_RXMIS_BIT    ((uint32_t) 6UL)
#define I2C_SMIS_R_RXMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SMIS_R_RXMIS_ACTIVE    ((uint32_t) 0x00000040UL)

#define I2C_SMIS_RXMIS_MASK    ((uint32_t) 0x00000001UL)
#define I2C_SMIS_RXMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SMIS_RXMIS_ACTIVE    ((uint32_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SMIS_R_TXFEMIS_MASK    ((uint32_t) 0x00000080UL)
#define I2C_SMIS_R_TXFEMIS_BIT    ((uint32_t) 7UL)
#define I2C_SMIS_R_TXFEMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SMIS_R_TXFEMIS_ACTIVE    ((uint32_t) 0x00000080UL)

#define I2C_SMIS_TXFEMIS_MASK    ((uint32_t) 0x00000001UL)
#define I2C_SMIS_TXFEMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SMIS_TXFEMIS_ACTIVE    ((uint32_t) 0x00000001UL)
/*--------*/

/*--------*/
#define I2C_SMIS_R_RXFFMIS_MASK    ((uint32_t) 0x00000100UL)
#define I2C_SMIS_R_RXFFMIS_BIT    ((uint32_t) 8UL)
#define I2C_SMIS_R_RXFFMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SMIS_R_RXFFMIS_ACTIVE    ((uint32_t) 0x00000100UL)

#define I2C_SMIS_RXFFMIS_MASK    ((uint32_t) 0x00000001UL)
#define I2C_SMIS_RXFFMIS_INACTIVE    ((uint32_t) 0x00000000UL)
#define I2C_SMIS_RXFFMIS_ACTIVE    ((uint32_t) 0x00000001UL)
/*--------*/
#endif /* XDRIVER_MCU_I2C_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_I2C_REGISTERDEFINES_SMIS_H_ */
