#include<stdio.h>
#include <stdlib.h>
 
#define MaxSize 10
// 顺序栈
typedef struct  Node
{
    int data[MaxSize];    // 指针传递真是值，不是副本
          
    int  top;
} SeqStack ;


bool InitSeqStack(SeqStack &L){
    
    L.top = -1;
    return true;
}

bool Empty(SeqStack L ){
    if(L.top == -1){
         return true;
    }
    return false;
}

bool Push(SeqStack &L,int  e){
    if(L.top == MaxSize-1){
        return false;
    }

    L.top = L.top +1;
    L.data[L.top]  = e;
    return true;
    
}

bool Pop(SeqStack &L,int  &e){
    if(L.top == -1){
        return false;
    }
    e= L.data[L.top];
    L.top = L.top -1;
    return true;
}


bool GetTop(SeqStack L,int  &e){
    if(L.top == -1){
        return false;
    }
    e= L.data[L.top];
    return true;
}


// 前向遍历
void printAllNodePreRead(SeqStack L){
    int len = L.top;

    for (int i = 0; i <= len; i++)
    {
         printf("data[%d]=%d\n",i,L.data[i]);
    }

}



int main(int argc, char const *argv[])
{

    SeqStack s;

    InitSeqStack(s);

    Push(s,8);
    Push(s,2);
    Push(s,3);
    Push(s,4);
    
    printAllNodePreRead(s);

    int res;

    bool popres = Pop(s,res);

    if(popres){
        printf("data[%d]=%d\n",popres,res);
    }

    return 0;
}


