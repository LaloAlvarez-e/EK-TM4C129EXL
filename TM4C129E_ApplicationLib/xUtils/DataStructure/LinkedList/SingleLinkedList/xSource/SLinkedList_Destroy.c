/**
 *
 * @file SLinkedList_Destroy.c
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

#include <xUtils/DataStructure/LinkedList/SingleLinkedList/xHeader/SLinkedList_Destroy.h>

#include <xUtils/DataStructure/LinkedList/SingleLinkedList/Intrinsics/List/xHeader/SLinkedList_Size.h>
#include <xUtils/DataStructure/LinkedList/SingleLinkedList/xHeader/SLinkedList_Init.h>
#include <xUtils/DataStructure/LinkedList/SingleLinkedList/xHeader/SLinkedList_Remove.h>

void SLinkedList__vDestroy(SLinkedList_t* pstList)
{
    SLinkedList_nERROR enStatus = SLinkedList_enSTATUS_UNDEF;
    void * pvDataItem = (void*)0UL;
    UBase_t uxSizeReg = 0UL;
    void (*pvfListDestroy) (void* List) = (void (*) (void* List) )0UL;

    if((SLinkedList_t*)0 != pstList)
    {
        enStatus = SLinkedList_enERROR_OK;
        uxSizeReg = SLinkedList__uxGetSize(pstList);
        pvfListDestroy = pstList->pvfDestroy;
        while (uxSizeReg > 0UL)
        {
            enStatus = SLinkedList__enRemoveNextInList_GetData(pstList, (SLinkedListItem_t*)0, (void **) & pvDataItem);
            if((SLinkedList_enERROR_OK == enStatus ) && ( (UBase_t) 0 != (UBase_t) pstList->pvfDestroyItemData))
            {
                pstList->pvfDestroyItemData(pvDataItem);
            }
            uxSizeReg = SLinkedList__uxGetSize(pstList);
        }

        pstList->pfuxMatch = (UBase_t (*) (const void *pcvKey1, const void *pcvKey2)) 0UL;
        pstList->pvfDestroy = (void (*) (void* List)) 0UL;
        pstList->pvfDestroyItemData = (void (*) (void* DataContainer)) 0UL;
        pstList->pvfDestroyItem = (void (*) (void* Item)) 0UL;
        pstList->pstHead = (SLinkedListItem_t *) 0UL;
        pstList->pstTail = (SLinkedListItem_t *) 0UL;
        pstList->pstLastItemRead = (SLinkedListItem_t*)  0UL;
        pstList->uxSize = 0UL;

        if((SLinkedList_enERROR_OK == enStatus ) && (0UL != (UBase_t) pvfListDestroy))
        {
            pvfListDestroy(pstList);
            pstList = (SLinkedList_t*) 0UL;
        }
    }
}
