#include "show_lot.h"

//显示彩单张票信息
void show_lot_info( LD_t *data )
{
	//显示期号和彩票ID
	printf( "第%04d期   ID:L_%d   ", data->issue, data->lot_id );
	for ( int i = 0; i < 3; i++ )
	{
		printf( "%02d ", data->lot_num[i] );		//显示下注号码
	}
	printf( "(%d)", data->bet_num);		//显示注数
}


//显示与单张彩票相关联的信息
void show_lot_by_user( UN_t *user_n, LN_t *lot_first, PN_t *pub_first )
{
	LN_t *lot_n = lot_first;
	while ( NULL != lot_n )
	{
		if (  0 == strcmp( lot_n->data.user_id, user_n->data.id ) )
		{
			show_lot_info( &lot_n->data );		//显示基础信息
			PN_t *pub_n = find_pub_by_issue( pub_first, lot_n->data.issue );
			printf( "   %s", pub_n->data.state );	//显示开奖状态
			printf( "   %s", lot_n->data.prize );	//显示奖项

			int empty[3] = { };
			if ( 0 != memcmp( pub_n->data.draw_num, empty, sizeof( int ) *3 ) )
			{

				//显示中奖金额
				if ( 0 == strcmp ( lot_n->data.prize, "🥇" ) )
				{
					printf( "   💰 x 2500 x %d", lot_n->data.bet_num );
				}
				else if ( 0 == strcmp ( lot_n->data.prize, "🥈" ) )
				{
					printf( "   💰 x 1000 x %d", lot_n->data.bet_num );
				}
				else if ( 0 == strcmp ( lot_n->data.prize, "🥉" ) )
				{
					printf( "   💰 x 500 x %d", lot_n->data.bet_num );
				}
				else
					printf( "   💰 x 0" );
			}
			printf( "\n" );
		}
		lot_n = lot_n->next;
	}

	printf( "请输入任意字符继续:" );
	getchar( );
	while ( '\n' != getchar( ) );
}


//显示所有彩票信息
void show_all_lot_info( LN_t *lot_first, PN_t *pub_first )
{
	LN_t *lot_n = lot_first;
	while ( NULL != lot_n )
	{
		if ( 0 == lot_n->data.issue )
		{
			printf( "暂无彩票信息!\n" );
			return;
		}
		show_lot_info( &lot_n->data );
		printf( "   user_id: %s", lot_n->data.user_id );	 //显示用户ID
		PN_t *pub_n = find_pub_by_issue( pub_first, lot_n->data.issue );
		if ( NULL != pub_n )
			printf( "   %s", pub_n->data.state );	//显示开奖状态

		printf( "\n" );
		lot_n = lot_n->next;
	}
}
