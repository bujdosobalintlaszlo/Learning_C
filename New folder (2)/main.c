#include<stdio.h>
int SumOfTwoInts(int* arr,int arrL,int num){
    
    for(int i=0;i<arrL-1;++i){
        for(int j=i+1;j<arrL;++j){
            if(arr[i] - arr[j] == 0){
                return 1;
            }
        }
    }
    return 0;
}