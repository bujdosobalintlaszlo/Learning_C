#include<stdio.h>
#include<string.h>
#define HEIGHT 6
#define WIDTH 7

int map[HEIGHT][WIDTH];
void init();
void printTable();
int submit(int playerId,char position);
int evaluate();
void game(char* game);
int main()
{
	char* games[5] = {"“ABDCAGEEE","ABDCAEEEEEEFFFAC","ABDCAEEEEEEFFG","AAAAAAABBBBBBBCCCCCCCDDDDDDDEEEEEEEFFFFFFFGGGGGG"};
	for(int i=0;i<5;++i)
	{
		game(games[i]);
	}
	return 0;
}

void init()
{
	for(int i=0;i<HEIGHT;++i)
	{
		for(int j=0;j<WIDTH;++j)
		{
			map[i][j]=0;
		}
	}
}

void printTable()
{
	for(int i=0;i<HEIGHT;++i)
	{
		for(int j=0;j<WIDTH;++j)
		{
			printf("%d",map[i][j]);
		}
		printf("\n");
	}
}


int submit(int playerId,char position)
{
    int y = tolower(position) - 'a';
    if(y >= WIDTH || y < 0) return 0;

    int x = HEIGHT - 1;
    while(x >= 0 && map[x][y] != 0) --x;

    if(x < 0) return 0;

    map[x][y] = playerId;
    return 1;
}


int evaluate()
{
	int merC = 0;
	for (int i = 0; i < WIDTH; ++i)
	{
	    int prev = 0;
	    merC = 1;

	    for (int j = 0; j < HEIGHT; ++j)
	    {
		int curr = map[j][i];

		if (curr != 0 && curr == prev) {
		    merC++;
		} else {
		    merC = 1;
		}

		if (merC >= 3 && curr != 0) {
		    return curr;
		}

		prev = curr;
	    }
	}

	//vizszintes
	int merL = 0;
	for (int i = 0; i < HEIGHT; ++i)
	{
	    int prev = 0;
	    merL = 1;

	    for (int j = 0; j < WIDTH; ++j)
	    {
		int curr = map[i][j];

		if (curr != 0 && curr == prev) {
		    merL++;
		} else {
		    merL = 1;
		}

		if (merL >= 3 && curr != 0) {
		    return curr;
		}
		prev = curr;
	    }
	}
	return 0;
}

void game(char* game)
{
    init();
    int incSteps = 0;
    int winnerF = 0;

    for(int i=0; game[i]!='\0' && incSteps < HEIGHT * WIDTH; ++i)
    {
        int currPlayerId = (i % 2 == 0) ? 1 : 2;

        if(submit(currPlayerId, game[i]))
        {
            printTable();
            printf("\n");

            int winner = evaluate();
            if(winner)
            {
                printf("Player %d wins!\n", winner);
                winnerF = winner;
                break;
            }
        }
        else
        {
            fprintf(stderr, "Illegal move: %c\n", game[i]);
            incSteps++;
        }
    }

    if(!winnerF)
        printf("Draw with %d invalid steps\n", incSteps);
}


