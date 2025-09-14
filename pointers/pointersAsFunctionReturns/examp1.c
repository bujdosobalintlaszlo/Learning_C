#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the size of the array\n");
    scanf("%d", &n);

    int *A = (int*)malloc(n * sizeof(int));
    //int *A = calloc(n,sizeof(int)); automaticly fills with 0 while malloc doesnt (junk)
    for (int i = 0; i < n; i++) {
        A[i] = i + 1;
    }

    for (int i = 0; i < n; ++i) {
        printf("%d\n", A[i]);
    }
    /*
    free(A); // Don't forget to free the memory!
    A = NULL; //after clearing the memory set the pointer to null
    */
    int *A = realloc(A,2*n*sizeof(int)); // equivalent of free(A)
    int *B = realloc(NULL,2*n*sizeof(int)); // equivalent of malloc
    return 0;
}
