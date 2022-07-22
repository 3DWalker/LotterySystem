#include "user.h"


UN_t *find_user_by_name( UN_t *first, const char *name )
{
    UN_t *node = first;
    while ( NULL != node )
    {
        if ( 0 == strcmp( node->data.name, name ) )
        {
            break;
        }
        node = node->next;
    }

    return node;
}


//按用户ID查找用户
UN_t *find_user_by_user_id( UN_t *first, const char *id )
{
    UN_t *node = first;
    while ( NULL != node )
    {
        if ( 0 == strcmp( node->data.id, id ) )
        {
            break;
        }
        node = node->next;
    }

    return node;
}


//按最大用户ID查找用户
UN_t *find_user_by_id_max( UN_t *first )
{
    UN_t *node = first, *pre = NULL;
    while ( NULL != node->next )
    {
        pre = node;
        node = node->next;
        if ( 0 > strcmp( node->data.id, pre->data.id ) )
        {
            UD_t temp = node->data;
            node->data = pre->data;
            pre->data = temp;
        }
    }

    return node;
}