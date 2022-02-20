这周的LeetCode刷题过程，遇到了求最长公共前缀的问题，我在做的时候不假思索的选择了遍历的方法。依次遍历字符串数组中的每个字符串，对于每个遍历到的字符串，更新最长公共前缀，当遍历完所有的字符串以后，从而得到字符串数组中的最长公共前缀。

但我在参考答案是发现，有时间复杂度更低的方法，使用二分查找法来实现可以更好地提高效率。因为最长公共前缀的长度不会超过字符串数组中的最短字符串的长度。用minLength 表示字符串数组中的最短字符串的长度，则可以通过二分查找得到最长公共前缀的长度。每次取查找范围的中间值 ，判断每个字符串的长度为该值的前缀是否相同，如果相同则最长公共前缀的长度一定大于或等于该值，如果不相同则最长公共前缀的长度一定小于该值，通过上述方式将查找范围缩小一半，直到得到最长公共前缀的长度。
二分查找法我的使用次数并不多，通过这次应用完善了我对该算法的理解，我认为应该多多尝试不同的方法，尽量以更高的效率完成程序。

除了刷LeetCode之外，这周我主要学习了斐波那契堆，笔记如下。

# 斐波那契堆

斐波那契堆(Fibonacci heap)是堆中一种，它和二项堆一样，也是一种可合并堆；可用于实现合并优先队列。斐波那契堆比二项堆具有更好的平摊分析性能，它的合并操作的时间复杂度是O(1)。

与二项堆一样，它也是由一组堆最小有序树组成，并且是一种可合并堆。

与二项堆不同的是，斐波那契堆中的树不一定是二项树；而且二项堆中的树是有序排列的，但是斐波那契堆中的树都是有根而无序的。

## 基本定义
斐波那契堆是由一组最小堆组成，这些最小堆的根节点组成了双向链表；斐波那契堆中的最小节点就是"根链表中的最小节点"！

## 插入操作
插入操作非常简单：插入一个节点到堆中，直接将该节点插入到"根链表的min节点"之前即可；若被插入节点比"min节点"小，则更新"min节点"为被插入节点。

## 合并操作
合并操作和插入操作的原理非常类似：将一个堆的根链表插入到另一个堆的根链表上即可。简单来说，就是将两个双链表拼接成一个双向链表。

## 取出最小节点
抽取最小结点的操作是斐波那契堆中较复杂的操作。

(1）将要抽取最小结点的子树都直接串联在根表中；

(2）合并所有degree相等的树，直到没有相等的degree的树。
## 减少节点值

(1) 首先，将"被减小节点"从"它所在的最小堆"剥离出来；然后将"该节点"关联到"根链表"中。 倘若被减小的节点不是单独一个节点，而是包含子树的树根。则是将以"被减小节点"为根的子树从"最小堆"中剥离出来，然后将该树关联到根链表中。

(2) 接着，对"被减少节点"的原父节点进行"级联剪切"。所谓"级联剪切"，就是在被减小节点破坏了最小堆性质，并被切下来之后；再从"它的父节点"进行递归级联剪切操作。

(3) 最后对根链表的最小节点进行更新。

## 增加节点值

增加节点值和减少节点值类似，这个操作的难点也是如何维护"最小堆"性质。思路如下：

(1) 将"被增加节点"的"左孩子和左孩子的所有兄弟"都链接到根链表中。

(2) 接下来，把"被增加节点"添加到根链表；但是别忘了对其进行级联剪切。
## 删除节点

(1) 先将被删除节点的键值减少。减少后的值要比"原最小节点的值"即可。

(2) 接着，取出最小节点即可。