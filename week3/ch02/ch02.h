#ifndef __BTREE_H__
#define __BTREE_H__
 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
typedef char dataype_bt;  //声明二叉树中存放的数据类型，便于后续更改
 
typedef struct btreenode{   //二叉树的节点结构：存放的数据 该节点的左子节点地址及右子节点地址。二叉树和单链表的区别，二叉树是非线性存储，单链表是线性存储
	dataype_bt data;
	struct btreenode *lchild,*rchild;
}btree_node,*btree_pnode;
 
extern btree_pnode create_btree1(void);    //通过递归方法创建一个二叉树
extern void create_btree(btree_pnode *T);  //通过递归方法创建一个二叉树（功能同上）
extern void pre_order(btree_pnode t);    //采用递归方法先序遍历
extern void unpre_order(btree_pnode t);  //采用非递归方法先序遍历
extern void mid_order(btree_pnode t);    //采用递归方法中序遍历
extern void post_order(btree_pnode t);   //采用递归方法后序遍历
extern void level_order(btree_pnode t);  //层次遍历
extern void travel(char const *str,void (*pfun)(btree_pnode),btree_pnode t);   //将上面的函数作为参数传入该函数（函数的回调），实现二叉树的创建 和 遍历，其中参数str可以是回调函数的功能描述
#endif
