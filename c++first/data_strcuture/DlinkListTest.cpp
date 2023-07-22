#include<stdio.h>
#include <stdlib.h>

typedef struct  Dnode
{
    int data;    // 指针传递真是值，不是副本
    struct  Dnode *prior,*next; // 前驱指针和后继节点     
} Dnode, *DLinkList;


bool InitDlinklist(DLinkList &L){
    L = (Dnode  *) malloc(sizeof(Dnode));
    if(L == NULL){
        return false;
    }
    L->prior = NULL;
    L->next = NULL;
    return true;

}

bool InsertNextDNode(Dnode *p,Dnode *s){
 if(p == NULL || s == NULL){ return false ; }

    s->next = p->next; //先修改插入节点的指向
    if(p->next != NULL){ // 修改的是后驱节点的前向指针
         p->next->prior = s;
    }
    s->prior = p;  // 修改插入元素的前向指针
    p->next = s;  // 修改p的后驱指针
    return true;
}

// 删除节点的后继节点
bool DeleteDNode(Dnode *p){
    if(p == NULL){ return false ;
    }
    Dnode *q  = p->next; //  z找到后继节点

    if(q == NULL){
            return false;
    }

    p->next = q->next;

    if(q->next != NULL){
        q->next->prior = p;
    }

    free(q);
    return true;
}

void DestroyList(DLinkList &L){
    while (L->next != NULL)
    {
       DeleteDNode(L);
    }
    free(L);
    L= NULL;
    
}

// 前向遍历
void printAllNodePreRead(DLinkList L){
    if(L == NULL){
        return;
    }

    Dnode *p  = L->prior;
    while (p->prior != NULL)
    {
          printf("%d",p->data);
          p  = p->prior;
    }

}

// 后向遍历
void printAllNodeBackRead(DLinkList L){
    
    if(L == NULL){
        return;
    }

    Dnode *p =L ;

    while (p->next != NULL)
    {
          printf("data is: %d \n",p->next->data);
          p  = p->next;
    }
}



int main(int argc, char const *argv[])
{
    
    DLinkList L;

    bool inires =   InitDlinklist(L);

    Dnode *s =  (Dnode  *) malloc(sizeof(Dnode));
    s->data = 9;

    bool res = InsertNextDNode(L,s);

    printAllNodeBackRead(L);



    return 0;
}


