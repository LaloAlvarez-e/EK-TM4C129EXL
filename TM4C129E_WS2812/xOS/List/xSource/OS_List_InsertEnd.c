/**
 *
 * @file OS_List_InsertEnd.c
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
 * @verbatim 8 sep. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 8 sep. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xOS/List/xHeader/OS_List_InsertEnd.h>

void OS_List__vInsertEnd(OS_List_t* const pstListArg ,
                         OS_ListItem_t* const pstNewListItemArg)
{
    CDLinkedList__enInsertPreviousOnLastItemRead(pstListArg, pstNewListItemArg);
}