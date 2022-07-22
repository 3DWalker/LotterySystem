#include "user.h"

//显示单个用户信息
void show_user_info( UD_t *data )
{
    printf( "姓名：%s, 账号：%s, 余额：%.2lf\n"
            , data->name, data->id, data->acc_bal );
}


//显示用户个人信息
void show_user_n_info( UD_t data )
{
    system( "clear" );
	printf( "=======================\n" );
	printf( "      个 人 信 息      \n" );
	printf( "-----------------------\n" );
	printf( "姓  名: %s\n", data.name );
	printf( "账  号: %s\n", data.id );
	printf( "余  额: %.2lf 元\n", data.acc_bal );
	printf( "=======================\n" );
	printf( "请输入任意字符继续:" );
	getchar( );
    while ( '\n' != getchar( ) );
}

//显示所有用户的基本信息
void show_all_user_info( UN_t *first )
{
	UN_t *node = first;
	while ( NULL != node )
	{
		show_user_info( &node->data );
		node = node->next;
	}
}