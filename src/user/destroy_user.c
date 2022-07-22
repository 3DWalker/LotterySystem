#include "destroy_user.h"

//删除注销用户的购买记录
void destroy_lot_by_user( UN_t *user_n, LN_t *lot_first )
{
	LN_t *lot_n = lot_first;
	while ( NULL != lot_n )
	{
		if ( 0 == strcmp( user_n->data.id, lot_n->data.user_id ) )
		{
			if ( lot_n == lot_first )		//删除首节点
			{
				LD_t empty = { };
				lot_n->data = empty;
			}
			//删除非首节点
			else
			{
				LN_t *pre = lot_first;
				while ( NULL != pre )
				{
					if ( pre->next == lot_n )
					{
						pre->next = lot_n->next;
						free( lot_n );
						break;
					}
					pre = pre->next;
				}
			}
		}	
		lot_n = lot_n->next;
	}
}


//注销用户
int destroy_user( UN_t *first, UN_t *user_n, LN_t *lot_first )
{
	//提示用户是否确认删除
	char ch = 0, flag = 1;
	printf( "是否确认注销账号[y/n]:" );
	scanf( "%c",  &ch );
	while ( '\n' != getchar( ) );
	if ( 'Y' != ch && 'y' != ch )
	{
		printf( "已取消, 输入任意字符继续:" );
		return flag;
	}

	//删除注销用户的购买记录
	destroy_lot_by_user( user_n, lot_first );

	//注销用户
	if ( first != user_n )		//注销的不是首节点
	{
		UN_t *pre = first;
		while ( user_n != pre->next )
		{
			pre = pre->next;
		}
		pre->next = user_n->next;
		free( user_n );
		user_n = NULL;
	}
	else		//注销的是首节点
	{
		UD_t empty = { };
		user_n->data = empty;
	}
	flag = 0;
	printf( "注销成功，输入任意字符退出:" );

	return flag;
}
