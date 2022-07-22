#include "lot.h"

//查找彩票ID的最大值
LN_t *find_lot_by_lot_id_max( LN_t *first )
{
	LN_t *node = first, *pre = NULL;
	while ( NULL != node->next )
	{
		pre = node;
		node = node->next;
		if ( pre->data.lot_id > node->data.lot_id )
		{
			LD_t tmp = node->data;
			node->data = pre->data;
			pre->data = tmp;
		}
	}

	return node;
}
