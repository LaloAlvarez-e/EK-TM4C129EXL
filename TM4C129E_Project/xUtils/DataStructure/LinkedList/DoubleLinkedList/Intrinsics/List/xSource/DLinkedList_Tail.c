/**
 *
 * @file DLinkedList_Tail.c
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
#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/Intrinsics/List/xHeader/DLinkedList_Tail.h>

DLinkedListItem_TypeDef* DLinkedList__pstGetTail(const DLinkedList_TypeDef*  const pstList)
{
    DLinkedListItem_TypeDef* pstTailReg = (DLinkedListItem_TypeDef*)0U;
    if(0UL != (uint32_t) pstList)
    {
        pstTailReg = pstList->pstTail;
    }
    return (pstTailReg);
}

void DLinkedList__vSetTail(DLinkedList_TypeDef* pstList, DLinkedListItem_TypeDef* pstTailArg)
{
    if(0UL != (uint32_t) pstList)
    {
        pstList->pstTail = pstTailArg;
    }
}

DLinkedList_nSTATUS DLinkedList__enIsTail(const DLinkedListItem_TypeDef* const pstItem)
{
    DLinkedList_nSTATUS enStatus = DLinkedList_enSTATUS_ERROR;
    if (0UL == (uint32_t) (pstItem->pstNextItem))
    {
        enStatus = DLinkedList_enSTATUS_OK;
    }
    return (enStatus);
}
