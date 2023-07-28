#include <stdio.h>
#include <stdlib.h>
typedef struct BiTNode
{
     int data;
     struct  BiTNode *lchild,*rchild;
}BiTNode,*BiTree;


bool  TreeeInit(BiTree root){

    root = (BiTree) malloc(sizeof(BiTNode));
    root->data=1;
    root->lchild=NULL;
    root->rchild=NULL;

    

}

int main(int argc, char const *argv[])
{
    


    return 0;
}
