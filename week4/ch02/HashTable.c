#include "HashTable.h"
#include <stdio.h>
#include <stdlib.h>
 
/***********************开发定址法（平方）***********************************/
hashTable initializeTable(int tableSize)
{
	hashTable table;
	int i;
	if(tableSize<MINTABLESIZE)
	{
		printf("table size is too small\n");
		exit(-1);
	}
	table=(hashTable)malloc(sizeof(struct HashTable));
	if(!table)
	{
		printf("out of space\n");
		exit(-1);
	}
	table->tableSize=nextPrime(tableSize);
	table->theCells=(cell*)malloc(sizeof(cell)*table->tableSize);
	if(!table->theCells)
	{
		printf("out of space\n");
		exit(-1);
	}
	for(i=0;i<table->tableSize;i++)
		table->theCells[i].info=empty;
	
	return table;
}
 
void destoryTable(hashTable H)
{
	free(H->theCells);
	H=NULL;
}
 
position find(ElementType key,hashTable H)
{
	position currentPos;
	int collisionNum;
	
	collisionNum=0;
	currentPos=Hash(key,H->tableSize);
	while(H->theCells[currentPos].info!=empty&&
		H->theCells[currentPos].element!=key)
	{
		//平方探测法
		currentPos+=2*collisionNum-1;
		if(currentPos>=H->tableSize)
			currentPos-=H->tableSize;
	}
	return currentPos;
}
 
int Delete(ElementType key,hashTable H)
{
	position pos;
	pos=find(key,H);
	if(H->theCells[pos].info==empty)
		return 0;
	else
	{
		H->theCells[pos].info=deleted;
		return 1;
	}
}
 
void insert(ElementType key,hashTable H)
{
	position pos;
	pos=find(key,H);
	if(H->theCells[pos].info!=legitimate)
	{
		H->theCells[pos].info=legitimate;
		H->theCells[pos].element=key;
	}
}
 
ElementType retrieve(position p,hashTable H)
{
 
}
 
hashTable reHash(hashTable H)	//再散列
{
	int i,oldSize;
	cell *oldCells;
 
	oldCells=H->theCells;
	oldSize=H->tableSize;
 
	H=initializeTable(2*oldSize);
	for(i=0;i<oldSize;i++)
	{
		if(oldCells[i].info==legitimate)
			insert(oldCells[i].element,H);
	}
	free(oldCells);
	return H;
}
int nextPrime(int tableSize)
{
	while(1)
	{
		if(isPrime(tableSize))
			return tableSize;
		else
			tableSize++;
	}
}
int isPrime(int x)
{
	int i;
	for(i=2;i*i<=x;i++)
	{
		if(x%i==0)
			return 0;
	}
	return 1;
}
int Hash(ElementType key,int tableSize)
{
	return key%tableSize;
}
/**************************************************************************/
