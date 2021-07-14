/**
 *
 * @file SLinkedList_ItemData.c
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
 * @verbatim 6 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 6 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */
#include <xUtils/DataStructure/LinkedList/SingleLinkedList/Intrinsics/Item/xHeader/SLinkedList_ItemData.h>

void* SLinkedList__pvGetItemData(const SLinkedListItem_TypeDef* const pstItem)
{
    void* pvDataReg = (void*)0UL;
    pvDataReg = pstItem->pvDataContainer;
    return pvDataReg;
}

void SLinkedList__vSetItemData(SLinkedListItem_TypeDef* pstItem, void* pvDataArg)
{
    pstItem->pvDataContainer = pvDataArg;
}