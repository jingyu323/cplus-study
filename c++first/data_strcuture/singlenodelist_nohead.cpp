#include <stdio.h>
#include <stdlib.h>

// list 不带头节点的定义
typedef struct LNode
{
    int data;
    struct  LNode *next;
    
    /* data */
} LNode, *LinkList;


bool InitList(LinkList &L){
    L = NULL;
    return true;

}

bool Empty(LinkList L){
    return  L == NULL;
}

bool ListInsert(LinkList &L,int i , int e ){
    if(i< 1){
        return false;

    }

    if(i == 1){
          LNode *s = (LNode * ) malloc(sizeof(LNode));
          s->data = e;
          s->next=L;
          L=s;
          return true;
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
