#include "create_node.h"

void *create_node( void *data, size_t size_node, size_t size_data )
{
    void *new = calloc( 1, size_node );
    if ( NULL != new && 0 != size_data )
    {
        memcpy( new, data, size_data );
    }

    return new;
}