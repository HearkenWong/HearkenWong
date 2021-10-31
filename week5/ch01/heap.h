#define _CRT_SECURE_NO_WARNINGS 1
 
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
 
typedef int HeapDataType;
 
typedef struct MaxHeap{
	HeapDataType* data;
	int count;
	int MaxSize;
}MH;
 
//-----------堆的构建等等方法
int size(MH *mh);//返回堆大小
int isEmpty(MH *mh);//判空
void initMaxHeap(MH* mh, int size);//初始化堆
void initMaxHeap2(MH* mh, int size, HeapDataType* arr);//第二种初始化堆,heapify算法
void AdjustUp(MH* mh, int k);//上移元素
void AdjustDown(MH* mh, int k);//下移操作
void insertMaxHeap(MH* mh, HeapDataType value);//插入元素
HeapDataType TopK(MH* mh);//弹出元素
void TestMaxHeap();//测试函数
 
 
 
