
#include<stdio.h>
#include <stdlib.h>
#define MaxSize 10


#define ElementType int //存储数据元素的类型
#define MAXSIZE 6 //存储数据元素的最大个数
#define ERROR -99 //ElementType的特殊值，标志错误
 


typedef struct  Queue1
{
    int data[MaxSize];    // 指针传递真是值，不是副本
          
    int  front,rear;
} SeqQueue ;

bool InitSeqQueue(SeqQueue &Q){
    Q.front=Q.rear=0;
    return true;
}



typedef struct {
    ElementType data[MAXSIZE];
    int front; //记录队列头元素位置
    int rear; //记录队列尾元素位置
    int size; //存储数据元素的个数
}Queue;


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





Queue* CreateQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (!q) {
        printf("空间不足\n");
        return NULL;
    }
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    return q;
} 



int IsFullQ(Queue* q) {
    return (q->size == MAXSIZE);
}



void AddQ(Queue* q, ElementType item) {
    if (IsFullQ(q)) {
        printf("队列已满\n");
        return;
    }
    q->rear++;
    q->rear %= MAXSIZE;
    q->size++;
    q->data[q->rear] = item;
}

int IsEmptyQ(Queue* q) {
    return (q->size == 0);
}


ElementType DeleteQ(Queue* q) {
    if (IsEmptyQ(q)) {
        printf("空队列\n");
        return ERROR;
    }
    q->front++;
    q->front %= MAXSIZE; //0 1 2 3 4 5
    q->size--;
    return q->data[q->front];
}


void PrintQueue(Queue* q) {
    if (IsEmptyQ(q)) {
        printf("空队列\n");
        return;
    }
    printf("打印队列数据元素：\n");
    int index = q->front;
    int i;
    for (i = 0; i < q->size; i++) {
        index++;
        index %= MAXSIZE;
        printf("%d ", q->data[index]);
    }
    printf("\n");
} 


int main(int argc, const char * argv[]) {
     SeqQueue q1;

    InitSeqQueue(q1);

    for (int i = 0; i < MaxSize+2; i++)
    {
        EnSeqQueue(q1,i+3);
    }
    
    printQueueEle( q1);


    
    Queue* q = CreateQueue();
    
    AddQ(q, 0);
    AddQ(q, 1);
    AddQ(q, 2);
    AddQ(q, 3);
    AddQ(q, 4);
    AddQ(q, 5);
    PrintQueue(q);
    
    DeleteQ(q);
    DeleteQ(q);
    DeleteQ(q);
    PrintQueue(q);
    
    AddQ(q, 6);
    AddQ(q, 7);
    AddQ(q, 8);
    PrintQueue(q);
 
    return 0;
} 


