#include "user_ctrl.h"

//用户控制面板
void user_ctrl( UN_t *user_first, UN_t *user_n, LN_t *lot_first, PN_t* pub_first )
{
    int flag = 1;
	while( flag )
	{
		system( "clear" );
		printf( "=======================\n" );
		printf( "      用 户 系 统      \n" );
		printf( "-----------------------\n" );
		printf( "    1.查看个人信息     \n" );
		printf( "    2.修改信息         \n" );
		printf( "    3.下  注           \n" );
		printf( "    4.查看购买记录     \n" );
		printf( "    5.注销账号		    \n" );
		printf( "    0.退  出           \n" );
		printf( "=======================\n" );
		printf( "请选择:" );

        int ch = -1;
        scanf( "%d", &ch );
        while ( '\n' != getchar( ) );

        switch ( ch )
        {
            case 1:
                show_user_n_info( user_n->data );
                break;
            case 2:
                flag = update_ctrl( user_first, &user_n->data );
                break;
            case 3:
				bet_ctrl( user_n, lot_first, pub_first );
				break;
			case 4:
				show_lot_by_user( user_n, lot_first, pub_first );
				break;
			case 5:
				flag = destroy_user( user_first, user_n, lot_first );
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

//注册新账户
void user_register( UN_t *first )
{
    system( "clear" );
    printf( "=======================\n" );
	printf( "    注 册 新 账 号     \n" );
	printf( "-----------------------\n" );

    //输入新用户昵称
    UD_t data = { };
    printf( "请输入用户昵称(按ESC退出):");
    scanf( "%s", data.name );
    while ( '\n' != getchar( ) );
    if ( 27 == data.name[0] )   return;     //强制退出

    //判断新用户昵称是否存在
    while ( NULL != find_user_by_name( first, data.name ) )
    {
       printf( "该昵称已存在，请重新输入(按ESC退出):\n");
       scanf( "%s", data.name );
       while ( '\n' != getchar( ) );
       if ( 27 == data.name[0] )        //强制退出
       {
           return;
       }
    }

    //初始化新用户基础信息
    UN_t *node = find_user_by_id_max( first );
    if ( 0 == strcmp( node->data.id, "" ) )
    {
        strcpy( data.id, "1001" );     //第一个用户的ID
    }
    else 
    {
        int id = 0;
        sscanf( node->data.id, "%d", &id );    //非第一个用户的ID
        id++;
        sprintf( data.id, "%d", id );
    }
    strcpy( data.pswd, "12345" );   //初始化密码
    data.acc_bal = 10;      //初始化余额

    //存储新用户的基础信息
    UN_t *user_n = create_node( &data, sizeof(UN_t), sizeof(UD_t) );
    insert_user( first, user_n );

    //显示新用户的基础信息
    if ( 0 != identify_code( ) )
    {
        system( "clear" );

        printf( "恭喜%s注册成功, 赠送您10元代金券!\n", data.name );
		printf( "您的账号为:%s\n", user_n->data.id);
		printf( "初始密码为:%s\n", user_n->data.pswd );
		printf( "请输入任意字符继续:" );
		getchar( );
		while ( '\n' != getchar( ) );
    }
}  


//账号密码登录
void user_login( UN_t *user_first, LN_t *lot_first, PN_t *pub_first )
{
    system( "clear" );
	printf( "=======================\n" );
	printf( "   账 号 密 码 登 陆   \n" );
	printf( "-----------------------\n" );

    //输入用户ID
    char id[20] = "";
    printf( "请输入账号:" );
    scanf( "%s", id );
    while ( '\n' != getchar( ) );

    //判断账号是否存在,若无则判断是否前往注册
    UN_t *user_n = find_user_by_user_id( user_first, id );
    if ( NULL == user_n )
    {
        printf( "没有该账号,是否前往注册[y/n]:");
        char ch = 0;
        scanf( "%c", &ch );
        while ( '\n' != getchar( ) );

        if ( 'Y' != ch && 'y' != ch )
        {
            printf( "已取消登录, 输入任意字符继续：");
            getchar( );
            while ( '\n' != getchar( ) );
        }
        else
        {
            user_register( user_first );
        }

        return;
    }

    //验证密码的正确性，并给予三次输入机会
    int count = 0;
    char pswd[32] = { };
    while ( 3 > count )
    {
        printf( "请输入密码:" );
        get_pswd( pswd );
        count++;

        if ( 0 == strcmp( user_n->data.pswd, pswd ) )
        {
            break;
        }
        if ( 3 > count )
        {
            printf( "密码错误(剩余次数%d), 请重新登录!\n", 3 - count );
        }
    }
    if( 3 > count )
    {
        if ( 0 != identify_code( ) )
        {
            system( "clear" );
            printf( "验证成功，请输入任意字符完成登录:" );
            getchar( );
            while ( '\n' != getchar( ) );
            user_ctrl( user_first, user_n, lot_first, pub_first );
        }
    }
    else
    {
        printf( "密码错误(剩余次数0)，登录取消!\n");
        printf( "请输入任意字符继续:" );
        getchar( );
        while ( '\n' != getchar( ) );
    }
} 


//用户登录选择面板
void user_login_ctrl( UN_t *user_first, LN_t *lot_first, PN_t *pub_first )
{
    while ( 1 )
    {
        system( "clear" );
		printf( "=======================\n" );
		printf( "      用 户 登 陆      \n" );
		printf( "-----------------------\n" );
		printf( "    1.账号密码登陆\n" );
		printf( "    2.注册新账号\n" );
		printf( "    0.退  出\n" );
		printf( "=======================\n" );
		printf( "请选择:" );

        int ch  = -1;
        scanf( "%d", &ch );
        while ( '\n' != getchar( ) );

        switch ( ch )
        {
            case 1:
                user_login( user_first, lot_first, pub_first );
                break;
            case 2:
                user_register( user_first );
                break;
            case 0:
                return;
            default :
                break;
        }
    }
}