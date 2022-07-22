#include "bet_ctrl.h"

void recharge( UD_t *data )
{
    double amount = 0.0;
	printf( "请输入充值金额:" );
	int rec = scanf( "%lf", &amount );
	while ( '\n' != getchar( ) );

	//判断输入的是不是数字
	if ( 0 == rec )
	{
		printf( "输入有误，退出充值!\n" );
		return;
	}

	//判断是否确认充值
	char ch = 0;
	printf( "是否确认充值[y/n]:" );
	scanf( "%c", &ch );
	while ( '\n' != getchar( ) );
	if ( 'Y' != ch && 'y' != ch )
	{
		printf( "充值失败!" );
		return;
	}
	data->acc_bal += amount;		//更新用户余额
	printf( "充值成功,请输入任意字符继续:" );
	getchar( );
	while ( '\n' != getchar( ) );
}


//下注
void bet( UN_t *user_n, LN_t *lot_first, PN_t *pub_n )
{
	//判断彩票是否发行
	if( 0 == pub_n->data.issue )
	{
		printf( "彩票暂未发行，敬请期待!" );
		return;
	}
	if ( 0 !=  pub_n->data.draw_num[0] )
	{
		printf( "新一期彩票暂未发行，无法购买!" );
		return;
	}

	//输入下注号码并判断是否有效
	LD_t data  = { };		//彩票信息存储器
	int rec = 0;
	for ( int i = 0; i < 3; i++ )
	{
		printf( "请输入第%d组数字:", i +1 );
		rec = scanf( "%d", &data.lot_num[i] );
		while( '\n' != getchar( ) );

		int count = 1;
		while ( count )
		{
			count = 0;
			//判断输入的数字是否合规
			while ( 0 == rec || 15 < data.lot_num[i] || 1 > data.lot_num[i] )
			{
				if ( 0 == rec )
					printf( "您输入的不是数字，请重新输入:" );
				else
        	        printf( "请输入1-15的数字:" );
				rec = scanf( "%d", &data.lot_num[i] );
				while( '\n' != getchar( ) );
			}
			//判断数字是否输入过
			for ( int j = 0; j < 3; j++ )
			{
				if ( j != i && data.lot_num[i] == data.lot_num[j] )
				{
					printf( "您已经输入过此数字，请重新输入:" );
					rec = scanf( "%d", &data.lot_num[i] );
					while( '\n' != getchar( ) );
					count++;
				}
			}
		}
	}

	//输入注数并判断是否有效
	int num = 0;
	printf( "请输入您要下的注数:" );
	rec = scanf( "%d", &num );
	while ( '\n' != getchar( ) );

	while( 5 < num || 0 == rec )
	{
		if ( 0 == rec )
			printf( "输入的不是数字!\n" );
		else
			printf( "单次购买最对5注!\n" );
		printf( "请重新输入您要下的注数:" );
		rec = scanf( "%d", &num );
		while ( '\n' != getchar( ) );
	}

	//判断余额是否充足并提醒用户是否充值
	if ( num *pub_n->data.price > user_n->data.acc_bal )
	{
		char ch = 0;
		printf( "余额不足，是否前往充值[y/n]" );
		scanf( "%c", &ch );
		while ( '\n' != getchar( ) );
		if ( 'Y' != ch && 'y' != ch )
		{
			printf( "余额不足购买失败!\n" );
			return;
		}
		recharge( &user_n->data );
	}

	//存储所购买彩票的信息
	data.bet_num = num;		//存储注数
	strcpy( user_n->data.id, data.user_id );		//存储用户id
	data.issue = pub_n->data.issue;		//存储期号
	LN_t *lot_n = find_lot_by_lot_id_max( lot_first );
	if ( 0 == lot_n->data.lot_id  )
		data.lot_id = 123;		//初始化彩票id
	else
		data.lot_id += lot_n->data.lot_id +1;		//存储彩票id

	//插入彩票节点并更新余额/奖池/销售额
	LN_t *q = create_node( &data, sizeof( LN_t ), sizeof( LD_t ) );
	insert_lot( lot_first, q );
	pub_n->data.sum_bet += num;		//更新销售额
	user_n->data.acc_bal -= num * pub_n->data.price;	//更新用户余额
	pub_n->data.pool += num * pub_n->data.price;	//更新奖池金额

	printf( "购买成功,请按回车键继续!" );
}


//下注控制面板
void bet_ctrl( UN_t *user_n, LN_t *lot_first, PN_t *pub_first )
{
	PN_t *pub_n = find_pub_by_issue_max( pub_first );
	while ( 1 )
	{
		system( "clear" );
		printf( "=======================\n" );
		printf( "      彩 票 下 注      \n" );
		printf( "-----------------------\n" );
		printf( " 余 额: %.2lf 元\n", user_n->data.acc_bal );
		printf( "-----------------------\n" );
		printf( " 单 价: %.2f 元 \n", pub_n->data.price );
		printf( "-----------------------\n" );
		printf( " 期 号: %04d\n", pub_n->data.issue );
		printf( "-----------------------\n" );
		printf( " 奖池金额:%d 元\n", pub_n->data.pool );
		printf( "-----------------------\n" );
		printf( " 1.下 注       2.充 值 \n" );
		printf( "-----------------------\n" );
		printf( " 3.规 则       0.退 出 \n" );
		printf( "=======================\n" );
		printf( "请选择:" );

		int ch = -1;
		scanf( "%d", &ch );
		while ( '\n' != getchar( ) );

		switch ( ch )
		{
			case 1:
				bet( user_n, lot_first, pub_n );
				getchar( );
				while ( '\n' != getchar( ) ){}
			 	break;
			case 2:
				recharge( &user_n->data );
				break;
			case 3:
				show_rule( );
				break;
			case 0:
				return;
			default :
				break;
		}
	}
}