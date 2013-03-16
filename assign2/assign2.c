#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
void place3(int (*boards)[10][10])
{	
	//0 for facing downwards, 1 for facing right, 2 for facing down, 3 for facing left
	int orientation=rand()%4;
	for (int i=0;i<100;i++)
	{
		//To ensure randomness, I found that the first few numbers were always the same
		orientation=rand()%4;
	};
	int xpos=rand()%10+1;
	int ypos=rand()%10+1;
	bool placed=false;
	
	while (placed==false)
	{
		xpos=rand()%10;
		ypos=rand()%10;
		orientation=rand()%4;
		if ((*boards)[xpos][ypos]!=0)
			continue;
		else if(orientation==0)
		{
			if (ypos-1<0||ypos-2<0)
				continue;
			if ((*boards)[xpos][ypos-1]==0&&(*boards)[xpos][ypos-2]==0)
			{
				(*boards)[xpos][ypos]=4;
				(*boards)[xpos][ypos-1]=4;
				(*boards)[xpos][ypos-2]=4;
				placed=true;
			}
		}
		else if(orientation==1)
		{
			if (xpos+1>9||xpos+2>9)
				continue;
			if ((*boards)[xpos+1][ypos]==0&&(*boards)[xpos+2][ypos]==0)
			{
				(*boards)[xpos][ypos]=4;
				(*boards)[xpos+1][ypos]=4;
				(*boards)[xpos+2][ypos]=4;
				placed=true;
			}
		}
		else if(orientation==2)
		{
			if (ypos+1>9||ypos+2>9)
				continue;
			if ((*boards)[xpos][ypos+1]==0&&(*boards)[xpos][ypos+2]==0)
			{
				(*boards)[xpos][ypos]=4;
				(*boards)[xpos][ypos+1]=4;
				(*boards)[xpos][ypos+2]=4;
				placed=true;
			}
		}
		else if(orientation==3)
		{
			if (xpos-1<0||xpos-2<0)
				continue;
			if ((*boards)[xpos-1][ypos]==0&&(*boards)[xpos-2][ypos]==0)
			{
				(*boards)[xpos][ypos]=4;
				(*boards)[xpos-1][ypos]=4;
				(*boards)[xpos-2][ypos]=4;
				placed=true;
			}
		}
	};
}void place2(int (*boards)[10][10])
{
	//0 for facing downwards, 1 for facing right, 2 for facing down, 3 for facing left
	int orientation=rand()%4;
	for (int i=0;i<100;i++)
	{
		//To ensure randomness, I found that the first few numbers were always the same
		orientation=rand()%4;
	};
	int xpos=rand()%10+1;
	int ypos=rand()%10+1;
	bool placed=false;
	
	while (placed==false)
	{
		xpos=rand()%10;
		ypos=rand()%10;
		orientation=rand()%4;
		if ((*boards)[xpos][ypos]!=0)
			continue;
		else if(orientation==0)
		{
			if (ypos-1<0)
				continue;
			if ((*boards)[xpos][ypos-1]==0)
			{
				(*boards)[xpos][ypos]=2;
				(*boards)[xpos][ypos-1]=2;
				placed=true;
			}
		}
		else if(orientation==1)
		{
			if (xpos+1>9)
				continue;
			if ((*boards)[xpos+1][ypos]==0)
			{
				(*boards)[xpos][ypos]=2;
				(*boards)[xpos+1][ypos]=2;
				placed=true;
			}
		}
		else if(orientation==2)
		{
			if (ypos+1>9)
				continue;
			if ((*boards)[xpos][ypos+1]==0)
			{
				(*boards)[xpos][ypos]=2;
				(*boards)[xpos][ypos+1]=2;
				placed=true;
			}
		}
		else if(orientation==3)
		{
			if (xpos-1<0)
				continue;
			if ((*boards)[xpos-1][ypos]==0)
			{
				(*boards)[xpos][ypos]=2;
				(*boards)[xpos-1][ypos]=2;
				placed=true;
			}
		}
	}
}
bool game(int (*boards)[10][10])
{
	for (int i=0;i<10;i++)
	{
		for (int h=0;h<10;h++)
		{
			if ((*boards)[h][i]==2||(*boards)[h][i]==4)
				return true;
		}
	}
	return false;
}
void check(int (*boards)[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int h = 0; h < 10; h++)
		{
			if ((*boards)[h][i] == 3&&(*boards)[h+1][i] == 3)
			{
				(*boards)[h][i]=6;
				(*boards)[h+1][i]=6;
			}
			else if ((*boards)[h][i] == 3&&(*boards)[h][i+1] == 3)
			{
				(*boards)[h][i]=6;
				(*boards)[h][i+1]=6;
			}
			else if ((*boards)[h][i] == 5&&(*boards)[h+1][i] == 5&&(*boards)[h+2][i] == 5)
			{
				(*boards)[h][i]=6;
				(*boards)[h+1][i]=6;
				(*boards)[h+2][i]=6;
			}
			else if ((*boards)[h][i] == 5&&(*boards)[h][i+1] == 5&&(*boards)[h][i+2] == 5)
			{
				(*boards)[h][i]=6;
				(*boards)[h][i+1]=6;
				(*boards)[h][i+2]=6;
			}
		}
	}
}
int main(void)
{
	srand(time(NULL));
	/*int i,j;
	printf("Please enter the dimmensions you would like the board to be\nX=");
	scanf("%i",&i);
	printf("\nY=");
	scanf("%i",&j);*/
	int ships = 11;
	char mode,garb,xcoord[4],ycoord[4];
	while (ships>10)
	{
		printf("Please enter how many ships you would like for there to be on the board (max 10):");
		scanf("%i%c", &ships, &garb);
	}
	while (1)
	{
		printf("Please enter mode, either t for test or g for game: ");
		scanf("%c%c",&mode,&garb);
		if (mode=='t'||mode=='g')
			break;
	}
	//0 means empty space, 1 means miss, 2 means an unhit ship of length 2, 3 means a hit ship of length 2, 4 means an unhit ship of length 3, 5 means a hit ship of length 3, 6 means a sunken ship
	int board[10][10]={0};
	for (int i=1;i<=ships;i++)
	{
		if (i%2==1)
			place3(&board);
		else
			place2(&board);
	}
	int x=0,y=0;
	if (mode=='t')
	{
		while (game(&board))
		{
			for (int i = 0; i < 10; i++)
			{
				for (int h = 0; h < 10; h++)
				{
					printf("%i",board[h][i]);
				}
				printf("\n");
			}
			printf("Please enter an X coordinate(1-10): ");
			scanf("%s%c", xcoord, &garb);
			if (xcoord[0] == *"q")
				break;
			printf("Please enter a Y coordinate(1-10): ");
			scanf("%s%c", ycoord, &garb);
			if (ycoord[0] == *"q")
				break;
			x = atoi(xcoord)-1;
			y = atoi(ycoord)-1;
			if (board[x][y] == 0)
				board[x][y] = 1;
			else if (board[x][y] == 2)
				board[x][y] = 3;
			else if (board[x][y] == 4)
				board[x][y] = 5;
			check(&board);
		}
	}
	else
	{
		while (game(&board))
		{
			for (int i = 0; i < 10; i++)
			{
				for (int h = 0; h < 10; h++)
				{
					if (board[h][i] == 0 || board[h][i] == 2 || board[h][i] == 4)
						printf(".");
					else if (board[h][i] == 1)
						printf("w");
					else if (board[h][i] == 3 || board[h][i] == 5)
						printf("r");
					else if (board[h][i] ==6)
						printf("R");
				}
				printf("\n");
			}
			printf("Please enter an X coordinate: ");
			scanf("%s%c", xcoord, &garb);
			if (xcoord[0] == *"q")
				break;
			printf("Please enter a Y coordinate: ");
			scanf("%s%c", ycoord, &garb);
			if (ycoord[0] == *"q")
				break;
			x = atoi(xcoord)-1;
			y = atoi(ycoord)-1;
			if (board[x][y] == 0)
				board[x][y] = 1;
			else if (board[x][y] == 2)
				board[x][y] = 3;
			else if (board[x][y] == 4)
				board[x][y] = 5;
			check(&board);
		}
	}
	if (game(&board)==false)
		printf("Congratulations, you won!\n");
	return 0;

}
