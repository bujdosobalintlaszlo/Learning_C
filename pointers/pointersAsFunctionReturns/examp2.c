#include<stdio.h>
#include<stdlib.h>

int Add(int a,int b){
    printf("a in Add func.: %d",&a);
    int c = a+ b;
    return c;
}

int AddWithPointer(int* a,int* b){
    int c = (*a) + (*b);
    printf("x's memory address in add (with pointers in params): %d",&a);
    return c;
}

//returns a pointer (int*)
int* AddRetPointer(int* a,int* b){
    int c = (*a) + (*b);
    return &c;
}


void PrintHelloWorld(){
    printf("Hello Wrld");
}

int main(){
    int a = 3, b=2;
    /*
    int x = 2,y=5;
    //call by value
    // the value of a and b are copied to a and b in Add
    //you can even veryfy it very simply
    //here you can check if the memory address of local a and Add's a arent the same 
    int z = Add(a,b); 
    printf("a in main: %d",&a);
    //here x and a's memory address will be the same since we are passing it's address
    int g = AddWithPointer(&x,&y); 
    printf("x's address in main: %d",&x);
    */

    int* ptr = AddRetPointer(&a,&b);
    PrintHelloWorld();
    //it wont work like this
    printf("Sum = %d\n",*ptr);

}