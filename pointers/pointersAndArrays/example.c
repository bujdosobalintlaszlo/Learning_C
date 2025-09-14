#include <stdio.h>
int main(){
    int A[] = {1,2,3,4,5};
    //printing the first address of the array
    printf("%d\n",A);
    printf("%d\n",&A[0]);    
    //first elements value
    printf("%d\n",A[0]);
    printf("%d\n",*A); 
    //printing every values with their addresses
    int i;
    int* p = A;
    //A++ is invalid comp. err.
    //once we assign A to *p ++p is possible 
    for(i =0;i<5;++i){
         printf("%d\n",A+i);
        printf("%d\n",&A[i]);    
        printf("%d\n",A[i]);
        printf("%d\n",*(A+i)); 
    }
}