/**
 *
 * @file DLinkedList_Head.c
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
#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/Intrinsics/List/xHeader/DLinkedList_Head.h>

DLinkedListItem_TypeDef* DLinkedList__pstGetHead(const DLinkedList_TypeDef*  const pstList)
{
    DLinkedListItem_TypeDef* pstHeadReg = (DLinkedListItem_TypeDef*) 0U;
    if(0UL != (uint32_t) pstList)
    {
        pstHeadReg = pstList->pstHead;
    }
    return (pstHeadReg);
}

void DLinkedList__vSetHead(DLinkedList_TypeDef* pstList, DLinkedListItem_TypeDef* pstHeadArg)
{
    if(0UL != (uint32_t) pstList)
    {
        pstList->pstHead = pstHeadArg;
    }
}

DLinkedList_nSTATUS DLinkedList__enIsHead(const DLinkedList_TypeDef* const pstList, const DLinkedListItem_TypeDef* const pstItem)
{
    DLinkedList_nSTATUS enStatus = DLinkedList_enSTATUS_ERROR;
    DLinkedListItem_TypeDef* pstListHead = (DLinkedListItem_TypeDef*)0UL;
    pstListHead = DLinkedList__pstGetHead(pstList);
    if ((uint32_t) pstItem == (uint32_t) (pstListHead))
    {
        enStatus = DLinkedList_enSTATUS_OK;
    }
    return (enStatus);
}
