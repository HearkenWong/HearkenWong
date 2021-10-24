#ifndef __HASHTABLE_H
#define __HASHTABLE_H
 
 
/*********************（平方）开放定址散列法***************/
 
//如果有冲突发生，那么就尝试另外的单元，直到找到空的单元为止
typedef unsigned int index;
typedef index position;
typedef int ElementType;
#define MINTABLESIZE 5
 
struct hashTable;
typedef struct HashTable *hashTable;
 
hashTable initializeTable(int tableSize);
void destoryTable(hashTable H);
position find(ElementType key,hashTable H);
void insert(ElementType key,hashTable H);
ElementType retrieve(position p,hashTable H);
hashTable reHash(hashTable H);
int Delete(ElementType key,hashTable H);
int nextPrime(int tableSize);
int isPrime(int x);
int Hash(ElementType key,int tableSize);
 
enum kindOfEntry{legitimate,empty,deleted};
 
struct hashEntry
{
	ElementType element;
	enum kindOfEntry info;
};
 
typedef struct hashEntry cell;
 
struct HashTable
{
	int tableSize;
	cell *theCells;
};
