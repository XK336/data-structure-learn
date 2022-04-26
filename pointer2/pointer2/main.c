//
//  main.c
//  pointer2
//
//  Created by xike on 2021/11/21.
//

#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
int compare(int x,int y){
    return (x-y);
}

int absolute_compare(int x, int y){
    int A=abs(x);
    int B=abs(y);
    return A-B ;
}

void BubbleSort(int* A,int n,int (*compare)(int,int)){
    int i,j,temp;
    for (i =0;i <n; i++){//compare n times, the array will be a tring of number from small to big
        for (j=0; j<n-1; j++){//compare [j] with [j+1] in array to get biggest number in                      //last of array
            if (compare (A[j],A [j+1]) > 0){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}
int main(void) {
    int i, A[] ={-3,2,66,-45,6,43};
    //int (*p)(int,int) = compare;
    BubbleSort(A,6,compare);
    for (i =0;i<6;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
    printf("\n");
    BubbleSort(A,6,absolute_compare);
    printf("sort by absolute value:\n");
    for (i =0;i<6;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}
