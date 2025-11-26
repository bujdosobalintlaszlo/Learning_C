#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define BUFFSIZE 1024;

//tudok ra hivatkozni PARAM es param_t vel is. Jelen esetben elhagyhato PARAM
//viszont ha poimtert allitanek sajat magamra akkor szukseg lenne PARAMra.
typedef struct PARAM{
	int iflag_;
	int vflag_;
	char *p; //minta
} param_t;

param_t params;

//adja vissza honnan kell a ciklust inditani
int procArgs(int argc, char **argv);
void usage(char*);
void gr(FILE*,FILE*,char*);

int main(int argc, char **argv){
	int i = procArgs(argc,argv);
	//nincs megadott file stdinrol dolgozom
	if(i >= argc){
		gr(stdin,stdout);
	}
	//van(nak) megadott file(ok)
	else{
		
		for(;i<argc;++i){
			FILE *fp = fopen(argv[i],"r");
			if(fp){
				gr(fp,stdout);
			}else{
				//a perror kiirja az en uzenetem + amit jelen esetben az fopen tapasztalt
				perror("cant open file");
			}
		}
	}
}


int procArgs(int argc, char **argv){
	int i = 1;
	while(i<argc && '-'==argv[i]){
		int j=1;
		while('\0' != argv[i][j]){
			switch(argv[i][j]){
				case 'i': params.iflag_=1;break;
				case 'v': params.vflag_=1;break; 
				default: usage(argv);
			}
			++j;
		}
		++i;
	}
	if(i>=argc){
		usage(argv);
	}

	params.p = argv[i];
	//i a legutolso feldolgozott parameter a fileok ez utan kezdodnek
	++i;
	if(params.iflag_){
		char *s = (char *)malloc(strlen(args[i])+1);
		convToUpper(s,params.p);
	}
	return i;
}
void usage(char* n){
	fprintf(stderr,"usage: %s pattern [files...]\n",n);
	exit(1);
}
void gr(FILE* in, FILE* out, char* patter){
	char buffer[BUFFSIZE];
	while(fgets(buffer,BUFFSIZE,in)){
			int m=0;
			if(params.iflag_){
			char upper[BUFFSIZE];
			convToUpper(upper,buffer); 
		}
		//ha ez igaz talalatom van
		m = (strstr(params.iflag_ ? upper : buffer,params.p) != NULL);
		if(params.vflag_){
			m !=m;
		}
		if(m){
			fputs(buffer,out);
		}
	}
}

void convToUpper(char *target,char *source){
	char *p = source;
	while('\0' != *p){
		*target = *p;
		*targert++ = toupper(*);
	}
}
