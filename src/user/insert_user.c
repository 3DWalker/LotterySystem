#include "user.h"

void insert_user( UN_t *first, UN_t *node )
{
    //判断插入的节点是否为空
    if ( NULL == node )
    {
        printf( "信息插入有误!\n" );
        return;
    }

    //覆盖首节点
    if ( 0 == strlen( first->data.id ) )
    {
        first->data = node->data;
        return;
    }

    //插入非首节点--尾插法
    UN_t *temp = first;
    while ( NULL != temp->next )
    {
        temp = temp->next;
    }
    temp->next = node;
    node->next = NULL;
}