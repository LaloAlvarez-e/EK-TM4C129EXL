/**
 *
 * @file CSLinkedList_Struct.h
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
 * @verbatim 9 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 9 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */
#ifndef XUTILS_DATASTRUCTURE_CIRCULARSINGLELINKEDLIST_INTRINSICS_XHEADER_CIRCULARSLINKEDLIST_STRUCT_H_
#define XUTILS_DATASTRUCTURE_CIRCULARSINGLELINKEDLIST_INTRINSICS_XHEADER_CIRCULARSLINKEDLIST_STRUCT_H_

#include <xUtils/Standard/Standard.h>

typedef enum
{
    CSLinkedList_enERROR_OK,
    CSLinkedList_enERROR_UNDEF
}CSLinkedList_nERROR;


typedef struct CSLinkedListItem
{
        void* pvDataContainer;
        void* pvOwnerList;
        UBase_t uxValueItem;
        struct CSLinkedListItem *pstNextItem;
}CSLinkedListItem_t;

typedef struct CSLinkedList
{
        UBase_t uxSize;
        UBase_t (*pfuxMatch) (const void *pcvKey1, const void *pcvKey2);
        void (*pvfDestroyItemData) (void *DataContainer);
        void (*pvfDestroyItem) (void *Item);
        void (*pvfDestroy) (void* List);
        CSLinkedListItem_t *pstLastItemRead;
        CSLinkedListItem_t *pstHead;
        CSLinkedListItem_t *pstTail;
}CSLinkedList_t;




#endif /* XUTILS_DATASTRUCTURE_CIRCULARSINGLELINKEDLIST_INTRINSICS_XHEADER_CIRCULARSLINKEDLIST_STRUCT_H_ */
