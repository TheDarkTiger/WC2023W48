
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


/* ======================================================================== */
/* Structures */

typedef struct t_game
{
	bool initilized;
	unsigned long days;
	signed char health;
	unsigned long gold;
	unsigned char artifacts;
	unsigned long hash;
} s_game;


/* ======================================================================== */
/* Functions */

void separator( void );

int title( s_game* game );
int adventure( s_game* game );
int shop( s_game* game );
int rest( s_game* game );
int princess( s_game* game );

void game_display( s_game* game );
unsigned long game_get_hash( s_game* game );

int rand_init( void );
int rand_int( int min, int max);


/* ======================================================================== *\
| Main
\* ======================================================================== */
int main( void )
{
	s_game game;
	
	fflush( stdout );
	
	rand_init();
	
	title( &game );
	
	
	bool run = true;
	while( run )
	{
		
		// Selection screen
		separator();
		printf( "Day %ld\n", game.days );
		printf( "Health\t: %d\n", game.health );
		printf( "Gold\t: %ld\n", game.gold );
		printf( "Artifacts\t: %d\n", game.artifacts );
		printf( "\n" );
		printf( "What to do adventurer?\n" );
		printf( "[A] go on an Adventure\n" );
		printf( "[S] Sell my artifacts\n" );
		printf( "[R] Rest for the night\n" );
		printf( "[P] marry the Princess!\n" );
		printf( "[Q] Quit my quest\n" );
		
		char selection = 0;
		//rewind(stdin);
		fflush( stdin );
		scanf( "%c", &selection );
		rewind( stdin );
		
		switch( selection )
		{
			case 'A':
			{
				adventure( &game );
				break;
			}
			
			case 'S':
			{
				shop( &game );
				break;
			}
			
			case 'R':
			{
				rest( &game );
				break;
			}
			
			case 'P':
			{
				princess( &game );
				break;
			}
			
			case 'Q':
			{
				run = false;
				separator();
				printf( "Farewell, adventurer!\n" );
				break;
			}
			
			default:
			{
				printf( "Nani?\n" );
				break;
			}
		}
		
		game_display( &game );
	}
	
	return 0;
}


/* ======================================================================== */
/* Functions */

void separator( void )
{
	printf( "\n  -========================================-\n\n" );
}

int title( s_game* game )
{
	printf( "XIBRIFI\nCastle\n" );
	
	game->days = 0;
	game->health = 100;
	game->gold = 20;
	game->artifacts = 0;
	game->hash = game_get_hash( game );
	game->initilized = true;
	
	printf( "> NEW GAME\n" );
	printf( "  LOAD\n" );
	printf( "  QUIT\n" );
	
	return 0;
}


int adventure( s_game* game )
{
	printf( "Adventure\n" );
	
	game->days += 1;
	
	game->health -= rand_int( 1, 99 );
	
	unsigned char loot = rand_int( 1, 12 );
	if( game->artifacts > (255-loot) )
	{
		game->artifacts = 255;
	}else{
		game->artifacts += loot;
	}
	
	game->hash = game_get_hash( game );
	
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


int rand_init( void )
{
	srand( time(NULL) );
	return 0;
}


int rand_int( int min, int max)
{
	return min + ( rand()% (max-min) );
}
