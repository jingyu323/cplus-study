#include<stdio.h>
#include <stdlib.h>
 
#define InitSize 10
// 静态链表
typedef struct  Node
{
    int *data;    // 指针传递真是值，不是副本
     int  MaxSize; // 前驱指针和后继节点     
     int  length;
} SeqList ;


bool InitDlinklist(SeqList &L){
    L.data = (int  *) malloc(sizeof(int) * InitSize);
    if(L.data == NULL){
        return false;
    }
    L.length = 0;
    return true;
}

bool Empty(SeqList L ){
    if(L.length == 0){
         return true;
    }
    return false;
}

// 前向遍历
void printAllNodePreRead(SeqList L){
 

}

 

int main(int argc, char const *argv[])
{
    
    
    return 0;
}


