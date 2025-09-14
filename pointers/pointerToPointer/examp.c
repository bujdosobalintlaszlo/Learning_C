int main(){
    int x = 5;
    int* p =&x;
    *p = 6;
    int** q = &p;
    int*** r = &q;

    printf("%d\n",p); //6
    printf("%d\n",*q); //memory address where p is stored lets say 225 as an examo
    printf("%d\n",*(*q)); //now we are first dereferencing q which is 225 based on our example, after this we are dereferencing this which will be 6 since it points to p. **p is the same
    printf("%d\n",*(*r));//225
    printf("%d\n",*(*(*r)));//6
}