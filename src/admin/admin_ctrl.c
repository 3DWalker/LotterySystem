#include "admin_ctrl.h"

//通过账号查询用户信息
void query_by_user_id( UN_t *user_first )
{
	char id[20] = "";
	printf( "请输入彩民账号:" );
	scanf( "%s", id );
	while ( '\n' != getchar( ) );

	UN_t *node = find_user_by_user_id( user_first, id );
	if ( NULL != node )
	{
		show_user_info( &node->data );
	}
	else
	{
		printf( "没有该用户!\n" );
	}
	printf( "请输入任意字符继续:" );
	getchar( );
	while ( '\n' != getchar( ) );
}

//通过用户账号充值
void recharge_by_user_id( UN_t *user_first )
{
	char id[20] = "";
	printf( "请输入彩民账号:" );
	scanf( "%s", id );
	while ( '\n' != getchar( ) );

	UN_t *node = find_user_by_user_id( user_first, id );
	if ( NULL != node )
	{
		recharge( &node->data );
	}
	else
	{
		printf( "没有该账户,充值失败!\n" );
		printf( "请输入任意字符继续:" );
		getchar( );
		while ( '\n' != getchar( ) );
	}
}

//管理员控制面板
void admin_ctrl( UN_t *user_first, PN_t *pub_first )
{
	while ( 1 )
	{
		system("clear");
		printf("=======================\n");
		printf("   管 理 员 菜 单 栏   \n");
		printf("-----------------------\n");
		printf("     1.发行彩票        \n");
		printf("     2.查询彩民信息    \n");
		printf("     3.彩民排序    	\n");
		printf("     4.充  值			\n");
		printf("     0.退  出          \n");
		printf("=======================\n");
		printf("请选择:");

		int ch = -1;
		scanf( "%d", &ch );
		while ( '\n' != getchar( ) );

		switch ( ch )
		{
		case 1:
			pub_ctrl( pub_first );
			break;
		case 2:
			query_by_user_id( user_first );
			break;
		case 3:
			sort_user_ctrl( user_first );
			break;
		case 4:
			recharge_by_user_id( user_first );
			break;
		case 0:
			return;
		default:
			break;
		}
	}
}
