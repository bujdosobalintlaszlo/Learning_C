
int main() {
    int a;
    int *p;
    a = 10;
    p = &a; 
    prinf("before %d\n",a);
    *p =12; // value at address so value at p is now 12. Its called dereferencing 
    prinf("after %d\n",a);
}