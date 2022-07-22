#include "pub.h"

//释放发行链表
void free_pub( PN_t *first )
{
	PN_t *node = first, *p = NULL;
	while ( NULL != node )
	{
		p = node;
		node = node->next;
		free( p );
		p = NULL;
	}
}
