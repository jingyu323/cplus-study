
#include<stdio.h>
#include <stdlib.h>
#define MaxSize 10


 // 双端队列的数组实现
typedef struct Deque
{
    int data[MaxSize];
    int front;
    int tail;
    int size;
} *Deque;


// 初始化
Deque initiation(int capacity)
{
    Deque queue = (Deque) malloc(sizeof (struct Deque));
    if(queue == NULL){
        perror("malloc errror");
        return NULL;
    }

    queue->front = queue->tail = -1;
    queue->size = 0;
  
    return queue;
}



// 获取容量
int getCapacity(Deque q)
{
    return q->size;
}
// 获取元素个数
int getSize(Deque q)
{
    return q->size;
}


// 判断队列是否空
int isEmpty(Deque q)
{
    if(q == NULL){

        printf("q is not existed");

        return  true;

    }
    return q->size == 0;
}

bool isFull(Deque q)
{
    if(q == NULL){

        printf("q is not existed");

        return  false;

    }
    return q->size == MaxSize;
}




 
// 队尾入队
void addLast(int e, Deque q)
{
    if (q->size == q->capacity)
    {
        resize(2 * q->capacity, q);
    }
    q->data[q->tail] = e;
    q->tail = (q->tail + 1) % q->capacity;
    q->size++;
} 


// 队首入队
void addFirst(int e, Deque q) {
    if (q->size == q->capacity) {
        resize(2 * q->capacity, q);
    }
    q->front = q->front == 0? q->capacity - 1: q->front - 1;
    q->data[q->front] = e;
    q->size++;
}
// 队首出队
int removeFirst(Deque q)
{
    if (isEmpty(q))
    {
        perror("removeFirst failed, queue is empty now");
        return -1;
    }
    int ret = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    if (q->size == q->capacity / 4 && q->capacity / 2 != 0)
    {
        resize(q->capacity / 2, q);
    }
    return ret;
} 
// 队尾出队
int removeLast(Deque q) {
    if (isEmpty(q))
    {
        perror("removeLast failed, queue is empty now");
        return -1;
    }
    q->tail = q->tail == 0? q->capacity - 1: q->tail - 1;
    int ret = q->data[q->tail];
    q->size--;
    if (q->size == q->capacity / 4 && q->capacity / 2 != 0)
    {
        resize(q->capacity / 2, q);
    }
    return ret;
}
// 获取队首
int getFront(Deque q)
{
    if (isEmpty(q))
    {
        perror("GetFront failed, queue is empty now");
        return -1;
    }
    return q->data[q->front];
}
// 获取队尾
int getLast( Deque q) {
    if (isEmpty(q))
    {
        perror("GetLast failed, queue is empty now");
        return -1;
    }
    int index = q->tail == 0? q->capacity - 1: q->tail - 1;
    return q->data[index];
}
// 打印队列
void toString(Deque q)
{
    printf("Deque: size = %d, capacity = %d\n", q->size, q->capacity);
    printf("front [");
    for (int i = 0; i < q->size; i++)
    {
        printf("%d", q->data[(q->front + i) % q->capacity]);
        if (i != q->size - 1)
        {
            printf(", ");
        }
    }
    printf("] tail\n");
}
// 销毁队列
void destroy(Deque &q) {
    if(q == NULL){
        printf(" queue not existed.") ;
        return;
    }

    q->front=q->tail=-1;
    
    q->size=0;
}
 
int main() {
    Deque q = initiation(10);
    for (int i = 0; i < 16; i ++) {
        if (i % 2 == 0) {
            addLast(i, q);
        } else addFirst(i, q);
        toString(q);
    }
    for (int i = 0; !isEmpty(q); i ++) {
        if (i % 2 == 0) {
            removeFirst(q);
        } else removeLast(q);
        toString(q);
    }
    destroy(q);
} 