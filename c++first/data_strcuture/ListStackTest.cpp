#include<stdio.h>
#include <stdlib.h>
 
#define MaxSize 10
// 链栈
typedef struct  Node
{
    int data;    // 指针传递真是值，不是副本
          
   struct Node *next;
} Node ,*LinkStNode ;


bool InitSeqStack(LinkStNode &s){
    s = (Node *) malloc(sizeof(Node)) ;
	s->next=NULL;
    return true;
}


void DestroyStack(LinkStNode &s)
{
	Node *p=s->next;
	while (p!=NULL)
	{	
		free(s);
		s=p;
		p=p->next;
	}
	free(s);	//s指向尾结点,释放其空间
} 


bool Empty(LinkStNode s ){
    return(s->next==NULL);
}

bool Push(LinkStNode &s,int  e){
    Node *p;
	p=(Node *)malloc(sizeof(Node));
    if(p == NULL){
        return false;
    }
	p->data=e;				//新建元素e对应的结点p
	p->next=s->next;		//插入p结点作为开始结点
	s->next=p;  // 头节点处添加

    return true;
    
}

bool Pop(LinkStNode &s,int  &e){
   Node *p;
	if (s->next==NULL)		//栈空的情况
		return false;
	p=s->next;				//p指向开始结点
	e=p->data;
	s->next=p->next;		//删除p结点
	free(p);				//释放p结点
	return true; 
}


bool GetTop(LinkStNode s,int  &e){
    if (s->next==NULL)		//栈空的情况
		return false;
	e=s->next->data;
    return true;
}


// 前向遍历
void printAllNodePreRead(LinkStNode L){
    int i =0;
    Node *p = L; 
    while (L->next != NULL)
    {
          printf("data[%d]=%d\n",i,p->next->data);
          i++;
          p = p->next;
    }
    
}



int main(int argc, char const *argv[])
{

    LinkStNode s;

    InitSeqStack(s);

    Push(s,8);
    Push(s,2);
    Push(s,3);
    Push(s,4);
    
    printAllNodePreRead(s);

    int res;

    bool popres = Pop(s,res);

    if(popres){
        printf("data[%d]=%d\n",popres,res);
    }

    return 0;
}


