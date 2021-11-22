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

CDLinkedList_t* CDLinkedList__pstInit(void (*pfvDestroyItemDataArg) (void *DataContainer), void (*pfvDestroyItemArg) (void *Item))
{
    CDLinkedList_t *pstList = 0;
#if defined (__TI_ARM__ )
    pstList = (CDLinkedList_t*) memalign((size_t) 4, (size_t) sizeof(CDLinkedList_t));
#elif defined (__GNUC__ )
    pstList = (CDLinkedList_t*) malloc(sizeof(CDLinkedList_t));
#endif
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstList->u32Size = 0UL;
        pstList->pfvDestroy = &free;
        pstList->pfvDestroyItemData = pfvDestroyItemDataArg;
        pstList->pfvDestroyItem = pfvDestroyItemArg;
        pstList->pstHead = (CDLinkedListItem_t*)  0UL;
        pstList->pstTail = (CDLinkedListItem_t*)  0UL;
        pstList->pstLastItemRead = (CDLinkedListItem_t*)  0UL;
    }
    return (pstList);
}


CDLinkedList_nSTATUS CDLinkedList__enInit(CDLinkedList_t* pstList,
                                          void (*pfvDestroyItemDataArg) (void *DataContainer),
                                          void (*pfvDestroyItemArg) (void *Item))
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        enStatus = CDLinkedList_enSTATUS_OK;
        pstList->u32Size = 0UL;
        pstList->pfvDestroy = (void (*) (void* List))0UL;
        pstList->pfvDestroyItemData = pfvDestroyItemDataArg;
        pstList->pfvDestroyItem = pfvDestroyItemArg;
        pstList->pstHead = (CDLinkedListItem_t*)  0UL;
        pstList->pstTail = (CDLinkedListItem_t*)  0UL;
        pstList->pstLastItemRead = (CDLinkedListItem_t*)  0UL;
    }
    return (enStatus);
}


