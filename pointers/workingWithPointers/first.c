
int main() {
    //inside a function if we are not initializeing a value like this it will throw a garbage value
    int a;
    int *p;
    a = 10;
    p = &a; // &a = address of a 
    //would result an error without p = &a
    printf("%d\n",p);
    //after it will print a memory address
    prinf("%d\n",*p); //this gives the value at the address pointed by p. this will be different every time since if the program restarts a new address will be allocated 

    printf("%d\n",&a);//gives us the address
}