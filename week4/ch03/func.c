#include"head.h"
//unsigned long NextPrime(unsigned long n)
//{
//	return n/2+1;
//}
 
/* 求下一个素数 ; assume N >= 10 */
static int NextPrime( int N )
{
    int i;
 
    if( N % 2 == 0 )
        N++;
    for( ; ; N += 2 )
    {
        for( i = 3; i * i <= N; i += 2 )
        {
            if( N % i == 0 )
                goto ContOuter;  /* Sorry about this! */
        }
        return N;
      ContOuter: ;
    }
}
/*
 *   初始化函数
 */
HashTable InitializeTable(int TableSize)
{
	HashTable H;
	int i;
	if( TableSize < MinTableSize)
	{
		puts("Table size too small \n");
		return NULL;
	}
	//分配表空间
	H=(HashTable)malloc(sizeof(struct HashTbl));
	if(H==NULL)
	{
		puts("Out of space \n");
		return NULL;
	}
	H->TableSize = NextPrime(TableSize);
	//分配链表数组空间,即为数组整体分配空间
	H->TheLists=malloc(sizeof(List) * H->TableSize);
	if(H->TheLists == NULL)
	{
		puts("Out of space \n");
		return NULL;
	}
	//分配表头空间,即把  数组空间分割为 多个节点大小的空间
	for(i=0;i < H->TableSize;i++)
	{
		H->TheLists[i] = malloc(sizeof(struct ListNode));
		if(H->TheLists[i] == NULL)
		{
			puts("Out of space \n");
			return NULL;
		}
		else
			H->TheLists[i]->next=NULL;
	}
	return H;
}
/*
 *   散列函数
 */
Index Hash( const char *key , int TableSize)
{
	unsigned int HashVal = 0;
	while( *key != '\0')
		HashVal = (HashVal << 5) + *key++;
	return HashVal % TableSize;
}
Position	Find( ElementType  key , HashTable  H)
{
	Position P;
	List L;
	L = H->TheLists[Hash(key,H->TableSize)];
	P=L->next;
	while( P != NULL && strcmp(P->data,key)!=0)
		P = P->next;
	return P;
}
void	Insert( ElementType  key , HashTable  H)
{
	Position Pos,NewCell;
	List L;
	Pos = Find(key,H);
	// 如果没找到
	if(Pos == NULL)
	{
		NewCell = malloc(sizeof(struct ListNode));
		if( NewCell == NULL )
		{
			puts("Out of space \n");
			return;
		}
		else
		{
			// 从表的前端插入
			L = H->TheLists[Hash(key,H->TableSize)];
			NewCell->next = L->next;
			// 此处插入的是字符串
			NewCell->data = malloc(strlen(key) + 1);
			strcpy(NewCell->data,key);
			NewCell->data[strlen(key)]='\0';
			L->next = NewCell;
		}
	}
}
void Delete( ElementType key, HashTable H )
{
	Position  Pos,Pre;
	List L;
	Pos = Find(key,H);
	if(Pos == NULL)
		return;
	else
	{
		L = H->TheLists[Hash(key,H->TableSize)];
		for(Pre = L; Pre->next != NULL; Pre=Pre->next)
		{
			if(Pre->next == Pos)
			{
				Pre->next = Pos->next;
				free(Pos->data);
				free(Pos);
				break;
			}
		}
	}
}
ElementType  Retrieve( Position P )
{
    return P->data;
}
void   DestroyTable( HashTable H )
{
    int i;
    Position P;
    Position Tmp;
    for( i = 0; i < H->TableSize; i++ )
    {
         P= H->TheLists[ i ];
        while( P != NULL )
        {
            Tmp = P->next;
            free( P );
            P = Tmp;
        }
    }
    free( H->TheLists );
    free( H );
}
