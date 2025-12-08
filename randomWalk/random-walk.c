#include<SDL2/SDL.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, const char *argv[]){
	int num_agents;
	if(argc ==1 ){
		num_agents = 5;
	}else if(argc == 2){
		num_agents = atoi(argc[1]);
	}else{
		fprintf(stderr,"Usage: %s <number of agents>",args[0]);
	}

}
