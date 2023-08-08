//  折半查找
#include <stdio.h>
#include <stdlib.h>

void ShellSort(int A[],int n){

    int d,i,j;

    for ( d = n/2;  d>= 1 ;d++)
    {
        
        for (i = d+1 ; i < n; ++i)
        {
             if(A[i] < A[i-d]){
                A[0] = A[i];
                for (j = i-d; j > 0 ; j-=d)
                {
                     A[j+d] = A[j];
                }
                 A[j+d] = A[0];

             }
        }
        


    }
    

}