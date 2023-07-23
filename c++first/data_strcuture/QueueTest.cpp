#include<stdio.h>
#include <stdlib.h>
#define MaxSize 10

typedef struct  Queue
{
    int data[MaxSize];    // 指针传递真是值，不是副本
          
    int  front,rear;
} SeqQueue ;

bool InitSeqQueue(SeqQueue &Q){
    Q.front=Q.rear=0;
    return true;
}

bool EmptySeqQueue(SeqQueue &Q){
    return Q.front==Q.rear;
}


// 入队
bool EnSeqQueue(SeqQueue &Q, int e){
    if((Q.rear +1)% MaxSize == Q.front){

        printf(" queue is full");
        return false;
    }

    Q.data[Q.rear] = e;
    Q.rear =(Q.rear +1)%MaxSize;
    return true;
}


// 出队
bool DeSeqQueue(SeqQueue &Q, int &e){
    if(Q.rear == Q.front){
            return false;
    }
    e=Q.data[Q.front];
    Q.front =(Q.front +1)%MaxSize;
    return true;
}

bool GetSeqQueueHead(SeqQueue Q, int &e){
    if(Q.rear == Q.front){
            return false;
    }
    e=Q.data[Q.front];
    return true;
}

// 获取队列中的元素个数
int getQueueSize(SeqQueue Q){
    return (Q.rear + MaxSize - Q.front)%MaxSize;
}

void printQueueEle(SeqQueue Q){

        for (int i = 0; i < getQueueSize(Q) ; i++)
    {
          printf("data[%d]=%d\n",i,Q.data[i]);
    }
    

}

int main(int argc, char const *argv[])
{
    
    SeqQueue q;

    InitSeqQueue(q);

    for (int i = 0; i < MaxSize+2; i++)
    {
        EnSeqQueue(q,i+3);
    }
    
    printQueueEle( q);

    return 0;
}

