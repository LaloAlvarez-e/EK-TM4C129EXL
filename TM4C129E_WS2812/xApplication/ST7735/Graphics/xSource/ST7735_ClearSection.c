/**
 *
 * @file ST7735_ClearSection.c
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
 * @verbatim 19 feb. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 19 feb. 2021     vyldram    1.0         initial Version@endverbatim
 */
#include <xApplication/ST7735/Graphics/xHeader/ST7735_ClearSection.h>
#include <xApplication/ST7735/Graphics/xHeader/ST7735_WorkingArea.h>

#include <xUtils/Graphics/xHeader/Graphics_ClearSection.h>

#include <xApplication/ST7735/xHeader/ST7735_Write.h>
#include <xApplication/ST7735/xHeader/ST7735_Enum.h>
#include <xApplication/ST7735/xHeader/ST7735_Defines.h>

#include <xDriver_MCU/SSI/SSI.h>

void ST7735__vClearSectionWrapper(ST7735_Layer_t* restrict enLayerArg, ST7735_DIMENSIONS_t stDimesionsArg, UBase_t uxColor);

void ST7735__vClearSectionWrapper(ST7735_Layer_t* restrict enLayerArg, ST7735_DIMENSIONS_t stDimesionsArg, UBase_t uxColor)
{
    UBase_t uxTotalDim = 0UL;
    if(0UL != (UBase_t) enLayerArg)
    {
        uxTotalDim = stDimesionsArg.uxHeight;
        uxTotalDim *= stDimesionsArg.uxWidth;
        ST7735__vSetWorkingArea(enLayerArg, stDimesionsArg);
        ST7735__enWriteDMA(uxColor, uxTotalDim);
    }
}

void ST7735__vClearSection(ST7735_Layer_t* restrict enLayerArg, ST7735_DIMENSIONS_t stDimesionsArg, UBase_t uxColor)
{
    Graphics__vClearSection(&ST7735__vClearSectionWrapper ,enLayerArg, stDimesionsArg, uxColor);

}