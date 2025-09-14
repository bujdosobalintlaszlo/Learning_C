#include<studio.h>
//we can force the program to only be able to read a value with print(const char *C)
void print(char *C){
    //here you can modify an element
    C[0] = 'B';
    while (*C != '\0')
    {
        printf("%c",C[i]);
        ++C;
    }
    printf("\n");
}

int main(){
    char C[20] = "Hello"
    //char C* = "Hello"; //string gets storedas compile time constant. You CANT MODIFY THIS like C[5]
    print(C);
}