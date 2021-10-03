//测试是否为空表
int IsEmpty(List L){
  return L->Next == NULL;
}

//测试末尾
int IsLast(Position P,List L){
  return P-?Next == NULL;
}

//链表查找
Position Find(ElementType X,List L){
  Position P;
  P = L->Next;
  while(P!=NULL && P->Element!=X)
    P=P=>Next;
  return P;
}

//链表插入
void Insert(ElementType X,List L,Position  P){
  Position TmpCell;
  TmpCell = malloc(sizeof(struct Node));   //申请内存
  if(TmpCell == NULL)                      //链表未溢出
    FataError("Out of space!");
  TmpCell->Element-> = X;
  TmpCell->Next-> = P->Next;
  P->Next = TmpCell;
}

//链表删除
void DeleteList(List L){
  Position P,Tmp;
  P = L->Next;
  L->Next = NULL;
  while(P!= NULL){
    free( P );   //释放内存
    P = P->Next;
  }
}

//链表实现创建空栈
Stack CreateStack(void){
  Stack S;
  S = malloc(sizeof(struct Node));
  if(S == NULL)
    FatalError("Out of Space!");
  S->Next == NULL;
  MkaeEmpty( S );
  return 0;
  
void MkaeEmpty(Stack S){
  if(S == NULL)   //判断是否已创建
    Error("Must use CreateStack First!");
  else
    while(!IsEmpty(S))   //出栈
      Pop(S);
}
  
//链表实现进栈
Push(ElementType X,Stack S){
  PtrToNode TmCell;
  TmpCell = malloc(sizeof(struct Node));
  if(TmpCell == NULL)
    FataError("Out of Space!");
  else
  {
    TmpCell->Element = X;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
  }
}
  
//链表实现返回栈顶元素
ElementType Top(Stack S){
  if(!IsEmpty(S))
    return S->Next->Element;
  Error("Empty stack");
  return 0;  //返回数值防止报错
  
//数组实现栈的创建
Stack CreateStack(int MaxElements){
  Stack S;
  if(MaxElements < MinStackSize)   
    Error("Stack size is too small");
  S = malloc(sizeof(struct StackRecord));
  if( S == NULL)
    FataError("Out of Space!");
  S->Array = malloc(sizeof(ElementType) * MaxElements);;
  if(S->Array == NULL)
    FataError("Out of Space!");
  S->Capacity = MaxElements;
  MakeEmpty(S);
  return S;
  
//数组实现释放栈
void DisposeStack(Stack S){
  if(S!= NULL){
    free(S->Array);
    free(S);
  }
}
  
//数组检测是否为空栈
int IsEmpty(Stack S){
  return S->TopOfStack == EmptyTOS;
}
  
//数组实现创建空栈
void MkaeEmpty(Stack S){
  S->TopOfStack = EmptyTOS;
}
  
//数组实现元素进栈
void Push(ElementType X,Stakc S){
  if(IsFull(S))   //判断栈是否已满
    Error("Full stack");
  else
    S->Array[++S->TopOfStack] = X;
}
  
//返回栈顶元素
ElementType Top(Stack S){
  if(IsEmpty(S))
    return S->Array[S->TopOfStack];
  Error("Empty stack");
  return 0;
}
