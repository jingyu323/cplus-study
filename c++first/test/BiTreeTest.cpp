#include <stdio.h>
#include <stdlib.h>
typedef struct BiTNode
{
     int data;
     struct  BiTNode *lchild,*rchild;
}BiTNode,*BiTree;


bool  TreeeInit(BiTree &root){

    root = (BiTree) malloc(sizeof(BiTNode));
    root->data=1;
    root->lchild=NULL;
    root->rchild=NULL;

    return true;

}


void visit(BiTree node){
    printf("%d ",node->data);
    
}

void PreOrder(BiTree t){
    if(t != NULL){
        visit(t);
        PreOrder(t->lchild);
        PreOrder(t->rchild);
    }
}

void MidOrder(BiTree t){
    if(t != NULL){
        PreOrder(t->lchild);
        visit(t);
        
        PreOrder(t->rchild);
    }
}


void BackOrder(BiTree t){
    if(t != NULL){
        PreOrder(t->lchild);
        PreOrder(t->rchild);
         visit(t);
    }
}


int main(int argc, char const *argv[])
{
    
  BiTree T; 

  TreeeInit(T);

   BiTree lft = (BiTree) malloc(sizeof(BiTNode));
   lft->data=2;
   lft->lchild=NULL;
   lft->rchild=NULL;
   T->lchild = lft;

   
   BiTree right = (BiTree) malloc(sizeof(BiTNode));
   right->data=3;
      right->lchild=NULL;
   right->rchild=NULL;
   T->rchild = right;

  PreOrder(T);

  printf("\n");

  MidOrder(T);

    printf("\n");

  BackOrder(T);

return 0;
}
