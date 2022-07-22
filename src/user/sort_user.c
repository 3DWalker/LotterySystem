#include "sort_user.h"

//按用户昵称排序
void sort_user_by_name( UN_t *first, int mode )
{
	int count = 1;
	while ( count )
	{
		count = 0;
		for ( UN_t *p = first; NULL != p->next; p = p->next )
		{
			int rec = 0;
			if ( mode )
			{
				rec = ( strcmp( p->data.name, p->next->data.name ) > 0 );
			}
			else
			{
				rec = ( strcmp( p->data.name, p->next->data.name ) < 0 );
			}
			if ( rec )
			{
				UD_t tmp = p->data;
				p->data = p->next->data;
				p->next->data = tmp;
				count++;
			}
		}
	}
}


//按用户ID排序
void sort_user_by_id( UN_t *first, int mode )
{
	int count = 1;
	while ( count )
	{
		count = 0;
		for ( UN_t *p = first; NULL != p->next; p = p->next )
		{
			int rec = 0;
			if ( mode )
			{
				rec = ( p->data.id > p->next->data.id );
			}
			else
			{
				rec = ( p->data.id < p->next->data.id );
			}
			if ( rec )
			{
				UD_t tmp = p->data;
				p->data = p->next->data;
				p->next->data = tmp;
				count++;
			}
		}
	}
}


//按用户余额排序
void sort_user_by_acc_bal( UN_t *first, int mode )
{
	int count = 1;
	while ( count )
	{
		count = 0;
		for ( UN_t *p = first; NULL != p->next; p = p->next )
		{
			int rec = 0;
			if ( mode )
			{
				rec = ( p->data.acc_bal > p->next->data.acc_bal );
			}
			else
			{
				rec = ( p->data.acc_bal < p->next->data.acc_bal );
			}
			if ( rec )
			{
				UD_t tmp = p->data;
				p->data = p->next->data;
				p->next->data = tmp;
				count++;
			}
		}
	}
}


//用户排序面板
void sort_user_ctrl( UN_t *first )
{
	while ( 1 )
	{
		system( "clear" );
		printf( "=======================\n" );
		printf( "      彩 民 排 序      \n" );
		printf( "-----------------------\n" );
		printf( "     1.按昵称升序      \n" );
		printf( "     2.按昵称降序		\n" );
		printf( "     3.按账号升序		\n" );
		printf( "     4.按账号降序		\n" );
		printf( "     5.按余额升序      \n" );
		printf( "     6.按余额降序		\n" );
		printf( "     0.退  出          \n" );
		printf( "=======================\n" );
		printf( "请选择:" );

		int ch = -1;
		scanf( "%d", &ch );
		while ( '\n' != getchar( ) );

		if ( 1 <= ch && 2 >= ch )
		{
			sort_user_by_name( first, ch % 2 );
		}
		else if ( 3 <= ch && 4 >= ch )
		{
			sort_user_by_id( first, ch % 2 );
		}
		else if ( 5 <= ch && 6 >= ch )
		{
			sort_user_by_acc_bal( first, ch % 2 );
		}
		else if ( 0 == ch )
		{
			return;
		}
		else
		{
			continue;
		}

		system( "clear" );
		printf( "排序完成:\n" );
		show_all_user_info( first );
		printf( "请输入任意字符继续:" );
		getchar( );
		while ( '\n' != getchar( ) );
	}
}
