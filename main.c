
#include <stdio.h>
#include <stdbool.h>


/* ======================================================================== */
/* Structures */

typedef struct t_game
{
	bool initilized;
	unsigned long days;
	unsigned char health;
	unsigned long gold;
	unsigned char artifacts;
	unsigned long hash;
} s_game;


/* ======================================================================== */
/* Functions */

int title( s_game* game );
int adventure( s_game* game );
int shop( s_game* game );
int rest( s_game* game );
int princess( s_game* game );

void game_display( s_game* game );
unsigned long game_get_hash( s_game* game );

/* ======================================================================== *\
| Main
\* ======================================================================== */
int main( void )
{
	s_game game;
	game_display( &game );
	title( &game );
	game_display( &game );
	
	bool run = false;
	while( run )
	{
		unsigned char selection = 0;
		
		switch( selection )
		{
			case 0:
			{
				adventure( &game );
				break;
			}
			
			case 1:
			{
				shop( &game );
				break;
			}
			
			case 2:
			{
				rest( &game );
				break;
			}
			
			case 3:
			{
				princess( &game );
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


/* ======================================================================== */
/* Functions */

int title( s_game* game )
{
	printf( "Title\n" );
	
	game->days = 0;
	game->health = 100;
	game->gold = 20;
	game->artifacts = 0;
	game->hash = game_get_hash( game );
	game->initilized = true;
	
	return 0;
}


int adventure( s_game* game )
{
	printf( "Adventure\n" );
	return 0;
}


int shop( s_game* game )
{
	printf( "Shop\n" );
	return 0;
}


int rest( s_game* game )
{
	printf( "Rest\n" );
	return 0;
}


int princess( s_game* game )
{
	printf( "Princess!\n" );
	return 0;
}


void game_display( s_game* game )
{
	printf( "DEBUG:\n" );
	printf( "Initialized\t: %d\n", game->initilized );
	printf( "Days\t: %ld\n", game->days );
	printf( "Health\t: %d\n", game->health );
	printf( "Gold\t: %ld\n", game->gold );
	printf( "Artifacts\t: %d\n", game->artifacts );
	printf( "Hash\t: %ld\n", game->hash );
}

unsigned long game_get_hash( s_game* game )
{
	return 0;
}
