#include <stdlib.h>

int main( void )
{
	system( "gcc ./src/user/*.c ./src/lot/*.c ./src/pub/*.c ./src/main/main.c -o ./bin/main -Wall -Iinclude" );

	return 0;
}
