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
    L->prior == NULL;
    L->next == NULL;
    return true;

}

