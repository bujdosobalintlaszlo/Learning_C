/*Arrays are always passed to functions by refference*/
#include<studio.h>
//the param could be char C[] but the compiler iterprets it like char *C
void print(char *C){
    int i;
    i = 0;
    //Since we only know the base address we can go till we find a null character which idicates the end of the stirng
    // can be *(C + i) too
    /*
    while (C[i] != '\0')
    {
        printf("%c",C[i]);
        ++i;
    }
    */
    //we can also leave out i
    while (*C != '\0')
    {
        printf("%c",C[i]);
        ++C;
    }
    printf("\n");
}

int main(){
    char C[20] = "Hello";
    print(C);
}