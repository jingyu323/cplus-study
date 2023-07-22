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


int main(int argc, char const *argv[])
{
    
     LinkList L = (LinkList  ) malloc(sizeof(LNode));

     L->next  = NULL;

    LNode *first,*sec,*third=L;


    first->data = 1;
    first->next=sec;
    sec->data = 2;
    third->data=3;
    sec->next = third;


    int e = 3 ;
     bool  res = ListInsert(L,  2 ,   e );
     printf(" ddis : s%",&res);


    return 0;
}
