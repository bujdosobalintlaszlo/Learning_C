#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define BUFFSIZE 16
void print(unsigned char *,int);
void hd(FILE *);
int main(int argc,char **argv){
	if(argc == 1){
		hd(stdin);
		//printf("We are working from stdin");
	}else{
		for(int i=1;i<argc;++i){
			FILE *fp = fopen(argv[i],"r");
			if(NULL == fp){
				fprintf(stderr,"%s Cant open %s for read\n",argv[0],argv[i]);
			}else{
				//printf("We are working from %s\n",argv[i]);
				hd(fp);
				fclose(fp);
			}
		}
	}
	return 0;
}

void hd(FILE *fp){
	//printf("hd has been called");
	char buffer[BUFFSIZE];
	//igy tudjuk felismerni az EOF-t
	int ch;
	int cnt = 0;
	while(EOF != (ch=fgetc(fp))){
		buffer[cnt++]=ch;
		if(cnt == BUFFSIZE){
			//cnt itt mindig buffsize
			print(buffer,cnt);
			cnt=0;
		}
	}
	//ha buffernek a hossza nem 16 tobbszorose mindig marad bent a bufferben karakter
	//itt cnt nem mindig buffsize
	if(cnt >0){
		print(buffer,cnt);
	}
}
/*binaris fileban elofordulhat ha nem kezeljuk megfeleloen oket "csunya karaktereket ir ki" ezek az olvashatatlan karakterek. ez abbol adodik hogy egy char -127tol 128 ig van reprezentalva, mig az unsigned-ek 0 255-ig nincsenek negativak. ez ha nincs meghatarozva gepfuggo tehat ha csak char-t irunk pl. inteles gepen elojeles lesz elonyben reszesitve es az ascii abrazolas emiatt szetesik*/
void print(unsigned char *buffer,int cnt){
	static int address = 0;
	//0 padelessel 8 hosszan kiirva
	printf("%08x | ",address);
	for(int i=0;i<cnt;++i){
		printf(" %02x",buffer[i]);
	}
	for(int i=cnt;i<BUFFSIZE;++i){
		printf("   ");
	}
	printf(" | ");
	for(int i=0; i<cnt;++i){
		putchar(isgraph(buffer[i]) ? buffer[i] :'.');
	}
	putchar('\n');
	address+=BUFFSIZE;
}
