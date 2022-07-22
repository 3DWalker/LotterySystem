#ifndef __USER_H__
#define __USER_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "create_node.h"

//用户基本信息结构体
typedef struct user_data
{
	char name[20];		//姓名
	char id[20];		//账号
	char pswd[20];		//密码
	double acc_bal;		//余额
}UD_t;

//用户节点信息结构体
typedef struct user_node
{
	UD_t data;
	struct user_node *next;
}UN_t;

//显示单个用户信息
void show_user_info( UD_t * );

//显示用户个人信息
void show_user_n_info( UD_t );

//显示所有用户的基本信息
void show_all_user_info( UN_t * );

//查找用户--按昵称
UN_t *find_user_by_name( UN_t *, const char * );

//查找用户--按ID
UN_t *find_user_by_user_id( UN_t *, const char * );

//查找用户--按idMax
UN_t *find_user_by_id_max( UN_t * );

//插入用户节点--尾插法
void insert_user( UN_t *first, UN_t * );

//保存用户数据
void save_user( UN_t * );

//加载用户数据
void load_user( UN_t * );

//释放用户数据
void free_user( UN_t * );

//信息修改面板
int update_ctrl( UN_t *, UD_t * );


#endif
