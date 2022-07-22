#include "user.h"

//释放用户数据
void free_user( UN_t *first )
{
    UN_t *node = first, *pre = NULL;
    while ( NULL != node )
    {
        pre = node;
        node = node->next;
        free( pre );
        pre = NULL;
    }
}