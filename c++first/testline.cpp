#include <stdio.h>
#include <stdlib.h>
#include "testline.h"



void InitListArr(SqlList &L) {
  
  L.data = (int *) malloc(MaxSize * sizeof(int));
  L.length =  0;
  L.maxSize = MaxSize;
}

void IncreaseSize(SqlList &L,int len){
    int *p = L.data;
    L.data =  (int *) malloc((L.maxSize + len)  * sizeof(int));


    for (int i = 0; i < L.length; i++)
    {
      /* code */

      L.data[i] = p[i];
 
    }
    L.maxSize = L.maxSize + len;
    printf("%d",L.maxSize);
    free(p);
    

}


int main(int argc, char const *argv[])
{
    
    SqlList L;
    InitListArr(L);
    for (int i = 0; i < L.length; i++)
    {
        /* code */
        printf("data[%d]=%d\n",i,L.data[i]);
    }
    

    IncreaseSize(L,5);
    for (int i = 0; i < L.length; i++)
    {
        /* code */
        printf("data[%d]=%d\n",i,L.data[i]);
    }
    

    printf("hello world");
    return 0;
}
