// 顺序表，顺序表的操作                            
// 1.定义顺序表（动态分配内存）
// 2.插入、删除、查找、输出到屏幕
#include<stdio.h>
#include<stdlib.h>
#define InitSize 5       //初始化大小为5

typedef struct {         //定义一个动态分配空间的结构体 顺序表
	int *data;           //int类型指针
	int length;			 //当前尺寸
	int MaxSize=10;      //我设定SqList最大尺寸是10,也就是最多放10个元素
} SqList;

//因为以下四个函数定义在main函数之后
//所以需要申明这四个函数
bool ListInsert(SqList &L, int i, int e);//插入一个元素到顺序表
bool ListDelete(SqList &L, int i);//从顺序表删除一个元素
int  LocateElem(SqList L, int e);//查找一个元素在顺序表第一次出现的位置
void ListPrint(SqList L);//打印顺序表

int main()
{
	int i = 0;    //i作为循环使用
	SqList L;
	L.data=(int*)malloc(sizeof(int)*InitSize);//分配内存空间
	L.length = 0; //因为现在还没有插入数据,所以L的长度为0

	//这个while是为了输入数据,每次输入后i++
	printf("输入%d个元素,每两个之间打空格,完毕后按回车\n", InitSize);
	while ((i < InitSize) && (L.length < L.MaxSize))
	{
		scanf_s("%d", &L.data[i]);//输入数据,这里用的scanf_s,等价于scanf
		L.length++;            //每输入一个数据,L的长度增加1
		i++;                   //每次循环i自增1
	}
	//输入完毕后打印L到屏幕
	ListPrint(L);

	//执行插入操作,下面可以自己修改,试试有什么不一样
	printf("在第3个元素前面插入10\n");
	if (ListInsert(L, 3, 10) == true)
		ListPrint(L);
	//执行删除操作,下面可以自己修改,试试有什么不一样
	printf("删除第4个元素\n");
	if (ListDelete(L, 4) == true)
		ListPrint(L);

	//执行查找操作,下面可以自己修改,试试有什么不一样
	printf("查找值为1的元素在L中第一次出现的位置\n");
	printf("值为1的元素在L中第一次出现的位置为%d\n", LocateElem(L, 1));

	return 0;
}

//顺序表插入元素的具体实现
bool ListInsert(SqList &L, int i, int e)
{
	if (i >= L.length + 1 || i < 0 || L.length >= L.MaxSize)//先判断i是否为有效值,L.length是否超出额定分配的空间
		return false;				  //插入失败,返回false
	//realloc可以动态改变指针指向内存的大小
	//用法是 指针名 =（数据类型*）realloc（要改变内存大小的指针名，新的大小）。
	(int *)realloc(L.data, (L.length + 1) * sizeof(int));
	int *j;
	int *k;
	j = &(L.data[i - 1]);//j指向实际插入的位置
	for (k = &(L.data[L.length-1]); k >= j; k--)    //把第j个之后的数据全部后移一位,可以理解为腾位置
	{
		*(k + 1) = *k;
	}
	*j = e;              //腾开位置后将待插入元素e插入到第j个位置
	L.length++;          //长度增加1
	return true;         //插入成功,返回true
}
//顺序表删除元素的具体实现
bool ListDelete(SqList &L, int i)
{
	if (i >= L.length || i < 1)        //先检查i是否为有效值
		return false;
	int *j = &(L.data[i - 1]);//需要删除的元素位置
	int *k = &(L.data[L.length - 1]);//最后一个元素的位置
	for (; j < k; j++)   //开始把被删除的值后面的值前移
	{
		*(j) = *(j + 1);
	}
	L.length--;                 //长度减少1
	return true;
}
//查找顺序表值为e的元素第一次出现的位置
int LocateElem(SqList L, int e)
{
	for (int i = 0; i < L.length; i++)  //用for循环从第一个位置开始找
	{
		if (L.data[i] == e)         //如果找到了就返回被找到的元素的下标+1
		{
			return i + 1;          //因为下标从0开始算,而我们要找出现的位置所以要+1
		}
	}
	return 0;                    //没有找到就返回0
}
//输出这个线性表
void ListPrint(SqList L)
{
	int i = 0;
	while (i < L.length && L.data[i] != NULL) //只要满足i小于线性表的长度且i对应的数据不为空就输出该元素
	{
		printf("%d\n", L.data[i]);
		i++;                             //每次循环i自增1
	}
	printf("整个线性表的长度为：");
	printf("%d\n", L.length);             //输出线性表的长度
	printf("------------------------------\n");
}
