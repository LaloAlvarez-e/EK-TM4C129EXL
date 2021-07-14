/**
 *
 * @file CSLinkedList_Data.c
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
 * @verbatim 10 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 10 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */
#include <xUtils/DataStructure/LinkedList/CircularSingleLinkedList/xHeader/CSLinkedList_Data.h>

#include <xUtils/DataStructure/LinkedList/CircularSingleLinkedList/Intrinsics/CSLinkedList_Intrinsics.h>
#include <xUtils/DataStructure/LinkedList/CircularSingleLinkedList/xHeader/CSLinkedList_Item.h>

void* CSLinkedList__pvGetItemDataPos(const CSLinkedList_TypeDef* pstList, uint32_t u32Position)
{
    CSLinkedListItem_TypeDef* pstItem = (CSLinkedListItem_TypeDef*) 0UL;
    void* pvItemData = (void*) 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstItem = CSLinkedList__pstGetItemPos(pstList, u32Position);
        if((uint32_t) 0UL != (uint32_t) pstItem)
        {
            pvItemData = CSLinkedList__pvGetItemData(pstItem);
        }
    }
    return (pvItemData);
}

uint32_t CSLinkedList__u32GetItemValuePos(const CSLinkedList_TypeDef* pstList, uint32_t u32Position)
{
    CSLinkedListItem_TypeDef* pstItem = (CSLinkedListItem_TypeDef*) 0UL;
    uint32_t u32ItemValue = (uint32_t) 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstItem = CSLinkedList__pstGetItemPos(pstList, u32Position);
        if((uint32_t) 0UL != (uint32_t) pstItem)
        {
            u32ItemValue = CSLinkedList__u32GetItemValue(pstItem);
        }
    }
    return (u32ItemValue);
}

void* CSLinkedList__pvGetItemDataEnd(const CSLinkedList_TypeDef* pstList)
{
    CSLinkedListItem_TypeDef* pstItem = (CSLinkedListItem_TypeDef*) 0UL;
    void* pvItemData = (void*) 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstItem = CSLinkedList__pstGetItemEnd(pstList);
        if((uint32_t) 0UL != (uint32_t) pstItem)
        {
            pvItemData = CSLinkedList__pvGetItemData(pstItem);
        }
    }
    return (pvItemData);
}

uint32_t CSLinkedList__u32GetItemValueEnd(const CSLinkedList_TypeDef* pstList)
{
    CSLinkedListItem_TypeDef* pstItem = (CSLinkedListItem_TypeDef*) 0UL;
    uint32_t u32ItemValue = (uint32_t) 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstItem = CSLinkedList__pstGetItemEnd(pstList);
        if((uint32_t) 0UL != (uint32_t) pstItem)
        {
            u32ItemValue = CSLinkedList__u32GetItemValue(pstItem);
        }
    }
    return (u32ItemValue);
}

void* CSLinkedList__pvGetItemDataBegin(const CSLinkedList_TypeDef* pstList)
{
    CSLinkedListItem_TypeDef* pstItem = (CSLinkedListItem_TypeDef*) 0UL;
    void* pvItemData = (void*) 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstItem = CSLinkedList__pstGetItemBegin(pstList);
        if((uint32_t) 0UL != (uint32_t) pstItem)
        {
            pvItemData = CSLinkedList__pvGetItemData(pstItem);
        }
    }
    return (pvItemData);
}

uint32_t CSLinkedList__u32GetItemValueBegin(const CSLinkedList_TypeDef* pstList)
{
    CSLinkedListItem_TypeDef* pstItem = (CSLinkedListItem_TypeDef*) 0UL;
    uint32_t u32ItemValue = (uint32_t) 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstItem = CSLinkedList__pstGetItemBegin(pstList);
        if((uint32_t) 0UL != (uint32_t) pstItem)
        {
            u32ItemValue = CSLinkedList__u32GetItemValue(pstItem);
        }
    }
    return (u32ItemValue);
}
