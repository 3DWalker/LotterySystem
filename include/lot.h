#ifndef __LOT_H__
#define __LOT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//彩票基本信息结构体
typedef struct lottery_data
{
	int issue;			//期号
	char user_id[20];		//用户id
	int lot_id;			//彩票id
	int lot_num[3];		//彩票号码
	int bet_num;		//倍率
	char prize[20];		//中奖等级
}LD_t;

//彩票节点信息结构体
typedef struct lottery_node
{
	LD_t data;
	struct lottery_node *next;
}LN_t;

//插入彩票节点--尾插法
void insert_lot( LN_t *, LN_t * );

//查找彩票ID的最大值
LN_t *find_lot_by_lot_id_max( LN_t *first );

//保存彩票数据
void save_lot( LN_t * );

//加载彩票数据
void load_lot( LN_t * );

//释放彩票空间
void free_lot( LN_t * );

#endif
