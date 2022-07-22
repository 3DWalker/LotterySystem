#ifndef __PUB_H__
#define __PUB_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//发行基本信息结构体
typedef struct publish_lottery_data
{
	int issue;			//期号
	double price;		//单价
	int pool;			//奖池金额
	int sum_bet;		//总注数
	int draw_num[3];	//开奖号码
	char state[20];		//开奖状态
}PD_t;

//发行节点信息结构体
typedef struct publish_lottery_node
{
	PD_t data;
	struct publish_lottery_node *next;
}PN_t;

//插入发行节点--尾插法
void insert_pub( PN_t *, PN_t * );

//查找发行--按期号最大值
PN_t *find_pub_by_issue_max( PN_t * );

//查找发行--按期号
PN_t *find_pub_by_issue( PN_t *, int );

//显示中奖号码
void show_draw_num( PD_t * );

//显示所有发行信息
void show_all_pub_info( PN_t * );

//保存发行信息
void save_pub( PN_t * );

//加载发行信息
void load_pub( PN_t * );

//释放发行空间
void free_pub( PN_t * );

#endif
