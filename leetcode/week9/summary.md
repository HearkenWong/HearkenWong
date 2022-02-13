这周重新主要复习了堆排序。
# 堆排序
## 性质
堆是一种数据结构，一种叫做完全二叉树的数据结构。

### 堆要满足两个条件：

1.是一个完全二叉树

2.堆中某个节点的值总是不大于或不小于其父节点的值

**大顶堆（大根堆）:** 每个父结点的值都大于等于其子节点的值，左边的子节点可以形象称为左孩子，右边的子节点则为右孩子

**小顶堆（小根堆）：** 每个父结点的值都小于等于其子节点的值

## 代码实现
### 1.heapify：
从一个结点出发，将它与左孩子右孩子比较，选择三者中中的最大值作为新的父节点，反复该过程直到成为一个大顶堆
```
int heapify(int tree[10000],int n,int i)
{
	if(i>=n)//i表示数组下标，n代表待排序的数字个数
	{
	return ;
	}
	int c1,c2,max;//c1,c2为两个子节点
	c1=2*i+1;
	c2=2*i+2;
	max=i;
	if(c1<n&&tree[c1]>tree[max])
	 {max=c1;}
	if(c2<n&&tree[c2]>tree[max])
	{max=c2;}
	if(max!=i)
	{
		swap(tree,max,i);//为了方便写一个swap函数，详情见（1）
		heapify(tree,n,max);
	}
}
```

### build_heap:
从中间的结点开始向上依次堆化
```
int build_heap(int tree[10000],int n)
{
	int last_node=n-1;
	int parent=(last_node-1)/2;
	int i;
	for(i=parent;i>=0;i--)
	{
		heapify(tree,n,i);
	}
}
```
### 3.heap_sort：
每将最大值与最后一个节点交换后，堆的结构就被破坏了，需要再次堆化。
我们可以理解为每交换一次最大值，就将连接最大值的树枝砍断，那么需要排列的数就从n变为n-1，继续对n-1个数重复这个过程
```
int heap_sort(int tree[10000],int n)
{
	build_heap(tree,n);
	int i;
	for(i=n-1;i>=0;i--)
	{
		swap(tree,i,0);
		heapify(tree,i,0);
	}
}
```
