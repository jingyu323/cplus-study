

#include <stdio.h>
#include <stdlib.h>


#define ElementType int //存储数据元素的类型
#define MAXSIZE 6 //存储数据元素的最大个数
#define ERROR -99 //ElementType的特殊值，标志错误
 


typedef struct Node {
    ElementType data;
    struct Node* next;
}QNode;


typedef struct {
    QNode* front; //指向对头节点
    QNode* rear; //指向队尾节点
}Queue;


Queue* CreateQueue() {
  Queue* q = (Queue*)malloc(sizeof(Queue));
    if (!q) {
        printf("空间不足！\n");
        return NULL;
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
} 



void AddQ(Queue* q, ElementType item) {

    QNode* qNode = (QNode*)malloc(sizeof(QNode));
    if (!qNode) {
        printf("空间不足！\n");
        return;
    }
    qNode->data = item;
    qNode->next = NULL;
    if (q->front == NULL) {
        q->front = qNode;
    }
    if (q->rear == NULL) {
        q->rear = qNode;
    }
    else {
        q->rear->next = qNode;
        q->rear = qNode;
    }


}

int IsEmptyQ(Queue* q) {
    return  (q->front == NULL);
}


ElementType DeleteQ(Queue* q) {
   if (IsEmptyQ(q)) {
        printf("空队列\n");
        return ERROR;
    }
    QNode* temp = q->front;
    ElementType item;
    if (q->front == q->rear) { //若队列只有一个元素
        q->front = NULL;
        q->rear = NULL;
    }
    else {
        q->front = q->front->next;
    }
    item = temp->data;
    free(temp);
 
    return item;
}


void PrintQueue(Queue* q) {
    if (IsEmptyQ(q)) {
        printf("空队列\n");
        return;
    }
    printf("打印队列数据元素：\n");
    QNode* qNode = q->front;
    while (qNode != NULL) {
        printf("%d " , qNode->data);
        qNode = qNode->next;
    }
    printf("\n"); 
} 


int main(int argc, const char * argv[]) {
   Queue* q = CreateQueue();
    
    AddQ(q, 1);
    PrintQueue(q);
    
    DeleteQ(q);
    PrintQueue(q);
    
    AddQ(q, 2);
    AddQ(q, 3);
    AddQ(q, 4);
    PrintQueue(q);
    
    DeleteQ(q);
    DeleteQ(q);
    PrintQueue(q);
    
    AddQ(q, 5);
    AddQ(q, 6);
    PrintQueue(q); 
 
    return 0;
} 

