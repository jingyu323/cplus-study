#include<stdio.h>
#include <stdlib.h>
#define MaxSize 10

typedef struct  Queue
{
    int data[MaxSize];    // 指针传递真是值，不是副本
          
    int  front,rear;
    int size ;
} SeqQueue ;

bool InitSeqQueue(SeqQueue &Q){
    Q.front=Q.rear=0;
    Q.size = 0;
    return true;
}

bool EmptySeqQueue(SeqQueue &Q){
    return  Q.size == 0;
}


// 入队
bool EnSeqQueue(SeqQueue &Q, int e){
    if(MaxSize == Q.size){
            return false;
    }

    Q.data[Q.rear] = e;
    Q.rear =(Q.rear +1)%MaxSize;
     Q.size =  Q.size +1;
    return true;
}


// 出队
bool DeSeqQueue(SeqQueue &Q, int &e){
    if(Q.size == 0){
            return false;
    }
    e=Q.data[Q.front];
    Q.front =(Q.front +1)%MaxSize;
    Q.size =  Q.size -1;
    return true;
}

bool GetSeqQueueHead(SeqQueue Q, int &e){
    if(Q.size==0){
            return false;
    }
    e=Q.data[Q.front];
    return true;
}

// 获取队列中的元素个数
int getQueueSize(SeqQueue Q){
    return  Q.size;
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

