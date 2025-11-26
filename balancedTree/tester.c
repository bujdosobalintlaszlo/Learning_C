#include<stdio.h>
#include<stdlib.h>
#define MAX_LENGTH 100000

int main(int argc, char **argv){
	int max = MAX_LENGTH;
	if(argc > 1){
		//atoi megprobalja int parseolni a stringet
		int m = atoi(argv[1]);
		if(m>0){
			max=m;
		}
	}
	for(int i=0;i<max;++i){
		printf("%d ",rand());
	}
}
