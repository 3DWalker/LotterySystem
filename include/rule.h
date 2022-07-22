#ifndef RULE_H
#define RULE_H

#include "user.h"
#include "lot.h"
#include "pub.h"

//投注及中奖说明
void show_rule( );

//获奖条件判定
void prize( UN_t *, LN_t *, PN_t * );

#endif
