#include "pub.h"
#include "create_node.h"

#define PUB_PATH "./bin/pub_data.bin"

//存储发行数据
void save_pub( PN_t *first )
{
	FILE *fp = fopen( PUB_PATH, "wb" );
	PN_t *p = first;
	while ( NULL != p )
	{
		fwrite( &p->data, sizeof( PD_t ), 1, fp );
		p = p->next;
	}

	fclose( fp );
}


//加载发行数据
void load_pub( PN_t *first )
{
	FILE *fp = fopen( PUB_PATH, "rb" );
	if ( NULL == fp )
	{
		return;
	}

	PD_t data = { };
	PN_t *p = NULL;
	while ( fread( &data, sizeof( PD_t ), 1, fp ) > 0 )
	{
		p = create_node( &data, sizeof( PN_t ), sizeof( PD_t ) );
		insert_pub( first, p );
		p = NULL;
	}

	fclose( fp );
}
