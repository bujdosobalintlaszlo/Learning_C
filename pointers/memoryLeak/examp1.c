#include<time.h>
/*
NO memory leak C is stored on the stack
void Play(int bet){
    char C[3] = {'K','J','Q'};
    printf("SHuffling...\n");
    srand(time(NULL)); //seding random number generator
    int i;
    for(i=0;i<5;++i){
        int x = rand() % 3;
        int y = rand() % 3;
        int temp = C[x];
        C[x] = C[y];
        C[y] = temp;
    }
        int playerGuess;
    printf("Whats the position of the Queen? (options are: 0,1,2)");
    scanf("%d",&playerGuess);
    if(C[playerGuess] = 'Q'){
        balance += 3*bet;
        printf("You guessed correctly! Your balance is $ %d. Positions were / %c %c %c/",balance,C[0],C[1],C[2]);
    }else{
        balance += 3*bet;
        printf("You guessed incorrectly! Your balance is $ %d. Positions were / %c %c %c/",balance,C[0],C[1],C[2]);
    }
}
*/
//in this case the array C is stored in the heap, and memory usage grows
void Play(int bet){
    char C[3] = malloc(3*sizeof(char));
    C[0] = 'K'; C[1] = 'J'; C[2] = 'Q';
    printf("Shuffling...\n");
    srand(time(NULL)); //seding random number generator
    int i;
    for(i=0;i<5;++i){
        int x = rand() % 3;
        int y = rand() % 3;
        int temp = C[x];
        C[x] = C[y];
        C[y] = temp;
    }
    int playerGuess;
    printf("Whats the position of the Queen? (options are: 0,1,2)");
    scanf("%d",&playerGuess);
    if(C[playerGuess] = 'Q'){
        balance += 3*bet;
        printf("You guessed correctly! Your balance is $ %d. Positions were / %c %c %c/",balance,C[0],C[1],C[2]);
    }else{
        balance += 3*bet;
        printf("You guessed incorrectly! Your balance is $ %d. Positions were / %c %c %c/",balance,C[0],C[1],C[2]);
    }
    free(C);
}
    int balance = 100;
int main(){
    int bet;
    printf("Welcome to the game! Place your bet!");
    printf("Total cash: %d",balance);
    while (balance > 0)
    {
        printf("Whats your bet? $");
        scanf("%d",&bet);
        if(bet <= 0 || bet > balance) break;
        Play(bet);
        /* code */
    }
    printf("\n********************************************\n");
    
}