#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFFSIZE 80
#define PROMT "PB> "
struct Command{
	char *name;
	int npar;
	void (*func)();
};
typedef struct Command command_t;

int parseInput(char *,char**,char **);
void list(void);
void help(void);
void add(char *name, char* phone);
void del(char *name);
void print(char *name);

command_t commands[] = { {"list",0,list},{"add",2,add},{"print",1,print},{"help",0,help},{"del",1,del}};
int ncommands = sizeof(commands) / sizeof(commands[0]);
int main()
{
	char buffer[BUFFSIZE];
	printf(PROMT);
	while(fgets(buffer,BUFFSIZE,stdin))
	{
		int com;
		char *par1;
		char *par2;
		if(-1 != (com =parseInput(buffer,&par1,&par2)))
		{
			switch (commands[com].npar){
				case 0:
					commands[com].func();
					break;
				case 1:
					commands[com].func(par1);
					break;
				case 2:
					commands[com].func(par1,par2);
					break;
				default:
					printf("Not implemented yet...");
					break;
			}
		}
		printf(PROMT);
	}
	return 0;
}

int parseInput(char *buffer,char **p1,char **p2)
{
	//beolv,felsorolt karaktereket atlepi
	char *command=strtok(buffer," \n\t");
	char *par1=strtok(NULL," \n\t");
	char *par2=strtok(NULL,"\n\t");

	if(command){
		for(int i=0;i<ncommands;++i){
			int pars = (NULL != par1) + (NULL != par2);
			if(0 == strcmp(commands[i].name,command)){
				if(commands[i].npar == pars)
				{
					*p1 = *par1;
					*p2 = *par2;
					return i;
				}else{
					fprintf(stderr,"%s requires %d parameters.",commands[i].name,commands[i].npar);
					return -1;
				}
			}
		}
		printf("command: %s\n",command);
		fprintf(stderr,"%s: command not found\n",command);
	}
	return -1;
}

void help(void){
	for(int i=0;i<ncommands;++i){
		int n = commands[i].npar;
		printf("%s %s %s\n",commands[i].name,n > 0 ? "NAME" : "", n >1?"PHONE":"");
	}
	printf("list\n");
}

void list(void){
	printf("list\n");

}
void add(char *name, char* phone){
	printf("add(%s,%s)\n",name,phone);
}
void del(char *name){
	printf("print(%s)\n",name);
}
void print(char *name){
	printf("del(%s,%s)\n",name);
}
