#include<stdio.h>

#define MaxSize 10 

typedef struct 
{
    int data[MaxSize];

    int length;
} SqList;

// 静态初始化，默认会分配内存空间
void InitList(SqList &L){
    for (int i = 0; i < MaxSize; i++)
    {
        L.data[i] = 0;
    }

    L.length = 0;
}
bool pushEle(SqList &L,int e){
   if(L.length >= MaxSize){
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





