#include "user.h"

#define USER_DATA "./bin/user_data.bin"

//保存用户数据
void save_user( UN_t *first )
{
    FILE *fp = fopen( USER_DATA, "wb" );

    UN_t *node = first;
    while ( NULL != node )
    {
        fwrite( &node->data, sizeof(UD_t), 1, fp );
        node = node->next;
    }

    fclose( fp );
}


//加载用户数据
void load_user( UN_t *first )
{
    FILE *fp = fopen( USER_DATA, "rb" );
    if ( NULL == fp )
    {
        return;
    }

    UD_t data = { };
    UN_t *node = NULL;
    while ( fread( &data, sizeof(UD_t), 1, fp ) > 0 )
    {
        node = create_node( &data, sizeof(UN_t), sizeof(UD_t) );
        insert_user( first, node );
        node = NULL;
    }

    fclose( fp );
}