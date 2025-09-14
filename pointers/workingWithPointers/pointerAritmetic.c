
int main() {
    int a;
    int *p;
    a = 10;
    p = &a;
    prinf("P is %d\n",p); // examp.: p is 2002
    print("size of an integer:%d\n",sizeof(int));
     //in this case p will be 2006, because incrementing it by 1 will take us to another integer. An integer is size of 4 bytes so the next one after 2002 will be 2006.
    prinf("P is %d\n",p + 1);

    //this will give a garbage value, cause we dont have an integer allocated to this memory address. In c you can reach any address and can lead to unvanted behaviour in
    //our program
     prinf("P is %d\n",*(p + 1));
}