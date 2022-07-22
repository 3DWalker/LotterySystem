#include "pub_ctrl.h"

//发行彩票
void pub_lot( PN_t *first, PN_t *pub_n )
{
	//限制彩票发行
	int empty[3] = { };
    if ( 0 == memcmp( pub_n->data.draw_num, empty, sizeof( int ) *3 )
		&& 0 != pub_n->data.issue )
    {
        printf( "本期彩票暂未开奖，无法发行!\n" );
		printf( "请输入任意字继续:" );
        return;
    }

	//是否确认发行
    char ch = 0;
    printf( "确认发行[y/n]:" );
    scanf( "%c", &ch );
    while ( '\n' != getchar( ) );
    if ( 'Y' != ch && 'y' != ch )
    {
        printf( "已取消发行, 请输入任意字继续:\n" );
		return;
    }

	//初始化发行数据
	PD_t data = { };
	if ( 0 == pub_n->data.issue )		//首节点的数据
	{
		data.price = 2;
		data.issue = 1;
		data.pool = 100000;
	}
	else		//非首节点的数据
	{
		data.price = pub_n->data.price;		
		data.issue = pub_n->data.issue +1;
		data.pool = pub_n->data.pool;
	}
	strcpy( data.state, "未开奖" );		//初始化开奖状态

	//存储发行节点
	PN_t *node = create_node( &data, sizeof( PN_t ), sizeof( PD_t ) );
	insert_pub( first, node );

	printf( "发行成功,请输入任意字继续:" );
}



//彩票发行控制面板
void pub_ctrl( PN_t *first )
{
	while ( 1 )
	{
		PN_t * pub_n = find_pub_by_issue_max( first );
		system( "clear" );
    	printf( "=======================\n" );
    	printf( "      彩 票 发 行      \n" );
    	printf( "-----------------------\n" );
    	printf( " 期 号: %d\n", pub_n->data.issue );
    	printf( "-----------------------\n" );
    	printf( " 单 价: %.2lf 元\n", pub_n->data.price );
    	printf( "-----------------------\n" );
		printf( " 销售量:%04d 注\n", pub_n->data.sum_bet );
    	printf( "-----------------------\n" );
    	printf( " 奖池金额: %d 元\n", pub_n->data.pool );
    	printf( "-----------------------\n" );
		printf( " 1.发行         0.退出 \n" );
    	printf( "=======================\n" );
		printf( "请选择:" );
		
		int ch = -1;
		scanf( "%d", &ch );
		while ( '\n' != getchar( ) );

		switch ( ch )
		{
			case 1:
				pub_lot( first, pub_n );
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
