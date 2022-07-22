#include "rule.h"

//投注及中奖说明
void show_rule( )
{
	system( "clear" );
	printf( "=================================================\n" );
	printf( "               投 注 及 中 奖 说 明              \n" );
	printf( "*************************************************\n" );
	printf( " 投  注：               *  奖  励：              \n"
			"     从01到15共15个号码 *      【一等奖】投注号码\n"
			" 中选择三个不同号码组合 *  与当期开奖号码全部相同\n" 
			" 为一注投注号码，单次购 *  (顺序不限)即中奖!     \n"
			" 买最多五注,每注两元。  *  奖金为:2500元         \n"
			"*********************** * ***********************\n"
			"     【二等奖】投注号码 *      【三等奖】投注号码\n"
			" 与当期开奖号码任意两个 *  与当期开奖号码任意一个\n"
			" 相同即中奖!            *  相同即中奖!           \n"
			" 奖金为:1000元          *  奖金为:500元          \n"
			"=================================================\n");
	printf( "请输入任意字符继续:" );
	getchar( );
	while ( '\n' != getchar( ) );
}


//获奖条件判定
void prize( UN_t *user_first, LN_t *lot_first, PN_t *pub_n )
{
	LN_t *lot_n = lot_first;
	while ( NULL != lot_n )
	{
		//判断出现相同号码的个数
		int count = 0;
		if ( lot_n->data.issue == pub_n->data.issue )
		{
			for ( int i = 0; i < 3; i++ )
			{
				for ( int j = 0; j < 3; j++ )
				{
					if ( lot_n->data.lot_num[i] == pub_n->data.draw_num[j] )
					{
						count++;
					}
				}
			}
			//获得奖项
			UN_t *user_n = find_user_by_user_id( user_first, lot_n->data.user_id );
			if ( 3 == count )
			{
				strcpy( lot_n->data.prize, "🥇" );
				pub_n->data.pool -= 2500 * lot_n->data.bet_num;
				user_n->data.acc_bal += 2500 * lot_n->data.bet_num;
			}
			else if ( 2 == count )
			{
				strcpy( lot_n->data.prize, "🥈" );
				pub_n->data.pool -= 1000 * lot_n->data.bet_num;
				user_n->data.acc_bal += 1000 * lot_n->data.bet_num;
			}
			else if( 1 == count )
			{
				strcpy( lot_n->data.prize, "🥉" );
				pub_n->data.pool -= 500 * lot_n->data.bet_num;
				user_n->data.acc_bal += 500 * lot_n->data.bet_num;
			}
			else
				strcpy( lot_n->data.prize, "🈚️" );
		}
		lot_n = lot_n->next;
	}
}
