#include<stdio.h>
#include<stdlib.h>
#include"leftheap.h"

struct TreeNode
{
    ElementType Element;
    PriorityQueue Left;
    PriorityQueue Right;
    int Npl;
};

PriorityQueue Initialize()
{
    PriorityQueue H=(PriorityQueue)malloc(sizeof(struct TreeNode));
    if (H == NULL)
    {
        printf("FAILURE!\n");
        exit(EXIT_FAILURE);
    }
    H->Left = H->Right = NULL;
    H->Npl = 0;
    H->Element = 0;
    return H;
}
ElementType FindMin(PriorityQueue H)
{
    if(!H)
        return H->Element;
    return 0;
}
int IsEmpty(PriorityQueue H)
{
    return H->Left == NULL && H->Right == NULL;
}
void SwapChildren(PriorityQueue H)
{
    PriorityQueue Temp;
    Temp = H->Left;
    H->Left = H->Right;
    H->Right = Temp;
}
static PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2)
{
    if (H1->Left == NULL)
        H1->Left = H2;
    else
    {
        H1->Right = Merge(H1->Right, H2);
        if (H1->Left->Npl < H2->Right->Npl)
            SwapChildren(H1);
        H1->Npl = H1->Right->Npl + 1;
    }
    return H1;
}
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2)
{
    if (H1 == NULL)
        return H2;
    if (H2 == NULL)
        return H1;
    if (H1->Element < H2->Element)
        return Merge1(H1, H2);
    else
        return Merge1(H2, H1);
}
PriorityQueue Insert1(ElementType X, PriorityQueue H)
{
    PriorityQueue SingleNode;
    SingleNode = Initialize();
    SingleNode->Element = X;
    H = Merge(SingleNode, H);
    return H;
}
PriorityQueue DeleteMin1(PriorityQueue H)
{
    PriorityQueue LeftHeap, RightHeap;
    if (IsEmpty(H))
    {
        printf("ERROR!\n");
        return H;
    }
    LeftHeap = H->Left;
    RightHeap = H->Right;
    free(H);
    return Merge(LeftHeap, RightHeap);
}
