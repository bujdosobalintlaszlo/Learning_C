#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFFSIZE 1024;

void usage(char*);
void gr(FILE*,FILE*,char*);
int main(int argc, char **argv){
	//grep mintaja argv[1]
	
	//adott mintat a usr
	if(1==argc){
		usage(argv[0]);
	}else if(2==argc){
		//potencialis fejlesztes miatt hatekony lehet atadni a std in es outputokat is
		gr(stdin,stdout,argv[1]);
	}else{
		//2 az elso igazi filenev
		for(int i=2;i<argc;++i){
			FILE *fp = fopen(argv[i],"r");
			if(fp){
				gr(fp,stdout,argv[1]);
			}else{
				//a perror kiirja az en uzenetem + amit jelen esetben az fopen tapasztalt
				perror("cant open file");
			}
		}
	}
	return 0;
}

void usage(char* n){
	fprintf(stderr,"usage: %s pattern [files...]\n",n);
	exit(1);
}
/*
scanf egyszerubb elore formazott inputnal
scanf,fscanf nel meg lehet adni max hany karaktert olvasson be
soronkenti beolvasasnal fgets
 */
void gr(FILE* in, FILE* out, char* patter){
	char buffer[BUFFSIZE];
	while(fgets(buffer,BUFFSIZE-1,in)){
		//azt keressuk, hogy szerepel-e pattern bufferben (substring)
		//ha talal a talalat elejere mutato pointert ad amugy nullptr
		if(strstr(buffer,pattern)){
			//sor kiiratas
			fputs(buffer,out);
		}
	}
}
