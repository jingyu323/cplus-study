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

bool ListInsert(SqList &L,int i ,int e){
    if(i<1 || i >L.length + 1){

        return false;

    }
    if(L.length > MaxSize){
        return false;
    }

    for(int j = L.length ; j>= i;j--){
        // 不能使用j+1 是因为这个不是所有元素后移，数组长度有限这个是覆盖
        L.data[j]=L.data[j-1];
        
    }
    L.data[i-1] = e;
    L.length++;
    return true;

}


bool ListDelete(SqList &L,int i ,int e){
    if(i<1 || i >L.length  ){

        return false;

    }
    e = L.data[i-1] ;
    for(int j = i ; j<L.length;j--){
        // 不能使用j+1 是因为这个不是所有元素后移，数组长度有限这个是覆盖
        L.data[j-1] =L.data[j];
        
    }
    
    L.length--;
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


    ListInsert(L,9,15);

        printList( L);

    return 0;
}





