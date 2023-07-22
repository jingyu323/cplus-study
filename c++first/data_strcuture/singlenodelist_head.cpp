#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int data;
    struct  LNode *next;
    
    /* data */
} LNode, *LinkList;

// 带头结点的写代码方便一点

bool InitList(LinkList &L){
    L = (LNode *) malloc(sizeof(LNode)) ;
    if (L == NULL)
    {
        /* code */
        return false;
    }
    L->next= NULL;
    return true;

}

bool Empty(LinkList L){
    return  L->next == NULL;
}


// P 节点之后插入元素
bool InsertNextNode(LNode *p,int e ){
    if(p == NULL){
        return false;
    }
     LNode *s = (LNode * ) malloc(sizeof(LNode));
    if(s == NULL){
        return false;
    }
    s->data = e;
    s->next=p->next;
    p->next=s;
    return  true;
}



// 再 p之前插入 节点s
bool InsertPreNode(LNode *p,LNode *s){
     if(s == NULL ||  p == NULL){
        return false;
    }
      s->next=p->next;

      int tmp = p->data;

      p->data = s->data;
      s->data =tmp;
    return true;
}


bool ListInsert(LinkList &L,int i , int e ){
    if(i< 1){
        return false;
    }
    LNode *p ;
    int j = 0;
    p = L;

    while (p != NULL && j < i-1   )
    {
        p= p->next;
        j++;
    }

    if(p == NULL) return false;

    LNode *s = (LNode * ) malloc(sizeof(LNode));
    s->data = e;
    s->next=p->next;
    p->next=s;

    return true;
}

bool ListDelete(LinkList &L,int i , int e){

    if(i< 1){
        return false;
    }
    LNode *p ;
    int j = 0;
    p = L;

    while (p != NULL && j < i-1   )
    {
        p= p->next;
        j++;
    }
    
    if(p == NULL) return false;

    if(p->next == NULL) return false;

    LNode *s = p->next;
    e= s->data;
    p->next = s->next;
    free(s);
    return  true;
}

bool DeleteNode(LNode *p){
    if(p == NULL) return false;
    LNode *q = p->next;
    q->data= p->next->data;
    p->next = q->next;
    free(q);
    return true;

}

LNode* GetEle(LinkList L, int i){
    if(i< 0){
        return NULL;
    }

    LNode *p;
    int j=0;
    p= L; // 头节点

    while (p!= NULL && j<i)
    {
        p = p->next;
        j++;
    }

    return p;
    

} 


// 按值查找
LNode * LocalteEle(LinkList L,int e){
    LNode *p = L->next;

    while (p != NULL && p->data != e)
    {
        /* code */
        p= p->next;
    }
    
    return p;

}



void printListInfo(LinkList L){
    if(L == NULL || L->next == NULL ){
        printf("L is null....");
        return ;
    }

     LNode *s = L->next;
     int i=0;

    while (s !=NULL)
    {
        printf("data[%d]=%d\n",i,s->data);
        s = s->next;
        i++;
    }
}


LinkList List_headInsert(LinkList &L){
    LNode *s;
    int x ;

    L = (LinkList)malloc (sizeof(LNode)); // 创建头节点
    L->next = NULL;
    scanf("%d",&x);
    while (x!=9999)
    {
        s= (LNode*) malloc(sizeof(LNode));
        s->data = x;
        s->next=L->next;
        L->next = s;  // 头节点指向新创建节点，也就是将新节点插入链表
        scanf("%d",&x);
    }
    return L;

}

int main(int argc, char const *argv[])
{
    LinkList L;
    InitList(L);
    List_headInsert(L);
    printListInfo(L);
    return 0;
}
