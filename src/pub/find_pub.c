#include "pub.h"

//查找发行--按期号最大值
PN_t *find_pub_by_issue_max( PN_t *first )
{
    PN_t *node = first, *pre = NULL;
    while ( NULL != node->next )
    {
        pre = node;
        node = node->next;
        if ( node->data.issue < pre->data.issue)
        {
            PD_t temp = node->data;
            node->data = pre->data;
            pre->data = temp;
        }
    }

    return node;
}

//查找发行--按期号
PN_t *find_pub_by_issue( PN_t *first, int issue )
{
	PN_t *node = first;
	while ( NULL != node )
	{
		if ( issue == node->data.issue )
		{
			break;
		}
		node = node->next;
	}
	
	return node;
}