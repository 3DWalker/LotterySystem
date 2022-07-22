#include "lot.h"

//释放彩票链表
void free_lot( LN_t *first )
{
	LN_t *node = first, *p = NULL;
	while ( NULL != node )
	{
		p = node;
		node = node->next;
		free( p );
		p = NULL;
	}
}
