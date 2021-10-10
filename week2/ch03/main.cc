#include<stdio.h>
#include<stdlib.h>
using namespace std;
//线性表的链式存储又称为单链表,本部分所有代码都是带头结点的操作
typedef struct LNode {         //定义单链表结点类型
	int data;            //数据域
	struct LNode *next;       //指针域
}LNode, *LinkList;             //单链表的定义

//建立链表的2种方法  头插法 尾插法
//1.头插法
LinkList CreatList1() {
	//从表尾到表头逆向建立单链表L，每次都在头结点之后插入
	LinkList L = (LinkList)malloc(sizeof(LNode));  //创建头结点；
	LNode *s; int x;
	L->next = NULL;                       //初始化为NULL
	scanf_s("%d", &x);
	while (x != -1)//当x=-1的时候结束插入
	{
		s = (LNode *)malloc(sizeof(LNode)); //创建新节点
		s->data = x;//数据域赋值
		s->next = L->next;
		L->next = s;
		scanf_s("%d", &x);
	}
	return L;
}
//2.尾插法
LinkList CreatList2()
{
	//从表头到表尾正向建立，每次均在表尾插入元素
	LinkList L = (LinkList)malloc(sizeof(LNode));// 创建头结点
	int x; //输入的数据
	LNode *s; // 指针
	LNode *ss = L;//储尾指针；让尾指针先等于L
	L->next = NULL;
	scanf_s("%d", &x);
	while (x != -1)//当x=-1的时候结束插入
	{
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		ss->next = s;
		ss = s;
		scanf_s("%d", &x);
	}
	ss->next = NULL;//最后一个元素的next为NULL
	return L;
}
//3.插入结点操作
//2个函数  一个是 找到第i个位置的函数，另一个是插入函数
LinkList GetElem(LinkList L, int i)
{
	LNode *p = L;
	while (i-- > 0 && p)
	{
		p = p->next;
	}
	return p;
}
bool Insert(LinkList L, int i, int x)
{
	//检查合法性
	//{}
	LNode *s = (LNode*)malloc(sizeof(LNode));
	s->next = GetElem(L, i - 1)->next;
	GetElem(L, i - 1)->next = s;         //调用返回 第i个位置的函数
	s->data = x;
	return true;
}
//4.删除结点操作
bool Delete(LinkList L, int i)
{
	//检查合法性
	//{}
	LNode *p; //找到的前驱
	LNode *q; //要找的那个
	p = GetElem(L, i - 1);
	q = p->next;
	p->next = q->next;
	free(q);
	return true;

}
//5.求表长度
int GetLength(LinkList L)
{
	if (L->next == NULL)
	{
		return NULL;
	}
	int i = 0;
	LinkList p = L->next;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}
//6.输出表
void Display(LinkList L)
{
	if (L->next == NULL)
		return;
	LinkList p = L->next;
	while (p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}
int main()
{
	LinkList L = CreatList2();//创建链表,随便输入几个数,输入-1停止输入
	Display(L);//打印表
	printf("表长为:%d\n", GetLength(L));//输出长度

	Insert(L, 1, 3);//在第一个位置前面插入3
	Display(L);//打印表
	printf("表长为:%d\n", GetLength(L));//输出长度

	Delete(L, 2);//删除第二个位置的元素
	Display(L);//打印表
	printf("表长为:%d\n",GetLength(L));//输出长度
}
