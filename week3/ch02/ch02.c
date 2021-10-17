#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
    ElemType data; 
    struct BiTNode *lchild,*rchild; //左右孩子树
}BiTNode,*BiTree;

//二叉树的建立  按照先序遍历建立 
void createBiTree(BiTree *T)
{
    char s;
    scanf("%c",&s);
    
    if(s=='$')
    {
        *T=NULL;
    }
    else
    {
        *T=(BiTNode*)malloc(sizeof(BiTNode)); //生成结点
        if(!(*T))
        {
            printf("申请空间失败\n");
        }
        (*T)->data=s;
        createBiTree(&(*T)->lchild);
        createBiTree(&(*T)->rchild);
    }
}

//二叉树先序遍历
void preorderVisit(BiTree T) //这里不要使用BiTNode *T , 不要直接对树进行操作 
{
    if(T)  //先要进行判断，只有结点不为空才会遍历 
    {
        printf("%c ",T->data);
        preorderVisit(T->lchild);
        preorderVisit(T->rchild);
    }
}

//二叉树中序遍历
void middleVisit(BiTree T)   //这里不要使用BiTNode *T , 不要直接对树进行操作 
{
    if(T)   //先要进行判断，只有结点不为空才会遍历 
    {
        middleVisit(T->lchild);
        printf("%c ",T->data);
        middleVisit(T->rchild);
    }

}

//二叉树后序遍历
void postVisit(BiTree T)   //这里不要使用BiTNode *T , 不要直接对树进行操作 
{
    if(T)   //先要进行判断，只有结点不为空才会遍历 
    {
        postVisit(T->lchild);
        postVisit(T->rchild);
        printf("%c ",T->data);
    }
}

int main()
{
    printf("请输入二叉树，按照先序遍历，无字树用$号表示\n"); 
    
    BiTree T;
    createBiTree(&T);
    
    printf("先序遍历结果如下：\n");
    preorderVisit(T);
    printf("\n");
    
    printf("中序遍历结果如下：\n");
    middleVisit(T);
    printf("\n");
    
    printf("后序遍历结果如下：\n");
    postVisit(T);
    printf("\n");
}
