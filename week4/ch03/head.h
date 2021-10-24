#ifndef HEAD_H_
#define HEAD_H_
#include <stdio.h>
#include <stdlib.h>
#include"string.h"
 #define MinTableSize  (10)
 
typedef char * ElementType;
typedef unsigned int Index;
typedef struct ListNode
{
	ElementType data;
	struct ListNode *next;
}*Position;
 
typedef Position List;
typedef struct HashTbl
{
	int TableSize;      //数组中链表的个数
	List *TheLists;     //指针数组。TheLists域是一个指向 ListNode 结构的指针的指针
}*HashTable;
//这是哈希表主结构，*TheLists是一个指针数组，数组的每一项都链接一个上面的ListNode，而这个入口地址相当于链表头节点
 
 
HashTable InitializeTable(int TableSize);
void	DestroyTable( HashTable  H);
Position	Find( ElementType  key , HashTable  H);
void	Insert( ElementType  key , HashTable  H);
ElementType	Retrieve( Position  P);
void Delete( ElementType Key, HashTable H );
 
#endif /* HEAD_H_ */
