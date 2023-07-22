#include<stdio.h>
#include <stdlib.h>

#define InitSize 10 

typedef struct 
{
    int *data;    // 指针传递真是值，不是副本
    int length;
    int  MaxSize;
} SqList;

// 动态初始化手动分配空间
void InitList(SqList &L){
    int *p = L.data;
    L.data =  (int *) malloc((InitSize )  * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
     
}

void IncreaseSize(SqList &L ,int len){
    int *p = L.data;
    L.data =  (int *) malloc((L.MaxSize + len)  * sizeof(int));
    for (int i = 0; i < L.length; i++)
    {
      /* code */

      L.data[i] = p[i];
 
    }
    L.MaxSize = L.MaxSize + len;
    printf("%d",L.MaxSize);
    free(p);
    
}

 bool pushEle(SqList &L,int e){
   if(L.length >= L.MaxSize){
         return false;
   }
   L.data[L.length] = e;
   L.length = L.length +1;
   return true;

}

void   printList(SqList L){
        for (int i = 0; i < L.length; i++)
    {
        /* code */
        printf("data[%d]=%d\n",i,L.data[i]);
    }

}

int main(int argc, char const *argv[])
{
    SqList L;

    InitList(L);    
    printList( L);

    printf("===============");
    IncreaseSize(L,8);
     pushEle(L,7);
    pushEle(L,6);
    pushEle(L,3);
    pushEle(L,3);
    pushEle(L,3);
    pushEle(L,3);
    pushEle(L,3);
    pushEle(L,3);
    pushEle(L,3);
    pushEle(L,13);
    pushEle(L,13);

    printList( L);
    return 0;
}





