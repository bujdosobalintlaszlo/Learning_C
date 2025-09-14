#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int compare(int a,int b){
    //if first if statement returns 1 it will be asc.
    if(a >b) return -1; // int this case this will ne desc.
    else return 1;

}

int absoluteCompare(int a,int b){
    if(abs(a) > abs(b) > 0) return 1;
    else return -1;
}


void BubbleSort(int *arr,int n, int (*compare)(int,int)){
    //bubblesort
    int i,j,temp;
    for(i=0;i<n;++i){
        for(j = 0; j<n -1;++j){
            if(comapare(arr[j] > arr[j+1]) > 0){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

int main(){
    //I want to sort them in increasing order
    int i, arr[] = {3,4,5,5,-1,3,-2};
    BubbleSort(arr,7,absoluteCompare);
    for(i=0;i<7;++i) printf("%d",arr[i]);
}

