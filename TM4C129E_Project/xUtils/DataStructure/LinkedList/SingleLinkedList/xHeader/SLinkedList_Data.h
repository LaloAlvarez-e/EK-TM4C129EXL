/**
 *
 * @file SLinkedList_Data.h
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
#ifndef XUTILS_DATASTRUCTURE_SINGLELINKEDLIST_XHEADER_SLINKEDLIST_DATA_H_
#define XUTILS_DATASTRUCTURE_SINGLELINKEDLIST_XHEADER_SLINKEDLIST_DATA_H_

#include <xUtils/DataStructure/LinkedList/SingleLinkedList/Intrinsics/xHeader/SLinkedList_Struct.h>

void*  SLinkedList__pvGetItemDataPos(const SLinkedList_TypeDef* pstList, uint32_t u32Position);
void*  SLinkedList__pvGetItemDataEnd(const SLinkedList_TypeDef* pstList);
void*  SLinkedList__pvGetItemDataBegin(const SLinkedList_TypeDef* pstList);

uint32_t  SLinkedList__u32GetItemValuePos(const SLinkedList_TypeDef* pstList, uint32_t u32Position);
uint32_t  SLinkedList__u32GetItemValueEnd(const SLinkedList_TypeDef* pstList);
uint32_t  SLinkedList__u32GetItemValueBegin(const SLinkedList_TypeDef* pstList);

#endif /* XUTILS_DATASTRUCTURE_SINGLELINKEDLIST_XHEADER_SLINKEDLIST_DATA_H_ */
