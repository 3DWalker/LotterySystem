#include "pub.h"

//插入发行节点--尾插法
void insert_pub( PN_t *first, PN_t *node )
{
	if ( NULL == node )		//判断插入的节点是否有误
	{
		printf( "用户插入信息有误，插入失败!\n" );
		return;
	}
    if ( 0 == first->data.issue )	//覆盖首节点
	{
		first->data = node->data;
		return;
	}

	PN_t *tmp = first;
	while ( NULL != tmp->next )		//查找链表的尾部
	{
		tmp = tmp->next;
	}
	tmp->next = node;		//插入用户节点
	node->next = NULL;
}