//打印单链表所有元素
struct Node{
  int element;
  struct Node *next;
};
Node *findEnd (Node *list){
  while(list->next) 
    list = list->next;
  return list;
}
void insert(int val,，Node *list){
  Node *p = (Node *)malloc(sizeof(Node)) ;
  p->val = val; 
  p->next = NULL;
  Node *end = findEnd(list);
  end->next = p;
}
int main(){
  Node *list = (Node *)malloc( sizeof(Node)),*p;
  list->next = NULL;
  int a;
  while(scanf( "%d" , &a) == 1)
  insert(a,list);
  p = list->next;
  while(p){
    printf("%d ",p->val);
    P = p->next;
  }
  return 0;
