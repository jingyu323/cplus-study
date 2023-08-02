#include <stdio.h>
#include <stdlib.h>

typedef struct tagListNode {
    int val;
    struct tagListNode *prev;
    struct tagListNode *next;
} ListNode;


typedef struct {
    ListNode *head;
    ListNode *tail;
    int capacity;
    int size;
} MyCircularDeque;


// 创建一个循环双队列
MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque *obj = (MyCircularDeque *)malloc(sizeof(MyCircularDeque));
    obj->capacity = k;
    obj->size = 0;
    obj->head = NULL;
    obj->tail = NULL;
    return obj;
} 


// 创建一个队列的单节点
ListNode *ListNodeCreate(int value) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->val = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
} 

 bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (obj->size == obj->capacity) {
        return false;
    }
    ListNode *node = ListNodeCreate(value);
    if (!obj->head) {
        obj->head = node;
        obj->tail = node;
    } else {
        node->next = obj->head;
        obj->head->prev = node;
        obj->head = node;
    }
    obj->size++;
    return true;
}


bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (obj->size == obj->capacity) {
        return false;
    }
    ListNode *node = ListNodeCreate(value);
    if (!obj->tail) {
        obj->head = node;
        obj->tail = node;
    } else {
        obj->tail->next = node;
        node->prev = obj->tail;
        obj->tail = node;
    }
    obj->size++;
    return true;
}
 
 bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (obj->size == 0) {
        return false;
    }
    ListNode *toDelete = obj->head;
    obj->head = toDelete->next;
    if (obj->size == 1) {
        obj->tail = NULL;
    }
    if (obj->head) {
        obj->head->prev = NULL;
    }
    free(toDelete);
    obj->size--;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (obj->size == 0) {
        return false;
    }
    ListNode *toDelete = obj->tail;
    obj->tail = toDelete->prev;
    if (obj->size == 1) {
        obj->head = NULL;
    }
    if (obj->tail) {
        obj->tail->next = NULL;
    }
    free(toDelete);
    obj->size--;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (obj->size == 0) {
        return -1;
    }
    return obj->head->val;
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (obj->size == 0) {
        return -1;
    }
    return obj->tail->val;
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->size == 0;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->size == obj->capacity;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    ListNode *cur = obj->head;
    while (cur) {
        ListNode *toDelete = cur;
        cur = cur->next;
        free(toDelete);
    }
    free(obj);
} 
 