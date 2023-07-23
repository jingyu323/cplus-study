#include<stdio.h>
#include <stdlib.h>

#define MaxSize 10

// 静态链表
typedef struct  Node
{
    int data;    // 指针传递真是值，不是副本
    int  cur; // 前驱指针和后继节点     
};

typedef struct  Node SLinkList[MaxSize];
 
/**
 * @brief 
 * 
 * ：对第一个和最后一个元素作为特殊元素处理，不存数据。通常把未被使用的数组元素称为备用链表。
 * 
 * 数组第一个元素，即下标为0的元素的cur存放备用链表的第一个结点的下标
 * 
 * 数组最后一个元素的cur则存放第一个有数值的元素的下标，相当于单链表的头结点作用，当整个链表为空时，则为0。
 */
bool InitDlinklist(SLinkList L){
    
    int i;
    for(i=0; i<MaxSize-1; i++){
        L[i].cur = i + 1;
    }

    L[MaxSize-1].cur = 0; 
    return true;

}

int Malloc_SSL(SLinkList space){
    int i = space[0].cur;  // 当前数组第一个元素的cur存的值，即第一个备用空闲的下标
    if(space[0].cur){ 
        space[0].cur = space[i].cur; //拿出备用链表的一个分量来使用，将其作为下个分量
    }
    return i;
} 


bool Empty(SLinkList L ){
    if(  L[MaxSize-1].cur ==  0){
         return true;
    }
    return false;
}


int ListLength(SLinkList L)
{
    int j=0;
    int i=L[MaxSize-1].cur;
    while(i)
    {
        i=L[i].cur;
        j++;
    }
    return j;
}

bool ListInsert(SLinkList L,int i,int e){
    int j,k,l;
    k = MaxSize-1;  // k是最后一个元素下标
    if(i<1 || i > ListLength(L)+1){  // 插入位置违法 
        return false;
    }
    j = Malloc_SSL(L);  // 获取空闲分量的下标
    if(j){
        L[j].data = e;  // 将数据复制给此分量的data
        for (l=1; l<=i-1; l++){  // 找到第i个元素之前的位置
            k = L[k].cur;
        }
        L[j].cur = L[k].cur;  // 第i个元素之前的cur赋值给新元素的cur
        L[k].cur = j;  // 把新元素的下标赋值给第i个元素之前元素的cur
        return true;
    }
    return false;
} 

void Free_SSL(SLinkList space, int k) 
{  
    space[k].cur = space[0].cur;    /* 把第一个元素的cur值赋给要删除的分量cur */
    space[0].cur = k;               /* 把要删除的分量下标赋值给第一个元素的cur */
}
// 删除节点的后继节点
bool ListDelete(SLinkList L, int i)   
{ 
    int j, k;   
    if (i < 1 || i > ListLength(L))   
        return false;   
    k = MaxSize - 1;   
    for (j = 1; j <= i - 1; j++)   
        k = L[k].cur;   
    j = L[k].cur;   
    L[k].cur = L[j].cur;   
    Free_SSL(L, j);   
    return true;   
}
  
int main(int argc, char const *argv[])
{
    
    SLinkList L; // 定义头节点
    bool inires =   InitDlinklist(L);
 
    return 0;
}


