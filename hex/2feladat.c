#include<stdio.h>
#define MAX_SIZE 16

/*
    FONTOS unsigned char-t hasznalni mert byte pontosan tarol.
    unsigned char - egy byte pontos reprezentacioja
*/

void printLine(unsigned char *buffer,int count){
    for(int i=0; i<count;++i){
        printf("%02x ",buffer[i]);
    }
    printf("\n");
}

int main(){
    unsigned char buffer[MAX_SIZE];
    int count =0;
    int c;

    while((c = getchar()) != EOF){
        buffer[count++] = (unsigned char)c;

        //ha megtelik a 16 hosszu tomb helye 
        if(count == MAX_SIZE){
            printLine(buffer,count);
            count =0;
        }
    }

    // ha a vegen maradtak karakterek, azokat is kiírjuk
    if(count > 0){
        printLine(buffer,count);
    }
    return 0;
}