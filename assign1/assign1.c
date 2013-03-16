#include <stdlib.h>
#include <stdio.h>
#include <time.h>
// Added a portion that will tell you what you rolled in the output, and when you hit a snake or a ladder

int main(void)
{
	//Initializing random
	srand(time(0));
	//Initializing all the variables that I will be using
	int player = 1;
	int die1;
	int die2;
	int moves=0;
	int board[] = 
	{
		0,0,0,22,0,0,0,0,21,0,
		0,0,43,0,0,0,0,0,19,0,
		0,0,-17,0,0,0,0,0,0,0,
		0,0,0,0,0,0,22,0,0,0,
		0,0,0,0,0,0,0,21,0,-23,
		0,0,0,-30,0,0,0,0,0,23,
		0,0,0,0,-25,0,0,0,0,0,
		0,0,16,0,0,0,19,0,0,0,
		-23,0,0,0,0,0,0,0,0,0,
		0,0,0,-24,0,0,0,-32,0,0
	};
	//Game loop
	while(player!=100)
	{
		//Rolling the dice and moving the player
		die1 = 1+rand()%5;
		die2 = 1+rand()%5;
		player = player + die1 + die2;

		
		//I noticed if you ended up on a square outside of the array (over 100) there would be random values there
		//However, they were all positive so they did not affect my loop
		
		//Printing what you rolled
		printf("You rolled %i\n",die1+die2);

		// Section in case you hit a snake or ladder
		if (player<100)
		{
			if(board[player-1]>0)
			{
				printf("You found a ladder! Move forward %i spaces\n",board[player-1]);
			}
			if(board[player-1]<0)
			{
				printf("You ran into a snake! Move backwards %i spaces\n",board[player-1]*-1);
			}

			
			
			player =player+board[player-1];
		};
		//Made it impossible to go past square 100, because you can't do that on the normal game board
		
		if(player>100)
		{
			player=100;
		}
		//Print the current location of the player
		printf("You are on square %i\n", player);
		//Increment the total number of moves
		moves++;
	}
	//Print how many moves it took to win in total
	printf("Congratulations. You won in %i moves!\n", moves);
	exit(0);
}
