#include<studio.h>
#include<string.h>
int main(){
    char C[5];
    c[0] = 'J';
    c[1] = 'o';
    c[2] = 'h';
    c[3] = 'n';
    // \0 is a null character
    c[4] = '\0';
    intl en = strlen(C);

    //We can declare the sam in 1 go, and the null termination is implicit here.
    char C2[5] - "John";

    //If we declare it like this it will result in an array which has the length 5 byte since we have the null character but the length with strlen will be 4 since we dont acknowledge the null character.
    char C3[] ="JOhn";
    //char C[4] = "JOhn" will give us compalation error since we dont have space for the null character.

    //we can declare it this way too
    char C4[5] = {'J','o','h','n','\n'} 
    //want to print a string %s
    princtf("%s",C);
}