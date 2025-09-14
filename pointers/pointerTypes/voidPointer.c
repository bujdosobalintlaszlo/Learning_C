int main(){
    int a = 1025;
    int* p;
    p = &a;
    printf("size of an integer %d",sizeof(int));
    printf("Address = %d, value = %d",p,*p);

    //void pointer - generic pointer
    void* p0;
    // we dont need (void*)p
    p0 = p;
    //this pointer type is not mapped to a particular datatype, we can dereference it. So we cant *p0, also we cant do p0 +1 in this case for example. We can only print the memory address
    printf("Address = %d",p0);
}