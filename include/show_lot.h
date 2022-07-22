#ifndef SHOW_ALL_H
#define SHOW_ALL_H

#include "user.h"
#include "pub.h"
#include "lot.h"

//显示与单张彩票相关联的信息
void show_lot_by_user( UN_t *, LN_t *, PN_t * );

//显示所有彩票信息
void show_all_lot_info( LN_t *, PN_t * );

#endif
