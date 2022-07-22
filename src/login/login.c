#include "login.h"

//管理员登录
void admin_login( UN_t *user_first, PN_t *pub_first )
{
	system( "clear" );
//	admin_ctrl( user_first, pub_first );
#if 1
	char name[20] = { }, pswd[20] = { };
	int count = 0;
	while ( 3 > count )
	{
		system( "clear" );
		printf( "========================\n" );
		printf( "     管 理 员 登 陆     \n" );
		printf( "------------------------\n" );
		printf( "请输入账户名称:" );
		scanf( "%s", name );
		while ( '\n' != getchar( ) );

		printf( "请输入账户密码:" );
		get_pswd( pswd );

		if ( 0 == strcmp( "admin", name )
		  && 0 == strcmp( "12345", pswd ))
		{
			break;
		}

		count++;
		if ( 3 > count )
		{
			printf( "用户名或密码错误(剩余次数%d), 请重新登录!\n"
				, 3 -count );
			printf( "请输入任意字符继续:" );
			getchar( );
			while ( '\n' != getchar( ) );
		}
	}
	if ( 3 > count )
	{
		if ( 0 != identify_code( ) )
		{
			printf( "验证成功，请输入任意字符完成登录:" );
			getchar( );
			admin_ctrl( user_first, pub_first );
		}
	}
	else
	{
		printf( "用户名或密码错误(剩余次数%d)\n", 3 -count );
		printf( "登录错误次数已用完,输入任意字符退出登录:" );
		getchar( );
		while ( '\n' != getchar( ) );
	}
#endif
}


//公证员登录
void gref_login( UN_t *user_first, LN_t *lot_first, PN_t *pub_first )
{
	system( "clear" );
//	gref_ctrl( user_first, lot_first, pub_first );
#if 1
	char name[20] = { }, pswd[20] = { };
	int count = 0;
	while ( 3 > count )
	{
		system( "clear" );
		printf( "========================\n" );
		printf( "     公 证 员 登 陆     \n" );
		printf( "------------------------\n" );
		printf( "请输入账户名称:" );
		scanf( "%s", name );
		while ( '\n' != getchar( ) );

		printf( "请输入账户密码:" );
		get_pswd( pswd );

		if ( 0 == strcmp( "gref", name )
		  && 0 == strcmp( "12345", pswd ))
		{
			break;
		}

		count++;
		if ( 3 > count )
		{
			printf( "用户名或密码错误(剩余次数%d), 请重新登录!\n"
				, 3 -count );
			printf( "请输入任意字符继续:" );
			getchar( );
			while ( '\n' != getchar( ) );
		}
	}
	if ( 3 > count )
	{
		if ( 0 != identify_code( ) )
		{
			printf( "验证成功，请输入任意字符完成登录:" );
			getchar( );
			gref_ctrl( user_first, lot_first, pub_first );
		}
	}
	else
	{
		printf( "用户名或密码错误(剩余次数%d)\n", 3 -count );
		printf( "登录错误次数已用完,输入任意字符退出登录:" );
		getchar( );
		while ( '\n' != getchar( ) );
	}
#endif
}


int login( UN_t *user_first, LN_t *lot_first, PN_t *pub_first )
{
	system( "clear" );
	printf( "=======================\n" );
	printf( "   彩 票 管 理 中 心   \n" );
	printf( " -^-----------------^- \n" );
	printf( "  |  1.用户登陆     |	\n" );
	printf( "  +-----------------+	\n" );
	printf( "  |  2.公证员登陆   |	\n" );
	printf( "  +-----------------+	\n" );
	printf( "  |  3.管理员登陆   |	\n" );
	printf( "  +-----------------+	\n" );
	printf( "  |  0.退出系统     |	\n" );
	printf( "=======================\n" );
	printf( "请选择:" );

	int ch = -1;
	scanf( "%d", &ch );
	while ( '\n' != getchar( ) );

	int flag = 1;
	switch ( ch )
	{
		case 1:
			user_login_ctrl( user_first, lot_first, pub_first );
			break;
		case 2:
			gref_login( user_first, lot_first, pub_first );
			break;
		case 3:
			admin_login( user_first, pub_first );
			break;
		case 0:
			flag = 0;
			break;
		default :
			break;
	}

	system( "clear" );
	return flag;
}
