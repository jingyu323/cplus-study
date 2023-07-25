
#include<stdio.h>
#include <stdlib.h>
#define MaxSize 10


#define ElementType int //存储数据元素的类型
#define MAXSIZE 6 //存储数据元素的最大个数
#define ERROR -99 //ElementType的特殊值，标志错误
 
 
typedef struct Deque
{
    int *data;
    int front;
    int tail;
    int size;
    int capacity;
} *Deque;


// 初始化
Deque initiation(int capacity)
{
    Deque queue = (Deque) malloc(sizeof (struct Deque));
    queue->data = (int *) malloc(sizeof (int) * capacity);
    queue->capacity = capacity;
    queue->front = 0;
    queue->tail = 0;
    queue->size = 0;
    if (queue == NULL || queue->data == NULL)
    {
        perror("Deque initiation failed");
        exit(-1);
    }
    return queue;
}



// 获取容量
int getCapacity(Deque q)
{
    return q->capacity;
}
// 获取元素个数
int getSize(Deque q)
{
    return q->size;
}


// 判断队列是否空
int isEmpty(Deque q)
{
    return q->size == 0;
}

// 扩容/缩容
void resize(int newCapacity, Deque q)
{
    int *newData = (int *) malloc(newCapacity * sizeof (int));
    for (int i = 0; i < q->size; i++)
    {
        newData[i] = q->data[(q->front + i) % q->capacity];
    }
    free(q->data);
    q->data = newData;
    q->capacity = newCapacity;
    q->front = 0;
    q->tail = q->size;
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
void destroy(Deque q) {
    free(q->data);
    q->data = NULL;
    if (q->data == NULL)
    {
        free(q);
        q = NULL;
        if (q == NULL)
        {
            printf("The Deque has successfully been destroyed.\n");
        }
        else
        {
            perror("Deque destroy failed");
            exit(-1);
        }
    }
    else
    {
        perror("Deque destroy failed");
        exit(-1);
    }
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