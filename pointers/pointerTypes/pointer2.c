int main(){
    int a = 1025;
    int *p;
    p = &a;
    printf("size of an integer %d",sizeof(int));
    printf("Address = %d, value = %d",p,*p);
    printf("Address = %d, value = %d",p+1,*(p+1)); //as we know from prev examples it will take us 4 bytes further, *(p+1) gives us garbage value
    char *p0;
    p0 = (char)p; //typecasting
    printf("size of an integer %d",sizeof(int));
    printf("Address = %d, value = %d",p0+1,*(p0+1)); // it only takes us 1 bytes further from the original and gives us 4 as a value
    /*
        Again 00000000 00000000 00000100 00000001 we will end up at 2. byte which is 00000100 where we have 1* 2^2 = 4
    */
}