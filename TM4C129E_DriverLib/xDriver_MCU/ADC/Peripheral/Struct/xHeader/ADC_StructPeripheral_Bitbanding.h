/**
 *
 * @file ADC_StructPeripheral_Bitbanding.h
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

#ifndef XDRIVER_MCU_ADC_PERIPHERAL_STRUCT_XHEADER_ADC_STRUCTPERIPHERAL_BITBANDING_H_
#define XDRIVER_MCU_ADC_PERIPHERAL_STRUCT_XHEADER_ADC_STRUCTPERIPHERAL_BITBANDING_H_

#include <xDriver_MCU/ADC/Peripheral/Struct/xHeader/ADC_StructRegister_Bitbanding.h>

typedef volatile struct
{
    union
      {
          volatile UBase_t MUX [32UL];
          ADC_BITBANDING_SS8_MUX_t MUX_Bit;
      };
      union
      {
          volatile UBase_t CTL [32UL];
          ADC_BITBANDING_SS8_CTL_t CTL_Bit;
      };
      union
      {
          volatile const UBase_t FIFO [32UL];
          ADC_BITBANDING_SS_FIFO_t FIFO_Bit;
      };
      union
      {
          volatile const UBase_t FSTAT [32UL];
          ADC_BITBANDING_SS_FSTAT_t FSTAT_Bit;
      };
      union
      {
          volatile UBase_t OP [32UL];
          ADC_BITBANDING_SS8_OP_t OP_Bit;
      };
      union
      {
          volatile UBase_t DC [32UL];
          ADC_BITBANDING_SS8_DC_t DC_Bit;
      };
      union
      {
          volatile UBase_t EMUX [32UL];
          ADC_BITBANDING_SS8_EMUX_t EMUX_Bit;
      };
      union
      {
          volatile UBase_t TSH [32UL];
          ADC_BITBANDING_SS8_TSH_t TSH_Bit;
      };
}ADC_BITBANDING_SEQUENCER_t;

typedef volatile struct
{
    union
    {
        volatile UBase_t ACTSS [32UL];
        ADC_BITBANDING_ACTSS_t ACTSS_Bit;
    };
    union
    {
        volatile const UBase_t RIS [32UL];
        ADC_BITBANDING_RIS_t RIS_Bit;
    };
    union
    {
        volatile UBase_t IM [32UL];
        ADC_BITBANDING_IM_t IM_Bit;
    };
    union
    {
        volatile UBase_t ISC [32UL];
        ADC_BITBANDING_ISC_t ISC_Bit;
    };
    union
    {
        volatile UBase_t OSTAT [32UL];
        ADC_BITBANDING_OSTAT_t OSTAT_Bit;
    };
    union
    {
        volatile UBase_t EMUX [32UL];
        ADC_BITBANDING_EMUX_t EMUX_Bit;
    };
    union
    {
        volatile UBase_t USTAT [32UL];
        ADC_BITBANDING_USTAT_t USTAT_Bit;
    };
    union
    {
        volatile UBase_t TSSEL [32UL];
        ADC_BITBANDING_TSSEL_t TSSEL_Bit;
    };
    union
    {
        volatile UBase_t SSPRI [32UL];
        ADC_BITBANDING_SSPRI_t SSPRI_Bit;
    };
    union
    {
        volatile UBase_t SPC [32UL];
        ADC_BITBANDING_SPC_t SPC_Bit;
    };
    union
    {
        volatile UBase_t PSSI [32UL];
        ADC_BITBANDING_PSSI_t PSSI_Bit;
    };

    const UBase_t reserved [32UL];
    union
    {
        volatile UBase_t SAC [32UL];
        ADC_BITBANDING_SAC_t SAC_Bit;
    };
    union
    {
        volatile UBase_t DCISC [32UL];
        ADC_BITBANDING_DCISC_t DCISC_Bit;
    };
    union
    {
        volatile UBase_t CTL [32UL];
        ADC_BITBANDING_CTL_t CTL_Bit;
    };

    const UBase_t reserved1 [32UL];

    ADC_BITBANDING_SEQUENCER_t SEQUENCER [4UL];

    const UBase_t reserved5 [32UL * 784UL];
    union
    {
        volatile UBase_t DC_RIC [32UL];
        ADC_BITBANDING_DC_RIC_t DC_RIC_Bit;
    };

    const UBase_t reserved6 [63UL * 32UL];
    union
    {
        volatile UBase_t DC_CTL [8UL][32UL];
        ADC_BITBANDING_DC_CTL_t DC_CTL_Bit [8UL];
    };
    const UBase_t reserved7 [8UL * 32UL];
    union
    {
        volatile UBase_t DC_CMP [8UL][32UL];
        ADC_BITBANDING_DC_CMP_t DC_CMP_Bit;
    };

    const UBase_t reserved8 [88UL * 32UL];
    union
    {
        volatile const UBase_t PP [32UL];
        ADC_BITBANDING_PP_t PP_Bit;
    };
    union
    {
        volatile UBase_t PC [32UL];
        ADC_BITBANDING_PC_t PC_Bit;
    };
    union
    {
        volatile UBase_t CC [32UL];
        ADC_BITBANDING_CC_t CC_Bit;
    };

    const UBase_t reserved9 [13UL * 32UL];
}ADC_BITBANDING_t;

typedef volatile struct
{
    ADC_BITBANDING_t MODULE [(UBase_t) ADC_enMODULE_MAX];
}ADCS_BITBANDING_t;

#endif /* XDRIVER_MCU_ADC_PERIPHERAL_STRUCT_XHEADER_ADC_STRUCTPERIPHERAL_BITBANDING_H_ */
