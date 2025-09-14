
int main() {
    int a;
    int *p;
    int b = 10;
    a = 10;
    p = &a; 
    prinf("Address of P is %d\n",p);
    prinf("Value of P is %d\n",*p);
    *p = b; //in this case the address of p wont change unless we are manualy doing it. Here we are basicly putting in the address of a the value that b has.
    prinf("after %d\n",a);
    prinf("Address of P is %d\n",p);
    prinf("Value of P is %d\n",*p);

    //We can also declare a pointer like this
    int c = 12;
    int *p2 = &c;
    //we can also declare a pointer like this
    int* p3 = &b;
}