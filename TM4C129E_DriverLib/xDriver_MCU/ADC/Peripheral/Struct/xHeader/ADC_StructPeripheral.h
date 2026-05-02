/**
 *
 * @file ADC_StructPeripheral.h
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
 * @verbatim 18 oct. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date Author Version Description
 * 18 oct. 2020 vyldram 1.0 initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_ADC_PERIPHERAL_STRUCT_XHEADER_ADC_STRUCTPERIPHERAL_H_
#define XDRIVER_MCU_ADC_PERIPHERAL_STRUCT_XHEADER_ADC_STRUCTPERIPHERAL_H_

#include <xDriver_MCU/ADC/Peripheral/Struct/xHeader/ADC_StructRegister.h>

typedef volatile struct
{
    union
      {
          volatile UBase_t MUX;
          ADC_SS8_MUX_t MUX_Bit;
      };
      union
      {
          volatile UBase_t CTL;
          ADC_SS8_CTL_t CTL_Bit;
      };
      union
      {
          volatile const UBase_t FIFO;
          ADC_SS_FIFO_t FIFO_Bit;
      };
      union
      {
          volatile const UBase_t FSTAT;
          ADC_SS_FSTAT_t FSTAT_Bit;
      };
      union
      {
          volatile UBase_t OP;
          ADC_SS8_OP_t OP_Bit;
      };
      union
      {
          volatile UBase_t DC;
          ADC_SS8_DC_t DC_Bit;
      };
      union
      {
          volatile UBase_t EMUX;
          ADC_SS8_EMUX_t EMUX_Bit;
      };
      union
      {
          volatile UBase_t TSH;
          ADC_SS8_TSH_t TSH_Bit;
      };
}ADC_SEQUENCER_t;

typedef volatile struct
{
    union
    {
        volatile UBase_t ACTSS;
        ADC_ACTSS_t ACTSS_Bit;
    };
    union
    {
        volatile const UBase_t RIS;
        ADC_RIS_t RIS_Bit;
    };
    union
    {
        volatile UBase_t IM;
        ADC_IM_t IM_Bit;
    };
    union
    {
        volatile UBase_t ISC;
        ADC_ISC_t ISC_Bit;
    };
    union
    {
        volatile UBase_t OSTAT;
        ADC_OSTAT_t OSTAT_Bit;
    };
    union
    {
        volatile UBase_t EMUX;
        ADC_EMUX_t EMUX_Bit;
    };
    union
    {
        volatile UBase_t USTAT;
        ADC_USTAT_t USTAT_Bit;
    };
    union
    {
        volatile UBase_t TSSEL;
        ADC_TSSEL_t TSSEL_Bit;
    };
    union
    {
        volatile UBase_t SSPRI;
        ADC_SSPRI_t SSPRI_Bit;
    };
    union
    {
        volatile UBase_t SPC;
        ADC_SPC_t SPC_Bit;
    };
    union
    {
        volatile UBase_t PSSI;
        ADC_PSSI_t PSSI_Bit;
    };

    const UBase_t reserved;
    union
    {
        volatile UBase_t SAC;
        ADC_SAC_t SAC_Bit;
    };
    union
    {
        volatile UBase_t DCISC;
        ADC_DCISC_t DCISC_Bit;
    };
    union
    {
        volatile UBase_t CTL;
        ADC_CTL_t CTL_Bit;
    };

    const UBase_t reserved1;

    ADC_SEQUENCER_t SEQUENCER [4UL];

    const UBase_t reserved5 [784UL];
    union
    {
        volatile UBase_t DC_RIC;
        ADC_DC_RIC_t DC_RIC_Bit;
    };

    const UBase_t reserved6 [63UL];
    union
    {
        volatile UBase_t DC_CTL [8UL];
        ADC_DC_CTL_t DC_CTL_Bit [8UL];
    };
    const UBase_t reserved7 [8UL];
    union
    {
        volatile UBase_t DC_CMP [8UL];
        ADC_DC_CMP_t DC_CMP_Bit [8UL];
    };

    const UBase_t reserved8 [88UL];
    union
    {
        volatile const UBase_t PP;
        ADC_PP_t PP_Bit;
    };
    union
    {
        volatile UBase_t PC;
        ADC_PC_t PC_Bit;
    };
    union
    {
        volatile UBase_t CC;
        ADC_CC_t CC_Bit;
    };

    const UBase_t reserved9 [13UL];
}ADC_t;

typedef volatile struct
{
    ADC_t MODULE [(UBase_t) ADC_enMODULE_MAX];
}ADCS_t;


#endif /* XDRIVER_MCU_ADC_PERIPHERAL_STRUCT_XHEADER_ADC_STRUCTPERIPHERAL_H_ */
