#include "lot.h"
#include "create_node.h"

#define LOT_PATH "./bin/lot_data.bin"

//存储彩票信息
void save_lot( LN_t *first )
{
	FILE *fp = fopen( LOT_PATH, "wb" );
	LN_t *p = first;
	while ( NULL != p )
	{
		fwrite( &p->data, sizeof( LD_t ), 1, fp );
		p = p->next;
	}

	fclose( fp );
}


//加载彩票信息
void load_lot( LN_t *first )
{
	FILE *fp = fopen( LOT_PATH, "rb" );
	if ( NULL == fp )
	{
		return;
	}

	LD_t data = { };
	LN_t *p = NULL;
	while ( fread( &data, sizeof( LD_t ), 1, fp ) > 0 )
	{
		p = create_node( &data, sizeof( LN_t ), sizeof( LD_t ) );
		insert_lot( first, p );
		p = NULL;
	}

	fclose( fp );
}
