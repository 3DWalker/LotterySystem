#include "gref_ctrl.h"

//获取开奖号码
void get_draw_num( UN_t *user_first, LN_t *lot_first, PN_t *pub_first )
{
	int empty[3] = { };
	PN_t * pub_n = find_pub_by_issue_max( pub_first );
	if( 0 != memcmp( pub_n->data.draw_num, empty, sizeof( int ) *3 )
		|| 0 == pub_n->data.issue )
	{
		printf( "新一期彩票暂未发行，无法开奖!\n" );
		printf( "请输入任意字符继续:" );
		return;
	}

#if 1
	int draw_num[3] = { 2, 3, 4 };		//测试
#endif

#if 1
	//判断是否确认开奖
	char ch = 0;
	printf( "确认开奖[y/n]:" );
	scanf( "%c", &ch );
	while ( '\n' != getchar( ) );
	if ( 'Y' != ch && 'y' != ch )
	{
		printf( "已取消开奖，输入任意字符继续:" );
		return;
	}
#endif
#if 0
	//生成开奖号码,并使三组数字不相同
	int draw_num[3] = { };
	srand( time( NULL ) );
	for ( int i = 0; i < 3; i++ )
    {   
		draw_num[i] = rand( ) % 15 + 1;
        for( int j = 0; j < 3; j++ )
        {
			while ( j != i && draw_num[i] == draw_num[j] ) 
			{
				draw_num[i] = rand( ) % 15 + 1;
			}
        }
    }   
#endif

	//存储发行数据
	char state[20] = "已开奖";
	memcpy( pub_n->data.draw_num, draw_num, sizeof( int ) *3 );
	strcpy( pub_n->data.state, state );
	prize( user_first, lot_first, pub_n );

	//显示开奖号码
	printf( "开奖成功!\n" );
	printf( "开奖号码为: " );
	for ( int i = 0; i < 3; i++ )
	{
		printf( "%02d ",draw_num[i] );
	}
	printf( "\n请输入任意字符继续:" );
}


//查询彩票信息
void find_lot_info( LN_t *lot_first, PN_t *pub_first )
{
	while ( 1 )
	{
		system( "clear" );
		printf( "=======================\n" );
		printf( "   彩 票 信 息 查 询   \n" );
		printf( "-----------------------\n" );
		printf( "    1.历史开奖查询     \n" );
		printf( "    2.显示所有彩票		\n" );
		printf( "    0.退 出			\n" );
		printf( "=======================\n" );
		printf( "请选择:" );

		int ch = -1;
		scanf( "%d", &ch );
		while ( '\n' != getchar( ) );

		switch ( ch )
		{
			case 1:
				show_all_pub_info( pub_first );
				printf( "请输入任意字符继续:" );
				getchar( );
				while ( '\n' != getchar( ) );
				break;
			case 2:
				show_all_lot_info( lot_first, pub_first );
				printf( "请输入任意字符继续:" );
				getchar( );
				while ( '\n' != getchar( ) );
				break;
			case 0:
				return;
			default :
				break;
		}
	}
}


//公证员控制面板
void gref_ctrl( UN_t *user_first, LN_t *lot_first, PN_t *pub_first )
{
	while ( 1 )
	{
		system( "clear" );
		printf( "=======================\n" );
		printf( "   公 证 员 菜 单 栏   \n" );
		printf( "-----------------------\n" );
		printf( "     1.开  奖          \n" );
		printf( "     2.查询彩票信息    \n" );
		printf( "     0.退  出          \n" );
		printf( "=======================\n" );
		printf( "请选择:" );

		int ch = -1;
		scanf( "%d", &ch );
		while ( '\n' != getchar( ) );

		switch ( ch )
		{
			case 1:
				get_draw_num( user_first, lot_first, pub_first );
				getchar( );
				while ( '\n' != getchar( ) );
				break;
			case 2:
				find_lot_info( lot_first, pub_first );
				break;
			case 0:
				return;
			default :
				break;
		}
	}
}
