
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


/* ======================================================================== */
/* Structures */

typedef struct t_game
{
	bool initilized;
	bool married;
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
	separator();
	
	bool run = true;
	while( run )
	{
		
		// Selection screen
		printf( "\n\n" );
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
		
		separator();
		
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
				
				if( game.married )
				{
					run = false;
					separator();
					printf( "Congratulations, adventurer!\n" );
				}
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
		
		//game_display( &game );
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
	
	game->married = false;
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
	//printf( "Adventure\n" );
	
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
	//printf( "Shop\n" );
	
	if( game->artifacts == 0 )
	{
		printf( "Unfortunately Adventurer, you don't have any artifacts.\n" );
	}else{
		unsigned long price = game->artifacts * rand_int( 10, 20 );
		
		if( game->gold < (0xFFFFFFFF-price) )
		{
			printf( "Sure thing Adventurer, have %ld gold for your %d artifacts!\n", price, game->artifacts );
			game->gold += price;
			game->artifacts = 0;
			
			game->hash = game_get_hash( game );
		}else{
			printf( "You are way too rich adventurer! Spend some gold first.\n" );
		}
	}
	
	return 0;
}


int rest( s_game* game )
{
	//printf( "Rest\n" );
	
	if( game->gold < 10 )
	{
		printf( "Unfortunately Adventurer, you don't have enought gold.\n" );
		if( game->artifacts > 0 )
		{
			printf( "Try selling some artifacts maybe?\n" );
		}
	}else{
		printf( "Sure thing adventurer!\nHave a nice meal, and rest as you wish until tomorrow!\n" );
		game->gold -= 10;
		
		// Bonus, you can rest to 110% of health
		unsigned char rest = rand_int( 50, 60 );
		if( game->health > (110-rest) )
		{
			game->health = 110;
		}else{
			game->health += rest;
		}
		
		game->days ++;
		
		game->hash = game_get_hash( game );
	}
	
	printf( "Also, would you like to save you progress?\n" );
	printf( "[UNIMPLEMENTED YET]\n" );
	
	return 0;
}


int princess( s_game* game )
{
	//printf( "Princess!\n" );
	
	if( game->gold >= 100 )
	{
		printf( "You are wealthy" );
		if( game->health >= 100 )
		{
			printf( " and well rested!\n" );
			printf( "The princess is yours!\n" );
			
			game->married = true;
			game->hash = game_get_hash( game );
		}else{
			printf( " but too tired!\n" );
			printf( "Come back when you are full of energy!\n" );
		}
	}else{
		printf( "Adventurer, you are not wealthy enough!\n" );
	}
	
	return 0;
}


void game_display( s_game* game )
{
	printf( "DEBUG:\n" );
	printf( "Initialized\t: %d\n", game->initilized );
	printf( "Married\t: %d\n", game->married );
	printf( "Days\t: %ld\n", game->days );
	printf( "Health\t: %d\n", game->health );
	printf( "Gold\t: %ld\n", game->gold );
	printf( "Artifacts\t: %d\n", game->artifacts );
	printf( "Hash\t: %ld\n", game->hash );
}


unsigned long game_get_hash( s_game* game )
{
	return (unsigned long)( game->initilized + game->married + game->days + game->health + game->gold + game->artifacts );
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
