/**
 *
 * @file CDLinkedList_Init.c
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
#include <xUtils/DataStructure/LinkedList/CircularDoubleLinkedList/xHeader/CDLinkedList_Init.h>
#include <stdlib.h>

CDLinkedList_t* CDLinkedList__pstInit(void (*pvfDestroyItemDataArg) (void *DataContainer), void (*pvfDestroyItemArg) (void *Item))
{
    CDLinkedList_t *pstList = 0;
#if defined (__TI_ARM__ ) || defined (__MSP430__ )
    pstList = (CDLinkedList_t*) memalign((size_t) 4, (size_t) sizeof(CDLinkedList_t));
#elif defined (__GNUC__ )
    pstList = (CDLinkedList_t*) malloc(sizeof(CDLinkedList_t));
#endif
    if((UBase_t) 0UL != (UBase_t) pstList)
    {
        pstList->uxSize = 0UL;
        pstList->pvfDestroy = &free;
        pstList->pvfDestroyItemData = pvfDestroyItemDataArg;
        pstList->pvfDestroyItem = pvfDestroyItemArg;
        pstList->pstHead = (CDLinkedListItem_t*)  0UL;
        pstList->pstTail = (CDLinkedListItem_t*)  0UL;
        pstList->pstLastItemRead = (CDLinkedListItem_t*)  0UL;
    }
    return (pstList);
}


CDLinkedList_nERROR CDLinkedList__enInit(CDLinkedList_t* pstList,
                                          void (*pvfDestroyItemDataArg) (void *DataContainer),
                                          void (*pvfDestroyItemArg) (void *Item))
{
    CDLinkedList_nERROR enStatus = CDLinkedList_enERROR_POINTER;
    if((UBase_t) 0UL != (UBase_t) pstList)
    {
        enStatus = CDLinkedList_enERROR_OK;
        pstList->uxSize = 0UL;
        pstList->pvfDestroy = (void (*) (void* List))0UL;
        pstList->pvfDestroyItemData = pvfDestroyItemDataArg;
        pstList->pvfDestroyItem = pvfDestroyItemArg;
        pstList->pstHead = (CDLinkedListItem_t*)  0UL;
        pstList->pstTail = (CDLinkedListItem_t*)  0UL;
        pstList->pstLastItemRead = (CDLinkedListItem_t*)  0UL;
    }
    return (enStatus);
}



