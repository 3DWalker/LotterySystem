#include "user.h"
#include "lot.h"
#include "pub.h"
#include "login.h"

int main( void )
{
	UN_t *user_first = calloc( 1, sizeof(UN_t) );
	LN_t *lot_first = calloc( 1, sizeof(LN_t) );
	PN_t *pub_first = calloc( 1, sizeof(PN_t) );

	load_user( user_first );
	load_lot( lot_first );
	load_pub( pub_first );

	while ( login( user_first, lot_first, pub_first ) );

	save_user( user_first );
	free_user( user_first );

	save_lot( lot_first );
	free_lot( lot_first );

	save_pub( pub_first );
	free_pub( pub_first );

	return 0;
} 