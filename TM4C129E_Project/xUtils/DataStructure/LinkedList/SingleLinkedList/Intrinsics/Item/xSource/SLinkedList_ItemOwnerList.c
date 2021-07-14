/**
 *
 * @file SLinkedList_ItemOwnerList.c
 * @copyright
 * @verbatim InDeviceMex 2021 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 13 jul. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 13 jul. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xUtils/DataStructure/LinkedList/SingleLinkedList/Intrinsics/Item/xHeader/SLinkedList_ItemOwnerList.h>

void* SLinkedList__pvGetItemOwnerList(const SLinkedListItem_TypeDef* const pstItem)
{
    void* pvOwnerListReg = (void*)0UL;
    pvOwnerListReg = pstItem->pvOwnerList;
    return (pvOwnerListReg);
}

void SLinkedList__vSetItemOwnerList(SLinkedListItem_TypeDef* pstItem, void* pvOwnerListArg)
{
    pstItem->pvOwnerList = pvOwnerListArg;
}