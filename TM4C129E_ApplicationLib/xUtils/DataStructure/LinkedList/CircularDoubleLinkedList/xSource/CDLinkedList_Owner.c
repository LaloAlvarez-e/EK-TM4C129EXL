/**
 *
 * @file CDLinkedList_Owner.c
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
 * @verbatim 14 jul. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 14 jul. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xUtils/DataStructure/LinkedList/CircularDoubleLinkedList/xHeader/CDLinkedList_Owner.h>

#include <xUtils/DataStructure/LinkedList/CircularDoubleLinkedList/Intrinsics/CDLinkedList_Intrinsics.h>

CDLinkedList_nERROR CDLinkedList__enIsItemOwnerList(const CDLinkedList_t* pstList, const CDLinkedListItem_t* const pstItem)
{
    CDLinkedList_nERROR enStatus = CDLinkedList_enERROR_POINTER;
    CDLinkedList_t* pstOwnerListItem = (CDLinkedList_t*) 0UL;
    pstOwnerListItem = (CDLinkedList_t*) CDLinkedList_Item__pvGetOwnerList(pstItem);
    if((UBase_t) pstOwnerListItem == (UBase_t) pstList )
    {
        enStatus = CDLinkedList_enERROR_OK;
    }
    return (enStatus);
}




