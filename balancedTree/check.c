#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int main(){
	//binarisan legelso biten 1 tobbi 0 lenne a legkisebb int
	int prev = INT_MIN;
	int n;
	while(1==scanf("%d",&n)){
		if(prev>n){
			fprintf(stderr,"Inversion: %d",prev.n);
			exit(1);
		}
		prev=n;
	}
}
