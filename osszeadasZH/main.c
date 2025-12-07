#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* plus(char* num1, char* num2);
char* sum(char* arr[],int length);
void trim(char *num);
int main(){
	/*
	char *res=plus("568","1597");
	printf("%s",res);
	*/
	char *nums[] = {"1","2","3","11","100","1597"};
	int length = sizeof(nums)/sizeof(nums[0]); 
	char *sumOfnums=sum(nums,length);
	printf("%s\n",sumOfnums);

	char trimTest[]="00000090";
	trim(trimTest);
	printf("%s\n",trimTest);
}

char* plus(char* num1, char* num2){
	int num1L = strlen(num1);
	int num2L = strlen(num2);
	//null terminator + ha tizes atlepes van a legnagyobb helyierteken
	int maxLen = (num1L > num2L ? num1L : num2L)+2;
	
	char *res = (char*)malloc(maxLen);
	if(!res){
		fprintf(stderr,"sikertelen memoriafoglalas");
		exit(1);
	}

	int i = num1L -1;
	int j = num2L -1;
	int k = maxLen - 2;
	res[maxLen-1]='\0';
	int carry =0;
	while(i>=0 || j>=0 || carry){
		int dig1 = (i >=0 ? num1[i] - '0' : 0);
		int dig2 = (j >=0 ? num2[j] - '0' : 0);

		int sum = dig1+dig2 + carry;
		//ezzel az intet vissza tudom valtani charra
		res[k]=(sum%10)+ '0';
		carry= sum /10;
		--i;
		--j;
		--k;
	}
	return res + (k+1);
}

char* sum(char* arr[],int length){
	if(length <=1){
		return arr[0];
	}
	char * current=arr[0];
	for(int i=1;i<length;++i){
		current = plus(arr[i],current);
	}	
	return current;
}

void trim(char *num){
	int i=0;

	while(num[i] =='0' && num[i+1] != '\0'){
		++i;
	}

	if(i>0){
		int j=0;
		while(num[i] != '\0'){
			num[j] = num[i];
			++j;
			++i;
		}
		num[j]='\0';
	}

}
