
int compare(const void* a,const void* b){
    int A = *((int*)a); //typecasting to int* and getting the value
    int B = *((int*)b);
    //B-A desc.
    return A-B; 
}

int main(){
    int i, A[] = {-1,3,-34,4,8,9,90};
    qsort(A,7,sizeof(int),compare);
    for(i=0;i<7;++i) printf("%d",A[i]);
}