int main(){
    //00000000 00000000 00000100 00000001 this is the binray rep. of the int a = 1025.The bit which tells us the -/+ is called sign bit (31. bit)
    int a = 1025;
    int *p;
    p = &a;
    printf("size of an integer %d",sizeof(int));
    printf("Address = %d, value = %d",p,*p);
    /*
        it would result in a compiler error 
        char *p0;
        p0 = p;
    */
   //so we do
   char *p0;
   p0 = (char)p; //typecasting
   printf("size of an integer %d",sizeof(int));
   //the value will be 1. And it is beacuse a char takes 1 byte of memory space while an int takes 4. If we take a look at the representation of 1025 in binary:
   //00000000 00000000 00000100 00000001 than we can see that in the first byte we have the value 1 (2^0).
   printf("Address = %d, value = %d",p0,*p0);
}