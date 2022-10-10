/**
 *
 * @file CDLinkedList_Tail.c
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
 * @verbatim 11 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 11 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */
#include <xUtils/DataStructure/LinkedList/CircularDoubleLinkedList/Intrinsics/List/xHeader/CDLinkedList_Tail.h>

CDLinkedListItem_t* CDLinkedList__pstGetTail(const CDLinkedList_t*  const pstList)
{
    CDLinkedListItem_t* pstTailReg = (CDLinkedListItem_t*)0U;
    if(0UL != (UBase_t) pstList)
    {
        pstTailReg = pstList->pstTail;
    }
    return (pstTailReg);
}

void CDLinkedList__vSetTail(CDLinkedList_t* pstList, CDLinkedListItem_t* pstTailArg)
{
    if(0UL != (UBase_t) pstList)
    {
        pstList->pstTail = pstTailArg;
    }
}

CDLinkedList_nERROR CDLinkedList__enIsTail(const CDLinkedListItem_t* const pstItem)
{
    CDLinkedList_nERROR enStatus = CDLinkedList_enERROR_POINTER;
    if (0UL == (UBase_t) (pstItem->pstNextItem))
    {
        enStatus = CDLinkedList_enERROR_OK;
    }
    return (enStatus);
}



