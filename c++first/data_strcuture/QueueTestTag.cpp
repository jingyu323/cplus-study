#include<stdio.h>
#include <stdlib.h>
#define MaxSize 10

typedef struct  Queue
{
    int data[MaxSize];    // 指针传递真是值，不是副本    
    int  front,rear;
    int tag ;
} SeqQueue ;

// 增加 tag  只有删除操作才能导致队列为空，只有插入操作才能导致队列满
bool InitSeqQueue(SeqQueue &Q){
    Q.front=Q.rear=0;
    Q.tag = 0;
    return true;
}

bool EmptySeqQueue(SeqQueue &Q){
    return  Q.tag == 0 &&   Q.front==Q.rear ;
}


// 入队
bool EnSeqQueue(SeqQueue &Q, int e){
    if(Q.tag == 1 &&   Q.front==Q.rear){
          printf(" queue is full \n" );
            return false;
    }

  

    Q.data[Q.rear] = e;
    Q.rear =(Q.rear +1)%MaxSize;
    Q.tag = 1;
      printf(" rear is %d   \n",Q.rear );
    return true;
}


// 出队
bool DeSeqQueue(SeqQueue &Q, int &e){
    if(Q.tag == 0 && Q.rear == Q.front ){
            return false;
    }
    e=Q.data[Q.front];
    Q.front =(Q.front +1)%MaxSize;
    Q.tag = 0;
    return true;
}

bool GetSeqQueueHead(SeqQueue Q, int &e){
    if(Q.tag == 0 && Q.rear == Q.front){
            return false;
    }
    e=Q.data[Q.front];
    return true;
}

// 获取队列中的元素个数
int getQueueSize(SeqQueue Q){
    if(Q.tag == 1 &&   Q.front==Q.rear){
     return MaxSize;
    }
    return (Q.rear + MaxSize - Q.front)%MaxSize;
}



void printQueueEle(SeqQueue Q){

    int len = getQueueSize(Q);

    printf("len is %d ",len);

        for (int i = 0; i < len ; i++)
    {
          printf("data[%d]=%d\n",i,Q.data[i]);
    }
    

}



/*遍历队列*/
void QueueTraverse(SeqQueue Q)
{
    if(Q.tag == 0 && Q.front==Q.rear)  //空队列 
    {
        printf("队列空队,请添加数据后在traverse!\n");return;
    }

    int front = Q.front;

    printf("%d ",Q.data[front]);  // 防止front与rear相等时,无法进入下面的循环 
    front = ++front % MaxSize;

    while( front != Q.rear)
    {
        printf("%d ",Q.data[front]);
        front = ++front % MaxSize;     
    }
    printf("\n");
    return; 
} 



int main(int argc, char const *argv[])
{
    
    SeqQueue q;

    InitSeqQueue(q);

    for (int i = 0; i < MaxSize-1; i++)
    {
        EnSeqQueue(q,i+3);
    }
    
    QueueTraverse( q);

  int len = getQueueSize(q);

    printf("len is %d  \n",len);

    return 0;
}
