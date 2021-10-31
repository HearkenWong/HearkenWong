#ifndef _LEFTHEAP_H_
#define _LEFTHEAP_H_
#define Insert(X,H) (H=Insert1((X),H))
#define DeleteMin(H)(H=DeleteMin1(H))

struct TreeNode;
typedef struct TreeNode *PriorityQueue;
typedef int ElementType;

PriorityQueue Initialize();
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);
PriorityQueue Insert1(ElementType X, PriorityQueue H);
PriorityQueue DeleteMin1(PriorityQueue H);

#endif
