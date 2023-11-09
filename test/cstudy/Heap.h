

#pragma once
 
//在堆头文件中包含之后所需头文件：
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
 
 
//定义节点值(堆底层数组元素)的类型：
typedef int HPDataType;




//定义堆类型：
typedef struct Heap
{
	//因为底层是用顺序结构实现，
	//所以该类型和顺序表类似：
 
	//指向堆节点的指针：
	//（指向堆底层数组的首元素）
	HPDataType* a;
 
	//堆当前节点个数：
	//（堆底层数组的元素个数）
	int size;
 
	//堆当前开辟的空间单位：
	//（堆底层数组动态开辟的空间单位）
	int capacity;
 
}HP; //堆类型Heap重命名为HP 



//堆初始化函数1 -- 对堆类型中的成员进行初始化
//接收 堆类型指针（php）
void HeapInit(HP* php);
 
//堆销毁函数 -- 对堆类型进行销毁
//接收 堆类型指针（php）
void HeapDestroy(HP* php);
 
//打印堆函数 -- 打印堆中各节点值
//接收 堆类型指针（php）
void HeapPrint(HP* php);
 
//节点位置互换函数 -- 在向上向下调整操作中互换节点位置：
//接收要互换位置的两个节点的指针（p1 和 p2）
void Swap(HPDataType* p1, HPDataType* p2);
 
//堆插入函数 -- 在堆类型中插入一个节点
//接收 堆类型指针（php）和插入节点的值（x）
void HeapPush(HP* php, HPDataType x);
 
//堆初始化函数2 -- 接收一个数组将其初始化为一个堆底层数组
//接收 堆类型指针（php）、数组首元素地址（a）、数组元素个数（n）
void HeapInitArray(HP* php, int* a, int n);
 
//堆删除函数 -- 删除堆类型根节点（删除当前堆中最值）
//接收 堆类型指针（php）
void HeapPop(HP* php);
 
//堆顶函数 -- 获取并返回推根节点值
//接收 堆类型指针（php）
HPDataType HeapTop(HP* php);
 
//判空函数 -- 判断堆类型是否为空
//接收 堆类型指针（php）
bool HeapEmpty(HP* php); 




