#include "update_user.h"

//修改昵称
void update_name( UN_t *first, UD_t *data )
{
    char name[20] = "";
    printf( "请输入新昵称:");
    scanf( "%s", name );
    while ( '\n' != getchar( ) );

    while ( NULL != find_user_by_name( first, name ) )
    {
        printf( "该昵称已存在，请重新输入(按ESC退出):" );
        scanf( "%s", name );
        while ( '\n' != getchar( ) );
        if( 27 == name[0] )
        {
            printf( "已取消修改,输入任意字符继续:");
            return;
        }
    }

    char ch = 0;
    printf( "修改成:%s[y/n]", name );
    scanf( "%c", &ch );
    while ( '\n' != getchar( ) );
    if ( 'Y' != ch && 'y' != ch )
    {
        printf( "已取消修改, 输入任意字符继续:");
        return;
    }
    
    strcpy( data->name, name );
    printf( "修改成功，输入任意字符继续:");
}


//修改密码
int update_pswd( UD_t *data )
{
    char pswd[20] = "";
    int count = 0;
    while ( 3 > count )
    {
        count++;
        printf( "请输入旧密码:" );
        get_pswd( pswd );
        if ( 27 == pswd[0] )
        {
            printf( "已取消修改, 输入任意字符继续:" );
            return 1;
        }
        
        if (0 == strcmp( data->pswd, pswd ) ) 
        {
            break;
        }

        if ( 3 == count )
        {
            printf( "密码错误(剩余次数0),修改退出!\n");
            printf( "请输入任意字符继续:" );
            return 1;
        }
        printf( "密码错误(剩余次数%d), 请重试(按ESC退出)!\n", 3 - count );
    }

    printf( "请输入新密码:" );
    get_pswd( pswd );
    char _pswd[20] = "";
    printf( "请确认新密码:" );
    get_pswd( _pswd );
    if ( 0 != strcmp( pswd, _pswd ) )
    {
        printf( "两次输入不一致，修改失败!\n" );
        printf( "请输入任意字符继续:");
        return 1;
    }

    strcpy( data->pswd, pswd );
    printf( "修改成功，请输入任意字符退出登录:");

    return 0;
}


//信息修改面板
int update_ctrl( UN_t *first, UD_t *data )
{
    int flag = 1;
    while ( flag )
    {
        system( "clear" );
		printf( "=======================\n" );
		printf( "      修 改 信 息      \n" );
		printf( "-----------------------\n" );
        printf( "      1.修改昵称        \n");
        printf( "      2.修改密码        \n");
        printf( "      0.退  出        \n");
        printf( "=======================\n" );
        printf( "请选择:" );

        int ch = -1;
        scanf( "%d", &ch );
        while ( '\n' != getchar( ) );

        switch ( ch )
        {
            case 1:
                update_name( first, data );
                getchar( );
                while ( '\n' != getchar( ) );
                break;
            case 2:
                flag = update_pswd( data );
                getchar( );
                while ( '\n' != getchar( ) );
                break;
            case 0:
                return flag;
            default :
                break;
        }
           
    }

    return flag;
}