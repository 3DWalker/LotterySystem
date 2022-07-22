#include "identify_code.h"

int identify_code( void )
{
    char arr[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890";
    char a[5] = "", b[5] = "";

    while ( 1 )
    {
        srand( time( NULL ) );
        a[0] = arr[rand( ) % 26];
        a[1] = arr[rand( ) % 26 + 26];
        a[2] = arr[rand( ) % 10 + 52];
        a[3] = arr[rand( ) % 10 + 52];
        a[4] = '\0';

        printf( "验证码:%s\n", a );
        printf( "请输入验证码:" );
        scanf( "%5s", b );
        while ( '\n' != getchar( ) );

        if ( 27 == b[0] )
        {
            system( "clear" );
            printf( "强制退出成功，输入任意字符继续:\n " );
            getchar( );
            while ( '\n' != getchar( ) );
            return 0;
        }
        if ( 0 == strcpy( a, b ) )
        {
            printf( "验证码错误，请重新输入！\n" );
            getchar( );
            while ( '\n' != getchar( ) );
            return 0;
        }
        else
        {
            return 1;
        }
    }
}