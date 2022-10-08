/**
 *
 * @file CDLinkedList_ItemValue.c
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
#include <xUtils/DataStructure/LinkedList/CircularDoubleLinkedList/Intrinsics/Item/xHeader/CDLinkedList_ItemValue.h>

UBase_t CDLinkedList_Item__uxGetValue(const CDLinkedListItem_t* const pstItem)
{
    UBase_t uxValueItemReg = 0UL;
    if(0UL != (UBase_t) pstItem)
    {
        uxValueItemReg = pstItem->uxValueItem;
    }
    return (uxValueItemReg);
}

void CDLinkedList_Item__vSetValue(CDLinkedListItem_t* const pstItem, UBase_t uxValueItemArg)
{
    if(0UL != (UBase_t) pstItem)
    {
        pstItem->uxValueItem = uxValueItemArg;
    }
}

