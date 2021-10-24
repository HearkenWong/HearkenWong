//散列表查找算法（Hash） 
#include <stdio.h>   
#include <stdlib.h>   
#define OK 1 
#define ERROR 0 
#define TRUE 1 
#define FALSE 0 
#define SUCCESS 1 
#define UNSUCCESS 0 
#define HASHSIZE 7          
#define NULLKEY -32768  
typedef int Status;   
typedef struct 
{ 
  int *elem;           //基址 
  int count;           //当前数据元素个数  
}HashTable; 
 
int m=0; // 散列表表长 
 
/*初始化*/ 
Status Init(HashTable *hashTable) 
{ 
  int i; 
  m=HASHSIZE; 
  hashTable->elem = (int *)malloc(m * sizeof(int)); //申请内存 
  hashTable->count=m; 
  for (i=0;i<m;i++) 
  { 
    hashTable->elem[i]=NULLKEY; 
  } 
  return OK; 
} 
 
/*散列函数*/ 
int Hash(int data) 
{ 
  return data % m; 
} 
 
/*插入*/ 
void Insert(HashTable *hashTable,int data) 
{ 
  int hashAddress=Hash(data); //求哈希地址 
 
  //发生冲突 
  while(hashTable->elem[hashAddress]!=NULLKEY) 
  { 
    //利用开放定址的线性探测法解决冲突 
    hashAddress=(++hashAddress)%m; 
  } 
 
  //插入值 
  hashTable->elem[hashAddress]=data; 
} 
 
/*查找*/ 
int Search(HashTable *hashTable,int data) 
{ 
  int hashAddress=Hash(data); //求散列地址 
 
  //发生冲突 
  while(hashTable->elem[hashAddress]!=data) 
  { 
    //利用开放定址的线性探测法解决冲突 
    hashAddress=(++hashAddress)%m; 
 
    if (hashTable->elem[hashAddress]==NULLKEY||hashAddress==Hash(data)) return -1; 
  } 
 
  //查找成功 
  return hashAddress; 
} 
 
/*打印结果*/ 
void Display(HashTable *hashTable) 
{ 
  int i; 
  printf("\n//==============================//\n"); 
 
  for (i=0;i<hashTable->count;i++) 
  { 
    printf("%d ",hashTable->elem[i]); 
  } 
 
  printf("\n//==============================//\n"); 
} 
 
int main() 
{ 
  int i,j,result; 
  HashTable hashTable; 
  int arr[HASHSIZE]={13,29,27,28,26,30,38}; 
 
  
 
  //初始化散列表 
  Init(&hashTable); 
 
  //插入数据 
  for (i=0;i<HASHSIZE;i++) 
  { 
    Insert(&hashTable,arr[i]); 
  } 
  Display(&hashTable); 
 
  //查找数据 
  result= Search(&hashTable,29); 
  if (result==-1)  
      printf("未找到！\n"); 
  else  
      printf("29在散列表中的位置是:%d\n",result); 
  return 0; 
} 

