/**
 *
 * @file SLinkedList_Reverse.c
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
 * @verbatim 7 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 7 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */
#include <xUtils/DataStructure/LinkedList/SingleLinkedList/xHeader/SLinkedList_Reverse.h>

#include <xUtils/DataStructure/LinkedList/SingleLinkedList/Intrinsics/SLinkedList_Intrinsics.h>

SLinkedList_nERROR SLinkedList__enReverse(SLinkedList_t* pstList)
{
    SLinkedList_nERROR enStatus = SLinkedList_enSTATUS_UNDEF;
    SLinkedListItem_t* pstPreviousItem = (SLinkedListItem_t*) 0UL ;
    SLinkedListItem_t* pstNextItemReg = (SLinkedListItem_t*) 0UL ;
    SLinkedListItem_t* pstHeadItem = (SLinkedListItem_t*) 0UL ;
    if(((UBase_t) 0UL != (UBase_t) pstList))
    {
        pstHeadItem = SLinkedList__pstGetHead(pstList);
        SLinkedList__vSetTail(pstList, pstHeadItem);
        while((UBase_t) 0UL != (UBase_t) pstHeadItem)
        {
            pstNextItemReg = SLinkedList_Item__pstGetNextItem(pstHeadItem);
            SLinkedList_Item__vSetNextItem(pstHeadItem, pstPreviousItem);
            pstPreviousItem = pstHeadItem;
            pstHeadItem = pstNextItemReg;
        }
        pstHeadItem = pstPreviousItem;
        SLinkedList__vSetHead(pstList, pstHeadItem);
    }
    return (enStatus);
}
