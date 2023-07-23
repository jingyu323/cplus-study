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

 


// 删除节点的后继节点
bool DeleteDNode(LNode *p){
    if(p == NULL){ return false ;
    }
    LNode *q  = p->next; //  z找到后继节点

    if(q == NULL){
            return false;
    }
    p->next = q->next;

    free(q);
    return true;
}

void DestroyList(LinkList &L){
    while (L->next != NULL)
    {
       DeleteDNode(L);
    }
    free(L);
    L= NULL;
    
}

// 前向遍历
void printAllNodePreRead(SeqList L){
 

}

 

int main(int argc, char const *argv[])
{
    
    LinkList L; // 定义头节点
    bool inires =   InitDlinklist(L);
    LNode *s =  (LNode  *) malloc(sizeof(LNode));
    s->data = 9;
    bool res = InsertNextDNode(L,s);
    printAllNodeBackRead(L);
    return 0;
}


