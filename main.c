
#include <stdio.h>
#include <stdbool.h>

typedef struct t_game
{
	unsigned long gold;
} s_game;


int title( s_game game );
int adventure( s_game game );
int shop( s_game game );
int rest( s_game game );
int princess( s_game game );


int main( void )
{
	s_game game;
	int result = title( game );
	
	bool run = false;
	while( run )
	{
		unsigned char selection = 0;
		
		switch( selection )
		{
			case 0:
			{
				adventure( game );
				break;
			}
			
			case 1:
			{
				shop( game );
				break;
			}
			
			case 2:
			{
				rest( game );
				break;
			}
			
			case 3:
			{
				princess( game );
				break;
			}
			
			default:
			{
				printf( "Nani?\n" );
				break;
			}
		}
	}
	
	return 0;
}


int title( s_game game )
{
	printf( "Title\n" );
	return 0;
}


int adventure( s_game game )
{
	printf( "Adventure\n" );
	return 0;
}


int shop( s_game game )
{
	printf( "Shop\n" );
	return 0;
}


int rest( s_game game )
{
	printf( "Rest\n" );
	return 0;
}


int princess( s_game game )
{
	printf( "Princess!\n" );
	return 0;
}
