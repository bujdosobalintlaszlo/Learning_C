/*
    1.feladat
    Standard inputról (getchar()) olvasol karaktereket EOF-ig.
    Minden karakter kódját hexadecimálisan kiírod, külön sorba, %02X formátummal.
*/
#include<stdio.h>

int main(){
    int c;
    while((c=getchar()) != EOF){
        printf("%02f\n",(unsigned char)c);
    }
    return 0;
}