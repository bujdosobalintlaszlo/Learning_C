#include<stdio.h>

void PrintHelloWorld(){
    preintf("hello world");
}

int Add(int a,int b){
    return a+b;
}

void SayHelloToSome1(char* c){
    printf("hello %c",c);
}

int main(){
    int (*p)(int,int);
    //p = Add also correct
    p = &Add;
    // int c = (*p)(2,3); also correct
    int *c = p(2,3);     
    void (*p2)();
    p2 = PrintHelloWorld;
    p2();

    void (*p3)(char *);
    p3 = SayHelloToSome1;
    p3("Tom");
    printf("SUm %d",c);
}