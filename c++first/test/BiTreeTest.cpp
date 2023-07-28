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
        MidOrder(t->lchild);
        visit(t);
        
        MidOrder(t->rchild);
    }
}


void BackOrder(BiTree t){
    if(t != NULL){
        BackOrder(t->lchild);
        BackOrder(t->rchild);
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


   
   BiTree lft1 = (BiTree) malloc(sizeof(BiTNode));
   lft1->data=4;
   lft1->lchild=NULL;
   lft1->rchild=NULL;

   BiTree lftr = (BiTree) malloc(sizeof(BiTNode));
   lftr->data=5;
   lftr->lchild=NULL;
   lftr->rchild=NULL;

   lft->lchild= lft1;
   lft->rchild=lftr;

   
   BiTree right = (BiTree) malloc(sizeof(BiTNode));
   right->data=3;
   right->lchild=NULL;
   right->rchild=NULL;
   T->rchild = right;


  BiTree right1 = (BiTree) malloc(sizeof(BiTNode));
   right1->data=6;
   right1->lchild=NULL;
   right1->rchild=NULL;

   BiTree rightr = (BiTree) malloc(sizeof(BiTNode));
   rightr->data=7;
   rightr->lchild=NULL;
   rightr->rchild=NULL;

   right->lchild= right1;
   right->rchild=rightr;


  PreOrder(T);

  printf("\n");

  MidOrder(T);

    printf("\n");

  BackOrder(T);

return 0;
}
