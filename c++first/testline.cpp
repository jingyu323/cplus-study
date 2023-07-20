#include <stdio.h>
#include "testline.h"



void InitListArr(SqlList &L) {
  L.length =10;
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
    
    printf("hello world");
    return 0;
}
