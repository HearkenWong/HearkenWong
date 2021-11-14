/*	PairingHeap.h -- 配对堆头文件	*/
#include <stdio.h>
#include <stdlib.h>

/*	明显常量定义	*/

#define FALSE (0)
#define TRUE (1)
#define MAXSIBLINGS (100)

/*	数据类型定义	*/

typedef int BOOL ;

typedef int Item ;
typedef struct node
{
	Item item ;
	struct node * left, * previous, * nextSibling ;
} Node ;
typedef struct pairingHeap
{
	Node * root ;
	int current ;
} * PairingHeap ;
BOOL Initialize_P (PairingHeap * const pph) ;
BOOL IsEmpty_P (const PairingHeap * const pph) ;
BOOL Insert_P (const PairingHeap * const pph, const Item item, const Node * * const localizer) ;
BOOL DecreaseKey_P (const PairingHeap * const pph, Node * const position, const Item delta) ;
BOOL DeleteMin_P (const PairingHeap * const pph, Item * const pmin) ;
void Release_P (PairingHeap * const pph) ;
