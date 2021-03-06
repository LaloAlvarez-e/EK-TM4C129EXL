/*
 * SYSCTL_Voltage.h
 *
 *  Created on: 13 jun. 2021
 *      Author: InDeviceMex
 */

#ifndef XDRIVER_MCU_SYSCTL_DRIVER_XHEADER_SYSCTL_VOLTAGE_H_
#define XDRIVER_MCU_SYSCTL_DRIVER_XHEADER_SYSCTL_VOLTAGE_H_

#include <xDriver_MCU/SYSCTL/Peripheral/xHeader/SYSCTL_Enum.h>

void SYSCTL__vSetBOREvent_VDD(SYSCTL_nBOR_EVENT enBOREvent);
void SYSCTL__vSetBOREvent_VDDA(SYSCTL_nBOR_EVENT enBOREvent);
void SYSCTL__vSetBOREvent(SYSCTL_nBOR_EVENT enBOREvent_VDD,
                          SYSCTL_nBOR_EVENT enBOREvent_VDDA);

SYSCTL_nBOR_EVENT SYSCTL__enGetBOREvent_VDD(void);
SYSCTL_nBOR_EVENT SYSCTL__enGetBOREvent_VDDA(void);
void SYSCTL__vGetBOREvent(SYSCTL_nBOR_EVENT* penBOREvent_VDD,
                          SYSCTL_nBOR_EVENT* penBOREvent_VDDA);

SYSCTL_nBOR_STATUS SYSCTL__enGetBORStatus_VDD(void);
SYSCTL_nBOR_STATUS SYSCTL__enGetBORStatus_VDDA(void);
SYSCTL_nBOR_STATUS SYSCTL__enGetBORStatus(void);

void SYSCTL__vClearBORStatus_VDD(void);
void SYSCTL__vClearBORStatus_VDDA(void);
void SYSCTL__vClearBORStatus(SYSCTL_nBOR_STATUS enBOREvent);

#endif /* XDRIVER_MCU_SYSCTL_DRIVER_XHEADER_SYSCTL_VOLTAGE_H_ */
