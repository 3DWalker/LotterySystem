#include "pub.h"

//显示所有发行信息
void show_all_pub_info( PN_t *first )
{
	PN_t *p = first;
	while ( NULL != p )
	{
		printf( "期 号: %04d   奖池金额: %06d   销售量: %03d"
			, p->data.issue, p->data.pool, p->data.sum_bet );
		show_draw_num( &p->data );
		p = p->next;
	}
}


//显示中奖号码
void show_draw_num( PD_t *data )
{
	printf( "  开奖号码: " );
	if ( 0 != data->draw_num[1] )
		for ( int i = 0; i < 3; i++ )
			printf( "%02d ", data->draw_num[i] );
	else
		printf( "%s", "" );
	printf( "\n" );
}
