#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
	srand(time(NULL)); //initialization
	for(int i=0;i<10;++i){
		int rand_val = 1+rand()%100;
		printf("%d\n",rand_val);
	}
	return 0;
}

