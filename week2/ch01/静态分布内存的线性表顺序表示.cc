// 顺序表，顺序表的操作                            
// 1.定义顺序表（静态分配内存）
// 2.插入、删除、查找、输出到屏幕
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 5
typedef struct {    //顺序表结构体
	int data[MaxSize];  //顺序表数据域的大小为5
	int length;   //顺序表的长度
} SqList;          //顺序表的类型

//因为以下四个函数定义在main函数之后
//所以需要申明这四个函数
bool ListInsert(SqList &L, int i, int e);//插入一个元素到顺序表
bool ListDelete(SqList &L, int i);//从顺序表删除一个元素
int  LocateElem(SqList L, int e);//查找一个元素在顺序表第一次出现的位置
void ListPrint(SqList L);//打印顺序表

int main()
{
	int i = 0;    //i作为循环使用
	SqList L;   //定义一个顺序表结构体L
	L.length = 0; //因为现在还没有插入数据,所以L的长度为0

	//这个while是为了输入数据,每次输入后i++,当i=MaxSize结束输入
	printf("输入%d个元素,每两个之间打空格,完毕后按回车\n",MaxSize);
	while (i < MaxSize)
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
	if (i >= L.length + 1 || i < 0)    //先判断i是否为有效值 
		return false;				  //插入失败,返回false
	if (L.length > MaxSize)           //在判断顺序表是否已经满了
		return false;                //插入失败,返回false
	for (int j = L.length; j >= i; j--)    //把第i个之后的数据全部后移一位,可以理解为腾位置
	{
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;              //腾开位置后将待插入元素e插入到第i个位置
	L.length++;                 //长度增加1
	return true;                //插入成功,返回true
}
//顺序表删除元素的具体实现
bool ListDelete(SqList &L, int i)
{
	if (i >= L.length || i < 1)        //先检查i是否为有效值
		return false;
	for (int j = i; j < L.length; j++)   //开始把被删除的值后面的值前移
	{
		L.data[j - 1] = L.data[j];
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

