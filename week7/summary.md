# 自顶向下红黑树
## 红黑树定义
红黑树，一种自平衡的二叉查找树，在每一个结点内部储存节点的颜色信息（红色或者黑色），能够以O(logN)的时间复杂度查找、插入和删除。

红黑树是一种二叉查找树，满足二叉树的一般性质：
1. 对于二叉树的任意一个节点，如果左子树非空，左子树的所有节点的键值均小于该结点；如果右子树非空，右子树所有节点的键值均大于该结点。
2. 树中不存在键值相等的节点。
## 性质
红黑树虽然在本质上是一棵二叉查找树，但其着色的特性使得红黑树保持了高度平衡性，其高度最高是2log(N+1)。红黑树着色性质如下：
1. 每一个节点或为黑色，或为红色。
2. 根是黑色的。
3. 如果一个节点是红色的，那么它的子节点必为黑色。
4. 从一个节点到一个NULL指针的每一条路径必须包含相同数目的黑色节点。
