#include<stdio.h>
#include <stdlib.h>

typedef struct  LNode
{
    int data;    // 指针传递真是值，不是副本
    struct  LNode  *next; // 前驱指针和后继节点     
} LNode, *LinkList;


bool InitDlinklist(LinkList &L){
    L = (LNode  *) malloc(sizeof(LNode));
    if(L == NULL){
        return false;
    }
    L->next = L;
    return true;

}

bool Empty(LinkList L ){
    if(L->next == L){
         return true;
    }
    return false;
}

// 是否尾节点
bool isTaily(LinkList L,LNode *p ){
    if(p->next == L){
         return true;
    }
    return false;
}


bool InsertNextDNode(LNode *p,LNode *s){
 if(p == NULL || s == NULL){ return false ; }

    s->next = p->next; //先修改插入节点的指向
   
    p->next = s;  // 修改p的后驱指针
    return true;
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
void printAllNodePreRead(LinkList L){
    if(L == NULL){
        return;
    }

    LNode *p  = L->next;
    while (p->next != NULL)
    {
          printf("%d",p->data);
          p  = p->next;
    }

}

// 后向遍历
void printAllNodeBackRead(LinkList L){
    
    if(L == NULL){
        return;
    }

    LNode *p =L ;

    while (p->next != NULL)
    {
          printf("data is: %d \n",p->data);
          p = p->next;
    }
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


