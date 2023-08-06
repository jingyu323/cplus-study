
//  折半查找
#include <stdio.h>
#include <stdlib.h>

void InsertSort(int A[],int n){
    int i,j,temp;

    for (  i = 1; i < n; i++)
    {
       if(A[i] < A[i-1]){
          temp = A[i];
          for (j  = i-1;  j>= 0; --j)
          {
             A[j+1] =A[j];
          }
           A[j+1] = temp;

       }
    }
    

}


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
