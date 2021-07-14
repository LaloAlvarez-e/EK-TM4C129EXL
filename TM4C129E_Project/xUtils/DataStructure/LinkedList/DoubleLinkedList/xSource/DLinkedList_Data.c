/**
 *
 * @file DLinkedList_Data.c
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
 * @verbatim 8 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 8 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */
#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/xHeader/DLinkedList_Data.h>

#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/Intrinsics/DLinkedList_Intrinsics.h>
#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/xHeader/DLinkedList_Item.h>

void* DLinkedList__pvGetItemDataPos(const DLinkedList_TypeDef* pstList, uint32_t u32Position)
{
    DLinkedListItem_TypeDef* pstItem = (DLinkedListItem_TypeDef*) 0UL;
    void* pvItemData = (void*) 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstItem = DLinkedList__pstGetItemPos(pstList, u32Position);
        if((uint32_t) 0UL != (uint32_t) pstItem)
        {
            pvItemData = DLinkedList__pvGetItemData(pstItem);
        }
    }
    return (pvItemData);
}

void* DLinkedList__pvGetItemDataEnd(const DLinkedList_TypeDef* pstList)
{
    DLinkedListItem_TypeDef* pstItem = (DLinkedListItem_TypeDef*) 0UL;
    void* pvItemData = (void*) 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstItem = DLinkedList__pstGetItemEnd(pstList);
        if((uint32_t) 0UL != (uint32_t) pstItem)
        {
            pvItemData = DLinkedList__pvGetItemData(pstItem);
        }
    }
    return (pvItemData);
}

void* DLinkedList__pvGetItemDataBegin(const DLinkedList_TypeDef* pstList)
{
    DLinkedListItem_TypeDef* pstItem = (DLinkedListItem_TypeDef*) 0UL;
    void* pvItemData = (void*) 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstItem = DLinkedList__pstGetItemBegin(pstList);
        if((uint32_t) 0UL != (uint32_t) pstItem)
        {
            pvItemData = DLinkedList__pvGetItemData(pstItem);
        }
    }
    return (pvItemData);
}


uint32_t DLinkedList__u32GetItemValuePos(const DLinkedList_TypeDef* pstList, uint32_t u32Position)
{
    DLinkedListItem_TypeDef* pstItem = (DLinkedListItem_TypeDef*) 0UL;
    uint32_t u32ItemValue = (uint32_t) 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstItem = DLinkedList__pstGetItemPos(pstList, u32Position);
        if((uint32_t) 0UL != (uint32_t) pstItem)
        {
            u32ItemValue = DLinkedList__u32GetItemValue(pstItem);
        }
    }
    return (u32ItemValue);
}

uint32_t DLinkedList__u32GetItemValueEnd(const DLinkedList_TypeDef* pstList)
{
    DLinkedListItem_TypeDef* pstItem = (DLinkedListItem_TypeDef*) 0UL;
    uint32_t u32ItemValue = (uint32_t) 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstItem = DLinkedList__pstGetItemEnd(pstList);
        if((uint32_t) 0UL != (uint32_t) pstItem)
        {
            u32ItemValue = DLinkedList__u32GetItemValue(pstItem);
        }
    }
    return (u32ItemValue);
}

uint32_t DLinkedList__u32GetItemValueBegin(const DLinkedList_TypeDef* pstList)
{
    DLinkedListItem_TypeDef* pstItem = (DLinkedListItem_TypeDef*) 0UL;
    uint32_t u32ItemValue = (uint32_t) 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstItem = DLinkedList__pstGetItemBegin(pstList);
        if((uint32_t) 0UL != (uint32_t) pstItem)
        {
            u32ItemValue = DLinkedList__u32GetItemValue(pstItem);
        }
    }
    return (u32ItemValue);
}
